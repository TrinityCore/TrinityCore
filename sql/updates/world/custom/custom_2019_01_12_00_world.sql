UPDATE `creature_template` SET `DamageModifier`= 90 WHERE `entry`= 48936;
UPDATE `creature_template` SET `DamageModifier`= 8 WHERE `entry` IN (48957, 48958);
UPDATE `creature_template` SET `DamageModifier`= 120 WHERE `entry`= 48939;
UPDATE `creature_template` SET `DamageModifier`= 18 WHERE `entry` IN (48940, 49674);
UPDATE `creature_template` SET `BaseAttackTime`= 1000, `flags_extra`= 2048 WHERE `entry` IN (47296, 48940, 49674);
UPDATE `creature_template` SET `DamageModifier`= 30 WHERE `entry`= 48943;
UPDATE `creature_template` SET `DamageModifier`= 90 WHERE `entry`= 49541;
UPDATE `creature` SET `spawnMask`= 2 WHERE `guid`= 376150;
