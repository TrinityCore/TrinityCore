DELETE FROM `build_info` WHERE `build` IN (56313);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(56313,11,0,2,NULL,NULL,'EAF769009A9AD3B1AA0414E1C344074B',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=56313 WHERE `gamebuild`=56311;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '56313';
