DELETE FROM `build_info` WHERE `build`=54736;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(54736,10,2,7,NULL,NULL,'FE58F039D91E1C248886A2828127CA2F',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=54736 WHERE `gamebuild`=54717;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '54736';
