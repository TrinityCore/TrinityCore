DELETE FROM `build_info` WHERE `build` IN (51187,51237);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(51187,10,1,7,NULL,NULL,'74E2055D3965269447B5CB1B31FC71C6',NULL,NULL,NULL),
(51237,10,1,7,NULL,NULL,'C8660A21B766646FBD67F481CFCF55C3',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=51237 WHERE `gamebuild`=51130;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '51237';
