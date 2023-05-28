DELETE FROM `build_info` WHERE `build`=49741;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(49741,10,1,0,NULL,NULL,'0EF181E2BB0E946CF3B7422ADEB6CD1A',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=49741 WHERE `gamebuild`=49679;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '49741';
