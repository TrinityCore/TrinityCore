SET @CGUID := 651526;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 89023, 1220, 7334, 7355, '0', 4369, 0, 0, 2, -4.74305582046508789, 6736.6318359375, 55.67241287231445312, 0.135024935007095336, 120, 0, 0, 15690, 3801, 0, 0, 0, 0, 46455); -- Nightwatcher Idri (Area: Crumbled Palace - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 7685, 0, 0, 3, ''); -- Nightwatcher Idri

UPDATE `creature_questender` SET `VerifiedBuild`=46455 WHERE (`id`=89023 AND `quest`=37733);
UPDATE `quest_offer_reward` SET `VerifiedBuild`=46455 WHERE `ID`=37733;

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 4369;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4369, 'Cosmetic - See Nightwatcher Idri at Crumbled Palace');

DELETE FROM `phase_area` WHERE `AreaId` IN (7355, 7357) AND `PhaseId` = 4369;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7355, 4369, 'See Nightwatcher Idri at Crumbled Palace'),
(7357, 4369, 'See Nightwatcher Idri at Crumbled Palace');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4369 AND `SourceEntry` IN (7355, 7357));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4369, 7355, 0, 0, 47, 0, 37733, 2 | 64, 0, 0, 'Apply Phase 4369 if Quest 37733 is completed | rewarded'),
(26, 4369, 7357, 0, 0, 47, 0, 37733, 2 | 64, 0, 0, 'Apply Phase 4369 if Quest 37733 is completed | rewarded');
