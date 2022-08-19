DELETE FROM `build_info` WHERE `build`=45114;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(45114,9,2,7,NULL,NULL,'D7AFE240BD00F06C30D0C2D16E54A8BE',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=45114 WHERE `gamebuild`=44908;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '45114';
