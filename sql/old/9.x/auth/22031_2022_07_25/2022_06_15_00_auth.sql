DELETE FROM `build_info` WHERE `build`=44127;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(44127,9,2,5,NULL,NULL,'787887CEC9FCC9B516481F60E4FC34A8',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=44127 WHERE `gamebuild`=44061;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '44127';
