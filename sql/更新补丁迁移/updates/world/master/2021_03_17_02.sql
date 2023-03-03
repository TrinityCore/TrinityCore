-- DB update 2021_03_17_01 -> 2021_03_17_02
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_17_01';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_17_01 2021_03_17_02 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1615134713336559993'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1615134713336559993');

-- Align resistances with vmangos for creatures level 1-20
UPDATE `creature_template` SET `resistance3`=0  WHERE `entry`=832;   -- 'Dust Devil' level 19, resistance3 was 40 (Nature)
UPDATE `creature_template` SET `resistance5`=0  WHERE `entry`=1892;  -- 'Moonrage Watcher' level 14, resistance5 was 5 (Shadow)
UPDATE `creature_template` SET `resistance5`=0  WHERE `entry`=1893;  -- 'Moonrage Sentry' level 15, resistance5 was 5 (Shadow)
UPDATE `creature_template` SET `resistance5`=0  WHERE `entry`=1896;  -- 'Moonrage Elder' level 15, resistance5 was 5 (Shadow)
UPDATE `creature_template` SET `resistance1`=0  WHERE `entry`=2166;  -- 'Oakenscowl'' level 9, resistance1 was 18 (Holy)
UPDATE `creature_template` SET `resistance2`=0  WHERE `entry`=3273;  -- 'Kolkar Stormer' level 14, resistance2 was 70 (Fire)
UPDATE `creature_template` SET `resistance5`=0  WHERE `entry`=3273;  -- 'Kolkar Stormer' level 14, resistance5 was 30 (Shadow)
UPDATE `creature_template` SET `resistance2`=0  WHERE `entry`=3274;  -- 'Kolkar Pack Runner' level 15, resistance2 was 70 (Fire)
UPDATE `creature_template` SET `resistance5`=0  WHERE `entry`=3274;  -- 'Kolkar Pack Runner' level 15, resistance5 was 30 (Shadow)
UPDATE `creature_template` SET `resistance2`=0  WHERE `entry`=3275;  -- 'Kolkar Marauder' level 16, resistance2 was 70 (Fire)
UPDATE `creature_template` SET `resistance5`=0  WHERE `entry`=3275;  -- 'Kolkar Marauder' level 16, resistance5 was 30 (Shadow)
UPDATE `creature_template` SET `resistance2`=0  WHERE `entry`=3397;  -- 'Kolkar Bloodcharger' level 15, resistance2 was 70 (Fire)
UPDATE `creature_template` SET `resistance5`=0  WHERE `entry`=3397;  -- 'Kolkar Bloodcharger' level 15, resistance5 was 30 (Shadow)
UPDATE `creature_template` SET `resistance5`=0  WHERE `entry`=3529;  -- 'Moonrage Armorer' level 15, resistance5 was 5 (Shadow)
UPDATE `creature_template` SET `resistance5`=0  WHERE `entry`=3531;  -- 'Moonrage Tailor' level 15, resistance5 was 5 (Shadow)
UPDATE `creature_template` SET `resistance5`=0  WHERE `entry`=3533;  -- 'Moonrage Leatherworker' level 15, resistance5 was 5 (Shadow)
UPDATE `creature_template` SET `resistance2`=5  WHERE `entry`=3569;  -- 'Bogling' level 5, resistance2 was 0 (Fire)
UPDATE `creature_template` SET `resistance3`=5  WHERE `entry`=3569;  -- 'Bogling' level 5, resistance3 was 0 (Nature)
UPDATE `creature_template` SET `resistance4`=5  WHERE `entry`=3569;  -- 'Bogling' level 5, resistance4 was 0 (Frost)
UPDATE `creature_template` SET `resistance5`=10 WHERE `entry`=3569;  -- 'Bogling' level 5, resistance5 was 0 (Shadow)
UPDATE `creature_template` SET `resistance6`=5  WHERE `entry`=3569;  -- 'Bogling' level 5, resistance6 was 0 (Arcane)
UPDATE `creature_template` SET `resistance3`=15 WHERE `entry`=5891;  -- 'Minor Manifestation of Earth' level 15, resistance3 was 0 (Nature)
UPDATE `creature_template` SET `resistance2`=0  WHERE `entry`=9523;  -- 'Kolkar Stormseer' level 16, resistance2 was 70 (Fire)
UPDATE `creature_template` SET `resistance5`=0  WHERE `entry`=9523;  -- 'Kolkar Stormseer' level 16, resistance5 was 30 (Shadow)
UPDATE `creature_template` SET `resistance2`=0  WHERE `entry`=9524;  -- 'Kolkar Invader' level 17, resistance2 was 70 (Fire)
UPDATE `creature_template` SET `resistance5`=0  WHERE `entry`=9524;  -- 'Kolkar Invader' level 17, resistance5 was 30 (Shadow)
UPDATE `creature_template` SET `resistance3`=15 WHERE `entry`=11321; -- 'Molten Elemental' level 13, resistance3 was 22 (Nature)
UPDATE `creature_template` SET `resistance1`=0  WHERE `entry`=12431; -- 'Gorefang'' level 13, resistance1 was 70 (Holy)

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
