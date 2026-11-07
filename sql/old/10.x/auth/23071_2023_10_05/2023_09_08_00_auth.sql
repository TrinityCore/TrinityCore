DELETE FROM `build_info` WHERE `build`=51261;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(51261,10,1,7,NULL,NULL,'1BEBB57AE450331E9F8C301AA7876FAB',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=51261 WHERE `gamebuild`=51237;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '51261';
