//constantes
#define led 11
#define ldr A0

//variables
int lecturaLdr;
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value


void setup()
{
    Serial.begin(115200);
	pinMode(led, OUTPUT);

    // turn on LED to signal the start of the calibration period:
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);

    // calibrate during the first five seconds
    while (millis() < 5000) {
        lecturaLdr = analogRead(ldr);

        // record the maximum sensor value
        if (lecturaLdr > sensorMax) {
            sensorMax = lecturaLdr;
        }

        // record the minimum sensor value
        if (lecturaLdr < sensorMin) {
        sensorMin = lecturaLdr;
        }
    }
}

void loop()
{
	lecturaLdr = analogRead(ldr);
    //valor restringido
    lecturaLdr = constrain(lecturaLdr, sensorMin, sensorMax);

    //valor mapeado
    lecturaLdr = map(lecturaLdr,sensorMin,sensorMax,15,500);

    digitalWrite(led, HIGH);
    delay(lecturaLdr);

    digitalWrite(led, LOW);
    delay(lecturaLdr);

    Serial.println(lecturaLdr);
}
