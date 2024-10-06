DELETE FROM `build_info` WHERE `build`=55165;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(55165,10,2,7,NULL,NULL,'26D4D1C01434A8A6723DCABC944B6FD0',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=55165 WHERE `gamebuild`=55142;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '55165';
