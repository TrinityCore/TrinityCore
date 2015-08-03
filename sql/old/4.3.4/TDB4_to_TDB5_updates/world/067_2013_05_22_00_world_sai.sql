-- Matthias Lehner quest chain in Icecrown. Sniffed info.
SET @GUID               := 62064; -- Need 4 Matthias Lehner guids; one is already spawned.
SET @CGUID              := 1637; -- Needs 81 creature guids (4.x changed)
SET @OGUID              := 2854; -- Needs 85 misc gameobject guids (4.x changed)
SET @MATT1              := 32408;  -- Matthias Lehner (Near demolisher)
SET @MATT2              := 32404;  -- Matthias Lehner (1)
SET @MATT3              := 32423;  -- Matthias Lerner (2)
SET @MATT4              := 32497;  -- Matthias Lerner (3)
SET @PLSP_FC            := 58989;  -- Prodigal Leader Force Cast
SET @REF_DEMOLISHER     := 32370;  -- Refurbished Demolisher
SET @DEMOLISHER         := 31868;  -- Wrecked Demolisher
SET @L_CAPTAIN          := 32414;  -- Lordaeron Captain
SET @L_FOOTSOLDIER      := 31254;  -- Lordaeron Footsoldier
SET @G_MINION           := 31276;  -- Ghoulish Minion
SET @SFKCB              := 58988;  -- Skeletal Footsoldier Kill Credit Base
SET @TPL                := 31268;  -- The Prodigal Leader
SET @NPC_LK             := 32443;  -- The Lich King
SET @NPC_SIND           := 32446;  -- Sindragosa
SET @LK                 := 32326;   -- Lich King
SET @ILLIDAN            := 32588;   -- Illidan Stormrage 
SET @BLOODSTAINED_S1    := 194023;  -- GO:194023  Event:20722
SET @BLOODSTAINED_S2    := 194024;  -- GO:194024  Event:20723
SET @BLOODSTAINED_S3    := 193980;  -- GO:193980  Event:20724
SET @EVENT_1            := 20722;   -- Spell Event 1
SET @EVENT_2            := 20723;   -- Spell Event 2
SET @EVENT_3            := 20724;   -- Spell Event 3

DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID,@MATT1,571,1,1,0,0,7269.866,1178.146,317.4561,1.954769,300,0,0,12600,0,0,0,0,0);
UPDATE `creature_template` SET `exp`=2,`npcflag`=0x2 WHERE `entry`=@MATT1;
DELETE FROM `creature_template_addon` WHERE `entry`=@MATT1;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(@MATT1,0,0x10000,0x1,'10848 49414'); -- Quest Invisibility, Shroud of Death

-- Apply aura (Generic Quest Invisibility Detection 1) when Field Repairs has been rewarded
DELETE FROM `spell_area` WHERE `spell`=49416 AND `area`=4537;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(49416,4537,13393,13394,0,1101,2,1,64,9), -- Alliance
(49416,4537,13304,13305,0,690,2,1,64,9);  -- Horde
-- Remove aura (Generic Quest Invisibility Detection 1) when "Do Your Worst" (13394/13305) has been completed

UPDATE `creature_template` SET `exp`=2,`unit_flags`=0x20040000,`dynamicflags`=0x20,`npcflag`=0x2 WHERE `entry`=@DEMOLISHER;

DELETE FROM `creature_addon` WHERE `guid`=122757; -- Guid based
DELETE FROM `creature_template_addon` WHERE `entry`=@DEMOLISHER;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(@DEMOLISHER,0,0x10000,0x1,'49415 29266'); -- Generic Quest Invisibility 2 & Permanent Feign Death

-- Apply aura (Generic Quest Invisibility Detection 2) when "Field Repairs" has been taken
DELETE FROM `spell_area` WHERE `spell`=49417 AND `area`=4537;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(49417,4537,13393,13393,0,1101,2,1,11,11), 	-- Alliance
(49417,4537,13304,13304,0,690,2,1,11,11); 	-- Horde
-- Remove aura (Generic Quest Invisibility Detection 1) when Field Repairs has been rewarded

UPDATE `creature_template` SET `exp`=2,`npcflag`=16777216 WHERE `entry`=@REF_DEMOLISHER;

DELETE FROM `creature_template_addon` WHERE `entry`=@REF_DEMOLISHER;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(@REF_DEMOLISHER,0,0x10000,0x1,'49414'); -- Generic Quest Invisibility 1

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=@REF_DEMOLISHER;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(@REF_DEMOLISHER,59724,1,0); -- Summon (Refurbished Demolisher)

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=@REF_DEMOLISHER;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(18,@REF_DEMOLISHER,59724,0,0,9,0,13394,0,0,0,0,0,'','Requires quest to be active for spellclick'),
(18,@REF_DEMOLISHER,59724,0,0,28,0,13394,0,0,1,0,0,'','Requires quest not to be completed for spellclick');


DELETE FROM `creature` WHERE `guid`=@GUID+1;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+1,@REF_DEMOLISHER,571,1,1,0,0,7259.758,1176.801,316.8752,0.9599311,300,0,0,36860,0,0,0,0,0);

-- Refurbished Demolisher (31830) -- The vehicle
UPDATE `creature_template` SET `exp`=2,`spell1`=59733,`spell2`=50652,`spell3`=59737 WHERE `entry`=31830;

UPDATE `creature_template` SET `exp`=2,`AIName`='SmartAI',`npcflag`=0x3,`gossip_menu_id`=10226 WHERE `entry`=@MATT2;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@MATT2 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@MATT2,0,0,0,19,0,100,0,13395,0,0,0,11,@PLSP_FC,0,0,0,0,0,7,0,0,0,0,0,0,0,'On quest accept - Cast spell - Invoker'),
(@MATT2,0,1,0,19,0,100,0,13236,0,0,0,11,@PLSP_FC,0,0,0,0,0,7,0,0,0,0,0,0,0,'On quest accept - Cast spell - Invoker');

DELETE FROM `creature_template_addon` WHERE `entry`=@MATT2;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(@MATT2,0,0x10000,0x1,'10848 49414'); -- Quest Invisibility, Shroud of Death

DELETE FROM `gossip_menu` WHERE `entry`=10226 AND `text_id`=14218;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(10226,14218);

