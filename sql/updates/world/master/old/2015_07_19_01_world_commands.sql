INSERT INTO `command` (`name`, `security`, `help`) VALUES
('npc flags', '3', 'Syntax: .npc flags\r\n\r\nDisplay a list of flags for the selected creature.');

INSERT INTO `command` (`name`, `security`, `help`) VALUES
('lfg join', '3', 'Syntax: .lfg join `role` `lfgEntry`');

DELETE FROM `trinity_string` WHERE `entry` IN(556, 714);
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(714, 'MechanicImmuneMask: %u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(556, 'Unit Flags: %u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(556, 'Unit Flags: %u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

UPDATE `trinity_string` SET `content_default`=
'Unit Flags 2: %u.
Dynamic Flags: %u.
Faction Template: %u.' WHERE `entry`=542;