DELETE FROM `build_info` WHERE `build`=43114;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(43114,9,2,0,NULL,NULL,'F75C9380CCB24A48A24EEE52C1594A7E',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=43114 WHERE `gamebuild`=42979;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '43114';
