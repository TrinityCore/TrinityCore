SET @YANNI := 25459;
SET @CARPET := 25460;
SET @Q_CarpetRide := 11636;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@YANNI,@CARPET) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@CARPET*100,@CARPET*100+1) AND `source_type`=9;
INSERT INTO `smart_scripts`(`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`)VALUES
(@YANNI,0,0,0,62,0,100,0,9162,0,0,0,11,45600,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Yanni - Cast Call of the Carpet on player'),
(@YANNI,0,1,0,62,0,100,0,9162,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Yanni - On Gossip option - Close gossip'),

(@CARPET,0,0,0,25,0,100,0,0,0,0,0,80,@CARPET*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Amazing Carpet - Call actionlist 2546000 on spawn'),
(@CARPET,0,1,0,40,0,100,0,14,0,0,0,80,@CARPET*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Amazing Carpet - On WP reach - Call actionlist 2546001'),

(@CARPET*100,9,0,0,0,0,100,0,1000,1000,0,0,11,45603,0,0,0,0,0,23,0,0,0,0,0,0,0, 'Amazing Carpet - Cast Ride Carpet on summoner'),
(@CARPET*100,9,1,0,0,0,100,0,100,100,0,0,53,0,@CARPET,0,0,0,0,1,0,0,0,0,0,0,0, 'Amazing Carpet - Load waypath'),

(@CARPET*100+1,9,0,0,0,0,100,0,0,0,0,0,15,@Q_CarpetRide,0,0,0,0,0,23,0,0,0,0,0,0,0, 'Amazing Carpet - Give quest credit'),
(@CARPET*100+1,9,1,0,0,0,100,0,500,500,0,0,28,45602,0,0,0,0,0,23,0,0,0,0,0,0,0, 'Amazing Carpet - Remove aura 45602'),
(@CARPET*100+1,9,2,0,0,0,100,0,100,100,0,0,28,46598,0,0,0,0,0,23,0,0,0,0,0,0,0, 'Amazing Carpet - Remove aura 46598'),
(@CARPET*100+1,9,3,0,0,0,100,0,200,200,0,0,41,200,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Amazing Carpet - Despawn');

DELETE FROM `waypoints` WHERE `entry`=@CARPET;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@CARPET,1,2751.96,6133.514,214.3789, 'Start WP'),
(@CARPET,2,2728.81,6146.472,213.5733, ''),
(@CARPET,3,2634.248,6188.829,185.9068, ''),
(@CARPET,4,2597.958,6255.91,159.7123, ''),
(@CARPET,5,2538.717,6307.643,138.9901, ''),
(@CARPET,6,2393.912,6321.946,85.79566, ''),
(@CARPET,7,2420.326,6461.604,89.3512, ''),
(@CARPET,8,2439.194,6494.39,84.93455, ''),
(@CARPET,9,2496.371,6496.766,78.76788, ''),
(@CARPET,10,2567.008,6550.509,79.90676, ''),
(@CARPET,11,2652.553,6572.071,58.54562, ''),
(@CARPET,12,2725.122,6642.299,41.57339, ''),
(@CARPET,13,2773.236,6694.341,25.49007, ''),
(@CARPET,14,2797.658,6718.523,9.212306, 'Run SmartAI script 2546001');

DELETE FROM `creature_template_addon` WHERE `entry` IN (@CARPET,@YANNI);
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES
(@CARPET,257, '61307'),
(@YANNI,257,NULL);

-- Update gossip_menu to proper entry from sniff (delete wrong one 21233)
UPDATE `creature_template` SET `gossip_menu_id`=9162,`AiName`= 'SmartAI' WHERE `entry`=@YANNI;
UPDATE `creature_template` SET `exp`=2,`minlevel`=72,`maxlevel`=72,`unit_flags`=`unit_flags`|520,`speed_run`=1.42857,`VehicleId`=317,`AiName`='SmartAI',`InhabitType`=5 WHERE `entry`=@CARPET;

UPDATE `creature_model_info` SET `bounding_radius`=0.31,`combat_reach`=1,`gender`=2 WHERE `modelid`=28082; -- Amazing Flying Carpet

DELETE FROM `gossip_menu` WHERE `entry` IN (21233,9162);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(9162,12417);

UPDATE `quest_template` SET `SpecialFlags`=`SpecialFlags`|2 WHERE `Id`=@Q_CarpetRide;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9162;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9162;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`Comment`) VALUES
(15,9162,0,0,9,@Q_CarpetRide,0,0,0,'Show gossip option 9162 if player has quest Carpet Ride');

DELETE FROM `spell_target_position` WHERE `id`=45601;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(45601,571,2753.64,6131.41,210.4463,2.892622);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=45602;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,45602,0,0,31,0,3,@CARPET,0,0,0, '', 'Ride Carpet - Target Amazing Flying Carpet');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=@CARPET;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(@CARPET,46598,1,0);
