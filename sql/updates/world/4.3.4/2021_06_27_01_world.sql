SET @PATH := 42383 * 100;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -9841.973, 892.3976, 28.4042, NULL, 32854),
(@PATH, 1, -10334.81, 979.1163, 31.12993, NULL, 42356),
(@PATH, 2, -10362.01, 926.9496, 31.6568, NULL, 0);

DELETE FROM `waypoint_data_addon` WHERE `PathID`=@PATH;
INSERT INTO `waypoint_data_addon` (`PathID`, `PointID`, `SplinePointIndex`, `PositionX`, `PositionY`, `PositionZ`) VALUES
(@PATH, 0, 0, -9790.656, 821.21704, 27.443325),
(@PATH, 0, 1, -9790.656, 821.21704, 27.443325),
(@PATH, 0, 2, -9790.656, 821.21704, 27.443325),
(@PATH, 0, 3, -9790.656, 821.21704, 27.443325),
(@PATH, 1, 0,  -9851.893, 889.75696, 30.017067),
(@PATH, 1, 1,  -9871.893, 903.75696, 32.267067),
(@PATH, 1, 2,  -9886.393, 935.00696, 32.767067),
(@PATH, 1, 3,  -9873.643, 952.25696, 31.517067),
(@PATH, 1, 4,  -9876.143, 967.25696, 31.267067),
(@PATH, 1, 5,  -9888.643, 981.50696, 31.267067),
(@PATH, 1, 6,  -9898.393, 985.75696, 31.267067),
(@PATH, 1, 7,  -9914.143, 987.00696, 31.517067),
(@PATH, 1, 8,  -9935.643, 995.75696, 31.767067),
(@PATH, 1, 9,  -9954.893, 1003.50696, 31.517067),
(@PATH, 1, 10, -9969.143, 1004.25696, 31.517067),
(@PATH, 1, 11, -9990.893, 995.50696, 32.017067),
(@PATH, 1, 12, -10009.893, 987.50696, 32.267067),
(@PATH, 1, 13, -10024.643, 981.50696, 32.767067),
(@PATH, 1, 14, -10033.643, 982.75696, 33.017067),
(@PATH, 1, 15, -10041.643, 987.00696, 33.267067),
(@PATH, 1, 16, -10057.143, 999.50696, 33.017067),
(@PATH, 1, 17, -10072.393, 1006.75696, 33.517067),
(@PATH, 1, 18, -10081.393, 1008.50696, 34.017067),
(@PATH, 1, 19, -10091.893, 1004.75696, 35.267067),
(@PATH, 1, 20, -10103.143, 996.50696, 38.017067),
(@PATH, 1, 21, -10116.143, 990.00696, 38.267067),
(@PATH, 1, 22, -10129.393, 990.75696, 36.767067),
(@PATH, 1, 23, -10157.143, 988.25696, 34.267067),
(@PATH, 1, 24, -10173.893, 986.25696, 34.517067),
(@PATH, 1, 25, -10192.893, 985.50696, 33.517067),
(@PATH, 1, 26, -10209.393, 992.75696, 32.517067),
(@PATH, 1, 27, -10222.143, 995.25696, 32.517067),
(@PATH, 1, 28, -10246.393, 994.25696, 31.267067),
(@PATH, 1, 29, -10257.893, 992.00696, 31.517067),
(@PATH, 1, 30, -10266.143, 984.25696, 31.517067),
(@PATH, 1, 31, -10273.143, 973.25696, 31.267067),
(@PATH, 1, 32, -10281.893, 965.25696, 31.267067),
(@PATH, 1, 33, -10290.393, 964.00696, 31.267067),
(@PATH, 1, 34, -10304.893, 967.00696, 31.267067),
(@PATH, 1, 35, -10313.393, 969.75696, 31.267067),
(@PATH, 1, 36, -10323.893, 976.00696, 31.267067),
(@PATH, 2, 0, -10324.161, 973.53296, 31.393368),
(@PATH, 2, 1, -10323.161, 960.53296, 33.393368),
(@PATH, 2, 2, -10341.161, 942.53296, 32.893368);

