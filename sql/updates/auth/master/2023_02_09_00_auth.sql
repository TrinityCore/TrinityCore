DELETE FROM `build_info` WHERE `build`=48001;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(48001,10,0,5,NULL,NULL,'4B0260A37BD95B615E71048469E6D5BB',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=48001 WHERE `gamebuild`=47967;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '48001';
