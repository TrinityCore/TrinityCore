DELETE FROM `build_info` WHERE `build`=32978;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(32978,8,2,5,NULL,NULL,'76AE2EA03E525D97F5688843F5489000',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=32978 WHERE `gamebuild`=32750;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '32978';
