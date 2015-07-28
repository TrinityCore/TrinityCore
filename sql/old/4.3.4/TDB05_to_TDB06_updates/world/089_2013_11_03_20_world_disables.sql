--
DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`IN(69922,69956);
INSERT INTO `disables`(`sourceType`,`entry`,`flags`,`comment`) VALUES
(0,69922,64,'Ignore LOS on Temper Quel Delar'),
(0,69956,64,'Ignore LOS on Return Tempered Quel Delar');
