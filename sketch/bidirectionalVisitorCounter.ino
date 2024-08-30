#include <LiquidCrystal.h>  // Include the LiquidCrystal library for LCD display

// Define pin connections for LCD display
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  // Initialize the LiquidCrystal library with the pin numbers

// Define pin connections for sensors, LEDs, and buzzer
int entryir = 6;    // Pin for the entry IR sensor
int exitir = 7;     // Pin for the exit IR sensor
int count1 = 0;     // Visitor counter
int red = 5;        // Pin for the red LED (exit indicator)
int green = 4;      // Pin for the green LED (entry indicator)
int buzzer = 14;    // Pin for the buzzer

void setup() 
{
  Serial.begin(9600);  // Initialize serial communication at 9600 bits per second
  pinMode(entryir, INPUT);  // Set the entry IR sensor pin as input
  pinMode(exitir, INPUT);   // Set the exit IR sensor pin as input
  pinMode(red, OUTPUT);     // Set the red LED pin as output
  pinMode(green, OUTPUT);   // Set the green LED pin as output
  pinMode(buzzer, OUTPUT);  // Set the buzzer pin as output

  Serial.println("Bidirectional Visit Counter");  // Print message to serial monitor
  lcd.begin(16, 2);   // Initialize the LCD with 16 columns and 2 rows
  lcd.clear();        // Clear the LCD screen
  lcd.setCursor(0, 0);  // Set the cursor to the first row, first column
  lcd.print("  BIDIRECTIONAL  ");  // Print message on the first row
  lcd.setCursor(0, 1);  // Set the cursor to the second row, first column
  lcd.print("VISITER COUNTER");  // Print message on the second row
  delay(1000);  // Delay for 1 second

  // Initialize all outputs to LOW (off)
  digitalWrite(red, LOW);   
  digitalWrite(green, LOW);
  digitalWrite(buzzer, LOW);
}

void loop() 
{
  int entryval = digitalRead(entryir);  // Read the state of the entry IR sensor
  int exitval = digitalRead(exitir);    // Read the state of the exit IR sensor

  // Check if the entry sensor is triggered (LOW state)
  if (entryval == LOW) 
  {
    count1++;  // Increment the visitor count
    digitalWrite(green, HIGH);  // Turn on the green LED
    lcd.clear();  // Clear the LCD screen
    lcd.setCursor(0, 0);  // Set cursor to the first row
    lcd.print("Total Visitor:");  // Print message on the first row
    lcd.setCursor(0, 1);  // Set cursor to the second row
    lcd.print(count1);  // Display the updated visitor count
    delay(1000);  // Delay for 1 second

    digitalWrite(green, LOW);  // Turn off the green LED
    delay(500);  // Delay for 0.5 seconds
  }

  // Check if the exit sensor is triggered (LOW state)
  if (exitval == LOW) 
  {
    count1--;  

    // Ensure count does not go below zero
    if (count1 < 0) 
    { 
      count1 = 0;
    }
    lcd.clear();  // Clear the LCD screen
    lcd.setCursor(0, 0);  // Set cursor to the first row
    lcd.print("Total Visitor:");  // Print message on the first row
    lcd.setCursor(0, 1);  // Set cursor to the second row
    lcd.print(count1);  // Display the updated visitor count

    digitalWrite(red, HIGH);  // Turn on the red LED
    delay(1500);  // Delay for 1.5 seconds
    digitalWrite(buzzer, LOW);  // Turn off the buzzer
    digitalWrite(red, LOW);  // Turn off the red LED
    delay(500);  // Delay for 0.5 seconds
  }

  // Check if the visitor count exceeds the maximum capacity (6)
  if (count1 > 6) 
  {
    digitalWrite(buzzer, HIGH);  // Turn on the buzzer to alert maximum capacity reached
    delay(1000);  // Delay for 1 second
  }
}
