#include <HardwareSerial.h>

#include "esp32-lorawan-macgsp6-node.h"

int initialiseLoraRadio()
{

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

//

void setup() {}

void loop() {}