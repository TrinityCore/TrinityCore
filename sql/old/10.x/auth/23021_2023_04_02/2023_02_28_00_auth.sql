DELETE FROM `build_info` WHERE `build`=48317;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(48317,10,0,5,NULL,NULL,'C096E37B45B43244E9C79916604DD4AF',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=48317 WHERE `gamebuild`=48069;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '48317';
