DELETE FROM `build_info` WHERE `build`=36839;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(36839,9,0,2,NULL,NULL,'356EB4412B8EFCF72E3AF50D5181D529',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=36839 WHERE `gamebuild`=36753;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '36839';
