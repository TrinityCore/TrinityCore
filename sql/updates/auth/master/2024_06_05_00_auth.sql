DELETE FROM `build_info` WHERE `build`=54988;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(54988,10,2,7,NULL,NULL,'8F2791553226871977B4F9D7F1137311',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=54988 WHERE `gamebuild`=54904;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '54988';
