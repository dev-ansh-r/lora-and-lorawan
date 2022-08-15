# LORA-E5 Development Kit

## Introduction
```shell
# connect lora to the pc and open the serial port of any serial monitor (I used Arduino)

AT                #to view AT functions 
AT+version        #to view the version of the module
AT+ID             #to read the module EUI's

AT+ID=AppEUI,"add appeui"      #to set the AppEUI
AT+ID=DevEUI,"add deveui"      #to set the DevEUI
AT+KEY=APPKEY,"add appkey"     #to set the AppKey
AT+ID=DevAddr,"add devaddr"    #to set the DevAddr
AT+KEY=NwkSKey,"add nwkskey"   #to set the Nwk Session Key
AT+KEY=AppSKey,"add appskey"   #to set the App Session Key
AT+MODE=OTAA                   #to set the mode to OTAA
AT+MODE=ABP                    #to set the mode to ABP
AT+JOIN                       #to join the network
AT+MSG="hello "           #to send a message
```

![LORA-E5 Development Kit](https://user-images.githubusercontent.com/59604988/184572677-f5739a09-076c-4df8-b665-a1d549b068c2.jpg)
