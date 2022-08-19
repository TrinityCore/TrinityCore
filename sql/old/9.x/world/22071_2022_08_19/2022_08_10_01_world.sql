-- 
SET @CGUID := 650132;

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 111109, 1220, 7502, 7506, '0', 7138, 0, 0, 0, -834.359375, 4399.119140625, 737.6126708984375, 4.948559761047363281, 120, 0, 0, 2588, 3801, 0, 0, 0, 0, 44908); -- Emissary Auldbridge (Area: Krasus' Landing - Difficulty: 0)

DELETE FROM `creature_template_addon` WHERE `entry`=111109;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(111109, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''); -- 111109 (Emissary Auldbridge)

UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45 WHERE `entry`=111109; -- Emissary Auldbridge

DELETE FROM `phase_area` WHERE `PhaseId`=7138;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7502, 7138, 'See Emissary Auldbridge, welcoming in Broken Isles Dalaran');

DELETE FROM `phase_name` WHERE `ID`=7138;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(7138, 'See Emissary Auldbridge, welcoming in Broken Isles Dalaran');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (7138));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 7138, 7502, 0, 0, 28, 0, 44663, 0, 0, 0, 'Player has completed quest In the Blink of an Eye (44663) (but not yet rewarded)'),
(26, 7138, 7502, 0, 1, 28, 0, 44184, 0, 0, 0, 'Player has completed quest In the Blink of an Eye (44184) (but not yet rewarded)');
