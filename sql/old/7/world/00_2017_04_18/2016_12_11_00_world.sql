-- add missing teleport locations with coordinates to game_tele
DELETE FROM `game_tele` WHERE `id` IN (1575,1576,1577,1578,1579,1580,1581,1582,1583);
INSERT INTO `game_tele` (`id`,`position_x`,`position_y`,`position_z`,`orientation`,`map`,`name`) VALUES
(1575, -828.835, 4371.91, 738.636, 1.88158,   1220, "DalaranCity"),  -- Dalaran, Krasus' Landing [Legion]
(1576, 1182.7,   3282.56,   69.99, 0.08,      1481, "Mardum"),       -- Mardum, The Shattered Abyss [Demon Hunter Start Zone]
(1577, -218.95,  5600.9,  61.1105, 3.32418,   1220, "Azsuna"),       -- Azsuna, Eye of Azshara
(1578, 2795.81,  7279.47, 21.6704, 4.75753,   1220, "Val'Sharah"),   -- Val'Sharah, Bradensbrook
(1579, 4492.69,  4836.35, 661.706, 1.37009,   1220, "Highmountain"), -- Highmountain, Nesingwary's Retreat
(1580, 3854.78,  2020.04, 242.638, 3.2904,    1220, "Stormheim"),    -- Stormheim, Stormtorn Foothills
(1581, 1708.83,  4637.75, 124.004, 5.25153,   1220, "Suramar"),      -- Suramar, Shal'Aran Sanctuary
(1582, -1306.66, 1741.4,  7.32331, 0.0914592, 1220, "BrokenShore"),  -- BrokenShore
(1583, -3400,    4827.46, 27.829,  3.56,      1220, "EyeAzshara");   -- Azsuna, Eye of Azshara
--
