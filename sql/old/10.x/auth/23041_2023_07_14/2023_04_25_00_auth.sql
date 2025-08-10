DELETE FROM `build_info` WHERE `build`=49267;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(49267,10,0,7,NULL,NULL,'EEE77EA5A216E0731ADBB41AEFB1DF31',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=49267 WHERE `gamebuild`=48999;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '49267';
