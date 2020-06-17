DELETE FROM `build_info` WHERE `build`=33775;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(33775,8,3,0,NULL,NULL,'B826300A8449ED0F6EF16EA747FA2D2E',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=33775 WHERE `gamebuild`=33724;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '33775';
