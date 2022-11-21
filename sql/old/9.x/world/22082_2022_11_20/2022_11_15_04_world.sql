SET @TEL_ID := 1893;

DELETE FROM `game_tele` WHERE `id` BETWEEN @TEL_ID+0 AND @TEL_ID+13;
INSERT INTO `game_tele` (`id`,`position_x`,`position_y`,`position_z`,`orientation`,`map`,`name`) VALUES
(@TEL_ID+0,68.6408,2532.25,149.072,5.59211,870,'ForgottenMire'),
(@TEL_ID+1,211.91,3297.27,214.998,4.67486,870,'Klaxxivess'),
(@TEL_ID+2,893.847,3670.26,273.479,1.90388,870,'KorVess'),
(@TEL_ID+3,-403.319,3161.6,190.901,1.30775,870,'KypariIk'),
(@TEL_ID+4,775.226,2784.47,310.452,0.984965,870,'KypariVor'),
(@TEL_ID+5,-765.167,3014.05,125.734,5.80811,870,'KypariZar'),
(@TEL_ID+6,-689.727,2777.5,131.202,5.52142,870,'LakeOfStars'),
(@TEL_ID+7,599.235,4112.16,208.655,1.33212,870,'RikkitunVillage'),
(@TEL_ID+8,-1084.49,3140.64,0.702106,2.73331,870,'SoggysGamble'),
(@TEL_ID+9,509.828,2290.65,258.337,2.92568,870,'TerraceOfGurthan'),
(@TEL_ID+10,-569.266,3856.38,1.04876,2.02571,870,'TheBrinyMuck'),
(@TEL_ID+11,-37.7685,3688.55,156.37,2.05948,870,'TheClutchesOfShekzeer'),
(@TEL_ID+12,995.761,3443.21,256.411,2.86992,870,'TheSunsetBrewgarden'),
(@TEL_ID+13,-1226.85,4563.08,129.094,2.61869,870,'Zanvess');

UPDATE `game_tele` SET `name` = 'HeartOfFear' WHERE (`id` = '1572');
