DELETE FROM `build_info` WHERE `build`=37176;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(37176,9,0,2,NULL,NULL,'3C725EA504EC3DAED143EB6FF3B48CDA',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=37176 WHERE `gamebuild`=37142;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '37176';
