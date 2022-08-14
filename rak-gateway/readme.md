# RAK-gateway Setup

[Original Source](https://docs.rakwireless.com/Product-Categories/WisLink/RAK2245-Pi-HAT/Quickstart/#prerequisites)


## RAK-gateway configuration
``` shell
sudo raspi-config
# add the new  SSID and password to the wifi configuration

#restart the packet forwarder with adding gateway configurations
```

## Connect to TTN
``` shell
sudo raspi-config
# select the server as TTN and Frequency channel 
# and the region as Europe/US/IN

```
## Setup the gateway
 

![gateway](https://user-images.githubusercontent.com/59604988/184530318-55e307b9-1a6d-4d8f-9cd4-6e9a7759610d.png)
