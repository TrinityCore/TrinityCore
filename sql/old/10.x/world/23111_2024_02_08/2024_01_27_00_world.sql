SET @OGUID := 166633;
SET @SPAWNGROUP := 1174;
SET @CGUID := 223867;

-- Areatrigger Scripts for buffs
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (5356, 5355, 5354);
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(5356, 'at_battleground_buffs'),
(5355, 'at_battleground_buffs'),
(5354, 'at_battleground_buffs');

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_place_seaforium_charge';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(52410, 'spell_place_seaforium_charge');

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWNGROUP+0 AND @SPAWNGROUP+40;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWNGROUP+0, 'Strand of the Ancients - Green Emerald Gate - Sigil', 0x20),
(@SPAWNGROUP+1, 'Strand of the Ancients - Blue Sapphire Gate - Sigil', 0x20),
(@SPAWNGROUP+2, 'Strand of the Ancients - Red Sun Gate - Sigil', 0x20),
(@SPAWNGROUP+3, 'Strand of the Ancients - Purple Amethyst - Sigil', 0x20),
(@SPAWNGROUP+4, 'Strand of the Ancients - Yellow Moon - Sigil', 0x20),
(@SPAWNGROUP+5, 'Strand of the Ancients - First Line - Horde Bombs', 0x20),
(@SPAWNGROUP+6, 'Strand of the Ancients - First Line - Alliance Bombs', 0x20),
(@SPAWNGROUP+7, 'Strand of the Ancients - Second Line - Horde Bombs', 0x20),
(@SPAWNGROUP+8, 'Strand of the Ancients - Second Line - Alliance Bombs', 0x20),
(@SPAWNGROUP+9, 'Strand of the Ancients - Third Line - Horde Bombs', 0x20),
(@SPAWNGROUP+10, 'Strand of the Ancients - Third Line - Alliance Bombs', 0x20),
(@SPAWNGROUP+11, 'Strand of the Ancients - Horde Attacking', 0x20), -- Bombs, graveyards, cannons
(@SPAWNGROUP+12, 'Strand of the Ancients - Alliance Attacking', 0x20), -- Bombs, graveyards, cannons
(@SPAWNGROUP+13, 'Strand of the Ancients - Beach - Horde Demolishers', 0x20),
(@SPAWNGROUP+14, 'Strand of the Ancients - Beach - Alliance Demolishers', 0x20),
(@SPAWNGROUP+15, 'Strand of the Ancients - West Graveyard - Horde Graveyard', 0x20),
(@SPAWNGROUP+16, 'Strand of the Ancients - West Graveyard - Alliance Graveyard', 0x20),
(@SPAWNGROUP+17, 'Strand of the Ancients - West Graveyard - Horde Demolisher', 0x20),
(@SPAWNGROUP+18, 'Strand of the Ancients - West Graveyard - Alliance Demolisher', 0x20),
(@SPAWNGROUP+19, 'Strand of the Ancients - East Graveyard - Horde Graveyard', 0x20),
(@SPAWNGROUP+20, 'Strand of the Ancients - East Graveyard - Alliance Graveyard', 0x20),
(@SPAWNGROUP+21, 'Strand of the Ancients - East Graveyard - Horde Demolisher', 0x20),
(@SPAWNGROUP+22, 'Strand of the Ancients - East Graveyard - Alliance Demolisher', 0x20),
(@SPAWNGROUP+23, 'Strand of the Ancients - Mid Graveyard - Horde Graveyard', 0x20),
(@SPAWNGROUP+24, 'Strand of the Ancients - Mid Graveyard - Alliance Graveyard', 0x20),
(@SPAWNGROUP+25, 'Strand of the Ancients - Cannons - Horde Attacking', 0x20),
(@SPAWNGROUP+26, 'Strand of the Ancients - Cannons - Alliance Attacking', 0x20);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN @SPAWNGROUP+0 AND @SPAWNGROUP+50;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
-- sigils
(@SPAWNGROUP+0, 1, @OGUID+48),
(@SPAWNGROUP+1, 1, @OGUID+28),
(@SPAWNGROUP+2, 1, @OGUID+51),
(@SPAWNGROUP+3, 1, @OGUID+58),
(@SPAWNGROUP+4, 1, @OGUID+60),
-- bombs, first line, horde
(@SPAWNGROUP+5, 1, @OGUID+67),
(@SPAWNGROUP+5, 1, @OGUID+75),
(@SPAWNGROUP+5, 1, @OGUID+79),
(@SPAWNGROUP+5, 1, @OGUID+66),
(@SPAWNGROUP+5, 1, @OGUID+70),
(@SPAWNGROUP+5, 1, @OGUID+93),
(@SPAWNGROUP+5, 1, @OGUID+72),
(@SPAWNGROUP+5, 1, @OGUID+73),
(@SPAWNGROUP+5, 1, @OGUID+74),
(@SPAWNGROUP+5, 1, @OGUID+90),
(@SPAWNGROUP+5, 1, @OGUID+89),
(@SPAWNGROUP+5, 1, @OGUID+33),
(@SPAWNGROUP+5, 1, @OGUID+92),
(@SPAWNGROUP+5, 1, @OGUID+87),
(@SPAWNGROUP+5, 1, @OGUID+91),
(@SPAWNGROUP+5, 1, @OGUID+77),
(@SPAWNGROUP+5, 1, @OGUID+78),
(@SPAWNGROUP+5, 1, @OGUID+65),
(@SPAWNGROUP+5, 1, @OGUID+84),
(@SPAWNGROUP+5, 1, @OGUID+86),
(@SPAWNGROUP+5, 1, @OGUID+76),
(@SPAWNGROUP+5, 1, @OGUID+83),
(@SPAWNGROUP+5, 1, @OGUID+80),
(@SPAWNGROUP+5, 1, @OGUID+69),
(@SPAWNGROUP+5, 1, @OGUID+68),
(@SPAWNGROUP+5, 1, @OGUID+82),
(@SPAWNGROUP+5, 1, @OGUID+85),
(@SPAWNGROUP+5, 1, @OGUID+81),
(@SPAWNGROUP+5, 1, @OGUID+88),
(@SPAWNGROUP+5, 1, @OGUID+71),
-- bombs, first line, alliance
(@SPAWNGROUP+6, 1, @OGUID+203),
(@SPAWNGROUP+6, 1, @OGUID+206),
(@SPAWNGROUP+6, 1, @OGUID+202),
(@SPAWNGROUP+6, 1, @OGUID+204),
(@SPAWNGROUP+6, 1, @OGUID+197),
(@SPAWNGROUP+6, 1, @OGUID+194),
(@SPAWNGROUP+6, 1, @OGUID+192),
(@SPAWNGROUP+6, 1, @OGUID+196),
(@SPAWNGROUP+6, 1, @OGUID+198),
(@SPAWNGROUP+6, 1, @OGUID+201),
(@SPAWNGROUP+6, 1, @OGUID+200),
(@SPAWNGROUP+6, 1, @OGUID+146),
(@SPAWNGROUP+6, 1, @OGUID+205),
(@SPAWNGROUP+6, 1, @OGUID+199),
(@SPAWNGROUP+6, 1, @OGUID+193),
(@SPAWNGROUP+6, 1, @OGUID+195),
(@SPAWNGROUP+6, 1, @OGUID+188),
(@SPAWNGROUP+6, 1, @OGUID+190),
(@SPAWNGROUP+6, 1, @OGUID+181),
(@SPAWNGROUP+6, 1, @OGUID+180),
(@SPAWNGROUP+6, 1, @OGUID+189),
(@SPAWNGROUP+6, 1, @OGUID+182),
(@SPAWNGROUP+6, 1, @OGUID+184),
(@SPAWNGROUP+6, 1, @OGUID+179),
(@SPAWNGROUP+6, 1, @OGUID+187),
(@SPAWNGROUP+6, 1, @OGUID+191),
(@SPAWNGROUP+6, 1, @OGUID+183),
(@SPAWNGROUP+6, 1, @OGUID+186),
(@SPAWNGROUP+6, 1, @OGUID+185),
(@SPAWNGROUP+6, 1, @OGUID+178),
-- bombs, second line, horde
(@SPAWNGROUP+7, 1, @OGUID+102),
(@SPAWNGROUP+7, 1, @OGUID+98),
(@SPAWNGROUP+7, 1, @OGUID+100),
(@SPAWNGROUP+7, 1, @OGUID+99),
(@SPAWNGROUP+7, 1, @OGUID+97),
(@SPAWNGROUP+7, 1, @OGUID+108),
(@SPAWNGROUP+7, 1, @OGUID+109),
(@SPAWNGROUP+7, 1, @OGUID+104),
(@SPAWNGROUP+7, 1, @OGUID+103),
(@SPAWNGROUP+7, 1, @OGUID+106),
(@SPAWNGROUP+7, 1, @OGUID+96),
(@SPAWNGROUP+7, 1, @OGUID+105),
(@SPAWNGROUP+7, 1, @OGUID+101),
(@SPAWNGROUP+7, 1, @OGUID+107),
-- bombs, second line, alliance
(@SPAWNGROUP+8, 1, @OGUID+207),
(@SPAWNGROUP+8, 1, @OGUID+208),
(@SPAWNGROUP+8, 1, @OGUID+209),
(@SPAWNGROUP+8, 1, @OGUID+210),
(@SPAWNGROUP+8, 1, @OGUID+211),
(@SPAWNGROUP+8, 1, @OGUID+212),
(@SPAWNGROUP+8, 1, @OGUID+213),
(@SPAWNGROUP+8, 1, @OGUID+214),
(@SPAWNGROUP+8, 1, @OGUID+215),
(@SPAWNGROUP+8, 1, @OGUID+216),
(@SPAWNGROUP+8, 1, @OGUID+217),
(@SPAWNGROUP+8, 1, @OGUID+218),
(@SPAWNGROUP+8, 1, @OGUID+219),
(@SPAWNGROUP+8, 1, @OGUID+220),
-- bombs, third line, horde
(@SPAWNGROUP+9, 1, @OGUID+111),
(@SPAWNGROUP+9, 1, @OGUID+112),
(@SPAWNGROUP+9, 1, @OGUID+113),
(@SPAWNGROUP+9, 1, @OGUID+114),
(@SPAWNGROUP+9, 1, @OGUID+115),
(@SPAWNGROUP+9, 1, @OGUID+116),
(@SPAWNGROUP+9, 1, @OGUID+117),
(@SPAWNGROUP+9, 1, @OGUID+118),
(@SPAWNGROUP+9, 1, @OGUID+119),
(@SPAWNGROUP+9, 1, @OGUID+120),
(@SPAWNGROUP+9, 1, @OGUID+121),
(@SPAWNGROUP+9, 1, @OGUID+122),
(@SPAWNGROUP+9, 1, @OGUID+123),
(@SPAWNGROUP+9, 1, @OGUID+124),
(@SPAWNGROUP+9, 1, @OGUID+125),
(@SPAWNGROUP+9, 1, @OGUID+126),
(@SPAWNGROUP+9, 1, @OGUID+127),
(@SPAWNGROUP+9, 1, @OGUID+128),
(@SPAWNGROUP+9, 1, @OGUID+129),
(@SPAWNGROUP+9, 1, @OGUID+130),
(@SPAWNGROUP+9, 1, @OGUID+131),
(@SPAWNGROUP+9, 1, @OGUID+132),
(@SPAWNGROUP+9, 1, @OGUID+133),
-- bombs, third line, alliance
(@SPAWNGROUP+10, 1, @OGUID+221),
(@SPAWNGROUP+10, 1, @OGUID+222),
(@SPAWNGROUP+10, 1, @OGUID+223),
(@SPAWNGROUP+10, 1, @OGUID+224),
(@SPAWNGROUP+10, 1, @OGUID+225),
(@SPAWNGROUP+10, 1, @OGUID+226),
(@SPAWNGROUP+10, 1, @OGUID+227),
(@SPAWNGROUP+10, 1, @OGUID+228),
(@SPAWNGROUP+10, 1, @OGUID+229),
(@SPAWNGROUP+10, 1, @OGUID+230),
(@SPAWNGROUP+10, 1, @OGUID+231),
(@SPAWNGROUP+10, 1, @OGUID+232),
(@SPAWNGROUP+10, 1, @OGUID+233),
(@SPAWNGROUP+10, 1, @OGUID+234),
(@SPAWNGROUP+10, 1, @OGUID+235),
(@SPAWNGROUP+10, 1, @OGUID+236),
(@SPAWNGROUP+10, 1, @OGUID+237),
(@SPAWNGROUP+10, 1, @OGUID+238),
(@SPAWNGROUP+10, 1, @OGUID+239),
(@SPAWNGROUP+10, 1, @OGUID+240),
(@SPAWNGROUP+10, 1, @OGUID+241),
(@SPAWNGROUP+10, 1, @OGUID+242),
(@SPAWNGROUP+10, 1, @OGUID+243),
-- bombs/demolishers/spirit guides, horde attacking
(@SPAWNGROUP+11, 1, @OGUID+14),
(@SPAWNGROUP+11, 1, @OGUID+17),
(@SPAWNGROUP+11, 1, @OGUID+12),
(@SPAWNGROUP+11, 1, @OGUID+9),
(@SPAWNGROUP+11, 1, @OGUID+13),
(@SPAWNGROUP+11, 1, @OGUID+10),
(@SPAWNGROUP+11, 1, @OGUID+18),
(@SPAWNGROUP+11, 1, @OGUID+15),
(@SPAWNGROUP+11, 1, @OGUID+11),
(@SPAWNGROUP+11, 1, @OGUID+8),
(@SPAWNGROUP+11, 1, @OGUID+16),
(@SPAWNGROUP+11, 1, @OGUID+35),
(@SPAWNGROUP+11, 1, @OGUID+40),
(@SPAWNGROUP+11, 1, @OGUID+41),
(@SPAWNGROUP+11, 1, @OGUID+43),
(@SPAWNGROUP+11, 1, @OGUID+39),
(@SPAWNGROUP+11, 1, @OGUID+37),
(@SPAWNGROUP+11, 1, @OGUID+44),
(@SPAWNGROUP+11, 1, @OGUID+38),
(@SPAWNGROUP+11, 1, @OGUID+36),
(@SPAWNGROUP+11, 1, @OGUID+42),
(@SPAWNGROUP+11, 1, @OGUID+34),
(@SPAWNGROUP+11, 1, @OGUID+31),
(@SPAWNGROUP+11, 1, @OGUID+21),
(@SPAWNGROUP+11, 1, @OGUID+26),
(@SPAWNGROUP+11, 1, @OGUID+32),
(@SPAWNGROUP+11, 1, @OGUID+30),
(@SPAWNGROUP+11, 1, @OGUID+23),
(@SPAWNGROUP+11, 1, @OGUID+24),
(@SPAWNGROUP+11, 1, @OGUID+29),
(@SPAWNGROUP+11, 1, @OGUID+19),
(@SPAWNGROUP+11, 1, @OGUID+22),
(@SPAWNGROUP+11, 1, @OGUID+20),
(@SPAWNGROUP+11, 1, @OGUID+25),
(@SPAWNGROUP+11, 1, @OGUID+27),
(@SPAWNGROUP+11, 0, @CGUID+19),
(@SPAWNGROUP+11, 0, @CGUID+21),
(@SPAWNGROUP+11, 0, @CGUID+18),
(@SPAWNGROUP+11, 0, @CGUID+0),
(@SPAWNGROUP+11, 0, @CGUID+1),
(@SPAWNGROUP+11, 0, @CGUID+2),
(@SPAWNGROUP+11, 0, @CGUID+3),
(@SPAWNGROUP+11, 0, @CGUID+4),
(@SPAWNGROUP+11, 0, @CGUID+5),
(@SPAWNGROUP+11, 0, @CGUID+6),
(@SPAWNGROUP+11, 0, @CGUID+7),
(@SPAWNGROUP+11, 0, @CGUID+8),
(@SPAWNGROUP+11, 0, @CGUID+9),
(@SPAWNGROUP+11, 1, @OGUID+52),
(@SPAWNGROUP+11, 1, @OGUID+55),
(@SPAWNGROUP+11, 1, @OGUID+56),
(@SPAWNGROUP+11, 1, @OGUID+57),
(@SPAWNGROUP+11, 1, @OGUID+61),
(@SPAWNGROUP+11, 1, @OGUID+63),
(@SPAWNGROUP+11, 1, @OGUID+2),
(@SPAWNGROUP+11, 1, @OGUID+7),
-- bombs/demolishers/spirit guides, alliance attacking
(@SPAWNGROUP+12, 1, @OGUID+147),
(@SPAWNGROUP+12, 1, @OGUID+149),
(@SPAWNGROUP+12, 1, @OGUID+141),
(@SPAWNGROUP+12, 1, @OGUID+169),
(@SPAWNGROUP+12, 1, @OGUID+171),
(@SPAWNGROUP+12, 1, @OGUID+158),
(@SPAWNGROUP+12, 1, @OGUID+151),
(@SPAWNGROUP+12, 1, @OGUID+156),
(@SPAWNGROUP+12, 1, @OGUID+168),
(@SPAWNGROUP+12, 1, @OGUID+140),
(@SPAWNGROUP+12, 1, @OGUID+165),
(@SPAWNGROUP+12, 1, @OGUID+164),
(@SPAWNGROUP+12, 1, @OGUID+153),
(@SPAWNGROUP+12, 1, @OGUID+154),
(@SPAWNGROUP+12, 1, @OGUID+152),
(@SPAWNGROUP+12, 1, @OGUID+139),
(@SPAWNGROUP+12, 1, @OGUID+143),
(@SPAWNGROUP+12, 1, @OGUID+145),
(@SPAWNGROUP+12, 1, @OGUID+142),
(@SPAWNGROUP+12, 1, @OGUID+170),
(@SPAWNGROUP+12, 1, @OGUID+172),
(@SPAWNGROUP+12, 1, @OGUID+157),
(@SPAWNGROUP+12, 1, @OGUID+144),
(@SPAWNGROUP+12, 1, @OGUID+155),
(@SPAWNGROUP+12, 1, @OGUID+163),
(@SPAWNGROUP+12, 1, @OGUID+137),
(@SPAWNGROUP+12, 1, @OGUID+148),
(@SPAWNGROUP+12, 1, @OGUID+162),
(@SPAWNGROUP+12, 1, @OGUID+166),
(@SPAWNGROUP+12, 1, @OGUID+138),
(@SPAWNGROUP+12, 1, @OGUID+159),
(@SPAWNGROUP+12, 1, @OGUID+167),
(@SPAWNGROUP+12, 1, @OGUID+150),
(@SPAWNGROUP+12, 1, @OGUID+160),
(@SPAWNGROUP+12, 1, @OGUID+161),
(@SPAWNGROUP+12, 0, @CGUID+35),
(@SPAWNGROUP+12, 0, @CGUID+36),
(@SPAWNGROUP+12, 0, @CGUID+34),
(@SPAWNGROUP+12, 0, @CGUID+24),
(@SPAWNGROUP+12, 0, @CGUID+25),
(@SPAWNGROUP+12, 0, @CGUID+26),
(@SPAWNGROUP+12, 0, @CGUID+27),
(@SPAWNGROUP+12, 0, @CGUID+28),
(@SPAWNGROUP+12, 0, @CGUID+29),
(@SPAWNGROUP+12, 0, @CGUID+30),
(@SPAWNGROUP+12, 0, @CGUID+31),
(@SPAWNGROUP+12, 0, @CGUID+32),
(@SPAWNGROUP+12, 0, @CGUID+33),
(@SPAWNGROUP+12, 1, @OGUID+173),
(@SPAWNGROUP+12, 1, @OGUID+174),
(@SPAWNGROUP+12, 1, @OGUID+175),
(@SPAWNGROUP+12, 1, @OGUID+176),
(@SPAWNGROUP+12, 1, @OGUID+177),
(@SPAWNGROUP+12, 1, @OGUID+136),
(@SPAWNGROUP+12, 1, @OGUID+134),
(@SPAWNGROUP+12, 1, @OGUID+135),
-- Beach, demolishers, horde
(@SPAWNGROUP+13, 0, @CGUID+11),
(@SPAWNGROUP+13, 0, @CGUID+12),
-- Beach, demolishers, alliance
(@SPAWNGROUP+14, 0, @CGUID+39),
(@SPAWNGROUP+14, 0, @CGUID+40),
-- West graveyard, Horde
(@SPAWNGROUP+15, 1, @OGUID+94),
(@SPAWNGROUP+15, 0, @CGUID+17),
-- West graveyard, Alliance
(@SPAWNGROUP+16, 1, @OGUID+50),
(@SPAWNGROUP+16, 0, @CGUID+38),
-- West graveyard, Horde Demolishers
(@SPAWNGROUP+17, 0, @CGUID+13),
(@SPAWNGROUP+17, 0, @CGUID+14),
-- West graveyard, Alliance Demolishers
(@SPAWNGROUP+18, 0, @CGUID+41),
(@SPAWNGROUP+18, 0, @CGUID+42),
-- East graveyard, Horde
(@SPAWNGROUP+19, 1, @OGUID+95),
(@SPAWNGROUP+19, 0, @CGUID+22),
-- East graveyard, Alliance
(@SPAWNGROUP+20, 1, @OGUID+46),
(@SPAWNGROUP+20, 0, @CGUID+37),
-- East graveyard, Horde Demolishers
(@SPAWNGROUP+21, 0, @CGUID+15),
(@SPAWNGROUP+21, 0, @CGUID+16),
-- East graveyard, Alliance Demolishers
(@SPAWNGROUP+22, 0, @CGUID+43),
(@SPAWNGROUP+22, 0, @CGUID+44),
-- Central graveyard, Horde
(@SPAWNGROUP+23, 1, @OGUID+110),
(@SPAWNGROUP+23, 0, @CGUID+23),
-- Central graveyard, Alliance
(@SPAWNGROUP+24, 1, @OGUID+54),
(@SPAWNGROUP+24, 0, @CGUID+20);

