DELETE FROM `build_info` WHERE `build`=52485;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(52485,10,2,0,NULL,NULL,'5805CEB4650730AE489258DD30E34441',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=52485 WHERE `gamebuild`=52393;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '52485';
