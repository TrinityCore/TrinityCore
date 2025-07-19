DELETE FROM `build_info` WHERE `build`=54904;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(54904,10,2,7,NULL,NULL,'09CBEC3C0DEA28BCA79F1FD9B879B0E3',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=54904 WHERE `gamebuild`=54847;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '54904';
