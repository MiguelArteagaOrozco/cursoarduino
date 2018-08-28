#define led 13
#define ldr A0
int lecturaLdr;

void setup()
{
    Serial.begin(115200);
	pinMode(led, OUTPUT);
}

void loop()
{
	lecturaLdr = analogRead(ldr);
    //valor restringido
    lecturaLdr = constrain(lecturaLdr, 700, 800);

    //valor mapeado
    lecturaLdr = map(lecturaLdr,700,800,15,500);

    digitalWrite(led, HIGH);
    delay(lecturaLdr);

    digitalWrite(led, LOW);
    delay(lecturaLdr);

    Serial.println(lecturaLdr);
}
