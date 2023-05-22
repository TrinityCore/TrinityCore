SET @CGUID := 651530;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 89634, 1220, 7334, 7366, '0', 4532, 0, 0, 0, -143.86285400390625, 6415.23193359375, 26.87994575500488281, 0.891245484352111816, 120, 0, 0, 3138, 3801, 0, 0, 0, 0, 46455), -- Nar'thalas Citizen (Area: Ruins of Nar'thalas - Difficulty: 0)
(@CGUID+1, 89634, 1220, 7334, 7366, '0', 4532, 0, 0, 0, -139.085067749023437, 6414.15380859375, 26.64783096313476562, 1.833551764488220214, 120, 0, 0, 3138, 3801, 0, 0, 0, 0, 46455), -- Nar'thalas Citizen (Area: Ruins of Nar'thalas - Difficulty: 0)
(@CGUID+2, 89634, 1220, 7334, 7366, '0', 4532, 0, 0, 0, -145.524307250976562, 6418.03662109375, 26.91436767578125, 0.264467328786849975, 120, 0, 0, 3138, 3801, 0, 0, 0, 0, 46455), -- Nar'thalas Citizen (Area: Ruins of Nar'thalas - Difficulty: 0)
(@CGUID+3, 89634, 1220, 7334, 7366, '0', 4532, 0, 0, 0, -136.277786254882812, 6415.861328125, 27.11276435852050781, 2.443514823913574218, 120, 0, 0, 3138, 3801, 0, 0, 0, 0, 46455); -- Nar'thalas Citizen (Area: Ruins of Nar'thalas - Difficulty: 0)

UPDATE `creature_template` SET `VerifiedBuild`=46455 WHERE `entry` = 89634;

UPDATE `quest_offer_reward` SET `VerifiedBuild`=46455 WHERE `ID` IN (37467, 37486);
UPDATE `quest_details` SET `VerifiedBuild`=46455 WHERE `ID` IN (37467, 37486);

DELETE FROM `creature_queststarter` WHERE (`id`=88867 AND `quest` IN (37467,37486));
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(88867, 37467, 46455), -- The Walk of Shame offered Prince Farondis
(88867, 37486, 46455); -- Nar'thalas Still Suffers offered Prince Farondis

UPDATE `creature_questender` SET `VerifiedBuild`=46455 WHERE (`id`=88890 AND `quest`=37467) OR (`id`=88867 AND `quest`=37486);

UPDATE `quest_template` SET `VerifiedBuild`=46455 WHERE `ID`=37467; -- The Walk of Shame
UPDATE `quest_template` SET `VerifiedBuild`=46455 WHERE `ID`=37486; -- Nar'thalas Still Suffers

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 4532;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4532, 'Cosmetic - See Voices of the Prince Farondis at Ruins of Nar\' thalas');

DELETE FROM `phase_area` WHERE `AreaId` = 7366 AND `PhaseId` = 4532;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7366, 4532, 'See Voices of the Prince Farondis at Ruins of Nar\' thalas');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4532 AND `SourceEntry` = 7366);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4532, 7366, 0, 0, 47, 0, 37486, 2 | 64, 0, 0, 'Apply Phase 4532 if Quest 37486 is completed | rewarded'),
(26, 4532, 7366, 0, 0, 47, 0, 37467, 64, 0, 1, 'Apply Phase 4532 if Quest 37467 is not rewarded');
