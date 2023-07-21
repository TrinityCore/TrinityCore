SET @MOP_CGUID := 397101;
SET @WOD_CGUID := 460992;
SET @WOD_OGUID := 395740;
SET @BFA_CGUID := 850951;
SET @SL_CGUID := 1052024;

-- Creature (Mists of Pandaria)
DELETE FROM `creature` WHERE `guid` BETWEEN @MOP_CGUID+0 AND @MOP_CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@MOP_CGUID+0, 68491, 974, 5861, 5902, '0', 0, 0, 0, 0, -3632.154541015625, 6310.541015625, 113.3639755249023437, 1.543435573577880859, 120, 0, 0, 112919, 0, 0, 0, 0, 50000), -- Darkmoon Strider (Area: Darkmoon Path - Difficulty: 0) CreateObject1
(@MOP_CGUID+1, 68491, 974, 5861, 5902, '0', 0, 0, 0, 0, -3628.46875, 6309.486328125, 113.27227783203125, 0.859974145889282226, 120, 0, 0, 112919, 0, 0, 0, 0, 50000), -- Darkmoon Strider (Area: Darkmoon Path - Difficulty: 0) CreateObject1
(@MOP_CGUID+2, 68492, 974, 5861, 5902, '0', 0, 0, 0, 1, -3630.217041015625, 6310.87060546875, 113.27679443359375, 0.493794798851013183, 120, 0, 0, 112919, 0, 0, 0, 0, 50000); -- "Dusty" Brandom (Area: Darkmoon Path - Difficulty: 0) CreateObject1

-- Creature (Warlords of Dreanor)
DELETE FROM `creature` WHERE `guid` BETWEEN @WOD_CGUID+0 AND @WOD_CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@WOD_CGUID+0, 85484, 974, 5861, 5870, '0', 0, 0, 0, 1, -4253.32275390625, 6311.42626953125, 13.59742927551269531, 1.876229405403137207, 120, 0, 0, 752041, 0, 0, 0, 0, 50000), -- Chester (Area: The Darkmoon Faire - Difficulty: 0) CreateObject1
(@WOD_CGUID+1, 85546, 974, 5861, 5870, '0', 0, 0, 0, 0, -4207.55029296875, 6369.76025390625, 13.17307472229003906, 4.783827781677246093, 120, 0, 0, 112919, 0, 0, 0, 0, 50000); -- Ziggie Sparks (Area: The Darkmoon Faire - Difficulty: 0) CreateObject1

DELETE FROM `gameobject` WHERE `guid` = @WOD_OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@WOD_OGUID+0, 235370, 974, 5861, 5870, '0', 0, 0, -4253.20849609375, 6311.08935546875, 13.11676788330078125, 1.906480908393859863, 0, 0, 0.815296173095703125, 0.579044163227081298, 120, 255, 1, 50000); -- Medium Crate (Area: The Darkmoon Faire - Difficulty: 0) CreateObject1

-- Creature (Battle for Azeroth)
DELETE FROM `creature` WHERE `guid` = @BFA_CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@BFA_CGUID+0, 149540, 974, 5861, 5902, '0', 0, 0, 0, 1, -4050.470458984375, 6252.517578125, 18.06995582580566406, 1.43361210823059082, 120, 0, 0, 112919, 0, 0, 0, 0, 50000); -- Mae Ti (Area: Darkmoon Path - Difficulty: 0) CreateObject1

