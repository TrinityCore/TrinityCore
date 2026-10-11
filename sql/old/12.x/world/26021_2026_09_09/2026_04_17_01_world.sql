SET @CGUID := 11000752;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 240523, 0, 15969, 16333, '0', 0, 0, 0, 0, 8457.0634765625, -4616.673828125, 48.38300704956054687, 4.704249858856201171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Scouting Map (Area: Sanctum of Light - Difficulty: 0) CreateObject1 (Auras: 1235365 - Quest Bang - Zone Choice Map)
(@CGUID+1, 244550, 0, 15969, 16333, '0', 0, 0, 0, 0, 8457.0634765625, -4616.673828125, 48.38300704956054687, 4.704249858856201171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Scouting Map (Area: Sanctum of Light - Difficulty: 0) CreateObject1
(@CGUID+2, 235787, 0, 15969, 16333, '0', 27428, 0, 0, 1, 8457.0390625, -4610.58154296875, 48.33489227294921875, 1.693117976188659667, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838); -- Lor'themar Theron (Area: Sanctum of Light - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (240523,235787);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(240523, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1235365'), -- 240523 (Scouting Map) - Quest Bang - Zone Choice Map
(235787, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- 235787 (Lor'themar Theron)

-- Template
UPDATE `creature_template` SET `faction`=190, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x4000800, `unit_flags3`=0x41008000 WHERE `entry`=244550; -- Scouting Map
UPDATE `creature_template` SET `faction`=190, `npcflag`=1, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x4000800, `unit_flags3`=0x41000000 WHERE `entry`=240523; -- Scouting Map
UPDATE `creature_template` SET `faction`=3526, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x4800 WHERE `entry`=235787; -- Lor'themar Theron

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3321, `StaticFlags1`=0x20000100, `VerifiedBuild`=66838 WHERE (`Entry`=244550 AND `DifficultyID`=0); -- 244550 (Scouting Map) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3321, `StaticFlags1`=0x20000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=66838 WHERE (`Entry`=240523 AND `DifficultyID`=0); -- 240523 (Scouting Map) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3313, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=235787 AND `DifficultyID`=0); -- 235787 (Lor'themar Theron) - CanSwim

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 27428;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(27428, 'Cosmetic - Lor''themar Theron at the Sanctum of Light');

DELETE FROM `phase_area` WHERE `PhaseId` = 27428;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(15969, 27428, 'Lor''themar Theron at the Sanctum of Light');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=240523 AND `MenuID`=38539);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(240523, 38539, 66838); -- Scouting Map

DELETE FROM `gossip_menu` WHERE (`MenuID`=38539 AND `TextID`=34568);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(38539, 34568, 66838); -- 240523 (Scouting Map)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=38539 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(38539, 132746, 0, 31, 'Show me what missions you have prepared.', 95541, 0, 0, 0, 0, 58756, 0, 0, NULL, 0, NULL, NULL, 66838); -- OptionBroadcastTextID: 95541 - 96633 - 98823

-- Quest
DELETE FROM `quest_offer_reward` WHERE `ID`=94993;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(94993, 0, 0, 0, 0, 0, 0, 0, 0, 'You have embarked on a campaign chapter using the Scouting Map. You may return to the Sanctum of Light to make another selection.', 66838); -- Adventuring in Midnight

DELETE FROM `quest_details` WHERE `ID`=94993;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(94993, 0, 0, 0, 0, 0, 0, 0, 0, 66838); -- Adventuring in Midnight

UPDATE `quest_poi` SET `VerifiedBuild`=66838 WHERE (`QuestID`=89402 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=89402 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=94993 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=56119 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=56119 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50605 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50601 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48639 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=48639 AND `BlobIndex`=3 AND `Idx1`=2) OR (`QuestID`=48639 AND `BlobIndex`=2 AND `Idx1`=1) OR (`QuestID`=48639 AND `BlobIndex`=1 AND `Idx1`=0) OR (`QuestID`=43179 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48641 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48641 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=53436 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=53436 AND `BlobIndex`=0 AND `Idx1`=0);

UPDATE `quest_poi_points` SET `VerifiedBuild`=66838 WHERE (`QuestID`=89402 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=89402 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=94993 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=56119 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=56119 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50605 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50601 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48639 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=48639 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48639 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48639 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=43179 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48641 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48641 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=53436 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=53436 AND `Idx1`=0 AND `Idx2`=0);

DELETE FROM `quest_details` WHERE `ID`=89402;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(89402, 0, 0, 0, 0, 0, 0, 0, 0, 66838); -- Harandar
