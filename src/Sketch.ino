#include <Servo.h> // Biblioteca para controle de motores servo

Servo servoBraco; // Controla subida e descida
Servo servoGarra; // Controla abertura e fechamento

const int LED = 7; // Pino do LED indicador de captura

void setup()
{
  Serial.begin(9600); // Inicia comunicação com o monitor serial

  servoBraco.attach(9);  // Liga o servo do braço no pino 9
  servoGarra.attach(10); // Liga o servo da garra no pino 10

  pinMode(LED, OUTPUT); // Configura o LED como saída

  servoBraco.write(90); // Posição inicial do braço (meio)
  servoGarra.write(90); // Posição inicial da garra (aberta)

  // Imprime o menu de instruções no Serial
  Serial.println("=== Docking & Retrieval ===");
  Serial.println("U = Up");
  Serial.println("D = Down");
  Serial.println("O = Open");
  Serial.println("C = Close");
}

void loop()
{
  // Verifica se o usuário enviou algum comando
  if (Serial.available())
  {
    // Lê o comando e converte sempre para maiúsculo
    char comando = toupper(Serial.read());

    // Executa a ação baseada na letra enviada
    switch(comando)
    {
      case 'U': // Levanta o braço
        servoBraco.write(150);
        Serial.println("Braço Subindo");
        break;

      case 'D': // Abaixa o braço
        servoBraco.write(30);
        Serial.println("Braço Descendo");
        break;

      case 'O': // Abre a garra e desliga o LED
        servoGarra.write(90);
        digitalWrite(LED, LOW);
        Serial.println("Garra Aberta");
        break;

      case 'C': // Fecha a garra e acende o LED (amostra pega)
        servoGarra.write(20);
        digitalWrite(LED, HIGH);
        Serial.println("Amostra Capturada");
        break;
    }
  }
}