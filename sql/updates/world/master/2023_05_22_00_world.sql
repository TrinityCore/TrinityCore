SET @CGUID := 9003871;

SET @NPCTEXTID := 590073;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+32;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 191150, 2444, 13644, 13722, '0', 0, 0, 0, 0, 3704.848876953125, -1833.888916015625, -0.03628153353929519, 6.230580329895019531, 7200, 0, 0, 35235, 0, 0, 0, 0, 0, 48317), -- 191150 (Area: 13722 - Difficulty: 0) (Auras: 375314 - 375314)
(@CGUID+1, 191161, 2444, 13644, 13722, '0', 0, 0, 0, 0, 3704.577392578125, -1830.84375, 0.076037533581256866, 0.246341869235038757, 7200, 0, 0, 35235, 0, 0, 0, 0, 0, 48317), -- 191161 (Area: 13722 - Difficulty: 0)
(@CGUID+2, 191148, 2444, 13644, 13722, '0', 0, 0, 0, 0, 3717.44873046875, -1828.5086669921875, 5.726345062255859375, 3.054856777191162109, 7200, 0, 0, 35235, 0, 0, 0, 0, 0, 48317), -- 191148 (Area: 13722 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+3, 194681, 2444, 13644, 13722, '0', 0, 0, 0, 0, 3700.950439453125, -1824.18408203125, 0.339223027229309082, 5.970033645629882812, 7200, 0, 0, 35235, 0, 0, 0, 0, 0, 48317), -- 194681 (Area: 13722 - Difficulty: 0) (Auras: 277936 - 277936)
(@CGUID+4, 187412, 2444, 13644, 13722, '0', 0, 0, 0, 0, 3675.540771484375, -1833.046875, 2.822750568389892578, 4.85208749771118164, 7200, 0, 0, 35235, 2568, 0, 0, 0, 0, 48317), -- 187412 (Area: 13722 - Difficulty: 0)
(@CGUID+5, 194671, 2444, 13644, 13722, '0', 0, 0, 0, 0, 3677.60791015625, -1842.7225341796875, 2.820841312408447265, 3.738029003143310546, 7200, 0, 0, 35235, 0, 1, 0, 0, 0, 48317), -- 194671 (Area: 13722 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+6, 197743, 2444, 13644, 13722, '0', 0, 0, 0, 0, 3666.02783203125, -1839.9739990234375, 2.915668964385986328, 0.203936353325843811, 7200, 0, 0, 35235, 0, 0, 0, 0, 0, 48317), -- 197743 (Area: 13722 - Difficulty: 0)
(@CGUID+7, 188904, 2444, 13644, 13722, '0', 0, 0, 0, 0, 3668.9765625, -1843.3629150390625, 3.0830841064453125, 4.445256233215332031, 7200, 0, 0, 35235, 100, 0, 0, 0, 0, 48317), -- 188904 (Area: 13722 - Difficulty: 0) (Auras: 122236 - 122236)
(@CGUID+8, 194652, 2444, 13644, 13722, '0', 0, 0, 0, 0, 3683.731689453125, -1886.9375, 8.81690216064453125, 1.452607393264770507, 7200, 0, 0, 35235, 0, 0, 0, 0, 0, 48317), -- 194652 (Area: 13722 - Difficulty: 0)
(@CGUID+9, 194650, 2444, 13644, 13722, '0', 0, 0, 0, 0, 3684.333251953125, -1883.890625, 10.01791954040527343, 2.49181675910949707, 7200, 0, 0, 880875, 0, 1, 0, 0, 0, 48317), -- 194650 (Area: 13722 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+10, 190575, 2444, 13644, 13722, '0', 0, 0, 0, 0, 3669.953125, -1903.751708984375, 7.7520751953125, 4.181522369384765625, 7200, 0, 0, 35235, 2568, 0, 0, 0, 0, 48317), -- 190575 (Area: 13722 - Difficulty: 0)
(@CGUID+11, 198146, 2444, 13644, 13722, '0', 0, 0, 0, 0, 3737.026123046875, -1899.529541015625, 5.977386951446533203, 6.083449363708496093, 7200, 0, 0, 35235, 0, 0, 0, 0, 0, 48317), -- 198146 (Area: 13722 - Difficulty: 0) (Auras: 381296 - 381296, 392623 - 392623)
(@CGUID+12, 194688, 2444, 13644, 13722, '0', 0, 0, 0, 0, 3704.90625, -1858.5625, 6.426148414611816406, 3.529885768890380859, 7200, 0, 0, 105705, 0, 0, 0, 0, 0, 48317), -- 194688 (Area: 13722 - Difficulty: 0)
(@CGUID+13, 194685, 2444, 13644, 13722, '0', 0, 0, 0, 1, 3704.717041015625, -1856.984375, 6.300654411315917968, 2.980614185333251953, 7200, 0, 0, 105705, 100, 0, 0, 0, 0, 48317), -- 194685 (Area: 13722 - Difficulty: 0)
(@CGUID+14, 188027, 2444, 13644, 13722, '0', 0, 0, 0, 0, 3725.5703125, -1821.7100830078125, 0.239273935556411743, 2.997308969497680664, 7200, 0, 0, 35235, 0, 0, 0, 0, 0, 48317), -- 188027 (Area: 13722 - Difficulty: 0) (Auras: 368927 - 368927)
(@CGUID+15, 188027, 2444, 13644, 13722, '0', 0, 0, 0, 0, 3729.012939453125, -1822.4791259765625, 0.199125260114669799, 0.541310906410217285, 7200, 0, 0, 35235, 0, 0, 0, 0, 0, 48317), -- 188027 (Area: 13722 - Difficulty: 0) (Auras: 368927 - 368927)
(@CGUID+16, 187135, 2444, 13644, 13722, '0', 0, 0, 0, 1, 3687.1796875, -1833.623291015625, 2.822757482528686523, 5.408229351043701171, 7200, 0, 0, 1693785, 3155, 0, 0, 0, 0, 48317), -- 187135 (Area: 13722 - Difficulty: 0) (Auras: )
(@CGUID+17, 187135, 2444, 13644, 13722, '0', 0, 0, 0, 1, 3667.2197265625, -1892.0625, 7.7370758056640625, 0.070526361465454101, 7200, 0, 0, 1693785, 3155, 0, 0, 0, 0, 48317), -- 187135 (Area: 13722 - Difficulty: 0) (Auras: )
(@CGUID+18, 187135, 2444, 13644, 13722, '0', 0, 0, 0, 1, 3657.91064453125, -1847.2379150390625, 9.516091346740722656, 5.940360069274902343, 7200, 0, 0, 1693785, 3155, 0, 0, 0, 0, 48317), -- 187135 (Area: 13722 - Difficulty: 0) (Auras: )
(@CGUID+19, 187135, 2444, 13644, 13722, '0', 0, 0, 0, 1, 3716.252685546875, -1888.0191650390625, 5.887425899505615234, 2.544367551803588867, 7200, 0, 0, 1693785, 3155, 0, 0, 0, 0, 48317), -- 187135 (Area: 13722 - Difficulty: 0) (Auras: )
(@CGUID+20, 187135, 2444, 13644, 13722, '0', 0, 0, 0, 1, 3713.296875, -1894.592041015625, 5.865893363952636718, 2.68091893196105957, 7200, 0, 0, 1693785, 3155, 0, 0, 0, 0, 48317), -- 187135 (Area: 13722 - Difficulty: 0) (Auras: )
(@CGUID+21, 187123, 2444, 13644, 13722, '0', 0, 0, 0, 1, 3638.692626953125, -1869.8524169921875, 9.409946441650390625, 3.028069496154785156, 7200, 0, 0, 1693785, 0, 0, 0, 0, 0, 48317), -- 187123 (Area: 13722 - Difficulty: 0) (Auras: )
(@CGUID+22, 187123, 2444, 13644, 13722, '0', 0, 0, 0, 1, 3635.709228515625, -1856.6163330078125, 10.02890205383300781, 3.666695594787597656, 7200, 0, 0, 1693785, 0, 0, 0, 0, 0, 48317), -- 187123 (Area: 13722 - Difficulty: 0) (Auras: )
(@CGUID+23, 194674, 2444, 13644, 13722, '0', 0, 0, 0, 0, 3712.377685546875, -1874.795166015625, 5.61551666259765625, 0.065184526145458221, 7200, 0, 0, 35235, 0, 1, 0, 0, 0, 48317), -- 194674 (Area: 13722 - Difficulty: 0) (Auras: 273097 - 273097) (possible waypoints or random movement)
(@CGUID+24, 194674, 2444, 13644, 13722, '0', 0, 0, 0, 0, 3682.014892578125, -1850, 3.888782024383544921, 4.247025966644287109, 7200, 0, 0, 35235, 0, 1, 0, 0, 0, 48317), -- 194674 (Area: 13722 - Difficulty: 0) (Auras: 244867 - 244867) (possible waypoints or random movement)
(@CGUID+25, 194674, 2444, 13644, 13722, '0', 0, 0, 0, 0, 3685.210205078125, -1865.462158203125, 5.593483924865722656, 5.095614910125732421, 7200, 0, 0, 35235, 0, 1, 0, 0, 0, 48317), -- 194674 (Area: 13722 - Difficulty: 0) (Auras: 273098 - 273098) (possible waypoints or random movement)
(@CGUID+26, 195830, 2444, 13644, 13722, '0', 0, 0, 0, 0, 3704.0390625, -1898.5711669921875, 5.476350307464599609, 5.430084228515625, 7200, 0, 0, 35235, 0, 0, 0, 0, 0, 48317), -- 195830 (Area: 13722 - Difficulty: 0) (Auras: 386797 - 386797)
(@CGUID+27, 195830, 2444, 13644, 13722, '0', 0, 0, 0, 0, 3711.509521484375, -1884.3125, 5.850404739379882812, 0.156756326556205749, 7200, 0, 0, 35235, 0, 0, 0, 0, 0, 48317), -- 195830 (Area: 13722 - Difficulty: 0) (Auras: 386797 - 386797)
(@CGUID+28, 195830, 2444, 13644, 13722, '0', 0, 0, 0, 0, 3707.462646484375, -1897.642333984375, 5.667359352111816406, 5.369266986846923828, 7200, 0, 0, 35235, 0, 0, 0, 0, 0, 48317), -- 195830 (Area: 13722 - Difficulty: 0) (Auras: 386797 - 386797)
(@CGUID+29, 195830, 2444, 13644, 13722, '0', 0, 0, 0, 0, 3712.395751953125, -1876.8194580078125, 5.654620170593261718, 0.207102850079536437, 7200, 0, 0, 35235, 0, 1, 0, 0, 0, 48317), -- 195830 (Area: 13722 - Difficulty: 0) (Auras: 386797 - 386797) (possible waypoints or random movement)
(@CGUID+30, 195830, 2444, 13644, 13722, '0', 0, 0, 0, 0, 3712.1962890625, -1881.798583984375, 5.858367443084716796, 5.644421577453613281, 7200, 0, 0, 35235, 0, 0, 0, 0, 0, 48317), -- 195830 (Area: 13722 - Difficulty: 0)
(@CGUID+31, 194668, 2444, 13644, 13722, '0', 0, 0, 0, 1, 3668.1259765625, -1888.541015625, 7.69602060317993164, 3.454401969909667968, 7200, 0, 0, 70470, 0, 0, 0, 0, 0, 48317), -- 194668 (Area: 13722 - Difficulty: 0)
(@CGUID+32, 194668, 2444, 13644, 13722, '0', 0, 0, 0, 0, 3666.6181640625, -1889.017333984375, 8.156268119812011718, 5.972821712493896484, 7200, 0, 0, 70470, 0, 0, 0, 0, 0, 48317); -- 194668 (Area: 13722 - Difficulty: 0)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+32;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- 188027 - 368927 - 368927
(@CGUID+15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- 188027 - 368927 - 368927
(@CGUID+26, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- 195830
(@CGUID+27, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- 195830
(@CGUID+28, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- 195830
(@CGUID+29, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- 195830
(@CGUID+30, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- 195830
(@CGUID+32, 0, 0, 0, 0, 0, 1, 0, 426, 0, 0, 0, 0, ''); -- 194668

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (194681,197743,188904,190575,194652,194650,198146,194685,191150,194688);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(194681, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '277936'), -- 194681 - 277936
(197743, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0, 0, ''), -- 197743
(188904, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '122236'), -- 188904 - 122236
(190575, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- 190575
(194652, 0, 0, 0, 0, 0, 1, 1, 483, 0, 0, 0, 0, ''), -- 194652
(194650, 0, 89712, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 194650
(198146, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '381296'), -- 198146 - 381296 - 381296, 392623 - 392623
(194685, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 194685
(191150, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '375314'), -- 191150 - 375314
(194688, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 194688

UPDATE `creature_template` SET `faction`=3272, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=8388608 WHERE `entry`=187123; -- Expedition Guardian
UPDATE `creature_template` SET `faction`=534, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=197743; -- Xingief
UPDATE `creature_template` SET `faction`=3270, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=190575; -- Cariel Roame
UPDATE `creature_template` SET `faction`=3270, `speed_run`=1.385714292526245117, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=194688; -- Valrash
UPDATE `creature_template` SET `faction`=3270, `npcflag`=65665, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187412; -- Happy Hal
UPDATE `creature_template` SET `faction`=3270, `npcflag`=83, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=191150; -- Danielle Anglers
UPDATE `creature_template` SET `faction`=3270, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `unit_flags3`=16777216 WHERE `entry` IN (191148, 190532); -- Kite
UPDATE `creature_template` SET `faction`=3270, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=194671; -- Elsa Donovan
UPDATE `creature_template` SET `faction`=3270, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=194668; -- Expedition Engineer
UPDATE `creature_template` SET `faction`=3270, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=191161; -- Waren Gearhart
UPDATE `creature_template` SET `faction`=3270, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=188904; -- John Stelle III
UPDATE `creature_template` SET `faction`=3270, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=198146; -- Liza Breezewood
UPDATE `creature_template` SET `faction`=3270, `speed_run`=1.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=33088, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=194650; -- Expedition Scout
UPDATE `creature_template` SET `faction`=3272, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=8388608 WHERE `entry`=187135; -- Expedition Guardian
UPDATE `creature_template` SET `faction`=3270, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=194674; -- Expedition Provisioner
UPDATE `creature_template` SET `faction`=2575, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=188027; -- Salty Salamander
UPDATE `creature_template` SET `faction`=3270, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=194685; -- Anaeli
UPDATE `creature_template` SET `faction`=3270, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=194652; -- Tarley Fellhew
UPDATE `creature_template` SET `faction`=3270, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=195830; -- Expedition Provisioner

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (191148, 194650);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(191148, 0, 0, 1, 0, 0, 0, NULL),
(194650, 0, 0, 1, 0, 0, 0, NULL);

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (197743,190575,194685,187135,187123,194668));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(197743, 1, 4991, 0, 0, 0, 0, 0, 0, 0, 0, 48317), -- 197743
(190575, 1, 2915, 0, 0, 0, 0, 0, 0, 0, 0, 48317), -- 190575
(194685, 1, 118409, 0, 0, 0, 0, 0, 0, 0, 0, 48317), -- 194685
(187135, 1, 159661, 0, 0, 126143, 0, 0, 0, 0, 0, 48317), -- 187135
(187123, 1, 141653, 0, 0, 0, 0, 0, 0, 0, 0, 48317), -- 187123
(194668, 1, 156874, 0, 0, 0, 0, 0, 3780, 0, 0, 48317); -- 194668

-- Gossip Data
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=188904 AND `MenuID`=28173) OR (`CreatureID`=190575 AND `MenuID`=29730) OR (`CreatureID`=191150 AND `MenuID`=30049) OR (`CreatureID`=187412 AND `MenuID`=28240) OR (`CreatureID`=198146 AND `MenuID`=29965);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(188904, 28173, 48317), -- 188904
(190575, 29730, 48317), -- 190575
(191150, 30049, 48317), -- 191150
(187412, 28240, 48317), -- 187412
(198146, 29965, 48317); -- 198146

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+4;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 230864, 0, 0, 0, 0, 0, 0, 0, 48317), -- 190575
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 232398, 0, 0, 0, 0, 0, 0, 0, 48317), -- 191150
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 232048, 0, 0, 0, 0, 0, 0, 0, 48317), -- 198146
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 219258, 0, 0, 0, 0, 0, 0, 0, 48317), -- 188904
(@NPCTEXTID+4, 1, 0, 0, 0, 0, 0, 0, 0, 221695, 0, 0, 0, 0, 0, 0, 0, 48317); -- 187412

DELETE FROM `gossip_menu` WHERE (`MenuID`=29730 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=30049 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=29965 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=28173 AND `TextID`=@NPCTEXTID+3) OR (`MenuID`=28240 AND `TextID`=@NPCTEXTID+4);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(29730, @NPCTEXTID+0, 48317), -- 190575
(30049, @NPCTEXTID+1, 48317), -- 191150
(29965, @NPCTEXTID+2, 48317), -- 198146
(28173, @NPCTEXTID+3, 48317), -- 188904
(28240, @NPCTEXTID+4, 48317); -- 187412

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (30049,28240,29965)) OR (`OptionID`=1 AND `MenuID`=28240) OR (`OptionID`=2 AND `MenuID`=28240);
INSERT INTO `gossip_menu_option` (`GossipOptionID`, `MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `Flags`, `OverrideIconID`, `GossipNpcOptionID`, `VerifiedBuild`) VALUES
(107425, 30049, 0, 3, 'Train me in Fishing', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 48317),
(54924, 28240, 1, 1, 'Let me browse your goods.', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 48317),
(54923, 28240, 0, 0, 'Why are you always so happy, Hal?', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 48317),
(54925, 28240, 2, 5, 'Make this inn your home.', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 48317),
(107306, 29965, 0, 0, 'How long until the Rugged Dragonscale docks here?', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 48317);

-- Trainer data
DELETE FROM `trainer` WHERE `Id`=1079;
INSERT INTO `trainer` (`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES
(1079, 2, 'Hello, friend!', 48317);

-- Cost may be off as already knew fishing when sniffed
DELETE FROM `trainer_spell` WHERE (`TrainerId`=1079 AND `SpellId` IN (366243,271617));
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(1079, 366243, 1000000, 356, 1, 0, 0, 0, 58, 48317), -- No Faction found! MoneyCost not recalculated!
(1079, 271617, 10, 0, 0, 0, 0, 0, 5, 48317); -- No Faction found! MoneyCost not recalculated!

DELETE FROM `creature_trainer` WHERE (`CreatureID`=191150 AND `MenuID`=30049 AND `OptionID`=0);
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(191150, 1079, 30049, 0);

-- Vendor data
DELETE FROM `npc_vendor` WHERE `entry` IN (191161, 187412);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(191161, 6, 6532, 0, 0, 1, 0, 0, 48317), -- 6532
(191161, 5, 6530, 0, 0, 1, 0, 0, 48317), -- 6530
(191161, 4, 6529, 0, 0, 1, 0, 0, 48317), -- 6529
(191161, 3, 136377, 0, 0, 1, 0, 0, 48317), -- 136377
(191161, 2, 6256, 0, 0, 1, 0, 0, 48317), -- 6256
(187412, 5, 194680, 0, 0, 1, 0, 0, 48317), -- 194680
(187412, 4, 197856, 0, 0, 1, 0, 0, 48317), -- 197856
(187412, 3, 197855, 0, 0, 1, 0, 0, 48317), -- 197855
(187412, 2, 197857, 0, 0, 1, 0, 0, 48317), -- 197857
(187412, 1, 197858, 0, 0, 1, 0, 0, 48317); -- 197858

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (197743,194652,194688,191161,188904,187412,190575,194685,194681,191150,191148,194674,190532,194650,194671,187135,187123,194668,195830,188027,198146));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(197743, 0, 0, 0, 2151, 48317),
(194652, 0, 0, 0, 2151, 48317),
(194688, 0, 0, 0, 2151, 48317),
(191161, 0, 0, 0, 2151, 48317),
(188904, 0, 0, 0, 2151, 48317),
(187412, 0, 0, 0, 2151, 48317),
(190575, 0, 0, 0, 2151, 48317),
(194685, 0, 0, 0, 2151, 48317),
(194681, 0, 0, 0, 2151, 48317),
(191150, 0, 0, 0, 2151, 48317),
(191148, 0, 0, 0, 2151, 48317),
(194674, 0, 0, 0, 2151, 48317),
(190532, 0, 0, 0, 2151, 48317),
(194650, 0, 0, 0, 2151, 48317),
(194671, 0, 0, 0, 2151, 48317),
(187135, 0, 0, 0, 883, 48317),
(187123, 0, 0, 0, 883, 48317),
(194668, 0, 0, 0, 2151, 48317),
(195830, 0, 0, 0, 2151, 48317),
(188027, 0, 0, 0, 2151, 48317),
(198146, 0, 0, 0, 2151, 48317);

-- Conversation data
DELETE FROM `conversation_actors` WHERE `ConversationId`=18625 AND `Idx`=0;
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(18625, 86121, @CGUID+4, 0, 187412, 0, 0, 0, 49343);

DELETE FROM `conversation_line_template` WHERE `Id`=47596;
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(47596, 0, 0, 0, 49343);

DELETE FROM `conversation_template` WHERE `Id`=18625;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(18625, 47596, 0, 49343);

-- Waren Gearhart SAI
SET @ENTRY := 191161;
SET @SOURCETYPE := 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,11,0,100,0,0,0,0,0,11,374205,2,0,0,0,0,19,191148,0,0,0.0,0.0,0.0,0.0,"Waren Gearhart - On Respawn - (Fly Kite SitGround To Target DNT)");

-- Danielle Anglers SAI
SET @ENTRY := 191150;
SET @SOURCETYPE := 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,11,0,100,0,0,0,0,0,11,375314,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Danielle Anglers - On Respawn - Cast (Fishing Mechagon Pole + Azsuna Bobber DNT)");

-- Happy Hal SAI
SET @ENTRY := 187412;
SET @SOURCETYPE := 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,1,62,0,100,0,28240,0,0,0,134,375316,2,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Happy Hal - Gossip Select -  Cast (Conversation DNT)"),
(@ENTRY,@SOURCETYPE,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Link - Closes Gossip - Happy Hal");

 -- Elsa Donovan smart ai
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 194671;
DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryOrGuid` = 194671) OR (`source_type` = 9 AND `entryOrGuid` IN (19467100, 19467101, 19467102));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(194671, 0, 0, 0, 34, 0, 100, 0, 2, 25, 0, 0, 80, 19467100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 25 - Self: Start timed action list id #Elsa Donovan #0 (19467100) (update out of combat)'),
(194671, 0, 1, 0, 34, 0, 100, 0, 2, 46, 0, 0, 80, 19467101, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 46 - Self: Start timed action list id #Elsa Donovan #0 (19467101) (update out of combat)'),
(194671, 0, 2, 0, 34, 0, 100, 0, 2, 5, 0, 0, 80, 19467102, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 5 - Self: Start timed action list id #Elsa Donovan #0 (19467102) (update out of combat)'),
(19467100, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1s - Play OneShotEmote 25 - to self'),
(19467100, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3s - Play OneShotEmote 25 - to self'),
(19467101, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 483, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1s - Set Emotestate to 483 - to self'),
(19467101, 9, 1, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 12s - Set Emotestate to 0 - to self'),
(19467102, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 483, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1s - Set Emotestate to 483 - to self'),
(19467102, 9, 1, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6s - Set Emotestate to 0 - to self'),
(19467102, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2s - Play OneShotEmote 25 - to self'),
(19467102, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2s - Play OneShotEmote 25 - to self');

-- Expedition Provisioner smart ai
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 194674;
DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+24), -(@CGUID+25), -(@CGUID+23))) OR (`source_type` = 9 AND `entryOrGuid` IN (19467400, 19467401, 19467402, 19467403, 19467404, 19467405));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
-- CGUID+24
(-(@CGUID+24), 0, 0, 0, 34, 0, 100, 0, 2, 2, 0, 0, 80, 19467400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 2 - Self: Start timed action list (19467400) (update out of combat)'),
(-(@CGUID+24), 0, 1, 0, 34, 0, 100, 0, 2, 16, 0, 0, 80, 19467401, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 16 - Self: Start timed action list (19467401) (update out of combat)'),
(19467400, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1s - Set SheathState to 8 (Kneel) - to self'),
(19467400, 9, 1, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6s - Remove SheathState 8 (Kneel) - to self'),
(19467400, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 244867, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Cast (8.0 Carry Sack New Anim) - to self'),
(19467401, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1s - Set SheathState to 8 (Kneel) - to self'),
(19467401, 9, 1, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 28, 244867, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6s - Remove (8.0 Carry Sack New Anim) - to self'),
(19467401, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Remove SheathState 8 (Kneel) - to self'),
-- CGUID+25
(-(@CGUID+25), 0, 0, 0, 34, 0, 100, 0, 2, 4, 0, 0, 80, 19467402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 4 - Self: Start timed action list (19467402) (update out of combat)'),
(-(@CGUID+25), 0, 1, 0, 34, 0, 100, 0, 2, 20, 0, 0, 80, 19467403, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 20 - Self: Start timed action list (19467403) (update out of combat)'),
(19467402, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1s - Set SheathState to 8 (Kneel) - to self'),
(19467402, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4s - Remove SheathState 8 (Kneel) - to self'),
(19467402, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 273098, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Cast (8.0 Carry Two Chest Stack) - to self'),
(19467403, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1s - Set SheathState to 8 (Kneel) - to self'),
(19467403, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 28, 273098, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2s - Remove (8.0 Carry Two Chest Stack) - to self'),
(19467403, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Remove SheathState 8 (Kneel) - to self'),
-- CGUID+23
(-(@CGUID+23), 0, 0, 0, 34, 0, 100, 0, 2, 24, 0, 0, 80, 19467404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 24 - Self: Start timed action list (19467404) (update out of combat)'),
(-(@CGUID+23), 0, 1, 0, 34, 0, 100, 0, 2, 4, 0, 0, 80, 19467405, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 4 - Self: Start timed action list (19467405) (update out of combat)'),
(19467404, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1s - Set SheathState to 8 (Kneel) - to self'),
(19467404, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3s - Remove SheathState 8 (Kneel) - to self'),
(19467404, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 273097, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Cast (8.0 Carry Large Chest) - to self'),
(19467405, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1s - Set SheathState to 8 (Kneel) - to self'),
(19467405, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 28, 273097, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2s - Remove (8.0 Carry Large Chest) - to self'),
(19467405, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Remove SheathState 8 (Kneel) - to self');

-- Elsa Donovan
SET @PATH := ((@CGUID+5) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 3671.246, -1894.194, 7.696021, NULL, 0),
(@PATH, 1, 3675.212, -1892.153, 7.696021, NULL, 0),
(@PATH, 2, 3679.095, -1889.892, 7.571021, NULL, 0),
(@PATH, 3, 3681.915, -1889.382, 7.973364, NULL, 0),
(@PATH, 4, 3685.4, -1888.726, 8.401587, NULL, 0),
(@PATH, 5, 3685.273, -1887.622, 8.666723, NULL, 15881),
(@PATH, 6, 3686.095, -1893.38, 7.533667, NULL, 0),
(@PATH, 7, 3688.017, -1895.049, 7.196509, NULL, 0),
(@PATH, 8, 3690.155, -1894.585, 6.940039, NULL, 0),
(@PATH, 9, 3693.362, -1892.569, 6.084937, NULL, 0),
(@PATH, 10, 3695.55, -1889.502, 4.99436, NULL, 0),
(@PATH, 11, 3696.896, -1886.109, 4.446021, NULL, 0),
(@PATH, 12, 3698.671, -1880.585, 4.446021, NULL, 0),
(@PATH, 13, 3699.009, -1877.299, 4.482642, NULL, 0),
(@PATH, 14, 3698.385, -1874.076, 4.571021, NULL, 0),
(@PATH, 15, 3696.984, -1868.724, 4.571021, NULL, 0),
(@PATH, 16, 3696.181, -1864.319, 4.451282, NULL, 0),
(@PATH, 17, 3695.116, -1859.267, 3.875843, NULL, 0),
(@PATH, 18, 3692.368, -1854.689, 3.597766, NULL, 0),
(@PATH, 19, 3689.212, -1851.106, 3.076282, NULL, 0),
(@PATH, 20, 3684.667, -1847.021, 3.03136, NULL, 0),
(@PATH, 21, 3680.863, -1843.686, 2.826282, NULL, 0),
(@PATH, 22, 3680.106, -1839.102, 2.826282, NULL, 0),
(@PATH, 23, 3679.808, -1835.955, 2.826282, NULL, 0),
(@PATH, 24, 3679.142, -1834.486, 2.826282, NULL, 0),
(@PATH, 25, 3678.291, -1834.286, 2.826282, NULL, 8490),
(@PATH, 26, 3679.899, -1839.517, 2.826282, NULL, 0),
(@PATH, 27, 3678.639, -1842.023, 2.826282, NULL, 0),
(@PATH, 28, 3676.649, -1843.373, 2.815784, NULL, 0),
(@PATH, 29, 3673.866, -1844.424, 2.951282, NULL, 0),
(@PATH, 30, 3671.092, -1849.401, 3.723254, NULL, 0),
(@PATH, 31, 3670.599, -1852.62, 4.420398, NULL, 0),
(@PATH, 32, 3670.699, -1855.396, 4.8651, NULL, 0),
(@PATH, 33, 3671.715, -1861.071, 5.776355, NULL, 0),
(@PATH, 34, 3672.849, -1863.637, 5.951282, NULL, 0),
(@PATH, 35, 3672.528, -1867.352, 6.071021, NULL, 0),
(@PATH, 36, 3671.865, -1870.038, 6.384741, NULL, 0),
(@PATH, 37, 3671.051, -1873.241, 6.636206, NULL, 0),
(@PATH, 38, 3670.958, -1876.573, 7.149756, NULL, 0),
(@PATH, 39, 3670.84, -1879.139, 7.443457, NULL, 0),
(@PATH, 40, 3671.452, -1883.832, 7.446021, NULL, 0),
(@PATH, 41, 3672.68, -1886.399, 7.536963, NULL, 0),
(@PATH, 42, 3673.431, -1888.88, 7.674292, NULL, 0),
(@PATH, 43, 3672.107, -1891.03, 7.696021, NULL, 0),
(@PATH, 44, 3670.769, -1893.142, 7.696021, NULL, 0),
(@PATH, 45, 3668.181, -1894.729, 7.696021, NULL, 0),
(@PATH, 46, 3664.119, -1897.682, 7.949098, 1.0532513, 14740);

UPDATE `creature` SET `position_x`= 3671.246, `position_y`= -1894.194, `position_z`= 7.696021, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+5;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+5;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+5, @PATH, 1);

-- Waypoints for CGUID+24
SET @PATH := ((@CGUID+24) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 3710.755, -1878.207, 5.468666, NULL, 0),
(@PATH, 1, 3711.728, -1878.417, 5.585365, NULL, 0),
(@PATH, 2, 3713.339, -1878.465, 5.740517, NULL, 8883),
(@PATH, 3, 3708.874, -1878.168, 5.242958, NULL, 0),
(@PATH, 4, 3705.255, -1876.983, 4.808632, NULL, 0),
(@PATH, 5, 3703.121, -1875.26, 4.615517, NULL, 0),
(@PATH, 6, 3700.254, -1872.646, 4.615517, NULL, 0),
(@PATH, 7, 3699.595, -1870.58, 4.571021, NULL, 0),
(@PATH, 8, 3699.045, -1867.108, 4.571021, NULL, 0),
(@PATH, 9, 3698.071, -1862.457, 4.383655, NULL, 0),
(@PATH, 10, 3696.401, -1858.372, 3.837756, NULL, 0),
(@PATH, 11, 3694.594, -1855.661, 3.7401, NULL, 0),
(@PATH, 12, 3691.215, -1851.98, 3.201282, NULL, 0),
(@PATH, 13, 3687.897, -1849.233, 3.076282, NULL, 0),
(@PATH, 14, 3685.363, -1848.59, 3.181751, NULL, 0),
(@PATH, 15, 3682.429, -1849.175, 3.549548, NULL, 0),
(@PATH, 16, 3682.015, -1850, 3.888782, NULL, 10676),
(@PATH, 17, 3688.565, -1849.677, 3.076282, NULL, 0),
(@PATH, 18, 3690.883, -1851.396, 3.201282, NULL, 0),
(@PATH, 19, 3692.945, -1853.714, 3.550159, NULL, 0),
(@PATH, 20, 3694.553, -1855.589, 3.735095, NULL, 0),
(@PATH, 21, 3697.729, -1862.035, 4.333117, NULL, 0),
(@PATH, 22, 3698.955, -1866.33, 4.598498, NULL, 0),
(@PATH, 23, 3700.063, -1872.547, 4.615517, NULL, 0),
(@PATH, 24, 3704.987, -1876.993, 4.776527, NULL, 0),
(@PATH, 25, 3710.755, -1878.207, 5.468666, NULL, 0);

UPDATE `creature` SET `position_x`= 3710.755, `position_y`= -1878.207, `position_z`= 5.468666, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+24;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+24;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+24, @PATH, 1);

-- Waypoints for CGUID+25
SET @PATH := ((@CGUID+25) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 3703.656, -1892.411, 4.892372, NULL, 0),
(@PATH, 1, 3705.838, -1894.745, 5.490517, NULL, 0),
(@PATH, 2, 3708.354, -1896.28, 5.865517, NULL, 0),
(@PATH, 3, 3709.375, -1897.415, 5.865517, NULL, 0),
(@PATH, 4, 3709.375, -1897.415, 5.865517, NULL, 7204),
(@PATH, 5, 3707.089, -1892.094, 5.403725, NULL, 0),
(@PATH, 6, 3705.813, -1890.819, 5.010536, NULL, 0),
(@PATH, 7, 3702.704, -1888.347, 4.57621, NULL, 0),
(@PATH, 8, 3701.954, -1886.318, 4.458168, NULL, 0),
(@PATH, 9, 3701.34, -1883.356, 4.490517, NULL, 0),
(@PATH, 10, 3701.294, -1880.342, 4.45829, NULL, 0),
(@PATH, 11, 3700.57, -1876.448, 4.629433, NULL, 0),
(@PATH, 12, 3700.091, -1873.693, 4.615517, NULL, 0),
(@PATH, 13, 3698.168, -1871.054, 4.571021, NULL, 0),
(@PATH, 14, 3696.149, -1869.91, 4.571021, NULL, 0),
(@PATH, 15, 3693.89, -1869.158, 4.616797, NULL, 0),
(@PATH, 16, 3691.027, -1868.479, 4.821021, NULL, 0),
(@PATH, 17, 3686.5, -1868.219, 5.503516, NULL, 0),
(@PATH, 18, 3685.135, -1867.97, 5.542334, NULL, 0),
(@PATH, 19, 3683.637, -1864.599, 6.124621, NULL, 0),
(@PATH, 20, 3683.766, -1861.879, 6.586902, NULL, 3879),
(@PATH, 21, 3685.765, -1866.833, 5.466773, NULL, 0),
(@PATH, 22, 3688.451, -1868.49, 5.217749, NULL, 0),
(@PATH, 23, 3688.451, -1868.49, 5.217749, NULL, 0),
(@PATH, 24, 3688.451, -1868.49, 5.217749, NULL, 0),
(@PATH, 25, 3691.48, -1868.507, 4.821021, NULL, 0),
(@PATH, 26, 3694.827, -1869.556, 4.571021, NULL, 0),
(@PATH, 27, 3696.696, -1871.528, 4.571021, NULL, 0),
(@PATH, 28, 3699.29, -1875.281, 4.497534, NULL, 0),
(@PATH, 29, 3700.776, -1878.281, 4.409218, NULL, 0),
(@PATH, 30, 3701.55, -1882.356, 4.489052, NULL, 0),
(@PATH, 31, 3701.864, -1887.089, 4.539589, NULL, 0),
(@PATH, 32, 3702.306, -1890.436, 4.530312, NULL, 0);

UPDATE `creature` SET `position_x`= 3703.656, `position_y`= -1892.411, `position_z`= 4.892372, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+25;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+25;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+25, @PATH, 1);

-- Waypoints for CGUID+23
SET @PATH := ((@CGUID+23) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 3683.787, -1839.747, 2.826282, NULL, 0),
(@PATH, 1, 3683.804, -1836.868, 2.826282, NULL, 0),
(@PATH, 2, 3683.257, -1833.661, 2.826282, NULL, 0),
(@PATH, 3, 3681.27, -1831.004, 2.798542, NULL, 0),
(@PATH, 4, 3679.622, -1829.224, 2.798542, NULL, 4173),
(@PATH, 5, 3680.644, -1834.155, 2.826282, NULL, 0),
(@PATH, 6, 3681.349, -1836.7, 2.826282, NULL, 0),
(@PATH, 7, 3682.126, -1839.748, 2.826282, NULL, 0),
(@PATH, 8, 3683.392, -1842.29, 2.826282, NULL, 0),
(@PATH, 9, 3687.142, -1846.479, 3.076282, NULL, 0),
(@PATH, 10, 3689.81, -1848.311, 3.076282, NULL, 0),
(@PATH, 11, 3691.465, -1849.889, 3.076282, NULL, 0),
(@PATH, 12, 3693.534, -1852.403, 3.463733, NULL, 0),
(@PATH, 13, 3695.547, -1854.629, 3.951282, NULL, 0),
(@PATH, 14, 3697.137, -1857.021, 4.140124, NULL, 0),
(@PATH, 15, 3698.358, -1858.951, 4.306994, NULL, 0),
(@PATH, 16, 3699.46, -1860.92, 4.326159, NULL, 0),
(@PATH, 17, 3699.849, -1864.318, 4.451282, NULL, 0),
(@PATH, 18, 3699.932, -1866.368, 4.451282, NULL, 0),
(@PATH, 19, 3700.864, -1870.58, 4.697792, NULL, 0),
(@PATH, 20, 3701.706, -1872.609, 4.615517, NULL, 0),
(@PATH, 21, 3703.413, -1874.417, 4.615517, NULL, 0),
(@PATH, 22, 3705.637, -1875.387, 4.995522, NULL, 0),
(@PATH, 23, 3709.937, -1874.962, 5.312538, NULL, 0),
(@PATH, 24, 3712.378, -1874.795, 5.615517, NULL, 5156),
(@PATH, 25, 3705.338, -1874.646, 5.115517, NULL, 0),
(@PATH, 26, 3703.212, -1873.321, 4.789833, NULL, 0),
(@PATH, 27, 3701.965, -1871.385, 4.833534, NULL, 0),
(@PATH, 28, 3700.874, -1868.911, 4.700233, NULL, 0),
(@PATH, 29, 3699.383, -1863.009, 4.324817, NULL, 0),
(@PATH, 30, 3698.634, -1860.028, 4.333972, NULL, 0),
(@PATH, 31, 3697.438, -1857.587, 4.233508, NULL, 0),
(@PATH, 32, 3694.65, -1853.436, 3.701282, NULL, 0),
(@PATH, 33, 3692.317, -1850.595, 3.326282, NULL, 0),
(@PATH, 34, 3689.24, -1848.309, 3.076282, NULL, 0),
(@PATH, 35, 3686.892, -1846.802, 3.076282, NULL, 0),
(@PATH, 36, 3684.58, -1842.934, 2.826282, NULL, 0);

UPDATE `creature` SET `position_x`= 3683.787, `position_y`= -1839.747, `position_z`= 2.826282, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+23;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+23;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+23, @PATH, 1);
