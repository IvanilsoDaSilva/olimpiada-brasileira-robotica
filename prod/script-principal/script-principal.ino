/*Declaracao das variaveis do PID (Proporcional, Integral, Derivativo)
  O controle PID é um método de controle amplamente utilizado em sistemas dinâmicos para manter uma variável próxima a um valor desejado.

  - setpoint e o valor desejado
  - kp e o ganho proporcional
  - ki e o ganho integral
  - kd e o ganho derivativo
  - proportional
  - integral soma dos erros  - integral soma dos erros
  - derivative
  - error e o erro atual
  - lastError e o ultimo erro
  - pv e a variavel do processo
  - output e a saida do controle
  - engineDifference diferença dos motores

  Declarados com "//*" necessitam serem iniciados.
*/         
double setpoint = 255; //*
double kp = 2.0; //*
double ki = 0.1; //*
double kd = 0.5; //*
double proportional;
double integral = 0; //*
double derivative;
double error;
double lastError = 0; //*
double pv;
double output;
double engineDifference = 0; //*

/*Declaracao das variaveis de estado dos sensores
  Declaração das variaveis que irao armazenar o estado dos sensores durante a execucao.

  - 0 significa que o sensor esta vendo a cor branca ou proximo a mesma
  - 1 significa que o sensor esta vendo a cor preta ou proximo a mesma

  Os sensores estao declarados na ordem que representa a esquerda para direita,
  ou seja, sensorStatus2 e o sensor mais a direita que o sensor sensorStatus4.
*/                                                                                                                        
int sensorValue2;
int sensorValue4;

/*Declaracao das variaveis de estado dos sensores
  Declaração das variaveis que irao armazenar a velocidade dos motores durante a execucao.

  - 255 significa que o motor esta em sua maxima velocidade
  - 0 significa que o motor esta em sua minima velocidade

  Os motores estao declarados na ordem que representa a esquerda para direita,
  ou seja, engine1Velocity e o motor mais a direita que o motor engine2Velocity.
*/    
int engine1Velocity;
int engine2Velocity;

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
#define engine1 7
#define engine2 9

void setup() {
  /*Configuracao dos pinos e seus repectivos modos*/
  pinMode (sensor2,INPUT);
  pinMode (sensor4,INPUT);
  pinMode (engine1, OUTPUT);
  pinMode (engine2 ,OUTPUT);
  
  /*Output inicial dos motores*/
  digitalWrite(engine1, LOW);
  digitalWrite(engine2, LOW);
}

void loop() {
  /*Leitura no console*/
  Serial.println("\nInicio do relatorio***********************");
  Serial.println("Valor desejado: "+(String)setpoint);
  Serial.println("Ganho proporcional: "+(String)kp);
  Serial.println("Ganho integral: "+(String)ki);
  Serial.println("Ganho derivativo: "+(String)kd);
  Serial.println("Valor proporcional: "+(String)proportional);
  Serial.println("Valor integral: "+(String)integral);
  Serial.println("Valor derivativo: "+(String)derivative);
  Serial.println("Valor do erro: "+(String)error);
  Serial.println("Valor do ultimo erro: "+(String)lastError);
  Serial.println("Valor da variavel do processo: "+(String)pv);
  Serial.println("Valor da saida: "+(String)output);
  Serial.println("Valor do sensor2: "+(String)sensorValue2);
  Serial.println("Valor da sensor4: "+(String)sensorValue4);
  Serial.println("Valor da velocidade do motor1: "+(String)engine1Velocity);
  Serial.println("Valor da velocidade do motor2: "+(String)engine2Velocity);
  Serial.println("\nFim do relatorio**************************");

  /*Leitura dos sensores*/
  sensorValue2 = analogRead(sensor2);
  sensorValue4 = analogRead(sensor4);

  /*Cálculo da variavel do processo*/
  pv = sensorValue2 + sensorValue4;

  /*Cálculo do erro*/
  error = setpoint - ((pv) / 2.0);

  /*Cálculo do termo proporcional*/
  proportional = kp * error;

  /*Cálculo do termo integral*/
  integral += ki * error;

  /*Cálculo do termo derivativo*/
  derivative = kd * (error - lastError);
  
  /*Cálculo da saída do PID*/
  output = proportional + integral + derivative;

  /*Ajuste da velocidade dos motores com base no controle PID*/
  engine1Velocity = constrain(255 - output - engineDifference, 0, 255);
  engine2Velocity = constrain(255 + output, 0, 255);

  /*Controle dos motores*/
  analogWrite(engine1, engine1Velocity);
  analogWrite(engine2, engine2Velocity);
}
