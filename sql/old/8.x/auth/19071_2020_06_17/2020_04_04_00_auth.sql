DELETE FROM `build_info` WHERE `build`=33941;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(33941,8,3,0,NULL,NULL,'88AF1A36D2770D0A6CA086497096A889',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=33941 WHERE `gamebuild`=33775;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '33941';
