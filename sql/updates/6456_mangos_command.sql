DELETE FROM `command` WHERE `name` IN ('instance unbind','instance listbinds','instance stats','instance savedata');

INSERT INTO `command` (`name`,`security`,`help`) VALUES
('instance unbind',3,'Syntax: .instance unbind all\r\n  All of the selected player\'s binds will be cleared.'),
('instance listbinds',3,'Syntax: .instance listbinds\r\n  Lists the binds of the selected player.'),
('instance stats',3,'Syntax: .instance stats\r\n  Shows statistics about instances.'),
('instance savedata',3,'Syntax: .instance savedata\r\n  Save the InstanceData for the current player\'s map to the DB.');
