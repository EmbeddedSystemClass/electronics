###Reunion 31 Janvier 2017
---
**Recherche et Developpement**

`Composants :`

|	Name	|	Composant	| Package |	Link	|	DOC | Protocol  | PIN | Conso max | Prix(E) |
|	----	|	---------	| ------- |	----	|	--- | --------  | --- | --------- | ---- |
|	Temperature		|	**DS18b20**		| TO-92 |	[Farnell](http://fr.farnell.com/maxim-integrated-products/ds18b20-par/sensor-temperature-nv-alarm-3to92/dp/2085184)| [Datasheet](http://www.farnell.com/datasheets/1537425.pdf?_ga=1.110999426.645639590.1485889958)	| One-wire | 1 num | 1.5mA | !NON STOCKE! |
|	Luminosite		|	**NSL4962**	||	[Farnell](http://fr.farnell.com/advanced-photonix/nsl-4962/photo-resistance/dp/3168359)	|	[Datasheet](http://www.farnell.com/datasheets/1699948.pdf) | analogique | 1 analogique || 1.54 |
|	Humidite		| electrodes PCB(capacitance) |N/A| ext |	ext | analogique | 1 CTMU (analogique)|||
|	Niveau d'eau	| Indestructible stainless steel fork electrode of metal of doom	|N/A|[IKEA](http://www.ikea.com/fr/fr/catalog/products/30090382/)|[Video](https://www.youtube.com/watch?v=hEb68oHnuEc)| parallele |	6 num -> I/O Expander| 0A ||
|Ecran|**FC1602B04-FHYYBW-91LE**|PCB module (!need a connector!)|[Farnell](http://fr.farnell.com/fordata/fc1602b04-fhyybw-91le/afficheur-alphanumerique-16x2/dp/2674137?exaMfpn=true&categoryId=&searchRef=SearchLookAhead&searchView=table&iscrfnonsku=false)|[Datasheet](http://fr.farnell.com/fordata/fc1602b04-fhyybw-91le/afficheur-alphanumerique-16x2/dp/2674137?exaMfpn=true&categoryId=&searchRef=SearchLookAhead&searchView=table&iscrfnonsku=false)|parallele|7 num -> I/O expander|6.5mA|13.37|
|	Led | **L-154A4SURKQBDZGW** |5mm round + domed| [Farnell](http://fr.farnell.com/kingbright/l-154a4surkqbdzgw/led-multi-couleur-rgb-5mm/dp/2290374)| [Datasheet](http://www.farnell.com/datasheets/2046599.pdf) | parallele | 3 PWM | 30mA |1.17|
|	Bargraph		| **DC-10EGWA**	|Piece|	[Farnell](http://fr.farnell.com/kingbright/dc-10egwa/bargraphe-reseau-10-segts-rouge/dp/2290326?exaMfpn=true&categoryId=&searchRef=SearchLookAhead&searchView=table&iscrfnonsku=false) |	[Datasheet](http://www.farnell.com/datasheets/1683492.pdf) | parallele | 3 num	| 85mA |3.66|
|	Bluetooth	| **RN42-I/RM**	|PCB module (CMS)| [Farnell](http://fr.farnell.com/microchip/rn42-i-rm/module-bluetooth-class-2-w-ant/dp/2143310) | [Datasheet](http://www.farnell.com/datasheets/1728644.pdf?_ga=1.123256712.2075605386.1487325858)| UART	| 2 num | 50mA |12.35 !non dispo!|
| GPIO Expander | **MCP23017** | 28-pins SSOP| [Farnell](http://fr.farnell.com/microchip/mcp23017-e-ss/ic-io-expander-16bit-smd/dp/1467674) | [Datasheet](http://www.farnell.com/datasheets/12179.pdf) | IIC  | 2 num | 1mA |1.17|
|	PIC32MX|	**PIC32MX170F256B-I/SO**|28-pins SOIC| [Farnell](http://fr.farnell.com/microchip/pic32mx170f256b-i-so/ic-32bit-mcu/dp/2449077)	| [Datasheet](http://ww1.microchip.com/downloads/en/DeviceDoc/60001168J.pdf) [Errata](http://ww1.microchip.com/downloads/en/DeviceDoc/80000531H.pdf)|| 21 (E/S) |30mA|4.71|
| Pompe |Yosoo|N/A| [Amazone](https://www.amazon.fr/Yosoo-p%C3%A9ristaltique-dosage-Aquarium-Analytique/dp/B00HLCOXFI/ref=sr_1_1?ie=UTF8&qid=1487687364&sr=8-1&keywords=pompe+p%C3%A9ristaltique)|ext | Parallele | 1 numerique | 30mA | 14.59 |
| Regulateur | **MIC5219-3.3YM5-TR** | SOT-23-5 | [Farnell](http://fr.farnell.com/microchip/mic5219-3-3ym5-tr/ldo-0-5vdo-0-5a-3-3v-1-5sot23/dp/2510252) | [Datasheet](http://www.farnell.com/datasheets/683599.pdf) | N/A | 0 | see dropout |0.82|
| PushButton Switche | | | |
|||||||**TOTAL**| 152.5mA |


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
