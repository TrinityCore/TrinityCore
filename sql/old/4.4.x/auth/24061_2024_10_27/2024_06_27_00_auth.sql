DELETE FROM `build_info` WHERE `build`=55262;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(55262,4,4,0,NULL,NULL,'EB4B58AF1B3B79DDD9E2477BA1375D42',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=55262 WHERE `gamebuild`=55141;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` INT UNSIGNED NOT NULL DEFAULT '55262';
