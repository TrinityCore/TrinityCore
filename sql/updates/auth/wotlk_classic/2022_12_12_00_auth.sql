DELETE FROM `build_info` WHERE `build`=46902;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(46902,3,4,0,NULL,NULL,'8FD406FE6A7F4A5553AE82368CC36993',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=46902 WHERE `gamebuild`=46779;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '46902';
