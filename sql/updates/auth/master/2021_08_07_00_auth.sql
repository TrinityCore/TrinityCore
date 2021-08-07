DELETE FROM `build_info` WHERE `build`=39653;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(39653,9,1,0,NULL,NULL,'10D015AB1EEB91310428D9C57EE24632',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=39653 WHERE `gamebuild`=38556;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '39653';
