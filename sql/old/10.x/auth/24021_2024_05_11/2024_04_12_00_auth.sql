DELETE FROM `build_info` WHERE `build`=54205;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(54205,10,2,6,NULL,NULL,'589D59EB3F0D6D77C2175D9302F78FDD',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=54205 WHERE `gamebuild`=54070;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '54205';
