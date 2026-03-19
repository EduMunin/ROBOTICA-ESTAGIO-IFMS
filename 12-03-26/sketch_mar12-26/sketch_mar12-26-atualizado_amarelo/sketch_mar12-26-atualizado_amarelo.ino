#define led_verde 3
#define led_vermelha 4
#define led_amarela 5
char opcao;
void setup() {
  pinMode(led_verde,OUTPUT);
  pinMode(led_vermelha,OUTPUT);
  pinMode(led_amarela, OUTPUT);
  Serial.begin(9600);
  //painel de escolhas
  Serial.println("------------------");
  Serial.println("R - liga vermelha");
  Serial.println("r - desliga vermelha");
  Serial.println("G - liga verde");
  Serial.println("g - desliga verde");
  Serial.println("Y - liga amarela");
  Serial.println("y - desliga amarela");

}

void loop() {
  opcao = Serial.read();
  if (opcao == 'G') {
    delay(1000);
  digitalWrite(led_verde, HIGH);
  } else if (opcao == 'g'){
    delay(1000);
    digitalWrite(led_verde, LOW);
  } else if (opcao == 'R'){
    delay(1000);
    digitalWrite(led_vermelha, HIGH);
  } else if (opcao == 'r'){
    delay(1000);
    digitalWrite(led_vermelha, LOW);
  } else if (opcao == 'Y'){
    delay(1000);
    digitalWrite(led_amarela, HIGH);
  } else if (opcao == 'y'){
    delay(1000);
    digitalWrite(led_amarela, LOW);
  }

}
