-- 
SET @STRINGENTRY := 884;

DELETE FROM `command` WHERE `name`='quest objective complete';
INSERT INTO `command` (`name`,`help`) VALUES
('quest objective complete','Syntax: .quest objective complete #questObjectiveId\nMark specific quest objective as completed for target character.');

DELETE FROM `trinity_string` WHERE `entry`=@STRINGENTRY;
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(@STRINGENTRY, 'Objective %u not found.');
