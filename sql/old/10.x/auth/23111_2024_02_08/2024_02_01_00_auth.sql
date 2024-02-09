DELETE FROM `build_info` WHERE `build`=53162;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(53162,10,2,5,NULL,NULL,'8A67511FBF8984EEE2B630F7CB23376A',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=53162 WHERE `gamebuild`=53104;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '53162';
