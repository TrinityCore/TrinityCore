-- 
DELETE FROM `command` WHERE `name` IN ('achievement','achievement add');
DELETE FROM `trinity_string` WHERE `entry`=365;
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(365, '### USAGE: .achievement add <achievement>
Add an achievement, specified by ID or link, to the targeted player.');
