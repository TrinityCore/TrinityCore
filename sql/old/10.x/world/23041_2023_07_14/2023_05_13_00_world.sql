DELETE FROM `command` WHERE `name`='damage go';
INSERT INTO `command` (`name`,`help`) VALUES
('damage go','Syntax: .damage go $guid|$link $damage_amount\n\nApply $damage to destructible gameobject.');