DELETE FROM `creature` WHERE `guid`=@GUID+2;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+2,@MATT2,571,1,1,0,0,7587.631,1398.042,332.4734,0.8203048,300,0,0,12600,0,0,0,0,0);

-- Apply aura (Generic Quest Invisibility Detection 1) when Do Your Worst has been completed|rewarded.
DELETE FROM `spell_area` WHERE `spell`=49416 AND `area`=4622;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(49416,4622,13394,13396,0,1101,2,1,66,11), -- Alliance
(49416,4622,13305,13348,0,690,2,1,66,11); -- Horde
-- Remove aura (Generic Quest Invisibility Detection 1) when Futility is rewarded

UPDATE `creature_template` SET `exp`=2,`minlevel`=80,`maxlevel`=80 WHERE `entry`=@MATT3;

DELETE FROM `creature` WHERE `guid`=@GUID+3;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+3,@MATT3,571,1,3,0,0,7854.05,957.014,450.898,0.628319,300,0,0,12600,0,0,0,0,0);

DELETE FROM `creature_template_addon` WHERE `entry`=@MATT3;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(@MATT3,0,0x10000,0x1,'10848 49414'); -- Quest Invisibility, Shroud of Death

-- Apply aura (Generic Quest Invisibility Detection 1) when Sindragosa's Fall/Cradle of the Frostbrood has been Taken.
DELETE FROM `spell_area` WHERE `spell`=49416 AND `area`=4533;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(49416,4533,13397,13399,0,1101,2,1,74,11), -- Alliance
(49416,4533,13349,13360,0,690,2,1,74,11);  -- Horde
-- Remove aura (Generic Quest Invisibility Detection 1) when Time for Answers is rewarded

UPDATE `creature_template` SET `exp`=2,`minlevel`=80,`maxlevel`=80 WHERE `entry`=@MATT4;

DELETE FROM `creature` WHERE `guid`=@GUID+4;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+4,@MATT4,571,1,1,0,0,6369.59,2360.84,471.656,1.22173,300,0,0,12600,0,0,0,0,0);

DELETE FROM `creature_template_addon` WHERE `entry`=@MATT4;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(@MATT4,0,0x10000,0x1,'10848 49414'); -- Quest Invisibility, Shroud of Death

-- Apply aura (Generic Quest Invisibility Detection 1) when Time for Answers has been completed/rewarded.
DELETE FROM `spell_area` WHERE `spell`=49416 AND `area`=4519;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(49416,4519,13399,0,0,1101,2,1,66,0), -- Alliance
(49416,4519,13360,0,0,690,2,1,66,0);  -- Horde
-- Remove aura (Generic Quest Invisibility Detection 1) when

-- Army of the Damned (13395/13236)
-- http://www.youtube.com/watch?v=Rimu18yrSx8

UPDATE `creature_template` SET `AIName`='SmartAI',`exp`=2,`spell1`=58912,`spell2`=58913,`spell3`=58916,`spell4`=58917,`speed_run`=0.992062866687775,`VehicleId`=269,`minlevel`=82,`maxlevel`=82,`unit_flags`=0x8,`baseattacktime`=3000,`unit_class`=2 WHERE `entry`=@TPL;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@TPL AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@TPL,0,0,0,8,0,100,0,@SFKCB,0,0,0,11,58987,0,0,0,0,0,23,0,0,0,0,0,0,0,'On Spellhit - Cast Spell - Owner'),
(@TPL,0,1,0,27,0,100,1,0,0,0,0,45,1,1,0,0,0,0,11,@L_CAPTAIN,50,0,0,0,0,0,'On Passenger Boarded - Set Data - Creature Distance');


