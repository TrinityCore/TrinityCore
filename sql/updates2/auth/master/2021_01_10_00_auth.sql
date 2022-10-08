DELETE FROM `build_info` WHERE `build`=37142;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(37142,9,0,2,NULL,NULL,'5D9CFB3139F0D1B6C2B304261F9EABC9',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=37142 WHERE `gamebuild`=36949;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '37142';
