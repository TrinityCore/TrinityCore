DELETE FROM `command` WHERE `name`='bnetaccount listgameaccounts';
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('bnetaccount listgameaccounts', 830, 'Syntax: .bnetaccount listgameaccounts $email $password\nLists all game accounts linked to battle.net $email');

DELETE FROM `trinity_string` WHERE `entry` IN (1034,1035);
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(1034, '| Account Id |  Internal name   |   Display name   |'),
(1035, 'Battle.net account %s has no linked game accounts.');

-- fix bad entries
UPDATE `command` SET `name`='scene playpackage',`help`='Syntax: .scene playpackage #scenePackageId #playbackFlags\nPlays scene with package id and playback flags for targeted player' WHERE `name`='scene play package';
UPDATE `command` SET `name`='reload scene_template',`help`='Syntax: .reload scene_template\nReload scene_template table.' WHERE `name`='reload scenes';
