DELETE FROM `build_info` WHERE `build`=44325;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(44325,9,2,5,NULL,NULL,'138A7D524D268A7F9934C3D148E8F01B',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=44325 WHERE `gamebuild`=44232;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '44325';
