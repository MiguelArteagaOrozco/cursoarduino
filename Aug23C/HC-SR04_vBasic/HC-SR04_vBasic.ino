/*
 * Sensor HC-SR04
  Ultrasonic sensor Pins:
 */
#define led 11
 
int trigPin = 9;    //Trig
int echoPin = 8;    //Echo
long duracion, cm;
 
void setup() {
  Serial.begin (9600);
  pinMode(led, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop()
{

  // El sensor es inicializado mediante un pulso (HIGH) de 10 microsegundos o más
  // Seteamos un pulso en baja (LOW) para asegurarnos un pulso en alto limpio
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Lee la señal proveniente del sensor: un pulso HIGH cuya duración es el tiempo en microsegundos de haber 
  //mandado la señal desde el transmisor y su llegada al receptor
  duracion = pulseIn(echoPin, HIGH);
 
  // convierte el tiempo en distancia
  //cm = (duracion/2) / 29.1;
  cm = duracion * 0.01715;
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  if(cm >= 20)
  {
    digitalWrite(led, LOW);
  }
  
  else if(cm < 10)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
     cm = constrain(cm, 10, 100);
     cm = map (cm, 10, 100, 10, 600);

    digitalWrite(led, HIGH);
    delay(cm);
    
    digitalWrite(led, LOW);
    delay(cm);

    
  }
  
  //delay(150); //sirve para tomar una nueva muestra
}
