#define trigPin 13
#define echoPin 12
#define led 11
#define led2 10

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin,HIGH);
  //duration=(duration/2)/29.1;
  distance = duration * 0.034 / 2;

  if (distance<10){
    digitalWrite(led,HIGH);
    digitalWrite(led2,LOW);
    //Serial.println("Less than 5");
    //Serial.println(distance);
  }
  else{
    digitalWrite(led, LOW);
    digitalWrite(led2,HIGH);
    //Serial.println("More than 5");
  }
  if (distance>=20||distance<=0){
    Serial.println("Out of range");
  }
  else{
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(1000);
}
