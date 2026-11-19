--
-- Table structure for table `build_auth_key`
--
DROP TABLE IF EXISTS `build_auth_key`;
CREATE TABLE `build_auth_key` (
  `build` int NOT NULL,
  `platform` char(4) CHARACTER SET ascii COLLATE ascii_bin NOT NULL,
  `arch` char(4) CHARACTER SET ascii COLLATE ascii_bin NOT NULL,
  `type` char(4) CHARACTER SET ascii COLLATE ascii_bin NOT NULL,
  `key` binary(16) NOT NULL,
  PRIMARY KEY (`build`,`platform`,`arch`,`type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `build_executable_hash`
--
DROP TABLE IF EXISTS `build_executable_hash`;
CREATE TABLE `build_executable_hash` (
  `build` int NOT NULL,
  `platform` char(4) CHARACTER SET ascii COLLATE ascii_bin NOT NULL,
  `executableHash` binary(20) NOT NULL,
  PRIMARY KEY (`build`,`platform`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

INSERT INTO `build_auth_key` SELECT `build`,'Win','x86','WoW',UNHEX(`winAuthSeed`) FROM `build_info` WHERE LENGTH(`winAuthSeed`)=32;
INSERT INTO `build_auth_key` SELECT `build`,'Win','x64','WoW',UNHEX(`win64AuthSeed`) FROM `build_info` WHERE LENGTH(`win64AuthSeed`)=32;
INSERT INTO `build_auth_key` SELECT `build`,'Mac','x64','WoW',UNHEX(`mac64AuthSeed`) FROM `build_info` WHERE LENGTH(`mac64AuthSeed`)=32;
INSERT INTO `build_auth_key` SELECT `build`,'Mac','A64','WoW',UNHEX(`macArmAuthSeed`) FROM `build_info` WHERE LENGTH(`macArmAuthSeed`)=32;

INSERT INTO `build_executable_hash` SELECT `build`,'Win',UNHEX(`winChecksumSeed`) FROM `build_info` WHERE LENGTH(`winChecksumSeed`)=40;
INSERT INTO `build_executable_hash` SELECT `build`,'OSX',UNHEX(`macChecksumSeed`) FROM `build_info` WHERE LENGTH(`macChecksumSeed`)=40;

ALTER TABLE `build_info`
  DROP `winAuthSeed`,
  DROP `win64AuthSeed`,
  DROP `mac64AuthSeed`,
  DROP `macArmAuthSeed`,
  DROP `winChecksumSeed`,
  DROP `macChecksumSeed`;
