-- DB update 2021_04_06_07 -> 2021_04_06_08
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_06_07';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_06_07 2021_04_06_08 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617688597765131400'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617688597765131400');

 -- Evolving Ectoplasm
UPDATE `creature` SET `position_z`=-57.160, `orientation`=1.591200 WHERE `guid`=86047;

-- Druid of the Fang
UPDATE `creature` SET `position_x`=-96.488, `position_y`=-262.308, `position_z`=-55.424, `orientation`=0.929340 WHERE `guid`=86048;

-- Evolving Ectoplasm
UPDATE `creature` SET `position_x`=-75.639, `position_y`=-142.529, `position_z`=-79.219, `orientation`=5.664870 WHERE `guid`=85900;

-- Deviate Shambler
UPDATE `creature` SET `position_x`=-69.525, `position_z`=-79.287, `orientation`=5.113810 WHERE `guid`=52598;


--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
