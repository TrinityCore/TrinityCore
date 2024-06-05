DELETE FROM `build_info` WHERE `build`=55006;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(55006,4,4,0,NULL,NULL,'D13B75D1E7848DFBB61AB5D9FEE51B49',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=55006 WHERE `gamebuild`=54901;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` INT UNSIGNED NOT NULL DEFAULT '55006';
