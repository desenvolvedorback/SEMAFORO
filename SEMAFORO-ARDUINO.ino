const int ledVermelho = 9;
const int ledAmarelo = 10;
const int ledVerde = 11;
const int pinoBotao = 2;

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(pinoBotao, INPUT_PULLUP);
}

void loop() {
  // 🟢 FASE 1: VERDE (Ciclo normal dura 5 segundos)
  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);
  
  // Em vez de dar um delay(5000), dividimos em 50 pedacinhos de 100ms.
  // Assim, o Arduino checa o botão 10 vezes por segundo!
  for (int i = 0; i < 50; i++) {
    delay(100); 
    // Se o pedestre apertar o botão, quebra o tédio e vai direto para o amarelo!
    if (digitalRead(pinoBotao) == LOW) {
      break; 
    }
  }

  // 🟡 FASE 2: AMARELO (Dura 2 segundos)
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, HIGH);
  delay(2000); 

  // 🔴 FASE 3: VERMELHO (Dura 5 segundos para travessia)
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, HIGH);
  delay(5000); 
  
  // O loop reinicia, abrindo o verde de novo no ciclo normal.
}
