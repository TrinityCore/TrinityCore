DELETE FROM `build_info` WHERE `build`=40593;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(40593,9,1,0,NULL,NULL,'BA14570F2D62D5F61953394164A8DAE2',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=40593 WHERE `gamebuild`=40443;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '40593';
