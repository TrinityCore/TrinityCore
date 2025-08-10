SET @CGUID := 651509;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 97736, 1220, 7334, 7361, '0', 5261, 0, 0, 1, 1133.782958984375, 6272.19775390625, 109.9548568725585937, 4.251774311065673828, 120, 0, 0, 19615, 100, 0, 0, 0, 0, 46455); -- Baric Stormrunner

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''); -- Baric Stormrunner

UPDATE `creature_template` SET `gossip_menu_id`=18836, `minlevel`=45, `maxlevel`=45, `VerifiedBuild`=46455 WHERE `entry`=97736; -- Baric Stormrunner

UPDATE `gossip_menu` SET `VerifiedBuild`=46455 WHERE (`MenuID`=18836 AND `TextID`=27440);

DELETE FROM `creature_queststarter` WHERE `id`=97736 AND `quest` IN (39938,39937);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(97736, 39938, 46455), -- Containing the Demon Within offered Baric Stormrunner
(97736, 39937, 46455); -- Opposites Repel offered Baric Stormrunner

UPDATE `creature_questender` SET `VerifiedBuild`=46455 WHERE `id`=97736 AND `quest` IN (39937,39936);

-- Quests
UPDATE `quest_template` SET `VerifiedBuild`=46455 WHERE `ID`=39938; -- Containing the Demon Within
UPDATE `quest_template` SET `VerifiedBuild`=46455 WHERE `ID`=39937; -- Opposites Repel

DELETE FROM `quest_offer_reward` WHERE `ID` = 39937;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(39937, 1, 1, 0, 0, 0, 0, 0, 0, 'If you can believe it, that was the easy part. The next part will be a bit more challenging$b$b...at least, for me it will.', 46455); -- Opposites Repel

UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=46455 WHERE `Idx`=0 AND `QuestID` = 39938;

UPDATE `quest_poi` SET `VerifiedBuild`=46455 WHERE (`QuestID`=39938 AND `BlobIndex`=1 AND `Idx1`=6) OR (`QuestID`=39938 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=39938 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=39938 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=39938 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=39938 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=39938 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=39937 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=39937 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=39937 AND `BlobIndex`=0 AND `Idx1`=0);

UPDATE `quest_poi_points` SET `VerifiedBuild`=46455 WHERE (`QuestID`=39938 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=39938 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=39938 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=39938 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=39938 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=39938 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=39938 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=39937 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=39937 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=39937 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=39937 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=39937 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=39937 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=39937 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=39937 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=39937 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=39937 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=39937 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=39937 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=39937 AND `Idx1`=0 AND `Idx2`=0);

DELETE FROM `quest_details` WHERE `ID` IN (39938, 39937);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(39938, 1, 1, 0, 0, 0, 0, 0, 0, 46455), -- Containing the Demon Within
(39937, 1, 1, 0, 0, 0, 0, 0, 0, 46455); -- Opposites Repel

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 5261;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(5261, 'Cosmetic - See Baric Stormrunner');

DELETE FROM `phase_area` WHERE `AreaId` = 7361 AND `PhaseId` = 5261;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7361, 5261, 'See Baric Stormrunner in Ley-Ruins of Zarkhenar');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 5261  AND `SourceEntry` = 7361);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 5261, 7361, 0, 0, 48, 0, 280166, 0, 1, 1, 'Apply Phase 5261 if player has no quest objective done: Start the Ritual'),
(26, 5261, 7361, 0, 0, 47, 0, 39938, 2 | 64, 0, 1, 'Apply Phase 5261 if Quest 39938 is not completed | rewarded');
