DELETE FROM `build_info` WHERE `build`=37474;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(37474,9,0,2,NULL,NULL,'0DE685BBB0551086E7FBDC0B4BB06A5B',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=37474 WHERE `gamebuild`=37176;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '37474';
