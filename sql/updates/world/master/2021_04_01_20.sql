-- DB update 2021_04_01_19 -> 2021_04_01_20
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_01_19';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_01_19 2021_04_01_20 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617254287410662400'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617254287410662400');

SET @SPELL_ATTR0_CU_NEGATIVE_EFF0 := 4096,
	@SPELL_ATTR0_CU_NEGATIVE_EFF1 := 8192;

DELETE FROM `spell_custom_attr` WHERE `spell_id`=57874;
INSERT INTO `spell_custom_attr` (`spell_id`, `attributes`) VALUES
(57874, @SPELL_ATTR0_CU_NEGATIVE_EFF0|@SPELL_ATTR0_CU_NEGATIVE_EFF1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=57874 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=1 AND `ConditionValue1`=4 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 57874, 0, 0, 31, 1, 4, 0, 0, 0, 0, 0, '', 'Twilight Shift spell should be applied only on player');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
