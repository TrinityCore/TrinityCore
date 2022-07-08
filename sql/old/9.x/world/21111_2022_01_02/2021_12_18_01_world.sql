SET @CGUID := 395092;

-- Narzak
UPDATE `creature_template` SET `gossip_menu_id`=14991, `VerifiedBuild`=41079 WHERE `entry`=63061;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=63061 AND `DifficultyID`=0);
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=63061 AND `Idx`=0);
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=3746;

DELETE FROM `creature_template_addon` WHERE `entry`=63061;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(63061, 0, 0, 0, 257, 0, 0, 0, 0, '');

DELETE FROM `creature_trainer` WHERE `CreatureId`=63061;
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuID`, `OptionIndex`) VALUES
(63061, 580, 14991, 0);

DELETE FROM `npc_vendor` WHERE `entry`=63061;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(63061, 1, 98715, 0, 4292, 1, 0, 0, 41079),
(63061, 2, 98715, 0, 4293, 1, 0, 0, 41079),
(63061, 3, 98715, 0, 4294, 1, 0, 0, 41079),
(63061, 4, 98715, 0, 4295, 1, 0, 0, 41079),
(63061, 5, 98715, 0, 4296, 1, 0, 0, 41079),
(63061, 6, 98715, 0, 4297, 1, 0, 0, 41079),
(63061, 7, 98715, 0, 4298, 1, 0, 0, 41079),
(63061, 8, 98715, 0, 4299, 1, 0, 0, 41079),
(63061, 9, 98715, 0, 4300, 1, 0, 0, 41079),
(63061, 10, 98715, 0, 4301, 1, 0, 0, 41079);

DELETE FROM `creature` WHERE `guid`=@CGUID+0 AND `id`=63061;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 63061, 1, 14, 362, '0', 0, 0, 0, 0, 352.845489501953125, -4749.765625, 12.41132545471191406, 2.928458690643310546, 120, 0, 0, 1989, 0, 0, 0, 0, 0, 41079);

-- Shifty
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=64, `VerifiedBuild`=41079 WHERE `entry`=63063;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=63063 AND `DifficultyID`=0);
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=63063 AND `Idx`=0);
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=1206;

DELETE FROM `creature_template_addon` WHERE `entry`=63063;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(63063, 0, 0, 0, 1, 0, 0, 0, 0, '');

DELETE FROM `creature` WHERE `guid`=@CGUID+1 AND `id`=63063;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+1, 63063, 1, 14, 362, '0', 0, 0, 0, 0, 352.767364501953125, -4751.49658203125, 12.68089485168457031, 2.928458690643310546, 120, 0, 0, 118, 0, 0, 0, 0, 0, 41079);

-- Naleen
UPDATE `creature_template` SET `VerifiedBuild`=41079 WHERE `entry`=63067;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=63067 AND `DifficultyID`=0);
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=63067 AND `Idx`=0);
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=3867;

DELETE FROM `creature_template_addon` WHERE `entry`=63067;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(63067, 0, 0, 0, 257, 0, 0, 0, 0, '');

DELETE FROM `creature_trainer` WHERE `CreatureId`=63067;
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuID`, `OptionIndex`) VALUES
(63067, 580, 14991, 0);

DELETE FROM `npc_vendor` WHERE `entry`=63067;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(63067, 1, 98715, 0, 4292, 1, 0, 0, 41079),
(63067, 2, 98715, 0, 4293, 1, 0, 0, 41079),
(63067, 3, 98715, 0, 4294, 1, 0, 0, 41079),
(63067, 4, 98715, 0, 4295, 1, 0, 0, 41079),
(63067, 5, 98715, 0, 4296, 1, 0, 0, 41079),
(63067, 6, 98715, 0, 4297, 1, 0, 0, 41079),
(63067, 7, 98715, 0, 4298, 1, 0, 0, 41079),
(63067, 8, 98715, 0, 4299, 1, 0, 0, 41079),
(63067, 9, 98715, 0, 4300, 1, 0, 0, 41079),
(63067, 10, 98715, 0, 4301, 1, 0, 0, 41079);

