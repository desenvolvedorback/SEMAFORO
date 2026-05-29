// --- SEMÁFORO 1 ---
int vermelho1 = 2;
int amarelo1  = 3;
int verde1    = 4;

// --- SEMÁFORO 2 ---
int vermelho2 = 5;
int amarelo2  = 6;
int verde2    = 7;

void setup() {
  // Configura todos os pinos como saída
  pinMode(vermelho1, OUTPUT);
  pinMode(amarelo1, OUTPUT);
  pinMode(verde1, OUTPUT);
  
  pinMode(vermelho2, OUTPUT);
  pinMode(amarelo2, OUTPUT);
  pinMode(verde2, OUTPUT);
}

void loop() {

  digitalWrite(verde1, HIGH);
  digitalWrite(amarelo1, LOW);
  digitalWrite(vermelho1, LOW);
  
  digitalWrite(verde2, LOW);
  digitalWrite(amarelo2, LOW);
  digitalWrite(vermelho2, HIGH);
  delay(5000); 


  digitalWrite(verde1, LOW);
  digitalWrite(amarelo1, HIGH);
  delay(2000); 

 
  digitalWrite(amarelo1, LOW);
  digitalWrite(vermelho1, HIGH);
  
  digitalWrite(vermelho2, LOW);
  digitalWrite(verde2, HIGH);
  delay(5000); 


  
  digitalWrite(verde2, LOW);
  digitalWrite(amarelo2, HIGH);
  delay(2000); 
  
}
