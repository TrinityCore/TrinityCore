DELETE FROM `build_info` WHERE `build` IN (56162);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(56162,11,0,2,NULL,NULL,'6F5C93BA436665A94DB67CE5361D4EA8',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=56162 WHERE `gamebuild`=56110;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '56162';
