-- Corrected HP & Mana
UPDATE `creature_template` SET `exp`=3 WHERE `entry` IN (46753, 45872, 45870, 45871);

-- Set InhabitType to fly for 2 triggers
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (19871, 46419); 

-- Throne of the Four Winds - All modes
UPDATE `creature` SET `spawnMask`=15 WHERE `map`=754;
UPDATE `gameobject` SET `spawnMask`=15 WHERE `map`=754;
