DELETE FROM `build_info` WHERE `build`=36753;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(36753,9,0,2,NULL,NULL,'386FDE8559B5EAD67B791B490B200B88',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=36753 WHERE `gamebuild`=35662;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '36753';
