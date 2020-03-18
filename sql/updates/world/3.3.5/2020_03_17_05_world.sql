-- 
-- Creature Formations - Trashmobs
-- Blackwing Lair

-- first room after Vaelastrasz
-- Pack one
DELETE FROM `creature_formations` WHERE `memberGUID` IN (84555,84549,84553,84552,84545,84546);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(84555, 84555, 0, 0, 3, 0, 0),
(84555, 84549, 0, 0, 3, 0, 0),
(84555, 84553, 0, 0, 3, 0, 0),
(84555, 84552, 0, 0, 3, 0, 0),
(84555, 84545, 0, 0, 3, 0, 0),
(84555, 84546, 0, 0, 3, 0, 0);

-- Pack two
DELETE FROM `creature_formations` WHERE `memberGUID` IN (84554,84544,84547,84551,84548,84550);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(84554, 84554, 0, 0, 3, 0, 0),
(84554, 84544, 0, 0, 3, 0, 0),
(84554, 84547, 0, 0, 3, 0, 0),
(84554, 84551, 0, 0, 3, 0, 0),
(84554, 84548, 0, 0, 3, 0, 0),
(84554, 84550, 0, 0, 3, 0, 0);

-- Firemaws patrol area, right after broodlord
-- Linking the 2 small packs at the entrance
DELETE FROM `creature_formations` WHERE `memberGUID` IN (128890,85759,85760,85758,128888,85625,84537,85757);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(128890, 128890, 0, 0, 3, 0, 0),
(128890, 85759, 0, 0, 3, 0, 0),
(128890, 85760, 0, 0, 3, 0, 0),
(128890, 85758, 0, 0, 3, 0, 0),
(128890, 128888, 0, 0, 3, 0, 0),
(128890, 85625, 0, 0, 3, 0, 0),
(128890, 84537, 0, 0, 3, 0, 0),
(128890, 85757, 0, 0, 3, 0, 0);

-- Pack at the right wall after the entrance
DELETE FROM `creature_formations` WHERE `memberGUID` IN (84539,128896,128891,85777,85776,85775,85773,85772,85768,85767,128892,85766,85764);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(84539, 84539, 0, 0, 3, 0, 0),
(84539, 128896, 0, 0, 3, 0, 0),
(84539, 128891, 0, 0, 3, 0, 0),
(84539, 85777, 0, 0, 3, 0, 0),
(84539, 85776, 0, 0, 3, 0, 0),
(84539, 85775, 0, 0, 3, 0, 0),
(84539, 85773, 0, 0, 3, 0, 0),
(84539, 85772, 0, 0, 3, 0, 0),
(84539, 85768, 0, 0, 3, 0, 0),
(84539, 85767, 0, 0, 3, 0, 0),
(84539, 128892, 0, 0, 3, 0, 0),
(84539, 85766, 0, 0, 3, 0, 0),
(84539, 85764, 0, 0, 3, 0, 0);

-- Pack on the small bay to the left
DELETE FROM `creature_formations` WHERE `memberGUID` IN (84543,128902,128897,128900,85798,85778,85779,85788,85793,85797,85794,85796,85795,85799);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(84543, 84543, 0, 0, 3, 0, 0),
(84543, 128902, 0, 0, 3, 0, 0),
(84543, 128897, 0, 0, 3, 0, 0),
(84543, 128900, 0, 0, 3, 0, 0),
(84543, 85798, 0, 0, 3, 0, 0),
(84543, 85778, 0, 0, 3, 0, 0),
(84543, 85779, 0, 0, 3, 0, 0),
(84543, 85788, 0, 0, 3, 0, 0),
(84543, 85793, 0, 0, 3, 0, 0),
(84543, 85797, 0, 0, 3, 0, 0),
(84543, 85794, 0, 0, 3, 0, 0),
(84543, 85796, 0, 0, 3, 0, 0),
(84543, 85795, 0, 0, 3, 0, 0),
(84543, 85799, 0, 0, 3, 0, 0);

