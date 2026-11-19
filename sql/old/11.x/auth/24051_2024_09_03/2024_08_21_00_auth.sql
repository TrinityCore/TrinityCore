DELETE FROM `build_info` WHERE `build` IN (56196);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(56196,11,0,2,NULL,NULL,'81FC14274BFF0347FFF9C8B1AA6BED9B',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=56196 WHERE `gamebuild`=56162;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '56196';
