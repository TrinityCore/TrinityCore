DELETE FROM `build_info` WHERE `build`=49444;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(49444,10,1,0,NULL,NULL,'363B2B05285BDD8857419D2866316D3C',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=49444 WHERE `gamebuild`=49426;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '49444';