UPDATE `creature` SET `ScriptName`='npc_westfall_refugee_bridge_to_sentinelhill' WHERE  `guid`=280420;
UPDATE `creature_template` SET `ScriptName`='npc_westfall_west_plains_drifter' WHERE  `entry`=42400;

DELETE FROM `linked_respawn` WHERE `guid` = 280419; 
INSERT INTO `linked_respawn` (`guid`, `linkedGuid`) VALUES (280419, 280420);

DELETE FROM `creature_formations` WHERE `leaderGUID` = 280420;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `followdistance`, `followangle`, `groupAI`) VALUES
(280420, 280420, 0, 0, 512),
(280420, 280419, 2, 270, 512);

DELETE FROM `vehicle_template_accessory` WHERE `entry` = 42399;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES 
(42399, 42403, 0, 1, 'Hobo Cart - Hobo Goods (Boots)', 8, 0),
(42399, 42401, 1, 1, 'Hobo Cart - Hobo Goods (Bag)', 8, 0),
(42399, 42401, 2, 1, 'Hobo Cart - Hobo Goods (Bag)', 8, 0),
(42399, 42402, 3, 1, 'Hobo Cart - Hobo Goods (Poop)', 8, 0);

DELETE FROM `creature_text` WHERE `CreatureID` = 42383 AND `GroupID` IN (11, 12, 13, 14, 15, 16);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42383, 11, 0, 'What the hell happened here?', 12, 7, 100, 1, 0, 0, 42318, 'Transient'),
(42383, 12, 0, 'What\'s happened to us? We\'re in worse shape now than when the Defias ran amok!', 12, 7, 100, 6, 0, 0, 42321, 'Transient'),
(42383, 13, 0, 'Let\'s get out of here before they try and pin this on us.', 12, 7, 100, 1, 0, 0, 42323, 'Transient'),
(42383, 14, 0, 'We\'re just trying to get a decent meal and maybe a comfortable night\'s sleep.', 12, 7, 100, 0, 0, 0, 42342, 'Transient to Transient'),
(42383, 15, 0, 'Dirty, rotten pig-lickers. You\'ll get your come-uppance some day.', 12, 7, 100, 396, 0, 0, 42347, 'Transient to Transient'),
(42383, 16, 0, 'Let\'s get the hell out of here. I hope this place burns to the ground.', 12, 7, 100, 396, 0, 0, 42348, 'Transient to Transient');

DELETE FROM `creature_text` WHERE `CreatureID` = 42400;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42400, 0, 0, 'Looks like the Furlbrow\'s were murdered...', 12, 7, 100, 396, 0, 0, 42320, 'West Plains Drifter'),
(42400, 1, 0, 'Yep. That King Varian is good for nothin\'.', 12, 7, 100, 396, 0, 0, 42322, 'West Plains Drifter'),
(42400, 2, 0, 'Good call.', 12, 7, 100, 396, 0, 0, 42324, 'West Plains Drifter'),
(42400, 3, 0, 'We\'re just trying to get a decent meal and maybe a comfortable night\'s sleep.', 12, 7, 100, 0, 0, 0, 42342, 'West Plains Drifter to Transient'),
(42400, 4, 0, 'Dirty, rotten pig-lickers. You\'ll get your come-uppance some day.', 12, 7, 100, 396, 0, 0, 42347, 'West Plains Drifter to Transient'),
(42400, 5, 0, 'Let\'s get the hell out of here. I hope this place burns to the ground.', 12, 7, 100, 396, 0, 0, 42348, 'West Plains Drifter to Transient');

