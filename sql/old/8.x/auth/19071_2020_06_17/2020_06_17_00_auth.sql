DELETE FROM `build_info` WHERE `build`=34769;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(34769,8,3,0,NULL,NULL,'93F9B9AF6397E3E4EED94D36D16907D2',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=34769 WHERE `gamebuild`=34601;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '34769';
