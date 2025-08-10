DELETE FROM `build_info` WHERE `build`=42698;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(42698,9,2,0,NULL,NULL,'B4497B1CD11FC974C5FB09548AC27269',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=42698 WHERE `gamebuild`=42614;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '42698';
