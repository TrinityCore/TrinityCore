DELETE FROM `build_info` WHERE `build`=53584;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(53584,10,2,5,NULL,NULL,'CDD7A93659A03460B5A6CE1C4ACE5554',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=53584 WHERE `gamebuild`=53441;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '53584';
