DELETE FROM `build_info` WHERE `build`=42614;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(42614,9,2,0,NULL,NULL,'772BE726FEEF42124255D2EA7973CA18',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=42614 WHERE `gamebuild`=42560;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '42614';
