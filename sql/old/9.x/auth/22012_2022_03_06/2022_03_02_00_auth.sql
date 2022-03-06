DELETE FROM `build_info` WHERE `build`=42538;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(42538,9,2,0,NULL,NULL,'71A7504BD53F8DE518F24265D37310AE',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=42538 WHERE `gamebuild`=42521;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '42538';
