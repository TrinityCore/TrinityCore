SET @OGUID := 7000579;

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 276251, 1643, 8721, 9224, '0', 0, 0, 392.260406494140625, 2331.229248046875, 121.2208023071289062, 0.032067839056253433, -0.02906465530395507, -0.06496047973632812, 0.014046669006347656, 0.997365593910217285, 120, 255, 1, 60568), -- Excavation Inventory (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@OGUID+1, 276259, 1643, 8721, 9224, '0', 0, 0, 490.890625, 2392.265625, 131.91070556640625, 0, 0, 0, 0, 1, 120, 255, 0, 60568), -- "Relic of the Makers" (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@OGUID+2, 276258, 1643, 8721, 9224, '0', 0, 0, 426.024322509765625, 2343.73779296875, 121.2100296020507812, 0, 0, 0, 0, 1, 120, 255, 0, 60568), -- "Genuine Titan Disc" (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@OGUID+3, 276257, 1643, 8721, 9224, '0', 0, 0, 403.201385498046875, 2370.057373046875, 122.0657730102539062, 0, 0, 0, 0, 1, 120, 255, 0, 60568); -- "Ancient Potsherds" (Area: North Pass Caverns - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (276257 /*"Ancient Potsherds"*/, 276258 /*"Genuine Titan Disc"*/, 276259 /*"Relic of the Makers"*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(276257, 0, 0x204004, 0, 0), -- "Ancient Potsherds"
(276258, 0, 0x204004, 0, 0), -- "Genuine Titan Disc"
(276259, 0, 0x204004, 0, 0); -- "Relic of the Makers"

-- GameObject loot
DELETE FROM `gameobject_loot_template` WHERE `Entry` IN (76100,76099,76098);
INSERT INTO `gameobject_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(76100, 0, 152704, 100, 1, 1, 0, 1, 1, 'Relic of the Makers'),
(76099, 0, 152703, 100, 1, 1, 0, 1, 1, 'Genuine Titan Disc'),
(76098, 0, 152699, 100, 1, 1, 0, 1, 1, 'Ancient Potsherds');

-- SpawnTracking
DELETE FROM `spawn_tracking_quest_objective` WHERE `QuestObjectiveId` IN (292964,292965,292966);
INSERT INTO `spawn_tracking_quest_objective` (`SpawnTrackingId`, `QuestObjectiveId`, `VerifiedBuild`) VALUES
(1387819,292964,60568), -- "Relic of the Makers"
(1387798,292965,60568), -- "Genuine Titan Disc"
(1387768,292966,60568); -- "Ancient Potsherds"

DELETE FROM `spawn_tracking` WHERE (`SpawnType`=1 AND `SpawnId` IN (@OGUID+1,@OGUID+2,@OGUID+3));
INSERT INTO `spawn_tracking` (`SpawnTrackingId`, `SpawnType`, `SpawnId`, `QuestObjectiveId`) VALUES
(1387819, 1, @OGUID+1, 292964), -- "Relic of the Makers"
(1387798, 1, @OGUID+2, 292965), -- "Genuine Titan Disc"
(1387768, 1, @OGUID+3, 292966); -- "Ancient Potsherds"

DELETE FROM `spawn_tracking_state` WHERE (`SpawnType`=0 AND `SpawnId` IN (@OGUID+0,@OGUID+1,@OGUID+2,@OGUID+3));
INSERT INTO `spawn_tracking_state` (`SpawnType`, `SpawnId`, `State`, `Visible`, `StateSpellVisualId`, `StateAnimId`, `StateAnimKitId`, `StateWorldEffects`) VALUES
(0, @OGUID+1, 0, 1, NULL, NULL, NULL, NULL), -- "Relic of the Makers"
(0, @OGUID+1, 1, 1, NULL, NULL, NULL, NULL), -- "Relic of the Makers"
(0, @OGUID+1, 2, 0, NULL, NULL, NULL, NULL), -- "Relic of the Makers"
(0, @OGUID+2, 0, 1, NULL, NULL, NULL, NULL), -- "Genuine Titan Disc"
(0, @OGUID+2, 1, 1, NULL, NULL, NULL, NULL), -- "Genuine Titan Disc"
(0, @OGUID+2, 2, 0, NULL, NULL, NULL, NULL), -- "Genuine Titan Disc"
(0, @OGUID+3, 0, 1, NULL, NULL, NULL, NULL), -- "Ancient Potsherds"
(0, @OGUID+3, 1, 1, NULL, NULL, NULL, NULL), -- "Ancient Potsherds"
(0, @OGUID+3, 2, 0, NULL, NULL, NULL, NULL); -- "Ancient Potsherds"

-- Quest
DELETE FROM `quest_greeting` WHERE (`ID`=127157 AND `Type`=0);
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(127157, 0, 1, 0, 'I\'m gonna be an explorer!', 60568); -- 127157

DELETE FROM `quest_details` WHERE `ID` IN (48804 /*Mistakes Were Made*/, 48805 /*Research Recovery*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(48804, 1, 0, 0, 0, 0, 0, 0, 0, 60568), -- Mistakes Were Made
(48805, 1, 0, 0, 0, 0, 0, 0, 0, 60568); -- Research Recovery

DELETE FROM `creature_questender` WHERE (`id`=127157 AND `quest`=48805);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(127157, 48805, 60568); -- Research Recovery ended by Marcus Howlingdale

DELETE FROM `gameobject_queststarter` WHERE (`id`=276251 AND `quest`=48805);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(276251, 48805, 60568); -- Research Recovery offered by Excavation Inventory

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 19) AND (`SourceEntry` IN (48805));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(19, 0, 48805, 0, 0, 47, 0, 48792, 64, 0, '', 0, 'Player has Menace to Society (48792) in state rewarded'),
(19, 0, 48805, 0, 1, 47, 0, 48793, 64, 0, '', 0, 'Player has The Adventurer\'s Society (48793) in state rewarded');
