DELETE FROM `build_info` WHERE `build`=54070;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(54070,10,2,6,NULL,NULL,'FDA08264B7587250CF78F9B960218169',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=54070 WHERE `gamebuild`=53989;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '54070';
