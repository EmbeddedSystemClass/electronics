###Petites explications non exhaustive..
<hr/>

L'I2C est un acronyme pour Inter Integrated Circuit.

Le master donne la cadence sur la ligne *SCL*.
<br/>Lors d'une interaction, la ligne *SDA* est solicite.
<br/>Les choses se jouent sur le HIGHT et le LOW

Il y a alors plusieurs procedure:
	*start
	*addressage
	*restart
	*stop

Noter le LOW de la SDA juste avant le LOW du clock.

Cette amorce est suivi par une adresse (en 7 bits), celle qui va appeler le slave
<br/>puis du 8eme bit qui va demander la lecture ou l'ecriture et le 9eme qui permet de confirmer ou d'infirmer l'envoie.(*ACK* ou *NACK*).

Une fois l'adressage effectue, le device va repondre en utilisant le SDA pour renvoyer des choses.

C'est ainsi que les deux parties vont communiquer.

Soit la lecture d'un registre 0101110

	*Start:
		*Master -> device
		*[procedure start][0.1.0.1.1.1.0.][0][0]-[1][0][0][0][1][1][1][0][0]
		*Bonjour 0101110, je souhaite lire [0], ok ? [0] Juste ici 10001110, ok ? [0]
	*restart:
		*[procedure restart][0.1.0.1.1.1.0.][1][0]
		*0101110 ? tu peux ecrire [1] ! ok ? [0]
	*reponse:
		*[1][0][0][0][1][1][1][0][1]
		*Voila la reponse : 10001110 - stop [1]
	*stop precedure

	


