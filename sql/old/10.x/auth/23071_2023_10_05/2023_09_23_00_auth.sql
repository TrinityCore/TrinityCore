DELETE FROM `build_info` WHERE `build`=51485;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(51485,10,1,7,NULL,NULL,'EC549E1D0A5DD85C03E7A9D93B7DC6D1',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=51485 WHERE `gamebuild`=51421;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '51485';
