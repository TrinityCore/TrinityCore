DELETE FROM `build_info` WHERE `build`=48838;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(48838,10,0,7,NULL,NULL,'9E6F4E1E46EF228D2DE90F7BC48AAA96',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=48838 WHERE `gamebuild`=48749;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '48838';
