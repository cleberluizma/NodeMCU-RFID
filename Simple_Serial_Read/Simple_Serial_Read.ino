/* RFID ID12 */

char val; // variable to store the data from the serial port

void setup()
{
Serial.begin(9600); // connect to the serial port
}

void loop ()

{
// read the serial port
  if(Serial.available() > 0)
  {
  val = Serial.read();
  Serial.print(val);
  }
}