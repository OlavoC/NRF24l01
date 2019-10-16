/******************************************/
// Este é o programa receptor.
// Recebe dados de um pipe 0.
// Transceiver: nRF24L01+
/******************************************/

#include <SPI.h>                                                    // Biblioteca de comunicação SPI
#include <RF24.h>                                                   // Inclui a biblioteca do nRF24L01+
 
RF24 myRadio(7,8);                                                 // Cria o objeto myRadio - CE,CSN
byte AdressPipe[6] = {"0pipe"};                                   // Cria um canal de comunição - PIPE0

void setup() 
{
    Serial.begin(9600);                                              // Inicializa a serial com 9600 bps     
    myRadio.begin();                                                // Inicia o radio
    //myRadio.setChannel(100);
    //myRadio.setAutoAck(false);                                      // Desliga o ACK
    myRadio.setPALevel(RF24_PA_MAX);                                // Ajusta a potencia do radio para a máxima
    myRadio.setDataRate(RF24_250KBPS);                              // Ajusta a taxa de comunicação para 250K bits por segundo
    myRadio.openReadingPipe(1,AdressPipe[0]);                       // Abre a leitura do 0pipe
    myRadio.startListening();                                       // Inicia a leitura dos dados
    if(myRadio.available())
    {
    Serial.println("OK, receptor pronto!");                         // Receptor pronto para leitura dos dados
    }
    delay(500);                                                     // Espera 1/2 segundo
}

void loop() 
{
    while(myRadio.available())                                      // Enquanto existir dados disponíveis
    {
        int x = 5;                                                              // Cria uma variável para ser armazenada a informação recebida
        myRadio.read(&x, sizeof(x));                  // Lê o dados que chegou e envia para Contador
        Serial.print("Valor do recebido: ");                        // Imprime máscara
        Serial.println(x);                                   // Imprime a variavel Contador
    }
}
