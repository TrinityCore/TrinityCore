DELETE FROM `build_info` WHERE `build`=47967;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(47967,10,0,5,NULL,NULL,'CFE225D0089E224D9E7541D3B5C26478',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=47967 WHERE `gamebuild`=47936;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '47967';
