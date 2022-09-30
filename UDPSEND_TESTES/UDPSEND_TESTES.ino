#include <ESP8266WiFi.h>//Biblioteca do WiFi.
#include <WiFiUdp.h>//Biblioteca do UDP.
WiFiUDP udp;//Cria um objeto da classe UDP.
long x;//Variavel para ser enviada.
void setup()
{
   pinMode(D4, OUTPUT);//Habilita o LED onboard como saida.
   digitalWrite(D4, 1);//Desliga o LED.

//--
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin("MTGTECH", "ORDNA123");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(500);
  }
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());
//--
}
void loop()
{
   //connect();//Sub-rotina para conectar-se ao host.
   send();//Sub-rotina para enviar os dados ao host.
   delay(500);//Aguarda meio segundo.
}

void send()//Sub-rotina para enviar dados ao host.
{
   if (WiFi.status() == WL_CONNECTED)//Só ira enviar dados se estiver conectado.
   {
      x = random(0, 1000);//Gera um numero aleatorio entre 0 e 1000.
      udp.beginPacket("192.168.1.6", 6001);//Inicializa o pacote de transmissao ao IP e PORTA.
      udp.println(x);//Adiciona-se o valor ao pacote.
      udp.endPacket();//Finaliza o pacote e envia.
      digitalWrite(D4, 0);//-
      delay(5);//-
      digitalWrite(D4, 1);//Pisca o led rapidamente apos enviar.
   }
   else//Caso nao esteja com uma conexao estabelicida ao host, piscara lentamente.
   {
      digitalWrite(D4, 0);
      delay(250);
      digitalWrite(D4, 1);
   }
}
