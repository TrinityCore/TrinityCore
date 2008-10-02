DELETE FROM `command` WHERE `name` IN ('quest complete');

INSERT INTO `command` (`name`,`security`,`help`) VALUES
('quest complete',3,'Syntax: .quest complete #questid\r\nMark all quest objectives as completed for target character active quest. After this target character can go and get quest reward.');
