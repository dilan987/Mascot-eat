
float volt=0;
int binario=0;
float echo=6;  //echo del sensor ultrasonido
float trigger=7; //trigger del sensor ultrasonido
int rojo=13;
int azul=10;
int MDE= 12;
int MIZ= 11;


void setup() {
  // put your setup code here, to run once:
   pinMode(echo, INPUT);
   pinMode(trigger, OUTPUT);
   pinMode(rojo, INPUT);
   pinMode(azul, OUTPUT);
    pinMode(MDE,OUTPUT);
 pinMode(MIZ,OUTPUT);
   Serial.begin(9600);
}

void loop() {

  if(Serial.available()>0){
    int input=Serial.read();
    if(input=='H'){
      digitalWrite(azul, HIGH);
      delay(3000);
      digitalWrite(azul, LOW);
    }
  }
  
    //CODIGO DISTANCIA COMIDA
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  float pulso=pulseIn(echo,HIGH);
  float distancia=pulso/2.0/29.2;

//  Serial.print(distancia);
//  Serial.print("cm");
//  Serial.println(" ");
  float porcentaje=map(distancia, 0, 1145, 100, 0);
  
  
  if(distancia>=100){
  digitalWrite(rojo, HIGH);
  }else{
  digitalWrite(rojo, LOW);    
  }
  
  //Códigoo PIR
  int pirState=digitalRead(8);
  int i=0;
if (pirState==HIGH){
   Serial.println(i+1);
//  Serial.println("Se detecto a un perro, abriendo compuerta! ");
   digitalWrite(MDE,HIGH);
   delay(3000);
   digitalWrite(MDE,LOW);
//   Serial.println("Compuerta Abierta");
   delay(2000);
   digitalWrite(MIZ,HIGH);
//   Serial.println("Cerrando compuerta");
   delay(3000);
   digitalWrite(MIZ,LOW);
//   Serial.println("Compuerta cerrada");
  }
//  Serial.println("cm");
  Serial.print(porcentaje);
  Serial.print("%");
  Serial.println(" ");
  delay(500);
}
