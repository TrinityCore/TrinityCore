DELETE FROM `build_info` WHERE `build`=53441;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(53441,10,2,5,NULL,NULL,'BFDD7D0FE87D5F75E6DEB4F5C99D7C99',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=53441 WHERE `gamebuild`=53262;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '53441';
