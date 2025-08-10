DELETE FROM `build_info` WHERE `build`=54630;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(54630,10,2,7,NULL,NULL,'F37935510BA6B559363C160E1DF18230',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=54630 WHERE `gamebuild`=54604;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '54630';
