DELETE FROM `build_info` WHERE `build`=40120;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(40120,9,1,0,NULL,NULL,'04F47EAEFD8BDEFE14AA0350EA336678',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=40120 WHERE `gamebuild`=40000;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '40120';
