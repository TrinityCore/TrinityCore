SET @CGUID := 223912;
SET @OGUID := 166877;

SET @SPAWNGROUP := 1201;

DELETE FROM `spell_area` WHERE `spell` IN (68719, 68720);
INSERT INTO `spell_area` (`spell`, `area`, `gender`, `flags`) VALUES
(68719, 4710, 2, 0x3),
(68720, 4710, 2, 0x3);

DELETE FROM `conditions` where `SourceTypeOrReferenceId` = 17 AND `SourceEntry` IN (68719, 68720);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 68720, 0, 0, 11, 4308, 1, 0, 0, 0, 0, '', 'Isle of Conquest - Spell - Quarry - Horde Controlled'),
(17, 0, 68720, 0, 0, 6, 67, 0, 0, 0, 0, 0, '', 'Isle of Conquest - Spell - Quarry - Team Horde'),
(17, 0, 68720, 0, 1, 11, 4309, 1, 0, 0, 0, 0, '', 'Isle of Conquest - Spell - Quarry - Alliance Controlled'),
(17, 0, 68720, 0, 1, 6, 469, 0, 0, 0, 0, 0, '', 'Isle of Conquest - Spell - Quarry - Team Alliance'),
(17, 0, 68719, 0, 0, 11, 4313, 1, 0, 0, 0, 0, '', 'Isle of Conquest - Spell - Oil Refinery - Horde Controlled'),
(17, 0, 68719, 0, 0, 6, 67, 0, 0, 0, 0, 0, '', 'Isle of Conquest - Spell - Oil Refinery - Team Horde'),
(17, 0, 68719, 0, 1, 11, 4314, 1, 0, 0, 0, 0, '', 'Isle of Conquest - Spell - Oil Refinery - Alliance Controlled'),
(17, 0, 68719, 0, 1, 6, 469, 0, 0, 0, 0, 0, '', 'Isle of Conquest - Spell - Oil Refinery - Team Alliance');

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWNGROUP+0 AND @SPAWNGROUP+1000;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWNGROUP+0, 'Isle of Conquest - Horde Keep - Horde Controlled - Banner & Spirit Guide', 0x20),
(@SPAWNGROUP+1, 'Isle of Conquest - Horde Keep - Horde Contested - Banner', 0x20),
(@SPAWNGROUP+2, 'Isle of Conquest - Horde Keep - Alliance Contested - Banner', 0x20),
(@SPAWNGROUP+3, 'Isle of Conquest - Horde Keep - Alliance Controlled - Banner & Spirit Guide', 0x20),

(@SPAWNGROUP+4, 'Isle of Conquest - Alliance Keep - Horde Controlled - Banner & Spirit Guide', 0x20),
(@SPAWNGROUP+5, 'Isle of Conquest - Alliance Keep - Horde Contested - Banner', 0x20),
(@SPAWNGROUP+6, 'Isle of Conquest - Alliance Keep - Alliance Contested - Banner', 0x20),
(@SPAWNGROUP+7, 'Isle of Conquest - Alliance Keep - Alliance Controlled - Banner & Spirit Guide', 0x20),

(@SPAWNGROUP+8, 'Isle of Conquest - Quarry - Neutral Controlled - Banner', 0x20),
(@SPAWNGROUP+9, 'Isle of Conquest - Quarry - Horde Controlled - Banner & Miners', 0x20),
(@SPAWNGROUP+10, 'Isle of Conquest - Quarry - Horde Contested - Banner', 0x20),
(@SPAWNGROUP+11, 'Isle of Conquest - Quarry - Alliance Contested - Banner', 0x20),
(@SPAWNGROUP+12, 'Isle of Conquest - Quarry - Alliance Controlled - Banner & Miners', 0x20),

(@SPAWNGROUP+13, 'Isle of Conquest - Refinery - Neutral Controlled - Banner', 0x20),
(@SPAWNGROUP+14, 'Isle of Conquest - Refinery - Horde Controlled - Banner', 0x20),
(@SPAWNGROUP+15, 'Isle of Conquest - Refinery - Horde Contested - Banner', 0x20),
(@SPAWNGROUP+16, 'Isle of Conquest - Refinery - Alliance Contested - Banner', 0x20),
(@SPAWNGROUP+17, 'Isle of Conquest - Refinery - Alliance Controlled - Banner', 0x20),

(@SPAWNGROUP+18, 'Isle of Conquest - Docks - Neutral Controlled - Banner', 0x20),
(@SPAWNGROUP+19, 'Isle of Conquest - Docks - Horde Controlled - Banner & Spirit Guide', 0x20),
(@SPAWNGROUP+20, 'Isle of Conquest - Docks - Horde Contested - Banner', 0x20),
(@SPAWNGROUP+21, 'Isle of Conquest - Docks - Alliance Contested - Banner', 0x20),
(@SPAWNGROUP+22, 'Isle of Conquest - Docks - Alliance Controlled - Banner & Spirit Guide', 0x20),
(@SPAWNGROUP+23, 'Isle of Conquest - Docks - Horde Controlled - Vehicles', 0x0),
(@SPAWNGROUP+24, 'Isle of Conquest - Docks - Alliance Controlled - Vehicles', 0x0),

(@SPAWNGROUP+25, 'Isle of Conquest - Workshop - Neutral Controlled - Banner', 0x20),
(@SPAWNGROUP+26, 'Isle of Conquest - Workshop - Horde Controlled - Banner & Spirit Guide & Bombs', 0x20),
(@SPAWNGROUP+27, 'Isle of Conquest - Workshop - Horde Contested - Banner', 0x20),
(@SPAWNGROUP+28, 'Isle of Conquest - Workshop - Alliance Contested - Banner', 0x20),
(@SPAWNGROUP+29, 'Isle of Conquest - Workshop - Alliance Controlled - Banner & Spirit Guide & Bombs', 0x20),
(@SPAWNGROUP+30, 'Isle of Conquest - Workshop - Horde Controlled - Vehicles', 0x0),
(@SPAWNGROUP+31, 'Isle of Conquest - Workshop - Alliance Controlled - Vehicles', 0x0),

(@SPAWNGROUP+32, 'Isle of Conquest - Hangar - Neutral Controlled - Banner', 0x20),
(@SPAWNGROUP+33, 'Isle of Conquest - Hangar - Horde Controlled - Banner & Spirit Guide & Teleporter', 0x20),
(@SPAWNGROUP+34, 'Isle of Conquest - Hangar - Horde Contested - Banner', 0x20),
(@SPAWNGROUP+35, 'Isle of Conquest - Hangar - Alliance Contested - Banner', 0x20),
(@SPAWNGROUP+36, 'Isle of Conquest - Hangar - Alliance Controlled - Banner & Spirit Guide & Teleporter', 0x20),

(@SPAWNGROUP+37, 'Isle of Conquest - Horde Keep - Breached', 0x20),
(@SPAWNGROUP+38, 'Isle of Conquest - Alliance Keep - Breached', 0x20),

(@SPAWNGROUP+39, 'Isle of Conquest - Horde Front Gate - Broken', 0x20),
(@SPAWNGROUP+40, 'Isle of Conquest - Alliance East Gate - Broken', 0x20);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN @SPAWNGROUP+0 AND @SPAWNGROUP+1000;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWNGROUP+0, 1, @OGUID+2),
(@SPAWNGROUP+0, 0, @CGUID+140),
(@SPAWNGROUP+1, 1, @OGUID+145),
(@SPAWNGROUP+2, 1, @OGUID+146),
(@SPAWNGROUP+3, 1, @OGUID+147),
(@SPAWNGROUP+3, 0, @CGUID+147),

(@SPAWNGROUP+4, 1, @OGUID+149),
(@SPAWNGROUP+4, 0, @CGUID+144),
(@SPAWNGROUP+5, 1, @OGUID+99),
(@SPAWNGROUP+6, 1, @OGUID+148),
(@SPAWNGROUP+7, 1, @OGUID+22),
(@SPAWNGROUP+7, 0, @CGUID+143),

(@SPAWNGROUP+8, 1, @OGUID+16),
(@SPAWNGROUP+9, 1, @OGUID+44),

(@SPAWNGROUP+9, 0, @OGUID+326), -- honorable defender
(@SPAWNGROUP+9, 0, @CGUID+80), -- Forsaken miners
(@SPAWNGROUP+9, 0, @CGUID+81),
(@SPAWNGROUP+9, 0, @CGUID+82),
(@SPAWNGROUP+9, 0, @CGUID+83),
(@SPAWNGROUP+9, 0, @CGUID+84),
(@SPAWNGROUP+9, 0, @CGUID+85),
(@SPAWNGROUP+9, 0, @CGUID+86),
(@SPAWNGROUP+9, 0, @CGUID+87),
(@SPAWNGROUP+9, 0, @CGUID+88),
(@SPAWNGROUP+9, 0, @CGUID+89),
(@SPAWNGROUP+9, 0, @CGUID+90),
(@SPAWNGROUP+9, 0, @CGUID+91),
(@SPAWNGROUP+9, 0, @CGUID+92),

(@SPAWNGROUP+10, 1, @OGUID+43),
(@SPAWNGROUP+11, 1, @OGUID+24),
(@SPAWNGROUP+12, 1, @OGUID+29),
(@SPAWNGROUP+12, 0, @CGUID+150),
(@SPAWNGROUP+12, 0, @CGUID+47), -- Human miners
(@SPAWNGROUP+12, 0, @CGUID+48),
(@SPAWNGROUP+12, 0, @CGUID+49),
(@SPAWNGROUP+12, 0, @CGUID+50),
(@SPAWNGROUP+12, 0, @CGUID+51),
(@SPAWNGROUP+12, 0, @CGUID+52),
(@SPAWNGROUP+12, 0, @CGUID+53),
(@SPAWNGROUP+12, 0, @CGUID+54),
(@SPAWNGROUP+12, 0, @CGUID+55),
(@SPAWNGROUP+12, 0, @CGUID+56),
(@SPAWNGROUP+12, 0, @CGUID+57),
(@SPAWNGROUP+12, 0, @CGUID+59),
(@SPAWNGROUP+12, 0, @CGUID+60),

(@SPAWNGROUP+13, 1, @OGUID+100),
(@SPAWNGROUP+14, 1, @OGUID+78),
(@SPAWNGROUP+14, 0, @CGUID+157),
(@SPAWNGROUP+15, 1, @OGUID+142),
(@SPAWNGROUP+16, 1, @OGUID+144),
(@SPAWNGROUP+17, 1, @OGUID+143),
(@SPAWNGROUP+17, 0, @CGUID+158),

(@SPAWNGROUP+18, 1, @OGUID+141),
(@SPAWNGROUP+19, 1, @OGUID+45),
(@SPAWNGROUP+19, 0, @CGUID+72),
(@SPAWNGROUP+19, 0, @CGUID+155),
(@SPAWNGROUP+20, 1, @OGUID+138),
(@SPAWNGROUP+21, 1, @OGUID+140),
(@SPAWNGROUP+22, 1, @OGUID+139),
(@SPAWNGROUP+22, 0, @CGUID+139),
(@SPAWNGROUP+22, 0, @CGUID+156),

(@SPAWNGROUP+23, 0, @CGUID+75),
(@SPAWNGROUP+23, 0, @CGUID+73),
(@SPAWNGROUP+23, 0, @CGUID+74),
(@SPAWNGROUP+23, 0, @CGUID+99),
(@SPAWNGROUP+23, 0, @CGUID+77),
(@SPAWNGROUP+23, 0, @CGUID+78),
(@SPAWNGROUP+23, 0, @CGUID+76),

(@SPAWNGROUP+24, 0, @CGUID+125),
(@SPAWNGROUP+24, 0, @CGUID+123),
(@SPAWNGROUP+24, 0, @CGUID+124),
(@SPAWNGROUP+24, 0, @CGUID+126),
(@SPAWNGROUP+24, 0, @CGUID+128),
(@SPAWNGROUP+24, 0, @CGUID+129),
(@SPAWNGROUP+24, 0, @CGUID+127),

(@SPAWNGROUP+25, 1, @OGUID+6),
(@SPAWNGROUP+26, 1, @OGUID+26),
(@SPAWNGROUP+26, 0, @CGUID+43),
(@SPAWNGROUP+26, 0, @CGUID+153),
(@SPAWNGROUP+26, 1, @OGUID+27),
(@SPAWNGROUP+26, 1, @OGUID+28),
(@SPAWNGROUP+27, 1, @OGUID+9),
(@SPAWNGROUP+28, 1, @OGUID+137),
(@SPAWNGROUP+29, 1, @OGUID+136),
(@SPAWNGROUP+29, 0, @CGUID+146),
(@SPAWNGROUP+29, 0, @CGUID+154),
(@SPAWNGROUP+29, 1, @OGUID+150),
(@SPAWNGROUP+29, 1, @OGUID+151),

(@SPAWNGROUP+30, 0, @CGUID+45),
(@SPAWNGROUP+30, 0, @CGUID+42),
(@SPAWNGROUP+30, 0, @CGUID+41),
(@SPAWNGROUP+30, 0, @CGUID+44),
(@SPAWNGROUP+30, 0, @CGUID+46),

(@SPAWNGROUP+31, 0, @CGUID+137),
(@SPAWNGROUP+31, 0, @CGUID+135),
(@SPAWNGROUP+31, 0, @CGUID+134),
(@SPAWNGROUP+31, 0, @CGUID+136),
(@SPAWNGROUP+31, 0, @CGUID+138),

(@SPAWNGROUP+32, 1, @OGUID+8),
(@SPAWNGROUP+33, 1, @OGUID+30),
(@SPAWNGROUP+33, 1, @OGUID+35),
(@SPAWNGROUP+33, 1, @OGUID+36),
(@SPAWNGROUP+33, 1, @OGUID+34),
(@SPAWNGROUP+33, 1, @OGUID+31),
(@SPAWNGROUP+33, 1, @OGUID+33),
(@SPAWNGROUP+33, 1, @OGUID+32),
(@SPAWNGROUP+33, 0, @CGUID+64),
(@SPAWNGROUP+33, 0, @CGUID+151),
(@SPAWNGROUP+33, 0, @CGUID+194),
(@SPAWNGROUP+34, 1, @OGUID+25),
(@SPAWNGROUP+35, 1, @OGUID+135),
(@SPAWNGROUP+36, 1, @OGUID+134),
(@SPAWNGROUP+36, 0, @CGUID+145),
(@SPAWNGROUP+36, 0, @CGUID+152),
(@SPAWNGROUP+36, 0, @CGUID+195),
(@SPAWNGROUP+36, 1, @OGUID+152),
(@SPAWNGROUP+36, 1, @OGUID+153),
(@SPAWNGROUP+36, 1, @OGUID+154),
(@SPAWNGROUP+36, 1, @OGUID+155),
(@SPAWNGROUP+36, 1, @OGUID+156),
(@SPAWNGROUP+36, 1, @OGUID+157),

(@SPAWNGROUP+37, 0, @CGUID+208),
(@SPAWNGROUP+37, 0, @CGUID+209),
(@SPAWNGROUP+37, 0, @CGUID+210),
(@SPAWNGROUP+37, 0, @CGUID+211),
(@SPAWNGROUP+37, 0, @CGUID+212),
(@SPAWNGROUP+37, 0, @CGUID+213),
(@SPAWNGROUP+37, 0, @CGUID+214),
(@SPAWNGROUP+37, 0, @CGUID+215),
(@SPAWNGROUP+37, 0, @CGUID+216),

(@SPAWNGROUP+38, 0, @CGUID+199),
(@SPAWNGROUP+38, 0, @CGUID+200),
(@SPAWNGROUP+38, 0, @CGUID+201),
(@SPAWNGROUP+38, 0, @CGUID+202),
(@SPAWNGROUP+38, 0, @CGUID+203),
(@SPAWNGROUP+38, 0, @CGUID+204),
(@SPAWNGROUP+38, 0, @CGUID+205),
(@SPAWNGROUP+38, 0, @CGUID+206),
(@SPAWNGROUP+38, 0, @CGUID+207),

(@SPAWNGROUP+39, 0, @CGUID+196),
(@SPAWNGROUP+39, 0, @CGUID+197),
(@SPAWNGROUP+39, 0, @CGUID+198),

(@SPAWNGROUP+40, 0, @CGUID+130),
(@SPAWNGROUP+40, 0, @CGUID+131),
(@SPAWNGROUP+40, 0, @CGUID+132),
(@SPAWNGROUP+40, 0, @CGUID+133);

