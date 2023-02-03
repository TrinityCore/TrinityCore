DELETE FROM `build_info` WHERE `build`=47631;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(47631,10,0,2,NULL,NULL,'F986AB91D0AEB20822EFB72F4256713C',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=47631 WHERE `gamebuild`=47213;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '47631';
