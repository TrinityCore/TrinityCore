DELETE FROM `build_info` WHERE `build`=34220;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(34220,8,3,0,NULL,NULL,'B5E35B976C6BAF82505700E7D9666A2C',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=34220 WHERE `gamebuild`=33941;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '34220';
