DELETE FROM `build_info` WHERE `build`=52649;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(52649,10,2,0,NULL,NULL,'D0B779FBECEBC1ED5A85D83F03C8A75B',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=52649 WHERE `gamebuild`=52607;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '52649';
