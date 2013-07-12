DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`=32979;
INSERT INTO `disables`(`sourceType`,`entry`,`flags`,`comment`) VALUES
(0,32979,64,'Ignore LOS on Ignite Horde Siege Engine');
