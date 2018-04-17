UPDATE `creature_template` SET `gossip_menu_id` = 0, `npcflag` = 16777216 WHERE (entry = 41989);
DELETE FROM `creature_text` WHERE `CreatureID` = 41989;
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(41989, 0, 0, 'Why dis happen?', 12, 0, 100, 0, 0, 0, 'Frightened Peon'),
(41989, 0, 1, 'You is friend. Tanks!', 12, 0, 100, 0, 0, 0, 'Frightened Peon'),
(41989, 0, 2, 'Oof! You touch naughty spot!', 12, 0, 100, 0, 0, 0, 'Frightened Peon');

-- Frightened Peon SAI
SET @ENTRY := 41989;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,1,78269,0,0,0,33,41989,0,0,0,0,0,7,0,0,0,0,0,0,0,"Frightened Peon - On Spellhit '<Spell not found!>' - Quest Credit '' (No Repeat)"),
(@ENTRY,0,1,2,61,0,100,1,78269,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frightened Peon - On Spellhit '<Spell not found!>' - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,3,61,0,100,1,78269,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frightened Peon - On Spellhit '<Spell not found!>' - Despawn In 3000 ms (No Repeat)"),
(@ENTRY,0,3,0,61,0,100,1,78269,0,0,0,17,30,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frightened Peon - On Spellhit '<Spell not found!>' - Set Emote State 30 (No Repeat)");

DELETE FROM creature_addon WHERE guid IN (271458,271649,271857,271858,271859,272133,272134,272135,272136,272301,272331,272336,272337,272338,272354,272355,272356,272360,272361,272398,272399,272428,272429,272430,272431);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES 
('271458', '0', '0', '0', '0', '431', '0', '0', '0', NULL),
('271649', '0', '0', '0', '0', '431', '0', '0', '0', NULL),
('271857', '0', '0', '0', '0', '431', '0', '0', '0', NULL),
('271858', '0', '0', '0', '0', '431', '0', '0', '0', NULL),
('271859', '0', '0', '0', '0', '431', '0', '0', '0', NULL),
('272133', '0', '0', '0', '0', '431', '0', '0', '0', NULL),
('272134', '0', '0', '0', '0', '431', '0', '0', '0', NULL),
('272135', '0', '0', '0', '0', '431', '0', '0', '0', NULL),
('272136', '0', '0', '0', '0', '431', '0', '0', '0', NULL),
('272301', '0', '0', '0', '0', '431', '0', '0', '0', NULL),
('272331', '0', '0', '0', '0', '431', '0', '0', '0', NULL),
('272336', '0', '0', '0', '0', '431', '0', '0', '0', NULL),
('272337', '0', '0', '0', '0', '431', '0', '0', '0', NULL),
('272338', '0', '0', '0', '0', '431', '0', '0', '0', NULL),
('272354', '0', '0', '0', '0', '431', '0', '0', '0', NULL),
('272355', '0', '0', '0', '0', '431', '0', '0', '0', NULL),
('272356', '0', '0', '0', '0', '431', '0', '0', '0', NULL),
('272360', '0', '0', '0', '0', '431', '0', '0', '0', NULL),
('272361', '0', '0', '0', '0', '431', '0', '0', '0', NULL),
('272398', '0', '0', '0', '0', '431', '0', '0', '0', NULL),
('272399', '0', '0', '0', '0', '431', '0', '0', '0', NULL),
('272428', '0', '0', '0', '0', '431', '0', '0', '0', NULL),
('272429', '0', '0', '0', '0', '431', '0', '0', '0', NULL),
('272430', '0', '0', '0', '0', '431', '0', '0', '0', NULL),
('272431', '0', '0', '0', '0', '431', '0', '0', '0', NULL);
