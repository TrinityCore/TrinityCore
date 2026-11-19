-- 
SET @OBJECTIVE_STRING_ID := 884;
SET @QUEST_NOT_FOUND_STRING_ID := 1517;

DELETE FROM `command` WHERE `name`='quest objective complete';
INSERT INTO `command` (`name`,`help`) VALUES
('quest objective complete','Syntax: .quest objective complete #questObjectiveId\nMark specific quest objective as completed for target character.');

DELETE FROM `trinity_string` WHERE `entry` IN (@OBJECTIVE_STRING_ID,@QUEST_NOT_FOUND_STRING_ID);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(@OBJECTIVE_STRING_ID, 'Objective %u not found.'),
(@QUEST_NOT_FOUND_STRING_ID, 'Quest ID %u does not exist.');
