<?php
	if (!empty($_POST['sub']))
	{
		$valide = true;
		$outconf = '';
		$data = Array(
			"bat",
			"lvl",
			"pum",
			"lum_b",
			"lum_h"
			);
		foreach ($data as $f)
		{
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
				//$outconf .= $f . ': ' . $_POST[$f] . "\n";
				$outconf .= $_POST[$f] . " ";
		}
		if ($valide)
		{
			file_put_contents('conf', $outconf);
			echo "Conf update !!! :)";
		}
	}
?><!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
  <head>
    <title>e.o.e awesome kawaidess</title>
  </head>
  <body bgcolor=white>

	<p>CONFIG</p>
	<form method="post" action="config.php">
	<legend>Seuils</legend>
	<label for="bat">Seuil accu</label>   	: <input type="number" min="0" max="100" step="1" value="10" name="bat" id="bat" />
	<br>
	<label for="lvl">Seuil eau </label> : <input type="number"  min="0" max="5" step="1" value="1" name="lvl" id="lvl" />
	<br>
	<label for="pum">Seuil pum</label> : <input type="number" min="0" max="100" step="1" value="50" name="pum" id="bat" />
	<br>
	<label for="lum_b">Seuil bas lum</label> : <input type="number" min="0" max="1000" step="1" value="500" name="lum_b" id="lum_b" />
	<br>
	<label for="lum_h">Seuil haut lum</label> : <input type="number" min="0" max="1000" step="1" value="900" name="lum_h" id="lum_h" />
	<br>
	<label for="tem_b">Seuil bas temp</label> : <input type="number" min="-40" max="80" step="1" value="5" name="tem_b" id="tem_b" />
	<br>
	<label for="tem_h">Seuil haut temp</label> : <input type="number" min="-40" max="80" step="1" value="35" name="tem_h" id="tem_h" />
	<br>
	<label for="bat_b">Offset bat bas</label> : <input type="number" min="0" max="1240" step="1" value="350" name="bat_b" id="bat_b" />
	<br>
	<label for="bat_h">Offset haut bat</label> : <input type="number" min="0" max="1240" step="1" value="792" name="bat_h" id="bat_h" />
	<br>
	<label for="frq">Frequence</label> : <input type="number" min="0" max="100" step="1" value="1" name="frq" id="frq" />
	<br>
	<label for="amask">Amask</label> : <input type="number" min="0" max="100" step="1" value="1" name="amask" id="amask" />
	<br>

	<input type="submit" value="Envoyer" name="sub"/>
		<br>
		<br>
	</form>

	<a href="index.html">Back to plotage</a>.

  </body>
</html>
