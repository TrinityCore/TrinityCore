DELETE FROM `build_info` WHERE `build`=55056;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(55056,4,4,0,NULL,NULL,'209BEEBBBFE6AA3AE491D9D1F1A7C98A',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=55056 WHERE `gamebuild`=55006;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` INT UNSIGNED NOT NULL DEFAULT '55056';
