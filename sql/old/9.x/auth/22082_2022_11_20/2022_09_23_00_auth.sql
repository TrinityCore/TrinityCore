DELETE FROM `build_info` WHERE `build`=45745;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(45745,9,2,7,NULL,NULL,'0F6DC90161694D765A595A3AF603166B',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=45745 WHERE `gamebuild`=45338;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '45745';
