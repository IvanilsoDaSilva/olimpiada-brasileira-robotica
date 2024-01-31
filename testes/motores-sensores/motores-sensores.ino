/*Declaracao das variaveis de estado dos sensores
  Declaração das variaveis que irao armazenar o estado dos sensores durante a execucao.

  - 0 significa que o sensor esta vendo a cor branca ou proximo a mesma
  - 1 significa que o sensor esta vendo a cor preta ou proximo a mesma

  Os sensores estao declarados na ordem que representa a esquerda para direita,
  ou seja, sensorStatus2 e o sensor mais a direita que o sensor sensorStatus4.
*/                                                                                                                        
// int sensorStatus1 = 0;
int sensorStatus2 = 0;
//int sensorStatus3 = 0;
int sensorStatus4 = 0;
// int sensorStatus5 = 0;

/*Definicao das portas dos sensores
  Definição das portas utilizadas pelos sensores no arduino.

  Na necessidade da mudança de alguma porta da placa do arduino referente aos sensores, basta reconfigura-la aqui.

  Os sensores estao definidos na ordem que representa a esquerda para direita,
  ou seja, sensor2 e o sensor mais a direita que o sensor sensor4.
*/           
// #define sensor1 2
#define sensor2 3
// #define sensor3 4
#define sensor4 5
// #define sensor5 6

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
  /*Atualização do estado dos sensores
    Atualiza o estado dos sensores para a tomada das decisoes posteriores durante o loop atual
  */
  sensorStatus2 = digitalRead(sensor2);
  sensorStatus4 = digitalRead(sensor4);

  Serial.println(sensorStatus2);
  Serial.println(sensorStatus4);
  Serial.println();

  /*Teste de uso dos motores e sensores
    Código simples para testar a interação entre os sensores e os motores
  */
  if (sensorStatus2 == 0){
    digitalWrite(engine1, LOW);
    digitalWrite(engine2, HIGH);
  } else if (sensorStatus4 == 0){
    digitalWrite(engine1, HIGH);
    digitalWrite(engine2, LOW);
  } else {
    digitalWrite(engine1, HIGH);
    digitalWrite(engine2, HIGH);
  }
}
