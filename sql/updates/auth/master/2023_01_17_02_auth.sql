DELETE FROM `build_info` WHERE `build`=47657;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(47657,10,0,2,NULL,NULL,'179D3DC3235629D07113A9B3867F97A7',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=47657 WHERE `gamebuild`=47631;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '47657';
