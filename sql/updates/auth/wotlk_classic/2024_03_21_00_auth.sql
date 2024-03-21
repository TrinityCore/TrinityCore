DELETE FROM `build_info` WHERE `build`=53788;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(53788,3,4,3,NULL,NULL,'E8F11A6A011B4ED7C20D055221DBCF8F',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=53788 WHERE `gamebuild`=53622;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '53788';
