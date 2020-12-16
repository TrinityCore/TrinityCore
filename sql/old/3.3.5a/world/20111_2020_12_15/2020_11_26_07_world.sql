--
UPDATE `creature` SET `VerifiedBuild` = 12340 WHERE `map` = 616 AND `id` IN (22517,30090,30118,30334,32448);
UPDATE `creature` SET `position_x` = 754.255, `position_y` = 1301.72, `position_z` = 266.253, `orientation` = 1.23918, `VerifiedBuild` = 12340 WHERE `id` = 31253;

-- Remove empty addon
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 30334);

-- Power Spark & Scion of Eternity
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80 WHERE `entry` IN (30084,30249);
