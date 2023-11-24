SET @CGUID := 7000030;

DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 121235, 1643, 8717, 8718, '0', 8988, 0, 0, 1, 1051.326416015625, -624.9461669921875, 0.700018584728240966, 0.429101288318634033, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 52129); -- Taelia (Area: Tradewinds Market - Difficulty: 0) CreateObject1

DELETE FROM `creature_template_addon` WHERE `entry` IN (121235 /*121235 (Taelia)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(121235, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- 121235 (Taelia)

UPDATE `creature_template` SET `npcflag`=281474976710659 WHERE `entry`=121235; -- Taelia

DELETE FROM `creature_queststarter` WHERE (`id`=121235 AND `quest`=47099);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(121235, 47099, 52129); -- Get Your Bearings offered Taelia

-- Phasing
DELETE FROM `phase_name` WHERE `ID` = 8988;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(8988, 'Cosmetic - Taelia (Boralus intro)');

DELETE FROM `phase_area` WHERE `PhaseId` = 8988 AND `AreaId` = 8718;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(8718, 8988, 'See Taelia at Tradewinds Market');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=8988 AND `SourceEntry` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 8988, 0, 0, 0, 47, 0, 47099, 2 | 8 | 64, 0, 1, 0, 0, '', 'Apply Phase 8988 if quest 47099 is not taken | complete | rewarded');

-- Gossip
UPDATE `gossip_menu` SET `VerifiedBuild`=52129 WHERE (`MenuID`=21307 AND `TextID`=32364);

DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=121235 AND `MenuID`=21307);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(121235, 21307, 52129); -- Taelia

-- Quest
UPDATE `quest_poi` SET `VerifiedBuild`=52129 WHERE (`QuestID`=47099 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=47099 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=47099 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47099 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47099 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=52129 WHERE (`QuestID`=47099 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=47099 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=47099 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47099 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47099 AND `Idx1`=0 AND `Idx2`=0);
UPDATE `quest_details` SET `VerifiedBuild`=52129 WHERE `ID`=47099;
