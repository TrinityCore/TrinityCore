ALTER TABLE db_version CHANGE COLUMN required_7662_02_mangos_spell_bonus_data required_7705_01_mangos_command bit;

DELETE FROM `command` WHERE `name` IN (
  'account lock','account password','chardelete','character customize','character delete',
  'character rename','customize','lockaccount','password','rename'
);

INSERT INTO `command` VALUES
('account lock',0,'Syntax: .account lock [on|off]\r\n\r\nAllow login from account only from current used IP or remove this requirement.'),
('account password',0,'Syntax: .account password $old_password $new_password $new_password\r\n\r\nChange your account password.'),
('character customize',2,'Syntax: .character customize [$name]\r\n\r\nMark selected in game or by $name in command character for customize at next login.'),
('character delete',4,'Syntax: .character delete $name\r\n\r\nDelete character $name.'),
('character rename',2,'Syntax: .character rename [$name]\r\n\r\nMark selected in game or by $name in command character for rename at next login.');
