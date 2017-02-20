###Composants

===
Si et seulement si le grand gourou l'autorise.
####Type Lux to analog

0.1 -> 83k Lux : [opt3001](http://www.ti.com/lit/ds/symlink/opt3001.pdf)

0.1 -> 10k Lux : [isl29102](http://www.intersil.com/content/dam/Intersil/documents/isl2/isl29102.pdf)

####Type Lux to digital

[TSL2561](https://cdn-shop.adafruit.com/datasheets/TSL2561.pdf)

Tous les produits sont sur farnell

===

####Methode artisanal

Une ldr qu'il faudrat etaloner a l'aide d'un potard en fonction de la precision voulu

[ldr520/720](http://www.stquentin-radio.com/?page=categorie&cat=19&id=0&act=0&sous_cat1=350&sous_cat2=645&ar_cat=2&v=1)


<hr/>

###Calcul

* 9~13 octets
  * A : 4~2 octets : reception de la valeurs analogique; (depent du calcul fait au prealable)
  * B : 2 octets : incrementation sur 48 mesures (1/2heures par jour); (max : [ 0011 0000 ])
  * C : 1 octets : incremantal sur 7 mesures (1 jour par semaine); (max : [ 0111 ])
  * D : 4~2 octets : valeur minimum reglable->jour (comparaison A > D)
  * E : 1 octets : valeur minimum reglable->semaine (comparaison C > E)
  * F : 1 octets : valeur incremental (garde fou pour la semaine); (max : [ 0111 ])
  * G : 2 octets : valeur incremental (garde fou pour le jour); (max : [ 0011 0000 ]

Pseudocode:
  Toutes les 1/2 heures
  <br/>if (A > D) B++;
  <br/>G++
  <br/>if G == 48 ( limite 24h )
  <br/>if (B > D) C++;
  <br/>F++;
  <br/>B = 0;
  <br/>if F == 7 ( limite 7 jours )
  <br/>return (F > E);
