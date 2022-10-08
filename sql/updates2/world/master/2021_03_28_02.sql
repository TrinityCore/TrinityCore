-- DB update 2021_03_28_01 -> 2021_03_28_02
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_28_01';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_28_01 2021_03_28_02 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1616571106507034555'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1616571106507034555');

-- Remove MECHANIC_SLOW_ATTACK mask
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask` &~128 WHERE `entry` IN
(639, -- Edwin VanCleef
643,  -- Sneed
645,  -- Cookie
646,  -- Mr. Smite
647,  -- Captain Greenskin
1763, -- Gilnid
642,  -- Sneed's Shredder
626); -- Foreman Thistlenettle

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
