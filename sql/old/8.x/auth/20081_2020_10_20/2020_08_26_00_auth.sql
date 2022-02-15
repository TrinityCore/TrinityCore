DELETE FROM `build_info` WHERE `build`=35662;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(35662,8,3,7,NULL,NULL,'578BC94870C278CB6962F30E6DC203BB',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=35662 WHERE `gamebuild`=35435;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '35662';
