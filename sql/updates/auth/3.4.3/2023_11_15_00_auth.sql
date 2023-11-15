DELETE FROM `build_info` WHERE `build`= 51943;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(51943,3,4,3,NULL,NULL,'926D8C2514A3FEBA84F0DEB031AE41CE',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=51943;
ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '51943';
