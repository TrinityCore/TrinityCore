DELETE FROM `build_info` WHERE `build`=54717;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(54717,10,2,7,NULL,NULL,'862BBA15158DFF6B56BCF71C1B34D41A',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=54717 WHERE `gamebuild`=54673;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '54717';
