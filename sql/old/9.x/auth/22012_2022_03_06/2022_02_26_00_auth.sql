DELETE FROM `build_info` WHERE `build`=42488;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(42488,9,2,0,NULL,NULL,'A78755E6928D83A271C5D1EE3CDB6F15',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=42488 WHERE `gamebuild`=42423;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '42488';
