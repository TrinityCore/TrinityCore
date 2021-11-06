DELETE FROM `build_info` WHERE `build`=40944;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(40944,9,1,5,NULL,NULL,'368FC7FABAF487A8A049C11970657074',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=40944 WHERE `gamebuild`=40906;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '40944';
