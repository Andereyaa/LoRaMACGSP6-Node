#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <HardwareSerial.h>
#include "esp32-lorawan-macgsp6-node.h"

using namespace std;

HardwareSerial LoRaRadio(2);

struct Payload
{
    int hop_counter;
    char* data;
};
struct Packet{
    int source_address;
    int data_size;
    string data;
    //struct Payload payload;
    int rssi;
    int snr;
}

queue<Payload> Tx_queue;
queue<Packet> Rx_queue;

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

void toggleRadio_On_Off(){}

vector<string> split_string(const string str, char delimiter){
    vector<string> result;
    stringstream ss(str);
    string item;

    while (getline(ss, item, delimiter)){
        result.push_back(item);
    }
    return result;
}

Packet listen(){
    Packet packet; 
    if(LoRaRadio.available()){
        String recTest = incoming_str.substring(0, 5);
        if (recTest == "+RCV=") {
            const string inbound_packet = LoRaRadio.readString();
            vector<string> result = split_string(inbound_packet, ',');

            packet.source_address = int(result[0]);
            packet.data_size = int(result[1]);
            packet.data = result[2];
            packet.rssi = result[3];
            packet.snr = result[4];
        }else if(recTest == "+ACK="){

        }
    }
    return packet;
}
