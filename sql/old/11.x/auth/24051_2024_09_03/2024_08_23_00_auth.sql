DELETE FROM `build_info` WHERE `build` IN (56288);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(56288,11,0,2,NULL,NULL,'03544E35D0480938E5C1238B3A26BDDD',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=56288 WHERE `gamebuild`=56263;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '56288';
