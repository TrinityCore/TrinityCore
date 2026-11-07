DELETE FROM `build_info` WHERE `build`=54673;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(54673,10,2,7,NULL,NULL,'AF8B9C8A9C6128498E85228B965A004D',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=54673 WHERE `gamebuild`=54630;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '54673';
