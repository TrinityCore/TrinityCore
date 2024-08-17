DELETE FROM `build_info` WHERE `build`=54261;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(54261,3,4,3,NULL,NULL,'25FD812475DCF26F9F1383AED37FC99E',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=54261 WHERE `gamebuild`=53788;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '54261';
