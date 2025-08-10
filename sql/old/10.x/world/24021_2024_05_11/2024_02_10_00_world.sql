SET @TEL_ID := 2151;

UPDATE `game_tele` SET `name` = 'EmeraldDreamClassic' WHERE `id` = 1425;

DELETE FROM `game_tele` WHERE `id` BETWEEN @TEL_ID+0 AND @TEL_ID+15;
INSERT INTO `game_tele` (`id`,`position_x`,`position_y`,`position_z`,`orientation`,`map`,`name`) VALUES
(@TEL_ID+0,-1134.45,7336.62,132.689,0.882665,2548,'EmeraldDreamDragonflight'),
(@TEL_ID+1,-2289.68,6929.88,66.0932,2.35535,2548,'RootBoundSanctuary'),
(@TEL_ID+2,-2048.04,8300.77,58.9846,5.02962,2548,'WhorlwingBasin'),
(@TEL_ID+3,-1619.93,6259.64,42.065,4.71783,2548,'ShorelineRoots'),
(@TEL_ID+4,-1886.4,7062.66,156.974,1.54563,2548,'Amirdrassil'),
(@TEL_ID+5,-995.698,7057.5,85.8742,5.7663,2548,'LushdreamCrags'),
(@TEL_ID+6,-952.519,8026.15,39.7644,1.41523,2548,'TheSmolderingCopse'),
(@TEL_ID+7,-175.216,8669.53,31.245,1.45215,2548,'WellspringOfLife'),
(@TEL_ID+8,358.468,7849.75,146.218,0.69345,2548,'ScorchingChasm'),
(@TEL_ID+9,372.974,8307.67,109.342,3.83113,2548,'PrimalistStronghold'),
(@TEL_ID+10,-276.958,8248.23,103.477,4.85607,2548,'WellspringOverlook'),
(@TEL_ID+11,-36.5172,6972.46,144.839,2.43705,2548,'EyeOfYsera'),
(@TEL_ID+12,-1100.05,5335.86,25.278,2.40642,2548,'AncientBough'),
(@TEL_ID+13,-1331.98,5743.55,45.0434,1.97053,2548,'VerdantLanding'),
(@TEL_ID+14,-1690.83,7151.72,202.397,3.94191,2548,'CentralEncampment'),
(@TEL_ID+15,-2977.19,8556.59,33.4102,4.32357,2209,'EmeraldDreamLegion');
