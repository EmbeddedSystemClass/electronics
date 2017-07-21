//dans le script
//definir des type de ligne:
//	set style line 10 linetype 1 linecolor rgb "" linewidth 1
// a l'appel :  plot "name" linestyle 1
//liste code couleur:
//saumon : fa8072
//orange : f4a460
//rouge : ff0000
//bleu : 4169e1
//bleu fade : 6a5acd
//vert : 2e8b57
//violet : 800080
//gris : 778899
//or : ffd700
//noir : 000000
//blanc : ffffff

//Dans le code du pi

#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
//		Ecrire en fin de fichier dans un fichier texte a partir de la radio
	FILE	*fichier = NULL;
	const char	*str = "10";
	
	if ((fichier = fopen("data.dat", "a+")) == NULL)
		return (-1);
	fprintf(fichier,"%s\t", str);
	fclose(fichier);
// fin ecriture
	//system ("echo $data >> data.dat");
	system("sh ~/Bureau/plot.sh"); // generation auto graphique gnuplot
	return (0);
}


