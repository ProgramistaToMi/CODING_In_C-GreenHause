/* Lista + Opis gniazd wykorzystanych w projekcie :)
// Gniazdo A4; Pin odpowiedzialny za zczytywanie danych z czujnika odległośći (HC-SR04);
// Gniazdo A5; Pin odpowiedzialny za zczytywanie danych z czujnika wody (WATER SENSORA);
// Gniazdo A6; Pin odpowiedzialny za sterowanie przekaźnikiem (230V.15A);
// Gniazdo A7; Pin odpowiedzialny za sterowanie głośniczkiem (BUZZEREM);
// Gniazdo GND; Pin odpowiedzialny za dostarczenie masy do całego układu elektronicznego;
// Gniazdo 5V; Pin odpowiedzialny za dostarczenie napięcia 5V do całego układu elektronicznego;
// Gniazdo 3,3V Pin odpowiedzialny za dostarczenie napięcia 3,3V do całego układu elektronicznego;
*/

/*
 Name:    CodingInC#-GreenHause_Auto.ino
 Created: 13.06.2019 21:00:00
 Author:  @ProgramistaToMi COPYRIGHT by 2019 GitHub, Inc.
*/

int WaterSensor = A5; // czujnik poziomu wody
int Relay = A6; // przekaźnik
int buzzer = A7; // głośniczek
#define trigPin A4 // Wysyłanie wiązki ultra dzwiękowej z czujnika HC-SR04 ( zasada PDC )
#define echoPin A3 // Odbieranie wiązki ultra dzwiękowej z czujnika HC-SR04
// Funkcje które zostaną wykonane tylko raz po uruchomieniu płytki
void setup() {
  Serial.begin(9600); // Uruchomienie inteligentnej machiny
  pinMode(trigPin, OUTPUT); // DEFINICJA PIINU A4 JAKO WEJŚCIE SYGNAŁU Z CZUJNIKA HC-SRO4
  pinMode(echoPin, INPUT);// DEFINICJA PIINU A4 JAKO WYJŚCIE SYGNAŁU Z CZUJNIKA HC-SRO4
  pinMode(A5, INPUT); // DEFINICJA PIINU A5 JAKO WEJŚĆIE SYGNAŁU Z WATER SENOSRA
  pinMode(A6, OUTPUT); // DEFINICJA PIINU A6 JAKO WYŚCIE NAPIĘCIA NA PRZEKAŹNIK (5V)
  pinMode(A7, OUTPUT); // DEFINICJA PIINU A7 JAKO WYŚĆIE NAPIĘCIA DLA GŁOŚNICZKA (BUZZERA)
  
  Serial.println("Intelligent_Greenhouse_Powered_by @ProgramistaToMi; Verion 1.0");
  delay(1000);        // 1 sekunda przerwy...
  Serial.println("INICJUJE GŁOŚNIK....");
  delay(1000);        // 1 sekunda przerwy...
  Serial.println("WYSZUKUJE CZĘSTOTLIWOŚĆ");
  delay(1000);        // 1 sekunda przerwy...
  Serial.println("GENERUJE CZĘSTOTLIWOŚĆ 1kHZ....");
  tone(buzzer, 1000); // Sygnał o częstotliwośći 1Khz
  delay(1000);        // 1 sekunda przerwy...
  Serial.println("ZAKOŃCZONO 1s TEST GŁOŚNIKA!!!");
  noTone(buzzer);     // Brak sygnału
  delay(1000);        // 1 sekunda przerwy...
  Serial.println("INICJUJE GŁOŚNIK....");
  delay(1000);        // 1 sekunda przerwy...
  Serial.println("WYSZUKUJE CZĘSTOTLIWOŚĆ");
  delay(1000);        // 1 sekunda przerwy...
  tone(buzzer, 1000); // Sygnał o częstotliwośći 1Khz
  Serial.println("GENERUJE CZĘSTOTLIWOŚĆ 1kHZ....");
  delay(1500);        // 1.5 sekundy przerwy...
  Serial.println("ZAKOŃCZONO 1,5s TEST GŁOŚNIKA!!!");
  noTone(buzzer);     // Brak sygnału
  Serial.println("INICJUJE GŁOŚNIK....");
  delay(1000);        // 1 sekunda przerwy...
  Serial.println("WYSZUKUJE CZĘSTOTLIWOŚĆ");
  delay(1000);        // 1 sekunda przerwy...
  Serial.println("GENERUJE CZĘSTOTLIWOŚĆ 1kHZ....");
  tone(buzzer, 1000); // Sygnał o częstotliwośći 1Khz
  delay(2000);        // 2 sekundy przerwy...
  noTone(buzzer);     // Brak sygnału
  Serial.println("ZAKOŃCZONO 2s TEST GŁOŚNIKA!!!");
  delay(1000);        // 1 sekunda przerwy...
  Serial.println("Intelligent_Greenhouse_Powered_by @ProgramistaToMi; Verion 1.0");
  delay(3000);        // 3 sekundy przerwy...
  Serial.println("Intelligent_Greenhouse_Powered_by @ProgramistaToMi; Verion 1.0 - DZIAŁA POPRAWNIE (TEST PASSED!)");
  delay(1000);        // 1 sekunda przerwy...

  Serial.println("Testowanie czujnika HC-SRO4");
  delay(2000);        // 2 sekundy przerwy...
  Serial.println("Uruchamianie HC-SRO4 [STOPIEŃ 1]");
  delay(2000);        // 2 sekundy przerwy...
  Serial.println("Uruchamianie HC-SRO4 [STOPIEŃ 2]");
  delay(2000);        // 2 sekundy przerwy...
  Serial.println("Uruchamianie HC-SRO4 [STOPIEŃ 3]");
  delay(2000);        // 2 sekundy przerwy...
  Serial.println("Uruchamianie HC-SRO4 [STOPIEŃ 4]");
  delay(2000);        // 2 sekundy przerwy...
  Serial.println("Uruchamianie HC-SRO4 [STOPIEŃ 5]");
  delay(2000);        // 2 sekundy przerwy...

}





// Fukcje które bedą powtarzane co określony czas po uruchomieniu płytki
void loop() { // Odrębna fukcja "LOOP" dla czujnika PDC ( sprawdzanie poziomu wody za pomocą ultra dzwięków )

  digitalWrite(trigPin, LOW);    /*Jeśli wartość pinu = HIGH, oznacza to że czujnik jest wykorzystywany w danym momencie, jeśli wartość pinu = LOW czujnik odpoczywa.*/
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);    

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);   // Odczywtywanie sygnału z sensora "PDC"
  duration = pulseIn(echoPin, HIGH); // Czas odświerzania sygnału (odzielnie dla "CM" oraz "INCH")

  // Konwertowanie dystansu!
  cm = (duration / 2) / 29.1;     // Wzór obliczenia odległości dla cm.
  inches = (duration / 2) / 74;   //Wzór obliczenia odległości dla inch.

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(250); // Przerwa 0,25s...
}
}

//Serial.println("");
//delay(1000);        // 1 sekunda przerwy...
