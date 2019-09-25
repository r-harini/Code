int LED = 13; // Use the onboard Uno LED
int obstaclePin = A0;  // This is our input pin
int hasObstacle = HIGH;  // HIGH MEANS NO OBSTACLE

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(obstaclePin, INPUT);
  Serial.begin(9600);  
}
void loop() {
  hasObstacle = analogRead(obstaclePin); //Reads the output of the obstacle sensor from the 7th PIN of the Digital section of the arduino
  Serial.println(hasObstacle);
  delay(200);
}
