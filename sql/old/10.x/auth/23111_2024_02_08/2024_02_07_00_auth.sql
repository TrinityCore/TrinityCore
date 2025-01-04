DELETE FROM `build_info` WHERE `build`=53212;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(53212,10,2,5,NULL,NULL,'08761EFF2F9B639364B9A9FBFFFFB949',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=53212 WHERE `gamebuild`=53162;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '53212';
