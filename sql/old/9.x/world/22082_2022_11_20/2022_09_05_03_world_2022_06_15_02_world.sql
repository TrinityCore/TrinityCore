--
DELETE FROM `spell_scripts` WHERE `id` = 58854;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 3123500 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3123500,9,0,0,0,0,100,0,2000,2000,0,0,0,11,37692,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crusader Olakin Sainrith - On Script - Cast 'Fake Blood Spurt'"),
(3123500,9,1,0,0,0,100,0,2000,2000,0,0,0,11,37692,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crusader Olakin Sainrith - On Script - Cast 'Fake Blood Spurt'"),
(3123500,9,2,0,0,0,100,0,2000,2000,0,0,0,11,58854,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crusader Olakin Sainrith - On Script - Cast 'Resurrection'"),
(3123500,9,3,0,0,0,100,0,0,0,0,0,0,28,35356,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crusader Olakin Sainrith - On Script - Remove Aura 'Spawn Feign Death'"),
(3123500,9,4,0,0,0,100,0,4000,4000,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Crusader Olakin Sainrith - On Script - Say Line 0"),
(3123500,9,5,0,0,0,100,0,3000,3000,0,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crusader Olakin Sainrith - On Script - Play Emote 2"),
(3123500,9,6,0,0,0,100,0,3000,3000,0,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Crusader Olakin Sainrith - On Script - Say Line 1"),
(3123500,9,7,0,0,0,100,0,6000,6000,0,0,0,1,2,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Crusader Olakin Sainrith - On Script - Say Line 2"),
(3123500,9,8,0,0,0,100,0,0,0,0,0,0,33,31235,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Crusader Olakin Sainrith - On Script - Quest Credit 'Putting Olakin Back Together Again'"),
(3123500,9,9,0,0,0,100,0,6000,6000,0,0,0,53,1,31235,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crusader Olakin Sainrith - On Script - Start Waypoint");

--
DELETE FROM `spell_scripts` WHERE `id` IN (26264,34874,45451);
DELETE FROM `spell_script_names` WHERE `spell_id` IN (26264,34874,45451) AND `ScriptName` = 'spell_gen_despawn_target';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(26264,'spell_gen_despawn_target'),
(34874,'spell_gen_despawn_target'),
(45451,'spell_gen_despawn_target');

--
DELETE FROM `spell_scripts` WHERE `id` IN (45505,45507,45509,45511);

DELETE FROM `smart_scripts` WHERE `entryorguid` = 25401 AND `source_type` = 0 AND `id` BETWEEN 1 AND 5;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25401,0,1,5,8,0,100,0,45505,0,0,0,0,11,45506,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Seaforium Depth Charge - On Spellhit 'Nerub'ar Sinkhole Credit (SW)' - Cast 'Nerub'ar Sinkhole Credit (SW)'"),
(25401,0,2,5,8,0,100,0,45507,0,0,0,0,11,45508,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Seaforium Depth Charge - On Spellhit 'Nerub'ar Sinkhole Credit (SE)' - Cast 'Nerub'ar Sinkhole Credit (SE)'"),
(25401,0,3,5,8,0,100,0,45509,0,0,0,0,11,45510,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Seaforium Depth Charge - On Spellhit 'Nerub'ar Sinkhole Credit (NW)' - Cast 'Nerub'ar Sinkhole Credit (NW)'"),
(25401,0,4,5,8,0,100,0,45511,0,0,0,0,11,45512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Seaforium Depth Charge - On Spellhit 'Nerub'ar Sinkhole Credit (NE)' - Cast 'Nerub'ar Sinkhole Credit (NE)'"),
(25401,0,5,0,61,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Seaforium Depth Charge - On Link - Despawn");

--
DELETE FROM `spell_scripts` WHERE `id` = 55288;
