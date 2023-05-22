DELETE FROM `build_info` WHERE `build`=48892;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(48892,10,0,7,NULL,NULL,'AA31BF27458321B03A1A346964DD7B9D',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=48892 WHERE `gamebuild`=48865;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '48892';
