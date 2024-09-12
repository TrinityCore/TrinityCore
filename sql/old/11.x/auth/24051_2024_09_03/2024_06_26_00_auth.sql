DELETE FROM `build_info` WHERE `build`=55261;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(55261,10,2,7,NULL,NULL,'84E153A3DD1F8249274B91047AAC7AED',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=55261 WHERE `gamebuild`=55165;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '55261';
