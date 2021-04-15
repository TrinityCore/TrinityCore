DELETE FROM `command` WHERE `name` IN ('reload disables','reload spell_disabled','instance open','instance close');
INSERT INTO `command` (`name`,`security`,`help`) VALUES
('reload disables',3,'Syntax: .reload disables\r\nReload disables table.');
