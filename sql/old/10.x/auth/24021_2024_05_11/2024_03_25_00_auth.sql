DELETE FROM `build_info` WHERE `build`=53913;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(53913,10,2,6,NULL,NULL,'475680680B2192EBCF6744D14F755199',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=53913 WHERE `gamebuild`=53877;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '53913';
