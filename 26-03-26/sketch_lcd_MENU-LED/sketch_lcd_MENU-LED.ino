#include <LiquidCrystal.h>

/// config lcd
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// LED VERDE
#define led_verde 7

// DEFINIR ESTADOS DE MENU
enum Estado {MENU, LIGAR, DESLIGAR, SAIR};
Estado estadoAtual = MENU;
Estado ultimoEstado = 2;

void setup() {
pinMode(led_verde, OUTPUT);
lcd.begin(16, 2);
Serial.begin(9600);

}
// FUNÇÃO MENU
void mostrarMenu() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("L-Luz ON");
  lcd.setCursor(0,1);
  lcd.print("D-Luz OFF ");
  lcd.print("2-Sair");
  Serial.println("\n--- MENU ---");
  Serial.println("l - Luz acende");
  Serial.println("d - Luz desliga");
  Serial.println("2 - Sair");
  Serial.print("op: ");
}

// função ligar
void ligar(){
  lcd.clear();
  lcd.print("Luz Ligada!");
  digitalWrite(led_verde, HIGH);
}

// função desligar
void desligar(){
  lcd.clear();
  lcd.print("luz desligada!");
  digitalWrite(led_verde, LOW);
}

void loop() {

  if(estadoAtual != ultimoEstado){/// if para lembrar do ultimo estado e nao rodar infinitamente menu

    // switch definar estado atual como se fossem funções
    switch(estadoAtual){
      case MENU:
        mostrarMenu();
        break;

      case LIGAR:
      ligar();
      delay(2500);
      estadoAtual = MENU; // para voltar ao menu
      break;

      case DESLIGAR:
      desligar();
      delay(2500);
      estadoAtual = MENU; // voltar menu
      break;

      case SAIR:
      lcd.clear();
      lcd.print("sistema parado!");
      digitalWrite(led_verde, LOW);
      while(true);
      break;
    }//fim switch
    ultimoEstado = estadoAtual;
  }//fim if

  //VERIFICAÇÃO DE ESTADO ATUAL
  if(Serial.available() > 0){
    char op = Serial.read();

    //if para ignorar o enter le
    if(op == '\n' || op == '\r') return;

    //muda o estado de acordo com a opção
    switch(op){
      case 'L': estadoAtual = LIGAR; break;
      case 'D': estadoAtual = DESLIGAR; break;
      case '2': estadoAtual = SAIR; break;
      default:
      lcd.clear();
      lcd.print("opcao invalida!");
      delay(2000);
      estadoAtual = MENU;
      break;
    }


  }

}