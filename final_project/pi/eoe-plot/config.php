<?php
	if (!empty($_POST['sub']))
	{
		$default_fd;
		$valide = true;
		$outconf = '';
		$data = Array(
			"bat",
			"lvl",
			"pum",
			"lum_b",
			"lum_h",
			"tem_b",
			"tem_h",
			"bat_b",
			"bat_h",
			"frq",
			"amask"
			);
		$comments = Array(
			"#bat_seuil",
			"#level_seuil",
			"#seuil_pump",
			"#lum_seuil_bas",
			"#lum_seuil_haut",
			"#temp_seuil_bas",
			"#temp_seuil_haut",
			"#min_bat",
			"#max_bat",
			"#frequency",
			"#amask"
			);

		//$ligne = "";

		$index = 0;
		foreach ($data as $f)
		{
			//jump comment line (fget() ~= get_next_line())
			//$ligne .= fgets($default_fd, 4096);
			//echo $ligne;

			if (empty($_POST[$f]))
			{
				echo "plese enter a valide " . $f . "<br />";
				$valide = false;
			}
			else if (is_numeric($_POST[$f]) !== true)
			{
				echo "plese enter an int " . $f . "<br />";
				$valide = false;
			}
			else
			{
				//write value to default file
				$outconf .= $comments[$index];
				$outconf .= "\n";
				$outconf .= $_POST[$f];
				$outconf .= "\n";

			//	fwrite($default_fd, $comments[$index]);
			//	fwrite($default_fd, "\n");
			//	fwrite($default_fd, $_POST[$f]);
			//	fwrite($default_fd, "\n");

			//	$outconf .= $_POST[$f] . " ";
			}
			$index += 1;
		}
		if ($valide)
		{
			//Open default config file
			if (!$default_fd = fopen("../default.txt", "w+"))
			{
				echo "Echec ouverture fichier.";
				exit;
			}
				fwrite($default_fd, $outconf);
				//file_put_contents('conf', $outconf);
				echo "Conf update !!! :)";
		//close file
		fclose($default_fd);
		}
	}

//read default values to set thresholds

		$def_vals = Array(0,0,0,0,0,0,0,0,0,0,0,0);
		$lines = file("../default.txt");

		$index = 0;
		foreach($lines as $n => $line)
		{
			if ($line[0] !== '#')
			{
				$def_vals[$index] = (int)$line;
				$index += 1;
			}
		}

////////	$line;/
////////	//Open default config file
////////	if (!$default_fd = fopen("../default.txt", "w+"))
////////	{
////////		echo "Echec ouverture fichier.";
////////		exit;
////////	}


////////	while (!feof($default_fd))
////////	{
////////		$line .= fread($default_fd, 1024);
////////		echo "Line =  " . $line . "<br />";
////////	}
////////	
////////	//closing file
////////	fclose($default_fd);
?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">

<html>
  <head>
    <title>e.o.e awesome kawaidess</title>
  </head>
  <body bgcolor=white>

	<p>CONFIG</p>
	<form method="post" action="config.php">
	<legend>Seuils</legend>
	<label for="bat">     Seuil accu</label> : <input type="number" min="0" max="100" step="1" value="<?php echo $def_vals[0] ?>" name="bat" id="bat" />
	<br>
	<label for="lvl">Seuil eau</label> : <input type="number"  min="0" max="5" step="1" value="<?php echo $def_vals[1] ?>" name="lvl" id="lvl" />
	<br>
	<label for="pum">Seuil pum</label> : <input type="number" min="0" max="100" step="1" value="<?php echo $def_vals[2] ?>" name="pum" id="bat" />
	<br>
	<label for="lum_b">Seuil bas lum</label> : <input type="number" min="0" max="1000" step="1" value="<?php echo $def_vals[3] ?>" name="lum_b" id="lum_b" />
	<br>
	<label for="lum_h">Seuil haut lum</label> : <input type="number" min="0" max="1000" step="1" value="<?php echo $def_vals[4] ?>" name="lum_h" id="lum_h" />
	<br>
	<label for="tem_b">Seuil bas temp</label> : <input type="number" min="-40" max="80" step="1" value="<?php echo $def_vals[5] ?>" name="tem_b" id="tem_b" />
	<br>
	<label for="tem_h">Seuil haut temp</label> : <input type="number" min="-40" max="80" step="1" value="<?php echo $def_vals[6] ?>" name="tem_h" id="tem_h" />
	<br>
	<label for="bat_b">Offset bat bas</label> : <input type="number" min="0" max="1240" step="1" value="<?php echo $def_vals[7] ?>" name="bat_b" id="bat_b" />
	<br>
	<label for="bat_h">Offset haut bat</label> : <input type="number" min="0" max="1240" step="1" value="<?php echo $def_vals[8] ?>" name="bat_h" id="bat_h" />
	<br>
	<label for="frq">Frequence</label> : <input type="number" min="0" max="100" step="1" value="<?php echo $def_vals[9] ?>" name="frq" id="frq" />
	<br>
	<label for="amask">Amask</label> : <input type="number" min="0" max="100" step="1" value="<?php echo $def_vals[10] ?>" name="amask" id="amask" />
	<br>

	<input type="submit" value="Envoyer" name="sub"/>
		<br>
		<br>
	</form>

	<a href="index.html">Back to plotage</a>.

  </body>
</html>
