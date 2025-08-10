-- fix underrot path ids
SET @CGUID := 850720;

-- ref 28828c4d8f208088544f55a4ecde338d1423070a
SET @GUID_OFFSET = 88;
SET @OLD_PATH := (@CGUID+@GUID_OFFSET+1) * 10;
SET @NEW_PATH := ((@CGUID+@GUID_OFFSET) * 10) << 3;
UPDATE `waypoint_data` SET `id`=@NEW_PATH WHERE `id`=@OLD_PATH;
UPDATE `creature_addon` SET `path_id`=@NEW_PATH WHERE `path_id`=@OLD_PATH;

-- ref db6c97b1061e059b9906f220e62e1ebd2292d835
SET @GUID_OFFSET = 29;
SET @OLD_PATH := (@CGUID+@GUID_OFFSET) * 10;
SET @NEW_PATH := ((@CGUID+@GUID_OFFSET) * 10) << 3;
UPDATE `waypoint_data` SET `id`=@NEW_PATH WHERE `id`=@OLD_PATH;
UPDATE `creature_addon` SET `path_id`=@NEW_PATH WHERE `path_id`=@OLD_PATH;

SET @GUID_OFFSET = 13;
SET @OLD_PATH := (@CGUID+@GUID_OFFSET) * 10;
SET @NEW_PATH := ((@CGUID+@GUID_OFFSET) * 10) << 3;
UPDATE `waypoint_data` SET `id`=@NEW_PATH WHERE `id`=@OLD_PATH;
UPDATE `creature_addon` SET `path_id`=@NEW_PATH WHERE `path_id`=@OLD_PATH;

SET @GUID_OFFSET = 18;
SET @OLD_PATH := (@CGUID+@GUID_OFFSET) * 10;
SET @NEW_PATH := ((@CGUID+@GUID_OFFSET) * 10) << 3;
UPDATE `waypoint_data` SET `id`=@NEW_PATH WHERE `id`=@OLD_PATH;
UPDATE `creature_addon` SET `path_id`=@NEW_PATH WHERE `path_id`=@OLD_PATH;

SET @GUID_OFFSET = 59;
SET @OLD_PATH := (@CGUID+@GUID_OFFSET) * 10;
SET @NEW_PATH := ((@CGUID+@GUID_OFFSET) * 10) << 3;
UPDATE `waypoint_data` SET `id`=@NEW_PATH WHERE `id`=@OLD_PATH;
UPDATE `creature_addon` SET `path_id`=@NEW_PATH WHERE `path_id`=@OLD_PATH;

SET @GUID_OFFSET = 73;
SET @OLD_PATH := (@CGUID+@GUID_OFFSET) * 10;
SET @NEW_PATH := ((@CGUID+@GUID_OFFSET) * 10) << 3;
UPDATE `waypoint_data` SET `id`=@NEW_PATH WHERE `id`=@OLD_PATH;
UPDATE `creature_addon` SET `path_id`=@NEW_PATH WHERE `path_id`=@OLD_PATH;

SET @GUID_OFFSET = 84;
SET @OLD_PATH := (@CGUID+@GUID_OFFSET) * 10;
SET @NEW_PATH := ((@CGUID+@GUID_OFFSET) * 10) << 3;
UPDATE `waypoint_data` SET `id`=@NEW_PATH WHERE `id`=@OLD_PATH;
UPDATE `creature_addon` SET `path_id`=@NEW_PATH WHERE `path_id`=@OLD_PATH;

SET @GUID_OFFSET = 52;
SET @OLD_PATH := (@CGUID+@GUID_OFFSET) * 10;
SET @NEW_PATH := ((@CGUID+@GUID_OFFSET) * 10) << 3;
UPDATE `waypoint_data` SET `id`=@NEW_PATH WHERE `id`=@OLD_PATH;
UPDATE `creature_addon` SET `path_id`=@NEW_PATH WHERE `path_id`=@OLD_PATH;

SET @GUID_OFFSET = 131;
SET @OLD_PATH := (@CGUID+@GUID_OFFSET) * 10;
SET @NEW_PATH := ((@CGUID+@GUID_OFFSET) * 10) << 3;
UPDATE `waypoint_data` SET `id`=@NEW_PATH WHERE `id`=@OLD_PATH;
UPDATE `creature_addon` SET `path_id`=@NEW_PATH WHERE `path_id`=@OLD_PATH;

SET @GUID_OFFSET = 85;
SET @OLD_PATH := (@CGUID+@GUID_OFFSET) * 10;
SET @NEW_PATH := ((@CGUID+@GUID_OFFSET) * 10) << 3;
UPDATE `waypoint_data` SET `id`=@NEW_PATH WHERE `id`=@OLD_PATH;
UPDATE `creature_addon` SET `path_id`=@NEW_PATH WHERE `path_id`=@OLD_PATH;

SET @GUID_OFFSET = 120;
SET @OLD_PATH := (@CGUID+@GUID_OFFSET) * 10;
SET @NEW_PATH := ((@CGUID+@GUID_OFFSET) * 10) << 3;
UPDATE `waypoint_data` SET `id`=@NEW_PATH WHERE `id`=@OLD_PATH;
UPDATE `creature_addon` SET `path_id`=@NEW_PATH WHERE `path_id`=@OLD_PATH;

SET @GUID_OFFSET = 125;
SET @OLD_PATH := (@CGUID+@GUID_OFFSET) * 10;
SET @NEW_PATH := ((@CGUID+@GUID_OFFSET) * 10) << 3;
UPDATE `waypoint_data` SET `id`=@NEW_PATH WHERE `id`=@OLD_PATH;
UPDATE `creature_addon` SET `path_id`=@NEW_PATH WHERE `path_id`=@OLD_PATH;

SET @GUID_OFFSET = 100;
SET @OLD_PATH := (@CGUID+@GUID_OFFSET) * 10;
SET @NEW_PATH := ((@CGUID+@GUID_OFFSET) * 10) << 3;
UPDATE `waypoint_data` SET `id`=@NEW_PATH WHERE `id`=@OLD_PATH;
UPDATE `creature_addon` SET `path_id`=@NEW_PATH WHERE `path_id`=@OLD_PATH;
