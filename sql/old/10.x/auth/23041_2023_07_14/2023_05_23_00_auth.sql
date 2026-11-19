DELETE FROM `build_info` WHERE `build`=49679;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(49679,10,1,0,NULL,NULL,'9CE59B68D8797EBF00581F41138F4316',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=49679 WHERE `gamebuild`=49570;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '49679';