-- Creature (Shadowlands)
DELETE FROM `creature` WHERE `guid` BETWEEN @SL_CGUID+0 AND @SL_CGUID+19;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@SL_CGUID+0, 181127, 974, 5861, 5870, '0', 0, 0, 0, 0, -4219.47802734375, 6267.255859375, 15.07441329956054687, 3.081998109817504882, 120, 0, 0, 112919, 0, 0, 0, 0, 50000), -- Dance Enthusiast (Area: The Darkmoon Faire - Difficulty: 0) CreateObject1
(@SL_CGUID+1, 181127, 974, 5861, 5870, '0', 0, 0, 0, 0, -4235.8154296875, 6272.35693359375, 15.062286376953125, 5.206719875335693359, 120, 0, 0, 112919, 0, 0, 0, 0, 50000), -- Dance Enthusiast (Area: The Darkmoon Faire - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@SL_CGUID+2, 181127, 974, 5861, 5870, '0', 0, 0, 0, 0, -4246.28466796875, 6327.34619140625, 11.10589504241943359, 5.123575687408447265, 120, 0, 0, 112919, 0, 0, 0, 0, 50000), -- Dance Enthusiast (Area: The Darkmoon Faire - Difficulty: 0) CreateObject1
(@SL_CGUID+3, 181124, 974, 5861, 5870, '0', 0, 0, 0, 0, -4245.4150390625, 6323.5, 11.87079811096191406, 4.886465072631835937, 120, 0, 0, 112919, 0, 0, 0, 0, 50000), -- Dance Enthusiast (Area: The Darkmoon Faire - Difficulty: 0) CreateObject1
(@SL_CGUID+4, 181126, 974, 5861, 5870, '0', 0, 0, 0, 0, -4248.39404296875, 6324.3916015625, 11.6595001220703125, 5.255956172943115234, 120, 0, 0, 112919, 0, 0, 0, 0, 50000), -- Dance Enthusiast (Area: The Darkmoon Faire - Difficulty: 0) CreateObject1
(@SL_CGUID+5, 181097, 974, 5861, 5870, '0', 0, 0, 0, 0, -4240.0087890625, 6312.4853515625, 15.14873218536376953, 2.109357357025146484, 120, 0, 0, 112919, 0, 0, 0, 0, 50000), -- Simon Sezdans (Area: The Darkmoon Faire - Difficulty: 0) CreateObject1
(@SL_CGUID+6, 181124, 974, 5861, 5870, '0', 0, 0, 0, 0, -4243.1494140625, 6325.931640625, 11.60040283203125, 4.775434494018554687, 120, 0, 0, 112919, 0, 0, 0, 0, 50000), -- Dance Enthusiast (Area: The Darkmoon Faire - Difficulty: 0) CreateObject1
(@SL_CGUID+7, 181127, 974, 5861, 5870, '0', 0, 0, 0, 0, -4239.10791015625, 6325.01806640625, 12.13327217102050781, 4.594147682189941406, 120, 0, 0, 112919, 0, 0, 0, 0, 50000), -- Dance Enthusiast (Area: The Darkmoon Faire - Difficulty: 0) CreateObject1
(@SL_CGUID+8, 181124, 974, 5861, 5870, '0', 0, 0, 0, 0, -4241.94091796875, 6323.72998046875, 12.17828273773193359, 4.70375680923461914, 120, 0, 0, 112919, 0, 0, 0, 0, 50000), -- Dance Enthusiast (Area: The Darkmoon Faire - Difficulty: 0) CreateObject1
(@SL_CGUID+9, 181126, 974, 5861, 5870, '0', 0, 0, 0, 0, -4249.8974609375, 6326.3271484375, 11.33077430725097656, 5.26937103271484375, 120, 0, 0, 112919, 0, 0, 0, 0, 50000), -- Dance Enthusiast (Area: The Darkmoon Faire - Difficulty: 0) CreateObject1
(@SL_CGUID+10, 181127, 974, 5861, 5870, '0', 0, 0, 0, 0, -4253.9775390625, 6323.06591796875, 11.96375656127929687, 5.593091964721679687, 120, 0, 0, 112919, 0, 0, 0, 0, 50000), -- Dance Enthusiast (Area: The Darkmoon Faire - Difficulty: 0) CreateObject1
(@SL_CGUID+11, 181127, 974, 5861, 5870, '0', 0, 0, 0, 0, -4247.048828125, 6320.44091796875, 12.25020027160644531, 5.419839382171630859, 120, 0, 0, 112919, 0, 0, 0, 0, 50000), -- Dance Enthusiast (Area: The Darkmoon Faire - Difficulty: 0) CreateObject1
(@SL_CGUID+12, 181125, 974, 5861, 5870, '0', 0, 0, 0, 0, -4252.26025390625, 6317.455078125, 12.90359020233154296, 6.025897979736328125, 120, 0, 0, 112919, 0, 0, 0, 0, 50000), -- Dance Enthusiast (Area: The Darkmoon Faire - Difficulty: 0) CreateObject1
(@SL_CGUID+13, 181127, 974, 5861, 5870, '0', 0, 0, 0, 0, -4254.45166015625, 6320.02783203125, 12.58815956115722656, 5.849483966827392578, 120, 0, 0, 112919, 0, 0, 0, 0, 50000), -- Dance Enthusiast (Area: The Darkmoon Faire - Difficulty: 0) CreateObject1
(@SL_CGUID+14, 181125, 974, 5861, 5870, '0', 0, 0, 0, 0, -4249.484375, 6318.220703125, 12.48281097412109375, 5.980894088745117187, 120, 0, 0, 112919, 0, 0, 0, 0, 50000), -- Dance Enthusiast (Area: The Darkmoon Faire - Difficulty: 0) CreateObject1
(@SL_CGUID+15, 181127, 974, 5861, 5870, '0', 0, 0, 0, 0, -4249.3837890625, 6316.20654296875, 12.75157928466796875, 5.961705684661865234, 120, 0, 0, 112919, 0, 0, 0, 0, 50000), -- Dance Enthusiast (Area: The Darkmoon Faire - Difficulty: 0) CreateObject1
(@SL_CGUID+16, 181126, 974, 5861, 5870, '0', 0, 0, 0, 0, -4251.52099609375, 6324.71533203125, 11.6417093276977539, 5.399308681488037109, 120, 0, 0, 112919, 0, 0, 0, 0, 50000), -- Dance Enthusiast (Area: The Darkmoon Faire - Difficulty: 0) CreateObject1
(@SL_CGUID+17, 181125, 974, 5861, 5870, '0', 0, 0, 0, 0, -4251.23974609375, 6320.18408203125, 12.37656974792480468, 5.855760097503662109, 120, 0, 0, 112919, 0, 0, 0, 0, 50000), -- Dance Enthusiast (Area: The Darkmoon Faire - Difficulty: 0) CreateObject1
(@SL_CGUID+18, 181126, 974, 5861, 5870, '0', 0, 0, 0, 0, -4249.796875, 6323.2333984375, 11.82277584075927734, 5.404091835021972656, 120, 0, 0, 112919, 0, 0, 0, 0, 50000), -- Dance Enthusiast (Area: The Darkmoon Faire - Difficulty: 0) CreateObject1
(@SL_CGUID+19, 181127, 974, 5861, 5870, '0', 0, 0, 0, 0, -4198.642578125, 6288.6484375, 15.16339111328125, 1.705774903297424316, 120, 0, 0, 112919, 0, 0, 0, 0, 50000); -- Dance Enthusiast (Area: The Darkmoon Faire - Difficulty: 0) CreateObject2

