String InBytes;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    InBytes=Serial.readStringUntil('\n');
    if(InBytes=="led on"){
      digitalWrite(13,HIGH);
      Serial.write("Led On");
    }
    if(InBytes=="led off"){
      digitalWrite(13,LOW);
      Serial.write("Led Off");
    }
    if(InBytes=="alarm on"){
      digitalWrite(12,HIGH);
      Serial.write("Alar, On");
    }
    if(InBytes=="alarm off"){
      digitalWrite(12,LOW);
      Serial.write("Alarm Off");
    }
    else{
      Serial.write("Invalid Input");
    }
  }
}
