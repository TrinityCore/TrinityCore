-- Monstrous Kaliri Egg Trigger despawns in 2 secs after spell hit
UPDATE `smart_scripts` SET `event_flags` = 1, `comment` = "Monstrous Kaliri Egg Trigger - On Spellhit 'Skyguard Blasting Charge' - Quest Credit 'Fires Over Skettis' (No Repeat)" WHERE `entryorguid` = 22991 AND `source_type` = 0 AND `id` = 1;
UPDATE `smart_scripts` SET `event_flags` = 0, `action_type` = 41, `action_param1` = 2000, `comment` = "Monstrous Kaliri Egg Trigger - On Link - Despawn (2000)" WHERE `entryorguid` = 22991 AND `source_type` = 0 AND `id` = 2;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2299100 AND `source_type` = 9;

-- Monstrous Kaliri Egg activates and despawns shortly after spell hit
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = 185549;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 185549 AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(185549,1,0,0,8,0,100,1,39844,0,0,0,0,9,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Monstrous Kaliri Egg - On Spellhit 'Skyguard Blasting Charge' - Activate Gameobject (No Repeat)");
