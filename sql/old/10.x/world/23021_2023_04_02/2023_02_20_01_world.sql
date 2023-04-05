-- Delete Onnessa & Worker
DELETE FROM `creature` WHERE `guid` IN (1051067, 1051066);
DELETE FROM `creature_addon` WHERE `guid` IN (1051067, 1051066);

-- Delete Excavation Stake Gob
DELETE FROM `gameobject` WHERE `guid` IN (600226, 600227);
DELETE FROM `gameobject_addon` WHERE `guid` IN (600226, 600227);
