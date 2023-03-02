-- DB update 2021_02_25_02 -> 2021_02_25_03
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_25_02';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_25_02 2021_02_25_03 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1614023588633206841'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1614023588633206841');

-- Create pooling for Copper Veins on Azuremyst Isle

DELETE FROM `pool_template` WHERE `entry`=11643;
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(11643,20,"Copper Vein - Azuremyst Isle");

-- Add gameobjects to pools
DELETE FROM `pool_gameobject` WHERE `guid` IN (5290,5291,5292,5293,5294,5295,5296,5297,5298,5299,5300,5301,5302,5303,5304,5305,5306,5307,5308,5309,5310,5311,5312,5313,30444,30478,30486,30498,30507,30512,30514,30531,39948,39949,39950,120291,120340,120362,120791);

INSERT INTO `pool_gameobject` (`guid`,`pool_entry`,`chance`,`description`) VALUES
(5290,11643,0,"Azuremyst Isle, Copper Vein, spawn 1"),
(5291,11643,0,"Azuremyst Isle, Copper Vein, spawn 2"),
(5292,11643,0,"Azuremyst Isle, Copper Vein, spawn 3"),
(5293,11643,0,"Azuremyst Isle, Copper Vein, spawn 4"),
(5294,11643,0,"Azuremyst Isle, Copper Vein, spawn 5"),
(5295,11643,0,"Azuremyst Isle, Copper Vein, spawn 6"),
(5296,11643,0,"Azuremyst Isle, Copper Vein, spawn 7"),
(5297,11643,0,"Azuremyst Isle, Copper Vein, spawn 8"),
(5298,11643,0,"Azuremyst Isle, Copper Vein, spawn 9"),
(5299,11643,0,"Azuremyst Isle, Copper Vein, spawn 10"),
(5300,11643,0,"Azuremyst Isle, Copper Vein, spawn 11"),
(5301,11643,0,"Azuremyst Isle, Copper Vein, spawn 12"),
(5302,11643,0,"Azuremyst Isle, Copper Vein, spawn 13"),
(5303,11643,0,"Azuremyst Isle, Copper Vein, spawn 14"),
(5304,11643,0,"Azuremyst Isle, Copper Vein, spawn 15"),
(5305,11643,0,"Azuremyst Isle, Copper Vein, spawn 16"),
(5306,11643,0,"Azuremyst Isle, Copper Vein, spawn 17"),
(5307,11643,0,"Azuremyst Isle, Copper Vein, spawn 18"),
(5308,11643,0,"Azuremyst Isle, Copper Vein, spawn 19"),
(5309,11643,0,"Azuremyst Isle, Copper Vein, spawn 20"),
(5310,11643,0,"Azuremyst Isle, Copper Vein, spawn 21"),
(5311,11643,0,"Azuremyst Isle, Copper Vein, spawn 22"),
(5312,11643,0,"Azuremyst Isle, Copper Vein, spawn 23"),
(5313,11643,0,"Azuremyst Isle, Copper Vein, spawn 24"),
(30444,11643,0,"Azuremyst Isle, Copper Vein, spawn 25"),
(30478,11643,0,"Azuremyst Isle, Copper Vein, spawn 26"),
(30486,11643,0,"Azuremyst Isle, Copper Vein, spawn 27"),
(30498,11643,0,"Azuremyst Isle, Copper Vein, spawn 28"),
(30507,11643,0,"Azuremyst Isle, Copper Vein, spawn 29"),
(30512,11643,0,"Azuremyst Isle, Copper Vein, spawn 30"),
(30514,11643,0,"Azuremyst Isle, Copper Vein, spawn 31"),
(30531,11643,0,"Azuremyst Isle, Copper Vein, spawn 32"),
(39948,11643,0,"Azuremyst Isle, Copper Vein, spawn 33"),
(39949,11643,0,"Azuremyst Isle, Copper Vein, spawn 34"),
(39950,11643,0,"Azuremyst Isle, Copper Vein, spawn 35"),
(120291,11643,0,"Azuremyst Isle, Copper Vein, spawn 36"),
(120340,11643,0,"Azuremyst Isle, Copper Vein, spawn 37"),
(120362,11643,0,"Azuremyst Isle, Copper Vein, spawn 38"),
(120791,11643,0,"Azuremyst Isle, Copper Vein, spawn 39");

-- Lower respawn of veins to 1 minute
UPDATE `gameobject` SET `spawntimesecs`=60 WHERE `guid` IN (5290,5291,5292,5293,5294,5295,5296,5297,5298,5299,5300,5301,5302,5303,5304,5305,5306,5307,5308,5309,5310,5311,5312,5313,30444,30478,30486,30498,30507,30512,30514,30531,39948,39949,39950,120291,120340,120362,120791);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
