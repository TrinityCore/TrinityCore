DELETE FROM `build_info` WHERE `build`=32750;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(32750,8,2,5,NULL,NULL,'C5CB669F5A5B237D1355430877173207',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=32750 WHERE `gamebuild`=32722;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '32750';
