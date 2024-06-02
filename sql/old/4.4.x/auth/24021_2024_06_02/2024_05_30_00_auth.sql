DELETE FROM `build_info` WHERE `build`=54901;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(54901,4,4,0,NULL,NULL,'AB840E833490435689D5832D91A70871',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=54901 WHERE `gamebuild`=54851;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` INT UNSIGNED NOT NULL DEFAULT '54901';
