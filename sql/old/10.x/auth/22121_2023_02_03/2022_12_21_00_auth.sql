DELETE FROM `build_info` WHERE `build`=47213;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(47213,10,0,2,NULL,NULL,'23C50D88CEAC0A8696ADDE8DD244D4A2',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=47213 WHERE `gamebuild`=47187;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '47213';
