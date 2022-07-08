DELETE FROM `build_info` WHERE `build`=41288;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(41288,9,1,5,NULL,NULL,'871C0C9691DBC536EB24B68EC73FAD5B',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=41288 WHERE `gamebuild`=41079;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '41288';
