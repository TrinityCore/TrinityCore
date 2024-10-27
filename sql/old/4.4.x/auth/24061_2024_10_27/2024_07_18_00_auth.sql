DELETE FROM `build_info` WHERE `build`=55639;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(55639,4,4,0,NULL,NULL,'FFD74533A9D95E1D38C972BA4F351B8D',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=55639 WHERE `gamebuild`=55613;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` INT UNSIGNED NOT NULL DEFAULT '55639';
