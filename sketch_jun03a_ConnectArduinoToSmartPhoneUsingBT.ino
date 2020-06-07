// We need to upload the below code to Arduino
// While uploading the code disconnect HC-05 bluetooth module from Arduino like shown in video.
// Code Author: Vignesh Raja

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

// After upload the code, download and install the app given below play store link in your smartphone :
// https://play.google.com/store/apps/details?id=ptah.apps.bluetoothterminal

// After installation turn on smartphone bluetooth and detect the HC -05 bluetooth module and
// Pair it with your smartphone (The pairing password for HC-05 module is mostly 1234).

// After pairing, open the app and select the paired
// HC-05 bluetooth module. Then type "on" and click send button then led will turn on. 
// Same as type "off" and click send button then led will turn off.

// We can use any comment we want instead of "on" and "off" by changing the Arduino code

// Also we can control anything we want instead of the led by changing the Arduino code

// See https://www.instructables.com/id/Connect-Arduino-With-Your-Smartphone/
