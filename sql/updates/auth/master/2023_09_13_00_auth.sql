DELETE FROM `build_info` WHERE `build`=51313;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(51313,10,1,7,NULL,NULL,'35419ED0AB16735CF720858F45DC300C',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=51313 WHERE `gamebuild`=51261;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '51313';