DELETE FROM `creature_text` WHERE `CreatureID` = 42407;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42407, 0, 0, 'WHOA THERE, BUDDY!', 12, 7, 100, 3, 0, 0, 42340, 'Sentinel Hill Guard to Transient'),
(42407, 1, 0, 'Where do you think you two are going?', 12, 7, 100, 0, 0, 0, 42341, 'Sentinel Hill Guard to Transient'),
(42407, 2, 0, 'Can\'t you read, pal? Probably not, huh?', 12, 7, 100, 0, 0, 0, 42344, 'Sentinel Hill Guard to Transient'),
(42407, 3, 0, 'The sign here says: \"ABSOLUTELY NO BUMS!\" Now get lost!', 12, 7, 100, 1, 0, 0, 42345, 'Sentinel Hill Guard to Transient');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 42407;
UPDATE `creature_template` SET `AIName`='' WHERE  `entry`=42407;
UPDATE `creature_template` SET `ScriptName`='npc_westfall_sentinel_hill_guard' WHERE  `entry`=42407;

UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26214; -- Hot On the Trail: Murlocs
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26213; -- Hot On the Trail: The Riverpaw Clan
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26209; -- Murder Was The Case That They Gave Me
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26378; -- Hero's Call: Westfall!

UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=26215; -- Meet Two-Shoed Lou
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=26353; -- Captain Sanders' Hidden Treasure
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=26214; -- Hot On the Trail: Murlocs
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=26213; -- Hot On the Trail: The Riverpaw Clan
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=26209; -- Murder Was The Case That They Gave Me

DELETE FROM `quest_request_items` WHERE `ID`=26209;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `CompletionText`, `VerifiedBuild`) VALUES
(26209, 0, 6, 'Anything yet?', 15595); -- Murder Was The Case That They Gave Me

UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=15595 WHERE `ID`=26214; -- Hot On the Trail: Murlocs
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=15595 WHERE `ID`=26213; -- Hot On the Trail: The Riverpaw Clan

 -- Riverpaw Gnoll
