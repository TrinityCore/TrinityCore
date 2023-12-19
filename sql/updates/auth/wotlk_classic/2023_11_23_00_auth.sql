DELETE FROM `build_info` WHERE `build`=52237;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(52237,3,4,3,NULL,NULL,'3BA993D54FD86EE03E6F81C8FBCE26B7',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=52237 WHERE `gamebuild`=51943;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '52237';
