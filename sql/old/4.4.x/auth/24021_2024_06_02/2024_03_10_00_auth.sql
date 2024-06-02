DELETE FROM `build_info` WHERE `build`=53627;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(53627,4,4,0,NULL,NULL,'57F35840BA629BAC4717A901347C40F1',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=53627 WHERE `gamebuild`=53584;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '53627';
