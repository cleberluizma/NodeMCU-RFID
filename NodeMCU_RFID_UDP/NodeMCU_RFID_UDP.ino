//inico do cod. Cleber Miyakpoda.

//--------------includes-----------------------------------------------------
#include <ESP8266WiFi.h>//Biblioteca do WiFi.
#include <WiFiUdp.h>//Biblioteca do UDP.

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
WiFiUDP udp;//Cria um objeto da classe UDP.
long x;//Variavel para ser enviada.
//---------------------------------------------------------------------------

//----------------------------------------------------------------------------
String datafw = "29/09/2022";
String versaofw = "01-RFID125";
char ID ; //Variável para armazenar o caractere que foi recebido da ID que
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
void setup()
{
 Serial.begin(9600); //Inicia a serial

  //----------------------------executa apenas uma vez
  Serial.println();
  Serial.println(datafw);
  Serial.println(versaofw);
  Serial.println("Inicializando........");
  Serial.println();
  //-----------------------------------------------------------
  
  pinMode(D4, OUTPUT);//Habilita o LED onboard como saida.
  digitalWrite(D4, 1);//Desliga o LED.
  WiFi.mode(WIFI_STA);//Define o ESP8266 como Station.

}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void loop ()
{
//------------------leitura cartao rfid em rx serial port----------------
  if(Serial.available() > 0) //Se a serial receber algum caractere
  {
    ID = Serial.read(); //Armazena na variável ID o caractere recebido
    Serial.print(ID); //Imprime na serial o caaractere recebido
  }
//------------------------------------------------------------------------
//------------------------------------------------------------------------
  connect();//Sub-rotina para conectar-se ao host.
  send();//Sub-rotina para enviar os dados ao host.
  delay(500);//Aguarda meio segundo. 
//------------------------------------------------------------------------
}
//-------end void loop------------------------------------------------------------------------

void send()//Sub-rotina para enviar dados ao host.
{
   if (WiFi.status() == WL_CONNECTED)//Só ira enviar dados se estiver conectado.
   {
      x = random(0, 1000);//Gera um numero aleatorio entre 0 e 1000.
      udp.beginPacket("192.168.1.6", 6000);//Inicializa o pacote de transmissao ao IP e PORTA.
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







