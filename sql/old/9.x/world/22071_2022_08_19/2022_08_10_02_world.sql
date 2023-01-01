-- 
SET @CGUID := 650133;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 103136, 1, 493, 656, '0', 5900, 0, 0, 1, 7673.54443359375, -2387.757080078125, 456.45819091796875, 4.519597530364990234, 120, 0, 0, 3236, 1534, 0, 0, 0, 0, 44908), -- Zen'tabra (Area: Lake Elune'ara - Difficulty: 0)
(@CGUID+1, 103135, 1, 493, 656, '0', 5899, 0, 0, 1, 7683.9052734375, -2410.326416015625, 455.290374755859375, 2.133832216262817382, 120, 0, 0, 3236, 1534, 0, 0, 0, 0, 44908), -- Zen'tabra (Area: Lake Elune'ara - Difficulty: 0)
(@CGUID+2, 103133, 1, 493, 0, '0', 5920, 0, 0, 0, 7405.717285156, -2307.901123046875, 498.89404296875, 5.867860794067382812, 120, 0, 0, 9708, 0, 0, 0, 0, 0, 44908); -- Naralex (Area: 0 - Difficulty: 0) (Auras: 204637 - Meditating)

DELETE FROM `creature_template_addon` WHERE `entry` IN (103133,103135,103136);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(103135, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- 103135 (Zen'tabra)
(103133, 0, 0, 0, 1, 0, 9979, 0, 0, 0, '204637'); -- 103133 (Naralex) - Meditating

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (103133,103135,103136));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(103133, 0, 0, 0, 642, 44908),
(103135, 0, 0, 0, 642, 44908),
(103136, 0, 0, 0, 642, 44908);

UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `VerifiedBuild`=44908 WHERE `entry` IN (103136, 103135); -- Zen'tabra
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `VerifiedBuild`=44908 WHERE `entry`=103133; -- Naralex

DELETE FROM `creature_template_movement` WHERE `CreatureId`=103135;
INSERT INTO `creature_template_movement` (`CreatureId`, `Flight`) VALUES
(103135, 1);

DELETE FROM `gossip_menu` WHERE (`MenuID`=19306 AND `TextID`=28414) OR (`MenuID`=19311 AND `TextID`=28419);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(19306, 28414, 44908), -- 103133 (Naralex)
(19311, 28419, 44908); -- 103136 (Zen'tabra)

DELETE FROM `phase_area` WHERE `PhaseId` IN(5899);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(493, 5899, 'See Zen''tabra Travelform at Lake Elune''ara (Legion Druid Campaign)'); 

DELETE FROM `phase_name` WHERE `ID` IN(5899, 5900, 5920);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(5899, 'See Zen''tabra Travelform at Lake Elune''ara (Legion Druid Campaign)'),
(5900, 'See Zen''tabra at Lake Elune''ara (Legion Druid Campaign)'), -- adding phase is done by serverside areatrigger
(5920, 'See Naralex meditating in Moonglade (Legion Druid Campaign)'); -- adding phase is done by serverside areatrigger

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (5899, 5920));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 5899, 493, 0, 0, 47, 0, 41106, 10, 0, 0, 'Player has Call of the Wilds (41106) in state complete, incomplete'),
(26, 5920, 493, 0, 0, 28, 0, 41106, 0, 0, 1, 'Player hasn\'t completed quest Call of the Wilds (41106) (or completed and rewarded)');
