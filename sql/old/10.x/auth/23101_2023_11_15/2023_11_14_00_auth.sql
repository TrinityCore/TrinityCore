DELETE FROM `build_info` WHERE `build`=52129;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(52129,10,2,0,NULL,NULL,'02DD842F2A7162EEB8FD5B9D325606F8',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=52129 WHERE `gamebuild`=52106;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '52129';