DELETE FROM `creature` WHERE `guid`=@CGUID+2 AND `id`=63067;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+2, 63067, 1, 215, 222, '0', 0, 0, 0, 0, -2205.989501953125, -477.732635498046875, -9.05783843994140625, 2.547599077224731445, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 41079);

-- Miles
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=64, `VerifiedBuild`=41079 WHERE `entry`=63068;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=63068 AND `DifficultyID`=0);
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=63068 AND `Idx`=0);
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=45900;

DELETE FROM `creature_template_addon` WHERE `entry`=63068;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(63068, 0, 0, 0, 1, 0, 0, 0, 0, '');

DELETE FROM `creature` WHERE `guid`=@CGUID+3 AND `id`=63068;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+3, 63068, 1, 215, 222, '0', 0, 0, 0, 0, -2206.0400390625, -476.5069580078125, -8.97754669189453125, 2.2899169921875, 120, 0, 0, 118, 0, 0, 0, 0, 0, 41079);

-- Ansel Fincap
UPDATE `creature_template` SET `VerifiedBuild`=41079 WHERE `entry`=63073;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=63073 AND `DifficultyID`=0);
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=63073 AND `Idx`=0);
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=35626;

DELETE FROM `creature_template_addon` WHERE `entry`=63073;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(63073, 0, 0, 0, 257, 0, 0, 0, 0, '');

DELETE FROM `creature_trainer` WHERE `CreatureId`=63073;
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuID`, `OptionIndex`) VALUES
(63073, 580, 14991, 0);

DELETE FROM `npc_vendor` WHERE `entry`=63073;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(63073, 1, 98715, 0, 4292, 1, 0, 0, 41079),
(63073, 2, 98715, 0, 4293, 1, 0, 0, 41079),
(63073, 3, 98715, 0, 4294, 1, 0, 0, 41079),
(63073, 4, 98715, 0, 4295, 1, 0, 0, 41079),
(63073, 5, 98715, 0, 4296, 1, 0, 0, 41079),
(63073, 6, 98715, 0, 4297, 1, 0, 0, 41079),
(63073, 7, 98715, 0, 4298, 1, 0, 0, 41079),
(63073, 8, 98715, 0, 4299, 1, 0, 0, 41079),
(63073, 9, 98715, 0, 4300, 1, 0, 0, 41079),
(63073, 10, 98715, 0, 4301, 1, 0, 0, 41079);

DELETE FROM `creature` WHERE `guid`=@CGUID+4 AND `id`=63073;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+4, 63073, 0, 85, 159, '0', 0, 0, 0, 0, 2201.069580078125, 280.154510498046875, 39.18885421752929687, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 41079);

 -- Fester
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=64, `VerifiedBuild`=41079 WHERE `entry`=63069;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=63069 AND `DifficultyID`=0);
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=63069 AND `Idx`=0);
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=2177;

DELETE FROM `creature_template_addon` WHERE `entry`=63069;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(63069, 0, 0, 0, 1, 0, 0, 0, 0, '');

UPDATE `creature` SET `zoneId`=85, `areaId`=159, `position_x`=2201.244873046875, `position_y`=281.161468505859375, `position_z`=39.38019561767578125, `orientation`=5.728331565856933593, `spawntimesecs`=120, `curhealth`=118, `VerifiedBuild`=41079 WHERE `id`=63069;

-- Jarson Everlong
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `VerifiedBuild`=41079 WHERE `entry`=63080;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=63080 AND `DifficultyID`=0);
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=63080 AND `Idx`=0);
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=16918;

UPDATE `npc_vendor` SET `VerifiedBuild`=41079 WHERE `entry`=63080;

UPDATE `creature` SET `zoneId`=3430, `areaId`=3665, `position_x`=9486.8564453125, `position_y`=-6819.42041015625, `position_z`=16.57690048217773437, `orientation`=0.626979470252990722, `spawntimesecs`=120, `curhealth`=1604, `VerifiedBuild`=41079 WHERE `id`=63080;

-- Flaps
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=64, `VerifiedBuild`=41079 WHERE `entry`=63079;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=63079 AND `DifficultyID`=0);
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=63079 AND `Idx`=0);
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=20027;

DELETE FROM `creature_template_movement` WHERE `CreatureId`=63079;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES
(63079,2,0,0,0,0,0);

UPDATE `creature` SET `zoneId`=3430, `areaId`=3665, `position_x`=9488.302734375, `position_y`=-6820.91162109375, `position_z`=17.48877525329589843, `orientation`=0.879761934280395507, `spawntimesecs`=120, `curhealth`=118, `VerifiedBuild`=41079 WHERE `id`=63079;

-- Matty
UPDATE `creature_template` SET `gossip_menu_id`=14991, `minlevel`=60, `VerifiedBuild`=41079 WHERE `entry`=63086;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=63086 AND `DifficultyID`=0);
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=63086 AND `Idx`=0);
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=29968;

DELETE FROM `creature_trainer` WHERE `CreatureId`=63086;
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuID`, `OptionIndex`) VALUES
(63086, 580, 14991, 0);

