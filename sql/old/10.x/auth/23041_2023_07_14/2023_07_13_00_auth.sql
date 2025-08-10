DELETE FROM `build_info` WHERE `build`=50438;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(50438,10,1,5,NULL,NULL,'0B5F68F06B129CB4C57702F6D30F260B',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=50438 WHERE `gamebuild`=50401;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '50438';
