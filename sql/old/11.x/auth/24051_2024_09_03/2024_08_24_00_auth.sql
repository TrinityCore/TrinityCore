DELETE FROM `build_info` WHERE `build` IN (56311);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(56311,11,0,2,NULL,NULL,'AC6415575AEE4D32735FFAD0C57226B2',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=56311 WHERE `gamebuild`=56288;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '56311';
