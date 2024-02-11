DELETE FROM `build_info` WHERE `build`=52148;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(52148,10,2,0,NULL,NULL,'8A969717C8CDC6E7FF4C54D5CB00C224',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=52148 WHERE `gamebuild`=52129;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '52148';
