-- DB update 2021_03_10_00 -> 2021_03_10_01
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_10_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_10_00 2021_03_10_01 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1615190253062057000'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1615190253062057000');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 6224;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 6224);
INSERT INTO `smart_scripts` VALUES
(6224, 0, 0, 0, 4, 0, 30, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Leprous Machinesmith - On Aggro - Say Line 1'),
(6224, 0, 1, 0, 0, 0, 100, 0, 3000, 3000, 25000, 25000, 0, 11, 10732, 0, 0, 0, 0, 0, 19, 6233, 15, 0, 0, 0, 0, 0, 0, 'Leprous Machinesmith - In Combat - Cast \'Supercharge\''),
(6224, 0, 2, 0, 0, 0, 100, 0, 20000, 20000, 25000, 25000, 0, 11, 10732, 0, 0, 0, 0, 0, 19, 6226, 15, 0, 0, 0, 0, 0, 0, 'Leprous Machinesmith - In Combat - Cast \'Supercharge\''),
(6224, 0, 3, 0, 0, 0, 100, 0, 2000, 5000, 4000, 6000, 0, 11, 13398, 64, 0, 0, 0, 0, 21, 30, 0, 0, 0, 0, 0, 0, 0, 'Leprous Machinesmith - In Combat - Cast \'Throw Wrench\''),
(6224, 0, 4, 0, 2, 0, 100, 1, 0, 90, 0, 0, 0, 11, 10348, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Leprous Machinesmith - Between 0-90% Health - Cast \'Tune Up\' (No Repeat)'),
(6224, 0, 5, 0, 8, 0, 100, 0, 9798, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Leprous Machinesmith - On Spellhit \'Radiation\' - Say Line 0');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=7 AND `SourceEntry`=10732;

DELETE FROM `spell_dbc` WHERE `ID` =10732;
INSERT INTO `spell_dbc` VALUES (10732, 0, 0, 0, 65536, 16388, 2048, 67108864, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 15, 0, 31756, 0, 101, 0, 0, 26, 26, 1, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 6, 6, 6, 1, 1, 1, 2, 0, 0, 49, 24, 24, 0, 0, 0, 21, 21, 21, 0, 0, 0, 0, 0, 0, 13, 138, 61, 3000, 3000, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12656, 0, 320, 0, 0, 'Supercharge','','','','','','','','', 0, 0, 0, 0, 0, 0, 0, 16712190,'','','','','','','','','', 0, 0, 0, 0, 0, 0, 0, 16712190, 'Speeds the attack of nearby mechanical allies by $s2% and increases the Physical damage they deal by $s1 for $d.','','','','','','','','', 0, 0, 0, 0, 0, 0, 0, 16712190, 'Physical damage dealt is increased by $s1.', null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
