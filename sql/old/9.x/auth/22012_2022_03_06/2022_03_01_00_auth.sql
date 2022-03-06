DELETE FROM `build_info` WHERE `build`=42521;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(42521,9,2,0,NULL,NULL,'5FE6C12FC407C6B15B4A5D3B5B4A5D3B',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=42521 WHERE `gamebuild`=42488;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '42521';
