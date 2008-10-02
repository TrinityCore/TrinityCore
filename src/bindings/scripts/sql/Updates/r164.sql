-- gruuls lair trash mobs
UPDATE `creature_template` SET `ScriptName` = 'mob_gruuls_lair' WHERE `entry` IN (19389, 21350);

-- morogrim tidewalker
UPDATE `creature_template` SET `ScriptName` = 'boss_morogrim_tidewalker' WHERE `entry`=21213;
-- Water Globule
UPDATE `creature_template` SET `ScriptName` = 'mob_water_globule' WHERE `entry`=21913;

-- Serpentshrine Cavern Trash Mobs
UPDATE `creature_template` SET `ScriptName` = 'mob_serpentshrine_cavern' WHERE `entry` IN (21246, 21339, 21221, 21224, 21227, 21228, 21226, 21225, 21298, 21299);