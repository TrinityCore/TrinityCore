DELETE FROM `build_info` WHERE `build`=42560;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(42560,9,2,0,NULL,NULL,'115FE8C38A8D67CA4664BB192E0F0DFE',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=42560 WHERE `gamebuild`=42538;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '42560';
