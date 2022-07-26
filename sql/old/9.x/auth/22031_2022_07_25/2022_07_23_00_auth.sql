DELETE FROM `build_info` WHERE `build`=44730;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(44730,9,2,5,NULL,NULL,'FC0B18C47BB4C79F4300CA0FF3E5CAC7',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=44730 WHERE `gamebuild`=44325;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '44730';
