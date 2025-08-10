DELETE FROM `build_info` WHERE `build` IN (55960);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(55960,11,0,0,NULL,NULL,'078C056CFC7B371BDE1BAF308E6C19AF',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=55960 WHERE `gamebuild`=55939;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '55960';
