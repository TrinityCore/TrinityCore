-- DB update 2021_02_04_02 -> 2021_02_04_03
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_04_02';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_04_02 2021_02_04_03 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1612103229762253100'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1612103229762253100');

UPDATE `page_text` SET `Text` = 'Supervisor Fizsprocket, please find enclosed a list of the equipment you have requisitioned, approved by President Razdunk.$B$BHe has asked me to remind and to emphasize to you of the Venture Company''s vested interest in setting up operations throughout Kalimdor. Our drilling and mining outposts in the Barrens have proven profitable and efficient, but we still await sufficient production numbers from Mulgore, your jurisdiction.$B$BThe advisory board understands the difficulties in establishing' WHERE `ID` = 352;
UPDATE `page_text` SET `Text` = 'a large scale operation so close to the tauren homeland, but do not feel that they pose a large impediment to our overall business plan in the area.$B$BWe are pleased to hear that mining has begun in the mineral rich plains of Mulgore. Because of this the board has approved your equipment request. In addition to mining, we feel that Mulgore also has much to offer in the way of lumber, thus you will also be provided with several of our newest model shredders and raw materials to construct a' WHERE `ID` = 353;

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
