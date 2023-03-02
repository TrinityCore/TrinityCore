-- DB update 2021_04_11_09 -> 2021_04_11_10
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_11_09';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_11_09 2021_04_11_10 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617739461755573400'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617739461755573400');

DELETE FROM `spell_script_names` WHERE (`spell_id` IN (23567, 23568, 23569, 23696, 24412, 24413, 24414));
INSERT INTO `spell_script_names` VALUES
(23567, 'spell_gen_bandage'),
(23568, 'spell_gen_bandage'),
(23569, 'spell_gen_bandage'),
(23696, 'spell_gen_bandage'),
(24412, 'spell_gen_bandage'),
(24413, 'spell_gen_bandage'),
(24414, 'spell_gen_bandage');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
