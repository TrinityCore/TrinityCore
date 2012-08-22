-- Flame Sphere should not be visible to players(only their visual)
UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry` IN (30106,31686,31687);
