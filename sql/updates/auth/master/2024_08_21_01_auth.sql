ALTER TABLE `build_info` ADD `macArmAuthSeed` varchar(32) NULL AFTER `mac64AuthSeed`;
DELETE FROM `build_info` WHERE `build` IN (56196);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`, `macArmAuthSeed`, `winChecksumSeed`,`macChecksumSeed`) VALUES
    (56196,11,0,2,NULL,NULL,'81FC14274BFF0347FFF9C8B1AA6BED9B',NULL,'778F6A5DF79A4EF1B86F651F3B303CE7', NULL, NULL);
