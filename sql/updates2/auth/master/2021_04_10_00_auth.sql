UPDATE `build_info` SET `mac64AuthSeed`='024C9BE7E44237B7E81C6D42E678D433' WHERE `build`=37474;

DELETE FROM `build_info` WHERE `build`=38134;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(38134,9,0,5,NULL,NULL,'32275ED0F13B357C28BDB0E611EF9E31',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=38134 WHERE `gamebuild`=37474;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '38134';
