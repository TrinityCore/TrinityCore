DELETE FROM `build_info` WHERE `build`=50585;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(50585,10,1,5,NULL,NULL,'C4F7CC38A3B84935A485F7EDAD3E764B',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=50585 WHERE `gamebuild`=50504;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '50585';
