--
UPDATE `creature_template` SET `ManaModifier` = 1 WHERE `entry` IN (3669,3670,3671);
UPDATE `creature_template` SET `ManaModifier` = 3 WHERE `entry` = 3673;
UPDATE `creature_template` SET `HealthModifier` = 6 WHERE `entry` = 25334;
UPDATE `creature_template` SET `HealthModifier` = 800, `ManaModifier` = 800, `exp` = 2 WHERE `entry` = 30838;
