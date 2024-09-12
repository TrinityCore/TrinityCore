DELETE FROM `build_info` WHERE `build` IN (55959,56110);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(55959,11,0,2,NULL,NULL,'ED57E0538FD1CE99B171BE34823148A9',NULL,NULL,NULL),
(56110,11,0,2,NULL,NULL,'800BCA228E2FAE37ED160F3C09E21F3A',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=56110 WHERE `gamebuild`=56008;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '56110';