-- Template data
UPDATE `creature_template` SET `faction`=1555, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry` IN (181125, 181126, 181124, 181127); -- Dance Enthusiast
UPDATE `creature_template` SET `faction`=1555, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=181097; -- Simon Sezdans

DELETE FROM `creature_template_addon` WHERE `entry` = 85484;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(85484, 0, 0, 0, 3, 0, 1, 0, 461, 0, 0, 0, 0, ''); -- Chester

-- NPC spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 68491;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(68491, 134931, 3, 0);

-- Quest data
DELETE FROM `quest_details` WHERE `ID`=64783;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(64783, 0, 0, 0, 0, 0, 0, 0, 0, 50000); -- Dance Dance Darkmoon

UPDATE `quest_details` SET `VerifiedBuild`=50000 WHERE `ID`=36481;

DELETE FROM `quest_request_items` WHERE `ID` IN (36481 /*Firebird's Challenge*/, 64783 /*Dance Dance Darkmoon*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(36481, 0, 1, 0, 0, 'How was the flight?', 50000), -- Firebird's Challenge
(64783, 0, 1, 0, 0, 'Simon says, \"Show me what you got.\"', 50000); -- Dance Dance Darkmoon

DELETE FROM `creature_queststarter` WHERE (`id`=181097 AND `quest`=64783);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(181097, 64783, 50000); -- Dance Dance Darkmoon offered Simon Sezdans

UPDATE `creature_queststarter` SET `VerifiedBuild`=50000 WHERE (`id`=85546 AND `quest`=36481);

DELETE FROM `creature_questender` WHERE (`id`=181097 AND `quest`=64783);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(181097, 64783, 50000); -- Dance Dance Darkmoon ended by Simon Sezdans

UPDATE `creature_questender` SET `VerifiedBuild`=50000 WHERE (`id`=85546 AND `quest`=36481);

-- Gossip & Text data
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=181097 AND `MenuID`=26818) OR (`CreatureID`=68492 AND `MenuID`=15306);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(181097, 26818, 50000), -- Simon Sezdans
(68492, 15306, 50000); -- "Dusty" Brandom

UPDATE `creature_template_gossip` SET `VerifiedBuild`=50000 WHERE (`CreatureID`=85546 AND `MenuID`=16970);

UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=50000 WHERE (`entry`=85484 AND `item`=116134 AND `ExtendedCost`=3813 AND `type`=1); -- Noble's Fancy Boots
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=50000 WHERE (`entry`=85484 AND `item`=116133 AND `ExtendedCost`=3814 AND `type`=1); -- Nobleman's Pantaloons
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=50000 WHERE (`entry`=85484 AND `item`=116052 AND `ExtendedCost`=3814 AND `type`=1); -- Nobleman's Coat
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=50000 WHERE (`entry`=85484 AND `item`=116138 AND `ExtendedCost`=5800 AND `type`=1); -- Last Deck of Nemelex Xobeh
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=50000 WHERE (`entry`=85484 AND `item`=116139 AND `ExtendedCost`=3700 AND `type`=1); -- Haunting Memento

DELETE FROM `gossip_menu` WHERE (`MenuID`=26818 AND `TextID`=42769);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(26818, 42769, 50000); -- 181097 (Simon Sezdans)

UPDATE `gossip_menu` SET `VerifiedBuild`=50000 WHERE (`MenuID`=16970 AND `TextID`=24702) OR (`MenuID`=15306 AND `TextID`=21955);
DELETE FROM `gossip_menu_option` WHERE (`MenuID`=26818 AND `OptionID` IN (0,1));
INSERT INTO `gossip_menu_option` (`GossipOptionID`, `MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `Flags`, `OverrideIconID`, `GossipNpcOptionID`, `VerifiedBuild`) VALUES
(52650, 26818, 0, 0, 'Sounds fun. What are the rules?', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 50000),
(52651, 26818, 1, 0, 'Ready to dance! |cFF0008E8(Darkmoon Game Token)|r', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 50000);

UPDATE `gossip_menu_option` SET `GossipOptionID`=43059, `VerifiedBuild`=50000 WHERE (`MenuID`=16970 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=43060, `VerifiedBuild`=50000 WHERE (`MenuID`=16970 AND `OptionID`=1);

-- Vendor data
DELETE FROM `npc_vendor` WHERE (`entry`=85484 AND `item`=116136 AND `ExtendedCost`=3814 AND `type`=1) OR (`entry`=85484 AND `item`=116137 AND `ExtendedCost`=3814 AND `type`=1) OR (`entry`=149540 AND `item`=92794 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(85484, 4, 116136, 0, 3814, 1, 0, 0, 50000), -- Noblewoman's Skirt
(85484, 3, 116137, 0, 3814, 1, 0, 0, 50000), -- Noblewoman's Finery
(149540, 7, 92794, 0, 0, 1, 0, 0, 50000); -- Ride Ticket Book
