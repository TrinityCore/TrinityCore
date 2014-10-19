DELETE FROM `trinity_string` WHERE `entry` IN (5057, 5058);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(5057, 'Boss id %i state is now set to %i.'),
(5058, 'Boss id %i state is %i.');

DELETE FROM `command` WHERE `permission` IN (795, 796);
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('instance setbossstate', '795', 'Syntax: .instance setbossstate $bossId $encounterState [$Name]\r\nSets the EncounterState for the given boss id to a new value. EncounterStates range from 0 to 5.\r\nIf no character name is provided, the current map will be used as target.'),
('instance getbossstate', '796', 'Syntax: .instance getbossstate $bossId [$Name]\r\nGets the current EncounterState for the provided boss id.\r\nIf no character name is provided, the current map will be used as target.');
