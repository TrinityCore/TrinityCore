DELETE FROM `build_info` WHERE `build`=42423;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(42423,9,2,0,NULL,NULL,'0B03614A7E94DD57548596BE420E9DC2',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=42423 WHERE `gamebuild`=42010;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '42423';
