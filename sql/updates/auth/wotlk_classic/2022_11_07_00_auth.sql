DELETE FROM `build_info` WHERE `build`=46368;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(46368,3,4,0,NULL,NULL,'B4CB2D7C7A4F46D11078CA7E8BCFD806',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=46368 WHERE `gamebuild`=45942;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '46368';