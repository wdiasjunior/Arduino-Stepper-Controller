// enable
#define enable 8
// 1° driver
#define xDir 5
#define xStep 2
// 2° driver
#define yDir 6
#define yStep 3
// 3° driver
#define zDir 7
#define zStep 4
// botoes
#define bUP 12
#define bDOWN 13
// sensores de final de curso/top and bottom travel limit sensors
#define sensorFinalDeCursoTop 11
#define sensorFinalDeCursoBottom 10

int stepsX = 1600;//int stepsY = 1;int stepsZ = 1;// num de voltas/turns
int stepDelay = 300; //velocidade/speed

void setup(){
  pinMode(xDir, OUTPUT); pinMode(xStep, OUTPUT);// 1° driver
  pinMode(yDir, OUTPUT); pinMode(yStep, OUTPUT);// 2° driver
  pinMode(zDir, OUTPUT); pinMode(zStep, OUTPUT);// 3° driver

  pinMode(bUP, INPUT_PULLUP); pinMode(bDOWN, INPUT_PULLUP);//botoes/buttons

  pinMode(sensorFinalDeCursoTop, INPUT_PULLUP);//sensor de final de curso top
  pinMode(sensorFinalDeCursoBottom, INPUT_PULLUP);//sensor de final de curso bottom

  pinMode(enable, OUTPUT);
  digitalWrite(enable,LOW);
  Serial.begin(9600);
}

void loop(){

  int varUP = digitalRead(bUP);
  int varDOWN = digitalRead(bDOWN);
  int varTop = digitalRead(sensorFinalDeCursoTop);
  int varBottom = digitalRead(sensorFinalDeCursoBottom);
  delay(50);

  if(varUP == LOW && varTop != LOW){

    digitalWrite(xDir, LOW);//direçao sentido horario/CW rotation
    digitalWrite(yDir, LOW);//direçao sentido horario/CW rotation
    digitalWrite(zDir, LOW);//direçao sentido horario/CW rotation

    for(int i = 0; i < stepsX; i++){
      
      varTop = digitalRead(sensorFinalDeCursoTop);
      if(varTop == LOW){
        Serial.println("top");
        break;
      }
      
      digitalWrite(xStep, HIGH);
      delayMicroseconds(stepDelay);
      digitalWrite(xStep, LOW);
      delayMicroseconds(stepDelay);
  
      digitalWrite(yStep, HIGH);
      delayMicroseconds(stepDelay);
      digitalWrite(yStep, LOW);
      delayMicroseconds(stepDelay);
  
      digitalWrite(zStep, HIGH);
      delayMicroseconds(stepDelay);
      digitalWrite(zStep, LOW);
      delayMicroseconds(stepDelay);    
    }
  }else if(varDOWN == LOW && varBottom != LOW){

    digitalWrite(xDir, HIGH);//direçao sentido anti horario/CCW rotation
    digitalWrite(yDir, HIGH);//direçao sentido anti horario/CCW rotation
    digitalWrite(zDir, HIGH);//direçao sentido anti horario/CCW rotation
    
    for(int i = 0; i < stepsX; i++){
      
      varBottom = digitalRead(sensorFinalDeCursoBottom);
      if(varBottom == LOW){
        Serial.println("bottom");
        break;
      }
      
      digitalWrite(xStep, HIGH);
      delayMicroseconds(stepDelay);
      digitalWrite(xStep, LOW);
      delayMicroseconds(stepDelay);
  
      digitalWrite(yStep, HIGH);
      delayMicroseconds(stepDelay);
      digitalWrite(yStep, LOW);
      delayMicroseconds(stepDelay);
  
      digitalWrite(zStep, HIGH);
      delayMicroseconds(stepDelay);
      digitalWrite(zStep, LOW);
      delayMicroseconds(stepDelay); 
    }
  }else{
      Serial.println("idle");
  }
}
