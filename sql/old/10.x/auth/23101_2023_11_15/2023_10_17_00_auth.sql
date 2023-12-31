DELETE FROM `build_info` WHERE `build`=51754;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(51754,10,1,7,NULL,NULL,'BED5A861C071AB41FEF6087E0C37BB1A',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=51754 WHERE `gamebuild`=51536;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '51754';
