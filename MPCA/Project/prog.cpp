#include "Servo.h"
#include "DHT.h" 

#define PIR_SENSOR A0
#define ULT_TRIG A1
#define ULT_ECHO A2
#define LDR_SENSOR A3
#define DHT_SENSOR A4

#define BUZZER1 13
#define SERVO 12
#define LED 11
#define BUZZER2 10
#define DHT_TYPE DHT11 

DHT sensor(DHT_SENSOR, DHT_TYPE); 
Servo servo;

void setup() 
{
    for (int i = PIR_SENSOR; i <= DHT_SENSOR; i++)
    {
        pinMode(i, INPUT);
    }
    pinMode(ULT_TRIG, OUTPUT);
    for (int i = BUZZER2; i <= BUZZER1; i++)
    {
        pinMode(i, OUTPUT);
    }
    sensor.begin();
    servo.attach(SERVO);
    Serial.begin(9600);
}

void loop()
{
    pir_Readings();
    ult_Readings();
    ldr_Readings();
    dht_Readings();
}

void pir_Readings() 
{
    int x = digitalRead(PIR_SENSOR);
    Serial.print("PIR=");
    Serial.print(x);
    Serial.print("\t");
    if (x == 1) 
    {
        digitalWrite(BUZZER1, HIGH); 
    }
    else 
    {
        digitalWrite(BUZZER1, LOW);
    }
    delay(10);
}

void ult_Readings() 
{
    long  duration;
    int distance;
    digitalWrite(ULT_TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(ULT_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(ULT_TRIG, LOW);
    duration = pulseIn(ULT_ECHO, HIGH);
    distance = (int)duration * (0.0343) / 2;
    Serial.print("ULT=");
    Serial.print(distance);
    Serial.print("\t");
    if (1 <= distance && distance <= 10) 
    {
        for(int pos=0; pos<=90; pos++)
        {
            servo.write(pos);
        }
    }
    else 
    {
        for(int pos=90;pos>=0;pos--)
        {
            servo.write(pos);
        }
    }
    delay(10);
}

void ldr_Readings() 
{
    int x = digitalRead(LDR_SENSOR);
    Serial.print("LDR=");
    Serial.print(x);
    Serial.print("\t");
    if (x == 1) 
    {
        digitalWrite(LED, HIGH);
    }
    else 
    {
        digitalWrite(LED, LOW);
    }
    delay(10);
}

void dht_Readings()
{
    float x = sensor.readTemperature();
    Serial.print("DHT=");
    Serial.print(x);
    Serial.print("\n");
    if (x > 30)
    {
        digitalWrite(BUZZER2, HIGH);
    }
    else
    {
        digitalWrite(BUZZER2, LOW);
    }
    delay(10);
}