int ledR = 2;
int ledG = 4;
int ledB = 6;

int sensor;
int value;
bool flag = true;
 
void setup() {
  // put your setup code here, to run once:
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);

  Serial.begin(9600);
}

void setColor(int red, int green, int blue) {
  analogWrite(ledR, red);
  analogWrite(ledG, green);
  analogWrite(ledB, blue);
}

void exerciseOne() {
  setColor(255, 128, 0);
  delay(2000);

  setColor(0,0,255);
  delay(2000);

  setColor(0,255,255);
  delay(2000);
}

void exerciseTwo() {
  sensor = analogRead(A0);
  value = (sensor * 5.0) / 1023;

  Serial.print("Voltaje: ");
  Serial.print(value);
  Serial.println("V");

  delay(1000);
}

void exerciseValued() {

  sensor = analogRead(A0);
  value = (sensor * 5.0) / 1023;

  if(value < 1) {
    setColor(255, 0, 0);
  } 

  if (value >= 1 && value < 2) {
    setColor(0,255,0);
  }

  if (value >= 2) {
    setColor(0,0,255);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (flag) {
    exerciseOne();
  } else 
    exerciseTwo();

  flag = !flag;
}
