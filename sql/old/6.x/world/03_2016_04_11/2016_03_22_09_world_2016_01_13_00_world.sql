--
DELETE FROM `command` WHERE `permission`=836;
INSERT INTO `command` (`name`,`permission`,`help`) VALUES ("debug boundary",836,"Syntax: .debug boundary [fill] [duration]
Flood fills the targeted unit's movement boundary and marks the edge of said boundary with debug creatures.\nSpecify 'fill' as first parameter to fill the entire area with debug creatures.");

DELETE FROM `trinity_string` WHERE `entry` IN (11011,11012,11013);
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(11011,"VisualizeBoundary warning: No interior point of the creature's boundary could be found - check if you have mutually exclusive boundaries!"),
(11012,"VisualizeBoundary error: Creature movement is unbounded"),
(11013,"VisualizeBoundary warning: Reached fail-safe flood boundary - check is your boundary is unbounded!");
