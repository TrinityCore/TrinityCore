
DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (42437,42507,42506,40446));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `VerifiedBuild`) VALUES
(42437, 0, 66263),
(42507, 0, 66263),
(42506, 0, 66263),
(40446, 0, 66263);


DELETE FROM `conversation_line_template` WHERE `Id` IN (79429, 87215, 87214, 79425, 81563, 87519, 79420, 79334, 79333, 79474, 82014, 82019, 80804, 78847, 80967, 78850, 80873, 87502, 87501, 87403, 87402, 81683, 87404, 80872, 79591, 79590, 82011, 82179, 82177, 82176, 80874, 82082, 80647, 81692, 85512, 79113, 79112, 78946, 81708, 78845, 79294, 79293);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(79429, 0, 3, 0, 0, 66263),
(87215, 0, 2, 0, 0, 66263),
(87214, 0, 1, 0, 0, 66263),
(79425, 0, 0, 0, 0, 66263),
(81563, 0, 0, 0, 0, 66263),
(87519, 0, 0, 0, 0, 66263),
(79420, 0, 0, 0, 0, 66263),
(79334, 0, 1, 0, 0, 66263),
(79333, 0, 0, 0, 0, 66263),
(79474, 0, 0, 0, 0, 66263),
(82014, 0, 0, 0, 0, 66263),
(82019, 0, 0, 0, 0, 66263),
(80804, 0, 0, 0, 0, 66263),
(78847, 0, 2, 0, 0, 66263),
(80967, 0, 1, 0, 0, 66263),
(78850, 0, 0, 0, 0, 66263),
(80873, 0, 0, 0, 0, 66263),
(87502, 0, 1, 0, 0, 66263),
(87501, 0, 0, 0, 0, 66263),
(87403, 0, 1, 0, 0, 66263),
(87402, 0, 2, 0, 0, 66263),
(81683, 0, 1, 0, 0, 66263),
(87404, 0, 0, 0, 0, 66263),
(80872, 0, 0, 0, 0, 66263),
(79591, 0, 0, 0, 0, 66263),
(79590, 0, 1, 0, 0, 66263),
(82011, 0, 0, 0, 0, 66263),
(82179, 0, 2, 0, 0, 66263),
(82177, 0, 1, 0, 0, 66263),
(82176, 0, 0, 0, 0, 66263),
(80874, 0, 0, 0, 0, 66263),
(82082, 0, 0, 0, 0, 66263),
(80647, 0, 0, 0, 0, 66263),
(81692, 0, 0, 0, 0, 66263),
(85512, 0, 2, 0, 0, 66263),
(79113, 0, 1, 0, 0, 66263),
(79112, 0, 0, 0, 0, 66263),
(78946, 0, 0, 0, 0, 66263),
(81708, 0, 0, 0, 0, 66263),
(78845, 0, 0, 0, 0, 66263),
(79294, 0, 1, 0, 0, 66263),
(79293, 0, 0, 0, 0, 66263);


