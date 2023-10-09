#include <lmic.h>
#include <hal/hal.h>
#include <SPI.h>
#include <Wire.h>

#define BAUDRATE_SERIAL_DEBUG   115200


#define GANHO_LORA_DBM          20 

#define RADIO_RESET_PORT        14
#define RADIO_MOSI_PORT         27
#define RADIO_MISO_PORT         19
#define RADIO_SCLK_PORT         5
#define RADIO_NSS_PORT          18
#define RADIO_DIO_0_PORT        26
#define RADIO_DIO_1_PORT        35
#define RADIO_DIO_2_PORT        34

const lmic_pinmap lmic_pins = {
  .nss = RADIO_NSS_PORT,
  .rxtx = LMIC_UNUSED_PIN,
  .rst = RADIO_RESET_PORT,
  .dio = {RADIO_DIO_0_PORT, RADIO_DIO_1_PORT, LMIC_UNUSED_PIN},
};
static const PROGMEM u1_t NWKSKEY[16] = {0x0b, 0x70, 0xc9, 0x73, 0x1d, 0x1c, 0x2a, 0xcd, 0xd5, 0xf9, 0x91, 0x53, 0x7a, 0x7a, 0xcd,0x35};
static const u1_t PROGMEM APPSKEY[16] = {0xae, 0xe8, 0xaa, 0xe1, 0x2e, 0x4d, 0xa3, 0x0b, 0x73, 0x83, 0x4a, 0x96, 0xa2, 0xb6, 0x66,0x61}; 

/* - Device Address */
static const u4_t DEVADDR = 0x999fffdd;

const unsigned TX_INTERVAL = 30; //seugndos


static osjob_t sendjob; // ABP

/*  OTAA */
//static const u1_t PROGMEM DEVEUI[8]= { 0x70,0xb3,0xd5,0x7e,0xd0,0x04,0x65,0xbe };
void os_getArtEui (u1_t* buf) 
{ 
    /* nao usa */  
}

void os_getDevEui (u1_t* buf) 
{ 
  //memcpy_P(buf, DEVEUI, 8);
    /* nao usa*/  
}

void os_getDevKey (u1_t* buf) 
{ 
    /* nao usa*/  
}

void onEvent (ev_t ev) 
{
    Serial.print(os_getTime());
    Serial.print(": ");
    Serial.println(ev);
    
    switch(ev) 
    {
        case EV_SCAN_TIMEOUT:
            Serial.println(F("cheguei no ->EV_SCAN_TIMEOUT"));
            break;
        case EV_BEACON_FOUND:
            Serial.println(F("cheguei no ->EV_BEACON_FOUND"));
            break;
        case EV_BEACON_MISSED:
            Serial.println(F("cheguei no ->EV_BEACON_MISSED"));
            break;
        case EV_BEACON_TRACKED:
            Serial.println(F("cheguei no ->EV_BEACON_TRACKED"));
            break;
        case EV_JOINING:
            Serial.println(F("cheguei no ->EV_JOINING"));
            break;
        case EV_JOINED:
            Serial.println(F("cheguei no ->EV_JOINED"));
            break;
        case EV_JOIN_FAILED:
            Serial.println(F("cheguei no ->EV_JOIN_FAILED"));
            break;
        case EV_REJOIN_FAILED:
            Serial.println(F("cheguei no ->EV_REJOIN_FAILED"));
            break;
        case EV_TXCOMPLETE:
            Serial.println (millis());
            Serial.println(F("cheguei no -> EV_TXCOMPLETE"));
            
            if (LMIC.txrxFlags & TXRX_ACK)
              Serial.println(F("Ack recebido"));
            if (LMIC.dataLen) 
            {
                Serial.println(F("Recebidos "));
                Serial.println(LMIC.dataLen);
                Serial.println(F(" bytes"));

                if (LMIC.dataLen == 1) 
                {
                    uint8_t dados_recebidos = LMIC.frame[LMIC.dataBeg + 0];
                    Serial.print(F("Dados recebidos: "));
                    Serial.write(dados_recebidos);
                }
                delay(1000);
            }
            os_setTimedCallback(&sendjob, os_getTime()+sec2osticks(TX_INTERVAL), do_send);
            break;
        case EV_LOST_TSYNC:
            Serial.println(F("cheguei no ->EV_LOST_TSYNC"));
            break;
        case EV_RESET:
            Serial.println(F("cheguei no ->EV_RESET"));
            break;
        case EV_RXCOMPLETE:
            Serial.println(F("cheguei no ->EV_RXCOMPLETE"));
            break;
        case EV_LINK_DEAD:
            Serial.println(F("cheguei no ->EV_LINK_DEAD"));
            break;
        case EV_LINK_ALIVE:
            Serial.println(F("cheguei no ->EV_LINK_ALIVE"));
            break;
        case EV_TXSTART:
            Serial.println(F("cheguei no ->EV_TXSTART"));
            Serial.println (millis());
            Serial.println(LMIC.freq);
            break;
        default:
            Serial.print(F("Evento desconhecido: "));
            Serial.println((unsigned) ev);
            break;
    }
}
void do_send(osjob_t* j)
{
    static uint8_t mydata[5];
    char mydata_str[5]={0};
    int numero_aleatorio = (int)random(100);
    delay(500);
    Serial.println("bonossauro"+String(numero_aleatorio));
    sprintf(mydata_str, "%02d", numero_aleatorio);  
    memcpy(mydata, (uint8_t *)&mydata_str, strlen(mydata_str));
    Serial.print(F(mydata));
    
    if (LMIC.opmode & OP_TXRXPEND) 
    {
        Serial.println(F("OP_TXRXPEND:  ja pendente um pacote, portanto o atual envio nao sera feito"));
    } 
    else 
    {
        LMIC_setTxData2(4, mydata, sizeof(mydata), 0);
        Serial.println(F("Pacote LoRaWAN na fila de envio."));       
    }
}
void setup() 
{
    uint8_t appskey[sizeof(APPSKEY)];
    uint8_t nwkskey[sizeof(NWKSKEY)];
    int b;
    Serial.begin(BAUDRATE_SERIAL_DEBUG);
    SPI.begin(RADIO_SCLK_PORT, RADIO_MISO_PORT, RADIO_MOSI_PORT);
    os_init();
    LMIC_reset();
    memcpy_P(appskey, APPSKEY, sizeof(APPSKEY));
    memcpy_P(nwkskey, NWKSKEY, sizeof(NWKSKEY));
    LMIC_setSession (0x13, DEVADDR, nwkskey, appskey);
    for (b=0; b<8; ++b) 
        LMIC_disableSubBand(b);

    LMIC_enableChannel(0); // 915.2 MHz
    LMIC_enableChannel(1); // 915.4 MHz
    LMIC_enableChannel(2); // 915.6 MHz
    LMIC_enableChannel(3); // 915.8 MHz
    LMIC_enableChannel(4); // 916.0 MHz
    LMIC_enableChannel(5); // 916.2 MHz
    LMIC_enableChannel(6); // 916.4 MHz
    LMIC_enableChannel(7); // 916.6 MHz
    LMIC_setAdrMode(0);
    LMIC_setLinkCheckMode(0);
    LMIC.dn2Dr = DR_SF12CR;
    LMIC_setDrTxpow(DR_SF12, GANHO_LORA_DBM);
    randomSeed(0);
    do_send(&sendjob);
}

void loop() 
{
    os_runloop_once();    
}