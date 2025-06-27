-- Fix Quest 308 "Distracting Jarven"
UPDATE `smart_scripts` SET `action_param1`=0, `action_param2`=0 WHERE `entryorguid`=1373 AND `source_type`=0 AND `id`=3;
UPDATE `smart_scripts` SET `action_param1`=46,`action_param2`=0 WHERE `entryorguid`=1373 AND `source_type`=0 AND `id`=4;
UPDATE `smart_scripts` SET `target_type`=8, `target_o`=0.977384 WHERE `entryorguid`=1373 AND `source_type`=0 AND `id`=11;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1373 AND `source_type`=0 AND `id`=12;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`event_type`,`event_chance`,`event_param1`,`action_type`,`action_param1`,`action_param2`,`target_type`,`comment`) VALUES
(1373,0,12,40,100,13,133,1,1037,1, "Jarven Thunderbrew - On WP 13 Reached - Respawn Closest Gameobject 'Guarded Thunder Ale Barrel'");
