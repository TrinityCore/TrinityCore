-- DB update 2021_04_19_06 -> 2021_04_19_07
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_19_06';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_19_06 2021_04_19_07 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1618383191741891235'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1618383191741891235');

UPDATE `quest_template_addon` SET `AllowableClasses` = 1090 WHERE (`ID` = 8989);
UPDATE `quest_template_addon` SET `AllowableClasses` = 9 WHERE (`ID` = 8990);
UPDATE `quest_template_addon` SET `AllowableClasses` = 144 WHERE (`ID` = 8991);
UPDATE `quest_template_addon` SET `AllowableClasses` = 260 WHERE (`ID` = 8992);
UPDATE `quest_template_addon` SET `AllowableClasses` = 9 WHERE (`ID` = 8985);
UPDATE `quest_template_addon` SET `AllowableClasses` = 1090 WHERE (`ID` = 8986);
UPDATE `quest_template_addon` SET `AllowableClasses` = 144 WHERE (`ID` = 8987);
UPDATE `quest_template_addon` SET `AllowableClasses` = 260 WHERE (`ID` = 8988);
UPDATE `quest_template_addon` SET `AllowableClasses` = 129 WHERE (`ID` = 8966);
UPDATE `quest_template_addon` SET `AllowableClasses` = 1280 WHERE (`ID` = 8967);
UPDATE `quest_template_addon` SET `AllowableClasses` = 12 WHERE (`ID` = 8968);
UPDATE `quest_template_addon` SET `AllowableClasses` = 82 WHERE (`ID` = 8969);
UPDATE `quest_template_addon` SET `AllowableClasses` = 129 WHERE (`ID` = 8962);
UPDATE `quest_template_addon` SET `AllowableClasses` = 1280 WHERE (`ID` = 8963);
UPDATE `quest_template_addon` SET `AllowableClasses` = 12 WHERE (`ID` = 8964);
UPDATE `quest_template_addon` SET `AllowableClasses` = 82 WHERE (`ID` = 8965);


--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
