DELETE FROM `build_info` WHERE `build`=51972;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(51972,10,1,7,NULL,NULL,'444DC7EF3544B6670C18884DADA00428',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=51972 WHERE `gamebuild`=51886;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '51972';
