-- 
SET @CGUID := 1051318;
SET @NPCTEXTID := 580002;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 188377, 2222, 10565, 13499, '0', 18890, 0, 0, 0, -1735.125, 1160.4896240234375, 5267.31396484375, 2.225665569305419921, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 45114), -- So'turu (Area: -Unknown- - Difficulty: 0)
(@CGUID+1, 188391, 2222, 10565, 13499, '0', 18890, 0, 0, 0, -1732.3367919921875, 1162.8316650390625, 5267.322265625, 2.988910436630249023, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 45114), -- Ko'ropo (Area: -Unknown- - Difficulty: 0)
(@CGUID+2, 188386, 2222, 10565, 13499, '0', 18890, 0, 0, 0, -1738.1302490234375, 1157.96533203125, 5267.30859375, 1.73673415184020996, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 45114); -- Ta'choso (Area: -Unknown- - Difficulty: 0)

-- Template Data
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=35, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=188386; -- Ta'choso
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=35, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=188391; -- Ko'ropo
UPDATE `creature_template` SET `gossip_menu_id`=28074, `minlevel`=60, `maxlevel`=60, `faction`=35, `npcflag`=131, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=188377; -- So'turu

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (188386,188391,188377));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(188386, 0, 0, 0, 783, 45114),
(188391, 0, 0, 0, 783, 45114),
(188377, 0, 0, 0, 783, 45114);

-- Gossip
DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 218562, 0, 0, 0, 0, 0, 0, 0, 45114), -- 188377 (So'turu)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 218563, 0, 0, 0, 0, 0, 0, 0, 45114); -- 188377 (So'turu)

DELETE FROM `gossip_menu` WHERE (`MenuID`=28074 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=28075 AND `TextID`=@NPCTEXTID+1);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(28074, @NPCTEXTID+0, 45114), -- 188377 (So'turu)
(28075, @NPCTEXTID+1, 45114); -- 188377 (So'turu)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=28074 AND `OptionID` IN (1,0));
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(28074, 1, 1, 'Show me your wares.', 58437, 3, 128, 0, 0, 0, 0, 0, NULL, 0, 45114), -- OptionBroadcastTextID: 58437 - 90189 - 180077
(28074, 0, 0, 'You seem to recognize this coin. What is it?', 0, 1, 1, 0, 28075, 0, 0, 0, NULL, 0, 45114);

-- Phasing
DELETE FROM `phase_area` WHERE (`AreaId` = 13499 AND `PhaseId` = 18890);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(13499, 18890, 'Cosmetic - See Shadowlands Season 4 Coin Vendors');

DELETE FROM `phase_name` WHERE `ID` = 18890;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(18890, 'Cosmetic - See Shadowlands Season 4 Coin Vendors');

-- Condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 18890 AND `SourceEntry` = 13499);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 18890, 13499, 0, 0, 47, 0, 66648, 64, 0, 0, 'Apply Phase 18890 If Quest 66648 IS rewarded');

-- Vendor Data
DELETE FROM `npc_vendor` WHERE (`entry`=188386 AND `item`=186417 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186438 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186398 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186406 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186410 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=187056 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186421 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186436 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186437 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186419 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186434 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186435 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186409 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186413 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186393 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186416 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186433 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186432 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186392 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186391 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186388 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186430 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186431 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186411 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186407 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186387 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186429 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186405 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186386 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186427 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186428 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186404 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186385 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186384 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186424 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186425 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186403 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186383 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186418 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186423 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186381 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186415 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188386 AND `item`=186422 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189851 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189861 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189862 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189818 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189860 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=188253 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=188252 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189852 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189853 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=191001 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=188254 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189846 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189845 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=188261 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=188255 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189839 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=188262 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189834 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189806 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189781 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=188264 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=188263 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189828 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189829 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189830 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=188266 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=188265 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=188267 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189816 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189817 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189819 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189808 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189754 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=188269 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=188268 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189789 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189799 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189800 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=188270 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=188271 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189790 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189807 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189788 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=188272 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=188273 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189779 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188377 AND `item`=189584 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188391 AND `item`=184031 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188391 AND `item`=184030 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188391 AND `item`=184029 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188391 AND `item`=184028 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188391 AND `item`=184027 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188391 AND `item`=184026 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188391 AND `item`=184025 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188391 AND `item`=184024 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188391 AND `item`=184023 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188391 AND `item`=184022 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188391 AND `item`=184021 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188391 AND `item`=184020 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188391 AND `item`=184019 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188391 AND `item`=184018 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188391 AND `item`=184017 AND `ExtendedCost`=7302 AND `type`=1) OR (`entry`=188391 AND `item`=184016 AND `ExtendedCost`=7302 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(188386, 43, 186417, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 42, 186438, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 41, 186398, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 40, 186406, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 39, 186410, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 38, 187056, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 37, 186421, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 36, 186436, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 35, 186437, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 34, 186419, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 33, 186434, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 32, 186435, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 31, 186409, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 30, 186413, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 29, 186393, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 28, 186416, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 27, 186433, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 26, 186432, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 25, 186392, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 24, 186391, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 23, 186388, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 22, 186430, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 21, 186431, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 20, 186411, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 19, 186407, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 18, 186387, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 17, 186429, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 16, 186405, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 15, 186386, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 14, 186427, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 13, 186428, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 12, 186404, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 11, 186385, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 10, 186384, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 9, 186424, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 8, 186425, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 7, 186403, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 6, 186383, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 5, 186418, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 4, 186423, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 3, 186381, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 2, 186415, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188386, 1, 186422, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 48, 189851, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 47, 189861, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 46, 189862, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 45, 189818, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 44, 189860, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 43, 188253, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 42, 188252, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 41, 189852, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 40, 189853, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 39, 191001, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 38, 188254, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 37, 189846, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 36, 189845, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 35, 188261, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 34, 188255, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 33, 189839, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 31, 188262, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 30, 189834, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 29, 189806, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 28, 189781, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 27, 188264, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 26, 188263, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 25, 189828, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 24, 189829, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 23, 189830, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 22, 188266, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 21, 188265, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 20, 188267, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 19, 189816, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 18, 189817, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 17, 189819, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 16, 189808, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 15, 189754, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 14, 188269, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 13, 188268, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 12, 189789, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 11, 189799, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 10, 189800, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 9, 188270, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 8, 188271, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 7, 189790, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 6, 189807, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 5, 189788, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 4, 188272, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 3, 188273, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 2, 189779, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188377, 1, 189584, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188391, 16, 184031, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188391, 15, 184030, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188391, 14, 184029, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188391, 13, 184028, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188391, 12, 184027, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188391, 11, 184026, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188391, 10, 184025, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188391, 9, 184024, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188391, 8, 184023, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188391, 7, 184022, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188391, 6, 184021, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188391, 5, 184020, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188391, 4, 184019, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188391, 3, 184018, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188391, 2, 184017, 0, 7302, 1, 0, 0, 45114), -- -Unknown-
(188391, 1, 184016, 0, 7302, 1, 0, 0, 45114); -- -Unknown-
