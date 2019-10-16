/******************************************/
// Este é o programa transmissor.
// Envia dados para um pipe 0.
// Transceiver: nRF24L01+
/******************************************/

#include <SPI.h>                                                    // Biblioteca de comunicação SPI
#include <RF24.h>                                                   // Inclui a biblioteca do nRF24L01+

RF24 myRadio(8,9);                                                 // Cria o objeto myRadio - CE,CSN
byte AdressPipe[6] = {"0pipe"};                                   // Cria um canal de comunição - PIPE0

void setup() 
{
    Serial.begin(9600);
    delay(1000);                                                    // Coloca o pino Ch1 como entrada e ativa o pullup
    myRadio.setChannel(100);                                          // Seleciona o canal do radio
    myRadio.setPALevel(RF24_PA_MAX);                                // Ajusta a potencia do radio para a máxima
    myRadio.setDataRate(RF24_250KBPS);                              // Ajusta a taxa de comunicação para 250K bits por segundo
    myRadio.setAutoAck(false);                                      // Desliga o ACK
    myRadio.openWritingPipe(AdressPipe[0]);                         // Abre o canal 0pipe
}

void loop() 
{ 
    int x = 7;
    if(myRadio.available())
    {// Cria uma variável para ser enviada
      myRadio.write(&x, sizeof(x));                                  
      delay(1000);
    }                                                    
}
