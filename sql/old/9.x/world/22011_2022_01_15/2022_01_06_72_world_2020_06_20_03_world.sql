-- These too should move randomly
UPDATE `creature` SET `wander_distance` = 5, `MovementType` = 1 WHERE `id` = 18797 AND `guid` IN (67109,67110,67111,67112,67113,67114,67115,67116,67117,67118);

-- Make NPCs in heroic too appear dead
DELETE FROM `creature_template_addon` WHERE `entry` = 20662;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES
(20662,0,0,7,4097,0,0,"");

-- Make all appeared dead non-selectable
UPDATE `creature` SET `unit_flags` = 33554432 WHERE `id` = 18797 AND `guid` IN (67090,67091,67092,67093,67094,67095,67096,67097,67098,67099,67100,67101,67102,67103,67104,67105,67106,67107,67108,67120,67121,67122,67133,67134,67135,67136,67137,67138,67139,67140,67141,67142,67143,67145,67146,67147,67148);

UPDATE `smart_scripts` SET `event_flags` = 0 WHERE `entryorguid` = 18797 AND `source_type` = 0 AND `id` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 18797 AND `source_type` = 0 AND `id` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18797,0,1,0,4,0,100,0,0,0,0,0,19,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tortured Skeleton - On Aggro - Remove Flag Not Selectable");
