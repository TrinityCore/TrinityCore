DELETE FROM `build_info` WHERE `build`=43340;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(43340,9,2,0,NULL,NULL,'70E46D2D888E84DF9316EA849B068CF4',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=43340 WHERE `gamebuild`=43206;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '43340';
