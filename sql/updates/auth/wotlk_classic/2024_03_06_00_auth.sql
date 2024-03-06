DELETE FROM `build_info` WHERE `build`=53622;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(53622,3,4,3,NULL,NULL,'CCC0A843915F46992BB1A650B18CFD67',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=53622 WHERE `gamebuild`=52237;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '53622';
