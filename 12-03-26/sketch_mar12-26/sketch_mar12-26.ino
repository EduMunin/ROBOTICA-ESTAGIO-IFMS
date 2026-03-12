#define led_verde 3
#define led_vermelha 4
char opcao;
void setup() {
  pinMode(led_verde,OUTPUT);
  pinMode(led_vermelha,OUTPUT);
  Serial.begin(9600);
  //painel de escolhas
  Serial.println("------------------");
  Serial.println("R - liga vermelha");
  Serial.println("r - desliga vermelha");
  Serial.println("G - liga verde");
  Serial.println("g - desliga verde");

}

void loop() {
  opcao = Serial.read();
  if (opcao == 'G') {
  digitalWrite(led_verde, HIGH);
  } else if (opcao == 'g'){
    digitalWrite(led_verde, LOW);
  } else if (opcao == 'R'){
    digitalWrite(led_vermelha, HIGH);
  } else if (opcao == 'r'){
    digitalWrite(led_vermelha, LOW);
  }

}
