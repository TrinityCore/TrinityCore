-- Sniffed
UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 31235;
UPDATE `smart_scripts` SET `event_flags` = 0 WHERE `entryorguid` = 31235;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3123500 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3123500,9,0,0,0,0,100,0,2000,2000,0,0,0,11,37692,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crusader Olakin Sainrith - On Script - Cast 'Fake Blood Spurt'"),
(3123500,9,1,0,0,0,100,0,2000,2000,0,0,0,11,37692,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crusader Olakin Sainrith - On Script - Cast 'Fake Blood Spurt'"),
(3123500,9,2,0,0,0,100,0,2000,2000,0,0,0,11,58854,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crusader Olakin Sainrith - On Script - Cast 'Resurrection'"),
(3123500,9,3,0,0,0,100,0,4000,4000,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Crusader Olakin Sainrith - On Script - Say Line 0"),
(3123500,9,4,0,0,0,100,0,3000,3000,0,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crusader Olakin Sainrith - On Script - Play Emote 2"),
(3123500,9,5,0,0,0,100,0,3000,3000,0,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Crusader Olakin Sainrith - On Script - Say Line 1"),
(3123500,9,6,0,0,0,100,0,6000,6000,0,0,0,1,2,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Crusader Olakin Sainrith - On Script - Say Line 2"),
(3123500,9,7,0,0,0,100,0,0,0,0,0,0,33,31235,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Crusader Olakin Sainrith - On Script - Quest Credit 'Putting Olakin Back Together Again'"),
(3123500,9,8,0,0,0,100,0,6000,6000,0,0,0,53,1,31235,0,0,0,2,1,0,0,0,0,0,0,0,0,"Crusader Olakin Sainrith - On Script - Start Waypoint");

DELETE FROM `spell_scripts` WHERE `id` = 58854;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`,`Comment`) VALUES
(58854,0,0,14,35356,1,0,0,0,0,0,"Resurrection - On Effect Hit (Dummy) - Caster - Remove Aura 'Spawn Feign Death'");
