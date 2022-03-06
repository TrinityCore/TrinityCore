-- https://www.youtube.com/watch?v=PukShfa4GkA
UPDATE `smart_scripts` SET `comment` = "Silithid Creeper Egg - On Just Summoned - Run Script" WHERE `entryorguid` = 5781 AND `source_type` = 0 AND `id` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 578100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(578100,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Silithid Creeper Egg - On Script - Set Reactstate Passive"),
(578100,9,1,0,0,0,100,0,6000,6000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Silithid Creeper Egg - On Script - Say Line 0"),
(578100,9,2,0,0,0,100,0,6000,6000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Silithid Creeper Egg - On Script - Say Line 1"),
(578100,9,3,0,0,0,100,0,0,0,0,0,0,11,6588,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Silithid Creeper Egg - On Script - Cast 'Summon Silithid Grub'"),
(578100,9,4,0,0,0,100,0,0,0,0,0,0,11,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Silithid Creeper Egg - On Script - Cast 'Suicide'");

-- Remove unconfirmed emote from Silithid Grub and allow him to attack on his own,
-- it's bad practice actually, mostly all creatures attacks on their own
UPDATE `creature_template` SET `AIName` = "" WHERE `entry` = 3251;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3251 AND `source_type` = 0;
DELETE FROM `creature_text` WHERE `CreatureID` = 3251;
