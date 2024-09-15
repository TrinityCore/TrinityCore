SET @OGUID := 7000249;

DELETE FROM `phase_name` WHERE `ID`=12885;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12885, 'Cosmetic: Kul Tiran Unlock Questline - Chelsea Wright Ore and dog stuff');

DELETE FROM `phase_area` WHERE `PhaseId`=12885;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9500, 12885, 'Cosmetic: Kul Tiran Unlock Questline - Chelsea Wright Ore and dog stuff - Bleak Hills Mine'),
(9432, 12885, 'Cosmetic: Kul Tiran Unlock Questline - Chelsea Wright Ore and dog stuff - Watchman''s Rise');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12885));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12885, 0, 0, 0, 47, 0, 54729, 74, 0, '', 0, 'Player have The Bleak Hills (54729) in state incomplete, complete, rewarded'),
(26, 12885, 0, 0, 0, 47, 0, 54733, 64, 0, '', 1, 'Player doesn\'t have Make It Wright (54733) in state rewarded');

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 322654, 1643, 8721, 9500, '0', 12885, 0, 106.1649322509765625, 3404.674560546875, 211.1198577880859375, 1.868429303169250488, 0, 0, 0.804132461547851562, 0.594450116157531738, 120, 255, 1, 54762), -- [DNT] Ore (Area: Bleak Hills Mine - Difficulty: 0) CreateObject1
(@OGUID+1, 322641, 1643, 8721, 9500, '0', 12885, 0, 95.90972137451171875, 3333.868896484375, 221.61285400390625, 1.811589360237121582, 0, 0, 0.786915779113769531, 0.617060422897338867, 120, 255, 1, 54904), -- [DNT] Dog House (Area: Bleak Hills Mine - Difficulty: 0) CreateObject1
(@OGUID+2, 322651, 1643, 8721, 9500, '0', 12885, 0, 105.7899322509765625, 3404.388916015625, 211.005706787109375, 2.607350349426269531, 0, 0, 0.964534759521484375, 0.263955861330032348, 120, 255, 1, 54904), -- Storage Crate (Area: Bleak Hills Mine - Difficulty: 0) CreateObject1
(@OGUID+3, 322640, 1643, 8721, 9500, '0', 12885, 0, 94.9288177490234375, 3317.744873046875, 229.2803497314453125, 0, 0, 0, 0, 1, 120, 255, 1, 54904), -- [DNT] Dog Ball (Area: Bleak Hills Mine - Difficulty: 0) CreateObject1
(@OGUID+4, 322639, 1643, 8721, 9500, '0', 12885, 0, 95.001739501953125, 3317.59375, 229.042449951171875, 4.877360820770263671, 0, 0, -0.64644241333007812, 0.762962758541107177, 120, 255, 1, 54904), -- [DNT] Dog Bowl (Area: Bleak Hills Mine - Difficulty: 0) CreateObject1
(@OGUID+5, 322642, 1643, 8721, 9500, '0', 12885, 0, 95.79166412353515625, 3334.155517578125, 221.59820556640625, 0.04821290448307991, 0, 0, 0.024104118347167968, 0.99970942735671997, 120, 255, 1, 54904); -- [DNT] Scattered Hay (Area: Bleak Hills Mine - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (322651 /*Storage Crate*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(322651, 0, 4, 0, 0); -- Storage Crate
