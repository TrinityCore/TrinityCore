DELETE FROM `build_info` WHERE `build`=33369;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(33369,8,3,0,NULL,NULL,'5986AC18B04D3C403F56A0CF8C4F0A14',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=33369 WHERE `gamebuild`=32978;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '33369';