DELETE FROM `conditions` where `SourceTypeOrReferenceId` = 17 AND `SourceEntry` IN (60027, 60028);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 60027, 0, 0, 13, 1, 1, 0, 0, 0, 0, 0, '', 'Strand of the Ancients - Spell - Alliance Control Phase Shift - Horde Attacking'),
(17, 0, 60028, 0, 0, 13, 1, 0, 0, 0, 0, 0, 0, '', 'Strand of the Ancients - Spell - Alliance Control Phase Shift - Alliance Attacking');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=33 AND `SourceEntry` BETWEEN @SPAWNGROUP+0 AND @SPAWNGROUP+132;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(33, 0, @SPAWNGROUP+0, 0, 0, 11, 0, 3623, 3, 0, 1, 0, 0, '', 'Strand of the Ancients - Green Emerald Gate - Sigil - Not Destroyed'),
(33, 0, @SPAWNGROUP+1, 0, 0, 11, 0, 3620, 3, 0, 1, 0, 0, '', 'Strand of the Ancients - Blue Sapphire Gate - Sigil - Not Destroyed'),
(33, 0, @SPAWNGROUP+2, 0, 0, 11, 0, 3617, 3, 0, 1, 0, 0, '', 'Strand of the Ancients - Red Sun Gate - Sigil - Not Destroyed'),
(33, 0, @SPAWNGROUP+3, 0, 0, 11, 0, 3614, 3, 0, 1, 0, 0, '', 'Strand of the Ancients - Purple Amethyst Gate - Sigil - Not Destroyed'),
(33, 0, @SPAWNGROUP+4, 0, 0, 11, 0, 3638, 3, 0, 1, 0, 0, '', 'Strand of the Ancients - Yewllow Moon Gate - Sigil - Not Destroyed'),
(33, 0, @SPAWNGROUP+0, 0, 0, 11, 0, 3623, 6, 0, 1, 0, 0, '', 'Strand of the Ancients - Green Emerald Gate - Sigil - Not Destroyed'),
(33, 0, @SPAWNGROUP+1, 0, 0, 11, 0, 3620, 6, 0, 1, 0, 0, '', 'Strand of the Ancients - Blue Sapphire Gate - Sigil - Not Destroyed'),
(33, 0, @SPAWNGROUP+2, 0, 0, 11, 0, 3617, 6, 0, 1, 0, 0, '', 'Strand of the Ancients - Red Sun Gate - Sigil - Not Destroyed'),
(33, 0, @SPAWNGROUP+3, 0, 0, 11, 0, 3614, 6, 0, 1, 0, 0, '', 'Strand of the Ancients - Purple Amethyst Gate - Sigil - Not Destroyed'),
(33, 0, @SPAWNGROUP+4, 0, 0, 11, 0, 3638, 6, 0, 1, 0, 0, '', 'Strand of the Ancients - Yewllow Moon Gate - Sigil - Not Destroyed'),
(33, 0, @SPAWNGROUP+5, 0, 0, 11, 0, 3623, 3, 0, 0, 0, 0, '', 'Strand of the Ancients - First Line - Horde Bombs - Green Gate Destroyed'),
(33, 0, @SPAWNGROUP+5, 0, 1, 11, 0, 3620, 3, 0, 0, 0, 0, '', 'Strand of the Ancients - First Line - Horde Bombs - Blue Gate Destroyed'),
(33, 0, @SPAWNGROUP+5, 0, 0, 11, 0, 4353, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - First Line - Horde Bombs - Horde Attacking'),
(33, 0, @SPAWNGROUP+5, 0, 1, 11, 0, 4353, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - First Line - Horde Bombs - Horde Attacking'),
(33, 0, @SPAWNGROUP+6, 0, 0, 11, 0, 3623, 6, 0, 0, 0, 0, '', 'Strand of the Ancients - First Line - Alliance Bombs - Green Gate Destroyed'),
(33, 0, @SPAWNGROUP+6, 0, 1, 11, 0, 3620, 6, 0, 0, 0, 0, '', 'Strand of the Ancients - First Line - Alliance Bombs - Blue Gate Destroyed'),
(33, 0, @SPAWNGROUP+6, 0, 0, 11, 0, 4352, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - First Line - Alliance Bombs - Alliance Attacking'),
(33, 0, @SPAWNGROUP+6, 0, 1, 11, 0, 4352, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - First Line - Alliance Bombs - Alliance Attacking'),
(33, 0, @SPAWNGROUP+7, 0, 0, 11, 0, 3614, 3, 0, 0, 0, 0, '', 'Strand of the Ancients - Second Line - Horde Bombs - Purple Gate Destroyed'),
(33, 0, @SPAWNGROUP+7, 0, 1, 11, 0, 3617, 3, 0, 0, 0, 0, '', 'Strand of the Ancients - Second Line - Horde Bombs - Red Gate Destroyed'),
(33, 0, @SPAWNGROUP+7, 0, 0, 11, 0, 4353, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - Second Line - Horde Bombs - Horde Attacking'),
(33, 0, @SPAWNGROUP+7, 0, 1, 11, 0, 4353, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - Second Line - Horde Bombs - Horde Attacking'),
(33, 0, @SPAWNGROUP+8, 0, 0, 11, 0, 3614, 6, 0, 0, 0, 0, '', 'Strand of the Ancients - First Line - Alliance Bombs - Purple Gate Destroyed'),
(33, 0, @SPAWNGROUP+8, 0, 1, 11, 0, 3617, 6, 0, 0, 0, 0, '', 'Strand of the Ancients - First Line - Alliance Bombs - Red Gate Destroyed'),
(33, 0, @SPAWNGROUP+8, 0, 0, 11, 0, 4352, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - First Line - Alliance Bombs - Alliance Attacking'),
(33, 0, @SPAWNGROUP+8, 0, 1, 11, 0, 4352, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - First Line - Alliance Bombs - Alliance Attacking'),
(33, 0, @SPAWNGROUP+9, 0, 0, 11, 0, 3638, 3, 0, 0, 0, 0, '', 'Strand of the Ancients - Third Line - Horde Bombs - Yellow Gate Destroyed'),
(33, 0, @SPAWNGROUP+9, 0, 0, 11, 0, 4353, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - Third Line - Horde Bombs - Horde Attacking'),
(33, 0, @SPAWNGROUP+10, 0, 0, 11, 0, 3638, 6, 0, 0, 0, 0, '', 'Strand of the Ancients - Third Line - Alliance Bombs - Yellow Gate Destroyed'),
(33, 0, @SPAWNGROUP+10, 0, 0, 11, 0, 4352, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - Third Line - Alliance Bombs - Alliance Attacking'),
(33, 0, @SPAWNGROUP+11, 0, 0, 11, 0, 4353, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - Beach - Horde Bombs - Horde Attacking'),
(33, 0, @SPAWNGROUP+12, 0, 0, 11, 0, 4352, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - Beach - Alliance Bombs - Alliance Attacking'),
(33, 0, @SPAWNGROUP+13, 0, 0, 11, 0, 4353, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - Beach - Demolishers - Horde Attacking'),
(33, 0, @SPAWNGROUP+13, 0, 0, 11, 0, 3564, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - Beach - Demolishers - Battle started (Timer shown)'),
(33, 0, @SPAWNGROUP+14, 0, 0, 11, 0, 4352, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - Beach - Demolishers - Alliance Attacking'),
(33, 0, @SPAWNGROUP+14, 0, 0, 11, 0, 3564, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - Beach - Demolishers - Battle started (Timer shown)'),
(33, 0, @SPAWNGROUP+15, 0, 0, 11, 0, 3633, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - West Graveyard - Horde Controlled'),
(33, 0, @SPAWNGROUP+16, 0, 0, 11, 0, 3635, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - West Graveyard - Alliance Controlled'),

(33, 0, @SPAWNGROUP+17, 0, 0, 11, 0, 3633, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - West Graveyard Demolishers - Horde Controlled'),
(33, 0, @SPAWNGROUP+17, 0, 0, 11, 0, 4353, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - West Graveyard Demolishers - Horde Attacking'),
(33, 0, @SPAWNGROUP+18, 0, 0, 11, 0, 3635, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - West Graveyard Demolishers - Alliance Controlled'),
(33, 0, @SPAWNGROUP+18, 0, 0, 11, 0, 4352, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - West Graveyard Demolishers - Alliance Attacking'),

(33, 0, @SPAWNGROUP+19, 0, 0, 11, 0, 3632, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - East Graveyard - Horde Controlled'),
(33, 0, @SPAWNGROUP+20, 0, 0, 11, 0, 3636, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - East Graveyard - Alliance Controlled'),

(33, 0, @SPAWNGROUP+21, 0, 0, 11, 0, 3632, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - East Graveyard Demolishers - Horde Controlled'),
(33, 0, @SPAWNGROUP+21, 0, 0, 11, 0, 4353, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - East Graveyard Demolishers - Horde Attacking'),
(33, 0, @SPAWNGROUP+22, 0, 0, 11, 0, 3636, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - East Graveyard Demolishers - Alliance Controlled'),
(33, 0, @SPAWNGROUP+22, 0, 0, 11, 0, 4352, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - East Graveyard Demolishers - Alliance Attacking'),

(33, 0, @SPAWNGROUP+23, 0, 0, 11, 0, 3634, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - Central Graveyard - Horde Controlled'),
(33, 0, @SPAWNGROUP+24, 0, 0, 11, 0, 3637, 1, 0, 0, 0, 0, '', 'Strand of the Ancients - Central Graveyard - Alliance Controlled');

DELETE FROM `graveyard_zone` WHERE `ID` IN (1346, 1347, 1348, 1349, 1350);
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(1350, 4384, 'Strand of the Ancients - Landing beach'),
(1349, 4384, 'Strand of the Ancients - Courtyard'),
(1348, 4384, 'Strand of the Ancients - Mid'),
(1347, 4384, 'Strand of the Ancients - East'),
(1346, 4384, 'Strand of the Ancients - West');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 27 AND `SourceEntry` IN (1346, 1347, 1348, 1349, 1350);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
(27, 1350, 4384, 0, 6, 469, 0, 'Graveyard - Strand of the Ancients - Landing Beach - Team Alliance'),
(27, 1350, 4384, 0, 11, 4352, 1, 'Graveyard - Strand of the Ancients - Landing Beach - Alliance Attacking'),
(27, 1350, 4384, 1, 6, 67, 0, 'Graveyard - Strand of the Ancients - Landing Beach - Team Horde'),
(27, 1350, 4384, 1, 11, 4353, 1, 'Graveyard - Strand of the Ancients - Landing Beach - Horde Attacking'),
(27, 1349, 4384, 0, 11, 4353, 0, 'Graveyard - Strand of the Ancients - Courtyard - Horde Defending'),
(27, 1349, 4384, 0, 6, 67, 0, 'Graveyard - Strand of the Ancients - Courtyard - Team Horde'),
(27, 1349, 4384, 1, 11, 4352, 0, 'Graveyard - Strand of the Ancients - Courtyard - Alliance Defending'),
(27, 1349, 4384, 1, 6, 469, 0, 'Graveyard - Strand of the Ancients - Courtyard - Team Alliance'),
(27, 1347, 4384, 0, 11, 3636, 1, 'Graveyard - Strand of the Ancients - East - Alliance Controlled'),
(27, 1347, 4384, 0, 6, 469, 0, 'Graveyard - Strand of the Ancients - East - Team Alliance'),
(27, 1347, 4384, 1, 11, 3632, 1, 'Graveyard - Strand of the Ancients - East - Horde Controlled'),
(27, 1347, 4384, 1, 6, 67, 0, 'Graveyard - Strand of the Ancients - East - Team Horde'),
(27, 1346, 4384, 0, 11, 3635, 1, 'Graveyard - Strand of the Ancients - West - Alliance Controlled'),
(27, 1346, 4384, 0, 6, 469, 0, 'Graveyard - Strand of the Ancients - West - Team Alliance'),
(27, 1346, 4384, 1, 11, 3633, 1, 'Graveyard - Strand of the Ancients - West - Horde Controlled'),
(27, 1346, 4384, 1, 6, 67, 0, 'Graveyard - Strand of the Ancients - West - Team Horde'),
(27, 1348, 4384, 0, 11, 3637, 1, 'Graveyard - Strand of the Ancients - Mid - Alliance Controlled'),
(27, 1348, 4384, 0, 6, 469, 0, 'Graveyard - Strand of the Ancients - Mid - Team Alliance'),
(27, 1348, 4384, 1, 11, 3634, 1, 'Graveyard - Strand of the Ancients - Mid - Horde Controlled'),
(27, 1348, 4384, 1, 6, 67, 0, 'Graveyard - Strand of the Ancients - Mid - Team Horde');


DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1000;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+10, 29, 607, 4384, 4384, '0', 0, 0, 0, 0, 841.92059326171875, -134.193954467773437, 196.8380889892578125, 6.230825424194335937, 7200, 0, 0, 63418750, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Kanrethad (Area: Strand of the Ancients - Difficulty: Normal) CreateObject1
-- Demolishers & Goblins
(@CGUID+11, 28781, 607, 4384, 0, '0', 0, 0, 0, 0, 1618.0477294921875, 61.42464065551757812, 7.248210430145263671, 3.979350566864013671, 60, 0, 0, 7274869, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Battleground Demolisher (Area: Landing Beach - Difficulty: Normal) CreateObject2 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+12, 28781, 607, 4384, 0, '0', 0, 0, 0, 0, 1611.59765625, -117.270072937011718, 8.719354629516601562, 2.513274192810058593, 60, 0, 0, 7274869, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Battleground Demolisher (Area: Landing Beach - Difficulty: Normal) CreateObject2 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+13, 28781, 607, 4384, 0, '0', 0, 0, 0, 0, 1352.4898681640625, 222.2818145751953125, 35.27858734130859375, 4.380776405334472656, 60, 0, 0, 7274869, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Battleground Demolisher (Area: Landing Beach - Difficulty: Normal) CreateObject2 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+14, 29262, 607, 4384, 0, '0', 0, 0, 0, 0, 1358.1910400390625, 195.5277862548828125, 31.01818656921386718, 4.171336650848388671, 60, 0, 0, 1039267, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Gorgril Rigspark (Area: Landing Beach - Difficulty: Normal) CreateObject1
(@CGUID+15, 28781, 607, 4384, 0, '0', 0, 0, 0, 0, 1370.0133056640625, -313.867889404296875, 34.8538055419921875, 1.954768776893615722, 60, 0, 0, 7274869, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Battleground Demolisher (Area: 0 - Difficulty: Normal) CreateObject2 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+16, 29260, 607, 4384, 0, '0', 0, 0, 0, 0, 1348.6441650390625, -298.786468505859375, 31.08012962341308593, 1.710422635078430175, 60, 0, 0, 1039267, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Rigger Sparklight (Area: 0 - Difficulty: Normal) CreateObject1

(@CGUID+39, 28781, 607, 4384, 0, '0', 0, 0, 0, 0, 1618.0477294921875, 61.42464065551757812, 7.248210430145263671, 3.979350566864013671, 60, 0, 0, 7274869, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Battleground Demolisher (Area: Landing Beach - Difficulty: Normal) CreateObject2 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+40, 28781, 607, 4384, 0, '0', 0, 0, 0, 0, 1611.59765625, -117.270072937011718, 8.719354629516601562, 2.513274192810058593, 60, 0, 0, 7274869, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Battleground Demolisher (Area: Landing Beach - Difficulty: Normal) CreateObject2 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+41, 28781, 607, 4384, 0, '0', 0, 0, 0, 0, 1352.4898681640625, 222.2818145751953125, 35.27858734130859375, 4.380776405334472656, 60, 0, 0, 7274869, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Battleground Demolisher (Area: Landing Beach - Difficulty: Normal) CreateObject2 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+42, 29262, 607, 4384, 0, '0', 0, 0, 0, 0, 1358.1910400390625, 195.5277862548828125, 31.01818656921386718, 4.171336650848388671, 60, 0, 0, 1039267, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Gorgril Rigspark (Area: Landing Beach - Difficulty: Normal) CreateObject1
(@CGUID+43, 28781, 607, 4384, 0, '0', 0, 0, 0, 0, 1370.0133056640625, -313.867889404296875, 34.8538055419921875, 1.954768776893615722, 60, 0, 0, 7274869, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Battleground Demolisher (Area: 0 - Difficulty: Normal) CreateObject2 (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+44, 29260, 607, 4384, 0, '0', 0, 0, 0, 0, 1348.6441650390625, -298.786468505859375, 31.08012962341308593, 1.710422635078430175, 60, 0, 0, 1039267, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Rigger Sparklight (Area: 0 - Difficulty: Normal) CreateObject1

-- Cannons
(@CGUID+0, 27894, 607, 4384, 4384, '0', 0, 0, 0, 0, 1455.232666015625, -219.59722900390625, 42.03958511352539062, 1.029744267463684082, 7200, 0, 0, 5196335, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Antipersonnel Cannon (Area: Strand of the Ancients - Difficulty: Normal) CreateObject1 (Auras: 52455 - PvP Vehicle Health Regen Suppression, 65219 - (Serverside/Non-DB2) No Teleport)
(@CGUID+1, 27894, 607, 4384, 4384, '0', 0, 0, 0, 0, 1422.6475830078125, -195.87847900390625, 42.26543807983398437, 0.977384388446807861, 7200, 0, 0, 5196335, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Antipersonnel Cannon (Area: Strand of the Ancients - Difficulty: Normal) CreateObject1 (Auras: 52455 - PvP Vehicle Health Regen Suppression, 65219 - (Serverside/Non-DB2) No Teleport)
(@CGUID+2, 27894, 607, 4384, 4384, '0', 0, 0, 0, 0, 1250.4010009765625, -223.498260498046875, 66.80340576171875, 0.558505356311798095, 7200, 0, 0, 5196335, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Antipersonnel Cannon (Area: Strand of the Ancients - Difficulty: Normal) CreateObject1 (Auras: 52455 - PvP Vehicle Health Regen Suppression, 65219 - (Serverside/Non-DB2) No Teleport)
(@CGUID+3, 27894, 607, 4384, 4384, '0', 0, 0, 0, 0, 1233.0711669921875, -187.083328247070312, 67.0279541015625, 0.506145477294921875, 7200, 0, 0, 5196335, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Antipersonnel Cannon (Area: Strand of the Ancients - Difficulty: Normal) CreateObject1 (Auras: 52455 - PvP Vehicle Health Regen Suppression, 65219 - (Serverside/Non-DB2) No Teleport)
(@CGUID+4, 27894, 607, 4384, 4384, '0', 0, 0, 0, 0, 1437.03125, 109.354156494140625, 41.490570068359375, 5.607047080993652343, 7200, 0, 0, 5196335, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Antipersonnel Cannon (Area: Strand of the Ancients - Difficulty: Normal) CreateObject1 (Auras: 52455 - PvP Vehicle Health Regen Suppression, 65219 - (Serverside/Non-DB2) No Teleport)
(@CGUID+5, 27894, 607, 4384, 4384, '0', 0, 0, 0, 0, 1405.5728759765625, 83.92534637451171875, 41.18357086181640625, 6.06153726577758789, 7200, 0, 0, 5196335, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Antipersonnel Cannon (Area: Strand of the Ancients - Difficulty: Normal) CreateObject1 (Auras: 52455 - PvP Vehicle Health Regen Suppression, 65219 - (Serverside/Non-DB2) No Teleport)
(@CGUID+6, 27894, 607, 4384, 4384, '0', 0, 0, 0, 0, 1215.75, 57.36284637451171875, 64.8218994140625, 5.777040004730224609, 7200, 0, 0, 5196335, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Antipersonnel Cannon (Area: Strand of the Ancients - Difficulty: Normal) CreateObject1 (Auras: 52455 - PvP Vehicle Health Regen Suppression, 65219 - (Serverside/Non-DB2) No Teleport)
(@CGUID+7, 27894, 607, 4384, 4384, '0', 0, 0, 0, 0, 1236.920166015625, 91.80034637451171875, 65.04779052734375, 5.724679946899414062, 7200, 0, 0, 5196335, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Antipersonnel Cannon (Area: Strand of the Ancients - Difficulty: Normal) CreateObject1 (Auras: 52455 - PvP Vehicle Health Regen Suppression, 65219 - (Serverside/Non-DB2) No Teleport)
(@CGUID+8, 27894, 607, 4384, 4384, '0', 0, 0, 0, 0, 1069.779541015625, -127.418403625488281, 96.532867431640625, 0.104719758033752441, 7200, 0, 0, 5196335, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Antipersonnel Cannon (Area: Strand of the Ancients - Difficulty: Normal) CreateObject1 (Auras: 52455 - PvP Vehicle Health Regen Suppression, 65219 - (Serverside/Non-DB2) No Teleport)
(@CGUID+9, 27894, 607, 4384, 4384, '0', 0, 0, 0, 0, 1069.1805419921875, -87.0833358764648437, 93.88944244384765625, 6.2657318115234375, 7200, 0, 0, 5196335, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Antipersonnel Cannon (Area: Strand of the Ancients - Difficulty: Normal) CreateObject1 (Auras: 52455 - PvP Vehicle Health Regen Suppression, 65219 - (Serverside/Non-DB2) No Teleport)

(@CGUID+24, 27894, 607, 4384, 0, '0', 0, 0, 0, 0, 1069.779541015625, -127.418403625488281, 96.532867431640625, 0.104719758033752441, 7200, 0, 0, 5196335, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Antipersonnel Cannon (Area: 0 - Difficulty: Normal) CreateObject2 (Auras: 65219 - (Serverside/Non-DB2) No Teleport)
(@CGUID+25, 27894, 607, 4384, 0, '0', 0, 0, 0, 0, 1215.75, 57.36284637451171875, 64.8218994140625, 5.777040004730224609, 7200, 0, 0, 5196335, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Antipersonnel Cannon (Area: 0 - Difficulty: Normal) CreateObject2 (Auras: 65219 - (Serverside/Non-DB2) No Teleport)
(@CGUID+26, 27894, 607, 4384, 0, '0', 0, 0, 0, 0, 1069.1805419921875, -87.0833358764648437, 93.88944244384765625, 6.2657318115234375, 7200, 0, 0, 5196335, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Antipersonnel Cannon (Area: 0 - Difficulty: Normal) CreateObject2 (Auras: 65219 - (Serverside/Non-DB2) No Teleport)
(@CGUID+27, 27894, 607, 4384, 0, '0', 0, 0, 0, 0, 1233.0711669921875, -187.083328247070312, 67.0279541015625, 0.506145477294921875, 7200, 0, 0, 5196335, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Antipersonnel Cannon (Area: 0 - Difficulty: Normal) CreateObject2 (Auras: 65219 - (Serverside/Non-DB2) No Teleport)
(@CGUID+28, 27894, 607, 4384, 0, '0', 0, 0, 0, 0, 1250.4010009765625, -223.498260498046875, 66.80340576171875, 0.558505356311798095, 7200, 0, 0, 5724494, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Antipersonnel Cannon (Area: 0 - Difficulty: Normal) CreateObject2 (Auras: 65219 - (Serverside/Non-DB2) No Teleport)
(@CGUID+29, 27894, 607, 4384, 0, '0', 0, 0, 0, 0, 1437.03125, 109.354156494140625, 41.490570068359375, 5.427973747253417968, 7200, 0, 0, 5196335, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Antipersonnel Cannon (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 65219 - (Serverside/Non-DB2) No Teleport, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+30, 27894, 607, 4384, 0, '0', 0, 0, 0, 0, 1405.5728759765625, 83.92534637451171875, 41.26646804809570312, 5.480333805084228515, 7200, 0, 0, 5196335, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Antipersonnel Cannon (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 65219 - (Serverside/Non-DB2) No Teleport, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+31, 27894, 607, 4384, 0, '0', 0, 0, 0, 0, 1422.6475830078125, -195.87847900390625, 42.26543807983398437, 0.977384388446807861, 7200, 0, 0, 5196335, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Antipersonnel Cannon (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 65219 - (Serverside/Non-DB2) No Teleport, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+32, 27894, 607, 4384, 0, '0', 0, 0, 0, 0, 1455.232666015625, -219.59722900390625, 42.03958511352539062, 1.029744267463684082, 7200, 0, 0, 5196335, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Antipersonnel Cannon (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 65219 - (Serverside/Non-DB2) No Teleport, 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+33, 27894, 607, 4384, 0, '0', 0, 0, 0, 0, 1236.920166015625, 91.80034637451171875, 65.04779052734375, 5.724679946899414062, 7200, 0, 0, 5196335, 0, 0, NULL, NULL, NULL, NULL, 26365), -- Antipersonnel Cannon (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 65219 - (Serverside/Non-DB2) No Teleport, 52455 - PvP Vehicle Health Regen Suppression)

-- Spirit guides
(@CGUID+17, 13117, 607, 4384, 4608, '0', 0, 0, 0, 1, 1391.88671875, 204.820587158203125, 32.23511505126953125, 4.468042850494384765, 7200, 0, 0, 10392670, 533108, 0, NULL, NULL, NULL, NULL, 26365), -- Horde Spirit Guide (Area: Gate of the Yellow Moon - Difficulty: Normal) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+18, 13116, 607, 4384, 4608, '0', 0, 0, 0, 1, 962.7569580078125, -183.116317749023437, 91.6829833984375, 0.453785598278045654, 7200, 0, 0, 10392670, 533108, 0, NULL, NULL, NULL, NULL, 26365), -- Alliance Spirit Guide (Area: Gate of the Yellow Moon - Difficulty: Normal) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+19, 13117, 607, 4384, 4608, '0', 0, 0, 0, 1, 1624.745361328125, 93.1954193115234375, 22.07644271850585937, 4.345870018005371093, 7200, 0, 0, 10392670, 533108, 0, NULL, NULL, NULL, NULL, 26365), -- Horde Spirit Guide (Area: Gate of the Yellow Moon - Difficulty: Normal) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+20, 13116, 607, 4384, 4608, '0', 0, 0, 0, 1, 1121.28125, 3.008681058883666992, 69.05757904052734375, 5.393067359924316406, 7200, 0, 0, 10392670, 533108, 0, NULL, NULL, NULL, NULL, 26365), -- Alliance Spirit Guide (Area: Gate of the Yellow Moon - Difficulty: Normal) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+21, 13117, 607, 4384, 4608, '0', 0, 0, 0, 1, 1447.765625, -53.6927070617675781, 5.908266544342041015, 6.195918560028076171, 7200, 0, 0, 10392670, 533108, 0, NULL, NULL, NULL, NULL, 26365), -- Horde Spirit Guide (Area: Gate of the Yellow Moon - Difficulty: Normal) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+22, 13117, 607, 4384, 4608, '0', 0, 0, 0, 1, 1397.7364501953125, -294.83636474609375, 32.26296234130859375, 2.321287870407104492, 7200, 0, 0, 10392670, 533108, 0, NULL, NULL, NULL, NULL, 26365), -- Horde Spirit Guide (Area: Gate of the Yellow Moon - Difficulty: Normal) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+23, 13117, 607, 4384, 4606, '0', 0, 0, 0, 1, 1121.951904296875, 4.433268070220947265, 69.02452850341796875, 5.759586334228515625, 7200, 0, 0, 10392670, 533108, 0, NULL, NULL, NULL, NULL, 26365), -- Horde Spirit Guide (Area: 0 - Difficulty: Normal) CreateObject2 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+34, 13117, 607, 4384, 4606, '0', 0, 0, 0, 1, 963.91839599609375, -183.118057250976562, 91.5367431640625, 0.855211317539215087, 7200, 0, 0, 10392670, 533108, 0, NULL, NULL, NULL, NULL, 26365), -- Horde Spirit Guide (Area: Gate of the Green Emerald - Difficulty: Normal) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+35, 13116, 607, 4384, 4606, '0', 0, 0, 0, 1, 1624.7965087890625, 93.500732421875, 22.07644081115722656, 4.468042850494384765, 7200, 0, 0, 10392670, 533108, 0, NULL, NULL, NULL, NULL, 26365), -- Alliance Spirit Guide (Area: Gate of the Green Emerald - Difficulty: Normal) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+36, 13116, 607, 4384, 4606, '0', 0, 0, 0, 1, 1448.640625, -53.2065963745117187, 5.839278697967529296, 0.01745329238474369, 7200, 0, 0, 10392670, 533108, 0, NULL, NULL, NULL, NULL, 26365), -- Alliance Spirit Guide (Area: Gate of the Green Emerald - Difficulty: Normal) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+37, 13116, 607, 4384, 4608, '0', 0, 0, 0, 1, 1397.7364501953125, -294.83636474609375, 32.26296234130859375, 2.321287870407104492, 7200, 0, 0, 10392670, 533108, 0, NULL, NULL, NULL, NULL, 0),-- Alliance Spirit Guide (Area: Gate of the Yellow Moon - Difficulty: Normal) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+38, 13116, 607, 4384, 4608, '0', 0, 0, 0, 1, 1391.88671875, 204.820587158203125, 32.23511505126953125, 4.468042850494384765, 7200, 0, 0, 10392670, 533108, 0, NULL, NULL, NULL, NULL, 0); -- Alliance Spirit Guide (Area: Gate of the Yellow Moon - Difficulty: Normal) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)

UPDATE `creature_template_addon` SET `PvpFlags`=1, `auras`='52455' WHERE `entry`=28781; -- 28781 (Battleground Demolisher) - PvP Vehicle Health Regen Suppression
UPDATE `creature_template_addon` SET `PvpFlags`=1, `auras`='52455 65219' WHERE `entry`=27894; -- 27894 (Antipersonnel Cannon) - PvP Vehicle Health Regen Suppression, (Serverside/Non-DB2) No Teleport

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+350;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 190723, 607, 0, 0, '0', '0', 0, 1214.77783203125, 81.56076812744140625, 54.58214187622070312, 5.777040958404541015, 0, 0, -0.25037956237792968, 0.968147754669189453, 7200, 216, 1, 26365), -- Gate of the Purple Amethyst (Area: -Unknown- - Difficulty: Normal) CreateObject1
(@OGUID+1, 190722, 607, 0, 0, '0', '0', 0, 1412.7430419921875, 106.9930572509765625, 29.87796974182128906, 5.436700820922851562, 0, 0, -0.41071891784667968, 0.911761999130249023, 7200, 0, 1, 26365), -- Gate of the Green Emerald (Area: -Unknown- - Difficulty: Normal) CreateObject1
(@OGUID+2, 193184, 607, 0, 0, '0', '0', 0, 2686.109375, -831.19549560546875, 0.45196533203125, 5.719419479370117187, 0, 0, -0.27816486358642578, 0.960533320903778076, 7200, 255, 24, 26365), -- The Coffin Carrier (Area: -Unknown- - Difficulty: Normal) CreateObject1
(@OGUID+3, 190724, 607, 0, 0, '0', '0', 0, 1431.1336669921875, -218.684036254882812, 32.10478591918945312, 0.986111819744110107, 0, 0, 0.47332000732421875, 0.880890548229217529, 7200, 0, 1, 26365), -- Gate of the Blue Sapphire (Area: -Unknown- - Difficulty: Normal) CreateObject1
(@OGUID+4, 190727, 607, 0, 0, '0', '0', 0, 1055.8992919921875, -107.628471374511718, 83.4274749755859375, 0.061086613684892654, 0, 0, 0.030538558959960937, 0.999533593654632568, 7200, 255, 1, 26365), -- Gate of the Yellow Moon (Area: -Unknown- - Difficulty: Normal) CreateObject1
(@OGUID+5, 190726, 607, 0, 0, '0', '0', 0, 1229.6666259765625, -211.30035400390625, 56.4359893798828125, 0.488691210746765136, 0, 0, 0.241921424865722656, 0.970295846462249755, 7200, 216, 1, 26365), -- Gate of the Red Sun (Area: -Unknown- - Difficulty: Normal) CreateObject1
(@OGUID+6, 192549, 607, 0, 0, '0', '0', 0, 878.03302001953125, -108.190971374511718, 117.8321762084960937, 0.010599185712635517, 0, 0, 0.005299568176269531, 0.999985933303833007, 7200, 255, 1, 26365), -- Chamber of Ancient Relics (Area: -Unknown- - Difficulty: Normal) CreateObject1
(@OGUID+7, 208001, 607, 4384, 4384, '0', 0, 0, 2578.895263671875, 986.32940673828125, -0.68536376953125, 0.807695746421813964, 0, 0, 0.3929595947265625, 0.919555723667144775, 7200, 255, 24, 26365), -- The Blightbringer (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+8, 194086, 607, 4384, 4384, '0', 0, 0, 1593.9642333984375, -96.168731689453125, 8.782253265380859375, 5.148722648620605468, 0, 0, -0.53729915618896484, 0.843391716480255126, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+9, 194086, 607, 4384, 4384, '0', 0, 0, 1581.9661865234375, -100.925033569335937, 8.327397346496582031, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+10, 194086, 607, 4384, 4384, '0', 0, 0, 1584.4390869140625, -103.336906433105468, 8.502038002014160156, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+11, 194086, 607, 4384, 4384, '0', 0, 0, 1585.013916015625, -104.328132629394531, 8.6132049560546875, 0.401424884796142578, 0, 0, 0.199367523193359375, 0.979924798011779785, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+12, 194086, 607, 4384, 4384, '0', 0, 0, 1581.2027587890625, -99.4962005615234375, 8.337002754211425781, 5.567600727081298828, 0, 0, -0.35020732879638671, 0.936672210693359375, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+13, 194086, 607, 4384, 4384, '0', 0, 0, 1583.673583984375, -91.875, 8.890683174133300781, 2.984498262405395507, 0, 0, 0.996916770935058593, 0.078466430306434631, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+14, 194086, 607, 4384, 4384, '0', 0, 0, 1584.1591796875, -92.271484375, 8.347928047180175781, 2.862335443496704101, 0, 0, 0.990267753601074218, 0.139175355434417724, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+15, 194086, 607, 4384, 4384, '0', 0, 0, 1584.295166015625, -103.916656494140625, 9.069079399108886718, 2.967041015625, 0, 0, 0.996193885803222656, 0.087165042757987976, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+16, 194086, 607, 4384, 4384, '0', 0, 0, 1583.457275390625, -104.075088500976562, 8.451749801635742187, 4.625123500823974609, 0, 0, -0.73727703094482421, 0.67559051513671875, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+17, 194086, 607, 4384, 4384, '0', 0, 0, 1582.967041015625, -92.590606689453125, 8.353337287902832031, 5.009094715118408203, 0, 0, -0.59482288360595703, 0.80385679006576538, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+18, 194086, 607, 4384, 4384, '0', 0, 0, 1583.354736328125, -91.1810989379882812, 8.356536865234375, 1.675513744354248046, 0, 0, 0.743144035339355468, 0.669131457805633544, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+19, 194086, 607, 4384, 4384, '0', 0, 0, 1592.642578125, 46.12369918823242187, 7.403531074523925781, 3.961898565292358398, 0, 0, -0.91705989837646484, 0.398749500513076782, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+20, 194086, 607, 4384, 4384, '0', 0, 0, 1591.729736328125, 47.05099868774414062, 7.381677150726318359, 2.862335443496704101, 0, 0, 0.990267753601074218, 0.139175355434417724, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+21, 194086, 607, 4384, 4384, '0', 0, 0, 1589.41064453125, 35.65158462524414062, 7.353652000427246093, 0.401424884796142578, 0, 0, 0.199367523193359375, 0.979924798011779785, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+22, 194086, 607, 4384, 4384, '0', 0, 0, 1594.083251953125, 46.61653518676757812, 7.441329002380371093, 4.572763919830322265, 0, 0, -0.75470924377441406, 0.656059443950653076, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+23, 194086, 607, 4384, 4384, '0', 0, 0, 1588.6461181640625, 34.91232681274414062, 7.436020851135253906, 0.663223206996917724, 0, 0, 0.325567245483398437, 0.945518851280212402, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+24, 194086, 607, 4384, 4384, '0', 0, 0, 1598.3648681640625, 37.421875, 7.396986007690429687, 5.969027042388916015, 0, 0, -0.1564340591430664, 0.987688362598419189, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+25, 194086, 607, 4384, 4384, '0', 0, 0, 1593.08740234375, 47.30522918701171875, 7.410294055938720703, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+26, 194086, 607, 4384, 4384, '0', 0, 0, 1597.0955810546875, 37.20963668823242187, 7.371291160583496093, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+27, 194086, 607, 4384, 4384, '0', 0, 0, 1594.7999267578125, 47.51573562622070312, 7.569773197174072265, 4.520402908325195312, 0, 0, -0.77162456512451171, 0.636078238487243652, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+28, 192689, 607, 4384, 4384, '0', 0, 0, 1433.3487548828125, -215.607315063476562, 44.42230606079101562, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 7200, 255, 1, 26365), -- Blue Moon Sigil (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+29, 194086, 607, 4384, 4384, '0', 0, 0, 1598.511474609375, 36.18088150024414062, 7.37793588638305664, 4.799657344818115234, 0, 0, -0.67558956146240234, 0.737277925014495849, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+30, 194086, 607, 4384, 4384, '0', 0, 0, 1597.704833984375, 37.00347137451171875, 7.80081796646118164, 4.572763919830322265, 0, 0, -0.75470924377441406, 0.656059443950653076, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+31, 194086, 607, 4384, 4384, '0', 0, 0, 1596.1759033203125, 36.333984375, 7.345334053039550781, 3.769911527633666992, 0, 0, -0.95105648040771484, 0.309017121791839599, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+32, 194086, 607, 4384, 4384, '0', 0, 0, 1588.3658447265625, 36.28743362426757812, 7.376103878021240234, 5.044002056121826171, 0, 0, -0.58070278167724609, 0.814115643501281738, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+33, 194086, 607, 4384, 4384, '0', 0, 0, 1339.18896484375, -303.45263671875, 30.907958984375, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+34, 194086, 607, 4384, 4384, '0', 0, 0, 1440.8489990234375, -44.5815963745117187, 5.729386329650878906, 2.984498262405395507, 0, 0, 0.996916770935058593, 0.078466430306434631, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+35, 194086, 607, 4384, 4384, '0', 0, 0, 1435.7760009765625, -52.8541679382324218, 5.859138011932373046, 4.677483558654785156, 0, 0, -0.71933937072753906, 0.694658815860748291, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+36, 194086, 607, 4384, 4384, '0', 0, 0, 1441.3992919921875, -45.09375, 5.82074594497680664, 4.799657344818115234, 0, 0, -0.67558956146240234, 0.737277925014495849, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+37, 194086, 607, 4384, 4384, '0', 0, 0, 1438.7379150390625, -59.9583320617675781, 5.371419429779052734, 3.717553615570068359, 0, 0, -0.95881938934326171, 0.284016460180282592, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+38, 194086, 607, 4384, 4384, '0', 0, 0, 1440.63720703125, -45.4427070617675781, 5.888772964477539062, 3.036838293075561523, 0, 0, 0.998628616333007812, 0.052353221923112869, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+39, 194086, 607, 4384, 4384, '0', 0, 0, 1439.765625, -59.7795143127441406, 5.413985252380371093, 5.026549339294433593, 0, 0, -0.5877847671508789, 0.809017360210418701, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+40, 194086, 607, 4384, 4384, '0', 0, 0, 1435.5086669921875, -53.453125, 5.804205894470214843, 4.118979454040527343, 0, 0, -0.88294696807861328, 0.469472706317901611, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+41, 194086, 607, 4384, 4384, '0', 0, 0, 1435.4757080078125, -51.8454856872558593, 5.790664196014404296, 2.792518377304077148, 0, 0, 0.984807014465332031, 0.173652306199073791, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+42, 194086, 607, 4384, 4384, '0', 0, 0, 1440, -44.734375, 5.762050151824951171, 3.43830275535583496, 0, 0, -0.98901557922363281, 0.147811368107795715, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+43, 194086, 607, 4384, 4384, '0', 0, 0, 1434.9444580078125, -52.5972213745117187, 5.692234992980957031, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+44, 194086, 607, 4384, 4384, '0', 0, 0, 1439.30908203125, -60.9479179382324218, 5.210583209991455078, 3.490667104721069335, 0, 0, -0.98480701446533203, 0.173652306199073791, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+45, 191311, 607, 4384, 4384, '0', 0, 0, 1338.8646240234375, -153.336807250976562, 30.90653228759765625, 3.752462387084960937, 0, 0, -0.95371627807617187, 0.300707906484603881, 7200, 255, 1, 26365), -- Flagpole (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+46, 191306, 607, 4384, 4384, '0', 0, 0, 1338.859375, -153.328125, 30.90636825561523437, 3.752462387084960937, 0, 0, -0.95371627807617187, 0.300707906484603881, 7200, 255, 1, 26365), -- Alliance Banner (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+47, 194162, 607, 4384, 4384, '0', 0, 0, 878.03302001953125, -108.190971374511718, 117.8321762084960937, 0.010599185712635517, 0, 0, 0.005299568176269531, 0.999985933303833007, 7200, 255, 1, 26365), -- Doodad_WG_Keep_Door01_collision01 (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+48, 192687, 607, 4384, 4384, '0', 0, 0, 1415.5390625, 103.830078125, 42.19883346557617187, 5.550147056579589843, 0, 0, -0.358367919921875, 0.933580458164215087, 7200, 255, 1, 26365), -- Green Moon Sigil (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+49, 191311, 607, 4384, 4384, '0', 0, 0, 1324.845458984375, 17.9375, 31.10868072509765625, 4.660029888153076171, 0, 0, -0.72537422180175781, 0.688354730606079101, 7200, 255, 1, 26365), -- Flagpole (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+50, 191308, 607, 4384, 4384, '0', 0, 0, 1324.9149169921875, 17.94270896911621093, 31.112274169921875, 1.518436193466186523, 0, 0, 0.6883544921875, 0.725374460220336914, 7200, 255, 1, 26365), -- Alliance Banner (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+51, 192690, 607, 4384, 4384, '0', 0, 0, 1233.8836669921875, -209.275283813476562, 69.0842132568359375, 0.558503925800323486, 0, 0, 0.275636672973632812, 0.961261868476867675, 7200, 255, 1, 26365), -- Red Moon Sigil (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+52, 191575, 607, 4384, 4384, '0', 0, 0, 1394.23681640625, 72.10178375244140625, 31.10579109191894531, 5.724681377410888671, 0, 0, -0.27563667297363281, 0.961261868476867675, 7200, 255, 1, 26365), -- Defender's Portal (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+53, 191311, 607, 4384, 4384, '0', 0, 0, 1215.1142578125, -65.7118606567382812, 70.08426666259765625, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 7200, 255, 1, 26365), -- Flagpole (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+54, 191310, 607, 4384, 4384, '0', 0, 0, 1215.1080322265625, -65.7157669067382812, 70.08426666259765625, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 7200, 255, 1, 26365), -- Alliance Banner (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+55, 191575, 607, 4384, 4384, '0', 0, 0, 1467.954833984375, -225.829864501953125, 30.96954727172851562, 3.874631166458129882, 0, 0, -0.93358039855957031, 0.358368009328842163, 7200, 255, 1, 26365), -- Defender's Portal (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+56, 191575, 607, 4384, 4384, '0', 0, 0, 1255.875, -233.723953247070312, 56.49681472778320312, 5.811946868896484375, 0, 0, -0.2334451675415039, 0.972369968891143798, 7200, 255, 1, 26365), -- Defender's Portal (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+57, 191575, 607, 4384, 4384, '0', 0, 0, 1216.0625, 47.546875, 54.34365081787109375, 4.45059061050415039, 0, 0, -0.79335308074951171, 0.608761727809906005, 7200, 255, 1, 26365), -- Defender's Portal (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+58, 192691, 607, 4384, 4384, '0', 0, 0, 1218.456787109375, 80.10538482666015625, 66.9543304443359375, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 7200, 255, 1, 26365), -- Purple Moon Sigil (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+59, 184977, 607, 4384, 4384, '0', 0, 0, 1357.075439453125, -323.11920166015625, 36.83068466186523437, 1.954769015312194824, 0, 0, 0.829037666320800781, 0.559192776679992675, 7200, 255, 1, 26365), -- Restoration Buff (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+60, 192685, 607, 4384, 4384, '0', 0, 0, 1060.4227294921875, -107.403648376464843, 95.74500274658203125, 0.24434557557106018, 0, 0, 0.121869087219238281, 0.9925462007522583, 7200, 255, 1, 26365), -- Yellow Moon Sigil (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+61, 191575, 607, 4384, 4384, '0', 0, 0, 1065.2412109375, -89.75341796875, 81.00298309326171875, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 7200, 255, 1, 26365), -- Defender's Portal (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+62, 184965, 607, 4384, 4384, '0', 0, 0, 1367.577880859375, 219.2498321533203125, 37.06921005249023437, 4.398232460021972656, 0, 0, -0.80901622772216796, 0.587786316871643066, 7200, 255, 1, 26365), -- Restoration Buff (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+63, 194082, 607, 4384, 4384, '0', 0, 0, 837.0653076171875, -107.536727905273437, 127.0248489379882812, 4.468043327331542968, 0, 0, -0.7880105972290039, 0.615661680698394775, 7200, 255, 1, 26365), -- Titan Relic (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+64, 184971, 607, 4384, 4384, '0', 0, 0, 978.84503173828125, -3.91769695281982421, 86.71141815185546875, 4.764749526977539062, 0, 0, -0.6883544921875, 0.725374460220336914, 7200, 255, 1, 26365), -- Restoration Buff (Area: Strand of the Ancients - Difficulty: 0) CreateObject1
(@OGUID+65, 194086, 607, 4384, 4610, '0', 0, 0, 1382.0445556640625, 200.5125274658203125, 32.03339004516601562, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject2
(@OGUID+66, 194086, 607, 4384, 4610, '0', 0, 0, 1371.1763916015625, -290.087615966796875, 31.12162208557128906, 4.886923789978027343, 0, 0, -0.64278697967529296, 0.766044974327087402, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject2
(@OGUID+67, 194086, 607, 4384, 4610, '0', 0, 0, 1371.326416015625, -291.328826904296875, 31.13518905639648437, 2.932138919830322265, 0, 0, 0.994521141052246093, 0.104535527527332305, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject2
(@OGUID+68, 194086, 607, 4384, 4610, '0', 0, 0, 1369.612060546875, 196.440887451171875, 30.93598365783691406, 1.308995485305786132, 0, 0, 0.608760833740234375, 0.793353796005249023, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject2
(@OGUID+69, 194086, 607, 4384, 4610, '0', 0, 0, 1371.7508544921875, 193.4837188720703125, 31.72035408020019531, 4.939284324645996093, 0, 0, -0.6225137710571289, 0.78260880708694458, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject2
(@OGUID+70, 194086, 607, 4384, 4610, '0', 0, 0, 1372.196044921875, -289.934783935546875, 31.15232086181640625, 3.857182979583740234, 0, 0, -0.93667125701904296, 0.350209832191467285, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject2
(@OGUID+71, 194086, 607, 4384, 4610, '0', 0, 0, 1334.25048828125, 208.27423095703125, 31.05311775207519531, 3.211419343948364257, 0, 0, -0.9993906021118164, 0.034906134009361267, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject2
(@OGUID+72, 194086, 607, 4384, 4610, '0', 0, 0, 1351.8411865234375, -302.070587158203125, 30.93121719360351562, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject1
(@OGUID+73, 194086, 607, 4384, 4610, '0', 0, 0, 1351.7039794921875, -300.47509765625, 30.93253517150878906, 2.914689540863037109, 0, 0, 0.993571281433105468, 0.113208353519439697, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject1
(@OGUID+74, 194086, 607, 4384, 4610, '0', 0, 0, 1353.1588134765625, -302.80670166015625, 30.93004989624023437, 3.769911527633666992, 0, 0, -0.95105648040771484, 0.309017121791839599, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject1
(@OGUID+75, 194086, 607, 4384, 4610, '0', 0, 0, 1372.4747314453125, -291.149688720703125, 31.17007827758789062, 2.373644113540649414, 0, 0, 0.927183151245117187, 0.37460830807685852, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject2
(@OGUID+76, 194086, 607, 4384, 4610, '0', 0, 0, 1369.4757080078125, 195.703125, 31.49237060546875, 5.183629035949707031, 0, 0, -0.52249813079833984, 0.852640450000762939, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject2
(@OGUID+77, 194086, 607, 4384, 4610, '0', 0, 0, 1387.903076171875, -302.44146728515625, 32.01015472412109375, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject2
(@OGUID+78, 194086, 607, 4384, 4610, '0', 0, 0, 1381.306396484375, 199.453826904296875, 32.03419113159179687, 0.698131442070007324, 0, 0, 0.342020034790039062, 0.939692676067352294, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject2
(@OGUID+79, 194086, 607, 4384, 4610, '0', 0, 0, 1371.920166015625, -290.836822509765625, 31.53046035766601562, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject2
(@OGUID+80, 194086, 607, 4384, 4610, '0', 0, 0, 1368.8038330078125, 196.170135498046875, 30.93807601928710937, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject2
(@OGUID+81, 194086, 607, 4384, 4610, '0', 0, 0, 1333.595458984375, 207.96875, 31.45840835571289062, 5.637413978576660156, 0, 0, -0.31730461120605468, 0.948323667049407958, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject2
(@OGUID+82, 194086, 607, 4384, 4610, '0', 0, 0, 1332.90283203125, 207.6993560791015625, 31.05311775207519531, 0.890116631984710693, 0, 0, 0.430510520935058593, 0.902585566043853759, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject2
(@OGUID+83, 194086, 607, 4384, 4610, '0', 0, 0, 1370.9813232421875, 192.559112548828125, 31.79929924011230468, 0.296705186367034912, 0, 0, 0.147809028625488281, 0.989015936851501464, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject2
(@OGUID+84, 194086, 607, 4384, 4610, '0', 0, 0, 1369.0833740234375, 195.1527862548828125, 31.14234161376953125, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject2
(@OGUID+85, 194086, 607, 4384, 4610, '0', 0, 0, 1334.2291259765625, 207.254913330078125, 31.05311775207519531, 0.226892471313476562, 0, 0, 0.113203048706054687, 0.993571877479553222, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject2
(@OGUID+86, 194086, 607, 4384, 4610, '0', 0, 0, 1370.005615234375, 195.1426544189453125, 31.14361572265625, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject2
(@OGUID+87, 194086, 607, 4384, 4610, '0', 0, 0, 1388.996337890625, -305.631134033203125, 32.00703811645507812, 1.082102894783020019, 0, 0, 0.51503753662109375, 0.857167601585388183, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject2
(@OGUID+88, 194086, 607, 4384, 4610, '0', 0, 0, 1333.1927490234375, 208.685760498046875, 31.05311775207519531, 1.134462952613830566, 0, 0, 0.537299156188964843, 0.843391716480255126, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject2
(@OGUID+89, 194086, 607, 4384, 4610, '0', 0, 0, 1340.3341064453125, -304.763031005859375, 30.94291114807128906, 1.832594871520996093, 0, 0, 0.793353080749511718, 0.608761727809906005, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject1
(@OGUID+90, 194086, 607, 4384, 4610, '0', 0, 0, 1352.459228515625, -299.62786865234375, 30.91556167602539062, 4.939284324645996093, 0, 0, -0.6225137710571289, 0.78260880708694458, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject1
(@OGUID+91, 194086, 607, 4384, 4610, '0', 0, 0, 1388.6258544921875, -306.84710693359375, 31.92926025390625, 5.881760597229003906, 0, 0, -0.19936752319335937, 0.979924798011779785, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject1
(@OGUID+92, 194086, 607, 4384, 4610, '0', 0, 0, 1338.5098876953125, -301.94573974609375, 30.92713165283203125, 0.907570242881774902, 0, 0, 0.438370704650878906, 0.898794233798980712, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject1
(@OGUID+93, 194086, 607, 4384, 4610, '0', 0, 0, 1352.8428955078125, -301.219879150390625, 30.91541290283203125, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Landing Beach - Difficulty: 0) CreateObject1
(@OGUID+94, 191307, 607, 4384, 4610, '0', 0, 0, 1324.9149169921875, 17.94270896911621093, 31.112274169921875, 1.518436193466186523, 0, 0, 0.6883544921875, 0.725374460220336914, 7200, 255, 1, 26365), -- Horde Banner (Area: Landing Beach - Difficulty: 0) CreateObject2
(@OGUID+95, 191305, 607, 4384, 0, '0', 0, 0, 1338.859375, -153.328125, 30.90636825561523437, 3.752462387084960937, 0, 0, -0.95371627807617187, 0.300707906484603881, 7200, 255, 1, 26365), -- Horde Banner (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+96, 194086, 607, 4384, 4604, '0', 0, 0, 1097.5465087890625, 0.440429985523223876, 70.55162811279296875, 1.308995485305786132, 0, 0, 0.608760833740234375, 0.793353796005249023, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+97, 194086, 607, 4384, 4604, '0', 0, 0, 1096.2410888671875, -6.24359798431396484, 70.74053192138671875, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+98, 194086, 607, 4384, 4604, '0', 0, 0, 1097.0347900390625, -5.79861116409301757, 71.16420745849609375, 5.183629035949707031, 0, 0, -0.52249813079833984, 0.852640450000762939, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+99, 194086, 607, 4384, 4604, '0', 0, 0, 1095.6646728515625, -4.72450113296508789, 70.6829681396484375, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+100, 194086, 607, 4384, 4604, '0', 0, 0, 1097.5640869140625, -6.35991811752319335, 70.72601318359375, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+101, 194086, 607, 4384, 4604, '0', 0, 0, 1099.794677734375, -8.88986587524414062, 70.96112823486328125, 0.296705186367034912, 0, 0, 0.147809028625488281, 0.989015936851501464, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+102, 194086, 607, 4384, 4604, '0', 0, 0, 1097.171630859375, -5.06130599975585937, 70.6573333740234375, 1.308995485305786132, 0, 0, 0.608760833740234375, 0.793353796005249023, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+103, 194086, 607, 4384, 4604, '0', 0, 0, 1097.4097900390625, -0.296875, 70.756134033203125, 5.183629035949707031, 0, 0, -0.52249813079833984, 0.852640450000762939, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+104, 194086, 607, 4384, 4604, '0', 0, 0, 1096.6158447265625, -0.74186199903488159, 70.3299560546875, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+105, 194086, 607, 4384, 4604, '0', 0, 0, 1098.5396728515625, -8.94325065612792968, 70.92966461181640625, 0.296705186367034912, 0, 0, 0.147809028625488281, 0.989015936851501464, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+106, 194086, 607, 4384, 4604, '0', 0, 0, 1100.5638427734375, -7.96451807022094726, 70.8386077880859375, 4.939284324645996093, 0, 0, -0.6225137710571289, 0.78260880708694458, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+107, 194086, 607, 4384, 4604, '0', 0, 0, 1096.03955078125, 0.777234971523284912, 70.26041412353515625, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+108, 194086, 607, 4384, 4604, '0', 0, 0, 1097.9388427734375, -0.85818099975585937, 70.29022216796875, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+109, 194086, 607, 4384, 4604, '0', 0, 0, 1099.308837890625, -8.01790332794189453, 70.861785888671875, 4.939284324645996093, 0, 0, -0.6225137710571289, 0.78260880708694458, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+110, 191309, 607, 4384, 0, '0', 0, 0, 1215.1080322265625, -65.7157669067382812, 70.08426666259765625, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 7200, 255, 1, 26365), -- Horde Banner (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+111, 194086, 607, 4384, 0, '0', 0, 0, 971.6640625, 2.423177003860473632, 86.873138427734375, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+112, 194086, 607, 4384, 0, '0', 0, 0, 983.1600341796875, 8.073621749877929687, 86.890838623046875, 5.35816192626953125, 0, 0, -0.446197509765625, 0.894934535026550292, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+113, 194086, 607, 4384, 0, '0', 0, 0, 979.0225830078125, 3.528320074081420898, 86.7908935546875, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+114, 194086, 607, 4384, 0, '0', 0, 0, 969.76031494140625, 1.590602993965148925, 86.92884063720703125, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+115, 194086, 607, 4384, 0, '0', 0, 0, 969.60723876953125, 4.697156906127929687, 87.01064300537109375, 3.176533222198486328, 0, 0, -0.999847412109375, 0.017469281330704689, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+116, 194086, 607, 4384, 0, '0', 0, 0, 967.73394775390625, 3.980143070220947265, 87.09085845947265625, 0.24434557557106018, 0, 0, 0.121869087219238281, 0.9925462007522583, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+117, 194086, 607, 4384, 0, '0', 0, 0, 982.3564453125, 7.541720867156982421, 86.8763427734375, 3.647741317749023437, 0, 0, -0.96814727783203125, 0.250381410121917724, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+118, 194086, 607, 4384, 0, '0', 0, 0, 980.4063720703125, 3.43174910545349121, 86.7923126220703125, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+119, 194086, 607, 4384, 0, '0', 0, 0, 978.9600830078125, 4.175346851348876953, 87.13205718994140625, 0.24434557557106018, 0, 0, 0.121869087219238281, 0.9925462007522583, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+120, 194086, 607, 4384, 0, '0', 0, 0, 969.00469970703125, 3.825195074081420898, 87.01322174072265625, 0.24434557557106018, 0, 0, 0.121869087219238281, 0.9925462007522583, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+121, 194086, 607, 4384, 0, '0', 0, 0, 984.1199951171875, 7.510850906372070312, 86.8842620849609375, 4.956737518310546875, 0, 0, -0.61566066741943359, 0.788011372089385986, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+122, 194086, 607, 4384, 0, '0', 0, 0, 983.7569580078125, 6.909721851348876953, 86.87149810791015625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+123, 194086, 607, 4384, 0, '0', 0, 0, 971.24578857421875, 4.677463054656982421, 86.91996002197265625, 0.24434557557106018, 0, 0, 0.121869087219238281, 0.9925462007522583, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+124, 194086, 607, 4384, 0, '0', 0, 0, 968.374267578125, 5.152668952941894531, 87.101043701171875, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+125, 194086, 607, 4384, 0, '0', 0, 0, 973.1192626953125, 5.39442300796508789, 86.89000701904296875, 3.176533222198486328, 0, 0, -0.999847412109375, 0.017469281330704689, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+126, 194086, 607, 4384, 0, '0', 0, 0, 983.10382080078125, 6.336967945098876953, 86.85764312744140625, 4.782202720642089843, 0, 0, -0.68199825286865234, 0.731353819370269775, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+127, 194086, 607, 4384, 0, '0', 0, 0, 968.857666015625, 4.553820133209228515, 87.48282623291015625, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+128, 194086, 607, 4384, 0, '0', 0, 0, 971.82989501953125, 5.217013835906982421, 86.916534423828125, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+129, 194086, 607, 4384, 0, '0', 0, 0, 978.5242919921875, 4.972221851348876953, 86.8182373046875, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+130, 194086, 607, 4384, 0, '0', 0, 0, 978.38714599609375, 3.9375, 86.80107879638671875, 0.24434557557106018, 0, 0, 0.121869087219238281, 0.9925462007522583, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+131, 194086, 607, 4384, 0, '0', 0, 0, 979.53643798828125, 4.822916984558105468, 86.8144378662109375, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+132, 194086, 607, 4384, 0, '0', 0, 0, 972.69317626953125, 3.93375706672668457, 86.871551513671875, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+133, 194086, 607, 4384, 0, '0', 0, 0, 983.1875, 7.192708015441894531, 87.170013427734375, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+134, 208000, 607, 4384, 0, '0', 0, 0, 2679.69677734375, -826.8912353515625, 3.7127685546875, 5.719419479370117187, 0, 0, -0.27816486358642578, 0.960533320903778076, 7200, 255, 25, 26365), -- The Graceful Maiden (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+135, 193185, 607, 4384, 0, '0', 0, 0, 2574.003662109375, 981.261474609375, 2.60333251953125, 0.807695746421813964, 0, 0, 0.3929595947265625, 0.919555723667144775, 7200, 255, 25, 26365), -- The Frostbreaker (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+136, 194083, 607, 4384, 0, '0', 0, 0, 837.0653076171875, -107.536727905273437, 127.0248489379882812, 4.468043327331542968, 0, 0, -0.7880105972290039, 0.615661680698394775, 7200, 255, 1, 26365), -- Titan Relic (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+137, 190753, 607, 4384, 0, '0', 0, 0, 1588.3658447265625, 36.28743362426757812, 7.376103878021240234, 5.044002056121826171, 0, 0, -0.58070278167724609, 0.814115643501281738, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+138, 190753, 607, 4384, 0, '0', 0, 0, 1598.511474609375, 36.18088150024414062, 7.37793588638305664, 4.799657344818115234, 0, 0, -0.67558956146240234, 0.737277925014495849, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+139, 190753, 607, 4384, 0, '0', 0, 0, 1439.765625, -59.7795143127441406, 5.413985252380371093, 5.026549339294433593, 0, 0, -0.5877847671508789, 0.809017360210418701, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+140, 190753, 607, 4384, 0, '0', 0, 0, 1593.9642333984375, -96.168731689453125, 8.782253265380859375, 5.148722648620605468, 0, 0, -0.53729915618896484, 0.843391716480255126, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+141, 190753, 607, 4384, 0, '0', 0, 0, 1581.2027587890625, -99.4962005615234375, 8.337002754211425781, 5.567600727081298828, 0, 0, -0.35020732879638671, 0.936672210693359375, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+142, 190753, 607, 4384, 0, '0', 0, 0, 1440.63720703125, -45.4427070617675781, 5.888772964477539062, 3.036838293075561523, 0, 0, 0.998628616333007812, 0.052353221923112869, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+143, 190753, 607, 4384, 0, '0', 0, 0, 1438.7379150390625, -59.9583320617675781, 5.371419429779052734, 3.717553615570068359, 0, 0, -0.95881938934326171, 0.284016460180282592, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+144, 190753, 607, 4384, 0, '0', 0, 0, 1596.1759033203125, 36.333984375, 7.345334053039550781, 3.769911527633666992, 0, 0, -0.95105648040771484, 0.309017121791839599, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+145, 190753, 607, 4384, 0, '0', 0, 0, 1439.30908203125, -60.9479179382324218, 5.210583209991455078, 3.490667104721069335, 0, 0, -0.98480701446533203, 0.173652306199073791, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+146, 190753, 607, 4384, 0, '0', 0, 0, 1339.18896484375, -303.45263671875, 30.907958984375, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+147, 190753, 607, 4384, 0, '0', 0, 0, 1584.1591796875, -92.271484375, 8.347928047180175781, 2.862335443496704101, 0, 0, 0.990267753601074218, 0.139175355434417724, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+148, 190753, 607, 4384, 0, '0', 0, 0, 1597.704833984375, 37.00347137451171875, 7.80081796646118164, 4.572763919830322265, 0, 0, -0.75470924377441406, 0.656059443950653076, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+149, 190753, 607, 4384, 0, '0', 0, 0, 1582.967041015625, -92.590606689453125, 8.353337287902832031, 5.009094715118408203, 0, 0, -0.59482288360595703, 0.80385679006576538, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+150, 190753, 607, 4384, 0, '0', 0, 0, 1591.729736328125, 47.05099868774414062, 7.381677150726318359, 2.862335443496704101, 0, 0, 0.990267753601074218, 0.139175355434417724, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+151, 190753, 607, 4384, 0, '0', 0, 0, 1583.354736328125, -91.1810989379882812, 8.356536865234375, 1.675513744354248046, 0, 0, 0.743144035339355468, 0.669131457805633544, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+152, 190753, 607, 4384, 0, '0', 0, 0, 1434.9444580078125, -52.5972213745117187, 5.692234992980957031, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+153, 190753, 607, 4384, 0, '0', 0, 0, 1435.5086669921875, -53.453125, 5.804205894470214843, 4.118979454040527343, 0, 0, -0.88294696807861328, 0.469472706317901611, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+154, 190753, 607, 4384, 0, '0', 0, 0, 1435.4757080078125, -51.8454856872558593, 5.790664196014404296, 2.792518377304077148, 0, 0, 0.984807014465332031, 0.173652306199073791, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+155, 190753, 607, 4384, 0, '0', 0, 0, 1589.41064453125, 35.65158462524414062, 7.353652000427246093, 0.401424884796142578, 0, 0, 0.199367523193359375, 0.979924798011779785, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+156, 190753, 607, 4384, 0, '0', 0, 0, 1584.295166015625, -103.916656494140625, 9.069079399108886718, 2.967041015625, 0, 0, 0.996193885803222656, 0.087165042757987976, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+157, 190753, 607, 4384, 0, '0', 0, 0, 1440.8489990234375, -44.5815963745117187, 5.729386329650878906, 2.984498262405395507, 0, 0, 0.996916770935058593, 0.078466430306434631, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+158, 190753, 607, 4384, 0, '0', 0, 0, 1584.4390869140625, -103.336906433105468, 8.502038002014160156, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+159, 190753, 607, 4384, 0, '0', 0, 0, 1592.642578125, 46.12369918823242187, 7.403531074523925781, 3.961898565292358398, 0, 0, -0.91705989837646484, 0.398749500513076782, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+160, 190753, 607, 4384, 0, '0', 0, 0, 1593.08740234375, 47.30522918701171875, 7.410294055938720703, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+161, 190753, 607, 4384, 0, '0', 0, 0, 1594.7999267578125, 47.51573562622070312, 7.569773197174072265, 4.520402908325195312, 0, 0, -0.77162456512451171, 0.636078238487243652, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+162, 190753, 607, 4384, 0, '0', 0, 0, 1588.6461181640625, 34.91232681274414062, 7.436020851135253906, 0.663223206996917724, 0, 0, 0.325567245483398437, 0.945518851280212402, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+163, 190753, 607, 4384, 0, '0', 0, 0, 1597.0955810546875, 37.20963668823242187, 7.371291160583496093, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+164, 190753, 607, 4384, 0, '0', 0, 0, 1435.7760009765625, -52.8541679382324218, 5.859138011932373046, 4.677483558654785156, 0, 0, -0.71933937072753906, 0.694658815860748291, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+165, 190753, 607, 4384, 0, '0', 0, 0, 1583.457275390625, -104.075088500976562, 8.451749801635742187, 4.625123500823974609, 0, 0, -0.73727703094482421, 0.67559051513671875, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+166, 190753, 607, 4384, 0, '0', 0, 0, 1598.3648681640625, 37.421875, 7.396986007690429687, 5.969027042388916015, 0, 0, -0.1564340591430664, 0.987688362598419189, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+167, 190753, 607, 4384, 0, '0', 0, 0, 1594.083251953125, 46.61653518676757812, 7.441329002380371093, 4.572763919830322265, 0, 0, -0.75470924377441406, 0.656059443950653076, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+168, 190753, 607, 4384, 0, '0', 0, 0, 1585.013916015625, -104.328132629394531, 8.6132049560546875, 0.401424884796142578, 0, 0, 0.199367523193359375, 0.979924798011779785, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+169, 190753, 607, 4384, 0, '0', 0, 0, 1581.9661865234375, -100.925033569335937, 8.327397346496582031, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+170, 190753, 607, 4384, 0, '0', 0, 0, 1441.3992919921875, -45.09375, 5.82074594497680664, 4.799657344818115234, 0, 0, -0.67558956146240234, 0.737277925014495849, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+171, 190753, 607, 4384, 0, '0', 0, 0, 1583.673583984375, -91.875, 8.890683174133300781, 2.984498262405395507, 0, 0, 0.996916770935058593, 0.078466430306434631, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+172, 190753, 607, 4384, 0, '0', 0, 0, 1440, -44.734375, 5.762050151824951171, 3.43830275535583496, 0, 0, -0.98901557922363281, 0.147811368107795715, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+173, 190763, 607, 4384, 0, '0', 0, 0, 1467.954833984375, -225.829864501953125, 30.96954727172851562, 3.874631166458129882, 0, 0, -0.93358039855957031, 0.358368009328842163, 7200, 255, 1, 26365), -- Defender's Portal (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+174, 190763, 607, 4384, 0, '0', 0, 0, 1394.23681640625, 72.10178375244140625, 31.10579109191894531, 5.724681377410888671, 0, 0, -0.27563667297363281, 0.961261868476867675, 7200, 255, 1, 26365), -- Defender's Portal (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+175, 190763, 607, 4384, 0, '0', 0, 0, 1255.875, -233.723953247070312, 56.49681472778320312, 5.811946868896484375, 0, 0, -0.2334451675415039, 0.972369968891143798, 7200, 255, 1, 26365), -- Defender's Portal (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+176, 190763, 607, 4384, 0, '0', 0, 0, 1065.2412109375, -89.75341796875, 81.00298309326171875, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 7200, 255, 1, 26365), -- Defender's Portal (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+177, 190763, 607, 4384, 0, '0', 0, 0, 1216.0625, 47.546875, 54.34365081787109375, 4.45059061050415039, 0, 0, -0.79335308074951171, 0.608761727809906005, 7200, 255, 1, 26365), -- Defender's Portal (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+178, 190753, 607, 4384, 0, '0', 0, 0, 1334.25048828125, 208.27423095703125, 31.05311775207519531, 3.211419343948364257, 0, 0, -0.9993906021118164, 0.034906134009361267, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+179, 190753, 607, 4384, 0, '0', 0, 0, 1371.7508544921875, 193.4837188720703125, 31.72035408020019531, 4.939284324645996093, 0, 0, -0.6225137710571289, 0.78260880708694458, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+180, 190753, 607, 4384, 0, '0', 0, 0, 1370.005615234375, 195.1426544189453125, 31.14361572265625, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+181, 190753, 607, 4384, 0, '0', 0, 0, 1369.0833740234375, 195.1527862548828125, 31.14234161376953125, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+182, 190753, 607, 4384, 0, '0', 0, 0, 1370.9813232421875, 192.559112548828125, 31.79929924011230468, 0.296705186367034912, 0, 0, 0.147809028625488281, 0.989015936851501464, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+183, 190753, 607, 4384, 0, '0', 0, 0, 1334.2291259765625, 207.254913330078125, 31.05311775207519531, 0.226892471313476562, 0, 0, 0.113203048706054687, 0.993571877479553222, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+184, 190753, 607, 4384, 0, '0', 0, 0, 1368.8038330078125, 196.170135498046875, 30.93807601928710937, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+185, 190753, 607, 4384, 0, '0', 0, 0, 1333.1927490234375, 208.685760498046875, 31.05311775207519531, 1.134462952613830566, 0, 0, 0.537299156188964843, 0.843391716480255126, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+186, 190753, 607, 4384, 0, '0', 0, 0, 1333.595458984375, 207.96875, 31.45840835571289062, 5.637413978576660156, 0, 0, -0.31730461120605468, 0.948323667049407958, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+187, 190753, 607, 4384, 0, '0', 0, 0, 1369.612060546875, 196.440887451171875, 30.93598365783691406, 1.308995485305786132, 0, 0, 0.608760833740234375, 0.793353796005249023, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+188, 190753, 607, 4384, 0, '0', 0, 0, 1381.306396484375, 199.453826904296875, 32.03419113159179687, 0.698131442070007324, 0, 0, 0.342020034790039062, 0.939692676067352294, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+189, 190753, 607, 4384, 0, '0', 0, 0, 1369.4757080078125, 195.703125, 31.49237060546875, 5.183629035949707031, 0, 0, -0.52249813079833984, 0.852640450000762939, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+190, 190753, 607, 4384, 0, '0', 0, 0, 1382.0445556640625, 200.5125274658203125, 32.03339004516601562, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+191, 190753, 607, 4384, 0, '0', 0, 0, 1332.90283203125, 207.6993560791015625, 31.05311775207519531, 0.890116631984710693, 0, 0, 0.430510520935058593, 0.902585566043853759, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+192, 190753, 607, 4384, 0, '0', 0, 0, 1351.8411865234375, -302.070587158203125, 30.93121719360351562, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+193, 190753, 607, 4384, 0, '0', 0, 0, 1388.6258544921875, -306.84710693359375, 31.92926025390625, 5.881760597229003906, 0, 0, -0.19936752319335937, 0.979924798011779785, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+194, 190753, 607, 4384, 0, '0', 0, 0, 1352.8428955078125, -301.219879150390625, 30.91541290283203125, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+195, 190753, 607, 4384, 0, '0', 0, 0, 1387.903076171875, -302.44146728515625, 32.01015472412109375, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+196, 190753, 607, 4384, 0, '0', 0, 0, 1351.7039794921875, -300.47509765625, 30.93253517150878906, 2.914689540863037109, 0, 0, 0.993571281433105468, 0.113208353519439697, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+197, 190753, 607, 4384, 0, '0', 0, 0, 1372.196044921875, -289.934783935546875, 31.15232086181640625, 3.857182979583740234, 0, 0, -0.93667125701904296, 0.350209832191467285, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+198, 190753, 607, 4384, 0, '0', 0, 0, 1353.1588134765625, -302.80670166015625, 30.93004989624023437, 3.769911527633666992, 0, 0, -0.95105648040771484, 0.309017121791839599, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+199, 190753, 607, 4384, 0, '0', 0, 0, 1388.996337890625, -305.631134033203125, 32.00703811645507812, 1.082102894783020019, 0, 0, 0.51503753662109375, 0.857167601585388183, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+200, 190753, 607, 4384, 0, '0', 0, 0, 1340.3341064453125, -304.763031005859375, 30.94291114807128906, 1.832594871520996093, 0, 0, 0.793353080749511718, 0.608761727809906005, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+201, 190753, 607, 4384, 0, '0', 0, 0, 1352.459228515625, -299.62786865234375, 30.91556167602539062, 4.939284324645996093, 0, 0, -0.6225137710571289, 0.78260880708694458, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+202, 190753, 607, 4384, 0, '0', 0, 0, 1371.920166015625, -290.836822509765625, 31.53046035766601562, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+203, 190753, 607, 4384, 0, '0', 0, 0, 1371.326416015625, -291.328826904296875, 31.13518905639648437, 2.932138919830322265, 0, 0, 0.994521141052246093, 0.104535527527332305, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+204, 190753, 607, 4384, 0, '0', 0, 0, 1371.1763916015625, -290.087615966796875, 31.12162208557128906, 4.886923789978027343, 0, 0, -0.64278697967529296, 0.766044974327087402, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+205, 190753, 607, 4384, 0, '0', 0, 0, 1338.5098876953125, -301.94573974609375, 30.92713165283203125, 0.907570242881774902, 0, 0, 0.438370704650878906, 0.898794233798980712, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+206, 190753, 607, 4384, 0, '0', 0, 0, 1372.4747314453125, -291.149688720703125, 31.17007827758789062, 2.373644113540649414, 0, 0, 0.927183151245117187, 0.37460830807685852, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1

(@OGUID+207, 190753, 607, 4384, 4604, '0', 0, 0, 1097.5465087890625, 0.440429985523223876, 70.55162811279296875, 1.308995485305786132, 0, 0, 0.608760833740234375, 0.793353796005249023, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+208, 190753, 607, 4384, 4604, '0', 0, 0, 1096.2410888671875, -6.24359798431396484, 70.74053192138671875, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+209, 190753, 607, 4384, 4604, '0', 0, 0, 1097.0347900390625, -5.79861116409301757, 71.16420745849609375, 5.183629035949707031, 0, 0, -0.52249813079833984, 0.852640450000762939, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+210, 190753, 607, 4384, 4604, '0', 0, 0, 1095.6646728515625, -4.72450113296508789, 70.6829681396484375, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+211, 190753, 607, 4384, 4604, '0', 0, 0, 1097.5640869140625, -6.35991811752319335, 70.72601318359375, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+212, 190753, 607, 4384, 4604, '0', 0, 0, 1099.794677734375, -8.88986587524414062, 70.96112823486328125, 0.296705186367034912, 0, 0, 0.147809028625488281, 0.989015936851501464, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+213, 190753, 607, 4384, 4604, '0', 0, 0, 1097.171630859375, -5.06130599975585937, 70.6573333740234375, 1.308995485305786132, 0, 0, 0.608760833740234375, 0.793353796005249023, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+214, 190753, 607, 4384, 4604, '0', 0, 0, 1097.4097900390625, -0.296875, 70.756134033203125, 5.183629035949707031, 0, 0, -0.52249813079833984, 0.852640450000762939, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+215, 190753, 607, 4384, 4604, '0', 0, 0, 1096.6158447265625, -0.74186199903488159, 70.3299560546875, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+216, 190753, 607, 4384, 4604, '0', 0, 0, 1098.5396728515625, -8.94325065612792968, 70.92966461181640625, 0.296705186367034912, 0, 0, 0.147809028625488281, 0.989015936851501464, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+217, 190753, 607, 4384, 4604, '0', 0, 0, 1100.5638427734375, -7.96451807022094726, 70.8386077880859375, 4.939284324645996093, 0, 0, -0.6225137710571289, 0.78260880708694458, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+218, 190753, 607, 4384, 4604, '0', 0, 0, 1096.03955078125, 0.777234971523284912, 70.26041412353515625, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+219, 190753, 607, 4384, 4604, '0', 0, 0, 1097.9388427734375, -0.85818099975585937, 70.29022216796875, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2
(@OGUID+220, 190753, 607, 4384, 4604, '0', 0, 0, 1099.308837890625, -8.01790332794189453, 70.861785888671875, 4.939284324645996093, 0, 0, -0.6225137710571289, 0.78260880708694458, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: Gate of the Red Sun - Difficulty: 0) CreateObject2

(@OGUID+221, 190753, 607, 4384, 0, '0', 0, 0, 971.6640625, 2.423177003860473632, 86.873138427734375, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+222, 190753, 607, 4384, 0, '0', 0, 0, 983.1600341796875, 8.073621749877929687, 86.890838623046875, 5.35816192626953125, 0, 0, -0.446197509765625, 0.894934535026550292, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+223, 190753, 607, 4384, 0, '0', 0, 0, 979.0225830078125, 3.528320074081420898, 86.7908935546875, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+224, 190753, 607, 4384, 0, '0', 0, 0, 969.76031494140625, 1.590602993965148925, 86.92884063720703125, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+225, 190753, 607, 4384, 0, '0', 0, 0, 969.60723876953125, 4.697156906127929687, 87.01064300537109375, 3.176533222198486328, 0, 0, -0.999847412109375, 0.017469281330704689, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+226, 190753, 607, 4384, 0, '0', 0, 0, 967.73394775390625, 3.980143070220947265, 87.09085845947265625, 0.24434557557106018, 0, 0, 0.121869087219238281, 0.9925462007522583, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+227, 190753, 607, 4384, 0, '0', 0, 0, 982.3564453125, 7.541720867156982421, 86.8763427734375, 3.647741317749023437, 0, 0, -0.96814727783203125, 0.250381410121917724, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+228, 190753, 607, 4384, 0, '0', 0, 0, 980.4063720703125, 3.43174910545349121, 86.7923126220703125, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+229, 190753, 607, 4384, 0, '0', 0, 0, 978.9600830078125, 4.175346851348876953, 87.13205718994140625, 0.24434557557106018, 0, 0, 0.121869087219238281, 0.9925462007522583, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+230, 190753, 607, 4384, 0, '0', 0, 0, 969.00469970703125, 3.825195074081420898, 87.01322174072265625, 0.24434557557106018, 0, 0, 0.121869087219238281, 0.9925462007522583, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+231, 190753, 607, 4384, 0, '0', 0, 0, 984.1199951171875, 7.510850906372070312, 86.8842620849609375, 4.956737518310546875, 0, 0, -0.61566066741943359, 0.788011372089385986, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+232, 190753, 607, 4384, 0, '0', 0, 0, 983.7569580078125, 6.909721851348876953, 86.87149810791015625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+233, 190753, 607, 4384, 0, '0', 0, 0, 971.24578857421875, 4.677463054656982421, 86.91996002197265625, 0.24434557557106018, 0, 0, 0.121869087219238281, 0.9925462007522583, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+234, 190753, 607, 4384, 0, '0', 0, 0, 968.374267578125, 5.152668952941894531, 87.101043701171875, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+235, 190753, 607, 4384, 0, '0', 0, 0, 973.1192626953125, 5.39442300796508789, 86.89000701904296875, 3.176533222198486328, 0, 0, -0.999847412109375, 0.017469281330704689, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+236, 190753, 607, 4384, 0, '0', 0, 0, 983.10382080078125, 6.336967945098876953, 86.85764312744140625, 4.782202720642089843, 0, 0, -0.68199825286865234, 0.731353819370269775, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+237, 190753, 607, 4384, 0, '0', 0, 0, 968.857666015625, 4.553820133209228515, 87.48282623291015625, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+238, 190753, 607, 4384, 0, '0', 0, 0, 971.82989501953125, 5.217013835906982421, 86.916534423828125, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+239, 190753, 607, 4384, 0, '0', 0, 0, 978.5242919921875, 4.972221851348876953, 86.8182373046875, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+240, 190753, 607, 4384, 0, '0', 0, 0, 978.38714599609375, 3.9375, 86.80107879638671875, 0.24434557557106018, 0, 0, 0.121869087219238281, 0.9925462007522583, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+241, 190753, 607, 4384, 0, '0', 0, 0, 979.53643798828125, 4.822916984558105468, 86.8144378662109375, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+242, 190753, 607, 4384, 0, '0', 0, 0, 972.69317626953125, 3.93375706672668457, 86.871551513671875, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 7200, 255, 1, 26365), -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+243, 190753, 607, 4384, 0, '0', 0, 0, 983.1875, 7.192708015441894531, 87.170013427734375, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 7200, 255, 1, 26365); -- Seaforium Bomb (Area: 0 - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+350;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0, 0, 0, 0), -- Gate of the Purple Amethyst
(@OGUID+1, 0, 0, 0, 0, 0, 0), -- Gate of the Green Emerald
(@OGUID+2, 0, 0, 1, -0.00000004371138828, 0, 0), -- The Coffin Carrier
(@OGUID+3, 0, 0, 0, 0, 0, 0), -- Gate of the Blue Sapphire
(@OGUID+4, 0, 0, 0, 0, 0, 0), -- Gate of the Yellow Moon
(@OGUID+5, 0, 0, 0, 0, 0, 0), -- Gate of the Red Sun
(@OGUID+6, 0, 0, 0, 0, 0, 0), -- Chamber of Ancient Relics
(@OGUID+7, 0, 0, 1, -0.00000004371138828, 0, 0), -- The Blightbringer
(@OGUID+8, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+9, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+10, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+11, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+12, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+13, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+14, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+15, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+16, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+17, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+18, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+19, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+20, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+21, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+22, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+23, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+24, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+25, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+26, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+27, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+29, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+30, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+31, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+32, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+33, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+34, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+35, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+36, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+37, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+38, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+39, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+40, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+41, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+42, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+43, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+44, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+47, 0, 0, 0.005299568176269531, 0.999985933303833007, 0, 0), -- Doodad_WG_Keep_Door01_collision01
(@OGUID+65, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+66, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+67, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+68, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+69, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+70, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+71, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+72, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+73, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+74, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+75, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+76, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+77, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+78, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+79, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+80, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+81, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+82, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+83, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+84, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+85, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+86, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+87, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+88, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+89, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+90, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+91, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+92, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+93, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+96, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+97, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+98, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+99, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+100, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+101, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+102, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+103, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+104, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+105, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+106, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+107, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+108, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+109, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+111, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+112, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+113, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+114, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+115, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+116, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+117, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+118, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+119, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+120, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+121, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+122, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+123, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+124, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+125, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+126, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+127, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+128, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+129, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+130, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+131, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+132, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+133, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+134, 0, 0, 1, -0.00000004371138828, 0, 0), -- The Graceful Maiden
(@OGUID+135, 0, 0, 1, -0.00000004371138828, 0, 0), -- The Frostbreaker
(@OGUID+137, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+138, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+139, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+140, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+141, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+142, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+143, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+144, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+145, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+146, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+147, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+148, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+149, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+150, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+151, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+152, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+153, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+154, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+155, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+156, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+157, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+158, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+159, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+160, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+161, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+162, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+163, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+164, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+165, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+166, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+167, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+168, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+169, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+170, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+171, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+172, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+178, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+179, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+180, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+181, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+182, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+183, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+184, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+185, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+186, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+187, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+188, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+189, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+190, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+191, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+192, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+193, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+194, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+195, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+196, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+197, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+198, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+199, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+200, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+201, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+202, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+203, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+204, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+205, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+206, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+207, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+208, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+209, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+210, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+211, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+212, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+213, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+214, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+215, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+216, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+217, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+218, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+219, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+220, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+221, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+222, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+223, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+224, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+225, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+226, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+227, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+228, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+229, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+230, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+231, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+232, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+233, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+234, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+235, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+236, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+237, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+238, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+239, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+240, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+241, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+242, 0, 0, 0, 1, 569, 0), -- Seaforium Bomb
(@OGUID+243, 0, 0, 0, 1, 569, 0); -- Seaforium Bomb

UPDATE `gameobject_template` SET `ScriptName` = 'go_sota_capturable_object' WHERE `entry` IN (191305, 191306, 191307, 191308, 191309, 191310);
UPDATE `gameobject_template_addon` SET `flags` = `flags`|0x10  WHERE `entry` = 190753;
UPDATE `creature` SET `PhaseId` = 0 WHERE `id` IN (23472, 22515) AND `map` = 607; -- triggers for defender portal, and text
