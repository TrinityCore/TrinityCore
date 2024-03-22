DELETE FROM `build_info` WHERE `build`=53863;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(53863,4,4,0,NULL,NULL,'6052C8F657F398912862CFD7010DBC73',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=53863 WHERE `gamebuild`=53750;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` INT UNSIGNED NOT NULL DEFAULT '53863';
