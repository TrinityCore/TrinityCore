-- DB update 2021_03_07_04 -> 2021_03_07_05
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_07_04';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_07_04 2021_03_07_05 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1614722186740264425'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1614722186740264425');

UPDATE `page_text` SET `Text` = 'The black dragon underwent a complete transformation; and in the end, Neltharion no longer existed. He became Deathwing, a creature of malice and hatred. No longer the Earth-Warder in the eyes of races like the high elves, he was renamed the Death Aspect and Xaxas in place of his titan-given name. Deathwing is the embodiment of chaos and evil, and is always hungry for destruction. He is arguably the first evil of Azeroth that appeared after the banishment of the Old Gods.' WHERE `ID` = 459;


--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
