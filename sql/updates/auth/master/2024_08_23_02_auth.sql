DELETE FROM `build_info` WHERE `build` IN (56288);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`, `macArmAuthSeed`, `winChecksumSeed`,`macChecksumSeed`) VALUES
    (56288,11,0,2,NULL,NULL,NULL,NULL,'41710C793EF021721F14B06EC1896D3F', NULL, NULL);
