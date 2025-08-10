DELETE FROM `build_info` WHERE `build`=43971;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(43971,9,2,5,NULL,NULL,'681CF99E61FB0005A5C7D31D0AAD1ED9',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=43971 WHERE `gamebuild`=43345;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '43971';
