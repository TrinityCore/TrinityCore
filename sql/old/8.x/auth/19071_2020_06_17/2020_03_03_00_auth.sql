DELETE FROM `build_info` WHERE `build`=33528;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(33528,8,3,0,NULL,NULL,'0ECE033CA9B11D92F7D2792C785B47DF',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=33528 WHERE `gamebuild`=33369;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '33528';
