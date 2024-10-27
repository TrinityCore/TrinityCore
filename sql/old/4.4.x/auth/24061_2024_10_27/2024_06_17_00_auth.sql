DELETE FROM `build_info` WHERE `build`=55141;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(55141,4,4,0,NULL,NULL,'102810005F13A3440705DE344DF5633F',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=55141 WHERE `gamebuild`=55056;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` INT UNSIGNED NOT NULL DEFAULT '55141';
