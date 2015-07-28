DELETE FROM `game_graveyard_zone` WHERE `ghost_zone`=33;
DELETE FROM `game_graveyard_zone` WHERE `id` IN (919, 920) AND `ghost_zone`=3535;
DELETE FROM `game_graveyard_zone` WHERE `id` IN (98, 149, 1285) AND `ghost_zone`=36;

UPDATE `game_graveyard_zone` SET `ghost_zone`=267 WHERE `id`=1411;
UPDATE `game_graveyard_zone` SET `ghost_zone`=4922 WHERE `id`=1813;
UPDATE `game_graveyard_zone` SET `ghost_zone`=5339 WHERE `ghost_zone`=5287;
UPDATE `game_graveyard_zone` SET `ghost_zone`=5146 WHERE `id`=1778 AND `ghost_zone`=5145;
UPDATE `game_graveyard_zone` SET `ghost_zone`=5146 WHERE `id` IN (1722, 1723, 1724, 1725, 1745, 1746, 1747);

DELETE FROM `game_tele` WHERE `id`=1371; -- Old Zul'Gurub Raid

-- (Creatures from old build - these values were 0)
UPDATE `creature_template` SET `faction_A`=35, `faction_H`=35, `unit_class`=1 WHERE `entry` IN (51275, 54352);

UPDATE `creature_template` SET `npcflag`=`npcflag`|0x2 WHERE `entry` IN (620, 9860, 9861, 15078, 16483, 17311, 17982, 23053, 23897, 34830, 35381, 36471, 38124, 38517, 38738, 39065, 40552, 41530, 42333, 43778, 43837, 47162, 47296, 4753, 47626, 47739, 49871, 49874, 50039, 50047, 52399, 53371, 53422);

DELETE FROM `creature_addon` WHERE `guid`=88732;

UPDATE `creature` SET `equipment_id`=0 WHERE `id` IN (23585, 47182, 47657, 47680);

-- Old gameobjects no longer used
DELETE FROM `gameobject` WHERE `id` IN (94039, 128196, 176211, 178164, 181272, 181282, 181284, 181285, 181376, 181676, 181677, 181678, 181679, 181695, 182051, 183122, 183123, 184080, 184081, 184082, 184083, 184109, 184143, 185122, 185139, 185324, 185499, 185502, 185879, 186470, 186617, 186620, 187690, 188500, 188711, 190557, 190857, 192523, 193579, 193582, 193607, 193962, 193982, 194010, 194013, 194029);
