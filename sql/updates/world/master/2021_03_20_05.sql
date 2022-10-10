-- DB update 2021_03_20_04 -> 2021_03_20_05
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_20_04';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_20_04 2021_03_20_05 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1615990232375736422'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1615990232375736422');

SET
@POOL            = '11651',
@POOLSIZE        = '4',
@POOLDESC        = 'Treasures - Teldrassil',
@GUID = '49528,49529,49621,49622,49623,49624,49625,49626,49627,49628';

-- Create pool(s)
DELETE FROM `pool_template` WHERE `entry`=@POOL;
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES (@POOL,@POOLSIZE,@POOLDESC);

-- Add gameobjects to pools
DELETE FROM `pool_gameobject` WHERE FIND_IN_SET (`guid`,@GUID);
INSERT INTO `pool_gameobject` (`guid`,`pool_entry`,`chance`,`description`) VALUES
(49528,@POOL,0,@POOLDESC),
(49529,@POOL,0,@POOLDESC),
(49621,@POOL,0,@POOLDESC),
(49622,@POOL,0,@POOLDESC),
(49623,@POOL,0,@POOLDESC),
(49624,@POOL,0,@POOLDESC),
(49625,@POOL,0,@POOLDESC),
(49626,@POOL,0,@POOLDESC),
(49627,@POOL,0,@POOLDESC),
(49628,@POOL,0,@POOLDESC);

-- Respawn rates of gameobjects is 5 minutes
UPDATE `gameobject` SET `spawntimesecs`=300 WHERE FIND_IN_SET (`guid`,@GUID);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
