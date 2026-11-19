DELETE FROM `command` WHERE `name` LIKE '%debug send playscene%';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('debug send playscene', 692, 'Syntax: .debug send playscene #SceneID #PlaybackFlags #SceneInstanceID #SceneScriptPackageID');
