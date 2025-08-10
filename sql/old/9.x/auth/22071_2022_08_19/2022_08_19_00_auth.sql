DELETE FROM `build_info` WHERE `build`=45161;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(45161,9,2,7,NULL,NULL,'74BD2E787A98B145B063BDA9A98F6CBD',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=45161 WHERE `gamebuild`=45114;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '45161';
