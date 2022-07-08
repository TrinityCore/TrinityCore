DELETE FROM `build_info` WHERE `build`=42852;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(42852,9,2,0,NULL,NULL,'DE9F9F0C3CC8FD54D3AFF99CEFFCE129',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=42852 WHERE `gamebuild`=42698;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '42852';
