DELETE FROM `build_info` WHERE `build`=51130;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(51130,10,1,5,NULL,NULL,'44CD2C91E4F0655DA387483726CE4035',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=51130 WHERE `gamebuild`=50791;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '51130';
