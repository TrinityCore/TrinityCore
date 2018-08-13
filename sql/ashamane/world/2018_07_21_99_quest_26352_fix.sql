UPDATE `creature_loot_template`
SET `Chance` = 15
WHERE (`Entry` = 515 AND `Item` = 1357);

UPDATE `creature_loot_template`
SET `Chance` = 15
WHERE (`Entry` = 126 AND `Item` = 1357);

UPDATE `creature_loot_template`
SET `Chance` = 11
WHERE (`Entry` = 456 AND `Item` = 1357);

UPDATE `creature_loot_template`
SET `Chance` = 4
WHERE (`Entry` = 127 AND `Item` = 1357);

UPDATE `creature_loot_template`
SET `Chance` = 4
WHERE (`Entry` = 391 AND `Item` = 1357);


-- fix up quest markers
DELETE FROM quest_poi
WHERE QuestID IN (26354,26355,26356);

DELETE FROM quest_poi_points
WHERE QuestID IN (26354,26355,26356);

INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES
(26354, 1, 0, -10514, 2110, 25881), -- Captain Sanders' Hidden Treasure
(26354, 0, 0, -10515, 1599, 25881), -- Captain Sanders' Hidden Treasure
(26355, 1, 0, -10515, 1599, 25881), -- Captain Sanders' Hidden Treasure
(26355, 0, 0, -9797, 1595, 25881), -- Captain Sanders' Hidden Treasure
(26356, 1, 0, -9797, 1595, 25881), -- Captain Sanders' Hidden Treasure
(26356, 0, 0, -9794, 2108, 25881); -- Captain Sanders' Hidden Treasure


INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `WorldMapAreaId`, `Floor`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `WoDUnk1`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(26354, 0, 1, 32, 0, 0, 0, 39, 0, 0, 0, 0, 0, 0, 0, 25881), -- Captain Sanders' Hidden Treasure
(26354, 0, 0, -1, 0, 0, 0, 39, 0, 0, 1, 0, 0, 0, 0, 25881), -- Captain Sanders' Hidden Treasure
(26355, 0, 1, 32, 0, 0, 0, 39, 0, 0, 0, 0, 0, 0, 0, 25881), -- Captain Sanders' Hidden Treasure
(26355, 0, 0, -1, 0, 0, 0, 39, 0, 0, 1, 0, 0, 0, 0, 25881), -- Captain Sanders' Hidden Treasure
(26356, 0, 1, 32, 0, 0, 0, 39, 0, 0, 0, 0, 0, 0, 0, 25881), -- Captain Sanders' Hidden Treasure
(26356, 0, 0, -1, 0, 0, 0, 39, 0, 0, 1, 0, 0, 0, 0, 25881); -- Captain Sanders' Hidden Treasure
