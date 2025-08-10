DELETE FROM `build_info` WHERE `build`=49801;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(49801,10,1,0,NULL,NULL,'0832179567B66CA85DBD5678B604C683',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=49801 WHERE `gamebuild`=49741;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '49801';
