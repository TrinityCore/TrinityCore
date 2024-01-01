DELETE FROM `build_info` WHERE `build`=49890;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(49890,10,1,0,NULL,NULL,'22A5B8A1EB797A64995F705B3DBCB14C',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=49890 WHERE `gamebuild`=49801;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '49890';
