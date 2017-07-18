/*
 * Exemple de code pour la bibliothèque Mirf – Client d'envoi de texte
 */
#include <SPI.h>      // Pour la communication via le port SPI
#include <Mirf.h>     // Pour la gestion de la communication
#include <nRF24L01.h> // Pour les définitions des registres du nRF24L01
#include <MirfHardwareSpiDriver.h> // Pour la communication SPI

void setup() {
  Serial.begin(9600);
   
  Mirf.cePin = 9;     // Broche CE sur D9
  Mirf.csnPin = 10;   // Broche CSN sur D10
  Mirf.spi = &MirfHardwareSpi; // On veut utiliser le port SPI hardware
  Mirf.init();        // Initialise la bibliothèque

  Mirf.channel = 1;   // Choix du canal de communication (128 canaux disponibles, de 0 à 127)
  Mirf.payload = 4;  // Taille d'un message (maximum 32 octets)
  Mirf.configRegister(RF_SETUP, 0x07); // 1 Mb/s et 0 dBm (puissance maximum) 
  Mirf.config(); // Sauvegarde la configuration dans le module radio

  Mirf.setTADDR((byte *) "11111"); // Adresse de transmission
  Mirf.setRADDR((byte *) "22222"); // Adresse de réception
  Serial.begin(9600);
  byte  reg_val = 0;
  char  index = 0;

  for (index = 0; index < 0x18; index++)
  {
    Mirf.readRegister(index, &reg_val, 1);
    Serial.print("reg_addr: ");
    Serial.print(index, HEX);
    Serial.print("\tvalue = ");
    Serial.println(reg_val, HEX);
  }
  Serial.println("Go !"); 
}

uint32_t valeur = 0x4502000a;   // contient la valeur à envoyer
byte valeur_octet[4];         // contient la valeur découpée en octet pour l’envoi

void loop() {
  
  while(Mirf.isSending())
 {
    delay(5);
  }
  valeur_octet[0] = valeur & 0xFF; // 1er octet 
  valeur_octet[1] = (valeur & 0xFF00) >> 8; // 2ème octet
  valeur_octet[2] = (valeur & 0xFF0000) >> 16;
  valeur_octet[3] = (valeur & 0xFF000000) >> 24;
  Mirf.send(valeur_octet); 
  delay(100);
} 