-- Pack on ramps in Firemaws patrol area
DELETE FROM `creature_formations` WHERE `memberGUID` IN (84535,84521,61997,84520,84635,84639,84618,84619,84623,84624,84625,84628,84617,84634);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(84535, 84535, 0, 0, 3, 0, 0),
(84535, 84521, 0, 0, 3, 0, 0),
(84535, 61997, 0, 0, 3, 0, 0),
(84535, 84520, 0, 0, 3, 0, 0),
(84535, 84635, 0, 0, 3, 0, 0),
(84535, 84639, 0, 0, 3, 0, 0),
(84535, 84618, 0, 0, 3, 0, 0),
(84535, 84619, 0, 0, 3, 0, 0),
(84535, 84623, 0, 0, 3, 0, 0),
(84535, 84624, 0, 0, 3, 0, 0),
(84535, 84625, 0, 0, 3, 0, 0),
(84535, 84628, 0, 0, 3, 0, 0),
(84535, 84617, 0, 0, 3, 0, 0),
(84535, 84634, 0, 0, 3, 0, 0);

-- Pack right after ramps in second level of Firemaws patrol area
DELETE FROM `creature_formations` WHERE `memberGUID` IN (84536,61998,84523,84522,84650,84691,84648,84651,84652,84688,84689,84653,84654,84655);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(84536, 84536, 0, 0, 3, 0, 0),
(84536, 61998, 0, 0, 3, 0, 0),
(84536, 84523, 0, 0, 3, 0, 0),
(84536, 84522, 0, 0, 3, 0, 0),
(84536, 84650, 0, 0, 3, 0, 0),
(84536, 84691, 0, 0, 3, 0, 0),
(84536, 84648, 0, 0, 3, 0, 0),
(84536, 84651, 0, 0, 3, 0, 0),
(84536, 84652, 0, 0, 3, 0, 0),
(84536, 84688, 0, 0, 3, 0, 0),
(84536, 84689, 0, 0, 3, 0, 0),
(84536, 84653, 0, 0, 3, 0, 0),
(84536, 84654, 0, 0, 3, 0, 0),
(84536, 84655, 0, 0, 3, 0, 0);

-- Pack to the left wall in second level of Firemaws patrol area
DELETE FROM `creature_formations` WHERE `memberGUID` IN (84537,84524,61999,67032,84525,84759,84692,84761,85601,84763,85581,84760,84762,84840);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(84537, 84537, 0, 0, 3, 0, 0),
(84537, 84524, 0, 0, 3, 0, 0),
(84537, 61999, 0, 0, 3, 0, 0),
(84537, 67032, 0, 0, 3, 0, 0),
(84537, 84525, 0, 0, 3, 0, 0),
(84537, 84759, 0, 0, 3, 0, 0),
(84537, 84692, 0, 0, 3, 0, 0),
(84537, 84761, 0, 0, 3, 0, 0),
(84537, 85601, 0, 0, 3, 0, 0),
(84537, 84763, 0, 0, 3, 0, 0),
(84537, 85581, 0, 0, 3, 0, 0),
(84537, 84760, 0, 0, 3, 0, 0),
(84537, 84762, 0, 0, 3, 0, 0),
(84537, 84840, 0, 0, 3, 0, 0);

-- Pack to the right wall in second level of Firemaws patrol area
DELETE FROM `creature_formations` WHERE `memberGUID` IN (84538,84527,84389,84390,84526,85611,85616,85622,85612,85609,85620,85613,85621,85623);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(84538, 84538, 0, 0, 3, 0, 0),
(84538, 84527, 0, 0, 3, 0, 0),
(84538, 84389, 0, 0, 3, 0, 0),
(84538, 84390, 0, 0, 3, 0, 0),
(84538, 84526, 0, 0, 3, 0, 0),
(84538, 85611, 0, 0, 3, 0, 0),
(84538, 85616, 0, 0, 3, 0, 0),
(84538, 85622, 0, 0, 3, 0, 0),
(84538, 85612, 0, 0, 3, 0, 0),
(84538, 85609, 0, 0, 3, 0, 0),
(84538, 85620, 0, 0, 3, 0, 0),
(84538, 85613, 0, 0, 3, 0, 0),
(84538, 85621, 0, 0, 3, 0, 0),
(84538, 85623, 0, 0, 3, 0, 0);

-- Pack at the gates to Chromaggus
DELETE FROM `creature_formations` WHERE `memberGUID` IN (84534,84532,84533);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(84534, 84534, 0, 0, 3, 0, 0),
(84534, 84532, 0, 0, 3, 0, 0),
(84534, 84533, 0, 0, 3, 0, 0);
