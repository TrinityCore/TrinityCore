-- DB update 2021_04_01_06 -> 2021_04_01_07
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_01_06';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_01_06 2021_04_01_07 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617016392531315494'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617016392531315494');

UPDATE creature_template SET InhabitType = 3 WHERE entry IN (
  3282, -- Venture Co. Mercenary
  3283, -- Venture Co. Enforcer
  3284, -- Venture Co. Drudger
  3445, -- Supervisor Lugwizzle
  5836  -- Engineer Whirleygig
);



--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
