DELETE FROM `build_info` WHERE `build`=50791;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(50791,10,1,5,NULL,NULL,'0BE7D0BB07EF37C25CBC682409091EA0',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=50791 WHERE `gamebuild`=50747;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '50791';
