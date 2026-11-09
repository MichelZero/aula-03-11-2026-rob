// autor: Michel
// data: 03/11/2026

// Este código controla um servomotor usando dois botões. Quando o botão conectado ao pino 3 é pressionado, o servomotor gira para 90 graus (abre). Quando o botão conectado ao pino 2 é pressionado, o servomotor retorna para 0 graus (fecha).
// Certifique-se de que os botões estejam conectados corretamente aos pinos especificados e que o servomotor esteja conectado ao pino 9.
//
#include <Servo.h>        // Importa a biblioteca Servo para controlar o servomotor

#define servo 9           // Define o pino onde o servo está conectado (pino 9)
#define botao3 3           // Define o pino do primeiro botão (abre o servo)
#define botao2 2          // Define o pino do segundo botão (fecha o servo)

// Cria um objeto chamado servomotor para controlar o servo
Servo servomotor;         // Cria um objeto chamado servomotor para controlar o servo


// A função setup() é chamada uma vez quando o programa inicia e configura os pinos e o servo
// Configura os pinos dos botões como entrada e inicializa o servo na posição 0 graus
void setup(){
  pinMode(botao3, INPUT);   // Configura o botão do pino 3 como entrada
  pinMode(botao2, INPUT);  // Configura o botão do pino 2 como entrada

  servomotor.attach(servo); // "Liga" o objeto servomotor ao pino do servo
  servomotor.write(0);      // Coloca o servo na posição inicial (0 graus)
}

// A função loop() é chamada repetidamente e contém a lógica principal do programa
// Quando o botão do pino 3 for pressionado, o servo abre (90 graus). Quando o botão do pino 2 for pressionado, o servo fecha (0 graus).
void loop(){

  // Quando o botão do pino 3 for pressionado (HIGH), abre o servo
  if (digitalRead(botao3) == HIGH){
    servomotor.write(90);    // Gira o servo para 90 graus
  }

  // Quando o botão do pino 2 for pressionado (HIGH), fecha o servo
  if (digitalRead(botao2) == HIGH){
    servomotor.write(0);    // Retorna o servo para 0 graus
  }

  delay(50);  // Pequena pausa para estabilizar a leitura dos botões
}