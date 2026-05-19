🚦 Semáforo Inteligente com Botão de Pedestres (Treino de Automação)
Este projeto é uma evolução do semáforo básico com Arduino. Foi desenvolvido para treinar conceitos intermédios de automação e lógica de programação, como a leitura de entradas digitais (digitalRead), o uso de resistores internos (INPUT_PULLUP) e técnicas para evitar o travamento do código por completo com a função delay().

O sistema funciona em modo cíclico normal (Verde -> Amarelo -> Vermelho), mas monitoriza um botão de pedestres em tempo real. Se o botão for pressionado enquanto o sinal está verde para os carros, o Arduino interrompe o tempo de espera e acelera a abertura do sinal fechado para a travessia dos pedestres.
![Foto do Circuito](./circuito-v2.jpg)


🛠️ Componentes Utilizados
1x Placa Arduino (Uno, Nano ou Mega)

1x Protoboard (Matriz de contatos)

3x LEDs (1 Vermelho, 1 Amarelo, 1 Verde)

1x Botão Pulsador (Push Button)

3x Resistores (Recomendado de 220Ω a 330Ω para os LEDs)

Cabos Jumper (Macho x Macho)

🔌 Esquema de Ligação (Hardware)
Pino Digital 9: LED Vermelho (Carros Param)

Pino Digital 10: LED Amarelo (Atenção)

Pino Digital 11: LED Verde (Carros Siga)

Pino Digital 2: Botão de Pedestres (Conectado diretamente ao GND)

GND (Terra): Comum para todos os catodos dos LEDs (via resistores) e para o botão.

💻 Código-Fonte (SEMAFORO-ARDUINO.ino)
O grande destaque deste código é a divisão do tempo do LED Verde em pequenos blocos dentro de um ciclo for. Isso permite que o Arduino verifique o estado do botão várias vezes por segundo, quebrando a limitação tradicional da função delay().

C++
// Definição dos pinos para organização do código
const int ledVermelho = 9;
const int ledAmarelo = 10;
const int ledVerde = 11;
const int pinoBotao = 2;

void setup() {
  // Configura os pinos dos LEDs como saídas
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  
  // INPUT_PULLUP ativa o resistor interno do Arduino.
  // O pino do botão lê HIGH por padrão e LOW quando é pressionado.
  pinMode(pinoBotao, INPUT_PULLUP);
}

void loop() {
  // 🟢 FASE 1: VERDE (O ciclo normal duraria 5 segundos)
  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);
  
  // Divide os 5 segundos em 50 partes de 100 milissegundos.
  // Permite ler o botão 10 vezes por segundo enquanto o sinal está verde!
  for (int i = 0; i < 50; i++) {
    delay(100); 
    
    // Se o pedestre carregar no botão (LOW), interrompe o Verde imediatamente
    if (digitalRead(pinoBotao) == LOW) {
      break; // Sai do laço "for" e avança para a fase amarela
    }
  }

  // 🟡 FASE 2: AMARELO (Atenção para os carros - 2 segundos)
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, HIGH);
  delay(2000); 

  // 🔴 FASE 3: VERMELHO (Carros param para a travessia - 5 segundos)
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, HIGH);
  delay(5000); 
  
  // O loop reinicia e o sinal volta a abrir o Verde para os carros.
}
🧠 Aprendizados neste Projeto
Uso do INPUT_PULLUP: Aprendizado prático sobre como economizar componentes físicos utilizando os resistores internos do microcontrolador, invertendo a lógica de leitura para LOW quando acionado.

Controlo de Fluxo não-bloqueante simples: Substituição de um delay(5000) longo por um laço de repetição com verificação condicional (if + break), garantindo a responsividade do botão sem complicar a estrutura do código.

Este projeto faz parte dos meus estudos práticos de lógica de programação, eletrônica básica e automação de sistemas.
