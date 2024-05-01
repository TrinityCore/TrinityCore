DELETE FROM `build_info` WHERE `build`=54358;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(54358,10,2,6,NULL,NULL,'89C733D366E845FB9264404CD48CCA89',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=54358 WHERE `gamebuild`=54205;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '54358';
