-- 
UPDATE `creature_template` SET `unit_flags`=256 WHERE `entry`=32588; 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (32588) AND `id`IN (0,6) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3258800) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(32588, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, 3258800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Illidan Stormrage - Just summoned - Action list"),
(32588, 0, 6, 0, 7, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Illidan Stormrage - On evade - Despawn"),
(3258800, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Illidan Stormrage - Action list - Remove bytes1"),
(3258800, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Illidan Stormrage - Action list - Say text"),
(3258800, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Illidan Stormrage - Action list - Remove unit flag"),
(3258800, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 32326, 0, 0, 0, 0, 0, 0, "Illidan Stormrage - Action list - Start attack");

UPDATE `creature_text` SET `Emote`=15 WHERE `CreatureID`=32588 AND `GroupID`=0;
DELETE FROM `creature_template_addon` WHERE `entry` IN (32588);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(32588, 0, 0, 8, 1, 0, ''); -- 32588

SET @ILLIDAN := 32588;   -- Illidan Stormrage 
SET @EVENT_1 := 20722;   -- Spell Event 1
SET @EVENT_2 := 20723;   -- Spell Event 2
SET @EVENT_3 := 20724;   -- Spell Event 3
DELETE FROM `event_scripts` WHERE `id` IN (@EVENT_1,@EVENT_2,@EVENT_3);
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(@EVENT_1,0,10,@ILLIDAN,60000,0,6375.921,2425.141,478.028,5.191484),
(@EVENT_2,0,10,@ILLIDAN,60000,0,6349.707,2318.625,474.6617,0.875729),
(@EVENT_3,0,10,@ILLIDAN,60000,0,6327.512,2355.488,477.5414,5.899213);
