--
UPDATE `creature` SET `spawntimesecs` = 300 WHERE `spawntimesecs` IN (190,200,360,400,425,430,444,450,490,498,500,534,543,570,588,700,720,1250,1272,1290,1416,1434,3540,5400);
UPDATE `creature` SET `spawntimesecs` = 300 WHERE `id` IN (22024,20552,10204,10942);

-- Won't touch 8 min respawn time of Son of Hodir and Frostworg, at least for now
UPDATE `creature` SET `spawntimesecs` = 300 WHERE `spawntimesecs` = 480 AND `map` != 571;
-- Won't touch 4 (and 2) min respawn time of Risen Zombie, at least for now
UPDATE `creature` SET `spawntimesecs` = 300 WHERE `spawntimesecs` = 240 AND `map` != 595;
-- Bosses
UPDATE `creature` SET `spawntimesecs` = 604800 WHERE `spawntimesecs` = 6380;

-- Loque'nahak, one of most-wanted rare tamable creature in whole game respawns in 8 min, really?
UPDATE `creature` SET `spawntimesecs` = 21600 WHERE `id` = 32517; -- From wiki
-- Okrek, Outland rare
UPDATE `creature` SET `spawntimesecs` = 28800 WHERE `id` = 18685; -- From 18684
-- High Tinker Mekkatorque
UPDATE `creature` SET `spawntimesecs` = 600 WHERE `id` = 7937; -- From Wowhead

-- Wrong spawns, summoned or spawns only after specific events
DELETE FROM `creature` WHERE `id` IN (14350,18381,20436,20792,18297);
