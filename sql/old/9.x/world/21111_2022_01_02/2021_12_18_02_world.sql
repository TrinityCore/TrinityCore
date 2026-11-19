SET @CGUID := 395101;

-- Marcus Jensen
UPDATE `creature_template` SET `gossip_menu_id`=14400, `VerifiedBuild`=41079 WHERE `entry`=63014;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=63014 AND `DifficultyID`=0);
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=63014 AND `Idx`=0);
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=13091;

DELETE FROM `creature_template_addon` WHERE `entry`=63014;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(63014, 0, 0, 0, 257, 0, 0, 0, 0, '');

UPDATE `gossip_menu` SET `VerifiedBuild`=41079 WHERE (`MenuId`=14400 AND `TextId`=20326);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=41079 WHERE `MenuId`=14991;

DELETE FROM `creature_trainer` WHERE `CreatureId`=63014;
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuID`, `OptionIndex`) VALUES
(63014, 580, 14400, 0);

DELETE FROM `npc_vendor` WHERE `entry`=63014;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(63014, 1, 98715, 0, 4292, 1, 0, 0, 41079),
(63014, 2, 98715, 0, 4293, 1, 0, 0, 41079),
(63014, 3, 98715, 0, 4294, 1, 0, 0, 41079),
(63014, 4, 98715, 0, 4295, 1, 0, 0, 41079),
(63014, 5, 98715, 0, 4296, 1, 0, 0, 41079),
(63014, 6, 98715, 0, 4297, 1, 0, 0, 41079),
(63014, 7, 98715, 0, 4298, 1, 0, 0, 41079),
(63014, 8, 98715, 0, 4299, 1, 0, 0, 41079),
(63014, 9, 98715, 0, 4300, 1, 0, 0, 41079),
(63014, 10, 98715, 0, 4301, 1, 0, 0, 41079);

DELETE FROM `creature` WHERE `guid`=@CGUID+0 AND `id`=63014;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 63014, 0, 12, 87, '0', 0, 0, 0, 0, -9467.576171875, 136.064239501953125, 58.36111068725585937, 3.468830108642578125, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 41079);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=63014;

DELETE FROM `areatrigger_scripts` WHERE `entry`=8130;
INSERT INTO `areatrigger_scripts` VALUES
(8130, 'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid`=8130 AND `source_type`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=63014 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8130,2,0,1,46,0,100,0,0,0,0,0,0,'',64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Areatrigger 8130 - On trigger - Store invoker in target list 1'),
(8130,2,1,2,61,0,100,0,0,0,0,0,0,'',100,1,0,0,0,0,0,19,63014,20,0,0,0,0,0,0,'Areatrigger 8130 - Event linked - Send stored target 1 to Marcus Jensen'),
(8130,2,2,0,61,0,100,0,0,0,0,0,0,'',45,1,1,0,0,0,0,19,63014,20,0,0,0,0,0,0,'Areatrigger 8130 - Event linked - Set data 1 1 on Marcus Jensen'),
(63014,0,0,1,38,0,100,0,1,1,0,0,0,'',11,116219,2,0,0,0,0,12,1,0,0,0,0,0,0,0,'Marcus Jensen - On data set 1 1 - Cast ''CSA Area Trigger Dummy Timer Aura A'' on invoker'),
(63014,0,1,0,61,0,100,0,0,0,0,0,0,'',1,0,0,1,0,0,0,12,1,0,0,0,0,0,0,0,'Marcus Jensen - Event linked - Say text');

DELETE FROM `creature_text` WHERE `CreatureID`=63014;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(63014, 0, 0, 'Interested in catching some rare pets?', 12, 0, 100, 1, 0, 0, 0, 62763, 5, 'Marcus Jensen - Random text'),
(63014, 0, 1, 'You look like someone that might be interested in some rare pets?', 12, 0, 100, 1, 0, 0, 0, 62764, 5, 'Marcus Jensen - Random text'),
(63014, 0, 2, 'Are you eyeing my cat?', 12, 0, 100, 1, 0, 0, 0, 63547, 5, 'Marcus Jensen - Random text');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND SourceEntry=8130 AND SourceId=2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,8130,2,0,6,0,469,0,0,0,0,0,'',' Areatrigger 8130 smart if player is Alliance'),
(22,1,8130,2,0,1,0,116219,0,0,1,0,0,'',' Areatrigger 8130 smart requires aura 116219 not applied'),
(22,1,8130,2,0,25,0,125610,0,0,1,0,0,'',' Areatrigger 8130 smart requires spell 125610 not learned');

