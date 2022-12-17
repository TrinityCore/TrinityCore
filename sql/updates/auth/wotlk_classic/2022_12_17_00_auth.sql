DELETE FROM `build_info` WHERE `build`=47168;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(47168,3,4,0,NULL,NULL,'E760AC9726383C972F6AE7F79BFB4E8A',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=47168 WHERE `gamebuild`=46902;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '47168';
