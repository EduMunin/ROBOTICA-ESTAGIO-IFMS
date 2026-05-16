const int buzzer = 8; // Pino onde o buzzer está conectado

void setup() {
  pinMode(buzzer, OUTPUT); // Define o pino do buzzer como saída
}

void loop() {
  tone(buzzer, 1000); // Emite um som de 1000Hz (1kHz)
  delay(1000);        // Espera 1 segundo
  noTone(buzzer);     // Para o som
  delay(1000);        // Espera 1 segundo
}
