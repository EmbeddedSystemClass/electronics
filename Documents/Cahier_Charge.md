###CAHIER DES CHARGES:

* Un nom de projet méga stylé
* une introduction expliquant votre projet
* un block diagram montrant tous les éléments nécessaires
	* au centre votre PIC32
	* aux bords la connectique
	* entre les deux : qui est connecté à quoi, comment électriquement et avec quel protocole
* un mode d'emploi prévisionnel expliquant comment l'utiliser
* un utilisateur à qui on donne ce mode d'emploi doit pouvoir utiliser le produit final
	> ca, ca vous aide à être sûr que vous avez pas oublié un bouton on/off ou un led de status :)

* les spécifications du produit, exemples non exhaustifs (tout dépend de ce que vous faites) :
	* affichage: 2 lignes x 16 caractères
	* mémoire : 1000 évenements
	* débit : 10ko/s
	* autonomie : 4h
	* fréquence de rafraichissement : 30 Hz
	* ...

* les calculs expliquant vos choix techniques de composants, exemples non exhaustifs :
	> un évenement contient la date (8 octets) + l'id du user (2 octets) + un texte de 32 caractères max (32 octets) donc, pour en stocker 1000 j'ai besoin de 42ko (336kbits) de flash, nous avons donc choisi un flash 512kbits (ref fabricant, ref farnell)
	
	> mon système va consommer 200mA @ 3.3V, pour avoir 4h d'autonomie j'aurai donc besoin d'une batterie de 800mAh minimum, j'ai donc choisi cette batterie 3.6V, 1Ah (ref fabricant, ref farnell) et j'utiliserai un régulateur de tension (ref fabricant, ref farnell) pour faire 3.6V -> 3.3V
	
	> pour rafraichir mon display j'ai besoin d'envoyer 100 octets de data, à 30Hz il faut donc que ma liaison fasse au moins 3ko/s soit 24kbit/s, l'interface prévue (xxxxx) est donc correctement dimensionnée

* une description des protocoles que vous aller utiliser, comment vous allez les utiliser, et en quoi vous êtes sûrs que ca couvre votre besoin :
	* documentations de référence
	* implémentation/variante choisie
	* limitations que vous comptez vous imposer (n'imaginez même pas coder une stack USB complète par exemple)

* un listing des principaux composants avec leur référence fabricant et leur référence farnell
	* leur datasheet
	* vérification que l'interface est compatible avec votre circuit (vérifier les tensions et les débits notamment)

* des schémas d'exemple d'implémentation des composants que vous avez choisi
* des schémas d'exemple de "tripaille" pour les mécanismes que vous ne savez pas déjà faire (circuits typiques, cf mon cours), je pense notamment à tous ceux qui ont de l'analogique (audio/touch panel/...), le conditionnement du signal.

	> Le but est de dissiper les incertitudes, vous devez me montrer que, avec les choix techniques que vous avez fait, vous pourrez réaliser ce que vous avez prévu de faire, que vous savez comment vous allez le faire. Tout doit être clair dans votre esprit.
	
===

###Quelques infos en vrac :

* vous devez utiliser un microcontrôleur de la gamme PIC32 de chez Microchip, pas d'exception
	
* les seuls fournisseurs que l'école peut payer sont Farnell et Olimex, pour tous les autres c'est à vos frais
	
* l'école, dans la mesure du raisonnable, prend en charge vos PCB et vos composants (POC et prototype) mais pas les "à côtés" (Raspberry Pi, carte SD, ...) ni les consommables (batteries / piles notamment)
	*pour approfondir les notions d'électricité et de semiconducteurs de base, vous pouvez lire un post que j'ai fait l'année dernière, il y a pas mal de liens bien faits, lisez le, ça vous sera utile: [https://forum.intra.42.fr/topics/4568/messages/last]
