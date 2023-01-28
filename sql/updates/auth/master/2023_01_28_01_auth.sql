DELETE FROM `build_info` WHERE `build`=47871;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(47871,10,0,5,NULL,NULL,'8E4F7D30EE4982B02B3B3F8837C2C4F2',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=47871 WHERE `gamebuild`=47849;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '47871';
