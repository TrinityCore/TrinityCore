DELETE FROM `build_info` WHERE `build`=41488;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(41488,9,1,5,NULL,NULL,'1BC91EC368705815F3F532B553DAD981',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=41488 WHERE `gamebuild`=41359;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '41488';
