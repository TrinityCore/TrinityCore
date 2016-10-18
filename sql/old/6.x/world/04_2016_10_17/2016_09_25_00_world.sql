DROP TABLE IF EXISTS `scene_template`;
CREATE TABLE `scene_template` (
  `SceneId` int(10) unsigned NOT NULL,
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `ScriptPackageID` int(10) unsigned NOT NULL DEFAULT '0',
  `ScriptName` varchar(64) NOT NULL DEFAULT '',
  PRIMARY KEY (`SceneId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DELETE FROM `command` WHERE `name`='debug send playscene';
DELETE FROM `command` WHERE `name` IN ('scene','scene debug','scene play','scene play package','scene cancel','list scenes','reload scenes');
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('scene', 844, ''),
('scene debug', 845, 'Syntax: .scene debug\nToggle debug mode for scenes. In debug mode GM will be notified in chat when scenes start/stop/trigger event'),
('scene play', 846, 'Syntax: .scene play #sceneId\nPlays scene with id for targeted player'),
('scene play package', 847, 'Syntax: .scene play package #scenePackageId #playbackFlags\nPlays scene with package id and playback flags for targeted player'),
('scene cancel', 848, 'Syntax: .scene cancel #scenePackageId\nCancels scene with package id for targeted player'),
('list scenes', 849, 'Syntax: .list scenes\nList of all active scenes for targeted character.'),
('reload scenes', 850, 'Syntax: .reload scenes\nReload scene_template table.');

DELETE FROM `trinity_string` WHERE `entry` IN (5062, 5063, 5064, 5065, 5066, 5067, 5068, 5069);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(5062, 'Scene debugging turned on.'),
(5063, 'Scene debugging turned off.'),
(5064, 'Scene : started (instance : %u - package : %u - flags : %u)'),
(5065, 'Scene : triggered (instance : %u - event : "%s")'),
(5066, 'Scene : canceled (instance : %u)'),
(5067, 'Scene : completed (instance : %u)'),
(5068, 'Player have %u active(s) scene(s)'),
(5069, 'ScenePackageId : %u - SceneInstanceId : %u');

DELETE FROM `scene_template` WHERE `SceneId`=1181;
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `ScriptName`) VALUES (1181, 16, 1550, "scene_deathwing_simulator");
