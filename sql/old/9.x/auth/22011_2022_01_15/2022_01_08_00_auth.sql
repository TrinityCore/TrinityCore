DELETE FROM `build_info` WHERE `build`=41793;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(41793,9,1,5,NULL,NULL,'B3B47DA3B7615570742A55B96614EE1C',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=41793 WHERE `gamebuild`=41488;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '41793';
