ALTER TABLE `gameobject_addon`
ADD COLUMN `parent_rotation0` FLOAT NOT NULL DEFAULT '0' AFTER `guid`,
ADD COLUMN `parent_rotation1` FLOAT NOT NULL DEFAULT '0' AFTER `parent_rotation0`,
ADD COLUMN `parent_rotation2` FLOAT NOT NULL DEFAULT '0' AFTER `parent_rotation1`,
ADD COLUMN `parent_rotation3` FLOAT NOT NULL DEFAULT '1' AFTER `parent_rotation2`;

-- Old parent_rotation fields now go to addon table
UPDATE `gameobject_addon` ga INNER JOIN `gameobject` g ON ga.`guid` = g.`guid` SET ga.`parent_rotation0` = g.`rotation0`, ga.`parent_rotation1` = g.`rotation1`, ga.`parent_rotation2` = g.`rotation2`, ga.`parent_rotation3` = g.`rotation3`;
INSERT IGNORE INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`) SELECT `guid`, `rotation0`, `rotation1`, `rotation2`, `rotation3` FROM `gameobject` WHERE `rotation0` != 0 OR `rotation1` != 0 OR `rotation2` != 0 OR `rotation3` != 1;

-- Retain compatibility with old UpdateRotationFields function
UPDATE `gameobject_addon` ga INNER JOIN `gameobject` g ON ga.`guid` = g.`guid` SET ga.`parent_rotation2`= IF(g.`rotation2` != 0 OR g.`rotation3` != 0, g.`rotation2`, SIN(g.`orientation` / 2)), ga.`parent_rotation3` = IF(g.`rotation2` != 0 OR g.`rotation3` != 0, g.`rotation3`, COS(g.`orientation` / 2));
UPDATE `gameobject` SET `rotation0`=0, `rotation1`=0, `rotation2`=SIN(`orientation`/2), `rotation3`=COS(`orientation`/2);

-- After mass import into gameobject_addon, some rows won't be unit length, so unitize them to prevent errors when starting server
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=1341;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=1343;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=1890;
UPDATE `gameobject_addon` SET `parent_rotation0`=0.6762096538109234, `parent_rotation1`=-0.20673818018978996, `parent_rotation2`=0.7071066602321923, `parent_rotation3`=0 WHERE `guid`=4718;
UPDATE `gameobject_addon` SET `parent_rotation0`=0.6762096538109234, `parent_rotation1`=-0.20673818018978996, `parent_rotation2`=0.7071066602321923, `parent_rotation3`=0 WHERE `guid`=4958;
UPDATE `gameobject_addon` SET `parent_rotation0`=0.6762096538109234, `parent_rotation1`=-0.20673818018978996, `parent_rotation2`=0.7071066602321923, `parent_rotation3`=0 WHERE `guid`=5136;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=5306;
UPDATE `gameobject_addon` SET `parent_rotation0`=-0.0030851075994373996, `parent_rotation1`=0.7070998757516332, `parent_rotation2`=0.7071069564239378, `parent_rotation3`=0 WHERE `guid`=5496;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=10528;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0.6957902409824018, `parent_rotation2`=0.6705396463625237, `parent_rotation3`=-0.25739565499377165 WHERE `guid`=12007;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=12098;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=12597;
UPDATE `gameobject_addon` SET `parent_rotation0`=0.5416755978208309, `parent_rotation1`=-0.4545190336806428, `parent_rotation2`=-0.45451857006530766, `parent_rotation3`=0.5416759771424687 WHERE `guid`=14036;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7963742763149461, `parent_rotation3`=-0.6048041104554813 WHERE `guid`=16736;
UPDATE `gameobject_addon` SET `parent_rotation0`=0.6678291213863456, `parent_rotation1`=0.2329403984683526, `parent_rotation2`=0.6674002564812922, `parent_rotation3`=-0.23306637045797093 WHERE `guid`=20458;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=-0.8164965561474501, `parent_rotation2`=-0.2508269266233929, `parent_rotation3`=0.5200184868637047 WHERE `guid`=20459;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=21636;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=21753;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=22049;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=22050;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=22105;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=22108;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=22117;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=22133;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=22135;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=22138;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=22150;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=22173;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=22185;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=22215;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=22216;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=22261;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=22270;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=22285;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=22304;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=22681;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=24650;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=24651;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=24731;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=0.7071067811865475, `parent_rotation3`=0.7071067811865475 WHERE `guid`=24732;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0.7071067811865475, `parent_rotation2`=-0.7071067811865475, `parent_rotation3`=0 WHERE `guid`=46424;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0.7071067811865475, `parent_rotation2`=-0.7071067811865475, `parent_rotation3`=0 WHERE `guid`=46425;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0.7071067811865475, `parent_rotation2`=-0.7071067811865475, `parent_rotation3`=0 WHERE `guid`=46429;
UPDATE `gameobject_addon` SET `parent_rotation0`=-0.5475785386184279, `parent_rotation1`=0.44738996187113267, `parent_rotation2`=0.7071067571883707, `parent_rotation3`=0 WHERE `guid`=67868;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0.26071837713139784, `parent_rotation2`=0.4995184262775704, `parent_rotation3`=0.8261399818645443 WHERE `guid`=99796;
UPDATE `gameobject_addon` SET `parent_rotation0`=0, `parent_rotation1`=0, `parent_rotation2`=-0.7305848035703219, `parent_rotation3`=0.6828219715212115 WHERE `guid`=151892;

-- Import special PARENT_ROTATION values for some transports, data taken from UDB
DELETE FROM `gameobject_addon` WHERE `guid` IN (6945,6946,9290,9411,9450,14139,16760,16761,16871,16874,16875,16876,16877,18298,18435,18802,18803,18804,18805,18806,18807,20505,20639,20640,24055,24074,24075,25138,34057,35693,35694,44890,44891,44892,44893,44901,44909,44954,44962,44976,48263,55230,56744,56937,56954,56961,57132,57133,57140,57141,57799,57992,57993,57994,57995,57996,58299,58304,58305,58306,58310,58782,58824,58935,59160,59328,59336,59343,59350,59386,59762,59763,59764,59765,59766,59779,59780,59781,59782,59783,60421,60463,61053,65435,65436,65438,65439,65520,65588,66717,67873,67874,67875,67876);
INSERT INTO `gameobject_addon`(`guid`,`parent_rotation0`,`parent_rotation1`,`parent_rotation2`,`parent_rotation3`) VALUES
(6945,0,0,1,-0.0000000437114),
(6946,0,0,1,-0.0000000437114),
(9290,0,0,0.95502,0.296542),
(9411,0,0,0.678801,0.734323),
(9450,0,0,0.678801,0.734323),
(14139,0,0,1,-0.0000000437114),
(16760,0,0,-0.378575,0.92557),
(16761,0,0,-0.378575,0.92557),
(16871,0,0,0.694658,0.71934),
(16874,0,0,0.989651,0.143493),
(16875,0,0,-0.426569,0.904455),
(16876,0,0,0.989651,0.143493),
(16877,0,0,-0.426569,0.904455),
(18298,0,0,0.612217,0.79069),
(18435,0,0,0.612217,0.79069),
(18802,0,0,1,-0.0000000437114),
(18803,0,0,1,-0.0000000437114),
(18804,0,0,1,-0.0000000437114),
(18805,0,0,1,-0.0000000437114),
(18806,0,0,1,-0.0000000437114),
(18807,0,0,1,-0.0000000437114),
(20505,0,0,-0.694658,0.71934),
(20639,0,0,0.612217,0.79069),
(20640,0,0,0.612217,0.79069),
(24055,0,0,-0.526214,0.850352),
(24074,0,0,-0.526214,0.850352),
(24075,0,0,-0.526214,0.850352),
(25138,0,0,0.45399,0.891007),
(34057,0,0,0.000000325841,1),
(35693,0,0,0.989651,0.143493),
(35694,0,0,0.989651,0.143493),
(44890,0,0,-0.0043634,0.99999),
(44891,0,0,-0.0043634,0.99999),
(44892,0,0,-0.0043634,0.99999),
(44893,0,0,-0.0043634,0.99999),
(44901,0,0,-0.0043634,0.99999),
(44909,0,0,-0.0043634,0.99999),
(44954,0,0,-0.0043634,0.99999),
(44962,0,0,-0.0043634,0.99999),
(44976,0,0,-0.0043634,0.99999),
(48263,0,0,-0.522498,0.85264),
(55230,0,0,0.999048,0.0436193),
(56744,0,0,0.951057,0.309017),
(56937,0,0,0.951057,0.309017),
(56954,0,0,0.951057,0.309017),
(56961,0,0,0.999048,0.0436193),
(57132,-0.00276125,-0.00551835,-0.370553,0.928791),
(57133,0.00544418,-0.00290476,0.918772,0.394739),
(57140,-0.00276125,-0.00551835,-0.370553,0.928791),
(57141,0.00544418,-0.00290476,0.918772,0.394739),
(57799,0,0,0.999048,0.0436193),
(57992,0,0,-0.370557,0.92881),
(57993,0,0,-0.760406,0.649448),
(57994,0,0,0.915312,0.402747),
(57995,0,0,-0.748956,0.66262),
(57996,0,0,0.995805,0.0915015),
(58299,0,0,0.999048,0.0436193),
(58304,0,0,-0.263031,0.964787),
(58305,0,0,0.522499,0.85264),
(58306,0,0,0.996917,-0.0784592),
(58310,0,0,0.333807,0.942641),
(58782,0,0,0.333807,0.942641),
(58824,0,0,0.333807,0.942641),
(58935,0,0,0.932008,-0.362438),
(59160,0,0,0.99999,0.00436324),
(59328,0,0,0.99999,-0.00436333),
(59336,0,0,0.99999,-0.00436333),
(59343,0,0,0.99999,-0.00436333),
(59350,0,0,0.99999,-0.00436333),
(59386,0,0,0.99999,-0.00436333),
(59762,0,0,-0.370557,0.92881),
(59763,0,0,-0.760406,0.649448),
(59764,0,0,0.915312,0.402747),
(59765,0,0,-0.748956,0.66262),
(59766,0,0,0.995805,0.0915015),
(59779,0,0,-0.370557,0.92881),
(59780,0,0,-0.760406,0.649448),
(59781,0,0,0.915312,0.402747),
(59782,0,0,-0.748956,0.66262),
(59783,0,0,0.995805,0.0915015),
(60421,0,0,0.99999,0.00436324),
(60463,0,0,0.999048,0.0436193),
(61053,0,0,0.999048,0.0436193),
(65435,0,0,0.915312,0.402747),
(65436,0,0,0.99999,0.00436324),
(65438,0,0,0.915312,0.402747),
(65439,0,0,0.915312,0.402747),
(65520,0,0,0.99999,0.00436324),
(65588,0,0,1,-0.0000000437114),
(66717,0,0,0.999657,0.0261769),
(67873,-0.00276125,-0.00551835,-0.370553,0.928791),
(67874,0.00544418,-0.00290476,0.918772,0.394739),
(67875,-0.00276125,-0.00551835,-0.370553,0.928791),
(67876,0.00544418,-0.00290476,0.918772,0.394739);

-- Import from mangos UDB rows with explicit rotation in X or Y set
UPDATE `gameobject` SET `rotation0`=0.00661993, `rotation1`=-0.0256987, `rotation2`=-0.913849, `rotation3`=0.405186 WHERE `guid`=31;
UPDATE `gameobject` SET `rotation0`=0.0217795, `rotation1`=0.0566788, `rotation2`=-0.998154, `rotation3`=0.00154408 WHERE `guid`=39;
UPDATE `gameobject` SET `rotation0`=0, `rotation1`=-1, `rotation2`=0, `rotation3`=0 WHERE `guid`=256;
UPDATE `gameobject` SET `rotation0`=0.0647478, `rotation1`=0.0103159, `rotation2`=-0.996012, `rotation3`=0.0605139 WHERE `guid`=422;
UPDATE `gameobject` SET `rotation0`=-0.0371165, `rotation1`=-0.0287819, `rotation2`=-0.959991, `rotation3`=0.276066 WHERE `guid`=425;
UPDATE `gameobject` SET `rotation0`=0.0527701, `rotation1`=0.0327311, `rotation2`=-0.980893, `rotation3`=0.184371 WHERE `guid`=428;
UPDATE `gameobject` SET `rotation0`=-0.0392456, `rotation1`=0.0261564, `rotation2`=0.998886, `rotation3`=0.00146484 WHERE `guid`=1643;
UPDATE `gameobject` SET `rotation0`=-0.0232878, `rotation1`=-0.0147963, `rotation2`=-0.969871, `rotation3`=0.242053 WHERE `guid`=1692;
UPDATE `gameobject` SET `rotation0`=-0.0346627, `rotation1`=-0.0136871, `rotation2`=-0.999145, `rotation3`=0.0179256 WHERE `guid`=1733;
UPDATE `gameobject` SET `rotation0`=0.681389, `rotation1`=-0.188966, `rotation2`=0.68139, `rotation3`=0.188967 WHERE `guid`=5141;
UPDATE `gameobject` SET `rotation0`=-0.316432, `rotation1`=-0.0235138, `rotation2`=-0.945716, `rotation3`=0.0702803 WHERE `guid`=5193;
UPDATE `gameobject` SET `rotation0`=0.309975, `rotation1`=-0.635543, `rotation2`=0.309974, `rotation3`=0.635543 WHERE `guid`=5205;
UPDATE `gameobject` SET `rotation0`=0.00517035, `rotation1`=-0.0122805, `rotation2`=-0.933433, `rotation3`=0.358505 WHERE `guid`=5352;
UPDATE `gameobject` SET `rotation0`=0.61994, `rotation1`=-0.340111, `rotation2`=0.619939, `rotation3`=0.34011 WHERE `guid`=5382;
UPDATE `gameobject` SET `rotation0`=0.607692, `rotation1`=-0.361538, `rotation2`=0.607693, `rotation3`=0.361539 WHERE `guid`=5398;
UPDATE `gameobject` SET `rotation0`=0.607692, `rotation1`=-0.361538, `rotation2`=0.607693, `rotation3`=0.361539 WHERE `guid`=5405;
UPDATE `gameobject` SET `rotation0`=0.147016, `rotation1`=-0.691655, `rotation2`=0.147016, `rotation3`=0.691655 WHERE `guid`=5425;
UPDATE `gameobject` SET `rotation0`=0.0828447, `rotation1`=0.0300417, `rotation2`=0.870979, `rotation3`=0.483352 WHERE `guid`=5514;
UPDATE `gameobject` SET `rotation0`=0.241845, `rotation1`=0.664462, `rotation2`=0.664463, `rotation3`=0.241847 WHERE `guid`=6166;
UPDATE `gameobject` SET `rotation0`=-0.120005, `rotation1`=0.0474339, `rotation2`=-0.901711, `rotation3`=0.412634 WHERE `guid`=6771;
UPDATE `gameobject` SET `rotation0`=-0.0218129, `rotation1`=-0.0130854, `rotation2`=-0.999676, `rotation3`=0.00117086 WHERE `guid`=6896;
UPDATE `gameobject` SET `rotation0`=-0.00554562, `rotation1`=0.00270462, `rotation2`=-0.945506, `rotation3`=0.325546 WHERE `guid`=6943;
UPDATE `gameobject` SET `rotation0`=0.00311899, `rotation1`=0.0220261, `rotation2`=-0.998138, `rotation3`=0.0567872 WHERE `guid`=6997;
UPDATE `gameobject` SET `rotation0`=-0.000787735, `rotation1`=-0.0194941, `rotation2`=-0.911526, `rotation3`=0.41078 WHERE `guid`=7016;
UPDATE `gameobject` SET `rotation0`=0.0240598, `rotation1`=-0.0310163, `rotation2`=-0.946024, `rotation3`=0.321711 WHERE `guid`=7033;
UPDATE `gameobject` SET `rotation0`=-0.517355, `rotation1`=-0.209099, `rotation2`=-0.745465, `rotation3`=0.364559 WHERE `guid`=11584;
UPDATE `gameobject` SET `rotation0`=0, `rotation1`=0.173648, `rotation2`=-0.98106, `rotation3`=0.0858351 WHERE `guid`=12045;
UPDATE `gameobject` SET `rotation0`=-0.0702071, `rotation1`=0.0758209, `rotation2`=-0.969868, `rotation3`=0.220633 WHERE `guid`=12126;
UPDATE `gameobject` SET `rotation0`=0.0112896, `rotation1`=-0.0421324, `rotation2`=-0.965006, `rotation3`=0.258575 WHERE `guid`=12153;
UPDATE `gameobject` SET `rotation0`=-0.13007, `rotation1`=0.0567751, `rotation2`=0.989808, `rotation3`=0.0117644 WHERE `guid`=13380;
UPDATE `gameobject` SET `rotation0`=-0.108055, `rotation1`=-0.0132675, `rotation2`=-0.98861, `rotation3`=0.103913 WHERE `guid`=14140;
UPDATE `gameobject` SET `rotation0`=0.045383, `rotation1`=0.0708761, `rotation2`=-0.883594, `rotation3`=0.460629 WHERE `guid`=15274;
UPDATE `gameobject` SET `rotation0`=0.045383, `rotation1`=0.0708761, `rotation2`=-0.883594, `rotation3`=0.460629 WHERE `guid`=15366;
UPDATE `gameobject` SET `rotation0`=0.00190258, `rotation1`=-0.0435772, `rotation2`=-0.998096, `rotation3`=0.0435988 WHERE `guid`=15561;
UPDATE `gameobject` SET `rotation0`=0.185185, `rotation1`=-0.389885, `rotation2`=-0.900506, `rotation3`=0.0527745 WHERE `guid`=17928;
UPDATE `gameobject` SET `rotation0`=0.171708, `rotation1`=-0.056263, `rotation2`=0.382931, `rotation3`=0.905933 WHERE `guid`=21760;
UPDATE `gameobject` SET `rotation0`=-0.0308428, `rotation1`=-0.000134468, `rotation2`=-0.704017, `rotation3`=0.709513 WHERE `guid`=21768;
UPDATE `gameobject` SET `rotation0`=-0.0229378, `rotation1`=0.0318613, `rotation2`=-0.810947, `rotation3`=0.583801 WHERE `guid`=21774;
UPDATE `gameobject` SET `rotation0`=-0.0175047, `rotation1`=0.00414562, `rotation2`=0.0124769, `rotation3`=0.99976 WHERE `guid`=21775;
UPDATE `gameobject` SET `rotation0`=0.0281639, `rotation1`=-0.00794315, `rotation2`=0.739404, `rotation3`=0.672626 WHERE `guid`=21777;
UPDATE `gameobject` SET `rotation0`=0.0193486, `rotation1`=0.00251198, `rotation2`=0.558642, `rotation3`=0.829179 WHERE `guid`=21778;
UPDATE `gameobject` SET `rotation0`=-0.00526476, `rotation1`=-0.0032177, `rotation2`=0.972073, `rotation3`=0.234599 WHERE `guid`=22676;
UPDATE `gameobject` SET `rotation0`=-0.00144768, `rotation1`=-0.00599766, `rotation2`=0.521473, `rotation3`=0.853246 WHERE `guid`=22681;
UPDATE `gameobject` SET `rotation0`=-0.00425291, `rotation1`=-0.00447083, `rotation2`=0.878231, `rotation3`=0.478197 WHERE `guid`=22682;
UPDATE `gameobject` SET `rotation0`=0.0059185, `rotation1`=0.00174522, `rotation2`=-0.999668, `rotation3`=0.025011 WHERE `guid`=22683;
UPDATE `gameobject` SET `rotation0`=0.0133157, `rotation1`=-0.0566292, `rotation2`=-0.9983, `rotation3`=0.00370258 WHERE `guid`=23388;
UPDATE `gameobject` SET `rotation0`=-0.0218129, `rotation1`=0.0130854, `rotation2`=0.999676, `rotation3`=0.00117086 WHERE `guid`=24026;
UPDATE `gameobject` SET `rotation0`=-0.0425816, `rotation1`=-0.0586815, `rotation2`=0.995896, `rotation3`=0.0541643 WHERE `guid`=24222;
UPDATE `gameobject` SET `rotation0`=-0.0627699, `rotation1`=0.0825901, `rotation2`=-0.992224, `rotation3`=0.0687813 WHERE `guid`=24223;
UPDATE `gameobject` SET `rotation0`=0.00614643, `rotation1`=-0.000543594, `rotation2`=-0.921, `rotation3`=0.389515 WHERE `guid`=24716;
UPDATE `gameobject` SET `rotation0`=0.0057869, `rotation1`=-0.002141, `rotation2`=-0.786171, `rotation3`=0.617978 WHERE `guid`=24718;
UPDATE `gameobject` SET `rotation0`=-0.00567293, `rotation1`=-0.0024271, `rotation2`=0.995696, `rotation3`=0.0924729 WHERE `guid`=24719;
UPDATE `gameobject` SET `rotation0`=0.00611162, `rotation1`=0.000849724, `rotation2`=-0.98495, `rotation3`=0.172729 WHERE `guid`=24720;
UPDATE `gameobject` SET `rotation0`=0.00600815, `rotation1`=0.00140476, `rotation2`=-0.996615, `rotation3`=0.0819735 WHERE `guid`=24722;
UPDATE `gameobject` SET `rotation0`=-0.00526476, `rotation1`=-0.0032177, `rotation2`=0.972073, `rotation3`=0.234599 WHERE `guid`=24726;
UPDATE `gameobject` SET `rotation0`=0.00599813, `rotation1`=-0.00144768, `rotation2`=-0.853245, `rotation3`=0.521474 WHERE `guid`=24742;
UPDATE `gameobject` SET `rotation0`=0.00387716, `rotation1`=-0.00479984, `rotation2`=-0.359471, `rotation3`=0.933136 WHERE `guid`=24745;
UPDATE `gameobject` SET `rotation0`=-0.00043869, `rotation1`=0.00434017, `rotation2`=-0.994905, `rotation3`=0.100727 WHERE `guid`=24760;
UPDATE `gameobject` SET `rotation0`=0.0261407, `rotation1`=-0.0523176, `rotation2`=0.998287, `rotation3`=0.00148505 WHERE `guid`=24869;
UPDATE `gameobject` SET `rotation0`=0.101759, `rotation1`=0.00521469, `rotation2`=0.9523, `rotation3`=0.28765 WHERE `guid`=25120;
UPDATE `gameobject` SET `rotation0`=0.0778918, `rotation1`=-0.124165, `rotation2`=0.683997, `rotation3`=0.714607 WHERE `guid`=25256;
UPDATE `gameobject` SET `rotation0`=0.106593, `rotation1`=-0.075654, `rotation2`=0.960539, `rotation3`=0.245519 WHERE `guid`=25257;
UPDATE `gameobject` SET `rotation0`=-0.0218129, `rotation1`=0.0130854, `rotation2`=0.999676, `rotation3`=0.00117086 WHERE `guid`=25913;
UPDATE `gameobject` SET `rotation0`=-0.59733, `rotation1`=-0.208596, `rotation2`=-0.731095, `rotation3`=0.255313 WHERE `guid`=26628;
UPDATE `gameobject` SET `rotation0`=-0.042439, `rotation1`=0.0258846, `rotation2`=-0.934402, `rotation3`=0.352734 WHERE `guid`=26846;
UPDATE `gameobject` SET `rotation0`=0.0240598, `rotation1`=-0.0310163, `rotation2`=-0.946024, `rotation3`=0.321711 WHERE `guid`=31662;
UPDATE `gameobject` SET `rotation0`=-0.00346088, `rotation1`=0.00462914, `rotation2`=0.577754, `rotation3`=0.81619 WHERE `guid`=32331;
UPDATE `gameobject` SET `rotation0`=0.118706, `rotation1`=0.0711489, `rotation2`=-0.899253, `rotation3`=0.414959 WHERE `guid`=42485;
UPDATE `gameobject` SET `rotation0`=-0.0733967, `rotation1`=-0.0395975, `rotation2`=0.686763, `rotation3`=0.722082 WHERE `guid`=42854;
UPDATE `gameobject` SET `rotation0`=0.00646782, `rotation1`=0.00192738, `rotation2`=0.999939, `rotation3`=0.00874828 WHERE `guid`=42958;
UPDATE `gameobject` SET `rotation0`=0.0646195, `rotation1`=0.0148668, `rotation2`=-0.997768, `rotation3`=0.00783916 WHERE `guid`=42985;
UPDATE `gameobject` SET `rotation0`=0.0384789, `rotation1`=0.0146103, `rotation2`=-0.999125, `rotation3`=0.00748919 WHERE `guid`=43182;
UPDATE `gameobject` SET `rotation0`=0.0646195, `rotation1`=0.0148668, `rotation2`=-0.997768, `rotation3`=0.00783916 WHERE `guid`=43193;
UPDATE `gameobject` SET `rotation0`=-0.0566726, `rotation1`=0.0261345, `rotation2`=0.998049, `rotation3`=0.00195313 WHERE `guid`=45565;
UPDATE `gameobject` SET `rotation0`=0.00597954, `rotation1`=-0.0124331, `rotation2`=-0.991918, `rotation3`=0.126131 WHERE `guid`=48526;
UPDATE `gameobject` SET `rotation0`=-0.402262, `rotation1`=-0.303519, `rotation2`=-0.679092, `rotation3`=0.533756 WHERE `guid`=48529;
UPDATE `gameobject` SET `rotation0`=-0.0139608, `rotation1`=-0.0136299, `rotation2`=-0.952168, `rotation3`=0.304953 WHERE `guid`=48551;
UPDATE `gameobject` SET `rotation0`=0.0608597, `rotation1`=-0.0783129, `rotation2`=0.995057, `rotation3`=0.00495468 WHERE `guid`=50347;
UPDATE `gameobject` SET `rotation0`=0.0022459, `rotation1`=0.0019207, `rotation2`=-0.82254, `rotation3`=0.568699 WHERE `guid`=55040;
UPDATE `gameobject` SET `rotation0`=0.064477, `rotation1`=-0.0282221, `rotation2`=-0.982747, `rotation3`=0.171039 WHERE `guid`=55077;
UPDATE `gameobject` SET `rotation0`=-0.0520096, `rotation1`=-0.0134745, `rotation2`=0.22455, `rotation3`=0.97298 WHERE `guid`=55419;
UPDATE `gameobject` SET `rotation0`=-0.00342178, `rotation1`=-0.0196419, `rotation2`=0.583972, `rotation3`=0.811529 WHERE `guid`=56066;
UPDATE `gameobject` SET `rotation0`=0.0469356, `rotation1`=-0.0745831, `rotation2`=-0.287543, `rotation3`=0.953705 WHERE `guid`=56099;
UPDATE `gameobject` SET `rotation0`=0.0234499, `rotation1`=-0.0849457, `rotation2`=-0.550198, `rotation3`=0.830372 WHERE `guid`=56106;
UPDATE `gameobject` SET `rotation0`=0.00357676, `rotation1`=0.00249863, `rotation2`=0.984033, `rotation3`=0.177935 WHERE `guid`=56122;
UPDATE `gameobject` SET `rotation0`=0.0249286, `rotation1`=-0.0845232, `rotation2`=-0.535622, `rotation3`=0.839848 WHERE `guid`=56124;
UPDATE `gameobject` SET `rotation0`=-0.00971794, `rotation1`=-0.0320435, `rotation2`=-0.997552, `rotation3`=0.0613915 WHERE `guid`=56222;
UPDATE `gameobject` SET `rotation0`=-0.0123668, `rotation1`=-0.0872507, `rotation2`=-0.835673, `rotation3`=0.542111 WHERE `guid`=56223;
UPDATE `gameobject` SET `rotation0`=-0.017982, `rotation1`=0.0323582, `rotation2`=0.703278, `rotation3`=0.709951 WHERE `guid`=56243;
UPDATE `gameobject` SET `rotation0`=0.0828447, `rotation1`=0.0300417, `rotation2`=0.870979, `rotation3`=0.483352 WHERE `guid`=56294;
UPDATE `gameobject` SET `rotation0`=0.0170689, `rotation1`=-0.00339508, `rotation2`=-0.831343, `rotation3`=0.555488 WHERE `guid`=56583;
UPDATE `gameobject` SET `rotation0`=-0.00762081, `rotation1`=-0.0171156, `rotation2`=0.70084, `rotation3`=0.713072 WHERE `guid`=56656;
UPDATE `gameobject` SET `rotation0`=-0.0153003, `rotation1`=0.0108137, `rotation2`=-0.836097, `rotation3`=0.548262 WHERE `guid`=56657;
UPDATE `gameobject` SET `rotation0`=-0.00747776, `rotation1`=0.00981712, `rotation2`=-0.636003, `rotation3`=0.771587 WHERE `guid`=56707;
UPDATE `gameobject` SET `rotation0`=0.00858116, `rotation1`=0.000598907, `rotation2`=0.70708, `rotation3`=0.707081 WHERE `guid`=56709;
UPDATE `gameobject` SET `rotation0`=-0.00108576, `rotation1`=-0.00853348, `rotation2`=-0.831438, `rotation3`=0.555551 WHERE `guid`=56710;
UPDATE `gameobject` SET `rotation0`=0.0329785, `rotation1`=0.027854, `rotation2`=-0.492602, `rotation3`=0.869183 WHERE `guid`=57528;
UPDATE `gameobject` SET `rotation0`=0.0271997, `rotation1`=0.0176859, `rotation2`=-0.837915, `rotation3`=0.544835 WHERE `guid`=57532;
UPDATE `gameobject` SET `rotation0`=0.00369692, `rotation1`=0.0233622, `rotation2`=-0.494075, `rotation3`=0.869098 WHERE `guid`=57536;
UPDATE `gameobject` SET `rotation0`=-0.0176406, `rotation1`=0.0272284, `rotation2`=0.543453, `rotation3`=0.838812 WHERE `guid`=57540;
UPDATE `gameobject` SET `rotation0`=0.0267119, `rotation1`=0.0184145, `rotation2`=-0.822888, `rotation3`=0.567276 WHERE `guid`=57567;
UPDATE `gameobject` SET `rotation0`=0.0122328, `rotation1`=-0.0124474, `rotation2`=-0.713141, `rotation3`=0.700803 WHERE `guid`=57574;
UPDATE `gameobject` SET `rotation0`=-0.0184145, `rotation1`=0.0267115, `rotation2`=0.567276, `rotation3`=0.822888 WHERE `guid`=57576;
UPDATE `gameobject` SET `rotation0`=-0.0411167, `rotation1`=0.0145597, `rotation2`=-0.333488, `rotation3`=0.941745 WHERE `guid`=57631;
UPDATE `gameobject` SET `rotation0`=0.0780907, `rotation1`=0.0286131, `rotation2`=-0.38856, `rotation3`=0.917662 WHERE `guid`=57635;
UPDATE `gameobject` SET `rotation0`=-0.00915575, `rotation1`=0.0746326, `rotation2`=0.898921, `rotation3`=0.43161 WHERE `guid`=57768;
UPDATE `gameobject` SET `rotation0`=0.0133748, `rotation1`=0.0159645, `rotation2`=0.999181, `rotation3`=0.0346989 WHERE `guid`=57778;
UPDATE `gameobject` SET `rotation0`=0.997061, `rotation1`=-0.0563049, `rotation2`=-0.00894737, `rotation3`=0.0511718 WHERE `guid`=57781;
UPDATE `gameobject` SET `rotation0`=-0.00120354, `rotation1`=-0.0202312, `rotation2`=0.999186, `rotation3`=0.0348925 WHERE `guid`=57792;
UPDATE `gameobject` SET `rotation0`=-0.010067, `rotation1`=-0.0192642, `rotation2`=-0.544604, `rotation3`=0.838411 WHERE `guid`=57794;
UPDATE `gameobject` SET `rotation0`=0.0594649, `rotation1`=0.0722637, `rotation2`=-0.99546, `rotation3`=0.0173821 WHERE `guid`=57800;
UPDATE `gameobject` SET `rotation0`=-0.0636859, `rotation1`=0.0447683, `rotation2`=0.99641, `rotation3`=0.0332605 WHERE `guid`=57845;
UPDATE `gameobject` SET `rotation0`=-0.0478525, `rotation1`=-0.0228243, `rotation2`=-0.901316, `rotation3`=0.429906 WHERE `guid`=57849;
UPDATE `gameobject` SET `rotation0`=-0.0688047, `rotation1`=-0.0223722, `rotation2`=0.993367, `rotation3`=0.0893701 WHERE `guid`=57868;
UPDATE `gameobject` SET `rotation0`=0.00230885, `rotation1`=-0.134351, `rotation2`=0.609957, `rotation3`=0.780959 WHERE `guid`=57887;
UPDATE `gameobject` SET `rotation0`=-0.101412, `rotation1`=-0.0473404, `rotation2`=0.990035, `rotation3`=0.0854701 WHERE `guid`=57888;
UPDATE `gameobject` SET `rotation0`=-0.061111, `rotation1`=-0.0142727, `rotation2`=-0.950614, `rotation3`=0.303965 WHERE `guid`=57889;
UPDATE `gameobject` SET `rotation0`=-0.00625563, `rotation1`=0.00534725, `rotation2`=-0.79151, `rotation3`=0.611101 WHERE `guid`=57977;
UPDATE `gameobject` SET `rotation0`=-0.021769, `rotation1`=0.00458431, `rotation2`=-0.304047, `rotation3`=0.952397 WHERE `guid`=57978;
UPDATE `gameobject` SET `rotation0`=0.0169549, `rotation1`=0.00413513, `rotation2`=0.999241, `rotation3`=0.0348292 WHERE `guid`=57998;
UPDATE `gameobject` SET `rotation0`=-0.00625563, `rotation1`=0.00534725, `rotation2`=-0.79151, `rotation3`=0.611101 WHERE `guid`=58003;
UPDATE `gameobject` SET `rotation0`=-0.00561047, `rotation1`=0.00602055, `rotation2`=-0.855554, `rotation3`=0.517649 WHERE `guid`=58015;
UPDATE `gameobject` SET `rotation0`=-0.00700092, `rotation1`=0.00432682, `rotation2`=-0.688617, `rotation3`=0.725079 WHERE `guid`=58033;
UPDATE `gameobject` SET `rotation0`=-0.00797653, `rotation1`=0.00202751, `rotation2`=-0.439443, `rotation3`=0.898233 WHERE `guid`=58054;
UPDATE `gameobject` SET `rotation0`=-0.0053606, `rotation1`=-0.0215902, `rotation2`=0.940907, `rotation3`=0.337935 WHERE `guid`=58137;
UPDATE `gameobject` SET `rotation0`=-0.0053606, `rotation1`=-0.0215902, `rotation2`=0.940907, `rotation3`=0.337935 WHERE `guid`=58152;
UPDATE `gameobject` SET `rotation0`=-0.0053606, `rotation1`=-0.0215902, `rotation2`=0.940907, `rotation3`=0.337935 WHERE `guid`=58175;
UPDATE `gameobject` SET `rotation0`=-0.0190578, `rotation1`=-0.0114765, `rotation2`=0.426367, `rotation3`=0.904277 WHERE `guid`=58191;
UPDATE `gameobject` SET `rotation0`=-0.0190578, `rotation1`=-0.0114765, `rotation2`=0.426367, `rotation3`=0.904277 WHERE `guid`=58208;
UPDATE `gameobject` SET `rotation0`=-0.0215907, `rotation1`=0.0053606, `rotation2`=-0.337934, `rotation3`=0.940907 WHERE `guid`=58220;
UPDATE `gameobject` SET `rotation0`=-0.0213366, `rotation1`=0.00629711, `rotation2`=-0.378653, `rotation3`=0.925272 WHERE `guid`=58225;
UPDATE `gameobject` SET `rotation0`=0.0115876, `rotation1`=0.0149164, `rotation2`=-0.972156, `rotation3`=0.233574 WHERE `guid`=58300;
UPDATE `gameobject` SET `rotation0`=-0.013093, `rotation1`=0.0179844, `rotation2`=-0.863675, `rotation3`=0.503558 WHERE `guid`=58303;
UPDATE `gameobject` SET `rotation0`=-0.0203118, `rotation1`=-0.0571537, `rotation2`=0.737972, `rotation3`=0.6721 WHERE `guid`=58307;
UPDATE `gameobject` SET `rotation0`=-0.00221872, `rotation1`=-0.00375652, `rotation2`=0.788001, `rotation3`=0.615658 WHERE `guid`=58972;
UPDATE `gameobject` SET `rotation0`=0.0625529, `rotation1`=-0.00466824, `rotation2`=0.99803, `rotation3`=0.00142357 WHERE `guid`=59047;
UPDATE `gameobject` SET `rotation0`=0.0179548, `rotation1`=-0.00972557, `rotation2`=0.999791, `rotation3`=0 WHERE `guid`=59052;
UPDATE `gameobject` SET `rotation0`=-0.00726509, `rotation1`=0.0038681, `rotation2`=-0.640481, `rotation3`=0.76793 WHERE `guid`=59053;
UPDATE `gameobject` SET `rotation0`=-0.00820541, `rotation1`=-0.000640869, `rotation2`=-0.127568, `rotation3`=0.991796 WHERE `guid`=59089;
UPDATE `gameobject` SET `rotation0`=0.0214567, `rotation1`=-0.00587368, `rotation2`=0.997311, `rotation3`=0.0698328 WHERE `guid`=59092;
UPDATE `gameobject` SET `rotation0`=-0.0145078, `rotation1`=-0.00969982, `rotation2`=0.66255, `rotation3`=0.748814 WHERE `guid`=59750;
UPDATE `gameobject` SET `rotation0`=0.0100765, `rotation1`=-0.0142488, `rotation2`=-0.765911, `rotation3`=0.64271 WHERE `guid`=59757;
UPDATE `gameobject` SET `rotation0`=-0.00212193, `rotation1`=-0.0173225, `rotation2`=-0.134826, `rotation3`=0.990716 WHERE `guid`=59769;
UPDATE `gameobject` SET `rotation0`=0.010324, `rotation1`=-0.0140705, `rotation2`=-0.777019, `rotation3`=0.629236 WHERE `guid`=59787;
UPDATE `gameobject` SET `rotation0`=-0.00570679, `rotation1`=-0.019104, `rotation2`=0.484539, `rotation3`=0.874542 WHERE `guid`=59858;
UPDATE `gameobject` SET `rotation0`=0.000127792, `rotation1`=-0.0199375, `rotation2`=0.719059, `rotation3`=0.694663 WHERE `guid`=59873;
UPDATE `gameobject` SET `rotation0`=0.0949898, `rotation1`=-0.0109949, `rotation2`=-0.438946, `rotation3`=0.893411 WHERE `guid`=60059;
UPDATE `gameobject` SET `rotation0`=0.0462666, `rotation1`=0.00813198, `rotation2`=-0.997513, `rotation3`=0.0525493 WHERE `guid`=60356;
UPDATE `gameobject` SET `rotation0`=0.000655651, `rotation1`=-0.00431347, `rotation2`=-0.99862, `rotation3`=0.0523356 WHERE `guid`=60402;
UPDATE `gameobject` SET `rotation0`=-0.00369263, `rotation1`=0.0337515, `rotation2`=-0.998056, `rotation3`=0.0522552 WHERE `guid`=60422;
UPDATE `gameobject` SET `rotation0`=-0.0572481, `rotation1`=0.0493526, `rotation2`=0.957794, `rotation3`=0.27734 WHERE `guid`=60430;
UPDATE `gameobject` SET `rotation0`=-0.00782394, `rotation1`=0.00386524, `rotation2`=0.894899, `rotation3`=0.446183 WHERE `guid`=60434;
UPDATE `gameobject` SET `rotation0`=0.0450549, `rotation1`=-0.035512, `rotation2`=0.997688, `rotation3`=0.0364277 WHERE `guid`=60443;
UPDATE `gameobject` SET `rotation0`=0.0507827, `rotation1`=-0.00883389, `rotation2`=0.998049, `rotation3`=0.0352375 WHERE `guid`=60453;
UPDATE `gameobject` SET `rotation0`=0.0323796, `rotation1`=-0.00742626, `rotation2`=0.831214, `rotation3`=0.554959 WHERE `guid`=60466;
UPDATE `gameobject` SET `rotation0`=-0.00159168, `rotation1`=-0.0173798, `rotation2`=-0.165, `rotation3`=0.986139 WHERE `guid`=60505;
UPDATE `gameobject` SET `rotation0`=0.00299168, `rotation1`=0.00317574, `rotation2`=0.465605, `rotation3`=0.884982 WHERE `guid`=60512;
UPDATE `gameobject` SET `rotation0`=0.00376463, `rotation1`=-0.00488853, `rotation2`=-0.999977, `rotation3`=0.0027729 WHERE `guid`=60670;
UPDATE `gameobject` SET `rotation0`=-0.00823879, `rotation1`=0.00287342, `rotation2`=-0.358356, `rotation3`=0.933544 WHERE `guid`=60705;
UPDATE `gameobject` SET `rotation0`=0.0208797, `rotation1`=0.0497112, `rotation2`=-0.915771, `rotation3`=0.398067 WHERE `guid`=60758;
UPDATE `gameobject` SET `rotation0`=-0.0140252, `rotation1`=-0.0223131, `rotation2`=-0.931563, `rotation3`=0.362623 WHERE `guid`=60818;
UPDATE `gameobject` SET `rotation0`=-0.0140252, `rotation1`=-0.0223131, `rotation2`=-0.931563, `rotation3`=0.362623 WHERE `guid`=60869;
UPDATE `gameobject` SET `rotation0`=-0.0112252, `rotation1`=0.019206, `rotation2`=-0.90978, `rotation3`=0.414495 WHERE `guid`=61001;
UPDATE `gameobject` SET `rotation0`=-0.0112252, `rotation1`=0.019206, `rotation2`=-0.90978, `rotation3`=0.414495 WHERE `guid`=61006;
UPDATE `gameobject` SET `rotation0`=-0.0192065, `rotation1`=-0.0112247, `rotation2`=0.414494, `rotation3`=0.90978 WHERE `guid`=61028;
UPDATE `gameobject` SET `rotation0`=-0.0192065, `rotation1`=-0.0112247, `rotation2`=0.414494, `rotation3`=0.90978 WHERE `guid`=61058;
UPDATE `gameobject` SET `rotation0`=-0.0192556, `rotation1`=-0.0111418, `rotation2`=0.41052, `rotation3`=0.91158 WHERE `guid`=61067;
UPDATE `gameobject` SET `rotation0`=-0.0192556, `rotation1`=-0.0111418, `rotation2`=0.41052, `rotation3`=0.91158 WHERE `guid`=61091;
UPDATE `gameobject` SET `rotation0`=-0.0113096, `rotation1`=0.0191565, `rotation2`=-0.907963, `rotation3`=0.41846 WHERE `guid`=61117;
UPDATE `gameobject` SET `rotation0`=-0.0113096, `rotation1`=0.0191565, `rotation2`=-0.907963, `rotation3`=0.41846 WHERE `guid`=61128;
UPDATE `gameobject` SET `rotation0`=-0.00185108, `rotation1`=-0.0210752, `rotation2`=0.926908, `rotation3`=0.374693 WHERE `guid`=61143;
UPDATE `gameobject` SET `rotation0`=-0.00629711, `rotation1`=-0.0213366, `rotation2`=0.925271, `rotation3`=0.378654 WHERE `guid`=61166;
UPDATE `gameobject` SET `rotation0`=-0.0210757, `rotation1`=0.00185108, `rotation2`=-0.374691, `rotation3`=0.926908 WHERE `guid`=61207;
UPDATE `gameobject` SET `rotation0`=-0.0213366, `rotation1`=0.00629711, `rotation2`=-0.378653, `rotation3`=0.925272 WHERE `guid`=61214;
UPDATE `gameobject` SET `rotation0`=-0.0215907, `rotation1`=0.0053606, `rotation2`=-0.337933, `rotation3`=0.940907 WHERE `guid`=61236;
UPDATE `gameobject` SET `rotation0`=-0.0215907, `rotation1`=0.0053606, `rotation2`=-0.337933, `rotation3`=0.940907 WHERE `guid`=61242;
UPDATE `gameobject` SET `rotation0`=-0.0213432, `rotation1`=0.00627518, `rotation2`=-0.377692, `rotation3`=0.925664 WHERE `guid`=61244;
UPDATE `gameobject` SET `rotation0`=-0.0553427, `rotation1`=-0.069665, `rotation2`=0.955796, `rotation3`=0.280245 WHERE `guid`=61493;
UPDATE `gameobject` SET `rotation0`=-0.00479174, `rotation1`=-0.0271702, `rotation2`=-0.655555, `rotation3`=0.754643 WHERE `guid`=61539;
UPDATE `gameobject` SET `rotation0`=0.0131559, `rotation1`=0.0326118, `rotation2`=-0.994302, `rotation3`=0.100635 WHERE `guid`=61588;
UPDATE `gameobject` SET `rotation0`=-0.00400114, `rotation1`=-0.00394249, `rotation2`=0.558556, `rotation3`=0.829448 WHERE `guid`=61665;
UPDATE `gameobject` SET `rotation0`=-0.00552464, `rotation1`=0.00101566, `rotation2`=-0.359068, `rotation3`=0.933295 WHERE `guid`=61775;
UPDATE `gameobject` SET `rotation0`=0.0938687, `rotation1`=-0.0521898, `rotation2`=-0.949377, `rotation3`=0.295209 WHERE `guid`=62004;
UPDATE `gameobject` SET `rotation0`=0.0347409, `rotation1`=-0.07829, `rotation2`=-0.81131, `rotation3`=0.578308 WHERE `guid`=62008;
UPDATE `gameobject` SET `rotation0`=-0.0624795, `rotation1`=-0.0596743, `rotation2`=0.803572, `rotation3`=0.588904 WHERE `guid`=62010;
UPDATE `gameobject` SET `rotation0`=-0.0421896, `rotation1`=-0.0416889, `rotation2`=0.747766, `rotation3`=0.661308 WHERE `guid`=62013;
UPDATE `gameobject` SET `rotation0`=-0.0421896, `rotation1`=-0.0416889, `rotation2`=0.747766, `rotation3`=0.661308 WHERE `guid`=62015;
UPDATE `gameobject` SET `rotation0`=-0.070652, `rotation1`=-0.0217209, `rotation2`=0.76553, `rotation3`=0.639141 WHERE `guid`=62017;
UPDATE `gameobject` SET `rotation0`=-0.0267367, `rotation1`=-0.0508165, `rotation2`=-0.143241, `rotation3`=0.988021 WHERE `guid`=62019;
UPDATE `gameobject` SET `rotation0`=-0.0184536, `rotation1`=-0.0218439, `rotation2`=0.515646, `rotation3`=0.856324 WHERE `guid`=62020;
UPDATE `gameobject` SET `rotation0`=0.544168, `rotation1`=0.438963, `rotation2`=-0.515592, `rotation3`=0.495336 WHERE `guid`=62022;
UPDATE `gameobject` SET `rotation0`=-0.0297956, `rotation1`=-0.103779, `rotation2`=-0.0643826, `rotation3`=0.992067 WHERE `guid`=62029;
UPDATE `gameobject` SET `rotation0`=-0.173857, `rotation1`=-0.281583, `rotation2`=0.244537, `rotation3`=0.91142 WHERE `guid`=62034;
UPDATE `gameobject` SET `rotation0`=0.0402169, `rotation1`=-0.225434, `rotation2`=-0.500674, `rotation3`=0.834798 WHERE `guid`=62037;
UPDATE `gameobject` SET `rotation0`=-0.267074, `rotation1`=0.195414, `rotation2`=-0.927796, `rotation3`=0.172276 WHERE `guid`=62039;
UPDATE `gameobject` SET `rotation0`=-0.084765, `rotation1`=0.142902, `rotation2`=0.731836, `rotation3`=0.660916 WHERE `guid`=62040;
UPDATE `gameobject` SET `rotation0`=-0.0131726, `rotation1`=-0.0648012, `rotation2`=0.134588, `rotation3`=0.988693 WHERE `guid`=62045;
UPDATE `gameobject` SET `rotation0`=-0.0770526, `rotation1`=-0.0317087, `rotation2`=0.687312, `rotation3`=0.721567 WHERE `guid`=62070;
UPDATE `gameobject` SET `rotation0`=0.0221438, `rotation1`=0.00338078, `rotation2`=-0.734296, `rotation3`=0.67846 WHERE `guid`=62071;
UPDATE `gameobject` SET `rotation0`=0.097621, `rotation1`=0.66564, `rotation2`=0.227495, `rotation3`=0.704017 WHERE `guid`=62072;
UPDATE `gameobject` SET `rotation0`=-0.0590367, `rotation1`=-0.00439453, `rotation2`=0.907238, `rotation3`=0.416431 WHERE `guid`=62074;
UPDATE `gameobject` SET `rotation0`=-0.0321445, `rotation1`=0.0484037, `rotation2`=0.955317, `rotation3`=0.289817 WHERE `guid`=62076;
UPDATE `gameobject` SET `rotation0`=-0.0091877, `rotation1`=0.0102921, `rotation2`=-0.370451, `rotation3`=0.92875 WHERE `guid`=62203;
UPDATE `gameobject` SET `rotation0`=-0.038785, `rotation1`=-0.0182981, `rotation2`=-0.371068, `rotation3`=0.927615 WHERE `guid`=62207;
UPDATE `gameobject` SET `rotation0`=0.057168, `rotation1`=0.211483, `rotation2`=-0.244818, `rotation3`=0.944495 WHERE `guid`=62211;
UPDATE `gameobject` SET `rotation0`=-0.149701, `rotation1`=-0.0807028, `rotation2`=-0.879606, `rotation3`=0.444263 WHERE `guid`=62212;
UPDATE `gameobject` SET `rotation0`=0.0538278, `rotation1`=-0.0377436, `rotation2`=0.759027, `rotation3`=0.647732 WHERE `guid`=62213;
UPDATE `gameobject` SET `rotation0`=-0.126301, `rotation1`=0.0268679, `rotation2`=-0.963754, `rotation3`=0.233463 WHERE `guid`=62214;
UPDATE `gameobject` SET `rotation0`=-0.0738959, `rotation1`=0.0277271, `rotation2`=0.986376, `rotation3`=0.144338 WHERE `guid`=62218;
UPDATE `gameobject` SET `rotation0`=0.0124745, `rotation1`=0.0353851, `rotation2`=-0.706221, `rotation3`=0.706997 WHERE `guid`=62221;
UPDATE `gameobject` SET `rotation0`=-0.00383759, `rotation1`=-0.0591726, `rotation2`=0.299043, `rotation3`=0.952396 WHERE `guid`=62276;
UPDATE `gameobject` SET `rotation0`=-0.0719967, `rotation1`=0.0297947, `rotation2`=0.786651, `rotation3`=0.612462 WHERE `guid`=62299;
UPDATE `gameobject` SET `rotation0`=-0.0790567, `rotation1`=0.0276194, `rotation2`=0.945269, `rotation3`=0.315364 WHERE `guid`=62302;
UPDATE `gameobject` SET `rotation0`=-0.0700746, `rotation1`=-0.0305157, `rotation2`=0.296399, `rotation3`=0.952001 WHERE `guid`=62344;
UPDATE `gameobject` SET `rotation0`=-0.054544, `rotation1`=-0.0291481, `rotation2`=0.562613, `rotation3`=0.824404 WHERE `guid`=62346;
UPDATE `gameobject` SET `rotation0`=-0.0337057, `rotation1`=-0.0518045, `rotation2`=0.0559473, `rotation3`=0.996519 WHERE `guid`=62348;
UPDATE `gameobject` SET `rotation0`=0.295899, `rotation1`=0.0340376, `rotation2`=0.329922, `rotation3`=0.895788 WHERE `guid`=62350;
UPDATE `gameobject` SET `rotation0`=-0.0818739, `rotation1`=0.267369, `rotation2`=0.863095, `rotation3`=0.420567 WHERE `guid`=62352;
UPDATE `gameobject` SET `rotation0`=0.0104589, `rotation1`=0.0212154, `rotation2`=-0.729574, `rotation3`=0.683492 WHERE `guid`=62353;
UPDATE `gameobject` SET `rotation0`=0.307564, `rotation1`=0.347115, `rotation2`=-0.125055, `rotation3`=0.877084 WHERE `guid`=62355;
UPDATE `gameobject` SET `rotation0`=0.00250769, `rotation1`=-0.013567, `rotation2`=0.88282, `rotation3`=0.469508 WHERE `guid`=62356;
UPDATE `gameobject` SET `rotation0`=-0.215984, `rotation1`=0.256128, `rotation2`=0.85913, `rotation3`=0.38684 WHERE `guid`=62358;
UPDATE `gameobject` SET `rotation0`=0.341446, `rotation1`=-0.304326, `rotation2`=0.602724, `rotation3`=0.653853 WHERE `guid`=62362;
UPDATE `gameobject` SET `rotation0`=0.120763, `rotation1`=-0.236484, `rotation2`=-0.909652, `rotation3`=0.319414 WHERE `guid`=62364;
UPDATE `gameobject` SET `rotation0`=-0.244493, `rotation1`=-0.195951, `rotation2`=0.949099, `rotation3`=0.0322192 WHERE `guid`=62369;
UPDATE `gameobject` SET `rotation0`=0.175162, `rotation1`=-0.601875, `rotation2`=0.694636, `rotation3`=0.352909 WHERE `guid`=62374;
UPDATE `gameobject` SET `rotation0`=0.0800338, `rotation1`=-0.00780964, `rotation2`=-0.987558, `rotation3`=0.135137 WHERE `guid`=62375;
UPDATE `gameobject` SET `rotation0`=0.0362339, `rotation1`=-0.0262403, `rotation2`=-0.94461, `rotation3`=0.325133 WHERE `guid`=62376;
UPDATE `gameobject` SET `rotation0`=-0.00289059, `rotation1`=-0.0755463, `rotation2`=-0.55819, `rotation3`=0.826261 WHERE `guid`=62377;
UPDATE `gameobject` SET `rotation0`=-0.0657239, `rotation1`=0.0171518, `rotation2`=0.896297, `rotation3`=0.43822 WHERE `guid`=62379;
UPDATE `gameobject` SET `rotation0`=-0.062573, `rotation1`=0.0657063, `rotation2`=0.994164, `rotation3`=0.0583465 WHERE `guid`=62380;
UPDATE `gameobject` SET `rotation0`=-0.103618, `rotation1`=0.0230484, `rotation2`=0.909678, `rotation3`=0.401521 WHERE `guid`=62382;
UPDATE `gameobject` SET `rotation0`=-0.0568237, `rotation1`=0.0413055, `rotation2`=0.996267, `rotation3`=0.050163 WHERE `guid`=62383;
UPDATE `gameobject` SET `rotation0`=-0.134973, `rotation1`=-0.13683, `rotation2`=-0.929156, `rotation3`=0.315798 WHERE `guid`=62384;
UPDATE `gameobject` SET `rotation0`=0.0177789, `rotation1`=-0.0288286, `rotation2`=-0.784378, `rotation3`=0.619358 WHERE `guid`=62385;
UPDATE `gameobject` SET `rotation0`=-0.078877, `rotation1`=-0.00378895, `rotation2`=0.914302, `rotation3`=0.397261 WHERE `guid`=62386;
UPDATE `gameobject` SET `rotation0`=-0.0624537, `rotation1`=0.0621939, `rotation2`=0.996101, `rotation3`=0.00367024 WHERE `guid`=62420;
UPDATE `gameobject` SET `rotation0`=0.496306, `rotation1`=0.0242853, `rotation2`=-0.867702, `rotation3`=0.0135888 WHERE `guid`=62421;
UPDATE `gameobject` SET `rotation0`=-0.0650849, `rotation1`=0.0319777, `rotation2`=0.997365, `rotation3`=0.00211432 WHERE `guid`=62422;
UPDATE `gameobject` SET `rotation0`=0.0176468, `rotation1`=-0.0565901, `rotation2`=-0.678891, `rotation3`=0.731842 WHERE `guid`=62423;
UPDATE `gameobject` SET `rotation0`=-0.0446796, `rotation1`=-0.00412178, `rotation2`=0.528811, `rotation3`=0.847553 WHERE `guid`=62427;
UPDATE `gameobject` SET `rotation0`=-0.0496626, `rotation1`=0.0201645, `rotation2`=0.826765, `rotation3`=0.559988 WHERE `guid`=62429;
UPDATE `gameobject` SET `rotation0`=-0.0713949, `rotation1`=0.0128832, `rotation2`=0.997364, `rotation3`=0.00131474 WHERE `guid`=62431;
UPDATE `gameobject` SET `rotation0`=0.0647397, `rotation1`=0.00320148, `rotation2`=-0.997896, `rotation3`=0.00131474 WHERE `guid`=62433;
UPDATE `gameobject` SET `rotation0`=-0.622238, `rotation1`=0.170283, `rotation2`=0.610718, `rotation3`=0.459182 WHERE `guid`=62438;
UPDATE `gameobject` SET `rotation0`=0.152232, `rotation1`=0.111365, `rotation2`=-0.901051, `rotation3`=0.390552 WHERE `guid`=62440;
UPDATE `gameobject` SET `rotation0`=-0.0765719, `rotation1`=0.0206394, `rotation2`=0.989102, `rotation3`=0.124046 WHERE `guid`=62442;
UPDATE `gameobject` SET `rotation0`=-0.0628777, `rotation1`=0.0141687, `rotation2`=0.971451, `rotation3`=0.228318 WHERE `guid`=62443;
UPDATE `gameobject` SET `rotation0`=0.241684, `rotation1`=0.120824, `rotation2`=-0.52985, `rotation3`=0.803896 WHERE `guid`=62444;
UPDATE `gameobject` SET `rotation0`=0.453855, `rotation1`=-0.520619, `rotation2`=0.477769, `rotation3`=0.54287 WHERE `guid`=62445;
UPDATE `gameobject` SET `rotation0`=-0.0516787, `rotation1`=0.0323219, `rotation2`=0.992534, `rotation3`=0.105648 WHERE `guid`=62450;
UPDATE `gameobject` SET `rotation0`=0.131849, `rotation1`=-0.683728, `rotation2`=-0.0452547, `rotation3`=0.716299 WHERE `guid`=62451;
UPDATE `gameobject` SET `rotation0`=0.476533, `rotation1`=-0.52781, `rotation2`=0.490279, `rotation3`=0.503944 WHERE `guid`=62452;
UPDATE `gameobject` SET `rotation0`=-0.0410066, `rotation1`=0.0257225, `rotation2`=0.922812, `rotation3`=0.382199 WHERE `guid`=62454;
UPDATE `gameobject` SET `rotation0`=-0.0262136, `rotation1`=-0.0292301, `rotation2`=0.954082, `rotation3`=0.296963 WHERE `guid`=62456;
UPDATE `gameobject` SET `rotation0`=0.05055, `rotation1`=-0.00258732, `rotation2`=-0.939903, `rotation3`=0.337668 WHERE `guid`=62457;
UPDATE `gameobject` SET `rotation0`=-0.0494318, `rotation1`=-0.00887966, `rotation2`=0.62317, `rotation3`=0.780472 WHERE `guid`=62458;
UPDATE `gameobject` SET `rotation0`=-0.000944614, `rotation1`=-0.040988, `rotation2`=-0.265645, `rotation3`=0.963199 WHERE `guid`=62462;
UPDATE `gameobject` SET `rotation0`=-0.0274858, `rotation1`=0.731253, `rotation2`=0.680927, `rotation3`=0.0291899 WHERE `guid`=62463;
UPDATE `gameobject` SET `rotation0`=-0.0713949, `rotation1`=0.0128832, `rotation2`=0.997364, `rotation3`=0.00131474 WHERE `guid`=62464;
UPDATE `gameobject` SET `rotation0`=-0.0986266, `rotation1`=-0.0312767, `rotation2`=0.69349, `rotation3`=0.712998 WHERE `guid`=62466;
UPDATE `gameobject` SET `rotation0`=-0.053257, `rotation1`=-0.0238132, `rotation2`=0.584893, `rotation3`=0.80901 WHERE `guid`=62467;
UPDATE `gameobject` SET `rotation0`=0.00172186, `rotation1`=0.496897, `rotation2`=-0.0318861, `rotation3`=0.867222 WHERE `guid`=62468;
UPDATE `gameobject` SET `rotation0`=-0.012682, `rotation1`=0.00324059, `rotation2`=-0.309, `rotation3`=0.950972 WHERE `guid`=62581;
UPDATE `gameobject` SET `rotation0`=-0.0216508, `rotation1`=0.0327387, `rotation2`=0.931026, `rotation3`=0.362837 WHERE `guid`=62591;
UPDATE `gameobject` SET `rotation0`=-0.00178766, `rotation1`=-0.00762177, `rotation2`=-0.00873852, `rotation3`=0.999931 WHERE `guid`=62593;
UPDATE `gameobject` SET `rotation0`=-0.0352879, `rotation1`=0.0307655, `rotation2`=0.736506, `rotation3`=0.67481 WHERE `guid`=62595;
UPDATE `gameobject` SET `rotation0`=-0.00647497, `rotation1`=0.0345688, `rotation2`=0.00893497, `rotation3`=0.999341 WHERE `guid`=62600;
UPDATE `gameobject` SET `rotation0`=0.0312877, `rotation1`=-0.0662994, `rotation2`=-0.82378, `rotation3`=0.562149 WHERE `guid`=62706;
UPDATE `gameobject` SET `rotation0`=0.0912547, `rotation1`=-0.0740461, `rotation2`=-0.973655, `rotation3`=0.195413 WHERE `guid`=62733;
UPDATE `gameobject` SET `rotation0`=-0.00413465, `rotation1`=0.00457954, `rotation2`=-0.0479574, `rotation3`=0.99883 WHERE `guid`=62734;
UPDATE `gameobject` SET `rotation0`=-0.101369, `rotation1`=0.0590372, `rotation2`=0.970378, `rotation3`=0.211201 WHERE `guid`=62746;
UPDATE `gameobject` SET `rotation0`=0.00691795, `rotation1`=-0.0743694, `rotation2`=-0.354098, `rotation3`=0.932221 WHERE `guid`=62754;
UPDATE `gameobject` SET `rotation0`=0.469189, `rotation1`=0.839209, `rotation2`=0.120181, `rotation3`=0.24728 WHERE `guid`=62755;
UPDATE `gameobject` SET `rotation0`=0.0654626, `rotation1`=-0.00331974, `rotation2`=-0.997606, `rotation3`=0.0220309 WHERE `guid`=62756;
UPDATE `gameobject` SET `rotation0`=0.0552759, `rotation1`=0.0188112, `rotation2`=-0.998293, `rotation3`=0.00140248 WHERE `guid`=62758;
UPDATE `gameobject` SET `rotation0`=0.0383778, `rotation1`=-0.0295868, `rotation2`=-0.915912, `rotation3`=0.398444 WHERE `guid`=62759;
UPDATE `gameobject` SET `rotation0`=-0.0766449, `rotation1`=0.025178, `rotation2`=0.947197, `rotation3`=0.310338 WHERE `guid`=62760;
UPDATE `gameobject` SET `rotation0`=0.0328836, `rotation1`=0.334789, `rotation2`=0.832582, `rotation3`=0.440047 WHERE `guid`=62761;
UPDATE `gameobject` SET `rotation0`=0.256151, `rotation1`=0.237044, `rotation2`=-0.923361, `rotation3`=0.160005 WHERE `guid`=62762;
UPDATE `gameobject` SET `rotation0`=-0.135204, `rotation1`=0.156828, `rotation2`=0.891665, `rotation3`=0.402566 WHERE `guid`=62763;
UPDATE `gameobject` SET `rotation0`=0.223603, `rotation1`=0.59363, `rotation2`=-0.256003, `rotation3`=0.72943 WHERE `guid`=62764;
UPDATE `gameobject` SET `rotation0`=0.060257, `rotation1`=0.680447, `rotation2`=-0.728232, `rotation3`=0.0551277 WHERE `guid`=62794;
UPDATE `gameobject` SET `rotation0`=0.60732, `rotation1`=0.432161, `rotation2`=-0.341002, `rotation3`=0.572815 WHERE `guid`=62795;
UPDATE `gameobject` SET `rotation0`=0.513972, `rotation1`=0.452635, `rotation2`=0.00952148, `rotation3`=0.728604 WHERE `guid`=62796;
UPDATE `gameobject` SET `rotation0`=0.611201, `rotation1`=-0.187566, `rotation2`=-0.147256, `rotation3`=0.754698 WHERE `guid`=62798;
UPDATE `gameobject` SET `rotation0`=0.0864978, `rotation1`=-0.766595, `rotation2`=-0.627791, `rotation3`=0.103578 WHERE `guid`=62800;
UPDATE `gameobject` SET `rotation0`=0.453995, `rotation1`=-0.54534, `rotation2`=-0.489407, `rotation3`=0.506927 WHERE `guid`=62802;
UPDATE `gameobject` SET `rotation0`=-0.11008, `rotation1`=-0.0325861, `rotation2`=0.971985, `rotation3`=0.2051 WHERE `guid`=62806;
UPDATE `gameobject` SET `rotation0`=-0.0574207, `rotation1`=-0.0667448, `rotation2`=0.803014, `rotation3`=0.589421 WHERE `guid`=62982;
UPDATE `gameobject` SET `rotation0`=-0.0617466, `rotation1`=-0.0747061, `rotation2`=0.240547, `rotation3`=0.965786 WHERE `guid`=63020;
UPDATE `gameobject` SET `rotation0`=-0.0421896, `rotation1`=-0.0416889, `rotation2`=0.747766, `rotation3`=0.661308 WHERE `guid`=63043;
UPDATE `gameobject` SET `rotation0`=-0.0131726, `rotation1`=-0.0648012, `rotation2`=0.134588, `rotation3`=0.988693 WHERE `guid`=63045;
UPDATE `gameobject` SET `rotation0`=-0.0740328, `rotation1`=0.00929928, `rotation2`=0.997211, `rotation3`=0.00142357 WHERE `guid`=63048;
UPDATE `gameobject` SET `rotation0`=-0.481176, `rotation1`=-0.0713978, `rotation2`=0.267664, `rotation3`=0.831702 WHERE `guid`=63049;
UPDATE `gameobject` SET `rotation0`=0.511276, `rotation1`=-0.266282, `rotation2`=0.778645, `rotation3`=0.247797 WHERE `guid`=63050;
UPDATE `gameobject` SET `rotation0`=0.0494189, `rotation1`=-0.263665, `rotation2`=0.470602, `rotation3`=0.840578 WHERE `guid`=63053;
UPDATE `gameobject` SET `rotation0`=0.0871148, `rotation1`=-0.0726948, `rotation2`=-0.45024, `rotation3`=0.885669 WHERE `guid`=63060;
UPDATE `gameobject` SET `rotation0`=-0.0000157356, `rotation1`=0.0079174, `rotation2`=0.992514, `rotation3`=0.121877 WHERE `guid`=65653;
UPDATE `gameobject` SET `rotation0`=-0.0263157, `rotation1`=0.0369759, `rotation2`=0.998969, `rotation3`=0.00100662 WHERE `guid`=65654;
UPDATE `gameobject` SET `rotation0`=-0.00622797, `rotation1`=0.00750923, `rotation2`=-0.414639, `rotation3`=0.909934 WHERE `guid`=65655;
UPDATE `gameobject` SET `rotation0`=-0.305481, `rotation1`=0.637715, `rotation2`=0.305481, `rotation3`=0.637716 WHERE `guid`=65857;
UPDATE `gameobject` SET `rotation0`=0.0129037, `rotation1`=-0.0371256, `rotation2`=0.312944, `rotation3`=0.948958 WHERE `guid`=65911;
UPDATE `gameobject` SET `rotation0`=-0.0407338, `rotation1`=-0.0906858, `rotation2`=0.957691, `rotation3`=0.270082 WHERE `guid`=65974;
UPDATE `gameobject` SET `rotation0`=0.0829248, `rotation1`=-0.210616, `rotation2`=0.47683, `rotation3`=0.849351 WHERE `guid`=65975;
UPDATE `gameobject` SET `rotation0`=0.0284739, `rotation1`=0.0860357, `rotation2`=-0.995881, `rotation3`=0.00281557 WHERE `guid`=65976;
UPDATE `gameobject` SET `rotation0`=0.0476589, `rotation1`=0.110981, `rotation2`=-0.992664, `rotation3`=0.0054153 WHERE `guid`=65977;
UPDATE `gameobject` SET `rotation0`=-0.0104766, `rotation1`=-0.0470209, `rotation2`=0.927595, `rotation3`=0.370468 WHERE `guid`=65978;
UPDATE `gameobject` SET `rotation0`=-0.0519929, `rotation1`=-0.00577831, `rotation2`=0.842955, `rotation3`=0.535435 WHERE `guid`=65982;
UPDATE `gameobject` SET `rotation0`=-0.00524759, `rotation1`=-0.0166445, `rotation2`=0.927033, `rotation3`=0.374572 WHERE `guid`=65985;
UPDATE `gameobject` SET `rotation0`=-0.0151815, `rotation1`=-0.0217628, `rotation2`=0.998057, `rotation3`=0.0563685 WHERE `guid`=65988;
UPDATE `gameobject` SET `rotation0`=0.146786, `rotation1`=-0.305458, `rotation2`=0.379759, `rotation3`=0.860774 WHERE `guid`=65992;
UPDATE `gameobject` SET `rotation0`=-0.0181217, `rotation1`=-0.116454, `rotation2`=0.978609, `rotation3`=0.168625 WHERE `guid`=65993;
UPDATE `gameobject` SET `rotation0`=-0.213069, `rotation1`=0.177652, `rotation2`=0.864994, `rotation3`=0.418123 WHERE `guid`=65994;
UPDATE `gameobject` SET `rotation0`=0.422521, `rotation1`=-0.0203085, `rotation2`=-0.134406, `rotation3`=0.896102 WHERE `guid`=65995;
UPDATE `gameobject` SET `rotation0`=-0.0131168, `rotation1`=-0.0416002, `rotation2`=0.944602, `rotation3`=0.325307 WHERE `guid`=65996;
UPDATE `gameobject` SET `rotation0`=0.000907898, `rotation1`=0.0157042, `rotation2`=-0.999266, `rotation3`=0.0349386 WHERE `guid`=65997;
UPDATE `gameobject` SET `rotation0`=-0.0140967, `rotation1`=-0.0684423, `rotation2`=0.921273, `rotation3`=0.382587 WHERE `guid`=65998;
UPDATE `gameobject` SET `rotation0`=0.016243, `rotation1`=-0.0696001, `rotation2`=0.981966, `rotation3`=0.175028 WHERE `guid`=66000;
UPDATE `gameobject` SET `rotation0`=0.0421166, `rotation1`=0.0615225, `rotation2`=-0.997213, `rotation3`=0.00258374 WHERE `guid`=66001;
UPDATE `gameobject` SET `rotation0`=0.100891, `rotation1`=0.0733604, `rotation2`=-0.95587, `rotation3`=0.265993 WHERE `guid`=66003;
UPDATE `gameobject` SET `rotation0`=-0.0622897, `rotation1`=-0.0891228, `rotation2`=0.982732, `rotation3`=0.149717 WHERE `guid`=66004;
UPDATE `gameobject` SET `rotation0`=-0.0458646, `rotation1`=-0.122612, `rotation2`=0.986681, `rotation3`=0.0965575 WHERE `guid`=66007;
UPDATE `gameobject` SET `rotation0`=0.063015, `rotation1`=-0.264695, `rotation2`=0.473343, `rotation3`=0.837802 WHERE `guid`=66013;
UPDATE `gameobject` SET `rotation0`=-0.160909, `rotation1`=0.156031, `rotation2`=0.449443, `rotation3`=0.864733 WHERE `guid`=66014;
UPDATE `gameobject` SET `rotation0`=-0.0372086, `rotation1`=-0.0788364, `rotation2`=0.991509, `rotation3`=0.0964853 WHERE `guid`=66017;
UPDATE `gameobject` SET `rotation0`=-0.061204, `rotation1`=-0.0995245, `rotation2`=-0.992772, `rotation3`=0.0274319 WHERE `guid`=66019;
UPDATE `gameobject` SET `rotation0`=-0.0430837, `rotation1`=-0.0871992, `rotation2`=0.892773, `rotation3`=0.439883 WHERE `guid`=66022;
UPDATE `gameobject` SET `rotation0`=-0.0744286, `rotation1`=-0.0784407, `rotation2`=0.956942, `rotation3`=0.269389 WHERE `guid`=66026;
UPDATE `gameobject` SET `rotation0`=-0.532122, `rotation1`=0.436562, `rotation2`=0.67231, `rotation3`=0.272507 WHERE `guid`=66028;
UPDATE `gameobject` SET `rotation0`=0.330425, `rotation1`=-0.255406, `rotation2`=-0.350611, `rotation3`=0.838248 WHERE `guid`=66030;
UPDATE `gameobject` SET `rotation0`=0.0748539, `rotation1`=0.0447206, `rotation2`=-0.892179, `rotation3`=0.443185 WHERE `guid`=66032;
UPDATE `gameobject` SET `rotation0`=0.134146, `rotation1`=-0.29005, `rotation2`=0.477654, `rotation3`=0.818366 WHERE `guid`=66034;
UPDATE `gameobject` SET `rotation0`=0.0793948, `rotation1`=-0.0132055, `rotation2`=-0.277456, `rotation3`=0.957361 WHERE `guid`=66036;
UPDATE `gameobject` SET `rotation0`=-0.0776229, `rotation1`=-0.225336, `rotation2`=0.951262, `rotation3`=0.195699 WHERE `guid`=66041;
UPDATE `gameobject` SET `rotation0`=-0.227892, `rotation1`=-0.129869, `rotation2`=0.894956, `rotation3`=0.360907 WHERE `guid`=66042;
UPDATE `gameobject` SET `rotation0`=-0.135084, `rotation1`=-0.206245, `rotation2`=0.939968, `rotation3`=0.235956 WHERE `guid`=66043;
UPDATE `gameobject` SET `rotation0`=-0.0180907, `rotation1`=-0.137054, `rotation2`=0.974839, `rotation3`=0.174864 WHERE `guid`=66044;
UPDATE `gameobject` SET `rotation0`=-0.0368748, `rotation1`=-0.0735445, `rotation2`=0.932367, `rotation3`=0.352026 WHERE `guid`=66045;
UPDATE `gameobject` SET `rotation0`=-0.0445237, `rotation1`=-0.104994, `rotation2`=0.993466, `rotation3`=0.00429854 WHERE `guid`=66046;
UPDATE `gameobject` SET `rotation0`=-0.0406528, `rotation1`=-0.150936, `rotation2`=0.906446, `rotation3`=0.392327 WHERE `guid`=66049;
UPDATE `gameobject` SET `rotation0`=-0.016573, `rotation1`=-0.0207224, `rotation2`=0.992234, `rotation3`=0.12152 WHERE `guid`=66051;
UPDATE `gameobject` SET `rotation0`=0.0159388, `rotation1`=-0.0696707, `rotation2`=0.981193, `rotation3`=0.179313 WHERE `guid`=66055;
UPDATE `gameobject` SET `rotation0`=0.0182266, `rotation1`=-0.116857, `rotation2`=0.992917, `rotation3`=0.0113151 WHERE `guid`=66057;
UPDATE `gameobject` SET `rotation0`=-0.0114007, `rotation1`=-0.115683, `rotation2`=0.981917, `rotation3`=0.149418 WHERE `guid`=66059;
UPDATE `gameobject` SET `rotation0`=-0.001297, `rotation1`=0.00416565, `rotation2`=0.329686, `rotation3`=0.94408 WHERE `guid`=66065;
UPDATE `gameobject` SET `rotation0`=-0.00108576, `rotation1`=-0.0292311, `rotation2`=0.766356, `rotation3`=0.64175 WHERE `guid`=66230;
UPDATE `gameobject` SET `rotation0`=-0.163696, `rotation1`=-0.0698996, `rotation2`=0.384427, `rotation3`=0.905833 WHERE `guid`=66259;
UPDATE `gameobject` SET `rotation0`=0.00430059, `rotation1`=0.00416565, `rotation2`=0.390713, `rotation3`=0.920493 WHERE `guid`=66260;
UPDATE `gameobject` SET `rotation0`=-0.00366974, `rotation1`=-0.00235939, `rotation2`=0.998839, `rotation3`=0.0479673 WHERE `guid`=66261;
UPDATE `gameobject` SET `rotation0`=-0.0187707, `rotation1`=-0.0138149, `rotation2`=0.544464, `rotation3`=0.83846 WHERE `guid`=66292;
UPDATE `gameobject` SET `rotation0`=0.0881805, `rotation1`=0.10418, `rotation2`=-0.501834, `rotation3`=0.854127 WHERE `guid`=66294;
UPDATE `gameobject` SET `rotation0`=0.0342517, `rotation1`=0.161542, `rotation2`=-0.986255, `rotation3`=0.00571519 WHERE `guid`=66295;
UPDATE `gameobject` SET `rotation0`=0.0212288, `rotation1`=0.0050211, `rotation2`=-0.999762, `rotation3`=0 WHERE `guid`=66296;
UPDATE `gameobject` SET `rotation0`=0.0207849, `rotation1`=0.00662231, `rotation2`=-0.999762, `rotation3`=0 WHERE `guid`=66297;
UPDATE `gameobject` SET `rotation0`=0.0415297, `rotation1`=0.0674372, `rotation2`=-0.27634, `rotation3`=0.957791 WHERE `guid`=66298;
UPDATE `gameobject` SET `rotation0`=0.0253768, `rotation1`=0.0393915, `rotation2`=-0.558539, `rotation3`=0.828153 WHERE `guid`=66299;
UPDATE `gameobject` SET `rotation0`=0.00339794, `rotation1`=0.0219831, `rotation2`=-0.876394, `rotation3`=0.48108 WHERE `guid`=66300;
UPDATE `gameobject` SET `rotation0`=-0.000585556, `rotation1`=-0.00614262, `rotation2`=-0.731327, `rotation3`=0.681999 WHERE `guid`=66301;
UPDATE `gameobject` SET `rotation0`=0.0589747, `rotation1`=0.0545664, `rotation2`=0.516011, `rotation3`=0.852805 WHERE `guid`=66302;
UPDATE `gameobject` SET `rotation0`=-0.0773177, `rotation1`=-0.035183, `rotation2`=0.572569, `rotation3`=0.815444 WHERE `guid`=66306;
UPDATE `gameobject` SET `rotation0`=0.0761347, `rotation1`=-0.0631371, `rotation2`=-0.989244, `rotation3`=0.107771 WHERE `guid`=66307;
UPDATE `gameobject` SET `rotation0`=0.00338888, `rotation1`=-0.0142326, `rotation2`=-0.913431, `rotation3`=0.40673 WHERE `guid`=66345;
UPDATE `gameobject` SET `rotation0`=-0.00172472, `rotation1`=-0.0225382, `rotation2`=-0.913224, `rotation3`=0.40683 WHERE `guid`=66347;
UPDATE `gameobject` SET `rotation0`=-0.00615454, `rotation1`=-0.00928211, `rotation2`=-0.722301, `rotation3`=0.69149 WHERE `guid`=66349;
UPDATE `gameobject` SET `rotation0`=-0.00608587, `rotation1`=-0.0101986, `rotation2`=-0.913453, `rotation3`=0.406771 WHERE `guid`=66354;
UPDATE `gameobject` SET `rotation0`=0.0448937, `rotation1`=-0.154575, `rotation2`=0.502752, `rotation3`=0.849312 WHERE `guid`=66355;
UPDATE `gameobject` SET `rotation0`=0.014133, `rotation1`=-0.00137234, `rotation2`=-0.931943, `rotation3`=0.362327 WHERE `guid`=66357;
UPDATE `gameobject` SET `rotation0`=-0.0129566, `rotation1`=0.00283623, `rotation2`=0.350251, `rotation3`=0.936562 WHERE `guid`=66366;
UPDATE `gameobject` SET `rotation0`=0.00392294, `rotation1`=0.00371265, `rotation2`=0.922192, `rotation3`=0.386696 WHERE `guid`=66375;
UPDATE `gameobject` SET `rotation0`=0.0300908, `rotation1`=-0.0217514, `rotation2`=0.99931, `rotation3`=0.00135932 WHERE `guid`=66406;
UPDATE `gameobject` SET `rotation0`=0.0405688, `rotation1`=0.0204649, `rotation2`=0.966308, `rotation3`=0.253347 WHERE `guid`=66407;
UPDATE `gameobject` SET `rotation0`=0.0554385, `rotation1`=0.0817881, `rotation2`=-0.129504, `rotation3`=0.986644 WHERE `guid`=66408;
UPDATE `gameobject` SET `rotation0`=-0.00613165, `rotation1`=0.0583906, `rotation2`=-0.707772, `rotation3`=0.703997 WHERE `guid`=66409;
UPDATE `gameobject` SET `rotation0`=-0.464443, `rotation1`=0.499267, `rotation2`=-0.661067, `rotation3`=0.313075 WHERE `guid`=66412;
UPDATE `gameobject` SET `rotation0`=-0.0148516, `rotation1`=0.0269852, `rotation2`=-0.926785, `rotation3`=0.374326 WHERE `guid`=66413;
UPDATE `gameobject` SET `rotation0`=-0.00749159, `rotation1`=0.0298777, `rotation2`=-0.991548, `rotation3`=0.126034 WHERE `guid`=66414;
UPDATE `gameobject` SET `rotation0`=0.031075, `rotation1`=-0.0419874, `rotation2`=0.998633, `rotation3`=0.00167374 WHERE `guid`=66415;
UPDATE `gameobject` SET `rotation0`=-0.0140429, `rotation1`=-0.00888062, `rotation2`=0.998916, `rotation3`=0.0434899 WHERE `guid`=66620;
UPDATE `gameobject` SET `rotation0`=0.00558281, `rotation1`=0.0118389, `rotation2`=0.845644, `rotation3`=0.533587 WHERE `guid`=66621;
UPDATE `gameobject` SET `rotation0`=-0.00416994, `rotation1`=-0.000220299, `rotation2`=0.998126, `rotation3`=0.0610488 WHERE `guid`=66622;
UPDATE `gameobject` SET `rotation0`=-0.00070858, `rotation1`=-0.00169086, `rotation2`=-0.740215, `rotation3`=0.672367 WHERE `guid`=66633;
UPDATE `gameobject` SET `rotation0`=-0.00752497, `rotation1`=-0.0114594, `rotation2`=-0.710091, `rotation3`=0.703977 WHERE `guid`=66634;
UPDATE `gameobject` SET `rotation0`=0.0395589, `rotation1`=-0.0160465, `rotation2`=-0.537083, `rotation3`=0.842449 WHERE `guid`=66807;
UPDATE `gameobject` SET `rotation0`=-0.00543785, `rotation1`=0.00140572, `rotation2`=-0.424541, `rotation3`=0.905391 WHERE `guid`=67445;
UPDATE `gameobject` SET `rotation0`=0.0245037, `rotation1`=0.0558653, `rotation2`=-0.984365, `rotation3`=0.165237 WHERE `guid`=67824;
UPDATE `gameobject` SET `rotation0`=0.457502, `rotation1`=0.879879, `rotation2`=-0.128418, `rotation3`=0.00371864 WHERE `guid`=67825;
UPDATE `gameobject` SET `rotation0`=0.00501299, `rotation1`=-0.00453663, `rotation2`=-0.177918, `rotation3`=0.984022 WHERE `guid`=67827;
UPDATE `gameobject` SET `rotation0`=-0.00782394, `rotation1`=0.00386524, `rotation2`=0.894899, `rotation3`=0.446183 WHERE `guid`=67968;
UPDATE `gameobject` SET `rotation0`=0.0222769, `rotation1`=-0.035924, `rotation2`=-0.82086, `rotation3`=0.569563 WHERE `guid`=71411;
UPDATE `gameobject` SET `rotation0`=0.0167089, `rotation1`=0.0073185, `rotation2`=0.337838, `rotation3`=0.941027 WHERE `guid`=71412;
UPDATE `gameobject` SET `rotation0`=0.895853, `rotation1`=0.375089, `rotation2`=-0.234593, `rotation3`=0.0414939 WHERE `guid`=71429;
UPDATE `gameobject` SET `rotation0`=0.0133057, `rotation1`=0.00767422, `rotation2`=-0.894822, `rotation3`=0.446159 WHERE `guid`=71431;
UPDATE `gameobject` SET `rotation0`=0.107768, `rotation1`=-0.24586, `rotation2`=0.963281, `rotation3`=0.00540979 WHERE `guid`=71432;
UPDATE `gameobject` SET `rotation0`=-0.0531387, `rotation1`=0.608887, `rotation2`=-0.606519, `rotation3`=0.508496 WHERE `guid`=71433;
UPDATE `gameobject` SET `rotation0`=0.217795, `rotation1`=0.271523, `rotation2`=0.450282, `rotation3`=0.822245 WHERE `guid`=76924;
UPDATE `gameobject` SET `rotation0`=-0.0121818, `rotation1`=-0.00647736, `rotation2`=-0.0524149, `rotation3`=0.99853 WHERE `guid`=76935;
UPDATE `gameobject` SET `rotation0`=-0.0568476, `rotation1`=0.0184574, `rotation2`=0.759868, `rotation3`=0.647324 WHERE `guid`=76963;
UPDATE `gameobject` SET `rotation0`=0.0264506, `rotation1`=-0.0387974, `rotation2`=0.794722, `rotation3`=0.605155 WHERE `guid`=76980;
UPDATE `gameobject` SET `rotation0`=0.00446081, `rotation1`=0.00867653, `rotation2`=0.958778, `rotation3`=0.283987 WHERE `guid`=76990;
UPDATE `gameobject` SET `rotation0`=-0.00244474, `rotation1`=-0.0307484, `rotation2`=0.0704784, `rotation3`=0.997036 WHERE `guid`=76994;
UPDATE `gameobject` SET `rotation0`=0.301799, `rotation1`=0.559454, `rotation2`=0.663756, `rotation3`=0.394152 WHERE `guid`=77005;
UPDATE `gameobject` SET `rotation0`=0.0638885, `rotation1`=-0.00834465, `rotation2`=0.871384, `rotation3`=0.486353 WHERE `guid`=77006;
UPDATE `gameobject` SET `rotation0`=0.529439, `rotation1`=-0.0826683, `rotation2`=-0.282406, `rotation3`=0.79568 WHERE `guid`=77007;
UPDATE `gameobject` SET `rotation0`=0.0796647, `rotation1`=0.0144062, `rotation2`=-0.000888824, `rotation3`=0.996717 WHERE `guid`=77008;
UPDATE `gameobject` SET `rotation0`=0.0790286, `rotation1`=-0.017458, `rotation2`=-0.418527, `rotation3`=0.904591 WHERE `guid`=77009;
UPDATE `gameobject` SET `rotation0`=0.0258098, `rotation1`=0.0587788, `rotation2`=0.790161, `rotation3`=0.609528 WHERE `guid`=77010;
UPDATE `gameobject` SET `rotation0`=-0.000017643, `rotation1`=0.000310898, `rotation2`=0.465845, `rotation3`=0.884866 WHERE `guid`=77011;
UPDATE `gameobject` SET `rotation0`=-0.00913286, `rotation1`=-0.0617018, `rotation2`=0.944452, `rotation3`=0.322675 WHERE `guid`=77012;
UPDATE `gameobject` SET `rotation0`=-0.0715327, `rotation1`=-0.0109978, `rotation2`=0.860805, `rotation3`=0.503763 WHERE `guid`=77013;
UPDATE `gameobject` SET `rotation0`=0.0488257, `rotation1`=0.0519066, `rotation2`=0.704068, `rotation3`=0.706548 WHERE `guid`=77014;
UPDATE `gameobject` SET `rotation0`=0.0600896, `rotation1`=-0.0089817, `rotation2`=-0.643221, `rotation3`=0.763266 WHERE `guid`=77015;
UPDATE `gameobject` SET `rotation0`=0.117878, `rotation1`=0.0288877, `rotation2`=-0.852855, `rotation3`=0.507847 WHERE `guid`=77016;
UPDATE `gameobject` SET `rotation0`=0.175502, `rotation1`=-0.0696192, `rotation2`=-0.835915, `rotation3`=0.515363 WHERE `guid`=77017;
UPDATE `gameobject` SET `rotation0`=-0.10428, `rotation1`=0.0728397, `rotation2`=0.523499, `rotation3`=0.842478 WHERE `guid`=77018;
UPDATE `gameobject` SET `rotation0`=-0.146883, `rotation1`=0.106271, `rotation2`=-0.919187, `rotation3`=0.349611 WHERE `guid`=77019;
UPDATE `gameobject` SET `rotation0`=-0.0967536, `rotation1`=0.0623951, `rotation2`=-0.112823, `rotation3`=0.986923 WHERE `guid`=77020;
UPDATE `gameobject` SET `rotation0`=0.121423, `rotation1`=0.0109167, `rotation2`=-0.951202, `rotation3`=0.283463 WHERE `guid`=77021;
UPDATE `gameobject` SET `rotation0`=0.0474486, `rotation1`=-0.0568333, `rotation2`=-0.225662, `rotation3`=0.971388 WHERE `guid`=77022;
UPDATE `gameobject` SET `rotation0`=-0.0137296, `rotation1`=0.00334263, `rotation2`=-0.985821, `rotation3`=0.167206 WHERE `guid`=77023;
UPDATE `gameobject` SET `rotation0`=-0.0574636, `rotation1`=-0.0339718, `rotation2`=-0.0337629, `rotation3`=0.997198 WHERE `guid`=77024;
UPDATE `gameobject` SET `rotation0`=0.119032, `rotation1`=-0.042861, `rotation2`=-0.775682, `rotation3`=0.618313 WHERE `guid`=77025;
UPDATE `gameobject` SET `rotation0`=0.013063, `rotation1`=0.123156, `rotation2`=0.888981, `rotation3`=0.44088 WHERE `guid`=77026;
UPDATE `gameobject` SET `rotation0`=-0.0474277, `rotation1`=0.038497, `rotation2`=0.904352, `rotation3`=0.422393 WHERE `guid`=77027;
UPDATE `gameobject` SET `rotation0`=-0.0808988, `rotation1`=0.00173664, `rotation2`=0.666332, `rotation3`=0.741251 WHERE `guid`=77028;
UPDATE `gameobject` SET `rotation0`=0.00607967, `rotation1`=-0.0487633, `rotation2`=0.0698023, `rotation3`=0.99635 WHERE `guid`=77029;
UPDATE `gameobject` SET `rotation0`=0.0470619, `rotation1`=0.0384197, `rotation2`=-0.997312, `rotation3`=0.040972 WHERE `guid`=77030;
UPDATE `gameobject` SET `rotation0`=0.176649, `rotation1`=-0.0290623, `rotation2`=-0.343566, `rotation3`=0.921907 WHERE `guid`=77031;
UPDATE `gameobject` SET `rotation0`=0.0263929, `rotation1`=0.121001, `rotation2`=0.8357, `rotation3`=0.53504 WHERE `guid`=77032;
UPDATE `gameobject` SET `rotation0`=-0.0216947, `rotation1`=-0.022048, `rotation2`=0.748631, `rotation3`=0.662265 WHERE `guid`=77033;
UPDATE `gameobject` SET `rotation0`=0.0561199, `rotation1`=-0.110401, `rotation2`=-0.985682, `rotation3`=0.114429 WHERE `guid`=77034;
UPDATE `gameobject` SET `rotation0`=-0.0579057, `rotation1`=0.0194483, `rotation2`=0.995007, `rotation3`=0.0789345 WHERE `guid`=77035;
UPDATE `gameobject` SET `rotation0`=0.107849, `rotation1`=0.0608816, `rotation2`=0.157308, `rotation3`=0.979753 WHERE `guid`=77036;
UPDATE `gameobject` SET `rotation0`=-0.0570979, `rotation1`=0.0217075, `rotation2`=0.99114, `rotation3`=0.117938 WHERE `guid`=77037;
UPDATE `gameobject` SET `rotation0`=0.0903859, `rotation1`=-0.0419741, `rotation2`=-0.412563, `rotation3`=0.905461 WHERE `guid`=77038;
UPDATE `gameobject` SET `rotation0`=0.104919, `rotation1`=0.0612249, `rotation2`=-0.685961, `rotation3`=0.717427 WHERE `guid`=77039;
UPDATE `gameobject` SET `rotation0`=0.105379, `rotation1`=0.0258522, `rotation2`=-0.58182, `rotation3`=0.806047 WHERE `guid`=77040;
UPDATE `gameobject` SET `rotation0`=-0.0350347, `rotation1`=-0.007514, `rotation2`=0.840987, `rotation3`=0.539867 WHERE `guid`=77041;
UPDATE `gameobject` SET `rotation0`=0.0236607, `rotation1`=0.0528755, `rotation2`=-0.892694, `rotation3`=0.446924 WHERE `guid`=77042;
UPDATE `gameobject` SET `rotation0`=-0.0387049, `rotation1`=-0.120429, `rotation2`=-0.273579, `rotation3`=0.953495 WHERE `guid`=77045;
UPDATE `gameobject` SET `rotation0`=-0.0990119, `rotation1`=-0.0587473, `rotation2`=0.83289, `rotation3`=0.541332 WHERE `guid`=77047;
UPDATE `gameobject` SET `rotation0`=0.0436177, `rotation1`=0.0427647, `rotation2`=-0.522051, `rotation3`=0.850724 WHERE `guid`=77048;
UPDATE `gameobject` SET `rotation0`=0.0664639, `rotation1`=-0.0326204, `rotation2`=0.188945, `rotation3`=0.979193 WHERE `guid`=77049;
UPDATE `gameobject` SET `rotation0`=-0.0246377, `rotation1`=-0.0620403, `rotation2`=0.583806, `rotation3`=0.809144 WHERE `guid`=77050;
UPDATE `gameobject` SET `rotation0`=0.0298905, `rotation1`=-0.0326824, `rotation2`=0.791899, `rotation3`=0.609044 WHERE `guid`=77051;
UPDATE `gameobject` SET `rotation0`=0.0402436, `rotation1`=-0.0483112, `rotation2`=0.956863, `rotation3`=0.283653 WHERE `guid`=77052;
UPDATE `gameobject` SET `rotation0`=0.063242, `rotation1`=0.0197554, `rotation2`=-0.162605, `rotation3`=0.984464 WHERE `guid`=77053;
UPDATE `gameobject` SET `rotation0`=0.0239267, `rotation1`=0.0582066, `rotation2`=-0.92025, `rotation3`=0.386238 WHERE `guid`=77054;
UPDATE `gameobject` SET `rotation0`=0.0541716, `rotation1`=0.0323639, `rotation2`=-0.245821, `rotation3`=0.967259 WHERE `guid`=77055;
UPDATE `gameobject` SET `rotation0`=-0.00713873, `rotation1`=-0.0216646, `rotation2`=-0.243133, `rotation3`=0.969725 WHERE `guid`=77056;
UPDATE `gameobject` SET `rotation0`=-0.126151, `rotation1`=0.0901117, `rotation2`=-0.923634, `rotation3`=0.350524 WHERE `guid`=77057;
UPDATE `gameobject` SET `rotation0`=-0.0150366, `rotation1`=-0.0171528, `rotation2`=-0.602707, `rotation3`=0.797637 WHERE `guid`=77058;
UPDATE `gameobject` SET `rotation0`=0.00825453, `rotation1`=-0.0623331, `rotation2`=0.657885, `rotation3`=0.750489 WHERE `guid`=77059;
UPDATE `gameobject` SET `rotation0`=-0.000444889, `rotation1`=-0.0317888, `rotation2`=0.999405, `rotation3`=0.0133833 WHERE `guid`=77061;
UPDATE `gameobject` SET `rotation0`=-0.0266786, `rotation1`=-0.0172901, `rotation2`=0.544106, `rotation3`=0.838414 WHERE `guid`=77062;
UPDATE `gameobject` SET `rotation0`=0.0752997, `rotation1`=-0.0983257, `rotation2`=-0.948325, `rotation3`=0.292132 WHERE `guid`=77063;
UPDATE `gameobject` SET `rotation0`=0.0610685, `rotation1`=-0.00140285, `rotation2`=-0.973658, `rotation3`=0.219681 WHERE `guid`=77064;
UPDATE `gameobject` SET `rotation0`=0.10274, `rotation1`=0.0691566, `rotation2`=0.233692, `rotation3`=0.964391 WHERE `guid`=77065;
UPDATE `gameobject` SET `rotation0`=-0.00709391, `rotation1`=0.0064373, `rotation2`=-0.337871, `rotation3`=0.941144 WHERE `guid`=77066;
UPDATE `gameobject` SET `rotation0`=-0.00249577, `rotation1`=-0.00319576, `rotation2`=-0.374365, `rotation3`=0.927273 WHERE `guid`=77067;
UPDATE `gameobject` SET `rotation0`=-0.0212216, `rotation1`=-0.00836372, `rotation2`=-0.901033, `rotation3`=0.43315 WHERE `guid`=77068;
UPDATE `gameobject` SET `rotation0`=-0.0304646, `rotation1`=-0.00535011, `rotation2`=0.224893, `rotation3`=0.973893 WHERE `guid`=77069;
UPDATE `gameobject` SET `rotation0`=0.0292087, `rotation1`=0.0536489, `rotation2`=-0.250513, `rotation3`=0.966184 WHERE `guid`=77070;
UPDATE `gameobject` SET `rotation0`=0.0301409, `rotation1`=0.0531301, `rotation2`=-0.267338, `rotation3`=0.961665 WHERE `guid`=77071;
UPDATE `gameobject` SET `rotation0`=0.00539398, `rotation1`=0.0608454, `rotation2`=0.155528, `rotation3`=0.985941 WHERE `guid`=77072;
UPDATE `gameobject` SET `rotation0`=-0.030252, `rotation1`=0.00645065, `rotation2`=-0.156309, `rotation3`=0.987224 WHERE `guid`=77073;
UPDATE `gameobject` SET `rotation0`=-0.0722237, `rotation1`=-0.103849, `rotation2`=-0.5404, `rotation3`=0.831846 WHERE `guid`=77074;
UPDATE `gameobject` SET `rotation0`=-0.111862, `rotation1`=-0.0272312, `rotation2`=0.638226, `rotation3`=0.761192 WHERE `guid`=77075;
UPDATE `gameobject` SET `rotation0`=0.0662546, `rotation1`=0.000401497, `rotation2`=-0.44333, `rotation3`=0.893906 WHERE `guid`=77076;
UPDATE `gameobject` SET `rotation0`=0.0209198, `rotation1`=-0.00909042, `rotation2`=0.943409, `rotation3`=0.330846 WHERE `guid`=77077;
UPDATE `gameobject` SET `rotation0`=0.0432615, `rotation1`=-0.116046, `rotation2`=-0.992298, `rotation3`=0.00248976 WHERE `guid`=77078;
UPDATE `gameobject` SET `rotation0`=-0.017314, `rotation1`=-0.0256319, `rotation2`=0.856783, `rotation3`=0.514749 WHERE `guid`=77079;
UPDATE `gameobject` SET `rotation0`=0.0752997, `rotation1`=-0.0983257, `rotation2`=-0.948325, `rotation3`=0.292132 WHERE `guid`=77080;
UPDATE `gameobject` SET `rotation0`=-0.0569057, `rotation1`=0.0222044, `rotation2`=0.990073, `rotation3`=0.126585 WHERE `guid`=77081;
UPDATE `gameobject` SET `rotation0`=-0.0347595, `rotation1`=0.0502291, `rotation2`=0.750026, `rotation3`=0.658582 WHERE `guid`=77082;
UPDATE `gameobject` SET `rotation0`=0.054215, `rotation1`=0.0281439, `rotation2`=-0.747968, `rotation3`=0.660918 WHERE `guid`=77084;
UPDATE `gameobject` SET `rotation0`=-0.0417008, `rotation1`=-0.0521269, `rotation2`=0.321725, `rotation3`=0.944477 WHERE `guid`=77085;
UPDATE `gameobject` SET `rotation0`=0.0398989, `rotation1`=0.0486679, `rotation2`=-0.992964, `rotation3`=0.100311 WHERE `guid`=77086;
UPDATE `gameobject` SET `rotation0`=0.0630999, `rotation1`=0.000666618, `rotation2`=-0.699629, `rotation3`=0.711714 WHERE `guid`=77087;
UPDATE `gameobject` SET `rotation0`=-0.0131607, `rotation1`=-0.018631, `rotation2`=-0.516029, `rotation3`=0.856267 WHERE `guid`=77088;
UPDATE `gameobject` SET `rotation0`=-0.0579896, `rotation1`=0.0191956, `rotation2`=0.995341, `rotation3`=0.0745953 WHERE `guid`=77089;
UPDATE `gameobject` SET `rotation0`=0.122504, `rotation1`=0.0181885, `rotation2`=-0.204252, `rotation3`=0.971053 WHERE `guid`=77090;
UPDATE `gameobject` SET `rotation0`=-0.00862169, `rotation1`=-0.0253086, `rotation2`=0.382218, `rotation3`=0.923685 WHERE `guid`=77091;
UPDATE `gameobject` SET `rotation0`=-0.00204277, `rotation1`=0.12383, `rotation2`=0.936084, `rotation3`=0.329255 WHERE `guid`=77092;
UPDATE `gameobject` SET `rotation0`=-0.0325356, `rotation1`=0.0516987, `rotation2`=0.720584, `rotation3`=0.690672 WHERE `guid`=77093;
UPDATE `gameobject` SET `rotation0`=0.117485, `rotation1`=0.0391846, `rotation2`=-0.0325279, `rotation3`=0.991768 WHERE `guid`=77094;
UPDATE `gameobject` SET `rotation0`=-0.0286865, `rotation1`=-0.0115671, `rotation2`=0.422462, `rotation3`=0.905853 WHERE `guid`=77095;
UPDATE `gameobject` SET `rotation0`=-0.0347595, `rotation1`=0.0502291, `rotation2`=0.750026, `rotation3`=0.658582 WHERE `guid`=77096;
UPDATE `gameobject` SET `rotation0`=0.115664, `rotation1`=0.0442724, `rotation2`=0.0107622, `rotation3`=0.992243 WHERE `guid`=77098;
UPDATE `gameobject` SET `rotation0`=0.0202045, `rotation1`=0.0576458, `rotation2`=-0.0919485, `rotation3`=0.993888 WHERE `guid`=77100;
UPDATE `gameobject` SET `rotation0`=-0.0240259, `rotation1`=0.0194817, `rotation2`=-0.587462, `rotation3`=0.80866 WHERE `guid`=77101;
UPDATE `gameobject` SET `rotation0`=0.104515, `rotation1`=0.0664425, `rotation2`=0.208368, `rotation3`=0.970178 WHERE `guid`=77102;
UPDATE `gameobject` SET `rotation0`=-0.0216928, `rotation1`=-0.00705242, `rotation2`=-0.925796, `rotation3`=0.377336 WHERE `guid`=77103;
UPDATE `gameobject` SET `rotation0`=-0.0108008, `rotation1`=0.0601225, `rotation2`=0.409385, `rotation3`=0.910315 WHERE `guid`=77104;
UPDATE `gameobject` SET `rotation0`=0.0947957, `rotation1`=-0.0796976, `rotation2`=-0.862617, `rotation3`=0.490464 WHERE `guid`=77105;
UPDATE `gameobject` SET `rotation0`=-0.0227056, `rotation1`=-0.00477314, `rotation2`=-0.902395, `rotation3`=0.430284 WHERE `guid`=77106;
UPDATE `gameobject` SET `rotation0`=0.112294, `rotation1`=0.0522327, `rotation2`=0.0799513, `rotation3`=0.989075 WHERE `guid`=77107;
UPDATE `gameobject` SET `rotation0`=-0.056201, `rotation1`=0.0239315, `rotation2`=0.985746, `rotation3`=0.156757 WHERE `guid`=77108;
UPDATE `gameobject` SET `rotation0`=-0.0557747, `rotation1`=0.02491, `rotation2`=0.982861, `rotation3`=0.173936 WHERE `guid`=77109;
UPDATE `gameobject` SET `rotation0`=0.0610828, `rotation1`=0.000462532, `rotation2`=-0.966495, `rotation3`=0.249313 WHERE `guid`=77110;
UPDATE `gameobject` SET `rotation0`=-0.00352192, `rotation1`=-0.0307302, `rotation2`=0.99766, `rotation3`=0.0609785 WHERE `guid`=77111;
UPDATE `gameobject` SET `rotation0`=0.00512791, `rotation1`=0.0608683, `rotation2`=0.159828, `rotation3`=0.985253 WHERE `guid`=77112;
UPDATE `gameobject` SET `rotation0`=-0.012002, `rotation1`=0.00661659, `rotation2`=-0.896828, `rotation3`=0.442168 WHERE `guid`=77113;
UPDATE `gameobject` SET `rotation0`=0.123432, `rotation1`=0.0101376, `rotation2`=-0.267324, `rotation3`=0.955615 WHERE `guid`=77115;
UPDATE `gameobject` SET `rotation0`=0.0494599, `rotation1`=0.0358477, `rotation2`=-0.642063, `rotation3`=0.764214 WHERE `guid`=77116;
UPDATE `gameobject` SET `rotation0`=0.0607848, `rotation1`=0.00604916, `rotation2`=-0.939628, `rotation3`=0.336702 WHERE `guid`=77117;
UPDATE `gameobject` SET `rotation0`=0.018436, `rotation1`=0.0582361, `rotation2`=-0.0615549, `rotation3`=0.996233 WHERE `guid`=77118;
UPDATE `gameobject` SET `rotation0`=0.0467849, `rotation1`=-0.11467, `rotation2`=-0.991772, `rotation3`=0.0324174 WHERE `guid`=77119;
UPDATE `gameobject` SET `rotation0`=-0.00744295, `rotation1`=0.123623, `rotation2`=0.949555, `rotation3`=0.288109 WHERE `guid`=77120;
UPDATE `gameobject` SET `rotation0`=-0.00286865, `rotation1`=0.0480499, `rotation2`=-0.0607004, `rotation3`=0.996995 WHERE `guid`=77121;
UPDATE `gameobject` SET `rotation0`=0.0481787, `rotation1`=0.0375519, `rotation2`=-0.615001, `rotation3`=0.786157 WHERE `guid`=77122;
UPDATE `gameobject` SET `rotation0`=0.0488267, `rotation1`=0.036706, `rotation2`=-0.628628, `rotation3`=0.775304 WHERE `guid`=77123;
UPDATE `gameobject` SET `rotation0`=0.0292087, `rotation1`=0.0536489, `rotation2`=-0.250513, `rotation3`=0.966184 WHERE `guid`=77124;
UPDATE `gameobject` SET `rotation0`=-0.013176, `rotation1`=0.0279846, `rotation2`=-0.880445, `rotation3`=0.473139 WHERE `guid`=77125;
UPDATE `gameobject` SET `rotation0`=-0.0131526, `rotation1`=0.0596514, `rotation2`=0.444809, `rotation3`=0.89354 WHERE `guid`=77126;
UPDATE `gameobject` SET `rotation0`=0.0433717, `rotation1`=0.0282393, `rotation2`=-0.960958, `rotation3`=0.271813 WHERE `guid`=77127;
UPDATE `gameobject` SET `rotation0`=0.0501857, `rotation1`=-0.00143909, `rotation2`=-0.956716, `rotation3`=0.286661 WHERE `guid`=77128;
UPDATE `gameobject` SET `rotation0`=0.0460067, `rotation1`=0.0250292, `rotation2`=-0.89929, `rotation3`=0.434205 WHERE `guid`=77129;
UPDATE `gameobject` SET `rotation0`=-0.0043478, `rotation1`=-0.0223913, `rotation2`=-0.118811, `rotation3`=0.992655 WHERE `guid`=77130;
UPDATE `gameobject` SET `rotation0`=-0.0251698, `rotation1`=0.0179787, `rotation2`=-0.537, `rotation3`=0.843015 WHERE `guid`=77131;
UPDATE `gameobject` SET `rotation0`=-0.0507507, `rotation1`=0.0339947, `rotation2`=0.939208, `rotation3`=0.337871 WHERE `guid`=77132;
UPDATE `gameobject` SET `rotation0`=-0.0164309, `rotation1`=0.0143499, `rotation2`=-0.612422, `rotation3`=0.79023 WHERE `guid`=77133;
UPDATE `gameobject` SET `rotation0`=0.150003, `rotation1`=-0.0637999, `rotation2`=-0.505119, `rotation3`=0.847516 WHERE `guid`=77134;
UPDATE `gameobject` SET `rotation0`=0.00594473, `rotation1`=-0.00461292, `rotation2`=-0.170579, `rotation3`=0.985315 WHERE `guid`=77135;
UPDATE `gameobject` SET `rotation0`=0.0518498, `rotation1`=0.0100574, `rotation2`=-0.229643, `rotation3`=0.971841 WHERE `guid`=77136;
UPDATE `gameobject` SET `rotation0`=-0.00587082, `rotation1`=-0.0157957, `rotation2`=0.394556, `rotation3`=0.918717 WHERE `guid`=77137;
UPDATE `gameobject` SET `rotation0`=0.0170288, `rotation1`=0.0472221, `rotation2`=0.659506, `rotation3`=0.750021 WHERE `guid`=77138;
UPDATE `gameobject` SET `rotation0`=0.030128, `rotation1`=0.027483, `rotation2`=0.0691519, `rotation3`=0.996772 WHERE `guid`=77139;
UPDATE `gameobject` SET `rotation0`=0.0950837, `rotation1`=0.0810518, `rotation2`=-0.0570211, `rotation3`=0.990524 WHERE `guid`=77140;
UPDATE `gameobject` SET `rotation0`=0.0844626, `rotation1`=-0.139417, `rotation2`=-0.905103, `rotation3`=0.392706 WHERE `guid`=77141;
UPDATE `gameobject` SET `rotation0`=0.151325, `rotation1`=-0.118515, `rotation2`=-0.150674, `rotation3`=0.969718 WHERE `guid`=77142;
UPDATE `gameobject` SET `rotation0`=-0.0991616, `rotation1`=-0.199687, `rotation2`=0.920929, `rotation3`=0.319659 WHERE `guid`=77143;
UPDATE `gameobject` SET `rotation0`=0.207263, `rotation1`=-0.123673, `rotation2`=-0.118627, `rotation3`=0.963159 WHERE `guid`=77144;
UPDATE `gameobject` SET `rotation0`=0.0850377, `rotation1`=-0.117254, `rotation2`=0.617311, `rotation3`=0.773271 WHERE `guid`=77145;
UPDATE `gameobject` SET `rotation0`=0.111181, `rotation1`=-0.132936, `rotation2`=0.250117, `rotation3`=0.95258 WHERE `guid`=77146;
UPDATE `gameobject` SET `rotation0`=-0.0618968, `rotation1`=-0.172729, `rotation2`=0.751708, `rotation3`=0.633458 WHERE `guid`=77147;
UPDATE `gameobject` SET `rotation0`=0.329918, `rotation1`=-0.0781288, `rotation2`=-0.556777, `rotation3`=0.75832 WHERE `guid`=77148;
UPDATE `gameobject` SET `rotation0`=0.100191, `rotation1`=-0.175282, `rotation2`=0.773164, `rotation3`=0.601212 WHERE `guid`=77149;
UPDATE `gameobject` SET `rotation0`=0.206481, `rotation1`=0.0967264, `rotation2`=-0.923958, `rotation3`=0.307102 WHERE `guid`=77150;
UPDATE `gameobject` SET `rotation0`=0.254753, `rotation1`=0.0382614, `rotation2`=-0.822841, `rotation3`=0.506528 WHERE `guid`=77151;
UPDATE `gameobject` SET `rotation0`=-0.0221047, `rotation1`=-0.302703, `rotation2`=0.907742, `rotation3`=0.289634 WHERE `guid`=77152;
UPDATE `gameobject` SET `rotation0`=-0.0450306, `rotation1`=0.244809, `rotation2`=-0.821506, `rotation3`=0.513 WHERE `guid`=77157;
UPDATE `gameobject` SET `rotation0`=-0.0161185, `rotation1`=0.160583, `rotation2`=-0.973068, `rotation3`=0.164595 WHERE `guid`=77158;
UPDATE `gameobject` SET `rotation0`=-0.0171127, `rotation1`=-0.0166779, `rotation2`=-0.997555, `rotation3`=0.065677 WHERE `guid`=77159;
UPDATE `gameobject` SET `rotation0`=-0.00719595, `rotation1`=-0.0719738, `rotation2`=0.1419, `rotation3`=0.987235 WHERE `guid`=77160;
UPDATE `gameobject` SET `rotation0`=-0.00724554, `rotation1`=-0.0421524, `rotation2`=0.532355, `rotation3`=0.84544 WHERE `guid`=77161;
UPDATE `gameobject` SET `rotation0`=-0.0255208, `rotation1`=0.0302401, `rotation2`=-0.189908, `rotation3`=0.981004 WHERE `guid`=77162;
UPDATE `gameobject` SET `rotation0`=0.0435467, `rotation1`=-0.011776, `rotation2`=-0.852303, `rotation3`=0.5211 WHERE `guid`=77163;
UPDATE `gameobject` SET `rotation0`=-0.0274987, `rotation1`=0.0110216, `rotation2`=0.675546, `rotation3`=0.736723 WHERE `guid`=77164;
UPDATE `gameobject` SET `rotation0`=0.0167489, `rotation1`=-0.000976563, `rotation2`=0.457918, `rotation3`=0.888836 WHERE `guid`=77165;
UPDATE `gameobject` SET `rotation0`=0.0871139, `rotation1`=0.0415649, `rotation2`=0.890839, `rotation3`=0.443948 WHERE `guid`=77167;
UPDATE `gameobject` SET `rotation0`=0.0360966, `rotation1`=-0.0301628, `rotation2`=-0.845136, `rotation3`=0.532478 WHERE `guid`=77168;
UPDATE `gameobject` SET `rotation0`=0.089571, `rotation1`=-0.177974, `rotation2`=0.654187, `rotation3`=0.729617 WHERE `guid`=77174;
UPDATE `gameobject` SET `rotation0`=0.014946, `rotation1`=0.0937176, `rotation2`=0.917232, `rotation3`=0.386885 WHERE `guid`=77176;
UPDATE `gameobject` SET `rotation0`=0.107347, `rotation1`=-0.11599, `rotation2`=-0.80059, `rotation3`=0.577996 WHERE `guid`=77177;
UPDATE `gameobject` SET `rotation0`=0.0979347, `rotation1`=-0.0203876, `rotation2`=-0.907374, `rotation3`=0.408246 WHERE `guid`=77178;
UPDATE `gameobject` SET `rotation0`=0.0107517, `rotation1`=0.0785532, `rotation2`=0.764607, `rotation3`=0.639601 WHERE `guid`=77179;
UPDATE `gameobject` SET `rotation0`=0.0792899, `rotation1`=0.0916252, `rotation2`=0.283839, `rotation3`=0.951185 WHERE `guid`=77181;
UPDATE `gameobject` SET `rotation0`=-0.0802469, `rotation1`=0.152781, `rotation2`=0.968978, `rotation3`=0.176919 WHERE `guid`=77182;
UPDATE `gameobject` SET `rotation0`=0.00961256, `rotation1`=0.117995, `rotation2`=0.961841, `rotation3`=0.246673 WHERE `guid`=77183;
UPDATE `gameobject` SET `rotation0`=0.104968, `rotation1`=0.15615, `rotation2`=-0.58289, `rotation3`=0.790467 WHERE `guid`=77184;
UPDATE `gameobject` SET `rotation0`=0.0362058, `rotation1`=0.120889, `rotation2`=-0.777025, `rotation3`=0.61669 WHERE `guid`=77185;
UPDATE `gameobject` SET `rotation0`=0.0951447, `rotation1`=-0.0871191, `rotation2`=-0.991632, `rotation3`=0.00477168 WHERE `guid`=77186;
UPDATE `gameobject` SET `rotation0`=0.0418429, `rotation1`=0.0310535, `rotation2`=0.994143, `rotation3`=0.094686 WHERE `guid`=77188;
UPDATE `gameobject` SET `rotation0`=-0.019105, `rotation1`=0.0849142, `rotation2`=0.25337, `rotation3`=0.963446 WHERE `guid`=77189;
UPDATE `gameobject` SET `rotation0`=0.00263071, `rotation1`=0.0212584, `rotation2`=0.99977, `rotation3`=0 WHERE `guid`=87974;
UPDATE `gameobject` SET `rotation0`=-0.00499153, `rotation1`=-0.0433273, `rotation2`=-0.976177, `rotation3`=0.212546 WHERE `guid`=100099;
UPDATE `gameobject` SET `rotation0`=-0.0704336, `rotation1`=-0.0118895, `rotation2`=0.615775, `rotation3`=0.784678 WHERE `guid`=100111;
UPDATE `gameobject` SET `rotation0`=0.0625167, `rotation1`=0.0988617, `rotation2`=0.0627174, `rotation3`=0.991153 WHERE `guid`=100113;
UPDATE `gameobject` SET `rotation0`=-0.0152206, `rotation1`=0.015625, `rotation2`=-0.156172, `rotation3`=0.987489 WHERE `guid`=100130;
UPDATE `gameobject` SET `rotation0`=-0.00867891, `rotation1`=0.000911713, `rotation2`=0.659348, `rotation3`=0.751787 WHERE `guid`=100131;
UPDATE `gameobject` SET `rotation0`=-0.00436258, `rotation1`=0.00755692, `rotation2`=0.0654306, `rotation3`=0.997819 WHERE `guid`=100133;
UPDATE `gameobject` SET `rotation0`=-0.00864697, `rotation1`=0.00117683, `rotation2`=0.636083, `rotation3`=0.771572 WHERE `guid`=100134;
UPDATE `gameobject` SET `rotation0`=0.0196276, `rotation1`=0.00951958, `rotation2`=-0.971087, `rotation3`=0.237725 WHERE `guid`=100136;
UPDATE `gameobject` SET `rotation0`=0.161899, `rotation1`=-0.411941, `rotation2`=0.241236, `rotation3`=0.863655 WHERE `guid`=100137;
UPDATE `gameobject` SET `rotation0`=0.644176, `rotation1`=-0.0210094, `rotation2`=0.761547, `rotation3`=0.0681314 WHERE `guid`=100141;
UPDATE `gameobject` SET `rotation0`=-0.0734706, `rotation1`=-0.56757, `rotation2`=-0.0934219, `rotation3`=0.814702 WHERE `guid`=100142;
UPDATE `gameobject` SET `rotation0`=-0.630999, `rotation1`=-0.218625, `rotation2`=-0.702788, `rotation3`=0.245218 WHERE `guid`=100144;
UPDATE `gameobject` SET `rotation0`=-0.107858, `rotation1`=-0.0487566, `rotation2`=-0.101926, `rotation3`=0.987725 WHERE `guid`=100450;
UPDATE `gameobject` SET `rotation0`=-0.0390229, `rotation1`=0.111322, `rotation2`=0.748832, `rotation3`=0.652178 WHERE `guid`=100451;
UPDATE `gameobject` SET `rotation0`=-0.0379386, `rotation1`=-0.156926, `rotation2`=-0.957411, `rotation3`=0.239373 WHERE `guid`=100452;
UPDATE `gameobject` SET `rotation0`=-0.180747, `rotation1`=0.0777254, `rotation2`=-0.015399, `rotation3`=0.980333 WHERE `guid`=100453;
UPDATE `gameobject` SET `rotation0`=-0.139477, `rotation1`=-0.0323668, `rotation2`=-0.199125, `rotation3`=0.969457 WHERE `guid`=100454;
UPDATE `gameobject` SET `rotation0`=-0.097249, `rotation1`=-0.0870361, `rotation2`=-0.955737, `rotation3`=0.263693 WHERE `guid`=100455;
UPDATE `gameobject` SET `rotation0`=0.072156, `rotation1`=-0.202436, `rotation2`=-0.864216, `rotation3`=0.454911 WHERE `guid`=100456;
UPDATE `gameobject` SET `rotation0`=-0.105731, `rotation1`=-0.0683603, `rotation2`=-0.0585232, `rotation3`=0.990315 WHERE `guid`=100457;
UPDATE `gameobject` SET `rotation0`=0.00770569, `rotation1`=0.0736351, `rotation2`=-0.67674, `rotation3`=0.73249 WHERE `guid`=100458;
UPDATE `gameobject` SET `rotation0`=-0.11402, `rotation1`=-0.16656, `rotation2`=0.159782, `rotation3`=0.966295 WHERE `guid`=100459;
UPDATE `gameobject` SET `rotation0`=-0.0164127, `rotation1`=-0.0513248, `rotation2`=0.0741091, `rotation3`=0.995793 WHERE `guid`=100461;
UPDATE `gameobject` SET `rotation0`=0.137686, `rotation1`=-0.0460796, `rotation2`=-0.409542, `rotation3`=0.900663 WHERE `guid`=100462;
UPDATE `gameobject` SET `rotation0`=0.00110674, `rotation1`=0.0625811, `rotation2`=0.691717, `rotation3`=0.719451 WHERE `guid`=100463;
UPDATE `gameobject` SET `rotation0`=-0.136161, `rotation1`=0.0206881, `rotation2`=-0.976232, `rotation3`=0.167344 WHERE `guid`=100464;
UPDATE `gameobject` SET `rotation0`=-0.151397, `rotation1`=0.19665, `rotation2`=-0.201186, `rotation3`=0.947593 WHERE `guid`=100465;
UPDATE `gameobject` SET `rotation0`=-0.0643306, `rotation1`=0.0673084, `rotation2`=-0.461115, `rotation3`=0.882442 WHERE `guid`=100466;
UPDATE `gameobject` SET `rotation0`=0.171546, `rotation1`=0.0245619, `rotation2`=-0.0352268, `rotation3`=0.98424 WHERE `guid`=100467;
UPDATE `gameobject` SET `rotation0`=-0.0134768, `rotation1`=-0.0521717, `rotation2`=0.130445, `rotation3`=0.98999 WHERE `guid`=100468;
UPDATE `gameobject` SET `rotation0`=-0.00244284, `rotation1`=0.0625439, `rotation2`=0.731393, `rotation3`=0.679078 WHERE `guid`=100469;
UPDATE `gameobject` SET `rotation0`=-0.162303, `rotation1`=0.187751, `rotation2`=-0.147141, `rotation3`=0.957474 WHERE `guid`=100470;
UPDATE `gameobject` SET `rotation0`=0.169878, `rotation1`=0.0342474, `rotation2`=0.0206289, `rotation3`=0.984654 WHERE `guid`=100471;
UPDATE `gameobject` SET `rotation0`=0.0185976, `rotation1`=0.0620785, `rotation2`=-0.88506, `rotation3`=0.460943 WHERE `guid`=100473;
UPDATE `gameobject` SET `rotation0`=0.0269089, `rotation1`=0.00610161, `rotation2`=-0.999321, `rotation3`=0.0244177 WHERE `guid`=151140;
UPDATE `gameobject` SET `rotation0`=-0.0320468, `rotation1`=-0.0343475, `rotation2`=0.725892, `rotation3`=0.686203 WHERE `guid`=151141;
UPDATE `gameobject` SET `rotation0`=0.021595, `rotation1`=-0.0220261, `rotation2`=0.904034, `rotation3`=0.426347 WHERE `guid`=151142;
UPDATE `gameobject` SET `rotation0`=0.0010438, `rotation1`=0.0539341, `rotation2`=-0.0478249, `rotation3`=0.997398 WHERE `guid`=151293;
UPDATE `gameobject` SET `rotation0`=0.0864091, `rotation1`=0.0250797, `rotation2`=-0.416438, `rotation3`=0.904701 WHERE `guid`=151893;
UPDATE `gameobject` SET `rotation0`=-0.0144057, `rotation1`=0.0048542, `rotation2`=-0.459116, `rotation3`=0.888246 WHERE `guid`=151894;
