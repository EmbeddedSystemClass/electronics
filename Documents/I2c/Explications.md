###Petites explications non exhaustive..
<hr/>

L'I2C est un acronyme pour Inter Integrated Circuit.

Le master donne la cadence sur la ligne *SCL*.
<br/>Lors d'une interaction, la ligne *SDA* est solicite.
<br/>Les choses se jouent sur le HIGHT et le LOW

Il y a alors une procedure de "start" :
	___
		\_____ SCL (clock)
	_
	  \_______ SDA (data)

Noter le LOW de la SDA juste avant le LOW du clock.

Cette amorce est suivi par une adresse (en 7 bits), celle qui va appeler le slave
<br/>puis du 8eme bit qui va confimer ou infirmer selon qu'il soit 1 ou 0 (*ACK* ou *NACK*).

Une fois l'adressage effectue, le device va repondre en utilisant le SDA pour renvoyer des choses.

C'est ainsi que les deux parties vont communiquer.


