###Reunion 31 Janvier 2017
---
**Recherche et Developpement**

`Composants :`

|	Name	|	Composant	| Package |	Link	|	DOC | Protocol  | PIN | Conso max | Prix(E) | Prix(E) gros |
|	----	|	---------	| ------- |	----	|	--- | --------  | --- | --------- | ---- | ----|
|	Temperature		|	**DS18b20+**		| TO-92 |	[Farnell](http://fr.farnell.com/maxim-integrated-products/ds18b20/temperature-sensor/dp/2515553)| [Datasheet](http://www.farnell.com/datasheets/1917635.pdf?_ga=1.89603419.1734350136.1487955004)	| One-wire | 1 num | 1mA | 3.90 | 2.66 |
|	Luminosite		|	**NSL4962**	|TO-8|	[Farnell](http://fr.farnell.com/advanced-photonix/nsl-4962/photo-resistance/dp/3168359)	|	[Datasheet](http://www.farnell.com/datasheets/1699948.pdf) | analogique | 1 analogique || 1.54 | 1.09 |
|	Humidite		| electrodes PCB(capacitance) |N/A| ext |	ext | analogique | 1 CTMU (analogique)| | cf PCB price| cf PCB price|
|	Niveau d'eau	| Best ever indestructible stainless steel fork electrode of metal of doom from the deep |N/A|[IKEA](http://www.ikea.com/fr/fr/catalog/products/30090382/)|[Video](https://www.youtube.com/watch?v=hEb68oHnuEc)| parallele |	6 num -> I/O Expander| 0A |recup|
|Ecran|**FC1602B04-FHYYBW-91LE**|PCB module (!need a connector!)|[Farnell](http://fr.farnell.com/fordata/fc1602b04-fhyybw-91le/afficheur-alphanumerique-16x2/dp/2674137?exaMfpn=true&categoryId=&searchRef=SearchLookAhead&searchView=table&iscrfnonsku=false)|[Datasheet](http://www.farnell.com/datasheets/2169359.pdf)|parallele|7 num -> I/O expander|6.5mA|13.37| 8.92 |
|	Led | **L-154A4SURKQBDZGW** |5mm round + domed| [Farnell](http://fr.farnell.com/kingbright/l-154a4surkqbdzgw/led-multi-couleur-rgb-5mm/dp/2290374)| [Datasheet](http://www.farnell.com/datasheets/2046599.pdf) | parallele | 3 PWM | 30mA |1.17| 0.71 | 
|	Bargraph		| **DC-10EGWA**	|Piece|	[Farnell](http://fr.farnell.com/kingbright/dc-10egwa/bargraphe-reseau-10-segts-rouge/dp/2290326?exaMfpn=true&categoryId=&searchRef=SearchLookAhead&searchView=table&iscrfnonsku=false) |	[Datasheet](http://www.farnell.com/datasheets/1683492.pdf) | parallele | 20 num	-> shift registers| 85mA |3.66| 1.97|
//old|	Bluetooth	| **RN42-I/RM**	|PCB module (CMS)| [Farnell](http://fr.farnell.com/microchip/rn42-i-rm/module-bluetooth-class-2-w-ant/dp/2143310) | [Datasheet](http://www.farnell.com/datasheets/1728644.pdf?_ga=1.123256712.2075605386.1487325858)| UART	| 2 num | 50mA |12.35 !non dispo!|
|registre a decalage (x3)|**SN74HC595DR**|SOIC|[Farnell](http://fr.farnell.com/texas-instruments/sn74hc595dr/ic-sm-logic-74hc-register/dp/1607849)|[Datasheet](http://www.ti.com/lit/ds/symlink/sn74hc595.pdf)|parallele|3 num|80μA|3X0.47| 3x0.912
| GPIO Expander | **MCP23017** | 28-pins SOIC| [Farnell](http://fr.farnell.com/microchip/mcp23017-e-so/16-bit-expander-i-o-i2c-i-f-cms/dp/1332087?exaMfpn=true&categoryId=&searchRef=SearchLookAhead&searchView=table&iscrfnonsku=false) | [Datasheet](http://www.farnell.com/datasheets/12179.pdf) | IIC  | 2 num | 1mA |1.17| 0.853 |
|	PIC32MX|	**PIC32MX170F256B-I/SO**|28-pins SOIC| [Farnell](http://fr.farnell.com/microchip/pic32mx170f256b-i-so/ic-32bit-mcu/dp/2449077)	| [Datasheet](http://ww1.microchip.com/downloads/en/DeviceDoc/60001168J.pdf) [Errata](http://ww1.microchip.com/downloads/en/DeviceDoc/80000531H.pdf)|| 21 (E/S) |30mA|4.71| 2.76 |
| Pompe |**Yosoo**|N/A| [Amazone](https://www.amazon.fr/Yosoo-p%C3%A9ristaltique-dosage-Aquarium-Analytique/dp/B00HLCOXFI/ref=sr_1_1?ie=UTF8&qid=1487687364&sr=8-1&keywords=pompe+p%C3%A9ristaltique)|ext | Parallele | 1 numerique | 30mA | 14.59 | -- |
| Regulateur 3.3V | **LM1117T-3.3/NOPB** | TO-220-3 | [Farnell](http://fr.farnell.com/texas-instruments/lm1117t-3-3-nopb/regulateur-lineaire-3-3v/dp/1469056) | [Datasheet](http://www.ti.com/lit/ds/symlink/lm1117.pdf) | N/A | 0 | see dropout |0.82| 0.531
//old|Support Batteries|**KEYSTONE  1047**|N/A|[Farnell](http://fr.farnell.com/keystone/1047/battery-holder-18650-li-ion-2cell/dp/2501206)|[Datasheet](http://www.farnell.com/datasheets/1926460.pdf)|N/A|N/A|||
|Batteries|Fenix|18650 (x2) | [Fenix](https://www.lampe-torche-fenix.fr/pile-rechargeable-fenix-arb-l18-18650-3500-mah-pour-tous-les-lampes-fenix-utilisants-des-18650.html)|nop|N/A|N/A|N/A|2x21.90| -- |
| PushButton Switche |**EOZ** | | [Farnell](http://fr.farnell.com/eoz/09-03201-02/commutateur-spst-co-0-5a-12v-pcb/dp/1608080) | [Datasheet](http://www.farnell.com/datasheets/2010029.pdf)| | |1.10 | 0.992 |
| Button Reset | **ALCOSWITCH 1437566-3** | CMS | [Farnell](http://fr.farnell.com/alcoswitch-te-connectivity/1437566-3/bouton-poussoir-spst-0-05a-24v/dp/2468741)| [Datasheet](http://www.farnell.com/cad/1885096.pdf) || |2.41 | 0.156 |
|||||||**TOTAL**| 152.5mA |
|	Quartz		|	**ABRACON  AB38T-32.768KHZ**		| AB38T |	[Farnell](http://fr.farnell.com/abracon/ab38t-32-768khz/crystal-32-768k-12-5pf-cl-watch/dp/1611828)| [Datasheet](http://www.farnell.com/datasheets/1883667.pdf?_ga=2.40960107.890087731.1495798896-304989867.1493929463)	| -- | 2 | -- | 0.18 | 0.07 |


ARROSAGE 

Il faut declancher la pompe en fonction de l'humidite de la terre et de la temperature  ambiante cf site :

https://www.rustica.fr/articles-jardin/arroser-basilic,5737.html
https://www.rustica.fr/articles-jardin/comment-arroser-plantes-interieur,2429.html


CTMU info

http://people.ece.cornell.edu/land/courses/ece4760/PIC32/index_CTMU.html

http://ww1.microchip.com/downloads/en/AppNotes/CTMU%2001375a.pdf

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
