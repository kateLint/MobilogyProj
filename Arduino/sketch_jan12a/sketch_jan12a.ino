char junk;
String inputString="";

int led =13;
int piezoPin = 8;
boolean stringComplete = false; 

void setup() {
  
  
 while(!Serial)
    Serial.begin(9600);

 inputString.reserve(200);
 pinMode(led,OUTPUT);
 // Serial.begin(9600);
 // digitalWrite(led, LOW);
}

void loop() {
 
 // print the string when a newline arrives:
  if (stringComplete) {
    Serial.println(inputString);
    tone(piezoPin, 1000, 500);
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
  

/* if(Serial.available() < 0)
{
   tone(piezoPin, 1000, 500);
   char inChar = (char)Serial.read();
// say what you got:
              
                Serial.println(inChar, DEC);

   
  while(Serial.available())
  {
  
 

        //tone( pin number, frequency in hertz);
    
      
    if(inChar == '1'){
      //LED off
      digitalWrite(led, LOW);
      tone(piezoPin, 500, 20);
    }
    if (inChar == '0')
    {
      //LED on
      digitalWrite(led, HIGH);
        
      //tone( pin number, frequency in hertz);
      tone(piezoPin, 1000, 500);
    }
   // inputString += inChar;
   //  Serial.println(inChar);
  }

 /* while (Serial.available() >0)
  {
    junk = Serial.read();
  }
  inputString = ""; */
} 


/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
       tone(piezoPin, 1000, 500);
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}


