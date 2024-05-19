DELETE FROM `build_info` WHERE `build`=54499;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(54499,10,2,6,NULL,NULL,'6AC1F6180FC4C390F782DB933BD83326',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=54499 WHERE `gamebuild`=54358;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '54499';
