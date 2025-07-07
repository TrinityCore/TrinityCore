SET @CGUID := 10004585;
SET @OGUID := 10001192;

SET @NPCTEXTID := 600050;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+29;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 226838, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1659.2100830078125, -2438.388916015625, -6.77278709411621093, 3.070060014724731445, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1
(@CGUID+1, 226838, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1595.9791259765625, -2499.14404296875, -12.2589845657348632, 3.950060129165649414, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1
(@CGUID+2, 226838, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1655.217041015625, -2470.725830078125, -8.35030269622802734, 3.950060129165649414, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1
(@CGUID+3, 226838, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1609.467041015625, -2498.901123046875, -11.6396751403808593, 0.930378496646881103, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1
(@CGUID+4, 226838, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1678.98095703125, -2428.829833984375, -2.39393210411071777, 5.200343608856201171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1
(@CGUID+5, 226292, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1656.251708984375, -2511.807373046875, -4.49869108200073242, 1.772120475769042968, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1 (Auras: 449618 - [DNT] Cosmetic - Woven Cocoon State)
(@CGUID+6, 226292, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1710.7135009765625, -2405.895751953125, -47.1095161437988281, 3.64921879768371582, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1 (Auras: 449618 - [DNT] Cosmetic - Woven Cocoon State)
(@CGUID+7, 226292, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1638.4896240234375, -2464.085205078125, -10.2341842651367187, 1.569582462310791015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1 (Auras: 449618 - [DNT] Cosmetic - Woven Cocoon State)
(@CGUID+8, 226292, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1681.2535400390625, -2424.00341796875, -45.4178237915039062, 2.772542476654052734, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1 (Auras: 449618 - [DNT] Cosmetic - Woven Cocoon State)
(@CGUID+9, 226292, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1660.0347900390625, -2433.204833984375, -5.77955007553100585, 4.406142234802246093, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1 (Auras: 449618 - [DNT] Cosmetic - Woven Cocoon State)
(@CGUID+10, 226292, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1692.2552490234375, -2421.0400390625, -1.04082369804382324, 2.620611190795898437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1 (Auras: 449618 - [DNT] Cosmetic - Woven Cocoon State)
(@CGUID+11, 226292, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1643.6649169921875, -2443.244873046875, -43.1610298156738281, 1.00031900405883789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1 (Auras: 449618 - [DNT] Cosmetic - Woven Cocoon State)
(@CGUID+12, 226292, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1590.876708984375, -2480.092041015625, -13.4635906219482421, 0.871347963809967041, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1 (Auras: 449618 - [DNT] Cosmetic - Woven Cocoon State)
(@CGUID+13, 226292, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1611.51220703125, -2447.947998046875, -14.9657478332519531, 5.356293678283691406, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1 (Auras: 449618 - [DNT] Cosmetic - Woven Cocoon State)
(@CGUID+14, 226292, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1672.920166015625, -2454.632080078125, -7.06928348541259765, 3.138380765914916992, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1 (Auras: 449618 - [DNT] Cosmetic - Woven Cocoon State)
(@CGUID+15, 226292, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1617.23095703125, -2502.40283203125, -10.0145339965820312, 3.504555940628051757, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1 (Auras: 449618 - [DNT] Cosmetic - Woven Cocoon State)
(@CGUID+16, 226292, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1575.1632080078125, -2479.80029296875, -52.07293701171875, 0.661658108234405517, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1 (Auras: 449618 - [DNT] Cosmetic - Woven Cocoon State)
(@CGUID+17, 226292, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1676.1961669921875, -2479.178955078125, -6.64516735076904296, 2.721494913101196289, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1 (Auras: 449618 - [DNT] Cosmetic - Woven Cocoon State)
(@CGUID+18, 226292, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1622.3853759765625, -2465.00341796875, -12.6451845169067382, 1.344075560569763183, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1 (Auras: 449618 - [DNT] Cosmetic - Woven Cocoon State)
(@CGUID+19, 226292, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1571.126708984375, -2452.538330078125, -55.886260986328125, 5.882104873657226562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1 (Auras: 449618 - [DNT] Cosmetic - Woven Cocoon State)
(@CGUID+20, 226292, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1550.8350830078125, -2421.76904296875, -25.7293472290039062, 5.882104873657226562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1 (Auras: 449618 - [DNT] Cosmetic - Woven Cocoon State)
(@CGUID+21, 226292, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1576.9149169921875, -2384.3837890625, -32.9735527038574218, 4.851584434509277343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1 (Auras: 449618 - [DNT] Cosmetic - Woven Cocoon State)
(@CGUID+22, 226292, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1647.3038330078125, -2360.95654296875, -42.9849166870117187, 4.160091876983642578, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1 (Auras: 449618 - [DNT] Cosmetic - Woven Cocoon State)
(@CGUID+23, 226838, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1623.13720703125, -2360.953125, 11.84552574157714843, 3.357110023498535156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1
(@CGUID+24, 226838, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1652.27783203125, -2353.350830078125, 10.15030860900878906, 3.223987579345703125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1
(@CGUID+25, 226838, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1679.8629150390625, -2352.986083984375, 11.86206626892089843, 5.955498218536376953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1
(@CGUID+26, 226838, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1656.3697509765625, -2343.154541015625, -2.51760363578796386, 3.950060129165649414, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1
(@CGUID+27, 226838, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1639.3785400390625, -2356.420166015625, 11.13512706756591796, 1.874772548675537109, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1
(@CGUID+28, 226838, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1680.923583984375, -2305.21533203125, 11.12991046905517578, 1.987367987632751464, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Opalcreg Worker (Area: The Opalcreg - Difficulty: 0) CreateObject1
(@CGUID+29, 224708, 2552, 14717, 14788, '0', 24032, 0, 0, 0, 1671.4478759765625, -2383.770751953125, 5.426219940185546875, 4.040614128112792968, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689); -- Cenderragg (Area: The Opalcreg - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+36;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449618'), -- 226292 (Opalcreg Worker) - [DNT] Cosmetic - Woven Cocoon State
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449618'), -- 226292 (Opalcreg Worker) - [DNT] Cosmetic - Woven Cocoon State
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449618'), -- 226292 (Opalcreg Worker) - [DNT] Cosmetic - Woven Cocoon State
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449618'), -- 226292 (Opalcreg Worker) - [DNT] Cosmetic - Woven Cocoon State
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449618'), -- 226292 (Opalcreg Worker) - [DNT] Cosmetic - Woven Cocoon State
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449618'), -- 226292 (Opalcreg Worker) - [DNT] Cosmetic - Woven Cocoon State
(@CGUID+11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449618'), -- 226292 (Opalcreg Worker) - [DNT] Cosmetic - Woven Cocoon State
(@CGUID+12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449618'), -- 226292 (Opalcreg Worker) - [DNT] Cosmetic - Woven Cocoon State
(@CGUID+13, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449618'), -- 226292 (Opalcreg Worker) - [DNT] Cosmetic - Woven Cocoon State
(@CGUID+14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449618'), -- 226292 (Opalcreg Worker) - [DNT] Cosmetic - Woven Cocoon State
(@CGUID+15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449618'), -- 226292 (Opalcreg Worker) - [DNT] Cosmetic - Woven Cocoon State
(@CGUID+16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449618'), -- 226292 (Opalcreg Worker) - [DNT] Cosmetic - Woven Cocoon State
(@CGUID+17, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449618'), -- 226292 (Opalcreg Worker) - [DNT] Cosmetic - Woven Cocoon State
(@CGUID+18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449618'), -- 226292 (Opalcreg Worker) - [DNT] Cosmetic - Woven Cocoon State
(@CGUID+19, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449618'), -- 226292 (Opalcreg Worker) - [DNT] Cosmetic - Woven Cocoon State
(@CGUID+20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449618'), -- 226292 (Opalcreg Worker) - [DNT] Cosmetic - Woven Cocoon State
(@CGUID+21, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449618'), -- 226292 (Opalcreg Worker) - [DNT] Cosmetic - Woven Cocoon State
(@CGUID+22, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449618'); -- 226292 (Opalcreg Worker) - [DNT] Cosmetic - Woven Cocoon State

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+4;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 454189, 2552, 14717, 14788, '0', 0, 0, 1564.5850830078125, -2436.076416015625, -22.9202518463134765, 1.628190994262695312, -0.11918592453002929, -0.02024555206298828, 0.726612091064453125, 0.676328122615814208, 120, 255, 1, 57689), -- Opal Ore (Area: The Opalcreg - Difficulty: 0) CreateObject1
(@OGUID+1, 454189, 2552, 14717, 14788, '0', 0, 0, 1642.9478759765625, -2459.163330078125, -43.3351402282714843, 0, 0, 0, 0, 1, 120, 255, 1, 57689), -- Opal Ore (Area: The Opalcreg - Difficulty: 0) CreateObject1
(@OGUID+2, 454189, 2552, 14717, 14788, '0', 0, 0, 1699.9322509765625, -2403.1806640625, -47.2254905700683593, 0, 0, 0, 0, 1, 120, 255, 1, 57689), -- Opal Ore (Area: The Opalcreg - Difficulty: 0) CreateObject1
(@OGUID+3, 454189, 2552, 14717, 14788, '0', 0, 0, 1655.8072509765625, -2479.600830078125, -58.6452980041503906, 0, 0, 0, 0, 1, 120, 255, 1, 57689), -- Opal Ore (Area: The Opalcreg - Difficulty: 0) CreateObject1
(@OGUID+4, 454189, 2552, 14717, 14788, '0', 0, 0, 1583.78125, -2405.921875, -27.4102687835693359, 0, 0, 0, 0, 1, 120, 255, 1, 57689); -- Opal Ore (Area: The Opalcreg - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 226838;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(226838, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 0, ''); -- Opalcreg Worker

DELETE FROM `gameobject_template_addon` WHERE `entry`=454189;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(454189, 0, 0x204004, 0, 0); -- Opal Ore

-- Template
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0xC0000000 WHERE `entry`=226422; -- Opalcreg Worker
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=225702; -- Nerubian Swarmite
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=224710; -- Kix'arak
UPDATE `creature_template` SET `faction`=3407, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags3`=0x40000000 WHERE `entry`=226292; -- Opalcreg Worker
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=219397; -- Shalescale Striker
UPDATE `creature_template` SET `faction`=3407, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=224708; -- Cenderragg
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800, `unit_flags3`=0x14000000 WHERE `entry`=219265; -- Emperor Pitfang
UPDATE `creature_template` SET `faction`=3407, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=226838; -- Opalcreg Worker

-- Gossip
DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 269518, 0, 0, 0, 0, 0, 0, 0, 57689), -- 224708 (Cenderragg)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 269612, 0, 0, 0, 0, 0, 0, 0, 57689); -- 224708 (Cenderragg)

DELETE FROM `gossip_menu` WHERE (`MenuID`=35982 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=36028 AND `TextID`=@NPCTEXTID+1);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(35982, @NPCTEXTID+0, 57689), -- 224708 (Cenderragg)
(36028, @NPCTEXTID+1, 57689); -- 224708 (Cenderragg)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=35425 AND `OptionID` IN (1,0));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(35425, 123762, 1, 0, 'What do the nerubians want from you?', 0, 0, 0, 36028, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689),
(35425, 123732, 0, 0, 'Why are these opals worth risking your life?', 0, 0, 0, 35982, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (35425));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 35425, 0, 0, 0, 47, 0, 82798, 74, 0, '', 0, 'Player for which gossip text is shown has An Opal of Mine (82798) in state complete, incomplete, rewarded'),
(15, 35425, 0, 0, 0, 47, 0, 82799, 74, 0, '', 0, 'Player for which gossip text is shown has Web Beats Rock (82799) in state complete, incomplete, rewarded'),
(15, 35425, 1, 0, 0, 47, 0, 82798, 74, 0, '', 0, 'Player for which gossip text is shown has An Opal of Mine (82798) in state complete, incomplete, rewarded'),
(15, 35425, 1, 0, 0, 47, 0, 82799, 74, 0, '', 0, 'Player for which gossip text is shown has Web Beats Rock (82799) in state complete, incomplete, rewarded');

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 24032;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(24032, 'Cosmetic - See Cenderragg in the cave of The Opalcreg');

DELETE FROM `phase_area` WHERE `PhaseId` = 24032;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(14788, 24032, 'See Cenderragg in the cave of The Opalcreg');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 23936 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 23936, 0, 0, 0, 47, 0, 82799, 2|8|64, 0, 0, 'Apply Phase 23936 if Quest 82799 is taken | complete | rewarded'),
(26, 23936, 0, 0, 0, 47, 0, 82798, 2|8|64, 0, 0, 'Apply Phase 23936 if Quest 82798 is taken | complete | rewarded');

-- Loot
DELETE FROM `creature_loot_template` WHERE `Entry` = 224149;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(224149, 0, 224808, 25, 1, 1, 0, 1, 1, 'Opal Ore');

UPDATE `creature_template_difficulty` SET `LootID` = 224149 WHERE `Entry` IN (224149, 224150);

DELETE FROM `gameobject_loot_template` WHERE `Entry` = 126024;
INSERT INTO `gameobject_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(126024, 0, 224808, 100, 1, 1, 0, 1, 1, 'Opal Ore');

-- Quest
DELETE FROM `ui_map_quest` WHERE (`UIMapId`=2248 AND `QuestId` IN (84429,82257));
INSERT INTO `ui_map_quest` (`UIMapId`, `QuestId`, `VerifiedBuild`) VALUES
(2248, 84429, 57689), -- Construct Containment
(2248, 82257, 57689); -- Burrow Burial

DELETE FROM `creature_queststarter` WHERE (`id`=224708 AND `quest`=82800);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(224708, 82800, 57689); -- A Sedimental Moment offered by Cenderragg

DELETE FROM `creature_questender` WHERE (`id`=224708 AND `quest` IN (82799,82798));
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(224708, 82799, 57689), -- Web Beats Rock ended by Cenderragg
(224708, 82798, 57689); -- An Opal of Mine ended by Cenderragg

DELETE FROM `quest_template_addon` WHERE `ID` IN (82799, 82798);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(82799, 0, 0, 0, 82797, 82800, -82799, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Web Beats Rock 
(82798, 0, 0, 0, 82797, 82800, -82799, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- An Opal of Mine

DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=454189 AND `Idx`=0);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(454189, 0, 224808, 57689); -- Opal Ore

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=0x30000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=57689 WHERE (`Entry`=226422 AND `DifficultyID`=0); -- 226422 (Opalcreg Worker) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=225702 AND `DifficultyID`=0); -- 225702 (Nerubian Swarmite) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=224710 AND `DifficultyID`=0); -- 224710 (Kix'arak) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=0x20000100, `VerifiedBuild`=57689 WHERE (`Entry`=226292 AND `DifficultyID`=0); -- 226292 (Opalcreg Worker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=219397 AND `DifficultyID`=0); -- 219397 (Shalescale Striker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=224708 AND `DifficultyID`=0); -- 224708 (Cenderragg) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2804, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=219265 AND `DifficultyID`=0); -- 219265 (Emperor Pitfang) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=226838 AND `DifficultyID`=0); -- 226838 (Opalcreg Worker) - CanSwim

