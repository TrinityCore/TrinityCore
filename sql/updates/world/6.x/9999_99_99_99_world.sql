CREATE TABLE IF NOT EXISTS `scene_template` (
  `SceneId` INT(10) UNSIGNED NOT NULL,
  `Flags` INT(10) UNSIGNED NOT NULL DEFAULT '16',
  `ScriptPackageID` INT(10) UNSIGNED NOT NULL,
  `ScriptName` CHAR(64) NOT NULL DEFAULT '',
  PRIMARY KEY (`SceneId`)
) ENGINE=INNODB DEFAULT CHARSET=utf8;

DELETE FROM `trinity_string` WHERE `entry` IN ( 5062, 5063, 5064, 5065, 5066, 5067, 5068, 5069 );
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
( 5062, 'Scene debugging turned on.' ),
( 5063, 'Scene debugging turned off.' ),
( 5064, 'Scene : started (instance : %u - package : %u - flags : %u)' ),
( 5065, 'Scene : triggered (instance : %u - event : "%s")' ),
( 5066, 'Scene : canceled (instance : %u)' ),
( 5067, 'Scene : completed (instance : %u)' ),
( 5068, 'Player have %u active(s) scene(s)' ),
( 5069, 'ScenePackageId : %u - SceneInstanceId : %u' );

DELETE FROM `scene_template` WHERE `SceneId` = 1181;
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `ScriptName`) VALUES (1181, 16, 1550, "Scene_DeathwingSimulator");
