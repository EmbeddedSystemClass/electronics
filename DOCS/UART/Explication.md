###UART Protocole
**U**niversal **A**synchronous **R**eceiver/**T**ransmitter

A l'origine, les uarts ressemblaient a ceci:

			  __
			-|  |-  1 -----<------------- 1
			-|  |-	2 ------<------------ 0
			-|  |-	3 -------<----------- 1
			-|  |-	4 --------<---------- 1
			-|  |-	5 ---------<--------- 1
			-|  |-	6 ----------<-------- 0
			-|  |-	7 -----------<------- 1
			-|  |-	8 ------------<------ 0
			  --

Ils ressemblent toutjours a ceci en fait, mais on ne le voit plus :o 

Maintenant, L'UART est integre un dans le microcontroleur,

<br/>Il sert a transmettre et a recevoir des datas en serie.
	Les datas sont organisees en "packets"

<br/> il utilise deux fils.
<br/> Un bits de starts est set pour savoir quand lire les bits.
<br/> La vitesse de transmission est calcule avec des multiple et des sous multiples de baud

>Les deux uart qui communiquent ensemble doivent avoir les memes baud rates (bps).

soit un packet :

![Packet](./packet.png)

![Uart](./uart.png)

TX -> Transmitter
RX -> Receiver

####LINK:
===

[Basic Uart](http://www.circuitbasics.com/basics-uart-communication/)

[Wiki](https://fr.wikipedia.org/wiki/UART)
