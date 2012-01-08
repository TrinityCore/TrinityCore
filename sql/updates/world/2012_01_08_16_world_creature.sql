-- Set Svala's  spawn time
UPDATE `creature` SET `spawntimesecs` = '86400' WHERE `id` = 29281;

-- Flame Brazier triggers deletion (will spawn them after activating event 17841 called by spell Call Flames 48258)
DELETE FROM `creature` WHERE `id` = 27273 AND `map` = 575;
DELETE FROM `creature_addon` WHERE `guid` IN (126121, 126122);