DELETE FROM `graveyard_zone` WHERE `ID` IN (1480, 1481, 1482, 1483, 1484, 1485, 1486);
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(1480, 4710, 'Isle of Conquest - Docks'),
(1481, 4710, 'Isle of Conquest - Airport'),
(1482, 4710, 'Isle of Conquest - Workshop'),
(1483, 4710, 'Isle of Conquest - Alliance Default'),
(1484, 4710, 'Isle of Conquest - Horde Default'),
(1485, 4710, 'Isle of Conquest - Alliance Keep'),
(1486, 4710, 'Isle of Conquest - Horde Keep');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 27 AND `SourceEntry` IN (1480, 1481, 1482, 1483, 1484, 1485, 1486);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
-- Docks
-- -- Alliance
(27, 1480, 4710, 0, 6, 469, 0, 'Graveyard - Isle of Conquest - Docks - Team Alliance'),
(27, 1480, 4710, 0, 11, 4304, 1, 'Graveyard - Isle of Conquest - Docks - Alliance Controlled'),
-- -- Horde
(27, 1480, 4710, 1, 6, 67, 0, 'Graveyard - Isle of Conquest - Docks - Team Horde'),
(27, 1480, 4710, 1, 11, 4303, 1, 'Graveyard - Isle of Conquest - Docks - Horde Controlled'),
-- Hangar
-- -- Alliance
(27, 1481, 4710, 0, 6, 469, 0, 'Graveyard - Isle of Conquest - Hangar - Team Alliance'),
(27, 1481, 4710, 0, 11, 4299, 1, 'Graveyard - Isle of Conquest - Hangar - Alliance Controlled'),
-- -- Horde
(27, 1481, 4710, 1, 6, 67, 0, 'Graveyard - Isle of Conquest - Hangar - Team Horde'),
(27, 1481, 4710, 1, 11, 4298, 1, 'Graveyard - Isle of Conquest - Hangar - Horde Controlled'),
-- Workshop
-- -- Alliance
(27, 1482, 4710, 0, 6, 469, 0, 'Graveyard - Isle of Conquest - Workshop - Team Alliance'),
(27, 1482, 4710, 0, 11, 4229, 1, 'Graveyard - Isle of Conquest - Workshop - Alliance Controlled'),
-- -- Horde
(27, 1482, 4710, 1, 6, 67, 0, 'Graveyard - Isle of Conquest - Workshop - Team Horde'),
(27, 1482, 4710, 1, 11, 4230, 1, 'Graveyard - Isle of Conquest - Workshop - Horde Controlled'),
-- Defaults (fallback)
-- -- Alliance
(27, 1483, 4710, 0, 6, 469, 0, 'Graveyard - Isle of Conquest - Alliance Base - Team Alliance'),
(27, 1483, 4710, 0, 11, 4339, 0, 'Graveyard - Isle of Conquest - Alliance Base - Keep NOT Alliance Controlled'),
-- -- Horde
(27, 1484, 4710, 1, 6, 67, 0, 'Graveyard - Isle of Conquest - Horde Base - Team Horde'),
(27, 1484, 4710, 1, 11, 4345, 0, 'Graveyard - Isle of Conquest - Horde Base - Keep NOT Horde Controlled'),
-- Alliance Keep
-- -- Alliance
(27, 1485, 4710, 0, 6, 469, 0, 'Graveyard - Isle of Conquest - Alliance Keep - Team Alliance'),
(27, 1485, 4710, 0, 11, 4339, 1, 'Graveyard - Isle of Conquest - Alliance Keep - Alliance Controlled'),
-- -- Horde
(27, 1485, 4710, 1, 6, 67, 0, 'Graveyard - Isle of Conquest - Alliance Keep - Team Horde'),
(27, 1485, 4710, 1, 11, 4340, 1, 'Graveyard - Isle of Conquest - Alliance Keep - Horde Controlled'),
-- Horde Keep
-- -- Alliance
(27, 1486, 4710, 0, 6, 469, 0, 'Graveyard - Isle of Conquest - Horde Keep - Team Alliance'),
(27, 1486, 4710, 0, 11, 4344, 1, 'Graveyard - Isle of Conquest - Horde Keep - Alliance Controlled'),
-- -- Horde
(27, 1486, 4710, 1, 6, 67, 0, 'Graveyard - Isle of Conquest - Horde Keep - Team Horde'),
(27, 1486, 4710, 1, 11, 4345, 1, 'Graveyard - Isle of Conquest - Horde Keep - Horde Controlled');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=33 AND `SourceEntry` BETWEEN @SPAWNGROUP+0 AND @SPAWNGROUP+1000;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
(33, @SPAWNGROUP+0, 0, 11, 4345, 1, 'Isle of Conquest - Spawn Group - Horde Keep - Horde Controlled'),
(33, @SPAWNGROUP+1, 0, 11, 4348, 1, 'Isle of Conquest - Spawn Group - Horde Keep - Horde Contested'),
(33, @SPAWNGROUP+2, 0, 11, 4347, 1, 'Isle of Conquest - Spawn Group - Horde Keep - Alliance Contested'),
(33, @SPAWNGROUP+3, 0, 11, 4344, 1, 'Isle of Conquest - Spawn Group - Horde Keep - Alliance Controlled'),

(33, @SPAWNGROUP+4, 0, 11, 4340, 1, 'Isle of Conquest - Spawn Group - Alliance Keep - Horde Controlled'),
(33, @SPAWNGROUP+5, 0, 11, 4343, 1, 'Isle of Conquest - Spawn Group - Alliance Keep - Horde Contested'),
(33, @SPAWNGROUP+6, 0, 11, 4342, 1, 'Isle of Conquest - Spawn Group - Alliance Keep - Alliance Contested'),
(33, @SPAWNGROUP+7, 0, 11, 4339, 1, 'Isle of Conquest - Spawn Group - Alliance Keep - Alliance Controlled'),

(33, @SPAWNGROUP+8, 0, 11, 4306, 1, 'Isle of Conquest - Spawn Group - Quarry - Neutral Controlled'),
(33, @SPAWNGROUP+9, 0, 11, 4308, 1, 'Isle of Conquest - Spawn Group - Quarry - Horde Controlled'),
(33, @SPAWNGROUP+10, 0, 11, 4307, 1, 'Isle of Conquest - Spawn Group - Quarry - Horde Contested'),
(33, @SPAWNGROUP+11, 0, 11, 4310, 1, 'Isle of Conquest - Spawn Group - Quarry - Alliance Contested'),
(33, @SPAWNGROUP+12, 0, 11, 4309, 1, 'Isle of Conquest - Spawn Group - Quarry - Alliance Controlled'),

(33, @SPAWNGROUP+13, 0, 11, 4311, 1, 'Isle of Conquest - Spawn Group - Refinery - Neutral Controlled'),
(33, @SPAWNGROUP+14, 0, 11, 4313, 1, 'Isle of Conquest - Spawn Group - Refinery - Horde Controlled'),
(33, @SPAWNGROUP+15, 0, 11, 4312, 1, 'Isle of Conquest - Spawn Group - Refinery - Horde Contested'),
(33, @SPAWNGROUP+16, 0, 11, 4315, 1, 'Isle of Conquest - Spawn Group - Refinery - Alliance Contested'),
(33, @SPAWNGROUP+17, 0, 11, 4314, 1, 'Isle of Conquest - Spawn Group - Refinery - Alliance Controlled'),

(33, @SPAWNGROUP+18, 0, 11, 4301, 1, 'Isle of Conquest - Spawn Group - Docks - Neutral Controlled'),
(33, @SPAWNGROUP+19, 0, 11, 4303, 1, 'Isle of Conquest - Spawn Group - Docks - Horde Controlled'),
(33, @SPAWNGROUP+20, 0, 11, 4302, 1, 'Isle of Conquest - Spawn Group - Docks - Horde Contested'),
(33, @SPAWNGROUP+21, 0, 11, 4305, 1, 'Isle of Conquest - Spawn Group - Docks - Alliance Contested'),
(33, @SPAWNGROUP+22, 0, 11, 4304, 1, 'Isle of Conquest - Spawn Group - Docks - Alliance Controlled'),
(33, @SPAWNGROUP+23, 0, 11, 4303, 1, 'Isle of Conquest - Spawn Group - Docks, Vehicles - Horde Controlled'),
(33, @SPAWNGROUP+24, 0, 11, 4304, 1, 'Isle of Conquest - Spawn Group - Docks, Vehicles - Alliance Controlled'),

(33, @SPAWNGROUP+25, 0, 11, 4294, 1, 'Isle of Conquest - Spawn Group - Workshop - Neutral Controlled'),
(33, @SPAWNGROUP+26, 0, 11, 4230, 1, 'Isle of Conquest - Spawn Group - Workshop - Horde Controlled'),
(33, @SPAWNGROUP+27, 0, 11, 4293, 1, 'Isle of Conquest - Spawn Group - Workshop - Horde Contested'),
(33, @SPAWNGROUP+28, 0, 11, 4228, 1, 'Isle of Conquest - Spawn Group - Workshop - Alliance Contested'),
(33, @SPAWNGROUP+29, 0, 11, 4229, 1, 'Isle of Conquest - Spawn Group - Workshop - Alliance Controlled'),
(33, @SPAWNGROUP+30, 0, 11, 4230, 1, 'Isle of Conquest - Spawn Group - Workshop, Vehicles - Horde Controlled'),
(33, @SPAWNGROUP+31, 0, 11, 4229, 1, 'Isle of Conquest - Spawn Group - Workshop, Vehicles - Alliance Controlled'),

(33, @SPAWNGROUP+32, 0, 11, 4296, 1, 'Isle of Conquest - Spawn Group - Hangar - Neutral Controlled'),
(33, @SPAWNGROUP+33, 0, 11, 4298, 1, 'Isle of Conquest - Spawn Group - Hangar - Horde Controlled'),
(33, @SPAWNGROUP+34, 0, 11, 4297, 1, 'Isle of Conquest - Spawn Group - Hangar - Horde Contested'),
(33, @SPAWNGROUP+35, 0, 11, 4300, 1, 'Isle of Conquest - Spawn Group - Hangar - Alliance Contested'),
(33, @SPAWNGROUP+36, 0, 11, 4299, 1, 'Isle of Conquest - Spawn Group - Hangar - Alliance Controlled'),

(33, @SPAWNGROUP+37, 0, 11, 4322, 1, 'Isle of Conquest - Spawn Group - Horde Keep Breached'),
(33, @SPAWNGROUP+37, 1, 11, 4321, 1, 'Isle of Conquest - Spawn Group - Horde Keep Breached'),
(33, @SPAWNGROUP+37, 2, 11, 4320, 1, 'Isle of Conquest - Spawn Group - Horde Keep Breached'),

(33, @SPAWNGROUP+38, 0, 11, 4323, 1, 'Isle of Conquest - Spawn Group - Alliance Keep Breached'),
(33, @SPAWNGROUP+38, 1, 11, 4324, 1, 'Isle of Conquest - Spawn Group - Alliance Keep Breached'),
(33, @SPAWNGROUP+38, 2, 11, 4325, 1, 'Isle of Conquest - Spawn Group - Alliance Keep Breached'),

(33, @SPAWNGROUP+39, 0, 11, 4322, 1, 'Isle of Conquest - Spawn Group - Horde Front Gate Breached'),
(33, @SPAWNGROUP+40, 0, 11, 4325, 1, 'Isle of Conquest - Spawn Group - Alliance East Gate Breached');

UPDATE `gameobject_template` SET `ScriptName` = 'go_ioc_capturable_object' WHERE `entry` IN (195393,195391,195398,195396,195338,195336,195334,195343,195341,195339,195157,195151,195149,195133,195130,195132,195158,195155,195153);
UPDATE `gameobject_template` SET `ScriptName` = 'go_ioc_contested_object' WHERE `entry` IN (195394,195392,195399,195397,195337,195335,195342,195340,195152,195150,195145,195144,195156,195154);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+10000;
-- Keep cannons
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `StringId`, `VerifiedBuild`) VALUES
(@CGUID+159, 34944, 628, 4710, 4752, '0', 0, 0, 0, 0, 1156.2222900390625, -866.80902099609375, 87.8754425048828125, 4.660028934478759765, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1735', 53007), -- Keep Cannon (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 75925 - Facing Saver, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+160, 34944, 628, 4710, 4752, '0', 0, 0, 0, 0, 1137.7222900390625, -688.51739501953125, 88.402252197265625, 3.31612563133239746, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1735', 53007), -- Keep Cannon (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 75925 - Facing Saver, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+161, 34944, 628, 4710, 4752, '0', 0, 0, 0, 0, 410.142364501953125, -754.515625, 87.79909515380859375, 1.780235767364501953, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1732', 53007), -- Keep Cannon (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 75925 - Facing Saver, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+162, 34944, 628, 4710, 4752, '0', 0, 0, 0, 0, 1138.892333984375, -835.734375, 88.37462615966796875, 2.984513044357299804, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1735', 53007), -- Keep Cannon (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 75925 - Facing Saver, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+163, 34944, 628, 4710, 4752, '0', 0, 0, 0, 0, 1135.1353759765625, -840.73785400390625, 88.0251922607421875, 3.019419670104980468, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1735', 53007), -- Keep Cannon (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 75925 - Facing Saver, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+164, 34944, 628, 4710, 4752, '0', 0, 0, 0, 0, 1160.02783203125, -660.935791015625, 87.9332122802734375, 1.413716673851013183, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1735', 53007), -- Keep Cannon (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 75925 - Facing Saver, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+165, 34944, 628, 4710, 4752, '0', 0, 0, 0, 0, 1167.1285400390625, -669.2117919921875, 87.96822357177734375, 1.361356854438781738, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1735', 53007), -- Keep Cannon (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 75925 - Facing Saver, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+166, 34944, 628, 4710, 4752, '0', 0, 0, 0, 0, 1142.5885009765625, -691.9461669921875, 87.97562408447265625, 3.31612563133239746, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1735', 53007), -- Keep Cannon (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 75925 - Facing Saver, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+167, 34944, 628, 4710, 4752, '0', 0, 0, 0, 0, 1162.078125, -863.717041015625, 88.35797119140625, 4.799655437469482421, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1735', 53007), -- Keep Cannon (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 75925 - Facing Saver, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+168, 34944, 628, 4710, 4752, '0', 0, 0, 0, 0, 404.736114501953125, -754.79864501953125, 87.79889678955078125, 1.780235767364501953, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1732', 53007), -- Keep Cannon (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 75925 - Facing Saver, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+169, 34944, 628, 4710, 4752, '0', 0, 0, 0, 0, 415.82464599609375, -753.796875, 87.798980712890625, 1.780235767364501953, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1732', 53007), -- Keep Cannon (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 75925 - Facing Saver, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+170, 34944, 628, 4710, 4752, '0', 0, 0, 0, 0, 1164.5504150390625, -663.984375, 88.35713958740234375, 1.396263360977172851, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1735', 53007), -- Keep Cannon (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 75925 - Facing Saver, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+171, 34944, 628, 4710, 4752, '0', 0, 0, 0, 0, 1134.701416015625, -683.89581298828125, 88.040863037109375, 3.246312379837036132, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1735', 53007), -- Keep Cannon (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 75925 - Facing Saver, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+172, 34944, 628, 4710, 4752, '0', 0, 0, 0, 0, 1166.1319580078125, -858.390625, 87.96527099609375, 4.817108631134033203, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1735', 53007), -- Keep Cannon (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 75925 - Facing Saver, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+173, 34944, 628, 4710, 4752, '0', 0, 0, 0, 0, 1144.326416015625, -833.30902099609375, 87.9267730712890625, 3.001966238021850585, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1735', 53007), -- Keep Cannon (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 75925 - Facing Saver, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+174, 34944, 628, 4710, 4752, '0', 0, 0, 0, 0, 425.0694580078125, -879.8507080078125, 88.0445556640625, 0.436332315206527709, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1732', 53162), -- Keep Cannon (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 75925 - Facing Saver, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+175, 34944, 628, 4710, 4752, '0', 0, 0, 0, 0, 426.998260498046875, -785.85589599609375, 87.799102783203125, 5.742133140563964843, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1732', 53162), -- Keep Cannon (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 75925 - Facing Saver, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+176, 34944, 628, 4710, 4752, '0', 0, 0, 0, 0, 427.477447509765625, -884.93927001953125, 88.04461669921875, 0.436332315206527709, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1732', 53162), -- Keep Cannon (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 75925 - Facing Saver, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+177, 34944, 628, 4710, 4752, '0', 0, 0, 0, 0, 429.357635498046875, -780.796875, 87.79906463623046875, 5.79449319839477539, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1732', 53162), -- Keep Cannon (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 75925 - Facing Saver, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+178, 34944, 628, 4710, 4752, '0', 0, 0, 0, 0, 429.9132080078125, -890.435791015625, 88.04461669921875, 0.436332315206527709, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1732', 53162), -- Keep Cannon (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 75925 - Facing Saver, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+179, 34944, 628, 4710, 4752, '0', 0, 0, 0, 0, 431.729156494140625, -775.66839599609375, 87.7990875244140625, 5.8817596435546875, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1732', 53162), -- Keep Cannon (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 75925 - Facing Saver, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+180, 34944, 628, 4710, 4752, '0', 0, 0, 0, 0, 408.055572509765625, -911.8819580078125, 88.0445404052734375, 4.642575740814208984, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1732', 53162), -- Keep Cannon (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 75925 - Facing Saver, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+181, 34944, 628, 4710, 4752, '0', 0, 0, 0, 0, 413.609375, -912.388916015625, 88.04470062255859375, 4.660028934478759765, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1732', 53162), -- Keep Cannon (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 75925 - Facing Saver, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+182, 34944, 628, 4710, 4752, '0', 0, 0, 0, 0, 402.5538330078125, -911.29339599609375, 88.044647216796875, 4.572762489318847656, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1732', 53162); -- Keep Cannon (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 75925 - Facing Saver, 52455 - PvP Vehicle Health Regen Suppression)

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
-- triggers
(@CGUID+5, 23472, 628, 4710, 4752, '0', 0, 0, 0, 0, 1287.376708984375, -1079.4444580078125, 2.130718231201171875, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Large AOI, Not Immune PC/NPC) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+6, 23472, 628, 4710, 4752, '0', 0, 0, 0, 0, 1247.611083984375, -1102.5694580078125, 4.007014274597167968, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Large AOI, Not Immune PC/NPC) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+7, 23472, 628, 4710, 4752, '0', 0, 0, 0, 0, 1272.234375, -1093.9010009765625, 0.447357356548309326, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Large AOI, Not Immune PC/NPC) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+8, 23472, 628, 4710, 4752, '0', 0, 0, 0, 0, 1248.8646240234375, -1136.9617919921875, 3.470679283142089843, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Large AOI, Not Immune PC/NPC) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+9, 23472, 628, 4710, 4752, '0', 0, 0, 0, 0, 1267.7413330078125, -1158.6302490234375, 2.388451337814331054, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Large AOI, Not Immune PC/NPC) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+10, 23472, 628, 4710, 4752, '0', 0, 0, 0, 0, 1272.71875, -1125.421875, 3.611910343170166015, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Large AOI, Not Immune PC/NPC) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+11, 23472, 628, 4710, 4752, '0', 0, 0, 0, 0, 1301.310791015625, -1117.357666015625, 1.536232352256774902, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Large AOI, Not Immune PC/NPC) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+12, 23472, 628, 4710, 4752, '0', 0, 0, 0, 0, 1298.07470703125, -1152.48095703125, 1.257777333259582519, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Large AOI, Not Immune PC/NPC) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+13, 23472, 628, 4710, 4752, '0', 0, 0, 0, 0, 1236.77783203125, -1177.361083984375, 4.7059326171875, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Large AOI, Not Immune PC/NPC) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+19, 22515, 628, 4710, 4752, '0', 0, 0, 0, 0, 774.84722900390625, -887.0711669921875, 56.27956008911132812, 1.466076612472534179, 7200, 0, 0, 36, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+20, 22515, 628, 4710, 4752, '0', 0, 0, 0, 0, 774.90802001953125, -886.982666015625, 56.26288986206054687, 0, 7200, 0, 0, 36, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+21, 22515, 628, 4710, 4752, '0', 0, 0, 0, 0, 775.37677001953125, -887.11456298828125, 56.132415771484375, 1.466076612472534179, 7200, 0, 0, 36, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+22, 22515, 628, 4710, 4752, '0', 0, 0, 0, 0, 775.11456298828125, -886.8663330078125, 56.20595550537109375, 1.466076612472534179, 7200, 0, 0, 36, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+23, 22515, 628, 4710, 4752, '0', 0, 0, 0, 0, 774.7725830078125, -887.326416015625, 56.29906082153320312, 1.466076612472534179, 7200, 0, 0, 36, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+24, 22515, 628, 4710, 4752, '0', 0, 0, 0, 0, 775.22222900390625, -886.796875, 56.17631912231445312, 1.466076612472534179, 7200, 0, 0, 36, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+25, 22515, 628, 4710, 4752, '0', 0, 0, 0, 0, 775.09552001953125, -887.046875, 56.21084976196289062, 1.466076612472534179, 7200, 0, 0, 36, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+26, 22515, 628, 4710, 4752, '0', 0, 0, 0, 0, 775.12847900390625, -887.234375, 56.20093154907226562, 1.466076612472534179, 7200, 0, 0, 36, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+29, 22515, 628, 4710, 4752, '0', 0, 0, 0, 0, 766.93402099609375, -900.967041015625, 35.64332199096679687, 0, 7200, 0, 0, 36, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+32, 23472, 628, 4710, 0, '0', 0, 0, 0, 0, 1230.5850830078125, -1207.892333984375, 4.828125476837158203, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Large AOI, Not Immune PC/NPC) (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+33, 23472, 628, 4710, 0, '0', 0, 0, 0, 0, 1254.03125, -1201.3697509765625, 2.774367332458496093, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Large AOI, Not Immune PC/NPC) (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+34, 23472, 628, 4710, 0, '0', 0, 0, 0, 0, 1290.9305419921875, -1191.8489990234375, 1.83943641185760498, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Large AOI, Not Immune PC/NPC) (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+35, 23472, 628, 4710, 0, '0', 0, 0, 0, 0, 1273.85595703125, -1219.5416259765625, 2.406368255615234375, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Large AOI, Not Immune PC/NPC) (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+36, 23472, 628, 4710, 0, '0', 0, 0, 0, 0, 1238.5660400390625, -1238.717041015625, 4.824849605560302734, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Large AOI, Not Immune PC/NPC) (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+37, 23472, 628, 4710, 0, '0', 0, 0, 0, 0, 1233.2239990234375, -1260.123291015625, 12.68245506286621093, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Large AOI, Not Immune PC/NPC) (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+38, 23472, 628, 4710, 0, '0', 0, 0, 0, 0, 1262.0086669921875, -1248.3958740234375, 2.581503152847290039, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Large AOI, Not Immune PC/NPC) (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+120, 23472, 628, 4710, 0, '0', 0, 0, 0, 0, 1267.96875, -1038.8125, 0.826364338397979736, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Large AOI, Not Immune PC/NPC) (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+121, 23472, 628, 4710, 0, '0', 0, 0, 0, 0, 1263.2447509765625, -1064.015625, 2.007972240447998046, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Large AOI, Not Immune PC/NPC) (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+122, 23472, 628, 4710, 0, '0', 0, 0, 0, 0, 1303.3958740234375, -1062.3836669921875, 0.083269335329532623, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53007), -- World Trigger (Large AOI, Not Immune PC/NPC) (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+183, 36171, 628, 4710, 4752, '0', 0, 0, 0, 0, 1401.1336669921875, -1167.3350830078125, 4.88478851318359375, 0, 7200, 0, 0, 36, 0, 0, NULL, NULL, NULL, NULL, 53162), -- World Trigger (Infinite AOI) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+184, 36171, 628, 4710, 4752, '0', 0, 0, 0, 0, 1400.73095703125, -1144.4913330078125, 5.117686271667480468, 0, 7200, 0, 0, 36, 0, 0, NULL, NULL, NULL, NULL, 53162), -- World Trigger (Infinite AOI) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+185, 36171, 628, 4710, 4752, '0', 0, 0, 0, 0, 1446.5260009765625, -1338.8958740234375, 4.475928306579589843, 0, 7200, 0, 0, 36, 0, 0, NULL, NULL, NULL, NULL, 53162), -- World Trigger (Infinite AOI) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+186, 36171, 628, 4710, 4752, '0', 0, 0, 0, 0, 1449.9879150390625, -1327.798583984375, 4.599755287170410156, 0, 7200, 0, 0, 36, 0, 0, NULL, NULL, NULL, NULL, 53162), -- World Trigger (Infinite AOI) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+187, 36171, 628, 4710, 4752, '0', 0, 0, 0, 0, 1444.998291015625, -1349.861083984375, 5.181267261505126953, 0, 7200, 0, 0, 36, 0, 0, NULL, NULL, NULL, NULL, 53162), -- World Trigger (Infinite AOI) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+188, 36171, 628, 4710, 4752, '0', 0, 0, 0, 0, 1448.560791015625, -1333.5191650390625, 4.450309276580810546, 0, 7200, 0, 0, 36, 0, 0, NULL, NULL, NULL, NULL, 53162), -- World Trigger (Infinite AOI) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+189, 36171, 628, 4710, 4752, '0', 0, 0, 0, 0, 1400.267333984375, -1150.576416015625, 5.154570579528808593, 0, 7200, 0, 0, 36, 0, 0, NULL, NULL, NULL, NULL, 53162), -- World Trigger (Infinite AOI) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+190, 36171, 628, 4710, 4752, '0', 0, 0, 0, 0, 1400.4114990234375, -1155.9913330078125, 5.118544578552246093, 0, 7200, 0, 0, 36, 0, 0, NULL, NULL, NULL, NULL, 53162); -- World Trigger (Infinite AOI) (Area: Horde Keep - Difficulty: 0) CreateObject1

