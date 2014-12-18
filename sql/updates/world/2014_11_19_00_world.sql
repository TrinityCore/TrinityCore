--
DELETE FROM `command` WHERE `name`='pvpstats';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('pvpstats', 797, 'Shows number of battleground victories in the last 7 days');

UPDATE `command` SET `permission`=798 WHERE `name`='modify xp';
