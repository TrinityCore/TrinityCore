-- DB update 2021_04_11_07 -> 2021_04_11_08
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_11_07';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_11_07 2021_04_11_08 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617726900389263800'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617726900389263800');

DELETE FROM `spell_dbc` WHERE (`ID` = 46393);
INSERT INTO `spell_dbc` VALUES (46393, 0, 0, 0, 738213888, 1024, 0, 2048, 131072, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 524288, 0, 0, 101, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 6, 6, 0, 1, 1, 0, 0, 0, 0, 99, 6, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 87, 191, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2615, 0, 0, 'Brutal Assault','','','','','','','','', 0, 0, 0, 0, 0, 0, 0, 16712190,'','','','','','','','','', 0, 0, 0, 0, 0, 0, 0, 16712190, 'The strength of the enemy bears down upon the flag carrier, increasing damage taken by $s1%, and limiting movement speed.', null, null, null, null, null, null, null, null, 0, 0, 0, 0, 0, 0, 0, 16712190, 'The strength of the enemy bears down upon the flag carrier, increasing damage taken by $s1%, and limiting movement speed.','','','','','','','','', 0, 0, 0, 0, 0, 0, 0, 16712190, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
