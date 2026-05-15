SET @CGUID := 11000720;

SET @NPCTEXTID := 610010;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+30;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 248902, 2694, 15355, 15928, '0', 26622, 0, 0, 1, 1281.767333984375, 926.07293701171875, 1332.53271484375, 5.504429340362548828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Har'mara Blossomsinger (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+1, 249173, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1255.6024169921875, 950.55206298828125, 1332.541748046875, 0.163528740406036376, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Har'alnorian Pilgrim (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+2, 245090, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1268.1285400390625, 943.05035400390625, 1332.669189453125, 4.229924201965332031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Hagar (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+3, 249173, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1258.6754150390625, 951.638916015625, 1332.541748046875, 3.329707145690917968, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Har'alnorian Pilgrim (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+4, 248818, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1266.34033203125, 943.09375, 1332.664794921875, 5.050043582916259765, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Ku'paal (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+5, 248817, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1277.4757080078125, 927.6805419921875, 1332.53271484375, 0.5752907395362854, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Ney'leia (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+6, 248900, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1281.0416259765625, 923.6961669921875, 1332.53271484375, 2.08398747444152832, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Har'mara Mycomancer (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+7, 248895, 2694, 15355, 15928, '0', 26622, 0, 0, 1, 1283.700927734375, 924.32867431640625, 1332.5875244140625, 2.632289648056030273, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Har'mara Sporeguard (Area: Har'mara - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+8, 248789, 2694, 15355, 15928, '0', 26622, 0, 0, 1, 1279.1822509765625, 929.1475830078125, 1332.53271484375, 3.702705860137939453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Hannan (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+9, 249173, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1246.9271240234375, 930.263916015625, 1332.541748046875, 0.334236830472946166, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Har'alnorian Pilgrim (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+10, 248901, 2694, 15355, 15928, '0', 26622, 0, 0, 1, 1254.7413330078125, 928.46356201171875, 1332.53271484375, 0.961435258388519287, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Har'mara Grove Protector (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+11, 248901, 2694, 15355, 15928, '0', 26622, 0, 0, 1, 1287.110107421875, 936.30035400390625, 1335.587646484375, 3.384865283966064453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Har'mara Grove Protector (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+12, 248910, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1247.9757080078125, 933.93927001953125, 1332.541748046875, 1.281082749366760253, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Har'mara Citizen (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+13, 248910, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1247.9271240234375, 935.81768798828125, 1332.541748046875, 4.418229103088378906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Har'mara Citizen (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+14, 248910, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1279.6302490234375, 948.86114501953125, 1332.541748046875, 5.048713207244873046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Har'mara Citizen (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+15, 248911, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1280.3507080078125, 946.79168701171875, 1332.541748046875, 1.786588549613952636, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Har'kuaian Pilgrim (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+16, 248901, 2694, 15355, 15928, '0', 26622, 0, 0, 1, 1255.3836669921875, 872.0069580078125, 1327.9986572265625, 4.233323097229003906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Har'mara Grove Protector (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+17, 248901, 2694, 15355, 15928, '0', 26622, 0, 0, 1, 1283.454833984375, 984.02606201171875, 1340.6011962890625, 0.584655463695526123, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Har'mara Grove Protector (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+18, 248902, 2694, 15355, 15928, '0', 26622, 0, 0, 1, 1269.09033203125, 965.44097900390625, 1332.53271484375, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Har'mara Blossomsinger (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+19, 248900, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1271.8836669921875, 985.15277099609375, 1340.6005859375, 4.216250896453857421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Har'mara Mycomancer (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+20, 248900, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1236.8004150390625, 954.94268798828125, 1335.625, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Har'mara Mycomancer (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+21, 251883, 2694, 15355, 15928, '0', 26622, 0, 0, 1, 1246.986083984375, 875.107666015625, 1328.0244140625, 5.050669193267822265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Grove Protector Madar (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+22, 248902, 2694, 15355, 15928, '0', 26622, 0, 0, 1, 1238.829833984375, 954.9757080078125, 1335.636962890625, 3.545102119445800781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Har'mara Blossomsinger (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+23, 248895, 2694, 15355, 15928, '0', 26622, 0, 0, 1, 1271.55908203125, 983.0382080078125, 1340.59912109375, 1.926427364349365234, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Har'mara Sporeguard (Area: Har'mara - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+24, 248895, 2694, 15355, 15928, '0', 26622, 0, 0, 1, 1271.4444580078125, 964.90625, 1332.53271484375, 2.899782896041870117, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Har'mara Sporeguard (Area: Har'mara - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+25, 248904, 2694, 15355, 15928, '0', 26622, 0, 0, 1, 1371.5069580078125, 915.796875, 1346.4896240234375, 1.779142379760742187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Har'mara Elder Root (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+26, 248902, 2694, 15355, 15928, '0', 26622, 0, 0, 1, 1372.6788330078125, 918.234375, 1346.4559326171875, 4.148610591888427734, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Har'mara Blossomsinger (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+27, 248905, 2694, 15355, 15928, '0', 26622, 0, 0, 1, 1219.4583740234375, 955.654541015625, 1338.2626953125, 4.400951385498046875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Har'mara Grovewarden (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+28, 248905, 2694, 15355, 15928, '0', 26622, 0, 0, 1, 1361.90625, 912.9930419921875, 1346.701416015625, 5.9857635498046875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Har'mara Grovewarden (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+29, 248905, 2694, 15355, 15928, '0', 26622, 0, 0, 1, 1355.3489990234375, 899.1336669921875, 1345.645263671875, 3.179465532302856445, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Har'mara Grovewarden (Area: Har'mara - Difficulty: 0) CreateObject1
(@CGUID+30, 248905, 2694, 15355, 15928, '0', 26622, 0, 0, 1, 1366.982666015625, 907.60589599609375, 1346.39990234375, 1.4651641845703125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838); -- Har'mara Grovewarden (Area: Har'mara - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+30;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Har'alnorian Pilgrim
(@CGUID+3, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Har'alnorian Pilgrim
(@CGUID+9, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Har'alnorian Pilgrim
(@CGUID+23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '18950'), -- Har'mara Sporeguard - 18950 - Invisibility and Stealth Detection
(@CGUID+24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Har'mara Sporeguard - 18950 - Invisibility and Stealth Detection

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (248789 /*248789 (Hannan)*/, 248895 /*248895 (Har'mara Sporeguard) - Invisibility and Stealth Detection*/, 249173 /*249173 (Har'alnorian Pilgrim)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(248789, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 248789 (Hannan)
(248895, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '18950'), -- 248895 (Har'mara Sporeguard) - Invisibility and Stealth Detection
(249173, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 249173 (Har'alnorian Pilgrim)

-- Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x4800 WHERE `entry`=245102; -- Dalnir

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=248789 AND `MenuID`=40070) OR (`CreatureID`=248817 AND `MenuID`=40071) OR (`CreatureID`=245090 AND `MenuID`=39757) OR (`CreatureID`=248818 AND `MenuID`=40069);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(248789, 40070, 66838), -- Hannan
(248817, 40071, 66838), -- Ney'leia
(245090, 39757, 66838), -- Hagar
(248818, 40069, 66838); -- Ku'paal

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+4;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 294583, 0, 0, 0, 0, 0, 0, 0, 66838), -- 248817 (Ney'leia)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 292811, 0, 0, 0, 0, 0, 0, 0, 66838), -- 245090 (Hagar)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 294577, 0, 0, 0, 0, 0, 0, 0, 66838), -- 248818 (Ku'paal)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 294582, 0, 0, 0, 0, 0, 0, 0, 66838), -- 248789 (Hannan)
(@NPCTEXTID+4, 1, 0, 0, 0, 0, 0, 0, 0, 294393, 0, 0, 0, 0, 0, 0, 0, 66838); -- 245090 (Hagar)

DELETE FROM `gossip_menu` WHERE (`MenuID`=40071 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=39757 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=40069 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=40070 AND `TextID`=@NPCTEXTID+3) OR (`MenuID`=40033 AND `TextID`=@NPCTEXTID+4);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(40071, @NPCTEXTID+0, 66838), -- 248817 (Ney'leia)
(39757, @NPCTEXTID+1, 66838), -- 245090 (Hagar)
(40069, @NPCTEXTID+2, 66838), -- 248818 (Ku'paal)
(40070, @NPCTEXTID+3, 66838), -- 248789 (Hannan)
(40033, @NPCTEXTID+4, 66838); -- 245090 (Hagar)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=39757 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(39757, 134936, 0, 0, 'What is this place?', 18411, 0, 0, 40033, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66838); -- OptionBroadcastTextID: 18411 - 39050 - 53647 - 60157 - 66591 - 94147 - 136659 - 208743

-- Quest
DELETE FROM `quest_details` WHERE `ID`=90957;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(90957, 1, 0, 0, 0, 0, 0, 0, 0, 66838); -- Initiation Day

DELETE FROM `creature_queststarter` WHERE (`id`=245090 AND `quest`=90957);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(245090, 90957, 66838); -- Initiation Day offered by Hagar

-- Path for Harmara Grove Protector
SET @MOVERGUID := @CGUID+11;
SET @ENTRY := 248901;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Har''mara Grove Protector - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1288.4462, 936.63196, 1335.5876, NULL, 0),
(@PATH, 1, 1291.7274, 937.80206, 1335.5875, NULL, 0),
(@PATH, 2, 1289.1292, 944.98865, 1335.4019, NULL, 0),
(@PATH, 3, 1287.1354, 953.3073, 1338.2437, NULL, 0),
(@PATH, 4, 1279.9271, 959.5764, 1342.2869, NULL, 5371),
(@PATH, 5, 1287.1354, 953.3073, 1338.2437, NULL, 0),
(@PATH, 6, 1289.0817, 945.1198, 1335.4164, NULL, 0),
(@PATH, 7, 1291.7274, 937.80206, 1335.5875, NULL, 0),
(@PATH, 8, 1288.4462, 936.63196, 1335.5876, NULL, 0),
(@PATH, 9, 1279.1841, 934.3333, 1332.5875, NULL, 5407);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '18950');