DELETE FROM `npc_vendor` WHERE `entry`=63086;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(63086, 1, 98715, 0, 4292, 1, 0, 0, 41079),
(63086, 2, 98715, 0, 4293, 1, 0, 0, 41079),
(63086, 3, 98715, 0, 4294, 1, 0, 0, 41079),
(63086, 4, 98715, 0, 4295, 1, 0, 0, 41079),
(63086, 5, 98715, 0, 4296, 1, 0, 0, 41079),
(63086, 6, 98715, 0, 4297, 1, 0, 0, 41079),
(63086, 7, 98715, 0, 4298, 1, 0, 0, 41079),
(63086, 8, 98715, 0, 4299, 1, 0, 0, 41079),
(63086, 9, 98715, 0, 4300, 1, 0, 0, 41079),
(63086, 10, 98715, 0, 4301, 1, 0, 0, 41079);

UPDATE `creature` SET `zoneId`=1637, `areaId`=5332, `position_x`=1592.0572509765625, `position_y`=-4146.1337890625, `position_z`=51.81286239624023437, `orientation`=3.244290590286254882, `spawntimesecs`=120, `curhealth`=11791, `VerifiedBuild`=41079 WHERE `id`=63086;

-- Snappy
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=64, `VerifiedBuild`=41079 WHERE `entry`=63085;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=63085 AND `DifficultyID`=0);
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=63085 AND `Idx`=0);
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=32790;

UPDATE `creature` SET `zoneId`=1637, `areaId`=5332, `position_x`=1592.4774169921875, `position_y`=-4147.23974609375, `position_z`=51.81286239624023437, `orientation`=3.864817619323730468, `spawntimesecs`=120, `curhealth`=118, `VerifiedBuild`=41079 WHERE `id`=63085;

-- Varzok
UPDATE `creature_template` SET `gossip_menu_id`=14991, `minlevel`=60, `VerifiedBuild`=41079 WHERE `entry`=63626;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=63626 AND `DifficultyID`=0);
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=63626 AND `Idx`=0);
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=5705;

DELETE FROM `creature_trainer` WHERE `CreatureId`=63626;
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuID`, `OptionIndex`) VALUES
(63626, 580, 14991, 0);

DELETE FROM `npc_vendor` WHERE `entry`=63626;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(63626, 1, 98715, 0, 4292, 1, 0, 0, 41079),
(63626, 2, 98715, 0, 4293, 1, 0, 0, 41079),
(63626, 3, 98715, 0, 4294, 1, 0, 0, 41079),
(63626, 4, 98715, 0, 4295, 1, 0, 0, 41079),
(63626, 5, 98715, 0, 4296, 1, 0, 0, 41079),
(63626, 6, 98715, 0, 4297, 1, 0, 0, 41079),
(63626, 7, 98715, 0, 4298, 1, 0, 0, 41079),
(63626, 8, 98715, 0, 4299, 1, 0, 0, 41079),
(63626, 9, 98715, 0, 4300, 1, 0, 0, 41079),
(63626, 10, 98715, 0, 4301, 1, 0, 0, 41079);

UPDATE `creature` SET `zoneId`=1637, `areaId`=5170, `position_x`=1799.375, `position_y`=-4420.59228515625, `position_z`=102.8434295654296875, `orientation`=1.095773577690124511, `spawntimesecs`=120, `curhealth`=11791, `VerifiedBuild`=41079 WHERE `id`=63626;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=63626;

DELETE FROM `areatrigger_scripts` WHERE `entry`=8190;
INSERT INTO `areatrigger_scripts` VALUES
(8190, 'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid`=8190 AND `source_type`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=63626 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8190,2,0,1,46,0,100,0,0,0,0,0,0,'',64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Areatrigger 8190 - On trigger - Store invoker in target list 1'),
(8190,2,1,2,61,0,100,0,0,0,0,0,0,'',100,1,0,0,0,0,0,19,63626,20,0,0,0,0,0,0,'Areatrigger 8190 - Event linked - Send stored target 1 to Varzok'),
(8190,2,2,0,61,0,100,0,0,0,0,0,0,'',45,1,1,0,0,0,0,19,63626,20,0,0,0,0,0,0,'Areatrigger 8190 - Event linked - Set data 1 1 on Varzok'),
(63626,0,0,1,38,0,100,0,1,1,0,0,0,'',11,116219,2,0,0,0,0,12,1,0,0,0,0,0,0,0,'Varzok - On data set 1 1 - Cast ''CSA Area Trigger Dummy Timer Aura A'' on invoker'),
(63626,0,1,0,61,0,100,0,0,0,0,0,0,'',1,0,0,1,0,0,0,12,1,0,0,0,0,0,0,0,'Varzok - Event linked - Say text');

