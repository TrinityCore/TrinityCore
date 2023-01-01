DELETE FROM `build_info` WHERE `build`=45338;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(45338,9,2,7,NULL,NULL,'5CE2094A41B61EDA9DF56378BC3B1DE0',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=45338 WHERE `gamebuild` IN(45114, 45161);

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '45338';
