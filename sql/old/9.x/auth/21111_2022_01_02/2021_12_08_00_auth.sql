DELETE FROM `build_info` WHERE `build`=41359;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(41359,9,1,5,NULL,NULL,'5F8D7F2A690A4375A1B52A28D6D681FA',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=41359 WHERE `gamebuild`=41323;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '41359';
