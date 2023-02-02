DELETE FROM `build_info` WHERE `build`=47936;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(47936,10,0,5,NULL,NULL,'179D3DC3235629D07113A9B3867F97A7',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=47936 WHERE `gamebuild`=47884;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '47936';