DELETE FROM `creature_text` WHERE `CreatureID`=63626;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(63626, 0, 0, 'Interested in catching some rare pets?', 12, 0, 100, 1, 0, 0, 0, 62763, 5, 'Varzok - Random text'),
(63626, 0, 1, 'You look like someone that might be interested in some rare pets?', 12, 0, 100, 1, 0, 0, 0, 62764, 5, 'Varzok - Random text'),
(63626, 0, 2, 'Careful with the scorpion, he may look friendly but he is a beast in battle!', 12, 0, 100, 1, 0, 0, 0, 63546, 5, 'Varzok - Random text');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND SourceEntry=8190 AND SourceId=2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,8190,2,0,6,0,67,0,0,0,0,0,'',' Areatrigger 8190 smart if player is Horde'),
(22,1,8190,2,0,1,0,116219,0,0,1,0,0,'',' Areatrigger 8190 smart requires aura 116219 not applied'),
(22,1,8190,2,0,25,0,125610,0,0,1,0,0,'',' Areatrigger 8190 smart requires spell 125610 not learned');

-- Spider
UPDATE `creature_template` SET `unit_flags`=32768, `VerifiedBuild`=41079 WHERE `entry`=14881;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=14881 AND `DifficultyID`=0);
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=14881 AND `Idx` IN (0,1));
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID` IN (20923,44816);

DELETE FROM `creature` WHERE `guid` IN (@CGUID+5,@CGUID+6) AND `id`=14881;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+5, 14881, 1, 1637, 5170, '0', 0, 0, 0, 0, 1802.060791015625, -4420.94775390625, 104.2365264892578125, 0.783415138721466064, 120, 0, 0, 5, 0, 0, 0, 33024, 0, 41079),
(@CGUID+6, 14881, 1, 1637, 5170, '0', 0, 0, 0, 0, 1798.4930419921875, -4419.73779296875, 102.8904495239257812, 0.783415138721466064, 120, 0, 0, 5, 0, 0, 0, 33024, 0, 41079);

-- Scorpid
UPDATE `creature_template` SET `VerifiedBuild`=41079 WHERE `entry`=15476;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=15476 AND `DifficultyID`=0);
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`CreatureID`=15476 AND `Idx` IN (0,1,2,3));
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID` IN (15470,15471);

DELETE FROM `creature` WHERE `guid` IN (@CGUID+7,@CGUID+8) AND `id`=15476;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+7, 15476, 1, 1637, 5170, '0', 0, 0, 0, 0, 1797.7135009765625, -4420.501953125, 103.904296875, 1.648120641708374023, 120, 0, 0, 5, 0, 0, 0, 256, 0, 41079),
(@CGUID+8, 15476, 1, 1637, 5170, '0', 0, 0, 0, 0, 1800.8541259765625, -4420.65283203125, 102.9233322143554687, 1.084395527839660644, 120, 0, 0, 5, 0, 0, 0, 256, 0, 41079);