SET @ENTRY := 117;
DELETE FROM smart_scripts WHERE entryOrGuid = @ENTRY AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= @ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When health between 0%-15%% (check once) - Self: Flee for assist"),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 3500, 7200, 25000, 35000, 11, 80475, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Every 25 - 35 seconds (3.5 - 7.2s initially) - Self: Cast spell Riverpaw Brand (80475) on Victim"),
(@ENTRY, 0, 2, 0, 4, 0, 20, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On aggro - Self: Talk 0 to invoker");

 -- Riverpaw Scout
SET @ENTRY := 500;
DELETE FROM smart_scripts WHERE entryOrGuid = @ENTRY AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= @ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Every 2.3 - 3.9 seconds (0 - 0s initially) - Self: Cast spell Shoot (6660) on Victim (flags: combat move)"),
(@ENTRY, 0, 1, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When health between 0%-15%% (check once) - Self: Flee for assist"),
(@ENTRY, 0, 2, 0, 4, 0, 20, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On aggro - Self: Talk 0 to invoker"),
(@ENTRY, 0, 3, 0, 0, 0, 100, 0, 5000, 7000, 25000, 30000, 11, 78509, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Every 25 - 30 seconds (5 - 7s initially) - Self: Cast spell Torch Toss (78509) on Victim");

 -- Murloc Raider
SET @ENTRY := 515;
DELETE FROM smart_scripts WHERE entryOrGuid = @ENTRY AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= @ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 2000, 5000, 50000, 60000, 11, 6533, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Every 50 - 60 seconds (2 - 5s initially) - Self: Cast spell Net (6533) on Victim"),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 4000, 6000, 27500, 33500, 11, 80522, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 27.5 - 33.5 seconds (4 - 6s initially) - Self: Cast spell Demoralizing Mmmrrrggglll (80522) on Self");

 -- Murloc Coastrunner
SET @ENTRY := 126;
DELETE FROM smart_scripts WHERE entryOrGuid = @ENTRY AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= @ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 85, 0, 6600, 9800, 24500, 32900, 11, 7357, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Every 24.5 - 32.9 seconds (6.6 - 9.8s initially) - Self: Cast spell Poisonous Stab (7357) on Victim");

 -- Murloc Minor Oracle
SET @ENTRY := 456;
DELETE FROM smart_scripts WHERE entryOrGuid = @ENTRY AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= @ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 5500, 7500, 25000, 35000, 11, 79831, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Every 25 - 35 seconds (5.5 - 7.5s initially) - Self: Cast spell Wave Crash (79831) on Victim"),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 500, 1000, 500000, 600000, 11, 79892, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 500 - 600 seconds (0.5 - 1s initially) - Self: Cast spell Water Shield (79892) on Self"),
(@ENTRY, 0, 2, 0, 16, 0, 100, 0, 79892, 1, 15000, 30000, 11, 79892, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When friendly unit in range 1 yards has not got aura Water Shield (79892) (check every 15000 - 30000 ms) - Self: Cast spell Water Shield (79892) on Self");

UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26232; -- Lou's Parting Thoughts
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26229; -- "I TAKE Candle!"
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26228; -- Livin' the Life
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26230; -- Feast or Famine
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26215; -- Meet Two-Shoed Lou

UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=26236; -- Shakedown at the Saldean's
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=26232; -- Lou's Parting Thoughts
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=26230; -- Feast or Famine
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=26229; -- "I TAKE Candle!"
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=26228; -- Livin' the Life

DELETE FROM `quest_request_items` WHERE `ID` IN (26230 /*Feast or Famine*/, 26229 /*"I TAKE Candle!"*/, 26228 /*Livin' the Life*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `CompletionText`, `VerifiedBuild`) VALUES
(26230, 396, 396, 'Dirt pies don\'t make themselves - usually.', 15595), -- Feast or Famine
(26229, 0, 5, 'I just want those kobolds dead. Dead!', 15595), -- "I TAKE Candle!"
(26228, 0, 0, 'Be careful with my old house. I plan to hand that off to my kids when they move out.', 15595); -- Livin' the Life

DELETE FROM `spell_area` WHERE `spell`=79229 AND `area`=40;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(79229, 40, 0, 26232, 0, 0, 2, 3, 64, 9);

DELETE FROM `creature_addon` WHERE `guid` IN (275897, 275898, 275896, 275894, 275892, 275895, 275888, 275900, 275902, 275904, 275906, 275908, 275907, 275903, 275901, 275899);
INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `cyclicSplinePathId`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(275897, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, NULL),
(275898, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, NULL),
(275896, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, NULL),
(275894, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, NULL),
(275892, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, NULL),
(275895, 0, 0, 0, 3, 1, 0, 0, 0, 0, 0, '78677'),
(275888, 2758880, 0, 0, 0, 1, 0, 0, 0, 0, 0, '79143'),
(275900, 0, 0, 0, 3, 1, 0, 0, 0, 0, 0, '78677'),
(275902, 0, 0, 0, 3, 1, 0, 0, 0, 0, 0, '78677'),
(275904, 0, 0, 0, 3, 1, 0, 0, 0, 0, 0, '78677'),
(275906, 0, 0, 0, 3, 1, 0, 0, 0, 0, 0, '78677'),
(275908, 0, 0, 0, 3, 1, 0, 0, 0, 0, 0, '78677'),
(275907, 0, 0, 0, 3, 1, 0, 0, 0, 0, 0, '78677'),
(275903, 0, 0, 0, 3, 1, 0, 0, 0, 0, 0, '78677'),
(275901, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, NULL),
(275899, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, NULL);

DELETE FROM `waypoint_data` WHERE `id`= 2758880;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(2758880, 0, -9842.531, 1300.802, 41.91594, 0, -1294),
(2758880, 1, -9830.325, 1289.771, 40.57365, 0, -1657),
(2758880, 2, -9819.903, 1276.254, 41.03447, 0, -1170),
(2758880, 3, -9828.67, 1270.09, 40.57072, 0, -1567),
(2758880, 4, -9841.393, 1260.05, 41.9507, 0, -631),
(2758880, 5, -9851.759, 1266.052, 41.59425, 0, -962),
(2758880, 6, -9867.886, 1280.066, 40.81526, 0, -1479),
(2758880, 7, -9856.901, 1292.205, 41.73405, 0, -1752);

UPDATE `creature` SET `position_x`= -9842.531, `position_y`= 1300.802, `position_z`= 41.91594, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= 275888;

DELETE FROM `waypoint_data` WHERE `id`= 2758590;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(2758590, 0, -9858.272, 1337.807, 42.02751, 0, -888),
(2758590, 1, -9871.33, 1348.74, 42.44026, 0, -1678),
(2758590, 2, -9900.007, 1320.08, 42.78728, 0, -1002),
(2758590, 3, -9887.603, 1306.399, 42.10258, 0, -1156),
(2758590, 4, -9882.014, 1314.167, 43.11626, 0, -1403),
(2758590, 5, -9886.849, 1308.37, 42.33904, 0, -885),
(2758590, 6, -9884.661, 1301.674, 42.14714, 0, -1308),
(2758590, 7, -9873.988, 1294.444, 42.19026, 0, -1565),
(2758590, 8, -9861.205, 1304.431, 42.19865, 0, -869),
(2758590, 9, -9846.795, 1322.707, 43.98332, 0, -1749);

UPDATE `creature` SET `position_x`= -9858.272, `position_y`= 1337.807, `position_z`= 42.02751, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= 275859;
DELETE FROM `creature_addon` WHERE `guid`= 275859;
INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `bytes2`) VALUES
(275859, 2758590, 1);

-- npcflag condition not yet implemented
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11779 AND `SourceEntry`=0 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 11779, 0, 0, 0, 8, 0, 26230, 0, 0, 0, 0, 0, '', 'Show gossip menu 11779 option id 0 if quest Feast or Famine has been rewarded.');

DELETE FROM `gossip_menu_option` WHERE `MenuId`=11779 AND `OptionIndex`=0;
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`, `VerifiedBuild`) VALUES
(11779, 0, 1, 'Let me browse your goods.', 2823, 3, 128, 15595);

 -- Timed list 4250000
SET @ENTRY := 4250000;
DELETE FROM smart_scripts WHERE entryOrGuid = @ENTRY AND source_type = 9;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 9300, 9300, 0, 0, 86, 79290, 0, 29, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 9.3 seconds - Target unit in Seat 0: Cast spell General Trigger 1: Glubtok (79290) at Self"),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 6500, 6500, 0, 0, 86, 79279, 0, 29, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 6.5 seconds - Target unit in Seat 0: Cast spell General Trigger 1: Figure (79279) at Self"),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 86, 79292, 0, 29, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 8 seconds - Target unit in Seat 0: Cast spell General Trigger 2: Glubtok (79292) at Self"),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 86, 79283, 0, 29, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 4 seconds - Target unit in Seat 0: Cast spell General Trigger 2: Figure (79283) at Self"),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 16000, 16000, 0, 0, 86, 79294, 0, 29, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 16 seconds - Target unit in Seat 0: Cast spell General Trigger 3: Glubtok (79294) at Self"),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 4100, 4100, 0, 0, 86, 79284, 0, 29, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 4.1 seconds - Target unit in Seat 0: Cast spell General Trigger 3: Figure (79284) at Self"),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 6400, 6400, 0, 0, 86, 79297, 0, 29, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 6.4 seconds - Target unit in Seat 0: Cast spell General Trigger 4: Glubtok (79297) at Self"),
(@ENTRY, 9, 7, 0, 0, 0, 100, 0, 11400, 11400, 0, 0, 86, 79287, 0, 29, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 11.4 seconds - Target unit in Seat 0: Cast spell General Trigger 4: Figure (79287) at Self");

DELETE FROM `creature_text` WHERE `CreatureID` IN (42387, 42562);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42387, 0, 0, 'Did you... Did you meet her?', 12, 7, 100, 6, 0, 0, 42439, 'Thug to Player'),
(42387, 1, 0, 'Yep. She\'s for real.', 12, 7, 100, 396, 0, 0, 42440, 'Thug to Player'),
(42387, 2, 0, 'She wanted me to tell you lugs that she appreciates the job that we did for her on the Furlbrows. Gave me a pile o\' gold to split with you all.', 12, 7, 100, 396, 0, 0, 42441, 'Thug to Player'),
(42387, 3, 0, 'See her face? Is it really...', 12, 0, 100, 6, 0, 0, 42442, 'Thug to Player'),
(42387, 4, 0, 'Whoa, what do we have here? Looks like we have ourselves an eavesdropper, boys.', 12, 0, 100, 5, 0, 0, 42443, 'Thug to Player'),
(42387, 5, 0, 'Only one thing to do with a lousy, good-for-nothin eavesdropper.', 12, 0, 100, 397, 0, 0, 42444, 'Thug to Player'),
(42387, 6, 0, 'DIE!', 12, 0, 100, 53, 0, 0, 28793, 'Thug to Player'), -- BroadcastTextID: 1694 - 9359 - 14091 - 28793 - 42445 - 51125 - 69531
(42562, 0, 0, 'Hurry back to the Furlbrow\'s Cottage!', 42, 0, 100, 0, 0, 0, 42446, 'Lou\'s Parting Thoughts Trigger to Player');

DELETE FROM `areatrigger_scripts` WHERE `entry`=5988;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES (5988, 'at_westfall_two_shoed_lou_thugs');

UPDATE `creature_template` SET `ScriptName`='npc_westfall_thug' WHERE `entry`=42387;
UPDATE `creature_template` SET `ScriptName`='npc_westfall_lous_parting_thoughts_trigger' WHERE `entry`=42562;

DELETE FROM `creature` WHERE  `guid`=275910;
DELETE FROM `creature` WHERE  `guid`=275911;
DELETE FROM `creature` WHERE  `guid`=275915;
DELETE FROM `creature` WHERE  `guid`=275916;

DELETE FROM `spell_area` WHERE `spell`=79346 AND `area`=40 AND `quest_start`=26232 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(79346, 40, 26232, 0, 0, 0, 2, 3, 66, 11);

DELETE FROM `creature_text` WHERE `CreatureID` = 42390;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42390, 0, 0, 'Pssst...', 12, 0, 100, 0, 0, 0, 42306, 'Small-Time Hustler to Player'),
(42390, 1, 0, 'What\'re you doin\' out here? Slummin\'?', 12, 7, 100, 25, 0, 0, 42310, 'Small-Time Hustler to Player'),
(42390, 1, 1, 'I think we can do business.', 12, 7, 100, 25, 0, 0, 42313, 'Small-Time Hustler to Player'),
(42390, 1, 2, 'You need something, $g mack:lady;?', 12, 7, 100, 25, 0, 0, 42307, 'Small-Time Hustler to Player'),
(42390, 1, 3, 'You lookin\' for somethin\' a little more... exotic?', 12, 7, 100, 25, 0, 0, 42312, 'Small-Time Hustler to Player'),
(42390, 1, 4, 'Whaddya need? Information? I got that too!', 12, 7, 100, 25, 0, 0, 42311, 'Small-Time Hustler to Player'),
(42390, 1, 5, 'Keep your head low, $g buddy:lady;.', 12, 7, 100, 25, 0, 0, 42314, 'Small-Time Hustler to Player');

DELETE FROM `areatrigger_scripts` WHERE `entry`=5987;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES (5987, 'at_westfall_small_time_hustler');

UPDATE `creature_template` SET `ScriptName`='npc_westfall_small_time_hustler' WHERE  `entry`=42390;

DELETE FROM `creature_text` WHERE `CreatureID` = 42559;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42559, 0, 0, 'You were standing right here! What the hell did you see? Speak up!', 12, 7, 100, 0, 0, 0, 42456, 'Stormwind Investigator to Player'),
(42559, 1, 0, 'Natural causes? Two bullets in the chest and his shoes are on his head. What kind of natural death would that be?', 12, 7, 100, 0, 0, 0, 42458, 'Stormwind Investigator to Player');

DELETE FROM `creature_text` WHERE `CreatureID` = 42384 AND `GroupID` = 11;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42384, 11, 0, 'I... I didn\'t see nothin\'! He... he died of natural causes.', 12, 7, 100, 0, 0, 0, 42457, 'Homeless Stormwind Citizen to Player');

DELETE FROM `creature_text` WHERE `CreatureID` = 42558;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42558, 0, 0, 'Doesn\'t look good, rookie.', 12, 7, 100, 1, 0, 0, 42447, 'Lieutenant Horatio Laine to Player'),
(42558, 1, 0, 'This was an execution. Whoever did this was sending a message...', 12, 7, 100, 0, 0, 0, 42449, 'Lieutenant Horatio Laine to Player'),
(42558, 2, 0, 'A message for anyone that would dare snitch on these criminals.', 12, 7, 100, 0, 0, 0, 42450, 'Lieutenant Horatio Laine to Player'),
(42558, 3, 0, 'It would appear that poor Lou really put his foot...', 12, 7, 100, 0, 0, 0, 42451, 'Lieutenant Horatio Laine to Player'),
(42558, 4, 0, 'In his mouth.', 12, 7, 100, 0, 0, 0, 42452, 'Lieutenant Horatio Laine to Player');

 -- Clientside area trigger 5989
SET @ENTRY := 5989;
DELETE FROM smart_scripts WHERE entryOrGuid = @ENTRY AND source_type = 2;
DELETE FROM areatrigger_scripts WHERE entry = @ENTRY;
INSERT INTO areatrigger_scripts(entry, ScriptName) VALUES(@ENTRY, "SmartTrigger");
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 2, 0, 0, 46, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 251575, 42558, 0, 0, 0, 0, 0, "On trigger - Creature Lieutenant Horatio Laine (42558) with guid 251575: Set creature data #1 to 1");

DELETE FROM conditions WHERE SourceTypeOrReferenceId = 22 AND SourceEntry = 5989 AND SourceId = 2;

INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, Comment) VALUES
(22, 1, 5989, 2, 0, 28, 0, 26232, 0, 0, 0, "Action invoker has completed quest quest Lou's Parting Thoughts (26232) (but not yet rewarded)");

 -- Lieutenant Horatio Laine
SET @ENTRY := 42558;
DELETE FROM smart_scripts WHERE entryOrGuid = @ENTRY AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= @ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 80, 4255800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On data[1] set to 1 - Self: Start timed action list id #4255800 (update out of combat)");

DELETE FROM conditions WHERE SourceTypeOrReferenceId = 22 AND SourceEntry = 42558 AND SourceId = 0;

 -- Timed list 4255800
SET @ENTRY := 4255800;
DELETE FROM smart_scripts WHERE entryOrGuid = @ENTRY AND source_type = 9;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 10, 251574, 42559, 0, 0, 0, 0, 0, "After 0 seconds - Creature Stormwind Investigator (42559) with guid 251574: Talk 0 to invoker"),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 4500, 4500, 0, 0, 1, 11, 0, 0, 0, 0, 0, 10, 251572, 42384, 0, 0, 0, 0, 0, "After 4.5 seconds - Creature Homeless Stormwind Citizen (42384) with guid 251572: Talk 11 to invoker"),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 10, 251574, 42559, 0, 0, 0, 0, 0, "After 4 seconds - Creature Stormwind Investigator (42559) with guid 251574: Talk 1 to invoker"),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 10 seconds - Self: Talk 0 to invoker"),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 5 seconds - Self: Talk 1 to invoker"),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 6 seconds - Self: Talk 2 to invoker"),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 6 seconds - Self: Talk 3 to invoker"),
(@ENTRY, 9, 7, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 3.5 seconds - Self: Talk 4 to invoker");

DELETE FROM conditions WHERE SourceTypeOrReferenceId = 22 AND SourceEntry = 4255800 AND SourceId = 9;
