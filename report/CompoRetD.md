###Reunion 31 Janvier 2017
---
**Recherche et Developpement**

`Composants :`

|	Mesure		|	Name	|	Composant	|	Link	|	DOC		| PIN | Conso max |
|	------		|	----	|	---------	|	----	|	---		| --- | --------- |
|	C	|	Temperature		|	**DS18b20**		|	[Farnell](http://fr.farnell.com/maxim-integrated-products/ds18b20-par/sensor-temperature-nv-alarm-3to92/dp/2085184)| [Datasheet](http://www.farnell.com/datasheets/1537425.pdf?_ga=1.110999426.645639590.1485889958)	| 1 one wire|
|	Lum	|	Luminosite		|	**NSL4962**	|	[Farnell](http://fr.farnell.com/advanced-photonix/nsl-4962/photo-resistance/dp/3168359)	|	[Datasheet](http://www.farnell.com/datasheets/1699948.pdf) | 1 analogique |
|	Hum	|	Humidite		| electrodes PCB(capacitance) |ext	|	ext| 1 CTMU (analogique)|
|	Nv	|	Niveau d'eau	| electrodes maison	|	|	|	6 (numerique)| 0A |
|	|	Ecran	|	**FC1602B04-FHYYBW-91LE** |	[Farnell](http://fr.farnell.com/fordata/fc1602b04-fhyybw-91le/afficheur-alphanumerique-16x2/dp/2674137?exaMfpn=true&categoryId=&searchRef=SearchLookAhead&searchView=table&iscrfnonsku=false) |	[Datasheet](http://fr.farnell.com/fordata/fc1602b04-fhyybw-91le/afficheur-alphanumerique-16x2/dp/2674137?exaMfpn=true&categoryId=&searchRef=SearchLookAhead&searchView=table&iscrfnonsku=false)| 2 i2c (puce) | 6.5mA |
|	|	Led | **L-154A4SURKQBDZGW** | [Farnell](http://fr.farnell.com/kingbright/l-154a4surkqbdzgw/led-multi-couleur-rgb-5mm/dp/2290374)| [Datasheet](http://www.farnell.com/datasheets/2046599.pdf) | 3 PWM | 30mA |
|	|	Bargraph		| **DC-10EGWA**	|	[Farnell](http://fr.farnell.com/kingbright/dc-10egwa/bargraphe-reseau-10-segts-rouge/dp/2290326?exaMfpn=true&categoryId=&searchRef=SearchLookAhead&searchView=table&iscrfnonsku=false) |	[Datasheet](http://www.farnell.com/datasheets/1683492.pdf)| 3 (numerique)	| 85mA |
|	|	Bluetooth	| **RN42-I/RM**	| [Farnell](http://fr.farnell.com/microchip/rn42-i-rm/module-bluetooth-class-2-w-ant/dp/2143310) | [Datasheet](http://www.farnell.com/datasheets/1728644.pdf?_ga=1.123256712.2075605386.1487325858)	| 2 UART |
|  | GPIO extension | MPC23017 |  |  | 2 I2C | 1mA |
|	|	PIC32MX|	**xxxF256B(170/230/270)**| [Farnell](http://fr.farnell.com/microchip/pic32mx170f256b-50i-sp/ic-32bit-mcu/dp/2449079)	| [Datasheet](http://ww1.microchip.com/downloads/en/DeviceDoc/60001168J.pdf) [Errata](http://ww1.microchip.com/downloads/en/DeviceDoc/80000531H.pdf)| 21 (i/o) |
| | Pompe | [Yosoo](https://www.amazon.fr/Yosoo-p%C3%A9ristaltique-dosage-Aquarium-Analytique/dp/B00HLCOXFI/ref=sr_1_1?ie=UTF8&qid=1487687364&sr=8-1&keywords=pompe+p%C3%A9ristaltique)| ext | ext | 1 numerique | 30mA |
| | Regulateur | | | |
| | PushButton Switche | | | |
||||||**TOTAL**| 151.5 |


Petits sites sur comment tout faire tout seul

http://gardenbot.org/howTo/

https://luckyresistor.me/2017/02/08/how-to-design-a-cheap-plant-watering-sensor-part-1/

https://www.dfrobot.com/wiki/index.php/Capacitive_Soil_Moisture_Sensor_SKU:SEN0193#Connection_Diagram

Le site de microship pour choisir son PIC32MX

http://www.microchip.com/maps/microcontroller.aspx

Theorie regulateurs de tension:
https://www.sonelec-musique.com/electronique_theorie_reg_tension.html

Ce qui nous manque

SPECIFICATION DU PRODUIT
. Autonomie
. Debit
. Frequence de rafraichissement
(Systeme de mise en veille du systeme par capteur de luminosite ?)
=>BILAN ELECTRIQUE

PROTOCOLE
. 1wire
. i2c
. pour le bluetooth ?
. pour la LED

POMPE
.Calcule du nombre de tour necessaire pour arroser et donc calcule de la consommation d'electricite

INFO EN PLUS

moisture sensor = pin CTMU et timer du PIC

Regulateur a chercher => intergrate switcher

boitier 5? piles 6V AA (il existe des piles rechargeable 1,5V donc dans ce cas 4 piles ?)


Rechercher *Soil moisture Sensor*

https://www.tindie.com/products/miceuz/i2c-soil-moisture-sensor/

http://www.vegetronix.com/Products/VH400/

https://imko.de/en/products/soilmoisture/soil-moisture-sensors/trimepico32

http://zerocharactersleft.blogspot.fr/2011/11/pcb-as-capacitive-soil-moisture-sensor.html?m=1

Super cher !!!
