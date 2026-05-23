int vermelho = 2;
int amarelo = 3;
int verde = 4;
int vermelho3 = 8;
int amarelo3 = 9;
int verde3 = 10;
int vermelho2 = 5;
int amarelo2 = 6;
int verde2 = 7;
int vermelho4 = 11;
int amarelo4 = 12;
int verde4 = 13;

void setup() {
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(vermelho2, OUTPUT);
  pinMode(amarelo2, OUTPUT);
  pinMode(verde2, OUTPUT);
  pinMode(vermelho3, OUTPUT);
  pinMode(amarelo3, OUTPUT);
  pinMode(verde3, OUTPUT);
  pinMode(vermelho4, OUTPUT);
  pinMode(amarelo4, OUTPUT);
  pinMode(verde4, OUTPUT);
}

void loop() {

  digitalWrite(verde, HIGH);
  digitalWrite(verde3, HIGH);
  digitalWrite(vermelho2, HIGH);
  digitalWrite(vermelho4, HIGH);
  delay(5000); 
  digitalWrite(verde, LOW);
  digitalWrite(verde3, LOW);
  digitalWrite(amarelo, HIGH);
  digitalWrite(amarelo3, HIGH);
  delay(2000); 
  digitalWrite(amarelo, LOW);
  digitalWrite(amarelo3, LOW);
  digitalWrite(vermelho, HIGH);
  digitalWrite(vermelho3, HIGH);
  digitalWrite(vermelho2, LOW); 
  digitalWrite(vermelho4, LOW); 
  digitalWrite(verde2, HIGH);
  digitalWrite(verde4, HIGH);
  delay(5000); 
  digitalWrite(verde2, LOW);
  digitalWrite(verde4, LOW);
  digitalWrite(amarelo2, HIGH);
  digitalWrite(amarelo4, HIGH);
  delay(2000); 
  digitalWrite(vermelho, LOW);
  digitalWrite(vermelho3, LOW);
  digitalWrite(amarelo2, LOW);
  digitalWrite(amarelo4, LOW);
}
