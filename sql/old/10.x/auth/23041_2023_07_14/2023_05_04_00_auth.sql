DELETE FROM `build_info` WHERE `build` IN (49318,49407,49426);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(49318,10,1,0,NULL,NULL,'AF439AEE62EE48B36C1725111E3D9BBF',NULL,NULL,NULL),
(49407,10,1,0,NULL,NULL,'6413820DC9885BB0693B37090CBB2F30',NULL,NULL,NULL),
(49426,10,1,0,NULL,NULL,'D85EDFBFE9A94A55E2B4510BE41C19B2',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=49426 WHERE `gamebuild`=49343;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '49426';
