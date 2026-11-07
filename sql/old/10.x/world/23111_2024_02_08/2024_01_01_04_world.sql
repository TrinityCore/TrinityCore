SET @CGUID := 222720;
SET @OGUID := 166368;
SET @SPAWN_GROUP := 1041;

DELETE FROM `graveyard_zone` WHERE `ID` IN (751, 689, 729, 169, 749, 690, 750, 611, 610);
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(751, 2597, 'Alterac Valley - Storm Aid'),
(689, 2597, 'Alterac Valley - Stormpike'),
(729, 2597, 'Alterac Valley - Stonehearth'),
(169, 2597, 'Alterac Valley - Snowfall'),
(749, 2597, 'Alterac Valley - Iceblood'),
(690, 2597, 'Alterac Valley - Frostowolf'),
(750, 2597, 'Alterac Valley - Frostwolf Hut'),
(611, 2597, 'Alterac Valley - Alliance Base'),
(610, 2597, 'Alterac Valley - Horde Base');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 27 AND `SourceEntry` IN (751, 689, 729, 169, 749, 690, 750, 611, 610);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
-- Bases
-- -- Alliance
(27, 611, 2597, 0, 6, 469, 0, 'Graveyard - Alterac Valley - Alliance Base - Team Alliance'),
(27, 611, 2597, 0, 11, 1325, 0, 'Graveyard - Alterac Valley - Alliance Base - Aid Station NOT Alliance Controlled'),
(27, 611, 2597, 0, 11, 1333, 0, 'Graveyard - Alterac Valley - Alliance Base - Stormpike NOT Alliance Controlled'),
(27, 611, 2597, 0, 11, 1302, 0, 'Graveyard - Alterac Valley - Alliance Base - Stonehearth NOT Alliance Controlled'),
(27, 611, 2597, 0, 11, 1341, 0, 'Graveyard - Alterac Valley - Alliance Base - Snowfall NOT Alliance Controlled'),
(27, 611, 2597, 0, 11, 1346, 0, 'Graveyard - Alterac Valley - Alliance Base - Iceblood NOT Alliance Controlled'),
(27, 611, 2597, 0, 11, 1337, 0, 'Graveyard - Alterac Valley - Alliance Base - Frostwolf NOT Alliance Controlled'),
(27, 611, 2597, 0, 11, 1329, 0, 'Graveyard - Alterac Valley - Alliance Base - Frostwolf Hut NOT Alliance Controlled'),
-- -- Horde
(27, 610, 2597, 0, 6, 67, 0, 'Graveyard - Alterac Valley - Horde Base - Team Horde'),
(27, 610, 2597, 0, 11, 1327, 0, 'Graveyard - Alterac Valley - Horde Base - Aid Station NOT Horde Controlled'),
(27, 610, 2597, 0, 11, 1334, 0, 'Graveyard - Alterac Valley - Horde Base - Stormpike NOT Horde Controlled'),
(27, 610, 2597, 0, 11, 1301, 0, 'Graveyard - Alterac Valley - Horde Base - Stonehearth NOT Horde Controlled'),
(27, 610, 2597, 0, 11, 1342, 0, 'Graveyard - Alterac Valley - Horde Base - Snowfall NOT Horde Controlled'),
(27, 610, 2597, 0, 11, 1347, 0, 'Graveyard - Alterac Valley - Horde Base - Iceblood NOT Horde Controlled'),
(27, 610, 2597, 0, 11, 1338, 0, 'Graveyard - Alterac Valley - Horde Base - Frostwolf NOT Horde Controlled'),
(27, 610, 2597, 0, 11, 1330, 0, 'Graveyard - Alterac Valley - Horde Base - Frostwolf Hut NOT Horde Controlled'),
-- Aid Station
(27, 751, 2597, 0, 6, 469, 0, 'Graveyard - Alterac Valley - Aid Station - Team Alliance'),
(27, 751, 2597, 0, 11, 1325, 1, 'Graveyard - Alterac Valley - Aid Station - Alliance Controlled'),
(27, 751, 2597, 1, 6, 67, 0, 'Graveyard - Alterac Valley - Aid Station - Team Horde'),
(27, 751, 2597, 1, 11, 1327, 1, 'Graveyard - Alterac Valley - Aid Station - Horde Controlled'),
-- Stormpike
(27, 689, 2597, 0, 6, 469, 0, 'Graveyard - Alterac Valley - Stormpike - Team Alliance'),
(27, 689, 2597, 0, 11, 1333, 1, 'Graveyard - Alterac Valley - Stormpike - Alliance Controlled'),
(27, 689, 2597, 1, 6, 67, 0, 'Graveyard - Alterac Valley - Stormpike - Team Horde'),
(27, 689, 2597, 1, 11, 1334, 1, 'Graveyard - Alterac Valley - Stormpike - Horde Controlled'),
-- Stonehearth
(27, 729, 2597, 0, 6, 469, 0, 'Graveyard - Alterac Valley - Stonehearth - Team Alliance'),
(27, 729, 2597, 0, 11, 1302, 1, 'Graveyard - Alterac Valley - Stonehearth - Alliance Controlled'),
(27, 729, 2597, 1, 6, 67, 0, 'Graveyard - Alterac Valley - Stonehearth - Team Horde'),
(27, 729, 2597, 1, 11, 1301, 1, 'Graveyard - Alterac Valley - Stonehearth - Horde Controlled'),
-- Snowfall
(27, 169, 2597, 0, 6, 469, 0, 'Graveyard - Alterac Valley - Snowfall - Team Alliance'),
(27, 169, 2597, 0, 11, 1341, 1, 'Graveyard - Alterac Valley - Snowfall - Alliance Controlled'),
(27, 169, 2597, 1, 6, 67, 0, 'Graveyard - Alterac Valley - Snowfall - Team Horde'),
(27, 169, 2597, 1, 11, 1342, 1, 'Graveyard - Alterac Valley - Snowfall - Horde Controlled'),
-- Iceblood
(27, 749, 2597, 0, 6, 469, 0, 'Graveyard - Alterac Valley - Iceblood - Team Alliance'),
(27, 749, 2597, 0, 11, 1346, 1, 'Graveyard - Alterac Valley - Iceblood - Alliance Controlled'),
(27, 749, 2597, 1, 6, 67, 0, 'Graveyard - Alterac Valley - Iceblood - Team Horde'),
(27, 749, 2597, 1, 11, 1347, 1, 'Graveyard - Alterac Valley - Iceblood - Horde Controlled'),
-- Frostwolf
(27, 690, 2597, 0, 6, 469, 0, 'Graveyard - Alterac Valley - Frostwolf - Team Alliance'),
(27, 690, 2597, 0, 11, 1337, 1, 'Graveyard - Alterac Valley - Frostwolf - Alliance Controlled'),
(27, 690, 2597, 1, 6, 67, 0, 'Graveyard - Alterac Valley - Frostwolf - Team Horde'),
(27, 690, 2597, 1, 11, 1338, 1, 'Graveyard - Alterac Valley - Frostwolf - Horde Controlled'),
-- Frostwolf Hut
(27, 750, 2597, 0, 6, 469, 0, 'Graveyard - Alterac Valley - Frostwolf Hut - Team Alliance'),
(27, 750, 2597, 0, 11, 1329, 1, 'Graveyard - Alterac Valley - Frostwolf Hut - Alliance Controlled'),
(27, 750, 2597, 1, 6, 67, 0, 'Graveyard - Alterac Valley - Frostwolf Hut - Team Horde'),
(27, 750, 2597, 1, 11, 1330, 1, 'Graveyard - Alterac Valley - Frostwolf Hut - Horde Controlled');

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+132;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP+0, 'Alterac Valley - Aid Station - Alliance Controlled', 0x20),
(@SPAWN_GROUP+1, 'Alterac Valley - Aid Station - Alliance Contested', 0x20),
(@SPAWN_GROUP+2, 'Alterac Valley - Aid Station - Horde Controlled', 0x20),
(@SPAWN_GROUP+3, 'Alterac Valley - Aid Station - Horde Contested', 0x20),
(@SPAWN_GROUP+4, 'Alterac Valley - Stormpike - Alliance Controlled', 0x20),
(@SPAWN_GROUP+5, 'Alterac Valley - Stormpike - Alliance Contested', 0x20),
(@SPAWN_GROUP+6, 'Alterac Valley - Stormpike - Horde Controlled', 0x20),
(@SPAWN_GROUP+7, 'Alterac Valley - Stormpike - Horde Contested', 0x20),
(@SPAWN_GROUP+8, 'Alterac Valley - Stonehearth - Alliance Controlled', 0x20),
(@SPAWN_GROUP+9, 'Alterac Valley - Stonehearth - Alliance Contested', 0x20),
(@SPAWN_GROUP+10, 'Alterac Valley - Stonehearth - Horde Controlled', 0x20),
(@SPAWN_GROUP+11, 'Alterac Valley - Stonehearth - Horde Contested', 0x20),
(@SPAWN_GROUP+12, 'Alterac Valley - Snowfall - Neutral Controlled', 0x20),
(@SPAWN_GROUP+13, 'Alterac Valley - Snowfall - Alliance Controlled', 0x20),
(@SPAWN_GROUP+14, 'Alterac Valley - Snowfall - Alliance Contested', 0x20),
(@SPAWN_GROUP+15, 'Alterac Valley - Snowfall - Horde Controlled', 0x20),
(@SPAWN_GROUP+16, 'Alterac Valley - Snowfall - Horde Contested', 0x20),
(@SPAWN_GROUP+17, 'Alterac Valley - Iceblood - Alliance Controlled', 0x20),
(@SPAWN_GROUP+18, 'Alterac Valley - Iceblood - Alliance Contested', 0x20),
(@SPAWN_GROUP+19, 'Alterac Valley - Iceblood - Horde Controlled', 0x20),
(@SPAWN_GROUP+20, 'Alterac Valley - Iceblood - Horde Contested', 0x20),
(@SPAWN_GROUP+21, 'Alterac Valley - Frostwolf - Alliance Controlled', 0x20),
(@SPAWN_GROUP+22, 'Alterac Valley - Frostwolf - Alliance Contested', 0x20),
(@SPAWN_GROUP+23, 'Alterac Valley - Frostwolf - Horde Controlled', 0x20),
(@SPAWN_GROUP+24, 'Alterac Valley - Frostwolf - Horde Contested', 0x20),
(@SPAWN_GROUP+25, 'Alterac Valley - Frostwolf Hut - Alliance Controlled', 0x20),
(@SPAWN_GROUP+26, 'Alterac Valley - Frostwolf Hut - Alliance Contested', 0x20),
(@SPAWN_GROUP+27, 'Alterac Valley - Frostwolf Hut - Horde Controlled', 0x20),
(@SPAWN_GROUP+28, 'Alterac Valley - Frostwolf Hut - Horde Contested', 0x20),

(@SPAWN_GROUP+29, 'Alterac Valley - Aid Station - Alliance Guards', 0x20),
(@SPAWN_GROUP+30, 'Alterac Valley - Aid Station - Horde Guards', 0x20),
(@SPAWN_GROUP+31, 'Alterac Valley - Stormpike - Alliance Guards', 0x20),
(@SPAWN_GROUP+32, 'Alterac Valley - Stormpike - Horde Guards', 0x20),
(@SPAWN_GROUP+33, 'Alterac Valley - Stonehearth - Alliance Guards', 0x20),
(@SPAWN_GROUP+34, 'Alterac Valley - Stonehearth - Horde Guards', 0x20),
(@SPAWN_GROUP+35, 'Alterac Valley - Snowfall - Alliance Guards', 0x20),
(@SPAWN_GROUP+36, 'Alterac Valley - Snowfall - Horde Guards', 0x20),
(@SPAWN_GROUP+37, 'Alterac Valley - Iceblood - Alliance Guards', 0x20),
(@SPAWN_GROUP+38, 'Alterac Valley - Iceblood - Horde Guards', 0x20),
(@SPAWN_GROUP+39, 'Alterac Valley - Frostwolf - Alliance Guards', 0x20),
(@SPAWN_GROUP+40, 'Alterac Valley - Frostwolf - Horde Guards', 0x20),
(@SPAWN_GROUP+41, 'Alterac Valley - Frostwolf Hut - Alliance Guards', 0x20),
(@SPAWN_GROUP+42, 'Alterac Valley - Frostwolf Hut - Horde Guards', 0x20),

(@SPAWN_GROUP+43, 'Alterac Valley - North Bunker - Controlled', 0x20),
(@SPAWN_GROUP+44, 'Alterac Valley - North Bunker - Contested', 0x20),
(@SPAWN_GROUP+45, 'Alterac Valley - North Bunker - Destroyed', 0x20),
(@SPAWN_GROUP+46, 'Alterac Valley - North Bunker - Guards', 0x0),

(@SPAWN_GROUP+47, 'Alterac Valley - South Bunker - Controlled', 0x20),
(@SPAWN_GROUP+48, 'Alterac Valley - South Bunker - Contested', 0x20),
(@SPAWN_GROUP+49, 'Alterac Valley - South Bunker - Destroyed', 0x20),
(@SPAWN_GROUP+50, 'Alterac Valley - South Bunker - Guards', 0x0),

(@SPAWN_GROUP+51, 'Alterac Valley - Icewing Bunker - Controlled', 0x20),
(@SPAWN_GROUP+52, 'Alterac Valley - Icewing Bunker - Contested', 0x20),
(@SPAWN_GROUP+53, 'Alterac Valley - Icewing Bunker - Destroyed', 0x20),
(@SPAWN_GROUP+54, 'Alterac Valley - Icewing Bunker - Guards', 0x0),

(@SPAWN_GROUP+55, 'Alterac Valley - Stonehearth Bunker - Controlled', 0x20),
(@SPAWN_GROUP+56, 'Alterac Valley - Stonehearth Bunker - Contested', 0x20),
(@SPAWN_GROUP+57, 'Alterac Valley - Stonehearth Bunker - Destroyed', 0x20),
(@SPAWN_GROUP+58, 'Alterac Valley - Stonehearth Bunker - Guards', 0x0),

(@SPAWN_GROUP+59, 'Alterac Valley - Iceblood Tower - Controlled', 0x20),
(@SPAWN_GROUP+60, 'Alterac Valley - Iceblood Tower - Contested', 0x20),
(@SPAWN_GROUP+61, 'Alterac Valley - Iceblood Tower - Destroyed', 0x20),
(@SPAWN_GROUP+62, 'Alterac Valley - Iceblood Tower - Guards', 0x0),

(@SPAWN_GROUP+63, 'Alterac Valley - Tower Point - Controlled', 0x20),
(@SPAWN_GROUP+64, 'Alterac Valley - Tower Point - Contested', 0x20),
(@SPAWN_GROUP+65, 'Alterac Valley - Tower Point - Destroyed', 0x20),
(@SPAWN_GROUP+66, 'Alterac Valley - Tower Point - Guards', 0x0),

(@SPAWN_GROUP+67, 'Alterac Valley - East Tower - Controlled', 0x20),
(@SPAWN_GROUP+68, 'Alterac Valley - East Tower - Contested', 0x20),
(@SPAWN_GROUP+69, 'Alterac Valley - East Tower - Destroyed', 0x20),
(@SPAWN_GROUP+70, 'Alterac Valley - East Tower - Guards', 0x0),

(@SPAWN_GROUP+71, 'Alterac Valley - West Tower - Controlled', 0x20),
(@SPAWN_GROUP+72, 'Alterac Valley - West Tower - Contested', 0x20),
(@SPAWN_GROUP+73, 'Alterac Valley - West Tower - Destroyed', 0x20),
(@SPAWN_GROUP+74, 'Alterac Valley - West Tower - Guards', 0x0),

(@SPAWN_GROUP+75, 'Alterac Valley - North Bunker - Marshall', 0x20),
(@SPAWN_GROUP+76, 'Alterac Valley - South Bunker - Marshall', 0x20),
(@SPAWN_GROUP+77, 'Alterac Valley - Icewing Bunker - Marshall', 0x20),
(@SPAWN_GROUP+78, 'Alterac Valley - Stonehearth Bunker - Marshall', 0x20),
(@SPAWN_GROUP+79, 'Alterac Valley - Iceblood Tower - Warmaster', 0x20),
(@SPAWN_GROUP+80, 'Alterac Valley - Tower Point - Warmaster', 0x20),
(@SPAWN_GROUP+81, 'Alterac Valley - East Tower - Warmaster', 0x20),
(@SPAWN_GROUP+82, 'Alterac Valley - West Tower - Warmaster', 0x20),

(@SPAWN_GROUP+83, 'Alterac Valley - Irondeep Mine - Alliance Controlled', 0x0),
(@SPAWN_GROUP+84, 'Alterac Valley - Irondeep Mine - Horde Controlled', 0x0),
(@SPAWN_GROUP+85, 'Alterac Valley - Coldtooth Mine - Alliance Controlled', 0x0),
(@SPAWN_GROUP+86, 'Alterac Valley - Coldtooth Mine - Horde Controlled', 0x0),

-- More graveyard Groups
(@SPAWN_GROUP+87, 'Alterac Valley - Aid Station - Alliance Seasoned Guards', 0x20),
(@SPAWN_GROUP+88, 'Alterac Valley - Aid Station - Horde Seasoned Guards', 0x20),
(@SPAWN_GROUP+89, 'Alterac Valley - Stormpike - Alliance Seasoned Guards', 0x20),
(@SPAWN_GROUP+90, 'Alterac Valley - Stormpike - Horde Seasoned Guards', 0x20),
(@SPAWN_GROUP+91, 'Alterac Valley - Stonehearth - Alliance Seasoned Guards', 0x20),
(@SPAWN_GROUP+92, 'Alterac Valley - Stonehearth - Horde Seasoned Guards', 0x20),
(@SPAWN_GROUP+93, 'Alterac Valley - Snowfall - Alliance Seasoned Guards', 0x20),
(@SPAWN_GROUP+94, 'Alterac Valley - Snowfall - Horde Seasoned Guards', 0x20),
(@SPAWN_GROUP+95, 'Alterac Valley - Iceblood - Alliance Seasoned Guards', 0x20),
(@SPAWN_GROUP+96, 'Alterac Valley - Iceblood - Horde Seasoned Guards', 0x20),
(@SPAWN_GROUP+97, 'Alterac Valley - Frostwolf - Alliance Seasoned Guards', 0x20),
(@SPAWN_GROUP+98, 'Alterac Valley - Frostwolf - Horde Seasoned Guards', 0x20),
(@SPAWN_GROUP+99, 'Alterac Valley - Frostwolf Hut - Alliance Seasoned Guards', 0x20),
(@SPAWN_GROUP+100, 'Alterac Valley - Frostwolf Hut - Horde Seasoned Guards', 0x20),

(@SPAWN_GROUP+101, 'Alterac Valley - Aid Station - Alliance Veteran Guards', 0x20),
(@SPAWN_GROUP+102, 'Alterac Valley - Aid Station - Horde Veteran Guards', 0x20),
(@SPAWN_GROUP+103, 'Alterac Valley - Stormpike - Alliance Veteran Guards', 0x20),
(@SPAWN_GROUP+104, 'Alterac Valley - Stormpike - Horde Veteran Guards', 0x20),
(@SPAWN_GROUP+105, 'Alterac Valley - Stonehearth - Alliance Veteran Guards', 0x20),
(@SPAWN_GROUP+106, 'Alterac Valley - Stonehearth - Horde Veteran Guards', 0x20),
(@SPAWN_GROUP+107, 'Alterac Valley - Snowfall - Alliance Veteran Guards', 0x20),
(@SPAWN_GROUP+108, 'Alterac Valley - Snowfall - Horde Veteran Guards', 0x20),
(@SPAWN_GROUP+109, 'Alterac Valley - Iceblood - Alliance Veteran Guards', 0x20),
(@SPAWN_GROUP+110, 'Alterac Valley - Iceblood - Horde Veteran Guards', 0x20),
(@SPAWN_GROUP+111, 'Alterac Valley - Frostwolf - Alliance Veteran Guards', 0x20),
(@SPAWN_GROUP+112, 'Alterac Valley - Frostwolf - Horde Veteran Guards', 0x20),
(@SPAWN_GROUP+113, 'Alterac Valley - Frostwolf Hut - Alliance Veteran Guards', 0x20),
(@SPAWN_GROUP+114, 'Alterac Valley - Frostwolf Hut - Horde Veteran Guards', 0x20),

(@SPAWN_GROUP+115, 'Alterac Valley - Aid Station - Alliance Champion Guards', 0x20),
(@SPAWN_GROUP+116, 'Alterac Valley - Aid Station - Horde Champion Guards', 0x20),
(@SPAWN_GROUP+117, 'Alterac Valley - Stormpike - Alliance Champion Guards', 0x20),
(@SPAWN_GROUP+118, 'Alterac Valley - Stormpike - Horde Champion Guards', 0x20),
(@SPAWN_GROUP+119, 'Alterac Valley - Stonehearth - Alliance Champion Guards', 0x20),
(@SPAWN_GROUP+120, 'Alterac Valley - Stonehearth - Horde Champion Guards', 0x20),
(@SPAWN_GROUP+121, 'Alterac Valley - Snowfall - Alliance Champion Guards', 0x20),
(@SPAWN_GROUP+122, 'Alterac Valley - Snowfall - Horde Champion Guards', 0x20),
(@SPAWN_GROUP+123, 'Alterac Valley - Iceblood - Alliance Champion Guards', 0x20),
(@SPAWN_GROUP+124, 'Alterac Valley - Iceblood - Horde Champion Guards', 0x20),
(@SPAWN_GROUP+125, 'Alterac Valley - Frostwolf - Alliance Champion Guards', 0x20),
(@SPAWN_GROUP+126, 'Alterac Valley - Frostwolf - Horde Champion Guards', 0x20),
(@SPAWN_GROUP+127, 'Alterac Valley - Frostwolf Hut - Alliance Champion Guards', 0x20),
(@SPAWN_GROUP+128, 'Alterac Valley - Frostwolf Hut - Horde Champion Guards', 0x20),

(@SPAWN_GROUP+129, 'Alterac Valley - Irondeep Mine - Neutral Controlled', 0x0),
(@SPAWN_GROUP+130, 'Alterac Valley - Coldtooth Mine - Neutral Controlled', 0x0),
(@SPAWN_GROUP+131, 'Alterac Valley - Horde mini boss fires', 0x20),
(@SPAWN_GROUP+132, 'Alterac Valley - Alliance mini boss fires', 0x20);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN  @SPAWN_GROUP+0 AND @SPAWN_GROUP+132;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
-- Aid Station
-- -- Alliance
(@SPAWN_GROUP+29, 0, @CGUID+345),
(@SPAWN_GROUP+29, 0, @CGUID+346),
(@SPAWN_GROUP+29, 0, @CGUID+347),
(@SPAWN_GROUP+29, 0, @CGUID+348),
(@SPAWN_GROUP+29, 0, @CGUID+353),
(@SPAWN_GROUP+0, 1, @OGUID+108),

(@SPAWN_GROUP+87, 0, @CGUID+979),
(@SPAWN_GROUP+87, 0, @CGUID+980),
(@SPAWN_GROUP+87, 0, @CGUID+981),
(@SPAWN_GROUP+87, 0, @CGUID+982),

(@SPAWN_GROUP+101, 0, @CGUID+987),
(@SPAWN_GROUP+101, 0, @CGUID+988),
(@SPAWN_GROUP+101, 0, @CGUID+989),
(@SPAWN_GROUP+101, 0, @CGUID+990),

(@SPAWN_GROUP+115, 0, @CGUID+995),
(@SPAWN_GROUP+115, 0, @CGUID+996),
(@SPAWN_GROUP+115, 0, @CGUID+997),
(@SPAWN_GROUP+115, 0, @CGUID+998),

-- -- Horde
(@SPAWN_GROUP+30, 0, @CGUID+349),
(@SPAWN_GROUP+30, 0, @CGUID+350),
(@SPAWN_GROUP+30, 0, @CGUID+351),
(@SPAWN_GROUP+30, 0, @CGUID+352),
(@SPAWN_GROUP+30, 0, @CGUID+354),
(@SPAWN_GROUP+2, 1, @OGUID+110),
(@SPAWN_GROUP+1, 1, @OGUID+111),
(@SPAWN_GROUP+3, 1, @OGUID+109),

(@SPAWN_GROUP+88, 0, @CGUID+983),
(@SPAWN_GROUP+88, 0, @CGUID+984),
(@SPAWN_GROUP+88, 0, @CGUID+985),
(@SPAWN_GROUP+88, 0, @CGUID+986),

(@SPAWN_GROUP+102, 0, @CGUID+991),
(@SPAWN_GROUP+102, 0, @CGUID+992),
(@SPAWN_GROUP+102, 0, @CGUID+993),
(@SPAWN_GROUP+102, 0, @CGUID+994),

(@SPAWN_GROUP+116, 0, @CGUID+999),
(@SPAWN_GROUP+116, 0, @CGUID+1000),
(@SPAWN_GROUP+116, 0, @CGUID+1001),
(@SPAWN_GROUP+116, 0, @CGUID+1002),

-- Stormpike
-- -- Alliance
(@SPAWN_GROUP+31, 0, @CGUID+355),
(@SPAWN_GROUP+31, 0, @CGUID+356),
(@SPAWN_GROUP+31, 0, @CGUID+357),
(@SPAWN_GROUP+31, 0, @CGUID+358),
(@SPAWN_GROUP+31, 0, @CGUID+364),
(@SPAWN_GROUP+4, 1, @OGUID+112),
(@SPAWN_GROUP+5, 1, @OGUID+115),

(@SPAWN_GROUP+89, 0, @CGUID+1003),
(@SPAWN_GROUP+89, 0, @CGUID+1004),
(@SPAWN_GROUP+89, 0, @CGUID+1005),
(@SPAWN_GROUP+89, 0, @CGUID+1006),

(@SPAWN_GROUP+103, 0, @CGUID+1011),
(@SPAWN_GROUP+103, 0, @CGUID+1012),
(@SPAWN_GROUP+103, 0, @CGUID+1013),
(@SPAWN_GROUP+103, 0, @CGUID+1014),

(@SPAWN_GROUP+117, 0, @CGUID+1019),
(@SPAWN_GROUP+117, 0, @CGUID+1020),
(@SPAWN_GROUP+117, 0, @CGUID+1021),
(@SPAWN_GROUP+117, 0, @CGUID+1022),

-- -- Horde
(@SPAWN_GROUP+32, 0, @CGUID+359),
(@SPAWN_GROUP+32, 0, @CGUID+360),
(@SPAWN_GROUP+32, 0, @CGUID+361),
(@SPAWN_GROUP+32, 0, @CGUID+362),
(@SPAWN_GROUP+32, 0, @CGUID+363),
(@SPAWN_GROUP+6, 1, @OGUID+114),
(@SPAWN_GROUP+7, 1, @OGUID+113),

(@SPAWN_GROUP+90, 0, @CGUID+1007),
(@SPAWN_GROUP+90, 0, @CGUID+1008),
(@SPAWN_GROUP+90, 0, @CGUID+1009),
(@SPAWN_GROUP+90, 0, @CGUID+1010),

(@SPAWN_GROUP+104, 0, @CGUID+1015),
(@SPAWN_GROUP+104, 0, @CGUID+1016),
(@SPAWN_GROUP+104, 0, @CGUID+1017),
(@SPAWN_GROUP+104, 0, @CGUID+1018),

(@SPAWN_GROUP+118, 0, @CGUID+1023),
(@SPAWN_GROUP+118, 0, @CGUID+1024),
(@SPAWN_GROUP+118, 0, @CGUID+1025),
(@SPAWN_GROUP+118, 0, @CGUID+1026),

-- Stonehearth
-- -- Alliance
(@SPAWN_GROUP+33, 0, @CGUID+365),
(@SPAWN_GROUP+33, 0, @CGUID+366),
(@SPAWN_GROUP+33, 0, @CGUID+367),
(@SPAWN_GROUP+33, 0, @CGUID+368),
(@SPAWN_GROUP+33, 0, @CGUID+374),
(@SPAWN_GROUP+8, 1, @OGUID+118),
(@SPAWN_GROUP+9, 1, @OGUID+119),

(@SPAWN_GROUP+91, 0, @CGUID+1027),
(@SPAWN_GROUP+91, 0, @CGUID+1028),
(@SPAWN_GROUP+91, 0, @CGUID+1029),
(@SPAWN_GROUP+91, 0, @CGUID+1030),

(@SPAWN_GROUP+105, 0, @CGUID+1035),
(@SPAWN_GROUP+105, 0, @CGUID+1036),
(@SPAWN_GROUP+105, 0, @CGUID+1037),
(@SPAWN_GROUP+105, 0, @CGUID+1038),

(@SPAWN_GROUP+119, 0, @CGUID+1043),
(@SPAWN_GROUP+119, 0, @CGUID+1044),
(@SPAWN_GROUP+119, 0, @CGUID+1045),
(@SPAWN_GROUP+119, 0, @CGUID+1046),

-- -- Horde
(@SPAWN_GROUP+34, 0, @CGUID+369),
(@SPAWN_GROUP+34, 0, @CGUID+370),
(@SPAWN_GROUP+34, 0, @CGUID+371),
(@SPAWN_GROUP+34, 0, @CGUID+372),
(@SPAWN_GROUP+34, 0, @CGUID+373),
(@SPAWN_GROUP+10, 1, @OGUID+117),
(@SPAWN_GROUP+11, 1, @OGUID+116),

(@SPAWN_GROUP+92, 0, @CGUID+1031),
(@SPAWN_GROUP+92, 0, @CGUID+1032),
(@SPAWN_GROUP+92, 0, @CGUID+1033),
(@SPAWN_GROUP+92, 0, @CGUID+1034),

(@SPAWN_GROUP+106, 0, @CGUID+1039),
(@SPAWN_GROUP+106, 0, @CGUID+1040),
(@SPAWN_GROUP+106, 0, @CGUID+1041),
(@SPAWN_GROUP+106, 0, @CGUID+1042),

(@SPAWN_GROUP+120, 0, @CGUID+1047),
(@SPAWN_GROUP+120, 0, @CGUID+1048),
(@SPAWN_GROUP+120, 0, @CGUID+1049),
(@SPAWN_GROUP+120, 0, @CGUID+1050),
-- Snowfall
-- -- Neutral
(@SPAWN_GROUP+12, 1, @OGUID+120),

-- -- Alliance
(@SPAWN_GROUP+35, 0, @CGUID+379),
(@SPAWN_GROUP+35, 0, @CGUID+380),
(@SPAWN_GROUP+35, 0, @CGUID+381),
(@SPAWN_GROUP+35, 0, @CGUID+382),
(@SPAWN_GROUP+35, 0, @CGUID+383),
(@SPAWN_GROUP+13, 1, @OGUID+124),
(@SPAWN_GROUP+13, 1, @OGUID+128),
(@SPAWN_GROUP+13, 1, @OGUID+131),
(@SPAWN_GROUP+13, 1, @OGUID+135),
(@SPAWN_GROUP+13, 1, @OGUID+139),
(@SPAWN_GROUP+14, 1, @OGUID+122),
(@SPAWN_GROUP+14, 1, @OGUID+127),
(@SPAWN_GROUP+14, 1, @OGUID+132),
(@SPAWN_GROUP+14, 1, @OGUID+136),
(@SPAWN_GROUP+14, 1, @OGUID+140),

(@SPAWN_GROUP+93, 0, @CGUID+1051),
(@SPAWN_GROUP+93, 0, @CGUID+1052),
(@SPAWN_GROUP+93, 0, @CGUID+1053),
(@SPAWN_GROUP+93, 0, @CGUID+1054),

(@SPAWN_GROUP+107, 0, @CGUID+1059),
(@SPAWN_GROUP+107, 0, @CGUID+1060),
(@SPAWN_GROUP+107, 0, @CGUID+1061),
(@SPAWN_GROUP+107, 0, @CGUID+1062),

(@SPAWN_GROUP+121, 0, @CGUID+1067),
(@SPAWN_GROUP+121, 0, @CGUID+1068),
(@SPAWN_GROUP+121, 0, @CGUID+1069),
(@SPAWN_GROUP+121, 0, @CGUID+1070),

-- -- Horde
(@SPAWN_GROUP+36, 0, @CGUID+375),
(@SPAWN_GROUP+36, 0, @CGUID+376),
(@SPAWN_GROUP+36, 0, @CGUID+377),
(@SPAWN_GROUP+36, 0, @CGUID+378),
(@SPAWN_GROUP+36, 0, @CGUID+384),
(@SPAWN_GROUP+15, 1, @OGUID+123),
(@SPAWN_GROUP+15, 1, @OGUID+126),
(@SPAWN_GROUP+15, 1, @OGUID+129),
(@SPAWN_GROUP+15, 1, @OGUID+133),
(@SPAWN_GROUP+15, 1, @OGUID+137),

(@SPAWN_GROUP+16, 1, @OGUID+121),
(@SPAWN_GROUP+16, 1, @OGUID+125),
(@SPAWN_GROUP+16, 1, @OGUID+130),
(@SPAWN_GROUP+16, 1, @OGUID+134),
(@SPAWN_GROUP+16, 1, @OGUID+138),

(@SPAWN_GROUP+94, 0, @CGUID+1055),
(@SPAWN_GROUP+94, 0, @CGUID+1056),
(@SPAWN_GROUP+94, 0, @CGUID+1057),
(@SPAWN_GROUP+94, 0, @CGUID+1058),

(@SPAWN_GROUP+108, 0, @CGUID+1063),
(@SPAWN_GROUP+108, 0, @CGUID+1064),
(@SPAWN_GROUP+108, 0, @CGUID+1065),
(@SPAWN_GROUP+108, 0, @CGUID+1066),

(@SPAWN_GROUP+122, 0, @CGUID+1071),
(@SPAWN_GROUP+122, 0, @CGUID+1072),
(@SPAWN_GROUP+122, 0, @CGUID+1073),
(@SPAWN_GROUP+122, 0, @CGUID+1074),

-- Iceblood
-- -- Alliance
(@SPAWN_GROUP+37, 0, @CGUID+389),
(@SPAWN_GROUP+37, 0, @CGUID+390),
(@SPAWN_GROUP+37, 0, @CGUID+391),
(@SPAWN_GROUP+37, 0, @CGUID+392),
(@SPAWN_GROUP+37, 0, @CGUID+394),
(@SPAWN_GROUP+17, 1, @OGUID+143),
(@SPAWN_GROUP+18, 1, @OGUID+142),

(@SPAWN_GROUP+95, 0, @CGUID+1075),
(@SPAWN_GROUP+95, 0, @CGUID+1076),
(@SPAWN_GROUP+95, 0, @CGUID+1077),
(@SPAWN_GROUP+95, 0, @CGUID+1078),

(@SPAWN_GROUP+109, 0, @CGUID+1083),
(@SPAWN_GROUP+109, 0, @CGUID+1084),
(@SPAWN_GROUP+109, 0, @CGUID+1085),
(@SPAWN_GROUP+109, 0, @CGUID+1086),

(@SPAWN_GROUP+123, 0, @CGUID+1091),
(@SPAWN_GROUP+123, 0, @CGUID+1092),
(@SPAWN_GROUP+123, 0, @CGUID+1093),
(@SPAWN_GROUP+123, 0, @CGUID+1094),

-- -- Horde
(@SPAWN_GROUP+38, 0, @CGUID+385),
(@SPAWN_GROUP+38, 0, @CGUID+386),
(@SPAWN_GROUP+38, 0, @CGUID+387),
(@SPAWN_GROUP+38, 0, @CGUID+388),
(@SPAWN_GROUP+38, 0, @CGUID+393),
(@SPAWN_GROUP+19, 1, @OGUID+141),
(@SPAWN_GROUP+20, 1, @OGUID+144),

(@SPAWN_GROUP+96, 0, @CGUID+1079),
(@SPAWN_GROUP+96, 0, @CGUID+1080),
(@SPAWN_GROUP+96, 0, @CGUID+1081),
(@SPAWN_GROUP+96, 0, @CGUID+1082),

(@SPAWN_GROUP+110, 0, @CGUID+1087),
(@SPAWN_GROUP+110, 0, @CGUID+1088),
(@SPAWN_GROUP+110, 0, @CGUID+1089),
(@SPAWN_GROUP+110, 0, @CGUID+1090),

(@SPAWN_GROUP+124, 0, @CGUID+1095),
(@SPAWN_GROUP+124, 0, @CGUID+1096),
(@SPAWN_GROUP+124, 0, @CGUID+1097),
(@SPAWN_GROUP+124, 0, @CGUID+1098),

-- Frostwolf
-- -- Alliance
(@SPAWN_GROUP+39, 0, @CGUID+399),
(@SPAWN_GROUP+39, 0, @CGUID+400),
(@SPAWN_GROUP+39, 0, @CGUID+401),
(@SPAWN_GROUP+39, 0, @CGUID+402),
(@SPAWN_GROUP+39, 0, @CGUID+404),
(@SPAWN_GROUP+21, 1, @OGUID+147),
(@SPAWN_GROUP+22, 1, @OGUID+146),

(@SPAWN_GROUP+97, 0, @CGUID+1099),
(@SPAWN_GROUP+97, 0, @CGUID+1100),
(@SPAWN_GROUP+97, 0, @CGUID+1101),
(@SPAWN_GROUP+97, 0, @CGUID+1102),

(@SPAWN_GROUP+111, 0, @CGUID+1107),
(@SPAWN_GROUP+111, 0, @CGUID+1108),
(@SPAWN_GROUP+111, 0, @CGUID+1109),
(@SPAWN_GROUP+111, 0, @CGUID+1110),

(@SPAWN_GROUP+125, 0, @CGUID+1115),
(@SPAWN_GROUP+125, 0, @CGUID+1116),
(@SPAWN_GROUP+125, 0, @CGUID+1117),
(@SPAWN_GROUP+125, 0, @CGUID+1118),
-- -- Horde
(@SPAWN_GROUP+40, 0, @CGUID+395),
(@SPAWN_GROUP+40, 0, @CGUID+396),
(@SPAWN_GROUP+40, 0, @CGUID+397),
(@SPAWN_GROUP+40, 0, @CGUID+398),
(@SPAWN_GROUP+40, 0, @CGUID+403),
(@SPAWN_GROUP+23, 1, @OGUID+145),
(@SPAWN_GROUP+24, 1, @OGUID+148),

(@SPAWN_GROUP+98, 0, @CGUID+1103),
(@SPAWN_GROUP+98, 0, @CGUID+1104),
(@SPAWN_GROUP+98, 0, @CGUID+1105),
(@SPAWN_GROUP+98, 0, @CGUID+1106),

(@SPAWN_GROUP+112, 0, @CGUID+1111),
(@SPAWN_GROUP+112, 0, @CGUID+1112),
(@SPAWN_GROUP+112, 0, @CGUID+1113),
(@SPAWN_GROUP+112, 0, @CGUID+1114),

(@SPAWN_GROUP+126, 0, @CGUID+1119),
(@SPAWN_GROUP+126, 0, @CGUID+1120),
(@SPAWN_GROUP+126, 0, @CGUID+1121),
(@SPAWN_GROUP+126, 0, @CGUID+1122),

-- Frostwolf Hut
-- -- Alliance
(@SPAWN_GROUP+41, 0, @CGUID+409),
(@SPAWN_GROUP+41, 0, @CGUID+410),
(@SPAWN_GROUP+41, 0, @CGUID+411),
(@SPAWN_GROUP+41, 0, @CGUID+412),
(@SPAWN_GROUP+41, 0, @CGUID+414),
(@SPAWN_GROUP+25, 1, @OGUID+151),
(@SPAWN_GROUP+26, 1, @OGUID+150),

(@SPAWN_GROUP+99, 0, @CGUID+1123),
(@SPAWN_GROUP+99, 0, @CGUID+1124),
(@SPAWN_GROUP+99, 0, @CGUID+1125),
(@SPAWN_GROUP+99, 0, @CGUID+1126),

(@SPAWN_GROUP+113, 0, @CGUID+1131),
(@SPAWN_GROUP+113, 0, @CGUID+1132),
(@SPAWN_GROUP+113, 0, @CGUID+1133),
(@SPAWN_GROUP+113, 0, @CGUID+1134),

(@SPAWN_GROUP+127, 0, @CGUID+1139),
(@SPAWN_GROUP+127, 0, @CGUID+1140),
(@SPAWN_GROUP+127, 0, @CGUID+1141),
(@SPAWN_GROUP+127, 0, @CGUID+1142),

-- -- Horde
(@SPAWN_GROUP+42, 0, @CGUID+405),
(@SPAWN_GROUP+42, 0, @CGUID+406),
(@SPAWN_GROUP+42, 0, @CGUID+407),
(@SPAWN_GROUP+42, 0, @CGUID+408),
(@SPAWN_GROUP+42, 0, @CGUID+413),
(@SPAWN_GROUP+27, 1, @OGUID+149),
(@SPAWN_GROUP+28, 1, @OGUID+152),

(@SPAWN_GROUP+100, 0, @CGUID+1127),
(@SPAWN_GROUP+100, 0, @CGUID+1128),
(@SPAWN_GROUP+100, 0, @CGUID+1129),
(@SPAWN_GROUP+100, 0, @CGUID+1130),

(@SPAWN_GROUP+114, 0, @CGUID+1135),
(@SPAWN_GROUP+114, 0, @CGUID+1136),
(@SPAWN_GROUP+114, 0, @CGUID+1137),
(@SPAWN_GROUP+114, 0, @CGUID+1138),

(@SPAWN_GROUP+128, 0, @CGUID+1143),
(@SPAWN_GROUP+128, 0, @CGUID+1144),
(@SPAWN_GROUP+128, 0, @CGUID+1145),
(@SPAWN_GROUP+128, 0, @CGUID+1146),

-- North Bunker
-- -- Controlled
(@SPAWN_GROUP+43, 1, @OGUID+168),
(@SPAWN_GROUP+43, 1, @OGUID+170),
-- -- Contested
(@SPAWN_GROUP+44, 1, @OGUID+167),
(@SPAWN_GROUP+44, 1, @OGUID+169),
-- -- Destroyed
(@SPAWN_GROUP+45, 1, @OGUID+171),
(@SPAWN_GROUP+45, 1, @OGUID+172),
(@SPAWN_GROUP+45, 1, @OGUID+173),
(@SPAWN_GROUP+45, 1, @OGUID+174),
(@SPAWN_GROUP+45, 1, @OGUID+175),
(@SPAWN_GROUP+45, 1, @OGUID+176),
(@SPAWN_GROUP+45, 1, @OGUID+177),
(@SPAWN_GROUP+45, 1, @OGUID+178),
(@SPAWN_GROUP+45, 1, @OGUID+179),
(@SPAWN_GROUP+45, 1, @OGUID+180),
(@SPAWN_GROUP+75, 0, @CGUID+322),
-- -- Guards
(@SPAWN_GROUP+46, 0, @CGUID+287),
(@SPAWN_GROUP+46, 0, @CGUID+288),
(@SPAWN_GROUP+46, 0, @CGUID+284),
(@SPAWN_GROUP+46, 0, @CGUID+281),

-- South Bunker
-- -- Controlled
(@SPAWN_GROUP+47, 1, @OGUID+153),
(@SPAWN_GROUP+47, 1, @OGUID+154),
-- -- Contested
(@SPAWN_GROUP+48, 1, @OGUID+155),
(@SPAWN_GROUP+48, 1, @OGUID+156),
-- -- Destroyed
(@SPAWN_GROUP+49, 1, @OGUID+157),
(@SPAWN_GROUP+49, 1, @OGUID+158),
(@SPAWN_GROUP+49, 1, @OGUID+159),
(@SPAWN_GROUP+49, 1, @OGUID+160),
(@SPAWN_GROUP+49, 1, @OGUID+161),
(@SPAWN_GROUP+49, 1, @OGUID+162),
(@SPAWN_GROUP+49, 1, @OGUID+163),
(@SPAWN_GROUP+49, 1, @OGUID+164),
(@SPAWN_GROUP+49, 1, @OGUID+165),
(@SPAWN_GROUP+49, 1, @OGUID+166),
(@SPAWN_GROUP+76, 0, @CGUID+324),
-- -- Guards
(@SPAWN_GROUP+50, 0, @CGUID+277),
(@SPAWN_GROUP+50, 0, @CGUID+282),
(@SPAWN_GROUP+50, 0, @CGUID+286),
(@SPAWN_GROUP+50, 0, @CGUID+283),

-- Icewing Bunker
-- -- Controlled
(@SPAWN_GROUP+51, 1, @OGUID+251),
(@SPAWN_GROUP+51, 1, @OGUID+253),
-- -- Contested
(@SPAWN_GROUP+52, 1, @OGUID+252),
(@SPAWN_GROUP+52, 1, @OGUID+254),
-- -- Destroyed
(@SPAWN_GROUP+53, 1, @OGUID+255),
(@SPAWN_GROUP+53, 1, @OGUID+256),
(@SPAWN_GROUP+53, 1, @OGUID+257),
(@SPAWN_GROUP+53, 1, @OGUID+258),
(@SPAWN_GROUP+53, 1, @OGUID+259),
(@SPAWN_GROUP+53, 1, @OGUID+260),
(@SPAWN_GROUP+53, 1, @OGUID+261),
(@SPAWN_GROUP+53, 1, @OGUID+262),
(@SPAWN_GROUP+53, 1, @OGUID+263),
(@SPAWN_GROUP+53, 1, @OGUID+264),
(@SPAWN_GROUP+77, 0, @CGUID+325),
-- -- Guards
(@SPAWN_GROUP+54, 0, @CGUID+233),
(@SPAWN_GROUP+54, 0, @CGUID+235),
(@SPAWN_GROUP+54, 0, @CGUID+230),
(@SPAWN_GROUP+54, 0, @CGUID+229),

-- Stonehearth Bunker
-- -- Controlled
(@SPAWN_GROUP+55, 1, @OGUID+238),
(@SPAWN_GROUP+55, 1, @OGUID+239),
-- -- Contested
(@SPAWN_GROUP+56, 1, @OGUID+237),
(@SPAWN_GROUP+56, 1, @OGUID+240),
-- -- Destroyed
(@SPAWN_GROUP+57, 1, @OGUID+241),
(@SPAWN_GROUP+57, 1, @OGUID+242),
(@SPAWN_GROUP+57, 1, @OGUID+243),
(@SPAWN_GROUP+57, 1, @OGUID+244),
(@SPAWN_GROUP+57, 1, @OGUID+245),
(@SPAWN_GROUP+57, 1, @OGUID+246),
(@SPAWN_GROUP+57, 1, @OGUID+247),
(@SPAWN_GROUP+57, 1, @OGUID+248),
(@SPAWN_GROUP+57, 1, @OGUID+249),
(@SPAWN_GROUP+57, 1, @OGUID+250),
(@SPAWN_GROUP+78, 0, @CGUID+316),
-- -- Guards
(@SPAWN_GROUP+58, 0, @CGUID+202),
(@SPAWN_GROUP+58, 0, @CGUID+201),
(@SPAWN_GROUP+58, 0, @CGUID+200),
(@SPAWN_GROUP+58, 0, @CGUID+198),

-- Iceblood Tower
-- -- Controlled
(@SPAWN_GROUP+59, 1, @OGUID+223),
(@SPAWN_GROUP+59, 1, @OGUID+226),
-- -- Contested
(@SPAWN_GROUP+60, 1, @OGUID+224),
(@SPAWN_GROUP+60, 1, @OGUID+225),
-- -- Destroyed
(@SPAWN_GROUP+61, 1, @OGUID+227),
(@SPAWN_GROUP+61, 1, @OGUID+228),
(@SPAWN_GROUP+61, 1, @OGUID+229),
(@SPAWN_GROUP+61, 1, @OGUID+230),
(@SPAWN_GROUP+61, 1, @OGUID+231),
(@SPAWN_GROUP+61, 1, @OGUID+232),
(@SPAWN_GROUP+61, 1, @OGUID+233),
(@SPAWN_GROUP+61, 1, @OGUID+234),
(@SPAWN_GROUP+61, 1, @OGUID+235),
(@SPAWN_GROUP+61, 1, @OGUID+236),
(@SPAWN_GROUP+79, 0, @CGUID+330),
-- -- Guards
(@SPAWN_GROUP+62, 0, @CGUID+170),
(@SPAWN_GROUP+62, 0, @CGUID+171),
(@SPAWN_GROUP+62, 0, @CGUID+174),
(@SPAWN_GROUP+62, 0, @CGUID+173),

-- Tower Point
-- -- Controlled
(@SPAWN_GROUP+63, 1, @OGUID+210),
(@SPAWN_GROUP+63, 1, @OGUID+211),
-- -- Contested
(@SPAWN_GROUP+64, 1, @OGUID+209),
(@SPAWN_GROUP+64, 1, @OGUID+212),
-- -- Destroyed
(@SPAWN_GROUP+65, 1, @OGUID+213),
(@SPAWN_GROUP+65, 1, @OGUID+214),
(@SPAWN_GROUP+65, 1, @OGUID+215),
(@SPAWN_GROUP+65, 1, @OGUID+216),
(@SPAWN_GROUP+65, 1, @OGUID+217),
(@SPAWN_GROUP+65, 1, @OGUID+218),
(@SPAWN_GROUP+65, 1, @OGUID+219),
(@SPAWN_GROUP+65, 1, @OGUID+220),
(@SPAWN_GROUP+65, 1, @OGUID+221),
(@SPAWN_GROUP+65, 1, @OGUID+222),
(@SPAWN_GROUP+80, 0, @CGUID+331),
-- -- Guards
(@SPAWN_GROUP+66, 0, @CGUID+162),
(@SPAWN_GROUP+66, 0, @CGUID+163),
(@SPAWN_GROUP+66, 0, @CGUID+161),
(@SPAWN_GROUP+66, 0, @CGUID+160),

-- East Tower
-- -- Controlled
(@SPAWN_GROUP+67, 1, @OGUID+181),
(@SPAWN_GROUP+67, 1, @OGUID+183),
-- -- Contested
(@SPAWN_GROUP+68, 1, @OGUID+182),
(@SPAWN_GROUP+68, 1, @OGUID+184),
-- -- Destroyed
(@SPAWN_GROUP+69, 1, @OGUID+185),
(@SPAWN_GROUP+69, 1, @OGUID+186),
(@SPAWN_GROUP+69, 1, @OGUID+187),
(@SPAWN_GROUP+69, 1, @OGUID+188),
(@SPAWN_GROUP+69, 1, @OGUID+189),
(@SPAWN_GROUP+69, 1, @OGUID+190),
(@SPAWN_GROUP+69, 1, @OGUID+191),
(@SPAWN_GROUP+69, 1, @OGUID+192),
(@SPAWN_GROUP+69, 1, @OGUID+193),
(@SPAWN_GROUP+69, 1, @OGUID+194),
(@SPAWN_GROUP+81, 0, @CGUID+334),
-- -- Guards
(@SPAWN_GROUP+70, 0, @CGUID+111),
(@SPAWN_GROUP+70, 0, @CGUID+115),
(@SPAWN_GROUP+70, 0, @CGUID+110),
(@SPAWN_GROUP+70, 0, @CGUID+114),

-- West Tower
-- -- Controlled
(@SPAWN_GROUP+71, 1, @OGUID+195),
(@SPAWN_GROUP+71, 1, @OGUID+196),
-- -- Contested
(@SPAWN_GROUP+72, 1, @OGUID+197),
(@SPAWN_GROUP+72, 1, @OGUID+198),
-- -- Destroyed
(@SPAWN_GROUP+73, 1, @OGUID+199),
(@SPAWN_GROUP+73, 1, @OGUID+200),
(@SPAWN_GROUP+73, 1, @OGUID+201),
(@SPAWN_GROUP+73, 1, @OGUID+202),
(@SPAWN_GROUP+73, 1, @OGUID+203),
(@SPAWN_GROUP+73, 1, @OGUID+204),
(@SPAWN_GROUP+73, 1, @OGUID+205),
(@SPAWN_GROUP+73, 1, @OGUID+206),
(@SPAWN_GROUP+73, 1, @OGUID+207),
(@SPAWN_GROUP+73, 1, @OGUID+208),
(@SPAWN_GROUP+82, 0, @OGUID+551),
-- -- Guards
(@SPAWN_GROUP+74, 0, @CGUID+129),
(@SPAWN_GROUP+74, 0, @CGUID+130),
(@SPAWN_GROUP+74, 0, @CGUID+126),
(@SPAWN_GROUP+74, 0, @CGUID+124),

-- Irondeep Mine
-- -- Alliance
(@SPAWN_GROUP+83, 0, @CGUID+520),
(@SPAWN_GROUP+83, 0, @CGUID+521),
(@SPAWN_GROUP+83, 0, @CGUID+522),
(@SPAWN_GROUP+83, 0, @CGUID+523),
(@SPAWN_GROUP+83, 0, @CGUID+524),
(@SPAWN_GROUP+83, 0, @CGUID+525),
(@SPAWN_GROUP+83, 0, @CGUID+526),
(@SPAWN_GROUP+83, 0, @CGUID+527),
(@SPAWN_GROUP+83, 0, @CGUID+528),
(@SPAWN_GROUP+83, 0, @CGUID+529),
(@SPAWN_GROUP+83, 0, @CGUID+530),
(@SPAWN_GROUP+83, 0, @CGUID+531),
(@SPAWN_GROUP+83, 0, @CGUID+532),
(@SPAWN_GROUP+83, 0, @CGUID+533),
(@SPAWN_GROUP+83, 0, @CGUID+534),
(@SPAWN_GROUP+83, 0, @CGUID+535),
(@SPAWN_GROUP+83, 0, @CGUID+536),
(@SPAWN_GROUP+83, 0, @CGUID+537),
(@SPAWN_GROUP+83, 0, @CGUID+538),
(@SPAWN_GROUP+83, 0, @CGUID+539),
(@SPAWN_GROUP+83, 0, @CGUID+540),
(@SPAWN_GROUP+83, 0, @CGUID+541),
(@SPAWN_GROUP+83, 0, @CGUID+542),
(@SPAWN_GROUP+83, 0, @CGUID+543),
(@SPAWN_GROUP+83, 0, @CGUID+544),
(@SPAWN_GROUP+83, 0, @CGUID+545),
(@SPAWN_GROUP+83, 0, @CGUID+546),
(@SPAWN_GROUP+83, 0, @CGUID+547),
(@SPAWN_GROUP+83, 0, @CGUID+548),
(@SPAWN_GROUP+83, 0, @CGUID+549),
(@SPAWN_GROUP+83, 0, @CGUID+550),
(@SPAWN_GROUP+83, 0, @CGUID+551),
(@SPAWN_GROUP+83, 0, @CGUID+552),
(@SPAWN_GROUP+83, 0, @CGUID+553),
(@SPAWN_GROUP+83, 0, @CGUID+554),
(@SPAWN_GROUP+83, 0, @CGUID+555),
(@SPAWN_GROUP+83, 0, @CGUID+556),
(@SPAWN_GROUP+83, 0, @CGUID+557),
(@SPAWN_GROUP+83, 0, @CGUID+558),
(@SPAWN_GROUP+83, 0, @CGUID+559),
(@SPAWN_GROUP+83, 0, @CGUID+560),
(@SPAWN_GROUP+83, 0, @CGUID+561),
(@SPAWN_GROUP+83, 0, @CGUID+562),
(@SPAWN_GROUP+83, 0, @CGUID+563),
(@SPAWN_GROUP+83, 0, @CGUID+564),
(@SPAWN_GROUP+83, 0, @CGUID+565),
(@SPAWN_GROUP+83, 0, @CGUID+566),
(@SPAWN_GROUP+83, 0, @CGUID+567),
(@SPAWN_GROUP+83, 0, @CGUID+568),
(@SPAWN_GROUP+83, 0, @CGUID+569),
(@SPAWN_GROUP+83, 0, @CGUID+570),
(@SPAWN_GROUP+83, 0, @CGUID+571),
(@SPAWN_GROUP+83, 0, @CGUID+572),
(@SPAWN_GROUP+83, 0, @CGUID+573),
(@SPAWN_GROUP+83, 0, @CGUID+574),
(@SPAWN_GROUP+83, 0, @CGUID+575),
(@SPAWN_GROUP+83, 0, @CGUID+576),
(@SPAWN_GROUP+83, 0, @CGUID+577),
(@SPAWN_GROUP+83, 0, @CGUID+578),
(@SPAWN_GROUP+83, 0, @CGUID+579),
(@SPAWN_GROUP+83, 0, @CGUID+580),
(@SPAWN_GROUP+83, 0, @CGUID+581),
(@SPAWN_GROUP+83, 0, @CGUID+583),
(@SPAWN_GROUP+83, 0, @CGUID+584),
(@SPAWN_GROUP+83, 0, @CGUID+585),
(@SPAWN_GROUP+83, 0, @CGUID+586),
(@SPAWN_GROUP+83, 0, @CGUID+587),
(@SPAWN_GROUP+83, 0, @CGUID+588),
(@SPAWN_GROUP+83, 0, @CGUID+589),
(@SPAWN_GROUP+83, 0, @CGUID+590),
(@SPAWN_GROUP+83, 0, @CGUID+591),
(@SPAWN_GROUP+83, 0, @CGUID+592),
(@SPAWN_GROUP+83, 0, @CGUID+593),
(@SPAWN_GROUP+83, 0, @CGUID+594),
(@SPAWN_GROUP+83, 0, @CGUID+595),
(@SPAWN_GROUP+83, 0, @CGUID+597),
(@SPAWN_GROUP+83, 0, @CGUID+598),
(@SPAWN_GROUP+83, 0, @CGUID+599),
(@SPAWN_GROUP+83, 0, @CGUID+601),
(@SPAWN_GROUP+83, 0, @CGUID+602),
(@SPAWN_GROUP+83, 0, @CGUID+603),
(@SPAWN_GROUP+83, 0, @CGUID+604),
(@SPAWN_GROUP+83, 0, @CGUID+605),
(@SPAWN_GROUP+83, 0, @CGUID+606),

-- -- Horde
(@SPAWN_GROUP+84, 0, @CGUID+433),
(@SPAWN_GROUP+84, 0, @CGUID+434),
(@SPAWN_GROUP+84, 0, @CGUID+435),
(@SPAWN_GROUP+84, 0, @CGUID+436),
(@SPAWN_GROUP+84, 0, @CGUID+437),
(@SPAWN_GROUP+84, 0, @CGUID+438),
(@SPAWN_GROUP+84, 0, @CGUID+439),
(@SPAWN_GROUP+84, 0, @CGUID+440),
(@SPAWN_GROUP+84, 0, @CGUID+441),
(@SPAWN_GROUP+84, 0, @CGUID+442),
(@SPAWN_GROUP+84, 0, @CGUID+443),
(@SPAWN_GROUP+84, 0, @CGUID+444),
(@SPAWN_GROUP+84, 0, @CGUID+445),
(@SPAWN_GROUP+84, 0, @CGUID+446),
(@SPAWN_GROUP+84, 0, @CGUID+447),
(@SPAWN_GROUP+84, 0, @CGUID+448),
(@SPAWN_GROUP+84, 0, @CGUID+449),
(@SPAWN_GROUP+84, 0, @CGUID+450),
(@SPAWN_GROUP+84, 0, @CGUID+451),
(@SPAWN_GROUP+84, 0, @CGUID+452),
(@SPAWN_GROUP+84, 0, @CGUID+453),
(@SPAWN_GROUP+84, 0, @CGUID+454),
(@SPAWN_GROUP+84, 0, @CGUID+455),
(@SPAWN_GROUP+84, 0, @CGUID+456),
(@SPAWN_GROUP+84, 0, @CGUID+457),
(@SPAWN_GROUP+84, 0, @CGUID+458),
(@SPAWN_GROUP+84, 0, @CGUID+459),
(@SPAWN_GROUP+84, 0, @CGUID+460),
(@SPAWN_GROUP+84, 0, @CGUID+461),
(@SPAWN_GROUP+84, 0, @CGUID+462),
(@SPAWN_GROUP+84, 0, @CGUID+463),
(@SPAWN_GROUP+84, 0, @CGUID+464),
(@SPAWN_GROUP+84, 0, @CGUID+465),
(@SPAWN_GROUP+84, 0, @CGUID+466),
(@SPAWN_GROUP+84, 0, @CGUID+467),
(@SPAWN_GROUP+84, 0, @CGUID+468),
(@SPAWN_GROUP+84, 0, @CGUID+469),
(@SPAWN_GROUP+84, 0, @CGUID+470),
(@SPAWN_GROUP+84, 0, @CGUID+471),
(@SPAWN_GROUP+84, 0, @CGUID+472),
(@SPAWN_GROUP+84, 0, @CGUID+473),
(@SPAWN_GROUP+84, 0, @CGUID+474),
(@SPAWN_GROUP+84, 0, @CGUID+475),
(@SPAWN_GROUP+84, 0, @CGUID+476),
(@SPAWN_GROUP+84, 0, @CGUID+477),
(@SPAWN_GROUP+84, 0, @CGUID+478),
(@SPAWN_GROUP+84, 0, @CGUID+479),
(@SPAWN_GROUP+84, 0, @CGUID+480),
(@SPAWN_GROUP+84, 0, @CGUID+481),
(@SPAWN_GROUP+84, 0, @CGUID+482),
(@SPAWN_GROUP+84, 0, @CGUID+483),
(@SPAWN_GROUP+84, 0, @CGUID+484),
(@SPAWN_GROUP+84, 0, @CGUID+485),
(@SPAWN_GROUP+84, 0, @CGUID+486),
(@SPAWN_GROUP+84, 0, @CGUID+487),
(@SPAWN_GROUP+84, 0, @CGUID+488),
(@SPAWN_GROUP+84, 0, @CGUID+489),
(@SPAWN_GROUP+84, 0, @CGUID+490),
(@SPAWN_GROUP+84, 0, @CGUID+491),
(@SPAWN_GROUP+84, 0, @CGUID+492),
(@SPAWN_GROUP+84, 0, @CGUID+493),
(@SPAWN_GROUP+84, 0, @CGUID+494),
(@SPAWN_GROUP+84, 0, @CGUID+495),
(@SPAWN_GROUP+84, 0, @CGUID+496),
(@SPAWN_GROUP+84, 0, @CGUID+497),
(@SPAWN_GROUP+84, 0, @CGUID+498),
(@SPAWN_GROUP+84, 0, @CGUID+499),
(@SPAWN_GROUP+84, 0, @CGUID+500),
(@SPAWN_GROUP+84, 0, @CGUID+501),
(@SPAWN_GROUP+84, 0, @CGUID+502),
(@SPAWN_GROUP+84, 0, @CGUID+503),
(@SPAWN_GROUP+84, 0, @CGUID+504),
(@SPAWN_GROUP+84, 0, @CGUID+505),
(@SPAWN_GROUP+84, 0, @CGUID+506),
(@SPAWN_GROUP+84, 0, @CGUID+507),
(@SPAWN_GROUP+84, 0, @CGUID+508),
(@SPAWN_GROUP+84, 0, @CGUID+509),
(@SPAWN_GROUP+84, 0, @CGUID+510),
(@SPAWN_GROUP+84, 0, @CGUID+511),
(@SPAWN_GROUP+84, 0, @CGUID+515),
(@SPAWN_GROUP+84, 0, @CGUID+513),
(@SPAWN_GROUP+84, 0, @CGUID+516),
(@SPAWN_GROUP+84, 0, @CGUID+518),
(@SPAWN_GROUP+84, 0, @CGUID+519),
-- -- Troggs
(@SPAWN_GROUP+129, 0, @CGUID+607),
(@SPAWN_GROUP+129, 0, @CGUID+608),
(@SPAWN_GROUP+129, 0, @CGUID+609),
(@SPAWN_GROUP+129, 0, @CGUID+610),
(@SPAWN_GROUP+129, 0, @CGUID+611),
(@SPAWN_GROUP+129, 0, @CGUID+612),
(@SPAWN_GROUP+129, 0, @CGUID+613),
(@SPAWN_GROUP+129, 0, @CGUID+614),
(@SPAWN_GROUP+129, 0, @CGUID+615),
(@SPAWN_GROUP+129, 0, @CGUID+616),
(@SPAWN_GROUP+129, 0, @CGUID+617),
(@SPAWN_GROUP+129, 0, @CGUID+618),
(@SPAWN_GROUP+129, 0, @CGUID+619),
(@SPAWN_GROUP+129, 0, @CGUID+620),
(@SPAWN_GROUP+129, 0, @CGUID+621),
(@SPAWN_GROUP+129, 0, @CGUID+622),
(@SPAWN_GROUP+129, 0, @CGUID+623),
(@SPAWN_GROUP+129, 0, @CGUID+624),
(@SPAWN_GROUP+129, 0, @CGUID+625),
(@SPAWN_GROUP+129, 0, @CGUID+626),
(@SPAWN_GROUP+129, 0, @CGUID+627),
(@SPAWN_GROUP+129, 0, @CGUID+628),
(@SPAWN_GROUP+129, 0, @CGUID+629),
(@SPAWN_GROUP+129, 0, @CGUID+630),
(@SPAWN_GROUP+129, 0, @CGUID+631),
(@SPAWN_GROUP+129, 0, @CGUID+632),
(@SPAWN_GROUP+129, 0, @CGUID+633),
(@SPAWN_GROUP+129, 0, @CGUID+634),
(@SPAWN_GROUP+129, 0, @CGUID+635),
(@SPAWN_GROUP+129, 0, @CGUID+636),
(@SPAWN_GROUP+129, 0, @CGUID+637),
(@SPAWN_GROUP+129, 0, @CGUID+638),
(@SPAWN_GROUP+129, 0, @CGUID+639),
(@SPAWN_GROUP+129, 0, @CGUID+640),
(@SPAWN_GROUP+129, 0, @CGUID+641),
(@SPAWN_GROUP+129, 0, @CGUID+642),
(@SPAWN_GROUP+129, 0, @CGUID+643),
(@SPAWN_GROUP+129, 0, @CGUID+644),
(@SPAWN_GROUP+129, 0, @CGUID+645),
(@SPAWN_GROUP+129, 0, @CGUID+646),
(@SPAWN_GROUP+129, 0, @CGUID+647),
(@SPAWN_GROUP+129, 0, @CGUID+648),
(@SPAWN_GROUP+129, 0, @CGUID+649),
(@SPAWN_GROUP+129, 0, @CGUID+650),
(@SPAWN_GROUP+129, 0, @CGUID+651),
(@SPAWN_GROUP+129, 0, @CGUID+652),
(@SPAWN_GROUP+129, 0, @CGUID+653),
(@SPAWN_GROUP+129, 0, @CGUID+654),
(@SPAWN_GROUP+129, 0, @CGUID+655),
(@SPAWN_GROUP+129, 0, @CGUID+656),
(@SPAWN_GROUP+129, 0, @CGUID+657),
(@SPAWN_GROUP+129, 0, @CGUID+658),
(@SPAWN_GROUP+129, 0, @CGUID+659),
(@SPAWN_GROUP+129, 0, @CGUID+660),
(@SPAWN_GROUP+129, 0, @CGUID+661),
(@SPAWN_GROUP+129, 0, @CGUID+662),
(@SPAWN_GROUP+129, 0, @CGUID+663),
(@SPAWN_GROUP+129, 0, @CGUID+664),
(@SPAWN_GROUP+129, 0, @CGUID+665),
(@SPAWN_GROUP+129, 0, @CGUID+666),
(@SPAWN_GROUP+129, 0, @CGUID+667),
(@SPAWN_GROUP+129, 0, @CGUID+668),
(@SPAWN_GROUP+129, 0, @CGUID+669),
(@SPAWN_GROUP+129, 0, @CGUID+670),
(@SPAWN_GROUP+129, 0, @CGUID+671),
(@SPAWN_GROUP+129, 0, @CGUID+672),
(@SPAWN_GROUP+129, 0, @CGUID+673),
(@SPAWN_GROUP+129, 0, @CGUID+674),
(@SPAWN_GROUP+129, 0, @CGUID+675),
(@SPAWN_GROUP+129, 0, @CGUID+676),
(@SPAWN_GROUP+129, 0, @CGUID+677),
(@SPAWN_GROUP+129, 0, @CGUID+678),
(@SPAWN_GROUP+129, 0, @CGUID+679),
(@SPAWN_GROUP+129, 0, @CGUID+680),
(@SPAWN_GROUP+129, 0, @CGUID+681),
(@SPAWN_GROUP+129, 0, @CGUID+682),
(@SPAWN_GROUP+129, 0, @CGUID+683),
(@SPAWN_GROUP+129, 0, @CGUID+684),
(@SPAWN_GROUP+129, 0, @CGUID+685),
(@SPAWN_GROUP+129, 0, @CGUID+686),
(@SPAWN_GROUP+129, 0, @CGUID+688),
(@SPAWN_GROUP+129, 0, @CGUID+690),
(@SPAWN_GROUP+129, 0, @CGUID+692),
-- Coldtooth Mine
-- -- Alliance
(@SPAWN_GROUP+85, 0, @CGUID+791),
(@SPAWN_GROUP+85, 0, @CGUID+792),
(@SPAWN_GROUP+85, 0, @CGUID+793),
(@SPAWN_GROUP+85, 0, @CGUID+794),
(@SPAWN_GROUP+85, 0, @CGUID+795),
(@SPAWN_GROUP+85, 0, @CGUID+796),
(@SPAWN_GROUP+85, 0, @CGUID+797),
(@SPAWN_GROUP+85, 0, @CGUID+798),
(@SPAWN_GROUP+85, 0, @CGUID+799),
(@SPAWN_GROUP+85, 0, @CGUID+800),
(@SPAWN_GROUP+85, 0, @CGUID+801),
(@SPAWN_GROUP+85, 0, @CGUID+802),
(@SPAWN_GROUP+85, 0, @CGUID+803),
(@SPAWN_GROUP+85, 0, @CGUID+804),
(@SPAWN_GROUP+85, 0, @CGUID+805),
(@SPAWN_GROUP+85, 0, @CGUID+806),
(@SPAWN_GROUP+85, 0, @CGUID+807),
(@SPAWN_GROUP+85, 0, @CGUID+808),
(@SPAWN_GROUP+85, 0, @CGUID+809),
(@SPAWN_GROUP+85, 0, @CGUID+810),
(@SPAWN_GROUP+85, 0, @CGUID+811),
(@SPAWN_GROUP+85, 0, @CGUID+812),
(@SPAWN_GROUP+85, 0, @CGUID+813),
(@SPAWN_GROUP+85, 0, @CGUID+814),
(@SPAWN_GROUP+85, 0, @CGUID+815),
(@SPAWN_GROUP+85, 0, @CGUID+816),
(@SPAWN_GROUP+85, 0, @CGUID+817),
(@SPAWN_GROUP+85, 0, @CGUID+818),
(@SPAWN_GROUP+85, 0, @CGUID+819),
(@SPAWN_GROUP+85, 0, @CGUID+820),
(@SPAWN_GROUP+85, 0, @CGUID+821),
(@SPAWN_GROUP+85, 0, @CGUID+822),
(@SPAWN_GROUP+85, 0, @CGUID+823),
(@SPAWN_GROUP+85, 0, @CGUID+824),
(@SPAWN_GROUP+85, 0, @CGUID+825),
(@SPAWN_GROUP+85, 0, @CGUID+826),
(@SPAWN_GROUP+85, 0, @CGUID+827),
(@SPAWN_GROUP+85, 0, @CGUID+828),
(@SPAWN_GROUP+85, 0, @CGUID+829),
(@SPAWN_GROUP+85, 0, @CGUID+830),
(@SPAWN_GROUP+85, 0, @CGUID+831),
(@SPAWN_GROUP+85, 0, @CGUID+832),
(@SPAWN_GROUP+85, 0, @CGUID+833),
(@SPAWN_GROUP+85, 0, @CGUID+834),
(@SPAWN_GROUP+85, 0, @CGUID+835),
(@SPAWN_GROUP+85, 0, @CGUID+836),
(@SPAWN_GROUP+85, 0, @CGUID+837),
(@SPAWN_GROUP+85, 0, @CGUID+838),
(@SPAWN_GROUP+85, 0, @CGUID+839),
(@SPAWN_GROUP+85, 0, @CGUID+840),
(@SPAWN_GROUP+85, 0, @CGUID+841),
(@SPAWN_GROUP+85, 0, @CGUID+842),
(@SPAWN_GROUP+85, 0, @CGUID+843),
(@SPAWN_GROUP+85, 0, @CGUID+844),
(@SPAWN_GROUP+85, 0, @CGUID+845),
(@SPAWN_GROUP+85, 0, @CGUID+846),
(@SPAWN_GROUP+85, 0, @CGUID+847),
(@SPAWN_GROUP+85, 0, @CGUID+848),
(@SPAWN_GROUP+85, 0, @CGUID+849),
(@SPAWN_GROUP+85, 0, @CGUID+850),
(@SPAWN_GROUP+85, 0, @CGUID+851),
(@SPAWN_GROUP+85, 0, @CGUID+852),
(@SPAWN_GROUP+85, 0, @CGUID+853),
(@SPAWN_GROUP+85, 0, @CGUID+854),
(@SPAWN_GROUP+85, 0, @CGUID+855),
(@SPAWN_GROUP+85, 0, @CGUID+856),
(@SPAWN_GROUP+85, 0, @CGUID+857),
(@SPAWN_GROUP+85, 0, @CGUID+858),
(@SPAWN_GROUP+85, 0, @CGUID+859),
(@SPAWN_GROUP+85, 0, @CGUID+860),
(@SPAWN_GROUP+85, 0, @CGUID+861),
(@SPAWN_GROUP+85, 0, @CGUID+862),
(@SPAWN_GROUP+85, 0, @CGUID+863),
(@SPAWN_GROUP+85, 0, @CGUID+864),
(@SPAWN_GROUP+85, 0, @CGUID+865),
(@SPAWN_GROUP+85, 0, @CGUID+866),
(@SPAWN_GROUP+85, 0, @CGUID+867),
(@SPAWN_GROUP+85, 0, @CGUID+868),
(@SPAWN_GROUP+85, 0, @CGUID+869),
(@SPAWN_GROUP+85, 0, @CGUID+871),
(@SPAWN_GROUP+85, 0, @CGUID+870),
(@SPAWN_GROUP+85, 0, @CGUID+872),
(@SPAWN_GROUP+85, 0, @CGUID+873),
(@SPAWN_GROUP+85, 0, @CGUID+874),
(@SPAWN_GROUP+85, 0, @CGUID+875),
(@SPAWN_GROUP+85, 0, @CGUID+876),
(@SPAWN_GROUP+85, 0, @CGUID+877),
(@SPAWN_GROUP+85, 0, @CGUID+878),
(@SPAWN_GROUP+85, 0, @CGUID+879),
(@SPAWN_GROUP+85, 0, @CGUID+880),
(@SPAWN_GROUP+85, 0, @CGUID+881),
(@SPAWN_GROUP+85, 0, @CGUID+882),
(@SPAWN_GROUP+85, 0, @CGUID+883),
(@SPAWN_GROUP+85, 0, @CGUID+884),
(@SPAWN_GROUP+85, 0, @CGUID+885),
(@SPAWN_GROUP+85, 0, @CGUID+886),
(@SPAWN_GROUP+85, 0, @CGUID+887),
-- -- Horde
(@SPAWN_GROUP+86, 0, @CGUID+693),
(@SPAWN_GROUP+86, 0, @CGUID+694),
(@SPAWN_GROUP+86, 0, @CGUID+695),
(@SPAWN_GROUP+86, 0, @CGUID+696),
(@SPAWN_GROUP+86, 0, @CGUID+697),
(@SPAWN_GROUP+86, 0, @CGUID+698),
(@SPAWN_GROUP+86, 0, @CGUID+699),
(@SPAWN_GROUP+86, 0, @CGUID+700),
(@SPAWN_GROUP+86, 0, @CGUID+701),
(@SPAWN_GROUP+86, 0, @CGUID+702),
(@SPAWN_GROUP+86, 0, @CGUID+703),
(@SPAWN_GROUP+86, 0, @CGUID+704),
(@SPAWN_GROUP+86, 0, @CGUID+705),
(@SPAWN_GROUP+86, 0, @CGUID+706),
(@SPAWN_GROUP+86, 0, @CGUID+707),
(@SPAWN_GROUP+86, 0, @CGUID+708),
(@SPAWN_GROUP+86, 0, @CGUID+709),
(@SPAWN_GROUP+86, 0, @CGUID+710),
(@SPAWN_GROUP+86, 0, @CGUID+711),
(@SPAWN_GROUP+86, 0, @CGUID+712),
(@SPAWN_GROUP+86, 0, @CGUID+713),
(@SPAWN_GROUP+86, 0, @CGUID+714),
(@SPAWN_GROUP+86, 0, @CGUID+715),
(@SPAWN_GROUP+86, 0, @CGUID+716),
(@SPAWN_GROUP+86, 0, @CGUID+717),
(@SPAWN_GROUP+86, 0, @CGUID+718),
(@SPAWN_GROUP+86, 0, @CGUID+719),
(@SPAWN_GROUP+86, 0, @CGUID+720),
(@SPAWN_GROUP+86, 0, @CGUID+721),
(@SPAWN_GROUP+86, 0, @CGUID+722),
(@SPAWN_GROUP+86, 0, @CGUID+723),
(@SPAWN_GROUP+86, 0, @CGUID+724),
(@SPAWN_GROUP+86, 0, @CGUID+725),
(@SPAWN_GROUP+86, 0, @CGUID+726),
(@SPAWN_GROUP+86, 0, @CGUID+727),
(@SPAWN_GROUP+86, 0, @CGUID+728),
(@SPAWN_GROUP+86, 0, @CGUID+729),
(@SPAWN_GROUP+86, 0, @CGUID+730),
(@SPAWN_GROUP+86, 0, @CGUID+731),
(@SPAWN_GROUP+86, 0, @CGUID+732),
(@SPAWN_GROUP+86, 0, @CGUID+733),
(@SPAWN_GROUP+86, 0, @CGUID+734),
(@SPAWN_GROUP+86, 0, @CGUID+735),
(@SPAWN_GROUP+86, 0, @CGUID+736),
(@SPAWN_GROUP+86, 0, @CGUID+737),
(@SPAWN_GROUP+86, 0, @CGUID+738),
(@SPAWN_GROUP+86, 0, @CGUID+739),
(@SPAWN_GROUP+86, 0, @CGUID+740),
(@SPAWN_GROUP+86, 0, @CGUID+741),
(@SPAWN_GROUP+86, 0, @CGUID+742),
(@SPAWN_GROUP+86, 0, @CGUID+743),
(@SPAWN_GROUP+86, 0, @CGUID+744),
(@SPAWN_GROUP+86, 0, @CGUID+745),
(@SPAWN_GROUP+86, 0, @CGUID+746),
(@SPAWN_GROUP+86, 0, @CGUID+747),
(@SPAWN_GROUP+86, 0, @CGUID+748),
(@SPAWN_GROUP+86, 0, @CGUID+749),
(@SPAWN_GROUP+86, 0, @CGUID+750),
(@SPAWN_GROUP+86, 0, @CGUID+751),
(@SPAWN_GROUP+86, 0, @CGUID+752),
(@SPAWN_GROUP+86, 0, @CGUID+753),
(@SPAWN_GROUP+86, 0, @CGUID+754),
(@SPAWN_GROUP+86, 0, @CGUID+755),
(@SPAWN_GROUP+86, 0, @CGUID+756),
(@SPAWN_GROUP+86, 0, @CGUID+757),
(@SPAWN_GROUP+86, 0, @CGUID+758),
(@SPAWN_GROUP+86, 0, @CGUID+759),
(@SPAWN_GROUP+86, 0, @CGUID+760),
(@SPAWN_GROUP+86, 0, @CGUID+761),
(@SPAWN_GROUP+86, 0, @CGUID+762),
(@SPAWN_GROUP+86, 0, @CGUID+763),
(@SPAWN_GROUP+86, 0, @CGUID+764),
(@SPAWN_GROUP+86, 0, @CGUID+765),
(@SPAWN_GROUP+86, 0, @CGUID+766),
(@SPAWN_GROUP+86, 0, @CGUID+767),
(@SPAWN_GROUP+86, 0, @CGUID+768),
(@SPAWN_GROUP+86, 0, @CGUID+769),
(@SPAWN_GROUP+86, 0, @CGUID+770),
(@SPAWN_GROUP+86, 0, @CGUID+771),
(@SPAWN_GROUP+86, 0, @CGUID+772),
(@SPAWN_GROUP+86, 0, @CGUID+773),
(@SPAWN_GROUP+86, 0, @CGUID+774),
(@SPAWN_GROUP+86, 0, @CGUID+775),
(@SPAWN_GROUP+86, 0, @CGUID+776),
(@SPAWN_GROUP+86, 0, @CGUID+777),
(@SPAWN_GROUP+86, 0, @CGUID+778),
(@SPAWN_GROUP+86, 0, @CGUID+779),
(@SPAWN_GROUP+86, 0, @CGUID+780),
(@SPAWN_GROUP+86, 0, @CGUID+781),
(@SPAWN_GROUP+86, 0, @CGUID+782),
(@SPAWN_GROUP+86, 0, @CGUID+783),
(@SPAWN_GROUP+86, 0, @CGUID+784),
(@SPAWN_GROUP+86, 0, @CGUID+785),
(@SPAWN_GROUP+86, 0, @CGUID+786),
(@SPAWN_GROUP+86, 0, @CGUID+787),
(@SPAWN_GROUP+86, 0, @CGUID+788),
(@SPAWN_GROUP+86, 0, @CGUID+789),
(@SPAWN_GROUP+86, 0, @CGUID+790),
-- -- Kobolds
(@SPAWN_GROUP+130, 0, @CGUID+888),
(@SPAWN_GROUP+130, 0, @CGUID+889),
(@SPAWN_GROUP+130, 0, @CGUID+890),
(@SPAWN_GROUP+130, 0, @CGUID+891),
(@SPAWN_GROUP+130, 0, @CGUID+892),
(@SPAWN_GROUP+130, 0, @CGUID+893),
(@SPAWN_GROUP+130, 0, @CGUID+894),
(@SPAWN_GROUP+130, 0, @CGUID+895),
(@SPAWN_GROUP+130, 0, @CGUID+896),
(@SPAWN_GROUP+130, 0, @CGUID+897),
(@SPAWN_GROUP+130, 0, @CGUID+898),
(@SPAWN_GROUP+130, 0, @CGUID+899),
(@SPAWN_GROUP+130, 0, @CGUID+900),
(@SPAWN_GROUP+130, 0, @CGUID+901),
(@SPAWN_GROUP+130, 0, @CGUID+902),
(@SPAWN_GROUP+130, 0, @CGUID+903),
(@SPAWN_GROUP+130, 0, @CGUID+904),
(@SPAWN_GROUP+130, 0, @CGUID+905),
(@SPAWN_GROUP+130, 0, @CGUID+906),
(@SPAWN_GROUP+130, 0, @CGUID+907),
(@SPAWN_GROUP+130, 0, @CGUID+908),
(@SPAWN_GROUP+130, 0, @CGUID+909),
(@SPAWN_GROUP+130, 0, @CGUID+910),
(@SPAWN_GROUP+130, 0, @CGUID+911),
(@SPAWN_GROUP+130, 0, @CGUID+912),
(@SPAWN_GROUP+130, 0, @CGUID+913),
(@SPAWN_GROUP+130, 0, @CGUID+914),
(@SPAWN_GROUP+130, 0, @CGUID+915),
(@SPAWN_GROUP+130, 0, @CGUID+916),
(@SPAWN_GROUP+130, 0, @CGUID+917),
(@SPAWN_GROUP+130, 0, @CGUID+918),
(@SPAWN_GROUP+130, 0, @CGUID+919),
(@SPAWN_GROUP+130, 0, @CGUID+920),
(@SPAWN_GROUP+130, 0, @CGUID+921),
(@SPAWN_GROUP+130, 0, @CGUID+922),
(@SPAWN_GROUP+130, 0, @CGUID+923),
(@SPAWN_GROUP+130, 0, @CGUID+924),
(@SPAWN_GROUP+130, 0, @CGUID+925),
(@SPAWN_GROUP+130, 0, @CGUID+926),
(@SPAWN_GROUP+130, 0, @CGUID+927),
(@SPAWN_GROUP+130, 0, @CGUID+928),
(@SPAWN_GROUP+130, 0, @CGUID+929),
(@SPAWN_GROUP+130, 0, @CGUID+930),
(@SPAWN_GROUP+130, 0, @CGUID+931),
(@SPAWN_GROUP+130, 0, @CGUID+932),
(@SPAWN_GROUP+130, 0, @CGUID+933),
(@SPAWN_GROUP+130, 0, @CGUID+934),
(@SPAWN_GROUP+130, 0, @CGUID+935),
(@SPAWN_GROUP+130, 0, @CGUID+936),
(@SPAWN_GROUP+130, 0, @CGUID+937),
(@SPAWN_GROUP+130, 0, @CGUID+938),
(@SPAWN_GROUP+130, 0, @CGUID+939),
(@SPAWN_GROUP+130, 0, @CGUID+940),
(@SPAWN_GROUP+130, 0, @CGUID+941),
(@SPAWN_GROUP+130, 0, @CGUID+942),
(@SPAWN_GROUP+130, 0, @CGUID+943),
(@SPAWN_GROUP+130, 0, @CGUID+944),
(@SPAWN_GROUP+130, 0, @CGUID+945),
(@SPAWN_GROUP+130, 0, @CGUID+946),
(@SPAWN_GROUP+130, 0, @CGUID+947),
(@SPAWN_GROUP+130, 0, @CGUID+948),
(@SPAWN_GROUP+130, 0, @CGUID+949),
(@SPAWN_GROUP+130, 0, @CGUID+950),
(@SPAWN_GROUP+130, 0, @CGUID+951),
(@SPAWN_GROUP+130, 0, @CGUID+952),
(@SPAWN_GROUP+130, 0, @CGUID+953),
(@SPAWN_GROUP+130, 0, @CGUID+954),
(@SPAWN_GROUP+130, 0, @CGUID+955),
(@SPAWN_GROUP+130, 0, @CGUID+956),
(@SPAWN_GROUP+130, 0, @CGUID+957),
(@SPAWN_GROUP+130, 0, @CGUID+958),
(@SPAWN_GROUP+130, 0, @CGUID+959),
(@SPAWN_GROUP+130, 0, @CGUID+960),
(@SPAWN_GROUP+130, 0, @CGUID+961),
(@SPAWN_GROUP+130, 0, @CGUID+962),
(@SPAWN_GROUP+130, 0, @CGUID+963),
(@SPAWN_GROUP+130, 0, @CGUID+964),
(@SPAWN_GROUP+130, 0, @CGUID+965),
(@SPAWN_GROUP+130, 0, @CGUID+966),
(@SPAWN_GROUP+130, 0, @CGUID+967),
(@SPAWN_GROUP+130, 0, @CGUID+968),
(@SPAWN_GROUP+130, 0, @CGUID+969),
(@SPAWN_GROUP+130, 0, @CGUID+970),
(@SPAWN_GROUP+130, 0, @CGUID+971),
(@SPAWN_GROUP+130, 0, @CGUID+972),
(@SPAWN_GROUP+130, 0, @CGUID+973),
(@SPAWN_GROUP+130, 0, @CGUID+974),
(@SPAWN_GROUP+130, 0, @CGUID+975),
(@SPAWN_GROUP+130, 0, @CGUID+976),
(@SPAWN_GROUP+130, 0, @CGUID+977),
(@SPAWN_GROUP+130, 0, @CGUID+978),

-- Horde mini boss fires
(@SPAWN_GROUP+131, 1, @OGUID+98),
(@SPAWN_GROUP+131, 1, @OGUID+99),
(@SPAWN_GROUP+131, 1, @OGUID+100),
(@SPAWN_GROUP+131, 1, @OGUID+101),
(@SPAWN_GROUP+131, 1, @OGUID+102),

-- Alliance mini boss fires
(@SPAWN_GROUP+132, 1, @OGUID+103),
(@SPAWN_GROUP+132, 1, @OGUID+104),
(@SPAWN_GROUP+132, 1, @OGUID+105),
(@SPAWN_GROUP+132, 1, @OGUID+106),
(@SPAWN_GROUP+132, 1, @OGUID+107);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=33 AND `SourceEntry` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+132;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(33, 0, @SPAWN_GROUP+0, 0, 0, 11, 0, 1325, 1, 0, 0, 0, 0, '', 'Alterac Valley - Aid Station - Alliance Controlled'),
(33, 0, @SPAWN_GROUP+29, 0, 0, 11, 0, 1325, 1, 0, 0, 0, 0, '', 'Alterac Valley - Aid Station - Alliance Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+29, 0, 0, 13, 0, 2, 0, 0, 0, 0, 0, '', 'Alterac Valley - Aid Station - Alliance Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+87, 0, 0, 11, 0, 1325, 1, 0, 0, 0, 0, '', 'Alterac Valley - Aid Station - Alliance Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+87, 0, 0, 13, 0, 2, 1, 0, 0, 0, 0, '', 'Alterac Valley - Aid Station - Alliance Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+101, 0, 0, 11, 0, 1325, 1, 0, 0, 0, 0, '', 'Alterac Valley - Aid Station - Alliance Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+101, 0, 0, 13, 0, 2, 2, 0, 0, 0, 0, '', 'Alterac Valley - Aid Station - Alliance Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+115, 0, 0, 11, 0, 1325, 1, 0, 0, 0, 0, '', 'Alterac Valley - Aid Station - Alliance Controlled - Champion'),
(33, 0, @SPAWN_GROUP+115, 0, 0, 13, 0, 2, 3, 0, 0, 0, 0, '', 'Alterac Valley - Aid Station - Alliance Controlled - Champion'),
(33, 0, @SPAWN_GROUP+1, 0, 0, 11, 0, 1326, 1, 0, 0, 0, 0, '', 'Alterac Valley - Aid Station - Alliance Contested'),
(33, 0, @SPAWN_GROUP+2, 0, 0, 11, 0, 1327, 1, 0, 0, 0, 0, '', 'Alterac Valley - Aid Station - Horde Controlled'),
(33, 0, @SPAWN_GROUP+30, 0, 0, 11, 0, 1327, 1, 0, 0, 0, 0, '', 'Alterac Valley - Aid Station - Horde Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+30, 0, 0, 13, 0, 1, 0, 0, 0, 0, 0, '', 'Alterac Valley - Aid Station - Horde Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+88, 0, 0, 11, 0, 1327, 1, 0, 0, 0, 0, '', 'Alterac Valley - Aid Station - Horde Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+88, 0, 0, 13, 0, 1, 1, 0, 0, 0, 0, '', 'Alterac Valley - Aid Station - Horde Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+102, 0, 0, 11, 0, 1327, 1, 0, 0, 0, 0, '', 'Alterac Valley - Aid Station - Horde Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+102, 0, 0, 13, 0, 1, 2, 0, 0, 0, 0, '', 'Alterac Valley - Aid Station - Horde Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+116, 0, 0, 11, 0, 1327, 1, 0, 0, 0, 0, '', 'Alterac Valley - Aid Station - Horde Controlled - Champion'),
(33, 0, @SPAWN_GROUP+116, 0, 0, 13, 0, 1, 3, 0, 0, 0, 0, '', 'Alterac Valley - Aid Station - Horde Controlled - Champion'),
(33, 0, @SPAWN_GROUP+3, 0, 0, 11, 0, 1328, 1, 0, 0, 0, 0, '', 'Alterac Valley - Aid Station - Horde Contested'),

(33, 0, @SPAWN_GROUP+4, 0, 0, 11, 0, 1333, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stormpike - Alliance Controlled'),
(33, 0, @SPAWN_GROUP+31, 0, 0, 11, 0, 1333, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stormpike - Alliance Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+31, 0, 0, 13, 0, 2, 0, 0, 0, 0, 0, '', 'Alterac Valley - Stormpike - Alliance Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+89, 0, 0, 11, 0, 1333, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stormpike - Alliance Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+89, 0, 0, 13, 0, 2, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stormpike - Alliance Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+103, 0, 0, 11, 0, 1333, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stormpike - Alliance Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+103, 0, 0, 13, 0, 2, 2, 0, 0, 0, 0, '', 'Alterac Valley - Stormpike - Alliance Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+117, 0, 0, 11, 0, 1333, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stormpike - Alliance Controlled - Champion'),
(33, 0, @SPAWN_GROUP+117, 0, 0, 13, 0, 2, 3, 0, 0, 0, 0, '', 'Alterac Valley - Stormpike - Alliance Controlled - Champion'),
(33, 0, @SPAWN_GROUP+5, 0, 0, 11, 0, 1335, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stormpike - Alliance Contested'),
(33, 0, @SPAWN_GROUP+6, 0, 0, 11, 0, 1334, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stormpike - Horde Controlled'),
(33, 0, @SPAWN_GROUP+32, 0, 0, 11, 0, 1334, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stormpike - Horde Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+32, 0, 0, 13, 0, 1, 0, 0, 0, 0, 0, '', 'Alterac Valley - Stormpike - Horde Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+90, 0, 0, 11, 0, 1334, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stormpike - Horde Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+90, 0, 0, 13, 0, 1, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stormpike - Horde Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+104, 0, 0, 11, 0, 1334, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stormpike - Horde Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+104, 0, 0, 13, 0, 1, 2, 0, 0, 0, 0, '', 'Alterac Valley - Stormpike - Horde Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+118, 0, 0, 11, 0, 1334, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stormpike - Horde Controlled - Champion'),
(33, 0, @SPAWN_GROUP+118, 0, 0, 13, 0, 1, 2, 0, 0, 0, 0, '', 'Alterac Valley - Stormpike - Horde Controlled - Champion'),
(33, 0, @SPAWN_GROUP+7, 0, 0, 11, 0, 1336, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stormpike - Horde Contested'),

(33, 0, @SPAWN_GROUP+8, 0, 0, 11, 0, 1302, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stonehearth - Alliance Controlled'),
(33, 0, @SPAWN_GROUP+33, 0, 0, 11, 0, 1302, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stonehearth - Alliance Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+33, 0, 0, 13, 0, 2, 0, 0, 0, 0, 0, '', 'Alterac Valley - Stonehearth - Alliance Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+91, 0, 0, 11, 0, 1302, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stonehearth - Alliance Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+91, 0, 0, 13, 0, 2, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stonehearth - Alliance Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+105, 0, 0, 11, 0, 1302, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stonehearth - Alliance Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+105, 0, 0, 13, 0, 2, 2, 0, 0, 0, 0, '', 'Alterac Valley - Stonehearth - Alliance Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+119, 0, 0, 11, 0, 1302, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stonehearth - Alliance Controlled - Champion'),
(33, 0, @SPAWN_GROUP+119, 0, 0, 13, 0, 2, 3, 0, 0, 0, 0, '', 'Alterac Valley - Stonehearth - Alliance Controlled - Champion'),
(33, 0, @SPAWN_GROUP+9, 0, 0, 11, 0, 1304, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stonehearth - Alliance Contested'),
(33, 0, @SPAWN_GROUP+10, 0, 0, 11, 0, 1301, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stonehearth - Horde Controlled'),
(33, 0, @SPAWN_GROUP+34, 0, 0, 11, 0, 1301, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stonehearth - Horde Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+34, 0, 0, 13, 0, 1, 0, 0, 0, 0, 0, '', 'Alterac Valley - Stonehearth - Horde Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+92, 0, 0, 11, 0, 1301, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stonehearth - Horde Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+92, 0, 0, 13, 0, 1, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stonehearth - Horde Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+106, 0, 0, 11, 0, 1301, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stonehearth - Horde Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+106, 0, 0, 13, 0, 1, 2, 0, 0, 0, 0, '', 'Alterac Valley - Stonehearth - Horde Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+120, 0, 0, 11, 0, 1301, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stonehearth - Horde Controlled - Champion'),
(33, 0, @SPAWN_GROUP+120, 0, 0, 13, 0, 1, 3, 0, 0, 0, 0, '', 'Alterac Valley - Stonehearth - Horde Controlled - Champion'),
(33, 0, @SPAWN_GROUP+11, 0, 0, 11, 0, 1303, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stonehearth - Horde Contested'),

(33, 0, @SPAWN_GROUP+12, 0, 0, 11, 0, 1966, 1, 0, 0, 0, 0, '', 'Alterac Valley - Snowfall - Neutral Controlled'),
(33, 0, @SPAWN_GROUP+13, 0, 0, 11, 0, 1341, 1, 0, 0, 0, 0, '', 'Alterac Valley - Snowfall - Alliance Controlled'),
(33, 0, @SPAWN_GROUP+35, 0, 0, 11, 0, 1341, 1, 0, 0, 0, 0, '', 'Alterac Valley - Snowfall - Alliance Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+35, 0, 0, 13, 0, 2, 0, 0, 0, 0, 0, '', 'Alterac Valley - Snowfall - Alliance Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+93, 0, 0, 11, 0, 1341, 1, 0, 0, 0, 0, '', 'Alterac Valley - Snowfall - Alliance Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+93, 0, 0, 13, 0, 2, 1, 0, 0, 0, 0, '', 'Alterac Valley - Snowfall - Alliance Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+107, 0, 0, 11, 0, 1341, 1, 0, 0, 0, 0, '', 'Alterac Valley - Snowfall - Alliance Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+107, 0, 0, 13, 0, 2, 2, 0, 0, 0, 0, '', 'Alterac Valley - Snowfall - Alliance Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+121, 0, 0, 11, 0, 1341, 1, 0, 0, 0, 0, '', 'Alterac Valley - Snowfall - Alliance Controlled - Champion'),
(33, 0, @SPAWN_GROUP+121, 0, 0, 13, 0, 2, 3, 0, 0, 0, 0, '', 'Alterac Valley - Snowfall - Alliance Controlled - Champion'),
(33, 0, @SPAWN_GROUP+14, 0, 0, 11, 0, 1343, 1, 0, 0, 0, 0, '', 'Alterac Valley - Snowfall - Alliance Contested'),
(33, 0, @SPAWN_GROUP+15, 0, 0, 11, 0, 1342, 1, 0, 0, 0, 0, '', 'Alterac Valley - Snowfall - Horde Controlled'),
(33, 0, @SPAWN_GROUP+36, 0, 0, 11, 0, 1342, 1, 0, 0, 0, 0, '', 'Alterac Valley - Snowfall - Horde Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+36, 0, 0, 13, 0, 1, 0, 0, 0, 0, 0, '', 'Alterac Valley - Snowfall - Horde Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+94, 0, 0, 11, 0, 1342, 1, 0, 0, 0, 0, '', 'Alterac Valley - Snowfall - Horde Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+94, 0, 0, 13, 0, 1, 1, 0, 0, 0, 0, '', 'Alterac Valley - Snowfall - Horde Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+108, 0, 0, 11, 0, 1342, 1, 0, 0, 0, 0, '', 'Alterac Valley - Snowfall - Horde Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+108, 0, 0, 13, 0, 1, 2, 0, 0, 0, 0, '', 'Alterac Valley - Snowfall - Horde Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+122, 0, 0, 11, 0, 1342, 1, 0, 0, 0, 0, '', 'Alterac Valley - Snowfall - Horde Controlled - Champion'),
(33, 0, @SPAWN_GROUP+122, 0, 0, 13, 0, 1, 3, 0, 0, 0, 0, '', 'Alterac Valley - Snowfall - Horde Controlled - Champion'),
(33, 0, @SPAWN_GROUP+16, 0, 0, 11, 0, 1344, 1, 0, 0, 0, 0, '', 'Alterac Valley - Snowfall - Horde Contested'),

(33, 0, @SPAWN_GROUP+17, 0, 0, 11, 0, 1346, 1, 0, 0, 0, 0, '', 'Alterac Valley - Iceblood - Alliance Controlled'),
(33, 0, @SPAWN_GROUP+37, 0, 0, 11, 0, 1346, 1, 0, 0, 0, 0, '', 'Alterac Valley - Iceblood - Alliance Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+37, 0, 0, 13, 0, 2, 0, 0, 0, 0, 0, '', 'Alterac Valley - Iceblood - Alliance Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+95, 0, 0, 11, 0, 1346, 1, 0, 0, 0, 0, '', 'Alterac Valley - Iceblood - Alliance Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+95, 0, 0, 13, 0, 2, 1, 0, 0, 0, 0, '', 'Alterac Valley - Iceblood - Alliance Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+109, 0, 0, 11, 0, 1346, 1, 0, 0, 0, 0, '', 'Alterac Valley - Iceblood - Alliance Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+109, 0, 0, 13, 0, 2, 2, 0, 0, 0, 0, '', 'Alterac Valley - Iceblood - Alliance Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+123, 0, 0, 11, 0, 1346, 1, 0, 0, 0, 0, '', 'Alterac Valley - Iceblood - Alliance Controlled - Champion'),
(33, 0, @SPAWN_GROUP+123, 0, 0, 13, 0, 2, 3, 0, 0, 0, 0, '', 'Alterac Valley - Iceblood - Alliance Controlled - Champion'),
(33, 0, @SPAWN_GROUP+18, 0, 0, 11, 0, 1348, 1, 0, 0, 0, 0, '', 'Alterac Valley - Iceblood - Alliance Contested'),
(33, 0, @SPAWN_GROUP+19, 0, 0, 11, 0, 1347, 1, 0, 0, 0, 0, '', 'Alterac Valley - Iceblood - Horde Controlled'),
(33, 0, @SPAWN_GROUP+38, 0, 0, 11, 0, 1347, 1, 0, 0, 0, 0, '', 'Alterac Valley - Iceblood - Horde Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+38, 0, 0, 13, 0, 1, 0, 0, 0, 0, 0, '', 'Alterac Valley - Iceblood - Horde Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+96, 0, 0, 11, 0, 1347, 1, 0, 0, 0, 0, '', 'Alterac Valley - Iceblood - Horde Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+96, 0, 0, 13, 0, 1, 1, 0, 0, 0, 0, '', 'Alterac Valley - Iceblood - Horde Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+110, 0, 0, 11, 0, 1347, 1, 0, 0, 0, 0, '', 'Alterac Valley - Iceblood - Horde Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+110, 0, 0, 13, 0, 1, 2, 0, 0, 0, 0, '', 'Alterac Valley - Iceblood - Horde Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+124, 0, 0, 11, 0, 1347, 1, 0, 0, 0, 0, '', 'Alterac Valley - Iceblood - Horde Controlled - Champion'),
(33, 0, @SPAWN_GROUP+124, 0, 0, 13, 0, 1, 3, 0, 0, 0, 0, '', 'Alterac Valley - Iceblood - Horde Controlled - Champion'),
(33, 0, @SPAWN_GROUP+20, 0, 0, 11, 0, 1349, 1, 0, 0, 0, 0, '', 'Alterac Valley - Iceblood - Horde Contested'),

(33, 0, @SPAWN_GROUP+21, 0, 0, 11, 0, 1337, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf - Alliance Controlled'),
(33, 0, @SPAWN_GROUP+39, 0, 0, 11, 0, 1337, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf - Alliance Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+39, 0, 0, 13, 0, 2, 0, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf - Alliance Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+97, 0, 0, 11, 0, 1337, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf - Alliance Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+97, 0, 0, 13, 0, 2, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf - Alliance Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+111, 0, 0, 11, 0, 1337, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf - Alliance Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+111, 0, 0, 13, 0, 2, 2, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf - Alliance Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+125, 0, 0, 11, 0, 1337, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf - Alliance Controlled - Champion'),
(33, 0, @SPAWN_GROUP+125, 0, 0, 13, 0, 2, 3, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf - Alliance Controlled - Champion'),
(33, 0, @SPAWN_GROUP+22, 0, 0, 11, 0, 1339, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf - Alliance Contested'),
(33, 0, @SPAWN_GROUP+23, 0, 0, 11, 0, 1338, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf - Horde Controlled'),
(33, 0, @SPAWN_GROUP+40, 0, 0, 11, 0, 1338, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf - Horde Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+40, 0, 0, 13, 0, 1, 0, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf - Horde Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+98, 0, 0, 11, 0, 1338, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf - Horde Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+98, 0, 0, 13, 0, 1, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf - Horde Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+112, 0, 0, 11, 0, 1338, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf - Horde Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+112, 0, 0, 13, 0, 1, 2, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf - Horde Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+126, 0, 0, 11, 0, 1338, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf - Horde Controlled - Champion'),
(33, 0, @SPAWN_GROUP+126, 0, 0, 13, 0, 1, 3, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf - Horde Controlled - Champion'),
(33, 0, @SPAWN_GROUP+24, 0, 0, 11, 0, 1340, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf - Horde Contested'),

(33, 0, @SPAWN_GROUP+25, 0, 0, 11, 0, 1329, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf Hut - Alliance Controlled'),
(33, 0, @SPAWN_GROUP+41, 0, 0, 11, 0, 1329, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf Hut - Alliance Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+41, 0, 0, 13, 0, 2, 0, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf Hut - Alliance Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+99, 0, 0, 11, 0, 1329, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf Hut - Alliance Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+99, 0, 0, 13, 0, 2, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf Hut - Alliance Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+113, 0, 0, 11, 0, 1329, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf Hut - Alliance Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+113, 0, 0, 13, 0, 2, 2, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf Hut - Alliance Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+127, 0, 0, 11, 0, 1329, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf Hut - Alliance Controlled - Champion'),
(33, 0, @SPAWN_GROUP+127, 0, 0, 13, 0, 2, 3, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf Hut - Alliance Controlled - Champion'),
(33, 0, @SPAWN_GROUP+26, 0, 0, 11, 0, 1331, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf Hut - Alliance Contested'),
(33, 0, @SPAWN_GROUP+27, 0, 0, 11, 0, 1330, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf Hut - Horde Controlled'),
(33, 0, @SPAWN_GROUP+42, 0, 0, 11, 0, 1330, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf Hut - Horde Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+42, 0, 0, 13, 0, 1, 0, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf Hut - Horde Controlled - Defenders'),
(33, 0, @SPAWN_GROUP+100, 0, 0, 11, 0, 1330, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf Hut - Horde Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+100, 0, 0, 13, 0, 1, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf Hut - Horde Controlled - Seasoned'),
(33, 0, @SPAWN_GROUP+114, 0, 0, 11, 0, 1330, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf Hut - Horde Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+114, 0, 0, 13, 0, 1, 2, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf Hut - Horde Controlled - Veteran'),
(33, 0, @SPAWN_GROUP+128, 0, 0, 11, 0, 1330, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf Hut - Horde Controlled - Champion'),
(33, 0, @SPAWN_GROUP+128, 0, 0, 13, 0, 1, 3, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf Hut - Horde Controlled - Champion'),
(33, 0, @SPAWN_GROUP+28, 0, 0, 11, 0, 1332, 1, 0, 0, 0, 0, '', 'Alterac Valley - Frostwolf Hut - Horde Contested'),

(33, 0, @SPAWN_GROUP+43, 0, 0, 11, 0, 1362, 1, 0, 0, 0, 0, '', 'Alterac Valley - North Bunker - Controlled'),
(33, 0, @SPAWN_GROUP+44, 0, 0, 11, 0, 1379, 1, 0, 0, 0, 0, '', 'Alterac Valley - North Bunker - Contested'),
(33, 0, @SPAWN_GROUP+45, 0, 0, 11, 0, 1371, 1, 0, 0, 0, 0, '', 'Alterac Valley - North Bunker - Destroyed'),
(33, 0, @SPAWN_GROUP+46, 0, 0, 11, 0, 1362, 1, 0, 0, 0, 0, '', 'Alterac Valley - North Bunker - Controlled'),
(33, 0, @SPAWN_GROUP+75, 0, 0, 11, 0, 1371, 0, 0, 0, 0, 0, '', 'Alterac Valley - North Bunker - NOT Destroyed'),

(33, 0, @SPAWN_GROUP+47, 0, 0, 11, 0, 1361, 1, 0, 0, 0, 0, '', 'Alterac Valley - South Bunker - Controlled'),
(33, 0, @SPAWN_GROUP+48, 0, 0, 11, 0, 1378, 1, 0, 0, 0, 0, '', 'Alterac Valley - South Bunker - Contested'),
(33, 0, @SPAWN_GROUP+49, 0, 0, 11, 0, 1370, 1, 0, 0, 0, 0, '', 'Alterac Valley - South Bunker - Destroyed'),
(33, 0, @SPAWN_GROUP+50, 0, 0, 11, 0, 1361, 1, 0, 0, 0, 0, '', 'Alterac Valley - South Bunker - Controlled'),
(33, 0, @SPAWN_GROUP+76, 0, 0, 11, 0, 1370, 0, 0, 0, 0, 0, '', 'Alterac Valley - South Bunker - NOT Destroyed'),

(33, 0, @SPAWN_GROUP+51, 0, 0, 11, 0, 1363, 1, 0, 0, 0, 0, '', 'Alterac Valley - Icewing Bunker - Controlled'),
(33, 0, @SPAWN_GROUP+52, 0, 0, 11, 0, 1380, 1, 0, 0, 0, 0, '', 'Alterac Valley - Icewing Bunker - Contested'),
(33, 0, @SPAWN_GROUP+53, 0, 0, 11, 0, 1372, 1, 0, 0, 0, 0, '', 'Alterac Valley - Icewing Bunker - Destroyed'),
(33, 0, @SPAWN_GROUP+54, 0, 0, 11, 0, 1363, 1, 0, 0, 0, 0, '', 'Alterac Valley - Icewing Bunker - Controlled'),
(33, 0, @SPAWN_GROUP+77, 0, 0, 11, 0, 1372, 0, 0, 0, 0, 0, '', 'Alterac Valley - Icewing Bunker - NOT Destroyed'),

(33, 0, @SPAWN_GROUP+55, 0, 0, 11, 0, 1364, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stonehearth Bunker - Controlled'),
(33, 0, @SPAWN_GROUP+56, 0, 0, 11, 0, 1381, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stonehearth Bunker - Contested'),
(33, 0, @SPAWN_GROUP+57, 0, 0, 11, 0, 1373, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stonehearth Bunker - Destroyed'),
(33, 0, @SPAWN_GROUP+58, 0, 0, 11, 0, 1364, 1, 0, 0, 0, 0, '', 'Alterac Valley - Stonehearth Bunker - Controlled'),
(33, 0, @SPAWN_GROUP+78, 0, 0, 11, 0, 1373, 0, 0, 0, 0, 0, '', 'Alterac Valley - Stonehearth Bunker - NOT Destroyed'),

(33, 0, @SPAWN_GROUP+59, 0, 0, 11, 0, 1385, 1, 0, 0, 0, 0, '', 'Alterac Valley - Iceblood Tower - Controlled'),
(33, 0, @SPAWN_GROUP+60, 0, 0, 11, 0, 1390, 1, 0, 0, 0, 0, '', 'Alterac Valley - Iceblood Tower - Contested'),
(33, 0, @SPAWN_GROUP+61, 0, 0, 11, 0, 1368, 1, 0, 0, 0, 0, '', 'Alterac Valley - Iceblood Tower - Destroyed'),
(33, 0, @SPAWN_GROUP+62, 0, 0, 11, 0, 1385, 1, 0, 0, 0, 0, '', 'Alterac Valley - Iceblood Tower - Controlled'),
(33, 0, @SPAWN_GROUP+79, 0, 0, 11, 0, 1368, 0, 0, 0, 0, 0, '', 'Alterac Valley - Iceblood Tower - NOT Destroyed'),


(33, 0, @SPAWN_GROUP+63, 0, 0, 11, 0, 1382, 1, 0, 0, 0, 0, '', 'Alterac Valley - Tower Point - Controlled'),
(33, 0, @SPAWN_GROUP+64, 0, 0, 11, 0, 1387, 1, 0, 0, 0, 0, '', 'Alterac Valley - Tower Point - Contested'),
(33, 0, @SPAWN_GROUP+65, 0, 0, 11, 0, 1367, 1, 0, 0, 0, 0, '', 'Alterac Valley - Tower Point - Destroyed'),
(33, 0, @SPAWN_GROUP+66, 0, 0, 11, 0, 1382, 1, 0, 0, 0, 0, '', 'Alterac Valley - Tower Point - Controlled'),
(33, 0, @SPAWN_GROUP+80, 0, 0, 11, 0, 1367, 0, 0, 0, 0, 0, '', 'Alterac Valley - Tower Point - NOT Destroyed'),

(33, 0, @SPAWN_GROUP+67, 0, 0, 11, 0, 1383, 1, 0, 0, 0, 0, '', 'Alterac Valley - East Tower - Controlled'),
(33, 0, @SPAWN_GROUP+68, 0, 0, 11, 0, 1388, 1, 0, 0, 0, 0, '', 'Alterac Valley - East Tower - Contested'),
(33, 0, @SPAWN_GROUP+69, 0, 0, 11, 0, 1366, 1, 0, 0, 0, 0, '', 'Alterac Valley - East Tower - Destroyed'),
(33, 0, @SPAWN_GROUP+70, 0, 0, 11, 0, 1383, 1, 0, 0, 0, 0, '', 'Alterac Valley - East Tower - Controlled'),
(33, 0, @SPAWN_GROUP+81, 0, 0, 11, 0, 1366, 0, 0, 0, 0, 0, '', 'Alterac Valley - East Tower - NOT Destroyed'),

(33, 0, @SPAWN_GROUP+71, 0, 0, 11, 0, 1382, 1, 0, 0, 0, 0, '', 'Alterac Valley - East Tower - Controlled'),
(33, 0, @SPAWN_GROUP+72, 0, 0, 11, 0, 1387, 1, 0, 0, 0, 0, '', 'Alterac Valley - East Tower - Contested'),
(33, 0, @SPAWN_GROUP+73, 0, 0, 11, 0, 1365, 1, 0, 0, 0, 0, '', 'Alterac Valley - East Tower - Destroyed'),
(33, 0, @SPAWN_GROUP+74, 0, 0, 11, 0, 1382, 1, 0, 0, 0, 0, '', 'Alterac Valley - East Tower - Controlled'),
(33, 0, @SPAWN_GROUP+82, 0, 0, 11, 0, 1365, 0, 0, 0, 0, 0, '', 'Alterac Valley - East Tower - NOT Destroyed'),

(33, 0, @SPAWN_GROUP+83, 0, 0, 11, 0, 1358, 1, 0, 0, 0, 0, '', 'Alterac Valley - Irondeep Mine - Alliance Controlled'),
(33, 0, @SPAWN_GROUP+84, 0, 0, 11, 0, 1359, 1, 0, 0, 0, 0, '', 'Alterac Valley - Irondeep Mine - Horde Controlled'),
(33, 0, @SPAWN_GROUP+85, 0, 0, 11, 0, 1355, 1, 0, 0, 0, 0, '', 'Alterac Valley - Coldtooth Mine - Alliance Controlled'),
(33, 0, @SPAWN_GROUP+86, 0, 0, 11, 0, 1356, 1, 0, 0, 0, 0, '', 'Alterac Valley - Coldtooth Mine - Horde Controlled'),
(33, 0, @SPAWN_GROUP+129, 0, 0, 11, 0, 1360, 1, 0, 0, 0, 0, '', 'Alterac Valley - Irondeep Mine - Neutral Controlled'),
(33, 0, @SPAWN_GROUP+130, 0, 0, 11, 0, 1357, 1, 0, 0, 0, 0, '', 'Alterac Valley - Coldtooth Mine - Neutral Controlled'),

(33, 0, @SPAWN_GROUP+131, 0, 0, 11, 0, 1352, 0, 0, 0, 0, 0, '', 'Alterac Valley - Horde mini boss fires - Dead'),
(33, 0, @SPAWN_GROUP+132, 0, 0, 11, 0, 1351, 0, 0, 0, 0, 0, '', 'Alterac Valley - Alliance mini boss fires - Dead');

-- Graveyards
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1146;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
-- Aid Station
(@CGUID+345, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, 635.945, -33.6171, 45.7164, 4.97419, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+346, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, 635.17, -29.5594, 46.5056, 4.81711, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+347, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, 642.488, -32.9437, 46.365, 4.67748, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+348, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, 642.326, -27.9442, 46.9211, 4.59022, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+349, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, 635.945, -33.6171, 45.7164, 4.97419, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+350, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, 635.17, -29.5594, 46.5056, 4.81711, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+351, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, 642.488, -32.9437, 46.365, 4.67748, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+352, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, 642.326, -27.9442, 46.9211, 4.59022, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+353, 13116, 30, 2597, 0, '0', '0', 0, 0, 1, 643.3094482421875, 37.69200515747070312, 69.06235504150390625, 1.570796370506286621, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 51536), -- Alliance Spirit Guide (Area: Dun Baldar - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+354, 13117, 30, 2597, 0, '0', '0', 0, 0, 1, 643.3094482421875, 37.69200515747070312, 69.06235504150390625, 1.570796370506286621, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 0), -- Horde Spirit Guide (Area: Dun Baldar - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)

-- Seasoned
(@CGUID+979, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, 635.945, -33.6171, 45.7164, 4.97419, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+980, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, 635.17, -29.5594, 46.5056, 4.81711, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+981, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, 642.488, -32.9437, 46.365, 4.67748, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+982, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, 642.326, -27.9442, 46.9211, 4.59022, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+983, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, 635.945, -33.6171, 45.7164, 4.97419, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+984, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, 635.17, -29.5594, 46.5056, 4.81711, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+985, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, 642.488, -32.9437, 46.365, 4.67748, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+986, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, 642.326, -27.9442, 46.9211, 4.59022, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)

-- Veteran
(@CGUID+987, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, 635.945, -33.6171, 45.7164, 4.97419, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+988, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, 635.17, -29.5594, 46.5056, 4.81711, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+989, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, 642.488, -32.9437, 46.365, 4.67748, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+990, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, 642.326, -27.9442, 46.9211, 4.59022, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+991, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, 635.945, -33.6171, 45.7164, 4.97419, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+992, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, 635.17, -29.5594, 46.5056, 4.81711, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+993, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, 642.488, -32.9437, 46.365, 4.67748, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+994, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, 642.326, -27.9442, 46.9211, 4.59022, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)

-- Champion
(@CGUID+995, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, 635.945, -33.6171, 45.7164, 4.97419, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+996, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, 635.17, -29.5594, 46.5056, 4.81711, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+997, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, 642.488, -32.9437, 46.365, 4.67748, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+998, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, 642.326, -27.9442, 46.9211, 4.59022, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+999, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, 635.945, -33.6171, 45.7164, 4.97419, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1000, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, 635.17, -29.5594, 46.5056, 4.81711, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1001, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, 642.488, -32.9437, 46.365, 4.67748, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1002, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, 642.326, -27.9442, 46.9211, 4.59022, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)

-- Stormpike Graveyard
(@CGUID+355, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, 669.64886474609375, -289.406524658203125, 30.24008941650390625, 1.466076612472534179, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+356, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, 675.58917236328125, -290.1754150390625, 30.67531394958496093, 3.682644605636596679, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+357, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, 668.32159423828125, -297.358551025390625, 30.37424468994140625, 3.822271108627319335, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+358, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, 673.234619140625, -298.55029296875, 30.4912567138671875, 1.029744267463684082, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+359, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, 669.64886474609375, -289.406524658203125, 30.24008941650390625, 1.466076612472534179, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 51886), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+360, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, 675.58917236328125, -290.1754150390625, 30.67531394958496093, 3.682644605636596679, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 51886), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+361, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, 668.32159423828125, -297.358551025390625, 30.37424468994140625, 3.822271108627319335, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 51886), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+362, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, 673.234619140625, -298.55029296875, 30.4912567138671875, 1.029744267463684082, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 51886), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+363, 13117, 30, 2597, 0, '0', '0', 0, 0, 1, 673.1029052734375, -367.582183837890625, 29.86406135559082031, 5.16617441177368164, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 51886), -- Horde Spirit Guide (Area: Dun Baldar - Difficulty: 0) CreateObject2 (Auras: 9036 - Ghost)
(@CGUID+364, 13116, 30, 2597, 0, '0', '0', 0, 0, 1, 673.1029052734375, -367.582183837890625, 29.86406135559082031, 5.16617441177368164, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 0), -- Alliance Spirit Guide (Area: Dun Baldar - Difficulty: 0) CreateObject2 (Auras: 9036 - Ghost)

-- Seasoned
(@CGUID+1003, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, 669.64886474609375, -289.406524658203125, 30.24008941650390625, 1.466076612472534179, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1004, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, 675.58917236328125, -290.1754150390625, 30.67531394958496093, 3.682644605636596679, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1005, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, 668.32159423828125, -297.358551025390625, 30.37424468994140625, 3.822271108627319335, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1006, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, 673.234619140625, -298.55029296875, 30.4912567138671875, 1.029744267463684082, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1007, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, 669.64886474609375, -289.406524658203125, 30.24008941650390625, 1.466076612472534179, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1008, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, 675.58917236328125, -290.1754150390625, 30.67531394958496093, 3.682644605636596679, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1009, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, 668.32159423828125, -297.358551025390625, 30.37424468994140625, 3.822271108627319335, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1010, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, 673.234619140625, -298.55029296875, 30.4912567138671875, 1.029744267463684082, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)

-- Veteran
(@CGUID+1011, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, 669.64886474609375, -289.406524658203125, 30.24008941650390625, 1.466076612472534179, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1012, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, 675.58917236328125, -290.1754150390625, 30.67531394958496093, 3.682644605636596679, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1013, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, 668.32159423828125, -297.358551025390625, 30.37424468994140625, 3.822271108627319335, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1014, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, 673.234619140625, -298.55029296875, 30.4912567138671875, 1.029744267463684082, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1015, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, 669.64886474609375, -289.406524658203125, 30.24008941650390625, 1.466076612472534179, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1016, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, 675.58917236328125, -290.1754150390625, 30.67531394958496093, 3.682644605636596679, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1017, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, 668.32159423828125, -297.358551025390625, 30.37424468994140625, 3.822271108627319335, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1018, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, 673.234619140625, -298.55029296875, 30.4912567138671875, 1.029744267463684082, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)

-- Champion
(@CGUID+1019, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, 669.64886474609375, -289.406524658203125, 30.24008941650390625, 1.466076612472534179, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1020, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, 675.58917236328125, -290.1754150390625, 30.67531394958496093, 3.682644605636596679, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1021, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, 668.32159423828125, -297.358551025390625, 30.37424468994140625, 3.822271108627319335, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1022, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, 673.234619140625, -298.55029296875, 30.4912567138671875, 1.029744267463684082, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1023, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, 669.64886474609375, -289.406524658203125, 30.24008941650390625, 1.466076612472534179, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1024, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, 675.58917236328125, -290.1754150390625, 30.67531394958496093, 3.682644605636596679, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1025, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, 668.32159423828125, -297.358551025390625, 30.37424468994140625, 3.822271108627319335, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1026, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, 673.234619140625, -298.55029296875, 30.4912567138671875, 1.029744267463684082, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)

-- Stonehearth
(@CGUID+365, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, 70.484375, -429.736114501953125, 61.140625, 3.822271108627319335, 300, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+366, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, 78.11284637451171875, -425.279510498046875, 61.40972137451171875, 3.682644605636596679, 300, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+367, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, 74.548614501953125, -432.458343505859375, 61.88367843627929687, 1.029744267463684082, 300, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+368, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, 74.01909637451171875, -422.24652099609375, 60.65625, 1.466076612472534179, 300, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+369, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, 70.484375, -429.736114501953125, 61.140625, 3.822271108627319335, 300, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 51886), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+370, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, 78.11284637451171875, -425.279510498046875, 61.40972137451171875, 3.682644605636596679, 300, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 51886), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+371, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, 74.548614501953125, -432.458343505859375, 61.88367843627929687, 1.029744267463684082, 300, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 51886), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+372, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, 74.01909637451171875, -422.24652099609375, 60.65625, 1.466076612472534179, 300, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 51886), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+373, 13117, 30, 2597, 0, '0', '0', 0, 0, 1, 73.24478912353515625, -487.845489501953125, 70.8417205810546875, 4.747295379638671875, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 51886), -- Horde Spirit Guide (Area: Dun Baldar - Difficulty: 0) CreateObject2 (Auras: 9036 - Ghost)
(@CGUID+374, 13116, 30, 2597, 0, '0', '0', 0, 0, 1, 73.26041412353515625, -488.182281494140625, 70.9157257080078125, 4.764749050140380859, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 51886), -- Alliance Spirit Guide (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost)

-- Seasoned
(@CGUID+1027, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, 70.484375, -429.736114501953125, 61.140625, 3.822271108627319335, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1028, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, 78.11284637451171875, -425.279510498046875, 61.40972137451171875, 3.682644605636596679, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1029, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, 74.548614501953125, -432.458343505859375, 61.88367843627929687, 1.029744267463684082, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1030, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, 74.01909637451171875, -422.24652099609375, 60.65625, 1.466076612472534179, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1031, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, 70.484375, -429.736114501953125, 61.140625, 3.822271108627319335, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1032, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, 78.11284637451171875, -425.279510498046875, 61.40972137451171875, 3.682644605636596679, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1033, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, 74.548614501953125, -432.458343505859375, 61.88367843627929687, 1.029744267463684082, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1034, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, 74.01909637451171875, -422.24652099609375, 60.65625, 1.466076612472534179, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)

-- Veteran
(@CGUID+1035, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, 70.484375, -429.736114501953125, 61.140625, 3.822271108627319335, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1036, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, 78.11284637451171875, -425.279510498046875, 61.40972137451171875, 3.682644605636596679, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1037, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, 74.548614501953125, -432.458343505859375, 61.88367843627929687, 1.029744267463684082, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1038, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, 74.01909637451171875, -422.24652099609375, 60.65625, 1.466076612472534179, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1039, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, 70.484375, -429.736114501953125, 61.140625, 3.822271108627319335, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1040, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, 78.11284637451171875, -425.279510498046875, 61.40972137451171875, 3.682644605636596679, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1041, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, 74.548614501953125, -432.458343505859375, 61.88367843627929687, 1.029744267463684082, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1042, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, 74.01909637451171875, -422.24652099609375, 60.65625, 1.466076612472534179, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)

-- Champion
(@CGUID+1043, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, 70.484375, -429.736114501953125, 61.140625, 3.822271108627319335, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1044, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, 78.11284637451171875, -425.279510498046875, 61.40972137451171875, 3.682644605636596679, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1045, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, 74.548614501953125, -432.458343505859375, 61.88367843627929687, 1.029744267463684082, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1046, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, 74.01909637451171875, -422.24652099609375, 60.65625, 1.466076612472534179, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1047, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, 70.484375, -429.736114501953125, 61.140625, 3.822271108627319335, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1048, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, 78.11284637451171875, -425.279510498046875, 61.40972137451171875, 3.682644605636596679, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1049, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, 74.548614501953125, -432.458343505859375, 61.88367843627929687, 1.029744267463684082, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1050, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, 74.01909637451171875, -422.24652099609375, 60.65625, 1.466076612472534179, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)

-- Snow fall
(@CGUID+375, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, -207.412, -110.616, 78.7959, 2.43251, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: Iceblood Garrison - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+376, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, -197.95, -112.205, 78.5686, 6.22441, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: Iceblood Garrison - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+377, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, -202.709, -116.829, 78.4358, 5.13742, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: Iceblood Garrison - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+378, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, -202.059, -108.314, 78.5783, 5.91968, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: Iceblood Garrison - Difficulty: 0) CreateOb
(@CGUID+379, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, -207.412, -110.616, 78.7959, 2.43251, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: Iceblood Garrison - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+380, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, -197.95, -112.205, 78.5686, 6.22441, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: Iceblood Garrison - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+381, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, -202.709, -116.829, 78.4358, 5.13742, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: Iceblood Garrison - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+382, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, -202.059, -108.314, 78.5783, 5.91968, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: Iceblood Garrison - Difficulty: 0) CreateOb
(@CGUID+383, 13116, 30, 2597, 0, '0', '0', 0, 0, 1, -160.63818359375, 18.41368293762207031, 77.21405029296875, 1.378810048103332519, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 51886), -- Alliance Spirit Guide (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost)
(@CGUID+384, 13117, 30, 2597, 0, '0', '0', 0, 0, 1, -160.63818359375, 18.41368293762207031, 77.21405029296875, 1.378810048103332519, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 0), -- Horde Spirit Guide (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost)

-- Seasoned
(@CGUID+1051, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, -207.412, -110.616, 78.7959, 2.43251, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1052, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, -197.95, -112.205, 78.5686, 6.22441, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1053, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, -202.709, -116.829, 78.4358, 5.13742, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1054, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, -202.059, -108.314, 78.5783, 5.91968, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1055, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, -207.412, -110.616, 78.7959, 2.43251, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1056, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, -197.95, -112.205, 78.5686, 6.22441, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1057, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, -202.709, -116.829, 78.4358, 5.13742, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1058, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, -202.059, -108.314, 78.5783, 5.91968, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)

-- Veteran
(@CGUID+1059, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, -207.412, -110.616, 78.7959, 2.43251, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1060, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, -197.95, -112.205, 78.5686, 6.22441, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1061, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, -202.709, -116.829, 78.4358, 5.13742, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1062, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, -202.059, -108.314, 78.5783, 5.91968, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1063, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, -207.412, -110.616, 78.7959, 2.43251, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1064, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, -197.95, -112.205, 78.5686, 6.22441, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1065, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, -202.709, -116.829, 78.4358, 5.13742, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1066, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, -202.059, -108.314, 78.5783, 5.91968, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)

-- Champion
(@CGUID+1067, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, -207.412, -110.616, 78.7959, 2.43251, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1068, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, -197.95, -112.205, 78.5686, 6.22441, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1069, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, -202.709, -116.829, 78.4358, 5.13742, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1070, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, -202.059, -108.314, 78.5783, 5.91968, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1071, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, -207.412, -110.616, 78.7959, 2.43251, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1072, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, -197.95, -112.205, 78.5686, 6.22441, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1073, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, -202.709, -116.829, 78.4358, 5.13742, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1074, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, -202.059, -108.314, 78.5783, 5.91968, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)

-- Ice Blood
(@CGUID+385, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, -613.73370361328125, -401.389312744140625, 60.34963607788085937, 1.466076612472534179, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 51886), -- Frostwolf Guardian (Area: Rock of Durotan - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+386, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, -613.90045166015625, -392.946502685546875, 60.86960601806640625, 3.682644605636596679, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 51886), -- Frostwolf Guardian (Area: Rock of Durotan - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+387, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, -609.3848876953125, -401.670684814453125, 60.6593475341796875, 1.008414268493652343, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 51886), -- Frostwolf Guardian (Area: Rock of Durotan - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+388, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, -617.5914306640625, -395.850372314453125, 60.536865234375, 3.822271108627319335, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 51886), -- Frostwolf Guardian (Area: Rock of Durotan - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+389, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, -609.4500732421875, -399.5771484375, 60.81250762939453125, 3.577924966812133789, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 51886), -- Stormpike Defender (Area: Rock of Durotan - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+390, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, -612.72119140625, -400.53265380859375, 60.76984786987304687, 4.384785175323486328, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 51886), -- Stormpike Defender (Area: Rock of Durotan - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+391, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, -615.45245361328125, -395.424163818359375, 60.94172286987304687, 6.17846536636352539, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 51886), -- Stormpike Defender (Area: Rock of Durotan - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+392, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, -612.69830322265625, -393.534515380859375, 60.92432785034179687, 0.48869219422340393, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 51886), -- Stormpike Defender (Area: Rock of Durotan - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+393, 13117, 30, 2597, 0, '0', '0', 0, 0, 1, -540.95611572265625, -397.119476318359375, 50.09281539916992187, 5.567600250244140625, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 51536), -- Horde Spirit Guide (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost)
(@CGUID+394, 13116, 30, 2597, 0, '0', '0', 0, 0, 1, -540.95611572265625, -397.119476318359375, 50.09281539916992187, 5.567600250244140625, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 0), -- Alliance Spirit Guide (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost)

-- Seasoned
(@CGUID+1075, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, -609.4500732421875, -399.5771484375, 60.81250762939453125, 3.577924966812133789, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1076, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, -612.72119140625, -400.53265380859375, 60.76984786987304687, 4.384785175323486328, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1077, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, -615.45245361328125, -395.424163818359375, 60.94172286987304687, 6.17846536636352539, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1078, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, -612.69830322265625, -393.534515380859375, 60.92432785034179687, 0.48869219422340393, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1079, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, -613.73370361328125, -401.389312744140625, 60.34963607788085937, 1.466076612472534179, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1080, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, -613.90045166015625, -392.946502685546875, 60.86960601806640625, 3.682644605636596679, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1081, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, -609.3848876953125, -401.670684814453125, 60.6593475341796875, 1.008414268493652343, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1082, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, -617.5914306640625, -395.850372314453125, 60.536865234375, 3.822271108627319335, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)

-- Veteran
(@CGUID+1083, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, -609.4500732421875, -399.5771484375, 60.81250762939453125, 3.577924966812133789, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1084, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, -612.72119140625, -400.53265380859375, 60.76984786987304687, 4.384785175323486328, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1085, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, -615.45245361328125, -395.424163818359375, 60.94172286987304687, 6.17846536636352539, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1086, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, -612.69830322265625, -393.534515380859375, 60.92432785034179687, 0.48869219422340393, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1087, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, -613.73370361328125, -401.389312744140625, 60.34963607788085937, 1.466076612472534179, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1088, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, -613.90045166015625, -392.946502685546875, 60.86960601806640625, 3.682644605636596679, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1089, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, -609.3848876953125, -401.670684814453125, 60.6593475341796875, 1.008414268493652343, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1090, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, -617.5914306640625, -395.850372314453125, 60.536865234375, 3.822271108627319335, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)

-- Champion
(@CGUID+1091, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, -609.4500732421875, -399.5771484375, 60.81250762939453125, 3.577924966812133789, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1092, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, -612.72119140625, -400.53265380859375, 60.76984786987304687, 4.384785175323486328, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1093, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, -615.45245361328125, -395.424163818359375, 60.94172286987304687, 6.17846536636352539, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1094, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, -612.69830322265625, -393.534515380859375, 60.92432785034179687, 0.48869219422340393, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1095, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, -613.73370361328125, -401.389312744140625, 60.34963607788085937, 1.466076612472534179, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1096, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, -613.90045166015625, -392.946502685546875, 60.86960601806640625, 3.682644605636596679, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1097, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, -609.3848876953125, -401.670684814453125, 60.6593475341796875, 1.008414268493652343, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1098, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, -617.5914306640625, -395.850372314453125, 60.536865234375, 3.822271108627319335, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)

-- Frost Wolf
(@CGUID+395, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, -1077.7, -340.21, 55.4682, 6.25569, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+396, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, -1082.74, -333.821, 54.7962, 2.05459, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+397, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, -1090.66, -341.267, 54.6768, 3.27746, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+398, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, -1081.58, -344.63, 55.256, 4.75636, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+399, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, -1077.7, -340.21, 55.4682, 6.25569, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+400, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, -1082.74, -333.821, 54.7962, 2.05459, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+401, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, -1090.66, -341.267, 54.6768, 3.27746, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+402, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, -1081.58, -344.63, 55.256, 4.75636, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+403, 13117, 30, 2597, 0, '0', '0', 0, 0, 1, -1089.447265625, -268.955230712890625, 57.08559036254882812, 1.570796370506286621, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 51886), -- Horde Spirit Guide (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+404, 13116, 30, 2597, 0, '0', '0', 0, 0, 1, -1089.447265625, -268.955230712890625, 57.08559036254882812, 1.570796370506286621, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 0), -- Alliance Spirit Guide (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)

-- Seasoned
(@CGUID+1099, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, -1077.7, -340.21, 55.4682, 6.25569, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1100, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, -1082.74, -333.821, 54.7962, 2.05459, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1101, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, -1090.66, -341.267, 54.6768, 3.27746, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1102, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, -1081.58, -344.63, 55.256, 4.75636, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1103, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, -1077.7, -340.21, 55.4682, 6.25569, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1104, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, -1082.74, -333.821, 54.7962, 2.05459, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1105, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, -1090.66, -341.267, 54.6768, 3.27746, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1106, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, -1081.58, -344.63, 55.256, 4.75636, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)

-- Veteran
(@CGUID+1107, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, -1077.7, -340.21, 55.4682, 6.25569, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1108, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, -1082.74, -333.821, 54.7962, 2.05459, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1109, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, -1090.66, -341.267, 54.6768, 3.27746, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1110, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, -1081.58, -344.63, 55.256, 4.75636, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1111, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, -1077.7, -340.21, 55.4682, 6.25569, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1112, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, -1082.74, -333.821, 54.7962, 2.05459, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1113, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, -1090.66, -341.267, 54.6768, 3.27746, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1114, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, -1081.58, -344.63, 55.256, 4.75636, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)

-- Champion
(@CGUID+1115, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, -1077.7, -340.21, 55.4682, 6.25569, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1116, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, -1082.74, -333.821, 54.7962, 2.05459, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1117, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, -1090.66, -341.267, 54.6768, 3.27746, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1118, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, -1081.58, -344.63, 55.256, 4.75636, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1119, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, -1077.7, -340.21, 55.4682, 6.25569, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1120, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, -1082.74, -333.821, 54.7962, 2.05459, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1121, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, -1090.66, -341.267, 54.6768, 3.27746, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1122, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, -1081.58, -344.63, 55.256, 4.75636, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)

-- Frost Hut
(@CGUID+405, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, -1408.95, -311.69, 89.2536, 4.49954, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+406, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, -1407.15, -305.323, 89.1993, 2.86827, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+407, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, -1400.64, -304.3, 89.7008, 1.0595, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+408, 12053, 30, 2597, 0, '0', '0', 0, 0, 1, -1400.4, -311.35, 89.3028, 4.99434, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+409, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, -1408.95, -311.69, 89.2536, 4.49954, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+410, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, -1407.15, -305.323, 89.1993, 2.86827, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+411, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, -1400.64, -304.3, 89.7008, 1.0595, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+412, 12050, 30, 2597, 0, '0', '0', 0, 0, 1, -1400.4, -311.35, 89.3028, 4.99434, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+413, 13117, 30, 2597, 0, '0', '0', 0, 0, 1, -1489.4744873046875, -329.778778076171875, 100.8793182373046875, 3.577924966812133789, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 51886), -- Horde Spirit Guide (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+414, 13116, 30, 2597, 0, '0', '0', 0, 0, 1, -1489.4744873046875, -329.778778076171875, 100.8793182373046875, 3.577924966812133789, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 0), -- Alliance Spirit Guide (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)

-- Seasoned
(@CGUID+1123, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, -1408.95, -311.69, 89.2536, 4.49954, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1124, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, -1407.15, -305.323, 89.1993, 2.86827, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1125, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, -1400.64, -304.3, 89.7008, 1.0595, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1126, 13326, 30, 2597, 0, '0', '0', 0, 0, 1, -1400.4, -311.35, 89.3028, 4.99434, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1127, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, -1408.95, -311.69, 89.2536, 4.49954, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1128, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, -1407.15, -305.323, 89.1993, 2.86827, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1129, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, -1400.64, -304.3, 89.7008, 1.0595, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1130, 13328, 30, 2597, 0, '0', '0', 0, 0, 1, -1400.4, -311.35, 89.3028, 4.99434, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Frostwolf Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)

-- Veteran
(@CGUID+1131, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, -1408.95, -311.69, 89.2536, 4.49954, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1132, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, -1407.15, -305.323, 89.1993, 2.86827, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1133, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, -1400.64, -304.3, 89.7008, 1.0595, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1134, 13331, 30, 2597, 0, '0', '0', 0, 0, 1, -1400.4, -311.35, 89.3028, 4.99434, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1135, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, -1408.95, -311.69, 89.2536, 4.49954, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1136, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, -1407.15, -305.323, 89.1993, 2.86827, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1137, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, -1400.64, -304.3, 89.7008, 1.0595, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1138, 13332, 30, 2597, 0, '0', '0', 0, 0, 1, -1400.4, -311.35, 89.3028, 4.99434, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Veteran Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)

-- Champion
(@CGUID+1139, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, -1408.95, -311.69, 89.2536, 4.49954, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1140, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, -1407.15, -305.323, 89.1993, 2.86827, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1141, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, -1400.64, -304.3, 89.7008, 1.0595, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1142, 13422, 30, 2597, 0, '0', '0', 0, 0, 1, -1400.4, -311.35, 89.3028, 4.99434, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Stormpike Defender (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1143, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, -1408.95, -311.69, 89.2536, 4.49954, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1144, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, -1407.15, -305.323, 89.1993, 2.86827, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)
(@CGUID+1145, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, -1400.64, -304.3, 89.7008, 1.0595, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0), -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1146, 13421, 30, 2597, 0, '0', '0', 0, 0, 1, -1400.4, -311.35, 89.3028, 4.99434, 300, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 0); -- Champion Guardian (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger) (possible waypoints or random movement)

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1441.212890625, -588.17901611328125, 51.294891357421875, 6.161012172698974609, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+1, 11837, 30, 2597, 2597, '0', '0', 0, 0, 1, -1490.738525390625, -426.808929443359375, 70.41715240478515625, 5.026548385620117187, 7200, 0, 0, 52851, 2620, 0, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Shaman (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+2, 11838, 30, 2597, 2597, '0', '0', 0, 0, 1, -1659.297607421875, -420.099029541015625, 45.74441146850585937, 4.254969120025634765, 7200, 10, 0, 83195, 2846, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Mystic (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+3, 14282, 30, 2597, 2597, '0', '0', 0, 0, 0, -1446.0372314453125, -609.2906494140625, 51.22806549072265625, 3.007961988449096679, 7200, 10, 0, 18713, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf Bloodhound (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+4, 11839, 30, 2597, 2597, '0', '0', 0, 0, 1, -1615.599853515625, -386.972259521484375, 56.90337753295898437, 0.349872082471847534, 7200, 10, 0, 83195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Brute (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+5, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1445.7454833984375, -607.3834228515625, 51.21709823608398437, 2.985686302185058593, 7200, 10, 0, 16937850, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike) (possible waypoints or random movement)
(@CGUID+6, 10991, 30, 2597, 2597, '0', '0', 0, 0, 1, -1559.994384765625, -504.875640869140625, 61.95435714721679687, 1.93731546401977539, 7200, 0, 0, 45805, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Gnoll (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+7, 14282, 30, 2597, 2597, '0', '0', 0, 0, 0, -1445.420166015625, -605.4014892578125, 51.24088668823242187, 2.988318443298339843, 7200, 10, 0, 16262, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf Bloodhound (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+8, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1487.766845703125, -656.1053466796875, 49.02204132080078125, 2.58308720588684082, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+9, 10991, 30, 2597, 2597, '0', '0', 0, 0, 1, -1547.075439453125, -478.649139404296875, 70.64583587646484375, 4.730722427368164062, 7200, 10, 0, 52851, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Gnoll (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+10, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1489.3642578125, -651.92523193359375, 48.79279327392578125, 3.089232683181762695, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+11, 10981, 30, 2597, 2597, '0', '0', 0, 0, 0, -1231.7000732421875, -558.0985107421875, 52.08137893676757812, 3.277127981185913085, 7200, 10, 0, 24195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+12, 13284, 30, 2597, 2597, '0', '0', 0, 0, 1, -1319.3138427734375, -344.475250244140625, 60.38251495361328125, 1.727875947952270507, 7200, 0, 0, 671840, 23928, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Shaman (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+13, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1427.734375, -595.85479736328125, 51.6255035400390625, 2.652900457382202148, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+14, 10991, 30, 2597, 2597, '0', '0', 0, 0, 1, -1561.810791015625, -473.60968017578125, 59.7586822509765625, 1.638768434524536132, 7200, 10, 0, 45805, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Gnoll (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+15, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1365.9635009765625, -538.2950439453125, 54.13965988159179687, 1.239183783531188964, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+16, 12051, 30, 2597, 2597, '0', '0', 0, 0, 1, -1267.32373046875, -587.06622314453125, 54.874298095703125, 1.134464025497436523, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Legionnaire (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+17, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1449.6405029296875, -614.09649658203125, 51.47637939453125, 0.663225114345550537, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+18, 11837, 30, 2597, 2597, '0', '0', 0, 0, 1, -1545.063232421875, -484.5582275390625, 71.09796905517578125, 5.399332046508789062, 7200, 10, 0, 60817, 2705, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Shaman (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+19, 12051, 30, 2597, 2597, '0', '0', 0, 0, 1, -1254.0272216796875, -587.41046142578125, 55.35766220092773437, 1.884955525398254394, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Legionnaire (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+20, 11838, 30, 2597, 2597, '0', '0', 0, 0, 1, -1539.0799560546875, -360.657501220703125, 64.5909576416015625, 1.119892597198486328, 7200, 10, 0, 95341, 2933, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Mystic (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+21, 11839, 30, 2597, 2597, '0', '0', 0, 0, 1, -1553.635498046875, -344.297637939453125, 64.40428924560546875, 5.720519065856933593, 7200, 10, 0, 95341, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Brute (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+22, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1453.2113037109375, -609.6470947265625, 51.51163101196289062, 0.698131680488586425, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+23, 11837, 30, 2597, 2597, '0', '0', 0, 0, 1, -1500.235595703125, -436.20733642578125, 70.08643341064453125, 3.44838881492614746, 7200, 10, 0, 60817, 2705, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Shaman (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+24, 11838, 30, 2597, 2597, '0', '0', 0, 0, 1, -1606.392822265625, -364.545379638671875, 69.0218353271484375, 3.701046705245971679, 7200, 10, 0, 95341, 2933, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Mystic (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+25, 11839, 30, 2597, 2597, '0', '0', 0, 0, 1, -1587.701416015625, -429.404205322265625, 72.5961456298828125, 0.506145477294921875, 7200, 0, 0, 83195, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Brute (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+26, 10991, 30, 2597, 2597, '0', '0', 0, 0, 1, -1523.1512451171875, -464.534820556640625, 69.436370849609375, 3.70009016990661621, 7200, 10, 0, 52851, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Gnoll (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+27, 10981, 30, 2597, 2597, '0', '0', 0, 0, 0, -1303.220458984375, -552.70074462890625, 53.2244720458984375, 4.226911067962646484, 7200, 10, 0, 24195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+28, 13616, 30, 2597, 2597, '0', '0', 0, 0, 1, -1244.9605712890625, -637.9991455078125, 52.63655471801757812, 1.919862151145935058, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Stable Master (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+29, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1508.714111328125, -708.59649658203125, 48.19881057739257812, 5.98647928237915039, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+30, 12051, 30, 2597, 2597, '0', '0', 0, 0, 1, -1254.3074951171875, -629.73773193359375, 52.90457534790039062, 0.558505356311798095, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Legionnaire (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+31, 11837, 30, 2597, 2597, '0', '0', 0, 0, 1, -1542.731689453125, -472.904052734375, 70.80667877197265625, 3.146024942398071289, 7200, 10, 0, 52851, 2620, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Shaman (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+32, 10991, 30, 2597, 2597, '0', '0', 0, 0, 1, -1573.9407958984375, -491.074981689453125, 53.90537261962890625, 2.757620096206665039, 7200, 0, 0, 45805, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Gnoll (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+33, 11838, 30, 2597, 2597, '0', '0', 0, 0, 1, -1664.3592529296875, -425.582916259765625, 45.58984375, 1.463978886604309082, 7200, 10, 0, 95341, 2933, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Mystic (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+34, 11839, 30, 2597, 2597, '0', '0', 0, 0, 1, -1621.989990234375, -433.393341064453125, 51.06298828125, 2.049295663833618164, 7200, 10, 0, 95341, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Brute (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+35, 10981, 30, 2597, 2597, '0', '0', 0, 0, 0, -1164.9266357421875, -538.97589111328125, 51.9334259033203125, 4.016900539398193359, 7200, 10, 0, 24195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+36, 10991, 30, 2597, 2597, '0', '0', 0, 0, 1, -1528.8482666015625, -440.94000244140625, 70.80005645751953125, 5.078907966613769531, 7200, 0, 0, 45805, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Gnoll (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+37, 11838, 30, 2597, 2597, '0', '0', 0, 0, 1, -1608.8660888671875, -444.146453857421875, 79.8340606689453125, 0.137792348861694335, 7200, 10, 0, 83195, 2846, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Mystic (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+38, 10991, 30, 2597, 2597, '0', '0', 0, 0, 1, -1568.5931396484375, -445.791290283203125, 67.812103271484375, 1.98121654987335205, 7200, 10, 0, 52851, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Gnoll (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+39, 13959, 30, 2597, 2597, '0', '0', 0, 0, 0, -1635.3956298828125, -464.93792724609375, 52.66338348388671875, 2.268928050994873046, 7200, 10, 0, 790433, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Alterac Yeti (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+40, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1483.2247314453125, -677.3427734375, 48.64051055908203125, 3.525565147399902343, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+41, 10991, 30, 2597, 2597, '0', '0', 0, 0, 1, -1560.9578857421875, -498.258575439453125, 60.48471832275390625, 1.794407486915588378, 7200, 10, 0, 52851, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Gnoll (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+42, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1490.66748046875, -685.8663330078125, 47.4121551513671875, 0.558505356311798095, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+43, 10981, 30, 2597, 2597, '0', '0', 0, 0, 0, -1321.593994140625, -516.37921142578125, 51.61293792724609375, 6.208958148956298828, 7200, 10, 0, 24195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+44, 11837, 30, 2597, 2597, '0', '0', 0, 0, 1, -1483.275390625, -469.653076171875, 69.436370849609375, 2.485081434249877929, 7200, 10, 0, 52851, 2620, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Shaman (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+45, 10991, 30, 2597, 2597, '0', '0', 0, 0, 1, -1576.1893310546875, -480.939208984375, 55.11746978759765625, 4.074281692504882812, 7200, 10, 0, 45805, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Gnoll (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+46, 11838, 30, 2597, 2597, '0', '0', 0, 0, 1, -1638.1383056640625, -425.57965087890625, 48.93149185180664062, 4.528761863708496093, 7200, 10, 0, 95341, 2933, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Mystic (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+47, 11839, 30, 2597, 2597, '0', '0', 0, 0, 1, -1571.794677734375, -362.362030029296875, 64.1884002685546875, 2.493666648864746093, 7200, 10, 0, 95341, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Brute (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+48, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1492.9197998046875, -643.14031982421875, 47.92842864990234375, 1.36099553108215332, 7200, 10, 0, 16937850, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike) (possible waypoints or random movement)
(@CGUID+49, 11837, 30, 2597, 2597, '0', '0', 0, 0, 1, -1530.1673583984375, -444.92327880859375, 70.80005645751953125, 0.01745329238474369, 7200, 0, 0, 60817, 2705, 0, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Shaman (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+50, 14282, 30, 2597, 2597, '0', '0', 0, 0, 0, -1494.86328125, -642.75494384765625, 47.97616958618164062, 1.366965532302856445, 7200, 10, 0, 16262, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf Bloodhound (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+51, 11839, 30, 2597, 2597, '0', '0', 0, 0, 1, -1637.0452880859375, -422.396514892578125, 49.18973922729492187, 4.358902454376220703, 7200, 10, 0, 95341, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Brute (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+52, 10991, 30, 2597, 2597, '0', '0', 0, 0, 1, -1600.9527587890625, -431.908843994140625, 61.87706756591796875, 5.078907966613769531, 7200, 0, 0, 45805, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Gnoll (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+53, 11840, 30, 2597, 2597, '0', '0', 0, 0, 1, -1590.1632080078125, -402.741119384765625, 81.016143798828125, 0.412616848945617675, 7200, 10, 0, 113373, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Alpha (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+54, 154473, 30, 2597, 2597, '0', '0', 0, 0, 1, -1386.3802490234375, -544.03302001953125, 54.93865585327148437, 4.111944198608398437, 7200, 0, 0, 118565, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Voggah Deathgrip (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+55, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1496.3922119140625, -637.85040283203125, 47.90900802612304687, 5.846852779388427734, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+56, 154474, 30, 2597, 2597, '0', '0', 0, 0, 1, -1382.15283203125, -551.607666015625, 55.061187744140625, 3.364171028137207031, 7200, 0, 0, 1355028, 37860, 0, NULL, NULL, NULL, NULL, 51536), -- Primalist Thurloga (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+57, 10981, 30, 2597, 2597, '0', '0', 0, 0, 0, -1191.6134033203125, -499.91448974609375, 52.2348175048828125, 3.270790338516235351, 7200, 10, 0, 24195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+58, 13284, 30, 2597, 2597, '0', '0', 0, 0, 1, -1317.6138916015625, -342.85345458984375, 60.37259292602539062, 2.478367567062377929, 7200, 0, 0, 671840, 23928, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Shaman (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+59, 11998, 30, 2597, 2597, '0', '0', 0, 0, 1, -1484.372314453125, -699.8885498046875, 47.08716583251953125, 2.321287870407104492, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Herald (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+60, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1425.2584228515625, -590.78399658203125, 51.81089019775390625, 3.298672199249267578, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+61, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1442.2960205078125, -592.6134033203125, 51.17546463012695312, 0.01745329238474369, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+62, 10991, 30, 2597, 2597, '0', '0', 0, 0, 1, -1492.4718017578125, -459.09686279296875, 69.4385986328125, 1.590808391571044921, 7200, 10, 0, 45805, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Gnoll (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+63, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1376.06396484375, -534.47515869140625, 55.49314498901367187, 0.453785598278045654, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+64, 10991, 30, 2597, 2597, '0', '0', 0, 0, 1, -1482.4227294921875, -461.043853759765625, 69.436370849609375, 2.110623359680175781, 7200, 10, 0, 45805, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Gnoll (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+65, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1373.7022705078125, -531.2449951171875, 54.44995880126953125, 0.296705961227416992, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+66, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1452.89306640625, -600.94171142578125, 51.380645751953125, 4.939281940460205078, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+67, 11838, 30, 2597, 2597, '0', '0', 0, 0, 1, -1666.303466796875, -421.865264892578125, 45.58984375, 5.812701225280761718, 7200, 10, 0, 83195, 2846, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Mystic (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+68, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1447.792724609375, -602.70263671875, 51.29736709594726562, 4.293509960174560546, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+69, 13441, 30, 2597, 2597, '0', '0', 0, 0, 1, -1248.7862548828125, -636.017822265625, 52.63482666015625, 0.959931075572967529, 7200, 0, 0, 1355028, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Wolf Rider Commander (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+70, 11837, 30, 2597, 2597, '0', '0', 0, 0, 1, -1578.0445556640625, -492.01617431640625, 53.18376922607421875, 1.518436431884765625, 7200, 0, 0, 52851, 2620, 0, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Shaman (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+71, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1369.575439453125, -539.44024658203125, 55.10938644409179687, 1.01229095458984375, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+72, 10981, 30, 2597, 2597, '0', '0', 0, 0, 0, -1340.854736328125, -472.003631591796875, 49.99468231201171875, 4.620380401611328125, 7200, 10, 0, 24195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+73, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1499.5943603515625, -711.28076171875, 47.50315475463867187, 2.408554315567016601, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+74, 12051, 30, 2597, 2597, '0', '0', 0, 0, 1, -1238.08447265625, -641.84112548828125, 53.89588546752929687, 1.675516128540039062, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Legionnaire (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+75, 13236, 30, 2597, 2597, '0', '0', 0, 0, 1, -1319.564453125, -342.67529296875, 60.3403778076171875, 2.059488534927368164, 7200, 0, 0, 1355028, 37860, 0, NULL, NULL, NULL, NULL, 51536), -- Primalist Thurloga (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+76, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1506.1094970703125, -705.9056396484375, 47.68996810913085937, 5.689773082733154296, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+77, 11837, 30, 2597, 2597, '0', '0', 0, 0, 1, -1500.7999267578125, -466.522674560546875, 69.48491668701171875, 6.248278617858886718, 7200, 0, 0, 52851, 2620, 0, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Shaman (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+78, 11838, 30, 2597, 2597, '0', '0', 0, 0, 1, -1586.1087646484375, -372.0313720703125, 67.71564483642578125, 5.680485725402832031, 7200, 10, 0, 95341, 2933, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Mystic (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+79, 11839, 30, 2597, 2597, '0', '0', 0, 0, 1, -1567.1983642578125, -393.579803466796875, 65.1964569091796875, 1.075974225997924804, 7200, 10, 0, 95341, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Brute (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+80, 603, 30, 2597, 2597, '0', '0', 0, 0, 1, -1594.3861083984375, -409.991424560546875, 81.50933837890625, 1.343903541564941406, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Grimtooth (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+81, 10991, 30, 2597, 2597, '0', '0', 0, 0, 1, -1500.189697265625, -470.4766845703125, 69.52548980712890625, 1.448623299598693847, 7200, 0, 0, 45805, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Gnoll (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+82, 10991, 30, 2597, 2597, '0', '0', 0, 0, 1, -1492.380126953125, -436.32421875, 69.79819488525390625, 2.657131195068359375, 7200, 10, 0, 52851, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Gnoll (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+83, 11838, 30, 2597, 2597, '0', '0', 0, 0, 1, -1590.177734375, -424.57421875, 71.9984130859375, 3.276056289672851562, 7200, 10, 0, 83195, 2846, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Mystic (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+84, 11839, 30, 2597, 2597, '0', '0', 0, 0, 1, -1605.13525390625, -446.004119873046875, 79.32411956787109375, 1.186823844909667968, 7200, 0, 0, 95341, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Brute (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+85, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1490.791748046875, -682.8597412109375, 47.7365264892578125, 0.174532920122146606, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+86, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1503.3179931640625, -713.9971923828125, 48.20803451538085937, 1.099557399749755859, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+87, 10981, 30, 2597, 2597, '0', '0', 0, 0, 0, -1258.7828369140625, -476.664794921875, 49.96657943725585937, 0.18657773733139038, 7200, 10, 0, 24195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+88, 10991, 30, 2597, 2597, '0', '0', 0, 0, 1, -1476.25341796875, -433.2835693359375, 70.311370849609375, 2.935067176818847656, 7200, 10, 0, 45805, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Gnoll (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+89, 11837, 30, 2597, 2597, '0', '0', 0, 0, 1, -1562.629638671875, -478.490081787109375, 59.60002899169921875, 2.468605756759643554, 7200, 10, 0, 60817, 2705, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Shaman (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+90, 11838, 30, 2597, 2597, '0', '0', 0, 0, 1, -1585.303466796875, -383.861419677734375, 65.0233612060546875, 5.292948246002197265, 7200, 10, 0, 95341, 2933, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Mystic (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+91, 14282, 30, 2597, 2597, '0', '0', 0, 0, 0, -1490.952392578125, -643.5618896484375, 47.97221755981445312, 1.364804267883300781, 7200, 10, 0, 16262, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf Bloodhound (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+92, 11839, 30, 2597, 2597, '0', '0', 0, 0, 1, -1612.9849853515625, -438.392913818359375, 80.1800994873046875, 0.575958669185638427, 7200, 0, 0, 83195, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Brute (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+93, 10991, 30, 2597, 2597, '0', '0', 0, 0, 1, -1543.3193359375, -465.6080322265625, 70.76100921630859375, 0.311644047498703002, 7200, 10, 0, 52851, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Gnoll (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+94, 11840, 30, 2597, 2597, '0', '0', 0, 0, 1, -1549.468017578125, -361.358917236328125, 66.282745361328125, 3.002275943756103515, 7200, 10, 0, 141232, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Alpha (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+95, 11838, 30, 2597, 2597, '0', '0', 0, 0, 1, -1551.8619384765625, -377.171875, 64.42989349365234375, 4.413138389587402343, 7200, 10, 0, 83195, 2846, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Mystic (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+96, 11839, 30, 2597, 2597, '0', '0', 0, 0, 1, -1629.8414306640625, -396.474609375, 51.94384002685546875, 5.2721710205078125, 7200, 10, 0, 83195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Brute (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+97, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1495.369140625, -634.252197265625, 47.8012847900390625, 5.462880611419677734, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+98, 10991, 30, 2597, 2597, '0', '0', 0, 0, 1, -1477.3671875, -464.3857421875, 69.436370849609375, 2.617825746536254882, 7200, 10, 0, 45805, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Gnoll (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+99, 14285, 30, 2597, 2597, '0', '0', 0, 0, 1, -1482.052490234375, -680.86065673828125, 48.28873062133789062, 3.351032257080078125, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Battleguard (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+100, 11946, 30, 2597, 2597, '0', '0', 0, 0, 1, -1370.8828125, -220.207839965820312, 98.509918212890625, 5.131268024444580078, 7200, 0, 0, 27100560, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Drek'Thar (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 177684 - Unit Frame)
(@CGUID+101, 11948, 30, 2597, 2597, '0', '0', 0, 0, 1, 722.4295654296875, -10.9981555938720703, 50.70463180541992187, 3.420845270156860351, 7200, 0, 0, 27100560, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Vanndar Stormpike (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 177684 - Unit Frame) (possible waypoints or random movement)
(@CGUID+102, 13284, 30, 2597, 2597, '0', '0', 0, 0, 1, -1321.6414794921875, -343.729644775390625, 60.48332977294921875, 1.01229095458984375, 7200, 0, 0, 671840, 23928, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Shaman (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+103, 14282, 30, 2597, 2597, '0', '0', 0, 0, 0, -1241.072509765625, -361.186187744140625, 59.79639816284179687, 2.493845462799072265, 7200, 10, 0, 18713, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf Bloodhound (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+104, 11838, 30, 2597, 2597, '0', '0', 0, 0, 1, -1612.66845703125, -361.849090576171875, 68.9689788818359375, 6.17249298095703125, 7200, 10, 0, 95341, 2933, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Mystic (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+105, 12051, 30, 2597, 2597, '0', '0', 0, 0, 1, -1242.779296875, -362.815887451171875, 59.76868820190429687, 2.688943147659301757, 7200, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Legionnaire (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+106, 14282, 30, 2597, 2597, '0', '0', 0, 0, 0, -1243.77099609375, -363.80889892578125, 59.828033447265625, 2.407325506210327148, 7200, 10, 0, 18713, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf Bloodhound (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+107, 11839, 30, 2597, 2597, '0', '0', 0, 0, 1, -1599.5511474609375, -353.221832275390625, 63.9396514892578125, 0.821584045886993408, 7200, 10, 0, 95341, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Wildpaw Brute (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+108, 13153, 30, 2597, 2597, '0', '0', 0, 0, 1, -1406.130126953125, -313.23297119140625, 89.36468505859375, 0.139626339077949523, 7200, 0, 0, 11291900, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Commander Mulfort (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+109, 13439, 30, 2597, 2597, '0', '0', 0, 0, 1, -1219.2529296875, -353.167388916015625, 57.75129318237304687, 4.485496044158935546, 7200, 0, 0, 3138480, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Wing Commander Vipore (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+110, 13359, 30, 2597, 2597, '0', '0', 0, 0, 1, -1292.8702392578125, -316.993377685546875, 113.8544387817382812, 0.03490658476948738, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Bowman (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+111, 13359, 30, 2597, 2597, '0', '0', 0, 0, 1, -1296.943115234375, -308.430206298828125, 107.3566360473632812, 0.506145477294921875, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Bowman (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+112, 14185, 30, 2597, 2597, '0', '0', 0, 0, 1, -1271.210693359375, -335.55419921875, 62.44617843627929687, 5.759586334228515625, 7200, 0, 0, 104616, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Najak Hexxen (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+113, 14186, 30, 2597, 2597, '0', '0', 0, 0, 1, -1268.640625, -332.6884765625, 62.73878097534179687, 5.288347721099853515, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Ravak Grimtotem (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+114, 13359, 30, 2597, 2597, '0', '0', 0, 0, 1, -1296.39501953125, -308.945068359375, 113.845184326171875, 1.274090290069580078, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Bowman (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+115, 13359, 30, 2597, 2597, '0', '0', 0, 0, 1, -1292.7808837890625, -317.950653076171875, 107.4113388061523437, 6.003932476043701171, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Bowman (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+116, 13798, 30, 2597, 2597, '0', '0', 0, 0, 1, -1213.9097900390625, -370.619049072265625, 56.4101409912109375, 0.837758064270019531, 7200, 0, 0, 417800, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Jotek (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+117, 2225, 30, 2597, 2597, '0', '0', 0, 0, 1, -1235.31396484375, -340.776702880859375, 60.50881576538085937, 3.31612563133239746, 7200, 0, 0, 537290, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Zora Guthrek (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+118, 14031, 30, 2597, 2597, '0', '0', 0, 0, 1, -1225.0501708984375, -350.430999755859375, 57.79180145263671875, 3.59537816047668457, 7200, 0, 0, 338757, 6310, 0, NULL, NULL, NULL, NULL, 51536), -- Trigger Vipore (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+119, 10981, 30, 2597, 2597, '0', '0', 0, 0, 0, -1118.5953369140625, -554.003662109375, 50.31036376953125, 2.748058319091796875, 7200, 10, 0, 24195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+120, 3343, 30, 2597, 2597, '0', '0', 0, 0, 1, -1244.0164794921875, -323.79498291015625, 60.99968719482421875, 5.218534469604492187, 7200, 0, 0, 537290, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Grelkor (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+121, 13176, 30, 2597, 2597, '0', '0', 0, 0, 1, -1251.5030517578125, -316.326934814453125, 62.6564788818359375, 5.026548385620117187, 7200, 0, 0, 1129190, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Smith Regzar (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+122, 3625, 30, 2597, 2597, '0', '0', 0, 0, 1, -1235.163818359375, -332.30181884765625, 60.27610015869140625, 2.967059612274169921, 7200, 0, 0, 537290, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Rarck (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+123, 13218, 30, 2597, 2597, '0', '0', 0, 0, 1, -1244.923583984375, -308.91552734375, 63.25250244140625, 1.623156189918518066, 7200, 0, 0, 839800, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Grunnda Wolfheart (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+124, 13359, 30, 2597, 2597, '0', '0', 0, 0, 1, -1300.61962890625, -275.9302978515625, 114.1352081298828125, 3.822271108627319335, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Bowman (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+125, 13437, 30, 2597, 2597, '0', '0', 0, 0, 1, -1302.77880859375, -268.606781005859375, 92.0257720947265625, 1.400266408920288085, 7200, 0, 0, 3387570, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Wing Commander Ichman (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+126, 13359, 30, 2597, 2597, '0', '0', 0, 0, 1, -1292.3270263671875, -273.102386474609375, 114.23455810546875, 4.991641521453857421, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Bowman (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+127, 14029, 30, 2597, 2597, '0', '0', 0, 0, 1, -1303.9920654296875, -266.817535400390625, 114.362548828125, 6.091198921203613281, 7200, 0, 0, 338757, 6310, 0, NULL, NULL, NULL, NULL, 51536), -- Trigger Ichman (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+128, 14848, 30, 2597, 2597, '0', '0', 0, 0, 2, -1357.4661865234375, -253.097976684570312, 120.98846435546875, 5.131268024444580078, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+129, 13359, 30, 2597, 2597, '0', '0', 0, 0, 1, -1288.2633056640625, -264.98626708984375, 107.6954421997070312, 0.174532920122146606, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Bowman (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+130, 13359, 30, 2597, 2597, '0', '0', 0, 0, 1, -1286.3443603515625, -265.083984375, 114.17181396484375, 5.969026088714599609, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Bowman (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+131, 10981, 30, 2597, 2597, '0', '0', 0, 0, 0, -1078.003662109375, -429.361785888671875, 53.33718109130859375, 5.252138137817382812, 7200, 10, 0, 24195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+132, 10981, 30, 2597, 2597, '0', '0', 0, 0, 0, -1049.849853515625, -534.8587646484375, 46.69826507568359375, 1.649067401885986328, 7200, 10, 0, 24195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+133, 10981, 30, 2597, 2597, '0', '0', 0, 0, 0, -1064.220458984375, -439.093048095703125, 51.28548431396484375, 1.882658362388610839, 7200, 10, 0, 24195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+134, 10981, 30, 2597, 2597, '0', '0', 0, 0, 0, -1044.960205078125, -487.41265869140625, 44.96054840087890625, 0.413863599300384521, 7200, 10, 0, 24195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+135, 13152, 30, 2597, 2597, '0', '0', 0, 0, 1, -1090.3226318359375, -349.622955322265625, 54.644744873046875, 0.03490658476948738, 7200, 0, 0, 11291900, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Commander Malgor (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+136, 10981, 30, 2597, 2597, '0', '0', 0, 0, 0, -1010.995361328125, -506.73406982421875, 41.9484100341796875, 1.360384702682495117, 7200, 10, 0, 24195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+137, 13448, 30, 2597, 2597, '0', '0', 0, 0, 1, -1212.1068115234375, -261.774200439453125, 73.4560546875, 5.79449319839477539, 7200, 0, 0, 123252, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Sergeant Yazra Bloodsnarl (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+138, 10364, 30, 2597, 2597, '0', '0', 0, 0, 1, -1183.7606201171875, -268.295318603515625, 72.82330322265625, 3.281219005584716796, 7200, 0, 0, 537290, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Yaelika Farclaw (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+139, 10367, 30, 2597, 2597, '0', '0', 0, 0, 1, -1187.894775390625, -275.0548095703125, 73.0009918212890625, 3.630284786224365234, 7200, 0, 0, 537290, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Shrye Ragefist (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+140, 10981, 30, 2597, 2597, '0', '0', 0, 0, 0, -1028.8768310546875, -400.10955810546875, 51.243499755859375, 6.090474128723144531, 7200, 10, 0, 24195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+141, 10981, 30, 2597, 2597, '0', '0', 0, 0, 0, -1004.27044677734375, -367.41143798828125, 55.6211700439453125, 0.153482452034950256, 7200, 10, 0, 24195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+142, 10981, 30, 2597, 2597, '0', '0', 0, 0, 0, -950, -400, 49.37044906616210937, 3.742067575454711914, 7200, 10, 0, 24195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+143, 10981, 30, 2597, 2597, '0', '0', 0, 0, 0, -947.13116455078125, -428.0164794921875, 48.9381256103515625, 2.430847883224487304, 7200, 10, 0, 24195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+144, 10981, 30, 2597, 2597, '0', '0', 0, 0, 0, -942.9219970703125, -473.225311279296875, 43.22744369506835937, 5.924190044403076171, 7200, 10, 0, 24195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+145, 12051, 30, 2597, 2597, '0', '0', 0, 0, 1, -883.41925048828125, -523.59930419921875, 53.56270217895507812, 4.283661842346191406, 7200, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Legionnaire (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+146, 12051, 30, 2597, 2597, '0', '0', 0, 0, 1, -884.16937255859375, -529.2734375, 54.1734466552734375, 4.388166427612304687, 7200, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Legionnaire (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+147, 10981, 30, 2597, 2597, '0', '0', 0, 0, 0, -880.39013671875, -429.70892333984375, 42.00390625, 4.837713241577148437, 7200, 10, 0, 24195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+148, 10981, 30, 2597, 2597, '0', '0', 0, 0, 0, -859.53436279296875, -470.5782470703125, 47.86272430419921875, 5.001415252685546875, 7200, 10, 0, 24195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+149, 10981, 30, 2597, 2597, '0', '0', 0, 0, 0, -844.0863037109375, -453.92974853515625, 46.8459625244140625, 0.631382882595062255, 7200, 10, 0, 24195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+150, 10981, 30, 2597, 2597, '0', '0', 0, 0, 0, -908.04541015625, -291.97509765625, 64.79936981201171875, 2.321877241134643554, 7200, 10, 0, 24195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Alterac Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+151, 12051, 30, 2597, 2597, '0', '0', 0, 0, 1, -842.97137451171875, -394.7342529296875, 51.0708160400390625, 5.377522468566894531, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Legionnaire (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+152, 12051, 30, 2597, 2597, '0', '0', 0, 0, 1, -833.58795166015625, -409.737518310546875, 52.03802490234375, 5.088541507720947265, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Legionnaire (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+153, 12051, 30, 2597, 2597, '0', '0', 0, 0, 1, -818.81512451171875, -342.071746826171875, 51.89333724975585937, 0.552805840969085693, 7200, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Legionnaire (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+154, 10981, 30, 2597, 2597, '0', '0', 0, 0, 0, -844.5340576171875, -302.657501220703125, 56.2043304443359375, 1.014206171035766601, 7200, 10, 0, 24195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+155, 12051, 30, 2597, 2597, '0', '0', 0, 0, 1, -806.46136474609375, -335.75360107421875, 57.25986862182617187, 5.888544559478759765, 7200, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Legionnaire (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+156, 12051, 30, 2597, 2597, '0', '0', 0, 0, 1, -761.834716796875, -431.594268798828125, 64.6922149658203125, 2.65175485610961914, 7200, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Legionnaire (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+157, 12051, 30, 2597, 2597, '0', '0', 0, 0, 1, -761.871337890625, -434.4071044921875, 64.9738006591796875, 2.769791126251220703, 7200, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Legionnaire (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+158, 13154, 30, 2597, 2597, '0', '0', 0, 0, 1, -764.654052734375, -355.08502197265625, 90.88481903076171875, 1.134464025497436523, 7200, 10, 0, 11291900, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Commander Louis Philips (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+159, 13438, 30, 2597, 2597, '0', '0', 0, 0, 1, -768.86395263671875, -360.92633056640625, 68.63196563720703125, 1.064650893211364746, 7200, 0, 0, 2519400, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Wing Commander Slidore (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+160, 13359, 30, 2597, 2597, '0', '0', 0, 0, 1, -773.6427001953125, -354.97760009765625, 90.87725830078125, 2.548180580139160156, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Bowman (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+161, 13359, 30, 2597, 2597, '0', '0', 0, 0, 1, -772.96771240234375, -373.49896240234375, 90.931121826171875, 4.537856101989746093, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Bowman (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+162, 13359, 30, 2597, 2597, '0', '0', 0, 0, 1, -758.46710205078125, -361.4208984375, 90.887786865234375, 5.934119224548339843, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Bowman (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+163, 13359, 30, 2597, 2597, '0', '0', 0, 0, 1, -762.73370361328125, -371.23968505859375, 90.87793731689453125, 5.427973747253417968, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Bowman (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+164, 14030, 30, 2597, 2597, '0', '0', 0, 0, 1, -762.54974365234375, -346.892486572265625, 91.0630035400390625, 4.799655437469482421, 7200, 0, 0, 338757, 6310, 0, NULL, NULL, NULL, NULL, 51536), -- Trigger Slidore (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+165, 14282, 30, 2597, 3318, '0', '0', 0, 0, 0, -714.773681640625, -360.980712890625, 66.79590606689453125, 5.54891824722290039, 7200, 10, 0, 16262, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf Bloodhound (Area: Rock of Durotan - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+166, 14282, 30, 2597, 3318, '0', '0', 0, 0, 0, -712.0933837890625, -358.01251220703125, 66.6379547119140625, 5.54891824722290039, 7200, 10, 0, 16262, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf Bloodhound (Area: Rock of Durotan - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+167, 12051, 30, 2597, 3318, '0', '0', 0, 0, 1, -710.083740234375, -362.516204833984375, 66.654296875, 5.549420833587646484, 7200, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Legionnaire (Area: Rock of Durotan - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+168, 11998, 30, 2597, 3318, '0', '0', 0, 0, 1, -735.099609375, -679.3709716796875, 50.79393386840820312, 4.136430263519287109, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Herald (Area: Rock of Durotan - Difficulty: 0) CreateObject1
(@CGUID+169, 10981, 30, 2597, 3318, '0', '0', 0, 0, 0, -552.22137451171875, -485.323455810546875, 77.6930999755859375, 2.862339973449707031, 7200, 0, 0, 24195, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Rock of Durotan - Difficulty: 0) CreateObject1
(@CGUID+170, 13359, 30, 2597, 0, '0', '0', 0, 0, 1, -573.5216064453125, -271.854156494140625, 75.00775909423828125, 3.96189737319946289, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Bowman (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+171, 13359, 30, 2597, 0, '0', '0', 0, 0, 1, -565.61578369140625, -269.051422119140625, 74.99517822265625, 5.026548385620117187, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Bowman (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+172, 13140, 30, 2597, 0, '0', '0', 0, 0, 1, -571.0814208984375, -263.750823974609375, 75.092010498046875, 5.410520553588867187, 7200, 10, 0, 11291900, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Commander Dardosh (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+173, 13359, 30, 2597, 0, '0', '0', 0, 0, 1, -569.17578125, -254.445632934570312, 74.87714385986328125, 0.820304751396179199, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Bowman (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+174, 13359, 30, 2597, 0, '0', '0', 0, 0, 1, -562.82452392578125, -261.087127685546875, 74.98979949951171875, 5.951572895050048828, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Bowman (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+175, 10981, 30, 2597, 2962, '0', '0', 0, 0, 0, -550.68511962890625, -197.201217651367187, 57.49631500244140625, 5.152544975280761718, 7200, 10, 0, 24195, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Tower Point - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+176, 14848, 30, 2597, 2962, '0', '0', 0, 0, 2, -539.74249267578125, -168.400115966796875, 114.84918212890625, 2.932153224945068359, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Tower Point - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+177, 14848, 30, 2597, 2962, '0', '0', 0, 0, 2, -539.6865234375, -168.401580810546875, 114.869537353515625, 0.959931075572967529, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Tower Point - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+178, 14848, 30, 2597, 2962, '0', '0', 0, 0, 2, -539.2822265625, -168.187225341796875, 115.01666259765625, 0.680678427219390869, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Tower Point - Difficulty: 0) CreateObject1
(@CGUID+179, 14848, 30, 2597, 2962, '0', '0', 0, 0, 2, -539.28515625, -168.243438720703125, 115.0155868530273437, 1.535889744758605957, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Tower Point - Difficulty: 0) CreateObject1
(@CGUID+180, 14848, 30, 2597, 2962, '0', '0', 0, 0, 2, -539.46368408203125, -168.518936157226562, 114.9434280395507812, 0.418879032135009765, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Tower Point - Difficulty: 0) CreateObject1
(@CGUID+181, 14848, 30, 2597, 2962, '0', '0', 0, 0, 2, -539.396484375, -168.57373046875, 114.9466094970703125, 4.101523876190185546, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Tower Point - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+182, 14848, 30, 2597, 2962, '0', '0', 0, 0, 2, -539.7364501953125, -168.287979125976562, 114.8513641357421875, 5.515240192413330078, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Tower Point - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+183, 14848, 30, 2597, 2962, '0', '0', 0, 0, 2, -539.61871337890625, -168.1787109375, 114.8942337036132812, 1.448623299598693847, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Tower Point - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+184, 14848, 30, 2597, 2962, '0', '0', 0, 0, 2, -539.5096435546875, -168.237686157226562, 114.93389892578125, 5.375614166259765625, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Tower Point - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+185, 14848, 30, 2597, 2962, '0', '0', 0, 0, 2, -539.5125732421875, -168.293899536132812, 114.9328231811523437, 4.450589656829833984, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Tower Point - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+186, 14848, 30, 2597, 2962, '0', '0', 0, 0, 2, -539.56866455078125, -168.292312622070312, 114.9124221801757812, 1.727875947952270507, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Tower Point - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+187, 14848, 30, 2597, 2962, '0', '0', 0, 0, 2, -539.9686279296875, -168.450149536132812, 114.766845703125, 5.096361160278320312, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Tower Point - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+188, 14848, 30, 2597, 2962, '0', '0', 0, 0, 2, -539.85113525390625, -168.341140747070312, 114.8096389770507812, 5.811946392059326171, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Tower Point - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+189, 14848, 30, 2597, 2962, '0', '0', 0, 0, 2, -539.80718994140625, -168.566787719726562, 114.8256072998046875, 5.148721218109130859, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Tower Point - Difficulty: 0) CreateObject1
(@CGUID+190, 14848, 30, 2597, 2962, '0', '0', 0, 0, 2, -539.34735107421875, -168.354385375976562, 114.9929885864257812, 4.450589656829833984, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Tower Point - Difficulty: 0) CreateObject1
(@CGUID+191, 14848, 30, 2597, 2962, '0', '0', 0, 0, 2, -539.34942626953125, -168.465988159179687, 114.9864425659179687, 5.305800914764404296, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Tower Point - Difficulty: 0) CreateObject1
(@CGUID+192, 14848, 30, 2597, 2962, '0', '0', 0, 0, 2, -539.8056640625, -168.677352905273437, 114.81463623046875, 0.471238881349563598, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Tower Point - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+193, 14848, 30, 2597, 2962, '0', '0', 0, 0, 2, -539.79827880859375, -168.398651123046875, 114.828857421875, 1.588249564170837402, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Tower Point - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+194, 14848, 30, 2597, 2962, '0', '0', 0, 0, 2, -539.7520751953125, -168.623977661132812, 114.8421783447265625, 1.762782573699951171, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Tower Point - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+195, 11947, 30, 2597, 2962, '0', '0', 0, 0, 1, -545.229736328125, -165.349884033203125, 57.78859329223632812, 6.003932476043701171, 7200, 0, 0, 19760825, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Captain Galvangar (Area: Tower Point - Difficulty: 0) CreateObject1
(@CGUID+196, 14848, 30, 2597, 2962, '0', '0', 0, 0, 2, -539.79534912109375, -168.342605590820312, 114.8299331665039062, 2.809980154037475585, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Tower Point - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+197, 10981, 30, 2597, 2962, '0', '0', 0, 0, 0, -483.019989013671875, -195.009780883789062, 55.94804000854492187, 5.875472545623779296, 7200, 0, 0, 24195, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frost Wolf (Area: Tower Point - Difficulty: 0) CreateObject1
(@CGUID+198, 13358, 30, 2597, 0, '0', '0', 0, 0, 1, -170.168411254882812, -460.0850830078125, 40.92316436767578125, 3.560471534729003906, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536); -- Stormpike Bowman (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+199, 13139, 30, 2597, 0, '0', '0', 0, 0, 1, -159.406143188476562, -458.362945556640625, 40.47910308837890625, 1.256637096405029296, 7200, 0, 0, 11291900, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Commander Randolph (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+200, 13358, 30, 2597, 0, '0', '0', 0, 0, 1, -157.710067749023437, -433.279510498046875, 41.13107681274414062, 2.426007747650146484, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Bowman (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+201, 13358, 30, 2597, 0, '0', '0', 0, 0, 1, -145.208328247070312, -463.40625, 40.94273757934570312, 6.126105785369873046, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Bowman (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+202, 13358, 30, 2597, 0, '0', '0', 0, 0, 1, -138.684036254882812, -447.53472900390625, 41.06644058227539062, 1.378810048103332519, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Bowman (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+203, 10990, 30, 2597, 0, '0', '0', 0, 0, 0, -121.952957153320312, -371.682464599609375, 11.0150299072265625, 1.302147865295410156, 7200, 0, 0, 30837, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+204, 10990, 30, 2597, 3057, '0', '0', 0, 0, 0, -50.9852752685546875, -502.638641357421875, 44.07640838623046875, 4.250489711761474609, 7200, 10, 0, 30837, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: Field of Strife - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+205, 11949, 30, 2597, 3057, '0', '0', 0, 0, 1, -57.7890625, -286.5968017578125, 15.64790630340576171, 6.021385669708251953, 7200, 0, 0, 19760825, 94650, 0, NULL, NULL, NULL, NULL, 51536), -- Captain Balinda Stonehearth (Area: Field of Strife - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+206, 14848, 30, 2597, 3057, '0', '0', 0, 0, 2, -48.6169700622558593, -288.69873046875, 55.30504608154296875, 5.270894527435302734, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Field of Strife - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+207, 14848, 30, 2597, 3057, '0', '0', 0, 0, 2, -48.4590950012207031, -288.802459716796875, 55.4724578857421875, 3.787364482879638671, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Field of Strife - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+208, 14848, 30, 2597, 3057, '0', '0', 0, 0, 2, -48.4093971252441406, -288.8057861328125, 55.51976394653320312, 0.174532920122146606, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Field of Strife - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+209, 14848, 30, 2597, 3057, '0', '0', 0, 0, 2, -48.4237213134765625, -288.83795166015625, 55.51230621337890625, 0.139626339077949523, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Field of Strife - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+210, 14848, 30, 2597, 3057, '0', '0', 0, 0, 2, -48.8082695007324218, -288.7706298828125, 55.13877105712890625, 3.804817676544189453, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Field of Strife - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+211, 14848, 30, 2597, 3057, '0', '0', 0, 0, 2, -48.4564895629882812, -288.600860595703125, 55.43748092651367187, 5.811946392059326171, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Field of Strife - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+212, 14848, 30, 2597, 3057, '0', '0', 0, 0, 2, -48.5055351257324218, -288.383697509765625, 55.34942245483398437, 2.897246599197387695, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Field of Strife - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+213, 14848, 30, 2597, 3057, '0', '0', 0, 0, 2, -48.3509101867675781, -288.740570068359375, 55.56249618530273437, 5.899212837219238281, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Field of Strife - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+214, 14848, 30, 2597, 3057, '0', '0', 0, 0, 2, -48.5047760009765625, -288.537445068359375, 55.38004302978515625, 2.932153224945068359, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Field of Strife - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+215, 14848, 30, 2597, 3057, '0', '0', 0, 0, 2, -48.2341575622558593, -288.610076904296875, 55.6478271484375, 1.954768776893615722, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Field of Strife - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+216, 14848, 30, 2597, 3057, '0', '0', 0, 0, 2, -48.2838554382324218, -288.606719970703125, 55.60063934326171875, 1.2042771577835083, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Field of Strife - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+217, 14848, 30, 2597, 3057, '0', '0', 0, 0, 2, -48.4239387512207031, -288.5279541015625, 55.45396041870117187, 5.235987663269042968, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Field of Strife - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+218, 14848, 30, 2597, 3057, '0', '0', 0, 0, 2, -48.3154296875, -288.466033935546875, 55.54361343383789062, 3.59537816047668457, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Field of Strife - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+219, 14848, 30, 2597, 3057, '0', '0', 0, 0, 2, -48.1561431884765625, -288.645233154296875, 55.72542190551757812, 2.984513044357299804, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Field of Strife - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+220, 14848, 30, 2597, 3057, '0', '0', 0, 0, 2, -48.2657356262207031, -288.469512939453125, 55.59083938598632812, 3.926990747451782226, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Field of Strife - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+221, 14848, 30, 2597, 3057, '0', '0', 0, 0, 2, -48.1519088745117187, -288.82318115234375, 55.745147705078125, 4.049163818359375, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Field of Strife - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+222, 14848, 30, 2597, 3057, '0', '0', 0, 0, 2, -48.3308372497558593, -288.59130859375, 55.55360794067382812, 2.58308720588684082, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Field of Strife - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+223, 10990, 30, 2597, 0, '0', '0', 0, 0, 0, -62.237762451171875, -184.094970703125, 21.90195274353027343, 0.093841217458248138, 7200, 10, 0, 30837, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: 0 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+224, 10990, 30, 2597, 3305, '0', '0', 0, 0, 0, 119.6200180053710937, -336.5352783203125, 41.19380950927734375, 2.64208984375, 7200, 10, 0, 30837, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: Stonehearth Bunker - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+225, 12127, 30, 2597, 3305, '0', '0', 0, 0, 1, 169.89471435546875, -406.46612548828125, 42.85085678100585937, 2.65859222412109375, 7200, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Stormpike Guardsman (Area: Stonehearth Bunker - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+226, 14283, 30, 2597, 3305, '0', '0', 0, 0, 0, 172.14398193359375, -409.504425048828125, 43.20683670043945312, 2.759994745254516601, 7200, 0, 0, 16262, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Owl (Area: Stonehearth Bunker - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+227, 14283, 30, 2597, 3305, '0', '0', 0, 0, 0, 173.238128662109375, -405.654571533203125, 42.71883773803710937, 2.76035928726196289, 7200, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Owl (Area: Stonehearth Bunker - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+228, 10990, 30, 2597, 3305, '0', '0', 0, 0, 0, 156.73968505859375, -403.966888427734375, 43.03268814086914062, 2.500437259674072265, 7200, 0, 0, 30837, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: Stonehearth Bunker - Difficulty: 0) CreateObject1
(@CGUID+229, 13358, 30, 2597, 0, '0', '0', 0, 0, 1, 191.4756927490234375, -363.895843505859375, 57.18364715576171875, 3.246312379837036132, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Bowman (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+230, 13358, 30, 2597, 0, '0', '0', 0, 0, 1, 210.7777862548828125, -383.895843505859375, 56.97255325317382812, 4.084070205688476562, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Bowman (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+231, 10990, 30, 2597, 0, '0', '0', 0, 0, 0, 224.0523223876953125, -429.9776611328125, 42.052032470703125, 3.314453363418579101, 7200, 10, 0, 30837, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: 0 - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+232, 13320, 30, 2597, 0, '0', '0', 0, 0, 1, 214.0989532470703125, -373.896148681640625, 56.47092437744140625, 2.268928050994873046, 7200, 0, 0, 11291900, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Commander Karl Philips (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+233, 13358, 30, 2597, 0, '0', '0', 0, 0, 1, 225.795135498046875, -365.60589599609375, 56.93998336791992187, 5.98647928237915039, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Bowman (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+234, 13179, 30, 2597, 0, '0', '0', 0, 0, 1, 210.875, -357.359649658203125, 56.45859146118164062, 5.672319889068603515, 7200, 0, 0, 3138480, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Wing Commander Guse (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+235, 13358, 30, 2597, 0, '0', '0', 0, 0, 1, 219.64410400390625, -380.689239501953125, 57.14948654174804687, 5.096361160278320312, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Bowman (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+236, 14026, 30, 2597, 0, '0', '0', 0, 0, 1, 216.6145782470703125, -377.946197509765625, 62.6054534912109375, 5.009094715118408203, 7200, 0, 0, 338757, 6310, 0, NULL, NULL, NULL, NULL, 51536), -- Trigger Guse (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+237, 10986, 30, 2597, 2958, '0', '0', 0, 0, 0, 268.365478515625, -314.7735595703125, -17.8158245086669921, 1.771254658699035644, 7200, 10, 0, 52851, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Snowblind Harpy (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+238, 10990, 30, 2597, 2958, '0', '0', 0, 0, 0, 257.036346435546875, -259.2017822265625, -42.9873046875, 2.405469894409179687, 7200, 10, 0, 30837, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+239, 10990, 30, 2597, 2958, '0', '0', 0, 0, 0, 296.0267333984375, -289.264801025390625, -40.6783294677734375, 4.50579833984375, 7200, 0, 0, 30837, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1
(@CGUID+240, 10990, 30, 2597, 2958, '0', '0', 0, 0, 0, 330.282470703125, -369.63720703125, -7.50539636611938476, 4.29595041275024414, 7200, 0, 0, 30837, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+241, 13180, 30, 2597, 2958, '0', '0', 0, 0, 1, 320.48577880859375, -502.64508056640625, 71.23211669921875, 5.934119224548339843, 7200, 0, 0, 2519400, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Wing Commander Jeztor (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1
(@CGUID+242, 11675, 30, 2597, 2958, '0', '0', 0, 0, 0, 314.387908935546875, -319.0552978515625, -27.6710224151611328, 4.193727493286132812, 7200, 0, 0, 60817, 2705, 0, NULL, NULL, NULL, NULL, 51536), -- Snowblind Windcaller (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1
(@CGUID+243, 12127, 30, 2597, 2958, '0', '0', 0, 0, 1, 356.213958740234375, -386.099517822265625, -0.15065109729766845, 2.978997707366943359, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Guardsman (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+244, 12127, 30, 2597, 2958, '0', '0', 0, 0, 1, 356.643280029296875, -384.135406494140625, -0.04344063997268676, 2.982860326766967773, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Guardsman (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+245, 14028, 30, 2597, 2958, '0', '0', 0, 0, 1, 321.366973876953125, -501.10992431640625, 82.6384429931640625, 1.850049018859863281, 7200, 0, 0, 338757, 6310, 0, NULL, NULL, NULL, NULL, 51536), -- Trigger Jeztor (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1
(@CGUID+246, 10990, 30, 2597, 2958, '0', '0', 0, 0, 0, 383.140960693359375, -350.06231689453125, -29.1920146942138671, 5.511598587036132812, 7200, 10, 0, 30837, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+247, 10990, 30, 2597, 2958, '0', '0', 0, 0, 0, 319.802337646484375, -182.4083251953125, -30.6479969024658203, 4.909018516540527343, 7200, 10, 0, 30837, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+248, 10990, 30, 2597, 2958, '0', '0', 0, 0, 0, 398.817291259765625, -305.85302734375, -42.6216468811035156, 5.156808376312255859, 7200, 10, 0, 30837, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+249, 10990, 30, 2597, 2958, '0', '0', 0, 0, 0, 367.005859375, -221.115646362304687, -32.9090995788574218, 4.712388992309570312, 7200, 10, 0, 30837, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+250, 12127, 30, 2597, 2958, '0', '0', 0, 0, 1, 433.087005615234375, -377.782073974609375, -1.23743748664855957, 3.32160806655883789, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Guardsman (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+251, 12127, 30, 2597, 2958, '0', '0', 0, 0, 1, 432.7462158203125, -375.81097412109375, -1.24386870861053466, 3.321696281433105468, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Guardsman (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+252, 12127, 30, 2597, 2958, '0', '0', 0, 0, 1, 440.45489501953125, -434.41766357421875, 27.39102935791015625, 2.149053812026977539, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Guardsman (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+253, 12127, 30, 2597, 2958, '0', '0', 0, 0, 1, 442.204559326171875, -433.445770263671875, 27.5749664306640625, 2.145888328552246093, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Guardsman (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+254, 10990, 30, 2597, 3304, '0', '0', 0, 0, 0, 455.30615234375, -317.737152099609375, -35.2060546875, 2.0964813232421875, 7200, 0, 0, 30837, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: Icewing Bunker - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+255, 10990, 30, 2597, 3304, '0', '0', 0, 0, 0, 357.717620849609375, -130.31170654296875, -23.0535240173339843, 1.267562150955200195, 7200, 10, 0, 30837, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: Icewing Bunker - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+256, 10990, 30, 2597, 3304, '0', '0', 0, 0, 0, 428.068328857421875, -218.470352172851562, -19.9210319519042968, 0.326074182987213134, 7200, 10, 0, 30837, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: Icewing Bunker - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+257, 11678, 30, 2597, 3304, '0', '0', 0, 0, 0, 319.110870361328125, -116.038719177246093, -42.85125732421875, 6.072675704956054687, 7200, 10, 0, 45805, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Snowblind Ambusher (Area: Icewing Bunker - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+258, 10990, 30, 2597, 3304, '0', '0', 0, 0, 0, 481.5313720703125, -460.4854736328125, 44.9342193603515625, 1.932081222534179687, 7200, 0, 0, 30837, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: Icewing Bunker - Difficulty: 0) CreateObject1
(@CGUID+259, 10990, 30, 2597, 3304, '0', '0', 0, 0, 0, 512.8929443359375, -477.51666259765625, 58.49010848999023437, 1.967991948127746582, 7200, 10, 0, 30837, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: Icewing Bunker - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+260, 10990, 30, 2597, 3304, '0', '0', 0, 0, 0, 485.368560791015625, -228.847427368164062, 2.363247632980346679, 0.728750646114349365, 7200, 0, 0, 30837, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: Icewing Bunker - Difficulty: 0) CreateObject1
(@CGUID+261, 10990, 30, 2597, 3304, '0', '0', 0, 0, 0, 524.05291748046875, -285.49859619140625, -6.38813543319702148, 1.158721446990966796, 7200, 0, 0, 30837, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: Icewing Bunker - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+262, 10990, 30, 2597, 3304, '0', '0', 0, 0, 0, 454.254486083984375, -183.598434448242187, -3.03487348556518554, 0.064489707350730896, 7200, 0, 0, 30837, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: Icewing Bunker - Difficulty: 0) CreateObject1
(@CGUID+263, 10990, 30, 2597, 0, '0', '0', 0, 0, 0, 485.910552978515625, -170.523406982421875, 15.57205772399902343, 3.361955165863037109, 7200, 0, 0, 30837, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+264, 10990, 30, 2597, 0, '0', '0', 0, 0, 0, 515.07940673828125, -212.870803833007812, 3.424401760101318359, 0.210411667823791503, 7200, 0, 0, 30837, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+265, 10990, 30, 2597, 0, '0', '0', 0, 0, 0, 469.553131103515625, -150.062911987304687, 13.02879047393798828, 1.745581626892089843, 7200, 0, 0, 30837, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+266, 10990, 30, 2597, 0, '0', '0', 0, 0, 0, 325.09124755859375, -100.05572509765625, -42.8809471130371093, 3.132728338241577148, 7200, 0, 0, 30837, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+267, 10990, 30, 2597, 0, '0', '0', 0, 0, 0, 450.90777587890625, -118.911331176757812, 5.347516059875488281, 0.768825054168701171, 7200, 0, 0, 30837, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+268, 10990, 30, 2597, 0, '0', '0', 0, 0, 0, 483.14471435546875, -122.481826782226562, 12.068328857421875, 5.079843521118164062, 7200, 0, 0, 30837, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+269, 12127, 30, 2597, 0, '0', '0', 0, 0, 1, 636.4066162109375, -301.9053955078125, 30.14362716674804687, 4.506185531616210937, 7200, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Stormpike Guardsman (Area: 0 - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+270, 76357, 30, 2597, 0, '0', '0', 0, 0, 0, 615.6395263671875, -227.3525390625, -18.6280498504638671, 2.156091928482055664, 7200, 10, 0, 112919, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Alterac Brew-Hound (Area: 0 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+271, 12127, 30, 2597, 0, '0', '0', 0, 0, 1, 633.304931640625, -306.9642333984375, 30.13375282287597656, 4.506282806396484375, 7200, 0, 0, 225838, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Guardsman (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+272, 13319, 30, 2597, 0, '0', '0', 0, 0, 1, 672.40802001953125, -286.799224853515625, 29.75512504577636718, 3.612831592559814453, 7200, 0, 0, 11291900, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Commander Duffy (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+273, 12127, 30, 2597, 0, '0', '0', 0, 0, 1, 690.96075439453125, -423.792236328125, 63.84815216064453125, 3.712537288665771484, 7200, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Stormpike Guardsman (Area: 0 - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+274, 12127, 30, 2597, 0, '0', '0', 0, 0, 1, 707.78228759765625, -412.98773193359375, 61.39805221557617187, 0.670650243759155273, 7200, 10, 0, 225838, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Stormpike Guardsman (Area: 0 - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+275, 13797, 30, 2597, 0, '0', '0', 0, 0, 1, 613.4215087890625, -150.76373291015625, 33.45171356201171875, 5.550147056579589843, 7200, 0, 0, 417800, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Mountaineer Boombellow (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+276, 10990, 30, 2597, 0, '0', '0', 0, 0, 0, 712.54437255859375, -249.84283447265625, 29.61767196655273437, 4.106065750122070312, 7200, 0, 0, 30837, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+277, 13358, 30, 2597, 0, '0', '0', 0, 0, 1, 565.045166015625, -102.605903625488281, 52.71755599975585937, 5.305800914764404296, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Bowman (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+278, 10990, 30, 2597, 0, '0', '0', 0, 0, 0, 493.322052001953125, -69.515472412109375, 4.887516021728515625, 2.16313028335571289, 7200, 10, 0, 30837, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Alterac Ram (Area: 0 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+279, 13216, 30, 2597, 0, '0', '0', 0, 0, 1, 569.983154296875, -94.9992446899414062, 38.03253936767578125, 1.396263360977172851, 7200, 0, 0, 839800, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Gaelden Hammersmith (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+280, 13181, 30, 2597, 0, '0', '0', 0, 0, 1, 674.46923828125, -144.53375244140625, 63.73537826538085937, 5.619960308074951171, 7200, 0, 0, 3387570, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Wing Commander Mulverick (Area: 0 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+281, 13358, 30, 2597, 0, '0', '0', 0, 0, 1, 669.390625, -150.079864501953125, 64.18804931640625, 3.752457857131958007, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Bowman (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+282, 13358, 30, 2597, 0, '0', '0', 0, 0, 1, 575.30731201171875, -88.078125, 52.4368896484375, 5.951572895050048828, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Bowman (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+283, 13358, 30, 2597, 0, '0', '0', 0, 0, 1, 549.732666015625, -71.0208358764648437, 52.43095016479492187, 0.523598790168762207, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Bowman (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+284, 13358, 30, 2597, 0, '0', '0', 0, 0, 1, 661.5711669921875, -134.684036254882812, 64.32918548583984375, 3.385938644409179687, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Bowman (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+285, 13447, 30, 2597, 0, '0', '0', 0, 0, 1, 596.67950439453125, -83.063262939453125, 39.00511550903320312, 6.248278617858886718, 7200, 0, 0, 251940, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Corporal Noreg Stormpike (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+286, 13358, 30, 2597, 0, '0', '0', 0, 0, 1, 568.107666015625, -72.7899322509765625, 52.60601425170898437, 6.2657318115234375, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Bowman (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+287, 13358, 30, 2597, 0, '0', '0', 0, 0, 1, 670.1475830078125, -120.711807250976562, 64.18433380126953125, 2.129301786422729492, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Bowman (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+288, 13358, 30, 2597, 0, '0', '0', 0, 0, 1, 664.50518798828125, -126.3125, 64.20493316650390625, 2.775073528289794921, 7200, 0, 0, 451676, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Bowman (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+289, 14027, 30, 2597, 0, '0', '0', 0, 0, 1, 666.46746826171875, -132.471084594726562, 70.048004150390625, 0.087266460061073303, 7200, 0, 0, 338757, 6310, 0, NULL, NULL, NULL, NULL, 51536), -- Trigger Mulverick (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+290, 10986, 30, 2597, 0, '0', '0', 0, 0, 0, 423.351806640625, -49.5849037170410156, -4.3071141242980957, 2.358956813812255859, 7200, 10, 0, 45805, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Snowblind Harpy (Area: 0 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+291, 13318, 30, 2597, 0, '0', '0', 0, 0, 1, 624.81829833984375, -68.0300216674804687, 40.41750335693359375, 3.629711151123046875, 7200, 0, 0, 11291900, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Commander Mortimer (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+292, 4255, 30, 2597, 0, '0', '0', 0, 0, 1, 587.3031005859375, -42.82568359375, 37.5614776611328125, 5.235987663269042968, 7200, 0, 0, 268645, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Brogus Thunderbrew (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+293, 5134, 30, 2597, 0, '0', '0', 0, 0, 1, 591.4638671875, -44.4520416259765625, 37.6165618896484375, 5.654866695404052734, 7200, 0, 0, 537290, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Jonivera Farmountain (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+294, 14187, 30, 2597, 0, '0', '0', 0, 0, 1, 648.3634033203125, -65.2233047485351562, 41.74046707153320312, 3.124139308929443359, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Athramanis (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+295, 14188, 30, 2597, 0, '0', '0', 0, 0, 1, 648.23785400390625, -67.89306640625, 41.7404632568359375, 2.600540637969970703, 7200, 0, 0, 104616, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Dirk Swindle (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+296, 12096, 30, 2597, 0, '0', '0', 0, 0, 1, 587.63311767578125, -45.9815559387207031, 37.54380416870117187, 5.811946392059326171, 7200, 0, 0, 537290, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Quartermaster (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+297, 11675, 30, 2597, 0, '0', '0', 0, 0, 0, 433.706268310546875, -41.0434036254882812, -0.38693165779113769, 3.804817676544189453, 7200, 10, 0, 60817, 2705, 1, NULL, NULL, NULL, NULL, 51536), -- Snowblind Windcaller (Area: 0 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+298, 10986, 30, 2597, 0, '0', '0', 0, 0, 0, 452.20489501953125, -34.176788330078125, -0.17213165760040283, 2.534069776535034179, 7200, 10, 0, 45805, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Snowblind Harpy (Area: 0 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+299, 13257, 30, 2597, 0, '0', '0', 0, 0, 1, 647.60968017578125, -61.1548385620117187, 41.74046707153320312, 4.24114990234375, 7200, 0, 0, 1129190, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Murgot Deepforge (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+300, 4257, 30, 2597, 0, '0', '0', 0, 0, 1, 643.63543701171875, -58.3987083435058593, 41.74046707153320312, 4.729842185974121093, 7200, 0, 0, 537290, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Lana Thunderbrew (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+301, 5135, 30, 2597, 0, '0', '0', 0, 0, 1, 608.51495361328125, -33.3935012817382812, 42.00032424926757812, 5.410520553588867187, 7200, 0, 0, 537290, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Svalbrad Farmountain (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+302, 14284, 30, 2597, 0, '0', '0', 0, 0, 1, 773.04144287109375, -485.532012939453125, 98.861297607421875, 4.223696708679199218, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Battleguard (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+303, 14284, 30, 2597, 0, '0', '0', 0, 0, 1, 776.62078857421875, -487.775390625, 99.404937744140625, 3.50811171531677246, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Battleguard (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+304, 14284, 30, 2597, 0, '0', '0', 0, 0, 1, 776.8299560546875, -496.35894775390625, 99.70737457275390625, 2.513274192810058593, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Battleguard (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+305, 14284, 30, 2597, 0, '0', '0', 0, 0, 1, 773.6513671875, -497.4815673828125, 99.04083251953125, 2.111848354339599609, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Battleguard (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+306, 13443, 30, 2597, 0, '0', '0', 0, 0, 1, 729.11761474609375, -82.8713150024414062, 51.6334991455078125, 2.530727386474609375, 7200, 0, 0, 903352, 25240, 0, NULL, NULL, NULL, NULL, 51536), -- Druid of the Grove (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+307, 13443, 30, 2597, 0, '0', '0', 0, 0, 1, 724.7677001953125, -84.1642227172851562, 51.6334991455078125, 0.733038306236267089, 7200, 0, 0, 903352, 25240, 0, NULL, NULL, NULL, NULL, 51536), -- Druid of the Grove (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+308, 13443, 30, 2597, 0, '0', '0', 0, 0, 1, 725.5535888671875, -79.497344970703125, 51.6334991455078125, 5.270894527435302734, 7200, 0, 0, 903352, 25240, 0, NULL, NULL, NULL, NULL, 51536), -- Druid of the Grove (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+309, 13442, 30, 2597, 0, '0', '0', 0, 0, 1, 729.2001953125, -78.81201171875, 51.6334991455078125, 3.979350566864013671, 7200, 0, 0, 1355028, 37860, 0, NULL, NULL, NULL, NULL, 51536), -- Archdruid Renferal (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+310, 5139, 30, 2597, 0, '0', '0', 0, 0, 1, 617.65570068359375, -32.0700950622558593, 42.71676254272460937, 4.066617012023925781, 7200, 0, 0, 537290, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Kurdrum Barleybeard (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+311, 14284, 30, 2597, 0, '0', '0', 0, 0, 1, 854.27642822265625, -494.241424560546875, 96.80171966552734375, 5.445427417755126953, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Battleguard (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+312, 14284, 30, 2597, 0, '0', '0', 0, 0, 1, 857.81610107421875, -491.926666259765625, 96.9192352294921875, 4.86946868896484375, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Battleguard (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+313, 13617, 30, 2597, 0, '0', '0', 0, 0, 1, 610.23907470703125, -21.845376968383789, 43.27197647094726562, 4.904375076293945312, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Stable Master (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+314, 14848, 30, 2597, 3303, '0', '0', 0, 0, 2, 699.27386474609375, -17.6360683441162109, 90.39348602294921875, 3.473205089569091796, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Herald (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1
(@CGUID+315, 13778, 30, 2597, 3303, '0', '0', 0, 0, 0, 704.94696044921875, -18.670083999633789, 91.9336090087890625, 2.670353651046752929, 7200, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51536), -- PvP Tower Credit Marker (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+316, 14765, 30, 2597, 3303, '0', '0', 0, 0, 1, 720.0460205078125, -19.9412975311279296, 50.21866607666015625, 3.368485450744628906, 7200, 0, 0, 52952836, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stonehearth Marshal (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: 45830 - Stonehearth Marshal)
(@CGUID+317, 13756, 30, 2597, 3303, '0', '0', 0, 0, 0, 705.0177001953125, -19.4748802185058593, 91.88559722900390625, 2.181661605834960937, 7200, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51536), -- PvP Graveyard Credit Marker (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+318, 13778, 30, 2597, 3303, '0', '0', 0, 0, 0, 704.58380126953125, -18.1901588439941406, 91.87030029296875, 6.2657318115234375, 7200, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51536), -- PvP Tower Credit Marker (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+319, 22515, 30, 2597, 3303, '0', '0', 0, 0, 0, 711.01019287109375, -13.6138782501220703, 50.21866607666015625, 4.276056766510009765, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 51536), -- World Trigger (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1
(@CGUID+320, 13796, 30, 2597, 3303, '0', '0', 0, 0, 0, 704.12823486328125, -17.599283218383789, 91.78995513916015625, 3.839724302291870117, 7200, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51536), -- PvP Mine Credit Marker (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+321, 13756, 30, 2597, 3303, '0', '0', 0, 0, 0, 703.39068603515625, -18.9669055938720703, 91.46258544921875, 4.118977069854736328, 7200, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51536), -- PvP Graveyard Credit Marker (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+322, 14762, 30, 2597, 3303, '0', '0', 0, 0, 1, 723.057861328125, -14.1548404693603515, 50.70463180541992187, 3.40339207649230957, 7200, 0, 0, 52952836, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Dun Baldar North Marshal (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: 45828 - Dun Baldar North Marshal)
(@CGUID+323, 13577, 30, 2597, 3303, '0', '0', 0, 0, 1, 600.03216552734375, -2.92475104331970214, 42.07876968383789062, 5.009094715118408203, 7200, 0, 0, 1806704, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Ram Rider Commander (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+324, 14763, 30, 2597, 3303, '0', '0', 0, 0, 1, 721.10418701171875, -7.64154720306396484, 50.70463180541992187, 3.455751895904541015, 7200, 0, 0, 52952836, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Dun Baldar South Marshal (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: 45829 - Dun Baldar South Marshal)
(@CGUID+325, 14764, 30, 2597, 3303, '0', '0', 0, 0, 1, 715.69097900390625, -4.72233104705810546, 50.21866607666015625, 3.473205089569091796, 7200, 0, 0, 52952836, 0, 0, NULL, NULL, NULL, NULL, 51536); -- Icewing Marshal (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: 45831 - Icewing Marshal)

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+326, 13116, 30, 2597, 2959, '0', '0', 0, 0, 1, 872.7252197265625, -497.276580810546875, 96.76715087890625, 0.522441446781158447, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 51536), -- Alliance Spirit Guide (Area: Dun Baldar - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+327, 13116, 30, 2597, 2959, '0', '0', 0, 0, 1, 873.29022216796875, -484.94586181640625, 96.74733734130859375, 4.642575740814208984, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 51536), -- Alliance Spirit Guide (Area: Dun Baldar - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+328, 13117, 30, 2597, 0, '0', '0', 0, 0, 1, -1432.1041259765625, -611.27777099609375, 51.31681060791015625, 1.169307231903076171, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 51536), -- Horde Spirit Guide (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+329, 13117, 30, 2597, 0, '0', '0', 0, 0, 1, -1442.51220703125, -603.31768798828125, 51.37030792236328125, 0.781178653240203857, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 51536), -- Horde Spirit Guide (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+330, 14773, 30, 2597, 0, '0', '0', 0, 0, 1, -1376.09033203125, -226.29541015625, 98.509918212890625, 5.16617441177368164, 7200, 0, 0, 52952836, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Iceblood Warmaster (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 45822 - Iceblood Warmaster)
(@CGUID+331, 14776, 30, 2597, 0, '0', '0', 0, 0, 1, -1363.0594482421875, -220.030487060546875, 98.48016357421875, 5.113814830780029296, 7200, 0, 0, 52952836, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Tower Point Warmaster (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 45823 - Tower Point Warmaster)
(@CGUID+332, 22515, 30, 2597, 0, '0', '0', 0, 0, 0, -1367.2799072265625, -227.151687622070312, 98.5079345703125, 5.131268024444580078, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 51536), -- World Trigger (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+333, 14777, 30, 2597, 0, '0', '0', 0, 0, 1, -1373.6953125, -222.202850341796875, 98.509918212890625, 5.148721218109130859, 7200, 0, 0, 52952836, 0, 0, NULL, NULL, NULL, NULL, 51536), -- West Frostwolf Warmaster (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 45824 - West Frostwolf Warmaster)
(@CGUID+334, 14772, 30, 2597, 0, '0', '0', 0, 0, 1, -1368.0845947265625, -219.586318969726562, 98.509918212890625, 5.113814830780029296, 7200, 0, 0, 52952836, 0, 0, NULL, NULL, NULL, NULL, 51536), -- East Frostwolf Warmaster (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 45826 - East Frostwolf Warmaster)
(@CGUID+335, 12121, 30, 2597, 0, '0', '0', 0, 0, 0, -1376.3118896484375, -219.308486938476562, 99.454620361328125, 4.607669353485107421, 7200, 0, 0, 3177170, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Drakan (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+336, 12122, 30, 2597, 0, '0', '0', 0, 0, 0, -1366.1961669921875, -216.074172973632812, 99.45421600341796875, 5.462880611419677734, 7200, 0, 0, 3177170, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Duros (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+337, 12097, 30, 2597, 0, '0', '0', 0, 0, 1, -1293.7867431640625, -194.407196044921875, 72.439788818359375, 5.846852779388427734, 7200, 0, 0, 537290, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Frostwolf Quartermaster (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+338, 10986, 30, 2597, 3057, '0', '0', 0, 0, 0, -15.8123817443847656, 30.85076332092285156, 17.211212158203125, 1.934207081794738769, 7200, 0, 0, 52851, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Snowblind Harpy (Area: Field of Strife - Difficulty: 0) CreateObject1
(@CGUID+339, 11678, 30, 2597, 3057, '0', '0', 0, 0, 0, 16.56490325927734375, 8.419537544250488281, -3.3024749755859375, 5.284939289093017578, 7200, 0, 0, 45805, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Snowblind Ambusher (Area: Field of Strife - Difficulty: 0) CreateObject1
(@CGUID+340, 10986, 30, 2597, 3057, '0', '0', 0, 0, 0, 8.917099952697753906, 16.19168281555175781, -3.10221767425537109, 6.217091560363769531, 7200, 0, 0, 45805, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Snowblind Harpy (Area: Field of Strife - Difficulty: 0) CreateObject1
(@CGUID+341, 11675, 30, 2597, 3057, '0', '0', 0, 0, 0, 43.123321533203125, -12.3202400207519531, -4.09882354736328125, 1.715870618820190429, 7200, 0, 0, 52851, 2620, 0, NULL, NULL, NULL, NULL, 51536), -- Snowblind Windcaller (Area: Field of Strife - Difficulty: 0) CreateObject1
(@CGUID+342, 11675, 30, 2597, 3057, '0', '0', 0, 0, 0, -0.51753824949264526, 82.9122772216796875, 19.30907630920410156, 0.494528830051422119, 7200, 0, 0, 52851, 2620, 0, NULL, NULL, NULL, NULL, 51536), -- Snowblind Windcaller (Area: Field of Strife - Difficulty: 0) CreateObject1
(@CGUID+343, 11675, 30, 2597, 3057, '0', '0', 0, 0, 0, 28.51379013061523437, 44.035491943359375, 0.683287501335144042, 5.785817623138427734, 7200, 0, 0, 52851, 2620, 0, NULL, NULL, NULL, NULL, 51536), -- Snowblind Windcaller (Area: Field of Strife - Difficulty: 0) CreateObject1
(@CGUID+344, 11675, 30, 2597, 3301, '0', '0', 0, 0, 0, 52.5637969970703125, 22.27169609069824218, -4.10893630981445312, 0.300644129514694213, 7200, 0, 0, 52851, 2620, 0, NULL, NULL, NULL, NULL, 51536), -- Snowblind Windcaller (Area: Snowfall Graveyard - Difficulty: 0) CreateObject1
(@CGUID+415, 14283, 30, 2597, 0, '0', '0', 0, 0, 0, 819.7117919921875, -497.868865966796875, 100.4365234375, 3.016581535339355468, 7200, 10, 0, 18713, 0, 1, NULL, NULL, NULL, NULL, 51886), -- Stormpike Owl (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+416, 14284, 30, 2597, 0, '0', '0', 0, 0, 1, 807.77557373046875, -495.041900634765625, 100.10198974609375, 3.072868108749389648, 7200, 10, 0, 16937850, 0, 1, NULL, NULL, NULL, NULL, 51886), -- Stormpike Battleguard (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike) (possible waypoints or random movement)
(@CGUID+417, 14283, 30, 2597, 0, '0', '0', 0, 0, 0, 819.9866943359375, -493.878326416015625, 100.495574951171875, 3.016885042190551757, 7200, 10, 0, 16262, 0, 1, NULL, NULL, NULL, NULL, 51886), -- Stormpike Owl (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+418, 14283, 30, 2597, 3303, '0', '0', 0, 0, 0, 872.9686279296875, -491.475128173828125, 96.531646728515625, 3.361934661865234375, 7200, 10, 0, 18713, 0, 1, NULL, NULL, NULL, NULL, 51886), -- Stormpike Owl (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+419, 14284, 30, 2597, 3303, '0', '0', 0, 0, 1, 867.23974609375, -493.95440673828125, 96.5595855712890625, 3.704070091247558593, 7200, 10, 0, 16937850, 0, 1, NULL, NULL, NULL, NULL, 51886), -- Stormpike Battleguard (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike) (possible waypoints or random movement)
(@CGUID+420, 14283, 30, 2597, 3303, '0', '0', 0, 0, 0, 868.632568359375, -496.753692626953125, 96.5695953369140625, 3.48145914077758789, 7200, 10, 0, 16262, 0, 1, NULL, NULL, NULL, NULL, 51886), -- Stormpike Owl (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+421, 14284, 30, 2597, 3303, '0', '0', 0, 0, 1, 883.60015869140625, -500.616546630859375, 96.8499603271484375, 2.251474618911743164, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51886), -- Stormpike Battleguard (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+422, 14284, 30, 2597, 3303, '0', '0', 0, 0, 1, 878.92059326171875, -508.4962158203125, 96.79261016845703125, 1.151917338371276855, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51886), -- Stormpike Battleguard (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+423, 14284, 30, 2597, 3303, '0', '0', 0, 0, 1, 884.738525390625, -497.807830810546875, 96.90430450439453125, 3.019419670104980468, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51886), -- Stormpike Battleguard (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+424, 14284, 30, 2597, 3303, '0', '0', 0, 0, 1, 936.85198974609375, -504.9757080078125, 94.2293243408203125, 5.724679946899414062, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51886), -- Stormpike Battleguard (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+425, 14284, 30, 2597, 3303, '0', '0', 0, 0, 1, 939.4197998046875, -502.777130126953125, 94.58873748779296875, 5.148721218109130859, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51886), -- Stormpike Battleguard (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+426, 14284, 30, 2597, 2957, '0', '0', 0, 0, 1, 949.0997314453125, -506.912872314453125, 95.4236907958984375, 3.31612563133239746, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51886), -- Stormpike Battleguard (Area: Irondeep Mine - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+427, 11997, 30, 2597, 2957, '0', '0', 0, 0, 1, 930.498046875, -520.755126953125, 93.7333984375, 1.832595705986022949, 7200, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 51886), -- Stormpike Herald (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+428, 14284, 30, 2597, 2957, '0', '0', 0, 0, 1, 947.4122314453125, -509.981658935546875, 95.109832763671875, 2.827433347702026367, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51886), -- Stormpike Battleguard (Area: Irondeep Mine - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+429, 154476, 30, 2597, 2597, '0', '0', 0, 0, 1, 798.29339599609375, -489.930572509765625, 99.73561859130859375, 5.717492103576660156, 7200, 0, 0, 1355028, 37860, 0, NULL, NULL, NULL, NULL, 51886), -- Archdruid Renferal (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+430, 154478, 30, 2597, 2597, '0', '0', 0, 0, 1, 796.96356201171875, -497.578125, 99.708099365234375, 0.373647898435592651, 7200, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51886), -- Prospector Stonehewer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+431, 14284, 30, 2597, 3303, '0', '0', 0, 0, 1, 863.11358642578125, -508.144439697265625, 96.5519256591796875, 2.007128715515136718, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Stormpike Battleguard (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)
(@CGUID+432, 14284, 30, 2597, 3303, '0', '0', 0, 0, 1, 866.84442138671875, -505.840484619140625, 96.5324859619140625, 2.460914134979248046, 7200, 0, 0, 16937850, 0, 0, NULL, NULL, NULL, NULL, 51536); -- Stormpike Battleguard (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: 12782 - Shield Spike)

-- -- Irondeep Mine - Horde
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+433, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 897.92901611328125, -471.74176025390625, 59.77292251586914062, 2.548180580139160156, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+434, 13099, 30, 2597, 2957, '0', '0', 0, 0, 1, 832.0352783203125, -389.300689697265625, 47.55669021606445312, 2.111848354339599609, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Explorer (Area: Irondeep Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+435, 13081, 30, 2597, 2957, '0', '0', 0, 0, 1, 957.2930908203125, -455.038848876953125, 56.739501953125, 5.79449319839477539, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Raider (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+436, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 909.24591064453125, -474.575531005859375, 58.29007339477539062, 0.226892799139022827, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+437, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 835.077392578125, -379.41796875, 48.275482177734375, 5.934119224548339843, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+438, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 913.064453125, -395.7725830078125, 60.13639068603515625, 4.415682792663574218, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+439, 13099, 30, 2597, 2957, '0', '0', 0, 0, 1, 955.8116455078125, -440.3018798828125, 55.34113693237304687, 3.193952560424804687, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Explorer (Area: Irondeep Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+440, 13081, 30, 2597, 2957, '0', '0', 0, 0, 1, 883.54962158203125, -443.284393310546875, 54.711883544921875, 1.850049018859863281, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Raider (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+441, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 890.58441162109375, -406.049468994140625, 61.19248199462890625, 5.672319889068603515, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+442, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 868.2474365234375, -343.1363525390625, 64.98935699462890625, 1.605702877044677734, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+443, 13099, 30, 2597, 2957, '0', '0', 0, 0, 1, 884.23663330078125, -407.596588134765625, 61.56597900390625, 0.820304751396179199, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Explorer (Area: Irondeep Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+444, 13081, 30, 2597, 2957, '0', '0', 0, 0, 1, 902.1949462890625, -475.891265869140625, 58.39536285400390625, 1.396263360977172851, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Raider (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+445, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 901.8092041015625, -457.708648681640625, 59.06573486328125, 3.525565147399902343, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+446, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 887.647216796875, -391.536895751953125, 61.8733978271484375, 1.378810048103332519, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+447, 13099, 30, 2597, 2957, '0', '0', 0, 0, 1, 909.9901123046875, -462.153533935546875, 59.16436767578125, 3.700098037719726562, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Explorer (Area: Irondeep Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+448, 13081, 30, 2597, 2957, '0', '0', 0, 0, 1, 907.89312744140625, -388.787445068359375, 61.79233551025390625, 5.742133140563964843, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Raider (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+449, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 821.00555419921875, -387.634979248046875, 49.07283401489257812, 3.159045934677124023, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+450, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 948.25042724609375, -448.267791748046875, 56.90093612670898437, 5.602506637573242187, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+451, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 905.06689453125, -396.07366943359375, 60.2085418701171875, 5.078907966613769531, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+452, 13099, 30, 2597, 2957, '0', '0', 0, 0, 1, 840.55987548828125, -384.443267822265625, 61.79925537109375, 5.761559486389160156, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Explorer (Area: Irondeep Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+453, 13079, 30, 2597, 2957, '0', '0', 0, 0, 1, 879.22064208984375, -443.25726318359375, 54.73109054565429687, 1.832595705986022949, 10, 0, 0, 83980, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Keetar (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+454, 13081, 30, 2597, 2957, '0', '0', 0, 0, 1, 878.309326171875, -448.080078125, 54.81945419311523437, 1.640609502792358398, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Raider (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+455, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 877.126708984375, -351.799652099609375, 66.5296173095703125, 5.742133140563964843, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+456, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 817.26007080078125, -447.431854248046875, 49.43082427978515625, 2.181661605834960937, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+457, 13099, 30, 2597, 2957, '0', '0', 0, 0, 1, 871.0357666015625, -404.119354248046875, 62.22373199462890625, 4.502949237823486328, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Explorer (Area: Irondeep Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+458, 13081, 30, 2597, 2957, '0', '0', 0, 0, 1, 856.70880126953125, -395.279632568359375, 61.29386138916015625, 5.183627605438232421, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Raider (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+459, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 921.9716796875, -358.596954345703125, 66.4312591552734375, 2.932153224945068359, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+460, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 849.859619140625, -340.94439697265625, 66.24468994140625, 0.401425719261169433, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+461, 13099, 30, 2597, 2957, '0', '0', 0, 0, 1, 827.01202392578125, -457.3974609375, 48.93306350708007812, 2.356194496154785156, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Explorer (Area: Irondeep Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+462, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 874.57708740234375, -414.785919189453125, 52.78171539306640625, 1.675516128540039062, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+463, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 852.6319580078125, -372.415802001953125, 48.165679931640625, 3.665191411972045898, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+464, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 831.7110595703125, -346.784576416015625, 47.29748916625976562, 0.226892799139022827, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+465, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 821.891845703125, -464.72308349609375, 48.94509506225585937, 4.660028934478759765, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+466, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 834.87042236328125, -453.304046630859375, 47.9074554443359375, 0.226892799139022827, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+467, 13099, 30, 2597, 2957, '0', '0', 0, 0, 1, 877.98895263671875, -418.050994873046875, 52.97534561157226562, 4.468042850494384765, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Explorer (Area: Irondeep Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+468, 13081, 30, 2597, 2957, '0', '0', 0, 0, 1, 868.1221923828125, -392.865570068359375, 61.56705474853515625, 2.426007747650146484, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Raider (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+469, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 859.0302734375, -367.23089599609375, 47.4655303955078125, 0.01745329238474369, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+470, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 900.96185302734375, -427.44000244140625, 59.0841522216796875, 1.500983119010925292, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+471, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 857.51251220703125, -351.817047119140625, 65.186737060546875, 4.398229598999023437, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+472, 13099, 30, 2597, 2957, '0', '0', 0, 0, 1, 846.93927001953125, -347.27886962890625, 66.287628173828125, 0.942477762699127197, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Explorer (Area: Irondeep Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+473, 13081, 30, 2597, 2957, '0', '0', 0, 0, 1, 817.82977294921875, -455.71484375, 48.420745849609375, 0.92502450942993164, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Raider (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+474, 13081, 30, 2597, 2957, '0', '0', 0, 0, 1, 898.800537109375, -437.10504150390625, 58.52662277221679687, 0.959931075572967529, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Raider (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+475, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 881.61822509765625, -419.948028564453125, 53.64105987548828125, 0.593411922454833984, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+476, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 907.208740234375, -428.266815185546875, 59.88685989379882812, 1.867502331733703613, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+477, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 834.35430908203125, -355.5263671875, 48.14905929565429687, 6.0737457275390625, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+478, 13099, 30, 2597, 2957, '0', '0', 0, 0, 1, 851.47052001953125, -362.52008056640625, 47.31400299072265625, 4.066617012023925781, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Explorer (Area: Irondeep Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+479, 13081, 30, 2597, 2957, '0', '0', 0, 0, 1, 826.401611328125, -349.453887939453125, 47.27222061157226562, 1.518436431884765625, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Raider (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+480, 13081, 30, 2597, 2957, '0', '0', 0, 0, 1, 876.046630859375, -341.85699462890625, 65.8742828369140625, 4.450589656829833984, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Raider (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+481, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 971.67120361328125, -442.657440185546875, 57.69507598876953125, 3.176499128341674804, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+482, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 823.2218017578125, -334.283111572265625, 65.63056182861328125, 4.886921882629394531, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+483, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 893.37603759765625, -343.1708984375, 68.14989471435546875, 5.358160972595214843, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+484, 13099, 30, 2597, 2957, '0', '0', 0, 0, 1, 950.07696533203125, -326.6719970703125, 61.65517807006835937, 5.480333805084228515, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Explorer (Area: Irondeep Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+485, 13081, 30, 2597, 2957, '0', '0', 0, 0, 1, 936.69183349609375, -356.78033447265625, 65.98349761962890625, 2.757620096206665039, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Raider (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+486, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 921.44921875, -341.98089599609375, 67.12642669677734375, 3.438298702239990234, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+487, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 957.11297607421875, -325.919921875, 61.75893783569335937, 1.134464025497436523, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+488, 13081, 30, 2597, 2957, '0', '0', 0, 0, 1, 808.95343017578125, -325.96435546875, 52.50748443603515625, 3.019419670104980468, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Raider (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+489, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 805.39947509765625, -320.145843505859375, 52.85462188720703125, 0.296705961227416992, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+490, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 888.208251953125, -332.564453125, 68.14801025390625, 1.93731546401977539, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+491, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 969.97918701171875, -457.14788818359375, 58.11191177368164062, 4.520402908325195312, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+492, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 833.701904296875, -327.505523681640625, 65.0438690185546875, 0.331612557172775268, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+493, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 931.14581298828125, -359.6656494140625, 66.02935791015625, 3.96189737319946289, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+494, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 958.6923828125, -333.476837158203125, 63.22761154174804687, 5.777040004730224609, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+495, 13099, 30, 2597, 2957, '0', '0', 0, 0, 1, 825.53485107421875, -322.37298583984375, 63.93574905395507812, 4.764749050140380859, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Explorer (Area: Irondeep Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+496, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 801.4046630859375, -328.054595947265625, 53.01951980590820312, 4.310963153839111328, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+497, 13099, 30, 2597, 2957, '0', '0', 0, 0, 1, 925.05889892578125, -331.346527099609375, 65.75640106201171875, 3.665191411972045898, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Explorer (Area: Irondeep Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+498, 13099, 30, 2597, 2957, '0', '0', 0, 0, 1, 897.4644775390625, -338.757965087890625, 68.171539306640625, 2.94960641860961914, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Explorer (Area: Irondeep Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+499, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 914.56768798828125, -326.2099609375, 66.1732635498046875, 2.251474618911743164, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+500, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 926.84893798828125, -379.073577880859375, 63.52860260009765625, 2.094395160675048828, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+501, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 833.1505126953125, -374.2275390625, 63.09382247924804687, 3.665191411972045898, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+502, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 847.6014404296875, -423.071502685546875, 50.0852203369140625, 4.572762489318847656, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+503, 13099, 30, 2597, 2957, '0', '0', 0, 0, 1, 926.4747314453125, -419.344635009765625, 56.18328094482421875, 2.094395160675048828, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Explorer (Area: Irondeep Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+504, 13081, 30, 2597, 2957, '0', '0', 0, 0, 1, 842.08026123046875, -421.775054931640625, 48.265869140625, 1.082104086875915527, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Raider (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+505, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 931.75067138671875, -403.4580078125, 59.67373275756835937, 5.637413501739501953, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+506, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 834.6343994140625, -365.981170654296875, 62.88013458251953125, 1.326450228691101074, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+507, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 934.726806640625, -385.802093505859375, 63.03435516357421875, 3.752457857131958007, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+508, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 847.1351318359375, -411.307281494140625, 50.21063995361328125, 1.570796370506286621, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+509, 13081, 30, 2597, 2957, '0', '0', 0, 0, 1, 838.35797119140625, -371.2119140625, 63.3298797607421875, 4.049163818359375, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Raider (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+510, 13081, 30, 2597, 2957, '0', '0', 0, 0, 1, 937.3780517578125, -377.81585693359375, 65.39192962646484375, 3.560471534729003906, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Raider (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+511, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 929.7022705078125, -412.4005126953125, 56.95518112182617187, 5.899212837219238281, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+513, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 775.5611572265625, -317.02642822265625, 63.09909820556640625, 0.003052708692848682, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+515, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 775.4708251953125, -316.938323974609375, 63.1527252197265625, 5.598447322845458984, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+516, 13081, 30, 2597, 2957, '0', '0', 0, 0, 1, 778.392578125, -320.66314697265625, 63.18989181518554687, 2.30383467674255371, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Raider (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+518, 13397, 30, 2597, 2957, '0', '0', 0, 0, 1, 775.61541748046875, -317.4940185546875, 63.09960556030273437, 2.312026500701904296, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Peon (Area: Irondeep Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+519, 13099, 30, 2597, 2957, '0', '0', 0, 0, 1, 776.23590087890625, -318.25067138671875, 63.09943771362304687, 2.356378078460693359, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649); -- Irondeep Explorer (Area: Irondeep Mine - Difficulty: 0) CreateObject1 (Auras: )

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1146;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+513, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Irondeep Peon
(@CGUID+515, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Irondeep Peon
(@CGUID+518, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''); -- Irondeep Peon

DELETE FROM `creature_template_addon` WHERE `entry` IN (13079, 13099, 13397 /*13397 (Irondeep Peon)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(13079, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 13079 (Keetar)
(13099, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 13099 (Irondeep Explorer)
(13397, 0, 0, 0, 0, 0, 1, 1, 233, 0, 0, 0, 0, ''); -- 13317 (Coldmine Miner)

-- Irondeep Mine - Alliance
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+520, 13098, 30, 2597, 2957, '0', '0', 0, 0, 1, 832.0352783203125, -389.300689697265625, 47.55669021606445312, 2.111848354339599609, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Surveyor (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+521, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 931.75067138671875, -403.4580078125, 59.67373275756835937, 5.637413501739501953, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+522, 13080, 30, 2597, 2957, '0', '0', 0, 0, 1, 926.4747314453125, -419.344635009765625, 56.18328094482421875, 2.094395160675048828, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Guard (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+523, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 948.25042724609375, -448.267791748046875, 56.90093612670898437, 5.602506637573242187, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+524, 13098, 30, 2597, 2957, '0', '0', 0, 0, 1, 868.1221923828125, -392.865570068359375, 61.56705474853515625, 2.426007747650146484, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Surveyor (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+525, 13098, 30, 2597, 2957, '0', '0', 0, 0, 1, 817.82977294921875, -455.71484375, 48.420745849609375, 0.92502450942993164, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Surveyor (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+526, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 926.84893798828125, -379.073577880859375, 63.52860260009765625, 2.094395160675048828, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+527, 13098, 30, 2597, 2957, '0', '0', 0, 0, 1, 878.08343505859375, -447.649078369140625, 54.79834747314453125, 2.076941728591918945, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Surveyor (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+528, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 857.51251220703125, -351.817047119140625, 65.186737060546875, 4.398229598999023437, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+529, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 821.891845703125, -464.72308349609375, 48.94509506225585937, 4.660028934478759765, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+530, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 821.00555419921875, -387.634979248046875, 49.07283401489257812, 3.159045934677124023, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+531, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 833.1505126953125, -374.2275390625, 63.09382247924804687, 3.665191411972045898, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+532, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 929.7022705078125, -412.4005126953125, 56.95518112182617187, 5.899212837219238281, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+533, 13080, 30, 2597, 2957, '0', '0', 0, 0, 1, 871.0357666015625, -404.119354248046875, 62.22373199462890625, 4.502949237823486328, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Guard (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+534, 13098, 30, 2597, 2957, '0', '0', 0, 0, 1, 838.35797119140625, -371.2119140625, 63.3298797607421875, 4.049163818359375, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Surveyor (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+535, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 834.87042236328125, -453.304046630859375, 47.9074554443359375, 0.226892799139022827, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+536, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 934.726806640625, -385.802093505859375, 63.03435516357421875, 3.752457857131958007, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+537, 13098, 30, 2597, 2957, '0', '0', 0, 0, 1, 883.21551513671875, -443.46929931640625, 54.7146759033203125, 2.234021425247192382, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Surveyor (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+538, 13098, 30, 2597, 2957, '0', '0', 0, 0, 1, 840.55987548828125, -384.443267822265625, 61.79925537109375, 5.761559486389160156, 300, 10, 0, 18713, 5410, 1, NULL, NULL, NULL, NULL, 52649), -- Irondeep Surveyor (Area: Irondeep Mine - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+539, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 834.6343994140625, -365.981170654296875, 62.88013458251953125, 1.326450228691101074, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+540, 13078, 30, 2597, 2957, '0', '0', 0, 0, 1, 880.236083984375, -444.586700439453125, 54.68965530395507812, 2.460914134979248046, 10, 10, 0, 83980, 0, 1, NULL, NULL, NULL, NULL, 52649), -- Umi Thorson (Area: Irondeep Mine - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+541, 13080, 30, 2597, 2957, '0', '0', 0, 0, 1, 856.70880126953125, -395.279632568359375, 61.29386138916015625, 5.183627605438232421, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Guard (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+542, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 817.26007080078125, -447.431854248046875, 49.43082427978515625, 2.181661605834960937, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+543, 13080, 30, 2597, 2957, '0', '0', 0, 0, 1, 827.01202392578125, -457.3974609375, 48.93306350708007812, 2.356194496154785156, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Guard (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+544, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 835.077392578125, -379.41796875, 48.275482177734375, 5.934119224548339843, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+545, 13080, 30, 2597, 2957, '0', '0', 0, 0, 1, 937.3780517578125, -377.81585693359375, 65.39192962646484375, 3.560471534729003906, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Guard (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+546, 13098, 30, 2597, 2957, '0', '0', 0, 0, 1, 846.93927001953125, -347.27886962890625, 66.287628173828125, 0.942477762699127197, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Surveyor (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+547, 13098, 30, 2597, 2957, '0', '0', 0, 0, 1, 957.2930908203125, -455.038848876953125, 56.739501953125, 5.79449319839477539, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Surveyor (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+548, 13080, 30, 2597, 2957, '0', '0', 0, 0, 1, 955.8116455078125, -440.3018798828125, 55.34113693237304687, 3.193952560424804687, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Guard (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+549, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 914.56768798828125, -326.2099609375, 66.1732635498046875, 2.251474618911743164, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+550, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 969.97918701171875, -457.14788818359375, 58.11191177368164062, 4.520402908325195312, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+551, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 921.44921875, -341.98089599609375, 67.12642669677734375, 3.438298702239990234, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+552, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 849.859619140625, -340.94439697265625, 66.24468994140625, 0.401425719261169433, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+553, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 971.67120361328125, -442.657440185546875, 57.69507598876953125, 3.176499128341674804, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+554, 13098, 30, 2597, 2957, '0', '0', 0, 0, 1, 925.05889892578125, -331.346527099609375, 65.75640106201171875, 3.665191411972045898, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Surveyor (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+555, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 852.6319580078125, -372.415802001953125, 48.165679931640625, 3.665191411972045898, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+556, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 881.61822509765625, -419.948028564453125, 53.64105987548828125, 0.593411922454833984, 300, 10, 0, 12197, 0, 1, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+557, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 847.1351318359375, -411.307281494140625, 50.21063995361328125, 1.570796370506286621, 300, 10, 0, 10571, 0, 1, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+558, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 900.96185302734375, -427.44000244140625, 59.0841522216796875, 1.500983119010925292, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+559, 13080, 30, 2597, 2957, '0', '0', 0, 0, 1, 907.89312744140625, -388.787445068359375, 61.79233551025390625, 5.742133140563964843, 300, 10, 0, 21492, 0, 1, NULL, NULL, NULL, NULL, 52649), -- Irondeep Guard (Area: Irondeep Mine - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+560, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 905.06689453125, -396.07366943359375, 60.2085418701171875, 5.078907966613769531, 300, 10, 0, 10571, 0, 1, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+561, 13098, 30, 2597, 2957, '0', '0', 0, 0, 1, 884.23663330078125, -407.596588134765625, 61.56597900390625, 0.820304751396179199, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Surveyor (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+562, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 890.58441162109375, -406.049468994140625, 61.19248199462890625, 5.672319889068603515, 300, 10, 0, 12197, 0, 1, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+563, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 907.208740234375, -428.266815185546875, 59.88685989379882812, 1.867502331733703613, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+564, 13080, 30, 2597, 2957, '0', '0', 0, 0, 1, 842.08026123046875, -421.775054931640625, 48.265869140625, 1.082104086875915527, 300, 10, 0, 18713, 0, 1, NULL, NULL, NULL, NULL, 52649), -- Irondeep Guard (Area: Irondeep Mine - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+565, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 913.064453125, -395.7725830078125, 60.13639068603515625, 4.415682792663574218, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+566, 13098, 30, 2597, 2957, '0', '0', 0, 0, 1, 851.47052001953125, -362.52008056640625, 47.31400299072265625, 4.066617012023925781, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Surveyor (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+567, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 859.0302734375, -367.23089599609375, 47.4655303955078125, 0.01745329238474369, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+568, 13080, 30, 2597, 2957, '0', '0', 0, 0, 1, 877.98895263671875, -418.050994873046875, 52.97534561157226562, 4.468042850494384765, 300, 10, 0, 18713, 0, 1, NULL, NULL, NULL, NULL, 52649), -- Irondeep Guard (Area: Irondeep Mine - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+569, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 847.6014404296875, -423.071502685546875, 50.0852203369140625, 4.572762489318847656, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+570, 13098, 30, 2597, 2957, '0', '0', 0, 0, 1, 898.800537109375, -437.10504150390625, 58.52662277221679687, 0.959931075572967529, 300, 10, 0, 21492, 5580, 1, NULL, NULL, NULL, NULL, 52649), -- Irondeep Surveyor (Area: Irondeep Mine - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+571, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 887.647216796875, -391.536895751953125, 61.8733978271484375, 1.378810048103332519, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+572, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 874.57708740234375, -414.785919189453125, 52.78171539306640625, 1.675516128540039062, 300, 10, 0, 10571, 0, 1, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+573, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 901.8092041015625, -457.708648681640625, 59.06573486328125, 3.525565147399902343, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+574, 13098, 30, 2597, 2957, '0', '0', 0, 0, 1, 826.401611328125, -349.453887939453125, 47.27222061157226562, 1.518436431884765625, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Surveyor (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+575, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 877.126708984375, -351.799652099609375, 66.5296173095703125, 5.742133140563964843, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+576, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 897.92901611328125, -471.74176025390625, 59.77292251586914062, 2.548180580139160156, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+577, 13098, 30, 2597, 2957, '0', '0', 0, 0, 1, 902.1949462890625, -475.891265869140625, 58.39536285400390625, 1.396263360977172851, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Surveyor (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+578, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 868.2474365234375, -343.1363525390625, 64.98935699462890625, 1.605702877044677734, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+579, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 834.35430908203125, -355.5263671875, 48.14905929565429687, 6.0737457275390625, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+580, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 909.24591064453125, -474.575531005859375, 58.29007339477539062, 0.226892799139022827, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+581, 13080, 30, 2597, 2957, '0', '0', 0, 0, 1, 909.9901123046875, -462.153533935546875, 59.16436767578125, 3.700098037719726562, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Guard (Area: Irondeep Mine - Difficulty: 0) CreateObject2
(@CGUID+583, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 776.12628173828125, -318.052093505859375, 63.1918182373046875, 2.312026500701904296, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+584, 13098, 30, 2597, 2957, '0', '0', 0, 0, 1, 825.53485107421875, -322.37298583984375, 63.93574905395507812, 4.764749050140380859, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Surveyor (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+585, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 823.2218017578125, -334.283111572265625, 65.63056182861328125, 4.886921882629394531, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+586, 13080, 30, 2597, 2957, '0', '0', 0, 0, 1, 897.4644775390625, -338.757965087890625, 68.171539306640625, 2.94960641860961914, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Guard (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+587, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 801.4046630859375, -328.054595947265625, 53.01951980590820312, 4.310963153839111328, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+588, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 931.14581298828125, -359.6656494140625, 66.02935791015625, 3.96189737319946289, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+589, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 833.701904296875, -327.505523681640625, 65.0438690185546875, 0.331612557172775268, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+590, 13080, 30, 2597, 2957, '0', '0', 0, 0, 1, 936.69183349609375, -356.78033447265625, 65.98349761962890625, 2.757620096206665039, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Guard (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+591, 13098, 30, 2597, 2957, '0', '0', 0, 0, 1, 778.392578125, -320.66314697265625, 63.18989181518554687, 2.30383467674255371, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Surveyor (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+592, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 831.7110595703125, -346.784576416015625, 47.29748916625976562, 0.226892799139022827, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+593, 13098, 30, 2597, 2957, '0', '0', 0, 0, 1, 808.95343017578125, -325.96435546875, 52.50748443603515625, 3.019419670104980468, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Surveyor (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+594, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 958.6923828125, -333.476837158203125, 63.22761154174804687, 5.777040004730224609, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+595, 13080, 30, 2597, 2957, '0', '0', 0, 0, 1, 950.07696533203125, -326.6719970703125, 61.65517807006835937, 5.480333805084228515, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Guard (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+597, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 775.058837890625, -317.0279541015625, 63.19129562377929687, 0.003052708460018038, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+598, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 805.39947509765625, -320.145843505859375, 52.85462188720703125, 0.296705961227416992, 300, 10, 0, 10571, 0, 1, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+599, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 893.37603759765625, -343.1708984375, 68.14989471435546875, 5.358160972595214843, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+601, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 774.67913818359375, -316.2918701171875, 63.172210693359375, 5.598447322845458984, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+602, 13080, 30, 2597, 2957, '0', '0', 0, 0, 1, 777.1015625, -319.115997314453125, 63.19189453125, 2.356397151947021484, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Guard (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+603, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 888.208251953125, -332.564453125, 68.14801025390625, 1.93731546401977539, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+604, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 921.9716796875, -358.596954345703125, 66.4312591552734375, 2.932153224945068359, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+605, 13098, 30, 2597, 2957, '0', '0', 0, 0, 1, 876.046630859375, -341.85699462890625, 65.8742828369140625, 4.450589656829833984, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Surveyor (Area: Irondeep Mine - Difficulty: 0) CreateObject1
(@CGUID+606, 13396, 30, 2597, 2957, '0', '0', 0, 0, 1, 957.11297607421875, -325.919921875, 61.75893783569335937, 1.134464025497436523, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649); -- Irondeep Miner (Area: Irondeep Mine - Difficulty: 0) CreateObject1

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+583, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Irondeep Miner
(@CGUID+597, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Irondeep Miner
(@CGUID+601, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Irondeep Miner

DELETE FROM `creature_template_addon` WHERE `entry` IN (13078 /*13078 (Umi Thorson)*/, 13080 /*13080 (Irondeep Guard)*/, 13098 /*13098 (Irondeep Surveyor)*/, 13396 /*13396 (Irondeep Miner)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(13078, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 13078 (Umi Thorson)
(13080, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 13080 (Irondeep Guard)
(13098, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 13098 (Irondeep Surveyor)
(13396, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, ''); -- 13396 (Irondeep Miner)

-- Irondeep Mine - Troggs
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+607, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 805.39947509765625, -320.145843505859375, 52.85462188720703125, 0.296705961227416992, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+608, 11602, 30, 2597, 0, '0', '0', 0, 0, 1, 808.95343017578125, -325.96435546875, 52.50748443603515625, 3.019419670104980468, 300, 0, 0, 23391, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Skullthumper (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+609, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 801.4046630859375, -328.054595947265625, 53.01951980590820312, 4.310963153839111328, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+610, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 834.35430908203125, -355.5263671875, 48.14905929565429687, 6.0737457275390625, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+611, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 821.00555419921875, -387.634979248046875, 49.07283401489257812, 3.159045934677124023, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+612, 11600, 30, 2597, 0, '0', '0', 0, 0, 1, 832.0352783203125, -389.300689697265625, 47.55669021606445312, 2.111848354339599609, 300, 0, 0, 20328, 3930, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Shaman (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+613, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 833.1505126953125, -374.2275390625, 63.09382247924804687, 3.665191411972045898, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+614, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 835.077392578125, -379.41796875, 48.275482177734375, 5.934119224548339843, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+615, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 823.2218017578125, -334.283111572265625, 65.63056182861328125, 4.886921882629394531, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+616, 11600, 30, 2597, 0, '0', '0', 0, 0, 1, 825.53485107421875, -322.37298583984375, 63.93574905395507812, 4.764749050140380859, 300, 0, 0, 23391, 4058, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Shaman (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+617, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 834.6343994140625, -365.981170654296875, 62.88013458251953125, 1.326450228691101074, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+618, 11600, 30, 2597, 0, '0', '0', 0, 0, 1, 826.401611328125, -349.453887939453125, 47.27222061157226562, 1.518436431884765625, 300, 0, 0, 20328, 3930, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Shaman (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+619, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 833.701904296875, -327.505523681640625, 65.0438690185546875, 0.331612557172775268, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+620, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 831.7110595703125, -346.784576416015625, 47.29748916625976562, 0.226892799139022827, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+621, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 847.1351318359375, -411.307281494140625, 50.21063995361328125, 1.570796370506286621, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+622, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 849.859619140625, -340.94439697265625, 66.24468994140625, 0.401425719261169433, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+623, 11600, 30, 2597, 0, '0', '0', 0, 0, 1, 846.93927001953125, -347.27886962890625, 66.287628173828125, 0.942477762699127197, 300, 0, 0, 20328, 3930, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Shaman (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+624, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 817.26007080078125, -447.431854248046875, 49.43082427978515625, 2.181661605834960937, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+625, 11600, 30, 2597, 0, '0', '0', 0, 0, 1, 851.47052001953125, -362.52008056640625, 47.31400299072265625, 4.066617012023925781, 300, 0, 0, 20328, 3930, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Shaman (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+626, 11602, 30, 2597, 0, '0', '0', 0, 0, 1, 827.01202392578125, -457.3974609375, 48.93306350708007812, 2.356194496154785156, 300, 0, 0, 26865, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Skullthumper (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+627, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 859.0302734375, -367.23089599609375, 47.4655303955078125, 0.01745329238474369, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+628, 11600, 30, 2597, 0, '0', '0', 0, 0, 1, 838.35797119140625, -371.2119140625, 63.3298797607421875, 4.049163818359375, 300, 0, 0, 23391, 4058, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Shaman (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+629, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 821.891845703125, -464.72308349609375, 48.94509506225585937, 4.660028934478759765, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+630, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 834.87042236328125, -453.304046630859375, 47.9074554443359375, 0.226892799139022827, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+631, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 847.6014404296875, -423.071502685546875, 50.0852203369140625, 4.572762489318847656, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+632, 11600, 30, 2597, 0, '0', '0', 0, 0, 1, 817.82977294921875, -455.71484375, 48.420745849609375, 0.92502450942993164, 300, 0, 0, 23391, 4058, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Shaman (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+633, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 857.51251220703125, -351.817047119140625, 65.186737060546875, 4.398229598999023437, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+634, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 852.6319580078125, -372.415802001953125, 48.165679931640625, 3.665191411972045898, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+635, 11602, 30, 2597, 0, '0', '0', 0, 0, 1, 856.89837646484375, -395.542999267578125, 61.26129913330078125, 5.746065139770507812, 300, 0, 0, 26865, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Skullthumper (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+636, 11600, 30, 2597, 0, '0', '0', 0, 0, 1, 842.08026123046875, -421.775054931640625, 48.265869140625, 1.082104086875915527, 300, 0, 0, 23391, 4058, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Shaman (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+637, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 868.2474365234375, -343.1363525390625, 64.98935699462890625, 1.605702877044677734, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+638, 11602, 30, 2597, 0, '0', '0', 0, 0, 1, 858.59344482421875, -439.614166259765625, 50.2183990478515625, 0.872664630413055419, 300, 0, 0, 26865, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Skullthumper (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+639, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 877.126708984375, -351.799652099609375, 66.5296173095703125, 5.742133140563964843, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+640, 11600, 30, 2597, 0, '0', '0', 0, 0, 1, 868.127197265625, -392.113739013671875, 61.49259567260742187, 4.085883140563964843, 300, 0, 0, 23391, 4058, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Shaman (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+641, 11602, 30, 2597, 0, '0', '0', 0, 0, 1, 876.046630859375, -341.85699462890625, 65.8742828369140625, 4.450589656829833984, 300, 0, 0, 23391, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Skullthumper (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+642, 11602, 30, 2597, 0, '0', '0', 0, 0, 1, 871.0357666015625, -404.119354248046875, 62.13052749633789062, 3.295674324035644531, 300, 0, 0, 26865, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Skullthumper (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+643, 11657, 30, 2597, 0, '0', '0', 0, 0, 1, 863.14794921875, -441.290985107421875, 50.57578277587890625, 4.161839008331298828, 10, 0, 0, 83980, 5982, 0, NULL, NULL, NULL, NULL, 52649), -- Morloch (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+644, 11602, 30, 2597, 0, '0', '0', 0, 0, 1, 897.4644775390625, -338.757965087890625, 68.171539306640625, 2.94960641860961914, 300, 0, 0, 26865, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Skullthumper (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+645, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 893.37603759765625, -343.1708984375, 68.14989471435546875, 5.358160972595214843, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+646, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 887.647216796875, -391.536895751953125, 61.8733978271484375, 1.378810048103332519, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+647, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 874.57708740234375, -414.785919189453125, 52.78171539306640625, 1.675516128540039062, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+648, 11600, 30, 2597, 0, '0', '0', 0, 0, 1, 877.98895263671875, -418.050994873046875, 52.97534561157226562, 4.468042850494384765, 300, 0, 0, 20328, 3930, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Shaman (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+649, 11602, 30, 2597, 0, '0', '0', 0, 0, 1, 884.23663330078125, -407.596588134765625, 61.56597900390625, 0.820304751396179199, 300, 0, 0, 26865, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Skullthumper (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+650, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 881.61822509765625, -419.948028564453125, 53.64105987548828125, 0.593411922454833984, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+651, 11602, 30, 2597, 0, '0', '0', 0, 0, 1, 868.1824951171875, -444.3154296875, 51.541534423828125, 1.640609502792358398, 300, 0, 0, 23391, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Skullthumper (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+652, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 888.208251953125, -332.564453125, 68.14801025390625, 1.93731546401977539, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+653, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 890.58441162109375, -406.049468994140625, 61.19248199462890625, 5.672319889068603515, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+654, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 905.06689453125, -396.07366943359375, 60.2085418701171875, 5.078907966613769531, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+655, 11602, 30, 2597, 0, '0', '0', 0, 0, 1, 907.89312744140625, -388.787445068359375, 61.79233551025390625, 5.742133140563964843, 300, 0, 0, 26865, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Skullthumper (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+656, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 900.96185302734375, -427.44000244140625, 59.0841522216796875, 1.500983119010925292, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+657, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 914.56768798828125, -326.2099609375, 66.1732635498046875, 2.251474618911743164, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+658, 11600, 30, 2597, 0, '0', '0', 0, 0, 1, 925.05889892578125, -331.346527099609375, 65.75640106201171875, 3.665191411972045898, 300, 0, 0, 20328, 3930, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Shaman (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+659, 11602, 30, 2597, 0, '0', '0', 0, 0, 1, 898.800537109375, -437.10504150390625, 58.52662277221679687, 0.959931075572967529, 300, 0, 0, 23391, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Skullthumper (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+660, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 907.208740234375, -428.266815185546875, 59.88685989379882812, 1.867502331733703613, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+661, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 921.44921875, -341.98089599609375, 67.12642669677734375, 3.438298702239990234, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+662, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 921.9716796875, -358.596954345703125, 66.4312591552734375, 2.932153224945068359, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+663, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 913.064453125, -395.7725830078125, 60.13639068603515625, 4.415682792663574218, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+664, 10987, 30, 2597, 3303, '0', '0', 0, 0, 1, 926.84893798828125, -379.073577880859375, 63.52860260009765625, 2.094395160675048828, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+665, 10987, 30, 2597, 3303, '0', '0', 0, 0, 1, 931.14581298828125, -359.6656494140625, 66.02935791015625, 3.96189737319946289, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+666, 11602, 30, 2597, 3303, '0', '0', 0, 0, 1, 936.69183349609375, -356.78033447265625, 65.98349761962890625, 2.757620096206665039, 300, 0, 0, 23391, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Skullthumper (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+667, 11602, 30, 2597, 3303, '0', '0', 0, 0, 1, 937.3780517578125, -377.81585693359375, 65.39192962646484375, 3.560471534729003906, 300, 0, 0, 26865, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Skullthumper (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+668, 10987, 30, 2597, 3303, '0', '0', 0, 0, 1, 934.726806640625, -385.802093505859375, 63.03435516357421875, 3.752457857131958007, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+669, 10987, 30, 2597, 3303, '0', '0', 0, 0, 1, 929.7022705078125, -412.4005126953125, 56.95518112182617187, 5.899212837219238281, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+670, 10987, 30, 2597, 3303, '0', '0', 0, 0, 1, 931.75067138671875, -403.4580078125, 59.67373275756835937, 5.637413501739501953, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1
(@CGUID+671, 10987, 30, 2597, 3303, '0', '0', 0, 0, 1, 901.8092041015625, -457.708648681640625, 59.06573486328125, 3.525565147399902343, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+672, 11602, 30, 2597, 3303, '0', '0', 0, 0, 1, 950.07696533203125, -326.6719970703125, 61.65517807006835937, 5.480333805084228515, 300, 0, 0, 26865, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Skullthumper (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+673, 11600, 30, 2597, 3303, '0', '0', 0, 0, 1, 926.4747314453125, -419.344635009765625, 56.18328094482421875, 2.094395160675048828, 300, 0, 0, 23391, 4058, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Shaman (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+674, 10987, 30, 2597, 3303, '0', '0', 0, 0, 1, 958.6923828125, -333.476837158203125, 63.22761154174804687, 5.777040004730224609, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+675, 10987, 30, 2597, 3303, '0', '0', 0, 0, 1, 957.11297607421875, -325.919921875, 61.75893783569335937, 1.134464025497436523, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+676, 10987, 30, 2597, 3303, '0', '0', 0, 0, 1, 897.92901611328125, -471.74176025390625, 59.77292251586914062, 2.548180580139160156, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+677, 11602, 30, 2597, 3303, '0', '0', 0, 0, 1, 909.9901123046875, -462.153533935546875, 59.16436767578125, 3.700098037719726562, 300, 0, 0, 23391, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Skullthumper (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+678, 11600, 30, 2597, 3303, '0', '0', 0, 0, 1, 902.1949462890625, -475.891265869140625, 58.39536285400390625, 1.396263360977172851, 300, 0, 0, 23391, 4058, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Shaman (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+679, 10987, 30, 2597, 3303, '0', '0', 0, 0, 1, 909.24591064453125, -474.575531005859375, 58.29007339477539062, 0.226892799139022827, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+680, 11602, 30, 2597, 3303, '0', '0', 0, 0, 1, 955.8116455078125, -440.3018798828125, 55.34113693237304687, 3.193952560424804687, 300, 0, 0, 26865, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Skullthumper (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+681, 10987, 30, 2597, 3303, '0', '0', 0, 0, 1, 948.25042724609375, -448.267791748046875, 56.90093612670898437, 5.602506637573242187, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+682, 11600, 30, 2597, 0, '0', '0', 0, 0, 1, 957.2930908203125, -455.038848876953125, 56.739501953125, 5.79449319839477539, 300, 0, 0, 23391, 4058, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Shaman (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+683, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 971.67120361328125, -442.657440185546875, 57.69507598876953125, 3.176499128341674804, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+684, 10987, 30, 2597, 0, '0', '0', 0, 0, 1, 969.97918701171875, -457.14788818359375, 58.11191177368164062, 4.520402908325195312, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+685, 11600, 30, 2597, 2597, '0', '0', 0, 0, 1, 786.79449462890625, -326.2647705078125, 63.40489578247070312, 5.603741168975830078, 300, 0, 0, 23391, 4058, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Shaman (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+686, 11602, 30, 2597, 2597, '0', '0', 0, 0, 1, 788.27081298828125, -327.43719482421875, 63.36409759521484375, 5.604738712310791015, 300, 0, 0, 26865, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Skullthumper (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+688, 10987, 30, 2597, 2597, '0', '0', 0, 0, 1, 789.8597412109375, -328.70220947265625, 63.23497772216796875, 5.606299877166748046, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+690, 10987, 30, 2597, 2597, '0', '0', 0, 0, 1, 791.4014892578125, -329.929718017578125, 63.04186630249023437, 5.608000755310058593, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Irondeep Trogg (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+692, 10987, 30, 2597, 2597, '0', '0', 0, 0, 1, 793.05322265625, -331.2530517578125, 63.08449554443359375, 5.612669944763183593, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52649); -- Irondeep Trogg (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+688, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Irondeep Trogg
(@CGUID+690, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Irondeep Trogg
(@CGUID+692, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Irondeep Trogg

DELETE FROM `creature_template_addon` WHERE `entry` IN (10987 /*10987 (Irondeep Trogg)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(10987, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, ''); -- 10987 (Irondeep Trogg)

-- Coldtooth mine - Horde
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+693, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -929.9473876953125, -154.449493408203125, 61.50844955444335937, 1.675516128540039062, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+694, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -903.783203125, -64.8839492797851562, 74.05413055419921875, 6.038839340209960937, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+695, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -899.4893798828125, -61.7252082824707031, 73.249755859375, 5.096361160278320312, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+696, 13089, 30, 2597, 2963, '0', '0', 0, 0, 1, -897.61724853515625, -52.0457344055175781, 71.9503173828125, 4.363323211669921875, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Guard (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+697, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -943.67803955078125, -110.986167907714843, 80.25574493408203125, 0.959931075572967529, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+698, 13089, 30, 2597, 2963, '0', '0', 0, 0, 1, -857.27239990234375, -141.141708374023437, 61.73563385009765625, 4.171336650848388671, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Guard (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+699, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -888.320556640625, -159.830886840820312, 62.5302734375, 1.2042771577835083, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+700, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -865.30517578125, -152.301712036132812, 63.50444793701171875, 4.86946868896484375, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+701, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -883.26812744140625, -159.738006591796875, 63.53113937377929687, 5.201081275939941406, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+702, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -857.29205322265625, -152.276809692382812, 63.26395034790039062, 4.188790321350097656, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+703, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -888.2503662109375, -148.467941284179687, 61.8873291015625, 1.65806281566619873, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+704, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -897.86383056640625, -84.4347915649414062, 74.08304595947265625, 3.001966238021850585, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+705, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -942.9931640625, -56.9881172180175781, 79.98038482666015625, 5.654866695404052734, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+706, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -915.8621826171875, -151.740127563476562, 76.9426727294921875, 0.942477762699127197, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+707, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -874.90087890625, -36.6579322814941406, 69.42462158203125, 2.007128715515136718, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+708, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -913.6953125, -146.783035278320312, 77.02935791015625, 1.867502331733703613, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+709, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -904.022705078125, -90.4557876586914062, 75.37059783935546875, 3.40339207649230957, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+710, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -945.50347900390625, -65.0653762817382812, 79.87158966064453125, 5.026548385620117187, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+711, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -905.45452880859375, -84.5179061889648437, 75.364166259765625, 3.298672199249267578, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+712, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -907.57232666015625, -148.936904907226562, 76.68979644775390625, 4.764749050140380859, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+713, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -866.353515625, -40.2454986572265625, 70.84197235107421875, 0.069813169538974761, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+714, 13089, 30, 2597, 2963, '0', '0', 0, 0, 1, -874.36053466796875, -42.47509765625, 69.43161773681640625, 0.78539818525314331, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Guard (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+715, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -958.5087890625, -173.652450561523437, 77.90131378173828125, 6.248278617858886718, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+716, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -952.47601318359375, -179.778488159179687, 78.677093505859375, 4.520402908325195312, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+717, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -950.42742919921875, -115.007377624511718, 79.7296600341796875, 3.682644605636596679, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+718, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -978.67828369140625, -37.3135871887207031, 75.83638763427734375, 2.844886541366577148, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+719, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -976.0858154296875, -44.1775169372558593, 76.0290069580078125, 1.466076612472534179, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+720, 13089, 30, 2597, 2963, '0', '0', 0, 0, 1, -951.47698974609375, -53.9646797180175781, 80.02349853515625, 5.323254108428955078, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Guard (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+721, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -971.863525390625, -87.4222564697265625, 81.4954071044921875, 5.829399585723876953, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+722, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -947.8543701171875, -170.50006103515625, 79.76178741455078125, 0.942477762699127197, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+723, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -963.95098876953125, -87.7339935302734375, 81.55553436279296875, 0.575958669185638427, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+724, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -938.1973876953125, -155.837509155273437, 61.31111526489257812, 1.65806281566619873, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+725, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -973.07586669921875, -36.5013008117675781, 77.5635528564453125, 1.082104086875915527, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+726, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -961.94110107421875, -90.7251510620117187, 81.6629180908203125, 0.820304751396179199, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+727, 13089, 30, 2597, 2963, '0', '0', 0, 0, 1, -954.62188720703125, -110.958442687988281, 80.7910614013671875, 6.248278617858886718, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Guard (Area: Coldtooth Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+728, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -934.110595703125, -159.75537109375, 60.88882064819335937, 2.565634012222290039, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+729, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -818.8287353515625, -153.004287719726562, 62.1757049560546875, 6.126105785369873046, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+730, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -821.495849609375, -143.094833374023437, 63.12924575805664062, 0.541052043437957763, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+731, 13089, 30, 2597, 2963, '0', '0', 0, 0, 1, -828.049560546875, -150.507598876953125, 62.34058761596679687, 2.146754980087280273, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Guard (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+732, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -837.02618408203125, -140.728622436523437, 62.51413345336914062, 5.515240192413330078, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+733, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -847.3914794921875, -98.0783462524414062, 68.508056640625, 3.543018341064453125, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+734, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -836.96337890625, -153.224288940429687, 63.38209915161132812, 4.468042850494384765, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+735, 13089, 30, 2597, 2963, '0', '0', 0, 0, 1, -920.8643798828125, -40.2009010314941406, 78.25604248046875, 5.16617441177368164, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Guard (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+736, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -917.64788818359375, -46.8922004699707031, 77.087158203125, 5.270894527435302734, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+737, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -876.791748046875, -128.64556884765625, 64.18595123291015625, 3.40339207649230957, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+738, 13089, 30, 2597, 2963, '0', '0', 0, 0, 1, -868.4403076171875, -121.648536682128906, 64.505645751953125, 3.333578824996948242, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Guard (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+739, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -927.41192626953125, -135.312606811523437, 61.19868087768554687, 3.298672199249267578, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+740, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -869.02325439453125, -82.2118072509765625, 69.58483123779296875, 3.228859186172485351, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+741, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -940.689453125, -140.706817626953125, 79.92253875732421875, 2.792526721954345703, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+742, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -912.68902587890625, -45.4494361877441406, 76.2277374267578125, 4.607669353485107421, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+743, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -877.76007080078125, -118.070472717285156, 65.21504974365234375, 2.94960641860961914, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+744, 13089, 30, 2597, 2963, '0', '0', 0, 0, 1, -922.53656005859375, -130.290908813476562, 61.45903778076171875, 4.956735134124755859, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Guard (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+745, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -868.32366943359375, -77.7196197509765625, 71.4768218994140625, 5.410520553588867187, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+746, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -916.75042724609375, -136.093643188476562, 62.3277435302734375, 0.069813169538974761, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+747, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -861.92645263671875, -79.0518646240234375, 71.417816162109375, 0.209439516067504882, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+748, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -892.32598876953125, -123.158363342285156, 76.031768798828125, 5.567600250244140625, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+749, 13089, 30, 2597, 2963, '0', '0', 0, 0, 1, -890.8355712890625, -113.457786560058593, 76.326019287109375, 2.30383467674255371, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Guard (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+750, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -873.13641357421875, -119.113662719726562, 64.803314208984375, 4.066617012023925781, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+751, 13089, 30, 2597, 2963, '0', '0', 0, 0, 1, -859.84600830078125, -19.6548938751220703, 70.79349517822265625, 1.972222089767456054, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Guard (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+752, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -867.500732421875, -11.8708772659301757, 70.0180206298828125, 6.143558979034423828, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+753, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -870.0303955078125, -6.2744140625, 70.4831085205078125, 2.39110112190246582, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+754, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -851.65472412109375, -88.7057266235351562, 68.6014404296875, 3.839724302291870117, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+755, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -904.331787109375, -111.508682250976562, 75.59250640869140625, 2.478367567062377929, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+756, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -853.35711669921875, -0.69618099927902221, 72.15228271484375, 0.994837641716003417, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+757, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -901.51641845703125, -116.328559875488281, 75.6875762939453125, 0.471238881349563598, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+758, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -894.7919921875, -127.140731811523437, 75.38339996337890625, 6.143558979034423828, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+759, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -850.6845703125, -14.2596025466918945, 70.31932830810546875, 0.209439516067504882, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+760, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -841.82684326171875, -147.257919311523437, 63.58951568603515625, 2.268928050994873046, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+761, 13089, 30, 2597, 2963, '0', '0', 0, 0, 1, -929.66583251953125, -201.308319091796875, 73.70318603515625, 5.026548385620117187, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Guard (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+762, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -976.10943603515625, -248.823150634765625, 65.471771240234375, 3.226116895675659179, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+763, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -956.58135986328125, -217.777374267578125, 77.006256103515625, 0.98184823989868164, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+764, 13089, 30, 2597, 2963, '0', '0', 0, 0, 1, -970.24383544921875, -205.887161254882812, 68.8988189697265625, 4.921828269958496093, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Guard (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+765, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -946.73760986328125, -139.567214965820312, 80.09039306640625, 2.39110112190246582, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+766, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -953.568115234375, -212.951828002929687, 77.00528717041015625, 4.202484607696533203, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+767, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -914.615234375, -231.291015625, 71.79819488525390625, 0.813015401363372802, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+768, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -954.46685791015625, -214.484375, 77.0807647705078125, 1.068455815315246582, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+769, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -957.62286376953125, -186.582473754882812, 66.60208892822265625, 1.954768776893615722, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+770, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -944.8369140625, -199.607528686523437, 77.07369232177734375, 4.97418832778930664, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+771, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -966.50616455078125, -209.179519653320312, 69.1329498291015625, 4.555309295654296875, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+772, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -970.2490234375, -223.733993530273437, 68.28643798828125, 5.342619895935058593, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+773, 13089, 30, 2597, 2963, '0', '0', 0, 0, 1, -951.95489501953125, -197.499725341796875, 77.2119903564453125, 5.637413501739501953, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Guard (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+774, 13089, 30, 2597, 2963, '0', '0', 0, 0, 1, -951.51055908203125, -181.241592407226562, 65.5289764404296875, 4.398229598999023437, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Guard (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+775, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -933.49444580078125, -209.062606811523437, 73.7802581787109375, 5.8817596435546875, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+776, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -950.1690673828125, -188.098907470703125, 66.618408203125, 5.550147056579589843, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+777, 13089, 30, 2597, 2963, '0', '0', 0, 0, 1, -954.33251953125, -214.170150756835937, 77.0058746337890625, 4.220669746398925781, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Guard (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+778, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -938.28302001953125, -259.269439697265625, 67.19976806640625, 2.921294927597045898, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+779, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -955.80084228515625, -216.342910766601562, 77.00656890869140625, 0.98913431167602539, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+780, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -949.943603515625, -142.977264404296875, 80.53816986083984375, 2.705260276794433593, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+781, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -824.20404052734375, -65.0529556274414062, 72.33805084228515625, 3.019419670104980468, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+782, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -839.19915771484375, -57.0558280944824218, 73.4891357421875, 1.675516128540039062, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+783, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -832.72088623046875, -67.7555313110351562, 73.037017822265625, 4.991641521453857421, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+784, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -900.79541015625, -136.095001220703125, 75.1326904296875, 5.759586334228515625, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+785, 13089, 30, 2597, 2963, '0', '0', 0, 0, 1, -951.3087158203125, -59.34375, 79.85997772216796875, 2.967059612274169921, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Guard (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+786, 13316, 30, 2597, 2963, '0', '0', 0, 0, 1, -839.987060546875, -67.7694778442382812, 72.79164886474609375, 4.939281940460205078, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Peon (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+787, 13089, 30, 2597, 2963, '0', '0', 0, 0, 1, -826.25396728515625, -58.6910820007324218, 72.00408935546875, 3.682644605636596679, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Guard (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+788, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -950.975830078125, -203.073562622070312, 77.24575042724609375, 0.48869219422340393, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+789, 13097, 30, 2597, 2963, '0', '0', 0, 0, 1, -954.318115234375, -214.292984008789062, 77.00592041015625, 4.202484607696533203, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52393), -- Coldmine Surveyor (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+790, 13088, 30, 2597, 2963, '0', '0', 0, 0, 1, -849.416259765625, -93.4278945922851562, 68.59841156005859375, 3.228859186172485351, 10, 0, 0, 83980, 0, 0, NULL, NULL, NULL, NULL, 52393); -- Masha Swiftcut (Area: Coldtooth Mine - Difficulty: 0) CreateObject2

DELETE FROM `creature_template_addon` WHERE `entry` IN (13088, 13097, 13089, 13316);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(13088, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Masha Swiftcut
(13097, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Coldmine Surveyor
(13089, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Coldmine Guard
(13316, 0, 0, 0, 0, 0, 1, 1, 233, 0, 0, 0, 0, ''); -- Coldmine Peon

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+763, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Coldmine Peon
(@CGUID+768, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Coldmine Peon
(@CGUID+779, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''); -- Coldmine Peon

-- Coldtooth Mine - Alliance
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+791, 13086, 30, 2597, 2963, '0', '0', 0, 0, 1, -849.490234375, -93.5311431884765625, 68.59334564208984375, 3.700098037719726562, 10, 0, 0, 83980, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Aggi Rumblestomp (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: 12782 - Shield Spike)
(@CGUID+792, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -857.27239990234375, -141.141708374023437, 61.73563385009765625, 4.171336650848388671, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+793, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -857.29205322265625, -152.276809692382812, 63.26395034790039062, 4.188790321350097656, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+794, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -868.32366943359375, -77.7196197509765625, 71.4768218994140625, 5.410520553588867187, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+795, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -861.92645263671875, -79.0518646240234375, 71.417816162109375, 0.209439516067504882, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+796, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -905.45452880859375, -84.5179061889648437, 75.364166259765625, 3.298672199249267578, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+797, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -929.9473876953125, -154.449493408203125, 61.50844955444335937, 1.675516128540039062, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+798, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -865.30517578125, -152.301712036132812, 63.50444793701171875, 4.86946868896484375, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+799, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -897.86383056640625, -84.4347915649414062, 74.08304595947265625, 3.001966238021850585, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+800, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -869.02325439453125, -82.2118072509765625, 69.58483123779296875, 3.228859186172485351, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+801, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -904.022705078125, -90.4557876586914062, 75.37059783935546875, 3.40339207649230957, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+802, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -913.6953125, -146.783035278320312, 77.02935791015625, 1.867502331733703613, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+803, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -874.90087890625, -36.6579322814941406, 69.42462158203125, 2.007128715515136718, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+804, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -907.57232666015625, -148.936904907226562, 76.68979644775390625, 4.764749050140380859, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+805, 13096, 30, 2597, 2963, '0', '0', 0, 0, 1, -915.8621826171875, -151.740127563476562, 76.9426727294921875, 0.942477762699127197, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Explorer (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+806, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -866.353515625, -40.2454986572265625, 70.84197235107421875, 0.069813169538974761, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+807, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -874.36053466796875, -42.47509765625, 69.43161773681640625, 0.78539818525314331, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+808, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -899.4893798828125, -61.7252082824707031, 73.249755859375, 5.096361160278320312, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+809, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -943.67803955078125, -110.986167907714843, 80.25574493408203125, 0.959931075572967529, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+810, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -883.26812744140625, -159.738006591796875, 63.53113937377929687, 5.201081275939941406, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+811, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -917.64788818359375, -46.8922004699707031, 77.087158203125, 5.270894527435302734, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+812, 13096, 30, 2597, 2963, '0', '0', 0, 0, 1, -920.8643798828125, -40.2009010314941406, 78.25604248046875, 5.16617441177368164, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Explorer (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+813, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -940.689453125, -140.706817626953125, 79.92253875732421875, 2.792526721954345703, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+814, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -903.783203125, -64.8839492797851562, 74.05413055419921875, 6.038839340209960937, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+815, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -912.68902587890625, -45.4494361877441406, 76.2277374267578125, 4.607669353485107421, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+816, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -888.2503662109375, -148.467941284179687, 61.8873291015625, 1.65806281566619873, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+817, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -950.42742919921875, -115.007377624511718, 79.7296600341796875, 3.682644605636596679, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+818, 13096, 30, 2597, 2963, '0', '0', 0, 0, 1, -888.320556640625, -159.830886840820312, 62.5302734375, 1.2042771577835083, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Explorer (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+819, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -897.61724853515625, -52.0457344055175781, 71.9503173828125, 4.363323211669921875, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+820, 13096, 30, 2597, 2963, '0', '0', 0, 0, 1, -976.0858154296875, -44.1775169372558593, 76.0290069580078125, 1.466076612472534179, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Explorer (Area: Coldtooth Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+821, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -938.1973876953125, -155.837509155273437, 61.31111526489257812, 1.65806281566619873, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+822, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -973.07586669921875, -36.5013008117675781, 77.5635528564453125, 1.082104086875915527, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+823, 13096, 30, 2597, 2963, '0', '0', 0, 0, 1, -954.62188720703125, -110.958442687988281, 80.7910614013671875, 6.248278617858886718, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Explorer (Area: Coldtooth Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+824, 13096, 30, 2597, 2963, '0', '0', 0, 0, 1, -971.863525390625, -87.4222564697265625, 81.4954071044921875, 5.829399585723876953, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Explorer (Area: Coldtooth Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+825, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -934.110595703125, -159.75537109375, 60.88882064819335937, 2.565634012222290039, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+826, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -978.67828369140625, -37.3135871887207031, 75.83638763427734375, 2.844886541366577148, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+827, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -946.73760986328125, -139.567214965820312, 80.09039306640625, 2.39110112190246582, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+828, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -958.5087890625, -173.652450561523437, 77.90131378173828125, 6.248278617858886718, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+829, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -963.95098876953125, -87.7339935302734375, 81.55553436279296875, 0.575958669185638427, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+830, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -952.47601318359375, -179.778488159179687, 78.677093505859375, 4.520402908325195312, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+831, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -947.8543701171875, -170.50006103515625, 79.76178741455078125, 0.942477762699127197, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+832, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -949.943603515625, -142.977264404296875, 80.53816986083984375, 2.705260276794433593, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+833, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -961.94110107421875, -90.7251510620117187, 81.6629180908203125, 0.820304751396179199, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+834, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -850.6845703125, -14.2596025466918945, 70.31932830810546875, 0.209439516067504882, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+835, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -894.7919921875, -127.140731811523437, 75.38339996337890625, 6.143558979034423828, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+836, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -853.35711669921875, -0.69618099927902221, 72.15228271484375, 0.994837641716003417, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+837, 13096, 30, 2597, 2963, '0', '0', 0, 0, 1, -841.82684326171875, -147.257919311523437, 63.58951568603515625, 2.268928050994873046, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Explorer (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+838, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -904.331787109375, -111.508682250976562, 75.59250640869140625, 2.478367567062377929, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+839, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -870.0303955078125, -6.2744140625, 70.4831085205078125, 2.39110112190246582, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+840, 13096, 30, 2597, 2963, '0', '0', 0, 0, 1, -867.500732421875, -11.8708772659301757, 70.0180206298828125, 6.143558979034423828, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Explorer (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+841, 13096, 30, 2597, 2963, '0', '0', 0, 0, 1, -851.7879638671875, -88.7193450927734375, 68.6057586669921875, 3.979350566864013671, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Explorer (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+842, 13096, 30, 2597, 2963, '0', '0', 0, 0, 1, -901.51641845703125, -116.328559875488281, 75.6875762939453125, 0.471238881349563598, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Explorer (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+843, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -890.8355712890625, -113.457786560058593, 76.326019287109375, 2.30383467674255371, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+844, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -859.84600830078125, -19.6548938751220703, 70.79349517822265625, 1.972222089767456054, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+845, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -892.32598876953125, -123.158363342285156, 76.031768798828125, 5.567600250244140625, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+846, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -927.41192626953125, -135.312606811523437, 61.19868087768554687, 3.298672199249267578, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+847, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -945.50347900390625, -65.0653762817382812, 79.87158966064453125, 5.026548385620117187, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+848, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -922.53656005859375, -130.290908813476562, 61.45903778076171875, 4.956735134124755859, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+849, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -876.791748046875, -128.64556884765625, 64.18595123291015625, 3.40339207649230957, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+850, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -942.9931640625, -56.9881172180175781, 79.98038482666015625, 5.654866695404052734, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+851, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -877.76007080078125, -118.070472717285156, 65.21504974365234375, 2.94960641860961914, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+852, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -868.4403076171875, -121.648536682128906, 64.505645751953125, 3.333578824996948242, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+853, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -916.75042724609375, -136.093643188476562, 62.3277435302734375, 0.069813169538974761, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+854, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -839.19915771484375, -57.0558280944824218, 73.4891357421875, 1.675516128540039062, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+855, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -832.72088623046875, -67.7555313110351562, 73.037017822265625, 4.991641521453857421, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+856, 13096, 30, 2597, 2963, '0', '0', 0, 0, 1, -824.20404052734375, -65.0529556274414062, 72.33805084228515625, 3.019419670104980468, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Explorer (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+857, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -826.25396728515625, -58.6910820007324218, 72.00408935546875, 3.682644605636596679, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+858, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -839.987060546875, -67.7694778442382812, 72.79164886474609375, 4.939281940460205078, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+859, 13096, 30, 2597, 2963, '0', '0', 0, 0, 1, -873.13641357421875, -119.113662719726562, 64.803314208984375, 4.066617012023925781, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Explorer (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+860, 13096, 30, 2597, 2963, '0', '0', 0, 0, 1, -944.8369140625, -199.607528686523437, 77.07369232177734375, 4.97418832778930664, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Explorer (Area: Coldtooth Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+861, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -975.13128662109375, -248.740997314453125, 65.61000823974609375, 2.95347905158996582, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+862, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -951.51055908203125, -181.241592407226562, 65.5289764404296875, 4.398229598999023437, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+863, 13096, 30, 2597, 2963, '0', '0', 0, 0, 1, -951.95489501953125, -197.499725341796875, 77.2119903564453125, 5.637413501739501953, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Explorer (Area: Coldtooth Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+864, 13096, 30, 2597, 2963, '0', '0', 0, 0, 1, -966.50616455078125, -209.179519653320312, 69.1329498291015625, 4.555309295654296875, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Explorer (Area: Coldtooth Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+865, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -951.47698974609375, -53.9646797180175781, 80.02349853515625, 5.323254108428955078, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+866, 13096, 30, 2597, 2963, '0', '0', 0, 0, 1, -929.66583251953125, -201.308319091796875, 73.70318603515625, 5.026548385620117187, 300, 0, 0, 21492, 5580, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Explorer (Area: Coldtooth Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+867, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -938.28302001953125, -259.269439697265625, 67.19976806640625, 5.307423114776611328, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+868, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -957.62286376953125, -186.582473754882812, 66.60208892822265625, 1.954768776893615722, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+869, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -950.1690673828125, -188.098907470703125, 66.618408203125, 5.550147056579589843, 300, 0, 0, 10571, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+870, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -951.3087158203125, -59.34375, 79.85997772216796875, 2.967059612274169921, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+871, 13096, 30, 2597, 2963, '0', '0', 0, 0, 1, -847.51934814453125, -98.0011978149414062, 68.51546478271484375, 3.682644605636596679, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Explorer (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+872, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -821.495849609375, -143.094833374023437, 63.12924575805664062, 0.541052043437957763, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+873, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -818.8287353515625, -153.004287719726562, 62.1757049560546875, 6.126105785369873046, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+874, 13096, 30, 2597, 2963, '0', '0', 0, 0, 1, -837.02618408203125, -140.728622436523437, 62.51413345336914062, 5.515240192413330078, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Explorer (Area: Coldtooth Mine - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+875, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -828.049560546875, -150.507598876953125, 62.34058761596679687, 2.146754980087280273, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+876, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -836.96337890625, -153.224288940429687, 63.38209915161132812, 4.468042850494384765, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+877, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -900.79541015625, -136.095001220703125, 75.1326904296875, 5.759586334228515625, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject2
(@CGUID+878, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -970.24383544921875, -205.887161254882812, 68.8988189697265625, 4.921828269958496093, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+879, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -953.952880859375, -213.548721313476562, 77.06523895263671875, 1.068455815315246582, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+880, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -915.577880859375, -229.522903442382812, 71.86220550537109375, 2.069364070892333984, 300, 0, 0, 18713, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+881, 13096, 30, 2597, 2963, '0', '0', 0, 0, 1, -954.340087890625, -214.332244873046875, 77.00594329833984375, 4.202484607696533203, 300, 0, 0, 18713, 5410, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Explorer (Area: Coldtooth Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+882, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -956.0045166015625, -216.913864135742187, 77.00659942626953125, 0.98184823989868164, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+883, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -933.49444580078125, -209.062606811523437, 73.7802581787109375, 5.8817596435546875, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+884, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -950.975830078125, -203.073562622070312, 77.24575042724609375, 0.48869219422340393, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+885, 13317, 30, 2597, 2963, '0', '0', 0, 0, 1, -955.16278076171875, -215.37255859375, 77.00621795654296875, 0.98913431167602539, 300, 0, 0, 12197, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Miner (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+886, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -970.36468505859375, -222.359664916992187, 68.55962371826171875, 6.126380443572998046, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52649), -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject1
(@CGUID+887, 13087, 30, 2597, 2963, '0', '0', 0, 0, 1, -954.88153076171875, -215.19512939453125, 77.0063629150390625, 4.220669746398925781, 300, 0, 0, 21492, 0, 0, NULL, NULL, NULL, NULL, 52649); -- Coldmine Invader (Area: Coldtooth Mine - Difficulty: 0) CreateObject1

DELETE FROM `creature_template_addon` WHERE `entry` IN (13087 /*13087 (Coldmine Invader)*/, 13086 /*13086 (Aggi Rumblestomp) - Shield Spike*/, 13317 /*13317 (Coldmine Miner)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(13087, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 13087 (Coldmine Invader)
(13086, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- 13086 (Aggi Rumblestomp) - Shield Spike
(13317, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, ''); -- 13317 (Coldmine Miner)

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+879, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''),
(@CGUID+882, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''),
(@CGUID+885, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

-- Coldtooth Mine - Kobolds
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+888, 10982, 30, 2597, 2597, '0', '0', 0, 0, 1, -971.46533203125, -249.305282592773437, 65.879119873046875, 6.130239009857177734, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Vermin (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+889, 10982, 30, 2597, 2597, '0', '0', 0, 0, 1, -973.1849365234375, -224.566574096679687, 69.19348907470703125, 4.057169914245605468, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Vermin (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+890, 10982, 30, 2597, 2597, '0', '0', 0, 0, 1, -940.73870849609375, -257.572265625, 66.765655517578125, 2.536789417266845703, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Vermin (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+891, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -950.1690673828125, -188.098907470703125, 66.618408203125, 5.550147056579589843, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+892, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -957.62286376953125, -186.582473754882812, 66.60208892822265625, 1.954768776893615722, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+893, 10982, 30, 2597, 2597, '0', '0', 0, 0, 1, -913.21856689453125, -230.526153564453125, 72.1684417724609375, 1.398247361183166503, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Vermin (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+894, 11605, 30, 2597, 2597, '0', '0', 0, 0, 1, -951.51055908203125, -181.241592407226562, 65.5289764404296875, 4.398229598999023437, 300, 0, 0, 28069, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Overseer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 13589 - Haste Aura)
(@CGUID+895, 11605, 30, 2597, 2597, '0', '0', 0, 0, 1, -958.5087890625, -173.652450561523437, 77.90131378173828125, 6.248278617858886718, 300, 0, 0, 32237, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Overseer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 13589 - Haste Aura)
(@CGUID+896, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -952.47601318359375, -179.778488159179687, 78.677093505859375, 4.520402908325195312, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+897, 11605, 30, 2597, 2597, '0', '0', 0, 0, 1, -953.9886474609375, -171.01080322265625, 78.0509490966796875, 5.366755962371826171, 300, 0, 0, 32237, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Overseer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 13589 - Haste Aura) 0x20428003C00B5540000B870001F6144D
(@CGUID+898, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -947.8543701171875, -170.50006103515625, 79.76178741455078125, 0.942477762699127197, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+899, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -949.943603515625, -142.977264404296875, 80.53816986083984375, 2.705260276794433593, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+900, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -938.1973876953125, -155.837509155273437, 61.31111526489257812, 1.65806281566619873, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+901, 11604, 30, 2597, 2597, '0', '0', 0, 0, 1, -934.110595703125, -159.75537109375, 60.88882064819335937, 2.565634012222290039, 300, 0, 0, 20328, 1310, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Geomancer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+902, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -946.73760986328125, -139.567214965820312, 80.09039306640625, 2.39110112190246582, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+903, 11605, 30, 2597, 2597, '0', '0', 0, 0, 1, -940.689453125, -140.706817626953125, 79.92253875732421875, 2.792526721954345703, 300, 0, 0, 28069, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Overseer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 13589 - Haste Aura)
(@CGUID+904, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -929.9473876953125, -154.449493408203125, 61.50844955444335937, 1.675516128540039062, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+905, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -907.57232666015625, -148.936904907226562, 76.68979644775390625, 4.764749050140380859, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+906, 11605, 30, 2597, 2597, '0', '0', 0, 0, 1, -888.320556640625, -159.830886840820312, 62.5302734375, 1.2042771577835083, 300, 0, 0, 28069, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Overseer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 13589 - Haste Aura)
(@CGUID+907, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -913.6953125, -146.783035278320312, 77.02935791015625, 1.867502331733703613, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+908, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -927.41192626953125, -135.312606811523437, 61.19868087768554687, 3.298672199249267578, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+909, 11605, 30, 2597, 2597, '0', '0', 0, 0, 1, -915.8621826171875, -151.740127563476562, 76.9426727294921875, 0.942477762699127197, 300, 0, 0, 32237, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Overseer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 13589 - Haste Aura)
(@CGUID+910, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -943.67803955078125, -110.986167907714843, 80.25574493408203125, 0.959931075572967529, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+911, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -916.75042724609375, -136.093643188476562, 62.3277435302734375, 0.069813169538974761, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+912, 11604, 30, 2597, 2597, '0', '0', 0, 0, 1, -922.53656005859375, -130.290908813476562, 61.45903778076171875, 4.956735134124755859, 300, 0, 0, 23391, 1352, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Geomancer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+913, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -950.42742919921875, -115.007377624511718, 79.7296600341796875, 3.682644605636596679, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+914, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -888.2503662109375, -148.467941284179687, 61.8873291015625, 1.65806281566619873, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+915, 11604, 30, 2597, 2597, '0', '0', 0, 0, 1, -954.62188720703125, -110.958442687988281, 80.7910614013671875, 6.248278617858886718, 300, 0, 0, 23391, 1352, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Geomancer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+916, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -883.26812744140625, -159.738006591796875, 63.53113937377929687, 5.201081275939941406, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+917, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -904.331787109375, -111.508682250976562, 75.59250640869140625, 2.478367567062377929, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+918, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -857.29205322265625, -152.276809692382812, 63.26395034790039062, 4.188790321350097656, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+919, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -876.791748046875, -128.64556884765625, 64.18595123291015625, 3.40339207649230957, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+920, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -963.95098876953125, -87.7339935302734375, 81.55553436279296875, 0.575958669185638427, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+921, 11605, 30, 2597, 2597, '0', '0', 0, 0, 1, -851.1990966796875, -146.756820678710937, 62.44575881958007812, 6.24749612808227539, 300, 0, 0, 28069, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Overseer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 13589 - Haste Aura)
(@CGUID+922, 11604, 30, 2597, 2597, '0', '0', 0, 0, 1, -971.863525390625, -87.4222564697265625, 81.4954071044921875, 5.829399585723876953, 300, 0, 0, 20328, 1310, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Geomancer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+923, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -894.7919921875, -127.140731811523437, 75.38339996337890625, 6.143558979034423828, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+924, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -961.94110107421875, -90.7251510620117187, 81.6629180908203125, 0.820304751396179199, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+925, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -892.32598876953125, -123.158363342285156, 76.031768798828125, 5.567600250244140625, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+926, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -865.30517578125, -152.301712036132812, 63.50444793701171875, 4.86946868896484375, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+927, 11605, 30, 2597, 2597, '0', '0', 0, 0, 1, -901.51641845703125, -116.328559875488281, 75.6875762939453125, 0.471238881349563598, 300, 0, 0, 32237, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Overseer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 13589 - Haste Aura)
(@CGUID+928, 11604, 30, 2597, 2597, '0', '0', 0, 0, 1, -857.27239990234375, -141.141708374023437, 61.73563385009765625, 4.171336650848388671, 300, 0, 0, 23391, 1352, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Geomancer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+929, 11605, 30, 2597, 2597, '0', '0', 0, 0, 1, -893.33050537109375, -110.487068176269531, 75.6680755615234375, 1.083758354187011718, 300, 0, 0, 28069, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Overseer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 13589 - Haste Aura)
(@CGUID+930, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -899.947265625, -107.935623168945312, 75.2123260498046875, 4.458644866943359375, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+931, 11605, 30, 2597, 2597, '0', '0', 0, 0, 1, -898.3148193359375, -97.6999740600585937, 74.74172210693359375, 4.330164909362792968, 300, 0, 0, 32237, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Overseer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 13589 - Haste Aura)
(@CGUID+932, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -905.45452880859375, -84.5179061889648437, 75.364166259765625, 3.298672199249267578, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+933, 11604, 30, 2597, 2597, '0', '0', 0, 0, 1, -898.26483154296875, -99.5624847412109375, 74.9485015869140625, 4.395177841186523437, 300, 0, 0, 20328, 1310, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Geomancer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+934, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -818.8287353515625, -153.004287719726562, 62.1757049560546875, 6.126105785369873046, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+935, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -898.2406005859375, -101.4903564453125, 75.05294036865234375, 4.463289260864257812, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+936, 11604, 30, 2597, 2597, '0', '0', 0, 0, 1, -890.8355712890625, -113.457786560058593, 76.326019287109375, 2.30383467674255371, 300, 0, 0, 20328, 1310, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Geomancer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+937, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -877.76007080078125, -118.070472717285156, 65.21504974365234375, 2.94960641860961914, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+938, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -945.50347900390625, -65.0653762817382812, 79.87158966064453125, 5.026548385620117187, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+939, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -821.495849609375, -143.094833374023437, 63.12924575805664062, 0.541052043437957763, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+940, 11604, 30, 2597, 2597, '0', '0', 0, 0, 1, -897.86383056640625, -84.4347915649414062, 74.08304595947265625, 3.001966238021850585, 300, 0, 0, 23391, 1352, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Geomancer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+941, 11605, 30, 2597, 2597, '0', '0', 0, 0, 1, -928.5977783203125, -65.0078811645507812, 78.80986785888671875, 0.058167718350887298, 300, 0, 0, 28069, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Overseer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 13589 - Haste Aura)
(@CGUID+942, 11604, 30, 2597, 2597, '0', '0', 0, 0, 1, -868.4403076171875, -121.648536682128906, 64.505645751953125, 3.333578824996948242, 300, 0, 0, 20328, 1310, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Geomancer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+943, 11605, 30, 2597, 2597, '0', '0', 0, 0, 1, -837.02618408203125, -140.728622436523437, 62.51413345336914062, 5.515240192413330078, 300, 0, 0, 32237, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Overseer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 13589 - Haste Aura)
(@CGUID+944, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -904.022705078125, -90.4557876586914062, 75.37059783935546875, 3.40339207649230957, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+945, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -836.96337890625, -153.224288940429687, 63.38209915161132812, 4.468042850494384765, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+946, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -897.47674560546875, -99.3101043701171875, 74.982879638671875, 4.533690929412841796, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+947, 11604, 30, 2597, 2597, '0', '0', 0, 0, 1, -828.049560546875, -150.507598876953125, 62.34058761596679687, 2.146754980087280273, 300, 0, 0, 23391, 1352, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Geomancer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+948, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -973.07586669921875, -36.5013008117675781, 77.5635528564453125, 1.082104086875915527, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+949, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -861.92645263671875, -79.0518646240234375, 71.417816162109375, 0.209439516067504882, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+950, 11605, 30, 2597, 2597, '0', '0', 0, 0, 1, -976.0858154296875, -44.1775169372558593, 76.0290069580078125, 1.466076612472534179, 300, 0, 0, 28069, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Overseer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 13589 - Haste Aura)
(@CGUID+951, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -903.783203125, -64.8839492797851562, 74.05413055419921875, 6.038839340209960937, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+952, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -917.64788818359375, -46.8922004699707031, 77.087158203125, 5.270894527435302734, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+953, 11605, 30, 2597, 2597, '0', '0', 0, 0, 1, -867.38262939453125, -95.5621414184570312, 66.61998748779296875, 4.507518768310546875, 300, 0, 0, 28069, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Overseer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 13589 - Haste Aura)
(@CGUID+954, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -899.4893798828125, -61.7252082824707031, 73.249755859375, 5.096361160278320312, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+955, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -942.9931640625, -56.9881172180175781, 79.98038482666015625, 5.654866695404052734, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+956, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -978.67828369140625, -37.3135871887207031, 75.83638763427734375, 2.844886541366577148, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+957, 11605, 30, 2597, 2597, '0', '0', 0, 0, 1, -868.32366943359375, -77.7196197509765625, 71.4768218994140625, 5.410520553588867187, 300, 0, 0, 32237, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Overseer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 13589 - Haste Aura)
(@CGUID+958, 10982, 30, 2597, 2597, '0', '0', 0, 0, 1, -851.562744140625, -88.6526718139648437, 68.5982666015625, 3.612831592559814453, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Vermin (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@CGUID+959, 11605, 30, 2597, 2597, '0', '0', 0, 0, 1, -847.4464111328125, -98.006134033203125, 68.5131072998046875, 3.246312379837036132, 300, 0, 0, 32237, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Overseer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 13589 - Haste Aura)
(@CGUID+960, 11677, 30, 2597, 2597, '0', '0', 0, 0, 1, -851.5711669921875, -92.5869293212890625, 68.5247650146484375, 0.034422963857650756, 300, 0, 0, 83980, 2991, 0, NULL, NULL, NULL, NULL, 52393), -- Taskmaster Snivvle (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+961, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -869.02325439453125, -82.2118072509765625, 69.58483123779296875, 3.228859186172485351, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+962, 11605, 30, 2597, 2597, '0', '0', 0, 0, 1, -951.47698974609375, -53.9646797180175781, 80.02349853515625, 5.323254108428955078, 300, 0, 0, 32237, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Overseer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 13589 - Haste Aura)
(@CGUID+963, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -912.68902587890625, -45.4494361877441406, 76.2277374267578125, 4.607669353485107421, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+964, 11605, 30, 2597, 2597, '0', '0', 0, 0, 1, -897.61724853515625, -52.0457344055175781, 71.9503173828125, 4.363323211669921875, 300, 0, 0, 28069, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Overseer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 13589 - Haste Aura)
(@CGUID+965, 11604, 30, 2597, 2597, '0', '0', 0, 0, 1, -920.8643798828125, -40.2009010314941406, 78.25604248046875, 5.16617441177368164, 300, 0, 0, 23391, 1352, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Geomancer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+966, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -866.353515625, -40.2454986572265625, 70.84197235107421875, 0.069813169538974761, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+967, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -839.987060546875, -67.7694778442382812, 72.79164886474609375, 4.939281940460205078, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+968, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -874.90087890625, -36.6579322814941406, 69.42462158203125, 2.007128715515136718, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+969, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -832.72088623046875, -67.7555313110351562, 73.037017822265625, 4.991641521453857421, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+970, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -839.19915771484375, -57.0558280944824218, 73.4891357421875, 1.675516128540039062, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+971, 11605, 30, 2597, 2597, '0', '0', 0, 0, 1, -874.36053466796875, -42.47509765625, 69.43161773681640625, 0.78539818525314331, 300, 0, 0, 28069, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Overseer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 13589 - Haste Aura)
(@CGUID+972, 11604, 30, 2597, 2597, '0', '0', 0, 0, 1, -826.25396728515625, -58.6910820007324218, 72.00408935546875, 3.682644605636596679, 300, 0, 0, 20328, 1310, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Geomancer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+973, 11605, 30, 2597, 2597, '0', '0', 0, 0, 1, -824.20404052734375, -65.0529556274414062, 72.33805084228515625, 3.019419670104980468, 300, 0, 0, 32237, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Overseer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 13589 - Haste Aura)
(@CGUID+974, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -850.6845703125, -14.2596025466918945, 70.31932830810546875, 0.209439516067504882, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+975, 11604, 30, 2597, 2597, '0', '0', 0, 0, 1, -859.84600830078125, -19.6548938751220703, 70.79349517822265625, 1.972222089767456054, 300, 0, 0, 20328, 1310, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Geomancer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+976, 11605, 30, 2597, 2597, '0', '0', 0, 0, 1, -867.500732421875, -11.8708772659301757, 70.0180206298828125, 6.143558979034423828, 300, 0, 0, 32237, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Overseer (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: 13589 - Haste Aura)
(@CGUID+977, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -870.0303955078125, -6.2744140625, 70.4831085205078125, 2.39110112190246582, 300, 0, 0, 20328, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+978, 11603, 30, 2597, 2597, '0', '0', 0, 0, 1, -853.35711669921875, -0.69618099927902221, 72.15228271484375, 0.994837641716003417, 300, 0, 0, 17618, 0, 0, NULL, NULL, NULL, NULL, 52393); -- Whitewhisker Digger (Area: Alterac Valley - Difficulty: 0) CreateObject1 (Auras: )

UPDATE `creature` SET `StringId` = 'bg_av_herald_stormpike_aid_station_alliance' WHERE `guid` = @CGUID+176;
UPDATE `creature` SET `StringId` = 'bg_av_herald_stormpike_aid_station_horde' WHERE `guid` = @CGUID+177;
UPDATE `creature` SET `StringId` = 'bg_av_herald_stormpike_alliance' WHERE `guid` = @CGUID+178;
UPDATE `creature` SET `StringId` = 'bg_av_herald_stormpike_horde' WHERE `guid` = @CGUID+179;
UPDATE `creature` SET `StringId` = 'bg_av_herald_stonehearth_alliance' WHERE `guid` = @CGUID+180;
UPDATE `creature` SET `StringId` = 'bg_av_herald_stonehearth_horde' WHERE `guid` = @CGUID+182;
UPDATE `creature` SET `StringId` = 'bg_av_herald_snowfall_alliance' WHERE `guid` = @CGUID+183;
UPDATE `creature` SET `StringId` = 'bg_av_herald_snowfall_horde' WHERE `guid` = @CGUID+184;
UPDATE `creature` SET `StringId` = 'bg_av_herald_iceblood_alliance' WHERE `guid` = @CGUID+185;
UPDATE `creature` SET `StringId` = 'bg_av_herald_iceblood_horde' WHERE `guid` = @CGUID+186;
UPDATE `creature` SET `StringId` = 'bg_av_herald_frostwolf_alliance' WHERE `guid` = @CGUID+187;
UPDATE `creature` SET `StringId` = 'bg_av_herald_frostwolf_horde' WHERE `guid` = @CGUID+188;
UPDATE `creature` SET `StringId` = 'bg_av_herald_frostwolf_hut_alliance' WHERE `guid` = @CGUID+189;
UPDATE `creature` SET `StringId` = 'bg_av_herald_frostwolf_hut_horde' WHERE `guid` = @CGUID+190;
UPDATE `creature` SET `StringId` = 'bg_av_herald_mine_alliance' WHERE `guid` = @CGUID+191;
UPDATE `creature` SET `StringId` = 'bg_av_herald_mine_horde' WHERE `guid` = @CGUID+192;
UPDATE `creature` SET `StringId` = 'bg_av_herald_alliance_win' WHERE `guid` = @CGUID+193;
UPDATE `creature` SET `StringId` = 'bg_av_herald_horde_win' WHERE `guid` = @CGUID+194;
-- UPDATE `creature` SET `StringId` = '' WHERE `guid` = @CGUID+196; -- Unknown

-- Alliance pos
UPDATE `creature` SET `StringId` = 'bg_av_herald_nort_bunker_attack' WHERE `guid` = @CGUID+206;
UPDATE `creature` SET `StringId` = 'bg_av_herald_nort_bunker_defend' WHERE `guid` = @CGUID+207;
UPDATE `creature` SET `StringId` = 'bg_av_herald_south_bunker_attack' WHERE `guid` = @CGUID+208;
UPDATE `creature` SET `StringId` = 'bg_av_herald_south_bunker_defend' WHERE `guid` = @CGUID+209;
UPDATE `creature` SET `StringId` = 'bg_av_herald_icewing_bunker_attack' WHERE `guid` = @CGUID+210;
UPDATE `creature` SET `StringId` = 'bg_av_herald_icewing_bunker_defend' WHERE `guid` = @CGUID+211;
UPDATE `creature` SET `StringId` = 'bg_av_herald_stonehearth_bunker_attack' WHERE `guid` = @CGUID+212;
UPDATE `creature` SET `StringId` = 'bg_av_herald_stonehearth_bunker_defend' WHERE `guid` = @CGUID+213;
UPDATE `creature` SET `StringId` = 'bg_av_herald_iceblood_tower_attack' WHERE `guid` = @CGUID+214;
UPDATE `creature` SET `StringId` = 'bg_av_herald_iceblood_tower_defend' WHERE `guid` = @CGUID+215;
UPDATE `creature` SET `StringId` = 'bg_av_herald_tower_point_attack' WHERE `guid` = @CGUID+216;
UPDATE `creature` SET `StringId` = 'bg_av_herald_tower_point_defend' WHERE `guid` = @CGUID+217;
UPDATE `creature` SET `StringId` = 'bg_av_herald_east_tower_attack' WHERE `guid` = @CGUID+218;
UPDATE `creature` SET `StringId` = 'bg_av_herald_east_tower_defend' WHERE `guid` = @CGUID+219;
UPDATE `creature` SET `StringId` = 'bg_av_herald_west_tower_attack' WHERE `guid` = @CGUID+220;
UPDATE `creature` SET `StringId` = 'bg_av_herald_west_tower_defend' WHERE `guid` = @CGUID+221;
-- UPDATE `creature` SET `StringId` = NULL WHERE `guid` = @CGUID+222; -- Unknown

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+3, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- Frost Wolf Bloodhound - 18950 - Invisibility and Stealth Detection
(@CGUID+5, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+7, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- Frost Wolf Bloodhound - 18950 - Invisibility and Stealth Detection
(@CGUID+8, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+10, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+12, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Shaman
(@CGUID+13, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+15, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+16, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Legionnaire
(@CGUID+17, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+19, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Legionnaire
(@CGUID+22, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+28, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Stable Master
(@CGUID+29, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+30, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Legionnaire
(@CGUID+40, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+42, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+48, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+50, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- Frost Wolf Bloodhound - 18950 - Invisibility and Stealth Detection
(@CGUID+54, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Voggah Deathgrip
(@CGUID+55, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+56, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Primalist Thurloga
(@CGUID+58, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Shaman
(@CGUID+59, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Herald
(@CGUID+60, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+61, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+63, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+65, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+66, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+68, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+69, 0, 1166, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Wolf Rider Commander
(@CGUID+71, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+73, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+74, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Legionnaire
(@CGUID+75, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Primalist Thurloga
(@CGUID+76, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+85, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+86, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+91, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- Frost Wolf Bloodhound - 18950 - Invisibility and Stealth Detection
(@CGUID+97, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+99, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Frostwolf Battleguard - 12782 - Shield Spike
(@CGUID+100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 5, '177684'), -- Drek'Thar - 177684 - Unit Frame
(@CGUID+101, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 5, '177684'), -- Vanndar Stormpike - 177684 - Unit Frame
(@CGUID+102, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Shaman
(@CGUID+103, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- Frost Wolf Bloodhound - 18950 - Invisibility and Stealth Detection
(@CGUID+105, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Legionnaire
(@CGUID+106, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- Frost Wolf Bloodhound - 18950 - Invisibility and Stealth Detection
(@CGUID+108, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- Commander Mulfort - 18950 - Invisibility and Stealth Detection
(@CGUID+109, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Wing Commander Vipore
(@CGUID+110, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Bowman
(@CGUID+111, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Bowman
(@CGUID+112, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Najak Hexxen
(@CGUID+113, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Ravak Grimtotem
(@CGUID+114, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Bowman
(@CGUID+115, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Bowman
(@CGUID+116, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Jotek
(@CGUID+117, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Zora Guthrek
(@CGUID+120, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Grelkor
(@CGUID+121, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Smith Regzar
(@CGUID+122, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Rarck
(@CGUID+123, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Grunnda Wolfheart
(@CGUID+124, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Bowman
(@CGUID+126, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Bowman
(@CGUID+129, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Bowman
(@CGUID+130, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Bowman
(@CGUID+137, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Sergeant Yazra Bloodsnarl
(@CGUID+138, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Yaelika Farclaw
(@CGUID+139, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Shrye Ragefist
(@CGUID+145, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Legionnaire
(@CGUID+146, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Legionnaire
(@CGUID+151, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Legionnaire
(@CGUID+152, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Legionnaire
(@CGUID+153, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Legionnaire
(@CGUID+155, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Legionnaire
(@CGUID+156, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Legionnaire
(@CGUID+157, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Legionnaire
(@CGUID+158, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- Commander Louis Philips - 18950 - Invisibility and Stealth Detection
(@CGUID+159, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Wing Commander Slidore
(@CGUID+160, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Bowman
(@CGUID+161, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Bowman
(@CGUID+162, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Bowman
(@CGUID+163, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Bowman
(@CGUID+165, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- Frost Wolf Bloodhound - 18950 - Invisibility and Stealth Detection
(@CGUID+166, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- Frost Wolf Bloodhound - 18950 - Invisibility and Stealth Detection
(@CGUID+167, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Legionnaire
(@CGUID+168, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Herald
(@CGUID+170, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Bowman
(@CGUID+171, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Bowman
(@CGUID+172, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- Commander Dardosh - 18950 - Invisibility and Stealth Detection
(@CGUID+173, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Bowman
(@CGUID+174, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Bowman
(@CGUID+195, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Captain Galvangar
(@CGUID+198, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Bowman
(@CGUID+199, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- Commander Randolph - 18950 - Invisibility and Stealth Detection
(@CGUID+200, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Bowman
(@CGUID+201, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Bowman
(@CGUID+202, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Bowman
(@CGUID+205, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Captain Balinda Stonehearth
(@CGUID+225, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Guardsman
(@CGUID+226, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- Stormpike Owl - 18950 - Invisibility and Stealth Detection
(@CGUID+227, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- Stormpike Owl - 18950 - Invisibility and Stealth Detection
(@CGUID+229, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Bowman
(@CGUID+230, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Bowman
(@CGUID+232, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- Commander Karl Philips - 18950 - Invisibility and Stealth Detection
(@CGUID+233, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Bowman
(@CGUID+234, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Wing Commander Guse
(@CGUID+235, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Bowman
(@CGUID+241, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Wing Commander Jeztor
(@CGUID+243, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Guardsman
(@CGUID+244, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Guardsman
(@CGUID+250, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Guardsman
(@CGUID+251, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Guardsman
(@CGUID+252, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Guardsman
(@CGUID+253, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Guardsman
(@CGUID+269, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Guardsman
(@CGUID+271, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Guardsman
(@CGUID+272, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- Commander Duffy - 18950 - Invisibility and Stealth Detection
(@CGUID+273, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Guardsman
(@CGUID+274, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Guardsman
(@CGUID+275, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Mountaineer Boombellow
(@CGUID+277, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Bowman
(@CGUID+279, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Gaelden Hammersmith
(@CGUID+280, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Wing Commander Mulverick
(@CGUID+281, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Bowman
(@CGUID+282, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Bowman
(@CGUID+283, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Bowman
(@CGUID+284, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Bowman
(@CGUID+285, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '5301'), -- Corporal Noreg Stormpike - 5301 - Revenge Trigger
(@CGUID+286, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Bowman
(@CGUID+287, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Bowman
(@CGUID+288, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Bowman
(@CGUID+291, 0, 14577, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Commander Mortimer
(@CGUID+292, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Brogus Thunderbrew
(@CGUID+293, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Jonivera Farmountain
(@CGUID+294, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Athramanis
(@CGUID+295, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Dirk Swindle
(@CGUID+296, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Quartermaster
(@CGUID+299, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Murgot Deepforge
(@CGUID+300, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Lana Thunderbrew
(@CGUID+301, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Svalbrad Farmountain
(@CGUID+302, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Stormpike Battleguard - 12782 - Shield Spike
(@CGUID+303, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Stormpike Battleguard - 12782 - Shield Spike
(@CGUID+304, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Stormpike Battleguard - 12782 - Shield Spike
(@CGUID+305, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Stormpike Battleguard - 12782 - Shield Spike
(@CGUID+306, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Druid of the Grove
(@CGUID+307, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Druid of the Grove
(@CGUID+308, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Druid of the Grove
(@CGUID+309, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''); -- Archdruid Renferal

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+310, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Kurdrum Barleybeard
(@CGUID+311, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Stormpike Battleguard - 12782 - Shield Spike
(@CGUID+312, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Stormpike Battleguard - 12782 - Shield Spike
(@CGUID+313, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Stable Master
(@CGUID+323, 0, 2786, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Ram Rider Commander
(@CGUID+431, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Stormpike Battleguard - 12782 - Shield Spike
(@CGUID+432, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Stormpike Battleguard - 12782 - Shield Spike
(@CGUID+525, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 5, '9036 9617'), -- Alliance Spirit Guide - 9036 - Ghost, 9617 - Ghost Visual
(@CGUID+326, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 5, '9036 9617'), -- Alliance Spirit Guide - 9036 - Ghost, 9617 - Ghost Visual
(@CGUID+327, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 5, '9036 9617'), -- Alliance Spirit Guide - 9036 - Ghost, 9617 - Ghost Visual
(@CGUID+328, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 5, '9036 9617'), -- Horde Spirit Guide - 9036 - Ghost, 9617 - Ghost Visual
(@CGUID+329, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 5, '9036 9617'), -- Horde Spirit Guide - 9036 - Ghost, 9617 - Ghost Visual
(@CGUID+335, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Drakan
(@CGUID+336, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Duros
(@CGUID+337, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Frostwolf Quartermaster
(@CGUID+616, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 5, '9036'), -- Horde Spirit Guide - 9036 - Ghost
(@CGUID+415, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- Stormpike Owl - 18950 - Invisibility and Stealth Detection
(@CGUID+416, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Stormpike Battleguard - 12782 - Shield Spike
(@CGUID+417, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- Stormpike Owl - 18950 - Invisibility and Stealth Detection
(@CGUID+418, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- Stormpike Owl - 18950 - Invisibility and Stealth Detection
(@CGUID+419, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Stormpike Battleguard - 12782 - Shield Spike
(@CGUID+420, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- Stormpike Owl - 18950 - Invisibility and Stealth Detection
(@CGUID+421, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Stormpike Battleguard - 12782 - Shield Spike
(@CGUID+422, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Stormpike Battleguard - 12782 - Shield Spike
(@CGUID+423, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Stormpike Battleguard - 12782 - Shield Spike
(@CGUID+424, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Stormpike Battleguard - 12782 - Shield Spike
(@CGUID+425, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Stormpike Battleguard - 12782 - Shield Spike
(@CGUID+426, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Stormpike Battleguard - 12782 - Shield Spike
(@CGUID+427, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormpike Herald
(@CGUID+428, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '12782'), -- Stormpike Battleguard - 12782 - Shield Spike
(@CGUID+429, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Archdruid Renferal
(@CGUID+430, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''); -- Prospector Stonehewer

UPDATE `gameobject_template` SET `ScriptName` = 'go_av_capturable_object' WHERE `entry` IN (179465, 179467, 178389, 178388, 179285, 179284, 180418, 178364, 178365, 179483, 179481, 178393, 178394, 179472, 179470, 178925, 178929, 178944, 178943, 178945, 178946, 178936, 178935);
UPDATE `gameobject_template` SET `ScriptName` = 'go_av_contested_object' WHERE `entry` IN (179468, 179466, 179287, 179286, 179310, 179308, 180420, 180419, 179482, 179484, 179304, 179305, 179471, 179473, 179435, 179439, 179449, 179445, 179453, 178940, 179443, 179441);

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+264;
-- Graveyards
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Aid Station
(@OGUID+108, 179465, 30, 2597, 0, '0', '0', 0, 638.59210205078125, -32.4220390319824218, 46.06084442138671875, 4.660029888153076171, 0, 0, -0.72537422180175781, 0.688354730606079101, 7200, 255, 1, 51536), -- Alliance Banner (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+109, 179468, 30, 2597, 2959, '0', '0', 0, 638.65704345703125, -32.2294387817382812, 46.09035110473632812, 4.660029888153076171, 0, 0, -0.72537422180175781, 0.688354730606079101, 7200, 255, 1, 51886), -- HORDE -- Contested Banner (Area: Dun Baldar - Difficulty: 0) CreateObject2
(@OGUID+110, 179467, 30, 2597, 3303, '0', '0', 0, 638.605712890625, -32.1506080627441406, 46.09933853149414062, 4.677483558654785156, 0, 0, -0.71933937072753906, 0.694658815860748291, 7200, 255, 1, 51886), -- Horde Banner (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1
(@OGUID+111, 179466, 30, 2597, 0, '0', '0', 0, 638.478759765625, -31.2173938751220703, 46.24166488647460937, 1.623155713081359863, 0, 0, 0.725374221801757812, 0.688354730606079101, 7200, 255, 1, 51886), -- ALLIANCE -- Contested Banner (Area: 0 - Difficulty: 0) CreateObject1

-- Stormpike
(@OGUID+112, 178389, 30, 2597, 0, '0', '0', 0, 669.00726318359375, -294.078277587890625, 30.29091072082519531, 2.775068521499633789, 0, 0, 0.983254432678222656, 0.182238012552261352, 7200, 255, 1, 51536), -- Alliance Banner (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+113, 179287, 30, 2597, 3303, '0', '0', 0, 669.29534912109375, -294.03753662109375, 30.28968620300292968, 5.916667938232421875, 0, 0, -0.18223476409912109, 0.98325502872467041, 7200, 255, 1, 51536), -- HORDE -- Contested Banner (Area: Stormpike Graveyard - Difficulty: 0) CreateObject2
(@OGUID+114, 178388, 30, 2597, 2959, '0', '0', 0, 669.31671142578125, -294.0552978515625, 30.28966903686523437, 5.916667938232421875, 0, 0, -0.18223476409912109, 0.98325502872467041, 7200, 255, 1, 51886), -- Horde Banner (Area: Dun Baldar - Difficulty: 0) CreateObject1
(@OGUID+115, 179286, 30, 2597, 3303, '0', '0', 0, 669.0321044921875, -294.060333251953125, 30.29091072082519531, 2.775068521499633789, 0, 0, 0.983254432678222656, 0.182238012552261352, 7200, 255, 1, 51886), -- Contested Banner (Area: Stormpike Graveyard - Difficulty: 0) CreateObject2

-- Stonehearth
(@OGUID+116, 179310, 30, 2597, 0, '0', '0', 0, 73.5868072509765625, -425.880218505859375, 60.67258071899414062, 5.410521507263183593, 0, 0, -0.42261791229248046, 0.906307935714721679, 7200, 255, 1, 51536), -- HORDE -- Contested Banner (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+117, 179285, 30, 2597, 0, '0', '0', 0, 73.58333587646484375, -425.876739501953125, 60.67203140258789062, 5.427974700927734375, 0, 0, -0.41469287872314453, 0.909961462020874023, 7200, 255, 1, 51536), -- Horde Banner (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+118, 179284, 30, 2597, 0, '0', '0', 0, 73.2899322509765625, -425.767364501953125, 60.6420440673828125, 2.286378860473632812, 0, 0, 0.909960746765136718, 0.414694398641586303, 7200, 255, 1, 51536), -- Alliance Banner (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+119, 179308, 30, 2597, 0, '0', '0', 0, 74.17014312744140625, -426.6319580078125, 60.8524322509765625, 5.427974700927734375, 0, 0, -0.41469287872314453, 0.909961462020874023, 7200, 255, 1, 51886), -- ALLIANCE -- Contested Banner (Area: 0 - Difficulty: 0) CreateObject1

-- Snowfall
-- -- Click Flag
(@OGUID+120, 180418, 30, 2597, 2958, '0', '0', 0, -202.610671997070312, -112.777992248535156, 78.48715972900390625, 5.131268978118896484, 0, 0, -0.54463863372802734, 0.838670849800109863, 7200, 255, 1, 51886), -- Snowfall Banner (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1
(@OGUID+121, 180420, 30, 2597, 3300, '0', '0', 0, -202.651580810546875, -112.807289123535156, 78.487060546875, 5.183629035949707031, 0, 0, -0.52249813079833984, 0.852640450000762939, 7200, 255, 1, 51536), -- Contested Banner (Area: Iceblood Graveyard - Difficulty: 0) CreateObject1
(@OGUID+122, 180419, 30, 2597, 3301, '0', '0', 0, -202.580841064453125, -112.730262756347656, 78.487579345703125, 5.567600727081298828, 0, 0, -0.35020732879638671, 0.936672210693359375, 7200, 255, 1, 51886), -- Contested Banner (Area: Snowfall Graveyard - Difficulty: 0) CreateObject2
(@OGUID+123, 178364, 30, 2597, 2977, '0', '0', 0, -202.622726440429687, -112.551490783691406, 78.49015045166015625, 5.026549339294433593, 0, 0, -0.5877847671508789, 0.809017360210418701, 7200, 255, 1, 51536), -- Horde Banner (Area: Iceblood Garrison - Difficulty: 0) CreateObject1
(@OGUID+124, 178365, 30, 2597, 2958, '0', '0', 0, -202.277786254882812, -113.208442687988281, 78.47940826416015625, 5.026549339294433593, 0, 0, -0.5877847671508789, 0.809017360210418701, 7200, 255, 1, 51886), -- Alliance Banner (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1

-- -- Other banners
(@OGUID+125, 179425, 30, 2597, 3300, '0', '0', 0, -201.178604125976562, -134.266876220703125, 78.677734375, 5.288348197937011718, 0, 0, -0.4771585464477539, 0.878817260265350341, 7200, 255, 1, 51536), -- [PH] Horde Graveyard Mid Pre-Banner BIG (Area: Iceblood Graveyard - Difficulty: 0) CreateObject1
(@OGUID+126, 179064, 30, 2597, 2962, '0', '0', 0, -201.443679809570312, -134.444442749023437, 78.9321136474609375, 5.427974700927734375, 0, 0, -0.41469287872314453, 0.909961462020874023, 7200, 255, 1, 51536), -- [PH] Horde Graveyard Mid Banner BIG (Area: Tower Point - Difficulty: 0) CreateObject1
(@OGUID+127, 179424, 30, 2597, 3301, '0', '0', 0, -201.281692504882812, -134.31884765625, 78.6753387451171875, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 7200, 255, 1, 51886), -- [PH] Alliance Graveyard Mid Pre-Banner BIG (Area: Snowfall Graveyard - Difficulty: 0) CreateObject2
(@OGUID+128, 179044, 30, 2597, 0, '0', '0', 0, -201.284072875976562, -134.570266723632812, 78.84847259521484375, 5.462882041931152343, 0, 0, -0.39874839782714843, 0.917060375213623046, 7200, 255, 1, 51886), -- [PH] Alliance Graveyard Mid Banner BIG (Area: 0 - Difficulty: 0) CreateObject1

(@OGUID+129, 179064, 30, 2597, 2962, '0', '0', 0, -190.94097900390625, -129.869354248046875, 78.93259429931640625, 5.218535900115966796, 0, 0, -0.507537841796875, 0.861629426479339599, 7200, 255, 1, 51536), -- [PH] Horde Graveyard Mid Banner BIG (Area: Tower Point - Difficulty: 0) CreateObject1
(@OGUID+130, 179425, 30, 2597, 3300, '0', '0', 0, -191.17578125, -129.929473876953125, 78.675201416015625, 5.078907966613769531, 0, 0, -0.56640625, 0.824126183986663818, 7200, 255, 1, 51536), -- [PH] Horde Graveyard Mid Pre-Banner BIG (Area: Iceblood Graveyard - Difficulty: 0) CreateObject1
(@OGUID+131, 179044, 30, 2597, 0, '0', '0', 0, -191.016708374023437, -129.963272094726562, 78.864227294921875, 5.235987663269042968, 0, 0, -0.5, 0.866025388240814208, 7200, 255, 1, 51886), -- [PH] Alliance Graveyard Mid Banner BIG (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+132, 179424, 30, 2597, 3301, '0', '0', 0, -191.153106689453125, -129.868377685546875, 78.5594940185546875, 5.026549339294433593, 0, 0, -0.5877847671508789, 0.809017360210418701, 7200, 255, 1, 51886), -- [PH] Alliance Graveyard Mid Pre-Banner BIG (Area: Snowfall Graveyard - Difficulty: 0) CreateObject2

(@OGUID+133, 179064, 30, 2597, 2962, '0', '0', 0, -215.740997314453125, -90.9972915649414062, 80.08941650390625, 1.169368624687194824, 0, 0, 0.551936149597167968, 0.833886384963989257, 7200, 255, 1, 51536), -- [PH] Horde Graveyard Mid Banner BIG (Area: Tower Point - Difficulty: 0) CreateObject1
(@OGUID+134, 179425, 30, 2597, 3300, '0', '0', 0, -216.158309936523437, -91.621856689453125, 80.86038970947265625, 4.555310726165771484, 0, 0, -0.76040554046630859, 0.649448513984680175, 7200, 255, 1, 51536), -- [PH] Horde Graveyard Mid Pre-Banner BIG (Area: Iceblood Graveyard - Difficulty: 0) CreateObject1
(@OGUID+135, 179044, 30, 2597, 0, '0', '0', 0, -216.212020874023437, -90.7064361572265625, 79.80706024169921875, 1.169368624687194824, 0, 0, 0.551936149597167968, 0.833886384963989257, 7200, 255, 1, 51886), -- [PH] Alliance Graveyard Mid Banner BIG (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+136, 179424, 30, 2597, 3301, '0', '0', 0, -215.980911254882812, -91.4101028442382812, 80.87021636962890625, 4.537858963012695312, 0, 0, -0.76604366302490234, 0.642788589000701904, 7200, 255, 1, 51886), -- [PH] Alliance Graveyard Mid Pre-Banner BIG (Area: Snowfall Graveyard - Difficulty: 0) CreateObject2

(@OGUID+137, 179064, 30, 2597, 2962, '0', '0', 0, -200.429367065429687, -96.5082473754882812, 79.75235748291015625, 1.343901276588439941, 0, 0, 0.622513771057128906, 0.78260880708694458, 7200, 255, 1, 51536), -- [PH] Horde Graveyard Mid Banner BIG (Area: Tower Point - Difficulty: 0) CreateObject1
(@OGUID+138, 179425, 30, 2597, 3300, '0', '0', 0, -200.6962890625, -96.61767578125, 79.70095062255859375, 4.188792228698730468, 0, 0, -0.86602497100830078, 0.50000077486038208, 7200, 255, 1, 51536), -- [PH] Horde Graveyard Mid Pre-Banner BIG (Area: Iceblood Graveyard - Difficulty: 0) CreateObject1
(@OGUID+139, 179044, 30, 2597, 0, '0', '0', 0, -200.464630126953125, -96.41796875, 79.75870513916015625, 1.361356139183044433, 0, 0, 0.629320144653320312, 0.77714616060256958, 7200, 255, 1, 51886), -- [PH] Alliance Graveyard Mid Banner BIG (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+140, 179424, 30, 2597, 3301, '0', '0', 0, -200.738723754882812, -96.6796875, 79.7800140380859375, 4.276057243347167968, 0, 0, -0.84339141845703125, 0.537299633026123046, 7200, 255, 1, 51886), -- [PH] Alliance Graveyard Mid Pre-Banner BIG (Area: Snowfall Graveyard - Difficulty: 0) CreateObject2

-- Iceblood
(@OGUID+141, 179483, 30, 2597, 3318, '0', '0', 0, -612.671630859375, -396.693267822265625, 60.85839080810546875, 3.089183330535888671, 0, 0, 0.99965667724609375, 0.026201646775007247, 7200, 255, 1, 51536), -- Horde Banner (Area: Rock of Durotan - Difficulty: 0) CreateObject1
(@OGUID+142, 179482, 30, 2597, 2977, '0', '0', 0, -611.52276611328125, -396.819000244140625, 60.85839080810546875, 6.248279094696044921, 0, 0, -0.01745223999023437, 0.999847710132598876, 7200, 255, 1, 51886), -- ALLIANCE -- Contested Banner (Area: Iceblood Garrison - Difficulty: 0) CreateObject1
(@OGUID+143, 179481, 30, 2597, 0, '0', '0', 0, -612.91387939453125, -396.83831787109375, 60.85839080810546875, 3.106652259826660156, 0, 0, 0.999847412109375, 0.017469281330704689, 7200, 255, 1, 51886), -- Alliance Banner (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+144, 179484, 30, 2597, 0, '0', '0', 0, -612.6614990234375, -396.69921875, 60.85839080810546875, 6.248279094696044921, 0, 0, -0.01745223999023437, 0.999847710132598876, 7200, 255, 1, 51886), -- Contested Banner (Area: 0 - Difficulty: 0) CreateObject2

-- Frostwolf
(@OGUID+145, 178393, 30, 2597, 2597, '0', '0', 0, -1082.5294189453125, -346.5670166015625, 54.97712326049804687, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 7200, 255, 1, 51536), -- Horde Banner (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+146, 179304, 30, 2597, 0, '0', '0', 0, -1082.4476318359375, -346.823394775390625, 54.92188262939453125, 4.747295856475830078, 0, 0, -0.69465827941894531, 0.719339847564697265, 7200, 255, 1, 51536), -- Contested Banner (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+147, 178394, 30, 2597, 2962, '0', '0', 0, -1082.4276123046875, -346.791656494140625, 54.92647552490234375, 4.764749526977539062, 0, 0, -0.6883544921875, 0.725374460220336914, 7200, 255, 1, 51536), -- Alliance Banner (Area: Tower Point - Difficulty: 0) CreateObject1
(@OGUID+148, 179305, 30, 2597, 0, '0', '0', 0, -1082.5361328125, -346.567169189453125, 54.97722244262695312, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 7200, 255, 1, 51886), -- Contested Banner (Area: 0 - Difficulty: 0) CreateObject2

-- Frostwolf Hut
(@OGUID+149, 179472, 30, 2597, 2597, '0', '0', 0, -1402.19189453125, -307.467071533203125, 89.44189453125, 0.191985160112380981, 0, 0, 0.095845222473144531, 0.995396256446838378, 7200, 255, 1, 51536), -- Horde Banner (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+150, 179471, 30, 2597, 0, '0', '0', 0, -1402.2781982421875, -307.37982177734375, 89.44196319580078125, 0.191985160112380981, 0, 0, 0.095845222473144531, 0.995396256446838378, 7200, 255, 1, 51536), -- ALLIANCE -- Contested Banner (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+151, 179470, 30, 2597, 0, '0', '0', 0, -1402.2095947265625, -307.43115234375, 89.44242095947265625, 0.191985160112380981, 0, 0, 0.095845222473144531, 0.995396256446838378, 7200, 255, 1, 51886), -- Alliance Banner (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+152, 179473, 30, 2597, 2978, '0', '0', 0, -1402.175537109375, -307.3056640625, 89.4469757080078125, 0.191985160112380981, 0, 0, 0.095845222473144531, 0.995396256446838378, 7200, 255, 1, 51886); -- Contested Banner (Area: Frostwolf Keep - Difficulty: 0) CreateObject2

-- Towers
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- South bunker
(@OGUID+153, 178927, 30, 2597, 2958, '0', '0', 0, 557.2266845703125, -86.85205078125, 62.17669677734375, 6.03883981704711914, 0, 0, -0.12186908721923828, 0.9925462007522583, 7200, 255, 1, 51536), -- [PH] Alliance A1 Tower Banner BIG (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1
(@OGUID+154, 178925, 30, 2597, 0, '0', '0', 0, 553.7794189453125, -78.6565780639648437, 51.93778610229492187, 5.061456203460693359, 0, 0, -0.57357597351074218, 0.819152355194091796, 7200, 255, 1, 51536), -- Alliance Banner (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+155, 179435, 30, 2597, 2959, '0', '0', 0, 553.82159423828125, -78.7675247192382812, 51.93867874145507812, 5.218535900115966796, 0, 0, -0.507537841796875, 0.861629426479339599, 7200, 255, 1, 51886), -- Contested Banner (Area: Dun Baldar - Difficulty: 0) CreateObject1
(@OGUID+156, 179436, 30, 2597, 2959, '0', '0', 0, 555.84759521484375, -84.4151458740234375, 64.43967437744140625, 3.124123096466064453, 0, 0, 0.99996185302734375, 0.008734640665352344, 7200, 255, 1, 51886), -- [PH] Horde A1 Tower Pre-Banner BIG (Area: Dun Baldar - Difficulty: 0) CreateObject2
(@OGUID+157, 179065, 30, 2597, 2958, '0', '0', 0, 549.262939453125, -79.364532470703125, 44.8191070556640625, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 7200, 255, 1, 51886), -- Roaring Flame (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1
(@OGUID+158, 179065, 30, 2597, 2958, '0', '0', 0, 558.0970458984375, -70.984161376953125, 52.48755645751953125, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 7200, 255, 1, 51886), -- Roaring Flame (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1
(@OGUID+159, 179065, 30, 2597, 2958, '0', '0', 0, 556.02777099609375, -94.9242095947265625, 44.8191070556640625, 3.054326534271240234, 0, 0, 0.999048233032226562, 0.043619260191917419, 7200, 255, 1, 51886), -- Roaring Flame (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1
(@OGUID+160, 179065, 30, 2597, 2958, '0', '0', 0, 562.632080078125, -88.1814804077148437, 61.99303054809570312, 0.383971005678176879, 0, 0, 0.190808296203613281, 0.981627285480499267, 7200, 255, 1, 51886), -- Roaring Flame (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1
(@OGUID+161, 179065, 30, 2597, 2958, '0', '0', 0, 572.1492919921875, -93.7861862182617187, 52.57261276245117187, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 7200, 255, 1, 51886), -- Roaring Flame (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1
(@OGUID+162, 179065, 30, 2597, 2958, '0', '0', 0, 543.5126953125, -94.4005508422851562, 52.48191070556640625, 0.034906249493360519, 0, 0, 0.017452239990234375, 0.999847710132598876, 7200, 255, 1, 51886), -- Roaring Flame (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1
(@OGUID+163, 179065, 30, 2597, 2958, '0', '0', 0, 562.52294921875, -74.5027694702148437, 37.94743728637695312, 6.230826377868652343, 0, 0, -0.02617645263671875, 0.999657332897186279, 7200, 255, 1, 51886), -- Roaring Flame (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1
(@OGUID+164, 179065, 30, 2597, 2958, '0', '0', 0, 572.45086669921875, -94.3654556274414062, 37.94425201416015625, 4.555310726165771484, 0, 0, -0.76040554046630859, 0.649448513984680175, 7200, 255, 1, 51886), -- Roaring Flame (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1
(@OGUID+165, 179065, 30, 2597, 3302, '0', '0', 0, 582.161865234375, -81.2375259399414062, 37.9216461181640625, 0.087265998125076293, 0, 0, 0.043619155883789062, 0.999048233032226562, 7200, 255, 1, 51886), -- Roaring Flame (Area: Stonehearth Graveyard - Difficulty: 0) CreateObject1
(@OGUID+166, 179065, 30, 2597, 3302, '0', '0', 0, 578.16705322265625, -71.8190689086914062, 38.15139389038085937, 2.72271275520324707, 0, 0, 0.978147506713867187, 0.207912087440490722, 7200, 255, 1, 51886), -- Roaring Flame (Area: Stonehearth Graveyard - Difficulty: 0) CreateObject1

-- North bunker
(@OGUID+167, 179440, 30, 2597, 2959, '0', '0', 0, 677.5916748046875, -139.034286499023437, 76.21964263916015625, 4.293513298034667968, 0, 0, -0.8386697769165039, 0.544640243053436279, 7200, 255, 1, 51536), -- [PH] Horde A2 Tower Pre-Banner BIG (Area: Dun Baldar - Difficulty: 0) CreateObject2
(@OGUID+168, 178932, 30, 2597, 2958, '0', '0', 0, 679.33917236328125, -136.46783447265625, 73.96262359619140625, 4.118979454040527343, 0, 0, -0.88294696807861328, 0.469472706317901611, 7200, 255, 1, 51536), -- [PH] Alliance A2 Tower Banner BIG (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1
(@OGUID+169, 179439, 30, 2597, 2959, '0', '0', 0, 674.046875, -143.155868530273437, 63.66139602661132812, 0.994837164878845214, 0, 0, 0.477158546447753906, 0.878817260265350341, 7200, 255, 1, 51536), -- Contested Banner (Area: Dun Baldar - Difficulty: 0) CreateObject2
(@OGUID+170, 178929, 30, 2597, 0, '0', '0', 0, 674.0006103515625, -143.12506103515625, 63.6615142822265625, 0.994837164878845214, 0, 0, 0.477158546447753906, 0.878817260265350341, 7200, 255, 1, 51536), -- Alliance Banner (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+171, 179065, 30, 2597, 3304, '0', '0', 0, 676.06695556640625, -124.319343566894531, 49.67263031005859375, 5.270895957946777343, 0, 0, -0.48480892181396484, 0.87462007999420166, 7200, 255, 1, 51886), -- Roaring Flame (Area: Icewing Bunker - Difficulty: 0) CreateObject1
(@OGUID+172, 179065, 30, 2597, 3304, '0', '0', 0, 680.2628173828125, -118.591583251953125, 64.33632659912109375, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 7200, 255, 1, 51886), -- Roaring Flame (Area: Icewing Bunker - Difficulty: 0) CreateObject1
(@OGUID+173, 179065, 30, 2597, 3304, '0', '0', 0, 674.5762939453125, -147.101181030273437, 56.54253005981445312, 4.677483558654785156, 0, 0, -0.71933937072753906, 0.694658815860748291, 7200, 255, 1, 51886), -- Roaring Flame (Area: Icewing Bunker - Difficulty: 0) CreateObject1
(@OGUID+174, 179065, 30, 2597, 3304, '0', '0', 0, 655.71905517578125, -126.673286437988281, 49.81383895874023437, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 7200, 255, 1, 51886), -- Roaring Flame (Area: Icewing Bunker - Difficulty: 0) CreateObject1
(@OGUID+175, 179065, 30, 2597, 3304, '0', '0', 0, 664.7972412109375, -143.650177001953125, 64.17842864990234375, 5.829400539398193359, 0, 0, -0.22495079040527343, 0.974370121955871582, 7200, 255, 1, 51886), -- Roaring Flame (Area: Icewing Bunker - Difficulty: 0) CreateObject1
(@OGUID+176, 179065, 30, 2597, 3304, '0', '0', 0, 664.50482177734375, -139.451614379882812, 49.6695556640625, 6.248279094696044921, 0, 0, -0.01745223999023437, 0.999847710132598876, 7200, 255, 1, 51886), -- Roaring Flame (Area: Icewing Bunker - Difficulty: 0) CreateObject1
(@OGUID+177, 179065, 30, 2597, 3304, '0', '0', 0, 684.4228515625, -146.582138061523437, 63.66624832153320312, 0.994837164878845214, 0, 0, 0.477158546447753906, 0.878817260265350341, 7200, 255, 1, 51886), -- Roaring Flame (Area: Icewing Bunker - Difficulty: 0) CreateObject1
(@OGUID+178, 179065, 30, 2597, 3304, '0', '0', 0, 693.0042724609375, -144.025070190429687, 64.1754913330078125, 2.44346022605895996, 0, 0, 0.939692497253417968, 0.34202045202255249, 7200, 255, 1, 51886), -- Roaring Flame (Area: Icewing Bunker - Difficulty: 0) CreateObject1
(@OGUID+179, 179065, 30, 2597, 3304, '0', '0', 0, 682.79083251953125, -127.768608093261718, 62.41549301147460937, 1.099556446075439453, 0, 0, 0.522498130798339843, 0.852640450000762939, 7200, 255, 1, 51886), -- Roaring Flame (Area: Icewing Bunker - Difficulty: 0) CreateObject1
(@OGUID+180, 179065, 30, 2597, 3304, '0', '0', 0, 661.1746826171875, -117.690757751464843, 49.64495086669921875, 1.919861555099487304, 0, 0, 0.819151878356933593, 0.573576688766479492, 7200, 255, 1, 51886), -- Roaring Flame (Area: Icewing Bunker - Difficulty: 0) CreateObject1

-- East Frostwolf
(@OGUID+181, 178944, 30, 2597, 2597, '0', '0', 0, -1302.8681640625, -316.9683837890625, 113.8671035766601562, 2.007128477096557617, 0, 0, 0.84339141845703125, 0.537299633026123046, 7200, 255, 1, 51536), -- Horde Banner (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+182, 179449, 30, 2597, 0, '0', '0', 0, -1302.8995361328125, -316.981109619140625, 113.8671035766601562, 2.007128477096557617, 0, 0, 0.84339141845703125, 0.537299633026123046, 7200, 255, 1, 51536), -- Contested Banner (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+183, 178956, 30, 2597, 2597, '0', '0', 0, -1302.73486328125, -316.63031005859375, 127.5031967163085937, 0.122172988951206207, 0, 0, 0.061048507690429687, 0.998134791851043701, 7200, 255, 1, 51536), -- [PH] Horde H2 Tower Banner BIG (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+184, 179450, 30, 2597, 0, '0', '0', 0, -1302.8350830078125, -316.581878662109375, 127.516387939453125, 0.122172988951206207, 0, 0, 0.061048507690429687, 0.998134791851043701, 7200, 255, 1, 51536), -- [PH] Alliance H2 Tower Pre-Banner BIG (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+185, 179065, 30, 2597, 2961, '0', '0', 0, -1311.566650390625, -308.079742431640625, 91.7665557861328125, 4.433136463165283203, 0, 0, -0.79863548278808593, 0.60181504487991333, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject2
(@OGUID+186, 179065, 30, 2597, 2961, '0', '0', 0, -1314.703125, -322.1309814453125, 107.3601531982421875, 0.645771682262420654, 0, 0, 0.317304611206054687, 0.948323667049407958, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject2
(@OGUID+187, 179065, 30, 2597, 2961, '0', '0', 0, -1302.6549072265625, -317.19232177734375, 127.487213134765625, 2.303830623626708984, 0, 0, 0.913544654846191406, 0.406738430261611938, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject2
(@OGUID+188, 179065, 30, 2597, 2961, '0', '0', 0, -1312.40673828125, -312.998809814453125, 107.3280029296875, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject2
(@OGUID+189, 179065, 30, 2597, 2961, '0', '0', 0, -1305.5775146484375, -320.624725341796875, 102.1660385131835937, 5.724681377410888671, 0, 0, -0.27563667297363281, 0.961261868476867675, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject2
(@OGUID+190, 179065, 30, 2597, 2961, '0', '0', 0, -1293.89453125, -313.4776611328125, 107.3280029296875, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject2
(@OGUID+191, 179065, 30, 2597, 2961, '0', '0', 0, -1304.8658447265625, -304.52490234375, 91.83664703369140625, 5.602506637573242187, 0, 0, -0.33380699157714843, 0.942641437053680419, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject2
(@OGUID+192, 179065, 30, 2597, 2961, '0', '0', 0, -1294.2664794921875, -323.467620849609375, 113.8926315307617187, 4.607671737670898437, 0, 0, -0.74314403533935546, 0.669131457805633544, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject2
(@OGUID+193, 179065, 30, 2597, 2961, '0', '0', 0, -1301.77392578125, -310.97369384765625, 95.82520294189453125, 0.907570242881774902, 0, 0, 0.438370704650878906, 0.898794233798980712, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject2
(@OGUID+194, 179065, 30, 2597, 2961, '0', '0', 0, -1304.5982666015625, -310.75384521484375, 113.8587417602539062, 5.881760597229003906, 0, 0, -0.19936752319335937, 0.979924798011779785, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject2

-- West Frostwolf
(@OGUID+195, 178955, 30, 2597, 2597, '0', '0', 0, -1297.7864990234375, -266.742828369140625, 127.7904205322265625, 0.069811686873435974, 0, 0, 0.034898757934570312, 0.999390840530395507, 7200, 255, 1, 51536), -- [PH] Horde H1 Tower Banner BIG (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+196, 178943, 30, 2597, 2597, '0', '0', 0, -1297.7154541015625, -266.741485595703125, 114.1512222290039062, 3.316144466400146484, 0, 0, -0.99619388580322265, 0.087165042757987976, 7200, 255, 1, 51536), -- Horde Banner (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+197, 179445, 30, 2597, 0, '0', '0', 0, -1297.694580078125, -266.7301025390625, 114.1512222290039062, 3.351046562194824218, 0, 0, -0.99452114105224609, 0.104535527527332305, 7200, 255, 1, 51536), -- Contested Banner (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+198, 179446, 30, 2597, 0, '0', '0', 0, -1297.869384765625, -266.7623291015625, 127.7958297729492187, 0.069811686873435974, 0, 0, 0.034898757934570312, 0.999390840530395507, 7200, 255, 1, 51536), -- [PH] Alliance H1 Tower Pre-Banner BIG (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+199, 179065, 30, 2597, 2961, '0', '0', 0, -1295.5533447265625, -263.865081787109375, 105.033172607421875, 0.925023794174194335, 0, 0, 0.446197509765625, 0.894934535026550292, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject2
(@OGUID+200, 179065, 30, 2597, 2961, '0', '0', 0, -1303.4053955078125, -268.2369384765625, 114.1512069702148437, 5.044002056121826171, 0, 0, -0.58070278167724609, 0.814115643501281738, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject2
(@OGUID+201, 179065, 30, 2597, 2961, '0', '0', 0, -1309.53369140625, -265.950531005859375, 92.14180755615234375, 3.78736734390258789, 0, 0, -0.94832324981689453, 0.317305892705917358, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject2
(@OGUID+202, 179065, 30, 2597, 2961, '0', '0', 0, -1294.7120361328125, -281.465728759765625, 107.6638412475585937, 4.782202720642089843, 0, 0, -0.68199825286865234, 0.731353819370269775, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject2
(@OGUID+203, 179065, 30, 2597, 2961, '0', '0', 0, -1302.2554931640625, -262.857696533203125, 95.9268951416015625, 0.418878614902496337, 0, 0, 0.207911491394042968, 0.978147625923156738, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject2
(@OGUID+204, 179065, 30, 2597, 2961, '0', '0', 0, -1297.2769775390625, -267.772613525390625, 126.7559127807617187, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject2
(@OGUID+205, 179065, 30, 2597, 2961, '0', '0', 0, -1289.6929931640625, -259.5211181640625, 107.6121063232421875, 4.084071159362792968, 0, 0, -0.8910064697265625, 0.453990638256072998, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject2
(@OGUID+206, 179065, 30, 2597, 2961, '0', '0', 0, -1304.43408203125, -273.681915283203125, 107.6121063232421875, 0.24434557557106018, 0, 0, 0.121869087219238281, 0.9925462007522583, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject2
(@OGUID+207, 179065, 30, 2597, 2961, '0', '0', 0, -1308.239990234375, -273.26025390625, 92.05139923095703125, 6.14356088638305664, 0, 0, -0.06975555419921875, 0.997564136981964111, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject2
(@OGUID+208, 179065, 30, 2597, 2961, '0', '0', 0, -1299.0775146484375, -256.889923095703125, 114.1078414916992187, 3.839725255966186523, 0, 0, -0.93969249725341796, 0.34202045202255249, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject2

-- Tower Point
(@OGUID+209, 179454, 30, 2597, 0, '0', '0', 0, -768.15411376953125, -363.102325439453125, 104.534576416015625, 0.122172988951206207, 0, 0, 0.061048507690429687, 0.998134791851043701, 7200, 255, 1, 51536), -- [PH] Alliance H3 Tower Pre-Banner BIG (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+210, 178957, 30, 2597, 2597, '0', '0', 0, -768.19903564453125, -363.105255126953125, 104.537200927734375, 0.104719325900077819, 0, 0, 0.052335739135742187, 0.998629570007324218, 7200, 255, 1, 51536), -- [PH] Horde H3 Tower Banner BIG (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+211, 178945, 30, 2597, 2597, '0', '0', 0, -768.0872802734375, -362.66607666015625, 90.89485931396484375, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 7200, 255, 1, 51536), -- Horde Banner (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+212, 179453, 30, 2597, 3300, '0', '0', 0, -768.07525634765625, -362.6295166015625, 90.89485931396484375, 1.151916384696960449, 0, 0, 0.544638633728027343, 0.838670849800109863, 7200, 255, 1, 51536), -- Contested Banner (Area: Iceblood Graveyard - Difficulty: 0) CreateObject1
(@OGUID+213, 179065, 30, 2597, 2978, '0', '0', 0, -777.5635986328125, -368.5211181640625, 90.67014312744140625, 1.727874636650085449, 0, 0, 0.760405540466308593, 0.649448513984680175, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Keep - Difficulty: 0) CreateObject1
(@OGUID+214, 179065, 30, 2597, 2978, '0', '0', 0, -760.35589599609375, -358.895721435546875, 84.35575103759765625, 2.129300594329833984, 0, 0, 0.874619483947753906, 0.484810054302215576, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Keep - Difficulty: 0) CreateObject1
(@OGUID+215, 179065, 30, 2597, 2978, '0', '0', 0, -771.96746826171875, -352.8380126953125, 84.34844207763671875, 1.745326757431030273, 0, 0, 0.766043663024902343, 0.642788589000701904, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Keep - Difficulty: 0) CreateObject1
(@OGUID+216, 179065, 30, 2597, 2978, '0', '0', 0, -764.10894775390625, -366.0693359375, 70.09340667724609375, 0.383971005678176879, 0, 0, 0.190808296203613281, 0.981627285480499267, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Keep - Difficulty: 0) CreateObject1
(@OGUID+217, 179065, 30, 2597, 2978, '0', '0', 0, -767.10284423828125, -350.737030029296875, 68.79332733154296875, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Keep - Difficulty: 0) CreateObject1
(@OGUID+218, 179065, 30, 2597, 2978, '0', '0', 0, -773.3331298828125, -364.652679443359375, 79.23514556884765625, 4.642575740814208984, 0, 0, -0.731353759765625, 0.681998312473297119, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Keep - Difficulty: 0) CreateObject1
(@OGUID+219, 179065, 30, 2597, 2978, '0', '0', 0, -776.072265625, -368.04638671875, 84.35575103759765625, 2.635444164276123046, 0, 0, 0.96814727783203125, 0.250381410121917724, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Keep - Difficulty: 0) CreateObject1
(@OGUID+220, 179065, 30, 2597, 2978, '0', '0', 0, -765.46051025390625, -357.71142578125, 90.88797760009765625, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Keep - Difficulty: 0) CreateObject1
(@OGUID+221, 179065, 30, 2597, 2978, '0', '0', 0, -760.115478515625, -353.844635009765625, 68.86331939697265625, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Keep - Difficulty: 0) CreateObject1
(@OGUID+222, 179065, 30, 2597, 2978, '0', '0', 0, -768.76300048828125, -362.73486328125, 104.6117324829101562, 1.815141916275024414, 0, 0, 0.788010597229003906, 0.615661680698394775, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Keep - Difficulty: 0) CreateObject1

-- Iceblood
(@OGUID+223, 178958, 30, 2597, 2597, '0', '0', 0, -572.32891845703125, -262.476287841796875, 88.64957427978515625, 5.70722818374633789, 0, 0, -0.28401470184326171, 0.958819925785064697, 7200, 255, 1, 51536), -- [PH] Horde H4 Tower Banner BIG (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+224, 179458, 30, 2597, 2962, '0', '0', 0, -572.20538330078125, -262.476226806640625, 88.66471099853515625, 5.6897735595703125, 0, 0, -0.29237174987792968, 0.956304728984832763, 7200, 255, 1, 51536), -- [PH] Alliance H4 Tower Pre-Banner BIG (Area: Tower Point - Difficulty: 0) CreateObject2
(@OGUID+225, 178940, 30, 2597, 2962, '0', '0', 0, -571.85675048828125, -262.790924072265625, 75.00867462158203125, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 7200, 255, 1, 51536), -- Contested Banner (Area: Tower Point - Difficulty: 0) CreateObject1
(@OGUID+226, 178946, 30, 2597, 0, '0', '0', 0, -571.879638671875, -262.776763916015625, 75.00867462158203125, 5.480334281921386718, 0, 0, -0.39073085784912109, 0.920504987239837646, 7200, 255, 1, 51536), -- Horde Banner (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+227, 179065, 30, 2597, 2961, '0', '0', 0, -580.94793701171875, -259.770233154296875, 68.469573974609375, 1.466075778007507324, 0, 0, 0.669130325317382812, 0.74314504861831665, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject1
(@OGUID+228, 179065, 30, 2597, 2961, '0', '0', 0, -566.03497314453125, -273.9073486328125, 52.95818328857421875, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject1
(@OGUID+229, 179065, 30, 2597, 2961, '0', '0', 0, -568.31781005859375, -267.099822998046875, 75.00077056884765625, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject1
(@OGUID+230, 179065, 30, 2597, 2961, '0', '0', 0, -578.625, -267.570953369140625, 68.469573974609375, 0.506144583225250244, 0, 0, 0.250379562377929687, 0.968147754669189453, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject1
(@OGUID+231, 179065, 30, 2597, 2961, '0', '0', 0, -574.77020263671875, -251.450027465820312, 74.94216156005859375, 5.096362113952636718, 0, 0, -0.55919265747070312, 0.829037725925445556, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject1
(@OGUID+232, 179065, 30, 2597, 2961, '0', '0', 0, -572.66680908203125, -267.9234619140625, 56.85420989990234375, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject1
(@OGUID+233, 179065, 30, 2597, 2961, '0', '0', 0, -572.538330078125, -262.649261474609375, 88.61969757080078125, 1.832594871520996093, 0, 0, 0.793353080749511718, 0.608761727809906005, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject1
(@OGUID+234, 179065, 30, 2597, 2961, '0', '0', 0, -571.47589111328125, -257.234375, 63.32225418090820312, 3.106652259826660156, 0, 0, 0.999847412109375, 0.017469281330704689, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject1
(@OGUID+235, 179065, 30, 2597, 2961, '0', '0', 0, -559.6212158203125, -268.5966796875, 52.89863967895507812, 0.052358884364366531, 0, 0, 0.02617645263671875, 0.999657332897186279, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject1
(@OGUID+236, 179065, 30, 2597, 2961, '0', '0', 0, -561.0213623046875, -262.6890869140625, 68.4589080810546875, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 7200, 255, 1, 51886), -- Roaring Flame (Area: Frostwolf Village - Difficulty: 0) CreateObject1

-- Stonehearth Bunker
(@OGUID+237, 179444, 30, 2597, 2958, '0', '0', 0, -155.832473754882812, -449.40093994140625, 52.7305908203125, 0.610863447189331054, 0, 0, 0.3007049560546875, 0.953717231750488281, 7200, 255, 1, 51536), -- [PH] Horde A4 Tower Pre-Banner BIG (Area: Stonehearth Outpost - Difficulty: 0) CreateObject2
(@OGUID+238, 178948, 30, 2597, 2962, '0', '0', 0, -156.4697265625, -449.953125, 50.668243408203125, 6.03883981704711914, 0, 0, -0.12186908721923828, 0.9925462007522583, 7200, 255, 1, 51536), -- [PH] Alliance A4 Tower Banner BIG (Area: Tower Point - Difficulty: 0) CreateObject1
(@OGUID+239, 178936, 30, 2597, 0, '0', '0', 0, -152.433914184570312, -441.61480712890625, 40.3970947265625, 4.345870018005371093, 0, 0, -0.82412624359130859, 0.566406130790710449, 7200, 255, 1, 51536), -- Alliance Banner (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+240, 179443, 30, 2597, 0, '0', '0', 0, -152.437286376953125, -441.75823974609375, 40.39822769165039062, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 7200, 255, 1, 51886), -- Contested Banner (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+241, 179065, 30, 2597, 3300, '0', '0', 0, -171.291015625, -444.683502197265625, 40.92113113403320312, 2.303830623626708984, 0, 0, 0.913544654846191406, 0.406738430261611938, 7200, 255, 1, 51536), -- Roaring Flame (Area: Iceblood Graveyard - Difficulty: 0) CreateObject1
(@OGUID+242, 179065, 30, 2597, 3300, '0', '0', 0, -155.487518310546875, -437.35589599609375, 33.27962112426757812, 2.600535154342651367, 0, 0, 0.963629722595214843, 0.26724100112915039, 7200, 255, 1, 51536), -- Roaring Flame (Area: Iceblood Graveyard - Difficulty: 0) CreateObject1
(@OGUID+243, 179065, 30, 2597, 3300, '0', '0', 0, -163.441085815429687, -454.1876220703125, 33.27962112426757812, 1.937312245368957519, 0, 0, 0.824125289916992187, 0.566407561302185058, 7200, 255, 1, 51536), -- Roaring Flame (Area: Iceblood Graveyard - Difficulty: 0) CreateObject1
(@OGUID+244, 179065, 30, 2597, 3300, '0', '0', 0, -143.591476440429687, -439.749664306640625, 40.92749404907226562, 4.555310726165771484, 0, 0, -0.76040554046630859, 0.649448513984680175, 7200, 255, 1, 51536), -- Roaring Flame (Area: Iceblood Graveyard - Difficulty: 0) CreateObject1
(@OGUID+245, 179065, 30, 2597, 3300, '0', '0', 0, -135.763992309570312, -464.708343505859375, 26.38227272033691406, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 7200, 255, 1, 51536), -- Roaring Flame (Area: Iceblood Graveyard - Difficulty: 0) CreateObject1
(@OGUID+246, 179065, 30, 2597, 3300, '0', '0', 0, -143.977218627929687, -445.148223876953125, 26.40972328186035156, 4.415683269500732421, 0, 0, -0.80385684967041015, 0.594822824001312255, 7200, 255, 1, 51536), -- Roaring Flame (Area: Iceblood Graveyard - Difficulty: 0) CreateObject1
(@OGUID+247, 179065, 30, 2597, 3300, '0', '0', 0, -154.075515747070312, -466.929046630859375, 41.0635528564453125, 4.415683269500732421, 0, 0, -0.80385684967041015, 0.594822824001312255, 7200, 255, 1, 51536), -- Roaring Flame (Area: Iceblood Graveyard - Difficulty: 0) CreateObject1
(@OGUID+248, 179065, 30, 2597, 3300, '0', '0', 0, -131.300994873046875, -454.904510498046875, 26.57706069946289062, 2.932138919830322265, 0, 0, 0.994521141052246093, 0.104535527527332305, 7200, 255, 1, 51536), -- Roaring Flame (Area: Iceblood Graveyard - Difficulty: 0) CreateObject1
(@OGUID+249, 179065, 30, 2597, 3300, '0', '0', 0, -151.637802124023437, -439.521270751953125, 40.37968826293945312, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 7200, 255, 1, 51536), -- Roaring Flame (Area: Iceblood Graveyard - Difficulty: 0) CreateObject1
(@OGUID+250, 179065, 30, 2597, 3300, '0', '0', 0, -149.908203125, -460.331695556640625, 26.40834999084472656, 4.188792228698730468, 0, 0, -0.86602497100830078, 0.50000077486038208, 7200, 255, 1, 51536), -- Roaring Flame (Area: Iceblood Graveyard - Difficulty: 0) CreateObject1

-- Icewing Bunker
(@OGUID+251, 178947, 30, 2597, 3057, '0', '0', 0, 208.9728240966796875, -365.97125244140625, 66.7409210205078125, 6.03883981704711914, 0, 0, -0.12186908721923828, 0.9925462007522583, 7200, 255, 1, 51536), -- [PH] Alliance A3 Tower Banner BIG (Area: Field of Strife - Difficulty: 0) CreateObject1
(@OGUID+252, 179442, 30, 2597, 0, '0', '0', 0, 202.5411834716796875, -361.857574462890625, 67.73706817626953125, 0.610863447189331054, 0, 0, 0.3007049560546875, 0.953717231750488281, 7200, 255, 1, 51536), -- [PH] Horde A3 Tower Pre-Banner BIG (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+253, 178935, 30, 2597, 0, '0', '0', 0, 203.238494873046875, -360.26422119140625, 56.38615036010742187, 5.410521507263183593, 0, 0, -0.42261791229248046, 0.906307935714721679, 7200, 255, 1, 51536), -- Alliance Banner (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+254, 179441, 30, 2597, 0, '0', '0', 0, 203.2808685302734375, -360.3663330078125, 56.38690567016601562, 5.35816192626953125, 0, 0, -0.446197509765625, 0.894934535026550292, 7200, 255, 1, 51536), -- Contested Banner (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+255, 179065, 30, 2597, 3057, '0', '0', 0, 205.7818450927734375, -351.335174560546875, 56.8997955322265625, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 7200, 255, 1, 51536), -- Roaring Flame (Area: Field of Strife - Difficulty: 0) CreateObject1
(@OGUID+256, 179065, 30, 2597, 3057, '0', '0', 0, 196.6048736572265625, -369.1871337890625, 56.39142227172851562, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 7200, 255, 1, 51536), -- Roaring Flame (Area: Field of Strife - Difficulty: 0) CreateObject1
(@OGUID+257, 179065, 30, 2597, 3057, '0', '0', 0, 200.2595977783203125, -359.967620849609375, 49.26770782470703125, 3.385940074920654296, 0, 0, -0.99254608154296875, 0.121869951486587524, 7200, 255, 1, 51536), -- Roaring Flame (Area: Field of Strife - Difficulty: 0) CreateObject1
(@OGUID+258, 179065, 30, 2597, 3017, '0', '0', 0, 196.6188201904296875, -378.016265869140625, 56.91305160522460937, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 7200, 255, 1, 51536), -- Roaring Flame (Area: Frost Dagger Pass - Difficulty: 0) CreateObject1
(@OGUID+259, 179065, 30, 2597, 3017, '0', '0', 0, 209.6469268798828125, -352.6319580078125, 42.39586639404296875, 5.585053920745849609, 0, 0, -0.34202003479003906, 0.939692676067352294, 7200, 255, 1, 51536), -- Roaring Flame (Area: Frost Dagger Pass - Difficulty: 0) CreateObject1
(@OGUID+260, 179065, 30, 2597, 3017, '0', '0', 0, 220.64996337890625, -368.13238525390625, 42.39780807495117187, 6.021387100219726562, 0, 0, -0.13052558898925781, 0.991444945335388183, 7200, 255, 1, 51536), -- Roaring Flame (Area: Frost Dagger Pass - Difficulty: 0) CreateObject1
(@OGUID+261, 179065, 30, 2597, 3017, '0', '0', 0, 224.9886016845703125, -348.175201416015625, 42.56069564819335937, 1.500982880592346191, 0, 0, 0.681998252868652343, 0.731353819370269775, 7200, 255, 1, 51536), -- Roaring Flame (Area: Frost Dagger Pass - Difficulty: 0) CreateObject1
(@OGUID+262, 179065, 30, 2597, 3017, '0', '0', 0, 210.6187591552734375, -376.9375, 49.26770782470703125, 2.862335443496704101, 0, 0, 0.990267753601074218, 0.139175355434417724, 7200, 255, 1, 51536), -- Roaring Flame (Area: Frost Dagger Pass - Difficulty: 0) CreateObject1
(@OGUID+263, 179065, 30, 2597, 3017, '0', '0', 0, 231.503143310546875, -356.688140869140625, 42.37038040161132812, 0.296705186367034912, 0, 0, 0.147809028625488281, 0.989015936851501464, 7200, 255, 1, 51536), -- Roaring Flame (Area: Frost Dagger Pass - Difficulty: 0) CreateObject1
(@OGUID+264, 179065, 30, 2597, 3017, '0', '0', 0, 224.68212890625, -374.031463623046875, 57.06790542602539062, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 7200, 255, 1, 51536); -- Roaring Flame (Area: Frost Dagger Pass - Difficulty: 0) CreateObject1

INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180424, 30, 2597, 2597, '0', '0', 0, -1382.056884765625, -545.9168701171875, 54.90467071533203125, 0.767943859100341796, 0, 0, 0.374606132507324218, 0.927184045314788818, 7200, 255, 1, 51536), -- Alterac Valley Gate (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+1, 179419, 30, 2597, 2597, '0', '0', 0, -1423.1614990234375, -318.435760498046875, 89.11356353759765625, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 7200, 255, 1, 51536), -- Brazier (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+2, 179025, 30, 2597, 2597, '0', '0', 0, -1551.8802490234375, -364.1875, 65.593353271484375, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 7200, 255, 1, 51536), -- Frostwolf Banner (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+3, 180322, 30, 2597, 2597, '0', '0', 0, -1382.432373046875, -545.41436767578125, 54.83085250854492187, 3.90954136848449707, 0, 0, -0.92718315124511718, 0.37460830807685852, 7200, 255, 1, 51536), -- Ghost Gate (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+4, 177409, 30, 2597, 2597, '0', '0', 0, -1215.592041015625, -371.946197509765625, 56.52930068969726562, 0.357791841030120849, 0, 0, 0.177943229675292968, 0.984040737152099609, 7200, 255, 1, 51536), -- Brazier (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+5, 177410, 30, 2597, 2597, '0', '0', 0, -1241.24658203125, -345.114593505859375, 59.68674087524414062, 0.357791841030120849, 0, 0, 0.177943229675292968, 0.984040737152099609, 7200, 255, 1, 51536), -- Brazier (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+6, 51705, 30, 2597, 2597, '0', '0', 0, -1258.2259521484375, -310.97747802734375, 63.20154953002929687, 0.862903237342834472, 0.017974376678466796, -0.01690864562988281, 0.418254852294921875, 0.907994449138641357, 7200, 255, 1, 51536), -- Anvil (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+7, 50984, 30, 2597, 2597, '0', '0', 0, -1250.392578125, -310.19140625, 61.18503189086914062, 5.174903392791748046, 0.024020671844482421, 0.005655288696289062, -0.52631187438964843, 0.849933445453643798, 7200, 255, 1, 51536), -- Heated Forge (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+8, 51704, 30, 2597, 2597, '0', '0', 0, -1245.2012939453125, -307.0587158203125, 63.31994247436523437, 3.079595088958740234, -0.0071115493774414, -0.02363014221191406, 0.999219894409179687, 0.030832361429929733, 7200, 255, 1, 51536), -- Anvil (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+9, 179438, 30, 2597, 2597, '0', '0', 0, -1181.099609375, -370.747222900390625, 53.62457275390625, 2.687806606292724609, 0, 0, 0.974370002746582031, 0.224951311945915222, 7200, 255, 1, 51536), -- Wanted: DWARVES! (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+10, 177412, 30, 2597, 2597, '0', '0', 0, -1282.2083740234375, -284.083343505859375, 87.25603485107421875, 6.222100734710693359, 0, 0, -0.03053760528564453, 0.999533593654632568, 7200, 255, 1, 51536), -- Brazier (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+11, 177413, 30, 2597, 2597, '0', '0', 0, -1256.5538330078125, -280.27777099609375, 73.94734954833984375, 6.222100734710693359, 0, 0, -0.03053760528564453, 0.999533593654632568, 7200, 255, 1, 51536), -- Brazier (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+12, 177405, 30, 2597, 2597, '0', '0', 0, -1140.8160400390625, -343.392364501953125, 50.90771484375, 3.499390363693237304, 0, 0, -0.9840402603149414, 0.177946031093597412, 7200, 255, 1, 51536), -- Brazier (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+13, 177406, 30, 2597, 2597, '0', '0', 0, -1139.6822509765625, -356.2882080078125, 51.26401901245117187, 5.576327323913574218, 0, 0, -0.34611701965332031, 0.938191354274749755, 7200, 255, 1, 51536), -- Brazier (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+14, 3832, 30, 2597, 2597, '0', '0', 0, -1235.5711669921875, -241.478118896484375, 73.437744140625, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 7200, 255, 1, 51536), -- Burning Embers (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+15, 3833, 30, 2597, 2597, '0', '0', 0, -1248.8515625, -254.060440063476562, 73.437744140625, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 7200, 255, 1, 51536), -- Burning Embers (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+16, 3834, 30, 2597, 2597, '0', '0', 0, -1248.14892578125, -245.59942626953125, 73.437744140625, 6.230826377868652343, 0, 0, -0.02617645263671875, 0.999657332897186279, 7200, 255, 1, 51536), -- Burning Embers (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+17, 3835, 30, 2597, 2597, '0', '0', 0, -1237.206298828125, -260.1676025390625, 73.437744140625, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 7200, 255, 1, 51536), -- Burning Embers (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+18, 3836, 30, 2597, 2597, '0', '0', 0, -1260.3656005859375, -248.766998291015625, 77.945404052734375, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 7200, 255, 1, 51536), -- Burning Embers (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+19, 3837, 30, 2597, 2597, '0', '0', 0, -1249.3153076171875, -244.907470703125, 92.33715057373046875, 0.401424884796142578, 0, 0, 0.199367523193359375, 0.979924798011779785, 7200, 255, 1, 51536), -- Burning Embers (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+20, 3838, 30, 2597, 2597, '0', '0', 0, -1250.091796875, -254.603591918945312, 92.30150604248046875, 0.148352250456809997, 0, 0, 0.074108123779296875, 0.997250199317932128, 7200, 255, 1, 51536), -- Burning Embers (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+21, 177411, 30, 2597, 2597, '0', '0', 0, -1202.8055419921875, -271.598968505859375, 72.58054351806640625, 0.357791841030120849, 0, 0, 0.177943229675292968, 0.984040737152099609, 7200, 255, 1, 51536), -- Brazier (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+22, 179945, 30, 2597, 2597, '0', '0', 0, -1070.532958984375, -617.90802001953125, 51.32492446899414062, 5.838126659393310546, 0, 0, -0.22069740295410156, 0.975342333316802978, 7200, 255, 1, 51536), -- Campfire (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+23, 177263, 30, 2597, 2597, '0', '0', 0, -1280.173583984375, -220.536453247070312, 72.26860809326171875, 1.623152971267700195, 0, 0, 0.725373268127441406, 0.688355743885040283, 7200, 255, 1, 51536), -- Campfire (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+24, 177292, 30, 2597, 2597, '0', '0', 0, -1099.2083740234375, -266.23089599609375, 57.88490676879882812, 3.996806621551513671, 0, 0, -0.90996074676513671, 0.414694398641586303, 7200, 255, 1, 51536), -- Brazier (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+25, 177293, 30, 2597, 2597, '0', '0', 0, -1082.6024169921875, -266.680572509765625, 57.85751724243164062, 2.408548831939697265, 0, 0, 0.933579444885253906, 0.358370482921600341, 7200, 255, 1, 51536), -- Brazier (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+26, 179909, 30, 2597, 2597, '0', '0', 0, -914.013916015625, -520.34722900390625, 57.22958755493164062, 1.535889148712158203, 0.057845592498779296, -0.04110336303710937, 0.693563461303710937, 0.716892004013061523, 7200, 255, 1, 51536), -- Rock of Durotan (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+27, 178784, 30, 2597, 2597, '0', '0', 0, -951.39434814453125, -193.694778442382812, 67.63397216796875, 0.802850961685180664, 0, 0, 0.390730857849121093, 0.920504987239837646, 7200, 255, 1, 51536), -- Coldtooth Supplies (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+28, 177408, 30, 2597, 2597, '0', '0', 0, -743.42706298828125, -398.2413330078125, 76.4265594482421875, 0.872664093971252441, 0.01739358901977539, -0.00633049011230468, 0.422700881958007812, 0.906080245971679687, 7200, 255, 1, 51536), -- Bonfire (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+29, 178784, 30, 2597, 2597, '0', '0', 0, -962.4659423828125, -168.578567504882812, 77.65695953369140625, 0.174532130360603332, 0, 0, 0.087155342102050781, 0.996194720268249511, 7200, 255, 1, 51536), -- Coldtooth Supplies (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+30, 177326, 30, 2597, 2962, '0', '0', 0, -487.401031494140625, -526.48614501953125, 82.5708465576171875, 5.471609115600585937, 0, 0, -0.39474296569824218, 0.918791592121124267, 7200, 255, 1, 51536), -- Campfire (Area: Tower Point - Difficulty: 0) CreateObject1
(@OGUID+31, 177325, 30, 2597, 2962, '0', '0', 0, -413.510406494140625, -521.4132080078125, 84.07706451416015625, 2.059488296508789062, 0, 0, 0.857167243957519531, 0.515038192272186279, 7200, 255, 1, 51536), -- Campfire (Area: Tower Point - Difficulty: 0) CreateObject1
(@OGUID+32, 177324, 30, 2597, 2962, '0', '0', 0, -375.017364501953125, -523.7100830078125, 84.07706451416015625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 51536), -- Campfire (Area: Tower Point - Difficulty: 0) CreateObject1
(@OGUID+33, 177327, 30, 2597, 0, '0', '0', 0, -251.555557250976562, -562.060791015625, 68.17247772216796875, 6.117380619049072265, 0, 0, -0.08280754089355468, 0.996565580368041992, 7200, 255, 1, 51536), -- Campfire (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+34, 179389, 30, 2597, 0, '0', '0', 0, -168.342391967773437, -458.40032958984375, 33.28615951538085937, 5.838126659393310546, 0, 0, -0.22069740295410156, 0.975342333316802978, 7200, 255, 1, 51536), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+35, 179391, 30, 2597, 0, '0', '0', 0, -172.362991333007812, -452.82415771484375, 33.27958297729492187, 0.6283189058303833, 0, 0, 0.309017181396484375, 0.951056420803070068, 7200, 255, 1, 51536), -- Anvil (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+36, 179392, 30, 2597, 0, '0', '0', 0, -171.28173828125, -456.89166259765625, 33.27958297729492187, 1.631881952285766601, 0, 0, 0.72837066650390625, 0.685183286666870117, 7200, 255, 1, 51536), -- Anvil (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+37, 179393, 30, 2597, 0, '0', '0', 0, -172.355575561523437, -453.880157470703125, 33.27958297729492187, 0.32288438081741333, 0, 0, 0.160741806030273437, 0.98699653148651123, 7200, 255, 1, 51536), -- Anvil (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+38, 179394, 30, 2597, 0, '0', '0', 0, -171.882232666015625, -454.6318359375, 33.27958297729492187, 0.759216904640197753, 0, 0, 0.370556831359863281, 0.928809821605682373, 7200, 255, 1, 51536), -- Anvil (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+39, 179395, 30, 2597, 0, '0', '0', 0, -171.6558837890625, -455.671295166015625, 33.27958297729492187, 0.061084706336259841, 0, 0, 0.030537605285644531, 0.999533593654632568, 7200, 255, 1, 51536), -- Anvil (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+40, 179396, 30, 2597, 0, '0', '0', 0, -170.698944091796875, -458.40960693359375, 33.27958297729492187, 5.253442287445068359, 0, 0, -0.49242305755615234, 0.870355963706970214, 7200, 255, 1, 51536), -- Anvil (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+41, 179397, 30, 2597, 0, '0', '0', 0, -170.140350341796875, -457.6087646484375, 33.27958297729492187, 5.602508544921875, 0, 0, -0.33380603790283203, 0.942641794681549072, 7200, 255, 1, 51536), -- Anvil (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+42, 179384, 30, 2597, 0, '0', '0', 0, -145.341384887695312, -444.845672607421875, 26.416259765625, 6.230826377868652343, 0, 0, -0.02617645263671875, 0.999657332897186279, 7200, 255, 1, 51536), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+43, 179385, 30, 2597, 0, '0', '0', 0, -155.404739379882812, -440.240142822265625, 33.28615951538085937, 2.347468852996826171, 0, 0, 0.922201156616210937, 0.386710494756698608, 7200, 255, 1, 51536), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+44, 179386, 30, 2597, 0, '0', '0', 0, -150.786636352539062, -459.829376220703125, 26.416259765625, 0.558503925800323486, 0, 0, 0.275636672973632812, 0.961261868476867675, 7200, 255, 1, 51536), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+45, 179387, 30, 2597, 0, '0', '0', 0, -153.74835205078125, -438.6392822265625, 33.28615951538085937, 3.394674062728881835, 0, 0, -0.99200439453125, 0.126203224062919616, 7200, 255, 1, 51536), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+46, 179388, 30, 2597, 0, '0', '0', 0, -149.056793212890625, -461.08917236328125, 26.416259765625, 1.38753819465637207, 0, 0, 0.639439582824707031, 0.768841326236724853, 7200, 255, 1, 51536), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+47, 179390, 30, 2597, 0, '0', '0', 0, -142.968002319335937, -444.076416015625, 26.416259765625, 4.049167633056640625, 0, 0, -0.89879322052001953, 0.438372820615768432, 7200, 255, 1, 51536), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+48, 32571, 30, 2597, 3057, '0', '0', 0, -100.07080078125, -583.51171875, 41.73162841796875, 0.008724239654839038, 0, 0, 0.004362106323242187, 0.999990463256835937, 7200, 255, 1, 51536), -- Anvil (Area: Field of Strife - Difficulty: 0) CreateObject1
(@OGUID+49, 34571, 30, 2597, 3057, '0', '0', 0, -105.423355102539062, -584.35174560546875, 42.014923095703125, 2.364918231964111328, 0, 0, 0.925539970397949218, 0.378649920225143432, 7200, 255, 1, 51536), -- Forge (Area: Field of Strife - Difficulty: 0) CreateObject1
(@OGUID+50, 32574, 30, 2597, 3057, '0', '0', 0, -106.171768188476562, -589.72076416015625, 41.73162841796875, 4.721118450164794921, 0, 0, -0.70401382446289062, 0.710186243057250976, 7200, 255, 1, 51536), -- Anvil (Area: Field of Strife - Difficulty: 0) CreateObject1
(@OGUID+51, 32572, 30, 2597, 3057, '0', '0', 0, -102.73321533203125, -588.7752685546875, 41.73162841796875, 5.244716167449951171, 0, 0, -0.4962158203125, 0.86819922924041748, 7200, 255, 1, 51536), -- Anvil (Area: Field of Strife - Difficulty: 0) CreateObject1
(@OGUID+52, 32573, 30, 2597, 3057, '0', '0', 0, -100.965805053710937, -586.9580078125, 41.73162841796875, 5.768314361572265625, 0, 0, -0.25460147857666015, 0.967046082019805908, 7200, 255, 1, 51536), -- Anvil (Area: Field of Strife - Difficulty: 0) CreateObject1
(@OGUID+53, 208246, 30, 2597, 3057, '0', '0', 0, 41.16717147827148437, -426.866058349609375, 44.68275833129882812, 2.783795118331909179, 0, 0, 0.984040260314941406, 0.177946031093597412, 7200, 255, 1, 51536), -- Wooden Chair (Area: Field of Strife - Difficulty: 0) CreateObject1
(@OGUID+54, 208247, 30, 2597, 3057, '0', '0', 0, 39.09879684448242187, -425.7462158203125, 44.68798446655273437, 5.663594245910644531, 0, 0, -0.30486392974853515, 0.952395915985107421, 7200, 255, 1, 51536), -- Wooden Chair (Area: Field of Strife - Difficulty: 0) CreateObject1
(@OGUID+55, 208245, 30, 2597, 0, '0', '0', 0, 50.6400604248046875, -421.1663818359375, 44.73253631591796875, 6.274435043334960937, -0.00858640670776367, 0.001552581787109375, -0.00436210632324218, 0.999952375888824462, 7200, 255, 1, 51536), -- Dwarven Fire (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+56, 177396, 30, 2597, 2958, '0', '0', 0, 12.82465267181396484, -120.210067749023437, 41.66688156127929687, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 51536), -- Cauldron (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1
(@OGUID+57, 161487, 30, 2597, 2958, '0', '0', 0, 361.09722900390625, -531.69268798828125, 71.1897735595703125, 4.127707481384277343, 0, 0, -0.880889892578125, 0.473321229219436645, 7200, 255, 1, 51536), -- Forge (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1
(@OGUID+58, 161488, 30, 2597, 2958, '0', '0', 0, 360.914947509765625, -497.098968505859375, 71.33890533447265625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 51536), -- Bonfire (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1
(@OGUID+59, 161489, 30, 2597, 2958, '0', '0', 0, 360.380218505859375, -527.54864501953125, 71.12046051025390625, 4.232423782348632812, 0, 0, -0.85491180419921875, 0.518773376941680908, 7200, 255, 1, 51536), -- Anvil (Area: Stonehearth Outpost - Difficulty: 0) CreateObject1
(@OGUID+60, 322707, 30, 2597, 3304, '0', '0', 0, 665.80035400390625, -4.33159732818603515, 73.33251953125, 0.205360665917396545, -0.01880693435668945, 0.071847915649414062, 0.103047370910644531, 0.99189990758895874, 7200, 255, 1, 51536), -- Collision PC Size (Area: Icewing Bunker - Difficulty: 0) CreateObject1
(@OGUID+61, 322707, 30, 2597, 3304, '0', '0', 0, 665.46875, 1.16319441795349121, 72.82878875732421875, 6.187799930572509765, -0.00783109664916992, 0.073854446411132812, -0.04670906066894531, 0.996143817901611328, 7200, 255, 1, 51536), -- Collision PC Size (Area: Icewing Bunker - Difficulty: 0) CreateObject1
(@OGUID+62, 322707, 30, 2597, 3304, '0', '0', 0, 666.48089599609375, -7.89583349227905273, 73.0741119384765625, 0.360511600971221923, -0.02431821823120117, 0.070174217224121093, 0.179607391357421875, 0.980930864810943603, 7200, 255, 1, 51536), -- Collision PC Size (Area: Icewing Bunker - Difficulty: 0) CreateObject1
(@OGUID+63, 179389, 30, 2597, 0, '0', '0', 0, 555.5166015625, -101.5894775390625, 44.8256988525390625, 0.392697066068649291, 0, 0, 0.195089340209960937, 0.980785489082336425, 7200, 255, 1, 51536), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+64, 179391, 30, 2597, 0, '0', '0', 0, 548.68243408203125, -100.846199035644531, 44.819122314453125, 1.466075778007507324, 0, 0, 0.669130325317382812, 0.74314504861831665, 7200, 255, 1, 51536), -- Anvil (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+65, 179392, 30, 2597, 0, '0', '0', 0, 552.42864990234375, -102.764358520507812, 44.819122314453125, 2.469640254974365234, 0, 0, 0.944088935852050781, 0.329690933227539062, 7200, 255, 1, 51536), -- Anvil (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+66, 179393, 30, 2597, 0, '0', '0', 0, 549.47216796875, -101.547279357910156, 44.819122314453125, 1.160643696784973144, 0, 0, 0.548293113708496093, 0.83628624677658081, 7200, 255, 1, 51536), -- Anvil (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+67, 179394, 30, 2597, 0, '0', '0', 0, 550.34747314453125, -101.698486328125, 44.819122314453125, 1.596976161003112792, 0, 0, 0.716301918029785156, 0.697790443897247314, 7200, 255, 1, 51536), -- Anvil (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+68, 179395, 30, 2597, 0, '0', '0', 0, 551.27142333984375, -102.225822448730468, 44.819122314453125, 0.89884275197982788, 0, 0, 0.434444427490234375, 0.900698602199554443, 7200, 255, 1, 51536), -- Anvil (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+69, 179396, 30, 2597, 0, '0', '0', 0, 553.94671630859375, -103.346954345703125, 44.819122314453125, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 7200, 255, 1, 51536), -- Anvil (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+70, 179397, 30, 2597, 0, '0', '0', 0, 553.725341796875, -102.395965576171875, 44.819122314453125, 0.15707901120185852, 0, 0, 0.078458786010742187, 0.996917366981506347, 7200, 255, 1, 51536), -- Anvil (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+71, 179385, 30, 2597, 0, '0', '0', 0, 550.677978515625, -79.8234024047851562, 44.8256988525390625, 3.185266733169555664, 0, 0, -0.99976158142089843, 0.021835235878825187, 7200, 255, 1, 51536), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+72, 179386, 30, 2597, 0, '0', '0', 0, 568.32568359375, -89.499237060546875, 37.9557952880859375, 1.396261811256408691, 0, 0, 0.642786979675292968, 0.766044974327087402, 7200, 255, 1, 51536), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+73, 179388, 30, 2597, 0, '0', '0', 0, 570.41943359375, -89.0566864013671875, 37.9557952880859375, 2.225293636322021484, 0, 0, 0.896872520446777343, 0.442289173603057861, 7200, 255, 1, 51536), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+74, 179384, 30, 2597, 0, '0', '0', 0, 560.834228515625, -75.4265823364257812, 37.9557952880859375, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 7200, 255, 1, 51536), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+75, 179387, 30, 2597, 0, '0', '0', 0, 550.59661865234375, -77.5212783813476562, 44.8256988525390625, 4.232423782348632812, 0, 0, -0.85491180419921875, 0.518773376941680908, 7200, 255, 1, 51536), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+76, 179390, 30, 2597, 0, '0', '0', 0, 561.85064697265625, -73.1480712890625, 37.9557952880859375, 4.886923789978027343, 0, 0, -0.64278697967529296, 0.766044974327087402, 7200, 255, 1, 51536), -- Chair (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+77, 179437, 30, 2597, 0, '0', '0', 0, 618.7481689453125, -52.1125755310058593, 42.11217880249023437, 6.213373661041259765, 0, 0, -0.03489875793457031, 0.999390840530395507, 7200, 255, 1, 51536), -- Wanted: ORCS! (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+78, 178684, 30, 2597, 0, '0', '0', 0, 649.263916015625, -59.1111106872558593, 41.54756927490234375, 3.595378875732421875, 0, 0, -0.97437000274658203, 0.224951311945915222, 7200, 255, 1, 51536), -- Forge (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+79, 178685, 30, 2597, 0, '0', '0', 0, 646.20660400390625, -57.2430572509765625, 41.65867996215820312, 6.12610626220703125, 0, 0, -0.07845878601074218, 0.996917366981506347, 7200, 255, 1, 51536), -- Anvil (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+80, 178785, 30, 2597, 0, '0', '0', 0, 837.11700439453125, -452.555877685546875, 47.23311233520507812, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 7200, 255, 1, 51536), -- Irondeep Supplies (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+81, 178785, 30, 2597, 0, '0', '0', 0, 854.44921875, -442.2548828125, 50.65888214111328125, 0.401424884796142578, 0, 0, 0.199367523193359375, 0.979924798011779785, 7200, 255, 1, 51536), -- Irondeep Supplies (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+82, 178785, 30, 2597, 0, '0', '0', 0, 869.7550048828125, -448.86676025390625, 52.5447540283203125, 5.427974700927734375, 0, 0, -0.41469287872314453, 0.909961462020874023, 7200, 255, 1, 51536), -- Irondeep Supplies (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+83, 178785, 30, 2597, 0, '0', '0', 0, 907.22698974609375, -323.286468505859375, 67.58397674560546875, 2.216565132141113281, 0, 0, 0.894933700561523437, 0.44619917869567871, 7200, 255, 1, 51536), -- Irondeep Supplies (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+84, 178785, 30, 2597, 0, '0', '0', 0, 886.6846923828125, -442.35797119140625, 54.69621658325195312, 5.061456203460693359, 0, 0, -0.57357597351074218, 0.819152355194091796, 7200, 255, 1, 51536), -- Irondeep Supplies (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+85, 375006, 30, 2597, 3303, '0', '0', 0, 668.12152099609375, 8.310764312744140625, 67.14469146728515625, 5.597913742065429687, 0, 0, -0.33597087860107421, 0.941872358322143554, 7200, 255, 1, 51536), -- Collision Wall (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1
(@OGUID+86, 178785, 30, 2597, 3303, '0', '0', 0, 960.8231201171875, -331.68414306640625, 62.70060348510742187, 3.874631166458129882, 0, 0, -0.93358039855957031, 0.358368009328842163, 7200, 255, 1, 51536), -- Irondeep Supplies (Area: Stormpike Graveyard - Difficulty: 0) CreateObject1
(@OGUID+87, 177262, 30, 2597, 0, '0', '0', 0, -1286.248291015625, -184.480911254882812, 71.833404541015625, 4.232425689697265625, -0.00733089447021484, -0.02995967864990234, -0.85425758361816406, 0.518934130668640136, 7200, 255, 1, 51536), -- Campfire (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+88, 177261, 30, 2597, 0, '0', '0', 0, -1290.2742919921875, -172.470489501953125, 72.18534088134765625, 3.063019752502441406, 0.008719921112060546, -0.00034236907958984, 0.999190330505371093, 0.039274781942367553, 7200, 255, 1, 51536), -- Brazier (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+89, 178784, 30, 2597, 0, '0', '0', 0, -925.86700439453125, -127.293403625488281, 61.32328414916992187, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 7200, 255, 1, 51536), -- Coldtooth Supplies (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+90, 178784, 30, 2597, 0, '0', '0', 0, -900.513916015625, -143.527236938476562, 75.96855926513671875, 1.867502212524414062, 0, 0, 0.803856849670410156, 0.594822824001312255, 7200, 255, 1, 51536), -- Coldtooth Supplies (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+91, 178784, 30, 2597, 0, '0', '0', 0, -975.855712890625, -82.5496444702148437, 80.489837646484375, 5.550147056579589843, 0, 0, -0.358367919921875, 0.933580458164215087, 7200, 255, 1, 51536), -- Coldtooth Supplies (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+92, 178784, 30, 2597, 2962, '0', '0', 0, -854.9324951171875, -85.9183502197265625, 68.60559844970703125, 4.241150379180908203, 0, 0, -0.85264015197753906, 0.522498607635498046, 7200, 255, 1, 51536), -- Coldtooth Supplies (Area: Tower Point - Difficulty: 0) CreateObject1
(@OGUID+93, 178784, 30, 2597, 2962, '0', '0', 0, -844.25, -60.0374336242675781, 72.1031036376953125, 4.084071159362792968, 0, 0, -0.8910064697265625, 0.453990638256072998, 7200, 255, 1, 51536), -- Coldtooth Supplies (Area: Tower Point - Difficulty: 0) CreateObject1
(@OGUID+94, 177425, 30, 2597, 2977, '0', '0', 0, -353.1181640625, 37.095703125, 65.89037322998046875, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 51536), -- Campfire (Area: Iceblood Garrison - Difficulty: 0) CreateObject1
(@OGUID+95, 179024, 30, 2597, 3301, '0', '0', 0, 63.27116012573242187, 5.837618827819824218, -4.09621810913085937, 2.216565132141113281, 0, 0, 0.894933700561523437, 0.44619917869567871, 7200, 255, 1, 51536), -- Stormpike Banner (Area: Snowfall Graveyard - Difficulty: 0) CreateObject1
(@OGUID+96, 180322, 30, 2597, 2597, '0', '0', 0, 794.63494873046875, -493.643280029296875, 98.60199737548828125, 3.036838293075561523, 0, 0, 0.998628616333007812, 0.052353221923112869, 7200, 255, 1, 51886), -- Ghost Gate (Area: Alterac Valley - Difficulty: 0) CreateObject1
(@OGUID+97, 180424, 30, 2597, 2597, '0', '0', 0, 794.64312744140625, -493.474517822265625, 99.77789306640625, 6.161012649536132812, 0, 0, -0.06104850769042968, 0.998134791851043701, 7200, 255, 1, 51886), -- Alterac Valley Gate (Area: Alterac Valley - Difficulty: 0) CreateObject1

-- Horde mini boss fires
(@OGUID+98, 179065, 30, 2597, 3300, '0', '0', 0, -568.03961181640625, -188.706924438476562, 81.549957275390625, 0, 0, 0, 0, 1, 7200, 255, 1, 51886), -- Roaring Flame (Area: Iceblood Graveyard - Difficulty: 0) CreateObject1
(@OGUID+99, 179065, 30, 2597, 3300, '0', '0', 0, -517.05316162109375, -200.4287109375, 80.75904083251953125, 0, 0, 0, 0, 1, 7200, 255, 1, 51886), -- Roaring Flame (Area: Iceblood Graveyard - Difficulty: 0) CreateObject1
(@OGUID+100, 179065, 30, 2597, 3300, '0', '0', 0, -509.974517822265625, -191.652023315429687, 83.29779052734375, 0, 0, 0, 0, 1, 7200, 255, 1, 51886), -- Roaring Flame (Area: Iceblood Graveyard - Difficulty: 0) CreateObject1
(@OGUID+101, 179065, 30, 2597, 3300, '0', '0', 0, -514.360595703125, -163.863983154296875, 104.16265869140625, 0, 0, 0, 0, 1, 7200, 255, 1, 51886), -- Roaring Flame (Area: Iceblood Graveyard - Difficulty: 0) CreateObject1
(@OGUID+102, 179065, 30, 2597, 3300, '0', '0', 0, -501.77484130859375, -151.580947875976562, 81.2026824951171875, 0, 0, 0, 0, 1, 7200, 255, 1, 51886), -- Roaring Flame (Area: Iceblood Graveyard - Difficulty: 0) CreateObject1

-- Alliance mini boss
(@OGUID+103, 179065, 30, 2597, 2958, '0', '0', 0, -64.2676849365234375, -289.411529541015625, 33.46895980834960937, 0, 0, 0, 0, 1, 7200, 255, 1, 52649), -- Roaring Flame (Area: Stonehearth Outpost - Difficulty: 0) CreateObject2
(@OGUID+104, 179065, 30, 2597, 2958, '0', '0', 0, -3.4092879295349121, -306.287506103515625, 33.3399505615234375, 0, 0, 0, 0, 1, 7200, 255, 1, 52649), -- Roaring Flame (Area: Stonehearth Outpost - Difficulty: 0) CreateObject2
(@OGUID+105, 179065, 30, 2597, 2958, '0', '0', 0, -62.9473762512207031, -286.21197509765625, 66.72882843017578125, 0, 0, 0, 0, 1, 7200, 255, 1, 52649), -- Roaring Flame (Area: Stonehearth Outpost - Difficulty: 0) CreateObject2
(@OGUID+106, 179065, 30, 2597, 2958, '0', '0', 0, -48.6190338134765625, -266.91650390625, 47.8167877197265625, 0, 0, 0, 0, 1, 7200, 255, 1, 52649), -- Roaring Flame (Area: Stonehearth Outpost - Difficulty: 0) CreateObject2
(@OGUID+107, 179065, 30, 2597, 2958, '0', '0', 0, -5.05132389068603515, -325.322967529296875, 38.85361480712890625, 0, 0, 0, 0, 1, 7200, 255, 1, 52649); -- Roaring Flame (Area: Stonehearth Outpost - Difficulty: 0) CreateObject2


DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+264;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+6, 0.024020733311772346, 0.005656128749251365, -0.52631276845932006, 0.849932849407196044, 0, 0), -- Anvil
(@OGUID+7, 0.024020733311772346, 0.005656128749251365, -0.52631276845932006, 0.849932849407196044, 0, 0), -- Heated Forge
(@OGUID+8, 0.024020733311772346, 0.005656128749251365, -0.52631276845932006, 0.849932849407196044, 0, 0), -- Anvil
(@OGUID+14, 0, 0, -0.0436192937195301, 0.999048233032226562, 0, 0), -- Burning Embers
(@OGUID+15, 0, 0, -0.0436192937195301, 0.999048233032226562, 0, 0), -- Burning Embers
(@OGUID+16, 0, 0, -0.0436192937195301, 0.999048233032226562, 0, 0), -- Burning Embers
(@OGUID+17, 0, 0, -0.0436192937195301, 0.999048233032226562, 0, 0), -- Burning Embers
(@OGUID+18, 0, 0, -0.0436192937195301, 0.999048233032226562, 0, 0), -- Burning Embers
(@OGUID+19, 0, 0, -0.0436192937195301, 0.999048233032226562, 0, 0), -- Burning Embers
(@OGUID+20, 0, 0, -0.0436192937195301, 0.999048233032226562, 0, 0), -- Burning Embers
(@OGUID+34, 0, 0, -0.19936791062355041, 0.979924678802490234, 0, 0), -- Chair
(@OGUID+35, 0, 0, -0.19936791062355041, 0.979924678802490234, 0, 0), -- Anvil
(@OGUID+36, 0, 0, -0.19936791062355041, 0.979924678802490234, 0, 0), -- Anvil
(@OGUID+37, 0, 0, -0.19936791062355041, 0.979924678802490234, 0, 0), -- Anvil
(@OGUID+38, 0, 0, -0.19936791062355041, 0.979924678802490234, 0, 0), -- Anvil
(@OGUID+39, 0, 0, -0.19936791062355041, 0.979924678802490234, 0, 0), -- Anvil
(@OGUID+40, 0, 0, -0.19936791062355041, 0.979924678802490234, 0, 0), -- Anvil
(@OGUID+41, 0, 0, -0.19936791062355041, 0.979924678802490234, 0, 0), -- Anvil
(@OGUID+42, 0, 0, -0.19936791062355041, 0.979924678802490234, 0, 0), -- Chair
(@OGUID+43, 0, 0, -0.19936791062355041, 0.979924678802490234, 0, 0), -- Chair
(@OGUID+44, 0, 0, -0.19936791062355041, 0.979924678802490234, 0, 0), -- Chair
(@OGUID+45, 0, 0, -0.19936791062355041, 0.979924678802490234, 0, 0), -- Chair
(@OGUID+46, 0, 0, -0.19936791062355041, 0.979924678802490234, 0, 0), -- Chair
(@OGUID+47, 0, 0, -0.19936791062355041, 0.979924678802490234, 0, 0), -- Chair
(@OGUID+48, 0, 0, 0.925540506839752197, 0.378648579120635986, 0, 0), -- Anvil
(@OGUID+49, 0, 0, 0.925540506839752197, 0.378648579120635986, 0, 0), -- Forge
(@OGUID+50, 0, 0, 0.925540506839752197, 0.378648579120635986, 0, 0), -- Anvil
(@OGUID+51, 0, 0, 0.925540506839752197, 0.378648579120635986, 0, 0), -- Anvil
(@OGUID+52, 0, 0, 0.925540506839752197, 0.378648579120635986, 0, 0), -- Anvil
(@OGUID+53, 0, 0, 0.841039061546325683, 0.540974378585815429, 0, 0), -- Wooden Chair
(@OGUID+54, 0, 0, 0.841039061546325683, 0.540974378585815429, 0, 0), -- Wooden Chair
(@OGUID+55, 0, 0, 0.841039061546325683, 0.540974378585815429, 0, 0), -- Dwarven Fire
(@OGUID+63, 0, 0, 0.216439634561538696, 0.976296007633209228, 0, 0), -- Chair
(@OGUID+64, 0, 0, 0.216439634561538696, 0.976296007633209228, 0, 0), -- Anvil
(@OGUID+65, 0, 0, 0.216439634561538696, 0.976296007633209228, 0, 0), -- Anvil
(@OGUID+66, 0, 0, 0.216439634561538696, 0.976296007633209228, 0, 0), -- Anvil
(@OGUID+67, 0, 0, 0.216439634561538696, 0.976296007633209228, 0, 0), -- Anvil
(@OGUID+68, 0, 0, 0.216439634561538696, 0.976296007633209228, 0, 0), -- Anvil
(@OGUID+69, 0, 0, 0.216439634561538696, 0.976296007633209228, 0, 0), -- Anvil
(@OGUID+70, 0, 0, 0.216439634561538696, 0.976296007633209228, 0, 0), -- Anvil
(@OGUID+71, 0, 0, 0.216439634561538696, 0.976296007633209228, 0, 0), -- Chair
(@OGUID+72, 0, 0, 0.216439634561538696, 0.976296007633209228, 0, 0), -- Chair
(@OGUID+73, 0, 0, 0.216439634561538696, 0.976296007633209228, 0, 0), -- Chair
(@OGUID+74, 0, 0, 0.216439634561538696, 0.976296007633209228, 0, 0), -- Chair
(@OGUID+75, 0, 0, 0.216439634561538696, 0.976296007633209228, 0, 0), -- Chair
(@OGUID+76, 0, 0, 0.216439634561538696, 0.976296007633209228, 0, 0); -- Chair

DELETE FROM `gameobject` WHERE `guid` IN (11765, 11766, 15388, 15389, 15390, 15391, 15392, 15393, 15394);
DELETE FROM `gameobject_addon` WHERE `guid` IN (11765, 11766, 15388, 15389, 15390, 15391, 15392, 15393, 15394);

DELETE FROM `creature_template_addon` WHERE `entry` IN (14465 /*14465 (Alliance Battle Standard) - Battle Standard*/, 12097 /*12097 (Frostwolf Quartermaster)*/, 12122 /*12122 (Duros)*/, 12121 /*12121 (Drakan)*/, 14772 /*14772 (East Frostwolf Warmaster) - East Frostwolf Warmaster*/, 14777 /*14777 (West Frostwolf Warmaster) - West Frostwolf Warmaster*/, 14776 /*14776 (Tower Point Warmaster) - Tower Point Warmaster*/, 14773 /*14773 (Iceblood Warmaster) - Iceblood Warmaster*/, 14764 /*14764 (Icewing Marshal) - Icewing Marshal*/, 14763 /*14763 (Dun Baldar South Marshal) - Dun Baldar South Marshal*/, 14762 /*14762 (Dun Baldar North Marshal) - Dun Baldar North Marshal*/, 14765 /*14765 (Stonehearth Marshal) - Stonehearth Marshal*/, 13617 /*13617 (Stormpike Stable Master)*/, 5139 /*5139 (Kurdrum Barleybeard)*/, 13442 /*13442 (Archdruid Renferal)*/, 13443 /*13443 (Druid of the Grove)*/, 5135 /*5135 (Svalbrad Farmountain)*/, 4257 /*4257 (Lana Thunderbrew)*/, 13257 /*13257 (Murgot Deepforge)*/, 12096 /*12096 (Stormpike Quartermaster)*/, 14188 /*14188 (Dirk Swindle)*/, 14187 /*14187 (Athramanis)*/, 5134 /*5134 (Jonivera Farmountain)*/, 4255 /*4255 (Brogus Thunderbrew)*/, 13447 /*13447 (Corporal Noreg Stormpike) - Revenge Trigger*/, 13181 /*13181 (Wing Commander Mulverick)*/, 13216 /*13216 (Gaelden Hammersmith)*/, 13797 /*13797 (Mountaineer Boombellow)*/, 13319 /*13319 (Commander Duffy) - Invisibility and Stealth Detection*/, 13180 /*13180 (Wing Commander Jeztor)*/, 13179 /*13179 (Wing Commander Guse)*/, 13320 /*13320 (Commander Karl Philips) - Invisibility and Stealth Detection*/, 14283 /*14283 (Stormpike Owl) - Invisibility and Stealth Detection*/, 12127 /*12127 (Stormpike Guardsman)*/, 12050 /*12050 (Stormpike Defender) - Revenge Trigger*/, 11949 /*11949 (Captain Balinda Stonehearth)*/, 13139 /*13139 (Commander Randolph) - Invisibility and Stealth Detection*/, 11947 /*11947 (Captain Galvangar)*/, 13140 /*13140 (Commander Dardosh) - Invisibility and Stealth Detection*/, 13438 /*13438 (Wing Commander Slidore)*/, 13154 /*13154 (Commander Louis Philips) - Invisibility and Stealth Detection*/, 11605 /*11605 (Whitewhisker Overseer) - Haste Aura*/, 10367 /*10367 (Shrye Ragefist)*/, 10364 /*10364 (Yaelika Farclaw)*/, 13448 /*13448 (Sergeant Yazra Bloodsnarl)*/, 13218 /*13218 (Grunnda Wolfheart)*/, 3625 /*3625 (Rarck)*/, 13176 /*13176 (Smith Regzar)*/, 3343 /*3343 (Grelkor)*/, 2225 /*2225 (Zora Guthrek)*/, 13798 /*13798 (Jotek)*/, 14186 /*14186 (Ravak Grimtotem)*/, 14185 /*14185 (Najak Hexxen)*/, 13439 /*13439 (Wing Commander Vipore)*/, 13153 /*13153 (Commander Mulfort) - Invisibility and Stealth Detection*/, 165189 /*165189 (Generic Hunter Pet)*/, 1863 /*1863 (Succubus) - Override Command Demon, Preparation, Avoidance*/, 11948 /*11948 (Vanndar Stormpike) - Unit Frame*/, 11946 /*11946 (Drek'Thar) - Unit Frame*/, 13236 /*13236 (Primalist Thurloga)*/, 174170 /*174170 (Maw Haunt) - Levitate, Scourge Haunt Visual, Face Player and give GUID*/, 11998 /*11998 (Frostwolf Herald)*/, 154474 /*154474 (Primalist Thurloga)*/, 154473 /*154473 (Voggah Deathgrip)*/, 13616 /*13616 (Frostwolf Stable Master)*/, 12051 /*12051 (Frostwolf Legionnaire)*/, 13284 /*13284 (Frostwolf Shaman)*/, 14282 /*14282 (Frost Wolf Bloodhound) - Invisibility and Stealth Detection*/, 12053 /*12053 (Frostwolf Guardian) - Revenge Trigger*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(14465, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '23033'), -- 14465 (Alliance Battle Standard) - Battle Standard
(12097, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 12097 (Frostwolf Quartermaster)
(12122, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 12122 (Duros)
(12121, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 12121 (Drakan)
(14772, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '45826'), -- 14772 (East Frostwolf Warmaster) - East Frostwolf Warmaster
(14777, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '45824'), -- 14777 (West Frostwolf Warmaster) - West Frostwolf Warmaster
(14776, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '45823'), -- 14776 (Tower Point Warmaster) - Tower Point Warmaster
(14773, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '45822'), -- 14773 (Iceblood Warmaster) - Iceblood Warmaster
(14764, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '45831'), -- 14764 (Icewing Marshal) - Icewing Marshal
(14763, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '45829'), -- 14763 (Dun Baldar South Marshal) - Dun Baldar South Marshal
(14762, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '45828'), -- 14762 (Dun Baldar North Marshal) - Dun Baldar North Marshal
(14765, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '45830'), -- 14765 (Stonehearth Marshal) - Stonehearth Marshal
(13617, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 13617 (Stormpike Stable Master)
(5139, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 5139 (Kurdrum Barleybeard)
(13442, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 13442 (Archdruid Renferal)
(13443, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 13443 (Druid of the Grove)
(5135, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 5135 (Svalbrad Farmountain)
(4257, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 4257 (Lana Thunderbrew)
(13257, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 13257 (Murgot Deepforge)
(12096, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 12096 (Stormpike Quartermaster)
(14188, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 14188 (Dirk Swindle)
(14187, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 14187 (Athramanis)
(5134, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 5134 (Jonivera Farmountain)
(4255, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 4255 (Brogus Thunderbrew)
(13447, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '5301'), -- 13447 (Corporal Noreg Stormpike) - Revenge Trigger
(13181, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 13181 (Wing Commander Mulverick)
(13216, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 13216 (Gaelden Hammersmith)
(13797, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 13797 (Mountaineer Boombellow)
(13180, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 13180 (Wing Commander Jeztor)
(13179, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 13179 (Wing Commander Guse)
(13320, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- 13320 (Commander Karl Philips) - Invisibility and Stealth Detection
(14283, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- 14283 (Stormpike Owl) - Invisibility and Stealth Detection
(12127, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 12127 (Stormpike Guardsman)
(12050, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '5301'), -- 12050 (Stormpike Defender) - Revenge Trigger
(11949, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 11949 (Captain Balinda Stonehearth)
(13139, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- 13139 (Commander Randolph) - Invisibility and Stealth Detection
(11947, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 11947 (Captain Galvangar)
(13140, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- 13140 (Commander Dardosh) - Invisibility and Stealth Detection
(13438, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 13438 (Wing Commander Slidore)
(13154, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- 13154 (Commander Louis Philips) - Invisibility and Stealth Detection
(11605, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '13589'), -- 11605 (Whitewhisker Overseer) - Haste Aura
(10367, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 10367 (Shrye Ragefist)
(10364, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 10364 (Yaelika Farclaw)
(13448, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 13448 (Sergeant Yazra Bloodsnarl)
(13218, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 13218 (Grunnda Wolfheart)
(3625, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 3625 (Rarck)
(13176, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 13176 (Smith Regzar)
(3343, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 3343 (Grelkor)
(2225, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 2225 (Zora Guthrek)
(13798, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 13798 (Jotek)
(14186, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 14186 (Ravak Grimtotem)
(14185, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 14185 (Najak Hexxen)
(13439, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 13439 (Wing Commander Vipore)
(13153, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- 13153 (Commander Mulfort) - Invisibility and Stealth Detection
(1863, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '119904 44521 32233'), -- 1863 (Succubus) - Override Command Demon, Preparation, Avoidance
(11948, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 5, '177684'), -- 11948 (Vanndar Stormpike) - Unit Frame
(11946, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 5, '177684'), -- 11946 (Drek'Thar) - Unit Frame
(13236, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 13236 (Primalist Thurloga)
(11998, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 11998 (Frostwolf Herald)
(13616, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 13616 (Frostwolf Stable Master)
(12051, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 12051 (Frostwolf Legionnaire)
(13284, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 13284 (Frostwolf Shaman)
(14282, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '18950'), -- 14282 (Frost Wolf Bloodhound) - Invisibility and Stealth Detection
(12053, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '5301'); -- 12053 (Frostwolf Guardian) - Revenge Trigger

-- UPDATE `creature_template_addon` SET `SheathState`=1, `PvpFlags`=1 WHERE `entry`=13577; -- 13577 (Stormpike Ram Rider Commander)
-- UPDATE `creature_template_addon` SET `SheathState`=1, `PvpFlags`=1 WHERE `entry`=13318; -- 13318 (Commander Mortimer)
-- UPDATE `creature_template_addon` SET `SheathState`=1, `PvpFlags`=1 WHERE `entry`=13358; -- 13358 (Stormpike Bowman)
-- UPDATE `creature_template_addon` SET `SheathState`=1, `PvpFlags`=1, `auras`='18950' WHERE `entry`=13152; -- 13152 (Commander Malgor) - Invisibility and Stealth Detection
-- UPDATE `creature_template_addon` SET `SheathState`=1, `PvpFlags`=1 WHERE `entry`=13359; -- 13359 (Frostwolf Bowman)
-- UPDATE `creature_template_addon` SET `SheathState`=1, `PvpFlags`=1 WHERE `entry`=13441; -- 13441 (Frostwolf Wolf Rider Commander)

UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=-5, `VerifiedBuild`=52649 WHERE (`Entry`=13096 AND `DifficultyID`=0); -- Coldmine Explorer
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-8, `LevelScalingDeltaMax`=-7, `ContentTuningID`=663, `VerifiedBuild`=52649 WHERE (`Entry`=13317 AND `DifficultyID`=0); -- Coldmine Miner
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-6, `LevelScalingDeltaMax`=-5, `ContentTuningID`=663, `VerifiedBuild`=52649 WHERE (`Entry`=13087 AND `DifficultyID`=0); -- Coldmine Invader
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-2, `LevelScalingDeltaMax`=-2, `ContentTuningID`=663, `VerifiedBuild`=52649 WHERE (`Entry`=13086 AND `DifficultyID`=0); -- Aggi Rumblestomp
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-8, `LevelScalingDeltaMax`=-7, `ContentTuningID`=663, `VerifiedBuild`=52649 WHERE (`Entry`=13316 AND `DifficultyID`=0); -- Coldmine Peon
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-2, `LevelScalingDeltaMax`=-2, `ContentTuningID`=663, `VerifiedBuild`=52649 WHERE (`Entry`=13088 AND `DifficultyID`=0); -- Masha Swiftcut
UPDATE `creature_template_difficulty` SET `ContentTuningID`=982, `VerifiedBuild`=52649 WHERE (`Entry`=14751 AND `DifficultyID`=0); -- Frostwolf Battle Standard
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-6, `LevelScalingDeltaMax`=-5, `ContentTuningID`=663, `VerifiedBuild`=52649 WHERE (`Entry`=13089 AND `DifficultyID`=0); -- Coldmine Guard
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-6, `LevelScalingDeltaMax`=-5, `ContentTuningID`=663, `VerifiedBuild`=52649 WHERE (`Entry`=13097 AND `DifficultyID`=0); -- Coldmine Surveyor
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-2, `LevelScalingDeltaMax`=-2, `ContentTuningID`=663, `VerifiedBuild`=52649 WHERE (`Entry`=13078 AND `DifficultyID`=0); -- Umi Thorson
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-6, `LevelScalingDeltaMax`=-5, `ContentTuningID`=663, `VerifiedBuild`=52649 WHERE (`Entry`=13080 AND `DifficultyID`=0); -- Irondeep Guard
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-8, `LevelScalingDeltaMax`=-7, `ContentTuningID`=663, `VerifiedBuild`=52649 WHERE (`Entry`=13396 AND `DifficultyID`=0); -- Irondeep Miner
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-6, `LevelScalingDeltaMax`=-5, `ContentTuningID`=663, `VerifiedBuild`=52649 WHERE (`Entry`=13098 AND `DifficultyID`=0); -- Irondeep Surveyor
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=-5, `VerifiedBuild`=52649 WHERE (`Entry`=13099 AND `DifficultyID`=0); -- Irondeep Explorer
UPDATE `creature_template_difficulty` SET `ContentTuningID`=663, `VerifiedBuild`=52649 WHERE (`Entry`=11997 AND `DifficultyID`=0); -- Stormpike Herald
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-2, `LevelScalingDeltaMax`=-2, `ContentTuningID`=663, `VerifiedBuild`=52649 WHERE (`Entry`=13447 AND `DifficultyID`=0); -- Corporal Noreg Stormpike
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `VerifiedBuild`=52649 WHERE (`Entry`=13797 AND `DifficultyID`=0); -- Mountaineer Boombellow
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=-7, `VerifiedBuild`=52649 WHERE (`Entry`=10986 AND `DifficultyID`=0); -- Snowblind Harpy
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-7, `VerifiedBuild`=52649 WHERE (`Entry`=11604 AND `DifficultyID`=0); -- Whitewhisker Geomancer
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-8, `VerifiedBuild`=52649 WHERE (`Entry`=10982 AND `DifficultyID`=0); -- Whitewhisker Vermin
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-4, `LevelScalingDeltaMax`=-4, `VerifiedBuild`=52649 WHERE (`Entry`=13448 AND `DifficultyID`=0); -- Sergeant Yazra Bloodsnarl
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-2, `VerifiedBuild`=52649 WHERE (`Entry`=11840 AND `DifficultyID`=0); -- Wildpaw Alpha
UPDATE `creature_template_difficulty` SET `ContentTuningID`=982, `VerifiedBuild`=51972 WHERE (`Entry`=14465 AND `DifficultyID`=0); -- Alliance Battle Standard
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `VerifiedBuild`=51972 WHERE (`Entry`=13798 AND `DifficultyID`=0); -- Jotek
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-2, `LevelScalingDeltaMax`=-2, `ContentTuningID`=663, `VerifiedBuild`=51972 WHERE (`Entry`=11677 AND `DifficultyID`=0); -- Taskmaster Snivvle
UPDATE `creature_template_difficulty` SET `ContentTuningID`=663, `VerifiedBuild`=51972 WHERE (`Entry`=11997 AND `DifficultyID`=0); -- Stormpike Herald