DELETE FROM `creature_equip_template` WHERE `entry`=@TPL;
INSERT INTO `creature_equip_template` (`entry`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(@TPL,33475,0,0);

DELETE FROM `spell_scripts` WHERE `id` IN (58916,58917);
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(58916,0,0,15,58915,0,0,0,0,0,0),
(58917,0,0,15,58919,0,0,0,0,0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (58916,58917);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,58916,0,0,31,0,3,@L_CAPTAIN,0,0,0,0,'','Gift of the Lich King target Lordaeron Captain'),
(13,1,58916,0,1,31,0,3,@L_FOOTSOLDIER,0,0,0,0,'','Gift of the Lich King target Lordaeron Footsoldier'),
(13,1,58916,0,0,36,0,0,0,0,1,0,0,'','Target needs to be dead'),
(13,1,58916,0,1,36,0,0,0,0,1,0,0,'','Target needs to be dead'),
(13,1,58917,0,0,31,0,3,@G_MINION,0,0,0,0,'','Consume Minions target Ghoulish Minion');


DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+80;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`curhealth`,`MovementType`) VALUES
(@CGUID+0, @L_CAPTAIN, 571, 1, 2, 7590.981, 1393.571, 332.805, 1.396263, 120, 0, 12600, 0), -- @L_CAPTAIN (Area: 4622)
(@CGUID+1, @L_FOOTSOLDIER, 571, 1, 2, 7597.618, 1305.04, 337.8358, 1.692969, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+2, @L_FOOTSOLDIER, 571, 1, 2, 7592.61, 1305.417, 336.9066, 1.623156, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+3, @L_FOOTSOLDIER, 571, 1, 2, 7587.983, 1305.996, 335.96, 1.570796, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+4, @L_FOOTSOLDIER, 571, 1, 2, 7575.548, 1310.397, 333.8244, 1.43117, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+5, @L_FOOTSOLDIER, 571, 1, 2, 7580.698, 1310.446, 334.4726, 1.500983, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+6, @L_FOOTSOLDIER, 571, 1, 2, 7581.648, 1306.047, 334.8738, 1.518436, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+7, @L_FOOTSOLDIER, 571, 1, 2, 7575.075, 1306.437, 333.991, 1.43117, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+8, @L_FOOTSOLDIER, 571, 1, 2, 7581.489, 1318.208, 334.0107, 1.448623, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+9, @L_FOOTSOLDIER, 571, 1, 2, 7576.248, 1318.982, 333.3188, 1.37881, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+10, @L_FOOTSOLDIER, 571, 1, 2, 7592.329, 1309.999, 336.3537, 1.623156, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+11, @L_FOOTSOLDIER, 571, 1, 2, 7586.704, 1310.507, 335.3659, 1.570796, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+12, @L_FOOTSOLDIER, 571, 1, 2, 7598.781, 1325.946, 335.8446, 1.692969, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+13, @L_FOOTSOLDIER, 571, 1, 2, 7594.156, 1325.512, 335.1556, 1.623156, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+14, @L_FOOTSOLDIER, 571, 1, 2, 7588.168, 1325.119, 334.319, 1.553343, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+15, @L_FOOTSOLDIER, 571, 1, 2, 7582.48, 1325.178, 333.5676, 1.466077, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+16, @L_FOOTSOLDIER, 571, 1, 2, 7577.097, 1325.809, 332.8546, 1.37881, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+17, @L_FOOTSOLDIER, 571, 1, 2, 7598.016, 1318.954, 336.3169, 1.675516, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+18, @L_FOOTSOLDIER, 571, 1, 2, 7592.37, 1318.074, 335.5277, 1.58825, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+19, @L_FOOTSOLDIER, 571, 1, 2, 7587.729, 1318.605, 334.7913, 1.53589, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+20, @L_FOOTSOLDIER, 571, 1, 2, 7581.285, 1353.305, 331.5094, 1.343904, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+21, @L_FOOTSOLDIER, 571, 1, 2, 7578.252, 1356.313, 331.3191, 1.239184, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+22, @L_FOOTSOLDIER, 571, 1, 2, 7574.283, 1359.968, 331.2968, 1.099557, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+23, @L_FOOTSOLDIER, 571, 1, 2, 7570.327, 1363.058, 330.5497, 0.9424778, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+24, @L_FOOTSOLDIER, 571, 1, 2, 7566.075, 1366.799, 329.6888, 0.7853982, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+25, @L_FOOTSOLDIER, 571, 1, 2, 7578.452, 1348.972, 331.6236, 1.291544, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+26, @L_FOOTSOLDIER, 571, 1, 2, 7574.736, 1352.336, 330.9636, 1.186824, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+27, @L_FOOTSOLDIER, 571, 1, 2, 7570.568, 1356.494, 330.5071, 1.047198, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+28, @L_FOOTSOLDIER, 571, 1, 2, 7566.392, 1359.588, 329.7618, 0.9250245, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+29, @L_FOOTSOLDIER, 571, 1, 2, 7562.342, 1362.778, 329.0039, 0.7853982, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+30, @L_FOOTSOLDIER, 571, 1, 2, 7558.438, 1359.295, 328.2628, 0.7853982, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+31, @L_FOOTSOLDIER, 571, 1, 2, 7562.093, 1356.335, 328.9453, 0.8901179, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+32, @L_FOOTSOLDIER, 571, 1, 2, 7566.872, 1352.062, 329.6797, 1.029744, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+33, @L_FOOTSOLDIER, 571, 1, 2, 7571.022, 1348.635, 330.5304, 1.151917, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+34, @L_FOOTSOLDIER, 571, 1, 2, 7575.356, 1345.213, 331.7339, 1.256637, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+35, @L_FOOTSOLDIER, 571, 1, 2, 7555.554, 1355.546, 328.1983, 0.7853982, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+36, @L_FOOTSOLDIER, 571, 1, 2, 7558.832, 1352.613, 329.0146, 0.8901179, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+37, @L_FOOTSOLDIER, 571, 1, 2, 7563.994, 1349.025, 329.8778, 1.012291, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+38, @L_FOOTSOLDIER, 571, 1, 2, 7568.353, 1344.57, 330.5612, 1.134464, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+39, @L_FOOTSOLDIER, 571, 1, 2, 7572.892, 1341.369, 331.6706, 1.239184, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+40, @L_FOOTSOLDIER, 571, 1, 2, 7597.866, 1354.706, 334.6848, 1.762783, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+41, @L_FOOTSOLDIER, 571, 1, 2, 7597.885, 1367.288, 334.5932, 1.867502, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+42, @L_FOOTSOLDIER, 571, 1, 2, 7593.319, 1367.276, 333.7295, 1.692969, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+43, @L_FOOTSOLDIER, 571, 1, 2, 7589.114, 1367.378, 332.953, 1.518436, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+44, @L_FOOTSOLDIER, 571, 1, 2, 7583.886, 1367.601, 331.9132, 1.308997, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+45, @L_FOOTSOLDIER, 571, 1, 2, 7579.366, 1368.245, 331.3056, 1.117011, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+46, @L_FOOTSOLDIER, 571, 1, 2, 7598.125, 1372.082, 334.4693, 1.954769, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+47, @L_FOOTSOLDIER, 571, 1, 2, 7593.253, 1372.027, 333.6238, 1.710423, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+48, @L_FOOTSOLDIER, 571, 1, 2, 7589.304, 1371.93, 333.0089, 1.518436, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+49, @L_FOOTSOLDIER, 571, 1, 2, 7584.049, 1372.177, 332.2688, 1.239184, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+50, @L_FOOTSOLDIER, 571, 1, 2, 7579.457, 1372.116, 331.681, 1.047198, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+51, @L_FOOTSOLDIER, 571, 1, 2, 7598.163, 1375.465, 334.3708, 2.042035, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+52, @L_FOOTSOLDIER, 571, 1, 2, 7593.275, 1375.512, 333.6264, 1.745329, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+53, @L_FOOTSOLDIER, 571, 1, 2, 7589.806, 1375.822, 333.1504, 1.53589, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+54, @L_FOOTSOLDIER, 571, 1, 2, 7584.474, 1376.15, 332.5364, 1.186824, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+55, @L_FOOTSOLDIER, 571, 1, 2, 7580.116, 1376.351, 331.8188, 0.9424778, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+56, @L_FOOTSOLDIER, 571, 1, 2, 7573.417, 1379.314, 330.5734, 0.5759587, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+57, @L_FOOTSOLDIER, 571, 1, 2, 7577.173, 1385.125, 331.072, 0.3839724, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+58, @L_FOOTSOLDIER, 571, 1, 2, 7597.55, 1310.817, 337.1335, 1.692969, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+59, @L_FOOTSOLDIER, 571, 1, 2, 7604.912, 1343.7, 336.2978, 1.867502, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+60, @L_FOOTSOLDIER, 571, 1, 2, 7609.108, 1346.246, 336.7637, 1.954769, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+61, @L_FOOTSOLDIER, 571, 1, 2, 7614.414, 1348.76, 337.1829, 2.094395, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+62, @L_FOOTSOLDIER, 571, 1, 2, 7618.95, 1352.026, 337.3129, 2.199115, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+63, @L_FOOTSOLDIER, 571, 1, 2, 7624.063, 1355.433, 337.9718, 2.321288, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+64, @L_FOOTSOLDIER, 571, 1, 2, 7601.938, 1347.675, 335.5448, 1.832596, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+65, @L_FOOTSOLDIER, 571, 1, 2, 7606.248, 1349.914, 336.0553, 1.937315, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+66, @L_FOOTSOLDIER, 571, 1, 2, 7611.866, 1352.601, 336.4185, 2.076942, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+67, @L_FOOTSOLDIER, 571, 1, 2, 7617.08, 1355.108, 336.8806, 2.216568, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+68, @L_FOOTSOLDIER, 571, 1, 2, 7622.682, 1358.639, 337.6412, 2.356194, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+69, @L_FOOTSOLDIER, 571, 1, 2, 7600.038, 1350.75, 334.9453, 1.797689, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+70, @L_FOOTSOLDIER, 571, 1, 2, 7603.683, 1353.315, 335.4449, 1.902409, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+71, @L_FOOTSOLDIER, 571, 1, 2, 7609.594, 1356.689, 336.257, 2.076942, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+72, @L_FOOTSOLDIER, 571, 1, 2, 7614.948, 1359.268, 337.0087, 2.234021, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+73, @L_FOOTSOLDIER, 571, 1, 2, 7621.068, 1362.548, 337.6258, 2.391101, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+74, @L_FOOTSOLDIER, 571, 1, 2, 7601.229, 1356.915, 335.2959, 1.867502, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+75, @L_FOOTSOLDIER, 571, 1, 2, 7607.468, 1359.978, 336.2152, 2.076942, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+76, @L_FOOTSOLDIER, 571, 1, 2, 7613.156, 1363.574, 336.9086, 2.268928, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+77, @L_FOOTSOLDIER, 571, 1, 2, 7618.365, 1366.665, 337.358, 2.426008, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+78, @L_FOOTSOLDIER, 571, 1, 2, 7600.953, 1385.339, 334.186, 2.687807, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+79, @L_FOOTSOLDIER, 571, 1, 2, 7608.228, 1378.985, 334.8071, 2.565634, 120, 0, 12600, 0), -- @L_FOOTSOLDIER (Area: 4622)
(@CGUID+80, @L_FOOTSOLDIER, 571, 1, 2, 7604.285, 1378.747, 334.8669, 2.443461, 120, 0, 12600, 0); -- @L_FOOTSOLDIER (Area: 4622)

