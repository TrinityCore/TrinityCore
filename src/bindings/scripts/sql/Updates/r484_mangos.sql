-- Quest support 9678
UPDATE `gameobject_template` SET `ScriptName`='go_gilded_brazier' WHERE `entry` = '181956';

-- Archimonde with related creatures.
UPDATE `creature_template` SET `Scriptname` = "boss_archimonde" WHERE `entry` = 17968;
UPDATE `creature_template` SET `ScriptName` = "mob_doomfire" WHERE `entry` = 18095;
UPDATE `creature_template` SET `Scriptname` = "mob_doomfire_targetting" WHERE `entry` = 18104;
UPDATE `creature_template` SET `ScriptName` = "mob_ancient_wisp" WHERE `entry` = 17946;
