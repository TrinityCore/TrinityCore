SET @OGUID := 900000;
DELETE FROM `gameobject` WHERE `guid` = @OGUID+107;
INSERT INTO `gameobject` VALUES
(@OGUID+107, 553793, 2694, 15355, 0, 0, 0, 26622, 0, -1, 1255.01, 807.479, 1330.89, 1.68607, 0, 0, -0.746665, -0.6652, 300, 255, 1, 0, '', '', 0);


DELETE FROM `gameobject_loot_template` WHERE `Entry` = 553793;
INSERT INTO `gameobject_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES (553793, 0, 246112, 100, 0, 1, 0, 1, 1, 'Alliance Shield');

UPDATE `gameobject_template` SET `Data1`=553793 WHERE  `entry`=553793;

DELETE FROM `quest_offer_reward` WHERE `ID`=86735;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(86735, 1, 0, 0, 0, 0, 0, 0, 0, 'Remember, you are a guest here. Your aid is appreciated, but our rules must be followed while you are within these walls.', 66263); -- Paved in Ash


DELETE FROM `quest_details` WHERE `ID` IN (86737 /*Fair Breeze, Light Bloom*/, 86735 /*Paved in Ash*/, 86734 /*Diplomacy*/, 86733 /*Silvermoon Negotiations*/, 86852 /*Light's Last Stand*/, 86850 /*Broken Sun*/, 86849 /*Wrath Unleashed*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(86737, 1, 0, 0, 0, 0, 0, 0, 0, 66263), -- Fair Breeze, Light Bloom
(86735, 1, 0, 0, 0, 0, 0, 0, 0, 66263), -- Paved in Ash
(86734, 1, 0, 0, 0, 0, 0, 0, 0, 66263), -- Diplomacy
(86733, 1, 0, 0, 0, 0, 0, 0, 0, 66263), -- Silvermoon Negotiations
(86852, 0, 0, 0, 0, 0, 0, 0, 0, 66263), -- Light's Last Stand
(86850, 0, 0, 0, 0, 0, 0, 0, 0, 66263), -- Broken Sun
(86849, 0, 0, 0, 0, 0, 0, 0, 0, 66263); -- Wrath Unleashed


DELETE FROM `creature_queststarter` WHERE (`id`=235787 AND `quest` IN (86737,86735,86734)) OR (`id`=236779 AND `quest`=86733) OR (`id`=237278 AND `quest`=86852) OR (`id`=237277 AND `quest`=86850) OR (`id`=236978 AND `quest`=86849);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(235787, 86737, 66263), -- Fair Breeze, Light Bloom offered by Lor'themar Theron
(235787, 86735, 66263), -- Paved in Ash offered by Lor'themar Theron
(235787, 86734, 66263), -- Diplomacy offered by Lor'themar Theron
(236779, 86733, 66263), -- Silvermoon Negotiations offered by Lor'themar Theron
(237278, 86852, 66263), -- Light's Last Stand offered by Lady Liadrin
(237277, 86850, 66263), -- Broken Sun offered by Lady Liadrin
(236978, 86849, 66263); -- Wrath Unleashed offered by High Exarch Turalyon



DELETE FROM `creature_questender` WHERE (`id`=235787 AND `quest`=86735);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(235787, 86735, 66263); -- Paved in Ash ended by Lor'themar Theron

UPDATE `creature_questender` SET `VerifiedBuild`=66263 WHERE (`id`=235787 AND `quest` IN (86734,86733)) OR (`id`=241068 AND `quest`=86852) OR (`id`=237278 AND `quest`=86850) OR (`id`=237277 AND `quest`=86849) OR (`id`=237253 AND `quest`=86848) OR (`id`=236978 AND `quest`=86811);

DELETE FROM `spawn_tracking_template` WHERE `SpawnTrackingId` IN (2911274 /*Map: 0 - Phase: 27260*/, 2768304 /*Map: 0 - Phase: 0*/, 2736095 /*Map: 0 - Phase: 0*/, 2735873 /*Map: 0 - Phase: 0*/, 2736111 /*Map: 0 - Phase: 0*/, 2735789 /*Map: 0 - Phase: 0*/, 2709775 /*Map: 0 - Phase: 26050*/, 2735695 /*Map: 0 - Phase: 0*/, 2713646 /*Map: 0 - Phase: 0*/, 3028339 /*Map: 0 - Phase: 0*/, 2768893 /*Map: 0 - Phase: 26050*/, 2713642 /*Map: 2858 - Phase: 26779*/, 2714512 /*Map: 2858 - Phase: 26127*/, 2713601 /*Map: 2858 - Phase: 26779*/);
INSERT INTO `spawn_tracking_template` (`SpawnTrackingId`, `MapId`, `PhaseId`, `PhaseGroup`, `PhaseUseFlags`, `VerifiedBuild`) VALUES
(2911274, 0, 27260, 0, 0, 66263), -- Map: 0 - Phase: 27260
(2768304, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2736095, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2735873, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2736111, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2735789, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2709775, 0, 26050, 0, 0, 66263), -- Map: 0 - Phase: 26050
(2735695, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2713646, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(3028339, 0, 0, 0, 0, 66263), -- Map: 0 - Phase: 0
(2768893, 0, 26050, 0, 0, 66263), -- Map: 0 - Phase: 26050
(2713642, 2858, 26779, 0, 0, 66263), -- Map: 2858 - Phase: 26779
(2714512, 2858, 26127, 0, 0, 66263), -- Map: 2858 - Phase: 26127
(2713601, 2858, 26779, 0, 0, 66263); -- Map: 2858 - Phase: 26779

UPDATE `spawn_tracking_template` SET `MapId`=0 WHERE `SpawnTrackingId`=2740685;
UPDATE `spawn_tracking_template` SET `MapId`=0, `PhaseId`=27551 WHERE `SpawnTrackingId`=3035217; -- Map: 0 - Phase: 27551
UPDATE `spawn_tracking_template` SET `MapId`=0, `PhaseId`=26881 WHERE `SpawnTrackingId`=2708164; -- Map: 0 - Phase: 26881
UPDATE `spawn_tracking_template` SET `MapId`=0, `PhaseId`=27731, `VerifiedBuild`=66263 WHERE `SpawnTrackingId`=3033381; -- Map: 0 - Phase: 27731 (Cosmetic - See Liadrin, Turalyon & Theron in The Bazaar, Silvermoon City)
UPDATE `spawn_tracking_template` SET `MapId`=0, `VerifiedBuild`=66263 WHERE `SpawnTrackingId` IN (2773842, 3023553); -- Map: 0 - Phase: 0
UPDATE `spawn_tracking_template` SET `MapId`=0, `PhaseId`=27732, `VerifiedBuild`=66263 WHERE `SpawnTrackingId`=3023462; -- Map: 0 - Phase: 27732 (Cosmetic - See Liadrin, Turalyon & Theron in Cathedral Square, Stormwind City)
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=66263 WHERE `SpawnTrackingId` IN (3033381, 2773842, 3023553, 3023462, 2712369, 2713591, 2768199);
UPDATE `spawn_tracking_template` SET `MapId`=2858 WHERE `SpawnTrackingId` IN (1483954, 1165906, 1237927, 1175420, 1216496, 1063686, 1266169);

DELETE FROM `spawn_tracking_quest_objective` WHERE (`SpawnTrackingId`=2911274 AND `QuestObjectiveId`=464102) OR (`SpawnTrackingId`=2768304 AND `QuestObjectiveId`=459731) OR (`SpawnTrackingId`=2781800 AND `QuestObjectiveId`=460916) OR (`SpawnTrackingId`=2736095 AND `QuestObjectiveId`=459711) OR (`SpawnTrackingId`=2735873 AND `QuestObjectiveId`=459710) OR (`SpawnTrackingId`=2736111 AND `QuestObjectiveId`=459709) OR (`SpawnTrackingId`=2735789 AND `QuestObjectiveId`=459708) OR (`SpawnTrackingId`=2704580 AND `QuestObjectiveId`=459139) OR (`SpawnTrackingId`=2735695 AND `QuestObjectiveId`=458775) OR (`SpawnTrackingId`=3028339 AND `QuestObjectiveId`=460174) OR (`SpawnTrackingId`=2714512 AND `QuestObjectiveId`=457508);
INSERT INTO `spawn_tracking_quest_objective` (`SpawnTrackingId`, `QuestObjectiveId`, `VerifiedBuild`) VALUES
(2911274, 464102, 66263), -- 2911274
(2768304, 459731, 66263), -- 2768304
(2781800, 460916, 66263), -- 2781800
(2736095, 459711, 66263), -- 2736095
(2735873, 459710, 66263), -- 2735873
(2736111, 459709, 66263), -- 2736111
(2735789, 459708, 66263), -- 2735789
(2704580, 459139, 66263), -- 2704580
(2735695, 458775, 66263), -- 2735695
(3028339, 460174, 66263), -- 3028339
(2714512, 457508, 66263); -- 2714512


UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=11 WHERE (`DifficultyID`=0 AND `Entry` IN (242566,242550)); -- Lorewalker Initiate
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=11 WHERE (`Entry`=32520 AND `DifficultyID`=0); -- Totally Generic Bunny (All Phase)
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=11 WHERE (`Entry`=230765 AND `DifficultyID`=0); -- Dracthyr Occultist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=11 WHERE (`Entry`=151937 AND `DifficultyID`=0); -- Portal Controller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=11 WHERE (`Entry`=230737 AND `DifficultyID`=0); -- Dracthyr Thaumaturge
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=11 WHERE (`Entry`=99541 AND `DifficultyID`=0); -- Risen Skulker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=11 WHERE (`Entry`=205879 AND `DifficultyID`=0); -- Ethereal Warpweaver


DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=240936 AND `MenuID`=38604) OR (`CreatureID`=242381 AND `MenuID`=38820) OR (`CreatureID`=239639 AND `MenuID`=38475) OR (`CreatureID`=239630 AND `MenuID`=38471) OR (`CreatureID`=261304 AND `MenuID`=42681) OR (`CreatureID`=239673 AND `MenuID`=38477) OR (`CreatureID`=239664 AND `MenuID`=38476) OR (`CreatureID`=248629 AND `MenuID`=40066) OR (`CreatureID`=235787 AND `MenuID`=38452) OR (`CreatureID`=237278 AND `MenuID`=38691) OR (`CreatureID`=237255 AND `MenuID`=38943);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(240936, 38604, 66263), -- Guard Captain Goldblade
(242381, 38820, 66263), -- Valeera Sanguinar
(239639, 38475, 66263), -- Skymaster Skyles
(239630, 38471, 66263), -- Innkeeper Jovia
(261304, 42681, 66263), -- Archmage Celindra
(239673, 38477, 66263), -- Magistrix Narinth
(239664, 38476, 66263), -- Ceera
(248629, 40066, 66263), -- General Amias Bellamy
(235787, 38452, 66263), -- Lor'themar Theron
(237278, 38691, 66263), -- Lady Liadrin
(237255, 38943, 66263); -- High Exarch Turalyon


DELETE FROM `npc_vendor` WHERE (`entry`=239630 AND `item`=260264 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=239630 AND `item`=260263 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=239630 AND `item`=260262 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=239630 AND `item`=260261 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=239630 AND `item`=260260 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=239630 AND `item`=260257 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=239630 AND `item`=260256 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=239630 AND `item`=260259 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=239630 AND `item`=260258 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=239630 AND `item`=260255 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=239630 AND `item`=260254 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(239630, 11, 260264, 0, 0, 1, 0, 0, 66263), -- 260264
(239630, 10, 260263, 0, 0, 1, 0, 0, 66263), -- 260263
(239630, 9, 260262, 0, 0, 1, 0, 0, 66263), -- 260262
(239630, 8, 260261, 0, 0, 1, 0, 0, 66263), -- 260261
(239630, 7, 260260, 0, 0, 1, 0, 0, 66263), -- 260260
(239630, 6, 260257, 0, 0, 1, 0, 0, 66263), -- 260257
(239630, 5, 260256, 0, 0, 1, 0, 0, 66263), -- 260256
(239630, 4, 260259, 0, 0, 1, 0, 0, 66263), -- 260259
(239630, 3, 260258, 0, 0, 1, 0, 0, 66263), -- 260258
(239630, 2, 260255, 0, 0, 1, 0, 0, 66263), -- 260255
(239630, 1, 260254, 0, 0, 1, 0, 0, 66263); -- 260254


DELETE FROM `gossip_menu` WHERE (`MenuID`=38475 AND `TextID`=7778) OR (`MenuID`=38471 AND `TextID`=8618) OR (`MenuID`=42681 AND `TextID`=30684) OR (`MenuID`=38477 AND `TextID`=5879) OR (`MenuID`=38476 AND `TextID`=9564);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(38475, 7778, 66263), -- 239639 (Skymaster Skyles)
(38471, 8618, 66263), -- 239630 (Innkeeper Jovia)
(42681, 30684, 66263), -- 261304 (Archmage Celindra)
(38477, 5879, 66263), -- 239673 (Magistrix Narinth)
(38476, 9564, 66263); -- 239664 (Ceera)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=1 AND `MenuID` IN (38452,38477,38471,38820,38476,38475)) OR (`OptionID`=0 AND `MenuID` IN (40066,38943,38820,38471,38452,38475,38476,38604,38691)) OR (`OptionID`=2 AND `MenuID`=38471);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(38452, 132632, 1, 0, '|cFFFF0000<Skip conversation>|r I expect you\'ll sort things out.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263),
(38477, 132678, 1, 0, 'Lor\'themar has allowed us to stay in the city for the time being. We\'ll need access to your portals.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263),
(40066, 135224, 0, 0, '<Offer greeting.>', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263),
(38943, 133285, 0, 0, 'Let\'s drive this threat back!', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263),
(38471, 132667, 1, 1, 'Let me browse your goods.', 2823, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(38820, 133099, 0, 0, 'Lor\'themar will need the services of the Reliquary.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263),
(38471, 132668, 0, 5, 'Bind your hearthstone to this inn.', 2822, 0, 0, 0, 0, 58723, 0, 0, NULL, 0, NULL, NULL, 66263),
(38820, 136352, 1, 0, 'Remind me who you are.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263),
(38471, 132666, 2, 0, 'Lor\'themar has allowed us to stay for now. We\'ll need lodging.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263),
(38452, 132633, 0, 0, '<Listen to the discussion.>', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263),
(38476, 132676, 1, 0, 'Lor\'themar has requested that we be allowed to use your services.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263),
(38475, 132674, 1, 0, 'Lor\'themar has requested that we be allowed to use your dragonhawks for travel.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263),
(38475, 132675, 0, 2, 'Show me where I can fly.', 12271, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263), -- OptionBroadcastTextID: 12271 - 140511 - 158191
(38476, 132677, 0, 6, 'I would like to check my deposit box.', 3398, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263),
(38604, 132828, 0, 0, 'The Alliance will be staying here slightly longer than expected.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263),
(38691, 132924, 0, 0, 'Nothing will get past me!', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66263);


DELETE FROM `conversation_actors` WHERE (`ConversationId`=32695 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(32695, 109989, 0, 233708, 131513, 0, 0, 66263);


DELETE FROM `conversation_line_template` WHERE `Id`=90677;
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(90677, 126, 0, 0, 0, 66263);


DELETE FROM `conversation_template` WHERE `Id`=32695;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(32695, 90677, 0, 66263);

DELETE FROM `areatrigger_template` WHERE (`Id`=38964 AND `IsCustom`=0);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `VerifiedBuild`) VALUES
(38964, 0, 66709);

DELETE FROM `quest_offer_reward` WHERE `ID`=93784;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(93784, 0, 0, 0, 0, 0, 0, 0, 0, 'An extraordinary find. The arcane energies emanating from your discovery clearly predate the Shattering... We could learn much from such artifacts.\n\nChampion! Fantastic work! If you happen upon any more during your expeditions, please bring your findings back to me.', 66709); -- A Gnawing Void of Curiosity

DELETE FROM `quest_details` WHERE `ID` IN (91822 /*The Regent's Request*/, 93385 /*Delver's Call: The Darkway*/, 93386 /*Delver's Call: Parhelion Plaza*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(91822, 0, 0, 0, 0, 0, 0, 0, 0, 66709), -- The Regent's Request
(93385, 1, 0, 0, 0, 0, 0, 0, 0, 66709), -- Delver's Call: The Darkway
(93386, 1, 0, 0, 0, 0, 0, 0, 0, 66709); -- Delver's Call: Parhelion Plaza

DELETE FROM `creature_queststarter` WHERE (`id`=242381 AND `quest`=91822);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(242381, 91822, 66709); -- The Regent's Request offered by Valeera Sanguinar

DELETE FROM `creature_questender` WHERE (`id`=242398 AND `quest`=93784);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(242398, 93784, 66709); -- A Gnawing Void of Curiosity ended by Naleidea Rivergleam

DELETE FROM `gameobject_queststarter` WHERE (`id`=612039 AND `quest`=93385) OR (`id`=612894 AND `quest`=93386);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(612039, 93385, 66709), -- Delver's Call: The Darkway offered by -Unknown-
(612894, 93386, 66709); -- Delver's Call: Parhelion Plaza offered by -Unknown-


UPDATE `creature_model_info` SET `VerifiedBuild`=66709 WHERE `DisplayID` IN (31174, 28282, 28111, 136878, 138873, 137598, 137054, 142928, 142927, 138870, 138871, 138869, 136695, 136532, 136660, 138872, 136527, 136669, 136666, 123613, 136659, 136665, 136546, 136543, 136662, 112141, 112165, 136681, 138547, 140227, 136562, 136713, 85939, 137092, 136556, 136737, 136738, 136296, 136739, 136735, 126435, 136734, 128953, 136696, 137667, 137524, 141877, 139428, 139426, 138852, 138930, 141698, 141800, 136918, 139427, 137044, 139430, 137097, 136902, 142232, 59131, 107365, 136905, 136892, 139926, 106643, 136885, 61133, 136719, 136540, 38804, 136776, 25983, 137043, 131798, 138853, 121108, 137089, 138855, 138865, 139421, 131794, 105169, 136716, 137086, 102040, 138868, 140886, 89801, 119100, 107574, 137042, 118073, 136922, 141432, 138249, 137178, 26365, 108870, 16925, 108777, 138285, 137088, 138864, 138861, 139899, 138275, 139898, 130341, 107560, 119222, 138273, 115505, 136524, 142190, 139429, 120336, 137144, 33479, 138848, 85526, 112146, 111139, 112147, 141673, 138591);
UPDATE `creature_model_info` SET `BoundingRadius`=0.158240109682083129, `CombatReach`=0.300000011920928955, `VerifiedBuild`=66709 WHERE `DisplayID` IN (120521, 120520);
UPDATE `creature_model_info` SET `BoundingRadius`=0.57750016450881958, `CombatReach`=0.533333361148834228 WHERE `DisplayID`=127895;

DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=249041 AND `MenuID`=34385) OR (`CreatureID`=243229 AND `MenuID`=41495) OR (`CreatureID`=242398 AND `MenuID`=41594) OR (`CreatureID`=242381 AND `MenuID`=38820);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(249041, 34385, 66709), -- Sandee Seabraid
(243229, 41495, 66709), -- Eldara Dawnrunner
(242398, 41594, 66709), -- Naleidea Rivergleam
(242381, 38820, 66709); -- Valeera Sanguinar


DELETE FROM `npc_vendor` WHERE (`entry`=242398 AND `item`=264652 AND `ExtendedCost`=11290 AND `type`=1) OR (`entry`=242398 AND `item`=248755 AND `ExtendedCost`=11302 AND `type`=1) OR (`entry`=242398 AND `item`=233061 AND `ExtendedCost`=11302 AND `type`=1) OR (`entry`=242398 AND `item`=246779 AND `ExtendedCost`=11313 AND `type`=1) OR (`entry`=242398 AND `item`=250770 AND `ExtendedCost`=11313 AND `type`=1) OR (`entry`=242398 AND `item`=262990 AND `ExtendedCost`=11299 AND `type`=1) OR (`entry`=242398 AND `item`=262973 AND `ExtendedCost`=11299 AND `type`=1) OR (`entry`=242398 AND `item`=262989 AND `ExtendedCost`=11299 AND `type`=1) OR (`entry`=242398 AND `item`=262984 AND `ExtendedCost`=11299 AND `type`=1) OR (`entry`=242398 AND `item`=264853 AND `ExtendedCost`=11299 AND `type`=1) OR (`entry`=242398 AND `item`=264860 AND `ExtendedCost`=11299 AND `type`=1) OR (`entry`=242398 AND `item`=264856 AND `ExtendedCost`=11300 AND `type`=1) OR (`entry`=242398 AND `item`=264849 AND `ExtendedCost`=11299 AND `type`=1) OR (`entry`=242398 AND `item`=262431 AND `ExtendedCost`=11301 AND `type`=1) OR (`entry`=242398 AND `item`=262963 AND `ExtendedCost`=11300 AND `type`=1) OR (`entry`=242398 AND `item`=262393 AND `ExtendedCost`=11298 AND `type`=1) OR (`entry`=242398 AND `item`=262502 AND `ExtendedCost`=11298 AND `type`=1) OR (`entry`=242398 AND `item`=244193 AND `ExtendedCost`=11303 AND `type`=1) OR (`entry`=242398 AND `item`=253342 AND `ExtendedCost`=11152 AND `type`=1) OR (`entry`=242398 AND `item`=263191 AND `ExtendedCost`=11053 AND `type`=1) OR (`entry`=242398 AND `item`=263188 AND `ExtendedCost`=11053 AND `type`=1) OR (`entry`=242398 AND `item`=267291 AND `ExtendedCost`=11377 AND `type`=1) OR (`entry`=242398 AND `item`=263178 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(242398, 46, 264652, 0, 11290, 1, 0, 0, 66709), -- 264652
(242398, 45, 248755, 0, 11302, 1, 0, 0, 66709), -- 248755
(242398, 44, 233061, 0, 11302, 1, 0, 0, 66709), -- 233061
(242398, 43, 246779, 0, 11313, 1, 0, 0, 66709), -- 246779
(242398, 42, 250770, 0, 11313, 1, 0, 0, 66709), -- 250770
(242398, 41, 262990, 0, 11299, 1, 0, 0, 66709), -- 262990
(242398, 40, 262973, 0, 11299, 1, 0, 0, 66709), -- 262973
(242398, 39, 262989, 0, 11299, 1, 0, 0, 66709), -- 262989
(242398, 38, 262984, 0, 11299, 1, 0, 0, 66709), -- 262984
(242398, 37, 264853, 0, 11299, 1, 0, 0, 66709), -- 264853
(242398, 36, 264860, 0, 11299, 1, 0, 0, 66709), -- 264860
(242398, 35, 264856, 0, 11300, 1, 0, 0, 66709), -- 264856
(242398, 34, 264849, 0, 11299, 1, 0, 0, 66709), -- 264849
(242398, 33, 262431, 0, 11301, 1, 0, 0, 66709), -- 262431
(242398, 32, 262963, 0, 11300, 1, 0, 0, 66709), -- 262963
(242398, 31, 262393, 0, 11298, 1, 0, 0, 66709), -- 262393
(242398, 30, 262502, 0, 11298, 1, 0, 0, 66709), -- 262502
(242398, 29, 244193, 0, 11303, 1, 0, 0, 66709), -- 244193
(242398, 28, 253342, 0, 11152, 1, 0, 0, 66709), -- 253342
(242398, 27, 263191, 0, 11053, 1, 148887, 0, 66709), -- 263191
(242398, 26, 263188, 0, 11053, 1, 148888, 0, 66709), -- 263188
(242398, 25, 267291, 0, 11377, 1, 0, 1, 66709), -- 267291
(242398, 24, 263178, 0, 0, 1, 0, 0, 66709); -- 263178


UPDATE `gossip_menu` SET `VerifiedBuild`=66709 WHERE (`MenuID`=34385 AND `TextID`=600017);
DELETE FROM `gossip_menu_option` WHERE (`OptionID`=1 AND `MenuID` IN (34385,38820)) OR (`OptionID`=0 AND `MenuID` IN (41594,41495)) OR (`OptionID`=2 AND `MenuID`=41594);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(34385, 121665, 1, 47, 'I\'d like to see what you have to offer this month.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66709),
(38820, 136352, 1, 0, 'Remind me who you are.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66709),
(41594, 137445, 0, 1, 'What does the Reliquary have to offer?', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66709),
(41594, 137442, 2, 1, 'What does the Reliquary have to offer?', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66709),
(41495, 137257, 0, 0, 'What does it do?', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66709);


SET @CGUID = 677000;
SET @OGUID = 220000;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1893;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 246066, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11371.9892578125, -4361.65283203125, 18.39295196533203125, 2.559302568435668945, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Commander Koruth Mountainfist (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+1, 241312, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11375.404296875, -4239.6787109375, 144.839630126953125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic - Empty Bunny (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+2, 245749, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11486.3974609375, -4394.99462890625, 61.07718658447265625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Pillaging Drifter (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 1239348 - 1239348)
(@CGUID+3, 246048, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11354.9033203125, -4360.9931640625, 18.46858596801757812, 1.324376106262207031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Grand Vindicator Sorvos (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+4, 241022, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11442.796875, -4431.26220703125, 16.26041793823242187, 1.611695528030395507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Reach Artisan (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 154470 - 154470)
(@CGUID+5, 243157, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11334.8056640625, -4301.76220703125, 4.902080535888671875, 3.17487192153930664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Light's Vanguard (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 154470 - 154470)
(@CGUID+6, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11343.1904296875, -4432.24462890625, 18.36854171752929687, 0.207699298858642578, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+7, 236978, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11390.9150390625, -4385.61474609375, 16.32988548278808593, 5.347464561462402343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- High Exarch Turalyon (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+8, 240665, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11487.7236328125, -4264.158203125, 12.87601757049560546, 2.534833431243896484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Berserker (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+9, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11355.8369140625, -4469.1162109375, 20.85551643371582031, 0.456636250019073486, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+10, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11427.0830078125, -4320.68603515625, 18.5595703125, 2.15972137451171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+11, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11423.8330078125, -4322.4306640625, 18.91295433044433593, 2.45787811279296875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+12, 238856, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11363.314453125, -4350.71826171875, 18.4288177490234375, 2.148640632629394531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidfront Pummeler (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590, 1252117 - 1252117, 1251577 - 1251577)
(@CGUID+13, 239416, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11374.734375, -4395.59033203125, 16.32988548278808593, 5.63163614273071289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Lothraxion (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+14, 240887, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11379.6826171875, -4391.84716796875, 16.32988548278808593, 0.427430421113967895, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Faerin Lothar (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+15, 240886, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11395.8115234375, -4376.1318359375, 16.32988548278808593, 0.367681890726089477, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Alonsus Faol (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+16, 245707, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11344.6484375, -4460.32666015625, 20.85549545288085937, 1.299799919128417968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Spoiler (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 1239277 - 1239277)
(@CGUID+17, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11443.6865234375, -4465.12158203125, 14.99981689453125, 1.577628135681152343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+18, 240601, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11248.5458984375, -4418.82666015625, 4.59364175796508789, 0.706317126750946044, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Blightclaw (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+19, 237253, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11392.3564453125, -4380.611328125, 16.32988548278808593, 4.452420234680175781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Lady Liadrin (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+20, 241312, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11325.4658203125, -4297.8125, 144.839630126953125, 6.283185005187988281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic - Empty Bunny (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+21, 245706, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11349.7470703125, -4464.37353515625, 45.90673446655273437, 3.79882979393005371, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Fatestealer (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+22, 243157, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11354.3857421875, -4296.9912109375, 4.864032745361328125, 6.030802726745605468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Light's Vanguard (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 154470 - 154470)
(@CGUID+23, 241022, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11421.9384765625, -4321.46533203125, 19.03808212280273437, 1.611695528030395507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Reach Artisan (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 154470 - 154470)
(@CGUID+24, 240915, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11354.2783203125, -4469.548828125, 21.43450355529785156, 1.79987490177154541, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Infinity Blades (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 1226216 - 1226216)
(@CGUID+25, 240921, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11462.466796875, -4378.3037109375, 44.48894882202148437, 0.917057931423187255, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Cosmic Infuser (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 1226232 - 1226232, 42459 - 42459)
(@CGUID+26, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11375.5927734375, -4457.4599609375, 45.79062271118164062, 1.675435543060302734, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+27, 240958, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11354.86328125, -4443.92724609375, 47.30728912353515625, 4.35816192626953125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Netherstrand Longbow (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 1226316 - 1226316)
(@CGUID+28, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11317.73046875, -4445.283203125, 17.58830642700195312, 3.521270036697387695, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+29, 246045, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11362.4111328125, -4368.90966796875, 18.52363777160644531, 1.834998607635498046, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Knight Anais (Area: 16209 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+30, 240665, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11556.1611328125, -4331.40087890625, 14.8315582275390625, 3.080567836761474609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Berserker (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+31, 240892, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11475.580078125, -4491.8564453125, 20.99374771118164062, 2.253585100173950195, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Norkonahl the Looter (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+32, 240963, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11450.36328125, -4366.095703125, 20.36166000366210937, 0.728420376777648925, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Staff of Disintegration (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 1226342 - 1226342)
(@CGUID+33, 243903, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11386.359375, -4388.35791015625, 16.32988548278808593, 5.828734874725341796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Arator (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+34, 241012, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11348.8408203125, -4463.33154296875, 29.63684844970703125, 1.373278141021728515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Scourgebane (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 1226491 - 1226491)
(@CGUID+35, 245749, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11383.7939453125, -4445.53173828125, 57.87200164794921875, 5.123824119567871093, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Pillaging Drifter (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 1239348 - 1239348) (possible waypoints or random movement)
(@CGUID+36, 245707, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11395.736328125, -4450.55712890625, 16.332977294921875, 0.117608390748500823, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Spoiler (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 1239277 - 1239277)
(@CGUID+37, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11368.501953125, -4478.8212890625, 30.00072479248046875, 2.131348609924316406, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+38, 245706, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11328.4375, -4455.42822265625, 45.7987823486328125, 1.367613434791564941, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Fatestealer (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+39, 245749, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11434.591796875, -4359.83203125, 59.30850601196289062, 1.143519759178161621, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Pillaging Drifter (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 1239348 - 1239348) (possible waypoints or random movement)
(@CGUID+40, 245607, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11361.7998046875, -4348.3955078125, 18.4289703369140625, 5.290233612060546875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Callum Ashvow (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+41, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11342.5693359375, -4445.51416015625, 45.86114120483398437, 1.39883279800415039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+42, 245609, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11397.16015625, -4357.35595703125, 16.7554168701171875, 1.465306401252746582, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Brandur Ironhammer (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+43, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11392.8857421875, -4448.30224609375, 16.32988548278808593, 4.025101184844970703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+44, 245706, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11379.3974609375, -4392.35693359375, 16.246551513671875, 4.358543872833251953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Fatestealer (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+45, 236684, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11779.0537109375, -4448.76025390625, 2.865513324737548828, 2.280548334121704101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidwake Behemoth (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+46, 243235, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11398.8857421875, -4311.3212890625, 8.316058158874511718, 0.972506105899810791, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Voidstorm Bombardier (Area: 16209 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
-- (@CGUID+47, 237222, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11351.4248046875, -4293.80029296875, 4.780697822570800781, 0.834474682807922363, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Light's Vanguard (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: ) - !!! might be temporary spawn !!!
(@CGUID+48, 240600, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11353.5517578125, -4291.45361328125, 4.780697822570800781, 2.155474185943603515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- The Wasting (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 1225550 - 1225550, 1269348 - 1269348)
(@CGUID+49, 245706, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11472.3701171875, -4333.62939453125, 16.58636093139648437, 2.648304462432861328, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Fatestealer (Area: 16209 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+50, 241312, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11477.4501953125, -4195.25, 138.355133056640625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic - Empty Bunny (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+51, 245706, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11471.23828125, -4477.84912109375, 52.7670135498046875, 2.983206987380981445, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Fatestealer (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+52, 245707, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11490.2880859375, -4388.73095703125, 50.23717498779296875, 0.994832336902618408, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Spoiler (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 1239277 - 1239277)
(@CGUID+53, 240665, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11569.2939453125, -4288.6962890625, 12.88324928283691406, 3.080567836761474609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Berserker (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+54, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11496.595703125, -4366.501953125, 15.96418666839599609, 1.400000333786010742, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+55, 243235, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11452.8037109375, -4299.81591796875, 15.41075611114501953, 2.886582612991333007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidstorm Bombardier (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+56, 245707, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11459.5732421875, -4483.1025390625, 52.9898529052734375, 3.139604806900024414, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Spoiler (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 1239277 - 1239277) (possible waypoints or random movement)
(@CGUID+57, 243235, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11460.6240234375, -4265.306640625, 6.5314788818359375, 6.114408493041992187, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Voidstorm Bombardier (Area: 16209 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
-- (@CGUID+58, 237222, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11397.6943359375, -4283.046875, 4.780697345733642578, 0.147344231605529785, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Light's Vanguard (Area: 16209 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
-- (@CGUID+59, 257493, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11452.501953125, -4470.47216796875, 14.9009408950805664, 0.139458447694778442, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Razeshi C. (Area: 16209 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!! (possible waypoints or random movement)
(@CGUID+60, 245749, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11471.1298828125, -4471.60888671875, 74.6805877685546875, 0.600399792194366455, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Pillaging Drifter (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 1239348 - 1239348) (possible waypoints or random movement)
-- (@CGUID+61, 237222, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11422.154296875, -4289.5615234375, 7.335607528686523437, 5.434161186218261718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Light's Vanguard (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: ) - !!! might be temporary spawn !!!
(@CGUID+62, 245707, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11365.9755859375, -4439.125, 20.68682098388671875, 1.774647951126098632, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Spoiler (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 1239369 - 1239369)
(@CGUID+63, 240892, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11491.2490234375, -4512.7744140625, 20.92678070068359375, 2.117382049560546875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Norkonahl the Looter (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+64, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11460.7333984375, -4492.5146484375, 52.75786209106445312, 4.870473384857177734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+65, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11388.2216796875, -4502.9091796875, 22.44693946838378906, 2.956977128982543945, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+66, 245706, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11447.171875, -4404.5869140625, 16.33618927001953125, 3.530686616897583007, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Fatestealer (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+67, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11480.0712890625, -4501.265625, 52.790618896484375, 3.805624723434448242, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+68, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11400.0419921875, -4520.0224609375, 21.54431343078613281, 1.203110814094543457, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+69, 240665, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11298.47265625, -4588.3994140625, 17.3629608154296875, 0.973838090896606445, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Berserker (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+70, 240950, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11347.904296875, -4473.9755859375, 46.48487472534179687, 5.831579208374023437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Devastation (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 1226304 - 1226304)
(@CGUID+71, 240965, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11468.115234375, -4508.125, 52.97744369506835937, 1.398657560348510742, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Warp Slicer (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 1226351 - 1226351)
(@CGUID+72, 259619, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11318.255859375, -4494.630859375, 17.87206459045410156, 3.209161996841430664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Smith Hauthaa (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+73, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11359.6435546875, -4523.50341796875, 26.10284042358398437, 2.127572536468505859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+74, 245707, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11443.9775390625, -4387.97216796875, 20.11954307556152343, 4.347882747650146484, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Spoiler (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 1239277 - 1239277) (possible waypoints or random movement)
(@CGUID+75, 245706, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11378.685546875, -4538.69677734375, 23.43012428283691406, 1.289807558059692382, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Fatestealer (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+76, 245706, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11323.244140625, -4494.29345703125, 17.87206459045410156, 3.209161996841430664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Fatestealer (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+77, 240601, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11250.8095703125, -4418.0693359375, 4.676975250244140625, 0.404301404953002929, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Blightclaw (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: )
-- (@CGUID+78, 43499, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11402.9169921875, -4441.87060546875, 16.246551513671875, 3.877605199813842773, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Consecration (Area: 16209 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
(@CGUID+79, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11483.6982421875, -4498.8408203125, 76.296356201171875, 3.683207035064697265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+80, 241022, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11301.353515625, -4472.60400390625, 16.55547523498535156, 1.611695528030395507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Reach Artisan (Area: 16208 - Difficulty: 0) CreateObject1 (Auras: 154470 - 154470)
(@CGUID+81, 241022, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11306.044921875, -4493.515625, 17.9553985595703125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Reach Artisan (Area: 16208 - Difficulty: 0) CreateObject1 (Auras: 154470 - 154470)
(@CGUID+82, 245707, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11301.4189453125, -4490.3662109375, 17.82980155944824218, 4.373387336730957031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Spoiler (Area: 16208 - Difficulty: 0) CreateObject1 (Auras: 1239369 - 1239369)
(@CGUID+83, 245706, 2858, 16182, 16208, '0', '0', 0, 0, 1, 11471.53515625, -4413.765625, 15.96780204772949218, 6.188770294189453125, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Fatestealer (Area: 16208 - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+84, 238186, 2858, 16182, 16208, '0', '0', 0, 0, 1, 11300.921875, -4503.5048828125, 18.42248916625976562, 2.343360662460327148, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16208 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+85, 238186, 2858, 16182, 16208, '0', '0', 0, 0, 1, 11314.2978515625, -4533.78125, 26.77069473266601562, 1.114010810852050781, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16208 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+86, 238186, 2858, 16182, 16208, '0', '0', 0, 0, 1, 11364.169921875, -4546.22900390625, 23.07568931579589843, 1.13228309154510498, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16208 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+87, 245707, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11373.013671875, -4558.845703125, 22.61009025573730468, 2.734062910079956054, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Spoiler (Area: 16208 - Difficulty: 0) CreateObject1 (Auras: 1239369 - 1239369)
(@CGUID+88, 241022, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11377.96875, -4555.47412109375, 22.8866119384765625, 1.611695528030395507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Reach Artisan (Area: 16208 - Difficulty: 0) CreateObject1 (Auras: 154470 - 154470)
(@CGUID+89, 245749, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11285.6552734375, -4516.05322265625, 50.05864715576171875, 0.444566607475280761, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Pillaging Drifter (Area: 16208 - Difficulty: 0) CreateObject1 (Auras: 1239348 - 1239348) (possible waypoints or random movement)
(@CGUID+90, 245706, 2858, 16182, 16208, '0', '0', 0, 0, 1, 11265.5888671875, -4492.42724609375, 21.93425941467285156, 1.415571331977844238, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Fatestealer (Area: 16208 - Difficulty: 0) CreateObject1
-- (@CGUID+91, 43499, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11357.5419921875, -4463.27294921875, 20.86311149597167968, 3.999373197555541992, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Consecration (Area: 16208 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
(@CGUID+92, 238186, 2858, 16182, 16208, '0', '0', 0, 0, 1, 11401.900390625, -4546.68017578125, 22.07270050048828125, 3.408123254776000976, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16208 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+93, 241022, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11378.041015625, -4561.5712890625, 22.64063835144042968, 3.695089101791381835, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Reach Artisan (Area: 16208 - Difficulty: 0) CreateObject1 (Auras: 154470 - 154470)
-- (@CGUID+94, 43499, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11357.890625, -4464.048828125, 20.85161399841308593, 3.299686193466186523, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Consecration (Area: 16208 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
(@CGUID+95, 238856, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11255.30078125, -4460.2763671875, 6.34688568115234375, 1.492299079895019531, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Voidfront Pummeler (Area: 16208 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590, 1252117 - 1252117) (possible waypoints or random movement)
(@CGUID+96, 238856, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11255.732421875, -4463.998046875, 7.002924919128417968, 3.625342607498168945, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Voidfront Pummeler (Area: 16208 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590, 1252117 - 1252117) (possible waypoints or random movement)
(@CGUID+97, 238856, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11399.0947265625, -4354.2412109375, 16.76888656616210937, 4.156599044799804687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidfront Pummeler (Area: 16208 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590, 1252117 - 1252117, 1251577 - 1251577)
-- (@CGUID+98, 43499, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11350.4423828125, -4457.779296875, 30.74110221862792968, 2.233644962310791015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Consecration (Area: 16208 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
-- (@CGUID+99, 43499, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11351.0517578125, -4458.5537109375, 30.74231910705566406, 5.275700092315673828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Consecration (Area: 16208 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
(@CGUID+100, 238186, 2858, 16182, 16208, '0', '0', 0, 0, 1, 11443.7529296875, -4474.8837890625, 14.97863101959228515, 5.724142074584960937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16208 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+101, 238186, 2858, 16182, 16208, '0', '0', 0, 0, 1, 11423.453125, -4554.48779296875, 9.866032600402832031, 1.313716053962707519, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16208 - Difficulty: 0) CreateObject1
(@CGUID+102, 238856, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11323.501953125, -4389.814453125, 7.30328989028930664, 2.899579524993896484, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Voidfront Pummeler (Area: 16208 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590) (possible waypoints or random movement)
(@CGUID+103, 245706, 2858, 16182, 16208, '0', '0', 0, 0, 1, 11342.349609375, -4441.16162109375, 28.53977584838867187, 0.393439292907714843, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Fatestealer (Area: 16208 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+104, 238856, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11247.080078125, -4492.57177734375, 19.44099617004394531, 6.090578079223632812, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Voidfront Pummeler (Area: 16208 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590, 1252117 - 1252117) (possible waypoints or random movement)
(@CGUID+105, 238855, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11243.0302734375, -4486.87255859375, 18.00067329406738281, 6.0666351318359375, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Voidfront Defiler (Area: 16208 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590) (possible waypoints or random movement)
(@CGUID+106, 238856, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11247.8134765625, -4488.0791015625, 18.54620933532714843, 6.15810394287109375, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Voidfront Pummeler (Area: 16208 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590, 1252117 - 1252117) (possible waypoints or random movement)
-- (@CGUID+107, 43499, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11326.4111328125, -4495.3388671875, 43.75938796997070312, 2.615509271621704101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Consecration (Area: 16208 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
-- (@CGUID+108, 43499, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11327.8349609375, -4477.82861328125, 45.31687545776367187, 0.766036391258239746, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Consecration (Area: 16208 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
-- (@CGUID+109, 43499, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11341.8671875, -4464.44140625, 45.83176803588867187, 1.497190833091735839, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Consecration (Area: 16208 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
-- (@CGUID+110, 43499, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11345.923828125, -4449.806640625, 45.94125747680664062, 2.222446918487548828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Consecration (Area: 16208 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
-- (@CGUID+111, 43499, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11372.708984375, -4449.7587890625, 45.79062271118164062, 2.302802085876464843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Consecration (Area: 16208 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
(@CGUID+112, 238186, 2858, 16182, 16208, '0', '0', 0, 0, 1, 11447.58203125, -4515.9619140625, 15.94223308563232421, 1.67816627025604248, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16208 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+113, 240600, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11388.2099609375, -4384.6865234375, 16.246551513671875, 0.61250394582748413, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- The Wasting (Area: 16208 - Difficulty: 0) CreateObject1 (Auras: 1225550 - 1225550, 1269348 - 1269348)
(@CGUID+114, 238855, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11331.50390625, -4384.64404296875, 7.044396877288818359, 2.899579524993896484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidfront Defiler (Area: 16208 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+115, 238186, 2858, 16182, 16208, '0', '0', 0, 0, 1, 11383.3564453125, -4580.375, 22.10931015014648437, 1.746611595153808593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16208 - Difficulty: 0) CreateObject1
(@CGUID+116, 238856, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11394.6923828125, -4384.677734375, 16.246551513671875, 6.082363128662109375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidfront Pummeler (Area: 16208 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590, 1252117 - 1252117, 1251577 - 1251577)
(@CGUID+117, 238186, 2858, 16182, 16208, '0', '0', 0, 0, 1, 11479.5849609375, -4501.50927734375, 52.8096466064453125, 3.848163127899169921, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16208 - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+118, 241022, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11432.9462890625, -4574.9912109375, 5.43998575210571289, 1.611695528030395507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Reach Artisan (Area: 16208 - Difficulty: 0) CreateObject1 (Auras: 154470 - 154470)
(@CGUID+119, 245706, 2858, 16182, 16208, '0', '0', 0, 0, 1, 11461.8193359375, -4564.95654296875, 5.03678750991821289, 2.243484258651733398, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Fatestealer (Area: 16208 - Difficulty: 0) CreateObject1
(@CGUID+120, 238186, 2858, 16182, 16208, '0', '0', 0, 0, 1, 11461.3232421875, -4373.29443359375, 19.79062271118164062, 3.498647928237915039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16208 - Difficulty: 0) CreateObject1
(@CGUID+121, 245707, 2858, 16182, 16208, '0', '0', 0, 0, 0, 11500.7490234375, -4547.96533203125, 20.56641197204589843, 4.160932540893554687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Spoiler (Area: 16208 - Difficulty: 0) CreateObject1 (Auras: 1239277 - 1239277)
(@CGUID+122, 238186, 2858, 16182, 16208, '0', '0', 0, 0, 1, 11509.8095703125, -4533.578125, 20.39999580383300781, 2.290012598037719726, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16208 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+123, 238186, 2858, 16182, 16208, '0', '0', 0, 0, 1, 11500.353515625, -4542.203125, 20.47448921203613281, 3.106096267700195312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16208 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+124, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11535.4970703125, -4516.67724609375, 4.943033218383789062, 3.665541410446166992, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+125, 241022, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11548.23828125, -4483.26025390625, 5.092014312744140625, 1.611695528030395507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Reach Artisan (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 154470 - 154470)
(@CGUID+126, 245707, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11449.8408203125, -4377.94677734375, 19.793182373046875, 4.158162117004394531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Spoiler (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+127, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11548.05078125, -4485.80908203125, 4.961580276489257812, 1.8552170991897583, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+128, 239544, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11549.166015625, -4457.02783203125, 5.683814525604248046, 2.972680568695068359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
(@CGUID+129, 245706, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11434.96875, -4576.4931640625, 5.338820934295654296, 2.45787811279296875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Fatestealer (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+130, 245707, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11560.2001953125, -4477.673828125, 5.026371002197265625, 6.173027992248535156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Spoiler (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 1239369 - 1239369)
(@CGUID+131, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11431.283203125, -4576.548828125, 5.371102333068847656, 6.188538074493408203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+132, 245707, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11511.982421875, -4575.70166015625, 5.0263671875, 6.25002145767211914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Spoiler (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 1239277 - 1239277)
(@CGUID+133, 245707, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11548.650390625, -4543.2724609375, 4.943033218383789062, 0.208590492606163024, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Spoiler (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 1239369 - 1239369)
(@CGUID+134, 241022, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11518.7138671875, -4571.48779296875, 5.0263671875, 1.611695528030395507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Reach Artisan (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 154470 - 154470)
(@CGUID+135, 245706, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11520.8330078125, -4568.228515625, 4.943033695220947265, 3.141592741012573242, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Fatestealer (Area: 16209 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+136, 239544, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11563.4482421875, -4461.1943359375, 4.928045272827148437, 4.50791788101196289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
(@CGUID+137, 239544, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11559.189453125, -4438.611328125, 4.775725364685058593, 2.717469453811645507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
-- (@CGUID+138, 256052, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11498.4931640625, -4512.16015625, 20.97902679443359375, 1.44183349609375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Repurposed Plunder (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: ) - !!! might be temporary spawn !!!
-- (@CGUID+139, 256052, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11484.5771484375, -4510.13818359375, 20.99374580383300781, 1.44183349609375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Repurposed Plunder (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: ) - !!! might be temporary spawn !!!
-- (@CGUID+140, 43499, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11493.58984375, -4504.474609375, 20.99374580383300781, 4.205414772033691406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Consecration (Area: 16209 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
(@CGUID+141, 239544, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11572.6533203125, -4445.34423828125, 4.943033695220947265, 2.5070953369140625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
(@CGUID+142, 239544, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11562.634765625, -4440.18408203125, 4.767800331115722656, 2.710421562194824218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
-- (@CGUID+143, 256052, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11495.625, -4509.04150390625, 20.99374580383300781, 3.556955575942993164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Repurposed Plunder (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: ) - !!! might be temporary spawn !!!
-- (@CGUID+144, 256052, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11501.4736328125, -4505.82373046875, 20.99374580383300781, 3.556955575942993164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Repurposed Plunder (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: ) - !!! might be temporary spawn !!!
(@CGUID+145, 239544, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11572.2783203125, -4445.06787109375, 4.943033695220947265, 2.5070953369140625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
(@CGUID+146, 239544, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11581.6220703125, -4458.4267578125, 5.088220596313476562, 2.470240592956542968, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169) (possible waypoints or random movement)
(@CGUID+147, 239544, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11573.11328125, -4460.11865234375, 4.94303750991821289, 3.742098331451416015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
(@CGUID+148, 241312, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11628.953125, -4396.05712890625, 95.89923095703125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic - Empty Bunny (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+149, 241312, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11623.46875, -4455.28125, 92.7553558349609375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic - Empty Bunny (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+150, 241312, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11607.83203125, -4409.03662109375, 95.89923095703125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic - Empty Bunny (Area: 16205 - Difficulty: 0) CreateObject1
-- (@CGUID+151, 43499, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11393.98046875, -4443.38671875, 16.246551513671875, 5.062657833099365234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Consecration (Area: 16209 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
(@CGUID+152, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11387.8994140625, -4484.515625, 21.22048759460449218, 4.773326396942138671, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
-- (@CGUID+153, 43499, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11468.48046875, -4481.873046875, 52.7655487060546875, 4.333987236022949218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Consecration (Area: 16209 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
(@CGUID+154, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11480.9287109375, -4517.38037109375, 76.12313079833984375, 5.015752792358398437, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+155, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11355.787109375, -4468.9921875, 20.81456756591796875, 0.456636250019073486, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+156, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11466.4423828125, -4373.8662109375, 47.42776107788085937, 3.006606578826904296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1
-- (@CGUID+157, 43499, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11371.04296875, -4441.50390625, 20.6249847412109375, 3.1292266845703125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Consecration (Area: 16209 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
(@CGUID+158, 245706, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11329.2412109375, -4453.251953125, 45.79509735107421875, 4.39378976821899414, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Fatestealer (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
-- (@CGUID+159, 43499, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11352.9140625, -4462.474609375, 20.99374771118164062, 3.472759723663330078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Consecration (Area: 16209 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
(@CGUID+160, 238856, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11429.8173828125, -4290.1005859375, 7.821457862854003906, 3.952397823333740234, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Voidfront Pummeler (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590, 1252117 - 1252117) (possible waypoints or random movement)
(@CGUID+161, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11469.134765625, -4376.8525390625, 20.1291351318359375, 4.953141212463378906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+162, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11322.0673828125, -4450.20458984375, 19.63436126708984375, 0.683832764625549316, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
-- (@CGUID+163, 243903, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11386.359375, -4388.35791015625, 16.41321945190429687, 5.828734874725341796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Arator (Area: 16209 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
-- (@CGUID+164, 236978, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11390.9150390625, -4385.61474609375, 16.41321945190429687, 5.347464561462402343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- High Exarch Turalyon (Area: 16209 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
-- (@CGUID+165, 239416, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11374.734375, -4395.59033203125, 16.41321945190429687, 5.63163614273071289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Lothraxion (Area: 16209 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
-- (@CGUID+166, 240887, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11379.6826171875, -4391.84716796875, 16.41321945190429687, 0.427430421113967895, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Faerin Lothar (Area: 16209 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
-- (@CGUID+167, 240886, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11395.8115234375, -4376.1318359375, 16.41321945190429687, 0.367681890726089477, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Alonsus Faol (Area: 16209 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
-- (@CGUID+168, 237253, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11392.3564453125, -4380.611328125, 16.41321945190429687, 4.452420234680175781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Lady Liadrin (Area: 16209 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
(@CGUID+169, 245706, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11349.7470703125, -4464.37353515625, 45.90673446655273437, 3.79882979393005371, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Fatestealer (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+170, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11375.4033203125, -4456.24658203125, 45.79516220092773437, 4.876911640167236328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+171, 238186, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11386.2861328125, -4502.701171875, 22.406890869140625, 2.286693334579467773, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Shadowguard Pillager (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+172, 239544, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11549.166015625, -4457.02783203125, 5.683814525604248046, 2.972680568695068359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
(@CGUID+173, 239544, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11559.189453125, -4438.611328125, 4.775725364685058593, 2.717469453811645507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
(@CGUID+174, 239544, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11563.4482421875, -4461.1943359375, 4.928045272827148437, 4.50791788101196289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
(@CGUID+175, 239544, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11594.7626953125, -4482.9443359375, -0.34959581494331359, 0.740139663219451904, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
(@CGUID+176, 241410, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11586.767578125, -4423.52587890625, 5.0263671875, 4.538820266723632812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Commander Koruth Mountainfist (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 1232950 - 1232950)
(@CGUID+177, 239544, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11583.2255859375, -4453.515625, 5.142632007598876953, 1.906718373298645019, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
(@CGUID+178, 239544, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11617.23828125, -4486.232421875, 0.200000002980232238, 1.590416312217712402, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
(@CGUID+179, 239544, 2858, 16182, 16209, '0', '0', 0, 0, 0, 11617.6591796875, -4484.51904296875, -0.30469089746475219, 5.447257518768310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16209 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
(@CGUID+180, 246132, 2858, 16182, 16209, '0', '0', 0, 0, 1, 11624.423828125, -4414.92041015625, 5.026369094848632812, 1.410199761390686035, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Commander Venel Lightblood (Area: 16209 - Difficulty: 0) CreateObject1
(@CGUID+181, 243554, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11626.4580078125, -4411.62158203125, 5.0263671875, 2.514026165008544921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- War Chaplain Senn (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1227208 - 1227208)
-- (@CGUID+182, 241322, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11741.22265625, -4415.8212890625, 32.68255615234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic - Empty Bunny (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: ) - !!! might be temporary spawn !!!
(@CGUID+183, 227536, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11753.8251953125, -4473.001953125, 3.45739912986755371, 4.603053569793701171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic - Empty Bunny (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1232360 - 1232360)
(@CGUID+184, 247611, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11747.056640625, -4424.01220703125, 24.51784515380859375, 4.603053569793701171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic - Empty Bunny (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+185, 246150, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11629.1845703125, -4414.2568359375, 5.026368618011474609, 5.148654460906982421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Noellene (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+186, 238856, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11632.0693359375, -4416.380859375, 5.993747711181640625, 2.506923913955688476, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidfront Pummeler (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590, 1252117 - 1252117, 1251577 - 1251577)
(@CGUID+187, 238872, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11726.7958984375, -4372.82275390625, 7.670139312744140625, 3.983031034469604492, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidgorged Reserve (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+188, 239544, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11589.78515625, -4463.4130859375, -0.88099241256713867, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
(@CGUID+189, 241395, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11667.0986328125, -4376.220703125, 5.08000040054321289, 2.311051130294799804, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- General Amias Bellamy (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1227208 - 1227208)
(@CGUID+190, 239544, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11599.03515625, -4333.36962890625, 9.753969192504882812, 5.56968545913696289, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169) (possible waypoints or random movement)
(@CGUID+191, 238856, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11685.4345703125, -4390.02099609375, 5.951244354248046875, 0.986318767070770263, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidfront Pummeler (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590, 1252117 - 1252117)
(@CGUID+192, 243432, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11684.0458984375, -4385.06298828125, 5.954830646514892578, 4.985478401184082031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Aponi Brightmane (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+193, 246121, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11703.5380859375, -4368.6494140625, 5.13970184326171875, 1.358343124389648437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Lothraxion (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+194, 246159, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11717.341796875, -4383.845703125, 7.92717599868774414, 0.867053091526031494, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Anduin Wrynn (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+195, 240665, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11682.484375, -4217.8154296875, 12.53675460815429687, 6.062609672546386718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Berserker (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+196, 238856, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11721.03125, -4369.63037109375, 7.223958492279052734, 3.602901220321655273, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidfront Pummeler (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590, 1252117 - 1252117)
(@CGUID+197, 239544, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11649.4375, -4300.41943359375, 10.90149497985839843, 1.206078052520751953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
(@CGUID+198, 246151, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11710.298828125, -4393.5537109375, 7.795804500579833984, 6.146082401275634765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Grand Vindicator Sorvos (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+199, 239544, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11698.1025390625, -4364.7412109375, 5.054760932922363281, 4.3115692138671875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
(@CGUID+200, 239544, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11595.21484375, -4315.12744140625, 10.38148784637451171, 0.795485198497772216, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
(@CGUID+201, 237255, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11726.876953125, -4393.97900390625, 8.604702949523925781, 5.610375881195068359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- High Exarch Turalyon (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+202, 227536, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11807.1298828125, -4427.375, 3.92248702049255371, 4.603053569793701171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic - Empty Bunny (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1232360 - 1232360)
(@CGUID+203, 239486, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11723.43359375, -4376.66796875, 8.559079170227050781, 0.852299094200134277, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Gidwin Goldbraids (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+204, 241385, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11718.3330078125, -4372.109375, 7.132752418518066406, 0.743076920509338378, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Tarenar Sunstrike (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1248504 - 1248504)
(@CGUID+205, 239544, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11676.9072265625, -4313.19482421875, 10.90130805969238281, 1.810475587844848632, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
(@CGUID+206, 239544, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11572.5244140625, -4323.70849609375, 10.52573680877685546, 4.242923736572265625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
(@CGUID+207, 241431, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11719.0361328125, -4392.3125, 8.423610687255859375, 2.208957195281982421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Alonsus Faol (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1232975 - 1232975)
(@CGUID+208, 237277, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11720.8642578125, -4400.27783203125, 8.589808464050292968, 5.23363351821899414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Lady Liadrin (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+209, 238856, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11707.16015625, -4351.85791015625, 9.025162696838378906, 4.122565269470214843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidfront Pummeler (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590, 1252117 - 1252117)
(@CGUID+210, 238856, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11688.560546875, -4343.23779296875, 8.877711296081542968, 5.261628150939941406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidfront Pummeler (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590, 1252117 - 1252117)
(@CGUID+211, 242740, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11705.7587890625, -4392.29345703125, 7.101871967315673828, 2.333779811859130859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Prophet Velen (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 155891 - 155891)
(@CGUID+212, 246135, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11723.8828125, -4388.298828125, 8.5742950439453125, 6.1266021728515625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Arator (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+213, 246130, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11714.6220703125, -4398.4287109375, 8.485294342041015625, 5.967183589935302734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Faerin Lothar (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+214, 239544, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11639.63671875, -4324.021484375, 11.60402679443359375, 3.634053945541381835, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
(@CGUID+215, 238856, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11742.8828125, -4341.87744140625, 4.923396587371826171, 3.153856277465820312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidfront Pummeler (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590, 1252117 - 1252117)
(@CGUID+216, 240665, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11625.3564453125, -4186.92724609375, 15.19569206237792968, 1.350433945655822753, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Voidborn Berserker (Area: 16205 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+217, 238856, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11723.9453125, -4343.84912109375, 6.953026771545410156, 4.326902389526367187, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Voidfront Pummeler (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590, 1252117 - 1252117) (possible waypoints or random movement)
(@CGUID+218, 239544, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11666.974609375, -4300.96875, 10.92420768737792968, 1.329766750335693359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
(@CGUID+219, 238856, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11674.912109375, -4300.0009765625, 10.84519195556640625, 4.952207088470458984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidfront Pummeler (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590, 1252117 - 1252117)
(@CGUID+220, 238856, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11734.048828125, -4316.8525390625, 8.416791915893554687, 6.250911712646484375, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Voidfront Pummeler (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590, 1252117 - 1252117) (possible waypoints or random movement)
(@CGUID+221, 238856, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11716.69921875, -4308.82275390625, 10.3836679458618164, 2.325523853302001953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidfront Pummeler (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590, 1252117 - 1252117)
-- (@CGUID+222, 242740, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11705.7587890625, -4392.29345703125, 7.185205459594726562, 2.333779811859130859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Prophet Velen (Area: 16205 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
(@CGUID+223, 247619, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11724.5244140625, -4398.33349609375, 8.605743408203125, 4.603053569793701171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic - Empty Bunny (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1243724 - 1243724)
(@CGUID+224, 239544, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11695.3388671875, -4305.80908203125, 10.90004158020019531, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
(@CGUID+225, 239544, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11692.1318359375, -4322.59716796875, 9.3498077392578125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
(@CGUID+226, 239544, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11708.056640625, -4324.939453125, 9.591173171997070312, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
(@CGUID+227, 242937, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11670.685546875, -4159.3994140625, 33.50641632080078125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic - Empty Bunny (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+228, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11799.703125, -4356.83447265625, 1.933796644210815429, 3.330179691314697265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
-- (@CGUID+229, 244000, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11676.7001953125, -4314.990234375, 10.92332077026367187, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Hungry Voidtrapper (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1250486 - 1250486) - !!! might be temporary spawn !!!
(@CGUID+230, 242915, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11730.4501953125, -4448.470703125, 19.505645751953125, 5.722697257995605468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Void Portal (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1231750 - 1231750)
(@CGUID+231, 243989, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11716.7373046875, -4399.6005859375, 8.584325790405273437, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Faerin Lothar (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+232, 227536, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11683.5751953125, -4207.02587890625, 13.05816078186035156, 5.200181007385253906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic - Empty Bunny (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1232360 - 1232360)
(@CGUID+233, 240665, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11531.8515625, -4385.52880859375, 13.71105480194091796, 2.18141341209411621, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Voidborn Berserker (Area: 16205 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+234, 227536, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11562.2314453125, -4292.517578125, 13.36108589172363281, 6.102949142456054687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic - Empty Bunny (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1232360 - 1232360)
(@CGUID+235, 237277, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11720.8701171875, -4400.2568359375, 8.591742515563964843, 5.23363351821899414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Lady Liadrin (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+236, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11711.123046875, -4336.32421875, 8.522475242614746093, 4.944570541381835937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+237, 236684, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11764.1533203125, -4435.36474609375, 8.330995559692382812, 1.884955525398254394, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidwake Behemoth (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+238, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11722.8369140625, -4310.53125, 9.636462211608886718, 5.405303001403808593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+239, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11645.37890625, -4386.52587890625, 4.943036079406738281, 0.687116205692291259, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+240, 227536, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11595.0146484375, -4396.85400390625, 6.681991100311279296, 5.198933124542236328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic - Empty Bunny (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1232360 - 1232360)
(@CGUID+241, 236684, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11839.6083984375, -4397.861328125, -4.28069782257080078, 2.351305484771728515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidwake Behemoth (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+242, 242937, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11623.6611328125, -4170.5087890625, 52.0746307373046875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic - Empty Bunny (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+243, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11741.5283203125, -4340.2099609375, 5.097573280334472656, 3.958941936492919921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+244, 240665, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11775.9892578125, -4254.7822265625, 0.932346701622009277, 5.464520454406738281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Berserker (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+245, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11744.2568359375, -4335.77880859375, 5.164136886596679687, 2.136851310729980468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+246, 240665, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11570.5634765625, -4447.83154296875, 4.943034172058105468, 0.746370136737823486, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Berserker (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+247, 244001, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11719.4052734375, -4403.189453125, 8.600049018859863281, 6.177652359008789062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Arator (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+248, 237255, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11726.873046875, -4393.9599609375, 8.604702949523925781, 5.30522775650024414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- High Exarch Turalyon (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+249, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11734.494140625, -4308.47216796875, 7.837399482727050781, 0.32398766279220581, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263); -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+250, 236684, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11640.3994140625, -4442.767578125, 7.667355060577392578, 2.416320085525512695, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidwake Behemoth (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+251, 242937, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11534.966796875, -4200.07275390625, 33.50641632080078125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic - Empty Bunny (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+252, 242915, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11793.42578125, -4392.1650390625, 10.09366321563720703, 5.722697257995605468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Void Portal (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1231750 - 1231750)
(@CGUID+253, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11774.5595703125, -4360.36376953125, 0.434758245944976806, 0.671720623970031738, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+254, 242915, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11683.267578125, -4444.5244140625, 7.352044105529785156, 5.269855499267578125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Void Portal (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1231750 - 1231750)
(@CGUID+255, 227536, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11704.423828125, -4268.77783203125, 12.07890605926513671, 4.603053569793701171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic - Empty Bunny (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1232360 - 1232360)
(@CGUID+256, 243987, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11721.318359375, -4391.6025390625, 8.544078826904296875, 6.02324676513671875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Alonsus Faol (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+257, 227536, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11572.1591796875, -4334.92041015625, 11.07645416259765625, 4.592368125915527343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic - Empty Bunny (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1232360 - 1232360)
-- (@CGUID+258, 244000, 2858, 16182, 16205, '0', '04', 0, 0, 0, 11676.7001953125, -4314.990234375, 10.92332077026367187, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Hungry Voidtrapper (Area: 16205 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
-- (@CGUID+259, 243989, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11716.7373046875, -4399.6005859375, 8.667658805847167968, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Faerin Lothar (Area: 16205 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
-- (@CGUID+260, 243987, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11721.318359375, -4391.6025390625, 8.627411842346191406, 6.02324676513671875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Alonsus Faol (Area: 16205 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
-- (@CGUID+261, 244001, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11719.4052734375, -4403.189453125, 8.683382034301757812, 6.177652359008789062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Arator (Area: 16205 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
-- (@CGUID+262, 237277, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11720.8701171875, -4400.2568359375, 8.675075531005859375, 5.23363351821899414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Lady Liadrin (Area: 16205 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
-- (@CGUID+263, 237255, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11726.873046875, -4393.9599609375, 8.688035964965820312, 5.30522775650024414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- High Exarch Turalyon (Area: 16205 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
(@CGUID+264, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11592.1162109375, -4362.7373046875, 34.64215469360351562, 3.590722322463989257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+265, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11606.822265625, -4374.75, 9.204310417175292968, 3.044030189514160156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+266, 243157, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11648.4443359375, -4284.05029296875, 11.78707122802734375, 2.966808319091796875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Light's Vanguard (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 154470 - 154470)
(@CGUID+267, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11631.2431640625, -4349.22412109375, 8.136570930480957031, 5.46392679214477539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+268, 241475, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11615.755859375, -4189.48779296875, 18.12001419067382812, 1.26475226879119873, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Reach Dragonhawk (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+269, 243157, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11651.08203125, -4275.3037109375, 10.75287628173828125, 1.666855454444885253, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Light's Vanguard (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 154470 - 154470)
(@CGUID+270, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11689.5205078125, -4292.37451171875, 11.17808341979980468, 3.22162628173828125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+271, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11688.447265625, -4284.611328125, 11.48137474060058593, 3.881323814392089843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+272, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11626.984375, -4344.83349609375, 9.299001693725585937, 5.484704017639160156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+273, 241475, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11606.2392578125, -4193.7568359375, 18.32634162902832031, 1.26475226879119873, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Reach Dragonhawk (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+274, 237388, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11616.0888671875, -4203.23974609375, 19.1935272216796875, 1.806432843208312988, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Empowered Dragonhawk (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+275, 227536, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11650.482421875, -4165.76416015625, 12.58353328704833984, 6.012816905975341796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic - Empty Bunny (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1232360 - 1232360)
(@CGUID+276, 227536, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11556.9853515625, -4195.32275390625, 13.85803413391113281, 6.012816905975341796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic - Empty Bunny (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1232360 - 1232360)
(@CGUID+277, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11591.103515625, -4310, 10.30954742431640625, 5.04598236083984375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
-- (@CGUID+278, 244000, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11676.7001953125, -4314.990234375, 11.007232666015625, 4.20595407485961914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Hungry Voidtrapper (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: ) - !!! might be temporary spawn !!!
(@CGUID+279, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11583.6728515625, -4287.806640625, 11.73896408081054687, 0.462568879127502441, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+280, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11590.9853515625, -4276.9169921875, 11.94124031066894531, 2.708164453506469726, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+281, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11564.8466796875, -4346.83154296875, 11.5876779556274414, 2.721187353134155273, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+282, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11708.14453125, -4254.078125, 11.78637886047363281, 6.224544525146484375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+283, 243157, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11633.78125, -4238.82275390625, 12.84644508361816406, 1.566379189491271972, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Light's Vanguard (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 154470 - 154470)
(@CGUID+284, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11595.6787109375, -4264.52978515625, 10.83802413940429687, 5.05392313003540039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+285, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11671.1357421875, -4232.89453125, 13.06782054901123046, 0.072320081293582916, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+286, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11667.0576171875, -4233.1953125, 13.00499439239501953, 3.48197484016418457, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+287, 240665, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11448.8056640625, -4324.892578125, 17.18735504150390625, 3.437908172607421875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Berserker (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+288, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11604.640625, -4226.56591796875, 11.68761920928955078, 0.385555505752563476, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+289, 241470, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11608.1494140625, -4225.6396484375, 11.26749610900878906, 3.441739320755004882, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Arator (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+290, 238882, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11606.7236328125, -4229.23779296875, 11.55313968658447265, 1.929023981094360351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidfront corpse (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 154470 - 154470)
(@CGUID+291, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11584.7080078125, -4253.4130859375, 10.94056892395019531, 5.868524551391601562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+292, 243162, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11636.580078125, -4215.080078125, 13.76112174987792968, 5.920773983001708984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Alonsus Faol (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+293, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11575.2529296875, -4252.50927734375, 10.39722824096679687, 3.567867279052734375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+294, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11565.826171875, -4273.7919921875, 11.12590312957763671, 4.581773757934570312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+295, 238882, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11616.7412109375, -4222.283203125, 11.42331409454345703, 1.929023981094360351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidfront corpse (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 154470 - 154470)
(@CGUID+296, 243157, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11616.076171875, -4231.205078125, 10.83088111877441406, 2.966808319091796875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Light's Vanguard (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 154470 - 154470)
(@CGUID+297, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11677.2333984375, -4213.3515625, 13.2447519302368164, 2.697593212127685546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+298, 238882, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11600.9658203125, -4218.3662109375, 12.61878299713134765, 1.929023981094360351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidfront corpse (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 154470 - 154470)
(@CGUID+299, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11636.2333984375, -4209.65966796875, 14.89397048950195312, 2.994549512863159179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+300, 245993, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11602.845703125, -4203.77783203125, 17.6388397216796875, 0.74165201187133789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Empowered Dragonhawk (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+301, 238882, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11658.3720703125, -4208.49658203125, 14.84293937683105468, 1.929023981094360351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidfront corpse (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 154470 - 154470)
(@CGUID+302, 238882, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11638.7724609375, -4203.92041015625, 16.17981719970703125, 0.350559353828430175, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidfront corpse (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 154470 - 154470)
(@CGUID+303, 243156, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11634.166015625, -4209.8662109375, 14.80960941314697265, 6.10843515396118164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- High Exarch Turalyon (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+304, 243165, 2858, 16182, 16205, '0', '0', 0, 0, 1, 11627.6337890625, -4201.859375, 20.86938858032226562, 2.509289503097534179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Lady Liadrin (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 1232344 - 1232344, 1234305 - 1234305, 86458 - 86458)
(@CGUID+305, 242884, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11716.0458984375, -4232.853515625, 12.17936038970947265, 5.332180500030517578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16205 - Difficulty: 0) CreateObject1
(@CGUID+306, 238882, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11649.1982421875, -4208.1943359375, 15.22641658782958984, 1.929023981094360351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidfront corpse (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 154470 - 154470)
(@CGUID+307, 238882, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11598.033203125, -4221.7431640625, 12.95490360260009765, 1.929023981094360351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidfront corpse (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 154470 - 154470)
(@CGUID+308, 238882, 2858, 16182, 16205, '0', '0', 0, 0, 0, 11651.3837890625, -4204.54150390625, 15.60350513458251953, 3.13037109375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidfront corpse (Area: 16205 - Difficulty: 0) CreateObject1 (Auras: 154470 - 154470)
(@CGUID+309, 242884, 2858, 16182, 16393, '0', '0', 0, 0, 0, 11635.7841796875, -4168.67041015625, 13.44780349731445312, 6.220644950866699218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16393 - Difficulty: 0) CreateObject1
(@CGUID+310, 240665, 2858, 16182, 16393, '0', '0', 0, 0, 0, 11717.7626953125, -4094.611083984375, 9.088466644287109375, 5.341394424438476562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Berserker (Area: 16393 - Difficulty: 0) CreateObject1
(@CGUID+311, 242884, 2858, 16182, 16393, '0', '0', 0, 0, 0, 11566.9609375, -4196.19482421875, 15.09399318695068359, 5.457557201385498046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Breacher (Area: 16393 - Difficulty: 0) CreateObject1
-- (@CGUID+312, 243165, 2858, 16182, 16393, '0', '0', 0, 0, 1, 11627.6337890625, -4201.859375, 20.95272254943847656, 2.509289503097534179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Lady Liadrin (Area: 16393 - Difficulty: 0) CreateObject1 (Auras: 1232344 - 1232344) - !!! might be temporary spawn !!!
(@CGUID+313, 243223, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10808.9775390625, -4594.53759765625, 36.682281494140625, 5.646839141845703125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590, 1251577 - 1251577)
(@CGUID+314, 240665, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10659.173828125, -4645.98974609375, 35.48469924926757812, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Berserker (Area: 16538 - Difficulty: 0) CreateObject1
(@CGUID+315, 241617, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10913.4775390625, -4659.9775390625, 37.6655120849609375, 1.689927935600280761, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Berserker (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+316, 206118, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10815.2626953125, -4610.02099609375, 37.08660888671875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic - Empty Bunny (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+317, 243223, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10823.32421875, -4600.98095703125, 36.8090057373046875, 6.088411808013916015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+318, 243235, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10754.7783203125, -4638.66162109375, 35.4013671875, 6.27989053726196289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidstorm Bombardier (Area: 16538 - Difficulty: 0) CreateObject1
(@CGUID+319, 243235, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10764.109375, -4661.4443359375, 35.48469924926757812, 1.435102462768554687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidstorm Bombardier (Area: 16538 - Difficulty: 0) CreateObject1
(@CGUID+320, 243230, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10807.185546875, -4597.4658203125, 36.67655563354492187, 2.225023746490478515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251533 - 1251533, 1251590 - 1251590, 1251577 - 1251577)
(@CGUID+321, 241590, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10776.5830078125, -4636.75341796875, 35.48469924926757812, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Void-Slash Vanguard (Area: 16538 - Difficulty: 0) CreateObject1
(@CGUID+322, 241617, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10948.560546875, -4549.43408203125, 37.64340972900390625, 4.383060455322265625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Berserker (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+323, 239544, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10692.861328125, -4639.689453125, 35.59375, 6.220897674560546875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
(@CGUID+324, 244047, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10948.974609375, -4523.4287109375, 37.930267333984375, 4.487250804901123046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Void-Runed Disruptor (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+325, 243223, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10813.7109375, -4641.4638671875, 36.796875, 5.311768531799316406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590, 1251577 - 1251577)
(@CGUID+326, 241617, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10937.525390625, -4559.90673828125, 37.59375, 4.081339836120605468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Berserker (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251577 - 1251577, 1251590 - 1251590)
(@CGUID+327, 240665, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10699.1396484375, -4682.267578125, 35.4013671875, 1.175245046615600585, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Berserker (Area: 16538 - Difficulty: 0) CreateObject1
(@CGUID+328, 243235, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10786.591796875, -4673.72412109375, 35.48469924926757812, 0.911503612995147705, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidstorm Bombardier (Area: 16538 - Difficulty: 0) CreateObject1
(@CGUID+329, 243228, 2858, 16182, 16538, '0', '0', 0, 0, 1, 10822.6455078125, -4601.3037109375, 36.81214141845703125, 0.736858129501342773, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Brother Sammuel (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+330, 243235, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10783.0634765625, -4536.5341796875, 53.796875, 5.763441085815429687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidstorm Bombardier (Area: 16538 - Difficulty: 0) CreateObject1
(@CGUID+331, 243223, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10812.4365234375, -4593.724609375, 36.796875, 4.181214809417724609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590, 1251577 - 1251577)
(@CGUID+332, 243235, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10775.7509765625, -4582.1005859375, 35.4013671875, 0.854655086994171142, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidstorm Bombardier (Area: 16538 - Difficulty: 0) CreateObject1
(@CGUID+333, 243223, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10810.5791015625, -4593.43310546875, 36.796875, 4.76570892333984375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+334, 246658, 2858, 16182, 16538, '0', '0', 0, 0, 1, 10821.8583984375, -4633.91943359375, 36.87735748291015625, 3.888580560684204101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Grand Lector Enaara (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 99203 - 99203)
(@CGUID+335, 243223, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10810.4501953125, -4526.37353515625, 92.29572296142578125, 4.304558753967285156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+336, 243215, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10826.328125, -4612.43603515625, 36.84276580810546875, 1.651440739631652832, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Nisa Cindersteel (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1223719 - 1223719, 99203 - 99203)
(@CGUID+337, 243223, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10825.23828125, -4598.951171875, 36.796875, 5.648043155670166015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590, 1251577 - 1251577)
(@CGUID+338, 240665, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10677.8740234375, -4503.88916015625, 53.4359283447265625, 6.144863128662109375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Berserker (Area: 16538 - Difficulty: 0) CreateObject1
(@CGUID+339, 243223, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10683.1142578125, -4548.97509765625, 35.4013671875, 3.130096197128295898, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+340, 240665, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10630.337890625, -4710.56982421875, 53.43593215942382812, 2.538203716278076171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Berserker (Area: 16538 - Difficulty: 0) CreateObject1
(@CGUID+341, 243223, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10772.7080078125, -4586.69970703125, 35.4013671875, 5.262042045593261718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+342, 243223, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10803.6943359375, -4636.54833984375, 35.9676971435546875, 4.6616973876953125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590, 1251577 - 1251577)
(@CGUID+343, 239544, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10699.8564453125, -4589.8369140625, 35.59375, 1.344326257705688476, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Oozing Void (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 123169 - 123169)
(@CGUID+344, 241617, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10930.62890625, -4550.8583984375, 37.59375, 3.79723978042602539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Berserker (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251577 - 1251577, 1251590 - 1251590)
(@CGUID+345, 241615, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10805.0634765625, -4552.6474609375, 35.9058837890625, 4.633199214935302734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Intruder (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+346, 243235, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10722.2490234375, -4606.86279296875, 35.59375, 6.259302139282226562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidstorm Bombardier (Area: 16538 - Difficulty: 0) CreateObject1
(@CGUID+347, 206118, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10825.4755859375, -4592.7255859375, 39.50122833251953125, 6.268740177154541015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic - Empty Bunny (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+348, 243223, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10779.599609375, -4657.66015625, 35.40140151977539062, 1.202120542526245117, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+349, 243218, 2858, 16182, 16538, '0', '0', 0, 0, 1, 10820.8193359375, -4597.84130859375, 36.91482162475585937, 5.880192279815673828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Vindicator Boros (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1248653 - 1248653)
(@CGUID+350, 243223, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10777.748046875, -4578.0625, 35.40137100219726562, 5.75501251220703125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+351, 243223, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10701.7373046875, -4622.82666015625, 35.59375, 3.344984054565429687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+352, 243223, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10688.818359375, -4590.75, 35.59375, 5.408619880676269531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+353, 243223, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10774.5048828125, -4492.548828125, 41.19462966918945312, 3.716421127319335937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+354, 206118, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10816.6513671875, -4631.14599609375, 38.20672607421875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic - Empty Bunny (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+355, 243230, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10809.6337890625, -4599.16552734375, 36.796875, 1.16125345230102539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+356, 246654, 2858, 16182, 16538, '0', '0', 0, 0, 1, 10803.5107421875, -4640.1669921875, 35.4013671875, 3.716963052749633789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Crusader Kern (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+357, 243227, 2858, 16182, 16538, '0', '0', 0, 0, 1, 10828.9814453125, -4601.7099609375, 36.8080291748046875, 2.506450176239013671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Tahu Sagewind (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 99203 - 99203)
(@CGUID+358, 243235, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10723.5908203125, -4568.0556640625, 35.4013671875, 5.071846961975097656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidstorm Bombardier (Area: 16538 - Difficulty: 0) CreateObject1
(@CGUID+359, 247269, 2858, 16182, 16538, '0', '0', 0, 0, 1, 10830.5068359375, -4635.30908203125, 36.73685073852539062, 2.860931634902954101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- War Chaplain Senn (Area: 16538 - Difficulty: 0) CreateObject1
(@CGUID+360, 247271, 2858, 16182, 16538, '0', '0', 0, 0, 1, 10825.5849609375, -4624.236328125, 36.88922119140625, 3.163865327835083007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Commander Koruth Mountainfist (Area: 16538 - Difficulty: 0) CreateObject1
(@CGUID+361, 247270, 2858, 16182, 16538, '0', '0', 0, 0, 1, 10838.1767578125, -4636.5693359375, 36.73685073852539062, 3.444773197174072265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- General Amias Bellamy (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1227208 - 1227208)
(@CGUID+362, 240665, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10686.3115234375, -4555.7578125, 35.4013671875, 3.607745647430419921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Berserker (Area: 16538 - Difficulty: 0) CreateObject1
(@CGUID+363, 247272, 2858, 16182, 16538, '0', '0', 0, 0, 1, 10838.814453125, -4633.38037109375, 36.73685073852539062, 2.429260492324829101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Commander Venel Lightblood (Area: 16538 - Difficulty: 0) CreateObject1
(@CGUID+364, 243223, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10733.017578125, -4638.513671875, 35.59375, 3.442870616912841796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+365, 243223, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10808.1552734375, -4597.20166015625, 36.796875, 0.228517413139343261, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+366, 243235, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10808.2939453125, -4561.11962890625, 36.03158950805664062, 4.375772953033447265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidstorm Bombardier (Area: 16538 - Difficulty: 0) CreateObject1
(@CGUID+367, 243223, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10815.5986328125, -4641.71533203125, 35.4013671875, 1.144651651382446289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+368, 243230, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10766.5244140625, -4546.21923828125, 54, 0.482012361288070678, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251533 - 1251533, 1251590 - 1251590, 1251577 - 1251577)
(@CGUID+369, 246659, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10815.779296875, -4644.4912109375, 36.81199264526367187, 2.170175552368164062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Fiona (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 99203 - 99203)
(@CGUID+370, 243223, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10771.806640625, -4489.408203125, 41.19462966918945312, 3.716421127319335937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+371, 243216, 2858, 16182, 16538, '0', '0', 0, 0, 1, 10810.748046875, -4596.5986328125, 36.796875, 3.370110273361206054, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Kyros Warstone (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 423723 - 423723, 423724 - 423724)
(@CGUID+372, 243219, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10829.4658203125, -4607.36962890625, 36.849090576171875, 2.036182403564453125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Meridelle Lightspark (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 99203 - 99203)
(@CGUID+373, 243230, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10808.8720703125, -4598.6865234375, 36.796875, 5.285516738891601562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251533 - 1251533, 1251590 - 1251590, 1251577 - 1251577)
(@CGUID+374, 240665, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10600.212890625, -4629.93212890625, 48.69982528686523437, 6.240404129028320312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Berserker (Area: 16538 - Difficulty: 0) CreateObject1
(@CGUID+375, 241617, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10954.3955078125, -4527.42138671875, 38.483612060546875, 3.604239225387573242, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Berserker (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590) (possible waypoints or random movement)
(@CGUID+376, 243223, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10803.9677734375, -4529.96337890625, 82.544189453125, 5.084683895111083984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: )
-- (@CGUID+377, 246179, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10776.53125, -4591.24462890625, 38.49872970581054687, 4.542636871337890625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Empowered Dragonhawk (Area: 16538 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
-- (@CGUID+378, 246179, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10772.06640625, -4582.60400390625, 38.49872970581054687, 4.542636871337890625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Empowered Dragonhawk (Area: 16538 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
-- (@CGUID+379, 237278, 2858, 16182, 16538, '0', '0', 0, 0, 1, 10779.599609375, -4589, 35.40140151977539062, 2.865742444992065429, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Lady Liadrin (Area: 16538 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
-- (@CGUID+380, 246179, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10763.076171875, -4587.85791015625, 38.49872970581054687, 4.542636871337890625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Empowered Dragonhawk (Area: 16538 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
(@CGUID+381, 244034, 2858, 16182, 16538, '0', '0', 0, 0, 1, 10858.669921875, -4622.078125, 37.6769256591796875, 2.41754007339477539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Lothraxion (Area: 16538 - Difficulty: 0) CreateObject1
(@CGUID+382, 244047, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10950.12890625, -4691.36279296875, 37.65219879150390625, 2.68090987205505371, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Void-Runed Disruptor (Area: 16538 - Difficulty: 0) CreateObject1
(@CGUID+383, 243235, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10771.50390625, -4686.1962890625, 53.75777435302734375, 1.173303008079528808, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidstorm Bombardier (Area: 16538 - Difficulty: 0) CreateObject1
(@CGUID+384, 243223, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10790.8408203125, -4513.85791015625, 93.63671112060546875, 3.716421127319335937, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590) (possible waypoints or random movement)
(@CGUID+385, 244037, 2858, 16182, 16538, '0', '0', 0, 0, 1, 10864.8662109375, -4611.63916015625, 37.6769256591796875, 2.492902517318725585, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Faerin Lothar (Area: 16538 - Difficulty: 0) CreateObject1
(@CGUID+386, 243223, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10800.1142578125, -4521.345703125, 92.5826263427734375, 4.297019481658935546, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Reserve (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590) (possible waypoints or random movement)
(@CGUID+387, 241617, 2858, 16182, 16538, '0', '0', 0, 0, 0, 10979.498046875, -4531.876953125, 45.35054397583007812, 3.648720979690551757, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Berserker (Area: 16538 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+388, 241617, 2858, 16182, 16356, '0', '0', 0, 0, 0, 10998.0869140625, -4524.1591796875, 52.74793243408203125, 3.386295795440673828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Berserker (Area: 16356 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+389, 244053, 2858, 16182, 16356, '0', '0', 0, 0, 0, 10917.751953125, -4684.70166015625, 37.67128372192382812, 0.842183172702789306, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Intruder (Area: 16356 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+390, 241625, 2858, 16182, 16356, '0', '0', 0, 0, 1, 10901.4560546875, -4611.34375, 37.73251724243164062, 2.92975616455078125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- High Exarch Turalyon (Area: 16356 - Difficulty: 0) CreateObject1
(@CGUID+391, 227536, 2858, 16182, 16356, '0', '0', 0, 0, 0, 11019.0244140625, -4616.09716796875, 35.00642776489257812, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic - Empty Bunny (Area: 16356 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+392, 244053, 2858, 16182, 16356, '0', '0', 0, 0, 0, 10923.755859375, -4583.3642578125, 37.59375, 1.505218744277954101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Intruder (Area: 16356 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+393, 238782, 2858, 16182, 16356, '0', '0', 0, 0, 1, 10912.9580078125, -4655.63720703125, 37.59375, 4.713305950164794921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Arator (Area: 16356 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+394, 244039, 2858, 16182, 16356, '0', '0', 0, 0, 1, 10921.09375, -4625.20166015625, 37.83840179443359375, 0.357769578695297241, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Alonsus Faol (Area: 16356 - Difficulty: 0) CreateObject1
-- (@CGUID+395, 241615, 2858, 16182, 16356, '0', '0', 0, 0, 0, 10936.6162109375, -4612.2568359375, 35.19717025756835937, 2.15721893310546875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Intruder (Area: 16356 - Difficulty: 0) CreateObject1 (Auras: ) - !!! might be temporary spawn !!!
(@CGUID+396, 259731, 2858, 16182, 16356, '0', '0', 0, 0, 0, 10925.484375, -4567.197265625, 37.59374618530273437, 1.593176960945129394, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16356 - Difficulty: 0) CreateObject1 (Auras: 1251577 - 1251577, 1251590 - 1251590)
(@CGUID+397, 244047, 2858, 16182, 16356, '0', '0', 0, 0, 0, 11009.44140625, -4678.453125, 34.18749618530273437, 3.155850887298583984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Void-Runed Disruptor (Area: 16356 - Difficulty: 0) CreateObject1
(@CGUID+398, 244047, 2858, 16182, 16356, '0', '0', 0, 0, 0, 11026.4921875, -4563.17919921875, 34.18749618530273437, 6.230846405029296875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Void-Runed Disruptor (Area: 16356 - Difficulty: 0) CreateObject1
(@CGUID+399, 244053, 2858, 16182, 16356, '0', '0', 0, 0, 0, 10931.0712890625, -4684.44287109375, 37.59375381469726562, 2.403130769729614257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Intruder (Area: 16356 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+400, 244053, 2858, 16182, 16356, '0', '0', 0, 0, 0, 10921.2939453125, -4552.82763671875, 37.59374618530273437, 5.114568710327148437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Intruder (Area: 16356 - Difficulty: 0) CreateObject1 (Auras: 1251577 - 1251577, 1251590 - 1251590)
(@CGUID+401, 252673, 2858, 16182, 16356, '0', '0', 0, 0, 1, 10935.1376953125, -4563.17431640625, 37.59375, 0.9397469162940979, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Vindicator Xayann (Area: 16356 - Difficulty: 0) CreateObject1 (Auras: 1248653 - 1248653) (possible waypoints or random movement)
(@CGUID+402, 244088, 2858, 16182, 16356, '0', '0', 0, 0, 1, 11059.904296875, -4630.2939453125, 34.18749618530273437, 4.0418243408203125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Imperatus (Area: 16356 - Difficulty: 0) CreateObject1
(@CGUID+403, 252672, 2858, 16182, 16356, '0', '0', 0, 0, 0, 10927.72265625, -4553.09375, 37.59375, 0.655646920204162597, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Quel'Danas Sentinel (Area: 16356 - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+404, 252627, 2858, 16182, 16356, '0', '0', 0, 0, 0, 10967.1923828125, -4601.06103515625, 34.91876220703125, 3.099357128143310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Ember (Area: 16356 - Difficulty: 0) CreateObject1
(@CGUID+405, 252627, 2858, 16182, 16356, '0', '0', 0, 0, 0, 10963.8642578125, -4619.73095703125, 34.91876220703125, 3.099357128143310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Ember (Area: 16356 - Difficulty: 0) CreateObject1
-- (@CGUID+406, 165189, 2858, 16182, 16356, '0', '0', 0, 0, 0, 10990.5078125, -4627.71728515625, 34.18749618530273437, 3.098102569580078125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic Hunter Pet (Area: 16356 - Difficulty: 0) CreateObject1 (Auras: 157863 - 157863, 166615 - 166615, 263934 - 263934, 8875 - 8875, 19581 - 19581, 34902 - 34902, 65220 - 65220, 88680 - 88680, 264662 - 264662, 388035 - 388035) - !!! might be temporary spawn !!!
(@CGUID+407, 244053, 2858, 16182, 16356, '0', '0', 0, 0, 0, 10968.283203125, -4663.0703125, 34.18749618530273437, 2.392456293106079101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Intruder (Area: 16356 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+408, 244053, 2858, 16182, 16356, '0', '0', 0, 0, 0, 10941.2255859375, -4698.2900390625, 37.59375, 1.578959345817565917, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Intruder (Area: 16356 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+409, 252627, 2858, 16182, 16356, '0', '0', 0, 0, 0, 10976.728515625, -4637.83154296875, 35.6612091064453125, 3.099357128143310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Ember (Area: 16356 - Difficulty: 0) CreateObject1
(@CGUID+410, 246779, 2858, 16182, 16356, '0', '0', 0, 0, 1, 10947.0712890625, -4553.79150390625, 37.59375, 1.241467595100402832, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Lord Grayson Shadowbreaker (Area: 16356 - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+411, 237278, 2858, 16182, 16356, '0', '0', 0, 0, 1, 10900.5341796875, -4620.6162109375, 37.6702423095703125, 2.865742444992065429, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Lady Liadrin (Area: 16356 - Difficulty: 0) CreateObject1
(@CGUID+412, 252627, 2858, 16182, 16356, '0', '0', 0, 0, 0, 10980.1689453125, -4607.08837890625, 34.91876220703125, 3.099357128143310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Ember (Area: 16356 - Difficulty: 0) CreateObject1
(@CGUID+413, 244088, 2858, 16182, 16356, '0', '0', 0, 0, 1, 11084.904296875, -4618.63916015625, 34.20345687866210937, 3.238022565841674804, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Imperatus (Area: 16356 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+414, 241617, 2858, 16182, 16356, '0', '0', 0, 0, 0, 11040.3544921875, -4506.7880859375, 67.73552703857421875, 2.998395681381225585, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Berserker (Area: 16356 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+415, 239904, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10956.5263671875, -4543.830078125, 54.9111328125, 2.713542461395263671, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Void Mistlurker (Area: 16555 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+416, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10994.76171875, -4597.71875, 34.18749618530273437, 5.337135791778564453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+417, 239904, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10950.296875, -4543.53466796875, 58.17206192016601562, 3.81615447998046875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Void Mistlurker (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+418, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10973.298828125, -4676.6787109375, 34.2034759521484375, 2.192410707473754882, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+419, 244053, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10984.6826171875, -4670.27783203125, 34.20346450805664062, 0.217479065060615539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Intruder (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+420, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10983.369140625, -4656.14892578125, 34.18749618530273437, 3.378628015518188476, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1
(@CGUID+421, 243223, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10805.5712890625, -4645.2373046875, 35.4013671875, 0.626331806182861328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251577 - 1251577)
(@CGUID+422, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10949.4931640625, -4696.89599609375, 37.65787506103515625, 2.192410707473754882, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
-- (@CGUID+423, 241615, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10969.8193359375, -4663.189453125, 34.2034454345703125, 0.40529218316078186, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Intruder (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: ) - !!! might be temporary spawn !!!
-- (@CGUID+424, 241615, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10975.9921875, -4676.216796875, 34.18749618530273437, 0.348282724618911743, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Intruder (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: ) - !!! might be temporary spawn !!!
-- (@CGUID+425, 241615, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10970.9580078125, -4572.46875, 34.2034454345703125, 2.754950284957885742, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Intruder (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: ) - !!! might be temporary spawn !!!
-- (@CGUID+426, 244027, 2858, 16182, 16555, '0', '0', 0, 0, 1, 10901.5, -4611.33984375, 37.649200439453125, 6.118876934051513671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- High Exarch Turalyon (Area: 16555 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
-- (@CGUID+427, 244026, 2858, 16182, 16555, '0', '0', 0, 0, 1, 10900.5, -4620.6201171875, 37.5868988037109375, 6.208251476287841796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Lady Liadrin (Area: 16555 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
-- (@CGUID+428, 246682, 2858, 16182, 16555, '0', '0', 0, 0, 1, 10880.5, -4624.56982421875, 37.64390182495117187, 0.94093102216720581, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Lothraxion (Area: 16555 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
-- (@CGUID+429, 244032, 2858, 16182, 16555, '0', '0', 0, 0, 1, 10879.400390625, -4607.14990234375, 37.56010055541992187, 4.81214141845703125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Faerin Lothar (Area: 16555 - Difficulty: 0) CreateObject1 - !!! might be temporary spawn !!!
(@CGUID+430, 244047, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10979.34375, -4558.5, 35.3910064697265625, 4.541409969329833984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Void-Runed Disruptor (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+431, 243223, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10806.6611328125, -4635.12158203125, 36.667236328125, 4.13697052001953125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251577 - 1251577)
(@CGUID+432, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10916.958984375, -4547.564453125, 37.66968536376953125, 2.192410707473754882, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+433, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10969.982421875, -4555.7568359375, 34.20347976684570312, 2.192410707473754882, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+434, 243223, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10816.583984375, -4589.04296875, 36.796875, 5.372169971466064453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+435, 246672, 2858, 16182, 16555, '0', '0', 0, 0, 1, 11024.2275390625, -4590.34375, 34.27109527587890625, 4.005798816680908203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Aponi Brightmane (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+436, 246670, 2858, 16182, 16555, '0', '0', 0, 0, 1, 11028.0712890625, -4642.13916015625, 34.27109527587890625, 2.171624183654785156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Delas Moonfang (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+437, 252627, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11015.5859375, -4581.033203125, 35.08174514770507812, 3.099357128143310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Ember (Area: 16555 - Difficulty: 0) CreateObject1
(@CGUID+438, 252627, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10996.1513671875, -4665.36962890625, 34.91876220703125, 3.099357128143310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Ember (Area: 16555 - Difficulty: 0) CreateObject1
(@CGUID+439, 252627, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11022.1171875, -4665.36962890625, 35.08174514770507812, 3.099357128143310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Ember (Area: 16555 - Difficulty: 0) CreateObject1
(@CGUID+440, 252627, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10991.619140625, -4582.796875, 34.91876220703125, 3.099357128143310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Ember (Area: 16555 - Difficulty: 0) CreateObject1
(@CGUID+441, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11017.4033203125, -4633.96728515625, 34.18749618530273437, 1.371888399124145507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+442, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11026.3896484375, -4604.39599609375, 34.18749618530273437, 3.948314189910888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+443, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11039.1650390625, -4568.443359375, 34.18749618530273437, 4.789629936218261718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+444, 239904, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10995.3671875, -4530.51806640625, 64.833740234375, 4.100545883178710937, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Void Mistlurker (Area: 16555 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+445, 244027, 2858, 16182, 16555, '0', '0', 0, 0, 1, 10991.3115234375, -4608.47412109375, 33.83426284790039062, 6.118876934051513671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- High Exarch Turalyon (Area: 16555 - Difficulty: 0) CreateObject1
(@CGUID+446, 244026, 2858, 16182, 16555, '0', '0', 0, 0, 1, 10991.158203125, -4626.28466796875, 34.27109527587890625, 6.208251476287841796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Lady Liadrin (Area: 16555 - Difficulty: 0) CreateObject1
(@CGUID+447, 246675, 2858, 16182, 16555, '0', '0', 0, 0, 1, 11040.4130859375, -4602.37158203125, 34.27109909057617187, 4.005798816680908203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Anduin Wrynn (Area: 16555 - Difficulty: 0) CreateObject1
(@CGUID+448, 246669, 2858, 16182, 16555, '0', '0', 0, 0, 1, 11042.3759765625, -4627.35791015625, 34.27109527587890625, 2.37468266487121582, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Prophet Velen (Area: 16555 - Difficulty: 0) CreateObject1
(@CGUID+449, 252627, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11034.0732421875, -4571.3369140625, 35.08174514770507812, 3.099357128143310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Ember (Area: 16555 - Difficulty: 0) CreateObject1
(@CGUID+450, 252627, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11049.982421875, -4650.09033203125, 35.08174514770507812, 3.099357128143310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Ember (Area: 16555 - Difficulty: 0) CreateObject1
(@CGUID+451, 252627, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11048.6142578125, -4581.033203125, 35.08174514770507812, 3.099357128143310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Ember (Area: 16555 - Difficulty: 0) CreateObject1
-- (@CGUID+452, 241615, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11031.5888671875, -4562.23095703125, 34.18749618530273437, 3.083246707916259765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Intruder (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: ) - !!! might be temporary spawn !!!
(@CGUID+453, 244032, 2858, 16182, 16555, '0', '0', 0, 0, 1, 11002.107421875, -4593.7744140625, 34.27109527587890625, 4.81214141845703125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Faerin Lothar (Area: 16555 - Difficulty: 0) CreateObject1
(@CGUID+454, 246682, 2858, 16182, 16555, '0', '0', 0, 0, 1, 11003.7919921875, -4641.96533203125, 34.27109527587890625, 0.94093102216720581, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Lothraxion (Area: 16555 - Difficulty: 0) CreateObject1
(@CGUID+455, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11003.8251953125, -4692.595703125, 34.20347976684570312, 4.197109699249267578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+456, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10949.4931640625, -4696.89599609375, 37.65787506103515625, 2.192410707473754882, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+457, 244053, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11044.8408203125, -4562.79248046875, 34.18749618530273437, 4.309239864349365234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Intruder (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+458, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11047.12109375, -4565.64990234375, 34.18749618530273437, 3.112810611724853515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+459, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10973.298828125, -4676.6787109375, 34.2034759521484375, 2.192410707473754882, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+460, 252627, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11048.6142578125, -4592.37353515625, 35.08174514770507812, 3.099357128143310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Ember (Area: 16555 - Difficulty: 0) CreateObject1
(@CGUID+461, 252627, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11063.6298828125, -4619.3505859375, 35.08174514770507812, 3.099357128143310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Ember (Area: 16555 - Difficulty: 0) CreateObject1
(@CGUID+462, 252627, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11064.9931640625, -4592.37353515625, 35.08174514770507812, 3.099357128143310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Ember (Area: 16555 - Difficulty: 0) CreateObject1
(@CGUID+463, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11034.4267578125, -4545.13037109375, 34.20346832275390625, 4.197109699249267578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+464, 252627, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11029.9599609375, -4640.79541015625, 35.08174514770507812, 3.099357128143310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Ember (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
-- (@CGUID+465, 234018, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11072.6181640625, -4635.81298828125, 34.27083206176757812, 0.955322265625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Bear (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: ) - !!! might be temporary spawn !!!
(@CGUID+466, 244053, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11023.0068359375, -4546.359375, 34.20346450805664062, 5.133213043212890625, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Intruder (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
-- (@CGUID+467, 62005, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11083.9521484375, -4621.21142578125, 34.1875, 1.294282436370849609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Beast (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 8875 - 8875, 65220 - 65220, 1284992 - 1284992) - !!! might be temporary spawn !!!
-- (@CGUID+468, 62005, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11083.8564453125, -4621.169921875, 34.1875, 1.252362608909606933, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Beast (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 8875 - 8875, 65220 - 65220, 1284992 - 1284992) - !!! might be temporary spawn !!!
(@CGUID+469, 252627, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11043.4228515625, -4607.09228515625, 35.08174514770507812, 3.099357128143310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Ember (Area: 16555 - Difficulty: 0) CreateObject1
(@CGUID+470, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11051.8544921875, -4565.7861328125, 34.18749618530273437, 3.112772703170776367, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
-- (@CGUID+471, 62005, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11081.0078125, -4636.33935546875, 34.27083206176757812, 1.366919517517089843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Beast (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: ) - !!! might be temporary spawn !!!
-- (@CGUID+472, 241615, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11051.6455078125, -4555.32958984375, 34.18749618530273437, 3.217415809631347656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Intruder (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: ) - !!! might be temporary spawn !!!
-- (@CGUID+473, 241615, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11051.671875, -4555.3408203125, 34.18749618530273437, 5.123811244964599609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Intruder (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: ) - !!! might be temporary spawn !!!
-- (@CGUID+474, 241615, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11032.720703125, -4686.794921875, 34.18749618530273437, 1.07809460163116455, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Intruder (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: ) - !!! might be temporary spawn !!!
(@CGUID+475, 244047, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11058.8408203125, -4569.5380859375, 35.44164276123046875, 2.744059324264526367, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Void-Runed Disruptor (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
-- (@CGUID+476, 165189, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11069.6826171875, -4629.9580078125, 34.27083206176757812, 0.396177649497985839, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Generic Hunter Pet (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 157863 - 157863, 166615 - 166615) - !!! might be temporary spawn !!!
(@CGUID+477, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11047.65625, -4684.42529296875, 34.20346450805664062, 4.197109699249267578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+478, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11010.04296875, -4685.36279296875, 34.18749618530273437, 0.860663056373596191, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+479, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10986.4296875, -4626.955078125, 34.18749618530273437, 0.673098623752593994, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+480, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10993.5302734375, -4583.7197265625, 34.18749618530273437, 4.727716445922851562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+481, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10980.353515625, -4608.77490234375, 34.18749618530273437, 6.16737222671508789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+482, 244047, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11071.1572265625, -4661.97900390625, 34.20346450805664062, 2.227736473083496093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Void-Runed Disruptor (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+483, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10987.16015625, -4646.66943359375, 34.18749618530273437, 0.78930211067199707, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+484, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10973.982421875, -4558.3232421875, 34.23180770874023437, 5.712910652160644531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+485, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10982.37890625, -4630.18408203125, 34.18749618530273437, 0.673098623752593994, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+486, 244053, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11003.8388671875, -4540.9619140625, 34.2034759521484375, 4.426189422607421875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Intruder (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+487, 244053, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10960.349609375, -4572.81591796875, 34.20346832275390625, 5.133213043212890625, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Intruder (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+488, 244047, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11004.9501953125, -4687.298828125, 34.17682647705078125, 1.461575865745544433, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Void-Runed Disruptor (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+489, 244047, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11045.857421875, -4680.57470703125, 34.20345687866210937, 2.139440298080444335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Void-Runed Disruptor (Area: 16555 - Difficulty: 0) CreateObject1
(@CGUID+490, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10965.185546875, -4607.01025390625, 34.18749618530273437, 6.16737222671508789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+491, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11019.9658203125, -4664.60595703125, 34.18749618530273437, 1.59691786766052246, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+492, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10990.79296875, -4643.00830078125, 34.18749618530273437, 0.78930211067199707, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+493, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11062.2578125, -4557.078125, 34.2034759521484375, 2.192410707473754882, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+494, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11015.5283203125, -4677.90625, 34.18749618530273437, 1.087926626205444335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+495, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10963.7646484375, -4644.66748046875, 34.1875, 0.627727389335632324, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
-- (@CGUID+496, 241615, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11051.666015625, -4555.328125, 34.20346832275390625, 4.359141826629638671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Intruder (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: ) - !!! might be temporary spawn !!!
-- (@CGUID+497, 241615, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11036.5888671875, -4682.98193359375, 34.18749618530273437, 0.545964002609252929, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Intruder (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: ) - !!! might be temporary spawn !!!
(@CGUID+498, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10980.1904296875, -4658.8427734375, 34.18749618530273437, 1.140563726425170898, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+499, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10951.814453125, -4606.83349609375, 34.1875, 6.281859397888183593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263); -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+500, 244088, 2858, 16182, 16555, '0', '0', 0, 0, 1, 11084.904296875, -4618.63916015625, 34.20345687866210937, 3.238022565841674804, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Imperatus (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+501, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11019.96875, -4664.4892578125, 34.18749618530273437, 1.600862383842468261, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+502, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10987.2685546875, -4646.56005859375, 34.18749618530273437, 0.78930211067199707, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+503, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10975.5, -4636.12744140625, 34.18749618530273437, 0.717597901821136474, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+504, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10951.80859375, -4606.83349609375, 34.1875, 6.28192758560180664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+505, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10990.68359375, -4643.11865234375, 34.18749618530273437, 0.78930211067199707, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+506, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11013.24609375, -4681.63720703125, 34.18749618530273437, 0.860663056373596191, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+507, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10986.6494140625, -4626.77978515625, 34.18749618530273437, 0.673098623752593994, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+508, 252627, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10976.728515625, -4637.83154296875, 35.6612091064453125, 3.099357128143310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Ember (Area: 16555 - Difficulty: 0) CreateObject1
(@CGUID+509, 244053, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10985.0322265625, -4686.99658203125, 34.20347213745117187, 0.61977773904800415, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Intruder (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+510, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10995.701171875, -4610.56396484375, 34.18749618530273437, 6.167039394378662109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
-- (@CGUID+511, 241615, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11032.7080078125, -4686.8193359375, 34.20346450805664062, 0.770533144474029541, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidborn Intruder (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: ) - !!! might be temporary spawn !!!
(@CGUID+512, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10995.1708984375, -4598.2861328125, 34.18749618530273437, 5.337135791778564453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+513, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10982.2607421875, -4654.66796875, 34.18749618530273437, 1.070077300071716308, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+514, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10971.427734375, -4639.10693359375, 34.1875, 0.627749025821685791, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+515, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10982.3095703125, -4563.43359375, 34.18749618530273437, 5.748339176177978515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+516, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11038.3447265625, -4559.0341796875, 34.18749618530273437, 4.819324493408203125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+517, 241617, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11085.1142578125, -4529.38037109375, 83.1584625244140625, 3.840314388275146484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Berserker (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+518, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10956.728515625, -4606.8681640625, 34.1875, 6.276010513305664062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+519, 252627, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10980.1689453125, -4607.08837890625, 34.91876220703125, 3.099357128143310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Ember (Area: 16555 - Difficulty: 0) CreateObject1
(@CGUID+520, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10993.8134765625, -4639.38623046875, 34.18749618530273437, 0.880755603313446044, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+521, 252627, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11064.9931640625, -4638.74853515625, 35.08174514770507812, 3.099357128143310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Ember (Area: 16555 - Difficulty: 0) CreateObject1
(@CGUID+522, 252627, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10996.1513671875, -4647.54541015625, 34.91876220703125, 3.099357128143310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Ember (Area: 16555 - Difficulty: 0) CreateObject1
(@CGUID+523, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10990.5234375, -4643.27978515625, 34.18749618530273437, 0.78930211067199707, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+524, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10982.56640625, -4630.03515625, 34.18749618530273437, 0.673098623752593994, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+525, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10946.6123046875, -4606.82666015625, 34.1875, 6.281888484954833984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+526, 252627, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10986.75390625, -4626.5712890625, 35.08174514770507812, 3.099357128143310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Ember (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+527, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11019.9609375, -4664.53857421875, 34.18749618530273437, 1.595291376113891601, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+528, 244047, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11006.7685546875, -4558.5, 35.3910064697265625, 4.938878536224365234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Void-Runed Disruptor (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+529, 241617, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11072.1767578125, -4536.75341796875, 82.35901641845703125, 2.27754974365234375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Berserker (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+530, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10987.48828125, -4646.3388671875, 34.18749618530273437, 0.78930211067199707, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+531, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10979.0703125, -4633.01171875, 34.18749618530273437, 0.717597901821136474, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+532, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11013.8330078125, -4657.6904296875, 34.18749618530273437, 1.672803163528442382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+533, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10966.0439453125, -4607.10986328125, 34.18749618530273437, 6.16737222671508789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+534, 241617, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10948.560546875, -4549.43408203125, 37.64340972900390625, 4.171863079071044921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Berserker (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+535, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10993.8828125, -4639.302734375, 34.18749618530273437, 0.880755603313446044, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+536, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11020.181640625, -4669.03125, 34.18749618530273437, 1.087926626205444335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+537, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10971.4150390625, -4639.11572265625, 34.1875, 0.627750694751739501, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+538, 244053, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10984.6826171875, -4670.27783203125, 34.20346450805664062, 0.217479065060615539, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Intruder (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590) (possible waypoints or random movement)
(@CGUID+539, 244053, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10972.6650390625, -4667.4814453125, 34.18749618530273437, 5.464321613311767578, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Intruder (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590) (possible waypoints or random movement)
(@CGUID+540, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10921.3115234375, -4570.00830078125, 37.59374618530273437, 4.643502712249755859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+541, 244053, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10918.0634765625, -4548.95166015625, 37.667999267578125, 4.921108722686767578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Intruder (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+542, 252627, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10967.1923828125, -4582.796875, 34.91876220703125, 3.099357128143310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Ember (Area: 16555 - Difficulty: 0) CreateObject1
(@CGUID+543, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10987.462890625, -4646.36474609375, 34.18749618530273437, 0.78930211067199707, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+544, 244053, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10931.3525390625, -4581.9599609375, 37.63721084594726562, 4.386876106262207031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Intruder (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+545, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11017.236328125, -4660.8388671875, 34.18749618530273437, 2.478977203369140625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+546, 239904, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11022.7939453125, -4503.33837890625, 78.28656768798828125, 4.640619277954101562, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Void Mistlurker (Area: 16555 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+547, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10945.818359375, -4650.9091796875, 34.15496444702148437, 0.31564265489578247, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+548, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10984.642578125, -4650.31494140625, 34.18749618530273437, 1.070077300071716308, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+549, 252627, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11034.9482421875, -4653.77783203125, 35.08174514770507812, 3.099357128143310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Sun's Ember (Area: 16555 - Difficulty: 0) CreateObject1
(@CGUID+550, 241617, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11084.2490234375, -4537.26416015625, 83.1499786376953125, 2.27754974365234375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Berserker (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+551, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10974.96875, -4608.1484375, 34.18749618530273437, 6.16737222671508789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+552, 244047, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10948.974609375, -4523.4287109375, 38.08940505981445312, 3.701852798461914062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Void-Runed Disruptor (Area: 16555 - Difficulty: 0) CreateObject1
(@CGUID+553, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11017.9150390625, -4673.35400390625, 34.18749618530273437, 1.087926626205444335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+554, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10987.38671875, -4646.44091796875, 34.18749618530273437, 0.78930211067199707, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+555, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10978.0849609375, -4560.9306640625, 34.18749618530273437, 5.748339176177978515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+556, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10974.9892578125, -4636.51904296875, 34.18749618530273437, 0.622464179992675781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+557, 241617, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11085.7978515625, -4545.51220703125, 83.14249420166015625, 2.27754974365234375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Berserker (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+558, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10979.87890625, -4608.7197265625, 34.18749618530273437, 6.167384147644042968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+559, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10982.318359375, -4654.56298828125, 34.18749618530273437, 1.070077300071716308, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+560, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11010.11328125, -4685.28125, 34.18749618530273437, 0.860663056373596191, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+561, 241617, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11058.7978515625, -4533.4287109375, 77.41613006591796875, 2.27754974365234375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Berserker (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+562, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10973.80078125, -4558.20654296875, 34.23537445068359375, 5.712910652160644531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+563, 239904, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10993.1884765625, -4532.880859375, 64.833740234375, 3.82517862319946289, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 66263), -- Void Mistlurker (Area: 16555 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+564, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10987.1767578125, -4646.65283203125, 34.18749618530273437, 0.78930211067199707, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+565, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10975.892578125, -4608.255859375, 34.18749618530273437, 6.16737222671508789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+566, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10982.529296875, -4630.064453125, 34.18749618530273437, 0.673098623752593994, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+567, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11020.1201171875, -4669.1484375, 34.18749618530273437, 1.087926626205444335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+568, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10973.962890625, -4558.31005859375, 34.23220443725585937, 5.712910652160644531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+569, 244053, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11049.5595703125, -4548.8818359375, 34.2034759521484375, 4.176634788513183593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidmarked Intruder (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+570, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10987.3203125, -4646.50830078125, 34.18749618530273437, 0.78930211067199707, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+571, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11017.7763671875, -4673.61865234375, 34.18749618530273437, 1.087926626205444335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+572, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10986.4013671875, -4626.9775390625, 34.18749618530273437, 0.673098623752593994, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+573, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10974.3818359375, -4608.080078125, 34.18749618530273437, 6.16737222671508789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+574, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10977.919921875, -4560.8330078125, 34.18749618530273437, 5.748339176177978515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+575, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10993.9287109375, -4639.24755859375, 34.18749618530273437, 0.880755603313446044, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+576, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10973.8818359375, -4558.25830078125, 34.23378753662109375, 5.712910652160644531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+577, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10979.501953125, -4632.63427734375, 34.18749618530273437, 0.717597901821136474, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+578, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10976.5458984375, -4608.33203125, 34.18749618530273437, 6.16737222671508789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+579, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10993.8212890625, -4639.37646484375, 34.18749618530273437, 0.880755603313446044, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+580, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 11017.8369140625, -4673.50341796875, 34.18749618530273437, 1.087926626205444335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+581, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10990.8544921875, -4642.94580078125, 34.18749618530273437, 0.78930211067199707, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+582, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10978.0537109375, -4560.912109375, 34.18749618530273437, 5.748339176177978515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263), -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)
(@CGUID+583, 259731, 2858, 16182, 16555, '0', '0', 0, 0, 0, 10986.794921875, -4626.66357421875, 34.18749618530273437, 0.673098623752593994, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66263); -- Voidswarm Reserve (Area: 16555 - Difficulty: 0) CreateObject1 (Auras: 1251590 - 1251590)



DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1285;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 556380, 2858, 16182, 16209, '0', '0', 0, 11100.8994140625, -4415.19384765625, 53.88355255126953125, 4.341718196868896484, 0, 0, -0.82530021667480468, 0.564694225788116455, 7200, 255, 1, 66263), -- Rampart Door (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+1, 494908, 2858, 16182, 16209, '0', '0', 0, 10503.2060546875, -4420.474609375, 97.559417724609375, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 7200, 255, 1, 66263), -- Door (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+2, 550375, 2858, 16182, 16209, '0', '0', 0, 11110.193359375, -4710.134765625, 81.44402313232421875, 2.372362136840820312, 0, 0, 0.926942825317382812, 0.375202596187591552, 7200, 255, 0, 66263), -- Sunwell Door (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+3, 550374, 2858, 16182, 16209, '0', '0', 0, 11110.345703125, -4522.9580078125, 81.77019500732421875, 3.934591293334960937, 0, 0, -0.92241859436035156, 0.386191576719284057, 7200, 255, 0, 66263), -- Sunwell Door (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+4, 617063, 2858, 16182, 16209, '0', '0', 0, 11351.36328125, -4985.21533203125, 98.3837432861328125, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 7200, 255, 1, 66263), -- Door (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+5, 612967, 2858, 16182, 16209, '0', '0', 0, 10735.3623046875, -4081.241455078125, 0, 0, 0, 0, 0, 1, 7200, 255, 1, 66263), -- 12.0 Intro Scenario Phaseable Ship (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+6, 626820, 2858, 16182, 16209, '0', '0', 0, 11464.462890625, -4368.77587890625, 47.96083831787109375, 5.314614295959472656, 0, 0, -0.465576171875, 0.885007798671722412, 7200, 255, 1, 66263), -- Orb of Translocation (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+7, 626819, 2858, 16182, 16209, '0', '0', 0, 11458.6220703125, -4367.6884765625, 29.14356613159179687, 1.899724721908569335, 0, 0, 0.813335418701171875, 0.581795036792755126, 7200, 255, 1, 66263), -- Orb of Translocation (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+8, 579329, 2858, 16182, 16209, '0', '0', 0, 10895.3671875, -4616.669921875, 37.39586639404296875, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 0, 66263), -- Sunwell Door (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+9, 494914, 2858, 16182, 16209, '0', '0', 0, 11727.900390625, -5232.728515625, 211.7383880615234375, 2.617996692657470703, 0, 0, 0.965926170349121093, 0.258817732334136962, 7200, 255, 1, 66263), -- Orb of Translocation (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+10, 612002, 2858, 16182, 16209, '0', '0', 0, 11635.689453125, -4967.87353515625, 110.1032333374023437, 1.047195315361022949, 0, 0, 0.499999046325683593, 0.866025924682617187, 7200, 255, 1, 66263), -- Door (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+11, 555879, 2858, 16182, 16209, '0', '0', 0, 11735.60546875, -5237.1767578125, 144.6988983154296875, 5.759589672088623046, 0, 0, -0.25881767272949218, 0.965926229953765869, 7200, 255, 1, 66263), -- Orb of Translocation (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+12, 549138, 2858, 16182, 16209, '0', '0', 0, 11393.9970703125, -4443.90087890625, 16.246551513671875, 5.515336036682128906, -0.00725793838500976, 0.033419609069824218, -0.37383842468261718, 0.926863133907318115, 7200, 255, 1, 66263), -- History of Sun's Reach (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+13, 549138, 2858, 16182, 16209, '0', '0', 0, 11387.1416015625, -4453.09716796875, 16.46314620971679687, 1.948523283004760742, -0.0964360237121582, 0.064480781555175781, 0.821756362915039062, 0.557905793190002441, 7200, 255, 1, 66263), -- History of Sun's Reach (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+14, 549136, 2858, 16182, 16209, '0', '0', 0, 11390.048828125, -4451.36962890625, 16.45355224609375, 0.936922192573547363, -0.50078582763671875, -0.43226242065429687, 0.208673477172851562, 0.720290303230285644, 7200, 255, 1, 66263), -- Pillaged Items (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+15, 549138, 2858, 16182, 16209, '0', '0', 0, 11386.9306640625, -4447.15478515625, 16.75540542602539062, 6.012125492095947265, 0.026120185852050781, 0.157452583312988281, -0.13412094116210937, 0.978027582168579101, 7200, 255, 1, 66263), -- History of Sun's Reach (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+16, 549135, 2858, 16182, 16209, '0', '0', 0, 11390.5693359375, -4449.26220703125, 16.246551513671875, 1.107962727546691894, 0, 0, 0.5260772705078125, 0.850436747074127197, 7200, 255, 1, 66263), -- Research of Quel'Danas (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+17, 613840, 2858, 16182, 16209, '0', '0', 0, 11314.2138671875, -4375.345703125, 4.456956386566162109, 2.121272563934326171, 0, 0, 0.872666358947753906, 0.488316953182220458, 7200, 255, 1, 66263), -- Void Anchor (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+18, 526148, 2858, 16182, 16209, '0', '0', 0, 11354.267578125, -4469.2119140625, 20.78416633605957031, 4.781200885772705078, 0, 0, -0.68236446380615234, 0.731012165546417236, 7200, 255, 1, 66263), -- Pedastal (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+19, 617063, 2858, 16182, 16209, '0', '0', 0, 11351.36328125, -4985.21533203125, 98.3837432861328125, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 7200, 255, 1, 66263), -- Door (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+20, 549136, 2858, 16182, 16209, '0', '0', 0, 11390.5595703125, -4452.15283203125, 16.17002487182617187, 1.041037678718566894, 0.04526376724243164, 0.049261093139648437, 0.49509429931640625, 0.866259872913360595, 7200, 255, 1, 66263), -- Pillaged Items (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+21, 549140, 2858, 16182, 16209, '0', '0', 0, 11393.0810546875, -4453.34033203125, 16.25050163269042968, 0.491103500127792358, -0.05878400802612304, 0.075916290283203125, 0.245271682739257812, 0.964688003063201904, 7200, 255, 1, 66263), -- Spilled Chest (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+22, 549138, 2858, 16182, 16209, '0', '0', 0, 11353.39453125, -4461.27099609375, 47.68505477905273437, 5.284212112426757812, -0.05610513687133789, 0.369884490966796875, -0.37878990173339843, 0.846496224403381347, 7200, 255, 1, 66263), -- History of Sun's Reach (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+23, 612002, 2858, 16182, 16209, '0', '0', 0, 11635.689453125, -4967.87353515625, 110.1032333374023437, 1.047195315361022949, 0, 0, 0.499999046325683593, 0.866025924682617187, 7200, 255, 1, 66263), -- Door (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+24, 573603, 2858, 16182, 16209, '0', '0', 0, 11780.4619140625, -4443.91650390625, 22.10453605651855468, 0, 0, 0, 0, 1, 7200, 255, 1, 66263), -- Void Portal (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+25, 553852, 2858, 16182, 16209, '0', '0', 0, 11462.998046875, -4376.92724609375, 47.19736480712890625, 1.626125693321228027, 0, 0, 0.726395606994628906, 0.687276780605316162, 7200, 255, 1, 66263), -- Cosmic Infuser (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+26, 518640, 2858, 16182, 16209, '0', '0', 0, 11410.1142578125, -4311.033203125, 8.923935890197753906, 1.605374932289123535, 0.6822662353515625, 0.673584938049316406, -0.24693775177001953, 0.140776023268699646, 7200, 255, 1, 66263), -- Lightspire Spear (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+27, 553848, 2858, 16182, 16209, '0', '0', 0, 11451.6142578125, -4367.4619140625, 19.94795608520507812, 5.965863227844238281, 0, 0, -0.15799617767333984, 0.987439751625061035, 7200, 255, 1, 66263), -- Staff of Disintegration (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+28, 553851, 2858, 16182, 16209, '0', '0', 0, 11349.69140625, -4461.283203125, 30.88691520690917968, 0.843902111053466796, 0, 0, 0.409541130065917968, 0.912291646003723144, 7200, 255, 1, 66263), -- Scourgebane (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+29, 555181, 2858, 16182, 16209, '0', '0', 0, 11458.779296875, -4378.90283203125, 19.693939208984375, 0, 0, 0, 0, 1, 7200, 255, 0, 66263), -- Etched Scroll (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+30, 540373, 2858, 16182, 16209, '0', '0', 0, 11458.638671875, -4367.68603515625, 29.30501937866210937, 5.199722766876220703, 0, 0, -0.51562023162841796, 0.856817245483398437, 7200, 255, 1, 66263), -- Translocation Portal (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+31, 613190, 2858, 16182, 16209, '0', '0', 0, 10735.40625, -4081.201416015625, -0.06589645892381668, 0, 0, 0, 0, 1, 7200, 255, 1, 66263), -- Sunstrider Corsair (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+32, 553839, 2858, 16182, 16209, '0', '0', 0, 11348.9931640625, -4473.361328125, 45.877044677734375, 1.200012564659118652, 0, 0, 0.564647674560546875, 0.825332045555114746, 7200, 255, 1, 66263), -- Devastation (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+33, 524892, 2858, 16182, 16209, '0', '0', 0, 11158.771484375, -4969.4775390625, 2.069998025894165039, 4.571784019470214843, 0, 0, -0.75503063201904296, 0.655689477920532226, 7200, 255, 1, 66263), -- Void Portal (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+34, 553835, 2858, 16182, 16209, '0', '0', 0, 11354.1708984375, -4467.99658203125, 20.94022941589355468, 1.638359546661376953, 0, 0, 0.730586051940917968, 0.682820677757263183, 7200, 255, 1, 66263), -- Infinity Blades (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+35, 549140, 2858, 16182, 16209, '0', '0', 0, 11440.810546875, -4393.96728515625, 17.3350372314453125, 5.607942104339599609, -0.80815649032592773, 0.396048545837402343, 0.203851699829101562, 0.385322064161300659, 7200, 255, 1, 66263), -- Spilled Chest (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+36, 642455, 2858, 16182, 16209, '0', '0', 0, 11354.5244140625, -4457.955078125, 47.41429519653320312, 4.250775337219238281, 0, 0, -0.85011577606201171, 0.526595830917358398, 7200, 255, 1, 66263), -- {DNT} Object (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+37, 642454, 2858, 16182, 16209, '0', '0', 0, 11352.337890625, -4459.1025390625, 45.49804306030273437, 5.530734539031982421, 0, 0, -0.36741256713867187, 0.930058062076568603, 7200, 255, 1, 66263), -- {DNT} Object (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+38, 556380, 2858, 16182, 16209, '0', '0', 0, 11100.8994140625, -4415.19384765625, 53.88355255126953125, 4.341718196868896484, 0, 0, -0.82530021667480468, 0.564694225788116455, 7200, 255, 1, 66263), -- Rampart Door (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+39, 642463, 2858, 16182, 16209, '0', '0', 0, 11349.5556640625, -4459.98974609375, 47.66792678833007812, 3.090420007705688476, -0.13793277740478515, -0.72029018402099609, -0.67046356201171875, 0.112406544387340545, 7200, 255, 1, 66263), -- {DNT} Object (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+40, 642456, 2858, 16182, 16209, '0', '0', 0, 11351.9423828125, -4457.55712890625, 47.42128372192382812, 4.305414676666259765, 0, 0, -0.83541393280029296, 0.549621284008026123, 7200, 255, 1, 66263), -- {DNT} Object (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+41, 642456, 2858, 16182, 16209, '0', '0', 0, 11353.978515625, -4457.0224609375, 45.80311203002929687, 2.278834819793701171, 0, 0, 0.908390045166015625, 0.418123811483383178, 7200, 255, 1, 66263), -- {DNT} Object (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+42, 642459, 2858, 16182, 16209, '0', '0', 0, 11350.4150390625, -4457.99658203125, 47.46675491333007812, 1.889805793762207031, 0, 0, 0.8104400634765625, 0.585821568965911865, 7200, 255, 1, 66263), -- {DNT} Object (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+43, 555181, 2858, 16182, 16209, '0', '0', 0, 11396.5361328125, -4443.984375, 16.246551513671875, 0, 0, 0, 0, 1, 7200, 255, 0, 66263), -- Etched Scroll (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+44, 540376, 2858, 16182, 16209, '0', '0', 0, 11464.2548828125, -4368.51416015625, 48.21047592163085937, 0.2491312175989151, 0, 0, 0.124243736267089843, 0.992251694202423095, 7200, 255, 1, 66263), -- Translocation Portal (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+45, 642447, 2858, 16182, 16209, '0', '0', 0, 11352.2587890625, -4459.1787109375, 46.29777908325195312, 4.882108688354492187, 0, 0, -0.64462947845458984, 0.76449519395828247, 7200, 255, 1, 66263), -- {DNT} Objkect (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+46, 553910, 2858, 16182, 16209, '0', '0', 0, 11354.470703125, -4446.46533203125, 45.99318313598632812, 4.631484508514404296, 0, 0, -0.73512458801269531, 0.677932024002075195, 7200, 255, 1, 66263), -- Netherstrand Longbow (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+47, 549140, 2858, 16182, 16209, '0', '0', 0, 11394.8974609375, -4454.3818359375, 17.3350372314453125, 3.104434728622436523, 0.160838127136230468, 0.849092483520507812, -0.32200241088867187, 0.386636137962341308, 7200, 255, 1, 66263), -- Spilled Chest (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+48, 549136, 2858, 16182, 16209, '0', '0', 0, 11446.615234375, -4388.31103515625, 20.03367424011230468, 1.237452626228332519, 0.254622936248779296, -0.04065799713134765, 0.588071823120117187, 0.766606509685516357, 7200, 255, 1, 66263), -- Pillaged Items (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+49, 526148, 2858, 16182, 16209, '0', '0', 0, 11463.060546875, -4378.14404296875, 47.02713775634765625, 4.769954681396484375, 0, 0, -0.68646430969238281, 0.727163493633270263, 7200, 255, 1, 66263), -- Pedastal (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+50, 526148, 2858, 16182, 16209, '0', '0', 0, 11450.462890625, -4367.0693359375, 19.73988723754882812, 2.85509657859802246, 0, 0, 0.989757537841796875, 0.142758607864379882, 7200, 255, 1, 66263), -- Pedastal (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+51, 526148, 2858, 16182, 16209, '0', '0', 0, 11348.8876953125, -4462.18603515625, 30.71525382995605468, 3.977580547332763671, 0, 0, -0.91390514373779296, 0.405927836894989013, 7200, 255, 1, 66263), -- Pedastal (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+52, 550375, 2858, 16182, 16209, '0', '0', 0, 11110.193359375, -4710.134765625, 81.44402313232421875, 2.372362136840820312, 0, 0, 0.926942825317382812, 0.375202596187591552, 7200, 255, 1, 66263), -- Sunwell Door (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+53, 550374, 2858, 16182, 16209, '0', '0', 0, 11110.345703125, -4522.9580078125, 81.77019500732421875, 3.934591293334960937, 0, 0, -0.92241859436035156, 0.386191576719284057, 7200, 255, 1, 66263), -- Sunwell Door (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+54, 526148, 2858, 16182, 16209, '0', '0', 0, 11354.5751953125, -4445.20849609375, 45.82802200317382812, 4.611666679382324218, 0, 0, -0.7418060302734375, 0.670614540576934814, 7200, 255, 1, 66263), -- Pedastal (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+55, 549135, 2858, 16182, 16209, '0', '0', 0, 11390.9052734375, -4450.5224609375, 16.246551513671875, 3.014124631881713867, -0.03044033050537109, 0.009601593017578125, 0.997446060180664062, 0.063894920051097869, 7200, 255, 1, 66263), -- Research of Quel'Danas (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+56, 642463, 2858, 16182, 16209, '0', '0', 0, 11353.6611328125, -4458.033203125, 47.42026519775390625, 6.118238449096679687, 0.007029056549072265, 0.233677864074707031, -0.07716655731201171, 0.96922159194946289, 7200, 255, 1, 66263), -- {DNT} Object (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+57, 642456, 2858, 16182, 16209, '0', '0', 0, 11352.6298828125, -4460.82275390625, 47.5726318359375, 2.278834819793701171, 0, 0, 0.908390045166015625, 0.418123811483383178, 7200, 255, 1, 66263), -- {DNT} Object (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+58, 549136, 2858, 16182, 16209, '0', '0', 0, 11445.8447265625, -4475.921875, 15.02853584289550781, 0.376562625169754028, -0.14197206497192382, -0.15507221221923828, 0.161646842956542968, 0.964192330837249755, 7200, 255, 1, 66263), -- Pillaged Items (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+59, 549135, 2858, 16182, 16209, '0', '0', 0, 11445.89453125, -4474.41845703125, 14.89537429809570312, 0.282056242227554321, 0, 0, 0.140561103820800781, 0.990072011947631835, 7200, 255, 1, 66263), -- Research of Quel'Danas (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+60, 549135, 2858, 16182, 16209, '0', '0', 0, 11446.8271484375, -4475.2412109375, 14.90129470825195312, 4.364962577819824218, 0, 0, -0.81868171691894531, 0.574247539043426513, 7200, 255, 1, 66263), -- Research of Quel'Danas (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+61, 549136, 2858, 16182, 16209, '0', '0', 0, 11448.4951171875, -4477.10400390625, 14.9296722412109375, 2.045217275619506835, 0.004824161529541015, -0.02231502532958984, 0.853112220764160156, 0.521227657794952392, 7200, 255, 1, 66263), -- Pillaged Items (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+62, 549138, 2858, 16182, 16209, '0', '0', 0, 11446.982421875, -4472.05029296875, 14.89676570892333984, 0, 0, 0, 0, 1, 7200, 255, 1, 66263), -- History of Sun's Reach (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+63, 549138, 2858, 16182, 16209, '0', '0', 0, 11437.50390625, -4474.86279296875, 14.89443492889404296, 1.193673372268676757, 0, 0, 0.562028884887695312, 0.827117621898651123, 7200, 255, 1, 66263), -- History of Sun's Reach (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+64, 526184, 2858, 16182, 16209, '0', '0', 0, 11330.978515625, -4488.87158203125, 17.87206459045410156, 3.010783195495605468, 0, 0, 0.997861862182617187, 0.06535813957452774, 7200, 255, 1, 66263), -- Training Dummy (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+65, 526148, 2858, 16182, 16209, '0', '0', 0, 11348.5546875, -4474.49658203125, 45.68550491333007812, 4.287904739379882812, 0, 0, -0.84019374847412109, 0.542286336421966552, 7200, 255, 1, 66263), -- Pedastal (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+66, 526148, 2858, 16182, 16209, '0', '0', 0, 11468.0830078125, -4507.0693359375, 52.89432907104492187, 3.09358978271484375, 0, 0, 0.999711990356445312, 0.023999160155653953, 7200, 255, 1, 66263), -- Pedastal (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+67, 553846, 2858, 16182, 16209, '0', '0', 0, 11469.2861328125, -4507.15087890625, 52.89254379272460937, 6.2067718505859375, 0, 0, -0.03819751739501953, 0.999270200729370117, 7200, 255, 1, 66263), -- Warp Slicer (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+68, 626761, 2858, 16182, 16209, '0', '0', 0, 11320.564453125, -4491.59033203125, 17.82082557678222656, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 7200, 255, 1, 66263), -- Anvil (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+69, 518640, 2858, 16182, 16208, '0', '0', 0, 11318.935546875, -4497.62158203125, 17.87206459045410156, 4.145742416381835937, 0.341364860534667968, -0.61791229248046875, -0.62175846099853515, 0.339220911264419555, 7200, 255, 1, 66263), -- Lightspire Spear (Area: 16208 - Difficulty: 0) CreateObject1
(@OGUID+70, 555181, 2858, 16182, 16208, '0', '0', 0, 11307.5673828125, -4497, 18.4218292236328125, 0.058648701757192611, -0.02843189239501953, 0.000342369079589843, 0.029341697692871093, 0.999164938926696777, 7200, 255, 1, 66263), -- Etched Scroll (Area: 16208 - Difficulty: 0) CreateObject1
(@OGUID+71, 549136, 2858, 16182, 16208, '0', '0', 0, 11374.6357421875, -4560.58837890625, 22.51871681213378906, 3.225256204605102539, -0.01642417907714843, 0.015857696533203125, -0.99887561798095703, 0.041548401117324829, 7200, 255, 1, 66263), -- Pillaged Items (Area: 16208 - Difficulty: 0) CreateObject1
(@OGUID+72, 549136, 2858, 16182, 16208, '0', '0', 0, 11373.3818359375, -4561.73779296875, 22.52859687805175781, 1.556576848030090332, -0.0316925048828125, -0.20784378051757812, 0.670763015747070312, 0.711247861385345458, 7200, 255, 1, 66263), -- Pillaged Items (Area: 16208 - Difficulty: 0) CreateObject1
(@OGUID+73, 549138, 2858, 16182, 16208, '0', '0', 0, 11377.044921875, -4557.1943359375, 22.72607612609863281, 5.515336036682128906, -0.00725793838500976, 0.033419609069824218, -0.37383842468261718, 0.926863133907318115, 7200, 255, 1, 66263), -- History of Sun's Reach (Area: 16208 - Difficulty: 0) CreateObject1
(@OGUID+74, 555181, 2858, 16182, 16208, '0', '0', 0, 11475.326171875, -4522.05908203125, 21.86649894714355468, 0, 0, 0, 0, 1, 7200, 255, 0, 66263), -- Etched Scroll (Area: 16208 - Difficulty: 0) CreateObject1
(@OGUID+75, 621669, 2858, 16182, 16208, '0', '0', 0, 11501.0908203125, -4498.0849609375, 76.04224395751953125, 3.824509143829345703, 0, 0, -0.94226741790771484, 0.334861367940902709, 7200, 255, 1, 66263), -- Artisan's Cache (Area: 16208 - Difficulty: 0) CreateObject1
(@OGUID+76, 549136, 2858, 16182, 16208, '0', '0', 0, 11530.939453125, -4514.7412109375, 4.947383403778076171, 2.045217275619506835, 0.004824161529541015, -0.02231502532958984, 0.853112220764160156, 0.521227657794952392, 7200, 255, 1, 66263), -- Pillaged Items (Area: 16208 - Difficulty: 0) CreateObject1
(@OGUID+77, 549135, 2858, 16182, 16209, '0', '0', 0, 11532.607421875, -4518.095703125, 4.943033695220947265, 4.364962577819824218, 0, 0, -0.81868171691894531, 0.574247539043426513, 7200, 255, 1, 66263), -- Research of Quel'Danas (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+78, 549138, 2858, 16182, 16209, '0', '0', 0, 11537.2470703125, -4514.33837890625, 4.943033695220947265, 0, 0, 0, 0, 1, 7200, 255, 1, 66263), -- History of Sun's Reach (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+79, 549136, 2858, 16182, 16209, '0', '0', 0, 11531.6298828125, -4518.77587890625, 4.943033695220947265, 0.376562625169754028, -0.14197206497192382, -0.15507221221923828, 0.161646842956542968, 0.964192330837249755, 7200, 255, 1, 66263), -- Pillaged Items (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+80, 549135, 2858, 16182, 16209, '0', '0', 0, 11531.6767578125, -4517.2724609375, 4.943033695220947265, 0.282056242227554321, 0, 0, 0.140561103820800781, 0.990072011947631835, 7200, 255, 1, 66263), -- Research of Quel'Danas (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+81, 549138, 2858, 16182, 16209, '0', '0', 0, 11538.603515625, -4519.63037109375, 4.943033695220947265, 1.193673372268676757, 0, 0, 0.562028884887695312, 0.827117621898651123, 7200, 255, 1, 66263), -- History of Sun's Reach (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+82, 549140, 2858, 16182, 16209, '0', '0', 0, 11519.763671875, -4576.0244140625, 5.846724987030029296, 0.651158690452575683, 0.892607688903808593, 0.31757354736328125, -0.28531742095947265, 0.144887953996658325, 7200, 255, 1, 66263), -- Spilled Chest (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+83, 518640, 2858, 16182, 16209, '0', '0', 0, 11520.1494140625, -4570.87158203125, 4.943033695220947265, 4.145742416381835937, 0.341364860534667968, -0.61791229248046875, -0.62175846099853515, 0.339220911264419555, 7200, 255, 1, 66263), -- Lightspire Spear (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+84, 518640, 2858, 16182, 16209, '0', '0', 0, 11426.255859375, -4603.59375, 5.021161556243896484, 4.145742416381835937, 0.341364860534667968, -0.61791229248046875, -0.62175846099853515, 0.339220911264419555, 7200, 255, 1, 66263), -- Lightspire Spear (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+85, 555181, 2858, 16182, 16209, '0', '0', 0, 11475.326171875, -4522.05908203125, 21.86649894714355468, 0, 0, 0, 0, 1, 7200, 255, 1, 66263), -- Etched Scroll (Area: 16209 - Difficulty: 0) CreateObject1
(@OGUID+86, 571699, 2858, 16182, 16538, '0', '0', 0, 11016.7001953125, -4616.830078125, 65.68630218505859375, 0, 0, 0, 0, 1, 7200, 255, 1, 66263), -- The Sunwell (Area: 16538 - Difficulty: 0) CreateObject1
(@OGUID+87, 519564, 2858, 16182, 16538, '0', '0', 0, 10845.2080078125, -4599.125, 35.8658447265625, 6.179849147796630859, 0, 0, -0.05164527893066406, 0.998665511608123779, 7200, 255, 1, 66263), -- Void Portal (Area: 16538 - Difficulty: 0) CreateObject1
(@OGUID+88, 523416, 2858, 16182, 16538, '0', '0', 0, 10596.451171875, -4617.60400390625, 48.61649322509765625, 3.27463078498840332, 0, 0, -0.9977884292602539, 0.066469945013523101, 7200, 255, 1, 66263), -- Void Portal (Area: 16538 - Difficulty: 0) CreateObject1
(@OGUID+89, 519564, 2858, 16182, 16538, '0', '0', 0, 10861.6298828125, -4621.7900390625, 37.31832504272460937, 4.938738346099853515, 0, 0, -0.6227273941040039, 0.782438874244689941, 7200, 255, 1, 66263); -- Void Portal (Area: 16538 - Difficulty: 0) CreateObject1


DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (41229,41348));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `VerifiedBuild`) VALUES
(41229, 0, 66709),
(41348, 0, 66709);


DELETE FROM `conversation_line_template` WHERE `Id` IN (81684, 81740, 81739, 79354, 80485, 78355, 92057, 80528, 79359, 79358, 78551, 78550, 81800, 78480, 81672, 82782, 78560, 80489, 82119, 82117, 82118, 78634, 78633, 78632, 78365, 78432, 78542, 78541, 80529, 79998, 85443, 85474);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(81684, 0, 0, 0, 0, 66709),
(81740, 0, 1, 0, 0, 66709),
(81739, 0, 0, 0, 0, 66709),
(79354, 0, 1, 0, 0, 66709),
(80485, 0, 0, 0, 0, 66709),
(78355, 0, 1, 0, 0, 66709),
(92057, 0, 0, 0, 0, 66709),
(80528, 0, 0, 0, 0, 66709),
(79359, 1849, 1, 0, 0, 66709),
(79358, 118, 0, 0, 0, 66709),
(78551, 0, 0, 0, 0, 66709),
(78550, 0, 0, 0, 0, 66709),
(81800, 0, 0, 0, 0, 66709),
(78480, 0, 0, 0, 0, 66709),
(81672, 0, 0, 0, 0, 66709),
(82782, 0, 0, 0, 0, 66709),
(78560, 1850, 0, 0, 0, 66709),
(80489, 0, 0, 0, 0, 66709),
(82119, 0, 0, 0, 0, 66709),
(82117, 0, 1, 0, 0, 66709),
(82118, 0, 0, 0, 0, 66709),
(78634, 0, 0, 0, 0, 66709),
(78633, 0, 0, 0, 0, 66709),
(78632, 0, 0, 0, 0, 66709),
(78365, 0, 0, 0, 0, 66709),
(78432, 0, 0, 0, 0, 66709),
(78542, 0, 0, 0, 0, 66709),
(78541, 0, 0, 0, 0, 66709),
(80529, 0, 0, 0, 0, 66709),
(79998, 0, 0, 0, 0, 66709),
(85443, 0, 0, 0, 0, 66709),
(85474, 0, 0, 0, 0, 66709);


DELETE FROM `quest_details` WHERE `ID` IN (86912 /*Down the Rootways*/, 90095 /*Echo of the Call*/, 90094 /*Echo of the Hunt*/, 86911 /*Echoes and Memories*/, 92448 /*Where Dust Dances*/, 86907 /*The Den of Echoes*/, 86929 /*The Council Assembles*/, 86901 /*The Rift and the Den*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(86912, 1, 0, 0, 0, 0, 0, 0, 0, 66709), -- Down the Rootways
(90095, 1, 0, 0, 0, 0, 0, 0, 0, 66709), -- Echo of the Call
(90094, 1, 0, 0, 0, 0, 0, 0, 0, 66709), -- Echo of the Hunt
(86911, 1, 0, 0, 0, 0, 0, 0, 0, 66709), -- Echoes and Memories
(92448, 0, 0, 0, 0, 0, 0, 0, 0, 66709), -- Where Dust Dances
(86907, 1, 0, 0, 0, 0, 0, 0, 0, 66709), -- The Den of Echoes
(86929, 1, 0, 0, 0, 0, 0, 0, 0, 66709), -- The Council Assembles
(86901, 1, 0, 0, 0, 0, 0, 0, 0, 66709); -- The Rift and the Den

DELETE FROM `creature_queststarter` WHERE (`id`=243884 AND `quest`=86912) OR (`id`=239795 AND `quest`=90095) OR (`id`=239650 AND `quest`=90094) OR (`id`=237567 AND `quest`=86911) OR (`id`=237332 AND `quest`=86907) OR (`id`=237345 AND `quest`=86929) OR (`id`=237483 AND `quest`=86901);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(243884, 86912, 66709), -- Down the Rootways offered by Zur'ashar Kassameh
(239795, 90095, 66709), -- Echo of the Call offered by Zur'ashar Kassameh
(239650, 90094, 66709), -- Echo of the Hunt offered by Zur'ashar Kassameh
(237567, 86911, 66709), -- Echoes and Memories offered by Hagar
(237332, 86907, 66709), -- The Den of Echoes offered by Hagar
(237345, 86929, 66709), -- The Council Assembles offered by Halduron Brightwing
(237483, 86901, 66709); -- The Rift and the Den offered by Orweyna


DELETE FROM `spawn_tracking_template` WHERE `SpawnTrackingId` IN (2767493 /*Map: 2694 - Phase: 26114*/, 2803616 /*Map: 2694 - Phase: 26467 (Cosmetic: See Zur'ashar Kassameh in Den of Echoes)*/, 2971891 /*Map: 2694 - Phase: 0*/, 3047210 /*Map: 2694 - Phase: 27847*/, 2767848 /*Map: 2694 - Phase: 26117*/, 2737380 /*Map: 2694 - Phase: 26450*/, 2767466 /*Map: 2694 - Phase: 26452 (Cosmetic: see third Memory spawns)*/, 2737381 /*Map: 2694 - Phase: 0*/, 2736083 /*Map: 2694 - Phase: 26213*/, 2736084 /*Map: 2694 - Phase: 0*/, 2716045 /*Map: 2694 - Phase: 26113*/, 2736016 /*Map: 2694 - Phase: 0*/, 2719161 /*Map: 2694 - Phase: 26110*/, 2810387 /*Map: 2694 - Phase: 26255 (Cosmetic: See first Memory spawns)*/, 2771051 /*Map: 2694 - Phase: 26255 (Cosmetic: See first Memory spawns)*/, 2771050 /*Map: 2694 - Phase: 26255 (Cosmetic: See first Memory spawns)*/, 2771049 /*Map: 2694 - Phase: 26255 (Cosmetic: See first Memory spawns)*/, 2771047 /*Map: 2694 - Phase: 26255 (Cosmetic: See first Memory spawns)*/, 2810376 /*Map: 2694 - Phase: 26255 (Cosmetic: See first Memory spawns)*/, 2988867 /*Map: 2694 - Phase: 0*/, 2774541 /*Map: 2694 - Phase: 0*/, 2826350 /*Map: 2694 - Phase: 0*/, 2774410 /*Map: 2694 - Phase: 0*/, 2719381 /*Map: 2694 - Phase: 0*/, 2714129 /*Map: 2694 - Phase: 26183*/, 2714215 /*Map: 2694 - Phase: 26183*/, 2715716 /*Map: 2694 - Phase: 26207*/, 2714205 /*Map: 2694 - Phase: 26037 (Cosmetic - See Orweyna near the Cave at Amirdrassil Roots)*/, 2714207 /*Map: 2694 - Phase: 26041 (Cosmetic: See Orweyna & Halduron Brightwing at Overlook)*/, 2713342 /*Map: 2694 - Phase: 26041 (Cosmetic: See Orweyna & Halduron Brightwing at Overlook)*/, 2719398 /*Map: 2694 - Phase: 27835 (Cosmetic: See Danul in Amirdrassil Roots)*/, 2719397 /*Map: 2694 - Phase: 26533 (Cosmetic: See Oorla in Amirdrassil Roots)*/, 2713344 /*Map: 2694 - Phase: 26040*/, 2734920 /*Map: 2694 - Phase: 0*/, 2734990 /*Map: 2694 - Phase: 26207*/, 2768731 /*Map: 0 - Phase: 26249 (Cosmetic - See Mysterious Rootway at Fairbreeze Village)*/);
INSERT INTO `spawn_tracking_template` (`SpawnTrackingId`, `MapId`, `PhaseId`, `PhaseGroup`, `PhaseUseFlags`, `VerifiedBuild`) VALUES
(2767493, 2694, 26114, 0, 0, 66709), -- Map: 2694 - Phase: 26114
(2803616, 2694, 26467, 0, 0, 66709), -- Map: 2694 - Phase: 26467 (Cosmetic: See Zur'ashar Kassameh in Den of Echoes)
(2971891, 2694, 0, 0, 0, 66709), -- Map: 2694 - Phase: 0
(3047210, 2694, 27847, 0, 0, 66709), -- Map: 2694 - Phase: 27847
(2767848, 2694, 26117, 0, 0, 66709), -- Map: 2694 - Phase: 26117
(2737380, 2694, 26450, 0, 0, 66709), -- Map: 2694 - Phase: 26450
(2767466, 2694, 26452, 0, 0, 66709), -- Map: 2694 - Phase: 26452 (Cosmetic: see third Memory spawns)
(2737381, 2694, 0, 0, 1, 66709), -- Map: 2694 - Phase: 0
(2736083, 2694, 26213, 0, 0, 66709), -- Map: 2694 - Phase: 26213
(2736084, 2694, 0, 0, 1, 66709), -- Map: 2694 - Phase: 0
(2716045, 2694, 26113, 0, 0, 66709), -- Map: 2694 - Phase: 26113
(2736016, 2694, 0, 0, 1, 66709), -- Map: 2694 - Phase: 0
(2719161, 2694, 26110, 0, 0, 66709), -- Map: 2694 - Phase: 26110
(2810387, 2694, 26255, 0, 0, 66709), -- Map: 2694 - Phase: 26255 (Cosmetic: See first Memory spawns)
(2771051, 2694, 26255, 0, 0, 66709), -- Map: 2694 - Phase: 26255 (Cosmetic: See first Memory spawns)
(2771050, 2694, 26255, 0, 0, 66709), -- Map: 2694 - Phase: 26255 (Cosmetic: See first Memory spawns)
(2771049, 2694, 26255, 0, 0, 66709), -- Map: 2694 - Phase: 26255 (Cosmetic: See first Memory spawns)
(2771047, 2694, 26255, 0, 0, 66709), -- Map: 2694 - Phase: 26255 (Cosmetic: See first Memory spawns)
(2810376, 2694, 26255, 0, 0, 66709), -- Map: 2694 - Phase: 26255 (Cosmetic: See first Memory spawns)
(2988867, 2694, 0, 0, 0, 66709), -- Map: 2694 - Phase: 0
(2774541, 2694, 0, 0, 0, 66709), -- Map: 2694 - Phase: 0
(2826350, 2694, 0, 0, 0, 66709), -- Map: 2694 - Phase: 0
(2774410, 2694, 0, 0, 0, 66709), -- Map: 2694 - Phase: 0
(2719381, 2694, 0, 0, 0, 66709), -- Map: 2694 - Phase: 0
(2714129, 2694, 26183, 0, 0, 66709), -- Map: 2694 - Phase: 26183
(2714215, 2694, 26183, 0, 0, 66709), -- Map: 2694 - Phase: 26183
(2715716, 2694, 26207, 0, 0, 66709), -- Map: 2694 - Phase: 26207
(2714205, 2694, 26037, 0, 0, 66709), -- Map: 2694 - Phase: 26037 (Cosmetic - See Orweyna near the Cave at Amirdrassil Roots)
(2714207, 2694, 26041, 0, 0, 66709), -- Map: 2694 - Phase: 26041 (Cosmetic: See Orweyna & Halduron Brightwing at Overlook)
(2713342, 2694, 26041, 0, 0, 66709), -- Map: 2694 - Phase: 26041 (Cosmetic: See Orweyna & Halduron Brightwing at Overlook)
(2719398, 2694, 27835, 0, 0, 66709), -- Map: 2694 - Phase: 27835 (Cosmetic: See Danul in Amirdrassil Roots)
(2719397, 2694, 26533, 0, 0, 66709), -- Map: 2694 - Phase: 26533 (Cosmetic: See Oorla in Amirdrassil Roots)
(2713344, 2694, 26040, 0, 0, 66709), -- Map: 2694 - Phase: 26040
(2734920, 2694, 0, 0, 0, 66709), -- Map: 2694 - Phase: 0
(2734990, 2694, 26207, 0, 0, 66709), -- Map: 2694 - Phase: 26207
(2768731, 0, 26249, 0, 0, 66709); -- Map: 0 - Phase: 26249 (Cosmetic - See Mysterious Rootway at Fairbreeze Village)

UPDATE `spawn_tracking_template` SET `MapId`=0, `VerifiedBuild`=66709 WHERE `SpawnTrackingId` IN (1483914, 1578973, 1483872, 1387286, 1402353, 1387171); -- Map: 0 - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=66709 WHERE `SpawnTrackingId` IN (1386863, 1402352, 1386861, 1448534, 1174114);

DELETE FROM `spawn_tracking_quest_objective` WHERE (`SpawnTrackingId`=3047210 AND `QuestObjectiveId`=461711) OR (`SpawnTrackingId`=2971891 AND `QuestObjectiveId`=464613) OR (`SpawnTrackingId`=2767466 AND `QuestObjectiveId`=460702) OR (`SpawnTrackingId`=2737381 AND `QuestObjectiveId`=460701) OR (`SpawnTrackingId`=2736084 AND `QuestObjectiveId`=460698) OR (`SpawnTrackingId`=2736016 AND `QuestObjectiveId`=458873) OR (`SpawnTrackingId`=2719161 AND `QuestObjectiveId`=457676) OR (`SpawnTrackingId`=2714215 AND `QuestObjectiveId`=457585) OR (`SpawnTrackingId`=2714207 AND `QuestObjectiveId`=457519) OR (`SpawnTrackingId`=2713342 AND `QuestObjectiveId`=460249) OR (`SpawnTrackingId`=2719398 AND `QuestObjectiveId`=457680) OR (`SpawnTrackingId`=2719397 AND `QuestObjectiveId`=457679) OR (`SpawnTrackingId`=2713344 AND `QuestObjectiveId`=458762) OR (`SpawnTrackingId`=2734920 AND `QuestObjectiveId`=458763) OR (`SpawnTrackingId`=2768731 AND `QuestObjectiveId`=461588) OR (`SpawnTrackingId`=2768734 AND `QuestObjectiveId`=464543) OR (`SpawnTrackingId`=2941027 AND `QuestObjectiveId`=464332);
INSERT INTO `spawn_tracking_quest_objective` (`SpawnTrackingId`, `QuestObjectiveId`, `VerifiedBuild`) VALUES
(3047210, 461711, 66709), -- 3047210
(2971891, 464613, 66709), -- 2971891
(2767466, 460702, 66709), -- 2767466
(2737381, 460701, 66709), -- 2737381
(2736084, 460698, 66709), -- 2736084
(2736016, 458873, 66709), -- 2736016
(2719161, 457676, 66709), -- 2719161
(2714215, 457585, 66709), -- 2714215
(2714207, 457519, 66709), -- 2714207
(2713342, 460249, 66709), -- 2713342
(2719398, 457680, 66709), -- 2719398
(2719397, 457679, 66709), -- 2719397
(2713344, 458762, 66709), -- 2713344
(2734920, 458763, 66709), -- 2734920
(2768731, 461588, 66709), -- 2768731
(2768734, 464543, 66709), -- 2768734
(2941027, 464332, 66709); -- 2941027



UPDATE `creature_model_info` SET `VerifiedBuild`=66709 WHERE `DisplayID` IN (110393, 137186, 127678, 130140, 137964, 125218, 125937, 127672, 127673, 116611, 110392, 127129, 5233, 127130, 75780, 125122, 129351, 137965, 126121, 89097, 106533, 57899, 129336, 105563, 120519, 120517, 126117, 126119, 131773, 109505, 117524, 117525, 105562, 128618, 131772, 114620, 139511, 114779, 105564, 125974, 136118, 139512, 131774, 104638, 45852, 45853, 113542, 43798, 113541, 127403, 113540, 128614, 128031, 108827, 113982, 125191, 108830, 128533, 104637, 104475, 59802, 108826, 108829, 108828, 140331, 139910, 128536, 139459, 131469, 126028, 114618, 115253, 126017, 131466, 120075, 126013, 115257, 131467, 126016, 139458, 126040, 115255, 112414, 112411, 110398, 136942, 36953, 59890, 140880, 139569, 137503, 140807, 140803, 128541, 130136, 131325, 140875, 140811, 130135, 125222, 140802, 138281, 129022, 129018, 129020, 129021, 137553, 129017, 127123, 131468, 137556, 140808, 130144, 138609, 139533, 140738, 130138, 140801, 137514, 137826, 138490, 140815, 138651, 139666, 140523, 128668, 138551, 138485, 130148, 140800, 137519, 137831, 140810, 130141, 130145, 140520, 137949, 139669, 139805, 139667, 140519, 140522, 139560, 130143, 137175, 137840, 128667, 125192, 129256, 129257, 129251, 137520, 129252, 128608, 128666, 137837, 116615, 45854, 128607, 120518, 140737, 140742, 128613, 140714, 139584, 131952, 139583, 131472, 138282, 116616, 131593, 138280, 112412, 128023, 110395, 139586, 131594, 139587, 126039, 110394, 129023, 126036, 129380, 92725, 131954, 125190, 121166, 137841, 139010, 137300, 138311, 137836, 139015, 131335, 128538, 110397, 127414, 137207, 140897, 130472, 131393, 137650, 137832, 137301, 137816, 130146, 130147, 130139, 129737, 137838, 139017, 128673, 137304, 110399, 137222, 128044, 137839, 137834, 137552, 130137, 36955, 104636, 137206, 128063, 137221, 137814, 137649, 126646, 137833, 139661, 36956, 108832, 139662, 36944, 104635, 128024, 128173, 130410, 138352, 130231, 108833, 130230, 128035, 36952, 126645, 128025, 131592, 108831, 128022, 126649, 126648, 138353, 138351, 128026, 122803, 122801, 117450, 126647, 122802, 131796, 106602, 126897, 128099, 99827, 126892, 126522, 117116, 128650, 99826, 99829, 89803, 99833, 89802, 126891, 126896, 128680, 99830, 128681, 99832, 89801, 129210, 129211, 128634, 86546, 16065, 128631, 100358, 126893, 128622, 129209, 129208, 128679, 115399, 131994, 128633, 128652, 126895, 129979, 138231, 129338, 138230, 137599, 132019, 139935, 136540, 38804, 25983, 138853, 136524, 138848);
UPDATE `creature_model_info` SET `BoundingRadius`=0.484952837228775024, `CombatReach`=1.5, `VerifiedBuild`=66709 WHERE `DisplayID`=137192;
UPDATE `creature_model_info` SET `BoundingRadius`=0.580512702465057373, `CombatReach`=1.5, `VerifiedBuild`=66709 WHERE `DisplayID` IN (137191, 137966);
UPDATE `creature_model_info` SET `BoundingRadius`=0.175423324108123779, `VerifiedBuild`=66709 WHERE `DisplayID`=130142;
UPDATE `creature_model_info` SET `BoundingRadius`=1.079608917236328125, `CombatReach`=1, `VerifiedBuild`=66709 WHERE `DisplayID`=107830;
UPDATE `creature_model_info` SET `BoundingRadius`=0.176249995827674865, `CombatReach`=0.75, `VerifiedBuild`=66709 WHERE `DisplayID`=85253;
UPDATE `creature_model_info` SET `BoundingRadius`=0.994205653667449951, `CombatReach`=0.800000011920928955, `VerifiedBuild`=66709 WHERE `DisplayID` IN (117451, 117448, 117449);
UPDATE `creature_model_info` SET `BoundingRadius`=10.39081764221191406, `CombatReach`=15.59999942779541015, `VerifiedBuild`=66709 WHERE `DisplayID`=136062;
UPDATE `creature_model_info` SET `BoundingRadius`=0.727682173252105712, `VerifiedBuild`=66709 WHERE `DisplayID`=114619;
UPDATE `creature_model_info` SET `BoundingRadius`=1.637537240982055664, `VerifiedBuild`=66709 WHERE `DisplayID`=110396;
UPDATE `creature_model_info` SET `BoundingRadius`=1.201061129570007324 WHERE `DisplayID`=125877;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=66709 WHERE `DisplayID`=85945;
UPDATE `creature_model_info` SET `BoundingRadius`=0.57750016450881958, `CombatReach`=0.533333361148834228 WHERE `DisplayID`=127895;

REPLACE INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(237837, 37955, 66709), -- Zur'ashar Kassameh
(237567, 39246, 66709), -- Hagar
(255056, 39229, 66709), -- Doecha
(237345, 39240, 66709), -- Halduron Brightwing
(239525, 42288, 66709), -- Ruia
(237343, 38640, 66709), -- Halduron Brightwing
(237210, 37879, 66709), -- Orweyna
(237866, 39190, 66709), -- Oorla
(237865, 39194, 66709), -- Danul
(237209, 38392, 66709); -- Ku'paal

REPLACE INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(39229, 7778, 66709); -- 255056 (Doecha)

REPLACE INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(39246, 133797, 0, 0, 'Who are you?', 25092, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66709), -- OptionBroadcastTextID: 25092 - 38470 - 47091 - 47632 - 62792 - 65124 - 79414 - 97339 - 153888 - 161428 - 166571 - 176081 - 185133 - 224837 - 263541 - 298152
(39246, 133801, 2, 0, '<Stay awhile and listen.>', 137786, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66709), -- OptionBroadcastTextID: 137786 - 144263 - 160761 - 160763 - 160765 - 160768 - 167552 - 173473 - 176737 - 188459 - 202026 - 205118 - 205774
(42288, 138420, 0, 0, 'Who are you?', 25092, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66709), -- OptionBroadcastTextID: 25092 - 38470 - 47091 - 47632 - 62792 - 65124 - 79414 - 97339 - 153888 - 161428 - 166571 - 176081 - 185133 - 224837 - 263541 - 298152
(39194, 133726, 0, 0, 'Ku\'paal and Orweyna sent me. It\'s safe to return to the village.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66709),
(39240, 133792, 0, 0, 'Let\'s go.', 15894, 0, 4, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66709), -- OptionBroadcastTextID: 15894 - 57655 - 60204 - 62002 - 75830 - 77209 - 78160 - 78305 - 108064 - 125346 - 128698 - 129792 - 129809 - 146440 - 148058 - 148106 - 160082 - 177822 - 178830
(38640, 133774, 0, 0, 'Let\'s head down.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66709),
(37955, 133805, 1, 0, 'Who are you?', 25092, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66709), -- OptionBroadcastTextID: 25092 - 38470 - 47091 - 47632 - 62792 - 65124 - 79414 - 97339 - 153888 - 161428 - 166571 - 176081 - 185133 - 224837 - 263541 - 298152
(38392, 132536, 1, 0, 'Who are you?', 25092, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66709), -- OptionBroadcastTextID: 25092 - 38470 - 47091 - 47632 - 62792 - 65124 - 79414 - 97339 - 153888 - 161428 - 166571 - 176081 - 185133 - 224837 - 263541 - 298152
(39229, 133778, 0, 2, 'Show me where I can fly.', 12271, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66709), -- OptionBroadcastTextID: 12271 - 140511 - 158191
(37879, 131842, 0, 0, '<Take in the view.>', 0, 0, 4, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66709),
(39246, 133796, 1, 0, 'You seem more open to collaborating with us than the rest of your people.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66709),
(37955, 131932, 0, 0, 'I am ready to begin the trials.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66709),
(39190, 133721, 0, 0, 'Ku\'paal and Orweyna sent me. It\'s safe to return to the village.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66709),
(37955, 133806, 2, 0, 'What is the Den of Echoes?', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66709),
(38392, 132537, 0, 0, 'We are friends of Orweyna and we are here to help.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66709);

REPLACE INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(237866, 1, 0, 0, 0, 0, 0, 0, 0, 283179, 0, 0, 0, 0, 0, 0, 0, 66220), -- 237211 (Faerin Lothar)
(237865, 1, 0, 0, 0, 0, 0, 0, 0, 283169, 0, 0, 0, 0, 0, 0, 0, 66220), -- 236657 (Lothraxion)
(237343, 1, 0, 0, 0, 0, 0, 0, 0, 283177, 0, 0, 0, 0, 0, 0, 0, 66220), -- 236789 (Alonsus Faol)
(237345, 1, 0, 0, 0, 0, 0, 0, 0, 288649, 0, 0, 0, 0, 0, 0, 0, 66220), -- 241677 (Image of Lady Liadrin)
(237209, 1, 0, 0, 0, 0, 0, 0, 0, 286065, 0, 0, 0, 0, 0, 0, 0, 66220), -- 236906 (High Exarch Turalyon)
(237567, 1, 0, 0, 0, 0, 0, 0, 0, 288213, 0, 0, 0, 0, 0, 0, 0, 66220), -- 236896 (Lor'themar Theron)
(237210, 1, 0, 0, 0, 0, 0, 0, 0, 288302, 0, 0, 0, 0, 0, 0, 0, 66220), -- 236692 (Lady Liadrin)
(237837, 1, 0, 0, 0, 0, 0, 0, 0, 282318, 0, 0, 0, 0, 0, 0, 0, 66220), -- 238756 (Parhelion Lightguard)
(239525, 1, 0, 0, 0, 0, 0, 0, 0, 282408, 0, 0, 0, 0, 0, 0, 0, 66220); -- 236959 (Arator)

REPLACE INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(38371, 237866, 66220), -- 237211 (Faerin Lothar)
(38372, 237865, 66220), -- 236657 (Lothraxion)
(38373, 237343, 66220), -- 236789 (Alonsus Faol)
(39008, 237345, 66220), -- 241677 (Image of Lady Liadrin)
(38654, 237209, 66220), -- 236906 (High Exarch Turalyon)
(38926, 237567, 66220), -- 236896 (Lor'themar Theron)
(38951, 237210, 66220), -- 236692 (Lady Liadrin)
(38248, 237837, 66220), -- 238756 (Parhelion Lightguard)
(38261, 239525, 66220); -- 236959 (Arator)


REPLACE INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(237866, 1, 0, 0, 0, 0, 0, 0, 0, 297049, 0, 0, 0, 0, 0, 0, 0, 65940), -- 233708 (Tocho Cloudhide)
(237865, 1, 0, 0, 0, 0, 0, 0, 0, 302697, 0, 0, 0, 0, 0, 0, 0, 65940), -- 253596 (The Last Architect)
(237343, 1, 0, 0, 0, 0, 0, 0, 0, 303804, 0, 0, 0, 0, 0, 0, 0, 65940); -- 254687 (Rotha)

REPLACE INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(40500, 237866, 65940), -- 233708 (Tocho Cloudhide)
(41100, 237865, 65940), -- 253596 (The Last Architect)
(41365, 237343, 65940); -- 254687 (Rotha)


REPLACE INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(237866, 1, 0, 0, 0, 0, 0, 0, 0, 288213, 0, 0, 0, 0, 0, 0, 0, 66220), -- 236896 (Lor'themar Theron)
(237865, 1, 0, 0, 0, 0, 0, 0, 0, 284092, 0, 0, 0, 0, 0, 0, 0, 66220), -- 240156 (Scared Civilian)
(237343, 1, 0, 0, 0, 0, 0, 0, 0, 285706, 0, 0, 0, 0, 0, 0, 0, 66220), -- 236978 (High Exarch Turalyon)
(237345, 1, 0, 0, 0, 0, 0, 0, 0, 283857, 0, 0, 0, 0, 0, 0, 0, 66220), -- 236964 (Arator)
(237209, 1, 0, 0, 0, 0, 0, 0, 0, 283974, 0, 0, 0, 0, 0, 0, 0, 66220), -- 240068 (Scared Civilian)
(237567, 1, 0, 0, 0, 0, 0, 0, 0, 284034, 0, 0, 0, 0, 0, 0, 0, 66220), -- 240075 (Scared Civilian)
(237210, 1, 0, 0, 0, 0, 0, 0, 0, 285498, 0, 0, 0, 0, 0, 0, 0, 66220), -- 236961 (Lor'themar Theron)
(237837, 1, 0, 0, 0, 0, 0, 0, 0, 282318, 0, 0, 0, 0, 0, 0, 0, 66220), -- 238756 (Parhelion Lightguard)
(239525, 1, 0, 0, 0, 0, 0, 0, 0, 284092, 0, 0, 0, 0, 0, 0, 0, 66220); -- 240125 (Scared Civilian)

REPLACE INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(38926, 237866, 66220), -- 236896 (Lor'themar Theron)
(38483, 237865, 66220), -- 240156 (Scared Civilian)
(38597, 237343, 66220), -- 236978 (High Exarch Turalyon)
(39126, 237345, 66220), -- 236964 (Arator)
(38466, 237209, 66220), -- 240068 (Scared Civilian)
(38467, 237567, 66220), -- 240075 (Scared Civilian)
(38579, 237210, 66220), -- 236961 (Lor'themar Theron)
(38248, 237837, 66220), -- 238756 (Parhelion Lightguard)
(38472, 239525, 66220); -- 240125 (Scared Civilian)

REPLACE INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(237866, 1, 0, 0, 0, 0, 0, 0, 0, 270982, 0, 0, 0, 0, 0, 0, 0, 64704), -- 227702 (Customs Agent)
(237865, 1, 0, 0, 0, 0, 0, 0, 0, 270985, 0, 0, 0, 0, 0, 0, 0, 64704), -- 227621 (Customs Agent)
(237343, 1, 0, 0, 0, 0, 0, 0, 0, 270987, 0, 0, 0, 0, 0, 0, 0, 64704), -- 230113 (Customs Agent)
(237345, 1, 0, 0, 0, 0, 0, 0, 0, 278477, 0, 0, 0, 0, 0, 0, 0, 64704), -- 234174 (Anti-Ethereal Unit)
(237209, 1, 0, 0, 0, 0, 0, 0, 0, 270989, 0, 0, 0, 0, 0, 0, 0, 64704), -- 230112 (Customs Agent)
(237567, 1, 0, 0, 0, 0, 0, 0, 0, 282229, 0, 0, 0, 0, 0, 0, 0, 64704), -- 225645 (Monte Gazlowe)
(237210, 1, 0, 0, 0, 0, 0, 0, 0, 278165, 0, 0, 0, 0, 0, 0, 0, 64704), -- 230461 (Monte Gazlowe)
(237837, 1, 0, 0, 0, 0, 0, 0, 0, 277436, 0, 0, 0, 0, 0, 0, 0, 64704), -- 233719 (Coastside Drill Control Panel)
(239525, 1, 0, 0, 0, 0, 0, 0, 0, 277780, 0, 0, 0, 0, 0, 0, 0, 64704), -- 234016 (Delby Overbite)
(258560, 1, 0, 0, 0, 0, 0, 0, 0, 277507, 0, 0, 0, 0, 0, 0, 0, 64704), -- 231409 (Smaks Topskimmer)
(230460, 1, 0, 0, 0, 0, 0, 0, 0, 271257, 0, 0, 0, 0, 0, 0, 0, 64704), -- 230460 (Renzik "The Shiv")
(225574, 1, 0, 0, 0, 0, 0, 0, 0, 280045, 0, 0, 0, 0, 0, 0, 0, 64704), -- 225574 (Grimla Fizzlecrank)
(225618, 1, 0, 0, 0, 0, 0, 0, 0, 277863, 0, 0, 0, 0, 0, 0, 0, 64704), -- 225618 (Pamsy)
(229243, 1, 0, 0, 0, 0, 0, 0, 0, 281725, 0, 0, 0, 0, 0, 0, 0, 64704), -- 229243 (Renzik "The Shiv")
(225627, 1, 0, 0, 0, 0, 0, 0, 0, 280065, 0, 0, 0, 0, 0, 0, 0, 64704), -- 225627 (Grimla Fizzlecrank)
(225624, 1, 0, 0, 0, 0, 0, 0, 0, 269102, 0, 0, 0, 0, 0, 0, 0, 64704), -- 225624 (Marin Noggenfogger)
(225626, 1, 0, 0, 0, 0, 0, 0, 0, 280066, 0, 0, 0, 0, 0, 0, 0, 64704), -- 225626 (Alleria Windrunner)
(234225, 1, 0, 0, 0, 0, 0, 0, 0, 277804, 0, 0, 0, 0, 0, 0, 0, 64704), -- 234225 (Potential Darkfuse Recruit)
(225811, 1, 0, 0, 0, 0, 0, 0, 0, 268680, 0, 0, 0, 0, 0, 0, 0, 64704), -- 225811 (Underpaid Worker)
(225816, 1, 0, 0, 0, 0, 0, 0, 0, 268680, 0, 0, 0, 0, 0, 0, 0, 64704), -- 225816 (Underpaid Worker)
(227813, 1, 0, 0, 0, 0, 0, 0, 0, 268680, 0, 0, 0, 0, 0, 0, 0, 64704), -- 227813 (Underpaid Worker)
(225686, 1, 0, 0, 0, 0, 0, 0, 0, 269254, 0, 0, 0, 0, 0, 0, 0, 64704), -- 225686 (Baron Revilgaz)
(233625, 1, 0, 0, 0, 0, 0, 0, 0, 277245, 0, 0, 0, 0, 0, 0, 0, 64704), -- 233625 (Bigz Speedtrack)
(212407, 1, 0, 0, 0, 0, 0, 0, 0, 276301, 0, 0, 0, 0, 0, 0, 0, 64704), -- 212407 (Enter Delve)
(227736, 1, 0, 0, 0, 0, 0, 0, 0, 280179, 0, 0, 0, 0, 0, 0, 0, 64704); -- 227736 (Renzik "The Shiv")

REPLACE INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(36336, 237866, 64704), -- 227702 (Customs Agent)
(36337, 237865, 64704), -- 227621 (Customs Agent)
(36338, 237343, 64704), -- 230113 (Customs Agent)
(37448, 237345, 64704), -- 234174 (Anti-Ethereal Unit)
(36339, 237209, 64704), -- 230112 (Customs Agent)
(38227, 237567, 64704), -- 225645 (Monte Gazlowe)
(37376, 237210, 64704), -- 230461 (Monte Gazlowe)
(37229, 237837, 64704), -- 233719 (Coastside Drill Control Panel)
(37308, 239525, 64704), -- 234016 (Delby Overbite)
(37236, 258560, 64704), -- 231409 (Smaks Topskimmer)
(36426, 230460, 64704), -- 230460 (Renzik "The Shiv")
(37759, 225574, 64704), -- 225574 (Grimla Fizzlecrank)
(36242, 225618, 64704), -- 225618 (Pamsy)
(36243, 229243, 64704), -- 229243 (Renzik "The Shiv")
(37762, 225627, 64704), -- 225627 (Grimla Fizzlecrank)
(35875, 225624, 64704), -- 225624 (Marin Noggenfogger)
(37763, 225626, 64704), -- 225626 (Alleria Windrunner)
(37356, 234225, 64704), -- 234225 (Potential Darkfuse Recruit)
(35730, 225811, 64704), -- 225811 (Underpaid Worker)
(35731, 225816, 64704), -- 225816 (Underpaid Worker)
(35732, 227813, 64704), -- 227813 (Underpaid Worker)
(35917, 225686, 64704), -- 225686 (Baron Revilgaz)
(37214, 233625, 64704), -- 233625 (Bigz Speedtrack)
(37069, 212407, 64704), -- 212407 (Enter Delve)
(37775, 227736, 64704); -- 227736 (Renzik "The Shiv")

REPLACE INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(237866, 1, 0, 0, 0, 0, 0, 0, 0, 286681, 0, 0, 0, 0, 0, 0, 0, 66709), -- 241654 (High Exarch Turalyon)
(237865, 1, 0, 0, 0, 0, 0, 0, 0, 307243, 0, 0, 0, 0, 0, 0, 0, 66709), -- 258561 (Eversong Arch Magister)
(237343, 1, 0, 0, 0, 0, 0, 0, 0, 307244, 0, 0, 0, 0, 0, 0, 0, 66709), -- 258562 (Blessed Lightbringer)
(237345, 1, 0, 0, 0, 0, 0, 0, 0, 307246, 0, 0, 0, 0, 0, 0, 0, 66709), -- 258563 (Veteran Blood Knight)
(237209, 1, 0, 0, 0, 0, 0, 0, 0, 307248, 0, 0, 0, 0, 0, 0, 0, 66709), -- 258564 (Blessed Lightbringer)
(237567, 1, 0, 0, 0, 0, 0, 0, 0, 307250, 0, 0, 0, 0, 0, 0, 0, 66709), -- 258565 (Eversong Magister)
(237210, 1, 0, 0, 0, 0, 0, 0, 0, 307252, 0, 0, 0, 0, 0, 0, 0, 66709), -- 258566 (Veteran Blood Knight)
(237837, 1, 0, 0, 0, 0, 0, 0, 0, 291711, 0, 0, 0, 0, 0, 0, 0, 66709), -- 235787 (Lor'themar Theron)
(239525, 1, 0, 0, 0, 0, 0, 0, 0, 307238, 0, 0, 0, 0, 0, 0, 0, 66709), -- 258559 (Eversong Farstrider)
(258560, 1, 0, 0, 0, 0, 0, 0, 0, 307240, 0, 0, 0, 0, 0, 0, 0, 66709); -- 258560 (Eversong Spellbreaker)

REPLACE INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(38702, 237866, 66709), -- 241654 (High Exarch Turalyon)
(41995, 237865, 66709), -- 258561 (Eversong Arch Magister)
(41996, 237343, 66709), -- 258562 (Blessed Lightbringer)
(41997, 237345, 66709), -- 258563 (Veteran Blood Knight)
(41998, 237209, 66709), -- 258564 (Blessed Lightbringer)
(41999, 237567, 66709), -- 258565 (Eversong Magister)
(42000, 237210, 66709), -- 258566 (Veteran Blood Knight)
(38452, 237837, 66709), -- 235787 (Lor'themar Theron)
(41992, 239525, 66709), -- 258559 (Eversong Farstrider)
(41994, 258560, 66709); -- 258560 (Eversong Spellbreaker)

REPLACE INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(237866, 1, 0, 0, 0, 0, 0, 0, 0, 301389, 0, 0, 0, 0, 0, 0, 0, 66263), -- 252822 (Lady Liadrin)
(237865, 1, 0, 0, 0, 0, 0, 0, 0, 288394, 0, 0, 0, 0, 0, 0, 0, 66263), -- 242949 (Sylmara Dawnpetal)
(237343, 1, 0, 0, 0, 0, 0, 0, 0, 288396, 0, 0, 0, 0, 0, 0, 0, 66263), -- 242913 (Vael'thas Dawnsoar)
(237345, 1, 0, 0, 0, 0, 0, 0, 0, 283851, 0, 0, 0, 0, 0, 0, 0, 66263), -- 236583 (Grand Magister Rommath)
(237209, 1, 0, 0, 0, 0, 0, 0, 0, 284658, 0, 0, 0, 0, 0, 0, 0, 66263), -- 236743 (Orweyna)
(237567, 1, 0, 0, 0, 0, 0, 0, 0, 283845, 0, 0, 0, 0, 0, 0, 0, 66263), -- 235787 (Lor'themar Theron)
(237210, 1, 0, 0, 0, 0, 0, 0, 0, 286666, 0, 0, 0, 0, 0, 0, 0, 66263); -- 236739 (Magistrix Landra Dawnstrider)

REPLACE INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(40774, 237866, 66263), -- 252822 (Lady Liadrin)
(38963, 237865, 66263), -- 242949 (Sylmara Dawnpetal)
(38964, 237343, 66263), -- 242913 (Vael'thas Dawnsoar)
(38521, 237345, 66263), -- 236583 (Grand Magister Rommath)
(38525, 237209, 66263), -- 236743 (Orweyna)
(38452, 237567, 66263), -- 235787 (Lor'themar Theron)
(38700, 237210, 66263); -- 236739 (Magistrix Landra Dawnstrider)

REPLACE INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(237866, 1, 0, 0, 0, 0, 0, 0, 0, 287826, 0, 0, 0, 0, 0, 0, 0, 66263), -- 242381 (Valeera Sanguinar)
(237865, 1, 0, 0, 0, 0, 0, 0, 0, 283845, 0, 0, 0, 0, 0, 0, 0, 66263), -- 235787 (Lor'themar Theron)
(237343, 1, 0, 0, 0, 0, 0, 0, 0, 285778, 0, 0, 0, 0, 0, 0, 0, 66263), -- 240936 (Guard Captain Goldblade)
(237345, 1, 0, 0, 0, 0, 0, 0, 0, 288281, 0, 0, 0, 0, 0, 0, 0, 66263), -- 237255 (High Exarch Turalyon)
(237209, 1, 0, 0, 0, 0, 0, 0, 0, 286595, 0, 0, 0, 0, 0, 0, 0, 66263), -- 237278 (Lady Liadrin)
(237567, 1, 0, 0, 0, 0, 0, 0, 0, 294564, 0, 0, 0, 0, 0, 0, 0, 66263); -- 248629 (General Amias Bellamy)

REPLACE INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(38820, 237866, 66263), -- 242381 (Valeera Sanguinar)
(38452, 237865, 66263), -- 235787 (Lor'themar Theron)
(38604, 237343, 66263), -- 240936 (Guard Captain Goldblade)
(38943, 237345, 66263), -- 237255 (High Exarch Turalyon)
(38691, 237209, 66263), -- 237278 (Lady Liadrin)
(40066, 237567, 66263); -- 248629 (General Amias Bellamy)

REPLACE INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(237866, 1, 1, 0, 0, 0, 0, 0, 0, 304930, 304933, 0, 0, 0, 0, 0, 0, 66709), -- 242398 (Naleidea Rivergleam)
(237865, 1, 0, 0, 0, 0, 0, 0, 0, 287826, 0, 0, 0, 0, 0, 0, 0, 66709), -- 242381 (Valeera Sanguinar)
(237343, 1, 0, 0, 0, 0, 0, 0, 0, 304489, 0, 0, 0, 0, 0, 0, 0, 66709); -- 243229 (Eldara Dawnrunner)

REPLACE INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(41594, 237866, 66709), -- 242398 (Naleidea Rivergleam)
(38820, 237865, 66709), -- 242381 (Valeera Sanguinar)
(41495, 237343, 66709); -- 243229 (Eldara Dawnrunner)

REPLACE INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(237866, 1, 0, 0, 0, 0, 0, 0, 0, 289743, 0, 0, 0, 0, 0, 0, 0, 66709), -- 237866 (Oorla)
(237865, 1, 0, 0, 0, 0, 0, 0, 0, 289759, 0, 0, 0, 0, 0, 0, 0, 66709), -- 237865 (Danul)
(237343, 1, 0, 0, 0, 0, 0, 0, 0, 285936, 0, 0, 0, 0, 0, 0, 0, 66709), -- 237343 (Halduron Brightwing)
(237345, 1, 0, 0, 0, 0, 0, 0, 0, 289980, 0, 0, 0, 0, 0, 0, 0, 66709), -- 237345 (Halduron Brightwing)
(237209, 1, 0, 0, 0, 0, 0, 0, 0, 290548, 0, 0, 0, 0, 0, 0, 0, 66709), -- 237209 (Ku'paal)
(237567, 1, 0, 0, 0, 0, 0, 0, 0, 289988, 0, 0, 0, 0, 0, 0, 0, 66709), -- 237567 (Hagar)
(237210, 1, 0, 0, 0, 0, 0, 0, 0, 289901, 0, 0, 0, 0, 0, 0, 0, 66709), -- 237210 (Orweyna)
(237837, 1, 0, 0, 0, 0, 0, 0, 0, 286077, 0, 0, 0, 0, 0, 0, 0, 66709), -- 237837 (Zur'ashar Kassameh)
(239525, 1, 0, 0, 0, 0, 0, 0, 0, 308496, 0, 0, 0, 0, 0, 0, 0, 66709); -- 239525 (Ruia)

REPLACE INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(39190, 237866, 66709), -- 237866 (Oorla)
(39194, 237865, 66709), -- 237865 (Danul)
(38640, 237343, 66709), -- 237343 (Halduron Brightwing)
(39240, 237345, 66709), -- 237345 (Halduron Brightwing)
(38392, 237209, 66709), -- 237209 (Ku'paal)
(39246, 237567, 66709), -- 237567 (Hagar)
(37879, 237210, 66709), -- 237210 (Orweyna)
(37955, 237837, 66709), -- 237837 (Zur'ashar Kassameh)
(42288, 239525, 66709); -- 239525 (Ruia)
