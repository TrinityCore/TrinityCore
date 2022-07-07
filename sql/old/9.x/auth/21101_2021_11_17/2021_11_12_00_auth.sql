DELETE FROM `build_info` WHERE `build`=41031;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(41031,9,1,5,NULL,NULL,'019A0FACD6B0D6374B7BA69A5B677449',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=41031 WHERE `gamebuild`=40966;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '41031';
