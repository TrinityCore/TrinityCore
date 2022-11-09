SET @CGUID := 651505;

DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 89978, 1220, 7334, 7361, '0', 4465, 0, 0, 0, 1091.826416015625, 6315.43212890625, 121.474365234375, 5.256217002868652343, 120, 0, 0, 3923000, 1534, 0, 0, 0, 0, 46455); -- Projection of Senegos

DELETE FROM `creature_queststarter` WHERE `id`=89978 AND `quest` IN (37861,37960);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(89978, 37861, 46455), -- The Nightborne Prince offered Projection of Senegos
(89978, 37960, 46455); -- Leyline Abuse offered Projection of Senegos

UPDATE `creature_questender` SET `VerifiedBuild`=46455 WHERE `id`=89978 AND `quest` IN (37960, 37861);

UPDATE `quest_details` SET `VerifiedBuild`=46455 WHERE `ID` IN (37861, 37960);

UPDATE `quest_offer_reward` SET `VerifiedBuild`=46455 WHERE `ID` =37960;

UPDATE `quest_template` SET `VerifiedBuild`=46455 WHERE `ID`=37861; -- The Nightborne Prince
UPDATE `quest_template` SET `VerifiedBuild`=46455 WHERE `ID`=37960; -- Leyline Abuse

DELETE FROM `quest_poi` WHERE (`QuestID`=37861 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=37861 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=37861 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=37960 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=37960 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=37960 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=37960 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(37960, 0, 3, 32, 0, 0, 1220, 630, 0, 0, 0, 0, 0, 991938, 0, 46455), -- Leyline Abuse
(37960, 0, 2, 1, 277147, 90389, 1220, 630, 0, 0, 0, 0, 0, 995666, 0, 46455), -- Leyline Abuse
(37960, 0, 1, 0, 277148, 90390, 1220, 630, 0, 0, 0, 0, 0, 995667, 0, 46455), -- Leyline Abuse
(37960, 0, 0, -1, 0, 0, 1220, 630, 0, 0, 0, 0, 0, 991938, 0, 46455); -- Leyline Abuse

DELETE FROM `quest_poi` WHERE (`QuestID`=37861 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=37861 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=37861 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(37861, 0, 2, 32, 0, 0, 1220, 630, 0, 0, 0, 0, 0, 991938, 0, 46455), -- The Nightborne Prince
(37861, 0, 1, 0, 277089, 90267, 1220, 630, 0, 0, 0, 0, 0, 994944, 0, 46455), -- The Nightborne Prince
(37861, 0, 0, -1, 0, 0, 1220, 630, 0, 0, 0, 0, 0, 1173754, 0, 46455); -- The Nightborne Prince

DELETE FROM `quest_poi_points` WHERE (`QuestID`=37861 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=37861 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=37861 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=37960 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=37960 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=37960 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=37960 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(37960, 3, 0, 1092, 6315, 119, 46455), -- Leyline Abuse
(37960, 2, 0, 996, 6087, 93, 46455), -- Leyline Abuse
(37960, 1, 0, 1164, 6005, 86, 46455), -- Leyline Abuse
(37960, 0, 0, 1092, 6315, 119, 46455); -- Leyline Abuse

DELETE FROM `quest_poi_points` WHERE (`QuestID`=37861 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=37861 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=37861 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(37861, 2, 0, 1092, 6315, 119, 46455), -- The Nightborne Prince
(37861, 1, 0, 1251, 6027, 116, 46455), -- The Nightborne Prince
(37861, 0, 0, 1208, 6037, 121, 46455); -- The Nightborne Prince

DELETE FROM `phase_name` WHERE `ID` = 4465;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4465, 'Cosmetic - See Projection of Senegos in Ley-Ruins of Zarkhenar');

DELETE FROM `phase_area` WHERE `AreaId` = 7361 AND `PhaseId` = 4465;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7361, 4465, 'Cosmetic - See Projection of Senegos in Ley-Ruins of Zarkhenar'); -- Ley-Ruins of Zarkhenar Zone

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 4465 AND `SourceEntry` = 7361);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4465, 7361, 0, 0, 47, 0, 37857, 2 | 64, 0, 0, 'Apply Phase 4465 if Quest 37857 is completed | rewarded'),
(26, 4465, 7361, 0, 0, 47, 0, 37862, 8 | 2 | 64, 0, 1, 'Apply Phase 4465 if Quest 37862 is not in progress | completed | rewarded');
