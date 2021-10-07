DELETE FROM `build_info` WHERE `build` IN (40120,40443);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(40120,9,1,0,NULL,NULL,'04F47EAEFD8BDEFE14AA0350EA336678','853F0F2985CEAED46DF422583CD07A7C',NULL,NULL),
(40443,9,1,0,NULL,NULL,'8597BB43E8AB38C85504E8BFB72ABBF5',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=40443 WHERE `gamebuild`=40120;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '40443';
