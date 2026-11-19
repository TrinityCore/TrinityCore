DELETE FROM `build_info` WHERE `build`=48865;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(48865,10,0,7,NULL,NULL,'4B774ABE7B34D6702571B4279A4B6A13',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=48865 WHERE `gamebuild`=48838;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '48865';
