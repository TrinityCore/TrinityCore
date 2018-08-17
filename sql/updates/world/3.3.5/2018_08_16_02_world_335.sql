-- 
DELETE FROM `trinity_string` WHERE `entry` IN (848,882);
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(848,'│ Map: %s, Zone: %s'),
(882,'│ Map: %s, Zone: %s, Area: %s');
