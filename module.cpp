
int pin2 = 2;
int pin3 = 3;
int pin4 = 4;
int pin5 = 5;
int pin6 = 6;
int pin7 = 7;
int pin8 = 8;
int pin9 = 9;
int pin10 = 10;
int pin11 = 11;
int timer = 100;

void setup()
{
    pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
    pinMode(pin4, OUTPUT);
    pinMode(pin5, OUTPUT);
    pinMode(pin6, OUTPUT);
    pinMode(pin7, OUTPUT);
    pinMode(pin8, OUTPUT);
    pinMode(pin9, OUTPUT);
    pinMode(pin10, OUTPUT);
    pinMode(pin11, OUTPUT);
}

void loop()
{
    digitalWrite(pin2, HIGH);
    delay(timer);
    digitalWrite(pin2, LOW);
    delay(timer);

    digitalWrite(pin3, HIGH);
    delay(timer);
    digitalWrite(pin3, LOW);
    delay(timer);

    digitalWrite(pin4, HIGH);
    delay(timer);
    digitalWrite(pin4, LOW);
    delay(timer);

    digitalWrite(pin5, HIGH);
    delay(timer);
    digitalWrite(pin5, LOW);
    delay(timer);

    digitalWrite(pin6, HIGH);
    delay(timer);
    digitalWrite(pin6, LOW);
    delay(timer);

    digitalWrite(pin7, HIGH);
    delay(timer);
    digitalWrite(pin7, LOW);
    delay(timer);

    digitalWrite(pin8, HIGH);
    delay(timer);
    digitalWrite(pin8, LOW);
    delay(timer);

    digitalWrite(pin9, HIGH);
    delay(timer);
    digitalWrite(pin9, LOW);
    delay(timer);

    digitalWrite(pin10, HIGH);
    delay(timer);
    digitalWrite(pin10, LOW);
    delay(timer);

    digitalWrite(pin11, HIGH);
    delay(timer);
    digitalWrite(pin11, LOW);
    delay(timer);

    digitalWrite(pin10, HIGH);
    delay(timer);
    digitalWrite(pin10, LOW);
    delay(timer);

    digitalWrite(pin9, HIGH);
    delay(timer);
    digitalWrite(pin9, LOW);
    delay(timer);

    digitalWrite(pin8, HIGH);
    delay(timer);
    digitalWrite(pin8, LOW);
    delay(timer);

    digitalWrite(pin7, HIGH);
    delay(timer);
    digitalWrite(pin7, LOW);
    delay(timer);

    digitalWrite(pin6, HIGH);
    delay(timer);
    digitalWrite(pin6, LOW);
    delay(timer);

    digitalWrite(pin5, HIGH);
    delay(timer);
    digitalWrite(pin5, LOW);
    delay(timer);

    digitalWrite(pin4, HIGH);
    delay(timer);
    digitalWrite(pin4, LOW);
    delay(timer);

    digitalWrite(pin3, HIGH);
    delay(timer);
    digitalWrite(pin3, LOW);
    delay(timer);
}

int buttonState = 0;

int lastButtonState = 0;

int buttonPushCounter = 0;

void setup()
{
    pinMode(2, INPUT);
    Serial.begin(9600);

    pinMode(13, OUTPUT);
}

void loop()
{

    buttonState = digitalRead(2);

    if (buttonState != lastButtonState)
    {

        if (buttonState == HIGH)
        {
            buttonPushCounter += 1;
            Serial.print("number of button pushes: ");
            Serial.println(buttonPushCounter);
        }

        delay(5);
    }

    lastButtonState = buttonState;

    if (buttonPushCounter % 3 == 0 || buttonPushCounter % 3 == 1)
    {
        digitalWrite(13, HIGH);
    }
    else
    {
        digitalWrite(13, LOW);
    }
}
int red_light_pin = 11;
int green_light_pin = 9;
int blue_light_pin = 10;
void setup()
{
    pinMode(red_light_pin, OUTPUT);
    pinMode(green_light_pin, OUTPUT);
    pinMode(blue_light_pin, OUTPUT);
}
void loop()
{
    color(255, 0, 0);   // turn the RGB LED red
    delay(1000);        // delay for 1 second
    color(237, 109, 0); // turn the RGB LED orange
    delay(1000);        // delay for 1 second
    color(255, 215, 0); // turn the RGB LED yellow
    delay(1000);        // delay for 1 second
    color(0, 255, 0);   // turn the RGB LED green
    delay(1000);        // delay for 1 second
    color(0, 0, 255);   // turn the RGB LED blue
    delay(1000);        // delay for 1 second
    color(0, 46, 90);   // turn the RGB LED indigo
    delay(1000);        // delay for 1 second
    color(128, 0, 128); // turn the RGB LED purple
    delay(1000);        // delay for 1 second
}
void color(int red_light_value, int green_light_value, int blue_light_value)
{
    analogWrite(red_light_pin, red_light_value);
    analogWrite(green_light_pin, green_light_value);
    analogWrite(blue_light_pin, blue_light_value);
}

