UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (39390, 43070, 48523, 41095, 42608);
UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry` IN (43070, 42496, 42495, 40197);

-- Set spawnMask to Heroic & Normal Difficulty for Grim Batol and Lost City of the Tol'vir
UPDATE `creature` SET `spawnMask`=3 WHERE `map` IN (755, 670);
UPDATE `gameobject` SET `spawnMask`=3  WHERE `map` IN (755, 670);
