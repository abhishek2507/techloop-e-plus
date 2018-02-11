const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte new_state=LOW;
int old_value = HIGH; 
int new_value;      
long time = 0;   
long diffrence = 10;   

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  attachInterrupt(0, change_blink, CHANGE);                                        //Defining the interrupt pin 2 and using it to trigger change_blink function below

}

void loop() {
  if (new_state==LOW)                                                              //The state here changes from the change_blink function below 
 {digitalWrite(ledPin, HIGH);
 delay(1000);
 digitalWrite(ledPin,LOW);}
 if (new_state==HIGH)
{ digitalWrite(ledPin,HIGH);
 delay(2000);
 digitalWrite(ledPin,LOW);
 } 

}
void change_blink(){
 new_value = digitalRead(interruptPin);                                            //This will start interrpt based on the way button is pressed
  if (new_value == HIGH && old_value == LOW && millis() - time > diffrence)        //
  {
    if (new_value == HIGH)                                                         //Changing the state which will change the delay in the main loop 
      new_state = LOW;                                                            
    else
      new_state = HIGH;

    time = millis();                                                              //Used to record the time when button was last pressed n store it in time
  }
old_value = new_value;                                                            //changing the old value of button
}
