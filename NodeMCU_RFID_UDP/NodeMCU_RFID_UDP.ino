char ID ; //Variável para armazenar o caractere que foi recebido da ID que

 

void setup()
{

  Serial.begin(9600); //Inicia a serial com um baud rate de 9600

}

 

void loop ()
{

  if(Serial.available() > 0) //Se a serial receber algum caractere
  {
    ID = Serial.read(); //Armazena na variável ID o caractere recebido
    Serial.print(ID); //Imprime na serial o caaractere recebido
  }

 

}
