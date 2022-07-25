SET @CGUID := 1050893;

DELETE FROM `phase_name` WHERE `ID` IN(17864, 18027, 18000, 18020, 17994, 18018, 18021, 18022);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(17864, 'Talking NPCs in Crowd in Oribos, Secret of the First Ones Chapter 8 / Sylvanas Judgment (A Long Walk: 65260)'),
(18027, 'Uther and Sylvanas in Oribos, Secret of the First Ones Chapter 8 / Sylvanas Judgment (Prisoner of Interest: 65250)'),
(18000, 'Uther and Sylvanas in Oribos walking to Enclave, Secret of the First Ones Chapter 8 / Sylvanas Judgment (A Long Walk: 65260)'),
(18020, 'Guards and Covenant Leaders at The Crucible in Oribos, Secret of the First Ones Chapter 8 / Sylvanas Judgment (The Fate of Sylvanas: 65263)'),
(17994, 'Several named NPCs (Sylvanas, Tyrande, Lilian Voss, ...) at The Crucible in Oribos, Secret of the First Ones Chapter 8 / Sylvanas Judgment (The Fate of Sylvanas: 65263)'),
(18018, 'Crowd (Tyrande, Alleria, Maiev, ...) at Ring of Transference, Secret of the First Ones Chapter 8 / Sylvanas Judgment (Penance and Renewal: 65297)'),
(18021, 'Sylvanas, Dori''thur at Ring of Transference, Secret of the First Ones Chapter 8 / Sylvanas Judgment (Penance and Renewal: 65297)'),
(18022, 'Post Sylvanas Judgment Spawns, Secret of the First Ones Chapter 8 / Sylvanas Judgment (after Penance and Renewal: 65297)');

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+26;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 183857, 2222, 10565, 13498, '0', 18018, 0, 0, 0, -1867.0850830078125, 1246.60595703125, 5446.439453125, 4.503840923309326171, 7200, 0, 0, 35864400, 2434, 0, 0, 0, 0, 42979), -- Tyrande Whisperwind (Area: -Unknown- - Difficulty: 0)
(@CGUID+1, 183822, 2222, 10565, 13498, '0', 18018, 0, 0, 0, -1876.484375, 1246.71875, 5445.7958984375, 5.507326126098632812, 7200, 0, 0, 298870, 2434, 0, 0, 0, 0, 42979), -- Uther (Area: -Unknown- - Difficulty: 0)
(@CGUID+2, 184100, 2222, 10565, 13498, '0', 18018, 0, 0, 1, -1871.5885009765625, 1231.2430419921875, 5445.7783203125, 1.426334261894226074, 7200, 0, 0, 7471750, 73020, 0, 0, 0, 0, 42979), -- Lor'themar Theron (Area: -Unknown- - Difficulty: 0)
(@CGUID+3, 184145, 2222, 10565, 13498, '0', 18021, 0, 0, 0, -1864.9739990234375, 1247.0364990234375, 5447.7685546875, 4.195971965789794921, 7200, 0, 0, 298870, 0, 0, 0, 0, 0, 42979), -- Dori'thur (Area: -Unknown- - Difficulty: 0)
(@CGUID+4, 184097, 2222, 10565, 13498, '0', 18018, 0, 0, 1, -1868.2535400390625, 1238.4375, 5445.79052734375, 1.206194162368774414, 7200, 0, 0, 448305, 2434, 0, 0, 0, 0, 42979), -- Vereesa Windrunner (Area: -Unknown- - Difficulty: 0)
(@CGUID+5, 184096, 2222, 10565, 13498, '0', 18018, 0, 0, 1, -1869.52783203125, 1238.8992919921875, 5445.79296875, 0.562227368354797363, 7200, 0, 0, 2988700, 1500, 0, 0, 0, 0, 42979), -- Alleria Windrunner (Area: -Unknown- - Difficulty: 0)
(@CGUID+6, 184099, 2222, 10565, 13498, '0', 18018, 0, 0, 1, -1874.59033203125, 1234.0885009765625, 5445.79296875, 0.678687453269958496, 7200, 0, 0, 1494350, 0, 0, 0, 0, 0, 42979), -- Thrall (Area: -Unknown- - Difficulty: 0)
(@CGUID+7, 183826, 2222, 10565, 13498, '0', 18021, 0, 0, 0, -1867.9305419921875, 1240.8021240234375, 5445.79296875, 4.196069717407226562, 7200, 0, 0, 29887, 0, 0, 0, 0, 0, 42979), -- Sylvanas Windrunner (Area: -Unknown- - Difficulty: 0)
(@CGUID+8, 184098, 2222, 10565, 13498, '0', 18018, 0, 0, 0, -1873.9097900390625, 1230.5850830078125, 5445.79052734375, 1.077165603637695312, 7200, 0, 0, 14943500, 0, 0, 0, 0, 0, 42979), -- Baine Bloodhoof (Area: -Unknown- - Difficulty: 0)
(@CGUID+9, 184052, 2222, 10565, 13498, '0', 18018, 0, 0, 0, -1865.1475830078125, 1229.2413330078125, 5445.86083984375, 1.752820730209350585, 7200, 0, 0, 896610, 0, 0, 0, 0, 0, 42979), -- Anduin Wrynn (Area: -Unknown- - Difficulty: 0)
(@CGUID+10, 184094, 2222, 10565, 13498, '0', 18018, 0, 0, 1, -1879.6510009765625, 1242.142333984375, 5445.875, 6.01679229736328125, 7200, 0, 0, 35864400, 608500, 0, 0, 0, 0, 42979), -- Highlord Bolvar Fordragon (Area: -Unknown- - Difficulty: 0)
(@CGUID+11, 184971, 2222, 10565, 13498, '0', 18018, 0, 0, 0, -1880.54345703125, 1245.7847900390625, 5445.8798828125, 5.757637977600097656, 7200, 0, 0, 29887, 0, 0, 0, 0, 0, 42979), -- Tal-Inara (Area: -Unknown- - Difficulty: 0)
(@CGUID+12, 184053, 2222, 10565, 13498, '0', 18018, 0, 0, 1, -1863.4791259765625, 1230.060791015625, 5445.85546875, 1.71511244773864746, 7200, 0, 0, 1195450, 6156, 0, 0, 0, 0, 42979), -- Lady Jaina Proudmoore (Area: -Unknown- - Difficulty: 0)
(@CGUID+13, 184088, 2222, 10565, 13498, '0', 18018, 0, 0, 0, -1866.73095703125, 1230.092041015625, 5445.8349609375, 1.543265581130981445, 7200, 0, 0, 14943500, 121700, 0, 0, 0, 0, 42979), -- Genn Greymane (Area: -Unknown- - Difficulty: 0)
(@CGUID+14, 184089, 2222, 10565, 13498, '0', 18018, 0, 0, 1, -1863.8629150390625, 1243.7430419921875, 5446.27490234375, 3.84290313720703125, 7200, 0, 0, 298870, 2434, 0, 0, 0, 0, 42979), -- Shandris Feathermoon (Area: -Unknown- - Difficulty: 0)
(@CGUID+15, 184090, 2222, 10565, 13498, '0', 18018, 0, 0, 1, -1870.32470703125, 1247.765625, 5446.52099609375, 4.692803382873535156, 7200, 0, 0, 7471750, 2434, 0, 0, 0, 0, 42979), -- Maiev Shadowsong (Area: -Unknown- - Difficulty: 0)
(@CGUID+16, 184096, 2222, 10565, 13498, '0', 18022, 0, 0, 1, -1869.611083984375, 1238.9305419921875, 5445.79296875, 0.639856398105621337, 7200, 0, 0, 2988700, 1500, 0, 0, 0, 0, 42979), -- Alleria Windrunner (Area: -Unknown- - Difficulty: 0)
(@CGUID+17, 184097, 2222, 10565, 13498, '0', 18022, 0, 0, 1, -1868.217041015625, 1238.439208984375, 5445.79052734375, 1.148086071014404296, 7200, 0, 0, 448305, 2434, 0, 0, 0, 0, 42979), -- Vereesa Windrunner (Area: -Unknown- - Difficulty: 0) (Auras: 366648 - -Unknown-)
(@CGUID+18, 184117, 2222, 10565, 13498, '0', 18022, 0, 0, 1, -1758.21875, 1317.6788330078125, 5445.76513671875, 5.125608444213867187, 7200, 0, 0, 298870, 60850, 0, 0, 0, 0, 42979), -- Highlord Darion Mograine (Area: -Unknown- - Difficulty: 0)
(@CGUID+19, 184094, 2222, 10565, 13498, '0', 18022, 0, 0, 1, -1756.5625, 1314.7725830078125, 5445.79150390625, 2.127844810485839843, 7200, 0, 0, 35864400, 608500, 0, 0, 0, 0, 42979), -- Highlord Bolvar Fordragon (Area: -Unknown- - Difficulty: 0) (Auras: 367011 - -Unknown-)
(@CGUID+20, 184584, 2222, 10565, 13498, '0', 18022, 0, 0, 1, -1841.482666015625, 1341.8055419921875, 5968.01171875, 5.249414443969726562, 120, 0, 0, 29887, 0, 0, 0, 0, 0, 42979), -- Kleia (Area: Ring of Transference - Difficulty: 0)
(@CGUID+21, 184098, 2222, 10565, 13499, '0', 18022, 0, 0, 0, -1817.0833740234375, 1370.2535400390625, 5963.3935546875, 6.106781959533691406, 120, 0, 0, 14943500, 0, 0, 0, 0, 0, 42979), -- Baine Bloodhoof (Area: Ring of Fates - Difficulty: 0) (Auras: 366954 - RP Chat Bubble on Baine)
(@CGUID+22, 184088, 2222, 10565, 13499, '0', 18022, 0, 0, 0, -1810.984375, 1350.7413330078125, 5963.36328125, 4.050899028778076171, 120, 0, 0, 14943500, 121700, 0, 0, 0, 0, 42979), -- Genn Greymane (Area: Ring of Fates - Difficulty: 0) (Auras: 366928 - RP Chat Bubble on Greymane)
(@CGUID+23, 184100, 2222, 10565, 13499, '0', 18022, 0, 0, 1, -1816.4791259765625, 1366.9461669921875, 5963.3935546875, 1.085948109626770019, 120, 0, 0, 7471750, 73020, 0, 0, 0, 0, 42979), -- Lor'themar Theron (Area: Ring of Fates - Difficulty: 0) (Auras: 366934 - RP Chat Bubble on Lor'themar)
(@CGUID+24, 183830, 2222, 10565, 13498, '0', 18022, 0, 0, 0, -1833.8958740234375, 1327.98095703125, 5964.43701171875, 1.541750788688659667, 120, 0, 0, 14943500, 0, 0, 0, 0, 0, 42979), -- Arbiter Pelagos (Area: Ring of Transference - Difficulty: 0) (Auras: 366959 - RP Chat Bubble on Pelagos)
(@CGUID+25, 184052, 2222, 10565, 13499, '0', 18022, 0, 0, 0, -1819.2430419921875, 1342.7135009765625, 5963.3935546875, 5.517285346984863281, 120, 0, 0, 896610, 0, 0, 0, 0, 0, 42979), -- Anduin Wrynn (Area: Ring of Fates - Difficulty: 0)
(@CGUID+26, 183720, 2222, 10565, 10565, '0', 18022, 0, 0, 0, -1827.16845703125, 1350.0625, 5963.39306640625, 4.318914413452148437, 120, 0, 0, 29887, 0, 0, 0, 0, 0, 42979); -- Tal-Inara (Area: Oribos - Difficulty: 0)

