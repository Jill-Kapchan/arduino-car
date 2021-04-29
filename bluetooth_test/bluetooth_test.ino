#include "SoftwareSerial.h"
// TX on 10
// RX on 11
//SoftwareSerial serial_connection(10, 11);

#define TxD 0
#define RxD 1
SoftwareSerial serial_connection(TxD, RxD);
#define BUFFER_SIZE 64


//This is a character buffer where the data sent by the python script will go.
char inData[BUFFER_SIZE];
char inChar = -1;

//This is the number of lines sent in from the python script
int count = 0;
int i = 0;

void setup()
{
  Serial.begin(9600);
  serial_connection.begin(9600);
  serial_connection.println("Ready!!!");
  Serial.println("Started");
}

void loop()
{
  //This will prevent bufferoverrun errors
  //This gets the number of bytes that were sent by the python script
  byte byte_count = serial_connection.available();
  
  if (byte_count)
  {
    Serial.println("Incoming Data");
    int first_bytes = byte_count;
    int remaining_bytes = 0;
    if (first_bytes >= BUFFER_SIZE - 1)
    {
      remaining_bytes = byte_count - (BUFFER_SIZE - 1);
    }
    
    for (i = 0; i < first_bytes; i++) //Handle the number of incoming bytes
    {
      inChar = serial_connection.read(); //Read one byte
      inData[i] = inChar; //Put it into a character string(array)
    }

    //This ends the character array with a null character. This signals the end of a string
    inData[i] = '\0'; 
    if (String(inData) == "A")
    {
      Serial.println("Letter A");
    }
    else if (String(inData) == "B")
    {
      Serial.println("LETTER B");
    }
    for (i = 0; i < remaining_bytes; i++)
    {
      inChar = serial_connection.read();
    }
    
    Serial.println(inData);
    serial_connection.println("Hello from Blue " + String(count));
    count++;
  }
  else
  {
    Serial.println("Not connected");
  }
  delay(1000);
}
