SET @CGUID := 7000562;
SET @OGUID := 7000208;

DELETE FROM `phase_name` WHERE `ID`=12858;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12858, 'Cosmetic: Kul Tiran Unlock Questline - Ancient Seedling and Haunted Lumber');

DELETE FROM `phase_area` WHERE `PhaseId`=12858;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9965, 12858, 'Cosmetic: Kul Tiran Unlock Questline - Ancient Seedling and Haunted Lumber - Ulfars Den');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12858));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12858, 0, 0, 0, 48, 0, 388248, 0, 1, '', 0, 'Player have quest objective 388248 == 1'),
(26, 12858, 0, 0, 0, 47, 0, 54731, 66, 0, '', 1, 'Player doesn\'t have Balance in All Things (54731) in state complete, rewarded');

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 149365, 1643, 8721, 9965, '0', 12858, 0, 0, 0, -488.489593505859375, 2723.890625, 280.480316162109375, 0, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847); -- Ancient Seedling (Area: Ulfar's Den - Difficulty: 0) CreateObject1

DELETE FROM `gameobject` WHERE `guid`=@OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 316972, 1643, 8721, 9965, '0', 12858, 0, -488.513885498046875, 2723.861083984375, 279.28173828125, 0, 0, 0, 0, 1, 120, 255, 1, 54847); -- Algerson Lumber Sample (Area: Ulfar's Den - Difficulty: 0) CreateObject1

UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=805306624, `VerifiedBuild`=54847 WHERE (`Entry`=149365 AND `DifficultyID`=0); -- 149365 (Ancient Seedling) - Sessile, CanSwim, Floating
UPDATE `creature_template` SET `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `unit_flags3`=16777216 WHERE `entry`=149365; -- Ancient Seedling

DELETE FROM `creature_template_addon` WHERE `entry` IN (149365);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(149365, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 149365 (Ancient Seedling)

-- 
DELETE FROM `gameobject_template` WHERE `entry` IN (316972 /*Algerson Lumber Sample*/, 316908 /*Empowered Minor Cairne*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(316972, 5, 46177, 'Algerson Lumber Sample', '', '', '', 0.400000005960464477, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54847), -- Algerson Lumber Sample
(316908, 10, 49311, 'Empowered Minor Cairne', 'questinteract', 'Filling Vessel', '', 0.400000005960464477, 1690, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 289438, 0, 0, 0, 168177, 0, 0, 0, 0, 0, 1, 0, 67012, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 517, 54847); -- Empowered Minor Cairne
