DELETE FROM `build_info` WHERE `build`=42010;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(42010,9,1,5,NULL,NULL,'302970161D16417B5BE553CC530E011A',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=42010 WHERE `gamebuild`=41793;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '42010';
