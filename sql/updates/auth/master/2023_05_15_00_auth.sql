DELETE FROM `build_info` WHERE `build`=49570;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(49570,10,1,0,NULL,NULL,'B024DE67ACAEB9E8EE6DB38DC53E8281',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=49570 WHERE `gamebuild`=49474;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '49570';
