DELETE FROM `build_info` WHERE `build`=52301;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(52301,10,2,0,NULL,NULL,'821AA3BB237B400B82F44970250539AA',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=52301 WHERE `gamebuild`=52188;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '52301';
