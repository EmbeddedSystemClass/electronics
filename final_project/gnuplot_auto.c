//Dans le code du pi

#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
//		Ecrire en fin de fichier dans un fichier texte a partir de la radio
	FILE	*fichier = NULL;
	const char	*str = "10";
	
	//if (mesures = 48)
	//	system("rm data.dat");
	if ((fichier = fopen("data.dat", "a+")) == NULL) //a+ = ecriture/lecture en partant de la fin du fichier et le créé si inexistant
		return (-1);
	fprintf(fichier,"%s\t", str); //comme printf
	fclose(fichier);
// fin ecriture
	//system ("echo $data >> data.dat");
	system("sh ~/Bureau/plot.sh"); // generation auto graphique gnuplot !! changer les path ici et dans le script
	return (0);
}


