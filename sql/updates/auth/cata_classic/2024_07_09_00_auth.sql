DELETE FROM `build_info` WHERE `build`=55460;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(55460,4,4,0,NULL,NULL,'E5455F750394046CC9BD2ED0397F7418',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=55460 WHERE `gamebuild`=55262;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` INT UNSIGNED NOT NULL DEFAULT '55460';
