DELETE FROM `build_info` WHERE `build`=50747;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(50747,10,1,5,NULL,NULL,'2D3C386A9C45C27304ED3A3C6EB3F7C8',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=50747 WHERE `gamebuild`=50622;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '50747';
