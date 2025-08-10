DELETE FROM `build_info` WHERE `build`=52393;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(52393,10,2,0,NULL,NULL,'B013ED23B7EF51B29A45594D9BBB0D03',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=52393 WHERE `gamebuild`=52301;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '52393';
