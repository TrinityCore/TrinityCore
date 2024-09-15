DELETE FROM `build_info` WHERE `build`=54847;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(54847,10,2,7,NULL,NULL,'32FDA0353160EC51EB36195CFACEF2B7',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=54847 WHERE `gamebuild`=54762;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '54847';
