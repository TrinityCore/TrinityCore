DELETE FROM `build_info` WHERE `build`=48676;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(48676,10,0,7,NULL,NULL,'E059FB74DFF6438CC20C7F28900F64CA',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=48676 WHERE `gamebuild`=48526;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '48676';
