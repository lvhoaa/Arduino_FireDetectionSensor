//full code for UNO

//bien bao co chay
bool cochaybenuno = false;
//communicate with nodemcu
#include <SoftwareSerial.h>
SoftwareSerial espSerial(5, 6);

//do thong so 
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 7  // what pin we're connected to

#define DHTTYPE DHT11   // DHT 11 

// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);

// mq2 smoke detector 
int smokeA0 =A5;
int thresval= 400;

//flame sensor
const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum

int chay =analogRead(A4);


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
// luu y khac o serial- o serial ben do thong so la 9600
espSerial.begin(115200);
delay(1000);
//do thong so 
pinMode(smokeA0,INPUT);
Serial.println("DHTxx test!");
dht.begin();
}



void loop() {
  // put your main code here, to run repeatedly:
// do thong so 
// dht11 temperature
delay(2000);
float t = dht.readTemperature();
if ( isnan(t) ) {
Serial.println("Failed to read from DHT sensor!");
return;
}

// mq2 co sensor 
int nongdoco=analogRead(smokeA0);



//flame 

int chay =analogRead(A4);

int range = map( chay, sensorMin, sensorMax, 0, 3);
  // range value:
  switch (range) {
  case 0:    // A fire closer than 1.5 feet away.
    Serial.println("** Fire ** from flame sensor");
    cochaybenuno=true;
    break;
  case 1:    // A fire between 1-3 feet away.
    Serial.println("** Fire ** from flame sensor");
    cochaybenuno=true;
    break;
  case 2:    // No fire detected.
    Serial.println("No Fire");
    break;
  }
// xuat gia tri len serial
Serial.print("Temperature: "); 
Serial.print(t);
Serial.println(" *C ");
Serial.print("Nong do CO trong khong khi la : " );
Serial.println(nongdoco);

//LUAN DIEM DE CHUNG MINH: nong do co trong khong khi binh thuong la 30-60 .
// Khi co dam chay, con so se len toi 80
if(nongdoco >80  ){
  //co fire
  Serial.println("FIRE! FIRE! from CO sensor");
  cochaybenuno=true;
}
//demo


 //communicate with esp
  if(cochaybenuno==true){
    espSerial.println(911);
    delay(1000);
  }

}
