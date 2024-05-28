DELETE FROM `build_info` WHERE `build`=54737;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(54737,4,4,0,NULL,NULL,'81E29E958CA39EE7BF0685B548A58B51',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=54737 WHERE `gamebuild`=54027;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` INT UNSIGNED NOT NULL DEFAULT '54737';
