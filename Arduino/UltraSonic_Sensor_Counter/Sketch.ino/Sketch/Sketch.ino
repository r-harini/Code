#define trigPin 13
#define echoPin 12
int counter=0;
int currentState=0;
int previousState=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance=(duration/2)/29.1;
  if(distance<=20){
    currentState=1;
  }
  else{
    currentState=0;
  }
  delay(100);
  if (currentState!=previousState){
    if (currentState==1){
      counter=counter+1;
      Serial.println(counter);
    }
  }
 
}
