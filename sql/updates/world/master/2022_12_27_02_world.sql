SET @CGUID := 396663;
SET @OGUID := 251922;
SET @EVENT := 52;

-- Creature templates
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=15745; -- Greatfather Winter's Helper
UPDATE `creature_template` SET `speed_walk`=1, `BaseAttackTime`=1500 WHERE `entry`=15721; -- Mechanical Greench

DELETE FROM `creature_template_addon` WHERE `entry` IN (15721, 15745);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(15721, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 15721 (Mechanical Greench)
(15745, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''); -- 15745 (Greatfather Winter's Helper)

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (15745,15721));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(15745, 0, 0, 0, 417, 47213),
(15721, 0, 0, 0, 417, 47213);

-- Quests
UPDATE `quest_details` SET `VerifiedBuild`=47213 WHERE `ID`=7043;

DELETE FROM `quest_offer_reward` WHERE `ID` IN (66507 /*A Winter Veil Gift*/, 66508 /*A Gently Shaken Gift*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(66507, 0, 0, 0, 0, 0, 0, 0, 0, 'A small tag on this present reads:$b$bHappy holidays, $n!', 47213), -- A Winter Veil Gift
(66508, 0, 0, 0, 0, 0, 0, 0, 0, 'This present looks like it has been shaken a few times. The tag on it reads:$b$bTo a very special $r $c.', 47213); -- A Gently Shaken Gift

UPDATE `quest_offer_reward` SET `VerifiedBuild`=47213 WHERE `ID` IN (8769, 8768, 8744, 8803);

UPDATE `creature_queststarter` SET `VerifiedBuild`=47213 WHERE (`id`=13433 AND `quest`=7043);

DELETE FROM `gameobject_queststarter` WHERE `id` IN (180743, 180746, 180747, 180748, 180793, 187236);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(180743, 8744, 47213), -- A Carefully Wrapped Present started by Carefully Wrapped Present
(180746, 66508, 47213), -- A Gently Shaken Gift started by Gently Shaken Gift
(180747, 8768, 47213), -- A Gaily Wrapped Present started by Gaily Wrapped Present
(180748, 8769, 47213), -- A Ticking Present started by Ticking Present
(180793, 8803, 47213), -- A Festive Gift started by Festive Gift
(187236, 66507, 47213); -- A Winter Veil Gift started by Winter Veil Gift

DELETE FROM `game_event_gameobject_quest` WHERE `id` IN (180743, 180746, 180747, 180748, 180793, 187236);

DELETE FROM `gameobject_questender` WHERE `id` IN (180743, 180746, 180747, 180748, 180793, 187236);
INSERT INTO `gameobject_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(180743, 8744, 47213), -- A Carefully Wrapped Present ended by Carefully Wrapped Present
(180746, 66508, 47213), -- A Gently Shaken Gift ended by Gently Shaken Gift
(180747, 8768, 47213), -- A Gaily Wrapped Present ended by Gaily Wrapped Present
(180748, 8769, 47213), -- A Ticking Present ended by Ticking Present
(180793, 8803, 47213), -- A Festive Gift ended by Festive Gift
(187236, 66507, 47213); -- A Winter Veil Gift ended by Winter Veil Gift

DELETE FROM `item_loot_template` WHERE `Entry` IN (21191, 21310, 21327, 21363, 192093, 192094);
INSERT INTO `item_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(21191, 21254, 0, 100, 0, 1, 0, 5, 5, 'Carefully Wrapped Present - Winter Veil Cookie'),
(21191, 128650, 0, 100, 0, 1, 0, 3, 5, 'Carefully Wrapped Present - "Merry Munchkin" Costume'),
(21191, 116448, 0, 10, 0, 1, 1, 1, 1, 'Carefully Wrapped Present - Warm Red Woolen Socks'),
(21191, 116450, 0, 10, 0, 1, 1, 1, 1, 'Carefully Wrapped Present - Warm Green Woolen Socks'),
(21191, 116451, 0, 10, 0, 1, 1, 1, 1, 'Carefully Wrapped Present - Warm Blue Woolen Socks'),
(21310, 21301, 0, 0, 0, 1, 1, 1, 1, 'Gaily Wrapped Present - Green Helper Box'),
(21310, 21305, 0, 0, 0, 1, 1, 1, 1, 'Gaily Wrapped Present - Red Helper Box'),
(21310, 21308, 0, 0, 0, 1, 1, 1, 1, 'Gaily Wrapped Present - Jingling Bell'),
(21310, 21309, 0, 0, 0, 1, 1, 1, 1, 'Gaily Wrapped Present - Snowman Kit'),
(21327, 17706, 0, 3, 0, 1, 1, 1, 1, 'Ticking Present - Plans: Edge of Winter'),
(21327, 17709, 0, 3, 0, 1, 1, 1, 1, 'Ticking Present - Recipe: Elixir of Frost Power'),
(21327, 17720, 0, 3, 0, 1, 1, 1, 1, 'Ticking Present - Schematic: Snowmaster 9000'),
(21327, 17722, 0, 3, 0, 1, 1, 1, 1, 'Ticking Present - Pattern: Gloves of the Greatfather'),
(21327, 17724, 0, 3, 0, 1, 1, 1, 1, 'Ticking Present - Pattern: Green Holiday Shirt'),
(21327, 17725, 0, 3, 0, 1, 1, 1, 1, 'Ticking Present - Formula: Enchant Weapon - Winter''s Might'),
(21327, 21213, 0, 100, 0, 1, 0, 5, 5, 'Ticking Present - Preserved Holly'),
(21327, 21325, 0, 100, 0, 1, 0, 1, 1, 'Ticking Present - Mechanical Greench'),
(21363, 21328, 0, 100, 0, 1, 0, 1, 1, 'Festive Gift - Wand of Holiday Cheer'),
(192093, 191925, 0, 100, 0, 1, 0, 1, 1, 'Gently Shaken Gift - Falling Star Flinger'),
(192094, 191937, 0, 100, 0, 1, 0, 1, 1, 'Winter Veil Gift - Falling Star Catcher');

-- Creature spawns
DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 15745, 0, 1537, 5719, '0', 0, 0, 0, 0, -4912.6767578125, -976.28009033203125, 501.53271484375, 2.49582076072692871, 120, 0, 0, 118565, 0, 0, 0, 0, 0, 47213); -- Greatfather Winter's Helper (Area: The Commons - Difficulty: 0)

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180743, 0, 1537, 5719, '0', 0, 0, -4916.0380859375, -981.1710205078125, 501.847808837890625, 0.087265998125076293, 0, 0, 0.043619155883789062, 0.999048233032226562, 120, 255, 1, 47213), -- Carefully Wrapped Present (Area: The Commons - Difficulty: 0)
(@OGUID+1, 180746, 0, 1537, 5719, '0', 0, 0, -4915.1650390625, -978.1317138671875, 501.4498291015625, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 120, 255, 1, 47213), -- Gently Shaken Gift (Area: The Commons - Difficulty: 0)
(@OGUID+2, 180747, 0, 1537, 5719, '0', 0, 0, -4919.125, -980.60394287109375, 501.456329345703125, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 47213), -- Gaily Wrapped Present (Area: The Commons - Difficulty: 0)
(@OGUID+3, 180748, 0, 1537, 5719, '0', 0, 0, -4920.98095703125, -981.29241943359375, 501.46234130859375, 6.14356088638305664, 0, 0, -0.06975555419921875, 0.997564136981964111, 120, 255, 1, 47213), -- Ticking Present (Area: The Commons - Difficulty: 0)
(@OGUID+4, 180793, 0, 1537, 5719, '0', 0, 0, -4917.0869140625, -981.59259033203125, 501.838165283203125, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 47213), -- Festive Gift (Area: The Commons - Difficulty: 0)
(@OGUID+5, 187236, 0, 1537, 5719, '0', 0, 0, -4915.52734375, -979.5645751953125, 501.44732666015625, 0, 0, 0, 0, 1, 120, 255, 1, 47213); -- Winter Veil Gift (Area: The Commons - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid`=@CGUID+0;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(@EVENT, @OGUID+0),
(@EVENT, @OGUID+1),
(@EVENT, @OGUID+2),
(@EVENT, @OGUID+3),
(@EVENT, @OGUID+4),
(@EVENT, @OGUID+5);
