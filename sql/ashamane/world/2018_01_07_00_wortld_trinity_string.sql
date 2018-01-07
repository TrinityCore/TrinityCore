DELETE FROM `trinity_string` WHERE `entry` BETWEEN 12001 AND 12014;
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
('12001','The battle for Twin Peaks begins in 1 minute.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
('12000','The battle for Twin Peaks begins in 2 minutes.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
('12002','The battle for Twin Peaks begins in 30 seconds. Prepare yourselves!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
('12003','Let the battle for Twin Peaks begin!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
('12004','$n captured the Horde flag!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
('12005','$n captured the Alliance flag!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
('12006','The Horde flag was dropped by $n!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
('12007','The Alliance Flag was dropped by $n!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
('12008','The Alliance Flag was returned to its base by $n!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
('12009','The Horde flag was returned to its base by $n!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
('12010','The Horde flag was picked up by $n!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
('12011','The Alliance Flag was picked up by $n!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
('12012','The flags are now placed at their bases.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
('12013','The Alliance flag is now placed at its base.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
('12014','The Horde flag is now placed at its base.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

DELETE FROM `graveyard_zone` WHERE `ID` IN (1750, 1749, 1726, 1727, 1729, 1728);
INSERT INTO `graveyard_zone`(`ID`,`GhostZone`,`Faction`) VALUES
(1750, 5031, 67),
(1749, 5031, 469),
(1726, 5031, 469),
(1727, 5031, 67),
(1729, 5031, 469),
(1728, 5031, 67);
