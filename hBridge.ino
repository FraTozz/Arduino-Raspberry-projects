
#define Ad 13
#define Bd 12
#define As 7
#define Bs 8
#define Power 11

int sagSpeed = 127;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(19200);
  pinMode(Bd, OUTPUT);
  pinMode(Ad, OUTPUT);
  pinMode(Bs, OUTPUT);
  pinMode(As, OUTPUT);
  pinMode(Power, OUTPUT);
  pinMode(beep, OUTPUT);

  
}

// the loop function runs over and over again forever
void loop() {
  
  

  //Check for any incoming bytes
  if (Serial.available() > 0){
    char newChar = Serial.read();
    if (newChar == 'p')//increase speed
    {
      if (sagSpeed < 205){
      sagSpeed = sagSpeed + 50;
      }
    }  
    
    if (newChar == 'm')
    {
      if(sagSpeed > 50){
        sagSpeed = sagSpeed - 50;
      }
    }
    
    if (newChar == 'w') //go forward
    {
      analogWrite(Power, sagSpeed);
      digitalWrite(Bd, LOW);
      digitalWrite(Ad, HIGH);
      digitalWrite(Bs, HIGH);
      digitalWrite(As, LOW);
      delay(120);
    }

    if (newChar == 's')//go backward
    {
      analogWrite(Power, sagSpeed);
      digitalWrite(Bd, HIGH);
      digitalWrite(Ad, LOW);
      digitalWrite(Bs, LOW);
      digitalWrite(As, HIGH);
      delay(120);
    }

    if (newChar == 'd') //turn right
    {
      analogWrite(Power, sagSpeed);
      digitalWrite(Bd, HIGH);
      digitalWrite(Ad, LOW);
      digitalWrite(Bs, HIGH);
      digitalWrite(As, LOW); 
      delay(120);
    }

    if (newChar == 'a') //turn left
    {
      analogWrite(Power, sagSpeed);
      digitalWrite(Bs, LOW);
      digitalWrite(As, HIGH);
      digitalWrite(Bd, LOW);
      digitalWrite(Ad, HIGH); 
      delay(120);
    }

    
  }
  else {
    digitalWrite(As, LOW);
    digitalWrite(Bs, LOW);
    digitalWrite(Ad, LOW);
    digitalWrite(Bd, LOW);
  }
}