-- Misc gameobjects
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+84;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 193813, 571, 1, 2, 7541.28, 1320.396, 328.9124, -1.500982, 0, 0, 0, 1, 120, 255, 1), -- 193813 (Area: 4622)
(@OGUID+1, 193814, 571, 1, 2, 7543.634, 1320.439, 329.0549, 2.775071, 0, 0, 0, 1, 120, 255, 1), -- 193814 (Area: 4622)
(@OGUID+2, 193816, 571, 1, 2, 7545.142, 1315.035, 329.4462, -3.010669, 0, 0, 0, 1, 120, 255, 1), -- 193816 (Area: 4622)
(@OGUID+3, 193817, 571, 1, 2, 7543.001, 1315.064, 329.2274, 0.130899, 0, 0, 0, 1, 120, 255, 1), -- 193817 (Area: 4622)
(@OGUID+4, 193818, 571, 1, 2, 7540.648, 1315.594, 328.9768, 1.701696, 0, 0, 0, 1, 120, 255, 1), -- 193818 (Area: 4622)
(@OGUID+5, 193819, 571, 1, 2, 7560.569, 1300.758, 333.2082, 1.806415, 0, 0, 0, 1, 120, 255, 1), -- 193819 (Area: 4622)
(@OGUID+6, 193820, 571, 1, 2, 7554.927, 1309.58, 330.9437, -1.771509, 0, 0, 0, 1, 120, 255, 1), -- 193820 (Area: 4622)
(@OGUID+7, 193807, 571, 1, 2, 7559.165, 1301.401, 332.9652, 2.015855, 0, 0, 0, 1, 120, 255, 1), -- 193807 (Area: 4622)
(@OGUID+8, 193808, 571, 1, 2, 7561.399, 1303.66, 332.1848, 1.370081, 0, 0, 0, 1, 120, 255, 1), -- 193808 (Area: 4622)
(@OGUID+9, 193809, 571, 1, 2, 7557.444, 1303.104, 331.5889, 1.30027, 0, 0, 0, 1, 120, 255, 1), -- 193809 (Area: 4622)
(@OGUID+10, 193815, 571, 1, 2, 7542.429, 1320.442, 329.6358, 1.911133, 0, 0, 0, 1, 120, 255, 1), -- 193815 (Area: 4622)
(@OGUID+11, 193800, 571, 1, 2, 7554.204, 1314.124, 330.6833, 2.338742, 0, 0, 0, 1, 120, 255, 1), -- 193800 (Area: 4622)
(@OGUID+12, 193801, 571, 1, 2, 7545.629, 1307.18, 329.9126, 0.7243106, 0, 0, 0, 1, 120, 255, 1), -- 193801 (Area: 4622)
(@OGUID+13, 193802, 571, 1, 2, 7541.902, 1316.621, 328.9081, 0.1134449, 0, 0, 0, 1, 120, 255, 1), -- 193802 (Area: 4622)
(@OGUID+14, 193810, 571, 1, 2, 7557.45, 1303.402, 332.9673, -1.832593, 0, 0, 0, 1, 120, 255, 1), -- 193810 (Area: 4622)
(@OGUID+15, 193821, 571, 1, 2, 7550.283, 1316.339, 329.959, 2.836153, 0, 0, 0, 1, 120, 255, 1), -- 193821 (Area: 4622)
(@OGUID+16, 193822, 571, 1, 2, 7553.371, 1304.985, 331.0674, -2.277654, 0, 0, 0, 1, 120, 255, 1), -- 193822 (Area: 4622)
(@OGUID+17, 193823, 571, 1, 2, 7551.499, 1304.395, 330.7182, 1.596977, 0, 0, 0, 1, 120, 255, 1), -- 193823 (Area: 4622)
(@OGUID+18, 193824, 571, 1, 2, 7553.543, 1304.755, 331.1079, 0.9424764, 0, 0, 0, 1, 120, 255, 1), -- 193824 (Area: 4622)
(@OGUID+19, 193825, 571, 1, 2, 7550.23, 1316.46, 330.6128, -2.330011, 0, 0, 0, 1, 120, 255, 1), -- 193825 (Area: 4622)
(@OGUID+20, 193826, 571, 1, 2, 7556.107, 1309.794, 331.7017, 1.021015, 0, 0, 0, 1, 120, 255, 1), -- 193826 (Area: 4622)
(@OGUID+21, 193827, 571, 1, 2, 7540.02, 1320.733, 329.4276, 1.596974, 0, 0, 0, 1, 120, 255, 1), -- 193827 (Area: 4622)
(@OGUID+22, 193805, 571, 1, 2, 7560.395, 1300.322, 332.0938, -1.335177, 0, 0, 0, 1, 120, 255, 1), -- 193805 (Area: 4622)
(@OGUID+23, 193811, 571, 1, 2, 7616.356, 1305.621, 341.7527, -1.553341, 0, 0, 0, 1, 120, 255, 1), -- 193811 (Area: 4622)
(@OGUID+24, 193829, 571, 1, 2, 7628.698, 1313.042, 341.731, 2.510756, 0, 0, 0, 1, 120, 255, 1), -- 193829 (Area: 4622)
(@OGUID+25, 193836, 571, 1, 2, 7623.703, 1306.834, 341.2804, -1.304631, 0, 0, 0, 1, 120, 255, 1), -- 193836 (Area: 4622)
(@OGUID+26, 193837, 571, 1, 2, 7623.346, 1306.82, 341.664, 0.3035969, 0, 0, 0, 1, 120, 255, 1), -- 193837 (Area: 4622)
(@OGUID+27, 193812, 571, 1, 2, 7616.432, 1305.333, 340.4039, 1.579521, 0, 0, 0, 1, 120, 255, 1), -- 193812 (Area: 4622)
(@OGUID+28, 193839, 571, 1, 2, 7620.775, 1303.785, 341.3588, 1.776699, 0, 0, 0, 1, 120, 255, 1), -- 193839 (Area: 4622)
(@OGUID+29, 193840, 571, 1, 2, 7619.116, 1305.521, 340.8146, -1.292454, 0, 0, 0, 1, 120, 255, 1), -- 193840 (Area: 4622)
(@OGUID+30, 193833, 571, 1, 2, 7611.557, 1304.096, 341.6903, 2.46209, 0, 0, 0, 1, 120, 255, 1), -- 193833 (Area: 4622)
(@OGUID+31, 193834, 571, 1, 2, 7611.44, 1305.623, 341.8747, 2.385941, 0, 0, 0, 1, 120, 255, 1), -- 193834 (Area: 4622)
(@OGUID+32, 193828, 571, 1, 2, 7628.804, 1312.444, 341.1812, -0.5995114, 0, 0, 0, 1, 120, 255, 1), -- 193828 (Area: 4622)
(@OGUID+33, 193830, 571, 1, 2, 7631.086, 1311.507, 341.5322, 2.199114, 0, 0, 0, 1, 120, 255, 1), -- 193830 (Area: 4622)
(@OGUID+34, 193838, 571, 1, 2, 7628.428, 1307.566, 341.7274, 2.481837, 0, 0, 0, 1, 120, 255, 1), -- 193838 (Area: 4622)
(@OGUID+35, 193831, 571, 1, 2, 7630.328, 1312.191, 341.3887, 1.474802, 0, 0, 0, 1, 120, 255, 1), -- 193831 (Area: 4622)
(@OGUID+36, 193832, 571, 1, 2, 7631.078, 1312.427, 341.4087, 1.210786, 0, 0, 0, 1, 120, 255, 1), -- 193832 (Area: 4622)
(@OGUID+37, 193845, 571, 1, 2, 7625.171, 1305.658, 341.5322, 2.274172, 0, 0, 0, 1, 120, 255, 1), -- 193845 (Area: 4622)
(@OGUID+38, 193803, 571, 1, 2, 7634.984, 1315.54, 341.3336, 0.3839723, 0, 0, 0, 1, 120, 255, 1), -- 193803 (Area: 4622)
(@OGUID+39, 193804, 571, 1, 2, 7612.716, 1303.828, 340.1033, 2.403463, 0, 0, 0, 1, 120, 255, 1), -- 193804 (Area: 4622)
(@OGUID+40, 193799, 571, 1, 2, 7629.829, 1308.381, 341.4977, 2.495816, 0, 0, 0, 1, 120, 255, 1), -- 193799 (Area: 4622)
(@OGUID+41, 193474, 571, 1, 2, 7594.459, 1387.242, 335.4896, 1.509709, 0, 0, 0, 1, 120, 255, 1), -- 193474 (Area: 4622)
(@OGUID+42, 193477, 571, 1, 2, 7565.28, 1388.165, 328.3016, 2.646745, 0, 0, 0, 1, 120, 255, 1), -- 193477 (Area: 4622)
(@OGUID+43, 193478, 571, 1, 2, 7573.998, 1396.272, 329.3516, 1.903219, 0, 0, 0, 1, 120, 255, 1), -- 193478 (Area: 4622)
(@OGUID+44, 193479, 571, 1, 2, 7574.192, 1387.192, 330.1734, -0.721683, 0, 0, 0, 1, 120, 255, 1), -- 193479 (Area: 4622)
(@OGUID+45, 193515, 571, 1, 2, 7572.924, 1386.133, 330.0977, -0.1943158, 0, 0, 0, 1, 120, 255, 1), -- 193515 (Area: 4622)
(@OGUID+46, 193475, 571, 1, 2, 7594.464, 1387.608, 334.2297, -1.596976, 0, 0, 0, 1, 120, 255, 1), -- 193475 (Area: 4622)
(@OGUID+47, 193511, 571, 1, 2, 7572.461, 1387.348, 329.9952, -2.310437, 0, 0, 0, 1, 120, 255, 1), -- 193511 (Area: 4622)
(@OGUID+48, 193523, 571, 1, 2, 7569.051, 1379.311, 329.6375, 0.26714, 0, 0, 0, 1, 120, 255, 1), -- 193523 (Area: 4622)
(@OGUID+49, 193524, 571, 1, 2, 7569.593, 1378.756, 331.6182, 0.2884431, 0, 0, 0, 1, 120, 255, 1), -- 193524 (Area: 4622)
(@OGUID+50, 193525, 571, 1, 2, 7569.944, 1380.115, 331.8074, 0.2884431, 0, 0, 0, 1, 120, 255, 1), -- 193525 (Area: 4622)
(@OGUID+51, 193526, 571, 1, 2, 7578.941, 1388.341, 331.1905, 2.510151, 0, 0, 0, 1, 120, 255, 1), -- 193526 (Area: 4622)
(@OGUID+52, 193527, 571, 1, 2, 7578.064, 1388.368, 330.8582, 0.952802, 0, 0, 0, 1, 120, 255, 1), -- 193527 (Area: 4622)
(@OGUID+53, 193528, 571, 1, 2, 7578.356, 1387.903, 331.3766, 2.996104, 0, 0, 0, 1, 120, 255, 1), -- 193528 (Area: 4622)
(@OGUID+54, 193514, 571, 1, 2, 7587.764, 1391.348, 333.9012, 3.10851, 0, 0, 0, 1, 120, 255, 1), -- 193514 (Area: 4622)
(@OGUID+55, 193472, 571, 1, 2, 7584.512, 1387.774, 335.2943, 1.52716, 0, 0, 0, 1, 120, 255, 1), -- 193472 (Area: 4622)
(@OGUID+56, 193473, 571, 1, 2, 7584.511, 1388.14, 334.0347, -1.579522, 0, 0, 0, 1, 120, 255, 1), -- 193473 (Area: 4622)
(@OGUID+57, 193510, 571, 1, 2, 7585.269, 1391.078, 333.9027, -2.382504, 0, 0, 0, 1, 120, 255, 1), -- 193510 (Area: 4622)
(@OGUID+58, 193529, 571, 1, 2, 7611.424, 1384.339, 335.7021, 0.4115172, 0, 0, 0, 1, 120, 255, 1), -- 193529 (Area: 4622)
(@OGUID+59, 193498, 571, 1, 2, 7608.75, 1388.728, 335.8158, -3.031208, 0, 0, 0, 1, 120, 255, 1), -- 193498 (Area: 4622)
(@OGUID+60, 193512, 571, 1, 2, 7607.569, 1380.687, 334.6062, -2.615315, 0, 0, 0, 1, 120, 255, 1), -- 193512 (Area: 4622)
(@OGUID+61, 193513, 571, 1, 2, 7602.882, 1392.214, 333.8481, 2.86819, 0, 0, 0, 1, 120, 255, 1), -- 193513 (Area: 4622)
(@OGUID+62, 193499, 571, 1, 2, 7607.803, 1387.896, 334.5514, 1.181878, 0, 0, 0, 1, 120, 255, 1), -- 193499 (Area: 4622)
(@OGUID+63, 193500, 571, 1, 2, 7607.761, 1388.981, 335.6974, 2.752486, 0, 0, 0, 1, 120, 255, 1), -- 193500 (Area: 4622)
(@OGUID+64, 193501, 571, 1, 2, 7608.067, 1387.847, 335.6891, 1.57918, 0, 0, 0, 1, 120, 255, 1), -- 193501 (Area: 4622)
(@OGUID+65, 193502, 571, 1, 2, 7606.78, 1387.013, 335.4621, 0.4406689, 0, 0, 0, 1, 120, 255, 1), -- 193502 (Area: 4622)
(@OGUID+66, 193507, 571, 1, 2, 7603.438, 1393.474, 333.8636, 0.8205906, 0, 0, 0, 1, 120, 255, 1), -- 193507 (Area: 4622)
(@OGUID+67, 193508, 571, 1, 2, 7604.211, 1394.048, 334.0117, 0.553567, 0, 0, 0, 1, 120, 255, 1), -- 193508 (Area: 4622)
(@OGUID+68, 193521, 571, 1, 2, 7603.405, 1381.198, 334.5134, 1.028245, 0, 0, 0, 1, 120, 255, 1), -- 193521 (Area: 4622)
(@OGUID+69, 193522, 571, 1, 2, 7609.946, 1383.467, 334.8445, 2.07127, 0, 0, 0, 1, 120, 255, 1), -- 193522 (Area: 4622)
(@OGUID+70, 193505, 571, 1, 2, 7614.041, 1383.107, 335.3358, -1.199282, 0, 0, 0, 1, 120, 255, 1), -- 193505 (Area: 4622)
(@OGUID+71, 193506, 571, 1, 2, 7604.289, 1393.07, 334.0316, -0.001746883, 0, 0, 0, 1, 120, 255, 1), -- 193506 (Area: 4622)
(@OGUID+72, 193466, 571, 1, 2, 7603.318, 1390.261, 333.631, -1.944215, 0, 0, 0, 1, 120, 255, 1), -- 193466 (Area: 4622)
(@OGUID+73, 193467, 571, 1, 2, 7611.13, 1380.281, 334.9095, -2.729541, 0, 0, 0, 1, 120, 255, 1), -- 193467 (Area: 4622)
(@OGUID+74, 193503, 571, 1, 2, 7613.502, 1382.34, 335.2786, 0.381168, 0, 0, 0, 1, 120, 255, 1), -- 193503 (Area: 4622)
(@OGUID+75, 193504, 571, 1, 2, 7613.352, 1382.993, 335.6254, 0.8341318, 0, 0, 0, 1, 120, 255, 1), -- 193504 (Area: 4622)
(@OGUID+76, 193509, 571, 1, 2, 7600.531, 1392.637, 333.3486, 1.351323, 0, 0, 0, 1, 120, 255, 1), -- 193509 (Area: 4622)
(@OGUID+77, 193806, 571, 1, 2, 7559.955, 1299.04, 333.1187, 2.809974, 0, 0, 0, 1, 120, 255, 1), -- 193806 (Area: 4622)
(@OGUID+78, 193798, 571, 1, 2, 7554.067, 1301.211, 331.2181, 1.195549, 0, 0, 0, 1, 120, 255, 1), -- 193798 (Area: 4622)
(@OGUID+79, 193841, 571, 1, 2, 7625.241, 1304.634, 341.6619, 2.192614, 0, 0, 0, 1, 120, 255, 1), -- 193841 (Area: 4622)
(@OGUID+80, 193843, 571, 1, 2, 7626.075, 1302.194, 342.0533, 1.939992, 0, 0, 0, 1, 120, 255, 1), -- 193843 (Area: 4622)
(@OGUID+81, 193842, 571, 1, 2, 7625.737, 1303.095, 341.8933, 2.157538, 0, 0, 0, 1, 120, 255, 1), -- 193842 (Area: 4622)
(@OGUID+82, 193835, 571, 1, 2, 7621.549, 1301.871, 341.7209, -1.390356, 0, 0, 0, 1, 120, 255, 1), -- 193835 (Area: 4622)
(@OGUID+83, 193797, 571, 1, 2, 7622.559, 1303.291, 341.1438, 1.823867, 0, 0, 0, 1, 120, 255, 1), -- 193797 (Area: 4622)
(@OGUID+84, 193844, 571, 1, 2, 7626.616, 1302.82, 342.0193, 1.37313, 0, 0, 0, 1, 120, 255, 1); -- 193844 (Area: 4622)

