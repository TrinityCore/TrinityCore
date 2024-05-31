DELETE FROM `build_info` WHERE `build`=53840;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(53840,10,2,6,NULL,NULL,'AC97D745C60DD3DC5F973E55C0E3649E',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=53840 WHERE `gamebuild`=53584;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '53840';