-- Honorable Defenders
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+79, 35380, 628, 4710, 4748, '0', 0, 0, 0, 0, 250.65625, -1159.37158203125, 17.28952980041503906, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Honorable Defender Trigger (Horde) (Area: Quarry - Difficulty: 0) CreateObject2 (Auras: 66157 - Honorable Defender)
-- Keep
(@CGUID+148, 35380, 628, 4710, 4748, '0', 0, 0, 0, 0, 1212.0365, -762.69617, 48.91625, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 0), -- Honorable Defender Trigger (Horde) (Area: Quarry - Difficulty: 0) CreateObject2 (Auras: 66157 - Honorable Defender)
(@CGUID+149, 35379, 628, 4710, 4748, '0', 0, 0, 0, 0, 347.64062, -836.16144, 48.91625, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 0), -- Honorable Defender Trigger (Alliance) (Area: Quarry - Difficulty: 0) CreateObject2 (Auras: 66157 - Honorable Defender)
-- Quarry
(@CGUID+150, 35379, 628, 4710, 4748, '0', 0, 0, 0, 0, 250.65625, -1159.37158203125, 17.28952980041503906, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 0), -- Honorable Defender Trigger (Alliance) (Area: Quarry - Difficulty: 0) CreateObject2 (Auras: 66157 - Honorable Defender)
-- Hangar
(@CGUID+151, 35380, 628, 4710, 4748, '0', 0, 0, 0, 0, 807.780029296875, -1000.07000732421875, 132.3809967041015625, 4.345870018005371093, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 0), -- Honorable Defender Trigger (Horde) (Area: Quarry - Difficulty: 0) CreateObject2 (Auras: 66157 - Honorable Defender)
(@CGUID+152, 35379, 628, 4710, 4748, '0', 0, 0, 0, 0, 807.780029296875, -1000.07000732421875, 132.3809967041015625, 4.345870018005371093, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 0), -- Honorable Defender Trigger (Alliance) (Area: Quarry - Difficulty: 0) CreateObject2 (Auras: 66157 - Honorable Defender)
-- Workshop
(@CGUID+153, 35380, 628, 4710, 4748, '0', 0, 0, 0, 0, 776.22900390625, -804.28302001953125, 6.450520038604736328, 1.605701684951782226, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 0), -- Honorable Defender Trigger (Horde) (Area: Quarry - Difficulty: 0) CreateObject2 (Auras: 66157 - Honorable Defender)
(@CGUID+154, 35379, 628, 4710, 4748, '0', 0, 0, 0, 0, 776.22900390625, -804.28302001953125, 6.450520038604736328, 1.605701684951782226, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 0), -- Honorable Defender Trigger (Alliance) (Area: Quarry - Difficulty: 0) CreateObject2 (Auras: 66157 - Honorable Defender)
-- Docks
(@CGUID+155, 35380, 628, 4710, 4748, '0', 0, 0, 0, 0, 726.385009765625, -360.204986572265625, 17.81529998779296875, 4.677483558654785156, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 0), -- Honorable Defender Trigger (Horde) (Area: Quarry - Difficulty: 0) CreateObject2 (Auras: 66157 - Honorable Defender)
(@CGUID+156, 35379, 628, 4710, 4748, '0', 0, 0, 0, 0, 726.385009765625, -360.204986572265625, 17.81529998779296875, 4.677483558654785156, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 0), -- Honorable Defender Trigger (Alliance) (Area: Quarry - Difficulty: 0) CreateObject2 (Auras: 66157 - Honorable Defender)
-- Refinery
(@CGUID+157, 35380, 628, 4710, 4748, '0', 0, 0, 0, 0, 1269.501708984375, -400.80902099609375, 37.62525177001953125, 4.520402908325195312, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 0), -- Honorable Defender Trigger (Horde) (Area: Quarry - Difficulty: 0) CreateObject2 (Auras: 66157 - Honorable Defender)
(@CGUID+158, 35379, 628, 4710, 4748, '0', 0, 0, 0, 0, 1269.501708984375, -400.80902099609375, 37.62525177001953125, 4.520402908325195312, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 0); -- Honorable Defender Trigger (Alliance) (Area: Quarry - Difficulty: 0) CreateObject2 (Auras: 66157 - Honorable Defender)

-- Spirit Guides
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+43, 13117, 628, 4710, 4750, '0', 0, 0, 0, 1, 774.51214599609375, -646.88543701171875, 9.864583015441894531, 4.625122547149658203, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 53007), -- Horde Spirit Guide (Area: Hangar - Difficulty: 0) CreateObject2 (Auras: 9036 - Ghost)
(@CGUID+64, 13117, 628, 4710, 0, '0', 0, 0, 0, 1, 784.1475830078125, -1095.6510009765625, 135.53009033203125, 3.141592741012573242, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 53007), -- Horde Spirit Guide (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 9036 - Ghost)
(@CGUID+72, 13117, 628, 4710, 4748, '0', 0, 0, 0, 1, 628.53643798828125, -277.392364501953125, 11.30339336395263671, 5.934119224548339843, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 53007), -- Horde Spirit Guide (Area: Quarry - Difficulty: 0) CreateObject2 (Auras: 9036 - Ghost)
(@CGUID+139, 13116, 628, 4710, 4747, '0', 0, 0, 0, 1, 628.7725830078125, -277.508697509765625, 11.31214237213134765, 5.934119224548339843, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 53162), -- Alliance Spirit Guide (Area: Workshop - Difficulty: 0) CreateObject2 (Auras: 9036 - Ghost)
(@CGUID+140, 13117, 628, 4710, 4749, '0', 0, 0, 0, 1, 1301.5086669921875, -832.77777099609375, 48.99958038330078125, 1.553343057632446289, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 53162), -- Horde Spirit Guide (Area: Docks - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+141, 13117, 628, 4710, 4749, '0', 0, 0, 0, 1, 1147.3472900390625, -1245.0885009765625, 16.68014335632324218, 1.919862151145935058, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 53162), -- Horde Spirit Guide (Area: Docks - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+142, 13116, 628, 4710, 4749, '0', 0, 0, 0, 1, 440.23089599609375, -309.12847900390625, 51.89045333862304687, 5.846852779388427734, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 53162), -- Alliance Spirit Guide (Area: Docks - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+143, 13116, 628, 4710, 4749, '0', 0, 0, 0, 1, 278.041656494140625, -883.46875, 50.00659942626953125, 1.535889744758605957, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 53162), -- Alliance Spirit Guide (Area: Docks - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+144, 13117, 628, 4710, 4753, '0', 0, 0, 0, 1, 277.92535400390625, -883.40625, 50.00659942626953125, 1.448623299598693847, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 53162), -- Horde Spirit Guide (Area: Alliance Keep - Difficulty: 0) CreateObject2 (Auras: 9036 - Ghost)
(@CGUID+145, 13116, 628, 4710, 4750, '0', 0, 0, 0, 1, 784.3836669921875, -1095.7691650390625, 135.528228759765625, 3.141592741012573242, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 53162), -- Alliance Spirit Guide (Area: Hangar - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+146, 13116, 628, 4710, 4753, '0', 0, 0, 0, 1, 774.748291015625, -647.00177001953125, 9.865810394287109375, 4.625122547149658203, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 53162), -- Alliance Spirit Guide (Area: Alliance Keep - Difficulty: 0) CreateObject2 (Auras: 9036 - Ghost)
(@CGUID+147, 13116, 628, 4710, 4752, '0', 0, 0, 0, 1, 1301.3055419921875, -832.671875, 48.99958038330078125, 1.518436431884765625, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 53162); -- Alliance Spirit Guide (Area: Horde Keep - Difficulty: 0) CreateObject2 (Auras: 9036 - Ghost)

