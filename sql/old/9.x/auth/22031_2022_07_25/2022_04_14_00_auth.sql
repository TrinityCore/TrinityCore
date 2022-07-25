DELETE FROM `build_info` WHERE `build`=43206;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(43206,9,2,0,NULL,NULL,'DDE806532C7704FFB75F256DC5F1F3D9',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=43206 WHERE `gamebuild`=43114;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '43206';
