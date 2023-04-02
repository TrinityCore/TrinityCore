DELETE FROM `build_info` WHERE `build`=48749;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(48749,10,0,7,NULL,NULL,'92DBCCA0E33DFB8A17A2B6A39246B288',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=48749 WHERE `gamebuild`=48676;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '48749';
