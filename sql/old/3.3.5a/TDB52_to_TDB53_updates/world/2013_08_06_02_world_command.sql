DELETE FROM `command` WHERE `name`='reload gameobject_questender';
INSERT INTO `command` (`name`, `security`, `help`) VALUES 
('reload gameobject_questender', 3, 'Syntax: .reload gameobject_questender\\nReload gameobject_questender table.');
