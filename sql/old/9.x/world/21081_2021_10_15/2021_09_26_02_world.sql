--
SET @CGUID := 1050000;

DELETE FROM `gameobject_template` WHERE `entry` IN (355480 /*Death Gate to the Maw*/, 355479 /*Death Gate to the Maw*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `ContentTuningId`, `VerifiedBuild`) VALUES
(355480, 10, 8046, 'Death Gate to the Maw', 'questinteract', '', '', 2, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 335263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1400, 38134), -- Death Gate to the Maw
(355479, 10, 8046, 'Death Gate to the Maw', 'questinteract', '', '', 2, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 335262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1400, 38134); -- Death Gate to the Maw
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=355461;

DELETE FROM `gameobject_template_addon` WHERE `entry` IN(355461, 355480, 355479);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(355461, 0, 262145, 0, 0), -- Death Gate to Acherus
(355480, 0, 262145, 0, 0), -- Death Gate to the Maw
(355479, 0, 262145, 0, 0); -- Death Gate to the Maw

DELETE FROM `npc_text` WHERE `ID` IN (41745 /*41745*/, 41398 /*41398*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(41745, 1, 0, 0, 0, 0, 0, 0, 0, 201959, 0, 0, 0, 0, 0, 0, 0, 38134), -- 41745
(41398, 1, 0, 0, 0, 0, 0, 0, 0, 204441, 0, 0, 0, 0, 0, 0, 0, 40120); -- 41398
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID` IN(41744);

DELETE FROM `gossip_menu` WHERE `MenuId`=26057 AND `TextId` IN (41745,41744,41398);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(26057, 41745, 38134), -- 171791 (Nazgrim)
(26057, 41744, 38134), -- 171791 (Nazgrim)
(26057, 41398, 38134); -- 171791 (Nazgrim)

DELETE FROM `gossip_menu_option` WHERE `MenuId`=26057 AND `OptionIndex`=0;
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionNpcFlag`, `OptionType`, `VerifiedBuild`) VALUES
(26057, 0, 0, 'Tell me what happened.', 0, 1, 1, 38134);

UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=176554; -- Highlord Darion Mograine
UPDATE `creature_template` SET `minlevel`=0 WHERE `entry`=173279; -- Orgrimmar Grunt

UPDATE `creature_equip_template` SET `ItemID1`=117049 WHERE (`CreatureID`=169177 AND `ID`=4); -- Knight of the Ebon Blade
UPDATE `creature_equip_template` SET `ItemID1`=49886 WHERE (`CreatureID`=169177 AND `ID`=3); -- Knight of the Ebon Blade
UPDATE `creature_equip_template` SET `ItemID1`=75223 WHERE (`CreatureID`=169177 AND `ID`=2); -- Knight of the Ebon Blade
UPDATE `creature_equip_template` SET `ItemID1`=164981 WHERE (`CreatureID`=169177 AND `ID`=1); -- Knight of the Ebon Blade

DELETE FROM `creature_template_addon` WHERE `entry` IN(176554, 171791, 173279, 169177, 173281);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(176554, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 176554 (Highlord Darion Mograine)
(171791, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 171791 (Nazgrim)
(173279, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 173279 (Orgrimmar Grunt)
(169177, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 169177 (Knight of the Ebon Blade)
(173281, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 173281 (Concerned Onlooker)

DELETE FROM `creature_template_scaling` WHERE `Entry` IN(171791, 173279, 173281);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(171791, 0, 0, 0, 1400, 38134),
(173279, 0, 0, 0, 883, 38134),
(173281, 0, 0, 0, 1400, 38134);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+37;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- Darion Mograine
(@CGUID+0, 176554, 1, 1637, 8618, '0', 16448, 0, 0, 0, 1596.546875, -4381.8818359375, 20.11281394958496093, 3.659459114074707031, 120, 0, 0, 186925, 45175, 0, 0, 0, 0, 38134), -- Highlord Darion Mograine (Area: -Unknown- - Difficulty: 0)
-- Nazgrim
(@CGUID+1, 171791, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1598.939208984375, -4382.73095703125, 20.25117301940917968, 3.740239381790161132, 120, 0, 0, 112155, 0, 0, 0, 0, 0, 38134), -- Nazgrim (Area: -Unknown- - Difficulty: 0)
-- Orgrimmar Grunt
(@CGUID+2, 173279, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1602.392333984375, -4393.05908203125, 18.4881591796875, 2.33484649658203125, 120, 0, 0, 17687, 0, 0, 0, 0, 0, 38134), -- Orgrimmar Grunt (Area: -Unknown- - Difficulty: 0) (Auras: )
(@CGUID+3, 173279, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1606.6614990234375, -4389.59033203125, 19.99199867248535156, 2.686850309371948242, 120, 0, 0, 17687, 0, 0, 0, 0, 0, 38134), -- Orgrimmar Grunt (Area: -Unknown- - Difficulty: 0) (Auras: )
(@CGUID+4, 173279, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1594.626708984375, -4369.7412109375, 21.27612495422363281, 4.686401844024658203, 120, 0, 0, 17687, 0, 0, 0, 0, 0, 38134), -- Orgrimmar Grunt (Area: -Unknown- - Difficulty: 0) (Auras: )
(@CGUID+5, 173279, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1605.3072509765625, -4392.173828125, 19.05565071105957031, 2.54192972183227539, 120, 0, 0, 17687, 0, 0, 0, 0, 0, 38134), -- Orgrimmar Grunt (Area: -Unknown- - Difficulty: 0) (Auras: )
(@CGUID+6, 173279, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1598.0625, -4393.798828125, 18.05163192749023437, 1.585963606834411621, 120, 0, 0, 17687, 0, 0, 0, 0, 0, 38134), -- Orgrimmar Grunt (Area: -Unknown- - Difficulty: 0) (Auras: )
(@CGUID+7, 173279, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1583.0989990234375, -4375.4599609375, 20.3298492431640625, 5.958539485931396484, 120, 0, 0, 17687, 0, 0, 0, 0, 0, 38134), -- Orgrimmar Grunt (Area: -Unknown- - Difficulty: 0) (Auras: )
(@CGUID+8, 173279, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1596.951416015625, -4366.64599609375, 21.15838050842285156, 4.124737739562988281, 120, 0, 0, 17687, 0, 0, 0, 0, 0, 38134), -- Orgrimmar Grunt (Area: -Unknown- - Difficulty: 0) (Auras: )
(@CGUID+9, 173279, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1597.986083984375, -4369.31591796875, 21.32096290588378906, 4.266610622406005859, 120, 0, 0, 17687, 0, 0, 0, 0, 0, 38134), -- Orgrimmar Grunt (Area: -Unknown- - Difficulty: 0) (Auras: )
(@CGUID+10, 173279, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1601.3646240234375, -4395.87158203125, 17.53847885131835937, 2.060830593109130859, 120, 0, 0, 17687, 0, 0, 0, 0, 0, 38134), -- Orgrimmar Grunt (Area: -Unknown- - Difficulty: 0) (Auras: )
(@CGUID+11, 173279, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1582.7117919921875, -4372.65087890625, 20.59259033203125, 5.621002197265625, 120, 0, 0, 17687, 0, 0, 0, 0, 0, 38134), -- Orgrimmar Grunt (Area: -Unknown- - Difficulty: 0) (Auras: )
(@CGUID+12, 173279, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1602.5521240234375, -4389.4775390625, 19.441741943359375, 2.42626500129699707, 120, 0, 0, 17687, 0, 0, 0, 0, 0, 38134), -- Orgrimmar Grunt (Area: -Unknown- - Difficulty: 0) (Auras: )
(@CGUID+13, 173279, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1580.3975830078125, -4375.859375, 20.13587570190429687, 5.946003913879394531, 120, 0, 0, 17687, 0, 0, 0, 0, 0, 38134), -- Orgrimmar Grunt (Area: -Unknown- - Difficulty: 0) (Auras: )
(@CGUID+14, 173279, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1581.90283203125, -4377.73974609375, 19.81879997253417968, 6.058449745178222656, 120, 0, 0, 17687, 0, 0, 0, 0, 0, 38134), -- Orgrimmar Grunt (Area: -Unknown- - Difficulty: 0) (Auras: )
-- Knight of the Ebon Blade
(@CGUID+15, 169177, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1590.34033203125, -4378.5, 19.91173744201660156, 2.393826484680175781, 120, 0, 0, 7477, 1807, 0, 0, 0, 0, 38134), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+16, 169177, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1588.8489990234375, -4381.4130859375, 19.20941162109375, 2.873449563980102539, 120, 0, 0, 7477, 1807, 0, 0, 0, 0, 38134), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+17, 169177, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1601.032958984375, -4386.21337890625, 19.85976982116699218, 5.448757171630859375, 120, 0, 0, 7477, 1807, 0, 0, 0, 0, 38134), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+18, 169177, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1596.80908203125, -4388.59716796875, 18.87882614135742187, 4.734880447387695312, 120, 0, 0, 7477, 1807, 0, 0, 0, 0, 38134), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+19, 169177, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1599.2603759765625, -4376.71337890625, 20.95309257507324218, 1.117129445075988769, 120, 0, 0, 7477, 1807, 0, 0, 0, 0, 38134), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+20, 169177, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1595.2396240234375, -4375.35791015625, 20.7305755615234375, 1.574090123176574707, 120, 0, 0, 7477, 1807, 0, 0, 0, 0, 38134), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+21, 169177, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1602.6632080078125, -4384.033203125, 20.34967422485351562, 6.105090141296386718, 120, 0, 0, 7477, 1807, 0, 0, 0, 0, 38134), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+22, 169177, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1593.373291015625, -4388.111328125, 18.47126197814941406, 4.669833183288574218, 120, 0, 0, 7477, 1807, 0, 0, 0, 0, 38134), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
-- Concerned Onlooker
(@CGUID+23, 173281, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1613.44970703125, -4394.81591796875, 19.32597923278808593, 2.209622621536254882, 120, 0, 0, 7477, 0, 0, 0, 0, 0, 38134), -- Concerned Onlooker (Area: -Unknown- - Difficulty: 0)
(@CGUID+24, 173281, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1610.71875, -4393.54541015625, 19.62863922119140625, 0.552337467670440673, 120, 0, 0, 7477, 0, 0, 0, 0, 0, 38134), -- Concerned Onlooker (Area: -Unknown- - Difficulty: 0)
(@CGUID+25, 173281, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1605.43408203125, -4385.7880859375, 20.48834991455078125, 0.503955304622650146, 120, 0, 0, 7477, 0, 0, 0, 0, 0, 38134), -- Concerned Onlooker (Area: -Unknown- - Difficulty: 0)
(@CGUID+26, 173281, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1592.6302490234375, -4365.1162109375, 21.09588813781738281, 4.900725364685058593, 120, 0, 0, 7477, 0, 0, 0, 0, 0, 38134), -- Concerned Onlooker (Area: -Unknown- - Difficulty: 0)
(@CGUID+27, 173281, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1583.8194580078125, -4387.9755859375, 17.79204750061035156, 1.526206493377685546, 120, 0, 0, 7477, 0, 0, 0, 0, 0, 38134), -- Concerned Onlooker (Area: -Unknown- - Difficulty: 0)
(@CGUID+28, 173281, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1584.2742919921875, -4385.73095703125, 17.87681198120117187, 4.402769088745117187, 120, 0, 0, 7477, 0, 0, 0, 0, 0, 38134), -- Concerned Onlooker (Area: -Unknown- - Difficulty: 0)
(@CGUID+29, 173281, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1588.71875, -4390.01220703125, 18.20344734191894531, 0.793151140213012695, 120, 0, 0, 7477, 0, 0, 0, 0, 0, 38134), -- Concerned Onlooker (Area: -Unknown- - Difficulty: 0)
(@CGUID+30, 173281, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1605.9410400390625, -4396.31591796875, 17.54245567321777343, 2.35004425048828125, 120, 0, 0, 7477, 0, 0, 0, 0, 0, 38134), -- Concerned Onlooker (Area: -Unknown- - Difficulty: 0)
(@CGUID+31, 173281, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1606.984375, -4384.4443359375, 20.7737884521484375, 3.663200855255126953, 120, 0, 0, 7477, 0, 0, 0, 0, 0, 38134), -- Concerned Onlooker (Area: -Unknown- - Difficulty: 0)
(@CGUID+32, 173281, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1612.5850830078125, -4392.37841796875, 20.49319839477539062, 4.416680812835693359, 120, 0, 0, 7477, 0, 0, 0, 0, 0, 38134), -- Concerned Onlooker (Area: -Unknown- - Difficulty: 0)
(@CGUID+33, 173281, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1594.1163330078125, -4395.90087890625, 17.3592071533203125, 2.14967203140258789, 120, 0, 0, 7477, 0, 0, 0, 0, 0, 38134), -- Concerned Onlooker (Area: -Unknown- - Difficulty: 0)
(@CGUID+34, 173281, 1, 1637, 8618, '0', 16447, 0, 0, 0, 1577.673583984375, -4380.7880859375, 18.074951171875, 6.17918252944946289, 120, 0, 0, 7477, 0, 0, 0, 0, 0, 38134), -- Concerned Onlooker (Area: -Unknown- - Difficulty: 0)
-- Nazgrim and two Ebon Blade Knights (Portal back to Maw after using it for the first time from Orgrimmar)
(@CGUID+35, 171791, 1, 1637, 5170, '0', 16450, 0, 0, 0, 1595.654541015625, -4350.970703125, 21.2030029296875, 4.991054534912109375, 120, 0, 0, 112155, 0, 0, 0, 0, 0, 38134), -- Nazgrim (Area: Valley of Strength - Difficulty: 0)
(@CGUID+36, 169177, 1, 1637, 5170, '0', 16450, 0, 0, 0, 1596.02783203125, -4348.5224609375, 21.2030029296875, 3.124286413192749023, 120, 0, 0, 7477, 1807, 0, 0, 0, 0, 38134), -- Knight of the Ebon Blade (Area: Valley of Strength - Difficulty: 0) (Auras: 335247 - -Unknown-)
(@CGUID+37, 169177, 1, 1637, 5170, '0', 16450, 0, 0, 0, 1587.782958984375, -4352.751953125, 21.20301055908203125, 0.944541215896606445, 120, 0, 0, 7477, 1807, 0, 0, 0, 0, 38134); -- Knight of the Ebon Blade (Area: Valley of Strength - Difficulty: 0) (Auras: 335247 - -Unknown-)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+37;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+23, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Concerned Onlooker
(@CGUID+24, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Concerned Onlooker
(@CGUID+25, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Concerned Onlooker
(@CGUID+26, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Concerned Onlooker
(@CGUID+27, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Concerned Onlooker
(@CGUID+28, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Concerned Onlooker
(@CGUID+29, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Concerned Onlooker
(@CGUID+30, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Concerned Onlooker
(@CGUID+31, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Concerned Onlooker
(@CGUID+32, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Concerned Onlooker
(@CGUID+33, 0, 0, 0, 1, 578, 0, 0, 0, ''), -- Concerned Onlooker
(@CGUID+34, 0, 0, 0, 1, 578, 0, 0, 0, ''), -- Concerned Onlooker
(@CGUID+36, 0, 0, 0, 1, 0, 0, 0, 0, '335247'), -- Knight of the Ebon Blade - 335247 - -Unknown-
(@CGUID+37, 0, 0, 0, 1, 0, 0, 0, 0, '335247'); -- Knight of the Ebon Blade - 335247 - -Unknown-

-- Portal itself does not have any assigned phase
-- the initial Acherus portal is a personal spawn even (when Darion Mograine creates it), is static personal spawning w/o phases a thing?
-- INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- initial (spawned by darion)
-- (@OGUID+0, 355461, 1, 1637, 5170, '0',  '13564 - 16447 - 16448 - 7688 - 10984 - 8658 - 12910 - 11965 - 11695 - 14852 - 16786 - 10351 - 10352 - 10353 - 16797 - 11596 - 4063 - 11744 - 6691 - 14647 - 11908 - 10401 - 1230', 0, 1591.545166015625, -4349.58349609375, 21.11966896057128906, 2.161438465118408203, 0, 0, 0.882296562194824218, 0.470693945884704589, 120, 255, 0, 38134), -- Death Gate to Acherus (Area: Valley of Strength - Difficulty: 0)
-- after first quest is rewarded one of these is spawned depending on progress
-- (@OGUID+1, 355461, 1, 1637, 5170, '0', '13564 - 16450 - 7688 - 10984 - 8658 - 12910 - 11965 - 11695 - 14852 - 16786 - 10351 - 10352 - 10353 - 11596 - 4063 - 11744 - 6691 - 14647 - 11908 - 10401 - 1230', 0, 1591.545166015625, -4349.58349609375, 21.11966896057128906, 2.161438465118408203, 0, 0, 0.882296562194824218, 0.470693945884704589, 120, 255, 0, 38134), -- Death Gate to Acherus (Area: Valley of Strength - Difficulty: 0)
-- (@OGUID+2, 355479, 1, 1637, 8618, '0', '13564 - 16450 - 7688 - 10984 - 8658 - 12910 - 11965 - 11695 - 14852 - 10351 - 10352 - 10353 - 11596 - 4063 - 11744 - 6691 - 14647 - 11908 - 10401 - 1230', 0, 1591.545166015625, -4349.58349609375, 21.11966896057128906, 2.161438465118408203, 0, 0, 0.882296562194824218, 0.470693945884704589, 120, 255, 0, 38134), -- Death Gate to the Maw (Area: -Unknown- - Difficulty: 0)
-- (@OGUID+3, 355480, 1, 1637, 8618, '0', '13564 - 16450 - 7688 - 10984 - 8658 - 12910 - 11965 - 11695 - 14852 - 10351 - 10352 - 10353 - 11596 - 4063 - 11744 - 6691 - 14647 - 11908 - 10401 - 1230', 0, 1591.545166015625, -4349.58349609375, 21.11966896057128906, 2.161438465118408203, 0, 0, 0.882296562194824218, 0.470693945884704589, 120, 255, 0, 38134), -- Death Gate to the Maw (Area: -Unknown- - Difficulty: 0)

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=173281;
DELETE FROM `smart_scripts` WHERE `entryorguid`=-(@CGUID+27) AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_chance`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `target_type`, `comment`) VALUES
(-(@CGUID+27), 0, 0, 0, 1, 100, 6000, 8000, 6000, 8000, 10, 396, 274, 273, 6, 1, "Concerned Onlooker - Out of Combat - Play Random Emote");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN(14, 15) AND SourceGroup=26057;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 26057, 41745, 0, 0, 48, 0, 406784, 0, 0, 0, 0, 0, "", "Show gossip text if player has quest objective done: Take the Death Gate to Acherus"),
(14, 26057, 41745, 0, 1, 8, 0, 61874, 0, 0, 0, 0, 0, "", "Show gossip text if player has quest 61874 rewarded"),
(14, 26057, 41744, 0, 0, 48, 0, 406783, 0, 0, 1, 0, 0, "", "Show gossip text if player has not quest objective done: Learn about your leaders' fate"),
(14, 26057, 41398, 0, 0, 48, 0, 406783, 0, 0, 0, 0, 0, "", "Show gossip text if player has quest objective done: Learn about your leaders' fate"),
(14, 26057, 41398, 0, 0, 48, 0, 406784, 0, 0, 1, 0, 0, "", "Show gossip text if player has not quest objective done: Take the Death Gate to Acherus"),
(15, 26057, 0, 0, 0, 8, 0, 61874, 0, 0, 1, 0, 0, "", "Show gossip text if player has not quest 61874 rewarded"),
(15, 26057, 0, 0, 0, 48, 0, 406783, 0, 0, 1, 0, 0, "", "Show gossip option if player has not quest objective done: Learn about your leaders' fate");
