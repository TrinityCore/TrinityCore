-- 
DELETE FROM `player_classlevelstats` WHERE (`class`=13 AND `level` BETWEEN 61 AND 70);
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `sta`, `inte`, `VerifiedBuild`) VALUES
(13, 61, 294, 457, 739, 672, 47187), -- DracthyrAlliance Evoker 
(13, 62, 335, 520, 889, 766, 47187), -- DracthyrAlliance Evoker 
(13, 63, 382, 593, 1066, 872, 47187), -- DracthyrAlliance Evoker 
(13, 64, 435, 675, 1276, 994, 47187), -- DracthyrAlliance Evoker 
(13, 65, 496, 769, 1524, 1132, 47187), -- DracthyrAlliance Evoker 
(13, 66, 565, 876, 1815, 1289, 47213), -- DracthyrAlliance Evoker 
(13, 67, 644, 998, 2159, 1468, 47213), -- DracthyrAlliance Evoker 
(13, 68, 734, 1137, 2562, 1673, 47213), -- DracthyrAlliance Evoker 
(13, 69, 837, 1295, 3036, 1905, 47213), -- DracthyrAlliance Evoker 
(13, 70, 918, 1422, 3461, 2091, 47213); -- DracthyrAlliance Evoker 
