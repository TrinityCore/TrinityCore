DELETE FROM `build_info` WHERE `build`=48526;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(48526,10,0,5,NULL,NULL,'D5B7D3303A2A741E6913EE1AEB0BCB65',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=48526 WHERE `gamebuild`=48397;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '48526';
