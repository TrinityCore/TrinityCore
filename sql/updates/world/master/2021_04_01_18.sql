-- DB update 2021_04_01_17 -> 2021_04_01_18
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_01_17';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_01_17 2021_04_01_18 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617197429170396176'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617197429170396176');

-- Delete duplicate herbs
SET
@GUID            = '1250,12522,12354,35488,30072,85437,12575,32214,42962,35532,12522,45091,85307,12364,45125,12580,85440,1671,12465,85450,85389,85446,29660,34033,85452,12625,85456,35500,85459,35366,85458,32504,85469,33472,65061,34831,30978,16804,85465,29649,85463,85464,30955,15049,63364,32018,16810,30873,85467,29568,17892,65117,21255,30373,85468,29250,35361,32834,16801,7614,16936,16936,34959,7816,29534,34911,46281,12323,12267,29291,30229,29587,35296,17296,17284,29588,32066,17587,17586,19033,19232,46306,86397,19748,45470,63704,45939,45556,65281,55627,56380,40367';

DELETE FROM `gameobject` WHERE `guid` IN (
1250,   -- Duplicate of 467, Silverleaf
12522,  -- Duplicate of 467, Silverleaf
12354,  -- Duplicate of 468, Silverleaf
35488,  -- Duplicate of 541, Silverleaf
30072,  -- Duplicate of 1093, Silverleaf
85437,  -- Duplicate of 1095, Silverleaf
12575,  -- Duplicate of 1156, Silverleaf
32214,  -- Duplicate of 1167, Silverleaf
42962,  -- Duplicate of 1209, Silverleaf
35532,  -- Duplicate of 1249, Silverleaf
12522,  -- Duplicate of 1250, Silverleaf
45091,  -- Duplicate of 1261, Silverleaf
85307,  -- Duplicate of 39947, Silverleaf
12364,  -- Duplicate of 1359, Peacebloom
45125,  -- Duplicate of 1614, Peacebloom
12580,  -- Duplicate of 1640, Peacebloom
85440,  -- Duplicate of 1659, Peacebloom
1671,   -- Duplicate of 1670, Peacebloom
12465,  -- Duplicate of 1766, Earthroot
85450,  -- Duplicate of 1820, Earthroot
85389,  -- Duplicate of 1882, Earthroot
85446,  -- Duplicate of 2048, Earthroot
29660,  -- Duplicate of 2059, Earthroot
34033,  -- Duplicate of 2132, Mageroyal
85452,  -- Duplicate of 2157, Mageroyal
12625,  -- Duplicate of 2484, Mageroyal
85456,  -- Duplicate of 2497, Mageroyal
35500,  -- Duplicate of 2587, Briarthorn
85459,  -- Duplicate of 2601, Briarthorn
35366,  -- Duplicate of 2663, Briarthorn
85458,  -- Duplicate of 2765, Briarthorn
32504,  -- Duplicate of 8293, Stranglekelp
85469,  -- Duplicate of 8588, Stranglekelp
33472,  -- Duplicate of 2957, Bruiseweed
65061,  -- Duplicate of 3144, Bruiseweed
34831,  -- Duplicate of 3203, Bruiseweed
30978,  -- Duplicate of 3426, Bruiseweed
16804,  -- Duplicate of 3638, Bruiseweed
85465,  -- Duplicate of 3715, Bruiseweed
29649,  -- Duplicate of 3744, Bruiseweed
85463,  -- Duplicate of 3797, Bruiseweed
85464,  -- Duplicate of 3804, Bruiseweed
30955,  -- Duplicate of 3832, Bruiseweed
15049,  -- Duplicate of 3876, Bruiseweed
63364,  -- Duplicate of 3877, Bruiseweed
32018,  -- Duplicate of 3921, Wild Steelbloom
16810,  -- Duplicate of 3938, Wild Steelbloom
30873,  -- Duplicate of 4173, Wild Steelbloom
85467,  -- Duplicate of 4178, Wild Steelbloom
29568,  -- Duplicate of 4253, Wild Steelbloom
17892,  -- Duplicate of 4470, Grave Moss
65117,  -- Duplicate of 4482, Grave Moss
21255,  -- Duplicate of 4293, Kingsblood
30373,  -- Duplicate of 4304, Kingsblood
85468,  -- Duplicate of 4357, Kingsblood
29250,  -- Duplicate of 7412, Liferoot
35361,  -- Duplicate of 7432, Liferoot
32834,  -- Duplicate of 7463, Liferoot
16801,  -- Duplicate of 7495, Liferoot
7614,   -- Duplicate of 7613, Fadeleaf
16936,  -- Duplicate of 7613, Fadeleaf
16936,  -- Duplicate of 7614, Fadeleaf
34959,  -- Duplicate of 7671, Fadeleaf
7816,   -- Duplicate of 7814, Fadeleaf
29534,  -- Duplicate of 8609, Goldthorn
34911,  -- Duplicate of 8682, Goldthorn
46281,  -- Duplicate of 8070, Khadgar's Whisker
12323,  -- Duplicate of 6964, Firebloom
12267,  -- Duplicate of 9980, Firebloom
29291,  -- Duplicate of 12240, Firebloom
30229,  -- Duplicate of 12294, Firebloom
29587,  -- Duplicate of 12310, Firebloom
35296,  -- Duplicate of 12315, Firebloom
17296,  -- Duplicate of 12326, Firebloom
17284,  -- Duplicate of 12334, Firebloom
29588,  -- Duplicate of 13232, Firebloom
32066,  -- Duplicate of 15807, Purple Lotus
17587,  -- Duplicate of 16077, Sungrass
17586,  -- Duplicate of 16092, Sungrass
19033,  -- Duplicate of 17740, Golden Sansam
19232,  -- Duplicate of 17744, Golden Sansam
46306,  -- Duplicate of 19071, Golden Sansam
86397,  -- Duplicate of 86396, Golden Sansam
19748,  -- Duplicate of 17890, Mountain Silversage
45470,  -- Duplicate of 19903, Plaguebloom
63704,  -- Duplicate of 19980, Plaguebloom
45939,  -- Duplicate of 20093, Plaguebloom
45556,  -- Duplicate of 20128, Plaguebloom
65281,  -- Duplicate of 65280, Plaguebloom
55627,  -- Duplicate of 40298, Felweed
56380,  -- Duplicate of 40654, Felweed
40367); -- Duplicate of 18912, Terocone

-- Cleanup pools
DELETE FROM `pool_gameobject` WHERE FIND_IN_SET (`guid`,@GUID);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
