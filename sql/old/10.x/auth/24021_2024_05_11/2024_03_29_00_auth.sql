DELETE FROM `build_info` WHERE `build`=53989;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(53989,10,2,6,NULL,NULL,'3AEB90ACB9E18B88BA1021F52D51B857',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=53989 WHERE `gamebuild`=53913;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '53989';
