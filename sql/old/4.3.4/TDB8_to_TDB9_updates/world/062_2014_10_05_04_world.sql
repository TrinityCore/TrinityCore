SET @CGUID :=74960;
SET @OGUID :=21104;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0 , 24545, 530, 1, 1, -1882.759, 5575.42, -12.3448, 4.677482, 120, 0, 0), -- Thunderbrew "Apprentice" (Area: Shattrath City)
(@CGUID+1 , 24484, 530, 1, 1, -1872.835, 5560.321, -12.3448, 2.748216, 120, 0, 0), -- Brewfest Reveler (Area: Shattrath City) (Auras: 43910 - Brewfest Reveler - Gnome)
(@CGUID+2 , 24484, 530, 1, 1, -1878.838, 5562.812, -12.3448, 5.889809, 120, 0, 0), -- Brewfest Reveler (Area: Shattrath City) (Auras: 43909 - Brewfest Reveler - Dwarf)
(@CGUID+3 , 24484, 530, 1, 1, -1878.618, 5556.088, -12.3448, 3.259485, 120, 0, 0), -- Brewfest Reveler (Area: Shattrath City) (Auras: 43910 - Brewfest Reveler - Gnome)
(@CGUID+4 , 24484, 530, 1, 1, -1897.398, 5558.127, -12.3448, 1.710423, 120, 0, 0), -- Brewfest Reveler (Area: Shattrath City) (Auras: 44004 - Brewfest Reveler - Goblin - Female)
(@CGUID+5 , 24484, 530, 1, 1, -1899.819, 5560.333, -12.3448, 0.3665192, 120, 0, 0), -- Brewfest Reveler (Area: Shattrath City) (Auras: 44003 - Brewfest Reveler - Goblin - Male)
(@CGUID+6 , 24484, 530, 1, 1, -1921.889, 5554.328, -12.34481, 0.04066804, 120, 0, 0), -- Brewfest Reveler (Area: Shattrath City) (Auras: 43916 - Brewfest Reveler - Troll)
(@CGUID+7 , 24484, 530, 1, 1, -1916.578, 5551.592, -12.34481, 2.666002, 120, 0, 0), -- Brewfest Reveler (Area: Shattrath City) (Auras: 43917 - Brewfest Reveler - Undead)
(@CGUID+8 , 24484, 530, 1, 1, -1924.595, 5549.645, -12.3448, 1.046868, 120, 0, 0), -- Brewfest Reveler (Area: Shattrath City) (Auras: 43914 - Brewfest Reveler - Orc)
(@CGUID+9 , 24484, 530, 1, 1, -1897.494, 5562.316, -12.3448, 4.433136, 120, 0, 0), -- Brewfest Reveler (Area: Shattrath City) (Auras: 44003 - Brewfest Reveler - Goblin - Male)
(@CGUID+10, 24501, 530, 1, 1, -1926.787, 5562.968, -12.3448, 5.061455, 120, 0, 0), -- Drohn's Distillery Apprentice (Area: Shattrath City)
(@CGUID+11, 24484, 530, 1, 1, -1895.234, 5560.195, -12.34481, 2.80998, 120, 0, 0), -- Brewfest Reveler (Area: Shattrath City) (Auras: 44003 - Brewfest Reveler - Goblin - Male)
(@CGUID+12, 23511, 530, 1, 1, -1906.297, 5569.852, -12.3448, 4.974188, 120, 0, 0); -- Gordok Brew Apprentice (Area: Shattrath City)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `creature_addon` (`guid`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(@CGUID+1 , 0, 0x0, 0x101, '43910'), -- Brewfest Reveler - 43910 - Brewfest Reveler - Gnome
(@CGUID+2 , 0, 0x0, 0x101, '43909'), -- Brewfest Reveler - 43909 - Brewfest Reveler - Dwarf
(@CGUID+3 , 0, 0x0, 0x101, '43910'), -- Brewfest Reveler - 43910 - Brewfest Reveler - Gnome
(@CGUID+4 , 0, 0x0, 0x101, '44004'), -- Brewfest Reveler - 44004 - Brewfest Reveler - Goblin - Female
(@CGUID+5 , 0, 0x0, 0x101, '44003'), -- Brewfest Reveler - 44003 - Brewfest Reveler - Goblin - Male
(@CGUID+6 , 0, 0x0, 0x101, '43916'), -- Brewfest Reveler - 43916 - Brewfest Reveler - Troll
(@CGUID+7 , 0, 0x0, 0x101, '43917'), -- Brewfest Reveler - 43917 - Brewfest Reveler - Undead
(@CGUID+8 , 0, 0x0, 0x101, '43914'), -- Brewfest Reveler - 43914 - Brewfest Reveler - Orc
(@CGUID+9 , 0, 0x0, 0x101, '44003'), -- Brewfest Reveler - 44003 - Brewfest Reveler - Goblin - Male
(@CGUID+11, 0, 0x0, 0x101, '44003'); -- Brewfest Reveler - 44003 - Brewfest Reveler - Goblin - Male

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+8;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 186259, 530, 1, 1, -1875.389, 5579.114, -12.42814, 1.605702, 0, 0, 0, 1, 120, 255, 1), -- Thunderbrew Festive Wagon (Area: Shattrath City)
(@OGUID+1, 180037, 530, 1, 1, -1909.218, 5569.716, -12.42814, 4.97419, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Shattrath City)
(@OGUID+2, 180037, 530, 1, 1, -1906.963, 5573.009, -12.42814, 3.47321, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Shattrath City)
(@OGUID+3, 178666, 530, 1, 1, -1882.575, 5582.089, -12.42814, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Gypsy Wagon (Area: Shattrath City)
(@OGUID+4, 178666, 530, 1, 1, -1928.171, 5567.508, -12.42814, 3.38594, 0, 0, 0, 1, 120, 255, 1), -- Gypsy Wagon (Area: Shattrath City)
(@OGUID+5, 186255, 530, 1, 1, -1920.9, 5568.442, -12.42814, 1.884953, 0, 0, 0, 1, 120, 255, 1), -- Drohn's Distillery Festive Wagon (Area: Shattrath City)
(@OGUID+6, 186257, 530, 1, 1, -1900.552, 5575.883, -12.42814, 1.937312, 0, 0, 0, 1, 120, 255, 1), -- Gordok Festive Wagon (Area: Shattrath City)
(@OGUID+7, 180037, 530, 1, 1, -1893.456, 5576.866, -12.42814, 4.223697, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Shattrath City)
(@OGUID+8, 180037, 530, 1, 1, -1904.326, 5571.048, -12.42814, 1.902409, 0, 0, 0, 1, 120, 255, 1); -- Haybail 01 (Area: Shattrath City)

DELETE FROM `game_event_creature` WHERE `eventEntry`=24 AND `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(24, @CGUID+0),
(24, @CGUID+1),
(24, @CGUID+2),
(24, @CGUID+3),
(24, @CGUID+4),
(24, @CGUID+5),
(24, @CGUID+6),
(24, @CGUID+7),
(24, @CGUID+8),
(24, @CGUID+9),
(24, @CGUID+10),
(24, @CGUID+11),
(24, @CGUID+12);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=24 AND `guid` BETWEEN @OGUID+0 AND @OGUID+8;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(24, @OGUID+0),
(24, @OGUID+1),
(24, @OGUID+2),
(24, @OGUID+3),
(24, @OGUID+4),
(24, @OGUID+5),
(24, @OGUID+6),
(24, @OGUID+7),
(24, @OGUID+8);