int sensorPin = A0;

int sensorValue = 0;
int led = 9;

void setup()
{
    pinMode(led, OUTPUT);

    Serial.begin(9600);
}

void loop()

{

    sensorValue = analogRead(sensorPin);

    Serial.println(sensorValue);

    if (sensorValue < 100)

    {

        Serial.println("LED light on");

        digitalWrite(led, HIGH);

        delay(1000);
    }

    digitalWrite(led, LOW);

    delay(sensorValue);
}

int sensorState = 0;
void setup()
{
    pinMode(2, INPUT);
    pinMode(13, OUTPUT);
    Serial.begin(9600);
}
void loop()
{
    sensorState = digitalRead(2);
    if (sensorState == HIGH)
    {
        digitalWrite(13, HIGH);
        Serial.println("Sensor activated!");
    }
    else
    {
        digitalWrite(13, LOW);
    }
    delay(10);
}

char degree = 176;
void setup()
{
    pinMode(A0, INPUT);
    pinMode(5, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    float tmp = analogRead(A0);
    float voltage = (tmp * 5.0) / 1024;
    float milliVolt = voltage * 1000;
    float tmpCel = (milliVolt - 500) / 10;
    if (tmpCel > 6)
    {
        digitalWrite(5, HIGH);
        Serial.print("Temperature: ");
        Serial.print(tmpCel);
        Serial.println(degree);
        Serial.println("Chiller is ON now");
        delay(2000);
    }
    else
    {
        digitalWrite(5, LOW);
        Serial.print("Temperature: ");
        Serial.print(tmpCel);
        Serial.println(degree);
        Serial.println("Chiller is Off now");
        delay(2000);
    }
}

#include <Servo.h>
Servo myservo;
int pos = 20;
const int trigPin = 8;
const int echoPin = 7;
const int led = 10;
long duration;
float dist;

void setup()
{
    myservo.attach(9);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    myservo.write(pos);
}

void loop()
{
    Serial.begin(9600);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    dist = 0.034 * (duration / 2);

    if (dist >= 25 && dist <= 35)
    {
        digitalWrite(led, 1);
        myservo.write(pos + 160);
        delay(1000);
    }
    else if (dist > 35)
    {
        digitalWrite(led, 0);
        myservo.write(pos);
    }
    delay(300);
}

Servo servoMain; // Define our Servo

int trigpin = 10;

int echopin = 11;

int distance;

float duration;

float cm;

void setup()

{
    servoMain.attach(9);

    pinMode(trigpin, OUTPUT);

    pinMode(echopin, INPUT);
}

void loop()

{
    digitalWrite(trigpin, LOW);

    delay(2);

    digitalWrite(trigpin, HIGH);

    delayMicroseconds(10);

    digitalWrite(trigpin, LOW);

    duration = pulseIn(echopin, HIGH);

    cm = (duration / 58.82);

    distance = cm;

    if (distance < 30)

    {

        servoMain.write(180); // Turn Servo back to center position (90 degrees)

        delay(3000);
    }

    else
    {
        servoMain.write(0);

        delay(50);
    }
}

#include <Servo.h>
Servo myservo;
int smk = A0;
int LM35 = A1;
int buzzer = 7;
int temp = 0;
int gas = 0;
void setup()
{
    myservo.attach(9);
    pinMode(smk, INPUT);
    pinMode(LM35, INPUT);
    pinMode(buzzer, OUTPUT);
    Serial.begin(9600);
}
void loop()
{
    int baselinetemp = 0;
    temp = analogRead(LM35);
    float voltage = (temp / 1024.0) * 5.0;
    int celsius = (voltage - .5) * 100;
    Serial.println(celsius);
    Serial.println(" ");
    gas = analogRead(smk);
    Serial.println(gas);
    if (celsius > baselinetemp + 60 || gas > 200)
    {
        digitalWrite(buzzer, HIGH);
        delay(300);
        digitalWrite(buzzer, LOW);
        delay(300);
    }
    else if (celsius > baselinetemp + 65 || gas > 220)
    {
        int pos = 180;
        myservo.write(pos);
        delay(5);
    }
    else
    {
        digitalWrite(buzzer, LOW);
        int pos = 0;
        myservo.write(pos);
        delay(5);
    }
}