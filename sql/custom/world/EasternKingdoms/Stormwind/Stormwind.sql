-- Stormwind changes and updates

-- NPC: 332 Master Mathias Shaw
-- NPC: 352 Dungar Longdrink
-- NPC: 914 Ander Germaine
-- NPC: 1323 Osric Strang
-- NPC: 1646 Baros Alexton
-- NPC: 5566 Tannysa
-- NPC: 6089 Harry Burlguard
-- NPC: 6122 Gakin
-- NPC: 6579 Shoni the Shilent
-- NPC: 49540 Stormwind Rat

-- Quest: 389 Bazil Thredd
-- Quest: 399 Humble Beginnings
-- Quest: 1666 Marshal Haggard
-- Quest: 1688 Surena Caledon
-- Quest: 1861 Mirror Lake
-- Quest: 2206 Snatch and Grab
-- Quest: 2040 Underground Assault
-- Quest: 2041 Speak with Shoni
-- Quest: 6261 Dungar Longdrink
-- Quest: 6285 Return to Lewis

-- Reactivating old/deprecated quests in Stormwind
DELETE FROM `disables` where `sourceType` = 1 AND `entry` IN (389,399, 1861, 1666, 1688, 2040,2041,2206,6261, 6285);

-- Quest starters and enders
DELETE FROM `creature_queststarter` WHERE `quest` IN (389,399,1666, 1688, 1861, 2040,2041,2206,6261, 6285);
DELETE FROM `creature_questender` WHERE `quest` IN (399,1666, 1688, 1861, 2206, 6261, 6285);

INSERT INTO `creature_queststarter` VALUES
(1646, 389,0),
(352, 6285, 0),
(1323, 6261, 0),
(6579, 2040, 0),
(6569, 2041, 0),
(332, 2206, 0),
(1646, 399, 0),
(6089, 1666, 0),
(6122, 1688, 0),
(5497, 1861, 0);

INSERT INTO `creature_questender` VALUES
(491, 6285, 0),
(352, 6261, 0),
(332, 2206, 0),
(1646, 399, 0),
(294, 1666, 0),
(6122, 1688, 0),
(5497, 1861, 0);

-- Quest Templates
UPDATE `quest_template` SET `ContentTuningID` = '73', `QuestSortID` = '12', `AllowableRaces` = '18446744073709551615', `Expansion` = '0', `RewardFactionID1` = '72', `RewardFactionValue1` = '1', `RewardFactionFlags` = '1' WHERE (`ID` = '1666');
UPDATE `quest_template_addon` SET `AllowableClasses` = '0', `PrevQuestID` = '0' WHERE (`ID` = '1666');
UPDATE `quest_template` SET `ContentTuningID` = '73', `QuestSortID` = '12', `AllowableRaces` = '18446744073709551615', `Expansion` = '0', `RewardFactionID1` = '72', `RewardFactionValue1` = '1', `RewardFactionFlags` = '1' WHERE (`ID` = '1688');
UPDATE `quest_template` SET `ContentTuningID` = '73', `QuestSortID` = '12', `AllowableRaces` = '18446744073709551615', `Expansion` = '0' WHERE `ID` IN (1861, 2206);
UPDATE `quest_template_addon` SET `AllowableClasses` = '0' WHERE `ID` IN (1688, 1861, 2206);
UPDATE `quest_template` SET `ContentTuningID` = '6', `Expansion` = '0' WHERE `ID` IN (399, 6261, 6285);

UPDATE `quest_template` SET `ContentTuningID` = 202, `Expansion` = 0 WHERE `ID` = 389;
UPDATE `quest_template` SET `ContentTuningID` = 202, `Expansion` = 0 WHERE `ID` = 2040;
UPDATE `quest_template` SET `ContentTuningID` = 6, `Expansion` = 0 WHERE `ID` = 2041;

-- Gameobjects
SET @OGUID := 900000;
DELETE FROM `gameobject` WHERE `guid` IN (@OGUID+0); -- spell focus object for Mirror Lake Quest
INSERT INTO `gameobject` VALUES
(@OGUID+0, 102414, 0, 12, 92, 0, 0, 0, 0, -1, -9358.1, 559.318, 61.5671, 3.06084, 0, 0, -0.999185, -0.0403646, 300, 255, 1, '', '', 0);

-- Creatures
SET @CGUID := 900000;
UPDATE `creature_template_difficulty` SET `ContentTuningID` = '864' WHERE (`Entry` = '914') and (`DifficultyID` = '0');
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+1220 AND @CGUID+1223;
INSERT INTO `creature` VALUES
(@CGUID+0, 914, 0, 1519, 1519, 0, 0, 0, 0, -1, 0, 1, -8795.63, 356.435, 107.27, 6.18479, 300, 0, 0, 100, 0, 0, 0, 0, 0, '', '', 0),

(@CGUID+1220, 43277, 0, 1519, 1519, 0, 0, 0, 0, -1, 0, 1, -8819.89, 346.938, 107.131, 1.62316, 180, 0, 0, 100, 0, 0, 0, 0, 0, '', '', 0),
(@CGUID+1221, 43294, 0, 1519, 1519, 0, 0, 0, 0, -1, 0, 0, -8821.33, 347.102, 107.131, 1.27409, 180, 0, 0, 100, 0, 0, 0, 0, 0, '', '', 0),
(@CGUID+1222, 44247, 0, 1519, 1519, 0, 0, 0, 0, -1, 0, 1, -8820.38, 351.293, 107.132, 5.44543, 180, 0, 0, 100, 0, 0, 0, 0, 0, '', '', 0),
(@CGUID+1223, 44249, 0, 1519, 1519, 0, 0, 0, 0, -1, 0, 1, -8815.72, 350.507, 107.132, 2.96706, 180, 0, 0, 100, 0, 0, 0, 0, 0, '', '', 0);
