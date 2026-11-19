UPDATE `creature_queststarter` SET `VerifiedBuild`=42010 WHERE (`id`=37783 AND `quest` IN (24676,24575,24904)) OR (`id`=38143 AND `quest`=24675) OR (`id`=37803 AND `quest`=24674) OR (`id`=37876 AND `quest`=24677) OR (`id`=37874 AND `quest`=24592) OR (`id`=37102 AND `quest` IN (24672,24501,24484)) OR (`id`=37195 AND `quest` IN (24673,24593,24646,24627)) OR (`id`=37873 AND `quest`=24628) OR (`id`=36451 AND `quest` IN (14395,14397)) OR (`id`=36290 AND `quest` IN (14396,14386,14382,14369)) OR (`id`=36291 AND `quest`=14368) OR (`id`=34571 AND `quest` IN (14367,14336)) OR (`id`=36140 AND `quest` IN (14366,14348,14347)) OR (`id`=36205 AND `quest`=14321) OR (`id`=36132 AND `quest`=14320) OR (`id`=36170 AND `quest`=14313) OR (`id`=35566 AND `quest`=14222) OR (`id`=35618 AND `quest` IN (14221,14218)) OR (`id`=38144 AND `quest` IN (24602,24680,24679)) OR (`id`=38539 AND `quest` IN (24678,24920)) OR (`id`=38611 AND `quest` IN (24903,24902)) OR (`id`=37822 AND `quest` IN (24617,24616)) OR (`id`=37815 AND `quest` IN (24578,24495)) OR (`id`=37065 AND `quest` IN (24483,24472,24468)) OR (`id`=36743 AND `quest`=24438) OR (`id`=36606 AND `quest`=14466) OR (`id`=36452 AND `quest` IN (14465,14406,14403,14398)) OR (`id`=36456 AND `quest` IN (14405,14412,14404)) OR (`id`=36458 AND `quest` IN (14401,14400,14399)) OR (`id`=36457 AND `quest`=14416) OR (`id`=35552 AND `quest`=14212) OR (`id`=35906 AND `quest`=14294) OR (`id`=35550 AND `quest`=14293) OR (`id`=35378 AND `quest` IN (14214,14204)) OR (`id`=35112 AND `quest` IN (14159,14157)) OR (`id`=35077 AND `quest` IN (26129,14154)) OR (`id`=50371 AND `quest`=28850) OR (`id`=35115 AND `quest`=24930) OR (`id`=35873 AND `quest`=14291) OR (`id`=35840 AND `quest`=14280) OR (`id`=34913 AND `quest` IN (14099,14098,14093)) OR (`id`=34936 AND `quest`=14094) OR (`id`=34863 AND `quest`=14091) OR (`id`=34850 AND `quest`=14078) OR (`id`=43727 AND `quest`=26706) OR (`id`=38149 AND `quest`=24681);

UPDATE `creature_questender` SET `VerifiedBuild`=42010 WHERE (`id`=37783 AND `quest` IN (24676,24575,24677)) OR (`id`=37803 AND `quest`=24674) OR (`id`=38143 AND `quest`=24675) OR (`id`=37876 AND `quest`=24592) OR (`id`=37874 AND `quest`=24672) OR (`id`=37102 AND `quest` IN (24673,24501,24484,24483)) OR (`id`=37195 AND `quest` IN (24593,24646,24627,24617)) OR (`id`=37873 AND `quest`=24628) OR (`id`=36451 AND `quest` IN (14395,14396)) OR (`id`=36290 AND `quest` IN (14386,14382,14369,14367)) OR (`id`=36291 AND `quest`=14368) OR (`id`=34571 AND `quest` IN (14366,14321)) OR (`id`=36140 AND `quest` IN (14348,14347,14336)) OR (`id`=36132 AND `quest`=14313) OR (`id`=36332 AND `quest`=14375) OR (`id`=35566 AND `quest` IN (14222,14221)) OR (`id`=35618 AND `quest` IN (14218,14212)) OR (`id`=38144 AND `quest` IN (24602,24678,24679)) OR (`id`=38539 AND `quest` IN (24920,24903)) OR (`id`=38611 AND `quest` IN (24902,24904)) OR (`id`=37822 AND `quest` IN (24616,24578)) OR (`id`=37815 AND `quest`=24495) OR (`id`=37065 AND `quest` IN (24472,24468,24438)) OR (`id`=36743 AND `quest` IN (14467,14466)) OR (`id`=36606 AND `quest`=14465) OR (`id`=36452 AND `quest` IN (14405,14397)) OR (`id`=36456 AND `quest` IN (14412,14404,14403)) OR (`id`=36458 AND `quest` IN (14401,14400,14399,14398)) OR (`id`=36457 AND `quest` IN (14416,14406)) OR (`id`=35911 AND `quest`=14294) OR (`id`=35906 AND `quest`=14293) OR (`id`=35550 AND `quest`=14214) OR (`id`=35378 AND `quest`=14204) OR (`id`=35369 AND `quest`=14159) OR (`id`=35112 AND `quest` IN (26129,14291)) OR (`id`=35115 AND `quest`=24930) OR (`id`=35077 AND `quest` IN (14154,28850)) OR (`id`=50371 AND `quest`=14157) OR (`id`=35873 AND `quest`=14280) OR (`id`=35840 AND `quest`=14099) OR (`id`=34913 AND `quest` IN (14098,14093,14091)) OR (`id`=34936 AND `quest`=14094) OR (`id`=34863 AND `quest`=14078) OR (`id`=36616 AND `quest`=14434) OR (`id`=43727 AND `quest`=26706) OR (`id`=38149 AND `quest` IN (24681,24680));

UPDATE `gameobject_questender` SET `VerifiedBuild`=42010 WHERE (`id`=196394 AND `quest`=14320);

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (35911,44455,44464,44465,35552,44427,35551,35554,44461,44459,44470,44468,44469,35915,35914,50420,35916,50471,50474,35753,35907,35631,35906,35378,38844,35505,35504,35370,35463,35509,35550,37953,36454,36455,36491,36456,36492,36528,37822,36457,37802,35836,36452,50570,36451,36653,36693,43558,37815,38792,37102,37499,36409,36405,35457,35124,35081,35077,35123,37806,37807,37808,37805,36294,43713,416,43567,38765,35369,50371,35115,35112,35871,35232,35912,38832,35874,35872,35873,35839,35870,35869,47091,35233,35840,43767,43764,35118,43651,43703,43793,43791,42141,43566,35660,36882,37067,37078,43751,36293,35167,38762,35170,34981,35188,35456,43336,43337,43718,34916,34913,34936,34884,37927,36397,36312,36743,36288,36290,36291,36690,36289,36287,36962,36742,36606,44460,44928,37946,43907,38853,38755,43338,51409,36138,36399,36396,36741,37785,36236,37921,37938,37939,36231,36292,36140,36283,34511,36211,37916,38365,38366,38389,38364,38287,38363,38344,38540,36207,37735,38615,44388,36488,43747,37914,43749,38783,43727,50274,38149,50271,50275,50273,38982,37733,36458,36461,38537,38533,38530,37718,38764,37876,37875,37716,38780,37874,38618,38617,38616,36810,38507,38539,39016,39017,38614,39015,38613,38611,38474,36616,39660,38470,51146,50902,50893,50881,51083,38473,38469,36555,38766,38767,38768,35166,35164,36459,36540,36512,35905,38415,44105,38331,38027,38348,38029,38424,38426,38051,38425,36809,36332,38464,36330,38210,36779,38192,36331,41561,36671,38377,41015,35627,35011,44426,34863,34850,39095,35830,35010,35006,38022,37786,34867,38218,38221,34864,44086,38553,44463,38795,38798,37803,51947,37783,38143,38799,38794,38793,42853,38796,34851,37784,38797,37757,35566,36205,35317,35618,44429,36057,36814,37870,37873,37195,42953,37489,37197,37492,37685,51589,37045,51277,38881,35231,35230,36813,37065,37694,37701,37686,37692,38150,38144,37892,38781,37885,37884,37891,37889,36460,36440,36170,36190,36200,36798,68993,36797,50252,34571,50247,50574,38791,50567,36449,35374,36453,36632,36630,36631,36628,36629,36652,36651,36198,36713,44125,36286,50260,36602,36698,36695,36132,36717,35229));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(35911, 0, 0, 0, 78, 42010),
(44455, 0, 0, 0, 78, 42010),
(44464, 0, 0, 0, 78, 42010),
(44465, 0, 0, 0, 78, 42010),
(35552, 0, 0, 0, 78, 42010),
(44427, 0, 0, 0, 78, 42010),
(35551, 0, 0, 0, 78, 42010),
(35554, 0, 0, 0, 78, 42010),
(44461, 0, 0, 0, 78, 42010),
(44459, 0, 0, 0, 78, 42010),
(44470, 0, 0, 0, 78, 42010),
(44468, 0, 0, 0, 78, 42010),
(44469, 0, 0, 0, 78, 42010),
(35915, 0, 0, 0, 78, 42010),
(35914, 0, 0, 0, 78, 42010),
(50420, 0, 0, 0, 78, 42010),
(35916, 0, 0, 0, 78, 42010),
(50471, 0, 0, 0, 78, 42010),
(50474, 0, 0, 0, 78, 42010),
(35753, 0, 0, 0, 78, 42010),
(35907, 0, 0, 0, 78, 42010),
(35631, 0, 0, 0, 78, 42010),
(35906, 0, 0, 0, 78, 42010),
(35378, 0, 0, 0, 78, 42010),
(38844, 0, 0, 0, 78, 42010),
(35505, 0, 0, 0, 78, 42010),
(35504, 0, 0, 0, 78, 42010),
(35370, 0, 0, 0, 78, 42010),
(35463, 0, 0, 0, 78, 42010),
(35509, 0, 0, 0, 78, 42010),
(35550, 0, 0, 0, 78, 42010),
(37953, 0, 0, 0, 78, 42010),
(36454, 0, 0, 0, 78, 42010),
(36455, 0, 0, 0, 78, 42010),
(36491, 0, 0, 0, 78, 42010),
(36456, 0, 0, 0, 78, 42010),
(36492, 0, 0, 0, 78, 42010),
(36528, 0, 0, 0, 78, 42010),
(37822, 0, 0, 0, 78, 42010),
(36457, 0, 0, 0, 78, 42010),
(37802, 0, 0, 0, 78, 42010),
(35836, 0, 0, 0, 78, 42010),
(36452, 0, 0, 0, 78, 42010),
(50570, 0, 0, 0, 78, 42010),
(36451, 0, 0, 0, 78, 42010),
(36653, 0, 0, 0, 78, 42010),
(36693, 0, 0, 0, 78, 42010),
(43558, 0, 0, 0, 78, 42010),
(37815, 0, 0, 0, 78, 42010),
(38792, 0, 0, 0, 78, 42010),
(37102, 0, 0, 0, 78, 42010),
(37499, 0, 0, 0, 78, 42010),
(36409, 0, 0, 0, 78, 42010),
(36405, 0, 0, 0, 78, 42010),
(35457, 0, 0, 0, 78, 42010),
(35124, 0, 0, 0, 78, 42010),
(35081, 0, 0, 0, 78, 42010),
(35077, 0, 0, 0, 78, 42010),
(35123, 0, 0, 0, 78, 42010),
(37806, 0, 0, 0, 78, 42010),
(37807, 0, 0, 0, 78, 42010),
(37808, 0, 0, 0, 78, 42010),
(37805, 0, 0, 0, 78, 42010),
(36294, 0, 0, 0, 78, 42010),
(43713, 0, 0, 0, 78, 42010),
(416, 0, 0, 0, 482, 42010),
(43567, 0, 0, 0, 78, 42010),
(38765, 0, 0, 0, 78, 42010),
(35369, 0, 0, 0, 78, 42010),
(50371, 0, 0, 0, 78, 42010),
(35115, 0, 0, 0, 78, 42010),
(35112, 0, 0, 0, 78, 42010),
(35871, 0, 0, 0, 78, 42010),
(35232, 0, 0, 0, 78, 42010),
(35912, 0, 0, 0, 78, 42010),
(38832, 0, 0, 0, 78, 42010),
(35874, 0, 0, 0, 78, 42010),
(35872, 0, 0, 0, 78, 42010),
(35873, 0, 0, 0, 78, 42010),
(35839, 0, 0, 0, 78, 42010),
(35870, 0, 0, 0, 78, 42010),
(35869, 0, 0, 0, 78, 42010),
(47091, 0, 0, 0, 78, 42010),
(35233, 0, 0, 0, 78, 42010),
(35840, 0, 0, 0, 78, 42010),
(43767, 0, 0, 0, 78, 42010),
(43764, 0, 0, 0, 78, 42010),
(35118, 0, 0, 0, 78, 42010),
(43651, 0, 0, 0, 78, 42010),
(43703, 0, 0, 0, 78, 42010),
(43793, 0, 0, 0, 78, 42010),
(43791, 0, 0, 0, 78, 42010),
(42141, 0, 0, 0, 78, 42010),
(43566, 0, 0, 0, 78, 42010),
(35660, 0, 0, 0, 78, 42010),
(36882, 0, 0, 0, 78, 42010),
(37067, 0, 0, 0, 78, 42010),
(37078, 0, 0, 0, 78, 42010),
(43751, 0, 0, 0, 78, 42010),
(36293, 0, 0, 0, 78, 42010),
(35167, 0, 0, 0, 78, 42010),
(38762, 0, 0, 0, 78, 42010),
(35170, 0, 0, 0, 78, 42010),
(34981, 0, 0, 0, 78, 42010),
(35188, 0, 0, 0, 78, 42010),
(35456, 0, 0, 0, 78, 42010),
(43336, 0, 0, 0, 78, 42010),
(43337, 0, 0, 0, 78, 42010),
(43718, 0, 0, 0, 328, 42010),
(34916, 0, 0, 0, 78, 42010),
(34913, 0, 0, 0, 78, 42010),
(34936, 0, 0, 0, 78, 42010),
(34884, 0, 0, 0, 78, 42010),
(37927, 0, 0, 0, 78, 42010),
(36397, 0, 0, 0, 78, 42010),
(36312, 0, 0, 0, 78, 42010),
(36743, 0, 0, 0, 78, 42010),
(36288, 0, -4, -4, 1723, 42010),
(36290, 0, 0, 0, 78, 42010),
(36291, 0, 0, 0, 78, 42010),
(36690, 0, 0, 0, 78, 42010),
(36289, 0, -4, -4, 1723, 42010),
(36287, 0, 0, 0, 78, 42010),
(36962, 0, 0, 0, 78, 42010),
(36742, 0, 0, 0, 78, 42010),
(36606, 0, 0, 0, 78, 42010),
(44460, 0, 0, 0, 78, 42010),
(44928, 0, 0, 0, 78, 42010),
(37946, 0, 0, 0, 78, 42010),
(43907, 0, 0, 0, 78, 42010),
(38853, 0, 0, 0, 78, 42010),
(38755, 0, 0, 0, 78, 42010),
(43338, 0, 0, 0, 78, 42010),
(51409, 0, 0, 0, 78, 42010),
(36138, 0, 0, 0, 78, 42010),
(36399, 0, 0, 0, 78, 42010),
(36396, 0, 0, 0, 78, 42010),
(36741, 0, 0, 0, 78, 42010),
(37785, 0, 0, 0, 78, 42010),
(36236, 0, 0, 0, 78, 42010),
(37921, 0, 0, 0, 78, 42010),
(37938, 0, 0, 0, 78, 42010),
(37939, 0, 0, 0, 78, 42010),
(36231, 0, 0, 0, 78, 42010),
(36292, 0, 0, 0, 78, 42010),
(36140, 0, 0, 0, 78, 42010),
(36283, 0, 0, 0, 78, 42010),
(34511, 0, 0, 0, 78, 42010),
(36211, 0, 0, 0, 78, 42010),
(37916, 0, 0, 0, 78, 42010),
(38365, 0, 0, 0, 78, 42010),
(38366, 0, 0, 0, 78, 42010),
(38389, 0, 0, 0, 78, 42010),
(38364, 0, 0, 0, 78, 42010),
(38287, 0, 0, 0, 78, 42010),
(38363, 0, 0, 0, 78, 42010),
(38344, 0, 0, 0, 78, 42010),
(38540, 0, 0, 0, 78, 42010),
(36207, 0, 0, 0, 78, 42010),
(37735, 0, 0, 0, 78, 42010),
(38615, 0, 0, 0, 78, 42010),
(44388, 0, 0, 0, 78, 42010),
(36488, 0, 0, 0, 78, 42010),
(43747, 0, 0, 0, 78, 42010),
(37914, 0, 0, 0, 78, 42010),
(43749, 0, 0, 0, 78, 42010),
(38783, 0, 0, 0, 78, 42010),
(43727, 0, 0, 0, 78, 42010),
(50274, 0, -4, -4, 1723, 42010),
(38149, 0, 0, 0, 78, 42010),
(50271, 0, 0, 0, 78, 42010),
(50275, 0, -4, -4, 1723, 42010),
(50273, 0, 0, 0, 78, 42010),
(38982, 0, 0, 0, 78, 42010),
(37733, 0, 0, 0, 78, 42010),
(36458, 0, 0, 0, 78, 42010),
(36461, 0, 0, 0, 78, 42010),
(38537, 0, 0, 0, 78, 42010),
(38533, 0, 0, 0, 78, 42010),
(38530, 0, 0, 0, 78, 42010),
(37718, 0, 0, 0, 78, 42010),
(38764, 0, 0, 0, 78, 42010),
(37876, 0, 0, 0, 78, 42010),
(37875, 0, 0, 0, 78, 42010),
(37716, 0, 0, 0, 78, 42010),
(38780, 0, 0, 0, 78, 42010),
(37874, 0, 0, 0, 78, 42010),
(38618, 0, 0, 0, 78, 42010),
(38617, 0, 0, 0, 78, 42010),
(38616, 0, 0, 0, 78, 42010),
(36810, 0, 0, 0, 78, 42010),
(38507, 0, 0, 0, 78, 42010),
(38539, 0, 0, 0, 78, 42010),
(39016, 0, 0, 0, 78, 42010),
(39017, 0, 0, 0, 78, 42010),
(38614, 0, 0, 0, 78, 42010),
(39015, 0, 0, 0, 78, 42010),
(38613, 0, 0, 0, 78, 42010),
(38611, 0, 0, 0, 78, 42010),
(38474, 0, 0, 0, 78, 42010),
(36616, 0, 0, 0, 78, 42010),
(39660, 0, 0, 0, 328, 42010),
(38470, 0, 0, 0, 78, 42010),
(51146, 0, 0, 0, 78, 42010),
(50902, 0, 0, 0, 78, 42010),
(50893, 0, 0, 0, 78, 42010),
(50881, 0, 0, 0, 78, 42010),
(51083, 0, 0, 0, 78, 42010),
(38473, 0, 0, 0, 78, 42010),
(38469, 0, 0, 0, 78, 42010),
(36555, 0, 0, 0, 78, 42010),
(38766, 0, 0, 0, 78, 42010),
(38767, 0, 0, 0, 78, 42010),
(38768, 0, 0, 0, 78, 42010),
(35166, 0, 0, 0, 78, 42010),
(35164, 0, 0, 0, 78, 42010),
(36459, 0, 0, 0, 78, 42010),
(36540, 0, 0, 0, 78, 42010),
(36512, 0, 0, 0, 78, 42010),
(35905, 0, 0, 0, 78, 42010),
(38415, 0, 0, 0, 78, 42010),
(44105, 0, 0, 0, 78, 42010),
(38331, 0, 0, 0, 78, 42010),
(38027, 0, 0, 0, 78, 42010),
(38348, 0, 0, 0, 78, 42010),
(38029, 0, 0, 0, 78, 42010),
(38424, 0, 0, 0, 78, 42010),
(38426, 0, 0, 0, 78, 42010),
(38051, 0, 0, 0, 78, 42010),
(38425, 0, 0, 0, 78, 42010),
(36809, 0, 0, 0, 78, 42010),
(36332, 0, 0, 0, 78, 42010),
(38464, 0, 0, 0, 78, 42010),
(36330, 0, 0, 0, 78, 42010),
(38210, 0, 0, 0, 78, 42010),
(36779, 0, 0, 0, 78, 42010),
(38192, 0, 0, 0, 78, 42010),
(36331, 0, 0, 0, 78, 42010),
(41561, 0, 0, 0, 78, 42010),
(36671, 0, 0, 0, 78, 42010),
(38377, 0, 0, 0, 78, 42010),
(41015, 0, 0, 0, 78, 42010),
(35627, 0, 0, 0, 78, 42010),
(35011, 0, 0, 0, 78, 42010),
(44426, 0, 0, 0, 81, 42010),
(34863, 0, 0, 0, 78, 42010),
(34850, 0, 0, 0, 78, 42010),
(39095, 0, 0, 0, 78, 42010),
(35830, 0, 0, 0, 78, 42010),
(35010, 0, 0, 0, 78, 42010);

INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(35006, 0, 0, 0, 78, 42010),
(38022, 0, 0, 0, 78, 42010),
(37786, 0, 0, 0, 78, 42010),
(34867, 0, 0, 0, 78, 42010),
(38218, 0, 0, 0, 78, 42010),
(38221, 0, 0, 0, 78, 42010),
(34864, 0, 0, 0, 78, 42010),
(44086, 0, 0, 0, 78, 42010),
(38553, 0, 0, 0, 78, 42010),
(44463, 0, 0, 0, 78, 42010),
(38795, 0, 0, 0, 78, 42010),
(38798, 0, 0, 0, 78, 42010),
(37803, 0, 0, 0, 78, 42010),
(51947, 0, 0, 0, 425, 42010),
(37783, 0, 0, 0, 78, 42010),
(38143, 0, 0, 0, 78, 42010),
(38799, 0, 0, 0, 78, 42010),
(38794, 0, 0, 0, 78, 42010),
(38793, 0, 0, 0, 78, 42010),
(42853, 0, 0, 0, 78, 42010),
(38796, 0, 0, 0, 78, 42010),
(34851, 0, 0, 0, 78, 42010),
(37784, 0, 0, 0, 78, 42010),
(38797, 0, 0, 0, 78, 42010),
(37757, 0, 0, 0, 78, 42010),
(35566, 0, 0, 0, 78, 42010),
(36205, 0, 0, 0, 78, 42010),
(35317, 0, 0, 0, 78, 42010),
(35618, 0, 0, 0, 78, 42010),
(44429, 0, 0, 0, 78, 42010),
(36057, 0, 0, 0, 78, 42010),
(36814, 0, 0, 0, 78, 42010),
(37870, 0, 0, 0, 78, 42010),
(37873, 0, 0, 0, 78, 42010),
(37195, 0, 0, 0, 78, 42010),
(42953, 0, 0, 0, 78, 42010),
(37489, 0, 0, 0, 78, 42010),
(37197, 0, 0, 0, 78, 42010),
(37492, 0, 0, 0, 78, 42010),
(37685, 0, 0, 0, 78, 42010),
(51589, 0, 0, 0, 78, 42010),
(37045, 0, 0, 0, 78, 42010),
(51277, 0, 0, 0, 78, 42010),
(38881, 0, 0, 0, 78, 42010),
(35231, 0, 0, 0, 78, 42010),
(35230, 0, 0, 0, 78, 42010),
(36813, 0, 0, 0, 78, 42010),
(37065, 0, 0, 0, 78, 42010),
(37694, 0, 0, 0, 78, 42010),
(37701, 0, 0, 0, 78, 42010),
(37686, 0, 0, 0, 78, 42010),
(37692, 0, 0, 0, 78, 42010),
(38150, 0, 0, 0, 78, 42010),
(38144, 0, 0, 0, 78, 42010),
(37892, 0, 0, 0, 78, 42010),
(38781, 0, 0, 0, 78, 42010),
(37885, 0, 0, 0, 78, 42010),
(37884, 0, 0, 0, 78, 42010),
(37891, 0, 0, 0, 78, 42010),
(37889, 0, 0, 0, 78, 42010),
(36460, 0, 0, 0, 78, 42010),
(36440, 0, 0, 0, 78, 42010),
(36170, 0, 0, 0, 78, 42010),
(36190, 0, 0, 0, 78, 42010),
(36200, 0, 0, 0, 78, 42010),
(36798, 0, 0, 0, 78, 42010),
(68993, 0, 0, 0, 78, 42010),
(36797, 0, 0, 0, 78, 42010),
(50252, 0, 0, 0, 78, 42010),
(34571, 0, 0, 0, 78, 42010),
(50247, 0, 0, 0, 78, 42010),
(50574, 0, 0, 0, 78, 42010),
(38791, 0, 0, 0, 78, 42010),
(50567, 0, 0, 0, 78, 42010),
(36449, 0, 0, 0, 78, 42010),
(35374, 0, 0, 0, 328, 42010),
(36453, 0, 0, 0, 78, 42010),
(36632, 0, 0, 0, 78, 42010),
(36630, 0, 0, 0, 78, 42010),
(36631, 0, 0, 0, 78, 42010),
(36628, 0, 0, 0, 78, 42010),
(36629, 0, 0, 0, 78, 42010),
(36652, 0, 0, 0, 78, 42010),
(36651, 0, 0, 0, 78, 42010),
(36198, 0, 0, 0, 328, 42010),
(36713, 0, 0, 0, 78, 42010),
(44125, 0, 0, 0, 78, 42010),
(36286, 0, 0, 0, 328, 42010),
(50260, 0, 0, 0, 81, 42010),
(36602, 0, 0, 0, 78, 42010),
(36698, 0, 0, 0, 78, 42010),
(36695, 0, 0, 0, 78, 42010),
(36132, 0, 0, 0, 78, 42010),
(36717, 0, 0, 0, 78, 42010),
(35229, 0, 0, 0, 78, 42010);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=42010 WHERE (`Entry`=36714 AND `DifficultyID`=0);

UPDATE `creature_trainer` SET `TrainerID`=877 WHERE (`CreatureID`=50574 AND `MenuID`=5855 AND `OptionID`=0);

DELETE FROM `gossip_menu` WHERE (`MenuID`=10838 AND `TextID`=14845) OR (`MenuID`=11061 AND `TextID`=15377) OR (`MenuID`=11672 AND `TextID`=16330) OR (`MenuID`=12676 AND `TextID`=17819) OR (`MenuID`=12693 AND `TextID`=17830) OR (`MenuID`=27383 AND `TextID`=43674) OR (`MenuID`=11833 AND `TextID`=16592) OR (`MenuID`=11070 AND `TextID`=15395);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(10838, 14845, 42010), -- 38795 (Sister Almyra)
(11061, 15377, 42010), -- 38553 (Krennan Aranas)
(11672, 16330, 42010), -- 42953 (Benjamin Sykes)
(12676, 17819, 42010), -- 35566 (Lord Darius Crowley)
(12693, 17830, 42010), -- 38611 (Lorna Crowley)
(27383, 43674, 42010), -- 44459 (Celestine of the Harvest)
(11833, 16592, 42010), -- 35550 (King Genn Greymane)
(11070, 15395, 42010); -- 34936 (Gwen Armstead)

UPDATE `gossip_menu` SET `VerifiedBuild`=42010 WHERE (`TextID`=15029 AND `MenuID`=14175) OR (`TextID`=14841 AND `MenuID` IN (10837,10698)) OR (`TextID`=14836 AND `MenuID`=14290) OR (`TextID`=14832 AND `MenuID`=14176) OR (`TextID`=14843 AND `MenuID` IN (10843,10699)) OR (`TextID`=15034 AND `MenuID`=10841) OR (`TextID`=14848 AND `MenuID`=14177) OR (`TextID`=15408 AND `MenuID`=11079) OR (`TextID`=14986 AND `MenuID`=10809) OR (`TextID`=15025 AND `MenuID`=10833) OR (`TextID`=15013 AND `MenuID`=10827) OR (`TextID`=14938 AND `MenuID`=10773) OR (`TextID`=16542 AND `MenuID`=11794) OR (`TextID`=16543 AND `MenuID`=11795) OR (`TextID`=15035 AND `MenuID`=10842) OR (`TextID`=16586 AND `MenuID`=14204) OR (`TextID`=14845 AND `MenuID`=10700) OR (`TextID`=14798 AND `MenuID`=10676) OR (`TextID`=14786 AND `MenuID`=10669) OR (`TextID`=17749 AND `MenuID`=12609);

UPDATE `gameobject_template` SET `Data26`=1, `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=201775; -- Ball and Chain
UPDATE `gameobject_template` SET `VerifiedBuild`=42010 WHERE `entry` IN (204423, 195454, 195453, 195465, 195466, 205009, 205005, 196400, 195581, 195580, 195579, 195430, 196401, 196412, 202644, 202643, 202634, 202633, 202632, 202629, 202628, 202627, 202626, 202630, 202631, 196394, 196849, 196854, 196880, 196399, 196879, 196846, 196404, 204986, 206693, 204419, 201891, 197338, 202625, 202624, 202646, 202645, 202642, 202641, 202640, 202639, 202638, 202637, 202636, 202635, 196864, 196863, 202191, 195621, 202692, 202688, 202687, 202691, 202682, 202671, 202683, 202672, 202670, 202684, 202669, 202685, 202680, 202679, 202678, 202675, 202674, 202668, 202677, 202673, 202686, 202681, 202676, 202666, 205044, 205012, 205011, 205013, 205024, 205022, 205021, 202696, 202695, 202694, 207330, 207093, 202591, 204428, 203428, 202319);
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27739, `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=201607; -- Old Journal Page
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=27788, `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=201939; -- Worn Coffer
UPDATE `gameobject_template` SET `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=201951; -- Well of Tranquility
UPDATE `gameobject_template` SET `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=201950; -- Well of Fury
UPDATE `gameobject_template` SET `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=201952; -- Well of Balance
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27783, `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=201914; -- Moonleaf
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=27605, `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=196810; -- Shipwright's Tools
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=27604, `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=196809; -- Planks of Wood
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=27603, `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=196808; -- Barrel of Coal Tar
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data4`=1, `Data5`=1, `Data13`=1, `Data30`=27592, `Data31`=1, `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=196473; -- Linen-Wrapped Book
UPDATE `gameobject_template` SET `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=197333; -- Gilneas - Drowning Sparkles
UPDATE `gameobject_template` SET `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry` IN (196466, 196465); -- Dustfall
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=42010 WHERE `entry`=196411; -- Basement Door
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27574, `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=196403; -- Black Gunpowder Keg
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27591, `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=196472; -- Grandma's Good Clothes
UPDATE `gameobject_template` SET `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=197337; -- Gilneas Invasion Camera
UPDATE `gameobject_template` SET `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=207417; -- Crow Scatter Trap
UPDATE `gameobject_template` SET `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=201964; -- Aderic's Tomb
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27777, `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=201871; -- Disturbed Soil
UPDATE `gameobject_template` SET `Data26`=1, `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=201775; -- Ball and Chain
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27783, `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=201914; -- Moonleaf
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27739, `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=201607; -- Old Journal Page
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=27732, `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=201594; -- Koroth's Banner
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=27605, `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=196810; -- Shipwright's Tools
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=27604, `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=196809; -- Planks of Wood
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=27603, `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=196808; -- Barrel of Coal Tar
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data4`=1, `Data5`=1, `Data13`=1, `Data30`=27592, `Data31`=1, `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=196473; -- Linen-Wrapped Book
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27591, `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=196472; -- Grandma's Good Clothes
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=42010 WHERE `entry`=196411; -- Basement Door
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27307, `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=195306; -- Supply Crate
UPDATE `gameobject_template` SET `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=195327; -- Merchant Square Door
UPDATE `gameobject_template` SET `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=204458; -- Incendiary Explosives
UPDATE `gameobject_template` SET `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=207999; -- Liam's Coffin Lid [INTERNAL]
UPDATE `gameobject_template` SET `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=207626; -- Liam's Coffin [INTERNAL]
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=42010 WHERE `entry`=195578; -- 195578
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27777, `ContentTuningId`=78, `VerifiedBuild`=42010 WHERE `entry`=201871; -- Disturbed Soil

UPDATE `gameobject_questitem` SET `VerifiedBuild`=42010 WHERE (`Idx`=0 AND `GameObjectEntry` IN (201607,201939,201914,196810,196809,196808,196473,196403,196472,201871,201594,195306));

DELETE FROM `creature_queststarter` WHERE (`id`=49748 AND `quest`=46727);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(49748, 46727, 42614); -- Tides of War offered Hero's Herald

UPDATE `creature_queststarter` SET `VerifiedBuild`=42614 WHERE (`id`=32979 AND `quest`=13560) OR (`id`=32971 AND `quest` IN (13589,13562,13522)) OR (`id`=33048 AND `quest` IN (13599,13569,13566,13598)) OR (`id`=33126 AND `quest`=13565) OR (`id`=32932 AND `quest`=13523) OR (`id`=33177 AND `quest`=13561) OR (`id`=32959 AND `quest`=13563) OR (`id`=32960 AND `quest`=13564) OR (`id`=32978 AND `quest`=13529) OR (`id`=32977 AND `quest` IN (13528,13521)) OR (`id`=32972 AND `quest`=13520) OR (`id`=63083 AND `quest`=31584) OR (`id`=32973 AND `quest`=13518) OR (`id`=48736 AND `quest`=26385) OR (`id`=54334 AND `quest`=7905) OR (`id`=42968 AND `quest`=28517);

UPDATE `creature_questender` SET `VerifiedBuild`=42614 WHERE (`id`=32972 AND `quest` IN (13599,13520)) OR (`id`=32959 AND `quest`=13563) OR (`id`=32971 AND `quest` IN (13562,13522)) OR (`id`=33048 AND `quest` IN (13569,13566,13598,13564)) OR (`id`=33133 AND `quest`=13567) OR (`id`=33126 AND `quest`=13565) OR (`id`=32932 AND `quest`=13523) OR (`id`=33177 AND `quest`=13561) OR (`id`=32977 AND `quest` IN (13554,13527)) OR (`id`=32978 AND `quest` IN (13831,13557,13529)) OR (`id`=32973 AND `quest` IN (13518,26385)) OR (`id`=48736 AND `quest`=28517);

UPDATE `gameobject_queststarter` SET `VerifiedBuild`=42614 WHERE (`id`=194714 AND `quest`=13831) OR (`id`=194122 AND `quest`=13554) OR (`id`=194105 AND `quest`=13527);

UPDATE `gameobject_questender` SET `VerifiedBuild`=42614 WHERE (`id`=194122 AND `quest`=13528) OR (`id`=194105 AND `quest`=13521);

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (175564,3843,70453,33133,33132,33131,34009,32937,34051,90203,7560,33980,33020,33981,2191,48738,48737,32962,48736,163897,33100,33103,33095,33099,33101,32911,33096,33098,33097,33094,33102,33093));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(175564, 0, 0, 0, 371, 42614),
(3843, 0, 0, 0, 5, 42614),
(70453, 0, 0, 0, 371, 42614),
(33133, 0, 0, 0, 5, 42614),
(33132, 0, 0, 0, 5, 42614),
(33131, 0, 0, 0, 5, 42614),
(34009, 0, 0, 0, 5, 42614),
(32937, 0, 0, 0, 5, 42614),
(34051, 0, 0, 0, 5, 42614),
(90203, 0, 0, 0, 371, 42614),
(7560, 0, 0, 0, 371, 42614),
(33980, 0, 0, 0, 5, 42614),
(33020, 0, 0, 0, 5, 42614),
(33981, 0, 0, 0, 5, 42614),
(2191, 0, 0, 0, 5, 42614),
(48738, 0, 3, 3, 876, 42614),
(48737, 0, 0, 0, 876, 42614),
(32962, 0, 0, 0, 5, 42614),
(48736, 0, 3, 3, 876, 42614),
(163897, 0, 0, 0, 371, 42614),
(33100, 0, 0, 0, 5, 42614),
(33103, 0, 0, 0, 5, 42614),
(33095, 0, 0, 0, 5, 42614),
(33099, 0, 0, 0, 5, 42614),
(33101, 0, 0, 0, 5, 42614),
(32911, 0, 0, 0, 5, 42614),
(33096, 0, 0, 0, 5, 42614),
(33098, 0, 0, 0, 5, 42614),
(33097, 0, 0, 0, 5, 42614),
(33094, 0, 0, 0, 5, 42614),
(33102, 0, 0, 0, 5, 42614),
(33093, 0, 0, 0, 5, 42614);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=42614 WHERE (`DifficultyID`=0 AND `Entry` IN (33997,33022,33024,33023,33021));

UPDATE `trainer` SET `VerifiedBuild`=42614 WHERE `Id`=580;

DELETE FROM `creature_trainer` WHERE (`CreatureID`=43429 AND `MenuID`=8521 AND `OptionID`=0) OR (`CreatureID`=4204 AND `MenuID`=7691 AND `OptionID`=0) OR (`CreatureID`=4212 AND `MenuID`=4241 AND `OptionID`=0) OR (`CreatureID`=4213 AND `MenuID`=4163 AND `OptionID`=0);
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(43429, 37, 8521, 0),
(4204, 133, 7691, 0),
(4212, 56, 4241, 0),
(4213, 62, 4163, 0);

DELETE FROM `gossip_menu` WHERE (`TextID`=14289 AND `MenuID`=10263) OR (`TextID`=539 AND `MenuID`=14238) OR (`TextID`=5725 AND `MenuID` IN (14035,14120,14034)) OR (`TextID`=4437 AND `MenuID`=14038) OR (`TextID`=17745 AND `MenuID`=14197) OR (`TextID`=17820 AND `MenuID`=12677) OR (`TextID`=14841 AND `MenuID`=14264) OR (`TextID`=18430 AND `MenuID`=13111) OR (`TextID`=4993 AND `MenuID` IN (14040,14045)) OR (`TextID`=4782 AND `MenuID` IN (14051,14054,14052)) OR (`TextID`=31561 AND `MenuID`=20948) OR (`TextID`=31558 AND `MenuID`=20951) OR (`TextID`=31560 AND `MenuID`=20947);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(10263, 14289, 42614), -- 33101 (Allyndia)
(14238, 539, 42614), -- 49968 (Lareth Beld)
(14035, 5725, 42614), -- 4089 (Sildanair)
(14038, 4437, 42614), -- 4092 (Lariia)
(14197, 17745, 42614), -- 50715 (Maelir)
(14120, 5725, 42614), -- 7315 (Darnath Bladesinger)
(14034, 5725, 42614), -- 4087 (Arias'ta Bladesinger)
(12677, 17820, 42614), -- 48735 (Gwen Armstead)
(14264, 14841, 42614), -- 50499 (Myriam Spellwaker)
(13111, 18430, 42614), -- 55285 (Astrid Langstrump)
(14040, 4993, 42614), -- 4138 (Jeen'ra Nightrunner)
(14045, 4993, 42614), -- 4205 (Dorion)
(14051, 4782, 42614), -- 4217 (Mathrengyl Bearwalker)
(14054, 4782, 42614), -- 4219 (Fylerian Nightwing)
(14052, 4782, 42614), -- 4218 (Denatharion)
(20948, 31561, 42614), -- 4262 (Darnassus Sentinel)
(20951, 31558, 42614), -- 4262 (Darnassus Sentinel)
(20947, 31560, 42614); -- 4262 (Darnassus Sentinel)

UPDATE `gossip_menu` SET `VerifiedBuild`=42614 WHERE (`TextID`=14327 AND `MenuID`=10321) OR (`TextID`=14505 AND `MenuID`=10479) OR (`TextID`=14447 AND `MenuID`=10410) OR (`TextID`=14454 AND `MenuID` IN (10429,10427)) OR (`TextID`=14294 AND `MenuID`=10290) OR (`TextID`=14299 AND `MenuID`=10295) OR (`TextID`=14296 AND `MenuID`=10292) OR (`TextID`=14293 AND `MenuID`=10289) OR (`TextID`=14295 AND `MenuID`=10291) OR (`TextID`=14292 AND `MenuID`=10288) OR (`TextID`=14300 AND `MenuID`=10296) OR (`TextID`=14290 AND `MenuID`=10286) OR (`TextID`=14291 AND `MenuID`=10287) OR (`TextID`=14298 AND `MenuID`=10294) OR (`TextID`=14297 AND `MenuID`=10293) OR (`TextID`=824 AND `MenuID`=347) OR (`TextID`=4794 AND `MenuID`=14256) OR (`TextID`=35679 AND `MenuID`=23074) OR (`TextID`=8800 AND `MenuID`=7366) OR (`TextID`=4437 AND `MenuID` IN (14130,14037,12537)) OR (`TextID`=5873 AND `MenuID`=4821) OR (`TextID`=8785 AND `MenuID`=14158) OR (`TextID`=8584 AND `MenuID`=14147) OR (`TextID`=5477 AND `MenuID`=4305) OR (`TextID`=14673 AND `MenuID`=10606) OR (`TextID`=9073 AND `MenuID`=7487) OR (`TextID`=14832 AND `MenuID`=14172) OR (`TextID`=14839 AND `MenuID`=14174) OR (`TextID`=14848 AND `MenuID`=14173) OR (`TextID`=2314 AND `MenuID`=1661) OR (`TextID`=2313 AND `MenuID`=1662) OR (`TextID`=18269 AND `MenuID`=12992) OR (`TextID`=3016 AND `MenuID`=10265) OR (`TextID`=2154 AND `MenuID`=1481) OR (`TextID`=2153 AND `MenuID`=1482) OR (`TextID`=3044 AND `MenuID`=2358) OR (`TextID`=3042 AND `MenuID`=2356) OR (`TextID`=17965 AND `MenuID`=12776) OR (`TextID`=3040 AND `MenuID`=2354) OR (`TextID`=17968 AND `MenuID`=12779) OR (`TextID`=13886 AND `MenuID`=10015) OR (`TextID`=3037 AND `MenuID`=2348) OR (`TextID`=17966 AND `MenuID`=12777) OR (`TextID`=3337 AND `MenuID`=2347) OR (`TextID`=3035 AND `MenuID`=2344) OR (`TextID`=20036 AND `MenuID`=13866) OR (`TextID`=3022 AND `MenuID`=2343) OR (`TextID`=3033 AND `MenuID`=2342) OR (`TextID`=17835 AND `MenuID`=12704) OR (`TextID`=15906 AND `MenuID`=11422) OR (`TextID`=3026 AND `MenuID`=2341) OR (`TextID`=3025 AND `MenuID`=2329) OR (`TextID`=17831 AND `MenuID`=12700) OR (`TextID`=3023 AND `MenuID`=2327) OR (`TextID`=3024 AND `MenuID`=2328) OR (`TextID`=10217 AND `MenuID`=8221) OR (`TextID`=4517 AND `MenuID`=3722) OR (`TextID`=5980 AND `MenuID`=4921) OR (`TextID`=3021 AND `MenuID`=2326) OR (`TextID`=3020 AND `MenuID`=2325) OR (`TextID`=3019 AND `MenuID`=2324) OR (`TextID`=14254 AND `MenuID`=10266) OR (`TextID`=3017 AND `MenuID`=2322) OR (`TextID`=3833 AND `MenuID`=3101);

UPDATE `gameobject_template` SET `ContentTuningId`=5, `VerifiedBuild`=42614 WHERE `entry` IN (284572, 17183); -- Buzzbox 411
UPDATE `gameobject_template` SET `VerifiedBuild`=42614 WHERE `entry` IN (284612, 91737, 194130, 194131, 146096, 175759, 95449, 92552, 195528, 92551, 92549, 92695, 92543, 92546, 92545, 92532, 92531, 92548, 92547, 92550, 208824, 208817, 92524, 92700, 92699, 188123, 148423);
UPDATE `gameobject_template` SET `ContentTuningId`=5, `VerifiedBuild`=42614 WHERE `entry`=194714; -- Disgusting Workbench
UPDATE `gameobject_template` SET `ContentTuningId`=5, `VerifiedBuild`=42614 WHERE `entry`=194124; -- Secure Bear Cage
UPDATE `gameobject_template` SET `ContentTuningId`=5, `VerifiedBuild`=42614 WHERE `entry`=194133; -- Secure Duskrat Cage
UPDATE `gameobject_template` SET `ContentTuningId`=5, `VerifiedBuild`=42614 WHERE `entry`=194122; -- Buzzbox 723
UPDATE `gameobject_template` SET `ContentTuningId`=876, `VerifiedBuild`=42614 WHERE `entry`=19877; -- Velinde's Locker
UPDATE `gameobject_template` SET `ContentTuningId`=72, `VerifiedBuild`=42614 WHERE `entry`=138498; -- Temple of the Moon Fountain
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39756, `ContentTuningId`=876, `VerifiedBuild`=42614 WHERE `entry`=208819; -- Blessed Rice Cakes
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39756, `ContentTuningId`=876, `VerifiedBuild`=42614 WHERE `entry`=208818; -- Blessed Rice Cakes
UPDATE `gameobject_template` SET `ContentTuningId`=876, `VerifiedBuild`=42614 WHERE `entry`=207995; -- Portal to Exodar
UPDATE `gameobject_template` SET `ContentTuningId`=37, `VerifiedBuild`=42614 WHERE `entry`=195141; -- Portal to Hellfire Peninsula
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39756, `ContentTuningId`=876, `VerifiedBuild`=42614 WHERE `entry`=208819; -- Blessed Rice Cakes
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39756, `ContentTuningId`=876, `VerifiedBuild`=42614 WHERE `entry`=208818; -- Blessed Rice Cakes

UPDATE `gameobject_questitem` SET `VerifiedBuild`=42614 WHERE (`Idx`=0 AND `GameObjectEntry` IN (19877,208819,208818));

UPDATE `page_text` SET `VerifiedBuild`=42614 WHERE `ID` IN (1817, 1816, 1815, 1814, 1813, 1812, 1811, 1810, 1809, 1808, 1807, 1806, 1805, 1804, 1803, 1794, 1793, 1792, 1791, 1790, 1789, 1788, 1787, 1848, 1847, 1846, 1845, 1844);

UPDATE `creature_queststarter` SET `VerifiedBuild`=42698 WHERE (`id`=40895 AND `quest` IN (25621,25607)) OR (`id`=34354 AND `quest` IN (25616,13913,13979)) OR (`id`=39256 AND `quest` IN (25615,25614)) OR (`id`=3691 AND `quest` IN (26898,26476,13872,26480,13867)) OR (`id`=34239 AND `quest` IN (13877,13874)) OR (`id`=34251 AND `quest`=13876) OR (`id`=11711 AND `quest`=5713) OR (`id`=34402 AND `quest` IN (26408,13899,13892)) OR (`id`=34422 AND `quest`=13897) OR (`id`=34423 AND `quest`=13900) OR (`id`=34403 AND `quest`=13898) OR (`id`=34498 AND `quest`=13953) OR (`id`=33072 AND `quest`=13895) OR (`id`=34340 AND `quest` IN (13910,13909,13907,13893)) OR (`id`=34342 AND `quest` IN (13918,13912)) OR (`id`=34343 AND `quest`=13911) OR (`id`=34301 AND `quest` IN (13891,13885,13925,13882,13881)) OR (`id`=32967 AND `quest` IN (13546,13545,13544,13526)) OR (`id`=32968 AND `quest`=13572) OR (`id`=34404 AND `quest`=13896) OR (`id`=33250 AND `quest`=13525) OR (`id`=33091 AND `quest` IN (13902,13588,13586,13579,13577,13575)) OR (`id`=33166 AND `quest` IN (13940,13587)) OR (`id`=33117 AND `quest` IN (13581,13580,13576)) OR (`id`=33119 AND `quest` IN (13583,13582,13578)) OR (`id`=33112 AND `quest` IN (13585,13584)) OR (`id`=6887 AND `quest` IN (13558,13547)) OR (`id`=33232 AND `quest`=13605) OR (`id`=3694 AND `quest`=13542) OR (`id`=32987 AND `quest` IN (13543,13573)) OR (`id`=32912 AND `quest` IN (13601,13596,13519)) OR (`id`=33727 AND `quest`=13683) OR (`id`=3901 AND `quest` IN (26469,26467)) OR (`id`=3920 AND `quest`=26468) OR (`id`=17291 AND `quest`=26454) OR (`id`=3848 AND `quest`=26455) OR (`id`=3894 AND `quest` IN (13919,26475)) OR (`id`=3845 AND `quest` IN (26897,13602)) OR (`id`=3846 AND `quest` IN (26466,26465)) OR (`id`=33204 AND `quest` IN (13623,26473)) OR (`id`=33187 AND `quest` IN (13617,13594)) OR (`id`=33182 AND `quest`=13595) OR (`id`=33178 AND `quest`=13515) OR (`id`=33176 AND `quest`=13514) OR (`id`=32963 AND `quest` IN (13590,13512,13509,13508)) OR (`id`=40879 AND `quest` IN (25642,25652,25649)) OR (`id`=33777 AND `quest` IN (13796,26472)) OR (`id`=17310 AND `quest` IN (13792,13766,13869,26446)) OR (`id`=17303 AND `quest` IN (26445,26444)) OR (`id`=17287 AND `quest` IN (13698,26457)) OR (`id`=40894 AND `quest`=25613) OR (`id`=3897 AND `quest` IN (26482,26481,13989)) OR (`id`=3885 AND `quest` IN (26838,26470)) OR (`id`=34604 AND `quest`=13987) OR (`id`=34599 AND `quest`=13985) OR (`id`=3698 AND `quest`=13982) OR (`id`=24739 AND `quest`=13976) OR (`id`=4079 AND `quest` IN (13964,13853,13849)) OR (`id`=3996 AND `quest`=13965) OR (`id`=3916 AND `quest` IN (26479,26478,26477)) OR (`id`=34358 AND `quest`=13924) OR (`id`=3880 AND `quest` IN (26456,13928)) OR (`id`=34377 AND `quest`=13935) OR (`id`=34335 AND `quest`=13922) OR (`id`=34289 AND `quest`=13886) OR (`id`=34290 AND `quest`=13880) OR (`id`=34292 AND `quest`=13884) OR (`id`=17106 AND `quest`=26453) OR (`id`=33445 AND `quest`=13646) OR (`id`=3847 AND `quest` IN (13645,26474,26463,13642)) OR (`id`=33443 AND `quest`=13644) OR (`id`=3891 AND `quest`=26464) OR (`id`=11806 AND `quest` IN (13626,13624)) OR (`id`=33276 AND `quest`=13630) OR (`id`=11219 AND `quest`=13632) OR (`id`=34041 AND `quest`=13844) OR (`id`=32966 AND `quest` IN (13513,13505)) OR (`id`=33055 AND `quest`=13511) OR (`id`=32965 AND `quest` IN (13507,13504)) OR (`id`=41482 AND `quest` IN (25925,25891,25889)) OR (`id`=41233 AND `quest` IN (25880,25875)) OR (`id`=41434 AND `quest` IN (25877,25876)) OR (`id`=41441 AND `quest` IN (25879,25878)) OR (`id`=40896 AND `quest` IN (25768,25671,25662)) OR (`id`=40897 AND `quest` IN (25765,25739)) OR (`id`=40899 AND `quest` IN (25769,25766)) OR (`id`=40900 AND `quest`=25767) OR (`id`=40898 AND `quest`=25741) OR (`id`=41071 AND `quest`=25669) OR (`id`=40908 AND `quest` IN (25728,25673)) OR (`id`=40881 AND `quest`=25650) OR (`id`=40973 AND `quest`=25646);

UPDATE `creature_questender` SET `VerifiedBuild`=42698 WHERE (`id`=40973 AND `quest` IN (25616,25646)) OR (`id`=40895 AND `quest` IN (25621,25607)) OR (`id`=34354 AND `quest` IN (25615,13981,13913,13979)) OR (`id`=39256 AND `quest` IN (25614,25613)) OR (`id`=34239 AND `quest` IN (13874,13872)) OR (`id`=34251 AND `quest`=13876) OR (`id`=34402 AND `quest` IN (13897,13953,13948,13892,13902)) OR (`id`=34422 AND `quest`=13900) OR (`id`=34403 AND `quest`=13898) OR (`id`=34423 AND `quest`=13899) OR (`id`=34446 AND `quest`=13895) OR (`id`=34404 AND `quest`=13893) OR (`id`=34340 AND `quest` IN (13910,13909,13907,13896)) OR (`id`=34342 AND `quest` IN (13918,13912,13911)) OR (`id`=34301 AND `quest` IN (13891,13885,13925,13882,13881)) OR (`id`=32967 AND `quest` IN (13546,13545,13544,13526,13525)) OR (`id`=32968 AND `quest`=13572) OR (`id`=33091 AND `quest` IN (13588,13940,13581,13583,13585,13573)) OR (`id`=33166 AND `quest` IN (13587,13586)) OR (`id`=33117 AND `quest` IN (13580,13576,13575)) OR (`id`=33119 AND `quest` IN (13582,13578,13577)) OR (`id`=33112 AND `quest` IN (13584,13579)) OR (`id`=32987 AND `quest` IN (13543,13558)) OR (`id`=3694 AND `quest`=13542) OR (`id`=6887 AND `quest`=13547) OR (`id`=33231 AND `quest`=13605) OR (`id`=33107 AND `quest`=13601) OR (`id`=32912 AND `quest` IN (13596,13519)) OR (`id`=32959 AND `quest`=13570) OR (`id`=32971 AND `quest`=13591) OR (`id`=3901 AND `quest` IN (26469,26468)) OR (`id`=33727 AND `quest`=13683) OR (`id`=3848 AND `quest`=26455) OR (`id`=3920 AND `quest`=26467) OR (`id`=17291 AND `quest`=26453) OR (`id`=14733 AND `quest`=26456) OR (`id`=3691 AND `quest` IN (26482,13867,13868,26479,13645)) OR (`id`=3894 AND `quest` IN (26475,13924,26474)) OR (`id`=3846 AND `quest` IN (26466,26465,13617)) OR (`id`=3845 AND `quest`=13602) OR (`id`=33182 AND `quest`=13595) OR (`id`=33204 AND `quest`=26473) OR (`id`=33187 AND `quest` IN (13594,26408)) OR (`id`=33176 AND `quest`=13514) OR (`id`=33178 AND `quest` IN (13515,13590)) OR (`id`=32966 AND `quest` IN (13513,13505)) OR (`id`=32963 AND `quest` IN (13512,13509,13511,13506,13589)) OR (`id`=34041 AND `quest`=13844) OR (`id`=40879 AND `quest` IN (25640,25650,25642,25647)) OR (`id`=17310 AND `quest` IN (13796,13766,26446,13869,26454)) OR (`id`=33777 AND `quest` IN (26472,13792)) OR (`id`=17303 AND `quest` IN (26445,26444,26443)) OR (`id`=17287 AND `quest` IN (13698,26457)) OR (`id`=3885 AND `quest` IN (26470,13964)) OR (`id`=3897 AND `quest` IN (26481,13989,26480)) OR (`id`=34604 AND `quest` IN (13987,13985)) OR (`id`=3698 AND `quest` IN (13982,13976)) OR (`id`=24739 AND `quest`=13965) OR (`id`=3916 AND `quest` IN (26478,26477,26476)) OR (`id`=34335 AND `quest` IN (13922,13921)) OR (`id`=3880 AND `quest`=13935) OR (`id`=34377 AND `quest`=13928) OR (`id`=34283 AND `quest` IN (13886,13877)) OR (`id`=34292 AND `quest`=13884) OR (`id`=34290 AND `quest`=13880) OR (`id`=4079 AND `quest` IN (13853,13849)) OR (`id`=33454 AND `quest`=13646) OR (`id`=3847 AND `quest` IN (26464,13642,13623)) OR (`id`=33443 AND `quest`=13644) OR (`id`=3891 AND `quest`=26463) OR (`id`=11806 AND `quest` IN (13626,13624,5713)) OR (`id`=33276 AND `quest`=13630) OR (`id`=11219 AND `quest`=13632) OR (`id`=32965 AND `quest` IN (13507,13504)) OR (`id`=33055 AND `quest`=13508) OR (`id`=32979 AND `quest`=13560) OR (`id`=41482 AND `quest` IN (25891,25889,25880)) OR (`id`=41441 AND `quest` IN (25879,25878)) OR (`id`=41233 AND `quest` IN (25877,25768)) OR (`id`=41434 AND `quest` IN (25876,25875)) OR (`id`=40896 AND `quest` IN (25769,25669,25671,25728,25652)) OR (`id`=40897 AND `quest`=25739) OR (`id`=40898 AND `quest`=25741) OR (`id`=40899 AND `quest`=25766) OR (`id`=40900 AND `quest`=25767) OR (`id`=41071 AND `quest`=25662) OR (`id`=41054 AND `quest`=25730) OR (`id`=40908 AND `quest`=25673) OR (`id`=40881 AND `quest`=25649);

UPDATE `gameobject_queststarter` SET `VerifiedBuild`=42698 WHERE (`id`=195134 AND `quest`=13981) OR (`id`=203186 AND `quest`=25730);

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (41599,159799,24735,24734,24739,24737,24736,41547,42015,42017,41551,41534,41552,41550,12918,12921,3897,41529,4020,41488,41486,4407,41491,41490,41489,43017,41493,41482,41485,42091,50895,42101,41528,50874,51816,34251,43569,34610,34609,34604,3773,3774,3772,33452,34601,34600,34599,34602,3698,8308,6731,24740,24738,33209,33204,33187,33208,11714,11713,41232,41231,34946,34243,34401,34398,33166,34399,34358,42984,34485,33082,34486,34370,34368,34367,42229,32850,34418,29876,34390,32856,3831,34422,34416,34940,34941,34945,34934,34933,34939,4066,3792,34937,34938,34932,34931,43500,3763,34348,34347,34357,34232,34233,41063,6072,12037,5314,12498,12475,12476,3759,3560,34400,41156,29684,34388,4202,3992,3993,5932,4070,41064,34331,17300,33767,12677,4273,34518,33494,34375,34376,34328,3696,3932,40910,43021,35137,40915,40899,40908,40900,41054,40898,41053,40897,34369,17541,22936,22935,3848,17304,50343,33078,33077,33076,33075,33046,12759,10642,20455,3770,175153,3767,3765,4619,3920,3757,3755,3752,3754,3762,3758,10647,32851,33038,33002,33183,3735,33034,51827,33338,33000,41090,41047,40896,41039,25670,33036,51374,51373,41009,41022,41021,17287,34283,3815,10641,10644,34322,33760,40271,51868,175154,2192,17303,12718,3527,12676,3941,33358,3940,3942,33777,33847,3799,3803,33421,33294,33295,3780,19914,19908,14753,14733,14963,14715,3821,34317,40881,3987,34207,34205,12818,4489,34167,34208,34314,3921,3922,69792,69791,10639,34621,34620,41854,32961,32960,148497,40984,40988,40973,40879));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(41599, 0, 0, 0, 14, 42698),
(159799, 0, 0, 0, 789, 42698),
(24735, 0, 0, 0, 12, 42698),
(24734, 0, 0, 0, 12, 42698),
(24739, 0, 0, 0, 12, 42698),
(24737, 0, 0, 0, 12, 42698),
(24736, 0, 0, 0, 12, 42698),
(41547, 0, 0, 0, 14, 42698),
(42015, 0, 0, 0, 14, 42698),
(42017, 0, 0, 0, 14, 42698),
(41551, 0, 0, 0, 14, 42698),
(41534, 0, 0, 0, 14, 42698),
(41552, 0, 0, 0, 14, 42698),
(41550, 0, 0, 0, 14, 42698),
(12918, 0, 0, 0, 12, 42698),
(12921, 0, 0, 0, 12, 42698),
(3897, 0, 0, 0, 12, 42698),
(41529, 0, 0, 0, 14, 42698),
(4020, 0, 0, 0, 14, 42698),
(41488, 0, 0, 0, 14, 42698),
(41486, 0, 0, 0, 14, 42698),
(4407, 0, 0, 0, 881, 42698),
(41491, 0, 0, 0, 14, 42698),
(41490, 0, 0, 0, 14, 42698),
(41489, 0, 0, 0, 14, 42698),
(43017, 0, 0, 0, 14, 42698),
(41493, 0, 0, 0, 14, 42698),
(41482, 0, 0, 0, 14, 42698),
(41485, 0, 0, 0, 2108, 42698),
(42091, 0, 0, 0, 14, 42698),
(50895, 0, 0, 0, 14, 42698),
(42101, 0, 0, 0, 14, 42698),
(41528, 0, 0, 0, 14, 42698),
(50874, 0, 0, 0, 14, 42698),
(51816, 0, 0, 0, 2108, 42698),
(34251, 0, 0, 0, 12, 42698),
(43569, 0, 0, 0, 14, 42698),
(34610, 0, 0, 0, 12, 42698),
(34609, 0, 0, 0, 12, 42698),
(34604, 0, 0, 0, 12, 42698),
(3773, 0, 0, 0, 12, 42698),
(3774, 0, 0, 0, 12, 42698),
(3772, 0, 0, 0, 12, 42698),
(33452, 0, 0, 0, 12, 42698),
(34601, 0, 0, 0, 12, 42698),
(34600, 0, 0, 0, 12, 42698),
(34599, 0, 0, 0, 12, 42698),
(34602, 0, 0, 0, 12, 42698),
(3698, 0, 0, 0, 12, 42698),
(8308, 0, 0, 0, 12, 42698),
(6731, 0, 0, 0, 12, 42698),
(24740, 0, 0, 0, 12, 42698),
(24738, 0, 0, 0, 12, 42698),
(33209, 0, 0, 0, 12, 42698),
(33204, 0, 0, 0, 12, 42698),
(33187, 0, 0, 0, 12, 42698),
(33208, 0, 0, 0, 12, 42698),
(11714, 0, 0, 0, 5, 42698),
(11713, 0, 0, 0, 5, 42698),
(41232, 0, 0, 0, 14, 42698),
(41231, 0, 0, 0, 14, 42698),
(34946, 0, 0, 0, 14, 42698),
(34243, 0, 0, 0, 5, 42698),
(34401, 0, 0, 0, 5, 42698),
(34398, 0, 0, 0, 5, 42698),
(33166, 0, 0, 0, 5, 42698),
(34399, 0, 0, 0, 5, 42698),
(34358, 0, 0, 0, 12, 42698),
(42984, 0, 0, 0, 5, 42698),
(34485, 0, 0, 0, 5, 42698),
(33082, 0, 0, 0, 5, 42698),
(34486, 0, 0, 0, 5, 42698),
(34370, 0, 0, 0, 5, 42698),
(34368, 0, 0, 0, 5, 42698),
(34367, 0, 0, 0, 5, 42698),
(42229, 0, 0, 0, 53, 42698),
(32850, 0, 0, 0, 12, 42698),
(34418, 0, 0, 0, 12, 42698),
(29876, 0, 0, 0, 12, 42698),
(34390, 0, 0, 0, 12, 42698),
(32856, 0, 0, 0, 12, 42698),
(3831, 0, 0, 0, 12, 42698),
(34422, 0, 0, 0, 5, 42698),
(34416, 0, 0, 0, 5, 42698),
(34940, 0, 0, 0, 14, 42698),
(34941, 0, 0, 0, 14, 42698),
(34945, 0, 0, 0, 14, 42698),
(34934, 0, 0, 0, 14, 42698),
(34933, 0, 0, 0, 14, 42698),
(34939, 0, 0, 0, 14, 42698),
(4066, 0, 0, 0, 14, 42698),
(3792, 0, 0, 0, 12, 42698),
(34937, 0, 0, 0, 14, 42698),
(34938, 0, 0, 0, 14, 42698),
(34932, 0, 0, 0, 14, 42698),
(34931, 0, 0, 0, 14, 42698),
(43500, 0, 0, 0, 14, 42698),
(3763, 0, 0, 0, 12, 42698),
(34348, 0, 0, 0, 5, 42698),
(34347, 0, 0, 0, 5, 42698),
(34357, 0, 0, 0, 5, 42698),
(34232, 0, 0, 0, 12, 42698),
(34233, 0, 0, 0, 12, 42698),
(41063, 0, 0, 0, 14, 42698),
(6072, 0, 0, 0, 12, 42698),
(12037, 0, 0, 0, 12, 42698),
(5314, 0, 0, 0, 12, 42698),
(12498, 0, 0, 0, 12, 42698),
(12475, 0, 0, 0, 12, 42698),
(12476, 0, 0, 0, 12, 42698),
(3759, 0, 0, 0, 12, 42698),
(3560, 0, 0, 0, 5, 42698),
(34400, 0, 0, 0, 5, 42698),
(41156, 0, 0, 0, 14, 42698),
(29684, 0, 0, 0, 328, 42698),
(34388, 0, 0, 0, 5, 42698),
(4202, 0, 0, 0, 14, 42698),
(3992, 0, 0, 0, 14, 42698),
(3993, 0, 0, 0, 14, 42698),
(5932, 0, 0, 0, 14, 42698),
(4070, 0, 0, 0, 14, 42698),
(41064, 0, 0, 0, 14, 42698),
(34331, 0, 0, 0, 5, 42698),
(17300, 0, 0, 0, 12, 42698),
(33767, 0, 0, 0, 12, 42698),
(12677, 0, 0, 0, 12, 42698),
(4273, 0, 0, 0, 12, 42698),
(34518, 0, 0, 0, 12, 42698),
(33494, 0, 0, 0, 12, 42698),
(34375, 0, 0, 0, 5, 42698),
(34376, 0, 0, 0, 5, 42698),
(34328, 0, 0, 0, 5, 42698),
(3696, 0, 0, 0, 12, 42698),
(3932, 0, 0, 0, 12, 42698),
(40910, 0, 0, 0, 14, 42698),
(43021, 0, 0, 0, 14, 42698),
(35137, 0, 0, 0, 881, 42698),
(40915, 0, 0, 0, 14, 42698),
(40899, 0, 0, 0, 14, 42698),
(40908, 0, 0, 0, 14, 42698),
(40900, 0, 0, 0, 14, 42698),
(41054, 0, 0, 0, 14, 42698),
(40898, 0, 0, 0, 14, 42698),
(41053, 0, 0, 0, 14, 42698),
(40897, 0, 0, 0, 14, 42698),
(34369, 0, 0, 0, 5, 42698),
(17541, 0, 0, 0, 12, 42698),
(22936, 0, 0, 0, 12, 42698),
(22935, 0, 0, 0, 881, 42698),
(3848, 0, 0, 0, 12, 42698),
(17304, 0, 0, 0, 12, 42698),
(50343, 0, 0, 0, 14, 42698),
(33078, 0, 0, 0, 5, 42698),
(33077, 0, 0, 0, 5, 42698),
(33076, 0, 0, 0, 5, 42698),
(33075, 0, 0, 0, 5, 42698),
(33046, 0, 0, 0, 5, 42698),
(12759, 0, 0, 0, 12, 42698),
(10642, 0, 0, 0, 12, 42698),
(20455, 0, 0, 0, 5, 42698),
(3770, 0, 0, 0, 12, 42698),
(175153, 0, 0, 0, 12, 42698),
(3767, 0, 0, 0, 12, 42698),
(3765, 0, 0, 0, 12, 42698),
(4619, 0, 0, 0, 12, 42698),
(3920, 0, 0, 0, 12, 42698),
(3757, 0, 0, 0, 12, 42698),
(3755, 0, 0, 0, 12, 42698),
(3752, 0, 0, 0, 12, 42698),
(3754, 0, 0, 0, 12, 42698),
(3762, 0, 0, 0, 12, 42698),
(3758, 0, 0, 0, 12, 42698),
(10647, 0, 0, 0, 12, 42698),
(32851, 0, 0, 0, 5, 42698),
(33038, 0, 0, 0, 5, 42698),
(33002, 0, 0, 0, 5, 42698),
(33183, 0, 0, 0, 12, 42698),
(3735, 0, 0, 0, 12, 42698),
(33034, 0, 0, 0, 5, 42698),
(51827, 0, 0, 0, 2108, 42698),
(33338, 0, 0, 0, 12, 42698),
(33000, 0, 0, 0, 5, 42698),
(41090, 0, 0, 0, 14, 42698),
(41047, 0, 0, 0, 14, 42698),
(40896, 0, 0, 0, 14, 42698),
(41039, 0, 0, 0, 2108, 42698),
(25670, 0, 0, 0, 328, 42698),
(33036, 0, 0, 0, 5, 42698),
(51374, 0, 0, 0, 14, 42698),
(51373, 0, 0, 0, 14, 42698),
(41009, 0, 0, 0, 14, 42698),
(41022, 0, 0, 0, 14, 42698),
(41021, 0, 0, 0, 14, 42698),
(17287, 0, 0, 0, 12, 42698),
(34283, 0, 0, 0, 12, 42698),
(3815, 0, 0, 0, 12, 42698),
(10641, 0, 0, 0, 12, 42698),
(10644, 0, 0, 0, 12, 42698),
(34322, 0, 0, 0, 12, 42698),
(33760, 0, 0, 0, 12, 42698),
(40271, 0, 0, 0, 5, 42698),
(51868, 0, 0, 0, 2108, 42698),
(175154, 0, 0, 0, 5, 42698),
(2192, 0, 0, 0, 5, 42698),
(17303, 0, 0, 0, 12, 42698),
(12718, 0, 0, 0, 12, 42698),
(3527, 0, 0, 0, 5, 42698),
(12676, 0, 0, 0, 12, 42698),
(3941, 0, 0, 0, 12, 42698),
(33358, 0, 0, 0, 5, 42698),
(3940, 0, 0, 0, 12, 42698),
(3942, 0, 0, 0, 12, 42698),
(33777, 0, 0, 0, 12, 42698),
(33847, 0, 0, 0, 12, 42698),
(3799, 0, 0, 0, 12, 42698),
(3803, 0, 0, 0, 12, 42698),
(33421, 0, 0, 0, 12, 42698),
(33294, 0, 0, 0, 12, 42698),
(33295, 0, 0, 0, 12, 42698),
(3780, 0, 0, 0, 12, 42698),
(19914, 0, 0, 0, 12, 42698),
(19908, 0, 0, 0, 12, 42698),
(14753, 0, 0, 0, 12, 42698),
(14733, 0, 0, 0, 12, 42698),
(14963, 0, 0, 0, 12, 42698),
(14715, 0, 0, 0, 12, 42698),
(3821, 0, 0, 0, 12, 42698),
(34317, 0, 0, 0, 12, 42698),
(40881, 0, 0, 0, 14, 42698),
(3987, 0, 0, 0, 12, 42698),
(34207, 0, 0, 0, 5, 42698),
(34205, 0, 0, 0, 5, 42698),
(12818, 0, 0, 0, 12, 42698),
(4489, 0, 0, 0, 14, 42698),
(34167, 0, 0, 0, 12, 42698),
(34208, 0, 0, 0, 12, 42698),
(34314, 0, 0, 0, 12, 42698),
(3921, 0, 0, 0, 12, 42698),
(3922, 0, 0, 0, 12, 42698),
(69792, 0, 0, 0, 482, 42698),
(69791, 0, 0, 0, 482, 42698),
(10639, 0, 0, 0, 12, 42698),
(34621, 0, 0, 0, 12, 42698),
(34620, 0, 0, 0, 12, 42698),
(41854, 0, 0, 0, 14, 42698),
(32961, 0, 0, 0, 5, 42698),
(32960, 0, 0, 0, 5, 42698),
(148497, 0, 1, 1, 733, 42698),
(40984, 0, 0, 0, 14, 42698),
(40988, 0, 0, 0, 14, 42698);

INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(40973, 0, 0, 0, 14, 42698),
(40879, 0, 0, 0, 14, 42698);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=42698 WHERE (`DifficultyID`=0 AND `Entry` IN (11711,7016,40350,34340,34343,32964,33119,32970,33055,33112,32862,7015,33178,33913,32855,32858,33176,43742,32990,33001,34248,33056,32859,33039,33037,32989,6887,33035,33232,32868,32986,33040,34342,34326,34427,34033,32996,34030,32899,32932,32890,32975,33262,33277,34046,32869,34231,32860,33071,43419,32963,32966,32965,34041,34103,32863,32861,34309,34321));

DELETE FROM `gossip_menu` WHERE (`MenuID`=14258 AND `TextID`=17615) OR (`MenuID`=10309 AND `TextID`=14311) OR (`MenuID`=10529 AND `TextID`=14569) OR (`MenuID`=10530 AND `TextID`=14568) OR (`MenuID`=24827 AND `TextID`=39095) OR (`MenuID`=10329 AND `TextID`=14340);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(14258, 17615, 42698), -- 49942 (Dular)
(10309, 14311, 42698), -- 33187 (Sentinel Shyela)
(10529, 14569, 42698), -- 3698 (Bolyun)
(10530, 14568, 42698), -- 3698 (Bolyun)
(24827, 39095, 42698), -- 159799 (Amara Lunastar)
(10329, 14340, 42698); -- 11806 (Sentinel Onaeya)

UPDATE `gossip_menu` SET `VerifiedBuild`=42698 WHERE (`MenuID`=11449 AND `TextID`=15962) OR (`MenuID`=10493 AND `TextID`=14520) OR (`MenuID`=10494 AND `TextID`=14521) OR (`MenuID`=10495 AND `TextID`=14523) OR (`MenuID`=5502 AND `TextID`=6553) OR (`MenuID`=3185 AND `TextID`=5844) OR (`MenuID`=10516 AND `TextID`=14548) OR (`MenuID`=10490 AND `TextID`=14517) OR (`MenuID`=11853 AND `TextID`=16615) OR (`MenuID`=10499 AND `TextID`=14531) OR (`MenuID`=10486 AND `TextID` IN (14524,14511)) OR (`MenuID`=10496 AND `TextID`=14526) OR (`MenuID`=10509 AND `TextID`=14541) OR (`MenuID`=10492 AND `TextID`=14518) OR (`MenuID`=10515 AND `TextID`=14547) OR (`MenuID`=10483 AND `TextID`=14509) OR (`MenuID`=10269 AND `TextID`=14260) OR (`MenuID`=10268 AND `TextID`=14259) OR (`MenuID`=10270 AND `TextID`=14261) OR (`MenuID`=10279 AND `TextID`=14276) OR (`MenuID`=10272 AND `TextID`=14264) OR (`MenuID`=10277 AND `TextID`=14274) OR (`MenuID`=10278 AND `TextID`=14275) OR (`MenuID`=10301 AND `TextID`=14304) OR (`MenuID`=7406 AND `TextID`=8875) OR (`MenuID`=7404 AND `TextID`=8873) OR (`MenuID`=7410 AND `TextID`=8939) OR (`MenuID`=7382 AND `TextID`=8838) OR (`MenuID`=11686 AND `TextID`=16363) OR (`MenuID`=6523 AND `TextID`=7725) OR (`MenuID`=8077 AND `TextID`=7599) OR (`MenuID`=10538 AND `TextID`=14577) OR (`MenuID`=10539 AND `TextID`=14576) OR (`MenuID`=10537 AND `TextID`=14575) OR (`MenuID`=10313 AND `TextID`=14316) OR (`MenuID`=10432 AND `TextID`=14470) OR (`MenuID`=10431 AND `TextID`=14469) OR (`MenuID`=8080 AND `TextID`=9986) OR (`MenuID`=7407 AND `TextID`=8876) OR (`MenuID`=11445 AND `TextID`=15946) OR (`MenuID`=10523 AND `TextID`=14557) OR (`MenuID`=2561 AND `TextID`=3233) OR (`MenuID`=10532 AND `TextID` IN (14572,14571)) OR (`MenuID`=14164 AND `TextID`=4993) OR (`MenuID`=10522 AND `TextID`=14556) OR (`MenuID`=10506 AND `TextID`=14538) OR (`MenuID`=7367 AND `TextID`=8802) OR (`MenuID`=361 AND `TextID`=838) OR (`MenuID`=10339 AND `TextID`=14347) OR (`MenuID`=10329 AND `TextID`=14339) OR (`MenuID`=14982 AND `TextID`=21179) OR (`MenuID`=10312 AND `TextID`=14315) OR (`MenuID`=10480 AND `TextID`=14506) OR (`MenuID`=10430 AND `TextID`=14468) OR (`MenuID`=10428 AND `TextID`=14454) OR (`MenuID`=10416 AND `TextID`=14454) OR (`MenuID`=10484 AND `TextID`=14510) OR (`MenuID`=11527 AND `TextID`=16089) OR (`MenuID`=11518 AND `TextID`=16072) OR (`MenuID`=11458 AND `TextID`=15978) OR (`MenuID`=11459 AND `TextID`=15979) OR (`MenuID`=11465 AND `TextID`=15991) OR (`MenuID`=11467 AND `TextID`=15995) OR (`MenuID`=11453 AND `TextID`=15970) OR (`MenuID`=11452 AND `TextID`=15966);

DELETE FROM `gameobject_template` WHERE `entry` IN (310498 /*Campfire*/, 310457 /*Campfire*/, 310507 /*Beached Sea Turtle*/, 284627 /*Beached Sea Creature*/, 311299 /*Beached Sea Turtle*/, 284631 /*Beached Sea Turtle*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(310498, 8, 33316, 'Campfire', '', '', '', 0.730000019073486328, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 733, 42698), -- Campfire
(310457, 8, 192, 'Campfire', '', '', '', 0.85000002384185791, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- Campfire
(310507, 2, 4153, 'Beached Sea Turtle', '', '', '', 1, 259, 3871, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 42698), -- Beached Sea Turtle
(284627, 3, 3512, 'Beached Sea Creature', '', '', '', 1, 259, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12620, 0, 0, 0, 0, 5, 42698), -- Beached Sea Creature
(311299, 2, 4153, 'Beached Sea Turtle', '', '', '', 1.009999990463256835, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 42698), -- Beached Sea Turtle
(284631, 2, 4153, 'Beached Sea Turtle', '', '', '', 1.009999990463256835, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 42698); -- Beached Sea Turtle

UPDATE `gameobject_template` SET `ContentTuningId`=14, `VerifiedBuild`=42698 WHERE `entry`=203414; -- Krom'gar "Elf Killer"
UPDATE `gameobject_template` SET `VerifiedBuild`=42698 WHERE `entry` IN (142342, 177277, 195134, 195005, 195002, 195110, 19015, 142117, 20961, 175848, 175849, 3723, 175847, 175850, 175844, 175846, 175845, 241595, 235311, 195078, 195045, 195044, 232560, 232554, 195058, 1926, 310463, 1923, 310508, 310491, 310489, 194144, 194143, 194141, 310490, 194142, 310475, 61929, 310458, 1921, 310488, 194140, 195057, 194113, 319201, 284630, 92489, 284613, 92490, 284597, 103687, 194211, 194112, 284522, 208296, 231268, 235892, 6289, 140111, 140109, 6290, 140112, 140110, 6291, 6292, 140105, 194482, 6287, 6286, 175284, 175286, 175285, 177194, 177195, 177196, 181913, 181681, 177197, 181916, 20964, 194465, 194464, 6288, 178195, 194997, 194566, 106336, 106327, 149038, 106326, 106325, 178864, 106335, 204875, 203822, 203823, 178146, 194550, 20724, 194990, 177225, 194809, 194175, 3722, 20960, 18603, 17783, 310460, 17284, 311291, 175984, 18596, 194564, 194563, 176784, 21004, 194493, 181690, 194615, 194458, 140113, 194617, 194616, 176789, 194651, 19025, 195111, 18645, 18644, 3220, 18643, 20963, 176999, 178247, 206854, 191369, 195012, 311309, 284501, 204130, 194102, 194103, 194104, 311297, 311288, 284603, 284545, 176291, 176289, 316799, 203377, 203376, 202572, 203448, 203146, 203145, 203141, 203429, 194473, 203162, 203160, 203161, 203163, 203158, 203154, 194475, 194474, 203148);
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=15060, `ContentTuningId`=12, `VerifiedBuild`=42698 WHERE `entry`=178144; -- Troll Chest
UPDATE `gameobject_template` SET `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=204228; -- Horn of the Ancients
UPDATE `gameobject_template` SET `Data3`=0, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=195056; -- Titan Data Display Device
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27251, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=195055; -- Buried Debris
UPDATE `gameobject_template` SET `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=195043; -- Greymist Murloc Build Site
UPDATE `gameobject_template` SET `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=195054; -- Mud-Crusted Ancient Disc
UPDATE `gameobject_template` SET `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry` IN (310484, 16393); -- Ancient Flame
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27249, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=195080; -- Floating Greymist Debris
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27237, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=195021; -- Glittering Shell
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27249, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=195042; -- Greymist Debris
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27237, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=195021; -- Glittering Shell
UPDATE `gameobject_template` SET `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=195071; -- Nightmare Portal
UPDATE `gameobject_template` SET `displayId`=56578, `name`='Flamestone', `size`=5, `Data1`=20, `Data3`=0, `Data6`=0, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=195059; -- Flamestone at the Blazing Strand
UPDATE `gameobject_template` SET `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry` IN (176190, 176196); -- Beached Sea Turtle
UPDATE `gameobject_template` SET `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=195070; -- Wildkin Funeral Pyre
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=12620, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=175207; -- Beached Sea Creature
UPDATE `gameobject_template` SET `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry` IN (284646, 17182); -- Buzzbox 827
UPDATE `gameobject_template` SET `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=194145; -- Aetherion Ritual Orb
UPDATE `gameobject_template` SET `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=194771; -- Grovekeeper's Incense
UPDATE `gameobject_template` SET `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=194179; -- The Final Flame of Bashal'Aran
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=26866, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=194204; -- Twilight Plans
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39335, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=207533; -- Runestone Treasure Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=26821, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=194090; -- Highborne Relic
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=26821, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=194089; -- Highborne Relic
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=26821, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=194088; -- Highborne Relic
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=2768, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=13359; -- Cat Figurine
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=26899, `ContentTuningId`=12, `VerifiedBuild`=42698 WHERE `entry`=194549; -- The Forest Heart
UPDATE `gameobject_template` SET `ContentTuningId`=21, `VerifiedBuild`=42698 WHERE `entry`=20725; -- The Legacy of the Aspects
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=26872, `ContentTuningId`=12, `VerifiedBuild`=42698 WHERE `entry`=194263; -- Serviceable Arrow
UPDATE `gameobject_template` SET `ContentTuningId`=165, `VerifiedBuild`=42698 WHERE `entry`=208790; -- Night Elf Grave
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=15060, `ContentTuningId`=12, `VerifiedBuild`=42698 WHERE `entry`=178144; -- Troll Chest
UPDATE `gameobject_template` SET `ContentTuningId`=200, `VerifiedBuild`=42698 WHERE `entry` IN (310468, 178828); -- Meeting Stone
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27237, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=195021; -- Glittering Shell
UPDATE `gameobject_template` SET `displayId`=56578, `name`='Flamestone', `size`=5, `Data1`=20, `Data3`=0, `Data6`=0, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=195059; -- Flamestone at the Blazing Strand
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=12620, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=175207; -- Beached Sea Creature
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=26866, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=194204; -- Twilight Plans
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39335, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=207533; -- Runestone Treasure Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=26821, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=194090; -- Highborne Relic
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=26821, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=194089; -- Highborne Relic
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=26821, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=194088; -- Highborne Relic
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=2768, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=13359; -- Cat Figurine
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27270, `ContentTuningId`=12, `VerifiedBuild`=42698 WHERE `entry`=195136; -- Bronze Cog
UPDATE `gameobject_template` SET `ContentTuningId`=12, `VerifiedBuild`=42698 WHERE `entry`=20806; -- Ashenvale Moonwell
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=26899, `ContentTuningId`=12, `VerifiedBuild`=42698 WHERE `entry`=194549; -- The Forest Heart
UPDATE `gameobject_template` SET `ContentTuningId`=12, `VerifiedBuild`=42698 WHERE `entry`=178228; -- Murgut's Totem Basket Aura
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=15160, `ContentTuningId`=12, `VerifiedBuild`=42698 WHERE `entry`=178227; -- Murgut's Totem Basket
UPDATE `gameobject_template` SET `ContentTuningId`=12, `VerifiedBuild`=42698 WHERE `entry`=195143; -- Bloodtooth Banner
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=2962, `ContentTuningId`=12, `VerifiedBuild`=42698 WHERE `entry`=19016; -- Stardust Covered Bush
UPDATE `gameobject_template` SET `ContentTuningId`=12, `VerifiedBuild`=42698 WHERE `entry`=19027; -- Tome of Mel'Thandris
UPDATE `gameobject_template` SET `ContentTuningId`=12, `VerifiedBuild`=42698 WHERE `entry`=19022; -- Worn Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27270, `ContentTuningId`=12, `VerifiedBuild`=42698 WHERE `entry`=195136; -- Bronze Cog
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=15060, `ContentTuningId`=12, `VerifiedBuild`=42698 WHERE `entry`=178144; -- Troll Chest
UPDATE `gameobject_template` SET `ContentTuningId`=12, `VerifiedBuild`=42698 WHERE `entry`=93192; -- Heartswood
UPDATE `gameobject_template` SET `Data3`=0, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=195056; -- Titan Data Display Device
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27251, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=195055; -- Buried Debris
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27249, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=195080; -- Floating Greymist Debris
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27237, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=195021; -- Glittering Shell
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27249, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=195042; -- Greymist Debris
UPDATE `gameobject_template` SET `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=194101; -- Shatterspear Cage
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=2768, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=13873; -- Cat Figurine
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39335, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=207533; -- Runestone Treasure Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=26821, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=194089; -- Highborne Relic
UPDATE `gameobject_template` SET `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=194787; -- Charred Book
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=26821, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=194090; -- Highborne Relic
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=26821, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=194088; -- Highborne Relic
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=2768, `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=13359; -- Cat Figurine
UPDATE `gameobject_template` SET `ContentTuningId`=5, `VerifiedBuild`=42698 WHERE `entry`=195006; -- Decoy Bot Control Console
UPDATE `gameobject_template` SET `ContentTuningId`=14, `VerifiedBuild`=42698 WHERE `entry`=203449; -- Turd Flies
UPDATE `gameobject_template` SET `ContentTuningId`=14, `VerifiedBuild`=42698 WHERE `entry`=203217; -- Highborne Prison
UPDATE `gameobject_template` SET `ContentTuningId`=14, `VerifiedBuild`=42698 WHERE `entry`=203088; -- BD-816 War Apparatus
UPDATE `gameobject_template` SET `ContentTuningId`=14, `VerifiedBuild`=42698 WHERE `entry`=203175; -- Mechanized Air
UPDATE `gameobject_template` SET `ContentTuningId`=14, `VerifiedBuild`=42698 WHERE `entry`=203176; -- Mechanized Ice
UPDATE `gameobject_template` SET `ContentTuningId`=14, `VerifiedBuild`=42698 WHERE `entry`=203174; -- Mechanized Fire
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=29533, `ContentTuningId`=14, `VerifiedBuild`=42698 WHERE `entry`=203132; -- Azure Iron Ore

DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=284627 AND `Idx`=0);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(284627, 0, 12242, 42698); -- Beached Sea Creature

UPDATE `gameobject_questitem` SET `VerifiedBuild`=42698 WHERE (`Idx`=0 AND `GameObjectEntry` IN (181686,181681,181916,178195,194997,194566,194549,20725,194263,178144,19015,178186,178185,17783,194202,195021,175207,194204,194090,194089,194088,195055,195054,195080,195042,195136,178227,19016,19022,195111,93192,195012,194787,203294,203216,203215,203214,203088,203175,203176,203174,203132));

UPDATE `page_text` SET `VerifiedBuild`=42698 WHERE `ID` IN (2211, 2910, 2909);

UPDATE `creature_queststarter` SET `VerifiedBuild`=42852 WHERE (`id`=38876 AND `quest`=25028) OR (`id`=38871 AND `quest` IN (25027,25015,25022,25034)) OR (`id`=38314 AND `quest` IN (24571,24570,24566)) OR (`id`=37570 AND `quest` IN (24565,24601,24574)) OR (`id`=37835 AND `quest`=25084) OR (`id`=37812 AND `quest`=26908) OR (`id`=37834 AND `quest`=24824) OR (`id`=39118 AND `quest`=25104) OR (`id`=39154 AND `quest`=25102) OR (`id`=39084 AND `quest` IN (25080,25079,25075)) OR (`id`=39083 AND `quest` IN (25087,25081)) OR (`id`=39085 AND `quest` IN (25086,25082)) OR (`id`=38873 AND `quest`=25008) OR (`id`=38878 AND `quest`=25002) OR (`id`=38620 AND `quest` IN (25036,24948,24943,24941)) OR (`id`=3454 AND `quest`=24939) OR (`id`=38804 AND `quest` IN (24956,24944)) OR (`id`=38621 AND `quest`=25000) OR (`id`=38619 AND `quest` IN (24938,24934)) OR (`id`=39322 AND `quest`=25197) OR (`id`=38383 AND `quest`=25191) OR (`id`=38323 AND `quest` IN (25074,25057,25045,25043)) OR (`id`=39003 AND `quest` IN (25042,25041)) OR (`id`=38986 AND `quest` IN (25059,25044)) OR (`id`=38380 AND `quest`=25186) OR (`id`=38378 AND `quest` IN (24863,24862)) OR (`id`=41229 AND `quest` IN (25852,25846,25823,25822,25834,25793)) OR (`id`=11858 AND `quest` IN (25851,25848,25847)) OR (`id`=41350 AND `quest`=25845) OR (`id`=41278 AND `quest` IN (25844,25837)) OR (`id`=41277 AND `quest` IN (25821,25806)) OR (`id`=41282 AND `quest`=25809) OR (`id`=41276 AND `quest`=25811) OR (`id`=41638 AND `quest`=25935) OR (`id`=41664 AND `quest`=25934) OR (`id`=41487 AND `quest` IN (25930,25938));

UPDATE `creature_questender` SET `VerifiedBuild`=42852 WHERE (`id`=38871 AND `quest` IN (25027,25022,25015,25036,25002)) OR (`id`=38873 AND `quest` IN (25008,25000)) OR (`id`=37835 AND `quest`=25086) OR (`id`=39154 AND `quest`=25102) OR (`id`=39118 AND `quest`=25087) OR (`id`=39084 AND `quest` IN (25080,25079,25075)) OR (`id`=39083 AND `quest` IN (25081,25074)) OR (`id`=39085 AND `quest`=25082) OR (`id`=38804 AND `quest` IN (24956,24944)) OR (`id`=38620 AND `quest` IN (24948,24943)) OR (`id`=3454 AND `quest` IN (24939,24938)) OR (`id`=38622 AND `quest`=24934) OR (`id`=38619 AND `quest`=25197) OR (`id`=39322 AND `quest`=25191) OR (`id`=38379 AND `quest`=25186) OR (`id`=38986 AND `quest` IN (25059,25044,25034)) OR (`id`=38323 AND `quest` IN (25057,25045,25043)) OR (`id`=39003 AND `quest` IN (25042,25041)) OR (`id`=37570 AND `quest` IN (24601,24574,24565,25028)) OR (`id`=38314 AND `quest` IN (24566,24571,24570)) OR (`id`=38380 AND `quest` IN (24863,24862)) OR (`id`=38378 AND `quest`=25852) OR (`id`=41229 AND `quest` IN (25851,25822,25823,25845,25821,25765)) OR (`id`=11858 AND `quest` IN (25848,25847,25846)) OR (`id`=41350 AND `quest`=25844) OR (`id`=41278 AND `quest` IN (25837,25834)) OR (`id`=41277 AND `quest` IN (25808,25806)) OR (`id`=41282 AND `quest`=25809) OR (`id`=41276 AND `quest` IN (25811,25793)) OR (`id`=41487 AND `quest` IN (25931,25930,25925)) OR (`id`=41664 AND `quest`=25934) OR (`id`=41638 AND `quest`=25935);

UPDATE `gameobject_questender` SET `VerifiedBuild`=42852 WHERE (`id`=202335 AND `quest`=24941);

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (44301,39084,44280,39124,39094,39083,44304,44267,39211,39085,44347,38333,39136,37529,37513,39040,6387,50825,41367,41369,41368,42855,41316,41317,41311,41315,41291,41314,41318,41282,41277,41276,38822,39024,44279,39025,39003,39009,38986,41283,38912,41286,41275,41274,41229,41397,41278,41361,35136,126964,37754,37792,37753,37736,37791,37103,44265,41350,41351,11858,50786,11918,11917,11915,50884,38623,38709,38622,38664,38707,39127,65936,3253,5864,5863,51856,39321,39327,34896,37224,39146,39099,38314,37570,3252,38942,38872,38924,38940,38941,39139,39129));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(44301, 0, 0, 0, 16, 42852),
(39084, 0, 0, 0, 16, 42852),
(44280, 0, 0, 0, 16, 42852),
(39124, 0, 0, 0, 16, 42852),
(39094, 0, 0, 0, 16, 42852),
(39083, 0, 0, 0, 16, 42852),
(44304, 0, 0, 0, 16, 42852),
(44267, 0, 0, 0, 16, 42852),
(39211, 0, 0, 0, 881, 42852),
(39085, 0, 0, 0, 16, 42852),
(44347, 0, 0, 0, 16, 42852),
(38333, 0, 0, 0, 16, 42852),
(39136, 0, 0, 0, 2108, 42852),
(37529, 0, 0, 0, 16, 42852),
(37513, 0, 0, 0, 16, 42852),
(39040, 0, 0, 0, 16, 42852),
(6387, 0, 0, 0, 16, 42852),
(50825, 0, 0, 0, 14, 42852),
(41367, 0, 0, 0, 14, 42852),
(41369, 0, 0, 0, 14, 42852),
(41368, 0, 0, 0, 14, 42852),
(42855, 0, 0, 0, 14, 42852),
(41316, 0, 0, 0, 14, 42852),
(41317, 0, 0, 0, 14, 42852),
(41311, 0, 0, 0, 14, 42852),
(41315, 0, 0, 0, 14, 42852),
(41291, 0, 0, 0, 14, 42852),
(41314, 0, 0, 0, 14, 42852),
(41318, 0, 0, 0, 14, 42852),
(41282, 0, 0, 0, 14, 42852),
(41277, 0, 0, 0, 14, 42852),
(41276, 0, 0, 0, 14, 42852),
(38822, 0, 0, 0, 16, 42852),
(39024, 0, 0, 0, 16, 42852),
(44279, 0, 0, 0, 16, 42852),
(39025, 0, 0, 0, 16, 42852),
(39003, 0, 0, 0, 16, 42852),
(39009, 0, 0, 0, 16, 42852),
(38986, 0, 0, 0, 16, 42852),
(41283, 0, 0, 0, 14, 42852),
(38912, 0, 0, 0, 16, 42852),
(41286, 0, 0, 0, 14, 42852),
(41275, 0, 0, 0, 14, 42852),
(41274, 0, 0, 0, 14, 42852),
(41229, 0, 0, 0, 14, 42852),
(41397, 0, 0, 0, 14, 42852),
(41278, 0, 0, 0, 14, 42852),
(41361, 0, 0, 0, 14, 42852),
(35136, 0, 0, 0, 881, 42852),
(126964, 0, 0, 0, 2108, 42852),
(37754, 0, 0, 0, 16, 42852),
(37792, 0, 0, 0, 16, 42852),
(37753, 0, 0, 0, 16, 42852),
(37736, 0, 0, 0, 16, 42852),
(37791, 0, 0, 0, 16, 42852),
(37103, 0, 0, 0, 16, 42852),
(44265, 0, 0, 0, 16, 42852),
(41350, 0, 0, 0, 14, 42852),
(41351, 0, 0, 0, 14, 42852),
(11858, 0, 0, 0, 14, 42852),
(50786, 0, 0, 0, 14, 42852),
(11918, 0, 0, 0, 14, 42852),
(11917, 0, 0, 0, 14, 42852),
(11915, 0, 0, 0, 14, 42852),
(50884, 0, 0, 0, 14, 42852),
(38623, 0, 0, 0, 16, 42852),
(38709, 0, 0, 0, 16, 42852),
(38622, 0, 0, 0, 16, 42852),
(38664, 0, 0, 0, 16, 42852),
(38707, 0, 0, 0, 16, 42852),
(39127, 0, 0, 0, 16, 42852),
(65936, 0, 0, 0, 16, 42852),
(3253, 0, 0, 0, 16, 42852),
(5864, 0, 0, 0, 16, 42852),
(5863, 0, 0, 0, 16, 42852),
(51856, 0, 0, 0, 2108, 42852),
(39321, 0, 0, 0, 16, 42852),
(39327, 0, 0, 0, 16, 42852),
(34896, 0, 0, 0, 14, 42852),
(37224, 0, 0, 0, 16, 42852),
(39146, 0, 0, 0, 16, 42852),
(39099, 0, 0, 0, 16, 42852),
(38314, 0, 0, 0, 16, 42852),
(37570, 0, 0, 0, 16, 42852),
(3252, 0, 0, 0, 16, 42852),
(38942, 0, 0, 0, 16, 42852),
(38872, 0, 0, 0, 16, 42852),
(38924, 0, 0, 0, 16, 42852),
(38940, 0, 0, 0, 16, 42852),
(38941, 0, 0, 0, 16, 42852),
(39139, 0, 0, 0, 16, 42852),
(39129, 0, 0, 0, 16, 42852);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=42852 WHERE (`Entry`=37204 AND `DifficultyID`=0);

DELETE FROM `gossip_menu` WHERE (`MenuID`=22831 AND `TextID`=35378) OR (`MenuID`=11175 AND `TextID`=15554) OR (`MenuID`=11158 AND `TextID` IN (15538,15537)) OR (`MenuID`=11125 AND `TextID`=15471);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(22831, 35378, 42852), -- 141073 (Ali Buntblaster)
(11175, 15554, 42852), -- 39154 (Hurlston Stonesthrow)
(11158, 15538, 42852), -- 39084 (Mizzy Pistonhammer)
(11158, 15537, 42852), -- 39084 (Mizzy Pistonhammer)
(11125, 15471, 42852); -- 38875 (Ol' Durty Pete)

UPDATE `gossip_menu` SET `VerifiedBuild`=42852 WHERE (`MenuID`=11108 AND `TextID` IN (15459,15482)) OR (`MenuID`=11129 AND `TextID`=15483) OR (`MenuID`=11128 AND `TextID`=15481) OR (`MenuID`=11005 AND `TextID`=15303) OR (`MenuID`=10941 AND `TextID` IN (15288,15289,15293,15205)) OR (`MenuID`=11028 AND `TextID`=15331) OR (`MenuID`=11026 AND `TextID`=15330) OR (`MenuID`=11027 AND `TextID`=15329) OR (`MenuID`=11025 AND `TextID`=15328) OR (`MenuID`=11024 AND `TextID`=15327) OR (`MenuID`=11175 AND `TextID`=15552) OR (`MenuID`=11196 AND `TextID` IN (15587,15586)) OR (`MenuID`=11163 AND `TextID`=15536) OR (`MenuID`=11158 AND `TextID` IN (15539,15530)) OR (`MenuID`=11162 AND `TextID`=15535) OR (`MenuID`=11165 AND `TextID`=15541) OR (`MenuID`=11113 AND `TextID`=15471) OR (`MenuID`=11121 AND `TextID`=15479) OR (`MenuID`=11119 AND `TextID`=15477) OR (`MenuID`=11118 AND `TextID`=15475) OR (`MenuID`=11115 AND `TextID`=15473) OR (`MenuID`=11117 AND `TextID`=15476) OR (`MenuID`=11116 AND `TextID`=15474) OR (`MenuID`=11122 AND `TextID`=15480) OR (`MenuID`=11120 AND `TextID`=15478) OR (`MenuID`=11105 AND `TextID`=15455) OR (`MenuID`=11080 AND `TextID`=15409) OR (`MenuID`=11068 AND `TextID` IN (15411,15393)) OR (`MenuID`=11071 AND `TextID` IN (15398,15397)) OR (`MenuID`=11197 AND `TextID`=15594) OR (`MenuID`=11814 AND `TextID`=16567) OR (`MenuID`=11153 AND `TextID`=15525) OR (`MenuID`=11138 AND `TextID` IN (15515,15514,15496,15495)) OR (`MenuID`=11140 AND `TextID`=15501) OR (`MenuID`=11148 AND `TextID`=15519) OR (`MenuID`=11147 AND `TextID` IN (15518,15517)) OR (`MenuID`=11151 AND `TextID`=15522) OR (`MenuID`=11150 AND `TextID`=15521) OR (`MenuID`=11149 AND `TextID`=15520) OR (`MenuID`=11010 AND `TextID`=15314) OR (`MenuID`=11012 AND `TextID`=15315) OR (`MenuID`=11506 AND `TextID`=16058) OR (`MenuID`=11500 AND `TextID`=16051) OR (`MenuID`=11504 AND `TextID`=16056) OR (`MenuID`=11505 AND `TextID`=16057) OR (`MenuID`=11529 AND `TextID`=16094);

UPDATE `gameobject_template` SET `ContentTuningId`=16, `VerifiedBuild`=42852 WHERE `entry`=201724; -- Bristleback Cage
UPDATE `gameobject_template` SET `VerifiedBuild`=42852 WHERE `entry` IN (293319, 3727, 293335, 202419, 202418, 201587, 201588, 204999, 204993, 204994, 201878, 200303, 204996, 204995, 200302, 202476, 175751, 48516, 142198, 201696, 3729, 23577, 201708, 201879, 203814, 202462, 202461, 202460, 195505, 195504, 195503, 195502, 201602, 182255, 175786, 204998, 202452, 201695, 91706, 204992, 204991, 141871, 92426, 203041, 177288, 92427, 203261, 203236, 206765, 204805, 203291, 203290, 204800, 204804, 176787, 2334, 176506, 143983, 176509, 176508, 176507, 194504, 208095);
UPDATE `gameobject_template` SET `ContentTuningId`=3, `VerifiedBuild`=42852 WHERE `entry`=293318; -- Rocketeer NX-01 High Jumpers
UPDATE `gameobject_template` SET `ContentTuningId`=16, `VerifiedBuild`=42852 WHERE `entry`=201876; -- Battlescar Flagpole
UPDATE `gameobject_template` SET `ContentTuningId`=16, `VerifiedBuild`=42852 WHERE `entry` IN (141862, 141863); -- Cannon
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=42852 WHERE `entry`=202453; -- Big Haunch of Stormsnout Meat
UPDATE `gameobject_template` SET `ContentTuningId`=16, `VerifiedBuild`=42852 WHERE `entry`=201792; -- Northwatch Siege Engine
UPDATE `gameobject_template` SET `ContentTuningId`=16, `VerifiedBuild`=42852 WHERE `entry` IN (201810, 201781, 201743); -- Field Banner
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=28355, `ContentTuningId`=16, `VerifiedBuild`=42852 WHERE `entry`=202467; -- Taurajo Intelligence
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=29625, `ContentTuningId`=14, `VerifiedBuild`=42852 WHERE `entry`=203281; -- Horde General's Chest
UPDATE `gameobject_template` SET `ContentTuningId`=14, `VerifiedBuild`=42852 WHERE `entry`=203235; -- Detonation Device
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=29682, `ContentTuningId`=14, `VerifiedBuild`=42852 WHERE `entry`=178106; -- Resonite Crystal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=29682, `ContentTuningId`=14, `VerifiedBuild`=42852 WHERE `entry`=178105; -- Resonite Crystal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=29682, `ContentTuningId`=14, `VerifiedBuild`=42852 WHERE `entry`=178104; -- Resonite Crystal

UPDATE `gameobject_questitem` SET `VerifiedBuild`=42852 WHERE (`Idx`=0 AND `GameObjectEntry` IN (202478,202477,202467,203281,203443,178106,178105,178104,203253));

DELETE FROM `creature_queststarter` WHERE (`id`=1750 AND `quest`=27241) OR (`id`=4921 AND `quest`=11212);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(1750, 27241, 42979), -- Return to Jaina offered Grand Admiral Jes-Tereth
(4921, 11212, 42979); -- Tabetha's Farm offered Guard Byron

UPDATE `creature_queststarter` SET `VerifiedBuild`=42979 WHERE (`id`=41060 AND `quest` IN (25704,25672,25661)) OR (`id`=41058 AND `quest`=25660) OR (`id`=40885 AND `quest` IN (25627,25609)) OR (`id`=47383 AND `quest` IN (28048,28047,28051,28045)) OR (`id`=40726 AND `quest`=28031) OR (`id`=40591 AND `quest`=25588) OR (`id`=40554 AND `quest` IN (25590,25517)) OR (`id`=40027 AND `quest` IN (25744,25504,27446,25835)) OR (`id`=40475 AND `quest` IN (25585,25532,25515)) OR (`id`=23579 AND `quest` IN (27407,27411,27410,27409,27408)) OR (`id`=40345 AND `quest`=25479) OR (`id`=23570 AND `quest`=27413) OR (`id`=23951 AND `quest` IN (27214,27247,27248)) OR (`id`=23905 AND `quest`=27222) OR (`id`=12919 AND `quest` IN (27221,27220)) OR (`id`=23896 AND `quest`=27219) OR (`id`=23892 AND `quest` IN (27218,27217)) OR (`id`=23835 AND `quest` IN (27215,27216)) OR (`id`=41190 AND `quest` IN (25774,25756,25825,25813,25798,25796,25778)) OR (`id`=40082 AND `quest`=25762) OR (`id`=39992 AND `quest`=25488) OR (`id`=39946 AND `quest`=25486) OR (`id`=6546 AND `quest` IN (27429,11211,27430)) OR (`id`=23601 AND `quest` IN (27339,27336)) OR (`id`=23600 AND `quest` IN (27346,27340)) OR (`id`=23568 AND `quest` IN (27428,27427,27426)) OR (`id`=4944 AND `quest` IN (27425,27287,27264,27284,27249,27291)) OR (`id`=5089 AND `quest`=27288) OR (`id`=23797 AND `quest` IN (27347,27348,11208)) OR (`id`=4941 AND `quest`=27285) OR (`id`=4948 AND `quest`=27286) OR (`id`=4968 AND `quest` IN (27240,27239)) OR (`id`=23569 AND `quest` IN (27238,27237,27236)) OR (`id`=4794 AND `quest` IN (1258,1204)) OR (`id`=5086 AND `quest` IN (27235,27234)) OR (`id`=23566 AND `quest` IN (27213,27212,27211,27210)) OR (`id`=4921 AND `quest`=27251) OR (`id`=41204 AND `quest`=25790) OR (`id`=4792 AND `quest` IN (27186,27191,27184,27183)) OR (`id`=23723 AND `quest` IN (27245,27243,27242)) OR (`id`=23843 AND `quest` IN (27190,27189,27188)) OR (`id`=4880 AND `quest`=1222) OR (`id`=39118 AND `quest` IN (26687,25183,25182)) OR (`id`=39188 AND `quest` IN (25175,25151)) OR (`id`=38152 AND `quest`=25174) OR (`id`=39220 AND `quest`=25163) OR (`id`=39218 AND `quest`=25153) OR (`id`=39155 AND `quest` IN (25120,25108,25106)) OR (`id`=37812 AND `quest`=24653) OR (`id`=37835 AND `quest`=25085) OR (`id`=45271 AND `quest`=25873) OR (`id`=41444 AND `quest`=25871) OR (`id`=41392 AND `quest`=25869);

DELETE FROM `creature_questender` WHERE (`id`=1750 AND `quest`=27240);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(1750, 27240, 42979); -- Proof of Treachery ended by Grand Admiral Jes-Tereth

UPDATE `creature_questender` SET `VerifiedBuild`=42979 WHERE (`id`=41060 AND `quest` IN (25704,25672,25661,25660)) OR (`id`=40885 AND `quest` IN (25627,25609,25590)) OR (`id`=47383 AND `quest` IN (28048,28047,28051,28045,28031)) OR (`id`=40591 AND `quest`=25588) OR (`id`=40475 AND `quest` IN (25585,25542,25515,25504)) OR (`id`=23572 AND `quest` IN (27412,11211,27248,11208)) OR (`id`=23579 AND `quest` IN (27407,27411,27410,27409,27408)) OR (`id`=23570 AND `quest`=27413) OR (`id`=23905 AND `quest` IN (27222,27221)) OR (`id`=12919 AND `quest` IN (27220,27219)) OR (`id`=23896 AND `quest`=27218) OR (`id`=23892 AND `quest` IN (27217,27216)) OR (`id`=23566 AND `quest` IN (27213,27212,27211,27210)) OR (`id`=41190 AND `quest` IN (25774,25756,25744,25813,25798,25796,25790)) OR (`id`=40082 AND `quest`=25762) OR (`id`=40554 AND `quest`=25517) OR (`id`=40027 AND `quest` IN (25488,25825)) OR (`id`=39992 AND `quest`=25486) OR (`id`=39946 AND `quest`=25479) OR (`id`=23600 AND `quest`=27340) OR (`id`=6546 AND `quest` IN (27429,27428,11212)) OR (`id`=23601 AND `quest` IN (27339,27336)) OR (`id`=23568 AND `quest` IN (27426,27427,27425)) OR (`id`=4944 AND `quest` IN (27288,27285,27286,27263,27262,27252,27247,27251,26687,27291,27430)) OR (`id`=5089 AND `quest`=27287) OR (`id`=4941 AND `quest`=27284) OR (`id`=4948 AND `quest`=27264) OR (`id`=23567 AND `quest`=27249) OR (`id`=4968 AND `quest` IN (27241,27239,27238)) OR (`id`=23569 AND `quest` IN (27237,27236,27235)) OR (`id`=4794 AND `quest` IN (1258,1222,1204)) OR (`id`=23951 AND `quest`=27246) OR (`id`=5086 AND `quest` IN (27234,27214)) OR (`id`=4792 AND `quest` IN (27186,27191,27184,27183,27215)) OR (`id`=41204 AND `quest`=25778) OR (`id`=23797 AND `quest` IN (27348,27347,27346)) OR (`id`=23723 AND `quest` IN (27245,27243,27242)) OR (`id`=23843 AND `quest` IN (27190,27189,27188)) OR (`id`=39118 AND `quest` IN (25182,25185,25175,25174)) OR (`id`=39188 AND `quest` IN (25151,25120)) OR (`id`=39218 AND `quest`=25153) OR (`id`=38152 AND `quest`=25163) OR (`id`=39155 AND `quest` IN (25108,25106,25104)) OR (`id`=37835 AND `quest` IN (25085,25084)) OR (`id`=37812 AND `quest` IN (24653,24606)) OR (`id`=37834 AND `quest`=24824) OR (`id`=41392 AND `quest`=25835);

UPDATE `gameobject_queststarter` SET `VerifiedBuild`=42979 WHERE (`id`=202975 AND `quest`=25524) OR (`id`=186426 AND `quest`=27412) OR (`id`=20992 AND `quest`=27252) OR (`id`=21042 AND `quest`=27263) OR (`id`=187273 AND `quest`=27262) OR (`id`=20985 AND `quest`=27246) OR (`id`=202598 AND `quest`=25185);

UPDATE `gameobject_questender` SET `VerifiedBuild`=42979 WHERE (`id`=202975 AND `quest`=25524) OR (`id`=202598 AND `quest`=25183);

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (41205,41204,40082,41184,41349,41348,41190,41058,46257,46253,46151,46148,46149,46154,23811,23753,23752,23751,41334,41302,41306,41299,41196,5089,41236,45227,14233,14231,23741,23789,4339,23786,14230,4363,4361,5088,23569,50957,26111,41131,41135,7394,4378,4379,4376,50342,23727,23720,23714,23593,40888,40885,50784,41078,41076,41081,41082,40431,4503,23583,3341,39697,38290,51061,10321,51069,50785,40432,41060,40092,40869,48138,40958,46206,50727,40959,23899,23900,143622,115918,23928,50892,14236,66439,66438,66436,66966,23864,12919,114992,115479,114991,130711,130534,114993,115477,115478,115580,115459,15552,115538,115539,38152,39220,39227,39238,39188,39213,39207,39218,39197,40512,4250,5933,39184,39182,39179,39177,23769,23768,5851,51924,4132,47383,47423,47426,47425,47390,47389,47424,39174,23701,23861,5849,14426,38315,23941,12716,4403,23620,24842,24840,24837,24836,24835,24834,24833,24843,24841,24839,24838,23637,5057,5859,37573,41199,40707,40705,51008,47388,41113,48179,48177,40663,40745,40743,48178,23595,23592,40408,23591,23679,23590,50875,23589,40700,40702,23892,40598,4397,4359,4362,23841,50764,40063,40062,40061,38109,38140,38190,38127,38119,38118,38115,38183,3376,3378,38215,3377));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(41205, 0, 0, 0, 21, 42979),
(41204, 0, 0, 0, 21, 42979),
(40082, 0, 0, 0, 21, 42979),
(41184, 0, 0, 0, 21, 42979),
(41349, 0, 0, 0, 21, 42979),
(41348, 0, 0, 0, 21, 42979),
(41190, 0, 0, 0, 21, 42979),
(41058, 0, 0, 0, 21, 42979),
(46257, 0, 0, 0, 21, 42979),
(46253, 0, 0, 0, 21, 42979),
(46151, 0, 0, 0, 21, 42979),
(46148, 0, 0, 0, 21, 42979),
(46149, 0, 0, 0, 21, 42979),
(46154, 0, 0, 0, 21, 42979),
(23811, 0, 0, 0, 23, 42979),
(23753, 0, 0, 0, 23, 42979),
(23752, 0, 0, 0, 23, 42979),
(23751, 0, 0, 0, 23, 42979),
(41334, 0, 0, 0, 21, 42979),
(41302, 0, 0, 0, 21, 42979),
(41306, 0, 0, 0, 21, 42979),
(41299, 0, 0, 0, 21, 42979),
(41196, 0, 0, 0, 21, 42979),
(5089, 0, 0, 0, 23, 42979),
(41236, 0, 0, 0, 21, 42979),
(45227, 0, 0, 0, 23, 42979),
(14233, 0, 0, 0, 23, 42979),
(14231, 0, 0, 0, 23, 42979),
(23741, 0, 0, 0, 23, 42979),
(23789, 0, 0, 0, 23, 42979),
(4339, 0, 0, 0, 23, 42979),
(23786, 0, 0, 0, 23, 42979),
(14230, 0, 0, 0, 23, 42979),
(4363, 0, 0, 0, 23, 42979),
(4361, 0, 0, 0, 23, 42979),
(5088, 0, 0, 0, 23, 42979),
(23569, 0, 0, 0, 23, 42979),
(50957, 0, 0, 0, 23, 42979),
(26111, 0, 0, 0, 23, 42979),
(41131, 0, 0, 0, 21, 42979),
(41135, 0, 0, 0, 21, 42979),
(7394, 0, 0, 0, 371, 42979),
(4378, 0, 0, 0, 23, 42979),
(4379, 0, 0, 0, 23, 42979),
(4376, 0, 0, 0, 23, 42979),
(50342, 0, 0, 0, 23, 42979),
(23727, 0, 0, 0, 23, 42979),
(23720, 0, 0, 0, 23, 42979),
(23714, 0, 0, 0, 23, 42979),
(23593, 0, 0, 0, 23, 42979),
(40888, 0, 0, 0, 21, 42979),
(40885, 0, 0, 0, 21, 42979),
(50784, 0, 0, 0, 23, 42979),
(41078, 0, 0, 0, 21, 42979),
(41076, 0, 0, 0, 21, 42979),
(41081, 0, 0, 0, 21, 42979),
(41082, 0, 0, 0, 21, 42979),
(40431, 0, 0, 0, 21, 42979),
(4503, 0, 0, 0, 23, 42979),
(23583, 0, 0, 0, 23, 42979),
(3341, 0, 0, 0, 16, 42979),
(39697, 0, 0, 0, 16, 42979),
(38290, 0, 0, 0, 16, 42979),
(51061, 0, 0, 0, 23, 42979),
(10321, 0, 0, 0, 23, 42979),
(51069, 0, 0, 0, 23, 42979),
(50785, 0, 0, 0, 21, 42979),
(40432, 0, 0, 0, 21, 42979),
(41060, 0, 0, 0, 21, 42979),
(40092, 0, 0, 0, 21, 42979),
(40869, 0, 0, 0, 21, 42979),
(48138, 0, 0, 0, 21, 42979),
(40958, 0, 0, 0, 21, 42979),
(46206, 0, 0, 0, 21, 42979),
(50727, 0, 0, 0, 21, 42979),
(40959, 0, 0, 0, 21, 42979),
(23899, 0, 0, 0, 23, 42979),
(23900, 0, 0, 0, 23, 42979),
(143622, 0, 0, 0, 482, 42979),
(115918, 0, 0, 0, 371, 42979),
(23928, 0, 0, 0, 23, 42979),
(50892, 0, 0, 0, 21, 42979),
(14236, 0, 0, 0, 23, 42979),
(66439, 0, 13, 13, 371, 42979),
(66438, 0, 13, 13, 371, 42979),
(66436, 0, 0, 0, 23, 42979),
(66966, 0, 13, 13, 371, 42979),
(23864, 0, 0, 0, 23, 42979),
(12919, 0, 0, 0, 23, 42979),
(114992, 0, 0, 0, 347, 42979),
(115479, 0, 0, 0, 347, 42979),
(114991, 0, 0, 0, 347, 42979),
(130711, 0, 0, 0, 708, 42979),
(130534, 0, 0, 0, 292, 42979),
(114993, 0, 0, 0, 347, 42979),
(115477, 0, 0, 0, 347, 42979),
(115478, 0, 0, 0, 347, 42979),
(115580, 0, 0, 0, 347, 42979),
(115459, 0, 0, 0, 347, 42979),
(15552, 0, 2, 2, 347, 42979),
(115538, 0, 0, 0, 347, 42979),
(115539, 0, 0, 0, 347, 42979),
(38152, 0, 0, 0, 16, 42979),
(39220, 0, 0, 0, 16, 42979),
(39227, 0, 0, 0, 16, 42979),
(39238, 0, 0, 0, 16, 42979),
(39188, 0, 0, 0, 16, 42979),
(39213, 0, 0, 0, 16, 42979),
(39207, 0, 0, 0, 16, 42979),
(39218, 0, 0, 0, 16, 42979),
(39197, 0, 0, 0, 16, 42979),
(40512, 0, 0, 0, 21, 42979),
(4250, 0, 0, 0, 21, 42979),
(5933, 0, 0, 0, 21, 42979),
(39184, 0, 0, 0, 16, 42979),
(39182, 0, 0, 0, 16, 42979),
(39179, 0, 0, 0, 16, 42979),
(39177, 0, 0, 0, 16, 42979),
(23769, 0, 0, 0, 23, 42979),
(23768, 0, 0, 0, 23, 42979),
(5851, 0, 0, 0, 16, 42979),
(51924, 0, 0, 0, 2108, 42979),
(4132, 0, 0, 0, 21, 42979),
(47383, 0, 0, 0, 21, 42979),
(47423, 0, 0, 0, 21, 42979),
(47426, 0, 0, 0, 21, 42979),
(47425, 0, 0, 0, 21, 42979),
(47390, 0, 0, 0, 21, 42979),
(47389, 0, 0, 0, 21, 42979),
(47424, 0, 0, 0, 21, 42979),
(39174, 0, 0, 0, 16, 42979),
(23701, 0, 0, 0, 23, 42979),
(23861, 0, 0, 0, 23, 42979),
(5849, 0, 0, 0, 16, 42979),
(14426, 0, 0, 0, 21, 42979),
(38315, 0, 0, 0, 208, 42979),
(23941, 0, 0, 0, 23, 42979),
(12716, 0, 0, 0, 23, 42979),
(4403, 0, 0, 0, 23, 42979),
(23620, 0, 0, 0, 23, 42979),
(24842, 0, 0, 0, 966, 42979),
(24840, 0, 0, 0, 966, 42979),
(24837, 0, 0, 0, 966, 42979),
(24836, 0, 0, 0, 966, 42979),
(24835, 0, 0, 0, 966, 42979),
(24834, 0, 0, 0, 966, 42979),
(24833, 0, 0, 0, 966, 42979),
(24843, 0, 0, 0, 966, 42979),
(24841, 0, 0, 0, 966, 42979),
(24839, 0, 0, 0, 966, 42979),
(24838, 0, 0, 0, 966, 42979),
(23637, 0, 0, 0, 23, 42979),
(5057, 0, 0, 0, 23, 42979),
(5859, 0, 0, 0, 16, 42979),
(37573, 0, 0, 0, 16, 42979),
(41199, 0, 0, 0, 21, 42979),
(40707, 0, 0, 0, 21, 42979),
(40705, 0, 0, 0, 21, 42979),
(51008, 0, 0, 0, 21, 42979),
(47388, 0, 0, 0, 21, 42979),
(41113, 0, 0, 0, 21, 42979),
(48179, 0, 0, 0, 21, 42979),
(48177, 0, 0, 0, 21, 42979),
(40663, 0, 0, 0, 21, 42979),
(40745, 0, 0, 0, 21, 42979),
(40743, 0, 0, 0, 21, 42979),
(48178, 0, 0, 0, 21, 42979),
(23595, 0, 0, 0, 23, 42979),
(23592, 0, 0, 0, 23, 42979),
(40408, 0, 0, 0, 22, 42979),
(23591, 0, 0, 0, 23, 42979),
(23679, 0, 0, 0, 23, 42979),
(23590, 0, 0, 0, 23, 42979),
(50875, 0, 0, 0, 23, 42979),
(23589, 0, 0, 0, 23, 42979),
(40700, 0, 0, 0, 21, 42979),
(40702, 0, 0, 0, 21, 42979),
(23892, 0, 0, 0, 23, 42979),
(40598, 0, 0, 0, 21, 42979),
(4397, 0, 0, 0, 23, 42979),
(4359, 0, 0, 0, 23, 42979),
(4362, 0, 0, 0, 23, 42979),
(23841, 0, 0, 0, 23, 42979),
(50764, 0, 0, 0, 23, 42979),
(40063, 0, 0, 0, 21, 42979),
(40062, 0, 0, 0, 21, 42979),
(40061, 0, 0, 0, 21, 42979),
(38109, 0, 0, 0, 16, 42979),
(38140, 0, 0, 0, 16, 42979),
(38190, 0, 0, 0, 16, 42979),
(38127, 0, 0, 0, 16, 42979),
(38119, 0, 0, 0, 16, 42979),
(38118, 0, 0, 0, 16, 42979),
(38115, 0, 0, 0, 16, 42979),
(38183, 0, 0, 0, 16, 42979),
(3376, 0, 0, 0, 16, 42979),
(3378, 0, 0, 0, 16, 42979),
(38215, 0, 0, 0, 16, 42979),
(3377, 0, 0, 0, 16, 42979);

UPDATE `trainer` SET `VerifiedBuild`=42979 WHERE `Id` IN (63, 29, 373, 56, 46);

DELETE FROM `creature_trainer` WHERE (`CreatureID`=4888 AND `MenuID`=10362 AND `OptionID`=0);
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(4888, 27, 10362, 0);

DELETE FROM `gossip_menu` WHERE (`MenuID`=11429 AND `TextID`=15917) OR (`MenuID`=11381 AND `TextID`=15851) OR (`MenuID`=11376 AND `TextID`=15847) OR (`MenuID`=14291 AND `TextID`=12930) OR (`MenuID`=15027 AND `TextID`=21713);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(11429, 15917, 42979), -- 40726 (Mazzer Stripscrew)
(11381, 15851, 42979), -- 39992 (Rendow)
(11376, 15847, 42979), -- 39946 (Caryssia Moonhunter)
(14291, 12930, 42979), -- 27704 (Horace Alder)
(15027, 21713, 42979); -- 63546 (Zidormi)

UPDATE `gossip_menu` SET `VerifiedBuild`=42979 WHERE (`MenuID`=11472 AND `TextID`=16004) OR (`MenuID`=11392 AND `TextID`=15867) OR (`MenuID`=11403 AND `TextID`=15887) OR (`MenuID`=11435 AND `TextID`=15932) OR (`MenuID`=11408 AND `TextID`=15893) OR (`MenuID`=11372 AND `TextID`=7778) OR (`MenuID`=2916 AND `TextID`=3590) OR (`MenuID`=8812 AND `TextID`=11311) OR (`MenuID`=8811 AND `TextID`=11309) OR (`MenuID`=8787 AND `TextID`=11243) OR (`MenuID`=8788 AND `TextID`=11245) OR (`MenuID`=8830 AND `TextID`=11403) OR (`MenuID`=5301 AND `TextID`=6333) OR (`MenuID`=14251 AND `TextID`=18067) OR (`MenuID`=8837 AND `TextID`=11432) OR (`MenuID`=8793 AND `TextID`=11264) OR (`MenuID`=8851 AND `TextID`=11492) OR (`MenuID`=8835 AND `TextID`=11426) OR (`MenuID`=8831 AND `TextID`=11406) OR (`MenuID`=4357 AND `TextID`=5579) OR (`MenuID`=8840 AND `TextID`=11457) OR (`MenuID`=8834 AND `TextID`=11424) OR (`MenuID`=11460 AND `TextID`=15981) OR (`MenuID`=12260 AND `TextID`=17221) OR (`MenuID`=11429 AND `TextID`=15918) OR (`MenuID`=11418 AND `TextID`=15898) OR (`MenuID`=11428 AND `TextID`=15915) OR (`MenuID`=8801 AND `TextID`=11281) OR (`MenuID`=11370 AND `TextID`=15841) OR (`MenuID`=9123 AND `TextID`=12334) OR (`MenuID`=8823 AND `TextID`=11365) OR (`MenuID`=6445 AND `TextID`=7638) OR (`MenuID`=14247 AND `TextID`=15111) OR (`MenuID`=14252 AND `TextID`=18049) OR (`MenuID`=14122 AND `TextID`=3977) OR (`MenuID`=14297 AND `TextID`=16569) OR (`MenuID`=4122 AND `TextID`=5049) OR (`MenuID`=12879 AND `TextID`=18108) OR (`MenuID`=12865 AND `TextID`=17774) OR (`MenuID`=12876 AND `TextID`=18105) OR (`MenuID`=12878 AND `TextID`=18107) OR (`MenuID`=12877 AND `TextID`=18106) OR (`MenuID`=12875 AND `TextID`=18104) OR (`MenuID`=12874 AND `TextID`=18103) OR (`MenuID`=12866 AND `TextID`=18095) OR (`MenuID`=12873 AND `TextID`=18102) OR (`MenuID`=12872 AND `TextID`=18101) OR (`MenuID`=12871 AND `TextID`=18100) OR (`MenuID`=12870 AND `TextID`=18099) OR (`MenuID`=12869 AND `TextID`=18098) OR (`MenuID`=12868 AND `TextID`=18097) OR (`MenuID`=12867 AND `TextID`=18096) OR (`MenuID`=12864 AND `TextID`=18094) OR (`MenuID`=12855 AND `TextID`=17774) OR (`MenuID`=12863 AND `TextID`=18093) OR (`MenuID`=12862 AND `TextID`=18092) OR (`MenuID`=12861 AND `TextID`=18091) OR (`MenuID`=12860 AND `TextID`=18090) OR (`MenuID`=12859 AND `TextID`=18089) OR (`MenuID`=12858 AND `TextID`=18088) OR (`MenuID`=12857 AND `TextID`=18087) OR (`MenuID`=12854 AND `TextID`=18086) OR (`MenuID`=8761 AND `TextID`=11126) OR (`MenuID`=15007 AND `TextID`=21215) OR (`MenuID`=11196 AND `TextID` IN (15589,15588)) OR (`MenuID`=11182 AND `TextID` IN (15564,15590)) OR (`MenuID`=11019 AND `TextID`=15317) OR (`MenuID`=11155 AND `TextID`=15528);

DELETE FROM `gameobject_template` WHERE `entry` IN (266102 /*Gnome Machine*/, 266116 /*Gnome Machine*/, 266115 /*Gnome Machine*/, 266114 /*Gnome Machine*/, 266113 /*Gnome Machine*/, 266107 /*Gnome Machine*/, 266109 /*Gnome Machine*/, 266108 /*Gnome Machine*/, 278902 /*Weathered Journal*/, 278897 /*Old Diving Helmet*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(266102, 5, 231, 'Gnome Machine', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 347, 42979), -- Gnome Machine
(266116, 5, 2089, 'Gnome Machine', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 347, 42979), -- Gnome Machine
(266115, 5, 9956, 'Gnome Machine', '', '', '', 0.400000005960464477, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 347, 42979), -- Gnome Machine
(266114, 5, 9460, 'Gnome Machine', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 347, 42979), -- Gnome Machine
(266113, 5, 2373, 'Gnome Machine', '', '', '', 1.5, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 347, 42979), -- Gnome Machine
(266107, 5, 7082, 'Gnome Machine', '', '', '', 1.899999976158142089, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 347, 42979), -- Gnome Machine
(266109, 5, 39012, 'Gnome Machine', '', '', '', 1.899999976158142089, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 347, 42979), -- Gnome Machine
(266108, 5, 7159, 'Gnome Machine', '', '', '', 1.899999976158142089, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 347, 42979), -- Gnome Machine
(278902, 9, 31810, 'Weathered Journal', '', '', '', 0.649999976158142089, 7475, 0, 1, 0, 54126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42979), -- Weathered Journal
(278897, 22, 9504, 'Old Diving Helmet', '', '', '', 1, 258852, -1, 0, 0, 0, 54118, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 708, 42979); -- Old Diving Helmet

UPDATE `gameobject_template` SET `VerifiedBuild`=42979 WHERE `entry` IN (202946, 202943, 202945, 203826, 202951, 203153, 203152, 70517, 101751, 202395, 186233, 186231, 186230, 177928, 186232, 21127, 20966, 182072, 182071, 20965, 21459, 186629, 20849, 186631, 186630, 20968, 187272, 202596, 186441, 61925, 61924, 148866, 138614, 61923, 61922, 61921, 61920, 61919, 202944, 334109, 334110, 182560, 197087, 197086, 332224, 323845, 323843, 197055, 197054, 197052, 323842, 323841, 323846, 197076, 197075, 197072, 197071, 197070, 197061, 197059, 197057, 197053, 197007, 323844, 323840, 197074, 197069, 197068, 197067, 197065, 197064, 197063, 197062, 197058, 197046, 197045, 197044, 197093, 197092, 197085, 197084, 197083, 197082, 197081, 197080, 197079, 197014, 105174, 311875, 197091, 197090, 197089, 197017, 197009, 105175, 197028, 197026, 197025, 335930, 322639, 197031, 197030, 197029, 197013, 197032, 197024, 197023, 197011, 205553, 197022, 197021, 197136, 197126, 201523, 201512, 201422, 4089, 4088, 123244, 4090, 4087, 179086, 186278, 21128, 36998, 36997, 36996, 3769, 36989, 36988, 36985, 36984, 36983, 36987, 36986, 36981, 36980, 36979, 169266, 169287, 169276, 169265, 36982, 169280, 208948, 169290, 148544, 169279, 169272, 169271, 148567, 22783, 177502, 177496, 177495, 177494, 22806, 22804, 22803, 169289, 169285, 169278, 169273, 148557, 148556, 148554, 148540, 169274, 169293, 169292, 169291, 169288, 169284, 169283, 169282, 169281, 169277, 169275, 169270, 169269, 169268, 169267, 169264, 148551, 148550, 148549, 148547, 177501, 177504, 177503, 177500, 177499, 177498, 177497, 142095, 22813, 22812, 22811, 186432, 186322, 186243, 20830, 20831, 187252, 177164, 186418, 176231, 186451, 205017, 202941, 202942, 202940, 203837, 179085, 202300, 202298, 179084, 20982, 20829, 180863, 180865, 180861, 186465, 186335, 214538, 185321, 186315, 186288, 186425, 20939, 178825, 202204, 202202, 202203, 202597, 202535, 202571, 202570, 202562, 202595, 141813, 201723, 201924, 201725, 3266);
UPDATE `gameobject_template` SET `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=186426; -- Wanted Poster
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=22311, `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=186301; -- Blackhoof Armaments
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=18400, `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=181626; -- Warped Crates
UPDATE `gameobject_template` SET `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=2555; -- Musty Scroll
UPDATE `gameobject_template` SET `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=22234; -- Signal Torch
UPDATE `gameobject_template` SET `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=186332; -- Ogre Remains
UPDATE `gameobject_template` SET `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=20727; -- Gizmorium Shipping Crate
UPDATE `gameobject_template` SET `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=174728; -- Damaged Crate
UPDATE `gameobject_template` SET `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=187273; -- Suspicious Hoofprint
UPDATE `gameobject_template` SET `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=21042; -- Theramore Guard Badge
UPDATE `gameobject_template` SET `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=20992; -- Black Shield
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=22364, `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=186450; -- Zeppelin Cargo
UPDATE `gameobject_template` SET `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=186266; -- Deserter Propaganda
UPDATE `gameobject_template` SET `ContentTuningId`=21, `VerifiedBuild`=42979 WHERE `entry`=207073; -- Ajamon's Portal to Tirth's Haunt
UPDATE `gameobject_template` SET `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=186283; -- Shipwreck Debris
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39337, `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=207475; -- Silverbound Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=186272; -- Tool Kit
UPDATE `gameobject_template` SET `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=186273; -- Damaged Diving Gear
UPDATE `gameobject_template` SET `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=20985; -- Loose Dirt
UPDATE `gameobject_template` SET `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=20925; -- Captain's Footlocker
UPDATE `gameobject_template` SET `ContentTuningId`=21, `VerifiedBuild`=42979 WHERE `entry`=207078; -- Ajamon's Portal to the Southsea Holdfast
UPDATE `gameobject_template` SET `ContentTuningId`=21, `VerifiedBuild`=42979 WHERE `entry` IN (206641, 206639, 206638, 206640); -- Refrigeration Pipe
UPDATE `gameobject_template` SET `ContentTuningId`=21, `VerifiedBuild`=42979 WHERE `entry`=203009; -- Pirate Accuracy Increasing Fire
UPDATE `gameobject_template` SET `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=2871; -- Seaworn Altar
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=22364, `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=186450; -- Zeppelin Cargo
UPDATE `gameobject_template` SET `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=20359; -- Egg of Onyxia
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39337, `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=207475; -- Silverbound Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=19904; -- Mok'Morokk's Snuff
UPDATE `gameobject_template` SET `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=19905; -- Mok'Morokk's Grog
UPDATE `gameobject_template` SET `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=19906; -- Mok'Morokk's Strongbox
UPDATE `gameobject_template` SET `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=186330; -- Stonemaul Banner
UPDATE `gameobject_template` SET `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=186329; -- Stonemaul Clan Banner
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=22364, `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=186450; -- Zeppelin Cargo
UPDATE `gameobject_template` SET `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=205267; -- Darkmist Egg
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=22311, `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=186301; -- Blackhoof Armaments
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=18400, `ContentTuningId`=23, `VerifiedBuild`=42979 WHERE `entry`=181626; -- Warped Crates
UPDATE `gameobject_template` SET `ContentTuningId`=16, `VerifiedBuild`=42979 WHERE `entry`=202598; -- Big Nasty Plunger
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=28414, `ContentTuningId`=16, `VerifiedBuild`=42979 WHERE `entry`=202567; -- Keg of Ol' Barkerstout
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=28393, `ContentTuningId`=16, `VerifiedBuild`=42979 WHERE `entry`=202542; -- Twinbraid's Tools
UPDATE `gameobject_template` SET `ContentTuningId`=16, `VerifiedBuild`=42979 WHERE `entry`=201963; -- Dwarven Artillery Gears
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=28392, `ContentTuningId`=16, `VerifiedBuild`=42979 WHERE `entry`=202533; -- Bael Modan Artifact
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=27798, `ContentTuningId`=16, `VerifiedBuild`=42979 WHERE `entry`=201971; -- Bael'dun Fortress Schematics

UPDATE `gameobject_questitem` SET `VerifiedBuild`=42979 WHERE (`Idx`=0 AND `GameObjectEntry` IN (202956,203090,186463,186301,181626,20727,174728,186450,186266,105174,105175,186272,186273,186423,20925,19904,19905,19906,186329,202567,202542,201924,202533,201971));

UPDATE `page_text` SET `VerifiedBuild`=42979 WHERE `ID` IN (3033, 579, 548, 507, 3032, 3036, 3034);

UPDATE `creature_queststarter` SET `VerifiedBuild`=43114 WHERE (`id`=39178 AND `quest` IN (25111,25112,25091,25115)) OR (`id`=38535 AND `quest` IN (25050,25048,25049,25121)) OR (`id`=38927 AND `quest` IN (25021,25032,25026,25025)) OR (`id`=40580 AND `quest` IN (25521,25522)) OR (`id`=39034 AND `quest` IN (25095,25094,25067)) OR (`id`=47580 AND `quest` IN (28127,28125,28140,28139,28136)) OR (`id`=47471 AND `quest` IN (28124,28098,28088,28087,28086)) OR (`id`=45442 AND `quest` IN (28085,27329)) OR (`id`=45277 AND `quest` IN (27357,27327,27323,27325,27320,28283,27318,27314,27312,27310)) OR (`id`=47745 AND `quest` IN (28160,28159,28158,28157)) OR (`id`=48208 AND `quest`=27316) OR (`id`=41444 AND `quest`=27275) OR (`id`=40712 AND `quest`=27068) OR (`id`=7804 AND `quest`=25556);

UPDATE `creature_questender` SET `VerifiedBuild`=43114 WHERE (`id`=39178 AND `quest` IN (25111,25112,25115)) OR (`id`=38535 AND `quest` IN (25050,25049,25048,27446)) OR (`id`=38927 AND `quest` IN (25021,25026,25025)) OR (`id`=40580 AND `quest` IN (25521,25522)) OR (`id`=19860 AND `quest` IN (25095,25094,25067)) OR (`id`=47580 AND `quest` IN (28127,28125,28124,28139,28136)) OR (`id`=47471 AND `quest` IN (28098,28088,28087,28086,28085)) OR (`id`=45442 AND `quest` IN (27329,27357)) OR (`id`=45277 AND `quest` IN (27327,27323,27325,27310,27320,27318,27316,27314,27312,27275)) OR (`id`=40027 AND `quest`=28160) OR (`id`=47745 AND `quest` IN (28159,28158,28157,28142)) OR (`id`=48208 AND `quest`=28283) OR (`id`=41392 AND `quest` IN (25873,25869)) OR (`id`=41444 AND `quest`=25871) OR (`id`=40712 AND `quest`=25556) OR (`id`=7804 AND `quest` IN (25032,25091));

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (39186,44869,5650,7407,7269,44929,5648,40712,47660,47580,40595,40591,38968,44557,38909,47508,47511,47509,47507,47504,47503,42895,39696,47483,39149,47745,47941,47736,39148,39374,39075,47486,50741,47718,5937,47487,45994,115146,47602,40581,128396,47528,47485,47481,47471,47479,7804,38927,40582,40580,44398,7270,5649,53604,7226,41242,45446,43677,8200,8199,46067,47510,45447,45468,45466,45463,47619,45442,45438,50748,66455,66454,66452,66453,45418,48208,45387,51359,45449,41392,41452,41446,41448,41447,41444,41421,47585,47621,47630,40791,46479,40511,47620,45448,47583,41464,45277,41463)) OR (`DifficultyID`=1 AND `Entry` IN (7246,8095));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(39186, 0, 0, 0, 28, 43114),
(44869, 0, 0, 0, 28, 43114),
(7246, 1, -1, 0, 218, 43114),
(8095, 1, 0, 1, 218, 43114),
(5650, 0, -1, -1, 218, 43114),
(7407, 0, 0, 0, 218, 43114),
(7269, 0, -1, -1, 218, 43114),
(44929, 0, -2, -2, 218, 43114),
(5648, 0, 0, 1, 218, 43114),
(40712, 0, -2, -2, 218, 43114),
(47660, 0, 0, 0, 21, 43114),
(47580, 0, 0, 0, 21, 43114),
(40595, 0, 0, 0, 21, 43114),
(40591, 0, 0, 0, 21, 43114),
(38968, 0, 0, 0, 28, 43114),
(44557, 0, 0, 0, 28, 43114),
(38909, 0, 0, 0, 28, 43114),
(47508, 0, 0, 0, 21, 43114),
(47511, 0, 0, 0, 21, 43114),
(47509, 0, 0, 0, 21, 43114),
(47507, 0, 0, 0, 21, 43114),
(47504, 0, 0, 0, 21, 43114),
(47503, 0, 0, 0, 21, 43114),
(42895, 0, 0, 0, 21, 43114),
(39696, 0, 0, 0, 28, 43114),
(47483, 0, 0, 0, 21, 43114),
(39149, 0, 0, 0, 28, 43114),
(47745, 0, 0, 0, 21, 43114),
(47941, 0, 0, 0, 21, 43114),
(47736, 0, 0, 0, 21, 43114),
(39148, 0, 0, 0, 28, 43114),
(39374, 0, 0, 0, 28, 43114),
(39075, 0, 0, 0, 28, 43114),
(47486, 0, 0, 0, 21, 43114),
(50741, 0, 0, 0, 21, 43114),
(47718, 0, 0, 0, 21, 43114),
(5937, 0, 0, 0, 21, 43114),
(47487, 0, 0, 0, 21, 43114),
(45994, 0, 0, 0, 21, 43114),
(115146, 0, 0, 0, 371, 43114),
(47602, 0, 0, 0, 21, 43114),
(40581, 0, 0, 0, 28, 43114),
(128396, 0, 0, 0, 371, 43114),
(47528, 0, 0, 0, 21, 43114),
(47485, 0, 0, 0, 21, 43114),
(47481, 0, 0, 0, 21, 43114),
(47471, 0, 0, 0, 21, 43114),
(47479, 0, 0, 0, 21, 43114),
(7804, 0, 0, 0, 28, 43114),
(38927, 0, 0, 0, 28, 43114),
(40582, 0, 0, 0, 28, 43114),
(40580, 0, 0, 0, 28, 43114),
(44398, 0, 0, 0, 28, 43114),
(7270, 0, 0, 0, 28, 43114),
(5649, 0, 0, 1, 218, 43114),
(53604, 0, 0, 0, 21, 43114),
(7226, 0, 0, 0, 28, 43114),
(41242, 0, 0, 0, 21, 43114),
(45446, 0, 0, 0, 21, 43114),
(43677, 0, 0, 0, 28, 43114),
(8200, 0, 0, 0, 28, 43114),
(8199, 0, 0, 0, 28, 43114),
(46067, 0, 0, 0, 21, 43114),
(47510, 0, 0, 0, 21, 43114),
(45447, 0, 0, 0, 21, 43114),
(45468, 0, 0, 0, 21, 43114),
(45466, 0, 0, 0, 21, 43114),
(45463, 0, 0, 0, 21, 43114),
(47619, 0, 0, 0, 21, 43114),
(45442, 0, 0, 0, 21, 43114),
(45438, 0, 0, 0, 21, 43114),
(50748, 0, 0, 0, 21, 43114),
(66455, 0, 14, 14, 371, 43114),
(66454, 0, 14, 14, 371, 43114),
(66452, 0, 0, 0, 21, 43114),
(66453, 0, 14, 14, 371, 43114),
(45418, 0, 0, 0, 21, 43114),
(48208, 0, 0, 0, 21, 43114),
(45387, 0, 0, 0, 21, 43114),
(51359, 0, 0, 0, 21, 43114),
(45449, 0, 0, 0, 21, 43114),
(41392, 0, 0, 0, 21, 43114),
(41452, 0, 0, 0, 21, 43114),
(41446, 0, 0, 0, 21, 43114),
(41448, 0, 0, 0, 21, 43114),
(41447, 0, 0, 0, 21, 43114),
(41444, 0, 0, 0, 21, 43114),
(41421, 0, 0, 0, 21, 43114),
(47585, 0, 0, 0, 21, 43114),
(47621, 0, 0, 0, 21, 43114),
(47630, 0, 0, 0, 21, 43114),
(40791, 0, 0, 0, 28, 43114),
(46479, 0, 0, 0, 28, 43114),
(40511, 0, 0, 0, 28, 43114),
(47620, 0, 0, 0, 21, 43114),
(45448, 0, 0, 0, 21, 43114),
(47583, 0, 0, 0, 21, 43114),
(41464, 0, 0, 0, 21, 43114),
(45277, 0, 0, 0, 21, 43114),
(41463, 0, 0, 0, 21, 43114);

UPDATE `trainer` SET `VerifiedBuild`=43114 WHERE `Id`=407;

UPDATE `gossip_menu` SET `VerifiedBuild`=43114 WHERE (`MenuID`=11111 AND `TextID`=15466) OR (`MenuID`=1143 AND `TextID`=1759) OR (`MenuID`=1142 AND `TextID`=1758) OR (`MenuID`=11426 AND `TextID`=15911) OR (`MenuID`=2890 AND `TextID`=3566) OR (`MenuID`=6094 AND `TextID`=7251) OR (`MenuID`=7083 AND `TextID`=8335) OR (`MenuID`=1301 AND `TextID`=1933) OR (`MenuID`=900 AND `TextID`=1471) OR (`MenuID`=7239 AND `TextID`=8539) OR (`MenuID`=12294 AND `TextID`=17275) OR (`MenuID`=12270 AND `TextID`=17234) OR (`MenuID`=12005 AND `TextID`=16827) OR (`MenuID`=12345 AND `TextID`=17348) OR (`MenuID`=12331 AND `TextID`=17328) OR (`MenuID`=12296 AND `TextID`=17278) OR (`MenuID`=12324 AND `TextID`=17319) OR (`MenuID`=12297 AND `TextID`=17279) OR (`MenuID`=12298 AND `TextID`=17280) OR (`MenuID`=11993 AND `TextID`=16812) OR (`MenuID`=11896 AND `TextID`=16688) OR (`MenuID`=11425 AND `TextID`=15909);

UPDATE `gameobject_template` SET `VerifiedBuild`=43114 WHERE `entry` IN (203820, 207003, 207002, 207004, 207005, 204733, 206743, 206742, 202201, 175670, 203228, 175673, 205432, 202206, 203221, 203057, 202304, 202303, 203055, 203060, 203056, 203059, 203053, 203052, 203049, 203050, 207436, 207433, 194147, 207437, 203051, 203058, 207250, 203054, 207458, 207457, 207455, 207453, 207451, 207448, 207447, 207446, 207444, 207442, 207441, 207440, 207439, 207438, 207435, 207434, 205116, 207443, 175675, 82138, 82136, 176324, 202207, 82137, 141071, 146084, 141074, 141072, 141070, 141073, 177227, 177226);
UPDATE `gameobject_template` SET `ContentTuningId`=218, `VerifiedBuild`=43114 WHERE `entry`=178829; -- Meeting Stone
UPDATE `gameobject_template` SET `ContentTuningId`=28, `VerifiedBuild`=43114 WHERE `entry`=205057; -- Shallow Grave
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27850, `ContentTuningId`=28, `VerifiedBuild`=43114 WHERE `entry`=202198; -- Steamwheedle Crate
UPDATE `gameobject_template` SET `ContentTuningId`=21, `VerifiedBuild`=43114 WHERE `entry`=205421; -- The Drums of War
UPDATE `gameobject_template` SET `ContentTuningId`=21, `VerifiedBuild`=43114 WHERE `entry`=205368; -- Grimtotem Weapon Rack
UPDATE `gameobject_template` SET `ContentTuningId`=21, `VerifiedBuild`=43114 WHERE `entry`=205416; -- The Writ of History
UPDATE `gameobject_template` SET `ContentTuningId`=21, `VerifiedBuild`=43114 WHERE `entry`=206834; -- Twilight Element of Fire
UPDATE `gameobject_template` SET `ContentTuningId`=21, `VerifiedBuild`=43114 WHERE `entry`=206832; -- Twilight Element of Air
UPDATE `gameobject_template` SET `ContentTuningId`=21, `VerifiedBuild`=43114 WHERE `entry`=206833; -- Twilight Element of Earth
UPDATE `gameobject_template` SET `ContentTuningId`=21, `VerifiedBuild`=43114 WHERE `entry`=206835; -- Twilight Element of Water
UPDATE `gameobject_template` SET `ContentTuningId`=21, `VerifiedBuild`=43114 WHERE `entry`=206758; -- Codemaster's Code Device
UPDATE `gameobject_template` SET `ContentTuningId`=21, `VerifiedBuild`=43114 WHERE `entry`=206767; -- Magatha's Bonds Controller
UPDATE `gameobject_template` SET `ContentTuningId`=28, `VerifiedBuild`=43114 WHERE `entry`=142122; -- Wanted Poster

UPDATE `gameobject_questitem` SET `VerifiedBuild`=43114 WHERE (`Idx`=0 AND `GameObjectEntry` IN (202198,203228,205421,205416,202959,202961,202960,202958,202957,206834,206832,206833,206835,206758));

UPDATE `creature_queststarter` SET `VerifiedBuild`=43206 WHERE (`id`=11811 AND `quest` IN (25061,24931)) OR (`id`=38706 AND `quest` IN (24953,24951,24933,25072,24932)) OR (`id`=38704 AND `quest` IN (26889,25166,26886,26887,25053,25054,25052)) OR (`id`=7784 AND `quest`=648);

UPDATE `creature_questender` SET `VerifiedBuild`=43206 WHERE (`id`=38706 AND `quest` IN (24953,24951,24933,25072,24932,26889)) OR (`id`=11811 AND `quest`=24931) OR (`id`=38704 AND `quest` IN (25166,26887,26886,25052,25053,25054,25121)) OR (`id`=7784 AND `quest`=351);

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (38748,38739,38718,20129,8205,39082,7770,38750,38749,44761,44763,44762,44861,38662,38660,38665,38704,38703,38824,38719,38823,8203,7803,44587,29873,29865,29867,29866,29868,40636,40593,40635,40632,38650,38649,7855,38648,7858,38646,7784));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(38748, 0, 0, 0, 28, 43206),
(38739, 0, 0, 0, 28, 43206),
(38718, 0, 0, 0, 28, 43206),
(20129, 0, 0, 0, 959, 43206),
(8205, 0, 0, 0, 28, 43206),
(39082, 0, 0, 0, 28, 43206),
(7770, 0, 0, 0, 28, 43206),
(38750, 0, 0, 0, 28, 43206),
(38749, 0, 0, 0, 28, 43206),
(44761, 0, 0, 0, 28, 43206),
(44763, 0, 0, 0, 28, 43206),
(44762, 0, 0, 0, 28, 43206),
(44861, 0, 0, 0, 827, 43206),
(38662, 0, 0, 0, 28, 43206),
(38660, 0, 0, 0, 28, 43206),
(38665, 0, 0, 0, 28, 43206),
(38704, 0, 0, 0, 28, 43206),
(38703, 0, 0, 0, 28, 43206),
(38824, 0, 0, 0, 28, 43206),
(38719, 0, 0, 0, 28, 43206),
(38823, 0, 0, 0, 28, 43206),
(8203, 0, 0, 0, 28, 43206),
(7803, 0, 0, 0, 28, 43206),
(44587, 0, 0, 0, 28, 43206),
(29873, 0, 0, 0, 243, 43206),
(29865, 0, -2, -1, 243, 43206),
(29867, 0, 0, 0, 243, 43206),
(29866, 0, -2, -1, 243, 43206),
(29868, 0, -2, -1, 243, 43206),
(40636, 0, 0, 0, 28, 43206),
(40593, 0, 0, 0, 28, 43206),
(40635, 0, 0, 0, 28, 43206),
(40632, 0, 0, 0, 28, 43206),
(38650, 0, 0, 0, 28, 43206),
(38649, 0, 0, 0, 28, 43206),
(7855, 0, 0, 0, 28, 43206),
(38648, 0, 0, 0, 28, 43206),
(7858, 0, 0, 0, 28, 43206),
(38646, 0, 0, 0, 28, 43206),
(7784, 0, 0, 0, 28, 43206);

UPDATE `gossip_menu` SET `VerifiedBuild`=43206 WHERE (`MenuID`=6646 AND `TextID`=7902) OR (`MenuID`=11069 AND `TextID`=15394) OR (`MenuID`=11402 AND `TextID`=15883) OR (`MenuID`=11876 AND `TextID`=16644);

UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=8439, `ContentTuningId`=28, `VerifiedBuild`=43206 WHERE `entry`=144053; -- Scrimshank's Surveying Gear
UPDATE `gameobject_template` SET `VerifiedBuild`=43206 WHERE `entry` IN (203821, 214502, 184531, 184530, 184532, 184006, 214613, 214612, 214503, 214500, 246871, 201947, 203824, 201944, 148879, 201946, 201945, 186904, 148880, 160411, 186902, 186901, 186897, 186900, 160420, 148878, 160414, 186903, 186922, 186899, 186896, 160418, 160416, 160419, 148877, 179496, 203022, 203019, 203021, 202263, 160415, 160413, 148876, 186218);
UPDATE `gameobject_template` SET `ContentTuningId`=28, `VerifiedBuild`=43206 WHERE `entry`=181095; -- Soothsaying for Dummies
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=8387, `ContentTuningId`=28, `VerifiedBuild`=43206 WHERE `entry`=142184; -- Captain's Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=8387, `ContentTuningId`=28, `VerifiedBuild`=43206 WHERE `entry`=142184; -- Captain's Chest

UPDATE `gameobject_questitem` SET `VerifiedBuild`=43206 WHERE (`Idx`=0 AND `GameObjectEntry` IN (144053,203022,203019,203021,202263));

UPDATE `creature_queststarter` SET `VerifiedBuild`=44325 WHERE (`id`=6019 AND `quest`=6134) OR (`id`=36034 AND `quest` IN (14372,14307)) OR (`id`=36056 AND `quest` IN (14328,14318,14314)) OR (`id`=36163 AND `quest` IN (14327,14325)) OR (`id`=35661 AND `quest` IN (14247,14246)) OR (`id`=11596 AND `quest`=5561) OR (`id`=11438 AND `quest`=5501) OR (`id`=36052 AND `quest` IN (14316,14312)) OR (`id`=36048 AND `quest` IN (14309,14304)) OR (`id`=36060 AND `quest` IN (14311,14306,14305)) OR (`id`=5638 AND `quest`=1456) OR (`id`=35773 AND `quest` IN (14302,14292,14260,14257,14256)) OR (`id`=35902 AND `quest` IN (14301,14284)) OR (`id`=35827 AND `quest` IN (14268,14264)) OR (`id`=35757 AND `quest` IN (14253,14252,14251));

UPDATE `creature_questender` SET `VerifiedBuild`=44325 WHERE (`id`=36056 AND `quest` IN (14327,14314,14312)) OR (`id`=36163 AND `quest` IN (14325,14318)) OR (`id`=36052 AND `quest`=14316) OR (`id`=35661 AND `quest`=14246) OR (`id`=35757 AND `quest` IN (14254,14253,14252,14251)) OR (`id`=11438 AND `quest`=5501) OR (`id`=11596 AND `quest`=5561) OR (`id`=36048 AND `quest` IN (14309,14304)) OR (`id`=36060 AND `quest` IN (14311,14306,14305)) OR (`id`=36034 AND `quest` IN (14307,14302)) OR (`id`=5638 AND `quest` IN (1456,1455)) OR (`id`=35773 AND `quest` IN (14301,14282,14257,14256,14365)) OR (`id`=35902 AND `quest` IN (14284,14292)) OR (`id`=35827 AND `quest` IN (14264,14260));

UPDATE `gameobject_queststarter` SET `VerifiedBuild`=44325 WHERE (`id`=195600 AND `quest`=14254) OR (`id`=35251 AND `quest`=1455);

UPDATE `gameobject_questender` SET `VerifiedBuild`=44325 WHERE (`id`=195600 AND `quest`=14247) OR (`id`=35251 AND `quest`=1454);

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (36163,36159,36142,36150,36134,36137,36183,14228,11560,11521,13836,36441,35898,35908,35902,35899,35900,35453,36079,4662,4643,4639,11438,13656,14229,35828,4716,4719,4715,4718,35842,35779,35879,4714,35773,35562,36059,41483,147583,36144,161919));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(36163, 0, 0, 0, 19, 44325),
(36159, 0, 0, 0, 19, 44325),
(36142, 0, 0, 0, 19, 44325),
(36150, 0, 0, 0, 19, 44325),
(36134, 0, 0, 0, 19, 44325),
(36137, 0, 0, 0, 19, 44325),
(36183, 0, 0, 0, 19, 44325),
(14228, 0, 0, 0, 19, 44325),
(11560, 0, 0, 0, 19, 44325),
(11521, 0, 0, 0, 19, 44325),
(13836, 0, 0, 0, 19, 44325),
(36441, 0, 0, 0, 19, 44325),
(35898, 0, 0, 0, 19, 44325),
(35908, 0, 0, 0, 19, 44325),
(35902, 0, 0, 0, 19, 44325),
(35899, 0, 0, 0, 19, 44325),
(35900, 0, 0, 0, 19, 44325),
(35453, 0, 0, 0, 19, 44325),
(36079, 0, 0, 0, 19, 44325),
(4662, 0, 0, 0, 19, 44325),
(4643, 0, 0, 0, 19, 44325),
(4639, 0, 0, 0, 19, 44325),
(11438, 0, 0, 0, 19, 44325),
(13656, 0, 0, 0, 19, 44325),
(14229, 0, 0, 0, 19, 44325),
(35828, 0, 0, 0, 19, 44325),
(4716, 0, 0, 0, 19, 44325),
(4719, 0, 0, 0, 19, 44325),
(4715, 0, 0, 0, 19, 44325),
(4718, 0, 0, 0, 19, 44325),
(35842, 0, 0, 0, 19, 44325),
(35779, 0, 0, 0, 19, 44325),
(35879, 0, 0, 0, 19, 44325),
(4714, 0, 0, 0, 19, 44325),
(35773, 0, 0, 0, 19, 44325),
(35562, 0, 0, 0, 881, 44325),
(36059, 0, 0, 0, 19, 44325),
(41483, 0, 0, 0, 19, 44325),
(147583, 0, 0, 0, 371, 44325),
(36144, 0, 0, 0, 19, 44325),
(161919, 0, 0, 0, 371, 44325);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=44325 WHERE (`DifficultyID`=0 AND `Entry` IN (35752,35811,51139,35384,35363,35621,35620,41353,4705,4667));

UPDATE `gossip_menu` SET `VerifiedBuild`=44325 WHERE (`MenuID`=10672 AND `TextID`=14792) OR (`MenuID`=3650 AND `TextID`=4449) OR (`MenuID`=8903 AND `TextID`=11714) OR (`MenuID`=10680 AND `TextID` IN (14834,14801)) OR (`MenuID`=10703 AND `TextID`=14849) OR (`MenuID`=10674 AND `TextID` IN (14968,14795));

UPDATE `gameobject_template` SET `VerifiedBuild`=44325 WHERE `entry` IN (74138, 177749, 177746, 51705, 51704, 50984, 74146, 3951, 3950, 3949, 3948, 3947, 3946, 3945, 3944, 175797, 175800, 175798, 175799, 195083, 195084, 175765, 175766, 175767, 204746, 204744, 195432, 195679, 179493, 195652, 179491, 195091, 195092, 204748, 204747, 204770, 204772, 204771, 175545, 174846, 3896, 3857, 3855, 3853, 3852, 3856, 204765, 3909, 3903, 3890, 204762, 204758, 174847, 3904, 3899, 3897, 3893, 204749, 204751, 204750);
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27444, `ContentTuningId`=19, `VerifiedBuild`=44325 WHERE `entry`=195440; -- Melonfruit
UPDATE `gameobject_template` SET `ContentTuningId`=19, `VerifiedBuild`=44325 WHERE `entry`=195497; -- Elune's Brazier
UPDATE `gameobject_template` SET `ContentTuningId`=19, `VerifiedBuild`=44325 WHERE `entry`=195433; -- Ancient Tablets
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27556, `ContentTuningId`=19, `VerifiedBuild`=44325 WHERE `entry`=195657; -- Ancient Tablet Fragment
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27557, `ContentTuningId`=19, `VerifiedBuild`=44325 WHERE `entry`=195659; -- Ancient Tablet Fragment
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27556, `ContentTuningId`=19, `VerifiedBuild`=44325 WHERE `entry`=195658; -- Ancient Tablet Fragment
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27556, `ContentTuningId`=19, `VerifiedBuild`=44325 WHERE `entry`=195656; -- Ancient Tablet Fragment
UPDATE `gameobject_template` SET `ContentTuningId`=19, `VerifiedBuild`=44325 WHERE `entry`=177786; -- Rackmore's Chest
UPDATE `gameobject_template` SET `ContentTuningId`=19, `VerifiedBuild`=44325 WHERE `entry`=177787; -- Rackmore's Log
UPDATE `gameobject_template` SET `ContentTuningId`=19, `VerifiedBuild`=44325 WHERE `entry`=35251; -- Karnitol's Chest
UPDATE `gameobject_template` SET `ContentTuningId`=19, `VerifiedBuild`=44325 WHERE `entry`=195531; -- Demonic Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27556, `ContentTuningId`=19, `VerifiedBuild`=44325 WHERE `entry`=195657; -- Ancient Tablet Fragment
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27557, `ContentTuningId`=19, `VerifiedBuild`=44325 WHERE `entry`=195659; -- Ancient Tablet Fragment
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27556, `ContentTuningId`=19, `VerifiedBuild`=44325 WHERE `entry`=195658; -- Ancient Tablet Fragment
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27556, `ContentTuningId`=19, `VerifiedBuild`=44325 WHERE `entry`=195656; -- Ancient Tablet Fragment

UPDATE `gameobject_questitem` SET `VerifiedBuild`=44325 WHERE (`Idx`=0 AND `GameObjectEntry` IN (195440,195659,195531));

DELETE FROM `creature_queststarter` WHERE (`id`=28126 AND `quest`=12515) OR (`id`=20102 AND `quest`=13484);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(28126, 12515, 43340), -- Nice Hat... offered Don Carlos
(20102, 13484, 43340); -- Spring Collectors offered Goblin Commoner

UPDATE `creature_queststarter` SET `VerifiedBuild`=43340 WHERE (`id`=9272 AND `quest` IN (24730,24723,24709,24708)) OR (`id`=38270 AND `quest` IN (24698,24697)) OR (`id`=38275 AND `quest` IN (24717,24722)) OR (`id`=38276 AND `quest` IN (24699,24700,24737)) OR (`id`=38277 AND `quest`=24701) OR (`id`=9998 AND `quest`=24736) OR (`id`=38263 AND `quest` IN (24721,24855,24687)) OR (`id`=38274 AND `quest` IN (24689,24686,24719)) OR (`id`=9619 AND `quest` IN (24733,24732,24731)) OR (`id`=10977 AND `quest` IN (24693,24691)) OR (`id`=9271 AND `quest`=24692) OR (`id`=9270 AND `quest` IN (24690,24740)) OR (`id`=9999 AND `quest`=24735) OR (`id`=9997 AND `quest`=24734) OR (`id`=10302 AND `quest` IN (24794,24742)) OR (`id`=38237 AND `quest` IN (24707,24706,24705,24704,24703)) OR (`id`=38255 AND `quest`=24705) OR (`id`=9117 AND `quest`=24720) OR (`id`=38269 AND `quest` IN (24854,28859)) OR (`id`=38502 AND `quest`=24695) OR (`id`=38504 AND `quest`=24694) OR (`id`=9623 AND `quest` IN (24926,24715)) OR (`id`=9618 AND `quest`=24714) OR (`id`=44833 AND `quest`=27003) OR (`id`=39034 AND `quest`=25513) OR (`id`=40109 AND `quest` IN (25566,25420,25565,25559)) OR (`id`=38578 AND `quest`=24911) OR (`id`=39059 AND `quest` IN (28881,25065,25063,25060,25062));

UPDATE `creature_questender` SET `VerifiedBuild`=43340 WHERE (`id`=9272 AND `quest` IN (24730,24698,24709,24708)) OR (`id`=38275 AND `quest` IN (24717,24693,24718)) OR (`id`=38277 AND `quest`=24701) OR (`id`=38276 AND `quest` IN (24700,24699,24737)) OR (`id`=9998 AND `quest`=24736) OR (`id`=9117 AND `quest` IN (24721,24720,24722,24723)) OR (`id`=9619 AND `quest` IN (24733,24732,24731)) OR (`id`=38263 AND `quest` IN (24855,24687,24689)) OR (`id`=38274 AND `quest` IN (24686,24719,24854)) OR (`id`=9271 AND `quest` IN (24692,24866)) OR (`id`=10977 AND `quest`=24691) OR (`id`=9270 AND `quest` IN (24690,24740,24865,24911)) OR (`id`=9997 AND `quest` IN (24735,24794)) OR (`id`=38270 AND `quest`=24697) OR (`id`=10302 AND `quest`=24742) OR (`id`=38237 AND `quest` IN (24706,24705,24704,24703)) OR (`id`=38502 AND `quest` IN (24695,24694)) OR (`id`=9618 AND `quest`=24926) OR (`id`=9623 AND `quest` IN (24715,24714)) OR (`id`=28126 AND `quest`=12515) OR (`id`=19860 AND `quest`=25513) OR (`id`=40109 AND `quest` IN (25421,25565,25559,25420,28881)) OR (`id`=39059 AND `quest` IN (25065,25063,25062,25060,25061));

UPDATE `gameobject_queststarter` SET `VerifiedBuild`=43340 WHERE (`id`=161526 AND `quest`=24865) OR (`id`=161521 AND `quest`=24866) OR (`id`=202474 AND `quest` IN (25070,25421));

UPDATE `gameobject_questender` SET `VerifiedBuild`=43340 WHERE (`id`=202135 AND `quest`=24702) OR (`id`=202264 AND `quest`=24734) OR (`id`=202474 AND `quest` IN (25070,25566));

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (38239,107836,9623,9272,38237,38373,6583,6498,28602,28092,38499,9684,9683,6551,38263,38205,40603,39077,38916,9622,38593,38666,38343,38504,9999,38498,40827,40815,39191,40109,38578,40826,6508,6507,38213,6581,38998,38307,38997,9376,38477,5475,38856,38849,38847,44611,44613,44612,38708,6553,6555,6554,6552,38305,38329,44842,62257,6499,8204,5459,5455,5460,5458,39159,5465,38240,44714,39061,41088,39020,41077,38346,5431,40527,40542,40547,6501,38255,39059,44417,40560,6504,38202,6502,62375,38238,6503,38254,4196,5451,5454));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(38239, 0, 0, 0, 32, 43340),
(107836, 0, 0, 0, 181, 43340),
(9623, 0, 0, 0, 32, 43340),
(9272, 0, 0, 0, 32, 43340),
(38237, 0, 0, 0, 32, 43340),
(38373, 0, 0, 0, 32, 43340),
(6583, 0, 0, 0, 32, 43340),
(6498, 0, 0, 0, 32, 43340),
(28602, 0, 0, 0, 49, 43340),
(28092, 0, 0, 0, 32, 43340),
(38499, 0, 0, 0, 32, 43340),
(9684, 0, 0, 0, 32, 43340),
(9683, 0, 0, 0, 32, 43340),
(6551, 0, 0, 0, 32, 43340),
(38263, 0, 0, 0, 32, 43340),
(38205, 0, 0, 0, 32, 43340),
(40603, 0, 0, 0, 28, 43340),
(39077, 0, 0, 0, 55, 43340),
(38916, 0, 0, 0, 28, 43340),
(9622, 0, 0, 0, 32, 43340),
(38593, 0, 0, 0, 32, 43340),
(38666, 0, 0, 0, 32, 43340),
(38343, 0, 0, 0, 32, 43340),
(38504, 0, 0, 0, 32, 43340),
(9999, 0, 0, 0, 32, 43340),
(38498, 0, 0, 0, 32, 43340),
(40827, 0, 0, 0, 881, 43340),
(40815, 0, 0, 0, 28, 43340),
(39191, 0, 0, 0, 28, 43340),
(40109, 0, 0, 0, 28, 43340),
(38578, 0, 0, 0, 28, 43340),
(40826, 0, 0, 0, 28, 43340),
(6508, 0, 0, 0, 32, 43340),
(6507, 0, 0, 0, 32, 43340),
(38213, 0, 0, 0, 32, 43340),
(6581, 0, 0, 0, 32, 43340),
(38998, 0, 0, 0, 28, 43340),
(38307, 0, 0, 0, 32, 43340),
(38997, 0, 0, 0, 28, 43340),
(9376, 0, 0, 0, 32, 43340),
(38477, 0, 0, 0, 32, 43340),
(5475, 0, 0, 0, 28, 43340),
(38856, 0, 0, 0, 28, 43340),
(38849, 0, 0, 0, 28, 43340),
(38847, 0, 0, 0, 28, 43340),
(44611, 0, 0, 0, 28, 43340),
(44613, 0, 0, 0, 28, 43340),
(44612, 0, 0, 0, 28, 43340),
(38708, 0, 0, 0, 32, 43340),
(6553, 0, 0, 0, 32, 43340),
(6555, 0, 0, 0, 32, 43340),
(6554, 0, 0, 0, 32, 43340),
(6552, 0, 0, 0, 32, 43340),
(38305, 0, 0, 0, 32, 43340),
(38329, 0, 0, 0, 32, 43340),
(44842, 0, 0, 0, 55, 43340),
(62257, 0, 0, 0, 371, 43340),
(6499, 0, 0, 0, 32, 43340),
(8204, 0, 0, 0, 28, 43340),
(5459, 0, 0, 0, 28, 43340),
(5455, 0, 0, 0, 28, 43340),
(5460, 0, 0, 0, 28, 43340),
(5458, 0, 0, 0, 28, 43340),
(39159, 0, 0, 0, 28, 43340),
(5465, 0, 0, 0, 28, 43340),
(38240, 0, 0, 0, 32, 43340),
(44714, 0, 0, 0, 28, 43340),
(39061, 0, 0, 0, 28, 43340),
(41088, 0, 0, 0, 28, 43340),
(39020, 0, 0, 0, 28, 43340),
(41077, 0, 0, 0, 28, 43340),
(38346, 0, 0, 0, 32, 43340),
(5431, 0, 0, 0, 28, 43340),
(40527, 0, 0, 0, 28, 43340),
(40542, 0, 0, 0, 28, 43340),
(40547, 0, 0, 0, 28, 43340),
(6501, 0, 0, 0, 32, 43340),
(38255, 0, 0, 0, 32, 43340),
(39059, 0, 0, 0, 28, 43340),
(44417, 0, 0, 0, 28, 43340),
(40560, 0, 0, 0, 28, 43340),
(6504, 0, 0, 0, 32, 43340),
(38202, 0, 0, 0, 32, 43340),
(6502, 0, 0, 0, 32, 43340),
(62375, 0, 0, 0, 371, 43340),
(38238, 0, 0, 0, 32, 43340),
(6503, 0, 0, 0, 32, 43340),
(38254, 0, 0, 0, 32, 43340),
(4196, 0, 0, 0, 28, 43340),
(5451, 0, 0, 0, 28, 43340),
(5454, 0, 0, 0, 28, 43340);

UPDATE `gossip_menu` SET `VerifiedBuild`=43340 WHERE (`MenuID`=2422 AND `TextID`=3094) OR (`MenuID`=11022 AND `TextID`=15325) OR (`MenuID`=11021 AND `TextID`=15324) OR (`MenuID`=20609 AND `TextID`=30907) OR (`MenuID`=2081 AND `TextID`=2734) OR (`MenuID`=2180 AND `TextID`=2811) OR (`MenuID`=2178 AND `TextID`=2810) OR (`MenuID`=11044 AND `TextID`=15353) OR (`MenuID`=2188 AND `TextID` IN (2821,2816)) OR (`MenuID`=2423 AND `TextID`=3095) OR (`MenuID`=2424 AND `TextID`=3096) OR (`MenuID`=2852 AND `TextID`=3546) OR (`MenuID`=2184 AND `TextID`=2817) OR (`MenuID`=10978 AND `TextID` IN (15277,15278)) OR (`MenuID`=10994 AND `TextID`=15291) OR (`MenuID`=10995 AND `TextID` IN (15294,15296)) OR (`MenuID`=11030 AND `TextID`=15333) OR (`MenuID`=11029 AND `TextID`=15332) OR (`MenuID`=10982 AND `TextID`=15270) OR (`MenuID`=10981 AND `TextID`=15269) OR (`MenuID`=10980 AND `TextID`=15268) OR (`MenuID`=10979 AND `TextID`=15267) OR (`MenuID`=10989 AND `TextID`=15266) OR (`MenuID`=2179 AND `TextID`=2810) OR (`MenuID`=12601 AND `TextID`=17736) OR (`MenuID`=7956 AND `TextID`=9774) OR (`MenuID`=21720 AND `TextID`=33093) OR (`MenuID`=5103 AND `TextID`=6155) OR (`MenuID`=11036 AND `TextID` IN (15345,15370)) OR (`MenuID`=11038 AND `TextID`=15349) OR (`MenuID`=11039 AND `TextID`=15348) OR (`MenuID`=11040 AND `TextID`=15350) OR (`MenuID`=11041 AND `TextID`=15348) OR (`MenuID`=11043 AND `TextID`=15348) OR (`MenuID`=11042 AND `TextID`=15351) OR (`MenuID`=11037 AND `TextID`=15346) OR (`MenuID`=11055 AND `TextID`=15376) OR (`MenuID`=11056 AND `TextID`=15375) OR (`MenuID`=11057 AND `TextID`=15374) OR (`MenuID`=11058 AND `TextID`=15373) OR (`MenuID`=11059 AND `TextID`=15372) OR (`MenuID`=11060 AND `TextID`=15371) OR (`MenuID`=11228 AND `TextID`=15639) OR (`MenuID`=2181 AND `TextID`=2812) OR (`MenuID`=2177 AND `TextID`=2810) OR (`MenuID`=2182 AND `TextID`=2813) OR (`MenuID`=12123 AND `TextID`=17029) OR (`MenuID`=9656 AND `TextID`=13079) OR (`MenuID`=11178 AND `TextID`=15559) OR (`MenuID`=10248 AND `TextID`=14231) OR (`MenuID`=12644 AND `TextID`=17789) OR (`MenuID`=12661 AND `TextID`=17749) OR (`MenuID`=11094 AND `TextID`=15444) OR (`MenuID`=11141 AND `TextID`=15504);

UPDATE `gameobject_template` SET `ContentTuningId`=683, `VerifiedBuild`=43340 WHERE `entry`=142144; -- Ghost Mushroom
UPDATE `gameobject_template` SET `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=201978; -- Sturdy Rock
UPDATE `gameobject_template` SET `VerifiedBuild`=43340 WHERE `entry` IN (202135, 201913, 201925, 201867, 204812, 201866, 169217, 202247, 277916, 277598, 207512, 203042, 175763, 144112, 175335, 141838, 202747, 202738, 175736, 141844, 175492, 35844, 175490, 175491, 149027, 149028, 149026, 149029, 202186, 202464, 206958, 247028);
UPDATE `gameobject_template` SET `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=174682; -- Beware of Pterrordax
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27848, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=202158; -- Discarded Supplies
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27848, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=202159; -- Discarded Supplies
UPDATE `gameobject_template` SET `ContentTuningId`=348, `VerifiedBuild`=43340 WHERE `entry`=266306; -- Forge
UPDATE `gameobject_template` SET `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=169216; -- Preserved Threshadon Carcass
UPDATE `gameobject_template` SET `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=164957; -- Eastern Crystal Pylon
UPDATE `gameobject_template` SET `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=166863; -- Fresh Threshadon Carcass
UPDATE `gameobject_template` SET `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=161505; -- A Wrecked Raft
UPDATE `gameobject_template` SET `ContentTuningId`=683, `VerifiedBuild`=43340 WHERE `entry`=123848; -- Ooze Covered Thorium Vein
UPDATE `gameobject_template` SET `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=161521; -- Research Equipment
UPDATE `gameobject_template` SET `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=202110; -- Enormous Dinosaur Bone
UPDATE `gameobject_template` SET `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=164910; -- Ornate Chest
UPDATE `gameobject_template` SET `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=202264; -- Ringo's Sack
UPDATE `gameobject_template` SET `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=161526; -- Crate of Foodstuffs
UPDATE `gameobject_template` SET `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=164955; -- Northern Crystal Pylon
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=10981, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=164659; -- Green Power Crystal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=10981, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=164779; -- Green Power Crystal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27806, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=201979; -- Un'Goro Coconut
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27848, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=202160; -- Discarded Supplies
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27804, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=201975; -- Tarblossom
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=10983, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=164661; -- Yellow Power Crystal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=10983, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=164781; -- Yellow Power Crystal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=10982, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=164780; -- Red Power Crystal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=10982, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=164660; -- Red Power Crystal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=10103, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=161527; -- Dinosaur Bone
UPDATE `gameobject_template` SET `name`='Dweller\'s Crate', `Data1`=0, `Data30`=27807, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=202065; -- "Damsel's" "Purse"
UPDATE `gameobject_template` SET `name`='Dweller\'s Crate', `Data1`=0, `Data30`=27807, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=202065; -- "Damsel's" "Purse"
UPDATE `gameobject_template` SET `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=164956; -- Western Crystal Pylon
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=10983, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=164781; -- Yellow Power Crystal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=10983, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=164661; -- Yellow Power Crystal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=10103, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=161527; -- Dinosaur Bone
UPDATE `gameobject_template` SET `type`=50, `Data0`=2863, `Data1`=51299, `Data3`=0, `Data4`=190, `Data5`=240, `Data6`=30, `Data12`=683, `Data13`=1, `Data18`=10, `Data19`=0, `ContentTuningId`=683, `VerifiedBuild`=43340 WHERE `entry`=123309; -- Ooze Covered Truesilver Deposit
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=10982, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=164660; -- Red Power Crystal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=10982, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=164780; -- Red Power Crystal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=10981, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=164659; -- Green Power Crystal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=10981, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=164779; -- Green Power Crystal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27829, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=202082; -- Ravasaur Matriarch's Nest
UPDATE `gameobject_template` SET `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=202197; -- Diemetradon Observation Lever
UPDATE `gameobject_template` SET `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=202196; -- Gorilla Observation Lever
UPDATE `gameobject_template` SET `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=202195; -- Pterrordax Observation Lever
UPDATE `gameobject_template` SET `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=202187; -- Bloodpetal Observation Lever
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27806, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=201979; -- Un'Goro Coconut
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=10981, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=164659; -- Green Power Crystal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=10981, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=164779; -- Green Power Crystal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27804, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=201975; -- Tarblossom
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=10983, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=164781; -- Yellow Power Crystal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=10983, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=164661; -- Yellow Power Crystal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27849, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=202165; -- Suspicious Mound of Dirt
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=10103, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=161527; -- Dinosaur Bone
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=10982, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=164780; -- Red Power Crystal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=10982, `ContentTuningId`=32, `VerifiedBuild`=43340 WHERE `entry`=164660; -- Red Power Crystal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27245, `ContentTuningId`=28, `VerifiedBuild`=43340 WHERE `entry`=195037; -- Silithid Egg
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=28238, `ContentTuningId`=28, `VerifiedBuild`=43340 WHERE `entry`=202441; -- Jang'thraze the Protector
UPDATE `gameobject_template` SET `ContentTuningId`=254, `VerifiedBuild`=43340 WHERE `entry`=205562; -- Meeting Stone
UPDATE `gameobject_template` SET `ContentTuningId`=28, `VerifiedBuild`=43340 WHERE `entry`=202615; -- Sand Trap
UPDATE `gameobject_template` SET `ContentTuningId`=28, `VerifiedBuild`=43340 WHERE `entry`=202474; -- Antediluvean Chest
UPDATE `gameobject_template` SET `ContentTuningId`=28, `VerifiedBuild`=43340 WHERE `entry`=142343; -- Uldum Pedestal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=28233, `ContentTuningId`=28, `VerifiedBuild`=43340 WHERE `entry`=202420; -- Ancient Hieroglyphs
UPDATE `gameobject_template` SET `ContentTuningId`=28, `VerifiedBuild`=43340 WHERE `entry`=202407; -- Sandscraper's Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=28367, `ContentTuningId`=28, `VerifiedBuild`=43340 WHERE `entry`=202470; -- Bilgewater Footlocker

UPDATE `gameobject_questitem` SET `VerifiedBuild`=43340 WHERE (`Idx`=0 AND `GameObjectEntry` IN (202158,202159,166863,164910,195022,201979,202160,201975,161527,202065,202165,195037,202420));

UPDATE `page_text` SET `VerifiedBuild`=43340 WHERE `ID` IN (3601, 3600, 3599, 3705, 3704, 3703, 3702, 3701, 3607, 3606);

UPDATE `creature_queststarter` SET `VerifiedBuild`=43345 WHERE (`id`=15194 AND `quest` IN (8323,8287,8279)) OR (`id`=15170 AND `quest` IN (8314,8309)) OR (`id`=15171 AND `quest`=8310) OR (`id`=15183 AND `quest` IN (8285,8284)) OR (`id`=15181 AND `quest` IN (8306,8304)) OR (`id`=15190 AND `quest`=8282) OR (`id`=5638 AND `quest`=1454) OR (`id`=5752 AND `quest`=14365) OR (`id`=5396 AND `quest` IN (14361,14387)) OR (`id`=5642 AND `quest`=14354) OR (`id`=36410 AND `quest`=14384) OR (`id`=17082 AND `quest`=9415) OR (`id`=50588 AND `quest`=28867) OR (`id`=15270 AND `quest` IN (8320,8321)) OR (`id`=15306 AND `quest`=8318) OR (`id`=15189 AND `quest` IN (8277,8278)) OR (`id`=15191 AND `quest` IN (8280,8281)) OR (`id`=35757 AND `quest` IN (14253,14252,14251));

UPDATE `creature_questender` SET `VerifiedBuild`=43345 WHERE (`id`=15194 AND `quest` IN (8323,8279,8285)) OR (`id`=15171 AND `quest`=8310) OR (`id`=15170 AND `quest` IN (8309,8308)) OR (`id`=15181 AND `quest` IN (8306,8304,8287)) OR (`id`=15306 AND `quest` IN (8319,8318)) OR (`id`=15190 AND `quest`=8282) OR (`id`=15183 AND `quest` IN (8284,8314)) OR (`id`=15189 AND `quest` IN (8278,8277)) OR (`id`=15191 AND `quest` IN (8281,8280,28859)) OR (`id`=15270 AND `quest` IN (8321,8320)) OR (`id`=5396 AND `quest` IN (14361,14364,14362)) OR (`id`=5642 AND `quest` IN (14354,14387)) OR (`id`=5752 AND `quest`=14384) OR (`id`=36410 AND `quest`=25938) OR (`id`=15182 AND `quest`=8283) OR (`id`=17080 AND `quest`=9415);

UPDATE `gameobject_queststarter` SET `VerifiedBuild`=43345 WHERE (`id`=195497 AND `quest` IN (14359,14358)) OR (`id`=195517 AND `quest`=14357) OR (`id`=195438 AND `quest`=14193) OR (`id`=180448 AND `quest`=8283);

UPDATE `gameobject_questender` SET `VerifiedBuild`=43345 WHERE (`id`=195517 AND `quest`=14357) OR (`id`=195497 AND `quest`=14358);

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (171396,14474,62524,162728,15215,15609,14472,15169,14347,51375,15611,14475,50744,35752,35811,51139,35750,15610,11726,50897,15196,35384,35647,41353,35621,35620,41355,35581,35381,41356,35363,15443,17068,17080,15444,15442,17090,15903,15441,17765,14478,50745,36419,11746,11725,11727,11728,11729,15308,14477,11803,41487,41664,41638,41637,41635,48687,44177,43019,35138,15801,41627,15693,133263,15454,34911,34898,34897,11747,49746,132886,36416,36410,15221,15172,15171,15170,15222,17070,17079,15615,15613,18199,15612,17766,15616,15617,11730,15200,14473,14479,11741,50743,11733,11732,11734,15194,14476,11731,11723,11737,11721,11739,15293,12199,11804,11882,11881,12178,12179,11880,11883,11745,15201,15202,15213,11805,12956,13220,11736,4667));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(171396, 0, 0, 0, 482, 43345),
(14474, 0, 0, 0, 36, 43345),
(62524, 0, 0, 0, 371, 43345),
(162728, 0, 0, 0, 703, 43345),
(15215, 0, 0, 0, 36, 43345),
(15609, 0, 0, 0, 36, 43345),
(14472, 0, 0, 0, 36, 43345),
(15169, 0, 0, 0, 36, 43345),
(14347, 0, 0, 0, 36, 43345),
(51375, 0, 0, 0, 36, 43345),
(15611, 0, 0, 0, 36, 43345),
(14475, 0, 0, 0, 36, 43345),
(50744, 0, 0, 0, 36, 43345),
(35752, 0, 0, 0, 19, 43345),
(35811, 0, 0, 0, 19, 43345),
(51139, 0, 0, 0, 19, 43345),
(35750, 0, 0, 0, 19, 43345),
(15610, 0, 0, 0, 36, 43345),
(11726, 0, 0, 0, 36, 43345),
(50897, 0, 0, 0, 36, 43345),
(15196, 0, 0, 0, 36, 43345),
(35384, 0, 0, 0, 19, 43345),
(35647, 0, 0, 0, 19, 43345),
(41353, 0, 0, 0, 19, 43345),
(35621, 0, 0, 0, 19, 43345),
(35620, 0, 0, 0, 19, 43345),
(41355, 0, 0, 0, 19, 43345),
(35581, 0, 0, 0, 19, 43345),
(35381, 0, 0, 0, 19, 43345),
(41356, 0, 0, 0, 19, 43345),
(35363, 0, 0, 0, 19, 43345),
(15443, 0, 0, 0, 36, 43345),
(17068, 0, 0, 0, 36, 43345),
(17080, 0, 0, 0, 36, 43345),
(15444, 0, 0, 0, 36, 43345),
(15442, 0, 0, 0, 36, 43345),
(17090, 0, 0, 0, 36, 43345),
(15903, 0, 0, 0, 36, 43345),
(15441, 0, 0, 0, 36, 43345),
(17765, 0, 0, 0, 36, 43345),
(14478, 0, 0, 0, 36, 43345),
(50745, 0, 0, 0, 36, 43345),
(36419, 0, 0, 0, 19, 43345),
(11746, 0, 0, 0, 36, 43345),
(11725, 0, 0, 0, 36, 43345),
(11727, 0, 0, 0, 36, 43345),
(11728, 0, 0, 0, 36, 43345),
(11729, 0, 0, 0, 36, 43345),
(15308, 0, 0, 0, 36, 43345),
(14477, 0, 0, 0, 36, 43345),
(11803, 0, 0, 0, 36, 43345),
(41487, 0, 0, 0, 14, 43345),
(41664, 0, 0, 0, 14, 43345),
(41638, 0, 0, 0, 14, 43345),
(41637, 0, 0, 0, 14, 43345),
(41635, 0, 0, 0, 14, 43345),
(48687, 0, 0, 0, 81, 43345),
(44177, 0, 0, 0, 14, 43345),
(43019, 0, 0, 0, 14, 43345),
(35138, 0, 0, 0, 881, 43345),
(15801, 0, 0, 0, 664, 43345),
(41627, 0, 0, 0, 2108, 43345),
(15693, 0, 0, 0, 36, 43345),
(133263, 0, 0, 0, 36, 43345),
(15454, 0, 0, 0, 36, 43345),
(34911, 0, 0, 0, 14, 43345),
(34898, 0, 0, 0, 14, 43345),
(34897, 0, 0, 0, 14, 43345),
(11747, 0, 0, 0, 36, 43345),
(49746, 0, 0, 0, 81, 43345),
(132886, 0, 0, 0, 492, 43345),
(36416, 0, 0, 0, 19, 43345),
(36410, 0, 0, 0, 19, 43345),
(15221, 0, 0, 0, 36, 43345),
(15172, 0, 0, 0, 36, 43345),
(15171, 0, 0, 0, 36, 43345),
(15170, 0, 0, 0, 36, 43345),
(15222, 0, 0, 0, 36, 43345),
(17070, 0, 0, 0, 36, 43345),
(17079, 0, 0, 0, 36, 43345),
(15615, 0, 0, 0, 36, 43345),
(15613, 0, 0, 0, 36, 43345),
(18199, 0, 0, 0, 36, 43345),
(15612, 0, 0, 0, 36, 43345),
(17766, 0, 0, 0, 36, 43345),
(15616, 0, 0, 0, 36, 43345),
(15617, 0, 0, 0, 36, 43345),
(11730, 0, 0, 0, 36, 43345),
(15200, 0, 0, 0, 36, 43345),
(14473, 0, 0, 0, 36, 43345),
(14479, 0, 0, 0, 36, 43345),
(11741, 0, 0, 0, 36, 43345),
(50743, 0, 0, 0, 36, 43345),
(11733, 0, 0, 0, 36, 43345),
(11732, 0, 0, 0, 36, 43345),
(11734, 0, 0, 0, 36, 43345),
(15194, 0, 0, 0, 36, 43345),
(14476, 0, 0, 0, 36, 43345),
(11731, 0, 0, 0, 36, 43345),
(11723, 0, 0, 0, 36, 43345),
(11737, 0, 0, 0, 36, 43345),
(11721, 0, 0, 0, 36, 43345),
(11739, 0, 0, 0, 36, 43345),
(15293, 0, 0, 0, 36, 43345),
(12199, 0, 0, 0, 36, 43345),
(11804, 0, 0, 0, 36, 43345),
(11882, 0, 0, 0, 36, 43345),
(11881, 0, 0, 0, 36, 43345),
(12178, 0, 0, 0, 36, 43345),
(12179, 0, 0, 0, 36, 43345),
(11880, 0, 0, 0, 36, 43345),
(11883, 0, 0, 0, 36, 43345),
(11745, 0, 0, 0, 36, 43345),
(15201, 0, 0, 0, 36, 43345),
(15202, 0, 0, 0, 36, 43345),
(15213, 0, 0, 0, 36, 43345),
(11805, 0, 0, 0, 36, 43345),
(12956, 0, 0, 0, 36, 43345),
(13220, 0, 0, 0, 36, 43345),
(11736, 0, 0, 0, 36, 43345),
(4667, 0, 0, 0, 19, 43345);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=43345 WHERE (`Entry`=41651 AND `DifficultyID`=0);

DELETE FROM `gossip_menu` WHERE (`MenuID`=22134 AND `TextID`=33891);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(22134, 33891, 43345); -- 133263 (Rhonormu)

UPDATE `gossip_menu` SET `VerifiedBuild`=43345 WHERE (`MenuID`=6596 AND `TextID`=7817) OR (`MenuID`=6534 AND `TextID`=7736) OR (`MenuID`=6561 AND `TextID`=7770) OR (`MenuID`=6583 AND `TextID`=7839) OR (`MenuID`=6528 AND `TextID`=7730) OR (`MenuID`=6533 AND `TextID`=7735) OR (`MenuID`=6692 AND `TextID`=8065) OR (`MenuID`=6530 AND `TextID`=7732) OR (`MenuID`=5703 AND `TextID`=6870) OR (`MenuID`=5704 AND `TextID`=6869) OR (`MenuID`=5701 AND `TextID`=6868) OR (`MenuID`=5702 AND `TextID`=6867) OR (`MenuID`=5687 AND `TextID`=6844) OR (`MenuID`=5688 AND `TextID`=6843) OR (`MenuID`=5689 AND `TextID`=6842) OR (`MenuID`=5675 AND `TextID`=6812) OR (`MenuID`=6552 AND `TextID`=7768) OR (`MenuID`=6553 AND `TextID`=7767) OR (`MenuID`=6554 AND `TextID`=7766) OR (`MenuID`=6555 AND `TextID`=7765) OR (`MenuID`=6556 AND `TextID`=7764) OR (`MenuID`=6557 AND `TextID`=7763) OR (`MenuID`=6558 AND `TextID`=7762) OR (`MenuID`=6545 AND `TextID`=7761) OR (`MenuID`=6546 AND `TextID`=7760) OR (`MenuID`=6547 AND `TextID`=7759) OR (`MenuID`=6548 AND `TextID`=7758) OR (`MenuID`=6549 AND `TextID`=7757) OR (`MenuID`=6550 AND `TextID`=7756) OR (`MenuID`=6551 AND `TextID`=7755) OR (`MenuID`=6544 AND `TextID` IN (7752,7753)) OR (`MenuID`=6532 AND `TextID`=7734) OR (`MenuID`=10639 AND `TextID`=14739) OR (`MenuID`=5302 AND `TextID`=6334) OR (`MenuID`=6563 AND `TextID`=7778) OR (`MenuID`=6531 AND `TextID`=7751) OR (`MenuID`=6564 AND `TextID`=7779) OR (`MenuID`=6526 AND `TextID`=7728) OR (`MenuID`=6529 AND `TextID`=7731) OR (`MenuID`=6796 AND `TextID`=8114) OR (`MenuID`=6541 AND `TextID`=7746) OR (`MenuID`=6527 AND `TextID`=7729) OR (`MenuID`=7045 AND `TextID`=8280) OR (`MenuID`=6525 AND `TextID`=7727) OR (`MenuID`=7418 AND `TextID`=8960) OR (`MenuID`=6567 AND `TextID`=7782) OR (`MenuID`=6585 AND `TextID`=7804) OR (`MenuID`=6586 AND `TextID`=7803) OR (`MenuID`=6587 AND `TextID`=7802) OR (`MenuID`=6588 AND `TextID`=7801) OR (`MenuID`=6923 AND `TextID`=8212) OR (`MenuID`=6623 AND `TextID`=7874) OR (`MenuID`=6540 AND `TextID`=7744) OR (`MenuID`=6542 AND `TextID`=7749) OR (`MenuID`=6543 AND `TextID`=7754) OR (`MenuID`=10674 AND `TextID`=14795);

UPDATE `gameobject_questitem` SET `VerifiedBuild`=43345 WHERE (`Idx`=0 AND `GameObjectEntry` IN (195531,195519,195440,178553,180436,180501,180435,179565));

UPDATE `page_text` SET `VerifiedBuild`=43345 WHERE `ID`=2807;

UPDATE `creature_queststarter` SET `VerifiedBuild`=44730 WHERE (`id`=40032 AND `quest` IN (25397,25396,25394,27131,27129,27063,25447)) OR (`id`=40035 AND `quest` IN (25654,25448)) OR (`id`=36487 AND `quest`=14410) OR (`id`=36034 AND `quest`=14381) OR (`id`=36329 AND `quest` IN (14380,14378,14373,14374)) OR (`id`=36378 AND `quest`=14379) OR (`id`=36398 AND `quest` IN (14394,14393)) OR (`id`=36196 AND `quest`=14332) OR (`id`=12277 AND `quest`=6132) OR (`id`=36185 AND `quest`=14329);

UPDATE `creature_questender` SET `VerifiedBuild`=44730 WHERE (`id`=40032 AND `quest` IN (25394,25447,14410)) OR (`id`=40035 AND `quest` IN (25654,25448)) OR (`id`=36034 AND `quest` IN (14381,14380)) OR (`id`=36329 AND `quest` IN (14378,14373,14374,14372)) OR (`id`=36378 AND `quest`=14379) OR (`id`=36444 AND `quest`=14394) OR (`id`=36398 AND `quest` IN (14393,14332)) OR (`id`=36196 AND `quest`=14330) OR (`id`=6019 AND `quest` IN (6132,6134)) OR (`id`=36185 AND `quest` IN (14329,14328));

UPDATE `gameobject_queststarter` SET `VerifiedBuild`=44730 WHERE (`id`=196393 AND `quest`=14333);

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (4690,35827,4712,4711,36232,36068,12347,36353,7772,5345,7773,11937,32589,41443,36493,36487,36486,36485,36489,36446,36445,36444,36442,8075,36400,36401,36402,36413,36398,36415,36412,36414,36447,36196,11688,1182,36490,35454,5601,41872,4644,41873,4694,11559,11561,12241,12277,11777,12239,4659,11778,11787,11788,12240,4658,11685,13718,4657,11686,11687,11782,13717,5771,5760));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(4690, 0, 0, 0, 19, 44730),
(35827, 0, 0, 0, 19, 44730),
(4712, 0, 0, 0, 19, 44730),
(4711, 0, 0, 0, 19, 44730),
(36232, 0, 0, 0, 19, 44730),
(36068, 0, 0, 0, 19, 44730),
(12347, 0, 0, 0, 19, 44730),
(36353, 0, 0, 0, 19, 44730),
(7772, 0, 0, 0, 22, 44730),
(5345, 0, 0, 0, 22, 44730),
(7773, 0, 0, 0, 22, 44730),
(11937, 0, 0, 0, 19, 44730),
(32589, 0, 0, 0, 371, 44730),
(41443, 0, 0, 0, 19, 44730),
(36493, 0, 0, 0, 19, 44730),
(36487, 0, 0, 0, 19, 44730),
(36486, 0, 0, 0, 19, 44730),
(36485, 0, 0, 0, 19, 44730),
(36489, 0, 0, 0, 19, 44730),
(36446, 0, 0, 0, 19, 44730),
(36445, 0, 0, 0, 19, 44730),
(36444, 0, 0, 0, 19, 44730),
(36442, 0, 0, 0, 19, 44730),
(8075, 0, 0, 0, 22, 44730),
(36400, 0, 0, 0, 19, 44730),
(36401, 0, 0, 0, 19, 44730),
(36402, 0, 0, 0, 19, 44730),
(36413, 0, 0, 0, 19, 44730),
(36398, 0, 0, 0, 19, 44730),
(36415, 0, 0, 0, 19, 44730),
(36412, 0, 0, 0, 19, 44730),
(36414, 0, 0, 0, 19, 44730),
(36447, 0, 0, 0, 19, 44730),
(36196, 0, 0, 0, 19, 44730),
(11688, 0, 0, 0, 19, 44730),
(1182, 0, 0, 0, 19, 44730),
(36490, 0, 0, 0, 19, 44730),
(35454, 0, 0, 0, 19, 44730),
(5601, 0, 0, 0, 19, 44730),
(41872, 0, 0, 0, 19, 44730),
(4644, 0, 0, 0, 19, 44730),
(41873, 0, 0, 0, 19, 44730),
(4694, 0, 0, 0, 19, 44730),
(11559, 0, 0, 0, 19, 44730),
(11561, 0, 0, 0, 19, 44730),
(12241, 0, 0, 0, 19, 44730),
(12277, 0, 0, 0, 19, 44730),
(11777, 0, 0, 0, 19, 44730),
(12239, 0, 0, 0, 19, 44730),
(4659, 0, 0, 0, 19, 44730),
(11778, 0, 0, 0, 19, 44730),
(11787, 0, 0, 0, 19, 44730),
(11788, 0, 0, 0, 19, 44730),
(12240, 0, 0, 0, 19, 44730),
(4658, 0, 0, 0, 19, 44730),
(11685, 0, 0, 0, 19, 44730),
(13718, 0, 0, 0, 19, 44730),
(4657, 0, 0, 0, 19, 44730),
(11686, 0, 0, 0, 19, 44730),
(11687, 0, 0, 0, 19, 44730),
(11782, 0, 0, 0, 19, 44730),
(13717, 0, 0, 0, 19, 44730),
(5771, 0, 0, 0, 19, 44730),
(5760, 0, 0, 0, 19, 44730);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=44730 WHERE (`DifficultyID`=0 AND `Entry` IN (4713,13699,35452,35815,90,36182));

UPDATE `gossip_menu` SET `VerifiedBuild`=44730 WHERE (`TextID`=16585 AND `MenuID`=11828) OR (`TextID`=2054 AND `MenuID`=1422) OR (`TextID`=2053 AND `MenuID`=1421) OR (`TextID`=2433 AND `MenuID`=1802) OR (`TextID`=14979 AND `MenuID`=10803) OR (`TextID`=14978 AND `MenuID`=10802) OR (`TextID`=14980 AND `MenuID`=10804) OR (`TextID`=14943 AND `MenuID`=10779) OR (`TextID`=14126 AND `MenuID` IN (11775,11776)) OR (`TextID`=6335 AND `MenuID`=5303) OR (`TextID`=14973 AND `MenuID`=10798);

UPDATE `gameobject_template` SET `VerifiedBuild`=44730 WHERE `entry` IN (142073, 142185, 144063, 142186, 175801, 22245, 177398, 195108, 195097, 195107, 179896, 175851, 175852, 175853, 177524, 176582, 177368, 177367, 175707, 138497, 138496, 204781, 204782, 196395, 178404, 178386, 178827, 204778, 204787, 176230, 176226, 204794, 204789, 177369, 177365, 177243, 180685);
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=6710, `ContentTuningId`=22, `VerifiedBuild`=44730 WHERE `entry`=142188; -- Flame of Samha
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=6709, `ContentTuningId`=22, `VerifiedBuild`=44730 WHERE `entry`=142187; -- Flame of Imbel
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=14620, `ContentTuningId`=19, `VerifiedBuild`=44730 WHERE `entry`=177784; -- Giant Softshell Clam
UPDATE `gameobject_template` SET `ContentTuningId`=19, `VerifiedBuild`=44730 WHERE `entry`=176635; -- Shellfish Trap
UPDATE `gameobject_template` SET `ContentTuningId`=19, `VerifiedBuild`=44730 WHERE `entry`=196393; -- Broken Relic
UPDATE `gameobject_template` SET `ContentTuningId`=19, `VerifiedBuild`=44730 WHERE `entry`=196387; -- Kherrah's Cage

UPDATE `gameobject_questitem` SET `VerifiedBuild`=44730 WHERE (`Idx`=0 AND `GameObjectEntry` IN (22245,177784,176582,196395));

UPDATE `creature_queststarter` SET `VerifiedBuild`=44908 WHERE (`id`=10923 AND `quest` IN (28150,27997)) OR (`id`=10921 AND `quest`=28148) OR (`id`=11554 AND `quest`=28100) OR (`id`=40052 AND `quest` IN (25403,25208)) OR (`id`=39653 AND `quest` IN (25406,25402,26574,25401,25400,25333)) OR (`id`=40078 AND `quest` IN (25410,25409,25407)) OR (`id`=7807 AND `quest`=25476) OR (`id`=40132 AND `quest`=25350) OR (`id`=39407 AND `quest` IN (25438,25379)) OR (`id`=39725 AND `quest` IN (25437,25436,25431,25429,25434,25433,25427,25432,25426)) OR (`id`=40913 AND `quest` IN (25469,25468)) OR (`id`=40226 AND `quest` IN (25450,25449)) OR (`id`=3936 AND `quest` IN (25463,25304,27133)) OR (`id`=39723 AND `quest` IN (25458,25399)) OR (`id`=14637 AND `quest` IN (25466,25465)) OR (`id`=40032 AND `quest` IN (26402,25398)) OR (`id`=40131 AND `quest` IN (25368,25423,25422));

UPDATE `creature_questender` SET `VerifiedBuild`=44908 WHERE (`id`=10921 AND `quest`=28148) OR (`id`=10923 AND `quest`=27997) OR (`id`=11554 AND `quest` IN (28396,27995)) OR (`id`=40078 AND `quest` IN (25410,25409,25407)) OR (`id`=40052 AND `quest` IN (25403,25402)) OR (`id`=39653 AND `quest` IN (25406,25400,25401,25463,25333,25208)) OR (`id`=40226 AND `quest` IN (25451,25450,25449)) OR (`id`=7807 AND `quest`=25475) OR (`id`=39725 AND `quest` IN (25438,25436,25431,25429,25434,25433,25427,25432,25426,26574)) OR (`id`=39407 AND `quest` IN (25379,25437)) OR (`id`=40913 AND `quest` IN (25469,25468)) OR (`id`=3936 AND `quest` IN (25458,25399,26402)) OR (`id`=39723 AND `quest`=25304) OR (`id`=14637 AND `quest` IN (25466,25465)) OR (`id`=40032 AND `quest` IN (25398,25396,25397)) OR (`id`=40132 AND `quest`=26401) OR (`id`=40131 AND `quest` IN (25368,25422,25423)) OR (`id`=40129 AND `quest`=25350);

UPDATE `gameobject_queststarter` SET `VerifiedBuild`=44908 WHERE (`id`=206585 AND `quest` IN (27995,27989,27994)) OR (`id`=203134 AND `quest`=26401);

UPDATE `gameobject_questender` SET `VerifiedBuild`=44908 WHERE (`id`=206585 AND `quest` IN (27989,27994,28100));

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (43326,40051,11825,11824,11717,4670,4673,4641,4642,4645,4640,36141,4638,39853,52562,51752,51750,51935,51718,54228,52008,51719,51941,51944,52057,51946,51735,51734,51733,51942,51936,51717,39407,11497,39946,40137,40136,39723,43900,43867,42211,44400,5343,39728,39733,39650,39704,39822,39812,39811,39810,39809,43865,43864,39382,43736,39813,39607,43838,43784,43783,43782,43781,40232,5350,5347,5244,5300,5346,5328,5327,7807,40131,5304,92462,39958,39957,47558,14395,14355,4661,36378,36329,35481,6019,13698,6706,8150,11103,11104,12960,5642,5752,5638,5396,1322,11715,4674,14225,4675,4671,4672,35382,50759,41071,41070,149179,2184,32959,39834,39394,39395,7957,7956,5806,51610,47649,5247,5349,14661,11447,40069,5245));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(43326, 0, 0, 0, 22, 44908),
(40051, 0, 0, 0, 22, 44908),
(11825, 0, 0, 0, 22, 44908),
(11824, 0, 0, 0, 22, 44908),
(11717, 0, 0, 0, 22, 44908),
(4670, 0, 0, 0, 19, 44908),
(4673, 0, 0, 0, 19, 44908),
(4641, 0, 0, 0, 19, 44908),
(4642, 0, 0, 0, 19, 44908),
(4645, 0, 0, 0, 19, 44908),
(4640, 0, 0, 0, 19, 44908),
(36141, 0, 0, 0, 19, 44908),
(4638, 0, 0, 0, 19, 44908),
(39853, 0, 0, 0, 22, 44908),
(52562, 0, 0, 0, 22, 44908),
(51752, 0, 0, 0, 22, 44908),
(51750, 0, 0, 0, 22, 44908),
(51935, 0, 0, 0, 22, 44908),
(51718, 0, 0, 0, 22, 44908),
(54228, 0, 0, 0, 22, 44908),
(52008, 0, 0, 0, 22, 44908),
(51719, 0, 0, 0, 22, 44908),
(51941, 0, 0, 0, 22, 44908),
(51944, 0, 0, 0, 22, 44908),
(52057, 0, 0, 0, 22, 44908),
(51946, 0, 0, 0, 22, 44908),
(51735, 0, 0, 0, 22, 44908),
(51734, 0, 0, 0, 22, 44908),
(51733, 0, 0, 0, 22, 44908),
(51942, 0, 0, 0, 22, 44908),
(51936, 0, 0, 0, 22, 44908),
(51717, 0, 0, 0, 22, 44908),
(39407, 0, 0, 0, 22, 44908),
(11497, 0, 0, 0, 22, 44908),
(39946, 0, 0, 0, 22, 44908),
(40137, 0, 0, 0, 22, 44908),
(40136, 0, 0, 0, 22, 44908),
(39723, 0, 0, 0, 22, 44908),
(43900, 0, 0, 0, 22, 44908),
(43867, 0, 0, 0, 22, 44908),
(42211, 0, 0, 0, 22, 44908),
(44400, 0, 0, 0, 22, 44908),
(5343, 0, 0, 0, 22, 44908),
(39728, 0, 0, 0, 22, 44908),
(39733, 0, 0, 0, 22, 44908),
(39650, 0, 0, 0, 22, 44908),
(39704, 0, 0, 0, 22, 44908),
(39822, 0, 0, 0, 22, 44908),
(39812, 0, 0, 0, 22, 44908),
(39811, 0, 0, 0, 22, 44908),
(39810, 0, 0, 0, 22, 44908),
(39809, 0, 0, 0, 22, 44908),
(43865, 0, 0, 0, 22, 44908),
(43864, 0, 0, 0, 22, 44908),
(39382, 0, 0, 0, 22, 44908),
(43736, 0, 0, 0, 22, 44908),
(39813, 0, 0, 0, 22, 44908),
(39607, 0, 0, 0, 22, 44908),
(43838, 0, 0, 0, 22, 44908),
(43784, 0, 0, 0, 22, 44908),
(43783, 0, 0, 0, 22, 44908),
(43782, 0, 0, 0, 22, 44908),
(43781, 0, 0, 0, 22, 44908),
(40232, 0, 0, 0, 22, 44908),
(5350, 0, 0, 0, 22, 44908),
(5347, 0, 0, 0, 22, 44908),
(5244, 0, 0, 0, 22, 44908),
(5300, 0, 0, 0, 22, 44908),
(5346, 0, 0, 0, 22, 44908),
(5328, 0, 0, 0, 22, 44908),
(5327, 0, 0, 0, 22, 44908),
(7807, 0, 0, 0, 22, 44908),
(40131, 0, 0, 0, 22, 44908),
(5304, 0, 0, 0, 22, 44908),
(92462, 0, 0, 0, 436, 44908),
(39958, 0, 0, 0, 22, 44908),
(39957, 0, 0, 0, 22, 44908),
(47558, 0, 0, 0, 26, 44908),
(14395, 0, 0, 0, 22, 44908),
(14355, 0, 0, 0, 22, 44908),
(4661, 0, -5, -5, 19, 44908),
(36378, 0, 0, 0, 19, 44908),
(36329, 0, 0, 0, 19, 44908),
(35481, 0, 0, 0, 881, 44908),
(6019, 0, 0, 0, 19, 44908),
(13698, 0, 0, 0, 19, 44908),
(6706, 0, 0, 0, 881, 44908),
(8150, 0, 0, 0, 19, 44908),
(11103, 0, 0, 0, 19, 44908),
(11104, 0, 0, 0, 19, 44908),
(12960, 0, 0, 0, 19, 44908),
(5642, 0, 0, 0, 19, 44908),
(5752, 0, 0, 0, 19, 44908),
(5638, 0, 0, 0, 19, 44908),
(5396, 0, 0, 0, 19, 44908),
(1322, 0, 0, 0, 19, 44908),
(11715, 0, 0, 0, 19, 44908),
(4674, 0, 0, 0, 19, 44908),
(14225, 0, 0, 0, 19, 44908),
(4675, 0, 0, 0, 19, 44908),
(4671, 0, 0, 0, 19, 44908),
(4672, 0, 0, 0, 19, 44908),
(35382, 0, 0, 0, 19, 44908),
(50759, 0, 0, 0, 14, 44908),
(41071, 0, 0, 0, 14, 44908),
(41070, 0, 0, 0, 14, 44908),
(149179, 0, 0, 0, 733, 44908),
(2184, 0, 0, 0, 5, 44908),
(32959, 0, 0, 0, 5, 44908),
(39834, 0, 0, 0, 22, 44908),
(39394, 0, 0, 0, 22, 44908),
(39395, 0, 0, 0, 22, 44908),
(7957, 0, 0, 0, 22, 44908),
(7956, 0, 0, 0, 22, 44908),
(5806, 0, 0, 0, 2108, 44908),
(51610, 0, 0, 0, 2108, 44908),
(47649, 0, 0, 0, 482, 44908),
(5247, 0, 0, 0, 22, 44908),
(5349, 0, 0, 0, 22, 44908),
(14661, 0, 0, 0, 22, 44908),
(11447, 0, 0, 0, 22, 44908),
(40069, 0, 0, 0, 22, 44908),
(5245, 0, 0, 0, 22, 44908);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=44908 WHERE (`DifficultyID`=0 AND `Entry` IN (3825,3919,3834,34424,12721,43624,43630,34429,34510,34359,12757,43653,43625,34395,3962,3954,11137,3967,35464,35556,35661,35409,36094,11596,35434,11564,11578,14226,4677,4681,35591,4668,4679,36181,4699,5366,40474,40473,44386,7776,39377,40467,44384,7775,51726,51943,51756,51758,53418,51945,51722,51865,51714,51757,51755,7737,3500,8159,39847,9986,39893,8145,8144,11098,8115,39949,39972,7997,11498,32780,43896,5234,11442,7948,5352,7941,7946,7945,3700,40226,7943,10293,7947,7942,40362,40129,40059,5236,5240,5462,39314,44391,41383,44397,10059,7939,3936,40360,5307,39677,14637,8157,7949,96485,40036,9548,11752,14373,4544,39898,7875,8143,8146,5390,40332,8158,11818,8142,36208,14344,39965,39384,36185,4653,62185,4651,4648,4646,40224,43488,68805,4688,4697,4726,4693,35592,4701,4695,8152,4702,9636,4700,35605,35606,41730,35450,36123,36234,36062,11577,35632,35412,35446,62184,4666,4665,35645,4664,4663,62187,62186,4689,4692,49839,49835,11576,39896,4728,4696,13737,8151,50481,35561,5356,34982,62191,4006,34866,66335,66334,66333,4007,4005,66137,41185,41186,41937,41936,34894,41935,41870,35204,35203,35333,35205,35334,41987,42029,41988,41062,40168,39952,39256,39257,32254,7727,7726,5354,7725,32997,8147,5278,34299,33057,33083,33058,34385,34282,34293,34304,33207,33181,33206,33978,33180,33179,48764,48726,48650,48763,48648,33903,33311,33009,33905,33884,3841,33175,32936,33359,49939,43439,43431,43420,32978,32971,49923,32972,32979,32977,33053,32973,51997,11037,49940,4187,43436,43429,43428,43424,63084,63083,32912,49963,49968,49927,33313,34056,10085,49942,33864,32969,62246,64375,32935,32928,33115,7907,3607,10118,7916,42970,42968,3838,53522,66364,66363,4214,4423,50305,40552,50307,7316,11700,4155,4209,4208,62450,118905,4156,4222,4221,7854,39889,40498,39840,39894,44376,39656,44378,44379,44377,5251,5461,41605,5249,5258,5260,39657,5253,5782,14380,5359,4235,4233,4171,4232,4231,4169,4230,4170,8669,15679,15678,8723,4164,61757,4203,6142,52641,52640,14378,4089,8026,7315,34989,34988,4088,4087,11050,4159,6034,11083,4168,4225,6292,11081,4212,14379,4223,4786,4210,4226,4783,4784,11042,4160,11041,4229,4213,4211,52637,52636,4228,47584,30731,11070,52645,52644,52643,52642,30715,3468,34396,62178,50506,50497,49778,49728,55285,50510,50509,50508,50507,50505,50504,50502,50501,50500,50499,50498,50513,36479,51371,55273,55272,50521,50520,50518,50517,50516,2041,50519,4262,4242,48735,48608,48607,10924,11554,10923,10921,22931,40026,5246,5255,5254,66361,66352,7155,7153,7154,47308,5286,5268,5362,62395,39339,40972,12418,11443,11440,40132,41580,40078,40496,40079,40493,40052,44381,40497,7584,39653,40194,40193,40035,40032,40968,40967,40966,44382,40969,44385,39725,40367,40369,40914,40913));

UPDATE `trainer` SET `VerifiedBuild`=44908 WHERE `Id` IN (122, 62);

DELETE FROM `gossip_menu` WHERE (`TextID`=17850 AND `MenuID` IN (12740,12736,12737,12735,12738,12718)) OR (`TextID`=17852 AND `MenuID`=12719) OR (`TextID`=17878 AND `MenuID`=12733) OR (`TextID`=17851 AND `MenuID`=12720);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(12740, 17850, 44908), -- 51717 (Resort Guest)
(12736, 17850, 44908), -- 51943 (Resort Guest)
(12737, 17850, 44908), -- 51942 (Resort Guest)
(12735, 17850, 44908), -- 51945 (Resort Guest)
(12738, 17850, 44908), -- 51941 (Resort Guest)
(12718, 17850, 44908), -- 51944 (Resort Guest)
(12719, 17852, 44908), -- 51935 (Resort Guest)
(12733, 17878, 44908), -- 51734 (Gordon Tramsay)
(12720, 17851, 44908); -- 51735 (Gott Weedlespan)

UPDATE `gossip_menu` SET `VerifiedBuild`=44908 WHERE (`MenuID`=3622 AND `TextID`=4393) OR (`MenuID`=3621 AND `TextID`=4394) OR (`MenuID`=11353 AND `TextID`=15821) OR (`MenuID`=11357 AND `TextID`=15828) OR (`MenuID`=1965 AND `TextID`=2639) OR (`MenuID`=11362 AND `TextID`=15835) OR (`MenuID`=14984 AND `TextID`=21183) OR (`MenuID`=11373 AND `TextID`=7778) OR (`MenuID`=11364 AND `TextID`=15838) OR (`MenuID`=11307 AND `TextID`=15761) OR (`MenuID`=11738 AND `TextID`=16432) OR (`MenuID`=11374 AND `TextID`=15845) OR (`MenuID`=11284 AND `TextID`=15719) OR (`MenuID`=11349 AND `TextID`=15816) OR (`MenuID`=11361 AND `TextID` IN (7116,15834)) OR (`MenuID`=1581 AND `TextID`=824) OR (`MenuID`=4133 AND `TextID`=5104) OR (`MenuID`=4164 AND `TextID`=5218) OR (`MenuID`=18692 AND `TextID`=27173) OR (`MenuID`=11347 AND `TextID`=15808) OR (`MenuID`=11315 AND `TextID`=15771) OR (`MenuID`=11363 AND `TextID`=15836);

UPDATE `gameobject_template` SET `VerifiedBuild`=44908 WHERE `entry` IN (311339, 311338, 204738, 204737, 311337, 204736, 50805, 50804, 50803, 204141, 311335, 204137, 204138, 204143, 204139, 204136, 204140, 3637, 204144, 3636, 204142, 206585, 276377, 276388, 276380, 276384, 276386, 276382, 148840, 276387, 276385, 204982, 204985, 204984, 204983, 176318, 176278, 176281, 176279, 176287, 176288, 176280, 176286, 176285, 178224, 176284, 177198, 176283, 184396, 184395, 202164, 204981, 204980, 202107, 177192, 177188, 204989, 179469, 177189, 204990, 194803, 194779, 194778, 194777, 175104, 203166, 203159, 203155, 203171, 203165, 203149, 203164, 203156, 203157, 194477, 194476, 11899, 11898, 204799, 92424, 176319, 195588, 195450, 195601, 195600, 195081, 195693, 175764, 195692, 195082, 195674, 177397, 177399, 177366, 177400, 195096, 195095, 204792, 204793, 176229, 176228, 176227, 177706, 177444, 202222, 202085, 142091, 142090, 208322, 208324, 208323, 153579, 153576, 143980, 41189, 41188, 41190, 41191, 41192, 110236, 110235, 153581, 153582, 38030, 38029, 38028, 40197, 141069, 143986, 179513, 144050, 110231, 110232, 40298, 110233, 41194, 41185, 41187, 41186, 41193, 153584, 110234, 153580, 40301, 206614, 180474, 180480, 180477, 180475, 180473, 180476, 180479, 180478, 142179, 202606, 202221, 202115, 202114, 49486, 49487, 49485, 110230, 204795, 204791, 204790, 204788, 204780, 204779, 195094, 204773, 204766, 3911, 204769, 204767, 204764, 204763, 3906, 3905, 3892, 204768, 204760, 204759, 3900, 3891, 3888, 195535, 204761, 204757, 204756, 204754, 204752, 204755, 204753, 175145, 175144, 178908, 175146, 203167, 195014, 284503, 284502, 284492, 204774, 204132, 204131, 194107, 311731, 208831, 207321, 187337, 187296, 142110, 92696, 92544, 92542, 92541, 92694, 92693, 92540, 92539, 195529, 92528, 92527, 195530, 1685, 92534, 92533, 91673, 175725, 92536, 92535, 91672, 92538, 92526, 92525, 92529, 193981, 175760, 92530, 92537, 267843, 267841, 267839, 267749, 267744, 267842, 267840, 267838, 208830, 208829, 208815, 195112, 177279, 208814);
UPDATE `gameobject_template` SET `ContentTuningId`=203, `VerifiedBuild`=44908 WHERE `entry`=178826; -- Meeting Stone
UPDATE `gameobject_template` SET `ContentTuningId`=12, `VerifiedBuild`=44908 WHERE `entry`=195079; -- Broken-down Wagon
UPDATE `gameobject_template` SET `ContentTuningId`=14, `VerifiedBuild`=44908 WHERE `entry`=19602; -- Venture Co. Engineering Plans
UPDATE `gameobject_template` SET `ContentTuningId`=14, `VerifiedBuild`=44908 WHERE `entry`=203186; -- STAY OUT!
UPDATE `gameobject_template` SET `ContentTuningId`=19, `VerifiedBuild`=44908 WHERE `entry`=195438; -- Cup of Elune
UPDATE `gameobject_template` SET `ContentTuningId`=19, `VerifiedBuild`=44908 WHERE `entry`=195517; -- Elune's Handmaiden
UPDATE `gameobject_template` SET `ContentTuningId`=19, `VerifiedBuild`=44908 WHERE `entry`=195687; -- Fertile Mound
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=3543, `ContentTuningId`=19, `VerifiedBuild`=44908 WHERE `entry`=22246; -- Tear of Theradras
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39388, `ContentTuningId`=22, `VerifiedBuild`=44908 WHERE `entry`=208203; -- Empty Kaja'Cola Can
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39388, `ContentTuningId`=22, `VerifiedBuild`=44908 WHERE `entry`=208202; -- Empty Kaja'Cola Can
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39388, `ContentTuningId`=22, `VerifiedBuild`=44908 WHERE `entry`=208201; -- Empty Kaja'Cola Can
UPDATE `gameobject_template` SET `ContentTuningId`=22, `VerifiedBuild`=44908 WHERE `entry`=164953; -- Large Leather Backpacks
UPDATE `gameobject_template` SET `ContentTuningId`=482, `VerifiedBuild`=44908 WHERE `entry`=204101; -- Frost Trap
UPDATE `gameobject_template` SET `ContentTuningId`=22, `VerifiedBuild`=44908 WHERE `entry`=142195; -- Woodpaw Battle Map
UPDATE `gameobject_template` SET `ContentTuningId`=22, `VerifiedBuild`=44908 WHERE `entry`=164954; -- Zukk'ash Pod
UPDATE `gameobject_template` SET `ContentTuningId`=22, `VerifiedBuild`=44908 WHERE `entry`=164909; -- Wrecked Row Boat
UPDATE `gameobject_template` SET `ContentTuningId`=22, `VerifiedBuild`=44908 WHERE `entry`=203134; -- Empty Pedestal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=3543, `ContentTuningId`=19, `VerifiedBuild`=44908 WHERE `entry`=22246; -- Tear of Theradras
UPDATE `gameobject_template` SET `ContentTuningId`=19, `VerifiedBuild`=44908 WHERE `entry`=65407; -- Graznab's Machine
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=13982, `ContentTuningId`=19, `VerifiedBuild`=44908 WHERE `entry`=176752; -- Kodo Bones
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=13982, `ContentTuningId`=19, `VerifiedBuild`=44908 WHERE `entry`=176751; -- Kodo Bones
UPDATE `gameobject_template` SET `ContentTuningId`=1281, `VerifiedBuild`=44908 WHERE `entry`=316907; -- Kodo Runt Bones
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39335, `ContentTuningId`=2, `VerifiedBuild`=44908 WHERE `entry`=207521; -- Maplewood Treasure Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27217, `ContentTuningId`=5, `VerifiedBuild`=44908 WHERE `entry`=195007; -- Slain Wildkin Feather
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=26867, `ContentTuningId`=5, `VerifiedBuild`=44908 WHERE `entry`=194209; -- Fuming Toadstool
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=26867, `ContentTuningId`=5, `VerifiedBuild`=44908 WHERE `entry`=194208; -- Fuming Toadstool
UPDATE `gameobject_template` SET `ContentTuningId`=5, `VerifiedBuild`=44908 WHERE `entry`=194105; -- Buzzbox 413

UPDATE `gameobject_questitem` SET `VerifiedBuild`=44908 WHERE (`Idx`=0 AND `GameObjectEntry` IN (19602,195601,195692,195674,22246,208203,208202,208201,202606,202793,176752,176751,316907,195535,195007,194209,194208,194107,208831,208814));

UPDATE `creature_queststarter` SET `VerifiedBuild`=45114 WHERE (`id`=10929 AND `quest` IN (28840,28839,28838,28837,28842,28841)) OR (`id`=50263 AND `quest` IN (28831,28830,28829)) OR (`id`=42308 AND `quest` IN (26214,26213,26209,26215)) OR (`id`=50366 AND `quest`=28847) OR (`id`=10618 AND `quest` IN (29034,29032)) OR (`id`=49396 AND `quest` IN (28742,28641,28640,28828)) OR (`id`=49436 AND `quest` IN (28639,28719,28637)) OR (`id`=49537 AND `quest`=28638) OR (`id`=49402 AND `quest`=28718) OR (`id`=49400 AND `quest`=28710) OR (`id`=49399 AND `quest`=28707) OR (`id`=49407 AND `quest` IN (28706,28703)) OR (`id`=11079 AND `quest` IN (28701,28676)) OR (`id`=10920 AND `quest` IN (28848,28537,28479)) OR (`id`=48660 AND `quest` IN (28536,28519)) OR (`id`=48659 AND `quest` IN (28535,28518)) OR (`id`=48658 AND `quest` IN (28534,28513)) OR (`id`=9298 AND `quest` IN (28472,28470,28530,28469,28460,28464)) OR (`id`=42405 AND `quest` IN (26232,26228)) OR (`id`=42497 AND `quest`=26230) OR (`id`=42498 AND `quest`=26229) OR (`id`=48722 AND `quest`=28614) OR (`id`=48723 AND `quest`=28615) OR (`id`=48965 AND `quest`=28610) OR (`id`=11191 AND `quest`=28609) OR (`id`=10307 AND `quest`=28540) OR (`id`=11557 AND `quest`=6031) OR (`id`=15395 AND `quest` IN (28521,28366,28338,28768)) OR (`id`=47556 AND `quest`=28364) OR (`id`=48044 AND `quest`=28228) OR (`id`=48042 AND `quest` IN (28224,28221)) OR (`id`=48032 AND `quest` IN (28222,28219)) OR (`id`=11556 AND `quest`=28522) OR (`id`=48461 AND `quest`=28362) OR (`id`=47931 AND `quest` IN (28392,28384,28382)) OR (`id`=48493 AND `quest` IN (28389,28388,28387,28386,28385,28337)) OR (`id`=48492 AND `quest`=28383) OR (`id`=48491 AND `quest`=28381) OR (`id`=47923 AND `quest` IN (28264,28261,28257,28256,28218)) OR (`id`=48126 AND `quest`=28229) OR (`id`=47843 AND `quest`=28217) OR (`id`=48459 AND `quest` IN (28374,28360,28361)) OR (`id`=48349 AND `quest` IN (28359,28358)) OR (`id`=48339 AND `quest` IN (28342,28341)) OR (`id`=47696 AND `quest` IN (28306,28213,28208,28207)) OR (`id`=47692 AND `quest` IN (28214,28190)) OR (`id`=47617 AND `quest`=28305) OR (`id`=51664 AND `quest` IN (28155,28153,28131,28126,28129,28128,28119)) OR (`id`=10922 AND `quest`=28116) OR (`id`=11019 AND `quest`=28121) OR (`id`=47341 AND `quest` IN (28288,28113,28000)) OR (`id`=9116 AND `quest` IN (28152,28102)) OR (`id`=47366 AND `quest` IN (28044,28049));

UPDATE `creature_questender` SET `VerifiedBuild`=45114 WHERE (`id`=10929 AND `quest` IN (28840,28839,28838,28837,28847,28842,28841)) OR (`id`=50263 AND `quest` IN (28831,28830,28829)) OR (`id`=42308 AND `quest` IN (26214,26213,26209)) OR (`id`=49396 AND `quest` IN (28742,28641,28828,28640,28718)) OR (`id`=10618 AND `quest` IN (29034,29032)) OR (`id`=49537 AND `quest`=28782) OR (`id`=49436 AND `quest` IN (28639,28719,28637)) OR (`id`=11079 AND `quest` IN (28701,28674)) OR (`id`=49407 AND `quest` IN (28703,28676)) OR (`id`=49402 AND `quest`=28710) OR (`id`=49400 AND `quest`=28707) OR (`id`=49399 AND `quest`=28706) OR (`id`=50366 AND `quest`=28848) OR (`id`=10920 AND `quest` IN (28537,28536,28472)) OR (`id`=48660 AND `quest` IN (28519,28535)) OR (`id`=48659 AND `quest` IN (28518,28534)) OR (`id`=48658 AND `quest` IN (28513,28479)) OR (`id`=9298 AND `quest` IN (28471,28530,28470,28469,28460,28467,28768)) OR (`id`=42405 AND `quest` IN (26228,26215)) OR (`id`=42498 AND `quest`=26229) OR (`id`=42497 AND `quest`=26230) OR (`id`=48723 AND `quest`=28615) OR (`id`=48722 AND `quest`=28614) OR (`id`=48965 AND `quest` IN (28610,28609)) OR (`id`=10307 AND `quest` IN (28540,28656)) OR (`id`=11556 AND `quest` IN (28522,28521)) OR (`id`=11558 AND `quest`=8470) OR (`id`=15395 AND `quest` IN (28366,28338,28392)) OR (`id`=47556 AND `quest` IN (28364,28362)) OR (`id`=47923 AND `quest` IN (28217,28261,28257,28256,28218)) OR (`id`=48044 AND `quest`=28224) OR (`id`=48042 AND `quest` IN (28221,28222)) OR (`id`=48032 AND `quest` IN (28219,28220)) OR (`id`=47931 AND `quest` IN (28389,28382,28381)) OR (`id`=48493 AND `quest` IN (28388,28387,28386,28337,28384)) OR (`id`=48492 AND `quest`=28383) OR (`id`=47843 AND `quest`=28264) OR (`id`=48459 AND `quest` IN (28374,28361,28360,28306)) OR (`id`=48349 AND `quest` IN (28359,28358)) OR (`id`=48339 AND `quest` IN (28342,28341)) OR (`id`=47696 AND `quest` IN (28213,28208,28207,28305)) OR (`id`=47692 AND `quest` IN (28214,28190)) OR (`id`=10922 AND `quest` IN (28126,28152)) OR (`id`=11019 AND `quest`=28128) OR (`id`=47617 AND `quest`=28155) OR (`id`=51664 AND `quest` IN (28153,28131,28129,28119,28116,28121)) OR (`id`=47341 AND `quest` IN (28288,28113,28044,28000,28150)) OR (`id`=9116 AND `quest`=28102) OR (`id`=47366 AND `quest`=28049);

UPDATE `gameobject_queststarter` SET `VerifiedBuild`=45114 WHERE (`id`=207179 AND `quest`=28467);

UPDATE `gameobject_questender` SET `VerifiedBuild`=45114 WHERE (`id`=207179 AND `quest`=28464) OR (`id`=207104 AND `quest`=28385);

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (151779,39212,44348,44268,37212,48077,37165,37166,38382,44294,39210,38383,44299,44219,44346,44277,38379,37157,37167,37136,37160,34855,38380,37180,34848,11914,41407,41408,34843,51062,40904,40905,41864,43498,40901,41865,83817,3783,3730,3725,3734,3733,33182,2070,107595,22895,48315,48317,48331,50819,48487,42515,42492,67247,67248,50320,48678,50319,48154,48809,48135,48134,47917,47819,48660,47795,47802,47800,47812,50317,47733,47735,48019,48727,50316,48681,48659,50318,47398,48241,47441,47439,12123,14345,48044,48481,10183,2630,47366,47360,10202,48042,42500,49399,1424,42311,238,237,582,51519,10197,42413,9877,48032));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(151779, 0, 0, 0, 371, 45114),
(39212, 0, 0, 0, 881, 45114),
(44348, 0, 0, 0, 16, 45114),
(44268, 0, 0, 0, 16, 45114),
(37212, 0, 0, 0, 16, 45114),
(48077, 0, 0, 0, 26, 45114),
(37165, 0, 0, 0, 16, 45114),
(37166, 0, 0, 0, 16, 45114),
(38382, 0, 0, 0, 16, 45114),
(44294, 0, 0, 0, 16, 45114),
(39210, 0, 0, 0, 881, 45114),
(38383, 0, 0, 0, 16, 45114),
(44299, 0, 0, 0, 16, 45114),
(44219, 0, 0, 0, 16, 45114),
(44346, 0, 0, 0, 16, 45114),
(44277, 0, 0, 0, 16, 45114),
(38379, 0, 0, 0, 16, 45114),
(37157, 0, 0, 0, 16, 45114),
(37167, 0, 0, 0, 16, 45114),
(37136, 0, 0, 0, 16, 45114),
(37160, 0, 0, 0, 16, 45114),
(34855, 0, 0, 0, 14, 45114),
(38380, 0, 0, 0, 16, 45114),
(37180, 0, 0, 0, 2108, 45114),
(34848, 0, 0, 0, 16, 45114),
(11914, 0, 0, 0, 14, 45114),
(41407, 0, 0, 0, 14, 45114),
(41408, 0, 0, 0, 14, 45114),
(34843, 0, 0, 0, 14, 45114),
(51062, 0, 0, 0, 14, 45114),
(40904, 0, 0, 0, 14, 45114),
(40905, 0, 0, 0, 14, 45114),
(41864, 0, 0, 0, 14, 45114),
(43498, 0, 0, 0, 14, 45114),
(40901, 0, 0, 0, 14, 45114),
(41865, 0, 0, 0, 14, 45114),
(83817, 0, 0, 0, 371, 45114),
(3783, 0, 0, 0, 12, 45114),
(3730, 0, 0, 0, 12, 45114),
(3725, 0, 0, 0, 12, 45114),
(3734, 0, 0, 0, 12, 45114),
(3733, 0, 0, 0, 12, 45114),
(33182, 0, 0, 0, 12, 45114),
(2070, 0, -3, -3, 5, 45114),
(107595, 0, 0, 0, 26, 45114),
(22895, 0, 0, 0, 33, 45114),
(48315, 0, 0, 0, 26, 45114),
(48317, 0, 0, 0, 26, 45114),
(48331, 0, 0, 0, 26, 45114),
(50819, 0, 0, 0, 33, 45114),
(48487, 0, 0, 0, 26, 45114),
(42515, 0, 0, 0, 6, 45114),
(42492, 0, 0, 0, 6, 45114),
(67247, 0, 0, 0, 26, 45114),
(67248, 0, 0, 0, 26, 45114),
(50320, 0, 0, 0, 33, 45114),
(48678, 0, 0, 0, 33, 45114),
(50319, 0, 0, 0, 33, 45114),
(48154, 0, 0, 0, 26, 45114),
(48809, 0, 0, 0, 33, 45114),
(48135, 0, 0, 0, 26, 45114),
(48134, 0, 0, 0, 26, 45114),
(47917, 0, 0, 0, 26, 45114),
(47819, 0, 0, 0, 26, 45114),
(48660, 0, 0, 0, 33, 45114),
(47795, 0, 0, 0, 26, 45114),
(47802, 0, 0, 0, 26, 45114),
(47800, 0, 0, 0, 26, 45114),
(47812, 0, 0, 0, 26, 45114),
(50317, 0, 0, 0, 33, 45114),
(47733, 0, 0, 0, 26, 45114),
(47735, 0, 0, 0, 26, 45114),
(48019, 0, 0, 0, 26, 45114),
(48727, 0, 0, 0, 33, 45114),
(50316, 0, 0, 0, 33, 45114),
(48681, 0, 0, 0, 33, 45114),
(48659, 0, 0, 0, 33, 45114),
(50318, 0, 0, 0, 33, 45114),
(47398, 0, 0, 0, 26, 45114),
(48241, 0, 0, 0, 26, 45114),
(47441, 0, 0, 0, 26, 45114),
(47439, 0, 0, 0, 26, 45114),
(12123, 0, 3, 3, 328, 45114),
(14345, 0, 0, 0, 26, 45114),
(48044, 0, 0, 0, 26, 45114),
(48481, 0, 0, 0, 26, 45114),
(10183, 0, 0, 0, 33, 45114),
(2630, 0, 0, 0, 33, 45114),
(47366, 0, 0, 0, 26, 45114),
(47360, 0, 0, 0, 26, 45114),
(10202, 0, 0, 0, 33, 45114),
(48042, 0, 0, 0, 26, 45114),
(42500, 0, 0, 0, 6, 45114),
(49399, 0, 0, 0, 33, 45114),
(1424, 0, 0, 0, 6, 45114),
(42311, 0, 0, 0, 6, 45114),
(238, 0, 0, 0, 6, 45114),
(237, 0, 0, 0, 6, 45114),
(582, 0, 0, 0, 6, 45114),
(51519, 0, 0, 0, 2108, 45114),
(10197, 0, 0, 0, 33, 45114),
(42413, 0, 0, 0, 6, 45114),
(9877, 0, 0, 0, 26, 45114),
(48032, 0, 0, 0, 26, 45114);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=45114 WHERE (`DifficultyID`=0 AND `Entry` IN (50346,3498,8119,16227,3496,13602,44058,3446,3665,3499,3292,3493,9558,3492,3491,3453,3497,34656,34651,34754,34759,8496,3572,3339,10063,6791,34707,3502,6020,3386,4975,4955,34727,3383,34729,3467,34527,3382,3385,3255,38663,38826,3256,3245,38820,38818,38659,38747,38661,38627,38801,3465,38800,44283,38658,38620,38624,38805,38804,34346,44303,38621,11696,37511,38876,38875,38873,38871,38636,37199,19444,37092,37093,3426,37091,37090,37548,37487,62127,4166,37738,49725,37086,37219,37084,37083,37216,34640,37085,62131,38378,38385,37161,37170,11911,11910,11912,4008,11913,41360,34886,62190,34795,34345,40957,34353,34834,43002,40926,41676,41675,41674,34341,41673,40993,49724,34832,40995,40942,34378,3951,34354,3885,40895,40894,39254,3781,3810,3818,3894,3892,3959,3888,3691,34239,3915,3961,6738,3969,3958,33512,4079,17106,3996,3952,34420,3953,3970,33454,34132,4267,34419,6145,6087,34123,34160,34163,3819,3926,62177,3924,3809,24288,33347,3925,11806,3847,33356,33334,33276,33381,33451,33445,33375,11219,33278,33283,33407,3727,3728,33390,33389,61366,34295,49842,3823,3816,2071,2237,34413,34406,34405,34417,33044,33043,32968,32967,2165,34306,34302,62250,34318,34392,33253,33250,34404,34403,34402,34301,43425,33072,34498,34446,50348,7137,7460,49235,49178,49233,10199,10200,10737,10619,10618,47692,47696,7450,48723,48722,49177,7439,71163,7438,7459,7458,50777,48461,15395,10806,48469,48491,48126,48216,48349,48339,48215,47843,48587,43073,48581,48580,48574,48573,48577,48459,48240,50833,48456,48344,48127,48235,48332,48236,43085,48238,48228,51664,50864,37162,50724,48551,48492,47931,5501,15315,12578,11181,2803,543,26043,48552,48258,48555,48553,48556,48452,48453,7104,48493,66445,66444,66443,66442,66447,47679,48025,48024,48023,47844,47842,11019,48599,47617,10922,43079,7109,7105,11757,11186,13917,9857,11183,11184,10468,11189,11193,11192,11191,62120,11546,11182,11755,11118,50366,10978,11187,48965,14742,11188,52831,52830,11753,10305,5198,11185,4779,12150,10637,11119,11754,11190,49772,16416,50321,50322,128164,50325,7432,7431,49565,11751,11718,50291,14343,7100,7451,48333,48310,48259,8960,48007,47923,10807,47601,7136,48664,48658,49217,62435,7524,7448,49436,49537,50094,50092,49396,7523,54313,10920,89715,11556,9879,7456,7455,47369,11553,11552,11557,11555,11558,11516,62317,48454,51025,9517,9516,9861,9860,7430,51681,7433,9454,7434,62315,47556,50044,7149,7110,47392,7106,7446,48665,9298,10307,7139,48740,48670,7093,47675,50313,50315,48765,50312,47339,50422,50129,50126,10301,10929,50251,10918,50282,50281,50280,519,16015,10738,10916,8958,515,126,49400,7440,1236,7429,7428,50258,32261,48960,50250,7156,7444,8959,8956,7097,50925,7442,48455,7441,48457,49407,9116,47341,7086,51046,47747,11139,50263,7452,11138,49773,49346,7099,11079,49347,2084,2303,49402,3779,47687,7092,48622,48038,9862,7120,49774,51711,7114,50003,7443,49779,48768,48767,48952,62189,7118,62316,50362,7126,7113,7125,7115,10017,10016,62314,7112,7453,7454,49161,48918,9462,7157,7158,62119,68839));

UPDATE `trainer` SET `VerifiedBuild`=45114 WHERE `Id`=163;

UPDATE `gossip_menu` SET `VerifiedBuild`=45114 WHERE (`MenuID`=5482 AND `TextID`=6534) OR (`MenuID`=12567 AND `TextID`=17666) OR (`MenuID`=11635 AND `TextID`=16250) OR (`MenuID`=15727 AND `TextID`=22587) OR (`MenuID`=3506 AND `TextID`=4259) OR (`MenuID`=3517 AND `TextID`=4271) OR (`MenuID`=3519 AND `TextID`=4264) OR (`MenuID`=3518 AND `TextID`=4272) OR (`MenuID`=8160 AND `TextID`=10101) OR (`MenuID`=3516 AND `TextID`=4270) OR (`MenuID`=3513 AND `TextID`=4267) OR (`MenuID`=3515 AND `TextID`=4269) OR (`MenuID`=3514 AND `TextID`=4268) OR (`MenuID`=3512 AND `TextID`=4266) OR (`MenuID`=3511 AND `TextID`=4265) OR (`MenuID`=4924 AND `TextID`=5983) OR (`MenuID`=3510 AND `TextID`=4263) OR (`MenuID`=3509 AND `TextID`=4262) OR (`MenuID`=3508 AND `TextID`=4261) OR (`MenuID`=3507 AND `TextID`=4260) OR (`MenuID`=3761 AND `TextID`=4573) OR (`MenuID`=3130 AND `TextID`=3854) OR (`MenuID`=12566 AND `TextID`=17665) OR (`MenuID`=12503 AND `TextID`=17587) OR (`MenuID`=12502 AND `TextID`=17586) OR (`MenuID`=7238 AND `TextID`=8538) OR (`MenuID`=2703 AND `TextID`=3375) OR (`MenuID`=3802 AND `TextID`=4634) OR (`MenuID`=9075 AND `TextID`=12273) OR (`MenuID`=9076 AND `TextID`=12274) OR (`MenuID`=9073 AND `TextID`=12272) OR (`MenuID`=9074 AND `TextID`=12271) OR (`MenuID`=9083 AND `TextID`=12281) OR (`MenuID`=1967 AND `TextID`=2640) OR (`MenuID`=3049 AND `TextID`=3758) OR (`MenuID`=7046 AND `TextID`=8292) OR (`MenuID`=12593 AND `TextID`=17712) OR (`MenuID`=6837 AND `TextID`=8143) OR (`MenuID`=6089 AND `TextID`=7243) OR (`MenuID`=6090 AND `TextID`=7245) OR (`MenuID`=6091 AND `TextID`=7247) OR (`MenuID`=6092 AND `TextID`=7249) OR (`MenuID`=12599 AND `TextID`=825) OR (`MenuID`=2984 AND `TextID`=3673) OR (`MenuID`=3624 AND `TextID`=4395) OR (`MenuID`=6801 AND `TextID`=8124) OR (`MenuID`=3626 AND `TextID`=4401) OR (`MenuID`=3625 AND `TextID`=4399) OR (`MenuID`=6800 AND `TextID`=8123) OR (`MenuID`=12431 AND `TextID`=17482) OR (`MenuID`=12353 AND `TextID` IN (17357,17477)) OR (`MenuID`=12413 AND `TextID`=17452) OR (`MenuID`=12404 AND `TextID`=17433) OR (`MenuID`=12401 AND `TextID`=17430) OR (`MenuID`=3623 AND `TextID`=4396) OR (`MenuID`=12433 AND `TextID`=17484) OR (`MenuID`=12432 AND `TextID`=17483) OR (`MenuID`=14101 AND `TextID`=4993) OR (`MenuID`=12428 AND `TextID`=5473) OR (`MenuID`=12398 AND `TextID`=17426) OR (`MenuID`=3074 AND `TextID`=3807) OR (`MenuID`=12706 AND `TextID` IN (17843,17837)) OR (`MenuID`=3128 AND `TextID`=3864) OR (`MenuID`=12244 AND `TextID`=17197) OR (`MenuID`=3142 AND `TextID`=3874);

DELETE FROM `gameobject_template` WHERE `entry` IN (307296 /*Campfire*/, 307279 /*Campfire*/, 310478 /*Buzzbox 525*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(307296, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45114), -- Campfire
(307279, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45114), -- Campfire
(310478, 2, 356, 'Buzzbox 525', '', '', '', 1.039999961853027343, 0, 571, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 45114); -- Buzzbox 525

UPDATE `gameobject_template` SET `ContentTuningId`=33, `VerifiedBuild`=45114 WHERE `entry`=207424; -- Abandoned Research Samples
UPDATE `gameobject_template` SET `ContentTuningId`=33, `VerifiedBuild`=45114 WHERE `entry`=175587; -- Damaged Crate
UPDATE `gameobject_template` SET `ContentTuningId`=33, `VerifiedBuild`=45114 WHERE `entry` IN (175629, 175628); -- Jaron's Supplies
UPDATE `gameobject_template` SET `ContentTuningId`=33, `VerifiedBuild`=45114 WHERE `entry`=175586; -- Jaron's Wagon
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=36134, `ContentTuningId`=33, `VerifiedBuild`=45114 WHERE `entry`=207422; -- Owlbeast Moon-Totem
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=35827, `ContentTuningId`=469, `VerifiedBuild`=45114 WHERE `entry`=203071; -- Night Elf Archaeology Find
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39339, `ContentTuningId`=26, `VerifiedBuild`=45114 WHERE `entry`=207489; -- Sturdy Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=33, `VerifiedBuild`=45114 WHERE `entry`=207423; -- Owlbeast Life-Totem
UPDATE `gameobject_template` SET `ContentTuningId`=33, `VerifiedBuild`=45114 WHERE `entry`=207421; -- Owlbeast Claw-Totem
UPDATE `gameobject_template` SET `VerifiedBuild`=45114 WHERE `entry` IN (207420, 207419, 207306, 278492, 179864, 179863, 176404, 175811, 175931, 176749, 179125, 176748, 207300, 205008, 175932, 175930, 307281, 307271, 174857, 220176, 175731, 169966, 21679, 169967, 175758, 106641, 174872, 144125, 143399, 143398, 107042, 107041, 107039, 107037, 106638, 107040, 174849, 195187, 3252, 204997, 177165, 142197, 201703, 201595, 186287, 201399, 201394, 201393, 201392, 201391, 201395, 203292, 4171, 4170, 204797, 2336, 50831, 50830, 3301, 2335, 190549, 204798, 47297, 47296, 194472, 194471, 203234, 195220, 203413, 195217, 195135, 175181, 175180, 175179, 175726, 175724, 194826, 20962, 176998, 194297, 194296, 194310, 194311, 194309, 17282, 178147, 194203, 310497, 194139, 194114, 310502, 207091, 311331, 204154, 311332, 311328, 204156, 204155, 176326, 206764, 206852, 142140, 206625, 311342, 206382, 177278, 207063, 311372, 311340, 311333, 206398, 204162, 204161, 311306, 207126, 204160, 175929, 176808, 176806, 176805, 176807, 176804, 311304, 204157, 176091, 311305, 204158, 311301, 3718, 311310, 311290, 204159, 3716, 311300, 3717, 311298, 153516, 311289, 204145, 311308, 204146, 311307, 204147, 311302, 204148, 311371, 204150, 311303, 204149, 311336, 204735, 175075, 176305, 311341, 206381, 176159, 176306, 177275, 208190, 206706, 310472, 176157, 175076, 311329, 204734, 206650, 206649, 206648, 185016, 194005, 310473, 177276);
UPDATE `gameobject_template` SET `ContentTuningId`=683, `VerifiedBuild`=45114 WHERE `entry`=176588; -- Icecap
UPDATE `gameobject_template` SET `ContentTuningId`=33, `VerifiedBuild`=45114 WHERE `entry`=175927; -- Malyfous's Catalogue
UPDATE `gameobject_template` SET `Data1`=0, `Data18`=679, `Data30`=39339, `ContentTuningId`=26, `VerifiedBuild`=45114 WHERE `entry`=207477; -- Silverbound Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=336, `VerifiedBuild`=45114 WHERE `entry`=269277; -- Large Nest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=36131, `ContentTuningId`=33, `VerifiedBuild`=45114 WHERE `entry`=207293; -- Chillwind Eggs
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=36096, `ContentTuningId`=33, `VerifiedBuild`=45114 WHERE `entry`=207301; -- Ancient Urn
UPDATE `gameobject_template` SET `ContentTuningId`=33, `VerifiedBuild`=45114 WHERE `entry`=208192; -- Snow-Covered Burrow
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39339, `ContentTuningId`=26, `VerifiedBuild`=45114 WHERE `entry`=207489; -- Sturdy Treasure Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39381, `ContentTuningId`=33, `VerifiedBuild`=45114 WHERE `entry`=208189; -- Smoked Meat
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=4059, `ContentTuningId`=208, `VerifiedBuild`=45114 WHERE `entry`=68865; -- Snufflenose Command Sticks
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=3502, `ContentTuningId`=3, `VerifiedBuild`=45114 WHERE `entry`=21530; -- Snufflenose Owner's Manual
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=3450, `ContentTuningId`=3, `VerifiedBuild`=45114 WHERE `entry`=21277; -- Crate with Holes
UPDATE `gameobject_template` SET `ContentTuningId`=3, `VerifiedBuild`=45114 WHERE `entry`=3972; -- WANTED
UPDATE `gameobject_template` SET `ContentTuningId`=216, `VerifiedBuild`=45114 WHERE `entry`=149036; -- Marvon's Chest
UPDATE `gameobject_template` SET `ContentTuningId`=3, `VerifiedBuild`=45114 WHERE `entry`=195205; -- Hanging Pirate Head
UPDATE `gameobject_template` SET `ContentTuningId`=3, `VerifiedBuild`=45114 WHERE `entry`=195203; -- Theramore Ammunition Stockpile
UPDATE `gameobject_template` SET `ContentTuningId`=16, `VerifiedBuild`=45114 WHERE `entry`=202323; -- Cannoneer Whessan's Bowling Trophies
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27894, `ContentTuningId`=16, `VerifiedBuild`=45114 WHERE `entry`=202321; -- Box of Cutlery
UPDATE `gameobject_template` SET `ContentTuningId`=16, `VerifiedBuild`=45114 WHERE `entry`=202325; -- Screws and Gears
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27894, `ContentTuningId`=16, `VerifiedBuild`=45114 WHERE `entry`=202324; -- Broken Bottles
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27894, `ContentTuningId`=16, `VerifiedBuild`=45114 WHERE `entry`=202322; -- Musketballs
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27894, `ContentTuningId`=16, `VerifiedBuild`=45114 WHERE `entry`=202320; -- Crate of Nails
UPDATE `gameobject_template` SET `ContentTuningId`=16, `VerifiedBuild`=45114 WHERE `entry`=202335; -- Paxton's Field Cannon
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=28228, `ContentTuningId`=16, `VerifiedBuild`=45114 WHERE `entry`=202405; -- Northwatch Supply Crate
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27751, `ContentTuningId`=16, `VerifiedBuild`=45114 WHERE `entry`=201738; -- Budding Flower
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27751, `ContentTuningId`=16, `VerifiedBuild`=45114 WHERE `entry`=201737; -- Budding Flower
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27744, `ContentTuningId`=16, `VerifiedBuild`=45114 WHERE `entry`=201701; -- Confiscated Arms
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=29604, `ContentTuningId`=14, `VerifiedBuild`=45114 WHERE `entry`=203280; -- Alliance Weapon Crate
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=29604, `ContentTuningId`=14, `VerifiedBuild`=45114 WHERE `entry`=203279; -- Alliance Weapon Crate
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27271, `ContentTuningId`=12, `VerifiedBuild`=45114 WHERE `entry`=195138; -- Copper Plating
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27261, `ContentTuningId`=12, `VerifiedBuild`=45114 WHERE `entry`=195077; -- Moon-kissed Clay
UPDATE `gameobject_template` SET `ContentTuningId`=5, `VerifiedBuild`=45114 WHERE `entry`=194150; -- Jadefire Brazier
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=26825, `ContentTuningId`=5, `VerifiedBuild`=45114 WHERE `entry`=194100; -- Bear's Paw
UPDATE `gameobject_template` SET `ContentTuningId`=5, `VerifiedBuild`=45114 WHERE `entry`=17185; -- Buzzbox 525
UPDATE `gameobject_template` SET `ContentTuningId`=5, `VerifiedBuild`=45114 WHERE `entry`=194106; -- Ancient Bear Statue
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=35871, `ContentTuningId`=26, `VerifiedBuild`=45114 WHERE `entry`=207105; -- Irontree Explosive
UPDATE `gameobject_template` SET `ContentTuningId`=26, `VerifiedBuild`=45114 WHERE `entry`=207104; -- Master Control Pump
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39381, `ContentTuningId`=33, `VerifiedBuild`=45114 WHERE `entry`=208189; -- Smoked Meat
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=12780, `ContentTuningId`=33, `VerifiedBuild`=45114 WHERE `entry`=175324; -- Frostmaul Shards
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39339, `ContentTuningId`=26, `VerifiedBuild`=45114 WHERE `entry`=207489; -- Sturdy Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=33, `VerifiedBuild`=45114 WHERE `entry`=207179; -- Winterfall Cauldron
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39381, `ContentTuningId`=33, `VerifiedBuild`=45114 WHERE `entry`=208189; -- Smoked Meat
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39381, `ContentTuningId`=33, `VerifiedBuild`=45114 WHERE `entry`=208189; -- Smoked Meat
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=35871, `ContentTuningId`=26, `VerifiedBuild`=45114 WHERE `entry`=207105; -- Irontree Explosive
UPDATE `gameobject_template` SET `ContentTuningId`=26, `VerifiedBuild`=45114 WHERE `entry`=206963; -- Rich Irontree Soil
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39381, `ContentTuningId`=33, `VerifiedBuild`=45114 WHERE `entry`=208189; -- Smoked Meat
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=35871, `ContentTuningId`=26, `VerifiedBuild`=45114 WHERE `entry`=207105; -- Irontree Explosive
UPDATE `gameobject_template` SET `ContentTuningId`=26, `VerifiedBuild`=45114 WHERE `entry`=176160; -- Brazier of Suffering
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=35827, `ContentTuningId`=469, `VerifiedBuild`=45114 WHERE `entry`=203071; -- Night Elf Archaeology Find
UPDATE `gameobject_template` SET `ContentTuningId`=26, `VerifiedBuild`=45114 WHERE `entry`=176161; -- Brazier of Hatred
UPDATE `gameobject_template` SET `ContentTuningId`=26, `VerifiedBuild`=45114 WHERE `entry`=176158; -- Brazier of Pain
UPDATE `gameobject_template` SET `ContentTuningId`=26, `VerifiedBuild`=45114 WHERE `entry`=176184; -- the Corrupt Jaedenar Moon Well
UPDATE `gameobject_template` SET `ContentTuningId`=26, `VerifiedBuild`=45114 WHERE `entry`=206656; -- Mark of Tichondrius

UPDATE `gameobject_questitem` SET `VerifiedBuild`=45114 WHERE (`Idx`=0 AND `GameObjectEntry` IN (207424,175629,175628,207422,207423,207421,207293,207301,208189,68865,21530,21277,149036,195205,202323,202321,202325,202324,202322,202320,202405,201738,201737,202136,203280,203279,19603,195135,195138,195077,17282,194100,206764,206852,207105,207126,175324,206706));

DELETE FROM `creature_queststarter` WHERE (`id`=1750 AND `quest` IN (29547,26370));
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(1750, 29547, 45338), -- The King's Command offered Grand Admiral Jes-Tereth
(1750, 26370, 45338); -- Return to Sentinel Hill offered Grand Admiral Jes-Tereth

UPDATE `creature_queststarter` SET `VerifiedBuild`=45338 WHERE (`id`=576 AND `quest`=26797) OR (`id`=264 AND `quest` IN (26796,26795,26686,26645,26627,26618)) OR (`id`=268 AND `quest`=26794) OR (`id`=43731 AND `quest` IN (26725,26778,26777)) OR (`id`=43861 AND `quest` IN (26724,26723)) OR (`id`=288 AND `quest` IN (26787,26721)) OR (`id`=43730 AND `quest` IN (26760,26720)) OR (`id`=43733 AND `quest` IN (26726,26713,26708)) OR (`id`=43461 AND `quest`=26636) OR (`id`=43459 AND `quest`=26637) OR (`id`=43462 AND `quest`=26638) OR (`id`=43458 AND `quest` IN (26639,26646)) OR (`id`=43184 AND `quest` IN (26616,26568)) OR (`id`=43221 AND `quest` IN (26607,26573,26586,26571,26567)) OR (`id`=43302 AND `quest`=26563) OR (`id`=43303 AND `quest`=26562) OR (`id`=43305 AND `quest`=26561) OR (`id`=43300 AND `quest`=26560) OR (`id`=43270 AND `quest`=26587) OR (`id`=382 AND `quest` IN (26570,26513)) OR (`id`=43194 AND `quest`=26569) OR (`id`=344 AND `quest` IN (26512,26510)) OR (`id`=8965 AND `quest`=26508) OR (`id`=900 AND `quest` IN (26728,26511)) OR (`id`=342 AND `quest`=26509) OR (`id`=464 AND `quest` IN (26505,26503)) OR (`id`=379 AND `quest`=26506) OR (`id`=234 AND `quest` IN (26761,26322,26292,26289,26286)) OR (`id`=44084 AND `quest` IN (26810,26809)) OR (`id`=44082 AND `quest` IN (26821,26825)) OR (`id`=44099 AND `quest` IN (26816,26824,26815,26817,26823)) OR (`id`=44083 AND `quest` IN (26808,26820,26819,26818)) OR (`id`=43099 AND `quest`=26451) OR (`id`=44100 AND `quest`=26822) OR (`id`=2495 AND `quest` IN (26344,26343,26345)) OR (`id`=717 AND `quest` IN (186,185,188,187)) OR (`id`=718 AND `quest` IN (190,193,192,191)) OR (`id`=716 AND `quest` IN (26269,583)) OR (`id`=715 AND `quest` IN (194,197,196,195)) OR (`id`=773 AND `quest` IN (26763,26765)) OR (`id`=43886 AND `quest` IN (26742,26743)) OR (`id`=43885 AND `quest` IN (26729,26731,26730)) OR (`id`=469 AND `quest` IN (26737,26736,26735)) OR (`id`=1422 AND `quest` IN (26744,26739)) OR (`id`=739 AND `quest` IN (26734,26733,26732)) OR (`id`=770 AND `quest`=26740) OR (`id`=43884 AND `quest`=26746) OR (`id`=42736 AND `quest`=26745) OR (`id`=263 AND `quest`=26727) OR (`id`=289 AND `quest` IN (26681,26677,26680,26660,26653)) OR (`id`=43738 AND `quest` IN (26719,26717,26707)) OR (`id`=888 AND `quest`=25235) OR (`id`=43453 AND `quest` IN (26785,26672,26666)) OR (`id`=265 AND `quest` IN (26674,26655,26652)) OR (`id`=267 AND `quest` IN (26671,26670,26669,26667)) OR (`id`=663 AND `quest` IN (26691,26690,26689,26688)) OR (`id`=273 AND `quest` IN (26676,26661)) OR (`id`=276 AND `quest` IN (26685,26683)) OR (`id`=302 AND `quest` IN (26684,26654)) OR (`id`=272 AND `quest` IN (26623,26620)) OR (`id`=43611 AND `quest` IN (26693,26668)) OR (`id`=43607 AND `quest`=26692) OR (`id`=43508 AND `quest`=26640) OR (`id`=392 AND `quest` IN (26348,26349,26347)) OR (`id`=42651 AND `quest`=26320) OR (`id`=42425 AND `quest` IN (26319,26297,26295)) OR (`id`=7024 AND `quest` IN (26291,26290)) OR (`id`=821 AND `quest` IN (26288,26287,26365)) OR (`id`=42575 AND `quest`=26271) OR (`id`=878 AND `quest`=26371) OR (`id`=235 AND `quest` IN (26266,26241)) OR (`id`=233 AND `quest` IN (26270,26257,26237)) OR (`id`=42558 AND `quest`=26236);

DELETE FROM `creature_questender` WHERE (`id`=1750 AND `quest`=26322) OR (`id`=167032 AND `quest`=62567);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(1750, 26322, 45338), -- Rise of the Brotherhood ended by Grand Admiral Jes-Tereth
(167032, 62567, 45338); -- Adventurers Wanted: Chromie's Call ended by Chromie

UPDATE `creature_questender` SET `VerifiedBuild`=45338 WHERE (`id`=576 AND `quest`=26796) OR (`id`=264 AND `quest` IN (26795,26794,26686,26645,26618,26728)) OR (`id`=268 AND `quest`=26793) OR (`id`=43861 AND `quest` IN (26754,26723)) OR (`id`=288 AND `quest` IN (26787,26721)) OR (`id`=43731 AND `quest` IN (26724,26778,26777)) OR (`id`=43730 AND `quest` IN (26760,26720,26719)) OR (`id`=344 AND `quest` IN (26726,26545,26520,26512,26510,26761,26505)) OR (`id`=43733 AND `quest` IN (26714,26713,26708)) OR (`id`=43611 AND `quest` IN (26694,26693,26668,26651)) OR (`id`=43461 AND `quest`=26636) OR (`id`=43459 AND `quest`=26637) OR (`id`=43462 AND `quest`=26638) OR (`id`=43458 AND `quest` IN (26616,26646,26640)) OR (`id`=43184 AND `quest` IN (26607,26567)) OR (`id`=43221 AND `quest` IN (26573,26563,26571,26568)) OR (`id`=43194 AND `quest`=26569) OR (`id`=382 AND `quest` IN (26570,26513)) OR (`id`=43275 AND `quest`=26562) OR (`id`=43274 AND `quest`=26561) OR (`id`=43272 AND `quest`=26560) OR (`id`=43270 AND `quest` IN (26587,26586)) OR (`id`=900 AND `quest`=26511) OR (`id`=8962 AND `quest`=26508) OR (`id`=342 AND `quest`=26509) OR (`id`=464 AND `quest` IN (26503,26504,26365)) OR (`id`=379 AND `quest`=26506) OR (`id`=234 AND `quest` IN (26370,26320,26291,26286)) OR (`id`=44084 AND `quest` IN (26814,26809,26808)) OR (`id`=44099 AND `quest` IN (26816,26815,26817,26823,26825)) OR (`id`=44082 AND `quest` IN (26824,26805)) OR (`id`=44083 AND `quest` IN (26820,26819,26818)) OR (`id`=44100 AND `quest`=26822) OR (`id`=2495 AND `quest` IN (26344,26343,26345)) OR (`id`=717 AND `quest` IN (186,185,188,187)) OR (`id`=715 AND `quest` IN (194,583,197,196,195)) OR (`id`=716 AND `quest`=26269) OR (`id`=718 AND `quest` IN (190,193,192,191)) OR (`id`=773 AND `quest` IN (26763,26740)) OR (`id`=43886 AND `quest` IN (26742,26743)) OR (`id`=469 AND `quest` IN (26737,26736,26735,26838)) OR (`id`=43885 AND `quest` IN (26729,26731,26730)) OR (`id`=739 AND `quest` IN (26734,26733,26732)) OR (`id`=1422 AND `quest` IN (26744,26739,26738)) OR (`id`=43884 AND `quest` IN (26746,26745)) OR (`id`=263 AND `quest` IN (26727,26681)) OR (`id`=289 AND `quest` IN (26677,26680,26676,26655,26627)) OR (`id`=276 AND `quest` IN (26685,26684)) OR (`id`=43738 AND `quest` IN (26717,26707,26785)) OR (`id`=888 AND `quest`=25235) OR (`id`=43453 AND `quest` IN (26674,26671)) OR (`id`=265 AND `quest` IN (26672,26654,26653)) OR (`id`=267 AND `quest` IN (26670,26669,26667,26666)) OR (`id`=661 AND `quest`=26691) OR (`id`=663 AND `quest` IN (26690,26689,26688)) OR (`id`=273 AND `quest` IN (26661,26660)) OR (`id`=302 AND `quest` IN (26683,26652)) OR (`id`=272 AND `quest` IN (26623,26620)) OR (`id`=43607 AND `quest`=26692) OR (`id`=43508 AND `quest`=26639) OR (`id`=392 AND `quest` IN (26349,26347,26348,26371)) OR (`id`=42651 AND `quest`=26319) OR (`id`=42425 AND `quest` IN (26297,26295,26296,26292)) OR (`id`=821 AND `quest` IN (26288,26287)) OR (`id`=7024 AND `quest` IN (26290,26289)) OR (`id`=42575 AND `quest` IN (26271,26266)) OR (`id`=233 AND `quest` IN (26257,26252,26237,26236)) OR (`id`=235 AND `quest` IN (26270,26241)) OR (`id`=42558 AND `quest`=26232);

DELETE FROM `gameobject_queststarter` WHERE (`id`=307277 AND `quest`=26356) OR (`id`=307307 AND `quest`=26355) OR (`id`=307330 AND `quest`=26354);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(307277, 26356, 45338), -- Captain Sanders' Hidden Treasure offered by Old Jug
(307307, 26355, 45338), -- Captain Sanders' Hidden Treasure offered by Broken Barrel
(307330, 26354, 45338); -- Captain Sanders' Hidden Treasure offered by Captain's Footlocker

UPDATE `gameobject_queststarter` SET `VerifiedBuild`=45338 WHERE (`id`=204406 AND `quest`=26603) OR (`id`=204825 AND `quest`=26754) OR (`id`=204824 AND `quest`=26722) OR (`id`=204817 AND `quest`=26753) OR (`id`=61 AND `quest`=26793) OR (`id`=204351 AND `quest`=26520) OR (`id`=204344 AND `quest`=26504);

DELETE FROM `gameobject_questender` WHERE (`id`=307340 AND `quest`=26356) OR (`id`=307277 AND `quest`=26355) OR (`id`=307307 AND `quest`=26354) OR (`id`=307330 AND `quest`=26353);
INSERT INTO `gameobject_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(307340, 26356, 45338), -- Captain Sanders' Hidden Treasure ended by Locked Chest
(307277, 26355, 45338), -- Captain Sanders' Hidden Treasure ended by Old Jug
(307307, 26354, 45338), -- Captain Sanders' Hidden Treasure ended by Broken Barrel
(307330, 26353, 45338); -- Captain Sanders' Hidden Treasure ended by Captain's Footlocker

UPDATE `gameobject_questender` SET `VerifiedBuild`=45338 WHERE (`id`=61 AND `quest`=26797) OR (`id`=204825 AND `quest`=26722) OR (`id`=204824 AND `quest`=26753) OR (`id`=204817 AND `quest`=26725) OR (`id`=204351 AND `quest`=26519);

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (43508,6250,43462,43461,43460,43459,43458,43457,43450,43443,43449,43448,43447,43446,43445,43435,43434,43433,43432,47296,48278,46612,48262,48446,48445,48442,48441,48440,48266,47297,47404,48505,43778,48338,47677,47162,50595,48417,48230,48502,48229,48439,47242,47284,47282,47403,48284,46614,46613,48280,48279,616,42683,42680,584,43350,175166,123120,46898,44943,14491,44157,44155,44156,43332,43839,43323,43322,17207,52374,52908,2687,8679,51658,756,43915,43862,43903,2667,43275,43363,43274,43255,43257,43485,43272,43246,43245,43241,7387,43184,45554,711,51821,51921,43197,99541,45811,43912,157969,90202,43913,979,3301,45740,43911,43302,43305,43300,43303,132969,175183,43921,43920,43919,43886,43884,14492,147222,976,43499,43618,43644,43643,43639,43642,43496,43863,26125,28306,43861,334,43950,43859,43858,43857,435,486,4464,4065,43812,43829,43828,43827,43826,436,874,43745,43734,43787,43788,43744,43775,115149,68665,43733,43885,43518,691,12922,43714,43728,875,873,103673,149375,150357,71022,43610,43609,43611,43608,43607,43925,43546,51915,42617,172334,103822,42736,73542,90213,42601,99,1552,579,175181,111421,42769,42755,42753,118244,2462,42749,42751,42750,42748,42744,42793,42752,42771,42745,55659,97207,148995,589,594,698,42405,93814,173851,449)) OR (`DifficultyID`=1 AND `Entry` IN (42371,42703,42702,42701,42700,42699,42698,42697,645,636,647,646,1732,657,3947,42693,48351));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(43508, 0, 0, 0, 10, 45338),
(6250, 0, -1, -1, 6, 45338),
(43462, 0, 0, 0, 10, 45338),
(43461, 0, 0, 0, 10, 45338),
(43460, 0, 0, 0, 10, 45338),
(43459, 0, 0, 0, 10, 45338),
(43458, 0, 0, 0, 10, 45338),
(43457, 0, 0, 0, 10, 45338),
(43450, 0, 0, 0, 10, 45338),
(43443, 0, 0, 0, 10, 45338),
(43449, 0, 0, 0, 10, 45338),
(43448, 0, 0, 0, 10, 45338),
(43447, 0, 0, 0, 10, 45338),
(43446, 0, 0, 0, 10, 45338),
(43445, 0, 0, 0, 10, 45338),
(43435, 0, 0, 0, 10, 45338),
(43434, 0, 0, 0, 10, 45338),
(43433, 0, 0, 0, 10, 45338),
(43432, 0, 0, 0, 10, 45338),
(42371, 1, -4, -4, 1723, 45338),
(42703, 1, 2, 2, 202, 45338),
(42702, 1, 2, 2, 202, 45338),
(42701, 1, 2, 2, 202, 45338),
(42700, 1, 2, 2, 202, 45338),
(42699, 1, 2, 2, 202, 45338),
(42698, 1, 1, 1, 202, 45338),
(42697, 1, 2, 2, 202, 45338),
(645, 1, 2, 2, 202, 45338),
(636, 1, 1, 1, 202, 45338),
(647, 1, 2, 2, 202, 45338),
(646, 1, 2, 2, 202, 45338),
(1732, 1, 1, 1, 202, 45338),
(657, 1, 1, 1, 202, 45338),
(3947, 1, 1, 1, 202, 45338),
(42693, 1, 0, 0, 202, 45338),
(48351, 1, 0, 0, 202, 45338),
(47296, 0, 1, 1, 202, 45338),
(48278, 0, -1, -1, 202, 45338),
(46612, 0, 0, 0, 202, 45338),
(48262, 0, 0, 0, 202, 45338),
(48446, 0, 0, 0, 328, 45338),
(48445, 0, 0, 0, 202, 45338),
(48442, 0, -1, -1, 202, 45338),
(48441, 0, -1, -1, 202, 45338),
(48440, 0, -1, -1, 202, 45338),
(48266, 0, 0, 0, 202, 45338),
(47297, 0, 1, 1, 202, 45338),
(47404, 0, 0, 0, 202, 45338),
(48505, 0, 0, 0, 202, 45338),
(43778, 0, 1, 1, 202, 45338),
(48338, 0, 0, 0, 202, 45338),
(47677, 0, 0, 0, 202, 45338),
(47162, 0, 1, 1, 202, 45338),
(50595, 0, 0, 0, 202, 45338),
(48417, 0, 0, 0, 202, 45338),
(48230, 0, 0, 0, 202, 45338),
(48502, 0, 0, 0, 202, 45338),
(48229, 0, -1, -1, 202, 45338),
(48439, 0, 0, 0, 202, 45338),
(47242, 0, 0, 0, 328, 45338),
(47284, 0, 0, 0, 202, 45338),
(47282, 0, 0, 0, 202, 45338),
(47403, 0, 0, 0, 202, 45338),
(48284, 0, -1, -1, 202, 45338),
(46614, 0, 0, 0, 202, 45338),
(46613, 0, 0, 0, 202, 45338),
(48280, 0, 0, 0, 202, 45338),
(48279, 0, 0, 0, 202, 45338),
(616, 0, 0, 0, 10, 45338),
(42683, 0, 0, 0, 6, 45338),
(42680, 0, 0, 0, 6, 45338),
(584, 0, 0, 0, 10, 45338),
(43350, 0, 0, 0, 10, 45338),
(175166, 0, 0, 0, 10, 45338),
(123120, 0, 0, 0, 338, 45338),
(46898, 0, 0, 0, 371, 45338),
(44943, 0, 0, 0, 24, 45338),
(14491, 0, 0, 0, 24, 45338),
(44157, 0, 0, 0, 24, 45338),
(44155, 0, 0, 0, 24, 45338),
(44156, 0, 0, 0, 24, 45338),
(43332, 0, 0, 0, 24, 45338),
(43839, 0, 0, 0, 24, 45338),
(43323, 0, 0, 0, 24, 45338),
(43322, 0, 0, 0, 24, 45338),
(17207, 0, 0, 0, 18, 45338),
(52374, 0, 0, 0, 827, 45338),
(52908, 0, 0, 0, 827, 45338),
(2687, 0, 0, 0, 18, 45338),
(8679, 0, 0, 0, 18, 45338),
(51658, 0, 0, 0, 18, 45338),
(756, 0, 0, 0, 18, 45338),
(43915, 0, 0, 0, 13, 45338),
(43862, 0, 0, 0, 13, 45338),
(43903, 0, 0, 0, 2108, 45338),
(2667, 0, 0, 0, 18, 45338),
(43275, 0, 0, 0, 10, 45338),
(43363, 0, 0, 0, 10, 45338),
(43274, 0, 0, 0, 10, 45338),
(43255, 0, 0, 0, 24, 45338),
(43257, 0, 0, 0, 24, 45338),
(43485, 0, 0, 0, 10, 45338),
(43272, 0, 0, 0, 10, 45338),
(43246, 0, 0, 0, 24, 45338),
(43245, 0, 0, 0, 24, 45338),
(43241, 0, 0, 0, 24, 45338),
(7387, 0, 0, 0, 371, 45338),
(43184, 0, 0, 0, 10, 45338),
(45554, 0, 0, 0, 13, 45338),
(711, 0, 0, 0, 10, 45338),
(51821, 0, 0, 0, 2108, 45338),
(51921, 0, 0, 0, 2108, 45338),
(43197, 0, 0, 0, 10, 45338),
(99541, 0, 0, 0, 482, 45338),
(45811, 0, 0, 0, 13, 45338),
(43912, 0, 0, 0, 18, 45338),
(157969, 0, 0, 0, 371, 45338),
(90202, 0, 0, 0, 371, 45338),
(43913, 0, 0, 0, 18, 45338),
(979, 0, 0, 0, 18, 45338),
(3301, 0, 0, 0, 13, 45338),
(45740, 0, 0, 0, 13, 45338),
(43911, 0, 0, 0, 18, 45338),
(43302, 0, 0, 0, 10, 45338),
(43305, 0, 0, 0, 10, 45338),
(43300, 0, 0, 0, 10, 45338),
(43303, 0, 0, 0, 10, 45338),
(132969, 0, 0, 0, 773, 45338),
(175183, 0, 0, 0, 24, 45338),
(43921, 0, 0, 0, 18, 45338),
(43920, 0, 0, 0, 18, 45338),
(43919, 0, 0, 0, 18, 45338),
(43886, 0, 0, 0, 18, 45338),
(43884, 0, 0, 0, 18, 45338),
(14492, 0, 0, 0, 24, 45338),
(147222, 0, 0, 0, 181, 45338),
(976, 0, 0, 0, 18, 45338),
(43499, 0, 0, 0, 482, 45338),
(43618, 0, 0, 0, 10, 45338),
(43644, 0, 0, 0, 10, 45338),
(43643, 0, 0, 0, 10, 45338),
(43639, 0, 0, 0, 10, 45338),
(43642, 0, 0, 0, 10, 45338),
(43496, 0, 0, 0, 10, 45338),
(43863, 0, 0, 0, 10, 45338),
(26125, 0, -3, 0, 10, 45338),
(28306, 0, 0, 0, 10, 45338),
(43861, 0, 0, 0, 13, 45338),
(334, 0, 0, 0, 10, 45338),
(43950, 0, 0, 0, 13, 45338),
(43859, 0, 0, 0, 13, 45338),
(43858, 0, 0, 0, 13, 45338),
(43857, 0, 0, 0, 13, 45338),
(435, 0, 0, 0, 10, 45338),
(486, 0, 0, 0, 10, 45338),
(4464, 0, 0, 0, 10, 45338),
(4065, 0, 0, 0, 10, 45338),
(43812, 0, 0, 0, 10, 45338),
(43829, 0, 0, 0, 10, 45338),
(43828, 0, 0, 0, 10, 45338),
(43827, 0, 0, 0, 10, 45338),
(43826, 0, 0, 0, 10, 45338),
(436, 0, 0, 0, 10, 45338),
(874, 0, 0, 0, 6, 45338),
(43745, 0, 0, 0, 10, 45338),
(43734, 0, 0, 0, 10, 45338),
(43787, 0, 0, 0, 10, 45338),
(43788, 0, 0, 0, 10, 45338),
(43744, 0, 0, 0, 10, 45338),
(43775, 0, 0, 0, 10, 45338),
(115149, 0, 0, 0, 371, 45338),
(68665, 0, 0, 0, 371, 45338),
(43733, 0, 0, 0, 10, 45338),
(43885, 0, 0, 0, 18, 45338),
(43518, 0, 0, 0, 10, 45338),
(691, 0, 0, 0, 18, 45338),
(12922, 0, 0, 0, 10, 45338),
(43714, 0, 0, 0, 10, 45338),
(43728, 0, 0, 0, 10, 45338),
(875, 0, 0, 0, 18, 45338),
(873, 0, 0, 0, 18, 45338),
(103673, 0, 0, 0, 482, 45338),
(149375, 0, 0, 0, 371, 45338),
(150357, 0, 0, 0, 371, 45338),
(71022, 0, 0, 0, 371, 45338),
(43610, 0, 0, 0, 10, 45338),
(43609, 0, 0, 0, 10, 45338),
(43611, 0, 0, 0, 10, 45338),
(43608, 0, 0, 0, 10, 45338),
(43607, 0, 0, 0, 10, 45338),
(43925, 0, 0, 0, 13, 45338),
(43546, 0, 0, 0, 10, 45338),
(51915, 0, 0, 0, 2108, 45338),
(42617, 0, 0, 0, 6, 45338),
(172334, 0, 0, 0, 824, 45338),
(103822, 0, 0, 0, 482, 45338),
(42736, 0, 0, 0, 18, 45338),
(73542, 0, 0, 0, 371, 45338),
(90213, 0, 0, 0, 371, 45338),
(42601, 0, 0, 0, 6, 45338),
(99, 0, 0, 0, 73, 45338),
(1552, 0, 0, 0, 24, 45338),
(579, 0, 0, 0, 10, 45338),
(175181, 0, 0, 0, 10, 45338),
(111421, 0, 0, 0, 371, 45338),
(42769, 0, 0, 0, 6, 45338),
(42755, 0, 0, 0, 6, 45338),
(42753, 0, 0, 0, 6, 45338),
(118244, 0, 0, 0, 13, 45338),
(2462, 0, 0, 0, 13, 45338),
(42749, 0, 0, 0, 6, 45338),
(42751, 0, 0, 0, 6, 45338),
(42750, 0, 0, 0, 6, 45338),
(42748, 0, 0, 0, 6, 45338),
(42744, 0, 0, 0, 6, 45338),
(42793, 0, 0, 0, 6, 45338),
(42752, 0, 0, 0, 6, 45338),
(42771, 0, 0, 0, 6, 45338),
(42745, 0, 0, 0, 6, 45338),
(55659, 0, 0, 0, 482, 45338),
(97207, 0, 0, 0, 371, 45338),
(148995, 0, 0, 0, 371, 45338),
(589, 0, 0, 0, 6, 45338),
(594, 0, 0, 0, 6, 45338),
(698, 0, 0, 0, 18, 45338),
(42405, 0, 0, 0, 6, 45338),
(93814, 0, 0, 0, 371, 45338),
(173851, 0, 0, 0, 371, 45338),
(449, 0, 0, 0, 6, 45338);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=45338 WHERE (`DifficultyID`=0 AND `Entry` IN (513,456,830,117,1065,500,42669,171,123,43589,43590,458,730,4305,61158,1216,831,60761,517,127,391,680,678,710,679,7802,728,44183,42812,42811,44187,44186,42814,42813,2519,696,667,48343,48342,48340,48341,53488,392,626,624,623,625,684,43515,119390,42679,62129,101624,3624,1404,7853,1149,1382,2497,141679,1385,12137,3149,1146,1147,17094,5814,16094,2465,2464,1381,16096,7485,1387,1148,780,784,42858,672,670,782,669,781,783,2530,1059,43270,7871,731,99875,100346,43351,45613,45785,315,2541,42677,43948,42425,42651,42426,43052,709,687,533,44087,2635,43003,921,920,42653,4723,45739,506,206,4459,4460,4458,2856,1064,770,1422,42662,42655,42654,43099,42656,453,98,688,43366,43369,518,43185,580,115,2483,773,2495,718,42616,715,717,716,14270,42357,511,48,203,6491,978,302,1449,100704,300,42620,4260,43910,942,445,501,43248,43249,43247,43222,3089,1680,348,847,849,3085,3091,5620,148335,1678,148338,148336,381,789,9982,6728,6727,936,777,791,344,790,900,415,43221,793,341,43196,956,653,652,651,650,649,648,939,124,44192,44191,44190,44193,44194,43098,43097,43096,43095,44196,43053,44195,43205,43219,43203,43204,850,148333,148332,859,6166,148337,266,346,3090,3088,343,3087,3086,851,342,812,162953,162962,1671,162570,162958,345,14508,1713,151241,941,938,1564,1563,1488,43223,977,943,14273,43150,175189,65661,65660,65659,65648,871,879,43072,6295,43572,2697,43571,877,385,88067,49760,49749,49745,49741,49736,8934,43011,49769,8931,10045,842,6670,876,870,52190,1670,843,1668,523,154,489,42575,234,42308,820,878,821,42309,491,488,143208,1440,44243,151247,2504,151256,151255,151251,151249,44239,44241,44238,93307,93296,35365,51938,1751,34997,1750,15187,24729,34998,42635,69822,49908,49907,69823,70296,142789,142787,142786,142788,61809,63596,63607,62106,887,703,88081,88080,42762,126332,158125,133409,112698,172572,158123,133408,158120,158119,112686,43451,42782,20716,112694,697,54334,42342,395,689,1550,50527,50526,50528,827,676,525,674,1551,252,42259,45979,905,462,42407,432,434,433,937,940,397,288,151761,43730,107736,152088,37522,107923,107659,43697,44114,43731,1062,1061,671,8310,930,3135,999,276,568,685,43084,429,544,431,289,100821,111403,43851,65662,65655,65665,65664,531,47228,6093,205,881,880,473,7382,50942,490,487,54372,54373,54371,44028,522,44098,43761,949,44029,45619,474,61,6927,247,255,64335,64334,64330,475,452,248,246,244,330,113,210,100,822,448,97,478,218,42381,61141,3,604,948,202,44115,62664,43814,7024,44016,45614,43923,116,524,45582,51014,889,212,1251,61259,46,49690,61253,869,233,235,42391,42385,114,157,833,1109,118,699,101701,595,588,701,1096,1095,1097,1094,44082,43043,44083,44106,44100,44084,44099,44020,736,888,43738,499,587,694,42498,42497,42406,832,42387,42403,42402,42400,42399,42390,834,199,42383,61160,454,42401,42562,42560,42559,42558,42386,42384,729,1085,702,43977,43049));
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=-4, `LevelScalingDeltaMax`=-4 WHERE (`Entry`=53626 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=-3, `LevelScalingDeltaMax`=-3 WHERE (`Entry`=51081 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `ContentTuningID`=2148, `VerifiedBuild`=45338 WHERE (`Entry`=175137 AND `DifficultyID`=0);

UPDATE `trainer` SET `VerifiedBuild`=45338 WHERE `Id` IN (91, 27, 196, 10, 136, 133, 386);

UPDATE `gossip_menu` SET `VerifiedBuild`=45338 WHERE (`MenuID`=11770 AND `TextID`=16499) OR (`MenuID`=14814 AND `TextID`=20966) OR (`MenuID`=11769 AND `TextID`=16498) OR (`MenuID`=11720 AND `TextID`=16402) OR (`MenuID`=1621 AND `TextID`=2273) OR (`MenuID`=1622 AND `TextID`=2276) OR (`MenuID`=5665 AND `TextID`=6961) OR (`MenuID`=5853 AND `TextID`=7021) OR (`MenuID`=7691 AND `TextID`=9385) OR (`MenuID`=11651 AND `TextID`=16275) OR (`MenuID`=14815 AND `TextID`=20967) OR (`MenuID`=11740 AND `TextID`=16434) OR (`MenuID`=11801 AND `TextID`=16547) OR (`MenuID`=11803 AND `TextID`=16550) OR (`MenuID`=11802 AND `TextID`=16548) OR (`MenuID`=11711 AND `TextID`=16549) OR (`MenuID`=7577 AND `TextID`=9218) OR (`MenuID`=11782 AND `TextID`=16521) OR (`MenuID`=12793 AND `TextID`=17980) OR (`MenuID`=14235 AND `TextID`=3977) OR (`MenuID`=14234 AND `TextID`=5721) OR (`MenuID`=14239 AND `TextID`=5722) OR (`MenuID`=14236 AND `TextID`=4837) OR (`MenuID`=14237 AND `TextID`=4434) OR (`MenuID`=4107 AND `TextID`=5010) OR (`MenuID`=25426 AND `TextID`=40347) OR (`MenuID`=4106 AND `TextID`=5009) OR (`MenuID`=11734 AND `TextID`=16427) OR (`MenuID`=7690 AND `TextID`=9384) OR (`MenuID`=2781 AND `TextID`=3461) OR (`MenuID`=7364 AND `TextID`=8798) OR (`MenuID`=3133 AND `TextID`=3868) OR (`MenuID`=14200 AND `TextID`=16569) OR (`MenuID`=1781 AND `TextID`=16260) OR (`MenuID`=11779 AND `TextID`=16511);

DELETE FROM `gameobject_template` WHERE `entry` IN (307276 /*Campfire*/, 307320 /*Campfire*/, 307342 /*Campfire*/, 344604 /*Fearbreaker*/, 340002 /*Shelf*/, 339222 /*Mechagnome*/, 307336 /*Campfire*/, 307266 /*Campfire*/, 307340 /*Locked Chest*/, 307277 /*Old Jug*/, 307273 /*Campfire*/, 307299 /*Campfire*/, 307318 /*Campfire*/, 307307 /*Broken Barrel*/, 307330 /*Captain's Footlocker*/, 307298 /*Campfire*/, 307261 /*Campfire*/, 307327 /*Campfire*/, 307305 /*Campfire*/, 307316 /*Campfire*/, 307322 /*Campfire*/, 307272 /*Campfire*/, 307335 /*Campfire*/, 307311 /*Campfire*/, 307300 /*Campfire*/, 307286 /*Campfire*/, 307303 /*Campfire*/, 307268 /*Campfire*/, 307344 /*Campfire*/, 307343 /*Campfire*/, 307262 /*Campfire*/, 307331 /*Campfire*/, 307308 /*Campfire*/, 307259 /*Anvil*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(307276, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(307320, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(307342, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(344604, 3, 60861, 'Fearbreaker', 'questinteract', 'Retrieving', '', 1.25, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23645, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100977, 0, 0, 0, 0, 703, 45338), -- Fearbreaker
(340002, 5, 59897, 'Shelf', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Shelf
(339222, 10, 60896, 'Mechagnome', 'inspect', '', '', 0.5, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 312644, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 674, 45338), -- Mechagnome
(307336, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(307266, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(307340, 2, 1, 'Locked Chest', '', '', '', 1.330000042915344238, 43, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Locked Chest
(307277, 2, 7, 'Old Jug', '', '', '', 1, 43, 76, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 45338), -- Old Jug
(307273, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(307299, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(307318, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(307307, 2, 9, 'Broken Barrel', '', '', '', 1, 43, 77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 45338), -- Broken Barrel
(307330, 2, 8, 'Captain\'s Footlocker', '', '', '', 1, 43, 78, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 45338), -- Captain's Footlocker
(307298, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(307261, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(307327, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(307305, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(307316, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(307322, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(307272, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(307335, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(307311, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(307300, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(307286, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(307303, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(307268, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(307344, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(307343, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(307262, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(307331, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(307308, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- Campfire
(307259, 8, 166, 'Anvil', '', '', '', 1, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45338); -- Anvil

UPDATE `gameobject_template` SET `VerifiedBuild`=45338 WHERE `entry` IN (119, 32107, 204462, 18089, 175151, 175149, 175150, 175148, 92419, 1628, 221526, 1799, 180655, 22544, 22543, 22540, 3802, 3801, 204363, 22836, 22835, 22834, 22833, 22832, 22831, 204371, 204370, 204369, 204368, 204367, 204366, 204365, 204364, 204362, 142093, 112241, 112239, 112238, 112237, 112215, 112200, 92703, 179781, 179780, 179779, 179778, 175739, 112236, 112235, 112234, 112232, 112231, 112205, 112204, 112201, 2015, 2014, 1810, 76, 204975, 92458, 178573, 1814, 1815, 1812, 1816, 1811, 148697, 148668, 148661, 148660, 148725, 148694, 148686, 148671, 148670, 148663, 148693, 148691, 148682, 148664, 148675, 148669, 148665, 148714, 148707, 148696, 148695, 148692, 148684, 148683, 148680, 148674, 148659, 148677, 148662, 148658, 1817, 1813, 266354, 203460, 1802, 204394, 204393, 1806, 1804, 204403, 204295, 1805, 1801, 204395, 1807, 35591, 22541, 149424, 22668, 22667, 22666, 22665, 22662, 22661, 22660, 22659, 3819, 3818, 3817, 3816, 3815, 2489, 1820, 1819, 1808, 22538, 22537, 22536, 22535, 1952, 307341, 1617, 204005, 307301, 307284, 307260, 307294, 307288, 204095, 204099, 307291, 270854, 111839, 112879, 164728, 2371, 1977, 1979, 1976, 293887, 293891, 293889, 204822, 204821, 293890, 293888, 2061, 202602, 207215, 202601, 202600, 1981, 94190, 1973, 207216, 1960, 157636, 157969, 1961, 269817, 197073, 197056, 197048, 197047, 197066, 197060, 197051, 197050, 197049, 197099, 197012, 197008, 197098, 197125, 205107, 205106, 197183, 197182, 197181, 197176, 197184, 197186, 197180, 197179, 197178, 197177, 197119, 197185, 202260, 202258, 202256, 197140, 202259, 270011, 197123, 197138, 202005, 202010, 202004, 202006, 201981, 201980, 202021, 202020, 202019, 202018, 202014, 202013, 201647, 201646, 201645, 201644, 201643, 201642, 175761, 175738, 175727, 175730, 201648, 21583, 201665, 201664, 201663, 201657, 201656, 201655, 201654, 201649, 201641, 175735, 201658, 201653, 201843, 201822, 201671, 201670, 201669, 201662, 201661, 201660, 201659, 201652, 201651, 201650, 175753, 175750, 201668, 201667, 201666, 201690, 201689, 201688, 201682, 201677, 201675, 201672, 201694, 201693, 201692, 201691, 201687, 201686, 201685, 201684, 201683, 201681, 201680, 201679, 201678, 201674, 201673, 193955, 201676, 281118, 201453, 201452, 201451, 201450, 201449, 201448, 201447, 201446, 201445, 296065, 205105, 205104, 278331, 278328, 278333, 278332, 278329, 278330, 278327, 278326, 278325, 278324, 278310, 350063, 281304, 231870, 210181, 201485, 201483, 201461, 201484, 201482, 201481, 201480, 201479, 201478, 201477, 201476, 201475, 201474, 201463, 201462, 204988, 204987, 202271, 193585, 193583, 180047, 203976, 202274, 202273, 202272, 202270, 202267, 193584, 92011, 201460, 201459, 201458, 201457, 201456, 206560, 201455, 201454, 201421, 201420, 201419, 201418, 201417, 201416, 201415, 202022, 202017, 202016, 202015, 202012, 207416, 206110, 202036, 202035, 202034, 202033, 202032, 202031, 202030, 202029, 209101, 202009, 202007, 201496, 201495, 201493, 202758, 209052, 209047, 201494, 201490, 209041, 201491, 209053, 209046, 209044, 209045, 201489, 209040, 209051, 209054, 209050, 209049, 209048, 209043, 209042, 206623, 202008, 201492, 201488, 202026, 202025, 202024, 202023, 1684, 202028, 202027, 201511, 201509, 201508, 201506, 201500, 201503, 197193, 197192, 197191, 197190, 197189, 197188, 197187, 201514, 202257, 202253, 197134, 203978, 201513, 197139, 197137, 197122, 197121, 209114, 197135, 281339, 209124, 197175, 197174, 197150, 197149, 197148, 197147, 197146, 197117, 197116, 203801, 197142, 197120, 209116, 203800, 197133, 197131, 197173, 197172, 197132, 197118, 250672, 201555, 201554, 209692, 209039, 201556, 201551, 201550, 201549, 201548, 201547, 201545, 179706, 259114, 203762, 201553, 201552, 201546, 197124, 259008, 190536, 294556, 179882, 278802, 197143, 197144, 197141, 339211, 209544, 180034, 210177, 180045, 179965, 307280, 204043, 307293, 204272, 206589, 1975, 94188, 94187, 1972, 1970, 1971, 142079, 142078, 142077, 176491, 176488, 208333, 176790, 205056, 176496, 94186, 51702, 50983, 195586, 1967, 163645, 176504, 176490, 176489, 1969, 204273, 1964, 20691, 51703, 2551, 2076, 176493, 176492, 245190, 58, 179426, 2576, 2744, 204044, 57, 204000, 94185, 204001, 307345, 307282, 307319, 1962, 206590, 204591, 19030, 1826, 204464, 1825, 1824, 41, 204457, 1827, 170002, 321, 1822, 204447, 307269, 307323, 307283, 307278, 144111, 3705, 266281, 17154, 211498, 123210, 16399, 123207, 123212, 17153, 123209, 16398, 16400, 123208, 16397, 13965, 123213, 307317, 43122, 43120, 43119, 43118, 43117, 43116, 43121, 214516, 307310, 268757, 307297, 186559, 129206, 307315, 307324, 175740, 307264, 307289, 203983, 307270, 22674, 22673, 22672, 22671, 22670, 3803, 3804);
UPDATE `gameobject_template` SET `ContentTuningId`=642, `VerifiedBuild`=45338 WHERE `entry`=250629; -- Books
UPDATE `gameobject_template` SET `ContentTuningId`=642, `VerifiedBuild`=45338 WHERE `entry`=250628; -- Rune
UPDATE `gameobject_template` SET `ContentTuningId`=13, `VerifiedBuild`=45338 WHERE `entry`=204817; -- Lightforged Rod
UPDATE `gameobject_template` SET `ContentTuningId`=13, `VerifiedBuild`=45338 WHERE `entry`=204825; -- Lightforged Crest
UPDATE `gameobject_template` SET `ContentTuningId`=13, `VerifiedBuild`=45338 WHERE `entry`=204824; -- Lightforged Arch
UPDATE `gameobject_template` SET `ContentTuningId`=13, `VerifiedBuild`=45338 WHERE `entry`=61; -- A Weathered Grave
UPDATE `gameobject_template` SET `ContentTuningId`=13, `VerifiedBuild`=45338 WHERE `entry`=204816; -- Bloodsoaked Hat
UPDATE `gameobject_template` SET `ContentTuningId`=13, `VerifiedBuild`=45338 WHERE `entry`=21052; -- Defias Strongbox
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30890, `ContentTuningId`=10, `VerifiedBuild`=45338 WHERE `entry`=204352; -- Redridge Supply Crate
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=4564, `ContentTuningId`=10, `VerifiedBuild`=45338 WHERE `entry`=103628; -- Ur's Treatise on Shadow Magic
UPDATE `gameobject_template` SET `ContentTuningId`=10, `VerifiedBuild`=45338 WHERE `entry`=31; -- Old Lion Statue
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39335, `ContentTuningId`=7, `VerifiedBuild`=45338 WHERE `entry`=207485; -- Sturdy Treasure Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30936, `ContentTuningId`=10, `VerifiedBuild`=45338 WHERE `entry`=204437; -- Blackrock Key Pouch
UPDATE `gameobject_template` SET `ContentTuningId`=10, `VerifiedBuild`=45338 WHERE `entry`=204445; -- Blackrock Explosive Device
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=4564, `ContentTuningId`=10, `VerifiedBuild`=45338 WHERE `entry`=103628; -- Ur's Treatise on Shadow Magic
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30911, `ContentTuningId`=10, `VerifiedBuild`=45338 WHERE `entry`=204388; -- Blackrock Coffer
UPDATE `gameobject_template` SET `ContentTuningId`=10, `VerifiedBuild`=45338 WHERE `entry`=204351; -- Ettin Control Orb
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39335, `ContentTuningId`=7, `VerifiedBuild`=45338 WHERE `entry`=207485; -- Sturdy Treasure Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30890, `ContentTuningId`=10, `VerifiedBuild`=45338 WHERE `entry`=204352; -- Redridge Supply Crate
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30882, `ContentTuningId`=10, `VerifiedBuild`=45338 WHERE `entry`=204346; -- Gnoll Orders
UPDATE `gameobject_template` SET `ContentTuningId`=10, `VerifiedBuild`=45338 WHERE `entry`=204345; -- Gnoll Battle Plan
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=4184, `ContentTuningId`=73, `VerifiedBuild`=45338 WHERE `entry`=85563; -- Dead-tooth's Strongbox
UPDATE `gameobject_template` SET `ContentTuningId`=73, `VerifiedBuild`=45338 WHERE `entry`=203734; -- Westfall Deed
UPDATE `gameobject_template` SET `ContentTuningId`=338, `VerifiedBuild`=45338 WHERE `entry`=270848; -- Bloodsail Keg
UPDATE `gameobject_template` SET `ContentTuningId`=338, `VerifiedBuild`=45338 WHERE `entry`=270882; -- Bloodsail Keg Stand
UPDATE `gameobject_template` SET `ContentTuningId`=18, `VerifiedBuild`=45338 WHERE `entry`=2893; -- Zul'Mamwe Trophy Skulls
UPDATE `gameobject_template` SET `ContentTuningId`=18, `VerifiedBuild`=45338 WHERE `entry`=204247; -- Zul'Mamwe Brazier
UPDATE `gameobject_template` SET `ContentTuningId`=18, `VerifiedBuild`=45338 WHERE `entry` IN (204386, 204372); -- Zanzil's Portal
UPDATE `gameobject_template` SET `ContentTuningId`=24, `VerifiedBuild`=45338 WHERE `entry`=204400; -- Zanzil's Elixir
UPDATE `gameobject_template` SET `ContentTuningId`=18, `VerifiedBuild`=45338 WHERE `entry`=759; -- The Holy Spring
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30919, `ContentTuningId`=24, `VerifiedBuild`=45338 WHERE `entry`=204398; -- Bloodsail Sapphire
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30920, `ContentTuningId`=24, `VerifiedBuild`=45338 WHERE `entry`=204399; -- Bloodsail Ruby
UPDATE `gameobject_template` SET `ContentTuningId`=24, `VerifiedBuild`=45338 WHERE `entry`=204361; -- Totem of Hir'eek
UPDATE `gameobject_template` SET `ContentTuningId`=18, `VerifiedBuild`=45338 WHERE `entry` IN (264, 263); -- Kurzen Supplies
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=31051, `ContentTuningId`=18, `VerifiedBuild`=45338 WHERE `entry`=204827; -- Kurzen Compound Officers' Dossier
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=31050, `ContentTuningId`=18, `VerifiedBuild`=45338 WHERE `entry`=204826; -- Kurzen Compound Prison Records
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=2217, `ContentTuningId`=6, `VerifiedBuild`=45338 WHERE `entry`=2724; -- Sack of Oats
UPDATE `gameobject_template` SET `ContentTuningId`=864, `VerifiedBuild`=45338 WHERE `entry`=180665; -- Draconic for Dummies
UPDATE `gameobject_template` SET `ContentTuningId`=17, `VerifiedBuild`=45338 WHERE `entry`=2657; -- Legends of the Earth
UPDATE `gameobject_template` SET `ContentTuningId`=674, `VerifiedBuild`=45338 WHERE `entry`=316736; -- Kul Tiran
UPDATE `gameobject_template` SET `ContentTuningId`=674, `VerifiedBuild`=45338 WHERE `entry`=273853; -- Void Elf
UPDATE `gameobject_template` SET `ContentTuningId`=674, `VerifiedBuild`=45338 WHERE `entry`=273855; -- Lightforged Draenei
UPDATE `gameobject_template` SET `ContentTuningId`=674, `VerifiedBuild`=45338 WHERE `entry`=298865; -- Dark Iron Dwarf
UPDATE `gameobject_template` SET `ContentTuningId`=864, `VerifiedBuild`=45338 WHERE `entry`=278311; -- Bonfire
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=29946, `ContentTuningId`=864, `VerifiedBuild`=45338 WHERE `entry`=203751; -- Stormwind Pumpkin
UPDATE `gameobject_template` SET `ContentTuningId`=344, `VerifiedBuild`=45338 WHERE `entry`=267647; -- Paladin - Scenario - Cosmetic Item
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=45338 WHERE `entry`=310709; -- Waterlogged Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data18`=469, `Data23`=600, `Data24`=600, `Data30`=35546, `ContentTuningId`=469, `VerifiedBuild`=45338 WHERE `entry`=202655; -- Troll Archaeology Find
UPDATE `gameobject_template` SET `ContentTuningId`=18, `VerifiedBuild`=45338 WHERE `entry`=2891; -- Balia'mah Trophy Skulls
UPDATE `gameobject_template` SET `ContentTuningId`=18, `VerifiedBuild`=45338 WHERE `entry`=204087; -- Mosh'Ogg Bounty
UPDATE `gameobject_template` SET `ContentTuningId`=18, `VerifiedBuild`=45338 WHERE `entry`=2892; -- Ziata'jai Trophy Skulls
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=31050, `ContentTuningId`=18, `VerifiedBuild`=45338 WHERE `entry`=204826; -- Kurzen Compound Prison Records
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=31051, `ContentTuningId`=18, `VerifiedBuild`=45338 WHERE `entry`=204827; -- Kurzen Compound Officers' Dossier
UPDATE `gameobject_template` SET `ContentTuningId`=18, `VerifiedBuild`=45338 WHERE `entry`=181636; -- Altar of Naias
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=1692, `ContentTuningId`=18, `VerifiedBuild`=45338 WHERE `entry`=307267; -- The Emperor's Tomb
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=1691, `ContentTuningId`=18, `VerifiedBuild`=45338 WHERE `entry`=307338; -- Fall of Gurubashi
UPDATE `gameobject_template` SET `Data1`=0, `Data18`=469, `Data30`=35733, `ContentTuningId`=469, `VerifiedBuild`=45338 WHERE `entry`=206836; -- Fossil Archaeology Find
UPDATE `gameobject_template` SET `ContentTuningId`=13, `VerifiedBuild`=45338 WHERE `entry`=22706; -- Faustin's Alchemy Set
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30936, `ContentTuningId`=10, `VerifiedBuild`=45338 WHERE `entry`=204437; -- Blackrock Key Pouch
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39335, `ContentTuningId`=7, `VerifiedBuild`=45338 WHERE `entry`=207485; -- Sturdy Treasure Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=2953, `ContentTuningId`=683, `VerifiedBuild`=45338 WHERE `entry`=19019; -- Box of Assorted Parts
UPDATE `gameobject_template` SET `type`=50, `Data6`=30, `Data10`=0, `Data12`=0, `Data15`=0, `Data18`=5, `Data22`=1, `ContentTuningId`=8, `VerifiedBuild`=45338 WHERE `entry`=75293; -- Large Battered Chest
UPDATE `gameobject_template` SET `ContentTuningId`=202, `VerifiedBuild`=45338 WHERE `entry`=207079; -- Ball and Chain
UPDATE `gameobject_template` SET `ContentTuningId`=202, `VerifiedBuild`=45338 WHERE `entry`=208002; -- Goblin Teleporter
UPDATE `gameobject_template` SET `ContentTuningId`=202, `VerifiedBuild`=45338 WHERE `entry`=307274; -- Meeting Stone
UPDATE `gameobject_template` SET `ContentTuningId`=6, `VerifiedBuild`=45338 WHERE `entry`=194340; -- Dusty Journal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30073, `ContentTuningId`=6, `VerifiedBuild`=45338 WHERE `entry`=204015; -- The Moonbrook Times
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30075, `ContentTuningId`=6, `VerifiedBuild`=45338 WHERE `entry`=204017; -- Mysterious Propaganda
UPDATE `gameobject_template` SET `ContentTuningId`=6, `VerifiedBuild`=45338 WHERE `entry`=3643; -- Old Footlocker
UPDATE `gameobject_template` SET `ContentTuningId`=6, `VerifiedBuild`=45338 WHERE `entry`=204014; -- Informational Pamphlet
UPDATE `gameobject_template` SET `ContentTuningId`=6, `VerifiedBuild`=45338 WHERE `entry`=204016; -- Secret Journal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39335, `ContentTuningId`=7, `VerifiedBuild`=45338 WHERE `entry`=207485; -- Sturdy Treasure Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30064, `ContentTuningId`=6, `VerifiedBuild`=45338 WHERE `entry`=203982; -- Okra
UPDATE `gameobject_template` SET `ContentTuningId`=6, `VerifiedBuild`=45338 WHERE `entry`=290; -- Furlbrow's Wardrobe
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=2217, `ContentTuningId`=6, `VerifiedBuild`=45338 WHERE `entry`=2724; -- Sack of Oats
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30025, `ContentTuningId`=6, `VerifiedBuild`=45338 WHERE `entry`=203972; -- Fresh Dirt

DELETE FROM `gameobject_questitem` WHERE (`Idx`=0 AND `GameObjectEntry` IN (344604,307267,307338));
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(344604, 0, 175151, 45338), -- Fearbreaker
(307267, 0, 2008, 45338), -- The Emperor's Tomb
(307338, 0, 2007, 45338); -- Fall of Gurubashi

UPDATE `gameobject_questitem` SET `VerifiedBuild`=45338 WHERE (`Idx`=0 AND `GameObjectEntry` IN (119,204462,21052,154357,204352,103628,204437,204388,204346,204345,85563,2893,759,204398,204399,264,263,204827,204826,2724,203751,203801,203800,203762,278802,2891,204087,2892,20691,58,179426,57,204000,204591,204464,41,204457,321,194340,204015,204017,204014,204016,203982,290,203972)) OR (`Idx`=1 AND `GameObjectEntry` IN (204388,759,58,179426));

UPDATE `page_text` SET `VerifiedBuild`=45338 WHERE `ID` IN (3652, 3650, 3648, 3682, 3681, 3680, 3679, 3678, 3677, 3676, 3675, 3674, 3673, 3672, 3699, 3698, 3697, 3696, 3695, 3694, 3693, 3692, 3691, 3690, 3689, 3688, 3687, 3686, 3685, 3684, 3683, 53, 23, 22, 1991, 1990, 1989, 1988, 1987, 1986, 1985, 1984, 1983, 1982, 1981, 1980, 1979, 1978, 1977, 1976, 2011, 2010, 2009, 2008, 2007, 2006, 2005, 2004, 2003, 2002, 3656, 3636, 3635, 3637, 3634, 3633, 2067, 2066, 2065, 2064);

DELETE FROM `creature_queststarter` WHERE (`id`=45428 AND `quest`=27369);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(45428, 27369, 45745); -- Greasing the Wheel offered Gidwin Goldbraids

UPDATE `creature_queststarter` SET `VerifiedBuild`=45745 WHERE (`id`=46654 AND `quest` IN (27766,27765,27858,27827,27769,27771,27770)) OR (`id`=46653 AND `quest` IN (27776,27775)) OR (`id`=46652 AND `quest` IN (27764,27774)) OR (`id`=2860 AND `quest` IN (27823,27824)) OR (`id`=46650 AND `quest`=27763) OR (`id`=45729 AND `quest` IN (27487,27466,27525,27522,27489,27488,27526)) OR (`id`=45574 AND `quest` IN (27481,27482,27449)) OR (`id`=45736 AND `quest`=27479) OR (`id`=45735 AND `quest`=27477) OR (`id`=16134 AND `quest` IN (27457,27456)) OR (`id`=49856 AND `quest` IN (28755,28756)) OR (`id`=16116 AND `quest` IN (27620,27460)) OR (`id`=16112 AND `quest` IN (27618,27619,27616,27615,27614)) OR (`id`=16115 AND `quest` IN (27617,27613,27612)) OR (`id`=45831 AND `quest` IN (27539,27529,27528,27530)) OR (`id`=45816 AND `quest`=27523) OR (`id`=45451 AND `quest` IN (27532,27382)) OR (`id`=45417 AND `quest` IN (27524,27455,27448,27373,27370,27367)) OR (`id`=45826 AND `quest`=27521) OR (`id`=45482 AND `quest`=27422) OR (`id`=45575 AND `quest`=27450) OR (`id`=11035 AND `quest` IN (27452,27451,27454,27453)) OR (`id`=10926 AND `quest` IN (27391,27385,27392,27384)) OR (`id`=10667 AND `quest` IN (27390,27389,27388,27387)) OR (`id`=16135 AND `quest` IN (27420,27421)) OR (`id`=45500 AND `quest` IN (27544,27432)) OR (`id`=11063 AND `quest` IN (27386,27383)) OR (`id`=45429 AND `quest` IN (27381,27372,27371)) OR (`id`=45431 AND `quest` IN (27369,27463)) OR (`id`=45428 AND `quest`=27368) OR (`id`=44454 AND `quest` IN (27053,27055,27054,26935,26999)) OR (`id`=44458 AND `quest`=27017) OR (`id`=45147 AND `quest` IN (27155,27154,27153,27152,27151)) OR (`id`=44905 AND `quest`=26957) OR (`id`=45157 AND `quest` IN (27157,27156)) OR (`id`=10840 AND `quest` IN (27175,27683)) OR (`id`=44457 AND `quest`=26956) OR (`id`=45012 AND `quest`=27197) OR (`id`=45165 AND `quest` IN (27174,27173,27167,27202)) OR (`id`=10838 AND `quest` IN (27172,27169,27166)) OR (`id`=1854 AND `quest`=27170) OR (`id`=11053 AND `quest`=27168) OR (`id`=44453 AND `quest` IN (27165,27206,27204,27201,27205,27199,27163,27162,27159)) OR (`id`=47269 AND `quest`=27956) OR (`id`=4618 AND `quest`=27715) OR (`id`=2920 AND `quest`=27714) OR (`id`=2785 AND `quest`=27713) OR (`id`=46857 AND `quest` IN (27829,27835)) OR (`id`=46856 AND `quest`=27834) OR (`id`=46852 AND `quest`=27828) OR (`id`=46930 AND `quest` IN (28512,27927,27825)) OR (`id`=46972 AND `quest`=27833) OR (`id`=46664 AND `quest` IN (27826,27791,27789)) OR (`id`=46760 AND `quest` IN (27797,27796,27792)) OR (`id`=46655 AND `quest`=27772) OR (`id`=12384 AND `quest` IN (27533,27534)) OR (`id`=45828 AND `quest` IN (27531,27535)) OR (`id`=45730 AND `quest`=27527) OR (`id`=16365 AND `quest`=27467) OR (`id`=11034 AND `quest` IN (27465,27464)) OR (`id`=11036 AND `quest`=27459) OR (`id`=48704 AND `quest`=27762) OR (`id`=11033 AND `quest`=27458) OR (`id`=44456 AND `quest` IN (26955,26954,26953)) OR (`id`=44467 AND `quest` IN (27198,27164,27161)) OR (`id`=44471 AND `quest`=27160) OR (`id`=18221 AND `quest` IN (27918,27840,27860)) OR (`id`=46676 AND `quest` IN (27845,27843,27795,27822,27821,27851,27849)) OR (`id`=46071 AND `quest` IN (27870,27915,27704,27694)) OR (`id`=45948 AND `quest` IN (27740,27600,27599,27598)) OR (`id`=45786 AND `quest` IN (27597,27656,27536,27587)) OR (`id`=46182 AND `quest`=27663) OR (`id`=46010 AND `quest`=27592) OR (`id`=42349 AND `quest` IN (26187,26185,26184)) OR (`id`=42352 AND `quest`=26186) OR (`id`=11616 AND `quest` IN (27002,27001,27000)) OR (`id`=44472 AND `quest` IN (27012,27011,27013)) OR (`id`=17127 AND `quest` IN (24913,27904,27902,27876,27875)) OR (`id`=7783 AND `quest`=26171) OR (`id`=42298 AND `quest` IN (26170,26162,26161,26163,26169,26168,26167,26160,26172,26159,26158)) OR (`id`=42299 AND `quest` IN (26166,26165,26164)) OR (`id`=16841 AND `quest` IN (26175,26174,26173)) OR (`id`=41354 AND `quest` IN (25706,25705,25703)) OR (`id`=41265 AND `quest`=25702) OR (`id`=2496 AND `quest` IN (26703,26697,26698,26695,26678,26624,26612)) OR (`id`=2487 AND `quest` IN (26699,26700,26630)) OR (`id`=2546 AND `quest`=26650) OR (`id`=2547 AND `quest` IN (26649,26647)) OR (`id`=2634 AND `quest` IN (26606,26605,26604)) OR (`id`=43556 AND `quest`=26648) OR (`id`=2548 AND `quest` IN (26644,26633)) OR (`id`=46172 AND `quest` IN (27869,27818,27757,27691)) OR (`id`=5385 AND `quest` IN (26157,25716)) OR (`id`=9540 AND `quest` IN (25714,25709,25708,25715)) OR (`id`=42264 AND `quest`=25713) OR (`id`=42262 AND `quest`=25712) OR (`id`=5393 AND `quest` IN (25711,25710)) OR (`id`=2549 AND `quest`=26634) OR (`id`=2545 AND `quest`=26635) OR (`id`=43504 AND `quest` IN (26631,26629)) OR (`id`=2488 AND `quest`=26613) OR (`id`=2493 AND `quest`=26614) OR (`id`=2490 AND `quest` IN (26611,26609)) OR (`id`=2500 AND `quest`=26601);

UPDATE `creature_questender` SET `VerifiedBuild`=45745 WHERE (`id`=46654 AND `quest` IN (27766,27765,27764,27832,27826,27771,27770)) OR (`id`=46653 AND `quest` IN (27776,27775)) OR (`id`=46652 AND `quest` IN (27774,27763)) OR (`id`=46650 AND `quest`=27762) OR (`id`=45417 AND `quest` IN (27457,27466,27522,27487,27448,27373,27369,27372,27683,27527)) OR (`id`=45574 AND `quest` IN (27481,27482,27449)) OR (`id`=45736 AND `quest`=27479) OR (`id`=45735 AND `quest`=27477) OR (`id`=49856 AND `quest` IN (28755,28756)) OR (`id`=11036 AND `quest`=27620) OR (`id`=16116 AND `quest` IN (27618,27617,27459)) OR (`id`=16112 AND `quest` IN (27619,27616,27614,27615,27462)) OR (`id`=16115 AND `quest` IN (27613,27612,27461)) OR (`id`=45729 AND `quest` IN (27525,27524,27489,27488,27551)) OR (`id`=45831 AND `quest` IN (27539,27529,27528,27530)) OR (`id`=45816 AND `quest`=27523) OR (`id`=45826 AND `quest`=27521) OR (`id`=45575 AND `quest`=27450) OR (`id`=11035 AND `quest` IN (27452,27451,27454,27453)) OR (`id`=45400 AND `quest` IN (27558,27560,27555,27557,27556)) OR (`id`=10926 AND `quest` IN (27390,27392,27384,27383)) OR (`id`=10667 AND `quest` IN (27388,27389,27387,27386)) OR (`id`=16135 AND `quest` IN (27421,27420,27544)) OR (`id`=11063 AND `quest`=27385) OR (`id`=45500 AND `quest`=27432) OR (`id`=45451 AND `quest`=27382) OR (`id`=45429 AND `quest` IN (27381,27371,27370)) OR (`id`=45428 AND `quest` IN (27368,27367)) OR (`id`=44458 AND `quest` IN (27017,26957)) OR (`id`=44441 AND `quest` IN (27155,27002)) OR (`id`=45147 AND `quest` IN (27154,27153,27152,27151)) OR (`id`=45157 AND `quest` IN (27157,27156)) OR (`id`=44454 AND `quest` IN (27175,27055,27054,27057,26999)) OR (`id`=45165 AND `quest` IN (27174,27173,27172,27167,27202)) OR (`id`=10838 AND `quest` IN (27171,27166,27165,27206)) OR (`id`=11053 AND `quest`=27168) OR (`id`=1854 AND `quest`=27169) OR (`id`=44453 AND `quest` IN (27163,27164,27162,27204,27201,27205,27199,27197,27159,28749)) OR (`id`=47266 AND `quest`=28512) OR (`id`=46664 AND `quest` IN (27859,27794,27789,27772)) OR (`id`=4618 AND `quest`=27715) OR (`id`=2920 AND `quest`=27714) OR (`id`=2785 AND `quest` IN (27713,27927)) OR (`id`=46972 AND `quest`=27833) OR (`id`=46930 AND `quest`=27825) OR (`id`=46857 AND `quest`=27835) OR (`id`=46856 AND `quest`=27834) OR (`id`=46855 AND `quest`=27828) OR (`id`=46852 AND `quest`=27827) OR (`id`=46760 AND `quest` IN (27792,27791)) OR (`id`=2860 AND `quest` IN (27824,27823)) OR (`id`=46655 AND `quest`=27769) OR (`id`=12384 AND `quest` IN (27534,27533,27535)) OR (`id`=45828 AND `quest` IN (27531,27532)) OR (`id`=45730 AND `quest`=27526) OR (`id`=11034 AND `quest` IN (27465,27464,27463)) OR (`id`=16365 AND `quest`=27467) OR (`id`=11033 AND `quest`=27458) OR (`id`=16134 AND `quest`=27456) OR (`id`=45431 AND `quest`=27455) OR (`id`=44456 AND `quest` IN (26955,26954,26953)) OR (`id`=44467 AND `quest` IN (27198,27161)) OR (`id`=44471 AND `quest`=27160) OR (`id`=18221 AND `quest` IN (27840,27860)) OR (`id`=46676 AND `quest` IN (27845,27843,27795,27822,27821,27870,27851,27849)) OR (`id`=46071 AND `quest` IN (27914,27704,27694,27869)) OR (`id`=45948 AND `quest` IN (27600,27599,27598,27597)) OR (`id`=46182 AND `quest`=27663) OR (`id`=45786 AND `quest` IN (27656,27536,27587)) OR (`id`=46010 AND `quest`=27592) OR (`id`=42349 AND `quest` IN (26187,26186,26184,26175)) OR (`id`=42352 AND `quest`=26185) OR (`id`=44472 AND `quest` IN (27012,27011,27013)) OR (`id`=11616 AND `quest` IN (27001,27000,26935)) OR (`id`=44457 AND `quest`=26956) OR (`id`=17127 AND `quest` IN (24913,27904,27902,27876,27875,27918)) OR (`id`=42299 AND `quest` IN (26171,26165,26164,26163)) OR (`id`=7783 AND `quest` IN (26170,26162)) OR (`id`=42298 AND `quest` IN (26161,26166,26169,26168,26167,26160,26159,26172,26158,26157)) OR (`id`=16841 AND `quest` IN (26174,26173)) OR (`id`=7363 AND `quest` IN (25772,25771)) OR (`id`=41354 AND `quest` IN (25706,25705,25703,25702)) OR (`id`=2496 AND `quest` IN (26703,26697,26699,26700,26695,26679,26665,26612,26611)) OR (`id`=2487 AND `quest` IN (26698,26630,26617)) OR (`id`=2547 AND `quest` IN (26649,26647)) OR (`id`=2634 AND `quest` IN (26606,26605,26604,26603)) OR (`id`=43556 AND `quest`=26648) OR (`id`=2546 AND `quest`=26644) OR (`id`=2549 AND `quest`=26634) OR (`id`=2548 AND `quest` IN (26633,26631)) OR (`id`=2545 AND `quest`=26635) OR (`id`=46172 AND `quest` IN (27818,27757,27691,27740)) OR (`id`=5385 AND `quest` IN (25716,25714)) OR (`id`=9540 AND `quest` IN (25709,25708,25715)) OR (`id`=42262 AND `quest`=25712) OR (`id`=5393 AND `quest` IN (25711,25710,28867)) OR (`id`=42264 AND `quest`=25713) OR (`id`=43504 AND `quest` IN (26629,26624)) OR (`id`=2493 AND `quest`=26614) OR (`id`=2488 AND `quest`=26613) OR (`id`=2490 AND `quest`=26610) OR (`id`=2501 AND `quest`=26595) OR (`id`=2500 AND `quest` IN (26601,26602));

UPDATE `gameobject_queststarter` SET `VerifiedBuild`=45745 WHERE (`id`=206374 AND `quest`=27794) OR (`id`=206335 AND `quest`=27693) OR (`id`=206336 AND `quest`=27709) OR (`id`=205875 AND `quest` IN (27462,27461)) OR (`id`=176392 AND `quest`=27057) OR (`id`=205258 AND `quest`=27171) OR (`id`=204578 AND `quest`=26679) OR (`id`=204450 AND `quest` IN (26665,26664,26663,26662)) OR (`id`=2083 AND `quest`=26610);

UPDATE `gameobject_questender` SET `VerifiedBuild`=45745 WHERE (`id`=208137 AND `quest`=28955) OR (`id`=206504 AND `quest`=27930) OR (`id`=208121 AND `quest`=28956) OR (`id`=206374 AND `quest`=27912) OR (`id`=206335 AND `quest`=27796) OR (`id`=206336 AND `quest`=27797) OR (`id`=190108 AND `quest`=12402) OR (`id`=205875 AND `quest`=27460) OR (`id`=176392 AND `quest`=27053) OR (`id`=177544 AND `quest`=27391) OR (`id`=205258 AND `quest`=27170) OR (`id`=204578 AND `quest`=26678) OR (`id`=204450 AND `quest` IN (26664,26663,26662,26650)) OR (`id`=2083 AND `quest`=26609);

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (46881,46882,41279,41280,7783,51523,50738,44406,43717,43790,43760,43740,43716,43700,43726,2752,1494,10945,10936,10938,10947,47128,10954,10937,10950,10946,10944,10949,10953,10951,10952,10948,47097,46471,46467,8303,10820,8116,8302,43553,102288,43194,43506,43507,4463,46371,45450,50856,44458,47064,45707,51018,45209,100200,100199,99998,99980,99976,100008,100009,100201,100196,100194,99990,99984,99978,92151,100010,100203,100195,100002,100001,99987,99947,115952,99945,99944,99943,93787,98279,98249,98245,116608,98251,113922,113921,92314,113923,90350,92316,100126,100123,100122,100121,100119,100117,100116,100110,100106,100104,100102,109255,100142,100140,100139,100138,100137,100136,100133,100131,100130,100127,100124,100118,100120,100113,100114,92271,92270,100105,100107,100103,100202,100146,92148,100145,100198,100148,100197,100141,99999,100135,99994,99992,100134,100129,100128,46369,44628,2057,1379,2476,45402,50964,46096,2557,51633,51631,8212,1784,1783,45155,45154,50906,2751,45934,45914,92147,92145,44624,44625,50797,45431,51792,10823,9916,45260,42298,22816,51000,46095,45730,46655,45235,45239,45243,45242,45241,45240,45249,10828,51334,51053,46876,46874,46870,46869,45729,41178,2731,763,44450,46658,46775,46770,46765,44448,44449,44946,44944,46094,46093,46092,14445,45574));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(46881, 0, 0, 0, 31, 45745),
(46882, 0, 0, 0, 31, 45745),
(41279, 0, 0, 0, 34, 45745),
(41280, 0, 0, 0, 34, 45745),
(7783, 0, 0, 0, 34, 45745),
(51523, 0, 0, 0, 2108, 45745),
(50738, 0, 0, 0, 31, 45745),
(44406, 0, 0, 0, 24, 45745),
(43717, 0, 0, 0, 24, 45745),
(43790, 0, 0, 0, 24, 45745),
(43760, 0, 0, 0, 24, 45745),
(43740, 0, 0, 0, 24, 45745),
(43716, 0, 0, 0, 24, 45745),
(43700, 0, 0, 0, 24, 45745),
(43726, 0, 0, 0, 24, 45745),
(2752, 0, 0, 0, 27, 45745),
(1494, 0, 0, 0, 24, 45745),
(10945, 0, 0, 0, 35, 45745),
(10936, 0, 0, 0, 35, 45745),
(10938, 0, 0, 0, 35, 45745),
(10947, 0, 0, 0, 35, 45745),
(47128, 0, 0, 0, 27, 45745),
(10954, 0, 0, 0, 35, 45745),
(10937, 0, 0, 0, 35, 45745),
(10950, 0, 0, 0, 35, 45745),
(10946, 0, 0, 0, 35, 45745),
(10944, 0, 0, 0, 35, 45745),
(10949, 0, 0, 0, 35, 45745),
(10953, 0, 0, 0, 35, 45745),
(10951, 0, 0, 0, 35, 45745),
(10952, 0, 0, 0, 35, 45745),
(10948, 0, 0, 0, 35, 45745),
(47097, 0, 0, 0, 27, 45745),
(46471, 0, 0, 0, 27, 45745),
(46467, 0, 0, 0, 27, 45745),
(8303, 0, 0, 0, 34, 45745),
(10820, 0, 0, 0, 35, 45745),
(8116, 0, 0, 0, 24, 45745),
(8302, 0, 0, 0, 34, 45745),
(43553, 0, 0, 0, 24, 45745),
(102288, 0, 0, 0, 642, 45745),
(43194, 0, 0, 0, 10, 45745),
(43506, 0, 0, 0, 24, 45745),
(43507, 0, 0, 0, 24, 45745),
(4463, 0, 0, 0, 10, 45745),
(46371, 0, 0, 0, 31, 45745),
(45450, 0, 0, 0, 35, 45745),
(50856, 0, 0, 0, 35, 45745),
(44458, 0, 0, 0, 25, 45745),
(47064, 0, 0, 0, 35, 45745),
(45707, 0, 0, 0, 35, 45745),
(51018, 0, 0, 0, 27, 45745),
(45209, 0, 0, 0, 25, 45745),
(100200, 0, 0, 0, 633, 45745),
(100199, 0, 0, 0, 633, 45745),
(99998, 0, 0, 0, 633, 45745),
(99980, 0, 0, 0, 633, 45745),
(99976, 0, 0, 0, 633, 45745),
(100008, 0, 0, 0, 633, 45745),
(100009, 0, 0, 0, 633, 45745),
(100201, 0, 0, 0, 633, 45745),
(100196, 0, 0, 0, 633, 45745),
(100194, 0, 0, 0, 633, 45745),
(99990, 0, 0, 0, 633, 45745),
(99984, 0, 0, 0, 633, 45745),
(99978, 0, 0, 0, 633, 45745),
(92151, 0, 0, 0, 633, 45745),
(100010, 0, 0, 0, 633, 45745),
(100203, 0, 0, 0, 633, 45745),
(100195, 0, 0, 0, 633, 45745),
(100002, 0, 0, 0, 633, 45745),
(100001, 0, 0, 0, 633, 45745),
(99987, 0, 0, 0, 633, 45745),
(99947, 0, 0, 0, 633, 45745),
(115952, 0, 0, 0, 633, 45745),
(99945, 0, 0, 0, 633, 45745),
(99944, 0, 0, 0, 633, 45745),
(99943, 0, 0, 0, 633, 45745),
(93787, 0, 0, 0, 633, 45745),
(98279, 0, 0, 0, 633, 45745),
(98249, 0, 0, 0, 633, 45745),
(98245, 0, 0, 0, 633, 45745),
(116608, 0, 0, 0, 633, 45745),
(98251, 0, 0, 0, 633, 45745),
(113922, 0, 0, 0, 633, 45745),
(113921, 0, 0, 0, 633, 45745),
(92314, 0, 0, 0, 633, 45745),
(113923, 0, 0, 0, 633, 45745),
(90350, 0, 0, 0, 633, 45745),
(92316, 0, 0, 0, 633, 45745),
(100126, 0, 0, 0, 633, 45745),
(100123, 0, 0, 0, 633, 45745),
(100122, 0, 0, 0, 633, 45745),
(100121, 0, 0, 0, 633, 45745),
(100119, 0, 0, 0, 633, 45745),
(100117, 0, 0, 0, 633, 45745),
(100116, 0, 0, 0, 633, 45745),
(100110, 0, 0, 0, 633, 45745),
(100106, 0, 0, 0, 633, 45745),
(100104, 0, 0, 0, 633, 45745),
(100102, 0, 0, 0, 633, 45745),
(109255, 0, 0, 0, 773, 45745),
(100142, 0, 0, 0, 633, 45745),
(100140, 0, 0, 0, 633, 45745),
(100139, 0, 0, 0, 633, 45745),
(100138, 0, 0, 0, 633, 45745),
(100137, 0, 0, 0, 633, 45745),
(100136, 0, 0, 0, 633, 45745),
(100133, 0, 0, 0, 633, 45745),
(100131, 0, 0, 0, 633, 45745),
(100130, 0, 0, 0, 633, 45745),
(100127, 0, 0, 0, 633, 45745),
(100124, 0, 0, 0, 633, 45745),
(100118, 0, 0, 0, 633, 45745),
(100120, 0, 0, 0, 633, 45745),
(100113, 0, 0, 0, 633, 45745),
(100114, 0, 0, 0, 633, 45745),
(92271, 0, 0, 0, 633, 45745),
(92270, 0, 0, 0, 633, 45745),
(100105, 0, 0, 0, 633, 45745),
(100107, 0, 0, 0, 633, 45745),
(100103, 0, 0, 0, 633, 45745),
(100202, 0, 0, 0, 633, 45745),
(100146, 0, 0, 0, 633, 45745),
(92148, 0, 0, 0, 633, 45745),
(100145, 0, 0, 0, 633, 45745),
(100198, 0, 0, 0, 633, 45745),
(100148, 0, 0, 0, 633, 45745),
(100197, 0, 0, 0, 633, 45745),
(100141, 0, 0, 0, 633, 45745),
(99999, 0, 0, 0, 633, 45745),
(100135, 0, 0, 0, 633, 45745),
(99994, 0, 0, 0, 633, 45745),
(99992, 0, 0, 0, 633, 45745),
(100134, 0, 0, 0, 633, 45745),
(100129, 0, 0, 0, 633, 45745),
(100128, 0, 0, 0, 633, 45745),
(46369, 0, 0, 0, 31, 45745),
(44628, 0, 0, 0, 9, 45745),
(2057, 0, 0, 0, 9, 45745),
(1379, 0, 0, 0, 9, 45745),
(2476, 0, 0, 0, 9, 45745),
(45402, 0, 0, 0, 9, 45745),
(50964, 0, 0, 0, 15, 45745),
(46096, 0, 0, 0, 35, 45745),
(2557, 0, 0, 0, 17, 45745),
(51633, 0, 0, 0, 17, 45745),
(51631, 0, 0, 0, 17, 45745),
(8212, 0, 0, 0, 20, 45745),
(1784, 0, 0, 0, 25, 45745),
(1783, 0, 0, 0, 25, 45745),
(45155, 0, 0, 0, 25, 45745),
(45154, 0, 0, 0, 25, 45745),
(50906, 0, 0, 0, 25, 45745),
(2751, 0, 0, 0, 27, 45745),
(45934, 0, 0, 0, 31, 45745),
(45914, 0, 0, 0, 31, 45745),
(92147, 0, 0, 0, 633, 45745),
(92145, 0, 0, 0, 633, 45745),
(44624, 0, 0, 0, 25, 45745),
(44625, 0, 0, 0, 25, 45745),
(50797, 0, 0, 0, 31, 45745),
(45431, 0, 0, 0, 35, 45745),
(51792, 0, 0, 0, 2108, 45745),
(10823, 0, 0, 0, 35, 45745),
(9916, 0, 0, 0, 31, 45745),
(45260, 0, 0, 0, 34, 45745),
(42298, 0, 0, 0, 34, 45745),
(22816, 0, 0, 0, 425, 45745),
(51000, 0, 0, 0, 27, 45745),
(46095, 0, 0, 0, 35, 45745),
(45730, 0, 0, 0, 35, 45745),
(46655, 0, 0, 0, 27, 45745),
(45235, 0, 0, 0, 25, 45745),
(45239, 0, 0, 0, 25, 45745),
(45243, 0, 0, 0, 25, 45745),
(45242, 0, 0, 0, 25, 45745),
(45241, 0, 0, 0, 25, 45745),
(45240, 0, 0, 0, 25, 45745),
(45249, 0, 0, 0, 25, 45745),
(10828, 0, 0, 0, 35, 45745),
(51334, 0, 0, 0, 2108, 45745),
(51053, 0, 0, 0, 35, 45745),
(46876, 0, 0, 0, 31, 45745),
(46874, 0, 0, 0, 31, 45745),
(46870, 0, 0, 0, 31, 45745),
(46869, 0, 0, 0, 31, 45745),
(45729, 0, 0, 0, 35, 45745),
(41178, 0, 0, 0, 35, 45745),
(2731, 0, 0, 0, 27, 45745),
(763, 0, 0, 0, 31, 45745),
(44450, 0, 0, 0, 25, 45745),
(46658, 0, 0, 0, 27, 45745),
(46775, 0, 0, 0, 31, 45745),
(46770, 0, 0, 0, 31, 45745),
(46765, 0, 0, 0, 31, 45745),
(44448, 0, 0, 0, 25, 45745),
(44449, 0, 0, 0, 25, 45745),
(44946, 0, 0, 0, 25, 45745),
(44944, 0, 0, 0, 25, 45745),
(46094, 0, 0, 0, 35, 45745),
(46093, 0, 0, 0, 35, 45745),
(46092, 0, 0, 0, 35, 45745),
(14445, 0, 0, 0, 31, 45745),
(45574, 0, 0, 0, 35, 45745);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=45745 WHERE (`DifficultyID`=0 AND `Entry` IN (5524,44984,44983,44986,44985,44321,8022,8178,5508,9540,44333,44325,42264,42262,5393,44330,44324,3546,88206,76672,78695,77723,77721,77767,77724,76609,76524,77640,76556,77090,77771,82451,78488,78345,78489,78348,78667,44113,1489,1490,2535,1491,5591,72944,985,864,989,6930,27705,8177,10049,5547,5546,987,984,983,982,17109,6026,7623,5416,981,980,8176,3622,988,1386,12807,47268,47267,47266,47269,52021,6009,6008,7506,7505,5976,6007,5974,5975,4872,4845,4846,4844,51007,67522,51021,47018,47013,61321,2861,46916,46861,46486,46860,46938,1407,1068,10058,9356,46660,2908,48125,47148,45575,47153,47149,11035,44231,47073,46917,46918,1492,61329,46749,46748,14448,45157,45150,10262,10260,45486,47875,45487,8816,46928,45488,45485,46929,8546,8550,7363,41166,44343,41159,16841,16840,19254,42299,42301,41269,41165,2717,2718,44485,150987,61323,1907,690,772,1144,1142,61314,14487,43050,4461,66983,66982,65677,63194,4457,686,1152,681,1150,682,683,754,61322,734,739,733,469,43045,43799,2634,44089,43732,61258,628,898,61255,45517,61169,225,1676,271,270,269,268,263,374,325,3137,3133,17104,664,267,44022,43453,3136,226,633,661,2409,264,3138,620,5464,826,885,828,2470,663,468,576,1673,1672,265,11040,495,10062,494,2668,2669,886,274,273,2112,6790,228,227,840,960,272,1559,49673,1270,61143,2142,3134,17467,43417,2521,732,166638,217,43704,61320,2522,379,43081,43080,464,43178,442,848,5608,5607,931,6966,7009,1070,934,382,8965,8963,8962,903,932,43041,45258,1885,43533,43535,14269,7013,2442,43106,1083,43083,424,426,423,712,935,933,66965,66964,65651,65668,43183,137757,137783,137778,28333,422,430,61171,437,446,44433,44622,2831,46854,46852,48093,46930,46972,48095,48098,48096,44410,46915,46914,44484,44486,46859,2730,2734,4618,2785,2920,43094,615,547,49995,43327,43329,61168,4064,43340,43341,545,578,43371,43594,43532,548,4462,14272,428,44623,61167,49996,50479,43504,8545,43659,44182,2551,16229,16228,46016,10926,43562,43560,43561,43853,47053,2672,49722,11706,46167,8532,111122,43107,47144,47142,45736,45735,44230,44336,44337,44334,42349,44335,42352,42350,307,306,65656,65676,65675,66930,1841,11620,11621,50779,44444,8564,47167,47164,47165,45482,47166,45826,28621,44442,8563,8565,10824,44902,44443,41402,41422,41195,41177,45816,41423,11897,45117,43536,41405,158637,2546,2547,11289,11288,10817,11034,16135,8529,41430,2860,46659,2910,46762,46761,46760,48090,44409,45453,45212,41404,42367,41254,118411,92168,92167,92166,92165,59113,51027,42334,46650,49925,49917,49919,49918,50514,49912,49937,49935,49922,49920,49934,49921,49953,49936,49932,49926,49924,46365,47545,46172,47547,46366,41359,46367,41162,41171,41386,41387,41354,46629,45336,44141,1933,8299,44188,44184,44176,1693,61459,2098,61142,33497,44626,2914,45404,44724,44729,44627,44620,46503,47530,45948,47532,41137,41132,61677,31890,42064,42041,42042,42043,6271,61384,41453,41628,41449,49910,66512,66487,66486,66485,41295,1063,2556,41384,41385,44438,8298,18562,2555,17127,47368,47367,1776,61071,11874,43088,2554,2619,44472,47370,11198,11616,47761,44836,2578,2620,5998,2621,42130,49999,5997,9555,41149,2563,44435,2761,61704,2559,10667,45500,44232,11063,47139,2640,42919,7865,44776,4467,44284,2680,2639,51986,35114,4466,2925,44309,41124,2928,44551,2659,5996,44310,44311,41125,61753,41136,16030,45031,44312,43121,41127,44313,61718,2656,2655,2929,41138,61752,22480,2723,2745,2742,61319,44479,44478,1412,46245,11038,8528,45695,45692,8542,45691,29196,28489,29194,28488,29195,28491,32545,28490,28481,29205,163148,32542,54344,45701,46014,29208,46950,32543,32546,29207,28512,28500,29203,29212,50837,2743,42231,1442,866,47041,46953,29239,28486,29246,29589,29588,29587,27928,163640,23033,29480,29202,5476,7572,1804,11102,11152,11078,1802,4472,48249,92149,96709,44483,2740,2739,16376,16365,48708,48705,48704,16283,16256,49856,11536,16284,111977,12636,47288,47286,12617,11039,11036,11033,111976,16378,47289,17072,17069,16212,12941,46022,16225,5985,41265,44142,45153,14463,16116,16115,16112,44445,61326,5977,5978,1815,42338,42337,42336,42348,41164,44341,42346,42344,61327,44339,44340,43114,27946,61080,45087,45118,41253,45887,42359,42232,5983,42248,5992,45967,46146,45125,42244,42249,10822,12384,11140,9699,25109,5990,42297,8562,44474,44432,44476,44482,10605,1835,1831,1839,46695,46693,46694,42228,45950,46424,5269,43454,43364,46071,16117,61328,45428,8558,8557,8556,8555,45439,45828,47106,47105,44240,44233,47104,8597,8560,17878,45208,12596,11609,10838,46269,12942,44473,48054,44407,48058,10857,11056,12425,10840,48055,11053,17238,48057,48056,883,48067,46653,46652,48060,48064,48075,44475,46654,48068,61438,61443,45475,92,45897,2728,46664,61081,61440,46464,46769,46757,46758,48123,46768,61439,46759,46707,48122,46713,44408,2729,46772,2830,16134,45451,49840,2732,49833,46773,46393,61441,32258,43605,43660,43661,44178,44179,1653,2548,2549,4506,43556,4505,2545,1565,43636,46138,8524,8523,8609,45165,45156,2836,2849,2846,96474,2859,2627,2848,908,2837,2670,49636,49635,2622,151042,2843,2542,2838,2493,2491,2842,2488,43505,9858,2498,6807,737,1411,7406,10060,54232,2699,2626,2501,44112,2858,15677,43849,2834,2832,2487,2625,2496,2486,8123,2490,15681,17249,21045,2494,14490,17253,1854,10927,11872,45166,11896,922,45809,8561,46010,10818,45149,44322,5385,5525,8537,8540,8522,8521,44436,1838,8535,12250,11291,11290,45148,1088,39308,45856,45852,44441,47340,47338,47343,46188,46184,46182,23837,46187,43086,2829,50512,48686,47334,47059,47337,46189,45786,47347,47345,45791,45147,44905,46190,44439,45151,44440,45743,45152,44437,45162,8544,45744,5225,46656,4075,5263,66494,66493,66492,66518,8527,8598,105637,8602,14356,45444,45443,45429,45851,45868,45831,45886,45893,45867,8530,8553,8547,45895,44481,49944,47060,8605,61257,47719,47721,46006,13321,45825,6827,61312,41471,41470,44360,47717,45119,46840,46841,47363,61370,43087,18221,46415,46702,45807,37888,45416,45434,45433,45417,45400,1106,25082,25078,25111,25098,25097,25096,25095,25094,25093,25089,6653,15384,102134,102124,9559,4631,2500,48797,48808,2594,61367,20102,2502,10779,3945,2482,2840,2847,2499,2685,7794,54308,41200,759,61372,2839,2664,2844,2845,1493,2663,47667,9600,28180,7390,7389,46676,8596,61828,54475,4076,61829,8603,4624,46164,46166,46714,46487,1561,44775,15475,41158,1562,50487,16399,49928,61313,6011,8520,1557,61830,8519,6010,44344,8534,46414,1844,2544,8600,61827,8543,43376,2110,8548,8526,8538,8551,44466,47864,47854,44359,8541,8525,8531,45664,45655,45657,45650,46004,47857,44447,47856,47866,47858,20725,44453,44467,47860,44452,47863,44462,9449,9451,9448,9450,9452,6547,9447,42296,6005,6004,42235,6006,1824,46623,5261,5243,46068,1822,2725,2726,44318,1852,44317,44471,44323,44326,49933,50594,50511,48248,61826,44315,44562,44328,44316,721,1817,45423,44863,47758,47757,47756,45013,45012,46011,44457,44456,44454,11194,46997,10780,45681,8601,43377,61318,1558,43596,761,61368,760,50000,44140,858));

DELETE FROM `gossip_menu` WHERE (`MenuID`=14293 AND `TextID`=19888);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(14293, 19888, 45745); -- 29194 (Amal'thazad)

UPDATE `gossip_menu` SET `VerifiedBuild`=45745 WHERE (`MenuID`=12148 AND `TextID`=17078) OR (`MenuID`=12149 AND `TextID`=17080) OR (`MenuID`=10181 AND `TextID`=14126) OR (`MenuID`=9868 AND `TextID`=9850) OR (`MenuID`=9821 AND `TextID`=13584) OR (`MenuID`=12229 AND `TextID`=17172) OR (`MenuID`=12596 AND `TextID`=17726) OR (`MenuID`=12022 AND `TextID` IN (16946,16947,16945,16848,16948)) OR (`MenuID`=12041 AND `TextID`=16871) OR (`MenuID`=12034 AND `TextID` IN (16963,16864)) OR (`MenuID`=12035 AND `TextID`=16865) OR (`MenuID`=7103 AND `TextID` IN (8357,16964)) OR (`MenuID`=12530 AND `TextID`=17611) OR (`MenuID`=7096 AND `TextID`=16979) OR (`MenuID`=7099 AND `TextID`=8353) OR (`MenuID`=7097 AND `TextID`=8351) OR (`MenuID`=3141 AND `TextID`=3873) OR (`MenuID`=12080 AND `TextID`=16951) OR (`MenuID`=12061 AND `TextID`=16909) OR (`MenuID`=7175 AND `TextID` IN (8455,8454)) OR (`MenuID`=3651 AND `TextID`=4450) OR (`MenuID`=12033 AND `TextID`=14125) OR (`MenuID`=3861 AND `TextID`=4778) OR (`MenuID`=3922 AND `TextID`=4777) OR (`MenuID`=2911 AND `TextID`=3584) OR (`MenuID`=3864 AND `TextID`=4716) OR (`MenuID`=12023 AND `TextID`=16849) OR (`MenuID`=7104 AND `TextID`=8358) OR (`MenuID`=12030 AND `TextID`=16862) OR (`MenuID`=12026 AND `TextID`=16858) OR (`MenuID`=11911 AND `TextID`=16727) OR (`MenuID`=11942 AND `TextID`=16762) OR (`MenuID`=11937 AND `TextID`=16757) OR (`MenuID`=11936 AND `TextID`=16756) OR (`MenuID`=11935 AND `TextID`=16755) OR (`MenuID`=11934 AND `TextID`=16754) OR (`MenuID`=11941 AND `TextID`=16761) OR (`MenuID`=11940 AND `TextID`=16760) OR (`MenuID`=11939 AND `TextID`=16759) OR (`MenuID`=11938 AND `TextID`=16758) OR (`MenuID`=11943 AND `TextID`=16763) OR (`MenuID`=3383 AND `TextID`=4135) OR (`MenuID`=12722 AND `TextID`=17855) OR (`MenuID`=11953 AND `TextID`=16780) OR (`MenuID`=3042 AND `TextID`=3754) OR (`MenuID`=11947 AND `TextID`=16774) OR (`MenuID`=3801 AND `TextID`=4633) OR (`MenuID`=3184 AND `TextID`=3940) OR (`MenuID`=3441 AND `TextID`=4194) OR (`MenuID`=3228 AND `TextID`=3984) OR (`MenuID`=12454 AND `TextID`=7778) OR (`MenuID`=3602 AND `TextID`=4354) OR (`MenuID`=12100 AND `TextID`=16988) OR (`MenuID`=7385 AND `TextID`=8846) OR (`MenuID`=11895 AND `TextID`=16687) OR (`MenuID`=12280 AND `TextID`=17247) OR (`MenuID`=12209 AND `TextID`=17151) OR (`MenuID`=12131 AND `TextID`=17038) OR (`MenuID`=12207 AND `TextID`=17143) OR (`MenuID`=12205 AND `TextID`=17143) OR (`MenuID`=12206 AND `TextID`=17143) OR (`MenuID`=12204 AND `TextID`=17143) OR (`MenuID`=12202 AND `TextID`=17140) OR (`MenuID`=12225 AND `TextID`=17168) OR (`MenuID`=12147 AND `TextID` IN (17075,17073)) OR (`MenuID`=12146 AND `TextID` IN (17074,17072)) OR (`MenuID`=12081 AND `TextID` IN (16958,16956)) OR (`MenuID`=12082 AND `TextID`=16957) OR (`MenuID`=7173 AND `TextID`=8448) OR (`MenuID`=4085 AND `TextID` IN (4980,4979)) OR (`MenuID`=12086 AND `TextID`=16966) OR (`MenuID`=12088 AND `TextID`=16970) OR (`MenuID`=15016 AND `TextID`=21240) OR (`MenuID`=7215 AND `TextID`=8506) OR (`MenuID`=7174 AND `TextID`=8452) OR (`MenuID`=7219 AND `TextID`=8513) OR (`MenuID`=7157 AND `TextID`=8422) OR (`MenuID`=7109 AND `TextID`=8366) OR (`MenuID`=3181 AND `TextID`=3935) OR (`MenuID`=9706 AND `TextID`=13262) OR (`MenuID`=9877 AND `TextID`=13699) OR (`MenuID`=12043 AND `TextID`=16873) OR (`MenuID`=11899 AND `TextID` IN (16711,16694)) OR (`MenuID`=7618 AND `TextID`=9270) OR (`MenuID`=12155 AND `TextID`=17091) OR (`MenuID`=12119 AND `TextID`=17019) OR (`MenuID`=12102 AND `TextID`=16990) OR (`MenuID`=12292 AND `TextID`=17263) OR (`MenuID`=12099 AND `TextID`=16987) OR (`MenuID`=12103 AND `TextID`=16991) OR (`MenuID`=15018 AND `TextID`=21244) OR (`MenuID`=342 AND `TextID`=820) OR (`MenuID`=5824 AND `TextID`=6995) OR (`MenuID`=11898 AND `TextID`=16691) OR (`MenuID`=3821 AND `TextID`=4357) OR (`MenuID`=12511 AND `TextID`=17599) OR (`MenuID`=12161 AND `TextID`=17100) OR (`MenuID`=1541 AND `TextID`=2213) OR (`MenuID`=11613 AND `TextID`=16214) OR (`MenuID`=11487 AND `TextID`=16031) OR (`MenuID`=11619 AND `TextID`=16220) OR (`MenuID`=7350 AND `TextID`=8770) OR (`MenuID`=11491 AND `TextID`=16035) OR (`MenuID`=11507 AND `TextID`=16059) OR (`MenuID`=11479 AND `TextID`=16016) OR (`MenuID`=11490 AND `TextID`=16034) OR (`MenuID`=17269 AND `TextID`=25558) OR (`MenuID`=6685 AND `TextID` IN (7965,16588)) OR (`MenuID`=12643 AND `TextID` IN (16500,16486)) OR (`MenuID`=11744 AND `TextID` IN (16589,16441)) OR (`MenuID`=11756 AND `TextID`=16469) OR (`MenuID`=11754 AND `TextID`=16464) OR (`MenuID`=11753 AND `TextID`=16463) OR (`MenuID`=11761 AND `TextID`=16474) OR (`MenuID`=11755 AND `TextID`=16465) OR (`MenuID`=11760 AND `TextID`=16473) OR (`MenuID`=11752 AND `TextID`=16461) OR (`MenuID`=11751 AND `TextID`=16460) OR (`MenuID`=11749 AND `TextID`=16458) OR (`MenuID`=11750 AND `TextID`=16457) OR (`MenuID`=11759 AND `TextID`=16472) OR (`MenuID`=11748 AND `TextID`=16455) OR (`MenuID`=12723 AND `TextID` IN (17856,17857)) OR (`MenuID`=12111 AND `TextID`=17006) OR (`MenuID`=752 AND `TextID`=1302) OR (`MenuID`=11618 AND `TextID`=16219) OR (`MenuID`=6944 AND `TextID`=7778) OR (`MenuID`=11908 AND `TextID`=16717) OR (`MenuID`=11822 AND `TextID`=16574) OR (`MenuID`=11740 AND `TextID`=16435) OR (`MenuID`=11745 AND `TextID`=16442) OR (`MenuID`=11743 AND `TextID`=16440) OR (`MenuID`=11742 AND `TextID`=16439) OR (`MenuID`=11741 AND `TextID`=16438) OR (`MenuID`=11727 AND `TextID`=16418) OR (`MenuID`=349 AND `TextID`=825) OR (`MenuID`=7236 AND `TextID`=8536);

UPDATE `gameobject_template` SET `VerifiedBuild`=45745 WHERE `entry` IN (103001, 144181, 144180, 142694, 142689, 142690, 32883, 103004, 103002, 103000, 102999, 102996, 102990, 102989, 102998, 103003, 102995, 102992, 102997, 102991, 102994, 204461, 185438, 185436, 180523, 180411, 180410, 204460, 204459, 180425, 102993, 102988, 180427, 180409, 180405, 180406, 180407, 180426, 205967, 205966, 180472, 180471, 180415, 208062, 208061, 208057, 208224, 176583, 2866, 2040, 207941, 142142, 176768, 202471, 202465, 144055, 207572, 207573, 207574, 23015, 23014, 23013, 194934, 180684, 176269, 2041, 191364, 181104, 175370, 207584, 207583, 207577, 207588, 207587, 207586, 207585, 207579, 181103, 207581, 207580, 181236, 175369, 278676, 181131, 181130, 176277, 176276, 207589, 207582, 207578, 1734, 2043, 1735, 148957, 148960, 148959, 148958, 148956, 178831, 176264, 185563, 176266, 177464, 175432, 181134, 181135, 204807, 204810, 204808, 204809, 182059, 204806, 2047, 194917, 194916, 20970, 20969, 194923, 194919, 194918, 206611, 190539, 176268, 176267, 176247, 176271, 176207, 177045, 176206, 176270, 174626, 175925, 1904, 1903, 205137, 1624, 205694, 205680, 205679, 205678, 205677, 205670, 205669, 205665, 205664, 205659, 205658, 205693, 205691, 205690, 205689, 205688, 205676, 205675, 205674, 205673, 205668, 205667, 205666, 205692, 205687, 205681, 205672, 205671, 205682, 205696, 205695, 205686, 205685, 205684, 205683, 205663, 205662, 205661, 205660, 205657, 205652, 205656, 205655, 205653, 205654, 205608, 205602, 205601, 205600, 205599, 205598, 205606, 205594, 205593, 205603, 205609, 205604, 205605, 205596, 205595, 205592, 205611, 205610, 205607, 205597, 205591, 205743, 205742, 205756, 205755, 205754, 205753, 205750, 205749, 205748, 205747, 205746, 205745, 205744, 205741, 205739, 205738, 205737, 205736, 205733, 205732, 205731, 205730, 205729, 205728, 205727, 205751, 205735, 205783, 205791, 205787, 205752, 205740, 205612, 205788, 205784, 205613, 205792, 23016, 205789, 205793, 205785, 205781, 23017, 205734, 205790, 205786, 205782, 23018, 278347, 205002, 207487, 1901, 22636, 22634, 22620, 22619, 22617, 22616, 22615, 22606, 22605, 22604, 22603, 22602, 205001, 22774, 22777, 22773, 22772, 22776, 22775, 205054, 210112, 210111, 210110, 195266, 210109, 210108, 203131, 2042, 2045, 278575, 177286, 170073, 3800, 3799, 205003, 195273, 195260, 185498, 292629, 292628, 292627, 292626, 268164, 181653, 292625, 292624, 205257, 205259, 142143, 195264, 195259, 206873, 206872, 206871, 206870, 206869, 195265, 195256, 195253, 204966, 206876, 206877, 204439, 48551, 48545, 48544, 1731, 48570, 48564, 48558, 48553, 48524, 48522, 48563, 48559, 48518, 48557, 48550, 48549, 48562, 48561, 48576, 48567, 142692, 206542, 206505, 164867, 164868, 208068, 194802, 204969, 278457, 208072, 208069, 202440, 208070, 208058, 208064, 208063, 204970, 208071, 142691, 175248, 175246, 175249, 175247, 207072, 142695, 206941, 185434, 208299, 207077, 204583, 185437, 185435, 180408, 161536, 206517, 149045, 149046, 2044, 61047, 61046, 61045, 61066, 61042, 61043, 61065, 61098, 61092, 61091, 61087, 61074, 61073, 61072, 61071, 61070, 61069, 61060, 61052, 61050, 61049, 61048, 61044, 61041, 61040, 61100, 61068, 61067, 61093, 61088, 61075, 61076, 61051, 61096, 61101, 61102, 61099, 61094, 61090, 61085, 61089, 61095, 61086, 61097, 61084, 61083, 61082, 61081, 61080, 61079, 61078, 61077, 61062, 61061, 61059, 61064, 61063, 61058, 61057, 61056, 61055, 61054, 61053, 61039, 61038, 61037, 61036, 61035, 204579, 2719, 153350, 1618, 206859, 206858, 1732, 180663, 1621, 1882, 1881, 1620, 1880, 103750, 208067, 208073, 2665, 177224, 2726, 1622, 290358, 290352, 20980, 20978, 290353, 20979, 290363, 20977, 1623, 2046, 180429, 208078, 180751, 176390, 176272, 176389, 176275, 38495, 38494, 38493, 38492, 38491, 160871, 160870, 160869, 160868, 160867, 160866, 3798, 3797, 207488, 147448, 147447, 207427, 205157, 205158, 207429, 205159, 207430, 205156, 208298, 205155, 205160, 207428, 206875, 206874, 195257, 177203, 3968, 3967, 3962, 157637, 3843, 3841, 3845, 175752, 175745, 175742, 51706, 207208, 51707, 50985, 3839, 176633, 3844, 3842, 3840, 1831, 203192, 176578, 184164, 176577, 176694, 176580, 176579, 324, 92099, 1829, 206334, 202756, 195263, 164767, 164766, 164765, 164764, 164763, 164760, 164759, 180712, 164762, 164761, 204582, 206307, 37118, 202822, 205567, 180683, 202821, 180682, 133469, 133468, 133467, 133466, 206558, 204814, 205548, 175404, 207085, 207084, 205020, 205019, 209129, 205039, 205035, 205034, 176584, 176586, 177253, 177250, 177252, 177251, 177249, 177248, 177247, 177245, 177246, 177047, 176901, 177048, 177049, 181310, 142145, 205069, 1902, 180391, 175757, 148909, 148887, 148885, 2574, 148910, 59861, 148894, 21582, 148903, 148898, 148884, 148888, 148911, 148886, 148915, 148914, 148912, 148906, 148905, 148901, 148895, 148893, 59858, 148913, 148891, 148899, 148892, 148889, 148902, 59850, 59517, 74091, 148904, 148900, 144127, 56910, 59848, 175856, 175855, 175854, 61918, 59865, 59857, 59856, 59851, 56901, 59862, 204578, 60395, 59859, 59864, 207200, 175756, 175732, 60439, 59854, 59852, 56897, 60440, 60438, 21678, 59846, 207199, 2575, 59863, 56911, 59860, 187299, 144126, 59853, 56898, 59855, 91692, 59847, 59845, 59518, 56905, 56903, 20808, 1984, 207486, 216761, 216764, 180497, 143979, 204828, 175080, 1959, 18090, 3187, 175746, 170066, 170060, 170059, 170058, 170056, 170055, 112074, 112073, 112050, 112049, 112048, 112044, 112042, 22534, 22533, 175748, 170065, 170063, 170062, 170061, 170057, 112079, 112061, 112045, 112043, 22593, 22592, 22590, 170064, 22599, 22594, 22598, 22591, 22531, 22589, 22600, 22595, 22530, 22579, 142089, 22581, 22578, 22580, 278574, 175741, 170001, 22753, 22738, 22588, 22587, 22582, 22567, 22566, 22565, 22564, 22563, 175733, 22750, 22749, 22748, 22747, 22746, 22745, 22743, 22733, 22712, 22710, 22709, 22707, 175729, 22752, 22742, 22740, 22739, 22737, 22735, 22732, 22711, 22708, 20689, 269998, 349779, 269997, 242509, 177256, 177255, 177254, 204349, 1809, 178572, 157968, 203838, 204344, 2062, 1619, 204442, 204441, 204435, 289682, 204355, 204976, 204384, 204383, 204443, 179487, 206375, 202861, 202858, 202860, 74135, 260287, 259236, 259235, 259234, 204115, 92065, 202125, 153220, 125475, 227644, 92067, 92066, 203986, 153221, 36396, 147757, 147771, 147767, 147763, 147759, 147755, 147743, 147753, 147752, 147744, 147745, 147749, 147768, 147764, 147760, 147756, 147748, 147769, 147754, 147750, 147746, 147765, 147742, 147770, 147766, 147762, 147758, 147751, 147761, 147747, 203753, 203752, 203229, 148729, 148765, 148758, 148733, 148732, 148730, 148764, 148748, 148728, 239107, 239098, 239097, 239093, 239108, 239106, 239105, 239104, 239103, 239102, 239101, 239100, 239096, 239095, 239090, 239109, 239099, 239094, 239089, 148773, 148769, 148768, 148767, 148762, 148754, 148752, 148749, 148741, 239092, 239091, 148755, 147285, 147284, 147283, 147282, 146441, 148511, 37038, 37036, 152332, 152331, 152330, 37037, 37035, 37034, 37033, 37032, 37031, 37030, 37029, 37027, 21581, 3772, 37025, 239087, 239088, 164618, 152329, 152328, 152327, 152326, 152325, 37028, 37026, 148437, 148436, 202124, 202123, 202122, 153460, 153459, 203707, 225937, 233913, 233911, 94191, 204572, 204571, 204570, 204569, 204568, 204567, 204566, 204565, 1985, 1733, 180901, 111149, 206333, 174863, 160410, 160409, 207167, 206860, 192035, 207081, 207080, 203183, 192037, 192036, 192034, 202116, 148745, 148744, 148742, 148740, 148738, 148737, 148734, 148743, 148774, 148766, 148731, 204909);
UPDATE `gameobject_template` SET `ContentTuningId`=27, `VerifiedBuild`=45745 WHERE `entry`=2868; -- Crumpled Map
UPDATE `gameobject_template` SET `ContentTuningId`=425, `VerifiedBuild`=45745 WHERE `entry` IN (208137, 208143, 208121, 190108); -- Candy Bucket
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=35342, `ContentTuningId`=27, `VerifiedBuild`=45745 WHERE `entry`=206320; -- Wild Black Dragon Egg
UPDATE `gameobject_template` SET `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=205873; -- Argent Parachutes
UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=45745 WHERE `entry` IN (253165, 253167, 253164, 253166); -- Gate
UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=45745 WHERE `entry`=245358; -- Light in the Darkness
UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=45745 WHERE `entry`=251515; -- Light-Forged Vessel
UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=45745 WHERE `entry`=252396; -- Libram of Ancient Kings
UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=45745 WHERE `entry`=251673; -- Portal to Dalaran
UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=45745 WHERE `entry`=254233; -- Seal of Broken Fate
UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=45745 WHERE `entry`=250906; -- Training Troops
UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=45745 WHERE `entry`=245359; -- Striding with the Sunwalkers
UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=45745 WHERE `entry`=245526; -- Secret Door
UPDATE `gameobject_template` SET `ContentTuningId`=328, `VerifiedBuild`=45745 WHERE `entry`=204100; -- Snake Trap
UPDATE `gameobject_template` SET `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=205875; -- Crusader's Flare
UPDATE `gameobject_template` SET `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry` IN (205877, 205876); -- Argent Portal
UPDATE `gameobject_template` SET `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry` IN (205878, 205879, 205880, 205881); -- Battered Chest
UPDATE `gameobject_template` SET `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=177789; -- Augustus' Receipt Book
UPDATE `gameobject_template` SET `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=205558; -- Flesh Giant Foot
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=34719, `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=205559; -- Rotberry Bush
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=34720, `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=205560; -- Disembodied Arm
UPDATE `gameobject_template` SET `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=177677; -- Shallow Grave
UPDATE `gameobject_template` SET `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=182058; -- Scourge Meat Wagon
UPDATE `gameobject_template` SET `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=205537; -- Open Prayer Book
UPDATE `gameobject_template` SET `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=177264; -- Symbol of Lost Honor
UPDATE `gameobject_template` SET `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=177527; -- Relic Bundle Aura
UPDATE `gameobject_template` SET `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=177526; -- Relic Bundle
UPDATE `gameobject_template` SET `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=177544; -- Joseph's Chest
UPDATE `gameobject_template` SET `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=176143; -- Pamela's Doll's Right Side
UPDATE `gameobject_template` SET `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=176142; -- Pamela's Doll's Left Side
UPDATE `gameobject_template` SET `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=176116; -- Pamela's Doll's Head
UPDATE `gameobject_template` SET `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=176865; -- Sword of Marduk Trap
UPDATE `gameobject_template` SET `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=176209; -- Shattered Sword of Marduk
UPDATE `gameobject_template` SET `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=176591; -- Horgus' Skull Trap
UPDATE `gameobject_template` SET `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=176208; -- Horgus' Skull
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=34661, `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=205423; -- Banshee's Bells
UPDATE `gameobject_template` SET `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=177667; -- Torn Scroll
UPDATE `gameobject_template` SET `ContentTuningId`=25, `VerifiedBuild`=45745 WHERE `entry`=205053; -- Rotten Apple
UPDATE `gameobject_template` SET `ContentTuningId`=25, `VerifiedBuild`=45745 WHERE `entry`=205052; -- Unhealthy-Looking Pumpkin
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=33831, `ContentTuningId`=25, `VerifiedBuild`=45745 WHERE `entry`=205246; -- Brownfeather Quill
UPDATE `gameobject_template` SET `ContentTuningId`=25, `VerifiedBuild`=45745 WHERE `entry`=205258; -- Broken Weapons Crate
UPDATE `gameobject_template` SET `ContentTuningId`=25, `VerifiedBuild`=45745 WHERE `entry`=176145; -- Joseph Redpath's Monument
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=14285, `ContentTuningId`=25, `VerifiedBuild`=45745 WHERE `entry`=177241; -- Araj's Phylactery
UPDATE `gameobject_template` SET `ContentTuningId`=217, `VerifiedBuild`=45745 WHERE `entry`=178833; -- Meeting Stone
UPDATE `gameobject_template` SET `ContentTuningId`=27, `VerifiedBuild`=45745 WHERE `entry`=206504; -- Rhea's Final Note
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39338, `ContentTuningId`=26, `VerifiedBuild`=45745 WHERE `entry`=207476; -- Silverbound Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=27, `VerifiedBuild`=45745 WHERE `entry`=206550; -- The Sun
UPDATE `gameobject_template` SET `Data8`=0, `Data10`=1, `VerifiedBuild`=45745 WHERE `entry`=206108; -- Gol' Durned Rock Heap
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=35466, `ContentTuningId`=27, `VerifiedBuild`=45745 WHERE `entry`=206498; -- Dustbelcher Meat
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=35470, `ContentTuningId`=27, `VerifiedBuild`=45745 WHERE `entry`=206499; -- Dustbelcher Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=35466, `ContentTuningId`=27, `VerifiedBuild`=45745 WHERE `entry`=206420; -- Dustbelcher Meat
UPDATE `gameobject_template` SET `ContentTuningId`=27, `VerifiedBuild`=45745 WHERE `entry`=206374; -- Trove of the Watchers
UPDATE `gameobject_template` SET `ContentTuningId`=27, `VerifiedBuild`=45745 WHERE `entry`=206388; -- Angor's Coffer
UPDATE `gameobject_template` SET `ContentTuningId`=27, `VerifiedBuild`=45745 WHERE `entry`=2875; -- Battered Dwarven Skeleton
UPDATE `gameobject_template` SET `ContentTuningId`=27, `VerifiedBuild`=45745 WHERE `entry`=206336; -- Marble Slab
UPDATE `gameobject_template` SET `ContentTuningId`=27, `VerifiedBuild`=45745 WHERE `entry`=206335; -- Stone Slab
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=35342, `ContentTuningId`=27, `VerifiedBuild`=45745 WHERE `entry`=206320; -- Wild Black Dragon Egg
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=35343, `ContentTuningId`=27, `VerifiedBuild`=45745 WHERE `entry`=206321; -- Nyxondra's Egg
UPDATE `gameobject_template` SET `ContentTuningId`=9, `VerifiedBuild`=45745 WHERE `entry`=194391; -- Stolen Explorers' League Document
UPDATE `gameobject_template` SET `ContentTuningId`=15, `VerifiedBuild`=45745 WHERE `entry`=2084; -- Musquash Root
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=29569, `ContentTuningId`=15, `VerifiedBuild`=45745 WHERE `entry`=203179; -- Sediment Deposit
UPDATE `gameobject_template` SET `ContentTuningId`=416, `VerifiedBuild`=45745 WHERE `entry`=202879; -- Ritual Drum
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=17851, `ContentTuningId`=664, `VerifiedBuild`=45745 WHERE `entry`=181053; -- Basket of Bloodkelp
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=9799, `ContentTuningId`=20, `VerifiedBuild`=45745 WHERE `entry`=153239; -- Wildkin Feather
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30067, `ContentTuningId`=20, `VerifiedBuild`=45745 WHERE `entry`=203989; -- Ooze-coated Supply Crate
UPDATE `gameobject_template` SET `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=205485; -- Mereldar Plague Cauldron
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=16467, `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=179498; -- Scarlet Footlocker
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=34720, `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=205560; -- Disembodied Arm
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=34719, `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=205559; -- Rotberry Bush
UPDATE `gameobject_template` SET `Data0`=2850, `Data6`=30, `Data12`=683, `ContentTuningId`=683, `VerifiedBuild`=45745 WHERE `entry`=253069; -- Blacker Lotus
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=16467, `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=179498; -- Scarlet Footlocker
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=34661, `ContentTuningId`=35, `VerifiedBuild`=45745 WHERE `entry`=205423; -- Banshee's Bells
UPDATE `gameobject_template` SET `ContentTuningId`=25, `VerifiedBuild`=45745 WHERE `entry`=205154; -- Child's Painting
UPDATE `gameobject_template` SET `ContentTuningId`=25, `VerifiedBuild`=45745 WHERE `entry`=205153; -- Prayer Book
UPDATE `gameobject_template` SET `ContentTuningId`=25, `VerifiedBuild`=45745 WHERE `entry`=176392; -- Scourge Cauldron
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=33831, `ContentTuningId`=25, `VerifiedBuild`=45745 WHERE `entry`=205246; -- Brownfeather Quill
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=14285, `ContentTuningId`=25, `VerifiedBuild`=45745 WHERE `entry`=177241; -- Araj's Phylactery
UPDATE `gameobject_template` SET `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=32569; -- Galen's Strongbox
UPDATE `gameobject_template` SET `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=28024; -- Caravan Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=3601, `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=22550; -- Draenethyst Crystals
UPDATE `gameobject_template` SET `ContentTuningId`=683, `VerifiedBuild`=45745 WHERE `entry`=176587; -- Sorrowmoss
UPDATE `gameobject_template` SET `ContentTuningId`=216, `VerifiedBuild`=45745 WHERE `entry`=179554; -- Meeting Stone
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=3598, `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=30854; -- Atal'ai Artifact
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=3598, `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=30855; -- Atal'ai Artifact
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=3626, `ContentTuningId`=216, `VerifiedBuild`=45745 WHERE `entry`=37099; -- Atal'ai Tablet
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=3598, `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=30856; -- Atal'ai Artifact
UPDATE `gameobject_template` SET `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=205828; -- Stack of Questionable Publications
UPDATE `gameobject_template` SET `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=205827; -- Extra-Pure Blasting Powder
UPDATE `gameobject_template` SET `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=205826; -- Thousand-Thread-Count Fuse
UPDATE `gameobject_template` SET `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=206679; -- Landward Cannon
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=3544, `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=24798; -- Sundried Driftwood
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=3626, `ContentTuningId`=216, `VerifiedBuild`=45745 WHERE `entry`=37099; -- Atal'ai Tablet
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=3598, `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=30856; -- Atal'ai Artifact
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=3598, `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=30855; -- Atal'ai Artifact
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=3598, `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=30854; -- Atal'ai Artifact
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=34715, `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=205545; -- Stray Land Mine
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=3601, `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=22550; -- Draenethyst Crystals
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=35471, `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=206503; -- Prayerbloom
UPDATE `gameobject_template` SET `ContentTuningId`=63, `VerifiedBuild`=45745 WHERE `entry`=225951; -- Iron Horde Weapon Rack
UPDATE `gameobject_template` SET `ContentTuningId`=34, `VerifiedBuild`=45745 WHERE `entry`=203225; -- Horde Plans
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=29593, `ContentTuningId`=34, `VerifiedBuild`=45745 WHERE `entry`=203224; -- Charred Granite Outcropping
UPDATE `gameobject_template` SET `ContentTuningId`=34, `VerifiedBuild`=45745 WHERE `entry`=203226; -- Alliance Plans
UPDATE `gameobject_template` SET `ContentTuningId`=34, `VerifiedBuild`=45745 WHERE `entry`=203289; -- Azsh'ir Idol
UPDATE `gameobject_template` SET `ContentTuningId`=24, `VerifiedBuild`=45745 WHERE `entry`=178204; -- Warsong Axe Shipment
UPDATE `gameobject_template` SET `ContentTuningId`=18, `VerifiedBuild`=45745 WHERE `entry`=2083; -- Bloodsail Correspondence
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30880, `ContentTuningId`=24, `VerifiedBuild`=45745 WHERE `entry`=204336; -- Naga Icon
UPDATE `gameobject_template` SET `ContentTuningId`=13, `VerifiedBuild`=45745 WHERE `entry`=204777; -- Mound of Loose Dirt
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30883, `ContentTuningId`=10, `VerifiedBuild`=45745 WHERE `entry`=204347; -- Gnoll Strategy Guide
UPDATE `gameobject_template` SET `ContentTuningId`=10, `VerifiedBuild`=45745 WHERE `entry`=32; -- Sunken Chest
UPDATE `gameobject_template` SET `ContentTuningId`=10, `VerifiedBuild`=45745 WHERE `entry` IN (204446, 204444); -- Blackrock Explosive Device
UPDATE `gameobject_template` SET `ContentTuningId`=10, `VerifiedBuild`=45745 WHERE `entry`=204350; -- Gnomecorder
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30914, `ContentTuningId`=10, `VerifiedBuild`=45745 WHERE `entry`=204389; -- Blackrock Key Pouch
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30930, `ContentTuningId`=10, `VerifiedBuild`=45745 WHERE `entry`=204424; -- Pile of Leaves
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30931, `ContentTuningId`=10, `VerifiedBuild`=45745 WHERE `entry`=204425; -- Fox Poop
UPDATE `gameobject_template` SET `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=2553; -- A Soggy Scroll
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=35471, `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=206503; -- Prayerbloom
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=3601, `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=22550; -- Draenethyst Crystals
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=35359, `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=206391; -- Stonard Supplies
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=3598, `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=30855; -- Atal'ai Artifact
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=3598, `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=30854; -- Atal'ai Artifact
UPDATE `gameobject_template` SET `ContentTuningId`=34, `VerifiedBuild`=45745 WHERE `entry`=153359; -- Rune of Return
UPDATE `gameobject_template` SET `ContentTuningId`=34, `VerifiedBuild`=45745 WHERE `entry`=153203; -- Rune of the Defiler
UPDATE `gameobject_template` SET `ContentTuningId`=34, `VerifiedBuild`=45745 WHERE `entry` IN (203204, 203205, 203206); -- Dreadmaul Cache
UPDATE `gameobject_template` SET `ContentTuningId`=34, `VerifiedBuild`=45745 WHERE `entry`=203196; -- Blood Altar
UPDATE `gameobject_template` SET `ContentTuningId`=34, `VerifiedBuild`=45745 WHERE `entry` IN (203181, 203180); -- Bloodstone Teleporter
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=29593, `ContentTuningId`=34, `VerifiedBuild`=45745 WHERE `entry`=203224; -- Charred Granite Outcropping
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=29600, `ContentTuningId`=34, `VerifiedBuild`=45745 WHERE `entry`=203230; -- Head of Grol
UPDATE `gameobject_template` SET `ContentTuningId`=1221, `VerifiedBuild`=45745 WHERE `entry`=232625; -- Cooking Pot
UPDATE `gameobject_template` SET `ContentTuningId`=262, `VerifiedBuild`=45745 WHERE `entry`=208420; -- Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=24, `VerifiedBuild`=45745 WHERE `entry`=204587; -- Narkk's Handbombs
UPDATE `gameobject_template` SET `ContentTuningId`=24, `VerifiedBuild`=45745 WHERE `entry`=204586; -- Bloodsail Rope
UPDATE `gameobject_template` SET `ContentTuningId`=24, `VerifiedBuild`=45745 WHERE `entry`=204585; -- Blackwater Rope
UPDATE `gameobject_template` SET `ContentTuningId`=18, `VerifiedBuild`=45745 WHERE `entry`=2087; -- Bloodsail Orders
UPDATE `gameobject_template` SET `ContentTuningId`=24, `VerifiedBuild`=45745 WHERE `entry`=204406; -- Half-Buried Bottle
UPDATE `gameobject_template` SET `ContentTuningId`=24, `VerifiedBuild`=45745 WHERE `entry`=2289; -- Ruined Lifeboat
UPDATE `gameobject_template` SET `ContentTuningId`=24, `VerifiedBuild`=45745 WHERE `entry`=204454; -- Grog Barrel
UPDATE `gameobject_template` SET `ContentTuningId`=24, `VerifiedBuild`=45745 WHERE `entry`=204450; -- Captain Stillwater's Charts
UPDATE `gameobject_template` SET `ContentTuningId`=24, `VerifiedBuild`=45745 WHERE `entry`=204455; -- Gunpowder Barrel
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30934, `ContentTuningId`=24, `VerifiedBuild`=45745 WHERE `entry`=204433; -- Bloodsail Cannonball
UPDATE `gameobject_template` SET `ContentTuningId`=24, `VerifiedBuild`=45745 WHERE `entry`=204456; -- Cannonball Crate
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30933, `ContentTuningId`=24, `VerifiedBuild`=45745 WHERE `entry`=204432; -- Lime Crate
UPDATE `gameobject_template` SET `ContentTuningId`=24, `VerifiedBuild`=45745 WHERE `entry`=204422; -- Swabbie's Mop
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=3544, `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=24798; -- Sundried Driftwood
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=3598, `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=30855; -- Atal'ai Artifact
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=3598, `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=30856; -- Atal'ai Artifact
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=3626, `ContentTuningId`=216, `VerifiedBuild`=45745 WHERE `entry`=37099; -- Atal'ai Tablet
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=3598, `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=30854; -- Atal'ai Artifact
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=35471, `ContentTuningId`=31, `VerifiedBuild`=45745 WHERE `entry`=206503; -- Prayerbloom
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=29593, `ContentTuningId`=34, `VerifiedBuild`=45745 WHERE `entry`=203224; -- Charred Granite Outcropping
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=29600, `ContentTuningId`=34, `VerifiedBuild`=45745 WHERE `entry`=203230; -- Head of Grol
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30934, `ContentTuningId`=24, `VerifiedBuild`=45745 WHERE `entry`=204433; -- Bloodsail Cannonball
UPDATE `gameobject_template` SET `ContentTuningId`=18, `VerifiedBuild`=45745 WHERE `entry`=2086; -- Bloodsail Charts
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30933, `ContentTuningId`=24, `VerifiedBuild`=45745 WHERE `entry`=204432; -- Lime Crate

DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=204587 AND `Idx`=0);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(204587, 0, 59524, 45745); -- Narkk's Handbombs

UPDATE `gameobject_questitem` SET `VerifiedBuild`=45745 WHERE (`Idx`=0 AND `GameObjectEntry` IN (206320,205878,205879,205880,205881,177789,205558,205559,205560,177464,205537,177264,176209,176208,176207,176206,205423,205137,205246,176145,177241,206498,206499,206420,206388,206321,2084,203179,181053,153239,203989,205154,205153,28024,22550,30854,30855,37099,30856,205828,205827,205826,24798,205545,206503,203224,178204,204336,204347,32,204350,204389,204424,204425,206391,203204,203205,203206,203229,2087,204433,204432,2086)) OR (`Idx`=1 AND `GameObjectEntry` IN (177241,2087));

UPDATE `page_text` SET `VerifiedBuild`=45745 WHERE `ID` IN (2415, 2414, 2413, 2251, 72, 71, 70, 69, 68, 67, 66, 65, 64, 3709, 292, 3630, 1975, 1974, 1973, 1972, 1971, 1970, 1969, 1968, 1967, 1966, 1965, 1964, 1963, 1962, 1961, 1960, 1959, 636, 635, 634, 633, 632, 631, 630, 629, 628, 627, 3655, 3654, 3653);
