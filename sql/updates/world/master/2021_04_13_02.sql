-- DB update 2021_04_13_01 -> 2021_04_13_02
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_13_01';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_13_01 2021_04_13_02 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1618114340791954300'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1618114340791954300');

UPDATE `gameobject` SET `id` = 24681 WHERE `guid` = 11051;

UPDATE `gameobject` SET `id` = 24681 WHERE `guid` = 11040;

UPDATE `gameobject` SET `id` = 24681 WHERE `guid` = 11043;

UPDATE `gameobject` SET `id` = 24681 WHERE `guid` = 11045;

UPDATE `gameobject` SET `id` = 24681 WHERE `guid` = 11046;

UPDATE `gameobject` SET `id` = 24681 WHERE `guid` = 11047;

UPDATE `gameobject` SET `id` = 24681 WHERE `guid` = 11048;

UPDATE `gameobject` SET `id` = 24681 WHERE `guid` = 11049;

UPDATE `gameobject` SET `id` = 24681 WHERE `guid` = 11050;

UPDATE `gameobject` SET `id` = 24681 WHERE `guid` = 11051;

UPDATE `gameobject` SET `id` = 24681 WHERE `guid` = 11052;

UPDATE `gameobject` SET `id` = 24681 WHERE `guid` = 11062;

UPDATE `gameobject` SET `id` = 24681 WHERE `guid` = 11063;

UPDATE `gameobject` SET `id` = 24681 WHERE `guid` = 11061;

UPDATE `gameobject` SET `id` = 24681 WHERE `guid` = 11060;

UPDATE `gameobject` SET `id` = 24681 WHERE `guid` = 11132;

UPDATE `gameobject` SET `id` = 24681 WHERE `guid` = 11053;


UPDATE `gameobject` SET `id` = 24681 WHERE `guid` = 11057;

UPDATE `gameobject` SET `id` = 24681 WHERE `guid` = 11056;

UPDATE `gameobject` SET `id` = 24681 WHERE `guid` = 11055;

UPDATE `gameobject` SET `id` = 24681 WHERE `guid` = 11054;

DELETE FROM `gameobject` WHERE `guid` = 11042;

DELETE FROM `gameobject` WHERE `guid` = 11041;

DELETE FROM `gameobject` WHERE `guid` = 11044;

DELETE FROM `gameobject` WHERE `guid` = 11039;

DELETE FROM `gameobject` WHERE `guid` = 11058;

DELETE FROM `gameobject` WHERE `guid` = 11059;

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
