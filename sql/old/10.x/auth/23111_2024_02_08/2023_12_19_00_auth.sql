DELETE FROM `build_info` WHERE `build`=52607;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(52607,10,2,0,NULL,NULL,'8F002E4AADCAEABB08ABC2880B31AD60',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=52607 WHERE `gamebuild` IN(52545, 52485);

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '52607';
