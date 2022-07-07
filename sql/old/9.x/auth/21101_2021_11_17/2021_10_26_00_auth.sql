DELETE FROM `build_info` WHERE `build`=40725;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(40725,9,1,0,NULL,NULL,'C1EBDBEB9BB2956EBCCEF7C9D27A1B3B',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=40725 WHERE `gamebuild`=40593;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '40725';
