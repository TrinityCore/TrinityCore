-- DB update 2021_01_31_00 -> 2021_01_31_01
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_01_31_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_01_31_00 2021_01_31_01 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1610824463901751500'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1610824463901751500');

DELETE FROM `spell_script_names` WHERE `ScriptName`="spell_gen_charmed_unit_spell_cooldown";
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(37727, "spell_gen_charmed_unit_spell_cooldown"),
(37851, "spell_gen_charmed_unit_spell_cooldown"),
(37917, "spell_gen_charmed_unit_spell_cooldown"),
(37918, "spell_gen_charmed_unit_spell_cooldown"),
(37919, "spell_gen_charmed_unit_spell_cooldown"),
(47911, "spell_gen_charmed_unit_spell_cooldown"),
(48620, "spell_gen_charmed_unit_spell_cooldown"),
(51748, "spell_gen_charmed_unit_spell_cooldown"),
(51752, "spell_gen_charmed_unit_spell_cooldown"),
(51756, "spell_gen_charmed_unit_spell_cooldown"),
(54996, "spell_gen_charmed_unit_spell_cooldown"),
(54997, "spell_gen_charmed_unit_spell_cooldown"),
(56513, "spell_gen_charmed_unit_spell_cooldown"),
(56524, "spell_gen_charmed_unit_spell_cooldown");

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
