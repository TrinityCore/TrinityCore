DELETE FROM `player_classlevelstats` WHERE `class`=12 AND `level`<8;
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `sta`, `inte`) VALUES
(12,1,14,15,11,8),
(12,2,16,17,12,9),
(12,3,17,18,12,10),
(12,4,17,19,13,10),
(12,5,17,19,13,10),
(12,6,17,19,13,10),
(12,7,19,20,14,11);
