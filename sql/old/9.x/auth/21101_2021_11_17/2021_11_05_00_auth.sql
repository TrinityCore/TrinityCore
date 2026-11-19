DELETE FROM `build_info` WHERE `build`=40906;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(40906,9,1,5,NULL,NULL,'F5FC259C8635488AFE0D0CD023F361D4',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=40906 WHERE `gamebuild`=40725;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '40906';
