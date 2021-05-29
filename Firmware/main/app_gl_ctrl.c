/* Controller -  GlueLogics System Business Logic
 *
 *
 *
 */
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_event_loop.h"
#include "esp_log.h"
#include "esp_system.h"

#include "mqtt_publish.h"
#include "mqtt_subscribe.h"

#include "led_blinker.h"

#include "json_util.h"


#define LONG_PRESS_PERIOD_MS 100
#define BTN_SENSE_BIT BIT0
#define KEY_GPIO_NUM 27
#define KEY_ACTIVE 1
#define GLITCH_TIMEOUT_MS 500

#define SERIAL "Button001"

#define TOPIC1 "v1/devices/me/attributes"
#define TOPIC2 "v1/devices/me/telemetry"

static EventGroupHandle_t button_event_group;

static const char *TAG = "gl_ctrl";

static void IRAM_ATTR gpio_isr_handler_up(void* arg) {
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	xEventGroupSetBitsFromISR(button_event_group, BTN_SENSE_BIT, &xHigherPriorityTaskWoken);
	portYIELD_FROM_ISR();
}

void init_gpio(void) {
	/*
	 * Setup button GPIO
	 */
	gpio_config_t io_conf = {
		.pin_bit_mask = 1 << KEY_GPIO_NUM,
		.mode = GPIO_MODE_INPUT,
		.pull_down_en = GPIO_PULLDOWN_ENABLE,
		.pull_up_en = GPIO_PULLUP_DISABLE,
		.intr_type = GPIO_INTR_POSEDGE,
	};
	gpio_config(&io_conf);
	printf("Button configured\n");
	
	gpio_intr_enable(KEY_GPIO_NUM);
	gpio_install_isr_service(0);
	gpio_isr_handler_add(KEY_GPIO_NUM, gpio_isr_handler_up, (void*) KEY_GPIO_NUM);
}

void app_gl_ctrl(void *arg) {
	
	EventBits_t bits;
	button_event_group = xEventGroupCreate();
	
	init_gpio();
	
	char *msg1, *msg2;
	char batt_value[32], click_type[32];

	//sprintf(batt_value1, "%d",(uint8_t)(esp_random()&0xFF));
		
	/*Create JSON Object*/
	msg1 = json_create(SERIAL);
	printf("%s\n",msg1);
	
	mqtt_pub(TOPIC1, msg1);
	

    while(1) {
       
		led_blinker_set_mode(BLINK_MODE_CONNECTED);
		vTaskDelay(1000 / portTICK_RATE_MS);
		ESP_LOGI(TAG, "Wait for button pressed...");
		
		if (gpio_get_level(KEY_GPIO_NUM) != KEY_ACTIVE) {
			vTaskDelay(GLITCH_TIMEOUT_MS / portTICK_RATE_MS);

			if (gpio_get_level(KEY_GPIO_NUM) != KEY_ACTIVE) {
				
				led_blinker_set_mode(BLINK_MODE_STARTED);

				bits = xEventGroupWaitBits(button_event_group, 
					BTN_SENSE_BIT, 
					pdTRUE, 
					pdTRUE, 
					LONG_PRESS_PERIOD_MS / portTICK_RATE_MS);
				
				if (bits != 0) {
					
					sprintf(batt_value, "%d",(uint8_t)(esp_random()&0xFF));
					sprintf(click_type,"SINGLE");
		
					/*Create JSON Object*/
					msg2 = json_update(batt_value, click_type);
					printf("%s\n",msg2);
					
					mqtt_pub(TOPIC2, msg2);
					//mqtt_sub();
					
					vTaskDelay(1000 / portTICK_RATE_MS);
					
					//led_blinker_set_mode(BLINK_MODE_CONNECTED);
					//ESP_LOGI(TAG, "Wait for button pressed...");	
					
					//xEventGroupClearBits(button_event_group, BTN_SENSE_BIT);
				}
			
			}
		}
	}	
}
 
 