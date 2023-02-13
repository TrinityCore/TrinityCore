DELETE FROM `build_info` WHERE `build`=47657;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(47657,10,0,2,NULL,NULL,'11857CA9FA336B5148E7B2A116858C92',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=47657 WHERE `gamebuild`=47631;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '47657';
