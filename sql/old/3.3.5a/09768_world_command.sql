DELETE FROM `command` WHERE `name` LIKE 'instance unbind';
INSERT INTO `command` (`name`,`security`,`help`) VALUES
('instance unbind',3,'Syntax: .instance unbind <mapid|all> [difficulty]\r\n  Clear all/some of player\'s binds');
