DELETE FROM `build_info` WHERE `build` IN (56263);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(56263,11,0,2,NULL,NULL,'EA8472C99236CC617BF518A924014D56',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=56263 WHERE `gamebuild`=56196;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '56263';
