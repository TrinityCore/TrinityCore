DELETE FROM `build_info` WHERE `build` IN (52038,52068,52095);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(52038,10,2,0,NULL,NULL,'A8EF004ADED8A3AFF5A67D2BB8D95795',NULL,NULL,NULL),
(52068,10,2,0,NULL,NULL,'A44F842BACCC7EE8E2975FAF01F12474',NULL,NULL,NULL),
(52095,10,2,0,NULL,NULL,'BA36382887D16D274EA9149695F0C9C8',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=52095 WHERE `gamebuild`=51972;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '52095';