-- Tabbi
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=64, `VerifiedBuild`=41079 WHERE `entry`=63015;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=63015 AND `DifficultyID`=0);
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=63015 AND `Idx`=0);
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=5554;

DELETE FROM `creature_template_addon` WHERE `entry`=63015;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(63015, 0, 0, 0, 1, 0, 0, 0, 0, '');

DELETE FROM `creature` WHERE `guid`=@CGUID+1 AND `id`=63015;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+1, 63015, 0, 12, 87, '0', 0, 0, 0, 0, -9467.87890625, 136.720489501953125, 58.19965362548828125, 3.162040472030639648, 120, 0, 0, 118, 0, 0, 0, 0, 0, 41079);

-- Grady Bannson
UPDATE `creature_template` SET `gossip_menu_id`=14991, `minlevel`=30, `maxlevel`=30, `VerifiedBuild`=41079 WHERE `entry`=63075;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=63075 AND `DifficultyID`=0);
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=63075 AND `Idx`=0);
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=30586;

DELETE FROM `creature_template_addon` WHERE `entry`=63075;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(63075, 0, 0, 0, 257, 0, 0, 0, 0, '');

DELETE FROM `creature_trainer` WHERE `CreatureId`=63075;
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuID`, `OptionIndex`) VALUES
(63075, 580, 14991, 0);

DELETE FROM `npc_vendor` WHERE `entry`=63075;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(63075, 1, 98715, 0, 4292, 1, 0, 0, 41079),
(63075, 2, 98715, 0, 4293, 1, 0, 0, 41079),
(63075, 3, 98715, 0, 4294, 1, 0, 0, 41079),
(63075, 4, 98715, 0, 4295, 1, 0, 0, 41079),
(63075, 5, 98715, 0, 4296, 1, 0, 0, 41079),
(63075, 6, 98715, 0, 4297, 1, 0, 0, 41079),
(63075, 7, 98715, 0, 4298, 1, 0, 0, 41079),
(63075, 8, 98715, 0, 4299, 1, 0, 0, 41079),
(63075, 9, 98715, 0, 4300, 1, 0, 0, 41079),
(63075, 10, 98715, 0, 4301, 1, 0, 0, 41079);

DELETE FROM `creature` WHERE `guid`=@CGUID+2 AND `id`=63075;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+2, 63075, 0, 1, 131, '0', 0, 0, 0, 0, -5576.798828125, -499.05902099609375, 403.9716796875, 1.957015395164489746, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 41079);

-- Fluffy
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=64, `VerifiedBuild`=41079 WHERE `entry`=63074;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=63074 AND `DifficultyID`=0);
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=63074 AND `Idx`=0);
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=328;

DELETE FROM `creature_template_addon` WHERE `entry`=63074;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(63074, 0, 0, 0, 1, 0, 0, 0, 0, '');

DELETE FROM `creature` WHERE `guid`=@CGUID+3 AND `id`=63074;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+3, 63074, 0, 1, 131, '0', 0, 0, 0, 0, -5577.9443359375, -499.454864501953125, 404.020843505859375, 2.323996782302856445, 120, 0, 0, 118, 0, 0, 0, 0, 0, 41079);

-- Valeena
UPDATE `creature_template` SET `VerifiedBuild`=41079 WHERE `entry`=63070;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=63070 AND `DifficultyID`=0);
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=63070 AND `Idx`=0);
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=2055;

DELETE FROM `creature_template_addon` WHERE `entry`=63070;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(63070, 0, 0, 0, 257, 0, 0, 0, 0, '');

DELETE FROM `creature_trainer` WHERE `CreatureId`=63070;
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuID`, `OptionIndex`) VALUES
(63070, 580, 14991, 0);

