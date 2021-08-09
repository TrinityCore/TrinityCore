-- DB update 2021_02_13_01 -> 2021_02_13_02
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_13_01';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_13_01 2021_02_13_02 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1612773554792500294'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1612773554792500294');

-- Lower respawn of items for quest Barov Family Fortune

UPDATE `gameobject` SET `spawntimesecs`=2 WHERE `guid` IN
(
43221, -- The Deed to Brill
43222, -- The Deed to Caer Darrow
43223, -- The Deed to Southshore
43224 -- The Deed to Tarren Mill
);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
