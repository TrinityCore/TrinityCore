DELETE FROM `build_info` WHERE `build` IN (56311);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`, `macArmAuthSeed`, `winChecksumSeed`,`macChecksumSeed`) VALUES
(56311,11,0,2,NULL,NULL,'AC6415575AEE4D32735FFAD0C57226B2',NULL,'412D3200715AAFDC0522DF031A941F0E',NULL, NULL);
