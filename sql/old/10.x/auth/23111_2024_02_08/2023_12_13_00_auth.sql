DELETE FROM `build_info` WHERE `build`=52545;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(52545,10,2,0,NULL,NULL,'FB52179A8355A46EDBFBDC8E8E5CDAFD',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=52545 WHERE `gamebuild`=52485;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '52545';
