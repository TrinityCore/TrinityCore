DELETE FROM `build_info` WHERE `build`=45942;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(45942,3,4,0,NULL,NULL,'902EC690E7349FB2C07D0FD1C6F10C26',NULL,NULL,NULL);

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '45942';
