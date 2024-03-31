DELETE FROM `build_info` WHERE `build`=54027;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(54027,4,4,0,NULL,NULL,'2DE781D4918766E5C12FBC54D63A9195',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=54027 WHERE `gamebuild`=53863;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` INT UNSIGNED NOT NULL DEFAULT '54027';
