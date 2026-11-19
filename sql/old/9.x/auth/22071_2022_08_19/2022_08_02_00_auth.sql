DELETE FROM `build_info` WHERE `build`=44908;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(44908,9,2,5,NULL,NULL,'BFFAEC40C9BCD591C7C959A9D5A8BA8C',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=44908 WHERE `gamebuild`=44730;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '44908';
