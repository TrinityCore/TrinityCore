-- DB update 2021_04_18_03 -> 2021_04_19_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_18_03';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_18_03 2021_04_19_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1618166495075484153'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1618166495075484153');

UPDATE `creature_equip_template` SET `itemID3`=5870 WHERE `CreatureID` IN (701);
UPDATE `smart_scripts` SET `action_param2`=`action_param2`|2 WHERE `source_type`=0 AND `entryorguid`=7856 AND `id`=0;
UPDATE `creature_equip_template` SET `itemID3`=5856 WHERE `CreatureID` IN (1162);


--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
