DELETE FROM `build_info` WHERE `build`=51536;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(51536,10,1,7,NULL,NULL,'570EEA10A8EC169C3FF9621D1B635BB4',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=51536 WHERE `gamebuild`=51485;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '51536';
