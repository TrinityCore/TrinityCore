DELETE FROM `build_info` WHERE `build`=43345;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(43345,9,2,0,NULL,NULL,'D911ABFCDA030DEE8CAF4EE3F60DEE13',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=43345 WHERE `gamebuild`=43340;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '43345';
