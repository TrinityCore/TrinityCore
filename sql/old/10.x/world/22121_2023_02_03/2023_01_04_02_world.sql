SET @mop_CGUID := 396708;
SET @wod_CGUID := 460983;
SET @sl_CGUID := 1051925;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @mop_CGUID+0 AND @mop_CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@mop_CGUID+0, 67383, 974, 5861, 5870, '0', '0', 0, 0, 0, -4098.87353515625, 6395.91162109375, 13.20007991790771484, 4.637650012969970703, 120, 0, 0, 1190, 0, 0, 0, 0, 0, 47213), -- Honky-Tonk (Area: The Darkmoon Faire - Difficulty: 0)
(@mop_CGUID+1, 67370, 974, 5861, 5870, '0', '0', 0, 0, 0, -4100.751953125, 6394.63720703125, 13.20008277893066406, 4.967448711395263671, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47213), -- Jeremy Feasel (Area: The Darkmoon Faire - Difficulty: 0)
(@mop_CGUID+2, 67382, 974, 5861, 5870, '0', '0', 0, 0, 0, -4102.95849609375, 6394.54931640625, 13.20008659362792968, 5.107638835906982421, 120, 0, 0, 1190, 0, 0, 0, 0, 0, 47213), -- Fezwick (Area: The Darkmoon Faire - Difficulty: 0)
(@mop_CGUID+3, 67384, 974, 5861, 5870, '0', '0', 0, 0, 0, -4101.96337890625, 6394.77685546875, 14.99535274505615234, 5.291092872619628906, 120, 0, 0, 1190, 0, 0, 0, 0, 0, 47213); -- Judgment (Area: The Darkmoon Faire - Difficulty: 0)

DELETE FROM `creature` WHERE `guid` BETWEEN @wod_CGUID+0 AND @wod_CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@wod_CGUID+0, 85523, 974, 5861, 5870, '0', '0', 0, 0, 0, -4089.520751953125, 6388.73681640625, 13.22179031372070312, 3.441970586776733398, 120, 0, 0, 1190, 0, 0, 0, 0, 0, 47213), -- Mr. Pointy (Area: The Darkmoon Faire - Difficulty: 0)
(@wod_CGUID+1, 85525, 974, 5861, 5870, '0', '0', 0, 0, 0, -4090.34033203125, 6389.697265625, 14.96317481994628906, 3.59274911880493164, 120, 0, 0, 1190, 0, 0, 0, 0, 0, 47213), -- Syd (Area: The Darkmoon Faire - Difficulty: 0)
(@wod_CGUID+2, 85522, 974, 5861, 5870, '0', '0', 0, 0, 0, -4091.58154296875, 6392.1943359375, 13.20008087158203125, 3.972317218780517578, 120, 0, 0, 1190, 0, 0, 0, 0, 0, 47213), -- Otto (Area: The Darkmoon Faire - Difficulty: 0)
(@wod_CGUID+3, 85519, 974, 5861, 5870, '0', '0', 0, 0, 1, -4091.09375, 6390.39501953125, 13.21238136291503906, 3.737870693206787109, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47213); -- Christoph VonFeasel (Area: The Darkmoon Faire - Difficulty: 0)

DELETE FROM `creature` WHERE `guid` BETWEEN @sl_CGUID+0 AND @sl_CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@sl_CGUID+0, 178298, 974, 5861, 5870, '0', '0', 0, 0, 0, -4101.62841796875, 6398.087890625, 14.1762847900390625, 5.024493694305419921, 120, 0, 0, 74, 0, 0, 0, 0, 0, 47213), -- Widget (Area: The Darkmoon Faire - Difficulty: 0)
(@sl_CGUID+1, 178299, 974, 5861, 5870, '0', '0', 0, 0, 0, -4101.0087890625, 6398.33349609375, 14.17394161224365234, 5.024493694305419921, 120, 0, 0, 34, 0, 0, 0, 0, 0, 47213); -- Gizmo (Area: The Darkmoon Faire - Difficulty: 0)

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (178299, 178298, 85525, 67384);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(178299, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 178299 (Gizmo)
(178298, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Widget
(85525, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- Syd
(67384, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''); -- Judgment

UPDATE `creature_template_addon` SET `mount`=78112 WHERE `entry`=14823; -- 14823 (Silas Darkmoon)

-- Creature Template
UPDATE `creature_template` SET `gossip_menu_id`=16967, `minlevel`=70, `maxlevel`=70 WHERE `entry`=85519; -- Christoph VonFeasel
UPDATE `creature_template` SET `gossip_menu_id`=15172, `minlevel`=70, `maxlevel`=70 WHERE `entry`=67370; -- Jeremy Feasel
UPDATE `creature_template` SET `minlevel`=2, `maxlevel`=2, `faction`=35, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=178299; -- Gizmo

-- Creature Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (85525, 67384);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(85525, 0, 0, 1, 0, 0, 0, NULL),
(67384, 0, 0, 1, 0, 0, 0, NULL);

-- Quest stuff
DELETE FROM `quest_details` WHERE `ID` IN (32175 /*Darkmoon Pet Battle!*/, 36471 /*A New Darkmoon Challenger!*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(32175, 1, 0, 0, 0, 0, 0, 0, 0, 47213), -- Darkmoon Pet Battle!
(36471, 1, 0, 0, 0, 0, 0, 0, 0, 47213); -- A New Darkmoon Challenger!

DELETE FROM `quest_request_items` WHERE `ID` IN (32175 /*Darkmoon Pet Battle!*/, 36471 /*A New Darkmoon Challenger!*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(32175, 0, 0, 0, 0, 'My, my. Well done!', 47213), -- Darkmoon Pet Battle!
(36471, 0, 0, 0, 0, 'Ready, eh? Put up your cat\'s tiny dukes!', 47213); -- A New Darkmoon Challenger!

DELETE FROM `quest_reward_display_spell` WHERE (`QuestID`=66444 AND `Idx`=0);
INSERT INTO `quest_reward_display_spell` (`QuestID`, `Idx`, `SpellID`, `PlayerConditionID`, `VerifiedBuild`) VALUES
(66444, 0, 390631, 0, 47213);

-- Gossip
DELETE FROM `gossip_menu` WHERE (`MenuID`=15172 AND `TextID`=21739) OR (`MenuID`=16967 AND `TextID`=24693);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(15172, 21739, 47213), -- 67370 (Jeremy Feasel)
(16967, 24693, 47213); -- 85519 (Christoph VonFeasel)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (16967,15172));
INSERT INTO `gossip_menu_option` (`GossipOptionID`, `MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `Flags`, `OverrideIconID`, `GossipNpcOptionID`, `VerifiedBuild`) VALUES
(42667, 16967, 0, 0, 'I challenge you to a pet battle! |cFF0008E8(Darkmoon Game Token)|r', 68908, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 47213),
(41758, 15172, 0, 0, 'I challenge you to a pet battle! |cFF0008E8(Darkmoon Game Token)|r', 68908, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 47213);
