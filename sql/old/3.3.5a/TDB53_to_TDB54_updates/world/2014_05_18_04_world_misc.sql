--
SET @CGUID := 68279; -- set by TDB team (3)
SET @OGUID := 6134; -- set by TDB team (2)

DELETE FROM `spell_area` WHERE `spell`=71314;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(71314, 4862, 24559, 24562, 0, 0, 2, 1, 74, 11);

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(@CGUID+0, 0, 0, 0x10000, 0x1, 0, '71312'),
(@CGUID+1, 0, 0, 0x10000, 0x1, 0, '71312'),
(@CGUID+2, 0, 0, 0x10000, 0x1, 0, '71312');

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 36657, 571, 1, 1, 5630.028, 2082.906, 798.1375, 0, 120, 0, 0), -- Sunreaver War Mage (Area: 210)
(@CGUID+1, 36642, 571, 1, 1, 5630.374, 2087.88, 798.1375, 6.213372, 120, 0, 0), -- Myralion Sunblaze (Area: 210)
(@CGUID+2, 36657, 571, 1, 1, 5631.038, 2092.561, 798.1375, 6.143559, 120, 0, 0); -- Sunreaver War Mage (Area: 210)

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 202192, 571, 1, 1, 5628.946, 2079.644, 798.0542, 0.6457717, 0, 0, 0, 1, 120, 255, 1), -- Sunreaver Banner (Area: 210)
(@OGUID+1, 202192, 571, 1, 1, 5630.607, 2096.247, 798.0542, 5.881761, 0, 0, 0, 1, 120, 255, 1); -- Sunreaver Banner (Area: 210)

DELETE FROM `gameobject_template` WHERE `entry`=202192;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES 
(202192, 5, 6794, 'Sunreaver Banner', '', '', '', 0, 0, 0.8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 16992);
