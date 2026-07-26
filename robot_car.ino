// Motor A pins
int ENA = D5;   // GPIO14
int IN1 = D1;   // GPIO5
int IN2 = D2;   // GPIO4

// Motor B pins
int ENB = D6;   // GPIO12
int IN3 = D3;   // GPIO0
int IN4 = D4;   // GPIO2

void setup() {

  Serial.begin(9600);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.println("Send Command: F,B,L,R,S");
}

// ------------ Movement Functions --------------

void forward() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 1023);
  analogWrite(ENB, 1023);

  Serial.println("Moving FORWARD");
}

void backward() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, 1023);
  analogWrite(ENB, 1023);

  Serial.println("Moving BACKWARD");
}

void leftTurn() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 1023);
  analogWrite(ENB, 1023);

  Serial.println("Turning LEFT");
}

void rightTurn() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, 1023);
  analogWrite(ENB, 1023);

  Serial.println("Turning RIGHT");
}

void stopMotor() {

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  Serial.println("STOPPED");
}

// ---------------- MAIN LOOP -------------------

void loop() {

  if (Serial.available()) {

    char cmd = Serial.read();
    cmd = toupper(cmd);

    switch (cmd) {

      case 'F':
        forward();
        break;

      case 'B':
        backward();
        break;

      case 'L':
        leftTurn();
        break;

      case 'R':
        rightTurn();
        break;

      case 'S':
        stopMotor();
        break;

      default:
        Serial.println("Invalid Command!");
    }
  }
}
