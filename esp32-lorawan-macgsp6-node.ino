#include <HardwareSerial.h>
#include <queue>
#include "esp32-lorawan-macgsp6-node.h"

struct Packet{

}
struct Payload
{
    int hop_counter;
    char* data;
};

queue<Payload> transmission_queue;

int initialiseLoraRadio(){

    LoRaRadio.begin(baudRate, SERIAL_8N1, DEFAULT_RX_PIN, DEFAULT_TX_PIN);
    delay(delayInMillis);
    LoRaRadio.print((String) "AT+ADDRESS=" + AT_ADDRESS + "\r\n");
    delay(delayInMillis);
    LoRaRadio.print((String) "AT+NETWORKID=" + AT_NETWORK_ID + "\r\n");
    delay(delayInMillis);
    LoRaRadio.print((String) "AT+MODE=" + AT_MODE + "\r\n");
    delay(delayInMillis);
    LoRaRadio.print((String) "AT+IPR=" + AT_IPR + "\r\n");
    delay(delayInMillis);
    LoRaRadio.print((String) "AT+CRFOP=" + AT_CRFOP + "\r\n");
    delay(delayInMillis);
    LoRaRadio.print((String) "AT+BAND=" + AT_BAND + "\r\n");
    delay(delayInMillis);
    LoRaRadio.print((String) "AT+PARAMETER=" + AT_PARAMETER + "\r\n");
    delay(delayInMillis);
    LoRaRadio.print((String) "AT+CPIN=" + AT_PASSWORD + "\r\n");
    delay(delayInMillis);
    LoRaRadio.print("AT+CPIN?\r\n"); // confirm password is set

    return 0;
}

int p_gsp() {}

// toggleRadioOn_Off(){}

Packet listen(){
    Packet packet; 
    if(LoRaPort.available()){
        char* inbound_packet = LoRaRadio.readString();
        char* delimiter = ",";
        char* token = strtok(inbound_packet, delimiter);
        while (token != NULL)
        {
            //TODO build packet struct
            token = strtok(inbound_packet, delimiter);
        }
    }
    return packet;
}

void send(Packet packet){}

void setup() {}

void loop() {}