SET @CGUID := 10006928;
SET @OGUID := 10001971;

SET @NPCTEXTID := 600168;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 252312, 0, 1519, 5390, '0', 0, 0, 0, 0, -8888.87890625, 748.4913330078125, 96.421875, 5.528662681579589843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65655); -- Second Chair Pawdo (Area: The Canals - Difficulty: 0) CreateObject1

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+6;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 576463, 0, 1519, 5390, '0', 0, 0, -8890.484375, 744.89410400390625, 97.33713531494140625, 5.872905254364013671, -0.09283876419067382, -0.4720010757446289, -0.17576217651367187, 0.858896732330322265, 120, 255, 1, 65655), -- Fishing Pole (Area: The Canals - Difficulty: 0) CreateObject1
(@OGUID+1, 576391, 0, 1519, 5390, '0', 0, 0, -8886.06640625, 749.81427001953125, 96.267730712890625, 5.117433547973632812, 0, 0, -0.55042743682861328, 0.834883034229278564, 120, 255, 1, 65655), -- Bookshelf (Area: The Canals - Difficulty: 0) CreateObject1
(@OGUID+2, 576392, 0, 1519, 5390, '0', 0, 0, -8890.515625, 745.0711669921875, 97.15087127685546875, 1.537836670875549316, 0, 0, 0.6953582763671875, 0.718663275241851806, 120, 255, 1, 65655), -- Keg (Area: The Canals - Difficulty: 0) CreateObject1
(@OGUID+3, 576393, 0, 1519, 5390, '0', 0, 0, -8885.951171875, 749.98785400390625, 97.42193603515625, 1.537836670875549316, 0, 0, 0.6953582763671875, 0.718663275241851806, 120, 255, 1, 65655), -- Coil (Area: The Canals - Difficulty: 0) CreateObject1
(@OGUID+4, 576394, 0, 1519, 5390, '0', 0, 0, -8887.591796875, 747.20831298828125, 96.33159637451171875, 5.473936080932617187, 0, 0, -0.39367389678955078, 0.919250190258026123, 120, 255, 1, 65655), -- Table (Area: The Canals - Difficulty: 0) CreateObject1
(@OGUID+5, 576395, 0, 1519, 5390, '0', 0, 0, -8889.20703125, 744.3663330078125, 97.0982208251953125, 1.537836670875549316, 0, 0, 0.6953582763671875, 0.718663275241851806, 120, 255, 1, 65655), -- Chandelier (Area: The Canals - Difficulty: 0) CreateObject1
(@OGUID+6, 576396, 0, 1519, 5390, '0', 0, 0, -8890.51953125, 745.0694580078125, 96.470489501953125, 6.123242378234863281, 0, 0, -0.07988643646240234, 0.996803939342498779, 120, 255, 1, 65655); -- Furniture Cart (Area: The Canals - Difficulty: 0) CreateObject1

-- Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=131, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=252312; -- Second Chair Pawdo

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2145, `VerifiedBuild`=65655 WHERE (`Entry`=252312 AND `DifficultyID`=0); -- 252312 (Second Chair Pawdo) - 

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=252312 AND `MenuID`=40669);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(252312, 40669, 65655); -- Second Chair Pawdo

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 300866, 0, 0, 0, 0, 0, 0, 0, 65655), -- 252312 (Second Chair Pawdo)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 300864, 0, 0, 0, 0, 0, 0, 0, 65655); -- 252312 (Second Chair Pawdo)

DELETE FROM `gossip_menu` WHERE (`MenuID`=40667 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=40669 AND `TextID`=@NPCTEXTID+1);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(40667, @NPCTEXTID+0, 65655), -- 252312 (Second Chair Pawdo)
(40669, @NPCTEXTID+1, 65655); -- 252312 (Second Chair Pawdo)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=40669 AND `OptionID` IN (1,0));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(40669, 138607, 1, 1, 'Show me your wares.', 58437, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 65655), -- OptionBroadcastTextID: 58437 - 90189 - 180077
(40669, 136047, 0, 0, 'Where can I acquire new decor for my house?', 0, 0, 0, 40667, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 65655);

-- Quest
DELETE FROM `quest_details` WHERE `ID`=92572;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(92572, 0, 0, 0, 0, 0, 0, 0, 0, 65655); -- Furniture Favor

DELETE FROM `quest_request_items` WHERE `ID`=92572;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(92572, 0, 0, 0, 0, 'How is your day going? Is it fantastic?', 65655); -- Furniture Favor

DELETE FROM `creature_queststarter` WHERE (`id`=252312 AND `quest`=92572);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(252312, 92572, 65655); -- Furniture Favor offered by Second Chair Pawdo

DELETE FROM `creature_questender` WHERE (`id`=252312 AND `quest`=92572);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(252312, 92572, 65655); -- Furniture Favor ended by Second Chair Pawdo

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID`=100252;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(100252, 1.85767364501953125, 1, 0, 65655);

-- Vendor
DELETE FROM `npc_vendor` WHERE (`entry`=252312 AND `item`=247915 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=252312 AND `item`=247908 AND `ExtendedCost`=10726 AND `type`=1) OR (`entry`=252312 AND `item`=246487 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=252312 AND `item`=246601 AND `ExtendedCost`=10727 AND `type`=1) OR (`entry`=252312 AND `item`=248116 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=252312 AND `item`=256168 AND `ExtendedCost`=7827 AND `type`=1) OR (`entry`=252312 AND `item`=245259 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=252312 AND `item`=245655 AND `ExtendedCost`=10723 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(252312, 10, 247915, 0, 0, 1, 146623, 0, 65655), -- Square Suramar Table
(252312, 9, 247908, 0, 10726, 1, 146623, 0, 65655), -- Nightborne Lantern
(252312, 8, 246487, 0, 0, 1, 146624, 0, 65655), -- Gnomish Tesla Coil
(252312, 7, 246601, 0, 10727, 1, 146624, 0, 65655), -- Bolt Chair
(252312, 6, 248116, 0, 0, 1, 146625, 0, 65655), -- Valdrakken Chandelier
(252312, 5, 256168, 0, 7827, 1, 146625, 0, 65655), -- Draconic Sconce
(252312, 4, 245259, 0, 0, 1, 146626, 0, 65655), -- Small Val'sharah Bookcase
(252312, 3, 245655, 0, 10723, 1, 146626, 0, 65655); -- Filigree Moon Lamp
