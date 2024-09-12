DELETE FROM `build_info` WHERE `build` IN (56008);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(56008,11,0,0,NULL,NULL,'00FCD6BFFCCCBA7A8E71E307EA6EBD0C',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=56008 WHERE `gamebuild`=55960;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '56008';
