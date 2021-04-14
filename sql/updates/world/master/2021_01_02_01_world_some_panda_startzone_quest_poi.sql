-- Pandaria Woundering Isle fixes

-- POI FOR QUESTID 29677
DELETE FROM `quest_poi` WHERE `QuestID` = '29677';
DELETE FROM `quest_poi_points` WHERE `QuestID` = '29677';
INSERT INTO `quest_poi`(`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES 
(29677, 0, 0, 0, 251732, 73184, 860, 808, 0, 1, 0, 0, 0, 0, 24330),
(29677, 0, 1, -1, 0, 0, 860, 808, 0, 1, 0, 0, 0, 0, 24330);
INSERT INTO `quest_poi_points`(`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES 
(29677, 0, 0, 947, 2942, 24330),
(29677, 1, 0, 1023, 2883, 24330);

-- POI FOR QUESTID 
DELETE FROM `quest_poi` WHERE `QuestID` = '29666';
DELETE FROM `quest_poi_points` WHERE `QuestID` = '29666';
INSERT INTO `quest_poi`(`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES (29666, 0, 0, 0, 258382, 60411, 860, 808, 0, 1, 0, 0, 0, 0, 24330);
INSERT INTO `quest_poi`(`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES (29666, 0, 1, -1, 0, 0, 860, 808, 0, 7, 0, 0, 0, 0, 24330);
INSERT INTO `quest_poi_points`(`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES 
(29666, 0, 0, 957, 2804, 24330),
(29666, 0, 1, 1010, 2884, 24330),
(29666, 0, 2, 1131, 2964, 24330),
(29666, 0, 3, 1119, 3004, 24330),
(29666, 0, 4, 1100, 3040, 24330),
(29666, 0, 5, 1054, 3082, 24330),
(29666, 0, 6, 947, 3105, 24330),
(29666, 0, 7, 849, 3107, 24330),
(29666, 0, 8, 846, 3043, 24330),
(29666, 0, 9, 834, 2950, 24330),
(29666, 0, 10, 824, 2865, 24330),
(29666, 0, 11, 849, 2810, 24330),
(29666, 1, 0, 1023, 2883, 24330);

-- Fix quest: Raucous Rousing (QuestID: 29772), now it's blizzlike..
DELETE FROM `quest_objectives` WHERE `QuestID` = '29772';
INSERT INTO `quest_objectives`(`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES (264091, 29772, 0, 0, 0, 55546, 1, 0, 0, 0, 'Ring the town gong', 25549);
DELETE FROM `gameobject_template` WHERE `entry` = '209626';
INSERT INTO `gameobject_template`(`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES (209626, 10, 11042, 'Break Gong', '', '', '', 0.85, 0, 29772, 0, 3000, 0, 1, 3000, 0, 0, 0, 104012, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 20886);

--
DELETE FROM `quest_poi` WHERE `QuestID` = '29776';
DELETE FROM `quest_poi_points` WHERE `QuestID` = '29776';
INSERT INTO `quest_poi`(`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES (29776, 1, 0, -1, 0, 0, 860, 808, 0, 1, 0, 0, 0, 0, 24330);
INSERT INTO `quest_poi_points`(`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES (29776, 0, 0, 1132, 4152, 24330);

-- invisible npc.. Fix issue: https://www.bfacore.com/d/1051-battle-for-the-skies
UPDATE `creature` SET `PhaseId` = '536' WHERE `guid` = '21001468';

-- DONT need SAI anymore
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` = '55586';
DELETE FROM `smart_scripts` WHERE `entryorguid` = 55586;

-- Another quest poi
DELETE FROM `quest_poi` WHERE `QuestID` = '29787';
DELETE FROM `quest_poi_points` WHERE `QuestID` = '29787';
INSERT INTO `quest_poi`(`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES (29787, 0, 0, -1, 0, 0, 860, 808, 0, 1, 0, 0, 0, 0, 24330);
INSERT INTO `quest_poi`(`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES (29787, 0, 1, 0, 264044, 56274, 860, 808, 0, 1, 0, 0, 0, 0, 24330);
INSERT INTO `quest_poi_points`(`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES (29787, 0, 0, 884, 4463, 24330);
INSERT INTO `quest_poi_points`(`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES (29787, 1, 0, 846, 4375, 24330);

