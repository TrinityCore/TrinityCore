DELETE FROM `build_info` WHERE `build`=48397;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(48397,10,0,5,NULL,NULL,'64BA8779EAA97E6C57982B6B1A5B32E7',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=48397 WHERE `gamebuild`=48317;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '48397';
