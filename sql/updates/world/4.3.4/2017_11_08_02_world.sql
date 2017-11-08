UPDATE `trinity_string` SET `content_default`='│ Phases: %s' WHERE `entry`=846;
DELETE FROM `trinity_string` WHERE `entry`=5083;
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(5083,"Uses invalid phaseID.");
