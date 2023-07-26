DELETE FROM `build_info` WHERE `build`=50469;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(50469,10,1,5,NULL,NULL,'1768CCB6589E16AB3BEFA9D608A393A2',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=50469 WHERE `gamebuild`=50467;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '50469';
