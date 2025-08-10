DELETE FROM `build_info` WHERE `build`=50000;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(50000,10,1,0,NULL,NULL,'02F06FFA2296FD66384295DBFD5A4C91',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=50000 WHERE `gamebuild`=49890;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '50000';
