UPDATE `build_info` SET `mac64AuthSeed`='853F0F2985CEAED46DF422583CD07A7C' WHERE `build`=40120;

DELETE FROM `build_info` WHERE `build`=40120;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(40443,9,1,0,NULL,NULL,'8597BB43E8AB38C85504E8BFB72ABBF5',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=40443 WHERE `gamebuild`=40120;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '40443';
