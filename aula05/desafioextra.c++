const int botao = 2;
const int rele1 = 12;
const int rele2 = 8;

int estado = 0;
int ultimoEstadoBotao = HIGH;
int botaoAtual;

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);

  digitalWrite(rele1, LOW);
  digitalWrite(rele2, LOW);
}

void loop() {
  botaoAtual = digitalRead(botao);

  if (ultimoEstadoBotao == HIGH && botaoAtual == LOW) {
    estado++;

    if (estado > 2) {
      estado = 0;
    }

    switch (estado) {
      case 0:
        digitalWrite(rele1, LOW);
        digitalWrite(rele2, LOW);
        break;

      case 1:
        digitalWrite(rele1, HIGH);
        digitalWrite(rele2, LOW);
        break;

      case 2:
        digitalWrite(rele1, HIGH);
        digitalWrite(rele2, HIGH);
        break;
    }

    delay(200);
  }

  ultimoEstadoBotao = botaoAtual;
}
