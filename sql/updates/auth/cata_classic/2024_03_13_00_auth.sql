DELETE FROM `build_info` WHERE `build`=53750;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(53750,4,4,0,NULL,NULL,'E33BA2DF1C239AB1B539FE1A01FC82B1',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=53750 WHERE `gamebuild`=53627;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` INT UNSIGNED NOT NULL DEFAULT '53750';
