DELETE FROM `build_info` WHERE `build`=50504;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(50504,10,1,5,NULL,NULL,'7D5FD20C0B32C9AF5DD65433B391D49C',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=50504 WHERE `gamebuild`=50469;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '50504';
