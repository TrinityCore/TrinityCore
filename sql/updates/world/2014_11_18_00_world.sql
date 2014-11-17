--
-- Fixed problem with self kill of creature 'Deviate Ravager (3636)' 
-- after spawn in dungeon Wailing Caverns. Now the setup is similar to
-- creature 'Deviate Guardian (3637)'
--
DELETE FROM `smart_scripts`
 WHERE `entryorguid` = 3636;

UPDATE `creature_template` 
   SET `spell1` = 0, 
	    `AIName` = '' 
 WHERE `entry` = 3636;
 
 