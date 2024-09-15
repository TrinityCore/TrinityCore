DELETE FROM `build_info` WHERE `build`=55664;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(55664,10,2,7,NULL,NULL,'DBCA58486FAAA0FE54EA287A3047E923',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=55664 WHERE `gamebuild`=55461;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '55664';
