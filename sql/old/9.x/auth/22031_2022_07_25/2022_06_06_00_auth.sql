DELETE FROM `build_info` WHERE `build`=44015;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(44015,9,2,5,NULL,NULL,'FCF0BDA7C98BFEF92AE6D8C39A217ABD',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=44015 WHERE `gamebuild`=43971;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '44015';
