DELETE FROM `build_info` WHERE `build`=56014;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(56014,4,4,0,NULL,NULL,'89AD7A75E156374D41F0CC70455B2F6B',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=56014 WHERE `gamebuild`=55639;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` INT UNSIGNED NOT NULL DEFAULT '56014';
