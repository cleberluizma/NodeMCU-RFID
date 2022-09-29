/* RFID ID12 */

//declarações
char val; // variable to store the data from the serial port
//String tag_lida = "00000000000000"; //cria a variavel como string 14 posições tag lida, e já limpando a leitura
String tag_lida[14];
int i; //variavel para contagem 
//////

///função le tag
void le_tag()
{
i=0; //zera count
  while(Serial.available() > 0) //enquanto serial receber dados
  {
  tag_lida[i] = Serial.read(); //armazena o caractere que entrou na posicao de entrada na string
  i++; //incrementa count
  //Serial.println(i); //pula linha na serial
  }

  Serial.print("\n\n TAG Lida:"); //pula duas linhas e imrime info na serial
  for(i=0;i<13;i++) Serial.print(tag_lida[i]); //pega cada posição da id e imprime a mesma na serial
  //Serial.println('tag_lida');
}

///função limpa buffer tag
void limpa_tag()
{
 for (i=0;i<13;i++) tag_lida[i] = '0'; //zera buffer tags

}






///setup pins e etc
void setup()
{
Serial.begin(9600); // inicia a serial a 9600
}
///////////////////////////////

///////////////////main loop
void loop ()

{
// read the serial port
  if(Serial.available() > 0) //se a serial receve info
  {
  le_tag(); //funão de leitura de tag
  limpa_tag(); //zera buffer
  
  //val = Serial.read();
  //Serial.print(val);
  //Serial.print("|");
  //Serial.print(val, HEX);
  //Serial.print("--");

  }




}