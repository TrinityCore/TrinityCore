-- DB update 2021_03_28_03 -> 2021_03_29_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_28_03';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_28_03 2021_03_29_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1616977871251124200'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1616977871251124200');

-- Add IA for 'Marked immortal guardian'
UPDATE `creature_template` SET `ScriptName`='boss_yoggsaron_immortal_guardian' WHERE `entry`=36064;
-- Match "Immortal Guardian" values with "Marked immortal guardian"
UPDATE `creature_template` SET `speed_walk`=1.6, `speed_run`=1.71429, `DamageModifier`=7.5, `mechanic_immune_mask`=617299839, `flags_extra`=1073741824 WHERE `entry` IN (36064, 36067);
UPDATE `creature_template` SET `DamageModifier`=8 WHERE `entry` IN (33989, 36067); -- 25mode
-- Add script into DB
DELETE FROM `spell_script_names` WHERE  `spell_id`=64465 AND `ScriptName`='spell_yogg_saron_shadow_beacon';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (64465, 'spell_yogg_saron_shadow_beacon');
-- Add/rework conditions for effect 'Titanic Storm'
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=64172;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,64172,0,0,31,0,3,33988,0,0,0,0,'','Titanic Storm on Immortal Guardian'),
(13,1,64172,0,1,31,0,3,36064,0,0,0,0,'','Titanic Storm on Marked Immortal Guardian');


--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
