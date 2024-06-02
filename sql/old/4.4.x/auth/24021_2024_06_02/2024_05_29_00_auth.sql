DELETE FROM `build_info` WHERE `build`=54851;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(54851,4,4,0,NULL,NULL,'04721BCF80465E14498799C00B32D646',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=54851 WHERE `gamebuild`=54737;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` INT UNSIGNED NOT NULL DEFAULT '54851';
