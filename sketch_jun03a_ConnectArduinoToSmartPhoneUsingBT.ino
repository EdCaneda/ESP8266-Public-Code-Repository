// We need to upload the below code to Arduino
// While uploading the code disconnect [HC-05] bluetooth module from Arduino like shown in video.
// Original Code Author and credit goes to: Vignesh Raja

int led = 13;
void setup()
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
  }
void loop()
{
  if(Serial.available())
  {
    String value = Serial.readStringUntil('\n');
    Serial.println(value);
    if(value == "on")
    {
      digitalWrite(led,HIGH);
    }
    else if(value == "off")
    {
      digitalWrite(led,LOW);
    }
  }
}

// Replace the LED function with another module like Temperature and Humidity or other motor device.
// The possibility are endless... As they say it.

// Check out my video in Youtube: https://youtu.be/MZw8hEbOnSU
// My reference(s):
   // See https://www.instructables.com/id/Connect-Arduino-With-Your-Smartphone/ by Vignesh Raja