DELETE FROM `npc_vendor` WHERE `entry`=63070;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(63070, 1, 98715, 0, 4292, 1, 0, 0, 41079),
(63070, 2, 98715, 0, 4293, 1, 0, 0, 41079),
(63070, 3, 98715, 0, 4294, 1, 0, 0, 41079),
(63070, 4, 98715, 0, 4295, 1, 0, 0, 41079),
(63070, 5, 98715, 0, 4296, 1, 0, 0, 41079),
(63070, 6, 98715, 0, 4297, 1, 0, 0, 41079),
(63070, 7, 98715, 0, 4298, 1, 0, 0, 41079),
(63070, 8, 98715, 0, 4299, 1, 0, 0, 41079),
(63070, 9, 98715, 0, 4300, 1, 0, 0, 41079),
(63070, 10, 98715, 0, 4301, 1, 0, 0, 41079);

UPDATE `creature` SET `zoneId`=141, `areaId`=186, `position_x`=9837.0849609375, `position_y`=991.1649169921875, `position_z`=1306.630859375, `orientation`=5.694543361663818359, `spawntimesecs`=120, `curhealth`=1604, `VerifiedBuild`=41079 WHERE `id`=63070 AND `guid`=864;

-- Hoo
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=64, `VerifiedBuild`=41079 WHERE `entry`=65097;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=65097 AND `DifficultyID`=0);
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=65097 AND `Idx`=0);
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=36640;

DELETE FROM `creature_template_addon` WHERE `entry`=65097;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(65097, 0, 0, 50331648, 1, 0, 0, 0, 0, '');

UPDATE `creature` SET `zoneId`=141, `areaId`=186, `position_x`=9838.046875, `position_y`=992.5, `position_z`=1308.134521484375, `orientation`=5.479003429412841796, `spawntimesecs`=120, `curhealth`=118, `VerifiedBuild`=41079 WHERE `id`=65097 AND `guid`=865;

-- Lehna
UPDATE `creature_template` SET `gossip_menu_id`=14991, `minlevel`=30, `maxlevel`=30, `VerifiedBuild`=41079 WHERE `entry`=63077;
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=63077 AND `Idx`=0);
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=17327;

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry`=63077);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(63077, 0, 0, 0, 76, 41079);

DELETE FROM `creature_template_addon` WHERE `entry`=63077;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(63077, 0, 0, 0, 257, 0, 0, 0, 0, '');

DELETE FROM `creature_trainer` WHERE `CreatureId`=63077;
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuID`, `OptionIndex`) VALUES
(63077, 580, 14991, 0);

UPDATE `npc_vendor` SET `VerifiedBuild`=41079 WHERE `entry`=63077;

DELETE FROM `creature` WHERE `guid`=@CGUID+4 AND `id`=63077;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+4, 63077, 530, 3524, 3576, '0', 0, 0, 0, 0, -4210.02783203125, -12507.3505859375, 45.50818634033203125, 0.161791294813156127, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 41079);

-- Flutters
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=64, `VerifiedBuild`=41079 WHERE `entry`=63078;
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=63078 AND `Idx`=0);
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=36640;

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry`=63078);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(63078, 0, 4, 4, 373, 41079);

DELETE FROM `creature_template_addon` WHERE `entry`=63078;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(63078, 0, 0, 33554432, 1, 0, 0, 0, 0, '');

DELETE FROM `creature_template_movement` WHERE `CreatureId`=63078;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES
(63078,2,0,0,0,0,0);

DELETE FROM `creature` WHERE `guid`=@CGUID+5 AND `id`=63078;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+5, 63078, 530, 3524, 3576, '0', 0, 0, 0, 0, -4209.68408203125, -12505.3232421875, 47.38095855712890625, 0.036397956311702728, 120, 0, 0, 118, 0, 0, 0, 0, 0, 41079);

-- Will Larsons
UPDATE `creature_template` SET `gossip_menu_id`=14991, `minlevel`=30, `maxlevel`=30, `VerifiedBuild`=41079 WHERE `entry`=63083;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=63083 AND `DifficultyID`=0);
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=63083 AND `Idx`=0);
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=33673;

DELETE FROM `creature_template_addon` WHERE `entry`=63083;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(63083, 0, 0, 0, 257, 0, 0, 0, 0, '');

DELETE FROM `creature_trainer` WHERE `CreatureId`=63083;
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuID`, `OptionIndex`) VALUES
(63083, 580, 14991, 0);

