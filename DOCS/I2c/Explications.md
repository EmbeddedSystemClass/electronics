###Petites explications non exhaustive..
<hr/>

L'I2C est un acronyme pour Inter Integrated Circuit.

Le master donne la cadence sur la ligne **SCL**.
<br/>Lors d'une interaction, la ligne **SDA** est solicite.
<br/>Les choses se jouent sur le HIGHT et le LOW que l'on envoit sur le SDA. [(la clock est fixe)]

Les niveaux utilisés entre les lignes de bus sont proportionnels à VDD :
| ETAT | NIVEAU|
| ---  | ---   |
|Dominant ou « 0 » ou « LOW » | de -0,5V à 0,3xVDD |
|Récessif ou « 1 » ou « HIGH » | de 0,7xVDD à VDD |

Il y a alors plusieurs procedure:
	*start
	*addressage
	*restart
	*stop


Cette amorce est suivi par une adresse (en 7 bits), celle qui va appeler le slave
<br/>puis du 8eme bit qui va demander la lecture ou l'ecriture et le 9eme qui permet de confirmer ou d'infirmer l'envoie.(**ACK** ou **NACK**).

Une fois l'adressage effectue, le device va repondre en utilisant le SDA pour renvoyer des choses.

C'est ainsi que les deux parties vont communiquer.

Soit la lecture d'un registre 0101110

	*Start:
		*Master -> device
		  (LOW SDA)	     1 2 3 4 5 6 7   8  9 _ 1  2  3  4  5  6  7  8  9 		
		  *[procedure start][0.1.0.1.1.1.0.][0][0]-[1][0][0][0][1][1][1][0][0]
		*Bonjour 0101110, je souhaite avoir l'info sur cette adress 10001110.
	*restart:
		  (LOW SDA)	       1 2 3 4 5 6 7   8  9
		  *[procedure restart][0.1.0.1.1.1.0.][1][0]
		*0101110 ?                             |->Ecriture [1]
	*reponse: 1  2  3  4  5  6  7  8  9 		
		*[1][0][0][0][1][1][1][0][1]
		*Reponse :10001110        |- stop [1]
	*stop precedure

	


