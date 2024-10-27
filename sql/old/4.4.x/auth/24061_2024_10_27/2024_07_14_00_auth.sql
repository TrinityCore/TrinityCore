DELETE FROM `build_info` WHERE `build`=55613;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(55613,4,4,0,NULL,NULL,'0BA3BFF2E324FE30D15BA8A88CF8738B',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=55613 WHERE `gamebuild`=55460;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` INT UNSIGNED NOT NULL DEFAULT '55613';
