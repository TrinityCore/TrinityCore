DELETE FROM `build_info` WHERE `build`=48999;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(48999,10,0,7,NULL,NULL,'79BA6FF0F9672EEF875F64155C8B62D4',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=48999 WHERE `gamebuild`=48966;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '48999';
