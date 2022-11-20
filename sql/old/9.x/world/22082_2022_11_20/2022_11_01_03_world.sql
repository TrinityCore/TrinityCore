-- Pre Broken Shore Harbor incorrect spawns
DELETE FROM `creature` WHERE `guid` IN (650989, 650998, 651006, 651007, 651012, 651016, 651024);
DELETE FROM `gameobject` WHERE `guid`=400277;

-- Duplicated - Totally Generic Bunny (All Phase)
DELETE FROM `creature` WHERE `guid` IN (651019, 651028);
