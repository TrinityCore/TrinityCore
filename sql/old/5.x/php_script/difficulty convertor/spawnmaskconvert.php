<?php
// Executer ces requetes AVANT d'executer le convertisseur
/*
ALTER TABLE creature CHANGE spawnMask spawnMask INT(8);
ALTER TABLE gameobject CHANGE spawnMask spawnMask INT(8);
*/
define("SPAWNMASK_DUNGEON_NORMAL_NEW", 2);
define("SPAWNMASK_DUNGEON_HEROIC_NEW", 4);
define("SPAWNMASK_RAID_10MAN_NORMAL_NEW", 8);
define("SPAWNMASK_RAID_25MAN_NORMAL_NEW", 16);
define("SPAWNMASK_RAID_10MAN_HEROIC_NEW", 32);
define("SPAWNMASK_RAID_25MAN_HEROIC_NEW", 64);

define("SPAWNMASK_DUNGEON_NORMAL", 1);
define("SPAWNMASK_DUNGEON_HEROIC", 2);
define("SPAWNMASK_RAID_10MAN_NORMAL", 1);
define("SPAWNMASK_RAID_25MAN_NORMAL", 2);
define("SPAWNMASK_RAID_10MAN_HEROIC", 4);
define("SPAWNMASK_RAID_25MAN_HEROIC", 8);

for($i = 0; $i < 1200; $i++)
	$mapType[$i] = 0;
	
// Load maps type from dbc file
$csv = fopen("Map.dbc.csv", "r");
while (($data = fgetcsv($csv)) !== FALSE) 
{
	$mapType[$data[0]] = $data[2];
}

// Mysql Connect
$connect = mysql_connect("localhost:5876", "root", "rWwubSTy3JE1Oem") or die (mysql_error());
mysql_select_db("trinworld505", $connect);


// Convert creature spawns data
$creature_spawn = mysql_query("SELECT guid, map, spawnMask FROM creature;");

if(!$creature_spawn)
	die("Table creature vide !");
	
while($row = mysql_fetch_assoc($creature_spawn))
{
	$oldSpawnMask = $row['spawnMask'];
	$newSpawnMask = 0;
	$map = $row['map'];
	$guid = $row['guid'];
	
	
	// MAP_RAID
	if($mapType[$map] == 2)
	{
		if($oldSpawnMask & SPAWNMASK_RAID_10MAN_NORMAL)
			$newSpawnMask |= SPAWNMASK_RAID_10MAN_NORMAL_NEW;
		if($oldSpawnMask & SPAWNMASK_RAID_25MAN_NORMAL)
			$newSpawnMask |= SPAWNMASK_RAID_25MAN_NORMAL_NEW;
		if($oldSpawnMask & SPAWNMASK_RAID_10MAN_HEROIC)
			$newSpawnMask |= SPAWNMASK_RAID_10MAN_HEROIC_NEW;
		if($oldSpawnMask & SPAWNMASK_RAID_25MAN_HEROIC)
			$newSpawnMask |= SPAWNMASK_RAID_25MAN_HEROIC_NEW;			
	}
	// MAP_INSTANCE
	else if($mapType[$map] == 1)
	{
		if($oldSpawnMask & SPAWNMASK_DUNGEON_NORMAL)
			$newSpawnMask |= SPAWNMASK_DUNGEON_NORMAL_NEW;
		if($oldSpawnMask & SPAWNMASK_DUNGEON_HEROIC)
			$newSpawnMask |= SPAWNMASK_DUNGEON_HEROIC_NEW;
	}
	
	echo "Map Type : ".$mapType[$map]." old : ".$oldSpawnMask." new : ".$newSpawnMask."<br>";
	
	if($newSpawnMask != 0)
		mysql_query("UPDATE creature set spawnmask = $newSpawnMask WHERE guid =$guid");
}

echo "creature ok ! <br>";
// Convert gameobject spawns data
$gameobject_spawn = mysql_query("SELECT guid, map, spawnMask FROM gameobject;");

if(!$gameobject_spawn)
	die("Table gameobject vide !");
	
while($row = mysql_fetch_assoc($gameobject_spawn))
{
	$oldSpawnMask = $row['spawnMask'];
	$newSpawnMask = 0;
	$map = $row['map'];
	$guid = $row['guid'];
	
	
	// MAP_RAID
	if($mapType[$map] == 2)
	{
		if($oldSpawnMask & SPAWNMASK_RAID_10MAN_NORMAL)
			$newSpawnMask |= SPAWNMASK_RAID_10MAN_NORMAL_NEW;
		if($oldSpawnMask & SPAWNMASK_RAID_25MAN_NORMAL)
			$newSpawnMask |= SPAWNMASK_RAID_25MAN_NORMAL_NEW;
		if($oldSpawnMask & SPAWNMASK_RAID_10MAN_HEROIC)
			$newSpawnMask |= SPAWNMASK_RAID_10MAN_HEROIC_NEW;
		if($oldSpawnMask & SPAWNMASK_RAID_25MAN_HEROIC)
			$newSpawnMask |= SPAWNMASK_RAID_25MAN_HEROIC_NEW;			
	}
	// MAP_INSTANCE
	else if($mapType[$map] == 1)
	{
		if($oldSpawnMask & SPAWNMASK_DUNGEON_NORMAL)
			$newSpawnMask |= SPAWNMASK_DUNGEON_NORMAL_NEW;
		if($oldSpawnMask & SPAWNMASK_DUNGEON_HEROIC)
			$newSpawnMask |= SPAWNMASK_DUNGEON_HEROIC_NEW;
	}
	
	if($newSpawnMask != 0)
		mysql_query("UPDATE gameobject set spawnmask = $newSpawnMask WHERE guid =$guid");
}


mysql_close();

// Executer ces requetes après avoir appliquer le convertisseur
/*
UPDATE creature_template SET difficulty_entry_4 = difficulty_entry_1, difficulty_entry_5 = difficulty_entry_2, difficulty_entry_6 = difficulty_entry_3, difficulty_entry_2 = difficulty_entry_1;
UPDATE gameobject SET spawnMask = 16 WHERE map = 565;
UPDATE gameobject SET spawnMask = 512 WHERE map = 469;
UPDATE gameobject SET spawnMask = 16 WHERE map = 544;
UPDATE gameobject SET spawnMask = 16 WHERE map = 548;
UPDATE gameobject SET spawnMask = 512 WHERE map = 409;
UPDATE gameobject SET spawnMask = 16 WHERE map = 564;
UPDATE gameobject SET spawnMask = 16 WHERE map = 580;

UPDATE creature SET spawnMask = 16 WHERE map = 550;
UPDATE creature SET spawnMask = 16 WHERE map = 544;
UPDATE creature SET spawnMask = 16 WHERE map = 564;
UPDATE creature SET spawnMask = 512 WHERE map = 409;
UPDATE creature SET spawnMask = 16 WHERE map = 534;
UPDATE creature SET spawnMask = 16 WHERE map = 580;
UPDATE creature SET spawnMask = 512 WHERE map = 531;
UPDATE creature SET spawnMask = 16 WHERE map = 565;
UPDATE creature SET spawnMask = 16 WHERE map = 548;
UPDATE creature SET spawnMask = 512 WHERE map = 469;
*/
?>