-- Vyragosa (32630) & Time-Lost Proto-Drake (32491) band-aid fix by nelegalno
SET @POOL := 60002;
SET @VYRA := 32630;
SET @TLPD := 32491;

-- TLPD & Vyragosa set respawn to 6h (current 25 sec)
UPDATE `creature` SET `spawntimesecs`=21600 WHERE `id` IN (@VYRA,@TLPD);

-- Remove old pool data
DELETE FROM `pool_template` WHERE `entry` IN (@VYRA,@TLPD,@POOL);
DELETE FROM `pool_creature` WHERE `pool_entry` IN (@VYRA,@TLPD,@POOL);
DELETE FROM `pool_pool` WHERE `mother_pool`=@POOL OR `pool_id` IN (@VYRA,@TLPD);

-- Insert new pool structure
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@POOL,1,"Vyragosa (32630) & Time-Lost Proto Drake (32491)"),
(@VYRA,1,"Vyragosa (32630)"),
(@TLPD,1,"Time-Lost Proto Drake (32491)");

INSERT INTO `pool_pool` (`pool_id`, `mother_pool`, `chance`, `description`) VALUES
(@VYRA,@POOL,80,"Vyragosa (32630)"),
(@TLPD,@POOL,20,"Time-Lost Proto Drake (32491)");

INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
-- spawns 1-20 for both NPCs are from old pool
(202461,@TLPD,0,"Time-Lost Proto Drake (32491) - Spawn 1"),
(202462,@TLPD,0,"Time-Lost Proto Drake (32491) - Spawn 2"),
(202463,@TLPD,0,"Time-Lost Proto Drake (32491) - Spawn 3"),
(202464,@TLPD,0,"Time-Lost Proto Drake (32491) - Spawn 4"),
(202465,@TLPD,0,"Time-Lost Proto Drake (32491) - Spawn 5"),
(202466,@TLPD,0,"Time-Lost Proto Drake (32491) - Spawn 6"),
(202467,@TLPD,0,"Time-Lost Proto Drake (32491) - Spawn 7"),
(202468,@TLPD,0,"Time-Lost Proto Drake (32491) - Spawn 8"),
(202469,@TLPD,0,"Time-Lost Proto Drake (32491) - Spawn 9"),
(202470,@TLPD,0,"Time-Lost Proto Drake (32491) - Spawn 10"),
(202471,@TLPD,0,"Time-Lost Proto Drake (32491) - Spawn 11"),
(202472,@TLPD,0,"Time-Lost Proto Drake (32491) - Spawn 12"),
(202473,@TLPD,0,"Time-Lost Proto Drake (32491) - Spawn 13"),
(202474,@TLPD,0,"Time-Lost Proto Drake (32491) - Spawn 14"),
(202475,@TLPD,0,"Time-Lost Proto Drake (32491) - Spawn 15"),
(202476,@TLPD,0,"Time-Lost Proto Drake (32491) - Spawn 16"),
(202477,@TLPD,0,"Time-Lost Proto Drake (32491) - Spawn 17"),
(202478,@TLPD,0,"Time-Lost Proto Drake (32491) - Spawn 18"),
(202479,@TLPD,0,"Time-Lost Proto Drake (32491) - Spawn 19"),
(202480,@TLPD,0,"Time-Lost Proto Drake (32491) - Spawn 20"),
(202441,@VYRA,0,"Vyragosa (32630) - Spawn 1"),
(202442,@VYRA,0,"Vyragosa (32630) - Spawn 2"),
(202443,@VYRA,0,"Vyragosa (32630) - Spawn 3"),
(202444,@VYRA,0,"Vyragosa (32630) - Spawn 4"),
(202445,@VYRA,0,"Vyragosa (32630) - Spawn 5"),
(202446,@VYRA,0,"Vyragosa (32630) - Spawn 6"),
(202447,@VYRA,0,"Vyragosa (32630) - Spawn 7"),
(202448,@VYRA,0,"Vyragosa (32630) - Spawn 8"),
(202449,@VYRA,0,"Vyragosa (32630) - Spawn 9"),
(202450,@VYRA,0,"Vyragosa (32630) - Spawn 10"),
(202451,@VYRA,0,"Vyragosa (32630) - Spawn 11"),
(202452,@VYRA,0,"Vyragosa (32630) - Spawn 12"),
(202453,@VYRA,0,"Vyragosa (32630) - Spawn 13"),
(202454,@VYRA,0,"Vyragosa (32630) - Spawn 14"),
(202455,@VYRA,0,"Vyragosa (32630) - Spawn 15"),
(202456,@VYRA,0,"Vyragosa (32630) - Spawn 16"),
(202457,@VYRA,0,"Vyragosa (32630) - Spawn 17"),
(202458,@VYRA,0,"Vyragosa (32630) - Spawn 18"),
(202459,@VYRA,0,"Vyragosa (32630) - Spawn 19"),
(202460,@VYRA,0,"Vyragosa (32630) - Spawn 20"),
-- spawned in TDB but not in the old pool
(202602,@VYRA,0,"Vyragosa (32630) - Spawn 21");
