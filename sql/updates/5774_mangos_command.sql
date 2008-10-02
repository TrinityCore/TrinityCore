DELETE FROM `command` WHERE `name` = 'targetobject';
DELETE FROM `command` WHERE `name` = 'gobject target';

INSERT INTO `command` (`name`,`security`,`help`) VALUES
('gobject target',2,'Syntax: .gobject target [#go_id|#go_name_part]\r\n\r\nLocate and show position nearest gameobject. If #go_id or #go_name_part provide then locate and show position of nearest gameobject with gameobject template id #go_id or name included #go_name_part as part.');
