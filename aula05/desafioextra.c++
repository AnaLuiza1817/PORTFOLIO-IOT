// C++

const int LED1 = 11;
const int LED2 = 4;
const int BOTAO = 3;

int estado = 0;
int ultimoEstadoBotao = HIGH;
int botaoAtual;
unsigned long ultimoTempoDebounce = 0;
const unsigned long delayDebounce = 50;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BOTAO, INPUT_PULLUP);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
}

void loop() {
  int leitura = digitalRead(BOTAO);
  
  if (leitura != ultimoEstadoBotao) {
    ultimoTempoDebounce = millis();
  }
  
  if ((millis() - ultimoTempoDebounce) > delayDebounce) {
    if (leitura != botaoAtual) {
      botaoAtual = leitura;
      
      if (botaoAtual == LOW) {
        estado++;
        if (estado > 3) {
          estado = 0;
        }
        
        switch(estado) {
          case 0:
            digitalWrite(LED1, HIGH);
            digitalWrite(LED2, LOW);
            break;
          case 1:
            digitalWrite(LED1, LOW);
            digitalWrite(LED2, HIGH);
            break;
          case 2:
            digitalWrite(LED1, LOW);
            digitalWrite(LED2, LOW);
            break;
          case 3:
            digitalWrite(LED1, HIGH);
            digitalWrite(LED2, LOW);
            break;
        }
      }
    }
  }
  
  ultimoEstadoBotao = leitura;
}
