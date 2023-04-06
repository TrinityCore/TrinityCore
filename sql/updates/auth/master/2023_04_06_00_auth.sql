DELETE FROM `build_info` WHERE `build`=48966;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(48966,10,0,7,NULL,NULL,'823142CA131FBB715FF55D4343E55C6D',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=48966 WHERE `gamebuild`=48892;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '48966';