-- Oil-covered Hawk
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 25748, 628, 4710, 4752, '0', 0, 0, 0, 0, 885.9461669921875, -531.1475830078125, 0.391945332288742065, 4.450589656829833984, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Oil-covered Hawk (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 45948 - Oil Coat)
(@CGUID+1, 25748, 628, 4710, 4752, '0', 0, 0, 0, 0, 885.05206298828125, -509.729156494140625, 5.066973686218261718, 4.450589656829833984, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Oil-covered Hawk (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 45948 - Oil Coat)
(@CGUID+2, 25748, 628, 4710, 4752, '0', 0, 0, 0, 0, 808.64410400390625, -688.920166015625, 2.001918315887451171, 2.164208173751831054, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Oil-covered Hawk (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 45948 - Oil Coat)
(@CGUID+3, 25748, 628, 4710, 4752, '0', 0, 0, 0, 0, 1337.30908203125, -367.446197509765625, 0.230803340673446655, 5.689773082733154296, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Oil-covered Hawk (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 45948 - Oil Coat)
(@CGUID+4, 25748, 628, 4710, 4752, '0', 0, 0, 0, 0, 1363.3697509765625, -407.01910400390625, 0.812617301940917968, 5.550147056579589843, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Oil-covered Hawk (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 45948 - Oil Coat)
(@CGUID+14, 25748, 628, 4710, 4752, '0', 0, 0, 0, 0, 1349.1353759765625, -439.118072509765625, 0.259844332933425903, 5.550147056579589843, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Oil-covered Hawk (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 45948 - Oil Coat)
(@CGUID+15, 25748, 628, 4710, 4752, '0', 0, 0, 0, 0, 1299.670166015625, -409.2413330078125, 0.27183234691619873, 1.308996915817260742, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Oil-covered Hawk (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 45948 - Oil Coat)
(@CGUID+16, 25748, 628, 4710, 4752, '0', 0, 0, 0, 0, 772.76739501953125, -570.3524169921875, 0.388206332921981811, 0, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Oil-covered Hawk (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 45948 - Oil Coat)
(@CGUID+17, 25748, 628, 4710, 4752, '0', 0, 0, 0, 0, 784.54339599609375, -546.90625, 1.641917347908020019, 4.450589656829833984, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Oil-covered Hawk (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 45948 - Oil Coat)
(@CGUID+18, 25748, 628, 4710, 4752, '0', 0, 0, 0, 0, 704.05902099609375, -663.295166015625, 2.097845315933227539, 0, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Oil-covered Hawk (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 45948 - Oil Coat)
(@CGUID+27, 25748, 628, 4710, 4752, '0', 0, 0, 0, 0, 661.36114501953125, -729.45660400390625, 0.237812340259552001, 2.164208173751831054, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Oil-covered Hawk (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 45948 - Oil Coat)
(@CGUID+28, 25748, 628, 4710, 4752, '0', 0, 0, 0, 0, 694.9288330078125, -589.59893798828125, 2.620331287384033203, 2.164208173751831054, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Oil-covered Hawk (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 45948 - Oil Coat)
(@CGUID+30, 25748, 628, 4710, 4752, '0', 0, 0, 0, 0, 716.6492919921875, -562.93402099609375, 1.780481338500976562, 4.258603572845458984, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Oil-covered Hawk (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 45948 - Oil Coat)
(@CGUID+31, 25748, 628, 4710, 4752, '0', 0, 0, 0, 0, 676.1788330078125, -626.0538330078125, 1.276142358779907226, 5.113814830780029296, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Oil-covered Hawk (Area: Horde Keep - Difficulty: 0) CreateObject1 (Auras: 45948 - Oil Coat)
(@CGUID+39, 25748, 628, 4710, 4750, '0', 0, 0, 0, 0, 886.8507080078125, -683.80902099609375, 0.453427344560623168, 2.164208173751831054, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Oil-covered Hawk (Area: Hangar - Difficulty: 0) CreateObject1 (Auras: 45948 - Oil Coat)
(@CGUID+40, 25748, 628, 4710, 4750, '0', 0, 0, 0, 0, 838.48956298828125, -633.26910400390625, 1.17678534984588623, 5.585053443908691406, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Oil-covered Hawk (Area: Hangar - Difficulty: 0) CreateObject1 (Auras: 45948 - Oil Coat)
(@CGUID+96, 25748, 628, 4710, 0, '0', 0, 0, 0, 0, 579.23089599609375, -601.15106201171875, 1.009244322776794433, 0, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Oil-covered Hawk (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 45948 - Oil Coat)
(@CGUID+97, 25748, 628, 4710, 0, '0', 0, 0, 0, 0, 560.88714599609375, -575.36285400390625, 0.648507297039031982, 5.096361160278320312, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Oil-covered Hawk (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 45948 - Oil Coat)
(@CGUID+98, 25748, 628, 4710, 0, '0', 0, 0, 0, 0, 605.94097900390625, -542.11981201171875, 0.608721315860748291, 3.612831592559814453, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Oil-covered Hawk (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 45948 - Oil Coat)
(@CGUID+101, 25748, 628, 4710, 0, '0', 0, 0, 0, 0, 928.25177001953125, -589.420166015625, 0.77868729829788208, 3.141592741012573242, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Oil-covered Hawk (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 45948 - Oil Coat)
(@CGUID+111, 25748, 628, 4710, 4749, '0', 0, 0, 0, 0, 1273.1129150390625, -500.0850830078125, 0.449441343545913696, 1.151917338371276855, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Oil-covered Hawk (Area: Docks - Difficulty: 0) CreateObject1 (Auras: 45948 - Oil Coat)
(@CGUID+112, 25748, 628, 4710, 4749, '0', 0, 0, 0, 0, 1319.3663330078125, -458.55035400390625, 0.339978337287902832, 1.518436431884765625, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007); -- Oil-covered Hawk (Area: Docks - Difficulty: 0) CreateObject1 (Auras: 45948 - Oil Coat)

-- Demolishers
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `stringId`, `VerifiedBuild`) VALUES
(@CGUID+41, 34775, 628, 4710, 4750, '0', 0, 0, 0, 0, 761.80902099609375, -854.2274169921875, 12.52632427215576171, 1.466076612472534179, 180, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1735', 53007), -- Demolisher (Area: Hangar - Difficulty: 0) CreateObject2 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+42, 34775, 628, 4710, 4750, '0', 0, 0, 0, 0, 793.0555419921875, -852.71875, 12.56713294982910156, 1.710422635078430175, 180, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1735', 53007), -- Demolisher (Area: Hangar - Difficulty: 0) CreateObject2 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+44, 34775, 628, 4710, 4750, '0', 0, 0, 0, 0, 751.828125, -852.732666015625, 12.52509784698486328, 1.466076612472534179, 180, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1735', 53007), -- Demolisher (Area: Hangar - Difficulty: 0) CreateObject2 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+45, 34775, 628, 4710, 4750, '0', 0, 0, 0, 0, 783.47222900390625, -853.9600830078125, 12.54775047302246093, 1.710422635078430175, 180, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1735', 53007), -- Demolisher (Area: Hangar - Difficulty: 0) CreateObject2 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+46, 35069, 628, 4710, 4750, '0', 0, 0, 0, 0, 773.6805419921875, -884.092041015625, 16.8090362548828125, 1.588249564170837402, 180, 0, 0, 3161732, 100, 0, NULL, NULL, NULL, NULL, NULL, 53007), -- Siege Engine (Area: Hangar - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+134, 34775, 628, 4710, 4750, '0', 0, 0, 0, 0, 761.80902099609375, -854.2274169921875, 12.52632427215576171, 1.466076612472534179, 180, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1732', 0), -- Demolisher (Area: Hangar - Difficulty: 0) CreateObject2 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+135, 34775, 628, 4710, 4750, '0', 0, 0, 0, 0, 793.0555419921875, -852.71875, 12.56713294982910156, 1.710422635078430175, 180, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1732', 0), -- Demolisher (Area: Hangar - Difficulty: 0) CreateObject2 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+136, 34775, 628, 4710, 4750, '0', 0, 0, 0, 0, 751.828125, -852.732666015625, 12.52509784698486328, 1.466076612472534179, 180, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1732', 0), -- Demolisher (Area: Hangar - Difficulty: 0) CreateObject2 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+137, 34775, 628, 4710, 4750, '0', 0, 0, 0, 0, 783.47222900390625, -853.9600830078125, 12.54775047302246093, 1.710422635078430175, 180, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1732', 0), -- Demolisher (Area: Hangar - Difficulty: 0) CreateObject2 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+138, 34776, 628, 4710, 4750, '0', 0, 0, 0, 0, 773.6805419921875, -884.092041015625, 16.8090362548828125, 1.588249564170837402, 180, 0, 0, 3161732, 100, 0, NULL, NULL, NULL, NULL, NULL, 0); -- Siege Engine (Area: Hangar - Difficulty: 0) CreateObject2 (Auras: )

-- Fires (missing lots of them)
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+130, 35377, 628, 4710, 4753, '0', 0, 0, 0, 0, 366.77777099609375, -903.25347900390625, 73.65229034423828125, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Door Fire (Area: Alliance Keep - Difficulty: 0) CreateObject2 (Auras: 67359 - Door Fire)
(@CGUID+131, 35377, 628, 4710, 4753, '0', 0, 0, 0, 0, 368.43402099609375, -899.44793701171875, 87.982452392578125, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Door Fire (Area: Alliance Keep - Difficulty: 0) CreateObject2 (Auras: 67359 - Door Fire)
(@CGUID+132, 35377, 628, 4710, 4753, '0', 0, 0, 0, 0, 323.576385498046875, -904.24481201171875, 88.535675048828125, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Door Fire (Area: Alliance Keep - Difficulty: 0) CreateObject2 (Auras: 67359 - Door Fire)
(@CGUID+133, 35377, 628, 4710, 4753, '0', 0, 0, 0, 0, 320.60589599609375, -901.0850830078125, 70.51508331298828125, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Door Fire (Area: Alliance Keep - Difficulty: 0) CreateObject2 (Auras: 67359 - Door Fire)
(@CGUID+196, 35377, 628, 4710, 4752, '0', 0, 0, 0, 0, 1148.296875, -762.80731201171875, 89.02325439453125, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Door Fire (Area: Horde Keep - Difficulty: 0) CreateObject2 (Auras: 67359 - Door Fire)
(@CGUID+197, 35377, 628, 4710, 4752, '0', 0, 0, 0, 0, 1153.4444580078125, -786.17364501953125, 71.0856475830078125, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Door Fire (Area: Horde Keep - Difficulty: 0) CreateObject2 (Auras: 67359 - Door Fire)
(@CGUID+198, 35377, 628, 4710, 4752, '0', 0, 0, 0, 0, 1150.1180419921875, -750.0399169921875, 81.47015380859375, 0, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 53162); -- Door Fire (Area: Horde Keep - Difficulty: 0) CreateObject2 (Auras: 67359 - Door Fire)

-- Penguins
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+100, 32498, 628, 4710, 0, '0', 0, 0, 0, 0, 601.43231201171875, -353.758697509765625, 0.924143314361572265, 5.550147056579589843, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Glacier Penguin (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 51583 - [DND] Creature Random Size (0 - 50))
(@CGUID+102, 32498, 628, 4710, 0, '0', 0, 0, 0, 0, 531.89581298828125, -206.338546752929687, 0.520865321159362792, 4.24114990234375, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Glacier Penguin (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 51583 - [DND] Creature Random Size (0 - 50))
(@CGUID+103, 32498, 628, 4710, 0, '0', 0, 0, 0, 0, 616.2413330078125, -190.244796752929687, 0.807831287384033203, 4.450589656829833984, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Glacier Penguin (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 51583 - [DND] Creature Random Size (0 - 50))
(@CGUID+104, 32498, 628, 4710, 0, '0', 0, 0, 0, 0, 635.31427001953125, -189.84722900390625, 0.78067028522491455, 3.490658521652221679, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Glacier Penguin (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 51583 - [DND] Creature Random Size (0 - 50))
(@CGUID+105, 32498, 628, 4710, 0, '0', 0, 0, 0, 0, 616.91839599609375, -192.489578247070312, 0.796478331089019775, 1.047197580337524414, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Glacier Penguin (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 51583 - [DND] Creature Random Size (0 - 50))
(@CGUID+106, 32498, 628, 4710, 0, '0', 0, 0, 0, 0, 634.48956298828125, -186.022567749023437, 0.813599288463592529, 1.448623299598693847, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Glacier Penguin (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 51583 - [DND] Creature Random Size (0 - 50))
(@CGUID+107, 32498, 628, 4710, 4749, '0', 0, 0, 0, 0, 647.0399169921875, -171.010421752929687, 0.305968344211578369, 1.448623299598693847, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Glacier Penguin (Area: Docks - Difficulty: 0) CreateObject1 (Auras: 51583 - [DND] Creature Random Size (0 - 50))
(@CGUID+108, 32498, 628, 4710, 4749, '0', 0, 0, 0, 0, 934.37847900390625, -303.7413330078125, 0.178161337971687316, 3.490658521652221679, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Glacier Penguin (Area: Docks - Difficulty: 0) CreateObject1 (Auras: 51583 - [DND] Creature Random Size (0 - 50))
(@CGUID+109, 32498, 628, 4710, 4749, '0', 0, 0, 0, 0, 947.670166015625, -177.96875, 0.290117323398590087, 3.490658521652221679, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Glacier Penguin (Area: Docks - Difficulty: 0) CreateObject1 (Auras: 51583 - [DND] Creature Random Size (0 - 50))
(@CGUID+110, 32498, 628, 4710, 4749, '0', 0, 0, 0, 0, 958.3125, -159.871536254882812, 0.705229341983795166, 1.448623299598693847, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Glacier Penguin (Area: Docks - Difficulty: 0) CreateObject1 (Auras: 51583 - [DND] Creature Random Size (0 - 50))
(@CGUID+113, 32498, 628, 4710, 0, '0', 0, 0, 0, 0, 1375.9114990234375, -297.821197509765625, 0.546406328678131103, 3.40339207649230957, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Glacier Penguin (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 51583 - [DND] Creature Random Size (0 - 50))
(@CGUID+114, 32498, 628, 4710, 0, '0', 0, 0, 0, 0, 1378.828125, -298.42535400390625, 0.51107335090637207, 2.94960641860961914, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Glacier Penguin (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 51583 - [DND] Creature Random Size (0 - 50))
(@CGUID+115, 32498, 628, 4710, 0, '0', 0, 0, 0, 0, 1378.0035400390625, -297.005218505859375, 0.515660345554351806, 1.047197580337524414, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Glacier Penguin (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 51583 - [DND] Creature Random Size (0 - 50))
(@CGUID+116, 32498, 628, 4710, 0, '0', 0, 0, 0, 0, 1377.28125, -286.373260498046875, 0.519130349159240722, 3.490658521652221679, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Glacier Penguin (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 51583 - [DND] Creature Random Size (0 - 50))
(@CGUID+117, 32498, 628, 4710, 0, '0', 0, 0, 0, 0, 1386.9791259765625, -297.375, 0.532947301864624023, 0.331612557172775268, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Glacier Penguin (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 51583 - [DND] Creature Random Size (0 - 50))
(@CGUID+118, 32498, 628, 4710, 0, '0', 0, 0, 0, 0, 1388.5521240234375, -297.086822509765625, 0.534635305404663085, 3.490658521652221679, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Glacier Penguin (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 51583 - [DND] Creature Random Size (0 - 50))
(@CGUID+119, 32498, 628, 4710, 0, '0', 0, 0, 0, 0, 1399.6927490234375, -297.20660400390625, 0.76446533203125, 3.490658521652221679, 7200, 0, 0, 2035, 0, 0, NULL, NULL, NULL, NULL, 53007); -- Glacier Penguin (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 51583 - [DND] Creature Random Size (0 - 50))

-- Catapults
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `StringId`, `VerifiedBuild`) VALUES
(@CGUID+76, 34793, 628, 4710, 4748, '0', 0, 0, 0, 0, 770.5382080078125, -321.857635498046875, 12.71080684661865234, 4.729842185974121093, 180, 0, 0, 564595, 100, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1735', 53007), -- Catapult (Area: Quarry - Difficulty: 0) CreateObject1 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+77, 34793, 628, 4710, 4748, '0', 0, 0, 0, 0, 791.59027099609375, -321.149322509765625, 12.71045589447021484, 4.677482128143310546, 180, 0, 0, 564595, 100, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1735', 53007), -- Catapult (Area: Quarry - Difficulty: 0) CreateObject1 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+78, 34793, 628, 4710, 4748, '0', 0, 0, 0, 0, 780.91668701171875, -321.430572509765625, 12.71062374114990234, 4.694935798645019531, 180, 0, 0, 564595, 100, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1735', 53007), -- Catapult (Area: Quarry - Difficulty: 0) CreateObject1 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+99, 34793, 628, 4710, 0, '0', 0, 0, 0, 0, 802.60418701171875, -322.34722900390625, 12.70589637756347656, 4.660028934478759765, 180, 0, 0, 564595, 100, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1735', 53007), -- Catapult (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+126, 34793, 628, 4710, 4747, '0', 0, 0, 0, 0, 770.375, -321.84027099609375, 12.71123027801513671, 4.729842185974121093, 7200, 0, 0, 564595, 100, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1732', 53162), -- Catapult (Area: Workshop - Difficulty: 0) CreateObject1 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+127, 34793, 628, 4710, 4747, '0', 0, 0, 0, 0, 802.44097900390625, -322.329864501953125, 12.70589733123779296, 4.660028934478759765, 7200, 0, 0, 564595, 100, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1732', 53162), -- Catapult (Area: Workshop - Difficulty: 0) CreateObject1 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+128, 34793, 628, 4710, 4747, '0', 0, 0, 0, 0, 780.75347900390625, -321.40972900390625, 12.71072578430175781, 4.694935798645019531, 7200, 0, 0, 564595, 100, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1732', 53162), -- Catapult (Area: Workshop - Difficulty: 0) CreateObject1 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+129, 34793, 628, 4710, 4747, '0', 0, 0, 0, 0, 791.4305419921875, -321.1319580078125, 12.71054267883300781, 4.677482128143310546, 7200, 0, 0, 564595, 100, 0, NULL, NULL, NULL, NULL, 'bg_ioc_faction_1732', 53162); -- Catapult (Area: Workshop - Difficulty: 0) CreateObject1 (Auras: 52455 - PvP Vehicle Health Regen Suppression)

-- Glaive Throwers
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+73, 35273, 628, 4710, 4748, '0', 0, 0, 0, 0, 787.47918701171875, -343.060760498046875, 12.25117206573486328, 4.712388992309570312, 180, 0, 0, 1027563, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Glaive Thrower (Area: Quarry - Difficulty: 0) CreateObject2 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+74, 35273, 628, 4710, 4748, '0', 0, 0, 0, 0, 802.65106201171875, -343.291656494140625, 12.17534732818603515, 4.712388992309570312, 180, 0, 0, 1027563, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Glaive Thrower (Area: Quarry - Difficulty: 0) CreateObject2 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+75, 35273, 628, 4710, 4748, '0', 0, 0, 0, 0, 771.842041015625, -342.401031494140625, 12.19386196136474609, 4.712388992309570312, 180, 0, 0, 1027563, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Glaive Thrower (Area: Quarry - Difficulty: 0) CreateObject2 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+123, 34802, 628, 4710, 4747, '0', 0, 0, 0, 0, 787.31597900390625, -343.04339599609375, 12.24087047576904296, 4.712388992309570312, 7200, 0, 0, 1027563, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Glaive Thrower (Area: Workshop - Difficulty: 0) CreateObject2 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+124, 34802, 628, 4710, 4747, '0', 0, 0, 0, 0, 802.65106201171875, -343.248260498046875, 12.17302513122558593, 4.712388992309570312, 7200, 0, 0, 1027563, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Glaive Thrower (Area: Workshop - Difficulty: 0) CreateObject2 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+125, 34802, 628, 4710, 4747, '0', 0, 0, 0, 0, 771.68231201171875, -342.380218505859375, 12.19341564178466796, 4.712388992309570312, 7200, 0, 0, 1027563, 0, 0, NULL, NULL, NULL, NULL, 53162); -- Glaive Thrower (Area: Workshop - Difficulty: 0) CreateObject2 (Auras: 52455 - PvP Vehicle Health Regen Suppression)

-- Human Miners
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+47, 61696, 628, 4710, 4750, '0', 0, 0, 0, 1, 300.42535400390625, -1180.0069580078125, 16.7330169677734375, 1.431169986724853515, 7200, 0, 0, 118565, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Human Miner (Area: Hangar - Difficulty: 0) CreateObject1
(@CGUID+48, 61696, 628, 4710, 4750, '0', 0, 0, 0, 1, 302.197906494140625, -1141.2257080078125, 30.97160530090332031, 5.497786998748779296, 7200, 0, 0, 118565, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Human Miner (Area: Hangar - Difficulty: 0) CreateObject1
(@CGUID+49, 61696, 628, 4710, 4750, '0', 0, 0, 0, 1, 320.243072509765625, -1147.7430419921875, 34.2675628662109375, 4.084070205688476562, 7200, 0, 0, 118565, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Human Miner (Area: Hangar - Difficulty: 0) CreateObject1
(@CGUID+50, 61696, 628, 4710, 4750, '0', 0, 0, 0, 1, 331.192718505859375, -1129.8316650390625, 19.95678901672363281, 3.647738218307495117, 7200, 0, 0, 118565, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Human Miner (Area: Hangar - Difficulty: 0) CreateObject1
(@CGUID+51, 61696, 628, 4710, 4750, '0', 0, 0, 0, 1, 273.28125, -1260.579833984375, 42.1154632568359375, 4.956735134124755859, 7200, 0, 0, 118565, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Human Miner (Area: Hangar - Difficulty: 0) CreateObject1
(@CGUID+52, 61696, 628, 4710, 4750, '0', 0, 0, 0, 1, 303.885406494140625, -1243.829833984375, 25.91202926635742187, 4.660028934478759765, 7200, 0, 0, 118565, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Human Miner (Area: Hangar - Difficulty: 0) CreateObject1
(@CGUID+53, 61696, 628, 4710, 4750, '0', 0, 0, 0, 1, 374.927093505859375, -1160.296875, 28.20929718017578125, 5.235987663269042968, 7200, 0, 0, 118565, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Human Miner (Area: Hangar - Difficulty: 0) CreateObject1
(@CGUID+54, 61696, 628, 4710, 4750, '0', 0, 0, 0, 1, 231.904510498046875, -1076.3663330078125, 17.85601425170898437, 1.884955525398254394, 7200, 0, 0, 118565, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Human Miner (Area: Hangar - Difficulty: 0) CreateObject1
(@CGUID+55, 61696, 628, 4710, 0, '0', 0, 0, 0, 1, 203.451385498046875, -1102.0382080078125, 8.814992904663085937, 3.560471534729003906, 7200, 0, 0, 118565, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Human Miner (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+56, 61696, 628, 4710, 0, '0', 0, 0, 0, 1, 226.626739501953125, -1068.6961669921875, 27.455169677734375, 1.623156189918518066, 7200, 0, 0, 118565, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Human Miner (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+57, 61696, 628, 4710, 0, '0', 0, 0, 0, 1, 197.4131927490234375, -1107.0260009765625, 16.24344825744628906, 2.460914134979248046, 7200, 0, 0, 118565, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Human Miner (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+59, 61696, 628, 4710, 0, '0', 0, 0, 0, 1, 174.62847900390625, -1132.4410400390625, 10.53891181945800781, 2.94960641860961914, 7200, 0, 0, 118565, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Human Miner (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+60, 61696, 628, 4710, 0, '0', 0, 0, 0, 1, 172.86285400390625, -1174.263916015625, 2.087067365646362304, 3.281219005584716796, 7200, 0, 0, 118565, 0, 0, NULL, NULL, NULL, NULL, 53007); -- Human Miner (Area: 0 - Difficulty: 0) CreateObject1

-- Peasant workers
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+58, 19444, 628, 4710, 0, '0', 0, 0, 0, 4, 302.064239501953125, -893.94793701171875, 66.069427490234375, 4.223696708679199218, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Peasant Worker (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+61, 19444, 628, 4710, 0, '0', 0, 0, 0, 2, 299.6358642578125, -872.642822265625, 48.95278167724609375, 5.4851837158203125, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Peasant Worker (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+62, 19444, 628, 4710, 0, '0', 0, 0, 0, 4, 265.80902099609375, -891.12847900390625, 76.61261749267578125, 0.890117883682250976, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Peasant Worker (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+63, 19444, 628, 4710, 0, '0', 0, 0, 0, 4, 252.734375, -893.67706298828125, 62.05205535888671875, 5.585053443908691406, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Peasant Worker (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+65, 19444, 628, 4710, 0, '0', 0, 0, 0, 4, 236.64410400390625, -880.6024169921875, 50.06217193603515625, 2.513274192810058593, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Peasant Worker (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+66, 19444, 628, 4710, 0, '0', 0, 0, 0, 2, 233.032989501953125, -874.2430419921875, 64.42089080810546875, 3.31612563133239746, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Peasant Worker (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+67, 19444, 628, 4710, 0, '0', 0, 0, 0, 0, 387.5, -780.22918701171875, 48.91879653930664062, 0.055398445576429367, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Peasant Worker (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+68, 19444, 628, 4710, 4748, '0', 0, 0, 0, 2, 265.3125, -795.59893798828125, 48.99958038330078125, 2.757620096206665039, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Peasant Worker (Area: Quarry - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+69, 19444, 628, 4710, 4748, '0', 0, 0, 0, 4, 255.423614501953125, -791.1163330078125, 52.6163177490234375, 1.65806281566619873, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Peasant Worker (Area: Quarry - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+70, 19444, 628, 4710, 4748, '0', 0, 0, 0, 4, 258.33160400390625, -792.6961669921875, 63.36460113525390625, 5.98647928237915039, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Peasant Worker (Area: Quarry - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+71, 19444, 628, 4710, 4748, '0', 0, 0, 0, 0, 271.357635498046875, -790.48785400390625, 48.96506500244140625, 6.009759426116943359, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Peasant Worker (Area: Quarry - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+93, 19444, 628, 4710, 4748, '0', 0, 0, 0, 4, 240.986114501953125, -787.29864501953125, 73.56451416015625, 5.777040004730224609, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Peasant Worker (Area: Quarry - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+94, 19444, 628, 4710, 4748, '0', 0, 0, 0, 2, 265.524322509765625, -778.732666015625, 48.99958038330078125, 2.111848354339599609, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Peasant Worker (Area: Quarry - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+95, 19444, 628, 4710, 4748, '0', 0, 0, 0, 2, 238.8090362548828125, -786.42535400390625, 55.42572784423828125, 3.385938644409179687, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 53007); -- Peasant Worker (Area: Quarry - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)

-- Forsaken Miner
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+80, 15075, 628, 4710, 4748, '0', 0, 0, 0, 1, 226.626739501953125, -1068.6961669921875, 27.455169677734375, 1.623156189918518066, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Forsaken Miner (Area: Quarry - Difficulty: 0) CreateObject2
(@CGUID+81, 15075, 628, 4710, 4748, '0', 0, 0, 0, 1, 174.62847900390625, -1132.4410400390625, 10.53891181945800781, 2.94960641860961914, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Forsaken Miner (Area: Quarry - Difficulty: 0) CreateObject2
(@CGUID+82, 15075, 628, 4710, 4748, '0', 0, 0, 0, 1, 300.42535400390625, -1180.0069580078125, 16.7330169677734375, 1.431169986724853515, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Forsaken Miner (Area: Quarry - Difficulty: 0) CreateObject2
(@CGUID+83, 15075, 628, 4710, 4748, '0', 0, 0, 0, 1, 231.904510498046875, -1076.3663330078125, 17.85601425170898437, 1.884955525398254394, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Forsaken Miner (Area: Quarry - Difficulty: 0) CreateObject2
(@CGUID+84, 15075, 628, 4710, 4748, '0', 0, 0, 0, 1, 197.4131927490234375, -1107.0260009765625, 16.24344825744628906, 2.460914134979248046, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Forsaken Miner (Area: Quarry - Difficulty: 0) CreateObject2
(@CGUID+85, 15075, 628, 4710, 4748, '0', 0, 0, 0, 1, 203.451385498046875, -1102.0382080078125, 8.814992904663085937, 3.560471534729003906, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Forsaken Miner (Area: Quarry - Difficulty: 0) CreateObject2
(@CGUID+86, 15075, 628, 4710, 4748, '0', 0, 0, 0, 1, 302.197906494140625, -1141.2257080078125, 30.97160530090332031, 5.497786998748779296, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Forsaken Miner (Area: Quarry - Difficulty: 0) CreateObject2
(@CGUID+87, 15075, 628, 4710, 4748, '0', 0, 0, 0, 1, 320.243072509765625, -1147.7430419921875, 34.2675628662109375, 4.084070205688476562, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Forsaken Miner (Area: Quarry - Difficulty: 0) CreateObject2
(@CGUID+88, 15075, 628, 4710, 4748, '0', 0, 0, 0, 1, 331.192718505859375, -1129.8316650390625, 19.95678901672363281, 3.647738218307495117, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Forsaken Miner (Area: Quarry - Difficulty: 0) CreateObject2
(@CGUID+89, 15075, 628, 4710, 4748, '0', 0, 0, 0, 1, 273.28125, -1260.579833984375, 42.1154632568359375, 4.956735134124755859, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Forsaken Miner (Area: Quarry - Difficulty: 0) CreateObject1
(@CGUID+90, 15075, 628, 4710, 4748, '0', 0, 0, 0, 1, 303.885406494140625, -1243.829833984375, 25.91202926635742187, 4.660028934478759765, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Forsaken Miner (Area: Quarry - Difficulty: 0) CreateObject1
(@CGUID+91, 15075, 628, 4710, 4748, '0', 0, 0, 0, 1, 172.86285400390625, -1174.263916015625, 2.087067365646362304, 3.281219005584716796, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007), -- Forsaken Miner (Area: Quarry - Difficulty: 0) CreateObject1
(@CGUID+92, 15075, 628, 4710, 4748, '0', 0, 0, 0, 1, 374.927093505859375, -1160.296875, 28.20929718017578125, 5.235987663269042968, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007); -- Forsaken Miner (Area: Quarry - Difficulty: 0) CreateObject1

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+191, 51435, 641, 4710, 4752, '0', 0, 0, 0, 0, -13.1210212707519531, -0.0992838516831398, 24.45633125305175781, 3.106686115264892578, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Alliance Gunship (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+192, 51436, 642, 4710, 4752, '0', 0, 0, 0, 0, -5.64433193206787109, 0.352720469236373901, 34.79607009887695312, 3.03687286376953125, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Horde Gunship (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+193, 35003, 642, 4710, 4750, '0', 0, 0, 0, 0, 2.516399621963500976, -3.52628135681152343, 34.24978256225585937, 1.558264493942260742, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007); -- Horde Gunship Captain (Area: Hangar - Difficulty: 0) CreateObject1 (Auras: 47934 - [DND] Force Response - Salute (0. Aura)) (possible waypoints or random movement)

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `ScriptName`, `VerifiedBuild`) VALUES
(@CGUID+194, 35003, 628, 4710, 4750, '0', 0, 0, 0, 0, 825.66668701171875, -994.00518798828125, 134.3568878173828125, 3.40339207649230957, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 'npc_ioc_gunship_captain', 53162), -- Horde Gunship Captain (Area: Hangar - Difficulty: 0) CreateObject2
(@CGUID+195, 51435, 628, 4710, 4750, '0', 0, 0, 0, 0, 825.66668701171875, -994.00518798828125, 134.3568878173828125, 3.40339207649230957, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 'npc_ioc_gunship_captain', 0); -- Alliance Gunship Captain (Area: Hangar - Difficulty: 0) CreateObject2

-- keep bosses
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+199, 34924, 628, 4710, 4747, '0', 0, 0, 0, 1, 224.982635498046875, -831.57293701171875, 60.90335464477539062, 0, 7200, 0, 0, 44038410, 0, 0, NULL, NULL, NULL, NULL, 53162), -- High Commander Halford Wyrmbane (Area: Workshop - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+200, 34919, 628, 4710, 4753, '0', 0, 0, 0, 1, 262.763885498046875, -837.32293701171875, 50.52349090576171875, 0, 7200, 0, 0, 56460, 0, 0, NULL, NULL, NULL, NULL, 53007), -- 7th Legion Infantry (Area: Alliance Keep - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+201, 34919, 628, 4710, 4753, '0', 0, 0, 0, 1, 262.90972900390625, -830.4757080078125, 50.52349472045898437, 0, 7200, 0, 0, 56460, 0, 0, NULL, NULL, NULL, NULL, 53007), -- 7th Legion Infantry (Area: Alliance Keep - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+202, 34919, 628, 4710, 4753, '0', 0, 0, 0, 1, 262.87847900390625, -833.8680419921875, 50.52349472045898437, 0, 7200, 0, 0, 56460, 0, 0, NULL, NULL, NULL, NULL, 53007), -- 7th Legion Infantry (Area: Alliance Keep - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+203, 34919, 628, 4710, 4753, '0', 0, 0, 0, 1, 262.967010498046875, -826.7725830078125, 50.52349090576171875, 0, 7200, 0, 0, 56460, 0, 0, NULL, NULL, NULL, NULL, 53007), -- 7th Legion Infantry (Area: Alliance Keep - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+204, 34919, 628, 4710, 0, '0', 0, 0, 0, 1, 224.376739501953125, -827.40106201171875, 60.90335464477539062, 0, 7200, 0, 0, 56460, 0, 0, NULL, NULL, NULL, NULL, 53162), -- 7th Legion Infantry (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+205, 34919, 628, 4710, 0, '0', 0, 0, 0, 1, 223.3229217529296875, -833.21875, 60.90335464477539062, 0, 7200, 0, 0, 56460, 0, 0, NULL, NULL, NULL, NULL, 53162), -- 7th Legion Infantry (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+206, 34919, 628, 4710, 0, '0', 0, 0, 0, 1, 223.8402862548828125, -835.513916015625, 60.90335464477539062, 0, 7200, 0, 0, 56460, 0, 0, NULL, NULL, NULL, NULL, 53162), -- 7th Legion Infantry (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+207, 34919, 628, 4710, 0, '0', 0, 0, 0, 1, 223.2934112548828125, -829.2100830078125, 60.90335464477539062, 0, 7200, 0, 0, 56460, 0, 0, NULL, NULL, NULL, NULL, 53162), -- 7th Legion Infantry (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+208, 34918, 628, 4710, 4752, '0', 0, 0, 0, 1, 1294.7535400390625, -761.451416015625, 70.0415496826171875, 0, 7200, 0, 0, 56460, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Kor'kron Guard (Area: Horde Keep - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+209, 34918, 628, 4710, 4752, '0', 0, 0, 0, 1, 1300.5399169921875, -764.08160400390625, 50.70293045043945312, 2.897246599197387695, 7200, 0, 0, 56460, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Kor'kron Guard (Area: Horde Keep - Difficulty: 0) CreateObject2 (Auras: ) (possible waypoints or random movement)
(@CGUID+210, 34918, 628, 4710, 4752, '0', 0, 0, 0, 1, 1295.7100830078125, -757.5399169921875, 70.04154205322265625, 0, 7200, 0, 0, 56460, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Kor'kron Guard (Area: Horde Keep - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+211, 34918, 628, 4710, 4752, '0', 0, 0, 0, 1, 1300.4322509765625, -775.70660400390625, 50.70293045043945312, 2.897246599197387695, 7200, 0, 0, 56460, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Kor'kron Guard (Area: Horde Keep - Difficulty: 0) CreateObject2 (Auras: ) (possible waypoints or random movement)
(@CGUID+212, 34922, 628, 4710, 4752, '0', 0, 0, 0, 1, 1295.439208984375, -765.732666015625, 70.0540618896484375, 0, 7200, 0, 0, 44038410, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Overlord Agmar (Area: Horde Keep - Difficulty: 0) CreateObject2 (Auras: 177684 - Unit Frame)
(@CGUID+213, 34918, 628, 4710, 4752, '0', 0, 0, 0, 1, 1294.9600830078125, -770.52606201171875, 70.04145050048828125, 0, 7200, 0, 0, 56460, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Kor'kron Guard (Area: Horde Keep - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+214, 34918, 628, 4710, 4752, '0', 0, 0, 0, 1, 1300.8697509765625, -757.95831298828125, 50.70293045043945312, 2.897246599197387695, 7200, 0, 0, 56460, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Kor'kron Guard (Area: Horde Keep - Difficulty: 0) CreateObject2 (Auras: ) (possible waypoints or random movement)
(@CGUID+215, 34918, 628, 4710, 4752, '0', 0, 0, 0, 1, 1300.76220703125, -769.58331298828125, 50.70293045043945312, 2.897246599197387695, 7200, 0, 0, 56460, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Kor'kron Guard (Area: Horde Keep - Difficulty: 0) CreateObject2 (Auras: ) (possible waypoints or random movement)
(@CGUID+216, 34918, 628, 4710, 4752, '0', 0, 0, 0, 1, 1296.0660400390625, -774.78472900390625, 70.04144287109375, 0, 7200, 0, 0, 56460, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Kor'kron Guard (Area: Horde Keep - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+217, 36169, 628, 4710, 4752, '0', 0, 0, 0, 1, 1233.154541015625, -685.33331298828125, 49.32620620727539062, 0.506145477294921875, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007), -- [DND] Bor'gorok Peon (Area: Horde Keep - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+218, 36169, 628, 4710, 4752, '0', 0, 0, 0, 1, 1323.454833984375, -717.48956298828125, 52.20786285400390625, 2.617993831634521484, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007), -- [DND] Bor'gorok Peon (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+219, 36169, 628, 4710, 4752, '0', 0, 0, 0, 1, 1251.34375, -685.13543701171875, 49.13456344604492187, 3.857177734375, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007), -- [DND] Bor'gorok Peon (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+220, 36167, 628, 4710, 4752, '0', 0, 0, 0, 0, 1325.0972900390625, -804.70660400390625, 49.04310226440429687, 3.333578824996948242, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007), -- [DND] Bor'gorok Wolf (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+221, 36169, 628, 4710, 4752, '0', 0, 0, 0, 1, 1315.248291015625, -713.0242919921875, 65.445953369140625, 0.279252678155899047, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007), -- [DND] Bor'gorok Peon (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+222, 36169, 628, 4710, 4752, '0', 0, 0, 0, 1, 1333.7083740234375, -710.1319580078125, 48.9995880126953125, 4.206243515014648437, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007), -- [DND] Bor'gorok Peon (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+223, 36167, 628, 4710, 4752, '0', 0, 0, 0, 0, 1353.0225830078125, -832.2742919921875, 49.07046890258789062, 2.373647689819335937, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007), -- [DND] Bor'gorok Wolf (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+224, 36169, 628, 4710, 4752, '0', 0, 0, 0, 1, 1317.84375, -696.78302001953125, 48.943145751953125, 4.520402908325195312, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007), -- [DND] Bor'gorok Peon (Area: Horde Keep - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+225, 36167, 628, 4710, 4752, '0', 0, 0, 0, 0, 1332.24658203125, -842.1007080078125, 49.14832305908203125, 2.600540637969970703, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007), -- [DND] Bor'gorok Wolf (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+226, 36169, 628, 4710, 4752, '0', 0, 0, 0, 1, 1321.1754150390625, -706.3507080078125, 69.2999267578125, 0.03490658476948738, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007), -- [DND] Bor'gorok Peon (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+227, 36154, 628, 4710, 4752, '0', 0, 0, 0, 0, 1159.3350830078125, -817.39581298828125, 48.95509719848632812, 0, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007), -- [DND] Valgarde Peon (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+228, 36154, 628, 4710, 4752, '0', 0, 0, 0, 0, 1188.6007080078125, -845.0538330078125, 49.0836944580078125, 2.129301786422729492, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007), -- [DND] Valgarde Peon (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+229, 36154, 628, 4710, 4752, '0', 0, 0, 0, 0, 1157.2274169921875, -822.576416015625, 53.09723663330078125, 0, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007), -- [DND] Valgarde Peon (Area: Horde Keep - Difficulty: 0) CreateObject1
(@CGUID+230, 36154, 628, 4710, 4752, '0', 0, 0, 0, 0, 1158.7066650390625, -822.921875, 49.03955078125, 0.558505356311798095, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53007); -- [DND] Valgarde Peon (Area: Horde Keep - Difficulty: 0) CreateObject1

-- Delete duplicate cannons
DELETE FROM `creature` WHERE `guid` IN (142965, 142966, 142967, 142968, 142969, 142970, 142971, 142972, 142973, 142974);
-- update current cannons
UPDATE `creature` SET `spawnDifficulties` = '0', `position_x` = -12.1064128875732421, `position_y` = -31.969635009765625, `position_z` = 34.463897705078125, `orientation` = 4.625122547149658203, `curhealth` = 451676, `VerifiedBuild` = 53162 WHERE `guid` = 75000;
UPDATE `creature` SET `spawnDifficulties` = '0', `position_x` = 19.46366691589355468, `position_y` = -30.7939929962158203, `position_z` = 36.30840682983398437, `orientation` = 4.852015495300292968, `curhealth` = 451676, `VerifiedBuild` = 53162 WHERE `guid` = 75001;
UPDATE `creature` SET `spawnDifficulties` = '0', `position_x` = -2.48760795593261718, `position_y` = -31.9885425567626953, `position_z` = 34.92169570922851562, `orientation` = 4.834561824798583984, `curhealth` = 451676, `VerifiedBuild` = 53162 WHERE `guid` = 75002;
UPDATE `creature` SET `spawnDifficulties` = '0', `position_x` = 10.26639747619628906, `position_y` = -32.0712966918945312, `position_z` = 35.81895065307617187, `orientation` = 4.852015495300292968, `curhealth` = 451676, `VerifiedBuild` = 53162 WHERE `guid` = 75003;
UPDATE `creature` SET `spawnDifficulties` = '0', `position_x` = -21.4009037017822265, `position_y` = -31.3430347442626953, `position_z` = 34.2563323974609375, `orientation` = 4.677482128143310546, `curhealth` = 451676, `VerifiedBuild` = 53162 WHERE `guid` = 75004;
UPDATE `creature` SET `spawnDifficulties` = '0', `position_x` = -31.0354042053222656, `position_y` = 24.86196708679199218, `position_z` = 21.7027435302734375, `orientation` = 1.65806281566619873, `curhealth` = 451676, `VerifiedBuild` = 53162 WHERE `guid` = 75005;
UPDATE `creature` SET `spawnDifficulties` = '0', `position_x` = -12.4733877182006835, `position_y` = 25.72649765014648437, `position_z` = 21.678131103515625, `orientation` = 1.65806281566619873, `curhealth` = 451676, `VerifiedBuild` = 53162 WHERE `guid` = 75006;
UPDATE `creature` SET `spawnDifficulties` = '0', `position_x` = -21.4492530822753906, `position_y` = 25.398895263671875, `position_z` = 21.66955757141113281, `orientation` = 1.65806281566619873, `curhealth` = 451676, `VerifiedBuild` = 53162 WHERE `guid` = 75007;
UPDATE `creature` SET `spawnDifficulties` = '0', `position_x` = -41.7122764587402343, `position_y` = 22.90813636779785156, `position_z` = 22.60103225708007812, `orientation` = 1.902408838272094726, `curhealth` = 451676, `VerifiedBuild` = 53162 WHERE `guid` = 75008;
UPDATE `creature` SET `spawnDifficulties` = '0', `position_x` = -2.81130409240722656, `position_y` = 25.78116035461425781, `position_z` = 21.69147872924804687, `orientation` = 1.65806281566619873, `curhealth` = 451676, `VerifiedBuild` = 53162 WHERE `guid` = 75009;

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+10000;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+58, 0, 0, 0, 0, 0, 1, 0, 234, 0, 0, 0, 0, '18950'), -- Peasant Worker - 18950 - Invisibility and Stealth Detection
(@CGUID+61, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, '18950'), -- Peasant Worker - 18950 - Invisibility and Stealth Detection
(@CGUID+62, 0, 0, 0, 0, 0, 1, 0, 234, 0, 0, 0, 0, '18950'), -- Peasant Worker - 18950 - Invisibility and Stealth Detection
(@CGUID+63, 0, 0, 0, 0, 0, 1, 0, 234, 0, 0, 0, 0, '18950'), -- Peasant Worker - 18950 - Invisibility and Stealth Detection
(@CGUID+65, 0, 0, 0, 0, 0, 1, 0, 234, 0, 0, 0, 0, '18950'), -- Peasant Worker - 18950 - Invisibility and Stealth Detection
(@CGUID+66, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, '18950'), -- Peasant Worker - 18950 - Invisibility and Stealth Detection
(@CGUID+67, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '18950'), -- Peasant Worker - 18950 - Invisibility and Stealth Detection
(@CGUID+68, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, '18950'), -- Peasant Worker - 18950 - Invisibility and Stealth Detection
(@CGUID+69, 0, 0, 0, 0, 0, 1, 0, 234, 0, 0, 0, 0, '18950'), -- Peasant Worker - 18950 - Invisibility and Stealth Detection
(@CGUID+70, 0, 0, 0, 0, 0, 1, 0, 234, 0, 0, 0, 0, '18950'), -- Peasant Worker - 18950 - Invisibility and Stealth Detection
(@CGUID+71, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '18950'), -- Peasant Worker - 18950 - Invisibility and Stealth Detection
(@CGUID+93, 0, 0, 0, 0, 0, 1, 0, 234, 0, 0, 0, 0, '18950'), -- Peasant Worker - 18950 - Invisibility and Stealth Detection
(@CGUID+94, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, '18950'), -- Peasant Worker - 18950 - Invisibility and Stealth Detection
(@CGUID+95, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, '18950'), -- Peasant Worker - 18950 - Invisibility and Stealth Detection
(@CGUID+217, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- [DND] Bor'gorok Peon
(@CGUID+218, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- [DND] Bor'gorok Peon
(@CGUID+220, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- [DND] Bor'gorok Wolf
(@CGUID+221, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- [DND] Bor'gorok Peon
(@CGUID+224, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- [DND] Bor'gorok Peon
(@CGUID+226, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, ''); -- [DND] Bor'gorok Peon

UPDATE `creature_template_addon` SET `StandState`=1 WHERE `entry`=25748; -- 25748 (Oil-covered Hawk) - Oil Coat
UPDATE `creature_template_addon` SET `auras`='52455' WHERE `entry`=34775; -- 34775 (Demolisher) - PvP Vehicle Health Regen Suppression
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=35069; -- 35069 (Siege Engine)
UPDATE `creature_template_addon` SET `auras`='52455' WHERE `entry`=34793; -- 34793 (Catapult) - PvP Vehicle Health Regen Suppression
UPDATE `creature_template_addon` SET `auras`='52455' WHERE `entry`=35273; -- 35273 (Glaive Thrower) - PvP Vehicle Health Regen Suppression
UPDATE `creature_template_addon` SET `visibilityDistanceType`=5, `auras`='177684' WHERE `entry`=34924; -- 34924 (High Commander Halford Wyrmbane) - Unit Frame
UPDATE `creature_template_addon` SET `auras`='67359' WHERE `entry`=35377; -- 35377 (Door Fire) - Door Fire
UPDATE `creature_template_addon` SET `auras`='75925 52455' WHERE `entry`=34944; -- 34944 (Keep Cannon) - Facing Saver, PvP Vehicle Health Regen Suppression

DELETE FROM `creature_template_addon` WHERE `entry` IN (15075 /*Forsaken Miner*/, 61696 /*Human Miner*/, 36148 /*36148 ([DND] Forsaken Mariner)*/, 35380 /*35380 (Honorable Defender Trigger (Horde)) - Honorable Defender*/, 35003 /*35003 (Horde Gunship Captain) - [DND] Force Response - Salute (0. Aura)*/, 36164 /*36164 (Kor'kron Reaver)*/, 36152 /*36152 (Navigator Saracen)*/, 36151 /*36151 (Navigator Taylor)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(36148, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 36148 ([DND] Forsaken Mariner)
(35380, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '66157'), -- 35380 (Honorable Defender Trigger (Horde)) - Honorable Defender
(35003, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '47934'), -- 35003 (Horde Gunship Captain) - [DND] Force Response - Salute (0. Aura)
(36164, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 36164 (Kor'kron Reaver)
(36152, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 36152 (Navigator Saracen)
(36151, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 36151 (Navigator Taylor)
(61696, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, ''), -- 61696 (Human Miner)
(15075, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, ''); -- 15075 (Forsaken Miner)

UPDATE `creature_template` SET `faction` = 1732 WHERE `entry` = 34802;

UPDATE `creature_template` SET `ScriptName` = 'npc_ioc_siege_engine' WHERE `entry` IN (34776, 35069);

UPDATE `creature_template` SET `ScriptName` = '' WHERE `ScriptName` = 'npc_ioc_gunship_captain';

UPDATE `creature_template_difficulty` SET `ContentTuningID`=958, `VerifiedBuild`=53162 WHERE (`Entry`=34919 AND `DifficultyID`=0); -- 7th Legion Infantry
UPDATE `creature_template_difficulty` SET `ContentTuningID`=958, `VerifiedBuild`=53162 WHERE (`Entry`=34924 AND `DifficultyID`=0); -- High Commander Halford Wyrmbane

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+10000;
-- Cosmetics
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 195377, 628, 4710, 4752, '0', 0, 0, 1162.2100830078125, -790.54339599609375, 48.91624832153320312, 2.277654170989990234, 0, 0, 0.908143043518066406, 0.418660014867782592, 7200, 255, 1, 53007), -- Bonfire (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+3, 195403, 628, 4710, 4752, '0', 0, 0, 1262.579833984375, -781.86114501953125, 48.81315994262695312, 2.042031526565551757, 0, 0, 0.852639198303222656, 0.522500097751617431, 7200, 255, 1, 53007), -- Brazier (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+37, 195425, 628, 4710, 0, '0', 0, 0, 223.8183746337890625, -839.3519287109375, 60.79163360595703125, 1.090830326080322265, 0, 0, 0.518773078918457031, 0.854911983013153076, 7200, 255, 1, 53007), -- Brazier (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+40, 195424, 628, 4710, 4748, '0', 0, 0, 224.2770843505859375, -822.7701416015625, 60.79163360595703125, 2.068215370178222656, 0, 0, 0.859406471252441406, 0.511292934417724609, 7200, 255, 1, 53007), -- Brazier (Area: Quarry - Difficulty: 0) CreateObject1
(@OGUID+47, 160411, 628, 4710, 0, '0', 0, 0, 761.462158203125, -446.683807373046875, 22.56014823913574218, 0.24434363842010498, 0, 0, 0.121868133544921875, 0.992546260356903076, 7200, 255, 1, 53007), -- Stove (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+48, 160413, 628, 4710, 0, '0', 0, 0, 762.9974365234375, -445.86358642578125, 22.85254096984863281, 3.28996133804321289, 0, 0, -0.99724960327148437, 0.074116282165050506, 7200, 255, 1, 53007), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+49, 160415, 628, 4710, 0, '0', 0, 0, 762.24468994140625, -444.7945556640625, 22.85254096984863281, 4.302238941192626953, 0, 0, -0.83628559112548828, 0.5482940673828125, 7200, 255, 1, 53007), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+50, 160414, 628, 4710, 0, '0', 0, 0, 762.9208984375, -447.259063720703125, 22.85254096984863281, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 7200, 255, 1, 53007), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+51, 195418, 628, 4710, 0, '0', 0, 0, 632.15643310546875, -304.5028076171875, 5.487901687622070312, 1.156033277511596679, 0, 0, 0.54636383056640625, 0.837547957897186279, 7200, 255, 1, 53007), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+52, 195411, 628, 4710, 0, '0', 0, 0, 633.96527099609375, -283.52777099609375, 5.453640937805175781, 2.369039058685302734, 0, 0, 0.926318168640136718, 0.376742124557495117, 7200, 255, 1, 53007), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+53, 195410, 628, 4710, 0, '0', 0, 0, 632.8760986328125, -282.461181640625, 5.453640937805175781, 5.432093620300292968, 0, 0, -0.41281795501708984, 0.910813570022583007, 7200, 255, 1, 53007), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+54, 195413, 628, 4710, 0, '0', 0, 0, 631.4180908203125, -278.137115478515625, 5.486441612243652343, 5.432093620300292968, 0, 0, -0.41281795501708984, 0.910813570022583007, 7200, 255, 1, 53007), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+55, 195412, 628, 4710, 0, '0', 0, 0, 632.63323974609375, -279.27374267578125, 5.486441612243652343, 2.369039058685302734, 0, 0, 0.926318168640136718, 0.376742124557495117, 7200, 255, 1, 53007), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+56, 195415, 628, 4710, 0, '0', 0, 0, 634.68426513671875, -276.426177978515625, 5.486584663391113281, 0.03029748611152172, 0, 0, 0.015148162841796875, 0.999885261058807373, 7200, 255, 1, 53007), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+57, 160416, 628, 4710, 0, '0', 0, 0, 798.32391357421875, -444.950897216796875, 22.56005096435546875, 5.26216888427734375, 0, 0, -0.48862075805664062, 0.872496306896209716, 7200, 255, 1, 53007), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+58, 195414, 628, 4710, 0, '0', 0, 0, 635.79608154296875, -276.2947998046875, 5.486584663391113281, 3.250456571578979492, 0, 0, -0.99851894378662109, 0.054405026137828826, 7200, 255, 1, 53007), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+59, 195417, 628, 4710, 0, '0', 0, 0, 642.7708740234375, -269.137420654296875, 5.488974571228027343, 5.432093620300292968, 0, 0, -0.41281795501708984, 0.910813570022583007, 7200, 255, 1, 53007), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+60, 195416, 628, 4710, 0, '0', 0, 0, 643.86004638671875, -270.20391845703125, 5.488974571228027343, 2.369039058685302734, 0, 0, 0.926318168640136718, 0.376742124557495117, 7200, 255, 1, 53007), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+61, 186897, 628, 4710, 0, '0', 0, 0, 819.2640380859375, -461.961181640625, 22.76141166687011718, 1.579522609710693359, -0.00304460525512695, -0.00312519073486328, 0.710178375244140625, 0.704008281230926513, 7200, 255, 1, 53007), -- Bench (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+62, 186899, 628, 4710, 0, '0', 0, 0, 817.4462890625, -470.46966552734375, 25.37198638916015625, 4.721118450164794921, 0, 0, -0.70401382446289062, 0.710186243057250976, 7200, 255, 1, 53007), -- Bench (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+63, 186901, 628, 4710, 0, '0', 0, 0, 826.9306640625, -470.380340576171875, 25.37198638916015625, 4.721118450164794921, 0, 0, -0.70401382446289062, 0.710186243057250976, 7200, 255, 1, 53007), -- Bench (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+64, 186900, 628, 4710, 0, '0', 0, 0, 822.15185546875, -470.433563232421875, 25.37198638916015625, 4.721118450164794921, 0, 0, -0.70401382446289062, 0.710186243057250976, 7200, 255, 1, 53007), -- Bench (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+65, 186903, 628, 4710, 0, '0', 0, 0, 822.2222900390625, -474.467803955078125, 25.37198638916015625, 1.579522013664245605, 0, 0, 0.710185050964355468, 0.704015016555786132, 7200, 255, 1, 53007), -- Bench (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+66, 186902, 628, 4710, 0, '0', 0, 0, 817.5167236328125, -474.503936767578125, 25.37198638916015625, 1.579522013664245605, 0, 0, 0.710185050964355468, 0.704015016555786132, 7200, 255, 1, 53007), -- Bench (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+67, 186904, 628, 4710, 0, '0', 0, 0, 827.00103759765625, -474.41461181640625, 25.37198638916015625, 1.579522013664245605, 0, 0, 0.710185050964355468, 0.704015016555786132, 7200, 255, 1, 53007), -- Bench (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+68, 160419, 628, 4710, 0, '0', 0, 0, 814.930908203125, -470.815521240234375, 33.63730621337890625, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 7200, 255, 1, 53007), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+69, 160418, 628, 4710, 0, '0', 0, 0, 810.23651123046875, -461.2003173828125, 25.46265792846679687, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 53007), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+70, 160420, 628, 4710, 0, '0', 0, 0, 813.23382568359375, -475.408050537109375, 33.57374954223632812, 6.213373661041259765, 0, 0, -0.03489875793457031, 0.999390840530395507, 7200, 255, 1, 53007), -- Stove (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+71, 186922, 628, 4710, 0, '0', 0, 0, 826.15289306640625, -461.984771728515625, 22.514923095703125, 1.570796370506286621, -0.00617122650146484, -0.00617027282714843, 0.707079887390136718, 0.707079827785491943, 7200, 255, 1, 53007), -- Bench (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+72, 186896, 628, 4710, 0, '0', 0, 0, 834.20782470703125, -461.825592041015625, 22.30665206909179687, 1.570796370506286621, -0.00617122650146484, -0.00617027282714843, 0.707079887390136718, 0.707079827785491943, 7200, 255, 1, 53007), -- Bench (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+73, 174863, 628, 4710, 0, '0', 0, 0, 903.29071044921875, -457.344818115234375, 18.13561820983886718, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 7200, 255, 1, 53007), -- Stove (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+74, 160409, 628, 4710, 0, '0', 0, 0, 901.24652099609375, -457.39837646484375, 18.39345932006835937, 0.008724239654839038, 0, 0, 0.004362106323242187, 0.999990463256835937, 7200, 255, 1, 53007), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+75, 160410, 628, 4710, 0, '0', 0, 0, 902.2344970703125, -455.507965087890625, 18.39345932006835937, 5.279621601104736328, 0, 0, -0.4809885025024414, 0.876726925373077392, 7200, 255, 1, 53007), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+81, 160409, 628, 4710, 4749, '0', 0, 0, 1067.9530029296875, -338.4100341796875, 18.82249069213867187, 1.466073274612426757, 0, 0, 0.669129371643066406, 0.743145942687988281, 7200, 255, 1, 53007), -- Chair (Area: Docks - Difficulty: 0) CreateObject1
(@OGUID+82, 160410, 628, 4710, 4749, '0', 0, 0, 1066.1865234375, -337.214385986328125, 18.82249069213867187, 0.453785061836242675, 0, 0, 0.224950790405273437, 0.974370121955871582, 7200, 255, 1, 53007), -- Chair (Area: Docks - Difficulty: 0) CreateObject1
(@OGUID+83, 174863, 628, 4710, 4749, '0', 0, 0, 1068.1312255859375, -336.372894287109375, 18.56464958190917968, 3.691374778747558593, 0, 0, -0.96245479583740234, 0.271441996097564697, 7200, 255, 1, 53007), -- Stove (Area: Docks - Difficulty: 0) CreateObject1
(@OGUID+84, 160416, 628, 4710, 4749, '0', 0, 0, 1081.805419921875, -358.63665771484375, 18.5531463623046875, 1.928588032722473144, 0, 0, 0.821646690368652343, 0.569997072219848632, 7200, 255, 1, 53007), -- Chair (Area: Docks - Difficulty: 0) CreateObject1
(@OGUID+85, 160411, 628, 4710, 4749, '0', 0, 0, 1118.320556640625, -363.9691162109375, 18.55324363708496093, 3.194002151489257812, 0, 0, -0.99965667724609375, 0.026201646775007247, 7200, 255, 1, 53007), -- Stove (Area: Docks - Difficulty: 0) CreateObject1
(@OGUID+86, 160413, 628, 4710, 4749, '0', 0, 0, 1116.656982421875, -364.481353759765625, 18.84563636779785156, 6.239553451538085937, 0, 0, -0.02181434631347656, 0.99976205825805664, 7200, 255, 1, 53007), -- Chair (Area: Docks - Difficulty: 0) CreateObject1
(@OGUID+87, 160415, 628, 4710, 4749, '0', 0, 0, 1117.19189453125, -365.67437744140625, 18.84563636779785156, 0.968655109405517578, 0, 0, 0.465613365173339843, 0.884988248348236083, 7200, 255, 1, 53007), -- Chair (Area: Docks - Difficulty: 0) CreateObject1
(@OGUID+88, 160414, 628, 4710, 4749, '0', 0, 0, 1116.9984130859375, -363.1260986328125, 18.84563636779785156, 5.777042865753173828, 0, 0, -0.25037860870361328, 0.968147993087768554, 7200, 255, 1, 53007), -- Chair (Area: Docks - Difficulty: 0) CreateObject1
(@OGUID+95, 195376, 628, 4710, 0, '0', 0, 0, 1162.9132080078125, -734.578125, 48.89479446411132812, 3.298687219619750976, 0, 0, -0.99691677093505859, 0.078466430306434631, 7200, 255, 1, 53007), -- Bonfire (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+96, 195402, 628, 4710, 0, '0', 0, 0, 1262.2083740234375, -751.357666015625, 48.81328201293945312, 2.268925428390502929, 0, 0, 0.906307220458984375, 0.422619491815567016, 7200, 255, 1, 53007), -- Brazier (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+97, 195207, 628, 4710, 0, '0', 0, 0, 1281.7579345703125, -732.84429931640625, 87.1573944091796875, 3.150726795196533203, 0.012359142303466796, -0.01225185394287109, -0.99983882904052734, 0.004414829425513744, 7200, 255, 1, 53007), -- Bonfire (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+98, 195208, 628, 4710, 0, '0', 0, 0, 1282.3419189453125, -799.76226806640625, 87.135711669921875, 3.150327444076538085, 0, 0, -0.99999046325683593, 0.004367320332676172, 7200, 255, 1, 53007), -- Bonfire (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+113, 195209, 628, 4710, 4752, '0', 0, 0, 1358.814697265625, -797.898681640625, 87.2953338623046875, 3.133123159408569335, 0.0067901611328125, -0.01746177673339843, 0.999814987182617187, 0.004353650845587253, 7200, 255, 1, 53007), -- Bonfire (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+114, 195210, 628, 4710, 4752, '0', 0, 0, 1358.0614013671875, -732.17840576171875, 87.16064453125, 3.150349617004394531, -0.005615234375, -0.0065164566040039, -0.99995326995849609, 0.004414829425513744, 7200, 255, 1, 53007); -- Bonfire (Area: Horde Keep - Difficulty: 0) CreateObject1

-- Teleporters
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+4, 195315, 628, 4710, 4752, '0', 0, 0, 425.67535400390625, -857.09027099609375, 48.51041793823242187, 4.677483558654785156, 0, 0, -0.71933937072753906, 0.694658815860748291, 7200, 255, 1, 53007), -- Teleporter (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+10, 195316, 628, 4710, 0, '0', 0, 0, 397.088531494140625, -859.3819580078125, 48.8993072509765625, 1.640606880187988281, 0, 0, 0.731352806091308593, 0.6819993257522583, 7200, 255, 1, 53007), -- Teleporter (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+11, 195316, 628, 4710, 0, '0', 0, 0, 323.539947509765625, -888.36114501953125, 48.91973495483398437, 0.034906249493360519, 0, 0, 0.017452239990234375, 0.999847710132598876, 7200, 255, 1, 53007), -- Teleporter (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+12, 195315, 628, 4710, 0, '0', 0, 0, 311.920135498046875, -913.97222900390625, 48.81592178344726562, 3.089183330535888671, 0, 0, 0.99965667724609375, 0.026201646775007247, 7200, 255, 1, 53007), -- Teleporter (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+17, 195316, 628, 4710, 4750, '0', 0, 0, 326.28472900390625, -777.3663330078125, 49.02083206176757812, 3.124123096466064453, 0, 0, 0.99996185302734375, 0.008734640665352344, 7200, 255, 1, 53007), -- Teleporter (Area: Hangar - Difficulty: 0) CreateObject1
(@OGUID+20, 195315, 628, 4710, 4750, '0', 0, 0, 324.635406494140625, -749.12847900390625, 49.3601837158203125, 0.017452461645007133, 0, 0, 0.008726119995117187, 0.999961912631988525, 7200, 255, 1, 53007), -- Teleporter (Area: Hangar - Difficulty: 0) CreateObject1
(@OGUID+76, 195313, 628, 4710, 4749, '0', 0, 0, 1158.76220703125, -746.18231201171875, 48.62767791748046875, 4.764749526977539062, 0, 0, -0.6883544921875, 0.725374460220336914, 7200, 255, 1, 53007), -- Teleporter (Area: Docks - Difficulty: 0) CreateObject1
(@OGUID+77, 195314, 628, 4710, 4749, '0', 0, 0, 1143.25, -779.59893798828125, 48.62895584106445312, 1.640606880187988281, 0, 0, 0.731352806091308593, 0.6819993257522583, 7200, 255, 1, 53007), -- Teleporter (Area: Docks - Difficulty: 0) CreateObject1
(@OGUID+79, 195314, 628, 4710, 4749, '0', 0, 0, 1236.53125, -669.4149169921875, 48.27285385131835937, 0.104719325900077819, 0, 0, 0.052335739135742187, 0.998629570007324218, 7200, 255, 1, 53007), -- Teleporter (Area: Docks - Difficulty: 0) CreateObject1
(@OGUID+80, 195313, 628, 4710, 4749, '0', 0, 0, 1235.52783203125, -683.87152099609375, 49.30397415161132812, 3.194002151489257812, 0, 0, -0.99965667724609375, 0.026201646775007247, 7200, 255, 1, 53007), -- Teleporter (Area: Docks - Difficulty: 0) CreateObject1
(@OGUID+92, 195313, 628, 4710, 4749, '0', 0, 0, 1233.2725830078125, -844.52606201171875, 48.882415771484375, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 7200, 255, 1, 53007), -- Teleporter (Area: Docks - Difficulty: 0) CreateObject1
(@OGUID+94, 195314, 628, 4710, 4749, '0', 0, 0, 1235.0867919921875, -857.8975830078125, 48.91625595092773437, 3.071766138076782226, 0, 0, 0.999390602111816406, 0.034906134009361267, 7200, 255, 1, 53007), -- Teleporter (Area: Docks - Difficulty: 0) CreateObject1
(@OGUID+101, 195701, 628, 4710, 4752, '0', 0, 0, 397.1163330078125, -859.37847900390625, 48.89894485473632812, 1.640606880187988281, 0, 0, 0.731352806091308593, 0.6819993257522583, 7200, 255, 1, 53007), -- Teleporter Effects (Alliance) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+102, 195702, 628, 4710, 4752, '0', 0, 0, 1235.0711669921875, -857.95660400390625, 48.91625595092773437, 3.054326534271240234, 0, 0, 0.999048233032226562, 0.043619260191917419, 7200, 255, 1, 53007), -- Teleporter Effects (Horde) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+103, 195701, 628, 4710, 4752, '0', 0, 0, 326.265625, -777.34722900390625, 49.02154541015625, 3.124123096466064453, 0, 0, 0.99996185302734375, 0.008734640665352344, 7200, 255, 1, 53007), -- Teleporter Effects (Alliance) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+104, 195702, 628, 4710, 4752, '0', 0, 0, 1158.640625, -746.1475830078125, 48.62769317626953125, 4.782202720642089843, 0, 0, -0.68199825286865234, 0.731353819370269775, 7200, 255, 1, 53007), -- Teleporter Effects (Horde) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+105, 195702, 628, 4710, 4752, '0', 0, 0, 1235.595458984375, -683.8055419921875, 49.30275344848632812, 3.211419343948364257, 0, 0, -0.9993906021118164, 0.034906134009361267, 7200, 255, 1, 53007), -- Teleporter Effects (Horde) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+106, 195701, 628, 4710, 4752, '0', 0, 0, 324.633697509765625, -749.1475830078125, 49.35897445678710937, 0.017452461645007133, 0, 0, 0.008726119995117187, 0.999961912631988525, 7200, 255, 1, 53007), -- Teleporter Effects (Alliance) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+107, 195702, 628, 4710, 4752, '0', 0, 0, 1236.4583740234375, -669.34375, 48.26840591430664062, 0.087265998125076293, 0, 0, 0.043619155883789062, 0.999048233032226562, 7200, 255, 1, 53007), -- Teleporter Effects (Horde) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+108, 195701, 628, 4710, 4752, '0', 0, 0, 311.911468505859375, -913.98614501953125, 48.81566238403320312, 3.089183330535888671, 0, 0, 0.99965667724609375, 0.026201646775007247, 7200, 255, 1, 53007), -- Teleporter Effects (Alliance) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+109, 195702, 628, 4710, 4752, '0', 0, 0, 1233.24658203125, -844.57293701171875, 48.88356781005859375, 0.017452461645007133, 0, 0, 0.008726119995117187, 0.999961912631988525, 7200, 255, 1, 53007), -- Teleporter Effects (Horde) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+110, 195701, 628, 4710, 4752, '0', 0, 0, 323.55035400390625, -888.34722900390625, 48.91978836059570312, 0.017452461645007133, 0, 0, 0.008726119995117187, 0.999961912631988525, 7200, 255, 1, 53007), -- Teleporter Effects (Alliance) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+111, 195702, 628, 4710, 4752, '0', 0, 0, 1143.24658203125, -779.623291015625, 48.62913894653320312, 1.623155713081359863, 0, 0, 0.725374221801757812, 0.688354730606079101, 7200, 255, 1, 53007), -- Teleporter Effects (Horde) (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+112, 195701, 628, 4710, 4752, '0', 0, 0, 425.685760498046875, -857.092041015625, 48.50996017456054687, 4.660029888153076171, 0, 0, -0.72537422180175781, 0.688354730606079101, 7200, 255, 1, 53007); -- Teleporter Effects (Alliance) (Area: Horde Keep - Difficulty: 0) CreateObject1

-- Gates
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+115, 195699, 628, 4710, 4752, '0', 0, 0, 351.614593505859375, -762.75, 48.91624832153320312, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 53007), -- Alliance Gate (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+116, 195698, 628, 4710, 4752, '0', 0, 0, 413.479156494140625, -833.94964599609375, 48.5237579345703125, 3.141592741012573242, 0, 0, -1, 0, 7200, 252, 1, 53007), -- Alliance Gate (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+117, 195700, 628, 4710, 4752, '0', 0, 0, 351.024322509765625, -903.326416015625, 48.92471694946289062, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 0, 1, 53007), -- Alliance Gate (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+118, 195703, 628, 4710, 4752, '0', 0, 0, 413.4791259765625, -833.94964599609375, 48.5237579345703125, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 53007), -- Doodad_ND_Human_Gate_ClosedFX_Door01 (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+119, 195223, 628, 4710, 4752, '0', 0, 0, 1283.0460205078125, -765.87847900390625, 50.82971954345703125, 3.150327444076538085, 0, 0, -0.99999046325683593, 0.004367320332676172, 7200, 255, 1, 53007), -- Horde Keep Portcullis (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+120, 195491, 628, 4710, 4752, '0', 0, 0, 1218.7430419921875, -851.154541015625, 48.25328445434570312, 4.712392330169677734, 0, 0, -0.70710563659667968, 0.707107901573181152, 7200, 255, 1, 53007), -- Doodad_ND_WinterOrc_Wall_GateFX_Door01 (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+121, 195437, 628, 4710, 4752, '0', 0, 0, 1156.8858642578125, -843.998291015625, 48.63224029541015625, 0.732933998107910156, 0, 0, 0.358319282531738281, 0.933599114418029785, 7200, 255, 1, 53007), -- Doodad_VR_Portcullis01 (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+122, 195436, 628, 4710, 4752, '0', 0, 0, 399.80194091796875, -885.20751953125, 50.19386672973632812, 2.515995502471923828, 0, 0, 0.951476097106933593, 0.307722687721252441, 7200, 255, 1, 53007), -- Portcullis (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+123, 195491, 628, 4710, 4752, '0', 0, 0, 1150.90283203125, -762.60589599609375, 47.50767898559570312, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 53007), -- Doodad_ND_WinterOrc_Wall_GateFX_Door01 (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+124, 195495, 628, 4710, 4752, '0', 0, 0, 1217.8992919921875, -676.94793701171875, 47.63407516479492187, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 53007), -- Horde Gate (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+125, 195494, 628, 4710, 4752, '0', 0, 0, 1150.90283203125, -762.60589599609375, 47.50767898559570312, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 53007), -- Horde Gate (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+126, 195496, 628, 4710, 4752, '0', 0, 0, 1218.7430419921875, -851.154541015625, 48.25328445434570312, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 53007), -- Horde Gate (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+127, 195703, 628, 4710, 4752, '0', 0, 0, 351.614593505859375, -762.75, 48.91624832153320312, 4.712392330169677734, 0, 0, -0.70710563659667968, 0.707107901573181152, 7200, 255, 1, 53007), -- Doodad_ND_Human_Gate_ClosedFX_Door01 (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+128, 195451, 628, 4710, 4752, '0', 0, 0, 288.15972900390625, -832.59527587890625, 51.41080093383789062, 6.257006168365478515, 0, 0, -0.01308917999267578, 0.999914348125457763, 7200, 255, 1, 53007), -- Portcullis (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+129, 195452, 628, 4710, 4752, '0', 0, 0, 273.03271484375, -832.19915771484375, 51.41080093383789062, 6.257006168365478515, 0, 0, -0.01308917999267578, 0.999914348125457763, 7200, 255, 1, 53007), -- Portcullis (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+130, 195437, 628, 4710, 4752, '0', 0, 0, 1157.047119140625, -682.36041259765625, 48.6322479248046875, 5.454051017761230468, 0, 0, -0.40279388427734375, 0.915290713310241699, 7200, 255, 1, 53007), -- Doodad_VR_Portcullis01 (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+131, 195436, 628, 4710, 4752, '0', 0, 0, 401.0240478515625, -780.7237548828125, 49.94826889038085937, 3.754217147827148437, 0, 0, -0.95345211029052734, 0.301544517278671264, 7200, 255, 1, 53007), -- Portcullis (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+132, 195703, 628, 4710, 4752, '0', 0, 0, 351.024322509765625, -903.326416015625, 48.92471694946289062, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 53007), -- Doodad_ND_Human_Gate_ClosedFX_Door01 (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+133, 195491, 628, 4710, 4752, '0', 0, 0, 1217.8992919921875, -676.94793701171875, 47.63407516479492187, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 53007); -- Doodad_ND_WinterOrc_Wall_GateFX_Door01 (Area: Horde Keep - Difficulty: 0) CreateObject1

-- Bombs
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+13, 195332, 628, 4710, 4750, '0', 0, 0, 298.104156494140625, -861.02606201171875, 48.9162750244140625, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 10, 255, 1, 53007), -- Huge Seaforium Bombs (Area: Hangar - Difficulty: 0) CreateObject1
(@OGUID+14, 195332, 628, 4710, 4750, '0', 0, 0, 297.321197509765625, -851.3211669921875, 48.91627120971679687, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 10, 255, 1, 53007), -- Huge Seaforium Bombs (Area: Hangar - Difficulty: 0) CreateObject1
(@OGUID+18, 195332, 628, 4710, 4750, '0', 0, 0, 302.135406494140625, -810.70831298828125, 48.91624832153320312, 5.235987663269042968, 0, 0, -0.5, 0.866025388240814208, 10, 255, 1, 53007), -- Huge Seaforium Bombs (Area: Hangar - Difficulty: 0) CreateObject1
(@OGUID+19, 195332, 628, 4710, 4750, '0', 0, 0, 300.37152099609375, -818.732666015625, 48.91624832153320312, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 10, 255, 1, 53007), -- Huge Seaforium Bombs (Area: Hangar - Difficulty: 0) CreateObject1
(@OGUID+89, 195333, 628, 4710, 4749, '0', 0, 0, 1268.5086669921875, -738.12152099609375, 48.91749954223632812, 5.235987663269042968, 0, 0, -0.5, 0.866025388240814208, 10, 255, 1, 53007), -- Huge Seaforium Bombs (Area: Docks - Difficulty: 0) CreateObject1
(@OGUID+90, 195333, 628, 4710, 4749, '0', 0, 0, 1268.30908203125, -745.78302001953125, 48.9187774658203125, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 10, 255, 1, 53007), -- Huge Seaforium Bombs (Area: Docks - Difficulty: 0) CreateObject1
(@OGUID+91, 195333, 628, 4710, 4749, '0', 0, 0, 1273.0660400390625, -786.57293701171875, 48.94191741943359375, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 10, 255, 1, 53007), -- Huge Seaforium Bombs (Area: Docks - Difficulty: 0) CreateObject1
(@OGUID+93, 195333, 628, 4710, 4749, '0', 0, 0, 1273.8489990234375, -796.27777099609375, 48.93642807006835937, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 10, 255, 1, 53007); -- Huge Seaforium Bombs (Area: Docks - Difficulty: 0) CreateObject1

-- Hangar
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+7, 195131, 628, 4710, 0, '0', 0, 0, 807.779541015625, -1000.06768798828125, 132.38140869140625, 4.363324165344238281, 0, 0, -0.81915187835693359, 0.573576688766479492, 7200, 255, 1, 53007), -- Flagpole (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+8, 195158, 628, 4710, 0, '0', 0, 0, 807.780029296875, -1000.07000732421875, 132.3809967041015625, 4.345870018005371093, 0, 0, -0.82412624359130859, 0.566406130790710449, 7200, 255, 1, 53007), -- Hangar Banner (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+25, 195156, 628, 4710, 4750, '0', 0, 0, 807.780029296875, -1000.07000732421875, 132.3809967041015625, 4.345870018005371093, 0, 0, -0.82412624359130859, 0.566406130790710449, 7200, 255, 1, 53007), -- Horde Banner (Area: Hangar - Difficulty: 0) CreateObject2
(@OGUID+30, 195155, 628, 4710, 0, '0', 0, 0, 807.780029296875, -1000.07000732421875, 132.3809967041015625, 4.363324165344238281, 0, 0, -0.81915187835693359, 0.573576688766479492, 7200, 255, 1, 53007), -- Horde Banner (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+31, 195326, 628, 4710, 0, '0', 0, 0, 739.0225830078125, -1106.6614990234375, 134.7550811767578125, 2.426007747650146484, 0, 0, 0.936672210693359375, 0.350207358598709106, 7200, 255, 1, 53007), -- Horde Gunship Portal (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+32, 195706, 628, 4710, 0, '0', 0, 0, 672.0867919921875, -1156.7864990234375, 133.7056732177734375, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 0, 53007), -- Horde Gunship Portal Effects (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+33, 195326, 628, 4710, 0, '0', 0, 0, 672.07989501953125, -1156.7760009765625, 133.7056732177734375, 1.832594871520996093, 0, 0, 0.793353080749511718, 0.608761727809906005, 7200, 255, 1, 53007), -- Horde Gunship Portal (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+34, 195706, 628, 4710, 0, '0', 0, 0, 739.013916015625, -1106.6614990234375, 134.7548370361328125, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 0, 53007), -- Horde Gunship Portal Effects (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+35, 195706, 628, 4710, 0, '0', 0, 0, 827.92364501953125, -993.29864501953125, 134.2002105712890625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 0, 53007), -- Horde Gunship Portal Effects (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+36, 195326, 628, 4710, 0, '0', 0, 0, 827.921875, -993.32464599609375, 134.1971893310546875, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 53007), -- Horde Gunship Portal (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+134, 195153, 628, 0, 0, '0', 0, 0, 807.780029296875, -1000.07000732421875, 132.3809967041015625, 4.363324165344238281, 0, 0, -0.81915187835693359, 0.573576688766479492, 7200, 255, 1, 0), -- Alliance Banner
(@OGUID+135, 195154, 628, 0, 0, '0', 0, 0, 807.780029296875, -1000.07000732421875, 132.3809967041015625, 4.345870018005371093, 0, 0, -0.82412624359130859, 0.566406130790710449, 7200, 255, 1, 0), -- Alliance Banner
(@OGUID+152, 195705, 628, 4710, 4752, '0', 0, 0, 827.9617919921875, -994.4757080078125, 134.0702667236328125, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 0, 53162), -- Alliance Gunship Portal Effects (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+153, 195320, 628, 4710, 4752, '0', 0, 0, 738.61285400390625, -1106.5833740234375, 134.7453155517578125, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 7200, 255, 1, 53162), -- Alliance Gunship Portal (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+154, 195705, 628, 4710, 4752, '0', 0, 0, 672.263916015625, -1157.0347900390625, 133.7056732177734375, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 0, 53162), -- Alliance Gunship Portal Effects (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+155, 195705, 628, 4710, 4752, '0', 0, 0, 738.795166015625, -1106.74658203125, 134.7429656982421875, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 0, 53162), -- Alliance Gunship Portal Effects (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+156, 195320, 628, 4710, 4752, '0', 0, 0, 827.95831298828125, -994.467041015625, 134.0712432861328125, 0, 0, 0, 0, 1, 7200, 255, 1, 53162), -- Alliance Gunship Portal (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+157, 195320, 628, 4710, 4752, '0', 0, 0, 672.28302001953125, -1156.9947509765625, 133.7056732177734375, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 7200, 255, 1, 53162); -- Alliance Gunship Portal (Area: Horde Keep - Difficulty: 0) CreateObject1

-- Workshop
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `stringId`, `VerifiedBuild`) VALUES
(@OGUID+5, 195131, 628, 4710, 0, '0', 0, 0, 776.22900390625, -804.28302001953125, 6.450520038604736328, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 7200, 255, 1, NULL, 53007), -- Flagpole (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+6, 195133, 628, 4710, 0, '0', 0, 0, 776.22900390625, -804.28302001953125, 6.450520038604736328, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 7200, 255, 1, NULL, 53007), -- Workshop Banner (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+9, 195145, 628, 4710, 0, '0', 0, 0, 776.22900390625, -804.28302001953125, 6.450520038604736328, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 7200, 255, 1, NULL, 53007), -- Horde Banner (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+26, 195130, 628, 4710, 4750, '0', 0, 0, 776.22900390625, -804.28302001953125, 6.450520038604736328, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 7200, 255, 1, NULL, 53007), -- Horde Banner (Area: Hangar - Difficulty: 0) CreateObject2
(@OGUID+27, 195237, 628, 4710, 4750, '0', 0, 0, 750.6007080078125, -864.59722900390625, 13.47540664672851562, 1.937312245368957519, 0, 0, 0.824125289916992187, 0.566407561302185058, 10, 255, 1, 'bg_ioc_faction_1735', 53007), -- Seaforium Bombs (Area: Hangar - Difficulty: 0) CreateObject2
(@OGUID+28, 195237, 628, 4710, 4750, '0', 0, 0, 785.5086669921875, -864.71527099609375, 13.39930534362792968, 2.478367090225219726, 0, 0, 0.94551849365234375, 0.325568377971649169, 10, 255, 1, 'bg_ioc_faction_1735', 53007), -- Seaforium Bombs (Area: Hangar - Difficulty: 0) CreateObject2
(@OGUID+136, 195132, 628, 4710, 4750, '0', 0, 0, 776.22900390625, -804.28302001953125, 6.450520038604736328, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 7200, 255, 1, NULL, 0), -- Alliance Banner
(@OGUID+137, 195144, 628, 4710, 0, '0', 0, 0, 776.22900390625, -804.28302001953125, 6.450520038604736328, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 7200, 255, 1, NULL, 0), -- Alliance Banner
(@OGUID+150, 195237, 628, 4710, 4750, '0', 0, 0, 750.6007080078125, -864.59722900390625, 13.47540664672851562, 1.937312245368957519, 0, 0, 0.824125289916992187, 0.566407561302185058, 10, 255, 1, 'bg_ioc_faction_1732', 53007), -- Seaforium Bombs (Area: Hangar - Difficulty: 0) CreateObject2
(@OGUID+151, 195237, 628, 4710, 4750, '0', 0, 0, 785.5086669921875, -864.71527099609375, 13.39930534362792968, 2.478367090225219726, 0, 0, 0.94551849365234375, 0.325568377971649169, 10, 255, 1, 'bg_ioc_faction_1732', 53007); -- Seaforium Bombs (Area: Hangar - Difficulty: 0) CreateObject2

-- Quarry
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+15, 195131, 628, 4710, 4750, '0', 0, 0, 251.015625, -1159.3160400390625, 17.23760032653808593, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 7200, 255, 1, 53007), -- Flagpole (Area: Hangar - Difficulty: 0) CreateObject1
(@OGUID+16, 195338, 628, 4710, 4750, '0', 0, 0, 251.015625, -1159.3160400390625, 17.23760032653808593, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 7200, 255, 1, 53007), -- Quarry Banner (Area: Hangar - Difficulty: 0) CreateObject1
(@OGUID+24, 195335, 628, 4710, 4750, '0', 0, 0, 251.015625, -1159.3160400390625, 17.23760032653808593, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 7200, 255, 1, 53007), -- Alliance Banner (Area: Hangar - Difficulty: 0) CreateObject1
(@OGUID+29, 195334, 628, 4710, 4750, '0', 0, 0, 251.015625, -1159.3160400390625, 17.23760032653808593, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 7200, 255, 0, 53007), -- Alliance Banner (Area: Hangar - Difficulty: 0) CreateObject2
(@OGUID+43, 195337, 628, 4710, 4748, '0', 0, 0, 251.015625, -1159.3160400390625, 17.23760032653808593, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 7200, 255, 1, 53007), -- Horde Banner (Area: Quarry - Difficulty: 0) CreateObject2
(@OGUID+44, 195336, 628, 4710, 4748, '0', 0, 0, 251.015625, -1159.3160400390625, 17.23760032653808593, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 7200, 255, 1, 53007); -- Horde Banner (Area: Quarry - Difficulty: 0) CreateObject2

-- Docks
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+45, 195151, 628, 4710, 0, '0', 0, 0, 726.385009765625, -360.204986572265625, 17.81529998779296875, 4.677483558654785156, 0, 0, -0.71933937072753906, 0.694658815860748291, 7200, 255, 1, 53007), -- Horde Banner (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+46, 195131, 628, 4710, 0, '0', 0, 0, 726.385009765625, -360.204986572265625, 17.81529998779296875, 4.677483558654785156, 0, 0, -0.71933937072753906, 0.694658815860748291, 7200, 255, 1, 53007), -- Flagpole (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+138, 195152, 628, 4710, 0, '0', 0, 0, 726.385009765625, -360.204986572265625, 17.81529998779296875, 4.677483558654785156, 0, 0, -0.71933937072753906, 0.694658815860748291, 7200, 255, 1, 0), -- Horde Banner (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+139, 195149, 628, 4710, 0, '0', 0, 0, 726.385009765625, -360.204986572265625, 17.81529998779296875, 4.677483558654785156, 0, 0, -0.71933937072753906, 0.694658815860748291, 7200, 255, 1, 0), -- Alliance Banner (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+140, 195150, 628, 4710, 0, '0', 0, 0, 726.385009765625, -360.204986572265625, 17.81529998779296875, 4.677483558654785156, 0, 0, -0.71933937072753906, 0.694658815860748291, 7200, 255, 1, 0), -- Alliance Banner (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+141, 195157, 628, 4710, 0, '0', 0, 0, 726.385009765625, -360.204986572265625, 17.81529998779296875, 4.677483558654785156, 0, 0, -0.71933937072753906, 0.694658815860748291, 7200, 255, 1, 0); -- Dock Banner

-- Refinery
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+1, 195131, 628, 4710, 4752, '0', 0, 0, 1269.501708984375, -400.80902099609375, 37.62525177001953125, 4.520402908325195312, 0, 0, -0.77162456512451171, 0.636078238487243652, 7200, 255, 1, 53007), -- Flagpole (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+78, 195341, 628, 4710, 4749, '0', 0, 0, 1269.501708984375, -400.80902099609375, 37.62525177001953125, 4.520402908325195312, 0, 0, -0.77162456512451171, 0.636078238487243652, 7200, 255, 1, 53007), -- Horde Banner (Area: Docks - Difficulty: 0) CreateObject1
(@OGUID+100, 195343, 628, 4710, 4752, '0', 0, 0, 1269.501708984375, -400.80902099609375, 37.62525177001953125, 4.520402908325195312, 0, 0, -0.77162456512451171, 0.636078238487243652, 7200, 255, 1, 53007), -- Refinery Banner (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+142, 195342, 628, 4710, 4749, '0', 0, 0, 1269.501708984375, -400.80902099609375, 37.62525177001953125, 4.520402908325195312, 0, 0, -0.77162456512451171, 0.636078238487243652, 7200, 255, 1, 0), -- Horde Banner
(@OGUID+143, 195339, 628, 4710, 4749, '0', 0, 0, 1269.501708984375, -400.80902099609375, 37.62525177001953125, 4.520402908325195312, 0, 0, -0.77162456512451171, 0.636078238487243652, 7200, 255, 1, 0), -- Alliance Banner
(@OGUID+144, 195340, 628, 4710, 4749, '0', 0, 0, 1269.501708984375, -400.80902099609375, 37.62525177001953125, 4.520402908325195312, 0, 0, -0.77162456512451171, 0.636078238487243652, 7200, 255, 1, 0); -- Alliance Banner

-- Horde Keep
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+2, 195393, 628, 4710, 4752, '0', 0, 0, 1284.7552490234375, -705.66839599609375, 48.91626358032226562, 3.194002151489257812, 0, 0, -0.99965667724609375, 0.026201646775007247, 7200, 255, 1, 53007), -- Horde Banner (Area: Horde Keep - Difficulty: 0) CreateObject1
(@OGUID+23, 195439, 628, 4710, 4750, '0', 0, 0, 1284.7552490234375, -705.66839599609375, 48.91626358032226562, 3.194002151489257812, 0, 0, -0.99965667724609375, 0.026201646775007247, 7200, 255, 1, 53007), -- Flagpole (Area: Hangar - Difficulty: 0) CreateObject1
(@OGUID+145, 195394, 628, 4710, 4752, '0', 0, 0, 1284.7552490234375, -705.66839599609375, 48.91626358032226562, 3.194002151489257812, 0, 0, -0.99965667724609375, 0.026201646775007247, 7200, 255, 1, 0), -- Horde Banner
(@OGUID+146, 195392, 628, 4710, 4752, '0', 0, 0, 1284.7552490234375, -705.66839599609375, 48.91626358032226562, 3.194002151489257812, 0, 0, -0.99965667724609375, 0.026201646775007247, 7200, 255, 1, 0), -- Alliance Banner
(@OGUID+147, 195391, 628, 4710, 4752, '0', 0, 0, 1284.7552490234375, -705.66839599609375, 48.91626358032226562, 3.194002151489257812, 0, 0, -0.99965667724609375, 0.026201646775007247, 7200, 255, 1, 0); -- Alliance Banner

-- Alliance Keep
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+21, 195439, 628, 4710, 4750, '0', 0, 0, 299.15277099609375, -784.58856201171875, 48.91624832153320312, 6.12610626220703125, 0, 0, -0.07845878601074218, 0.996917366981506347, 7200, 255, 1, 53007), -- Flagpole (Area: Hangar - Difficulty: 0) CreateObject1
(@OGUID+22, 195396, 628, 4710, 4750, '0', 0, 0, 299.15277099609375, -784.58856201171875, 48.91624832153320312, 6.12610626220703125, 0, 0, -0.07845878601074218, 0.996917366981506347, 7200, 255, 1, 53007), -- Alliance Banner (Area: Hangar - Difficulty: 0) CreateObject1
(@OGUID+99, 195399, 628, 4710, 4753, '0', 0, 0, 299.15277099609375, -784.58856201171875, 48.91624832153320312, 6.12610626220703125, 0, 0, -0.07845878601074218, 0.996917366981506347, 7200, 255, 1, 53007), -- Horde Banner (Area: Alliance Keep - Difficulty: 0) CreateObject2
(@OGUID+148, 195397, 628, 4710, 4753, '0', 0, 0, 299.15277099609375, -784.58856201171875, 48.91624832153320312, 6.12610626220703125, 0, 0, -0.07845878601074218, 0.996917366981506347, 7200, 255, 1, 0), -- Alliance Banner
(@OGUID+149, 195398, 628, 4710, 4753, '0', 0, 0, 299.15277099609375, -784.58856201171875, 48.91624832153320312, 6.12610626220703125, 0, 0, -0.07845878601074218, 0.996917366981506347, 7200, 255, 1, 0); -- Horde Banner

-- Statues Collision in alliance keep
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+38, 375005, 628, 4710, 0, '0', 0, 0, 217.08160400390625, -842.29339599609375, 61.00786209106445312, 0.98643660545349121, 0, 0, 0.473463058471679687, 0.880813658237457275, 7200, 255, 1, 53007), -- Collision PC Size (Blocks LoS) (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+39, 375005, 628, 4710, 0, '0', 0, 0, 215.703125, -841.4617919921875, 61.00786209106445312, 0.98643660545349121, 0, 0, 0.473463058471679687, 0.880813658237457275, 7200, 255, 1, 53007), -- Collision PC Size (Blocks LoS) (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+41, 375005, 628, 4710, 4748, '0', 0, 0, 218.1215362548828125, -819.22222900390625, 61.00786209106445312, 0.4928361177444458, 0, 0, 0.243931770324707031, 0.969792366027832031, 7200, 255, 1, 53007), -- Collision PC Size (Blocks LoS) (Area: Quarry - Difficulty: 0) CreateObject1
(@OGUID+42, 375005, 628, 4710, 4748, '0', 0, 0, 216.5677032470703125, -820.17364501953125, 61.00786209106445312, 0.4928361177444458, 0, 0, 0.243931770324707031, 0.969792366027832031, 7200, 255, 1, 53007); -- Collision PC Size (Blocks LoS) (Area: Quarry - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+10000;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+37, 0, 0, -0.01308943517506122, 0.999914348125457763, 0, 0), -- Brazier
(@OGUID+40, 0, 0, -0.01308943517506122, 0.999914348125457763, 0, 0), -- Brazier
(@OGUID+47, 0, 0, 0.982450366020202636, 0.186524167656898498, 0, 0), -- Stove
(@OGUID+48, 0, 0, 0.982450366020202636, 0.186524167656898498, 0, 0), -- Chair
(@OGUID+49, 0, 0, 0.982450366020202636, 0.186524167656898498, 0, 0), -- Chair
(@OGUID+50, 0, 0, 0.982450366020202636, 0.186524167656898498, 0, 0), -- Chair
(@OGUID+51, 0, 0, 0.366501331329345703, 0.930417537689208984, 0, 0), -- Chair
(@OGUID+52, 0, 0, 0.366501331329345703, 0.930417537689208984, 0, 0), -- Chair
(@OGUID+53, 0, 0, 0.366501331329345703, 0.930417537689208984, 0, 0), -- Chair
(@OGUID+54, 0, 0, 0.366501331329345703, 0.930417537689208984, 0, 0), -- Chair
(@OGUID+55, 0, 0, 0.366501331329345703, 0.930417537689208984, 0, 0), -- Chair
(@OGUID+56, 0, 0, 0.366501331329345703, 0.930417537689208984, 0, 0), -- Chair
(@OGUID+57, 0, 0, 0.982450366020202636, 0.186524167656898498, 0, 0), -- Chair
(@OGUID+58, 0, 0, 0.366501331329345703, 0.930417537689208984, 0, 0), -- Chair
(@OGUID+59, 0, 0, 0.366501331329345703, 0.930417537689208984, 0, 0), -- Chair
(@OGUID+60, 0, 0, 0.366501331329345703, 0.930417537689208984, 0, 0), -- Chair
(@OGUID+61, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Bench
(@OGUID+62, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Bench
(@OGUID+63, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Bench
(@OGUID+64, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Bench
(@OGUID+65, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Bench
(@OGUID+66, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Bench
(@OGUID+67, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Bench
(@OGUID+68, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Chair
(@OGUID+69, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Chair
(@OGUID+70, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Stove
(@OGUID+71, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Bench
(@OGUID+72, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Bench
(@OGUID+73, 0, 0, -0.69151294231414794, 0.722364068031311035, 0, 0), -- Stove
(@OGUID+74, 0, 0, -0.69151294231414794, 0.722364068031311035, 0, 0), -- Chair
(@OGUID+75, 0, 0, -0.69151294231414794, 0.722364068031311035, 0, 0), -- Chair
(@OGUID+81, 0, 0, -0.03489945083856582, 0.999390840530395507, 0, 0), -- Chair
(@OGUID+82, 0, 0, -0.03489945083856582, 0.999390840530395507, 0, 0), -- Chair
(@OGUID+83, 0, 0, -0.03489945083856582, 0.999390840530395507, 0, 0), -- Stove
(@OGUID+84, 0, 0, -0.27982896566390991, 0.960049867630004882, 0, 0), -- Chair
(@OGUID+85, 0, 0, -0.27982896566390991, 0.960049867630004882, 0, 0), -- Stove
(@OGUID+86, 0, 0, -0.27982896566390991, 0.960049867630004882, 0, 0), -- Chair
(@OGUID+87, 0, 0, -0.27982896566390991, 0.960049867630004882, 0, 0), -- Chair
(@OGUID+88, 0, 0, -0.27982896566390991, 0.960049867630004882, 0, 0), -- Chair
(@OGUID+97, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Bonfire
(@OGUID+98, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Bonfire
(@OGUID+115, 0, 0, 0, 1, 0, 0), -- Alliance Gate
(@OGUID+116, 0, 0, 0, 1, 0, 0), -- Alliance Gate
(@OGUID+117, 0, 0, 0, 1, 0, 0), -- Alliance Gate
(@OGUID+118, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_ND_Human_Gate_ClosedFX_Door01
(@OGUID+119, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Horde Keep Portcullis
(@OGUID+120, 0, 0, -0.70710641145706176, 0.707107126712799072, 0, 0), -- Doodad_ND_WinterOrc_Wall_GateFX_Door01
(@OGUID+113, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Bonfire
(@OGUID+114, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Bonfire
(@OGUID+121, 0, 0, 0.358319789171218872, 0.933598935604095458, 0, 0), -- Doodad_VR_Portcullis01
(@OGUID+122, 0, 0, 0.951476275920867919, 0.307722091674804687, 0, 0), -- Portcullis
(@OGUID+123, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_ND_WinterOrc_Wall_GateFX_Door01
(@OGUID+124, 0, 0, 0, 1, 0, 0), -- Horde Gate
(@OGUID+125, 0, 0, 0, 1, 0, 0), -- Horde Gate
(@OGUID+126, 0, 0, 0, 1, 0, 0), -- Horde Gate
(@OGUID+127, 0, 0, -0.70710641145706176, 0.707107126712799072, 0, 0), -- Doodad_ND_Human_Gate_ClosedFX_Door01
(@OGUID+128, 0, 0, -0.01308943517506122, 0.999914348125457763, 0, 0), -- Portcullis
(@OGUID+129, 0, 0, -0.01308943517506122, 0.999914348125457763, 0, 0), -- Portcullis
(@OGUID+130, 0, 0, -0.4027940034866333, 0.915290653705596923, 0, 0), -- Doodad_VR_Portcullis01
(@OGUID+131, 0, 0, 0.953452110290527343, -0.30154460668563842, 0, 0), -- Portcullis
(@OGUID+132, 0, 0, 0.707106590270996093, 0.707106947898864746, 0, 0), -- Doodad_ND_Human_Gate_ClosedFX_Door01
(@OGUID+133, 0, 0, 0.707106590270996093, 0.707106947898864746, 0, 0); -- Doodad_ND_WinterOrc_Wall_GateFX_Door01

UPDATE `gameobject_template_addon` SET `flags` = `flags` & ~0x1 WHERE `entry` IN (195133, 195151, 195153, 195155, 195157, 195158, 195339, 195341, 195396);
UPDATE `gameobject_template_addon` SET `flags` = `flags` | 0x10 WHERE `entry` IN (195396, 195393);

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_ioc_damaged';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(67323, 'spell_ioc_damaged');

DELETE FROM `areatrigger_scripts` WHERE `entry` IN (9176, 9178, 5535, 5536);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(9176, 'at_ioc_exploit'),
(9178, 'at_ioc_exploit'),
(5535, 'at_ioc_backdoor_job'),
(5536, 'at_ioc_backdoor_job');
