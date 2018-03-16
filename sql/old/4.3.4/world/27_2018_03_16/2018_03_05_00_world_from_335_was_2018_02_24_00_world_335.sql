/*
-- Deathguard Elite
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7980;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7980 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(7980,0,0,0,0,0,100,0,0,0,2000,4000,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deathguard Elite - In Combat - Cast 'Shoot'");

-- Stormwind City Guard
DELETE FROM `smart_scripts` WHERE `entryorguid`=68 AND `source_type`=0 AND `id` IN (1,2,3,4,5,6,7,8,9,10);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6800,6801,6802,6803,6804) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(68,  0, 1,0,0,0,100,0,0,0,2000,4000,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Stormwind City Guard - In Combat - Cast 'Shoot'"),
(68,  0, 2,0,9,0,100,0,0,5,11000,14000,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - Within 0-5 Range - Cast 'Shield Block'"),
(68,  0, 3,0,0,0,100,0,5000,9000,8000,13000,11,12170,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormwind City Guard - In Combat - Cast 'Revenge'"),
(68,  0, 4,0,22,0,100,0,101,5000,5000,0,80,6800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Received Emote 'Wave' - Run Script"),
(68,  0, 5,0,22,0,100,0,78,5000,5000,0,80,6801,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Received Emote 'Salute' - Run Script"),
(68,  0, 6,0,22,0,100,0,58,5000,5000,0,80,6802,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Received Emote 'Kiss' - Run Script"),
(68,  0, 7,0,22,0,100,0,84,5000,5000,0,80,6803,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Received Emote 'Shy' - Run Script"),
(68,  0, 8,0,22,0,100,0,77,5000,5000,0,80,6804,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Received Emote 'Rude' - Run Script"),
(68,  0, 9,0,22,0,100,0,22,5000,5000,0,80,6804,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Received Emote 'Chicken' - Run Script"),
(68,  0,10,0,22,0,100,0,17,5000,5000,0,80,6802,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Received Emote 'Bow' - Run Script"),
(6800,9, 0,0, 0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Orientation"),
(6800,9, 1,0, 0,0,100,0,2000,2000,0,0,5,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Play Emote 'Wave'"),
(6800,9, 2,0, 0,0,100,0,10000,10000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Orientation"),
(6801,9, 0,0, 0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Orientation"),
(6801,9, 1,0, 0,0,100,0,2000,2000,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Play Emote 'Salute'"),
(6801,9, 2,0, 0,0,100,0,10000,10000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Orientation"),
(6802,9, 0,0, 0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Orientation"),
(6802,9, 1,0, 0,0,100,0,2000,2000,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Play Emote 'Bow'"),
(6802,9, 2,0, 0,0,100,0,10000,10000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Orientation"),
(6803,9, 0,0, 0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Orientation"),
(6803,9, 1,0, 0,0,100,0,2000,2000,0,0,5,23,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Play Emote 'Flex'"),
(6803,9, 2,0, 0,0,100,0,10000,10000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Orientation"),
(6804,9, 0,0, 0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Orientation"),
(6804,9, 1,0, 0,0,100,0,2000,2000,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Play Emote 'Point'"),
(6804,9, 2,0, 0,0,100,0,10000,10000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Orientation");
*/
