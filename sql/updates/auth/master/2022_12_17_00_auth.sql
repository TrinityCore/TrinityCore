DELETE FROM `build_info` WHERE `build` IN (47187);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(47187,10,0,2,NULL,NULL,'711F8455C5000C237292E1E6E90631E1',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=47187 WHERE `gamebuild`=47067;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '47187';
