DELETE FROM `build_info` WHERE `build`=44232;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(44232,9,2,5,NULL,NULL,'81F0A71DF7E9873BB3750022D64D33CF',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=44232 WHERE `gamebuild`=44127;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '44232';
