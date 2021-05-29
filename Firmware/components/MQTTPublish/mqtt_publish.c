/* MQTT Publisher
 *
 *
 */
#include <string.h>

#include "MQTTClient.h"
#include "MQTTLinux.h"

#include "esp_log.h"

//#include "json_util.h"

/* Constants that aren't configurable in menuconfig */
#define MQTT_SERVER "gluelogics.com" 
//#define MQTT_PORT 443
//#define MQTT_PORT 1883
#define MQTT_PORT 8883
#define MQTT_BUF_SIZE 1024
#define MQTT_WEBSOCKET 0  // 0=no 1=yes

static unsigned char mqtt_sendBuf[MQTT_BUF_SIZE];
static unsigned char mqtt_readBuf[MQTT_BUF_SIZE];

static const char *TAG = "MQTT";


void mqtt_pub(char *topic, char *msgbuf) {
	
	int ret;
	Network network;

   // while(1) {
					

		ESP_LOGD(TAG, "Start MQTT ...");
		
		MQTTClient client;
		NetworkInit(&network);
		network.websocket = MQTT_WEBSOCKET;

		ESP_LOGD(TAG,"NetworkConnect %s:%d ...",MQTT_SERVER,MQTT_PORT);
		ret = NetworkConnect(&network, MQTT_SERVER, MQTT_PORT);
		if (ret != 0) {
			ESP_LOGI(TAG, "NetworkConnect not SUCCESS: %d", ret);
			goto exit;
		}
		
		ESP_LOGI(TAG,"MQTTClientInit  ...");
		MQTTClientInit(&client, &network,
			2000,            // command_timeout_ms
			mqtt_sendBuf,         //sendbuf,
			MQTT_BUF_SIZE, //sendbuf_size,
			mqtt_readBuf,         //readbuf,
			MQTT_BUF_SIZE  //readbuf_size
		);

		MQTTString clientId = MQTTString_initializer;
		clientId.cstring = "Button001";
		
		MQTTString user = MQTTString_initializer;
		user.cstring= "mys0nJqB9MO85KiQYiPD"; //Button001
		
		MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
		data.clientID          = clientId;
		data.username		   = user;
		data.willFlag          = 0;
		data.MQTTVersion       = 4; // 3 = 3.1 4 = 3.1.1
		data.keepAliveInterval = 60;
		data.cleansession      = 1;

		ESP_LOGI(TAG,"MQTTConnect  ...");
		ret = MQTTConnect(&client, &data);
		if (ret != SUCCESS) {
			ESP_LOGI(TAG, "MQTTConnect not SUCCESS: %d", ret);
			goto exit;
		}
		
		MQTTMessage message;
			
		ESP_LOGI(TAG, "MQTTPublish  ... %s",msgbuf);
		message.qos = QOS0;
		message.retained = false;
		message.dup = false;
		message.payload = (void*)msgbuf;
		message.payloadlen = strlen(msgbuf);
			
		int check = strlen(msgbuf);
		printf("%d\n",check);

		ret = MQTTPublish(&client, topic, &message);
		if (ret != SUCCESS) {
			ESP_LOGI(TAG, "MQTTPublish not SUCCESS: %d", ret);
			goto exit;
		}
			
		//for(int countdown = 5; countdown >= 0; countdown--) {	
		//	if(countdown%10==0) {
		//		ESP_LOGI(TAG, "%d...", countdown);
		//	}
		//	vTaskDelay(1000 / portTICK_RATE_MS);
		//}
	
		exit:
			MQTTDisconnect(&client);
			NetworkDisconnect(&network);
			ESP_LOGI(TAG, "MQTTDisconnect ...");
			for(int countdown = 5; countdown >= 0; countdown--) {
				if(countdown%10==0) {
					ESP_LOGI(TAG, "%d...", countdown);
				}
				vTaskDelay(1000 / portTICK_RATE_MS);
			}
			printf("Disconnected!\n");
}			
