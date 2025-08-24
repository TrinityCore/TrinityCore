SET @OGUID := 7000575;

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 276247, 1643, 8721, 9224, '0', 0, 0, 278.071197509765625, 2242.517333984375, 90.96817779541015625, 4.278735160827636718, -0.41899490356445312, 0.505031585693359375, -0.67096328735351562, 0.34524574875831604, 120, 255, 1, 60568), -- Child-sized Backpack (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@OGUID+1, 276255, 1643, 8721, 9224, '0', 0, 0, 406.9913330078125, 2260.654541015625, 106.410308837890625, 6.202590465545654296, 0.6925811767578125, 0.218840599060058593, -0.64408397674560546, 0.239991605281829833, 120, 255, 0, 60568), -- Is it a Rock? How to Identify Relics (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@OGUID+2, 276254, 1643, 8721, 9224, '0', 0, 0, 375.414947509765625, 2233.9150390625, 105.7968902587890625, 6.242641925811767578, -0.05344390869140625, -0.00926113128662109, -0.02079200744628906, 0.998311400413513183, 120, 255, 0, 60568), -- Beginner's Guide to Archaeology (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@OGUID+3, 276253, 1643, 8721, 9224, '0', 0, 0, 341.217010498046875, 2331.7744140625, 106.2588272094726562, 0, 0, 0, 0, 1, 120, 255, 0, 60568); -- Half-eaten Journal (Area: North Pass Caverns - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (276255 /*Is it a Rock? How to Identify Relics*/, 276251 /*Excavation Inventory*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(276255, 0, 0x204004, 0, 0), -- Is it a Rock? How to Identify Relics
(276251, 0, 0x4, 0, 0); -- Excavation Inventory

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=127015 AND `MenuID`=21542);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(127015, 21542, 60568); -- Thaddeus "Gramps" Rifthold

UPDATE `gossip_menu_option` SET `GossipOptionID`=48123, `VerifiedBuild`=60568 WHERE (`MenuID`=21819 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=47798, `ActionMenuID`=21819, `VerifiedBuild`=60568 WHERE (`MenuID`=21703 AND `OptionID`=0);

-- GameObject loot
DELETE FROM `gameobject_loot_template` WHERE `Entry` IN (76093,76095,76092);
INSERT INTO `gameobject_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(76093, 0, 152677, 100, 1, 1, 0, 1, 1, 'A Beginners Guide to Archaeology'),
(76095, 0, 152685, 100, 1, 1, 0, 1, 1, 'Is it a Rock? How to Identify Relics'),
(76092, 0, 152676, 100, 1, 1, 0, 1, 1, 'Half-eaten Journal');

-- Quest
DELETE FROM `creature_queststarter` WHERE (`id`=127157 AND `quest`=48804);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(127157, 48804, 60568); -- Mistakes Were Made offered by Marcus Howlingdale

DELETE FROM `creature_questender` WHERE (`id`=127157 AND `quest` IN (48793,48792));
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(127157, 48793, 60568), -- The Adventurer's Society ended by Marcus Howlingdale
(127157, 48792, 60568); -- Menace to Society ended by Marcus Howlingdale

DELETE FROM `quest_template_addon` WHERE `ID` = 48804;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(48804, 0, 0, 0, 48793, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Mistakes Were Made offered

-- Child-sized Backpack smart ai
SET @ENTRY := 276247;
UPDATE `gameobject_template` SET `AIName` = 'SmartGameObjectAI' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 1 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 1, 0, 1, 62, 0, 100, 0, 21819, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21819 selected - Gossip player: Close gossip', ''),
(@ENTRY, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 85, 254754, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21819 selected - Gossip player: Cast spell 254754 on self', '');

-- SpawnTracking
DELETE FROM `spawn_tracking_quest_objective` WHERE `QuestObjectiveId` IN (292952,292954,292953,292997);
INSERT INTO `spawn_tracking_quest_objective` (`SpawnTrackingId`, `QuestObjectiveId`, `VerifiedBuild`) VALUES
(1387670,292952,60568), -- Child-sized Backpack
(1387741,292954,60568), -- Is it a Rock? How to Identify Relics
(1387723,292953,60568), -- Beginner's Guide to Archaeology
(1387724,292997,60568); -- Half-eaten Journal

DELETE FROM `spawn_tracking` WHERE (`SpawnType`=1 AND `SpawnId` IN (@OGUID+0,@OGUID+1,@OGUID+2,@OGUID+3));
INSERT INTO `spawn_tracking` (`SpawnTrackingId`, `SpawnType`, `SpawnId`, `QuestObjectiveId`) VALUES
(1387670, 1, @OGUID+0, 292952), -- Child-sized Backpack
(1387741, 1, @OGUID+1, 292954), -- Is it a Rock? How to Identify Relics
(1387723, 1, @OGUID+2, 292953), -- Beginner's Guide to Archaeology
(1387724, 1, @OGUID+3, 292997); -- Half-eaten Journal

DELETE FROM `spawn_tracking_state` WHERE (`SpawnType`=0 AND `SpawnId` IN (@OGUID+0,@OGUID+1,@OGUID+2,@OGUID+3));
INSERT INTO `spawn_tracking_state` (`SpawnType`, `SpawnId`, `State`, `Visible`, `StateSpellVisualId`, `StateAnimId`, `StateAnimKitId`, `StateWorldEffects`) VALUES
(0, @OGUID+0, 0, 1, NULL, NULL, NULL, NULL), -- Child-sized Backpack
(0, @OGUID+0, 1, 1, NULL, NULL, NULL, NULL), -- Child-sized Backpack
(0, @OGUID+0, 2, 0, NULL, NULL, NULL, NULL), -- Child-sized Backpack
(0, @OGUID+1, 0, 1, NULL, NULL, NULL, NULL), -- Is it a Rock? How to Identify Relics
(0, @OGUID+1, 1, 1, NULL, NULL, NULL, NULL), -- Is it a Rock? How to Identify Relics
(0, @OGUID+1, 2, 0, NULL, NULL, NULL, NULL), -- Is it a Rock? How to Identify Relics
(0, @OGUID+2, 0, 1, NULL, NULL, NULL, NULL), -- Beginner's Guide to Archaeology
(0, @OGUID+2, 1, 1, NULL, NULL, NULL, NULL), -- Beginner's Guide to Archaeology
(0, @OGUID+2, 2, 0, NULL, NULL, NULL, NULL), -- Beginner's Guide to Archaeology
(0, @OGUID+3, 0, 1, NULL, NULL, NULL, NULL), -- Half-eaten Journal
(0, @OGUID+3, 1, 1, NULL, NULL, NULL, NULL), -- Half-eaten Journal
(0, @OGUID+3, 2, 0, NULL, NULL, NULL, NULL); -- Half-eaten Journal
