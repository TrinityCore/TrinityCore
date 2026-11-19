DELETE FROM `build_info` WHERE `build`=42979;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(42979,9,2,0,NULL,NULL,'E1DD38AE6450FC4D2AE4609233C59E54',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=42979 WHERE `gamebuild`=42852;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '42979';
