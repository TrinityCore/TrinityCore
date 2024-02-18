DELETE FROM `build_info` WHERE `build`=52188;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(52188,10,2,0,NULL,NULL,'977DF9993E94855DED5E328BA7A2F21F',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=52188 WHERE `gamebuild`=52148;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '52188';
