ServiceButton: Connected Button for Notifications and Alarms
======

WiFi connected button that sends push notification data to an IoT platform. The notifications can be configured depending on use case.
Possible business cases are presented [here](/Docs).


### Hardware

ESP32 Microcontroller, simple push button, rechargeable battery.

### Firmware

The deevice connects with a server over WLAN. When button pressed, a notification message is composed from previously configured
data. The notification message is then sent in JSON format via TLS-secured MQTT protocol to the cloud service ([GlueLogics](https://github.com/eptecon/gluelogics)).


---
