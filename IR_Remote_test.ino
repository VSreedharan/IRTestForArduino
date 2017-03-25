// example 32.1 - IR receiver code repeater
// http://tronixstuff.com/tutorials > chapter 32
// based on code by Ken Shirriff - http://arcfn.com
 
#include <IRremote.h> // use the library

IRrecv irrecv(10); // create instance of 'irrecv'
decode_results results;

int LED_PIN = 5;


void setup()
{

  irrecv.enableIRIn(); // Start the receiver
  Serial.begin(9600); // for serial monitor output
  while (!Serial) {
     ; // wait for serial port to connect. Needed for native USB port only
   }
  Serial.println("Goodnight moon!");

  pinMode(LED_PIN, OUTPUT);

}


void indicateDataReceived ()  {
  digitalWrite(LED_PIN,HIGH);
  delay(250);
  digitalWrite(LED_PIN,LOW);
  
}

void translateIR() // takes action based on IR code received
// describing Sony IR codes on LCD module
{
  switch(results.value)
  {
    case 0x499B750A: Serial.println(" Power button   "); indicateDataReceived();break;
    case 0x59B558AC:  Serial.println(" zero            "); indicateDataReceived();break;
    case 0x7D03709:  Serial.println(" one            "); indicateDataReceived();break;
    case 0x7AD7A7D9:  Serial.println("  two           "); indicateDataReceived();break;
    case 0x77D7A320:  Serial.println(" three          "); indicateDataReceived();break;
    case 0x1FF256EE:  Serial.println(" four           "); indicateDataReceived();break;
    case 0xDFF8AB96:  Serial.println(" five           "); indicateDataReceived();break;
    case 0x5CD90715:  Serial.println(" six            "); indicateDataReceived();break;
    case 0x5FD90BCC:  Serial.println(" seven          "); indicateDataReceived();break;
    case 0x54BEF27E:  Serial.println(" eight          "); indicateDataReceived();break;
    case 0x5D69140F:  Serial.println(" nine           "); indicateDataReceived();break;
    case 0xC31D712E:  Serial.println(" volume up      "); indicateDataReceived();break;
    case 0x49F4E73F:  Serial.println(" volume down    "); indicateDataReceived();break;
    case 0x5BBC35BE:   Serial.println(" channel up     "); indicateDataReceived();break;
    case 0xB23554F:  Serial.println(" channel down   "); indicateDataReceived();break;
    default: 
      Serial.println(results.value, HEX);
      break; 
  }

}

void loop()
{
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    translateIR();
//     for (int z=0; z<2; z++) 
        irrecv.resume(); // receive the next value
  }  // Your loop can do other things while waiting for an IR command

  delay(200);
}



