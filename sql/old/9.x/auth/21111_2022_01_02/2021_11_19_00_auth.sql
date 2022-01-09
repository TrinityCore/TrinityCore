DELETE FROM `build_info` WHERE `build`=41079;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(41079,9,1,5,NULL,NULL,'F8853CF823BC0BBE8A9677A762DFAEE1',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=41079 WHERE `gamebuild`=41031;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '41079';
