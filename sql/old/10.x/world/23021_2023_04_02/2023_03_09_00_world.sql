SET @CGUID := 9003482;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+25;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 188004, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 299.142364501953125, -1015.0103759765625, 870.8427734375, 5.912754535675048828, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Azure Retainer (Area: The Seat of the Aspects - Difficulty: 0) (Auras: 383207 - Conversation Aura: Talk/Exclamation [DNT])
(@CGUID+1, 193284, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 292.1788330078125, -1138.220458984375, 911.3271484375, 3.32702183723449707, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 48317), -- Emerald Citizen (Area: The Seat of the Aspects - Difficulty: 0)
(@CGUID+2, 193285, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 301.743072509765625, -1014.30902099609375, 870.84033203125, 3.802387952804565429, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Bronze Citizen (Area: The Seat of the Aspects - Difficulty: 0)
(@CGUID+3, 193285, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 289.2725830078125, -1138.765625, 911.3271484375, 0.185429111123085021, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Bronze Citizen (Area: The Seat of the Aspects - Difficulty: 0) (Auras: 383207 - Conversation Aura: Talk/Exclamation [DNT])
(@CGUID+4, 197794, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 335.314239501953125, -1010.23089599609375, 963.03057861328125, 4.060590744018554687, 120, 0, 0, 1129190, 0, 0, 0, 0, 0, 48317), -- Emerald Dragon (Area: The Seat of the Aspects - Difficulty: 0)
(@CGUID+5, 188007, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 316.244781494140625, -1000.44622802734375, 870.8345947265625, 0.538431107997894287, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Azure Scholar (Area: The Seat of the Aspects - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+6, 188008, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 283.44097900390625, -1092.560791015625, 875.055908203125, 3.933995962142944335, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Blue Whelp (Area: The Seat of the Aspects - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+7, 193284, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 292.951385498046875, -1012.911376953125, 911.80511474609375, 4.165384292602539062, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 48317), -- Emerald Citizen (Area: The Seat of the Aspects - Difficulty: 0)
(@CGUID+8, 193284, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 194.685760498046875, -1010.61798095703125, 870.7139892578125, 2.971033096313476562, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 48317), -- Emerald Citizen (Area: The Seat of the Aspects - Difficulty: 0)
(@CGUID+9, 193285, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 291.052093505859375, -1015.18231201171875, 911.78472900390625, 0.874281525611877441, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Bronze Citizen (Area: The Seat of the Aspects - Difficulty: 0) (Auras: 383207 - Conversation Aura: Talk/Exclamation [DNT])
(@CGUID+10, 197242, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 317.645843505859375, -999.609375, 870.861328125, 3.561002254486083984, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Asahina (Area: The Seat of the Aspects - Difficulty: 0) (Auras: 383207 - Conversation Aura: Talk/Exclamation [DNT]) (possible waypoints or random movement)
(@CGUID+11, 193284, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 252.279510498046875, -1107.7847900390625, 870.82861328125, 6.151369571685791015, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 48317), -- Emerald Citizen (Area: The Seat of the Aspects - Difficulty: 0)
(@CGUID+12, 197806, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 272.958343505859375, -1000.19268798828125, 913.1767578125, 3.933995962142944335, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Bronze Whelp (Area: The Seat of the Aspects - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+13, 193285, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 207.138885498046875, -1080.5069580078125, 911.743896484375, 5.011152267456054687, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Bronze Citizen (Area: The Seat of the Aspects - Difficulty: 0) (Auras: 383207 - Conversation Aura: Talk/Exclamation [DNT])
(@CGUID+14, 193285, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 256.7413330078125, -1108.4444580078125, 870.818115234375, 2.977940320968627929, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Bronze Citizen (Area: The Seat of the Aspects - Difficulty: 0)
(@CGUID+15, 193283, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 254.892364501953125, -1105.73095703125, 870.8192138671875, 4.609187126159667968, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 48317), -- Ruby Citizen (Area: The Seat of the Aspects - Difficulty: 0)
(@CGUID+16, 193284, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 208.0104217529296875, -1083.3367919921875, 911.743896484375, 2.018648862838745117, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 48317), -- Emerald Citizen (Area: The Seat of the Aspects - Difficulty: 0)
(@CGUID+17, 195331, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 333.638885498046875, -1095.41845703125, 1020.56109619140625, 2.569890737533569335, 120, 0, 0, 1129190, 0, 0, 0, 0, 0, 48317), -- Ruby Dragon (Area: The Seat of the Aspects - Difficulty: 0) (Auras: 371171 - Cosmetic - Sleep Zzz (With Aggro Change) - Head (Scale 4,  Down 1))
(@CGUID+18, 188008, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 260.67535400390625, -1066.3489990234375, 912.5587158203125, 1.446961402893066406, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Blue Whelp (Area: The Seat of the Aspects - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+19, 188004, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 228.3697967529296875, -1006.6754150390625, 870.7138671875, 5.631715774536132812, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Azure Retainer (Area: The Seat of the Aspects - Difficulty: 0) (Auras: 383207 - Conversation Aura: Talk/Exclamation [DNT])
(@CGUID+20, 193285, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 191.876739501953125, -1009.6875, 870.7139892578125, 5.963313579559326171, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Bronze Citizen (Area: The Seat of the Aspects - Difficulty: 0) (Auras: 383207 - Conversation Aura: Talk/Exclamation [DNT])
(@CGUID+21, 193285, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 230.7239532470703125, -1008.47052001953125, 870.7138671875, 2.641051054000854492, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Bronze Citizen (Area: The Seat of the Aspects - Difficulty: 0)
(@CGUID+22, 197806, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 246.7413177490234375, -1122.0382080078125, 963.03057861328125, 1.803510308265686035, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Bronze Whelp (Area: The Seat of the Aspects - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+23, 188008, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 260.151031494140625, -1132.7222900390625, 963.03057861328125, 1.569526553153991699, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Blue Whelp (Area: The Seat of the Aspects - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+24, 188008, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 251.0225677490234375, -1121.69970703125, 963.03057861328125, 1.42327737808227539, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Blue Whelp (Area: The Seat of the Aspects - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+25, 197806, 2444, 13862, 14489, '0', 19586, 0, 0, 0, 246.7413177490234375, -1122.0382080078125, 963.03057861328125, 1.803510308265686035, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317); -- Bronze Whelp (Area: The Seat of the Aspects - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+25;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '383207'), -- Azure Retainer - 383207 - Conversation Aura: Talk/Exclamation [DNT]
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '383207'), -- Bronze Citizen - 383207 - Conversation Aura: Talk/Exclamation [DNT]
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 455, 0, 0, 0, 0, ''), -- Emerald Dragon
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Blue Whelp - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '383207'), -- Bronze Citizen - 383207 - Conversation Aura: Talk/Exclamation [DNT]
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '383207'), -- Asahina - 383207 - Conversation Aura: Talk/Exclamation [DNT]
(@CGUID+12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Bronze Whelp - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+13, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '383207'), -- Bronze Citizen - 383207 - Conversation Aura: Talk/Exclamation [DNT]
(@CGUID+17, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371171'), -- Ruby Dragon - 371171 - Cosmetic - Sleep Zzz (With Aggro Change) - Head (Scale 4,  Down 1)
(@CGUID+18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Blue Whelp - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+19, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '383207'), -- Azure Retainer - 383207 - Conversation Aura: Talk/Exclamation [DNT]
(@CGUID+20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '383207'), -- Bronze Citizen - 383207 - Conversation Aura: Talk/Exclamation [DNT]
(@CGUID+25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Bronze Whelp - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Blue Whelp - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+24, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'); -- Blue Whelp - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath

-- Creature Template
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=197806; -- Bronze Whelp
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `VehicleId`=7769 WHERE `entry`=188056; -- Azure Retainer
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=2007, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=197242; -- Asahina
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=188004; -- Azure Retainer
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=197805; -- Red Whelp
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=197804; -- Green Whelp
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=193283; -- Ruby Citizen
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=193285; -- Bronze Citizen
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=193284; -- Emerald Citizen
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry` IN (197803, 188008); -- Blue Whelp
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048, `HoverHeight`=10 WHERE `entry`=195331; -- Ruby Dragon
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=188007; -- Azure Scholar
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048, `HoverHeight`=10 WHERE `entry`=197794; -- Emerald Dragon

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`Entry`=198480 AND `DifficultyID`=0);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(198480, 0, 0, 0, 371, 48317);

-- Phasing
DELETE FROM `phase_name` WHERE `ID` = 19586;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(19586, 'Cosmetic - See Citizen in Seat of Aspects');

DELETE FROM `phase_area` WHERE `PhaseId` = 19586;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(13862, 19586, 'Cosmetic - See Citizen in Seat of Aspects');

-- Update missing ActionPOI
UPDATE `gossip_menu_option` SET `ActionPoiID` = 7280 WHERE `GossipOptionID` = 107215;
UPDATE `gossip_menu_option` SET `ActionPoiID` = 7039 WHERE `GossipOptionID` = 107214;
UPDATE `gossip_menu_option` SET `ActionPoiID` = 7042 WHERE `GossipOptionID` = 107213;

 -- Scalesworn Guardian smart ai
SET @ENTRY := 184168;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 62, 0, 100, 0, 29893, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action (0) from menu 29893 selected - Close Gossip - to self'),
(@ENTRY, 0, 1, 0, 62, 0, 100, 0, 29893, 1, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action (1) from menu 29893 selected - Close Gossip - to self'),
(@ENTRY, 0, 2, 0, 62, 0, 100, 0, 29893, 2, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action (2) from menu 29893 selected - Close Gossip - to self');

-- Waypoints for CGUID+10
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+10;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+10, @CGUID+10, 0, 0, 515, 0, 0),
(@CGUID+10, @CGUID+5, 2, 270, 515, 0, 0);

SET @PATH := (@CGUID+10) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 320.8536, -1008.05, 870.7996, NULL, 0),
(@PATH, 1, 320.7056, -1005.8, 870.8259, NULL, 0),
(@PATH, 2, 320.5751, -1003.814, 870.8499, NULL, 0),
(@PATH, 3, 316.2448, -1000.446, 870.8346, NULL, 21847),
(@PATH, 4, 314.4317, -999.0656, 870.8504, NULL, 0),
(@PATH, 5, 312.4535, -997.8751, 870.911, NULL, 0),
(@PATH, 6, 310.4778, -996.3765, 870.7982, NULL, 0),
(@PATH, 7, 308.6677, -994.9864, 870.863, NULL, 0),
(@PATH, 8, 306.8524, -993.6491, 870.8934, NULL, 0),
(@PATH, 9, 304.9613, -992.2668, 870.8914, NULL, 0),
(@PATH, 10, 303.1097, -990.9135, 870.808, NULL, 0),
(@PATH, 11, 301.315, -989.6017, 870.9321, NULL, 0),
(@PATH, 12, 299.373, -988.1823, 870.9103, NULL, 0),
(@PATH, 13, 297.3543, -986.7068, 870.9136, NULL, 0),
(@PATH, 14, 295.532, -985.6908, 870.9233, NULL, 0),
(@PATH, 15, 293.356, -984.6412, 870.9385, NULL, 0),
(@PATH, 16, 291.273, -983.6365, 870.9391, NULL, 0),
(@PATH, 17, 289.0369, -982.5581, 871.0032, NULL, 0),
(@PATH, 18, 286.8515, -981.5038, 870.9239, NULL, 0),
(@PATH, 19, 284.7703, -981.0396, 870.9044, NULL, 0),
(@PATH, 20, 282.4583, -980.6299, 870.8846, NULL, 0),
(@PATH, 21, 279.9607, -980.1873, 870.8633, NULL, 0),
(@PATH, 22, 278.9286, -980.0005, 870.8544, NULL, 0),
(@PATH, 23, 277.5443, -981.7516, 870.8801, NULL, 0),
(@PATH, 24, 276.1358, -983.5332, 870.9063, NULL, 0),
(@PATH, 25, 274.7261, -985.3163, 870.9324, NULL, 0),
(@PATH, 26, 273.1626, -987.0409, 870.9505, NULL, 0),
(@PATH, 27, 271.4859, -988.7433, 870.8006, NULL, 0),
(@PATH, 28, 269.8763, -990.3716, 870.8006, NULL, 0),
(@PATH, 29, 268.6969, -992.0905, 870.8006, NULL, 0),
(@PATH, 30, 267.4616, -993.9965, 870.8006, NULL, 0),
(@PATH, 31, 266.2181, -995.9151, 870.7883, NULL, 0),
(@PATH, 32, 264.947, -997.8764, 870.7795, NULL, 0),
(@PATH, 33, 263.7159, -999.7761, 870.7709, NULL, 0),
(@PATH, 34, 262.4857, -1001.674, 870.8301, NULL, 0),
(@PATH, 35, 261.3768, -1003.589, 870.8007, NULL, 0),
(@PATH, 36, 260.2878, -1005.59, 870.8007, NULL, 0),
(@PATH, 37, 259.1951, -1007.598, 870.8007, NULL, 0),
(@PATH, 38, 258.6691, -1009.508, 871.0745, NULL, 0),
(@PATH, 39, 258.1748, -1011.719, 871.1912, NULL, 0),
(@PATH, 40, 257.6726, -1013.965, 870.8472, NULL, 0),
(@PATH, 41, 258.3412, -1015.395, 870.8987, NULL, 0),
(@PATH, 42, 259.27, -1017.429, 870.9711, NULL, 0),
(@PATH, 43, 260.3948, -1018.996, 870.9489, NULL, 0),
(@PATH, 44, 262.1199, -1020.542, 870.8977, NULL, 0),
(@PATH, 45, 263.824, -1022.07, 870.8792, NULL, 0),
(@PATH, 46, 265.5292, -1023.51, 870.8793, NULL, 0),
(@PATH, 47, 267.2972, -1024.959, 870.8631, NULL, 0),
(@PATH, 48, 269.0696, -1026.412, 870.9633, NULL, 0),
(@PATH, 49, 270.8391, -1027.862, 870.911, NULL, 0),
(@PATH, 50, 272.6759, -1028.946, 870.8795, NULL, 0),
(@PATH, 51, 274.6453, -1030.106, 870.8456, NULL, 0),
(@PATH, 52, 276.6465, -1031.295, 870.8112, NULL, 0),
(@PATH, 53, 278.705, -1032.679, 870.7807, NULL, 0),
(@PATH, 54, 280.5935, -1033.948, 870.8006, NULL, 0),
(@PATH, 55, 282.3365, -1035.133, 870.7821, NULL, 0),
(@PATH, 56, 284.6162, -1035.971, 870.8187, NULL, 0),
(@PATH, 57, 286.8061, -1036.776, 870.8539, NULL, 0),
(@PATH, 58, 288.8116, -1037.486, 870.8861, NULL, 0),
(@PATH, 59, 291.0827, -1037.581, 870.8006, NULL, 0),
(@PATH, 60, 293.3204, -1037.674, 871.1913, NULL, 0),
(@PATH, 61, 295.0591, -1037.261, 870.975, NULL, 0),
(@PATH, 62, 297.2878, -1036.028, 870.8293, NULL, 0),
(@PATH, 63, 299.2704, -1034.889, 870.8491, NULL, 0),
(@PATH, 64, 301.1544, -1033.754, 870.9637, NULL, 0),
(@PATH, 65, 302.9082, -1032.096, 870.8781, NULL, 0),
(@PATH, 66, 304.5883, -1030.508, 870.9403, NULL, 0),
(@PATH, 67, 306.5566, -1028.595, 870.9609, NULL, 0),
(@PATH, 68, 308.2429, -1026.902, 870.9374, NULL, 0),
(@PATH, 69, 310.2072, -1024.858, 870.909, NULL, 0),
(@PATH, 70, 311.8018, -1022.919, 870.8826, NULL, 0),
(@PATH, 71, 313.3019, -1021.095, 870.8578, NULL, 0),
(@PATH, 72, 314.7801, -1019.297, 870.8333, NULL, 0),
(@PATH, 73, 316.1978, -1017.551, 870.8095, NULL, 0),
(@PATH, 74, 317.6331, -1015.784, 870.7855, NULL, 0),
(@PATH, 75, 318.5754, -1014.078, 870.8185, NULL, 0),
(@PATH, 76, 319.4319, -1011.95, 870.8453, NULL, 0),
(@PATH, 77, 320.2841, -1009.833, 870.8198, NULL, 0);

UPDATE `creature` SET `position_x`= 320.8536, `position_y`= -1008.05, `position_z`= 870.7996, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+10;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+10;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+10, @PATH, 1);