DELETE FROM `quest_details` WHERE `ID` IN (86624 /*Rational Explanation*/, 86623 /*Appeal to the Void*/, 86621 /*The Wayward Magister*/, 86745 /*Silvermoon Must Know*/, 86744 /*Seeking Truth*/, 86742 /*Curious Cultivation*/, 86743 /*Trimming the Lightbloom*/, 86741 /*Lightbloom Looming*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(86624, 378, 0, 0, 0, 0, 0, 0, 0, 66263), -- Rational Explanation
(86623, 378, 0, 0, 0, 0, 0, 0, 0, 66263), -- Appeal to the Void
(86621, 378, 0, 0, 0, 0, 0, 0, 0, 66263), -- The Wayward Magister
(86745, 1, 0, 0, 0, 0, 0, 0, 0, 66263), -- Silvermoon Must Know
(86744, 1, 0, 0, 0, 0, 0, 0, 0, 66263), -- Seeking Truth
(86742, 1, 0, 0, 0, 0, 0, 0, 0, 66263), -- Curious Cultivation
(86743, 0, 0, 0, 0, 0, 0, 0, 0, 66263), -- Trimming the Lightbloom
(86741, 1, 0, 0, 0, 0, 0, 0, 0, 66263); -- Lightbloom Looming


DELETE FROM `creature_queststarter` WHERE (`id`=236100 AND `quest`=86624) OR (`id`=236087 AND `quest`=86623) OR (`id`=236716 AND `quest` IN (86621,86745)) OR (`id`=236903 AND `quest` IN (86744,86742,86743)) OR (`id`=236743 AND `quest`=86741);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(236100, 86624, 66263), -- Rational Explanation offered by Arator
(236087, 86623, 66263), -- Appeal to the Void offered by Magister Umbric
(236716, 86621, 66263), -- The Wayward Magister offered by Arator
(236716, 86745, 66263), -- Silvermoon Must Know offered by Arator
(236903, 86744, 66263), -- Seeking Truth offered by Orweyna
(236903, 86742, 66263), -- Curious Cultivation offered by Orweyna
(236903, 86743, 66263), -- Trimming the Lightbloom offered by Orweyna
(236743, 86741, 66263); -- Lightbloom Looming offered by Orweyna



UPDATE `creature_questender` SET `VerifiedBuild`=66263 WHERE (`id`=236087 AND `quest`=86621) OR (`id`=236716 AND `quest`=86745) OR (`id`=236903 AND `quest` IN (86744,86742,86741)) OR (`id`=240663 AND `quest`=86743) OR (`id`=236743 AND `quest`=86740);

DELETE FROM `spawn_tracking_template` WHERE `SpawnTrackingId` IN (2819308 /*Map: 0 - Phase: 0*/, 2709096 /*Map: 0 - Phase: 27509*/, 2770819 /*Map: 0 - Phase: 0*/, 2705994 /*Map: 0 - Phase: 0*/, 2813884 /*Map: 0 - Phase: 0*/, 2783351 /*Map: 0 - Phase: 26332*/, 2734838 /*Map: 0 - Phase: 0*/, 2734837 /*Map: 0 - Phase: 26332*/, 2705824 /*Map: 0 - Phase: 25989*/, 2819311 /*Map: 0 - Phase: 0*/, 2770818 /*Map: 0 - Phase: 0*/, 2770817 /*Map: 0 - Phase: 0*/, 2770823 /*Map: 0 - Phase: 0*/, 2819310 /*Map: 0 - Phase: 0*/, 2779289 /*Map: 0 - Phase: 26281*/, 2744503 /*Map: 0 - Phase: 0*/, 2744497 /*Map: 0 - Phase: 0*/, 2744116 /*Map: 0 - Phase: 0*/, 2709310 /*Map: 0 - Phase: 26025*/, 2705887 /*Map: 0 - Phase: 25983*/, 2705885 /*Map: 0 - Phase: 25864*/, 2711974 /*Map: 0 - Phase: 26013*/, 2768392 /*Map: 0 - Phase: 0*/, 2768710 /*Map: 0 - Phase: 26026*/, 2714722 /*Map: 0 - Phase: 0*/, 3003247 /*Map: 0 - Phase: 27550*/, 2781229 /*Map: 0 - Phase: 0*/, 2714761 /*Map: 0 - Phase: 0*/, 2714763 /*Map: 0 - Phase: 0*/, 2744878 /*Map: 0 - Phase: 0*/, 2806964 /*Map: 0 - Phase: 0*/, 2711977 /*Map: 0 - Phase: 25938*/);
INSERT INTO `spawn_tracking_template` (`SpawnTrackingId`, `MapId`, `PhaseId`, `PhaseGroup`, `PhaseUseFlags`, `VerifiedBuild`) VALUES
(2819308, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2709096, 0, 27509, 0, 0, 66263), -- Map: 0 - Phase: 27509
(2770819, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2705994, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2813884, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2783351, 0, 26332, 0, 0, 66263), -- Map: 0 - Phase: 26332
(2734838, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2734837, 0, 26332, 0, 0, 66263), -- Map: 0 - Phase: 26332
(2705824, 0, 25989, 0, 0, 66263), -- Map: 0 - Phase: 25989
(2819311, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2770818, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2770817, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2770823, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2819310, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2779289, 0, 26281, 0, 0, 66263), -- Map: 0 - Phase: 26281
(2744503, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2744497, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2744116, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2709310, 0, 26025, 0, 0, 66263), -- Map: 0 - Phase: 26025
(2705887, 0, 25983, 0, 0, 66263), -- Map: 0 - Phase: 25983
(2705885, 0, 25864, 0, 0, 66263), -- Map: 0 - Phase: 25864
(2711974, 0, 26013, 0, 0, 66263), -- Map: 0 - Phase: 26013
(2768392, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2768710, 0, 26026, 0, 0, 66263), -- Map: 0 - Phase: 26026
(2714722, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(3003247, 0, 27550, 0, 0, 66263), -- Map: 0 - Phase: 27550
(2781229, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2714761, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2714763, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2744878, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2806964, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2711977, 0, 25938, 0, 0, 66263); -- Map: 0 - Phase: 25938

UPDATE `spawn_tracking_template` SET `MapId`=0 WHERE `SpawnTrackingId` IN (1483954, 1174115);

DELETE FROM `spawn_tracking_quest_objective` WHERE (`SpawnTrackingId`=2770819 AND `QuestObjectiveId`=459995) OR (`SpawnTrackingId`=2705994 AND `QuestObjectiveId`=458712) OR (`SpawnTrackingId`=2813884 AND `QuestObjectiveId`=461808) OR (`SpawnTrackingId`=2783351 AND `QuestObjectiveId`=461635) OR (`SpawnTrackingId`=2734838 AND `QuestObjectiveId`=458747) OR (`SpawnTrackingId`=2734837 AND `QuestObjectiveId`=458743) OR (`SpawnTrackingId`=2744503 AND `QuestObjectiveId`=459457) OR (`SpawnTrackingId`=2744497 AND `QuestObjectiveId`=459456) OR (`SpawnTrackingId`=2744116 AND `QuestObjectiveId`=459455) OR (`SpawnTrackingId`=2709096 AND `QuestObjectiveId`=461573) OR (`SpawnTrackingId`=2705887 AND `QuestObjectiveId`=461571) OR (`SpawnTrackingId`=2709310 AND `QuestObjectiveId` IN (462246,459813)) OR (`SpawnTrackingId`=2705885 AND `QuestObjectiveId`=459174) OR (`SpawnTrackingId`=2768392 AND `QuestObjectiveId`=459728) OR (`SpawnTrackingId`=2714722 AND `QuestObjectiveId`=459572) OR (`SpawnTrackingId`=3003247 AND `QuestObjectiveId`=459657) OR (`SpawnTrackingId`=2781229 AND `QuestObjectiveId`=460817) OR (`SpawnTrackingId`=2714761 AND `QuestObjectiveId`=460816) OR (`SpawnTrackingId`=2714763 AND `QuestObjectiveId`=460815) OR (`SpawnTrackingId`=2744878 AND `QuestObjectiveId`=461618) OR (`SpawnTrackingId`=2806964 AND `QuestObjectiveId`=461604);
INSERT INTO `spawn_tracking_quest_objective` (`SpawnTrackingId`, `QuestObjectiveId`, `VerifiedBuild`) VALUES
(2770819, 459995, 66263), -- 2770819
(2705994, 458712, 66263), -- 2705994
(2813884, 461808, 66263), -- 2813884
(2783351, 461635, 66263), -- 2783351
(2734838, 458747, 66263), -- 2734838
(2734837, 458743, 66263), -- 2734837
(2744503, 459457, 66263), -- 2744503
(2744497, 459456, 66263), -- 2744497
(2744116, 459455, 66263), -- 2744116
(2709096, 461573, 66263), -- 2709096
(2705887, 461571, 66263), -- 2705887
(2709310, 462246, 66263), -- 2709310
(2705885, 459174, 66263), -- 2705885
(2709310, 459813, 66263), -- 2709310
(2768392, 459728, 66263), -- 2768392
(2714722, 459572, 66263), -- 2714722
(3003247, 459657, 66263), -- 3003247
(2781229, 460817, 66263), -- 2781229
(2714761, 460816, 66263), -- 2714761
(2714763, 460815, 66263), -- 2714763
(2744878, 461618, 66263), -- 2744878
(2806964, 461604, 66263); -- 2806964


DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=236149 AND `MenuID`=38536) OR (`CreatureID`=238480 AND `MenuID`=7147) OR (`CreatureID`=239457 AND `MenuID`=38507) OR (`CreatureID`=244840 AND `MenuID`=39343) OR (`CreatureID`=236087 AND `MenuID`=38763) OR (`CreatureID`=236903 AND `MenuID` IN (38606,38525)) OR (`CreatureID`=236716 AND `MenuID`=38595) OR (`CreatureID`=249863 AND `MenuID`=40522);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(236149, 38536, 66263), -- Innkeeper Kalarin
(238480, 7147, 66263), -- Skymaster Sunwing
(239457, 38507, 66263), -- Guard Captain Leonic
(244840, 39343, 66263), -- Quartermaster Lymel
(236087, 38763, 66263), -- Magister Umbric
(236903, 38606, 66263), -- Orweyna
(236716, 38595, 66263), -- Arator
(236903, 38525, 66263), -- Orweyna
(249863, 40522, 66263); -- Larianna Riverwind



UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=66263 WHERE (`entry`=246742 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- 20815
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=66263 WHERE (`entry`=246742 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- 39354
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=66263 WHERE (`entry`=246742 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- 2324
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=66263 WHERE (`entry`=246742 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- 2604
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=66263 WHERE (`entry`=246742 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- 6260
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=66263 WHERE (`entry`=246742 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- 2605
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=66263 WHERE (`entry`=246742 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- 6530
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=66263 WHERE (`entry`=246742 AND `item`=6529 AND `ExtendedCost`=0 AND `type`=1); -- 6529
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=66263 WHERE (`entry`=246742 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- 4289
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=66263 WHERE (`entry`=246742 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- 2880
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=66263 WHERE (`entry`=246742 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- 2678
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=66263 WHERE (`entry`=246742 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- 2321
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=66263 WHERE (`entry`=246742 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- 2320
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=66263 WHERE (`entry`=246742 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- 3371
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=66263 WHERE (`entry`=246742 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- 6217
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=66263 WHERE (`entry`=246742 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- 6256
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=66263 WHERE (`entry`=246742 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- 39505
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=66263 WHERE (`entry`=246742 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- 5956
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=66263 WHERE (`entry`=246742 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- 2901
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=66263 WHERE (`entry`=246742 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1); -- 85663
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=66263 WHERE (`entry`=246742 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- 7005


UPDATE `gossip_menu` SET `VerifiedBuild`=66263 WHERE (`MenuID`=7147 AND `TextID`=8411);
DELETE FROM `gossip_menu_option` WHERE (`OptionID`=2 AND `MenuID` IN (38595,38606,38536)) OR (`OptionID`=1 AND `MenuID` IN (38763,38606,38536,38595)) OR (`OptionID`=0 AND `MenuID` IN (38525,38507,38606,39343,38763)) OR (`OptionID`=3 AND `MenuID`=38525);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(38595, 136284, 2, 0, '|cFFFF0000<Skip conversation>|r What now?', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263),
(38763, 134207, 1, 0, 'How do you know the Governor of Tranquillien?', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263),
(38525, 132732, 0, 0, 'What brought you here?', 177999, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263), -- OptionBroadcastTextID: 177999 - 260541
(38525, 133725, 3, 0, 'Let\'s follow the trail you found.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263),
(38507, 132706, 0, 0, 'Have you seen anything suspicious lately?', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263),
(38606, 132833, 0, 0, 'I\'m ready when you are.', 152709, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263), -- OptionBroadcastTextID: 152709 - 267802
(38606, 134076, 2, 0, 'What are the rutaani?', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263),
(39343, 133888, 0, 0, 'Have there been any issues around town lately?', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263),
(38606, 133705, 1, 0, '<Stay awhile and listen.>', 137786, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263), -- OptionBroadcastTextID: 137786 - 144263 - 160761 - 160763 - 160765 - 160768 - 167552 - 173473 - 176737 - 188459 - 202026 - 205118 - 205774
(38536, 137856, 1, 5, 'Bind your hearthstone to this inn.', 2822, 0, 0, 0, 0, 60317, 0, 0, NULL, 0, NULL, NULL, 66263),
(38536, 137854, 2, 1, 'What do you have for sale?', 10182, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263), -- OptionBroadcastTextID: 10182 - 16129 - 16134 - 16135 - 16452 - 20994 - 53758 - 66614 - 117193 - 122305 - 122306
(38595, 132860, 1, 0, '<Contact Silvermoon.>', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263),
(38763, 134206, 0, 0, 'How do you know the corpse we found?', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263);

UPDATE `gossip_menu_option` SET `VerifiedBuild`=66263 WHERE (`MenuID`=7147 AND `OptionID`=0);

DELETE FROM `spawn_tracking_template` WHERE `SpawnTrackingId` IN (2709096 /*Map: 0 - Phase: 27509*/, 2770819 /*Map: 0 - Phase: 0*/, 2705994 /*Map: 0 - Phase: 0*/, 2813884 /*Map: 0 - Phase: 0*/, 2783351 /*Map: 0 - Phase: 26332*/, 2734838 /*Map: 0 - Phase: 0*/, 2734837 /*Map: 0 - Phase: 26332*/, 2705824 /*Map: 0 - Phase: 25989*/, 2779289 /*Map: 0 - Phase: 26281*/, 2744503 /*Map: 0 - Phase: 0*/, 2744497 /*Map: 0 - Phase: 0*/, 2744116 /*Map: 0 - Phase: 0*/);
INSERT INTO `spawn_tracking_template` (`SpawnTrackingId`, `MapId`, `PhaseId`, `PhaseGroup`, `PhaseUseFlags`, `VerifiedBuild`) VALUES
(2709096, 0, 27509, 0, 0, 66337), -- Map: 0 - Phase: 27509
(2770819, 0, 0, 0, 0, 66337), -- Map: 0 - Phase: 0
(2705994, 0, 0, 0, 0, 66337), -- Map: 0 - Phase: 0
(2813884, 0, 0, 0, 0, 66337), -- Map: 0 - Phase: 0
(2783351, 0, 26332, 0, 0, 66337), -- Map: 0 - Phase: 26332
(2734838, 0, 0, 0, 0, 66337), -- Map: 0 - Phase: 0
(2734837, 0, 26332, 0, 0, 66337), -- Map: 0 - Phase: 26332
(2705824, 0, 25989, 0, 0, 66337), -- Map: 0 - Phase: 25989
(2779289, 0, 26281, 0, 0, 66337), -- Map: 0 - Phase: 26281
(2744503, 0, 0, 0, 0, 66337), -- Map: 0 - Phase: 0
(2744497, 0, 0, 0, 0, 66337), -- Map: 0 - Phase: 0
(2744116, 0, 0, 0, 0, 66337); -- Map: 0 - Phase: 0

UPDATE `spawn_tracking_template` SET `VerifiedBuild`=66337 WHERE `SpawnTrackingId`=1289000;
UPDATE `spawn_tracking_template` SET `MapId`=0, `VerifiedBuild`=66337 WHERE `SpawnTrackingId`=1174111; -- Map: 0 - Phase: 0

DELETE FROM `spawn_tracking_quest_objective` WHERE (`SpawnTrackingId`=2770819 AND `QuestObjectiveId`=459995) OR (`SpawnTrackingId`=2705994 AND `QuestObjectiveId`=458712) OR (`SpawnTrackingId`=2813884 AND `QuestObjectiveId`=461808) OR (`SpawnTrackingId`=2783351 AND `QuestObjectiveId`=461635) OR (`SpawnTrackingId`=2734838 AND `QuestObjectiveId`=458747) OR (`SpawnTrackingId`=2734837 AND `QuestObjectiveId`=458743) OR (`SpawnTrackingId`=2744503 AND `QuestObjectiveId`=459457) OR (`SpawnTrackingId`=2744497 AND `QuestObjectiveId`=459456) OR (`SpawnTrackingId`=2744116 AND `QuestObjectiveId`=459455);
INSERT INTO `spawn_tracking_quest_objective` (`SpawnTrackingId`, `QuestObjectiveId`, `VerifiedBuild`) VALUES
(2770819, 459995, 66337), -- 2770819
(2705994, 458712, 66337), -- 2705994
(2813884, 461808, 66337), -- 2813884
(2783351, 461635, 66337), -- 2783351
(2734838, 458747, 66337), -- 2734838
(2734837, 458743, 66337), -- 2734837
(2744503, 459457, 66337), -- 2744503
(2744497, 459456, 66337), -- 2744497
(2744116, 459455, 66337); -- 2744116

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (42507,42506,41777));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `VerifiedBuild`) VALUES
(42507, 0, 66666),
(42506, 0, 66666),
(41777, 0, 66666);

DELETE FROM `conversation_line_template` WHERE `Id` IN (79660, 86270, 82368, 79531, 79658, 81772, 81771, 81770, 79662, 79535, 79534, 79533, 79664);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(79660, 0, 0, 0, 0, 66666),
(86270, 0, 0, 0, 0, 66666),
(82368, 0, 0, 0, 0, 66666),
(79531, 0, 0, 0, 0, 66666),
(79658, 0, 0, 0, 0, 66666),
(81772, 0, 2, 0, 0, 66666),
(81771, 0, 1, 0, 0, 66666),
(81770, 0, 0, 0, 0, 66666),
(79662, 0, 0, 0, 0, 66666),
(79535, 0, 2, 0, 0, 66666),
(79534, 0, 1, 0, 0, 66666),
(79533, 0, 0, 0, 0, 66666),
(79664, 0, 0, 0, 0, 66666);

DELETE FROM `quest_details` WHERE `ID` IN (86640 /*Premonition*/, 86638 /*Choking Tendrils*/, 86639 /*What's Left*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(86640, 0, 0, 0, 0, 0, 0, 0, 0, 66666), -- Premonition
(86638, 0, 0, 0, 0, 0, 0, 0, 0, 66666), -- Choking Tendrils
(86639, 0, 0, 0, 0, 0, 0, 0, 0, 66666); -- What's Left

DELETE FROM `creature_queststarter` WHERE (`id`=236572 AND `quest`=86640) OR (`id`=236132 AND `quest`=86638) OR (`id`=236099 AND `quest`=86639);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(236572, 86640, 66666), -- Premonition offered by Lor'themar Theron
(236132, 86638, 66666), -- Choking Tendrils offered by Arator
(236099, 86639, 66666); -- What's Left offered by Lady Liadrin


DELETE FROM `spawn_tracking_template` WHERE `SpawnTrackingId` IN (2737721 /*Map: 0 - Phase: 27460*/, 2996293 /*Map: 0 - Phase: 27461*/, 2737780 /*Map: 0 - Phase: 27457*/, 2740135 /*Map: 0 - Phase: 27458*/, 2707914 /*Map: 0 - Phase: 26670*/, 2768857 /*Map: 0 - Phase: 0*/, 2737761 /*Map: 0 - Phase: 0*/, 2768849 /*Map: 0 - Phase: 0*/, 2768850 /*Map: 0 - Phase: 0*/, 2768842 /*Map: 0 - Phase: 0*/, 2768843 /*Map: 0 - Phase: 0*/, 2737760 /*Map: 0 - Phase: 0*/, 2737773 /*Map: 0 - Phase: 0*/, 2740118 /*Map: 0 - Phase: 0*/, 2707905 /*Map: 0 - Phase: 0*/, 2739973 /*Map: 0 - Phase: 0*/, 2740038 /*Map: 0 - Phase: 0*/, 2707913 /*Map: 0 - Phase: 25893*/);
INSERT INTO `spawn_tracking_template` (`SpawnTrackingId`, `MapId`, `PhaseId`, `PhaseGroup`, `PhaseUseFlags`, `VerifiedBuild`) VALUES
(2737721, 0, 27460, 0, 0, 66666), -- Map: 0 - Phase: 27460
(2996293, 0, 27461, 0, 0, 66666), -- Map: 0 - Phase: 27461
(2737780, 0, 27457, 0, 0, 66666), -- Map: 0 - Phase: 27457
(2740135, 0, 27458, 0, 0, 66666), -- Map: 0 - Phase: 27458
(2707914, 0, 26670, 0, 0, 66666), -- Map: 0 - Phase: 26670
(2768857, 0, 0, 0, 0, 66666), -- Map: 0 - Phase: 0
(2737761, 0, 0, 0, 0, 66666), -- Map: 0 - Phase: 0
(2768849, 0, 0, 0, 0, 66666), -- Map: 0 - Phase: 0
(2768850, 0, 0, 0, 0, 66666), -- Map: 0 - Phase: 0
(2768842, 0, 0, 0, 0, 66666), -- Map: 0 - Phase: 0
(2768843, 0, 0, 0, 0, 66666), -- Map: 0 - Phase: 0
(2737760, 0, 0, 0, 0, 66666), -- Map: 0 - Phase: 0
(2737773, 0, 0, 0, 0, 66666), -- Map: 0 - Phase: 0
(2740118, 0, 0, 0, 0, 66666), -- Map: 0 - Phase: 0
(2707905, 0, 0, 0, 0, 66666), -- Map: 0 - Phase: 0
(2739973, 0, 0, 0, 0, 66666), -- Map: 0 - Phase: 0
(2740038, 0, 0, 0, 0, 66666), -- Map: 0 - Phase: 0
(2707913, 0, 25893, 0, 0, 66666); -- Map: 0 - Phase: 25893

UPDATE `spawn_tracking_template` SET `VerifiedBuild`=66666 WHERE `SpawnTrackingId` IN (2706575, 2782280, 1484068);
UPDATE `spawn_tracking_template` SET `MapId`=0, `VerifiedBuild`=66666 WHERE `SpawnTrackingId`=1174115; -- Map: 0 - Phase: 0

DELETE FROM `spawn_tracking_quest_objective` WHERE (`SpawnTrackingId`=2737721 AND `QuestObjectiveId`=464806) OR (`SpawnTrackingId`=2996293 AND `QuestObjectiveId`=464804) OR (`SpawnTrackingId`=2737780 AND `QuestObjectiveId`=464805) OR (`SpawnTrackingId`=2740135 AND `QuestObjectiveId`=464803);
INSERT INTO `spawn_tracking_quest_objective` (`SpawnTrackingId`, `QuestObjectiveId`, `VerifiedBuild`) VALUES
(2737721, 464806, 66666), -- 2737721
(2996293, 464804, 66666), -- 2996293
(2737780, 464805, 66666), -- 2737780
(2740135, 464803, 66666); -- 2740135


DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=251539 AND `MenuID`=38478) OR (`CreatureID`=251542 AND `MenuID`=40511) OR (`CreatureID`=251543 AND `MenuID`=38481) OR (`CreatureID`=251540 AND `MenuID`=38465);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(251539, 38478, 66666), -- Magistrix Silanna
(251542, 40511, 66666), -- Outrunner Alarion
(251543, 38481, 66666), -- Trainee Solanin
(251540, 38465, 66666); -- Apprentice Erilia


DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (38478,38465,38481,40511));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(38478, 132680, 0, 0, 'I\'ll cover your escape. Go quickly!', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66666),
(38465, 132652, 0, 0, '<Instruct the defender to go to the Runestone Shan\'dor, where it is safe.>', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66666),
(38481, 132684, 0, 0, '<Instruct the defender to go to the Runestone Shan\'dor, where it is safe.>', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66666),
(40511, 135781, 0, 0, '<Instruct the defender to go to the Runestone Shan\'dor, where it is safe.>', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66666);

DELETE FROM `areatrigger_template` WHERE (`Id`=39871 AND `IsCustom`=0);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `VerifiedBuild`) VALUES
(39871, 0, 66527);


DELETE FROM `conversation_line_template` WHERE `Id` IN (79173, 79172, 91367, 80790, 82171, 79105, 79104, 79183, 79182, 91368, 80769, 80348, 80347, 80346, 79125, 91366, 86981, 86980, 82261, 79956, 91369, 82367, 82366, 87217, 82369, 80151, 81484, 81483, 82080, 80788, 80787, 82308, 82307, 79169, 80802, 91372, 80965, 80964, 82174, 82173, 82172, 81823, 82512, 81825, 79223, 79224, 79221, 81482, 81481, 82304, 82303, 80433, 80432, 79174, 87138, 80157, 82074, 82072, 79123);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(79173, 0, 1, 0, 0, 66527),
(79172, 0, 1, 0, 0, 66527),
(91367, 0, 0, 0, 0, 66527),
(80790, 0, 0, 0, 0, 66527),
(82171, 0, 2, 0, 0, 66527),
(79105, 0, 1, 0, 0, 66527),
(79104, 0, 0, 0, 0, 66527),
(79183, 0, 1, 0, 0, 66527),
(79182, 0, 1, 0, 0, 66527),
(91368, 0, 0, 0, 0, 66527),
(80769, 0, 0, 0, 0, 66527),
(80348, 0, 2, 0, 0, 66527),
(80347, 0, 1, 0, 0, 66527),
(80346, 0, 0, 0, 0, 66527),
(79125, 0, 1, 0, 0, 66527),
(91366, 0, 0, 0, 0, 66527),
(86981, 0, 1, 0, 0, 66527),
(86980, 0, 0, 0, 0, 66527),
(82261, 0, 2, 0, 3, 66527),
(79956, 0, 1, 0, 0, 66527),
(91369, 0, 0, 0, 0, 66527),
(82367, 0, 1, 0, 0, 66527),
(82366, 0, 1, 0, 0, 66527),
(87217, 0, 0, 0, 0, 66527),
(82369, 0, 1, 0, 0, 66527),
(80151, 0, 0, 0, 0, 66527),
(81484, 0, 1, 0, 0, 66527),
(81483, 0, 0, 0, 0, 66527),
(82080, 0, 0, 0, 0, 66527),
(80788, 0, 1, 0, 0, 66527),
(80787, 0, 0, 0, 0, 66527),
(82308, 0, 0, 0, 0, 66527),
(82307, 0, 0, 0, 0, 66527),
(79169, 0, 0, 0, 0, 66527),
(80802, 0, 0, 0, 0, 66527),
(91372, 0, 0, 0, 0, 66527),
(80965, 0, 1, 0, 0, 66527),
(80964, 0, 0, 0, 0, 66527),
(82174, 0, 2, 0, 0, 66527),
(82173, 0, 1, 0, 0, 66527),
(82172, 0, 0, 0, 0, 66527),
(81823, 0, 0, 0, 0, 66527),
(82512, 121, 0, 0, 0, 66527),
(81825, 121, 0, 0, 0, 66527),
(79223, 0, 2, 0, 0, 66527),
(79224, 0, 1, 0, 0, 66527),
(79221, 0, 0, 0, 0, 66527),
(81482, 0, 1, 0, 0, 66527),
(81481, 0, 0, 0, 0, 66527),
(82304, 0, 1, 0, 0, 66527),
(82303, 0, 0, 0, 0, 66527),
(80433, 0, 1, 0, 0, 66527),
(80432, 0, 0, 0, 0, 66527),
(79174, 0, 0, 0, 0, 66527),
(87138, 0, 0, 0, 0, 66527),
(80157, 0, 0, 0, 0, 66527),
(82074, 0, 1, 0, 0, 66527),
(82072, 0, 0, 0, 0, 66527),
(79123, 0, 0, 0, 0, 66527);

DELETE FROM `quest_details` WHERE `ID` IN (90494 /*The Missing Magister*/, 90493 /*The Heart of Tranquillien*/, 90509 /*The Traitors of Tranquillien*/, 86632 /*The Battle for Tranquillien*/, 86626 /*The Ransacked Lab*/, 86622 /*Chance Meeting*/, 90907 /*The First to Know*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(90494, 378, 0, 0, 0, 0, 0, 0, 0, 66527), -- The Missing Magister
(90493, 0, 0, 0, 0, 0, 0, 0, 0, 66527), -- The Heart of Tranquillien
(90509, 0, 0, 0, 0, 0, 0, 0, 0, 66527), -- The Traitors of Tranquillien
(86632, 378, 0, 0, 0, 0, 0, 0, 0, 66527), -- The Battle for Tranquillien
(86626, 274, 0, 0, 0, 0, 0, 0, 0, 66527), -- The Ransacked Lab
(86622, 378, 0, 0, 0, 0, 0, 0, 0, 66527), -- Chance Meeting
(90907, 378, 0, 0, 0, 0, 0, 0, 0, 66527); -- The First to Know

DELETE FROM `creature_queststarter` WHERE (`id`=243984 AND `quest`=90494) OR (`id`=236686 AND `quest` IN (90493,90509)) OR (`id`=236687 AND `quest`=86632) OR (`id`=242143 AND `quest`=86626) OR (`id`=245004 AND `quest`=86622) OR (`id`=236087 AND `quest`=90907);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(243984, 90494, 66527), -- The Missing Magister offered by Arator
(236686, 90493, 66527), -- The Heart of Tranquillien offered by Arator
(236686, 90509, 66527), -- The Traitors of Tranquillien offered by Arator
(236687, 86632, 66527), -- The Battle for Tranquillien offered by Magister Umbric
(242143, 86626, 66527), -- The Ransacked Lab offered by Magister Umbric
(245004, 86622, 66527), -- Chance Meeting offered by Lord Antenorian
(236087, 90907, 66527); -- The First to Know offered by Magister Umbric


DELETE FROM `spawn_tracking_template` WHERE `SpawnTrackingId` IN (2782313 /*Map: 0 - Phase: 26338*/, 2811039 /*Map: 0 - Phase: 25483*/, 2774240 /*Map: 0 - Phase: 25483*/, 2709092 /*Map: 0 - Phase: 26201*/, 2709098 /*Map: 0 - Phase: 26289*/, 2709080 /*Map: 0 - Phase: 26444*/, 2709712 /*Map: 0 - Phase: 26444*/, 2778537 /*Map: 0 - Phase: 25483*/, 2709067 /*Map: 0 - Phase: 25483*/, 2709084 /*Map: 0 - Phase: 25483*/, 2709075 /*Map: 0 - Phase: 25483*/, 2774205 /*Map: 0 - Phase: 25483*/, 2778435 /*Map: 0 - Phase: 25483*/, 2802488 /*Map: 0 - Phase: 25483*/, 2802231 /*Map: 0 - Phase: 25483*/, 2778540 /*Map: 0 - Phase: 25483*/, 2709058 /*Map: 0 - Phase: 25483*/, 2802910 /*Map: 0 - Phase: 25483*/, 2871546 /*Map: 0 - Phase: 25483*/, 2709721 /*Map: 0 - Phase: 25483*/, 2774202 /*Map: 0 - Phase: 25483*/, 2774167 /*Map: 0 - Phase: 25483*/, 2838351 /*Map: 0 - Phase: 0*/, 2713491 /*Map: 0 - Phase: 0*/, 2713493 /*Map: 0 - Phase: 0*/, 2804298 /*Map: 0 - Phase: 26475*/, 2713492 /*Map: 0 - Phase: 0*/, 2804297 /*Map: 0 - Phase: 26475*/, 2804296 /*Map: 0 - Phase: 26475*/, 2804280 /*Map: 0 - Phase: 26475*/, 2804267 /*Map: 0 - Phase: 26475*/, 2804295 /*Map: 0 - Phase: 26475*/, 2819832 /*Map: 0 - Phase: 26633*/, 2809738 /*Map: 0 - Phase: 0*/, 2709096 /*Map: 0 - Phase: 27509*/, 2863840 /*Map: 0 - Phase: 0*/, 2811096 /*Map: 0 - Phase: 26332*/, 2734836 /*Map: 0 - Phase: 27520*/, 2819831 /*Map: 0 - Phase: 26600*/, 3019762 /*Map: 0 - Phase: 0*/, 2779289 /*Map: 0 - Phase: 26281*/, 2744503 /*Map: 0 - Phase: 0*/, 2744497 /*Map: 0 - Phase: 0*/, 2744116 /*Map: 0 - Phase: 0*/, 2770819 /*Map: 0 - Phase: 0*/, 2705994 /*Map: 0 - Phase: 0*/, 2813884 /*Map: 0 - Phase: 0*/, 2783351 /*Map: 0 - Phase: 26332*/, 2734838 /*Map: 0 - Phase: 0*/, 2734837 /*Map: 0 - Phase: 26332*/, 2705824 /*Map: 0 - Phase: 25989*/, 2770825 /*Map: 0 - Phase: 0*/, 2819309 /*Map: 0 - Phase: 0*/);
INSERT INTO `spawn_tracking_template` (`SpawnTrackingId`, `MapId`, `PhaseId`, `PhaseGroup`, `PhaseUseFlags`, `VerifiedBuild`) VALUES
(2782313, 0, 26338, 0, 0, 66527), -- Map: 0 - Phase: 26338
(2811039, 0, 25483, 0, 0, 66527), -- Map: 0 - Phase: 25483
(2774240, 0, 25483, 0, 0, 66527), -- Map: 0 - Phase: 25483
(2709092, 0, 26201, 0, 0, 66527), -- Map: 0 - Phase: 26201
(2709098, 0, 26289, 0, 0, 66527), -- Map: 0 - Phase: 26289
(2709080, 0, 26444, 0, 0, 66527), -- Map: 0 - Phase: 26444
(2709712, 0, 26444, 0, 0, 66527), -- Map: 0 - Phase: 26444
(2778537, 0, 25483, 0, 0, 66527), -- Map: 0 - Phase: 25483
(2709067, 0, 25483, 0, 0, 66527), -- Map: 0 - Phase: 25483
(2709084, 0, 25483, 0, 0, 66527), -- Map: 0 - Phase: 25483
(2709075, 0, 25483, 0, 0, 66527), -- Map: 0 - Phase: 25483
(2774205, 0, 25483, 0, 0, 66527), -- Map: 0 - Phase: 25483
(2778435, 0, 25483, 0, 0, 66527), -- Map: 0 - Phase: 25483
(2802488, 0, 25483, 0, 0, 66527), -- Map: 0 - Phase: 25483
(2802231, 0, 25483, 0, 0, 66527), -- Map: 0 - Phase: 25483
(2778540, 0, 25483, 0, 0, 66527), -- Map: 0 - Phase: 25483
(2709058, 0, 25483, 0, 0, 66527), -- Map: 0 - Phase: 25483
(2802910, 0, 25483, 0, 0, 66527), -- Map: 0 - Phase: 25483
(2871546, 0, 25483, 0, 0, 66527), -- Map: 0 - Phase: 25483
(2709721, 0, 25483, 0, 0, 66527), -- Map: 0 - Phase: 25483
(2774202, 0, 25483, 0, 0, 66527), -- Map: 0 - Phase: 25483
(2774167, 0, 25483, 0, 0, 66527), -- Map: 0 - Phase: 25483
(2838351, 0, 0, 0, 0, 66527), -- Map: 0 - Phase: 0
(2713491, 0, 0, 0, 0, 66527), -- Map: 0 - Phase: 0
(2713493, 0, 0, 0, 0, 66527), -- Map: 0 - Phase: 0
(2804298, 0, 26475, 0, 0, 66527), -- Map: 0 - Phase: 26475
(2713492, 0, 0, 0, 0, 66527), -- Map: 0 - Phase: 0
(2804297, 0, 26475, 0, 0, 66527), -- Map: 0 - Phase: 26475
(2804296, 0, 26475, 0, 0, 66527), -- Map: 0 - Phase: 26475
(2804280, 0, 26475, 0, 0, 66527), -- Map: 0 - Phase: 26475
(2804267, 0, 26475, 0, 0, 66527), -- Map: 0 - Phase: 26475
(2804295, 0, 26475, 0, 0, 66527), -- Map: 0 - Phase: 26475
(2819832, 0, 26633, 0, 0, 66527), -- Map: 0 - Phase: 26633
(2809738, 0, 0, 0, 0, 66527), -- Map: 0 - Phase: 0
(2709096, 0, 27509, 0, 0, 66527), -- Map: 0 - Phase: 27509
(2863840, 0, 0, 0, 0, 66527), -- Map: 0 - Phase: 0
(2811096, 0, 26332, 0, 0, 66527), -- Map: 0 - Phase: 26332
(2734836, 0, 27520, 0, 0, 66527), -- Map: 0 - Phase: 27520
(2819831, 0, 26600, 0, 0, 66527), -- Map: 0 - Phase: 26600
(3019762, 0, 0, 0, 0, 66527), -- Map: 0 - Phase: 0
(2779289, 0, 26281, 0, 0, 66527), -- Map: 0 - Phase: 26281
(2744503, 0, 0, 0, 0, 66527), -- Map: 0 - Phase: 0
(2744497, 0, 0, 0, 0, 66527), -- Map: 0 - Phase: 0
(2744116, 0, 0, 0, 0, 66527), -- Map: 0 - Phase: 0
(2770819, 0, 0, 0, 0, 66527), -- Map: 0 - Phase: 0
(2705994, 0, 0, 0, 0, 66527), -- Map: 0 - Phase: 0
(2813884, 0, 0, 0, 0, 66527), -- Map: 0 - Phase: 0
(2783351, 0, 26332, 0, 0, 66527), -- Map: 0 - Phase: 26332
(2734838, 0, 0, 0, 0, 66527), -- Map: 0 - Phase: 0
(2734837, 0, 26332, 0, 0, 66527), -- Map: 0 - Phase: 26332
(2705824, 0, 25989, 0, 0, 66527), -- Map: 0 - Phase: 25989
(2770825, 0, 0, 0, 0, 66527), -- Map: 0 - Phase: 0
(2819309, 0, 0, 0, 0, 66527); -- Map: 0 - Phase: 0

UPDATE `spawn_tracking_template` SET `MapId`=2783, `VerifiedBuild`=66527 WHERE `SpawnTrackingId` IN (1483954, 1051130, 1165906, 1237927, 1175420, 1216496, 1063686, 1266169); -- Map: 2783 - Phase: 0

DELETE FROM `spawn_tracking_quest_objective` WHERE (`SpawnTrackingId`=2811039 AND `QuestObjectiveId`=460905) OR (`SpawnTrackingId`=2774240 AND `QuestObjectiveId`=460904) OR (`SpawnTrackingId`=2709092 AND `QuestObjectiveId`=460903) OR (`SpawnTrackingId`=2709721 AND `QuestObjectiveId`=461366) OR (`SpawnTrackingId`=2774202 AND `QuestObjectiveId`=461365) OR (`SpawnTrackingId`=2774167 AND `QuestObjectiveId`=460927) OR (`SpawnTrackingId`=2838351 AND `QuestObjectiveId`=462104) OR (`SpawnTrackingId`=2809738 AND `QuestObjectiveId` IN (461632,461631,461630)) OR (`SpawnTrackingId`=2819832 AND `QuestObjectiveId`=461973) OR (`SpawnTrackingId`=2811096 AND `QuestObjectiveId`=461787) OR (`SpawnTrackingId`=2734836 AND `QuestObjectiveId`=461786) OR (`SpawnTrackingId`=2819831 AND `QuestObjectiveId`=461785) OR (`SpawnTrackingId`=2770819 AND `QuestObjectiveId`=459995) OR (`SpawnTrackingId`=2705994 AND `QuestObjectiveId`=458712) OR (`SpawnTrackingId`=2813884 AND `QuestObjectiveId`=461808) OR (`SpawnTrackingId`=2783351 AND `QuestObjectiveId`=461635) OR (`SpawnTrackingId`=2734838 AND `QuestObjectiveId`=458747) OR (`SpawnTrackingId`=2734837 AND `QuestObjectiveId`=458743) OR (`SpawnTrackingId`=2744503 AND `QuestObjectiveId`=459457) OR (`SpawnTrackingId`=2744497 AND `QuestObjectiveId`=459456) OR (`SpawnTrackingId`=2744116 AND `QuestObjectiveId`=459455);
INSERT INTO `spawn_tracking_quest_objective` (`SpawnTrackingId`, `QuestObjectiveId`, `VerifiedBuild`) VALUES
(2811039, 460905, 66527), -- 2811039
(2774240, 460904, 66527), -- 2774240
(2709092, 460903, 66527), -- 2709092
(2709721, 461366, 66527), -- 2709721
(2774202, 461365, 66527), -- 2774202
(2774167, 460927, 66527), -- 2774167
(2838351, 462104, 66527), -- 2838351
(2809738, 461632, 66527), -- 2809738
(2809738, 461631, 66527), -- 2809738
(2809738, 461630, 66527), -- 2809738
(2819832, 461973, 66527), -- 2819832
(2811096, 461787, 66527), -- 2811096
(2734836, 461786, 66527), -- 2734836
(2819831, 461785, 66527), -- 2819831
(2770819, 459995, 66527), -- 2770819
(2705994, 458712, 66527), -- 2705994
(2813884, 461808, 66527), -- 2813884
(2783351, 461635, 66527), -- 2783351
(2734838, 458747, 66527), -- 2734838
(2734837, 458743, 66527), -- 2734837
(2744503, 459457, 66527), -- 2744503
(2744497, 459456, 66527), -- 2744497
(2744116, 459455, 66527); -- 2744116


DELETE FROM `creature_template_gossip` WHERE (`MenuID`=38883 AND `CreatureID` IN (243984,236686)) OR (`MenuID`=39451 AND `CreatureID`=245004) OR (`MenuID`=38533 AND `CreatureID`=239405) OR (`MenuID`=38763 AND `CreatureID`=236087) OR (`MenuID`=38536 AND `CreatureID`=236149) OR (`MenuID`=39389 AND `CreatureID`=242568) OR (`MenuID`=38670 AND `CreatureID`=239406);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(243984, 38883, 66527), -- Arator
(236686, 38883, 66527), -- Arator
(245004, 39451, 66527), -- Lord Antenorian
(239405, 38533, 66527), -- Secretary Faloria
(236087, 38763, 66527), -- Magister Umbric
(236149, 38536, 66527), -- Innkeeper Kalarin
(242568, 39389, 66527), -- Matron Narsilla
(239406, 38670, 66527); -- Ranger Belonis

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (38763,39451,38670,39389,38536,38533)) OR (`OptionID`=1 AND `MenuID` IN (39451,38536,38763)) OR (`OptionID`=2 AND `MenuID`=38536);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(38763, 134206, 0, 0, 'How do you know the corpse we found?', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66527),
(39451, 134002, 0, 0, '<Tell Lord Antenorian everything.>', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66527),
(38670, 132894, 0, 0, 'You\'ve had scouts go missing?', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66527),
(39389, 133913, 0, 0, 'What problems ail the people of Tranquillien?', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66527),
(39451, 134001, 1, 0, '<Lie to Lord Antenorian about how much you know.>', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66527),
(38536, 137856, 1, 5, 'Bind your hearthstone to this inn.', 2822, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66527),
(38536, 137854, 2, 1, 'What do you have for sale?', 10182, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66527), -- OptionBroadcastTextID: 10182 - 16129 - 16134 - 16135 - 16452 - 20994 - 53758 - 66614 - 117193 - 122305 - 122306
(38763, 134207, 1, 0, 'How do you know the Governor of Tranquillien?', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66527),
(38536, 132744, 0, 0, 'Have you seen anything strange recently?', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66527),
(38533, 132741, 0, 0, 'We need to speak to Lord Antenorian.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66527);



DELETE FROM `conversation_line_template` WHERE `Id` IN (79781, 82294, 82095, 82094, 82093, 82372, 82371, 82370, 82291);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(79781, 0, 0, 0, 0, 66709),
(82294, 0, 3, 0, 0, 66709),
(82095, 0, 2, 0, 0, 66709),
(82094, 0, 1, 0, 0, 66709),
(82093, 0, 0, 0, 0, 66709),
(82372, 0, 2, 0, 0, 66709),
(82371, 0, 1, 0, 0, 66709),
(82370, 0, 0, 0, 0, 66709),
(82291, 0, 0, 0, 0, 66709);


DELETE FROM `conversation_line_template` WHERE `Id` IN (80815, 91390, 80009, 80008, 82101, 90708, 80163, 80162, 79839, 87577, 87576, 91563, 81832, 79841, 80613, 80726, 88769, 82100, 86342, 86341, 86340, 86339, 86338, 82087);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(80815, 0, 1, 0, 0, 66709),
(91390, 0, 0, 0, 0, 66709),
(80009, 0, 0, 0, 0, 66709),
(80008, 0, 0, 0, 0, 66709),
(82101, 0, 0, 0, 0, 66709),
(90708, 0, 2, 0, 0, 66709),
(80163, 0, 1, 0, 0, 66709),
(80162, 0, 0, 0, 0, 66709),
(79839, 0, 0, 0, 0, 66709),
(87577, 0, 1, 0, 0, 66709),
(87576, 0, 0, 0, 0, 66709),
(91563, 0, 0, 0, 0, 66709),
(81832, 0, 0, 0, 0, 66709),
(79841, 0, 1, 0, 0, 66709),
(80613, 0, 0, 0, 0, 66709),
(80726, 0, 0, 0, 0, 66709),
(88769, 0, 1, 0, 0, 66709),
(82100, 0, 0, 0, 0, 66709),
(86342, 0, 0, 0, 0, 66709),
(86341, 0, 0, 0, 0, 66709),
(86340, 0, 0, 0, 0, 66709),
(86339, 0, 0, 0, 0, 66709),
(86338, 0, 0, 0, 0, 66709),
(82087, 0, 0, 0, 0, 66709);


DELETE FROM `quest_details` WHERE `ID` IN (86648 /*Light Guide Us*/, 86647 /*Beat of Blood*/, 86646 /*An Impasse*/, 86644 /*Gods Before Us*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(86648, 1, 0, 0, 0, 0, 0, 0, 0, 66709), -- Light Guide Us
(86647, 1, 0, 0, 0, 0, 0, 0, 0, 66709), -- Beat of Blood
(86646, 0, 0, 0, 0, 0, 0, 0, 0, 66709), -- An Impasse
(86644, 0, 0, 0, 0, 0, 0, 0, 0, 66709); -- Gods Before Us



UPDATE `quest_description_conditional` SET `VerifiedBuild`=66709 WHERE (`QuestId`=90835 AND `PlayerConditionId`=95784 AND `QuestgiverCreatureId`=0 AND `locale`='enUS') OR (`QuestId`=94933 AND `PlayerConditionId`=151288 AND `QuestgiverCreatureId`=257544 AND `locale`='enUS') OR (`QuestId`=82817 AND `PlayerConditionId`=34450 AND `QuestgiverCreatureId`=234556 AND `locale`='enUS');

DELETE FROM `creature_queststarter` WHERE (`id`=236612 AND `quest`=86648) OR (`id`=236737 AND `quest`=86647) OR (`id`=240662 AND `quest`=86646) OR (`id`=236610 AND `quest`=86644);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(236612, 86648, 66709), -- Light Guide Us offered by Lor'themar Theron
(236737, 86647, 66709), -- Beat of Blood offered by Arator
(240662, 86646, 66709), -- An Impasse offered by Assisting Paladin
(236610, 86644, 66709); -- Gods Before Us offered by Arator


DELETE FROM `spawn_tracking_template` WHERE `SpawnTrackingId` IN (2709424 /*Map: 0 - Phase: 26112*/, 2714847 /*Map: 0 - Phase: 26141*/, 2709428 /*Map: 0 - Phase: 0*/, 2814469 /*Map: 0 - Phase: 0*/, 3003150 /*Map: 0 - Phase: 0*/, 3003060 /*Map: 0 - Phase: 0*/, 3002259 /*Map: 0 - Phase: 0*/, 3002302 /*Map: 0 - Phase: 0*/);
INSERT INTO `spawn_tracking_template` (`SpawnTrackingId`, `MapId`, `PhaseId`, `PhaseGroup`, `PhaseUseFlags`, `VerifiedBuild`) VALUES
(2709424, 0, 26112, 0, 0, 66709), -- Map: 0 - Phase: 26112
(2714847, 0, 26141, 0, 0, 66709), -- Map: 0 - Phase: 26141
(2709428, 0, 0, 0, 0, 66709), -- Map: 0 - Phase: 0
(2814469, 0, 0, 0, 0, 66709), -- Map: 0 - Phase: 0
(3003150, 0, 0, 0, 0, 66709), -- Map: 0 - Phase: 0
(3003060, 0, 0, 0, 0, 66709), -- Map: 0 - Phase: 0
(3002259, 0, 0, 0, 0, 66709), -- Map: 0 - Phase: 0
(3002302, 0, 0, 0, 0, 66709); -- Map: 0 - Phase: 0


DELETE FROM `spawn_tracking_quest_objective` WHERE (`SpawnTrackingId`=2778557 AND `QuestObjectiveId`=462105) OR (`SpawnTrackingId`=2714491 AND `QuestObjectiveId`=462098) OR (`SpawnTrackingId`=2709428 AND `QuestObjectiveId`=457392) OR (`SpawnTrackingId`=2814469 AND `QuestObjectiveId`=460719);
INSERT INTO `spawn_tracking_quest_objective` (`SpawnTrackingId`, `QuestObjectiveId`, `VerifiedBuild`) VALUES
(2778557, 462105, 66709), -- 2778557
(2714491, 462098, 66709), -- 2714491
(2709428, 457392, 66709), -- 2709428
(2814469, 460719, 66709); -- 2814469

UPDATE `creature_model_info` SET `VerifiedBuild`=66709 WHERE `DisplayID` IN (123487, 136563, 139598, 132021, 132017, 113066, 89537, 128295, 137257, 137255, 137258, 137256, 131959, 4588, 137272, 109964, 78952, 136160, 80840, 137963, 124914, 114968, 125472, 84987, 80837, 125471, 114967, 125470, 80839, 107091, 112496, 114975, 136682, 138228, 131993, 138229, 131961, 136159, 124930, 131347, 131257);
UPDATE `creature_model_info` SET `BoundingRadius`=0.571933865547180175 WHERE `DisplayID`=125877;

DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=236738 AND `MenuID`=40546) OR (`CreatureID`=236610 AND `MenuID`=38653);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(236738, 40546, 66709), -- Arator
(236610, 38653, 66709); -- Arator


DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (38653,39345,40546,39344));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(38653, 132886, 0, 0, '<Stay silent.>', 0, 0, 5, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66709),
(39345, 133890, 0, 0, '<Place Bloodvein Clot into the vase.>', 0, 0, 1, 39345, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66709),
(40546, 135806, 0, 0, '<Stay awhile and listen.>', 137786, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66709), -- OptionBroadcastTextID: 137786 - 144263 - 160761 - 160763 - 160765 - 160768 - 167552 - 173473 - 176737 - 188459 - 202026 - 205118 - 205774
(39344, 133889, 0, 0, '<Place Bonecarapace Fangs into the vase.>', 0, 0, 1, 39344, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66709);

DELETE FROM `page_text` WHERE `ID`=9995;
INSERT INTO `page_text` (`ID`, `Text`, `NextPageID`, `PlayerConditionID`, `Flags`, `VerifiedBuild`) VALUES
(9995, 'Cursed Gurubashi bind us\nFang of Shadra pry the bars\nBlood of Hir\'eek mark the way\nBy their corpses we be freed', 0, 0, 0, 66709); -- 9995
