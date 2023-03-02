-- DB update 2021_02_14_04 -> 2021_02_14_05
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_14_04';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_14_04 2021_02_14_05 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1613178860602736100'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1613178860602736100');

/* Add missing emotes for Maybell Maclure when offering quest Young Lovers=id106
   Source: https://www.youtube.com/watch?v=Y6XYsgc2epI
*/

DELETE FROM `quest_details` WHERE `ID` = 106;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `EmoteDelay2`, `VerifiedBuild`) VALUES (106, 18, 20, 1, 12340);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
