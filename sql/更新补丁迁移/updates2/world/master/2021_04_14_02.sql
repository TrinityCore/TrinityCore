-- DB update 2021_04_14_01 -> 2021_04_14_02
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_14_01';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_14_01 2021_04_14_02 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1618371673205623900'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1618371673205623900');

UPDATE `page_text` SET `Text` = 'Feel blessed that your spirit was not released to the Nether, $N. Feel even more blessed that I decided you were worth the effort to write this scroll for.$B$BThe people you once knew, perhaps even cared for, are no longer! You must learn to "live" with that for the rest of your now unnatural life. I suggest you learn to deal with that first.$B$BIf you think you\'re ready for the trials ahead, then seek me out in the church in Deathknell.$B$B- Dark Cleric Duesten, Priest Trainer' WHERE `ID`= 2467;


--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
