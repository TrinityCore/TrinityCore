DELETE FROM `build_info` WHERE `build`=38556;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(38556,9,0,5,NULL,NULL,'EC7D5AF64364AC3E7181F3FBA1B3A882',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=38556 WHERE `gamebuild`=38134;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '38556';
