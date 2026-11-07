DELETE FROM `build_info` WHERE `build`=50622;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(50622,10,1,5,NULL,NULL,'D23A26FD75FD9A6073EB7060AA28E6A7',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=50622 WHERE `gamebuild`=50585;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '50622';
