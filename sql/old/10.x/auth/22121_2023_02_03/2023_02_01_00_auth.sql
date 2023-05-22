DELETE FROM `build_info` WHERE `build`=47884;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(47884,10,0,5,NULL,NULL,'2B7A002BC359F2C31104BC2DE04302BF',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=47884 WHERE `gamebuild`=47871;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '47884';
