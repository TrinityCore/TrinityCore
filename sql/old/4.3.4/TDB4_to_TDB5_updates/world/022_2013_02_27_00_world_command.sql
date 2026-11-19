DELETE FROM `command` WHERE `name` = 'reload rbac';
INSERT INTO `command` (`name`,`security`,`help`) VALUES
('reload rbac',3,'Syntax: .reload rbac\nReload rbac system.');
