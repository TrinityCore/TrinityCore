DELETE FROM `build_info` WHERE `build`=35435;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(35435,8,3,7,NULL,NULL,'BB397A92FE23740EA52FC2B5BA2EC8E0',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=35435 WHERE `gamebuild`=35284;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '35435';
