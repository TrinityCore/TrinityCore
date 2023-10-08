DELETE FROM `build_info` WHERE `build`=51421;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(51421,10,1,7,NULL,NULL,'45E24D6F3335269787DF2B2063939002',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=51421 WHERE `gamebuild`=51313;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '51421';
