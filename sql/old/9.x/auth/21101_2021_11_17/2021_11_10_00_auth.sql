DELETE FROM `build_info` WHERE `build`=40966;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(40966,9,1,5,NULL,NULL,'D90F47AF21F381D2D8F3763B994BAC88',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=40966 WHERE `gamebuild`=40944;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '40966';
