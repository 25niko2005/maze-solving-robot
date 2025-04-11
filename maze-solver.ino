#define trigPin1 8
#define echoPin1 9
#define trigPin2 A5
#define echoPin2 A3
#define trigPin3 A0
#define echoPin3 A1

#define enA 5
#define enB 6
#define motor1A 2
#define motor1B 3
#define motor2A 4
#define motor2B 10

int Mspeed=60;
int dis=20;
int sideDis= 7;

void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud rate
  
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
}

long readDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;  // Speed of sound = 0.034 cm/us
  return distance;
}

void moveForward() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, Mspeed);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, Mspeed);

  analogWrite(enA, Mspeed);
  analogWrite(enB, Mspeed);
  Serial.println("Moving Forward");
}

void turnBack() {
  turnLeft();
  delay(700);
  Serial.println("turning Back");
}

void turnLeft() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, Mspeed);
  digitalWrite(motor2A, Mspeed);
  digitalWrite(motor2B, LOW);

  analogWrite(enA, Mspeed);
  analogWrite(enB, Mspeed);
  Serial.println("Turning Left");
}

void turnRight() {
  digitalWrite(motor1A, Mspeed);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, Mspeed);

  analogWrite(enA, Mspeed);
  analogWrite(enB, Mspeed);
  Serial.println("Turning Right");
}

void stopMotors() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW);

  Serial.println("Motors Stopped");
  delay(500);
}


void loop() {
  long frontDistance = readDistance(trigPin1, echoPin1);
  long leftDistance = readDistance(trigPin2, echoPin2);
  long rightDistance = readDistance(trigPin3, echoPin3);
  
  // Output the sensor readings to Serial Monitor
  Serial.print("Front Distance: ");
  Serial.print(frontDistance);
  Serial.print(" cm, Left Distance: ");
  Serial.print(leftDistance);
  Serial.print(" cm, Right Distance: ");
  Serial.print(rightDistance);
  Serial.println(" cm");
  
  if(leftDistance > dis){
    turnLeft();
  }
  else if(frontDistance > dis ){
    moveForward();
  }
  else if(rightDistance > dis){
    turnRight();
  }
  else{
    turnBack();
  }
  if(leftDistance < sideDis){
    turnRight();
  }
  if(rightDistance < sideDis){
    turnLeft();
  }

  
  delay(50);  // Small delay for stability
}

