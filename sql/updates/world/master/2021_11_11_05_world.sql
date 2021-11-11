-- Exists in db2
DELETE FROM `serverside_spell` WHERE `Id`=123456;
DELETE FROM `serverside_spell_effect` WHERE `SpellId`=123456;

-- No longer exist
DELETE FROM `spell_custom_attr` WHERE `entry` IN (207194,70324,67331,67333,67097,67098,67099,72447,72448,72449,73797,73798,73799);

-- Available difficulty changes
UPDATE `creature` SET `spawnDifficulties`='0' WHERE `map`=0; -- Eastern Kingdoms
UPDATE `creature` SET `spawnDifficulties`='0' WHERE `map`=1; -- Kalimdor
UPDATE `creature` SET `spawnDifficulties`='1' WHERE `map`=47; -- Razorfen Kraul
UPDATE `creature` SET `spawnDifficulties`='0' WHERE `map`=530; -- Outland
UPDATE `creature` SET `spawnDifficulties`='1,2' WHERE `spawnDifficulties`='0,1' AND `map`=643; -- Throne of the Tides
UPDATE `creature` SET `spawnDifficulties`='0' WHERE `map`=646; -- Deepholm
UPDATE `creature` SET `spawnDifficulties`='0' WHERE `map`=648; -- LostIsles
UPDATE `creature` SET `spawnDifficulties`='3,4,5,6' WHERE `spawnDifficulties`='0,1,2,3' AND `map`=671; -- The Bastion of Twilight
UPDATE `creature` SET `spawnDifficulties`='14,15,33' WHERE `spawnDifficulties`='3,4,5,6' AND `map`=720; -- Firelands
UPDATE `creature` SET `spawnDifficulties`='0' WHERE `map`=730; -- Maelstrom Zone
UPDATE `creature` SET `spawnDifficulties`='0' WHERE `map`=860; -- The Wandering Isle
UPDATE `creature` SET `spawnDifficulties`='0' WHERE `map`=870; -- Pandaria
UPDATE `creature` SET `spawnDifficulties`='2' WHERE `map`=940; -- Hour of Twilight
UPDATE `creature` SET `spawnDifficulties`='0' WHERE `map`=1064; -- Mogu Island Daily Area
UPDATE `creature` SET `spawnDifficulties`='0' WHERE `map`=1116; -- Draenor
UPDATE `creature` SET `spawnDifficulties`='0' WHERE `map`=1191; -- Ashran
UPDATE `creature` SET `spawnDifficulties`='0' WHERE `map`=1220; -- Broken Isles
UPDATE `creature` SET `spawnDifficulties`='0' WHERE `map`=1464; -- Tanaan Jungle

UPDATE `gameobject` SET `spawnDifficulties`='0' WHERE `map`=0; -- Eastern Kingdoms
UPDATE `gameobject` SET `spawnDifficulties`='0' WHERE `map`=1; -- Kalimdor
UPDATE `gameobject` SET `spawnDifficulties`='1' WHERE `map`=47; -- Razorfen Kraul
UPDATE `gameobject` SET `spawnDifficulties`='0' WHERE `map`=530; -- Outland
UPDATE `gameobject` SET `spawnDifficulties`='1,2' WHERE `spawnDifficulties`='0,1' AND `map`=643; -- Throne of the Tides
UPDATE `gameobject` SET `spawnDifficulties`='0' WHERE `map`=646; -- Deepholm
UPDATE `gameobject` SET `spawnDifficulties`='0' WHERE `map`=648; -- LostIsles
UPDATE `gameobject` SET `spawnDifficulties`='3,4,5,6' WHERE `spawnDifficulties`='0,1,2,3' AND `map`=671; -- The Bastion of Twilight
UPDATE `gameobject` SET `spawnDifficulties`='14,15,33' WHERE `spawnDifficulties`='3,4,5,6' AND `map`=720; -- Firelands
UPDATE `gameobject` SET `spawnDifficulties`='0' WHERE `map`=730; -- Maelstrom Zone
UPDATE `gameobject` SET `spawnDifficulties`='0' WHERE `map`=860; -- The Wandering Isle
UPDATE `gameobject` SET `spawnDifficulties`='0' WHERE `map`=870; -- Pandaria
UPDATE `gameobject` SET `spawnDifficulties`='2' WHERE `map`=940; -- Hour of Twilight
UPDATE `gameobject` SET `spawnDifficulties`='0' WHERE `map`=1064; -- Mogu Island Daily Area
UPDATE `gameobject` SET `spawnDifficulties`='0' WHERE `map`=1116; -- Draenor
UPDATE `gameobject` SET `spawnDifficulties`='0' WHERE `map`=1191; -- Ashran
UPDATE `gameobject` SET `spawnDifficulties`='0' WHERE `map`=1220; -- Broken Isles
UPDATE `gameobject` SET `spawnDifficulties`='0' WHERE `map`=1464; -- Tanaan Jungle

-- Wrong phases from cherry-picks
UPDATE `creature` SET `PhaseId`=0 WHERE `PhaseId`=1;
UPDATE `gameobject` SET `PhaseId`=0 WHERE `PhaseId`=1;
