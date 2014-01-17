-- Remove achievements from disables
DELETE FROM `disables` WHERE  `sourceType`=4 AND `entry`=7323; -- Ruby Void
DELETE FROM `disables` WHERE  `sourceType`=4 AND `entry`=7324; -- Emerald Void
DELETE FROM `disables` WHERE  `sourceType`=4 AND `entry`=7325; -- Amber Void
