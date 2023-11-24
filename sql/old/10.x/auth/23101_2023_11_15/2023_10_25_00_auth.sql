DELETE FROM `build_info` WHERE `build`=51886;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(51886,10,1,7,NULL,NULL,'09CF8919FD2EABDEAEBC0C810F53B511',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=51886 WHERE `gamebuild`=51754;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '51886';
