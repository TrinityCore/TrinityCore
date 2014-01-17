-- fix DB-error on startup
DELETE FROM `creature_loot_template` WHERE `entry` IN (34965,34980);
