DELETE FROM `build_info` WHERE `build`=50401;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(50401,10,1,5,NULL,NULL,'3EEF52D902CCE81D16D0E255F0AA4938',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=50401 WHERE `gamebuild`=50000;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '50401';
