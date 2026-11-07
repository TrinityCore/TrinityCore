DELETE FROM `build_info` WHERE `build`=55461;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(55461,10,2,7,NULL,NULL,'C4522674F854EFECC76C898EC9545099',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=55461 WHERE `gamebuild`=55261;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '55461';
