DELETE FROM `build_info` WHERE `build`=53877;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(53877,10,2,6,NULL,NULL,'16320F95B63846A2276E1D2612C34AD4',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=53877 WHERE `gamebuild`=53840;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '53877';