-- Creature Addon
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+26;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+17, 0, 0, 0, 1, 0, 0, 0, 0, 0, '366648'), -- Vereesa Windrunner - 366648 - -Unknown-
(@CGUID+19, 0, 0, 0, 0, 0, 0, 0, 0, 0, '367011'), -- Highlord Bolvar Fordragon - 367011 - -Unknown-
(@CGUID+20, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- Kleia
(@CGUID+21, 0, 0, 0, 1, 0, 0, 0, 0, 0, '366954'), -- Baine Bloodhoof - 366954 - RP Chat Bubble on Baine
(@CGUID+22, 0, 0, 0, 0, 0, 0, 0, 0, 0, '366928'), -- Genn Greymane - 366928 - RP Chat Bubble on Greymane
(@CGUID+23, 0, 0, 0, 0, 0, 0, 0, 0, 0, '366934'), -- Lor'themar Theron - 366934 - RP Chat Bubble on Lor'themar
(@CGUID+24, 0, 0, 0, 1, 0, 0, 0, 0, 3, '366959'), -- Arbiter Pelagos - 366959 - RP Chat Bubble on Pelagos
(@CGUID+26, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''); -- Tal-Inara

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (184098, 183822, 184097, 184090, 183857, 184089, 184053, 184094, 184099, 184088, 184100, 184117);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(184098, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 184098 (Baine Bloodhoof)
(183822, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 183822 (Uther)
(184090, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 184090 (Maiev Shadowsong)
(183857, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 183857 (Tyrande Whisperwind)
(184089, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 184089 (Shandris Feathermoon)
(184053, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 184053 (Lady Jaina Proudmoore)
(184094, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 184094 (Highlord Bolvar Fordragon)
(184099, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 184099 (Thrall)
(184088, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 184088 (Genn Greymane)
(184100, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 184100 (Lor'themar Theron)
(184117, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- 184117 (Highlord Darion Mograine)

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (184089,184053,184094,184099,184096,184097,184090,184100,184117,184584));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(184089, 1, 45078, 0, 0, 0, 0, 0, 55048, 0, 0, 42979), -- Shandris Feathermoon
(184053, 1, 153575, 0, 0, 0, 0, 0, 0, 0, 0, 42979), -- Lady Jaina Proudmoore
(184094, 1, 177838, 0, 0, 0, 0, 0, 0, 0, 0, 42979), -- Highlord Bolvar Fordragon
(184099, 1, 168268, 0, 0, 0, 0, 0, 0, 0, 0, 42979), -- Thrall
(184096, 1, 0, 0, 0, 0, 0, 0, 151781, 0, 0, 42979), -- Alleria Windrunner
(184097, 1, 0, 0, 0, 0, 0, 0, 42140, 0, 0, 42979), -- Vereesa Windrunner
(184090, 1, 32425, 0, 0, 0, 0, 0, 32740, 0, 0, 42979), -- Maiev Shadowsong
(184100, 1, 168606, 0, 0, 0, 0, 0, 0, 0, 0, 42979), -- Lor'themar Theron
(184117, 1, 40276, 0, 0, 40276, 0, 0, 0, 0, 0, 42979), -- Highlord Darion Mograine
(184584, 1, 171132, 0, 0, 0, 0, 0, 0, 0, 0, 42979); -- Kleia

-- Creature Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (184098,182864,183826,184089,184053,184094,184052,184128,183830,184099,184096,184097,184090,184088,184145,184971,184100,183822,185576,183857,184117));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(184098, 0, 0, 0, 2057, 42979),
(182864, 0, 0, 0, 783, 42979),
(183826, 0, 0, 0, 2057, 42979),
(184089, 0, 0, 0, 2057, 42979),
(184053, 0, 3, 3, 2057, 42979),
(184094, 0, 0, 0, 2057, 42979),
(184052, 0, 0, 0, 2057, 42979),
(184128, 0, 0, 0, 2057, 42979),
(183830, 0, 3, 3, 2057, 42979),
(184099, 0, 3, 3, 2057, 42979),
(184096, 0, 0, 0, 2057, 42979),
(184097, 0, 0, 0, 2057, 42979),
(184090, 0, 0, 0, 2057, 42979),
(184088, 0, 0, 0, 2057, 42979),
(184145, 0, 0, 0, 2057, 42979),
(184971, 0, 0, 0, 2057, 42979),
(184100, 0, 0, 0, 2057, 42979),
(183822, 0, 0, 0, 2057, 42979),
(185576, 0, 0, 0, 709, 42979),
(183857, 0, 0, 0, 2057, 42979),
(184117, 0, 0, 0, 2057, 42979);

-- Creature Model Info
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (104785, 102134, 104817, 105302, 104789, 104820, 104963, 90230, 105509, 96510, 105361, 101941, 104815);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(104785, 1.888888955116271972, 2, 0, 42979),
(102134, 0.580414056777954101, 1.25, 0, 42979),
(104817, 0.435065627098083496, 0, 0, 42979),
(105302, 0.498761951923370361, 0, 0, 42979),
(104789, 2.754532814025878906, 21, 0, 42979),
(104820, 0.665421724319458007, 1, 0, 42979),
(104963, 0.430167853832244873, 0, 0, 42979),
(90230, 2.269287347793579101, 0, 0, 42979),
(105509, 0.886238932609558105, 0.75, 0, 42979),
(96510, 2.833333492279052734, 3, 0, 42979),
(105361, 1.446130156517028808, 1.80000007152557373, 0, 42979),
(101941, 0.490392029285430908, 1.25, 0, 42979),
(104815, 1.050356507301330566, 0.899999976158142089, 0, 42979);

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN(184145, 184584, 183830);
INSERT INTO `creature_template_movement` (`CreatureId`, `Flight`) VALUES
(184145, 1),
(184584, 1),
(183830, 1);
