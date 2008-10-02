DELETE FROM `command` WHERE `name` = 'wp import';
DELETE FROM `command` WHERE `name` = 'wp export';

INSERT INTO `command` (`name`,`security`,`help`) VALUES
('wp import',3,'Syntax: .wp import $filename');

INSERT INTO `command` (`name`,`security`,`help`) VALUES
('wp export',3,'Syntax: .wp export [#creature_guid or Select a Creature] $filename');

UPDATE `command` SET `help` = 'Syntax: .wp modify [#creature_guid or Select a Creature]\r\nadd - Add a waypoint after the selected visual\r\nwaittime $time\r\nemote ID\r\nspell ID\r\ntext1| text2| text3| text4| text5 <text>\r\nmodel1 ID\r\nmodel2 ID\r\nmove(moves wp to player pos)\r\ndel (deletes the wp)\r\n\r\nOnly one parameter per time!' WHERE `name` = 'wp modify';