const byte buzzer = 8;
const byte led = 10;
const byte rainSensor = 2;

volatile bool toggle1 = false; // for buzzer
volatile bool toggle2 = false;      // for light

void setup() 
{
  pinMode(buzzer, OUTPUT); 
  pinMode(led, OUTPUT);
  pinMode(rainSensor, INPUT);  
  Serial.begin(9600); // Starts the serial communication
}
void loop() 
{
  check();
}

void check()
{
  int sensorValue = digitalRead(rainSensor);
  
  
  // toggle buzzer if rain detected
  if(sensorValue == HIGH)
  {
    delay(500);
    toggle1= !toggle1;
    digitalWrite(buzzer, toggle1);
  }
  else if(sensorValue == LOW)
  {
    delay(200);
    toggle2= !toggle2;
    digitalWrite(led, toggle2);
  }
  Serial.print((String)"sensor: " + sensorValue);
  Serial.println((String)"        //   buzzer: " + digitalRead(buzzer));

  delay(500);
}
