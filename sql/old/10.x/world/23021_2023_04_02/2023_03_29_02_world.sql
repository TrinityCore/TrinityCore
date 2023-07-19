-- Creature Movement data
DELETE FROM `creature_template_movement` WHERE `CreatureId` = 45088;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(45088, 0, 0, 1, 1, 0, 0, NULL);

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (62925,45088));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(62925, 0, 0, 0, 371, 48676),
(45088, 0, 0, 0, 54, 48676);

-- SAI
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (45088, 43254, 43258);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (45088, 43254, 43258) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(45088, 0, 0, 0, 8, 0, 100, 0, 84163, 0, 0, 0, 0, 11, 84170, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnSpellHit 84163 - Cast 84170 - to self'),
(43254, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 11, 84163, 3, 0, 0, 0, 0, 11, 45088, 50, 0, 0, 0, 0, 0, 'OnDeath - Cast Energy Capture - to Deplete Totem (50y)'),
(43258, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 11, 84163, 3, 0, 0, 0, 0, 11, 45088, 50, 0, 0, 0, 0, 0, 'OnDeath - cast Energy Capture - to Deplete Totem (50y)');

-- Condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceGroup` = 1 AND `SourceEntry` = 84163;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 84163, 0, 0, 31, 0, 3, 45088, 0, 0, 0, 0, '', 'Energy Capture - can only Target Deplete Totem (45088)');

-- POIs
DELETE FROM `quest_poi` WHERE (`QuestID`=27136 AND `BlobIndex`=1 AND `Idx1`=6) OR (`QuestID`=27136 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=27136 AND `BlobIndex`=3 AND `Idx1`=4) OR (`QuestID`=27136 AND `BlobIndex`=2 AND `Idx1`=3) OR (`QuestID`=27136 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=27136 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=27136 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(27136, 1, 6, 32, 0, 0, 646, 207, 0, 0, 0, 0, 0, 433784, 0, 48676), -- Elemental Energy
(27136, 0, 5, 32, 0, 0, 646, 207, 0, 0, 0, 0, 0, 458472, 0, 48676), -- Elemental Energy
(27136, 3, 4, 0, 252040, 45091, 646, 207, 0, 7, 0, 0, 0, 0, 0, 48676), -- Elemental Energy
(27136, 2, 3, 0, 252040, 45091, 646, 207, 0, 1, 0, 0, 0, 0, 0, 48676), -- Elemental Energy
(27136, 1, 2, 0, 252040, 45091, 646, 207, 0, 3, 0, 0, 0, 0, 0, 48676), -- Elemental Energy
(27136, 0, 1, 0, 252040, 45091, 646, 207, 0, 1, 0, 0, 0, 0, 0, 48676), -- Elemental Energy
(27136, 0, 0, -1, 0, 0, 646, 207, 0, 1, 0, 0, 0, 0, 0, 48676); -- Elemental Energy

UPDATE `quest_poi` SET `VerifiedBuild`=48676 WHERE (`QuestID`=70197 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=53436 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=53436 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50604 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50604 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50600 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50562 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48641 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48639 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=48639 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=48639 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=42170 AND `BlobIndex`=0 AND `Idx1`=0);
DELETE FROM `quest_poi_points` WHERE (`QuestID`=27136 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=27136 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=27136 AND `Idx1`=4 AND `Idx2`=11) OR (`QuestID`=27136 AND `Idx1`=4 AND `Idx2`=10) OR (`QuestID`=27136 AND `Idx1`=4 AND `Idx2`=9) OR (`QuestID`=27136 AND `Idx1`=4 AND `Idx2`=8) OR (`QuestID`=27136 AND `Idx1`=4 AND `Idx2`=7) OR (`QuestID`=27136 AND `Idx1`=4 AND `Idx2`=6) OR (`QuestID`=27136 AND `Idx1`=4 AND `Idx2`=5) OR (`QuestID`=27136 AND `Idx1`=4 AND `Idx2`=4) OR (`QuestID`=27136 AND `Idx1`=4 AND `Idx2`=3) OR (`QuestID`=27136 AND `Idx1`=4 AND `Idx2`=2) OR (`QuestID`=27136 AND `Idx1`=4 AND `Idx2`=1) OR (`QuestID`=27136 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=27136 AND `Idx1`=3 AND `Idx2`=3) OR (`QuestID`=27136 AND `Idx1`=3 AND `Idx2`=2) OR (`QuestID`=27136 AND `Idx1`=3 AND `Idx2`=1) OR (`QuestID`=27136 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=27136 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=27136 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=27136 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=27136 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=27136 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=27136 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=27136 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=27136 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=27136 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=27136 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=27136 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=27136 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=27136 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(27136, 6, 0, 996, 518, -49, 48676), -- Elemental Energy
(27136, 5, 0, 994, 525, -49, 48676), -- Elemental Energy
(27136, 4, 11, 985, 28, 0, 48676), -- Elemental Energy
(27136, 4, 10, 943, 74, 0, 48676), -- Elemental Energy
(27136, 4, 9, 939, 129, 0, 48676), -- Elemental Energy
(27136, 4, 8, 977, 184, 0, 48676), -- Elemental Energy
(27136, 4, 7, 1011, 210, 0, 48676), -- Elemental Energy
(27136, 4, 6, 1066, 218, 0, 48676), -- Elemental Energy
(27136, 4, 5, 1125, 210, 0, 48676), -- Elemental Energy
(27136, 4, 4, 1167, 159, 0, 48676), -- Elemental Energy
(27136, 4, 3, 1163, 104, 0, 48676), -- Elemental Energy
(27136, 4, 2, 1133, 83, 0, 48676), -- Elemental Energy
(27136, 4, 1, 1062, 36, 0, 48676), -- Elemental Energy
(27136, 4, 0, 1015, 24, 0, 48676), -- Elemental Energy
(27136, 3, 3, 1049, 1010, 0, 48676), -- Elemental Energy
(27136, 3, 2, 1122, 979, 0, 48676), -- Elemental Energy
(27136, 3, 1, 1117, 920, 0, 48676), -- Elemental Energy
(27136, 3, 0, 1055, 857, 0, 48676), -- Elemental Energy
(27136, 2, 5, 623, 363, 0, 48676), -- Elemental Energy
(27136, 2, 4, 653, 481, 0, 48676), -- Elemental Energy
(27136, 2, 3, 688, 621, 0, 48676), -- Elemental Energy
(27136, 2, 2, 781, 548, 0, 48676), -- Elemental Energy
(27136, 2, 1, 781, 483, 0, 48676), -- Elemental Energy
(27136, 2, 0, 694, 351, 0, 48676), -- Elemental Energy
(27136, 1, 5, 1378, 424, 0, 48676), -- Elemental Energy
(27136, 1, 4, 1318, 681, 0, 48676), -- Elemental Energy
(27136, 1, 3, 1368, 851, 0, 48676), -- Elemental Energy
(27136, 1, 2, 1434, 901, 0, 48676), -- Elemental Energy
(27136, 1, 1, 1515, 553, 0, 48676), -- Elemental Energy
(27136, 1, 0, 1454, 382, 0, 48676), -- Elemental Energy
(27136, 0, 0, 996, 521, -49, 48676); -- Elemental Energy
