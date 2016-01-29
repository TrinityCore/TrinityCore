-- Iceskin Sentry
UPDATE `creature` SET `movementtype`=0, `spawndist`=0 WHERE `id`=31012;
UPDATE `creature_addon` SET `bytes1`=50331657 WHERE `guid`=121512;
UPDATE `creature_template` SET `unit_flags`=2147778560 WHERE `entry`=31012;
UPDATE `creature_addon` SET `auras`="58269" WHERE `guid` IN (121497, 121498, 121499, 121500, 121502, 121503, 121504, 121505, 121506, 121507, 121508, 121509, 121510, 121511, 121512);
