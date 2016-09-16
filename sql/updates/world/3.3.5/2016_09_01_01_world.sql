-- Fix Cabal Abjurist SAI even more
UPDATE `smart_scripts` SET `action_param1`=34446,`action_param2`=0x40,`event_param3`=5500,`event_param4`=6500 WHERE `entryorguid`=21660 AND `source_type`=0 AND `id`=0;

-- Same treatment for Bleeding Hollow Darkcaster
DELETE FROM `smart_scripts` WHERE `entryorguid`=17269 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`event_type`,`event_chance`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`target_type`,`comment`) VALUES
(17269,0,0,0,100,300,450,1800,2100,11,15241,0x40,2,"Bleeding Hollow Darkcaster - In Combat - Cast 'Scorch' at Victim"),
(17269,0,1,0,100,11600,23300,22700,33400,11,20754,0x41,6,"Bleeding Hollow Darkcaster - In Combat - Cast 'Rain of Fire' at Random Hostile");

DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (15241,20754);
INSERT INTO `spelldifficulty_dbc` (`id`,`spellid0`,`spellid1`) VALUES
(15241,15241,36807),
(20754,20754,36808);
