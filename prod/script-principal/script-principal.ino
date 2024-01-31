/*Declaracao das variaveis do PID (Proporcional, Integral, Derivativo)
  O controle PID é um método de controle amplamente utilizado em sistemas dinâmicos para manter uma variável próxima a um valor desejado.

  - setpoint e a velocidade desejada
  - kp e o ganho proporcional
  - ki e o ganho integral
  - kd e o ganho derivativo
  - lastError e o ultimo erro
  - integral soma dos erros
  - pv e a variavel do processo
*/         
int setpoint = 3;
float kp = 2.0;
float ki = 0.1;
float kd = 0.5;

float lastError = 0;
float integral = 0;

int pv;
int error;
float derivative;
float output;

/*Declaracao das variaveis de estado dos sensores
  Declaração das variaveis que irao armazenar o estado dos sensores durante a execucao.

  - 0 significa que o sensor esta vendo a cor branca ou proximo a mesma
  - 1 significa que o sensor esta vendo a cor preta ou proximo a mesma

  Os sensores estao declarados na ordem que representa a esquerda para direita,
  ou seja, sensorStatus2 e o sensor mais a direita que o sensor sensorStatus4.
*/                                                                                                                        
int sensorStatus1 = 0;
int sensorStatus2 = 0;
// int sensorStatus3 = 0;
int sensorStatus4 = 0;
int sensorStatus5 = 0;

/*Definicao das portas dos sensores
  Definição das portas utilizadas pelos sensores no arduino.

  Na necessidade da mudança de alguma porta da placa do arduino referente aos sensores, basta reconfigura-la aqui.

  Os sensores estao definidos na ordem que representa a esquerda para direita,
  ou seja, sensor2 e o sensor mais a direita que o sensor sensor4.
*/           
#define sensor1 2
#define sensor2 3
// #define sensor3 4
#define sensor4 5
#define sensor5 6

/*Definicao das portas dos motores
  Definição das portas utilizadas pelos motores no arduino.

  Na necessidade da mudança de alguma porta da placa do arduino referente aos motores, basta reconfigura-la aqui.

  Os motores estao definidos na ordem que representa a esquerda para direita,
  ou seja, sensor2 e o sensor mais a direita que o sensor sensor4.
*/           
#define engine1 7
// #define pinMOT1 8
#define engine2 9
// #define pinMOT2 10

void setup() {
  /*Configuracao dos pinos e seus repectivos modos*/
  // pinMode (sensor1,INPUT);
  pinMode (sensor2,INPUT);
  // pinMode (sensor3,INPUT);
  pinMode (sensor4,INPUT);
  // pinMode (sensor5,INPUT);
  pinMode (engine1, OUTPUT);
  // pinMode (pinMOT1 ,OUTPUT);
  pinMode (engine2 ,OUTPUT);
  // pinMode (pinMOT2 ,OUTPUT);
  
  /*Output inicial dos motores*/
  digitalWrite(engine1, LOW);
  // digitalWrite(pinMOT1, LOW);
  digitalWrite(engine2, LOW);
  // digitalWrite(pinMOT2, LOW);
}

void loop() {
  /*Valor digital, menos preciso*/
  sensorStatus1 = digitalRead(sensor1);
  sensorStatus2 = digitalRead(sensor2);
  sensorStatus4 = digitalRead(sensor4);
  sensorStatus5 = digitalRead(sensor5);

  /*Para testar com valor analogico (Mais precisao)*/
  // sensorStatus2 = analogRead(sensor2);
  // sensorStatus4 = analogRead(sensor4);

  /*Calculos do PID*/
  pv = sensorStatus1 + sensorStatus2 + sensorStatus4 + sensorStatus5;
  error = setpoint - pv;
  integral += error;
  derivative = error - lastError;
  output = kp * error + ki * integral + kd * derivative;
  lastError = error;

  /*Ajuste da velocidade dos motores com base no controle PID*/
  analogWrite(engine1, constrain(output, 0, 255));
  analogWrite(engine2, constrain(output, 0, 255));
  // delay(100);  // Ajuste conforme necessário
}