UPDATE `npc_vendor` SET `VerifiedBuild`=41079 WHERE `entry`=63083;

DELETE FROM `creature` WHERE `guid`=@CGUID+6 AND `id`=63083;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+6, 63083, 1, 148, 4659, '0', 0, 0, 0, 0, 7353.603515625, -223.777786254882812, 8.578592300415039062, 5.006371974945068359, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 41079);

-- Poe
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=64, `VerifiedBuild`=41079 WHERE `entry`=63084;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=63084 AND `DifficultyID`=0);
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=63084 AND `Idx`=0);
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=42863;

DELETE FROM `creature_template_addon` WHERE `entry`=63084;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(63084, 0, 0, 33554432, 1, 0, 0, 0, 0, '');

DELETE FROM `creature_template_movement` WHERE `CreatureId`=63084;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES
(63084,2,0,0,0,0,0);

DELETE FROM `creature` WHERE `guid`=@CGUID+7 AND `id`=63084;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+7, 63084, 1, 148, 4659, '0', 0, 0, 0, 0, 7351.87939453125, -224.104171752929687, 10.4171905517578125, 5.161756038665771484, 120, 0, 0, 118, 0, 0, 0, 0, 0, 41079);

-- Audrey Burnhep
UPDATE `creature_template` SET `gossip_menu_id`=14991, `minlevel`=60, `maxlevel`=60, `flags_extra` = (`flags_extra` | 0x1000), `VerifiedBuild`=41079 WHERE `entry`=63596;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=63596 AND `DifficultyID`=0);
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=63596 AND `Idx`=0);
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=4558;

DELETE FROM `creature_trainer` WHERE `CreatureId`=63596;
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuID`, `OptionIndex`) VALUES
(63596, 580, 14991, 0);

UPDATE `npc_vendor` SET `VerifiedBuild`=41079 WHERE `entry`=63596;

UPDATE `creature` SET `zoneId`=1519, `areaId`=1519, `position_x`=-8287.2158203125, `position_y`=515.4913330078125, `position_z`=120.5628433227539062, `orientation`=1.472758412361145019, `spawntimesecs`=120, `curhealth`=11791, `VerifiedBuild`=41079 WHERE `id`=63596;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=63596;

DELETE FROM `areatrigger_scripts` WHERE `entry`=8189;
INSERT INTO `areatrigger_scripts` VALUES
(8189, 'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid`=8189 AND `source_type`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=63596 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8189,2,0,1,46,0,100,0,0,0,0,0,0,'',64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Areatrigger 8189 - On trigger - Store invoker in target list 1'),
(8189,2,1,2,61,0,100,0,0,0,0,0,0,'',100,1,0,0,0,0,0,19,63596,20,0,0,0,0,0,0,'Areatrigger 8189 - Event linked - Send stored target 1 to Audrey Burnhep'),
(8189,2,2,0,61,0,100,0,0,0,0,0,0,'',45,1,1,0,0,0,0,19,63596,20,0,0,0,0,0,0,'Areatrigger 8189 - Event linked - Set data 1 1 on Audrey Burnhep'),
(63596,0,0,1,38,0,100,0,1,1,0,0,0,'',11,116219,2,0,0,0,0,12,1,0,0,0,0,0,0,0,'Audrey Burnhep - On data set 1 1 - Cast ''CSA Area Trigger Dummy Timer Aura A'' on invoker'),
(63596,0,1,0,61,0,100,0,0,0,0,0,0,'',1,0,0,1,0,0,0,12,1,0,0,0,0,0,0,0,'Audrey Burnhep - Event linked - Say text');

