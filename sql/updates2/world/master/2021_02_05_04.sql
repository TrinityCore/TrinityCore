-- DB update 2021_02_05_03 -> 2021_02_05_04
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_05_03';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_05_03 2021_02_05_04 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1612059439455457600'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1612059439455457600');

-- SPELL_SCHOOL_FIRE
UPDATE `creature_template` SET `spell_school_immune_mask` = 4 WHERE `entry` IN (17267,15438);

-- SPELL_SCHOOL_NATURE
UPDATE `creature_template` SET `spell_school_immune_mask` = 8 WHERE `entry` IN (30258,31463,15352);

-- SPELL_SCHOOL_FROST
UPDATE `creature_template` SET `spell_school_immune_mask` = 16 WHERE `entry` IN (37994,510,17167);

-- School ALL
UPDATE `creature_template` SET `spell_school_immune_mask`=`spell_school_immune_mask`|1|2|4|8|16|32|64 WHERE `entry` IN (28912);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
