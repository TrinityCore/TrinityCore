DELETE FROM `build_info` WHERE `build`=46779;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(46779,3,4,0,NULL,NULL,'F83CF04FC0B3DBE82BE09E34B2E30ACD',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=46779 WHERE `gamebuild`=46368;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '46779';
