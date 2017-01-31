DELETE FROM `disables` WHERE `sourceType`=0 AND `entry` IN (38729,38736);
INSERT INTO `disables`(`sourceType`,`entry`,`flags`,`comment`) VALUES
(0,38729,64,'Ignore LOS on Rod of Purification'),
(0,38736,64,'Ignore LOS on Rod of Purification');
