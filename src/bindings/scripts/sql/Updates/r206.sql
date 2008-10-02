-- Zul'Gurub Bosses Part 1 + Trash Mobs
UPDATE `creature_template` SET `ScriptName` = 'boss_jeklik' WHERE `entry` = 14517;
UPDATE `creature_template` SET `ScriptName` = 'boss_venoxis' WHERE `entry` = 14607;
UPDATE `creature_template` SET `ScriptName` = 'boss_marli' WHERE `entry` = 14510;
UPDATE `creature_template` SET `ScriptName` = 'boss_mandokir' WHERE `entry` = 11382;
UPDATE `creature_template` SET `ScriptName` = 'boss_gahzranka' WHERE `entry` = 15114;
UPDATE `creature_template` SET `ScriptName` = 'boss_jindo' WHERE `entry` = 11380;

/* Spawn of Marli */
UPDATE `creature_template` SET `ScriptName` = 'mob_spawn_of_marli' WHERE `entry` = 15041;
/* Jeklik Batrider */
UPDATE `creature_template` SET `ScriptName` = 'mob_batrider' WHERE `entry` = 14965;


-- Darkmaster Ganling
UPDATE `creature_template` SET `ScriptName` = 'boss_darkmaster_gandling' WHERE `entry` = 1853;