DELETE FROM `creature_text` WHERE `CreatureID`=63596;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(63596, 0, 0, 'Interested in catching some rare pets?', 12, 0, 100, 1, 0, 0, 0, 62763, 5, 'Audrey Burnhep - Random text'),
(63596, 0, 1, 'You look like someone that might be interested in some rare pets?', 12, 0, 100, 1, 0, 0, 0, 62764, 5, 'Audrey Burnhep - Random text'),
(63596, 0, 2, 'Have you ever seen such a beautiful rabbit?  I can help you catch your own!', 12, 0, 100, 1, 0, 0, 0, 62765, 5, 'Audrey Burnhep - Random text');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND SourceEntry=8189 AND SourceId=2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,8189,2,0,6,0,469,0,0,0,0,0,'',' Areatrigger 8189 smart if player is Alliance'),
(22,1,8189,2,0,1,0,116219,0,0,1,0,0,'',' Areatrigger 8189 smart requires aura 116219 not applied'),
(22,1,8189,2,0,25,0,125610,0,0,1,0,0,'',' Areatrigger 8189 smart requires spell 125610 not learned');

-- Rabbit
UPDATE `creature_template` SET `VerifiedBuild`=41079 WHERE `entry`=721;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=721 AND `DifficultyID`=0);
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=721 AND `Idx` IN (0,1));
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=4626;

UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=721;
DELETE FROM `creature_addon` WHERE `path_id`=0 AND (`auras` IS NULL OR `auras` != '74096') AND `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=721);

UPDATE `creature` SET `zoneId`=1519, `areaId`=1519, `position_x`=-8288.9619140625, `position_y`=514.86981201171875, `position_z`=121.168182373046875, `orientation`=1.322720766067504882, `spawntimesecs`=120, `curhealth`=1, `unit_flags`=256, `VerifiedBuild`=41079 WHERE `id`=721 AND `guid`=452739;
UPDATE `creature` SET `zoneId`=1519, `areaId`=1519, `position_x`=-8285.966796875, `position_y`=515.20831298828125, `position_z`=121.2848892211914062, `orientation`=1.322720766067504882, `spawntimesecs`=120, `curhealth`=1, `unit_flags`=256, `VerifiedBuild`=41079 WHERE `id`=721 AND `guid`=452741;

-- Squirrel
UPDATE `creature_template` SET `VerifiedBuild`=41079 WHERE `entry`=63607;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=63607 AND `DifficultyID`=0);
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=63607 AND `Idx`=0);
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=36620;

UPDATE `creature` SET `zoneId`=1519, `areaId`=1519, `position_x`=-8286.0595703125, `position_y`=515.4132080078125, `position_z`=121.9550323486328125, `orientation`=1.6369476318359375, `spawntimesecs`=120, `curhealth`=5, `unit_flags`=256, `VerifiedBuild`=41079 WHERE `id`=63607 AND `guid`=452740;
UPDATE `creature` SET `zoneId`=1519, `areaId`=1519, `position_x`=-8289.283203125, `position_y`=516.125, `position_z`=120.517669677734375, `orientation`=1.207058548927307128, `spawntimesecs`=120, `curhealth`=5, `unit_flags`=256, `VerifiedBuild`=41079 WHERE `id`=63607 AND `guid`=452743;

-- Prairie Dog
UPDATE `creature_template` SET `VerifiedBuild`=41079 WHERE `entry`=2620;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=2620 AND `DifficultyID`=0);
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=2620 AND `Idx`=0);
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=1072;

UPDATE `creature` SET `zoneId`=1519, `areaId`=1519, `position_x`=-8285.2255859375, `position_y`=516.26214599609375, `position_z`=120.608306884765625, `orientation`=1.7983018159866333, `spawntimesecs`=120, `curhealth`=5, `unit_flags`=256, `VerifiedBuild`=41079 WHERE `id`=2620 AND `guid`=452742;
