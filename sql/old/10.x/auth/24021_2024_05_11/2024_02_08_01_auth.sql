DELETE FROM `build_info` WHERE `build`=53262;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(53262,10,2,5,NULL,NULL,'614A72D53126348A4927EC0F53FD2B7A',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=53262 WHERE `gamebuild`=53212;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '53262';
