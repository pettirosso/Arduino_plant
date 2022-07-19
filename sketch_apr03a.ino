const int SENSOR = A0; // Benenne analogen Eingang A0 "SENSOR"
int sensorWert = 0; // Definiere int Variable "sensorWert" und setze sie auf 0

void setup() {
Serial.begin(9600); // baud rate 9600
pinMode(2,OUTPUT); // Definiere digitalen Pin 2 als Output (Schaltet das Relais)
}

void loop() {
sensorWert = analogRead(SENSOR); // Lies ANalogpin "SENSOR" aus und speichere Ergebnis in Variable "sensorWert"
Serial.print("Sensorwert = ");
Serial.println(sensorWert); // In diesen beiden Zeilen wird der Sensorwert auf dem Computermonitor ausgegeben

if (sensorWert > 500) { //Falls Sensorwert 500 überschreitet... (trockene Luft = 600, Wasser = 264, gut feuchte Erde = 385)
digitalWrite(2,HIGH); // Setze digitalen Pin 2 auf High (schalte Relais -> schalte Pumpe)
delay (20000); //2000 ist die Zeit in Millisekunden (20 Sekunden), die die Pumpe laufen soll
digitalWrite (2,LOW); // Setze digitalen Pin 2 auf Low (schalte Relais -> schalte Pumpe)
}
delay(86400000); // 86400000 (24 Stunden) ist die Zeit in Millisekunden, die gewartet wird und danach wird das gleiche wiederholt
delay(10000); // 86400000 (24 Stunden) ist die Zeit in Millisekunden, die gewartet wird und danach wird das gleiche wiederholt
} 
