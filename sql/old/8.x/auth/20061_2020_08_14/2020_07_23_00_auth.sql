DELETE FROM `build_info` WHERE `build`=35249;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(35249,8,3,7,NULL,NULL,'C7B11F9AE9FF1409F5582902B3D10D1C',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=35249 WHERE `gamebuild`=34963;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '35249';
