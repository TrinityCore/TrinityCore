DELETE FROM `build_info` WHERE `build`=34963;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(34963,8,3,0,NULL,NULL,'7BA50C879C5D04221423B02AC3603A11',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=34963 WHERE `gamebuild`=34769;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '34963';
