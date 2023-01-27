-- DB update 2021_03_27_00 -> 2021_03_28_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_27_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_27_00 2021_03_28_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1616775049718733000'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1616775049718733000');
DELETE FROM `spell_dbc` WHERE (`ID` IN (20335, 20336, 20337));
INSERT INTO `spell_dbc` VALUES
(20335, 0, 0, 0, 464, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 6, 6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 6, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 21183, 0, 0, 0, 0, 536870912, 0, 0, 536870912, 0, 0, 0, 0, 0, 0, 0, 237, 0, 0, 'Heart of the Crusader','','','','','','','','', 0, 0, 0, 0, 0, 0, 0, 16712190, 'Rank 1','','','','','','','','', 0, 0, 0, 0, 0, 0, 0, 16712190, 'In addition to the normal effect, your Judgement spells will also increase the critical strike chance of all attacks made against that target by an additional $s1%.','','','','','','','','', 0, 0, 0, 0, 0, 0, 0, 16712190,'','','','','','','','','', 0, 0, 0, 0, 0, 0, 0, 16712190, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0),
(20336, 0, 0, 0, 464, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 6, 6, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 6, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 54498, 0, 0, 0, 0, 536870912, 0, 0, 536870912, 0, 0, 0, 0, 0, 0, 0, 237, 0, 0, 'Heart of the Crusader','','','','','','','','', 0, 0, 0, 0, 0, 0, 0, 16712190, 'Rank 2','','','','','','','','', 0, 0, 0, 0, 0, 0, 0, 16712190, 'In addition to the normal effect, your Judgement spells will also increase the critical strike chance of all attacks made against that target by an additional $s1%.','','','','','','','','', 0, 0, 0, 0, 0, 0, 0, 16712190,'','','','','','','','','', 0, 0, 0, 0, 0, 0, 0, 16712190, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0),
(20337, 0, 0, 0, 464, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 6, 6, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 6, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 54499, 0, 0, 0, 0, 536870912, 0, 0, 536870912, 0, 0, 0, 0, 0, 0, 0, 237, 0, 0, 'Heart of the Crusader','','','','','','','','', 0, 0, 0, 0, 0, 0, 0, 16712190, 'Rank 3','','','','','','','','', 0, 0, 0, 0, 0, 0, 0, 16712190, 'In addition to the normal effect, your Judgement spells will also increase the critical strike chance of all attacks made against that target by an additional $s1%.','','','','','','','','', 0, 0, 0, 0, 0, 0, 0, 16712190,'','','','','','','','','', 0, 0, 0, 0, 0, 0, 0, 16712190, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
