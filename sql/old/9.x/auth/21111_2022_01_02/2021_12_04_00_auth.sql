DELETE FROM `build_info` WHERE `build`=41323;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(41323,9,1,5,NULL,NULL,'E53D0DF1FAC1A59A1C8071B295A04A1D',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=41323 WHERE `gamebuild`=41288;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '41323';
