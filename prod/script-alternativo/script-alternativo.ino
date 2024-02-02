/*Declaracao das variaveis de estado dos sensores
  Declaração das variaveis que irao armazenar o estado dos sensores durante a execucao.

  - 0 significa que o sensor esta vendo a cor preta ou proximo a mesma
  - 1 significa que o sensor esta vendo a cor branca ou proximo a mesma

  Os sensores estao declarados na ordem que representa a esquerda para direita,
  ou seja, sensorValue2 e o sensor mais a direita que o sensor sensorValue4.
*/                                                                                                                        
int sensorValue2 = 0;
int sensorValue4 = 0;

/*Definicao das portas dos sensores
  Definição das portas utilizadas pelos sensores no arduino.

  Na necessidade da mudança de alguma porta da placa do arduino referente aos sensores, basta reconfigura-la aqui.

  Os sensores estao definidos na ordem que representa a esquerda para direita,
  ou seja, sensor2 e o sensor mais a direita que o sensor sensor4.
*/           
#define sensor2 3
#define sensor4 5

/*Definicao das portas dos motores
  Definição das portas utilizadas pelos motores no arduino.

  Na necessidade da mudança de alguma porta da placa do arduino referente aos motores, basta reconfigura-la aqui.

  Os motores estao definidos na ordem que representa a esquerda para direita,
  ou seja, sensor2 e o sensor mais a direita que o sensor sensor4.
*/           
#define engine1front 7
#define engine1back 8
#define engine2front 9
#define engine2brack 10

void setup() {
  /*Configuracao dos pinos e seus repectivos modos*/
  pinMode (sensor2,INPUT);
  pinMode (sensor4,INPUT);
  pinMode (engine1front, OUTPUT);
  pinMode (engine2front ,OUTPUT);

  /*Output inicial dos motores*/
  digitalWrite(engine1front, LOW);
  // digitalWrite(engine1brack, LOW);
  digitalWrite(engine2front, LOW);
  // digitalWrite(engine2back, LOW);
}

void loop() {
  /*Atualização do estado dos sensores
    Atualiza o estado dos sensores para a tomada das decisoes posteriores durante o loop atual
  */
  sensorValue2 = digitalRead(sensor2);
  sensorValue4 = digitalRead(sensor4);

  Serial.println(sensorValue2);
  Serial.println(sensorValue4);
  Serial.println();

  /*Teste de uso dos motores e sensores
    Código simples para testar a interação entre os sensores e os motores
  */
  if (sensorValue2 == 0){
    digitalWrite(engine1front, LOW);
    digitalWrite(engine2front, HIGH);
  } else if (sensorValue4 == 0){
    digitalWrite(engine1front, HIGH);
    digitalWrite(engine2front, LOW);
  } else {
    digitalWrite(engine1front, HIGH);
    digitalWrite(engine2front, HIGH);
  }
}
