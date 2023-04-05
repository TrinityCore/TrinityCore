DELETE FROM `build_info` WHERE `build`=48069;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(48069,10,0,5,NULL,NULL,'558CDF958FA082E95849779C7C6945E5',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=48069 WHERE `gamebuild`=48001;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '48069';
