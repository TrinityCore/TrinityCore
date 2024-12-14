DELETE FROM `build_info` WHERE `build` IN (54577,54601,54604);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(54577,10,2,7,NULL,NULL,'CBBBBBFFB2C652F0F4A7848D86E1B063',NULL,NULL,NULL),
(54601,10,2,7,NULL,NULL,'F8B866CF7DB9A12273F35B3929627375',NULL,NULL,NULL),
(54604,10,2,7,NULL,NULL,'A5FF4CE535F69D4D7F638CB2C11F2243',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=54604 WHERE `gamebuild`=54499;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '54604';
