SET @CGUID := 651865;
SET @OGUID := 400542;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+20;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 93725, 1220, 7334, 7599, '0', 0, 0, 0, 0, -864.46575927734375, 6093.65673828125, 14.50513267517089843, 5.402491092681884765, 120, 10, 0, 27, 0, 1, 0, 0, 0, 46549), -- Slithering Brownscale (Area: Shackle's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1, 91419, 1220, 7334, 7599, '0', 0, 0, 0, 0, -812.44964599609375, 6101.1103515625, 7.08855295181274414, 0.742335915565490722, 120, 0, 0, 3923, 100, 0, 0, 0, 0, 46549), -- Mr. Shackle (Area: Shackle's Den - Difficulty: 0)
(@CGUID+2, 101554, 1220, 7334, 7599, '0', 0, 0, 0, 0, -787.246826171875, 6226.30517578125, -0.36890578269958496, 2.065465450286865234, 120, 10, 0, 3923, 0, 1, 0, 0, 0, 46549), -- Spikebacked Scuttler (Area: Shackle's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+3, 101554, 1220, 7334, 7599, '0', 0, 0, 0, 0, -774.09490966796875, 6249.50927734375, 0.628494739532470703, 5.767069816589355468, 120, 10, 0, 3923, 0, 1, 0, 0, 0, 46549), -- Spikebacked Scuttler (Area: Shackle's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+4, 89288, 1220, 7334, 7599, '0', 0, 0, 0, 0, -824.7939453125, 6201.07861328125, 5.356404304504394531, 3.323116779327392578, 120, 10, 0, 1569, 0, 1, 0, 0, 0, 46549), -- Scuttleback Pincher (Area: Shackle's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+5, 109028, 1220, 7334, 7599, '0', 0, 0, 0, 1, -815.31427001953125, 6122.203125, 5.129961013793945312, 0, 120, 0, 0, 23538, 0, 0, 0, 0, 0, 46549), -- Horkus (Area: Shackle's Den - Difficulty: 0) (Auras: 215919 - Truthguard Area Trigger)
(@CGUID+6, 91719, 1220, 7334, 7599, '0', 0, 0, 0, 1, -811.77874755859375, 6150.68701171875, 6.333962440490722656, 2.421398878097534179, 120, 0, 0, 29423, 0, 0, 0, 0, 0, 46549), -- Smuggler Brute (Area: Shackle's Den - Difficulty: 0) (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+7, 114287, 1220, 7334, 7599, '0', 0, 0, 0, 0, -780.4461669921875, 6131.275390625, 4.729145050048828125, 3.784507036209106445, 120, 0, 0, 4511, 0, 0, 0, 0, 0, 46549), -- Hippogryph (Area: Shackle's Den - Difficulty: 0)
(@CGUID+8, 97289, 1220, 7334, 7599, '0', 0, 0, 0, 0, -794.554931640625, 6145.64892578125, 3.540369987487792968, 2.422825336456298828, 120, 10, 0, 27, 0, 1, 0, 0, 0, 46549), -- Juvenile Scuttleback (Area: Shackle's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+9, 112866, 1220, 7334, 7599, '0', 0, 0, 0, 1, -782.51214599609375, 6128.51025390625, 4.729145050048828125, 3.441309213638305664, 120, 0, 0, 281565, 0, 0, 0, 0, 0, 46549), -- Avaya Farwind (Area: Shackle's Den - Difficulty: 0)
(@CGUID+10, 113892, 1220, 7334, 7599, '0', 0, 0, 0, 1, -782.07989501953125, 6126.8515625, 4.729145050048828125, 2.550699472427368164, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46549), -- Kevin Lee (Area: Shackle's Den - Difficulty: 0)
(@CGUID+11, 64806, 1220, 7334, 7599, '0', 0, 0, 0, 0, -781.65435791015625, 6067.4794921875, 11.43035507202148437, 1.244855403900146484, 120, 10, 0, 5, 0, 1, 0, 0, 0, 46549), -- Rapana Whelk (Area: Shackle's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+12, 112871, 1220, 7334, 7599, '0', 0, 0, 0, 1, -784.22918701171875, 6127.033203125, 4.729145050048828125, 0.592259347438812255, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46549), -- Holland Mattila (Area: Shackle's Den - Difficulty: 0)
(@CGUID+13, 107768, 1220, 7334, 7599, '0', 0, 0, 0, 1, -800.5850830078125, 6103.63720703125, 5.642831802368164062, 1.934130191802978515, 120, 0, 0, 5885, 100, 0, 0, 0, 0, 46549), -- 'Smackdown' Jack (Area: Shackle's Den - Difficulty: 0)
(@CGUID+14, 101554, 1220, 7334, 7599, '0', 0, 0, 0, 0, -734.58599853515625, 6224.23974609375, 1.478126287460327148, 4.68700408935546875, 120, 10, 0, 3923, 0, 1, 0, 0, 0, 46549), -- Spikebacked Scuttler (Area: Shackle's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+15, 101554, 1220, 7334, 7599, '0', 0, 0, 0, 0, -818.41400146484375, 6182.96630859375, 2.113361358642578125, 4.667453765869140625, 120, 10, 0, 3923, 0, 1, 0, 0, 0, 46549), -- Spikebacked Scuttler (Area: Shackle's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+16, 91719, 1220, 7334, 7599, '0', 0, 0, 0, 1, -784.890625, 6154.587890625, 5.735948085784912109, 1.938125014305114746, 120, 0, 0, 29423, 0, 0, 0, 0, 0, 46549), -- Smuggler Brute (Area: Shackle's Den - Difficulty: 0) (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+17, 112874, 1220, 7334, 7599, '0', 0, 0, 0, 0, -776.88543701171875, 6116.99853515625, 4.752652645111083984, 1.29154360294342041, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46549), -- Landon Doi (Area: Shackle's Den - Difficulty: 0)
(@CGUID+18, 64806, 1220, 7334, 7599, '0', 0, 0, 0, 0, -782.3492431640625, 6210.37255859375, -0.16590285301208496, 4.20244598388671875, 120, 10, 0, 5, 0, 1, 0, 0, 0, 46549), -- Rapana Whelk (Area: Shackle's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+19, 89288, 1220, 7334, 7599, '0', 0, 0, 0, 0, -812.72698974609375, 6192.85986328125, 0.734699249267578125, 1.044620871543884277, 120, 10, 0, 1569, 0, 1, 0, 0, 0, 46549), -- Scuttleback Pincher (Area: Shackle's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+20, 101554, 1220, 7334, 7599, '0', 0, 0, 0, 0, -811.843017578125, 6235.712890625, -1.4217691421508789, 5.610209465026855468, 120, 10, 0, 3923, 0, 1, 0, 0, 0, 46549); -- Spikebacked Scuttler (Area: Shackle's Den - Difficulty: 0) (possible waypoints or random movement)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+20;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Mr. Shackle
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '215919'), -- Horkus - 215919 - Truthguard Area Trigger
(@CGUID+6, 0, 0, 0, 0, 0, 1, 1, 333, 0, 0, 0, 0, '18950'), -- Smuggler Brute - 18950 - Invisibility and Stealth Detection
(@CGUID+7, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Hippogryph
(@CGUID+9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Avaya Farwind
(@CGUID+10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Kevin Lee
(@CGUID+12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Holland Mattila
(@CGUID+13, 0, 0, 0, 0, 0, 1, 0, 426, 0, 0, 0, 0, ''), -- 'Smackdown' Jack
(@CGUID+16, 0, 0, 0, 0, 0, 1, 1, 333, 0, 0, 0, 0, '18950'); -- Smuggler Brute - 18950 - Invisibility and Stealth Detection

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+6;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 251829, 1220, 7334, 7599, '0', 0, 0, -799.203125, 6102.30126953125, 5.19053506851196289, 4.598945140838623046, 0, 0, -0.74605655670166015, 0.665882587432861328, 120, 255, 1, 46549), -- Mailbox (Area: Shackle's Den - Difficulty: 0)
(@OGUID+1, 258972, 1220, 7334, 7599, '0', 0, 0, -791.5850830078125, 6111.33349609375, 4.645809650421142578, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 120, 255, 1, 46549), -- Campfire (Area: Shackle's Den - Difficulty: 0)
(@OGUID+2, 241907, 1220, 7334, 7599, '0', 0, 0, -821.1875, 6082.3525390625, 2.897713899612426757, 0.397231251001358032, 0, 0, 0.197312355041503906, 0.980340659618377685, 120, 255, 1, 46549), -- 6OR TradingPost Stack 02 (Area: Shackle's Den - Difficulty: 0)
(@OGUID+3, 241906, 1220, 7334, 7599, '0', 0, 0, -826.9774169921875, 6087.041015625, 2.936748504638671875, 5.856661796569824218, 0, 0, -0.21164894104003906, 0.977345764636993408, 120, 255, 1, 46549), -- 6OR TradingPost Stack 01 (Area: Shackle's Den - Difficulty: 0)
(@OGUID+4, 241907, 1220, 7334, 7599, '0', 0, 0, -826.86981201171875, 6091.80712890625, 2.913311481475830078, 4.869811534881591796, 0, 0, -0.64931774139404296, 0.760517239570617675, 120, 255, 1, 46549), -- 6OR TradingPost Stack 02 (Area: Shackle's Den - Difficulty: 0)
(@OGUID+5, 241906, 1220, 7334, 7599, '0', 0, 0, -826.515625, 6082.015625, 2.917426347732543945, 3.8948974609375, 0, 0, -0.929901123046875, 0.367809593677520751, 120, 255, 1, 46549), -- 6OR TradingPost Stack 01 (Area: Shackle's Den - Difficulty: 0)
(@OGUID+6, 241906, 1220, 7334, 7599, '0', 0, 0, -817.920166015625, 6083.40966796875, 2.88257145881652832, 1.091060161590576171, 0, 0, 0.518871307373046875, 0.854852378368377685, 120, 255, 1, 46549); -- 6OR TradingPost Stack 01 (Area: Shackle's Den - Difficulty: 0)

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (241906 /*6OR TradingPost Stack 01*/, 241907 /*6OR TradingPost Stack 02*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(241906, 114, 0, 0, 0), -- 6OR TradingPost Stack 01
(241907, 114, 0, 0, 0); -- 6OR TradingPost Stack 02

DELETE FROM `creature_text` WHERE `CreatureID` = 91419;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(91419, 0, 0, 'It\'s unfortunate that affairs have come to this, but what are we going to do? Wait for them to come slaughter us in our sleep and go out of business?', 12, 0, 100, 6, 0, 0, 111167, 5, 'c to Player'),
(91419, 1, 0, 'Welcome to our humble place of business, traveler.', 12, 0, 100, 2, 0, 40019, 92192, 0, 'Mr. Shackle to Player');

UPDATE `gossip_menu` SET `VerifiedBuild`=46549 WHERE (`MenuID`=18270 AND `TextID`=26121) OR (`MenuID`=19881 AND `TextID`=29539);

UPDATE `creature_template` SET `gossip_menu_id`=18270, `AIName` = 'SmartAI', `VerifiedBuild`=46549 WHERE `entry`=91419; -- Mr. Shackle
UPDATE `creature_template` SET `gossip_menu_id`=19881, `VerifiedBuild`=46549 WHERE `entry`=109028; -- Horkus
UPDATE `creature_template` SET `unit_flags`=33536, `VerifiedBuild`=46549 WHERE `entry`=112874; -- Landon Doi
UPDATE `creature_template` SET `VerifiedBuild`=46549 WHERE `entry`=64806; -- Rapana Whelk
UPDATE `creature_template` SET `VerifiedBuild`=46549 WHERE `entry`=89288;
UPDATE `creature_template` SET `VerifiedBuild`=46549 WHERE `entry`=91719; -- Smuggler Brute
UPDATE `creature_template` SET `VerifiedBuild`=46549 WHERE `entry`=114287;
UPDATE `creature_template` SET `VerifiedBuild`=46549 WHERE `entry`=97289; -- Juvenile Scuttleback
UPDATE `creature_template` SET `AIName` = 'SmartAI', `VerifiedBuild`=46549 WHERE `entry`=112866; -- Avaya Farwind
UPDATE `creature_template` SET `AIName` = 'SmartAI', `VerifiedBuild`=46549 WHERE `entry`=113892;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `VerifiedBuild`=46549 WHERE `entry`=112871;
UPDATE `creature_template` SET `VerifiedBuild`=46549 WHERE `entry`=107768;
UPDATE `creature_template` SET `VerifiedBuild`=46549 WHERE `entry`=93725; -- Slithering Brownscale
UPDATE `creature_template` SET `VerifiedBuild`=46549 WHERE `entry`=64352; -- Rapana Whelk

UPDATE `creature_questitem` SET `VerifiedBuild`=46549 WHERE (`CreatureEntry`=101554 AND `Idx` IN (2,1,0));

DELETE FROM `creature_queststarter` WHERE (`id`=91419 AND `quest` IN (37657,37654));
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(91419, 37657, 46549), -- Making the World Safe for Profit offered Mr. Shackle
(91419, 37654, 46549); -- Maritime Law offered Mr. Shackle

UPDATE `quest_poi_points` SET `VerifiedBuild`=46549 WHERE (`QuestID`=37657 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=37657 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=37657 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=37657 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=37657 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=37657 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=37657 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=37657 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=37657 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=37657 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=37657 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=37657 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=37657 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=37657 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=37654 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=37654 AND `Idx1`=0 AND `Idx2`=0);

UPDATE `quest_details` SET `VerifiedBuild`=46549 WHERE `ID` IN (37657, 37654);

DELETE FROM `smart_scripts` WHERE `entryorguid`=112866 AND `source_type`=0 AND `id`=0 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(112866, 0, 0, 0, 1, 0, 100, 0, 5000, 7000, 5000, 7000, 0, '', 5, 1, 5, 6, 11, 25, 273, 274, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'OOC Every 5s to 7s - Play Random Emote - to self');

DELETE FROM `smart_scripts` WHERE `entryorguid`=113892 AND `source_type`=0 AND `id`=0 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(113892, 0, 0, 0, 1, 0, 100, 0, 5000, 7000, 5000, 7000, 0, '', 5, 1, 5, 6, 11, 25, 273, 274, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'OOC Every 5s to 7s - Play Random Emote - to self');

DELETE FROM `smart_scripts` WHERE `entryorguid`=112871 AND `source_type`=0 AND `id`=0 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(112871, 0, 0, 0, 1, 0, 100, 0, 5000, 7000, 5000, 7000, 0, '', 5, 1, 5, 6, 11, 25, 273, 274, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'OOC Every 5s to 7s - Play Random Emote - to self');

DELETE FROM `smart_scripts` WHERE `entryorguid`=91419 AND `source_type`=0 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(91419, 0, 0, 0, 19, 0, 100, 0, 37657, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Mr. Shackle - on quest 37657 accepted - Say text 0'),
(91419, 0, 1, 0, 10, 0, 100, 0, 1, 40, 180000, 300000, 1, '', 1, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Mr. Shackle - On LoS with Player Near - Say text 1');
