SET @CGUID := 1051903;
SET @CONDREF := -1;

-- Creature templates
UPDATE `creature_template` SET `minlevel`=63, `maxlevel`=63 WHERE `entry`=175135; -- Rokhan

DELETE FROM `creature_template_addon` WHERE `entry`=175135;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(175135, 0, 0, 0, 257, 0, 0, 0, 0, 3, ''); -- 175135 (Rokhan)

-- Gossips
UPDATE `gossip_menu` SET `VerifiedBuild`=46597 WHERE `MenuID`=26685 AND `TextID`=42407;

UPDATE `npc_text` SET `Probability0`=1 WHERE `ID`=42407;

-- Scaling
DELETE FROM `creature_template_scaling` WHERE `DifficultyID`=1 AND `Entry`=175135;

-- Phases
DELETE FROM `phase_name` WHERE `ID`=16786;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(16786, 'Cosmetic - Orgrimmar - Grommash Hold - See Rokhan');

DELETE FROM `phase_area` WHERE `PhaseId`=16786;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(5170, 16786, 'Orgrimmar - Valley of Strength: Cosmetic - Orgrimmar - Valley of Strength - See Rokhan'),
(5356, 16786, 'Orgrimmar - Grommash Hold: Cosmetic - Orgrimmar - Grommash Hold - See Rokhan');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=16786;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` BETWEEN @CONDREF-2 AND @CONDREF-0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 16786, 0, 0, 0, @CONDREF-0, 0, 0, 0, 0, 0, 'Apply phase 16786 if condition reference 1 is fullfilled'),
(26, 16786, 0, 0, 0, @CONDREF-1, 0, 0, 0, 0, 0, 'Apply phase 16786 if condition reference 2 is fullfilled'),
(26, 16786, 0, 0, 0, @CONDREF-2, 0, 0, 0, 0, 0, 'Apply phase 16786 if condition reference 3 is fullfilled'),
(@CONDREF-0, 0, 0, 0, 0, 47, 0, 60359, 64, 0, 1, 'Apply condition reference if quest 60359 is not rewarded'),
(@CONDREF-0, 0, 0, 0, 1, 47, 0, 60361, 64, 0, 0, 'Apply condition reference if quest 60361 is rewarded'),
(@CONDREF-1, 0, 0, 0, 0, 47, 0, 51443, 2 | 8, 0, 1, 'Apply condition reference if quest 51443 is not taken | complete'),
(@CONDREF-2, 0, 0, 0, 0, 47, 0, 29611, 1, 0, 0, 'Apply condition reference if quest 29611 is not taken | complete | rewarded'),
(@CONDREF-2, 0, 0, 0, 0, 47, 0, 29612, 1, 0, 0, 'Apply condition reference if quest 29612 is not taken | complete | rewarded'),
(@CONDREF-2, 0, 0, 0, 0, 47, 0, 49852, 1, 0, 0, 'Apply condition reference if quest 49852 is not taken | complete | rewarded'),
(@CONDREF-2, 0, 0, 0, 0, 47, 0, 49538, 1, 0, 0, 'Apply condition reference if quest 49538 is not taken | complete | rewarded'),
(@CONDREF-2, 0, 0, 0, 0, 47, 0, 60126, 1, 0, 0, 'Apply condition reference if quest 60126 is not taken | complete | rewarded'),
(@CONDREF-2, 0, 0, 0, 1, 47, 0, 31853, 64, 0, 0, 'Apply condition reference if quest 31853 is rewarded');

-- Creature spawns
DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 175135, 1, 1637, 5356, '0', 16786, 0, 0, 1, 1664.267333984375, -4345.51416015625, 26.37074661254882812, 3.670068740844726562, 120, 0, 0, 4421750, 262000, 0, 0, 0, 0, 46549); -- Rokhan (Area: Valley of Strength - Difficulty: 0)