-- 193471
UPDATE `gameobject` SET `phaseMask`=3 WHERE `guid`=62737;

UPDATE `creature_template` SET `AIName`='SmartAI',`exp`=2,`minlevel`=80,`maxlevel`=80,`faction_A`=2136,`faction_H`=2136 WHERE `entry`=@L_FOOTSOLDIER;
UPDATE `creature_template` SET `AIName`='SmartAI',`exp`=2,`minlevel`=80,`maxlevel`=80,`faction_A`=2136,`faction_H`=2136 WHERE `entry`=@L_CAPTAIN;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@L_CAPTAIN,@L_FOOTSOLDIER) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
 -- We hide the body; this way to prevent multiple ghoul spawns from the same body
(@L_CAPTAIN,0,0,0,8,0,100,0,58916,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lordaeron Captain - On Spellhit - Set Invisible'),
(@L_CAPTAIN,0,1,0,38,0,100,0,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lordaeron Captain - On Data Set - Talk'),
(@L_FOOTSOLDIER,0,0,0,8,0,100,0,58916,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lordaeron Footsoldier - On Spellhit -Set Invisible'),
(@L_FOOTSOLDIER,0,1,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lordaeron Footsoldier - On Aggro - Talk');


DELETE FROM `creature_equip_template` WHERE `entry` IN (@L_CAPTAIN,@L_FOOTSOLDIER);
INSERT INTO `creature_equip_template` (`entry`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(@L_CAPTAIN,1895,0,36636), -- Lordaeron Captain @L_CAPTAIN
(@L_FOOTSOLDIER,1895,0,36636); -- Lordaeron Footsoldier @L_FOOTSOLDIER

DELETE FROM `creature_text` WHERE `entry` IN (@L_FOOTSOLDIER,@L_CAPTAIN);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@L_FOOTSOLDIER,0,0,'The undead are upon us!',12,0,10,0,0,0,'Lordaeron Footsoldier to Ghoulish Minion'),
(@L_FOOTSOLDIER,0,1,'The rumors were true!  The prince has gone mad!',12,0,10,0,0,0,'Lordaeron Footsoldier to Ghoulish Minion'),
(@L_CAPTAIN,0,0,'You''ve come to address the men, sir?', 12,0,100,66,0,0,'Lordaeron Captain');

UPDATE `creature_template` SET `AIName`='SmartAI',`speed_walk`=0.777776,`minlevel`=82,`maxlevel`=82,`unit_flags`=0x8 WHERE `entry`=@G_MINION;
DELETE FROM `creature_template_addon` WHERE `entry`=@G_MINION;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(@G_MINION,0,0x0,0x1,'58946'); -- Hate Aura


DELETE FROM `smart_scripts` WHERE `entryorguid`=@G_MINION AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@G_MINION,0,0,0,54,0,100,1,0,0,0,0,11,@SFKCB,0,0,0,0,0,23,0,0,0,0,0,0,0,'On Just Summoned - Cast Spell - Owner');

-- Where Dragons Fell (13398/13359)
-- http://www.youtube.com/watch?v=v3FsLm1oY8k

UPDATE `creature_template` SET `minlevel`=83, `maxlevel`=83, `exp`=2, `unit_class`=2, `InhabitType`=7 WHERE  `entry`=@NPC_SIND;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@NPC_LK,@NPC_SIND,@NPC_LK*100,@MATT3);
DELETE FROM `smart_scripts` WHERE (`entryorguid` IN (@NPC_LK,@NPC_SIND,@MATT3,@NPC_LK*100) AND `source_type`IN (0,9));
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@MATT3,0,0,0,20,0,100,0,13398,1,0,0,12,@NPC_LK,1,27000,0,0,0,8,0,0,0,7863.779, 943.377, 451.502, 1.556,'Matthias Lehner - On Quest rewarded - Summon Lich King'),
(@MATT3,0,1,0,20,0,100,0,13359,0,0,0,12,@NPC_LK,1,27000,0,0,0,8,0,0,0,7863.779, 943.377, 451.502, 1.556,'Matthias Lehner - On Quest rewarded - Summon Lich King '),

(@NPC_LK,0,0,0,54,0,100,0,0,0,0,0,53,0,@NPC_LK,0,0,0,0,1,0,0,0,0,0,0,0,'Lich King - On Summoned - Start WP-Movement'),
(@NPC_LK,0,1,2,58,0,100,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lich King - On WP-End - Talk'),
(@NPC_LK,0,2,3,61,0,100,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lich King - On Link -Add unit field bytes - Kneel'),
(@NPC_LK,0,3,4,61,0,100,0,0,0,0,0,12,@NPC_SIND,8,0,0,0,0,8,0,0,0,7837.523,1054.987,421.766,5.00,'Lich King - On WP-End - Summon Sindragosa'),
(@NPC_LK,0,4,0,61,0,100,0,0,0,0,0,80,@NPC_LK*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Lich King - On Link - Start timed script'),
(@NPC_LK,0,5,0,38,0,100,0,1,1,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lich King - On data set - Remove unit field bytes'),
(@NPC_LK*100,9,0,0,0,0,100,0,2000,2000,2000,2000,45,1,1,0,0,0,0,1,0,0,0,0,0,0,0,'Lich King - On Script - Set Data'),

(@NPC_SIND,0,0,0,54,0,100,0,0,0,0,0,53,1,@NPC_SIND,0,0,0,0,1,0,0,0,0,0,0,0,'Sindragosa - On Summoned - Start WP-Movement'),
(@NPC_SIND,0,1,2,58,0,100,0,1,0,0,0,45,1,1,0,0,0,0,1,0,0,0,0,0,0,0,'Sindragosa - On WP-Ended - Set Data on self'),
(@NPC_SIND,0,2,3,61,0,100,0,1,1,0,0,46,200,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sindragosa - On data set - Move forward'),
(@NPC_SIND,0,3,0,61,0,100,0,0,0,0,0,41,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sindragosa - On data set - Despawn');

DELETE FROM `creature_template_addon` WHERE entry =@NPC_SIND;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(@NPC_SIND,0,0,33554432,0,0,'43775');

DELETE FROM `waypoints` WHERE `entry`=@NPC_LK;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@NPC_LK,1,7863.453, 960.661, 450.491,'Lich King - WP1');

DELETE FROM `waypoints` WHERE `entry`=@NPC_SIND;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@NPC_SIND,1,7848.635,1027.209,480.763,'Sindragosa- WP1');

DELETE FROM `creature_text` WHERE `entry`= @NPC_LK;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_LK,0,0,'Rise, Sindragosa! Rise and lead the Frostbrood into war!',12,0,100,16,0,0,'Lich King');


-- The Hunter and the Prince (13400/13361)
-- Bloodstained Stone
-- GO:194023  Event:20722
-- GO:194024  Event:20723
-- GO:193980  Event:20724
     
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@MATT4;

DELETE FROM `smart_scripts` WHERE (`entryorguid`=@MATT4 AND `source_type`=0) OR (`entryorguid` IN (@MATT4*100,@MATT4*100+1,@MATT4*100+2) AND `source_type`=9);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@MATT4,0,0,0,19,0,100,0,13400,0,0,0,87,@MATT4*100,@MATT4*100+1,@MATT4*100+2,0,0,0,1,0,0,0,0,0,0,0,'On Quest Accepted - Run Script - Self'),
(@MATT4,0,1,0,19,0,100,0,13361,0,0,0,87,@MATT4*100,@MATT4*100+1,@MATT4*100+2,0,0,0,1,0,0,0,0,0,0,0,'On Quest Accepted - Run Script - Self'),
(@MATT4*100,9,0,0,0,0,100,0,0,0,0,0,50,@BLOODSTAINED_S1,30000,0,0,0,0,8,0,0,0,6331.721,2360.052,477.274,0,'On Script - Summon GO - Location'),
(@MATT4*100+1,9,0,0,0,0,100,0,0,0,0,0,50,@BLOODSTAINED_S2,30000,0,0,0,0,8,0,0,0,6359.744,2342.196,472.701,0,'On Script - Summon GO - Location'),
(@MATT4*100+2,9,0,0,0,0,100,0,0,0,0,0,50,@BLOODSTAINED_S3,30000,0,0,0,0,8,0,0,0,6358.710,2383.027,474.682,0,'On Script - Summon GO - Location');

-- LK
UPDATE `creature_template` SET `AIName`='',`minlevel`=82,`maxlevel`=82,`EXP`=2,`mindmg`=417,`maxdmg`=582,`attackpower`=608,`baseattacktime`=3000,`unit_class`=2,`minrangedmg`=341,`maxrangedmg`=506,`rangedattackpower`=80,`spell1`=60617,`spell2`=60644,`spell3`=60672,`spell4`=60642,`VehicleId`=300 WHERE `entry`=@LK;
UPDATE `creature_template` SET `Health_mod`=160,`EXP`=0,`rank`=3,`type_flags`=0,`AIName`='SmartAI',`faction_A`=14,`faction_H`=14,`minlevel`=82,`maxlevel`=82,`mindmg`=452,`maxdmg`=678,`attackpower`=169,`baseattacktime`=2000,`unit_class`=1,`minrangedmg`=362,`maxrangedmg`=542,`rangedattackpower`=135 WHERE `entry`= @ILLIDAN;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ILLIDAN AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ILLIDAN,0,0,0,54,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Illidan - On Just Summoned - Talk - Self'),
(@ILLIDAN,0,1,0,0,0,100,0,15000,16000,15000,16000,11,60744,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Illidan - In combat - Immolate'),
(@ILLIDAN,0,2,0,0,0,100,0,6000,7000,6000,7000,11,61101,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Illidan - In combat - Heart Rip'),
(@ILLIDAN,0,4,0,0,0,100,0,19000,19000,19000,19000,11,60742,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Illidan - In combat - Shear'),
(@ILLIDAN,0,5,0,6,0,100,0,0,0,0,0,33,32797,0,0,0,0,0,21,20,0,0,0,0,0,0, 'Illidan - On death - Give quest credit');

-- Removing spell from this table in order for Energize (60628) to refund mana.
DELETE FROM `spell_proc_event` WHERE  `entry`=60617;

DELETE FROM `creature_text` WHERE `entry`=@ILLIDAN;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`TEXT`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ILLIDAN,0,0,'Prepare to die!',12,0,100,0,0,0,'Illidan Stormrage');

DELETE FROM `event_scripts` WHERE `id` IN (@EVENT1,@EVENT2,@EVENT3);
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(@EVENT_1,0,10,@ILLIDAN,60000,0,6342.646,2399.023,478.483,5.5137),
(@EVENT_2,0,10,@ILLIDAN,60000,0,6313.481,2345.141,479.379,1.0173),
(@EVENT_3,0,10,@ILLIDAN,60000,0,6351.155,2315.504,474.698,1.2568);

-- These don't work ...
-- 61752 Illidan Kill Credit Master
-- 61748 Illidan Kill Credit
 
-- Addition Dr-j
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=32370 AND `SourceEntry`=59724 AND `ConditionValue1`=13305;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18,32370,59724,0,1,9,0,13305,0,0,0,0,0, '', 'Required quest active for spellclick'),
(18,32370,59724,0,1,28,0,13305,0,0,1,0,0, '', 'Required quest not completed for spellclick');
