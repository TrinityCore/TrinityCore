DELETE FROM `build_info` WHERE `build`=52808;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(52808,10,2,0,NULL,NULL,'6276712B6C8AEA21CD5D94D52FEE70EE',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=52808 WHERE `gamebuild`=52649;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '52808';
