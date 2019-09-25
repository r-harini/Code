void setup() {
  pinMode(13,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13,1);
  delay(1000);
  digitalWrite(13,0);
  delay(1000);

}
