-- If Grethok the Controller and Blackwing Guardsman are supposed to respawn after wipe,
-- respawntime means nothing here until the encounter is finished
-- Since they're part of encounter and are in formation with the boss, they should not respawn after being killed
UPDATE `creature` SET `spawntimesecs` = 604800 WHERE `id` IN (12557,14456);
-- Archbishop Benedictus, https://www.wowhead.com/npc=1284/archbishop-benedictus#comments
-- Seems correct since all racial leaders have the same respawn time
UPDATE `creature` SET `spawntimesecs` = 600 WHERE `id` IN (1284);
-- Doom Lord Kazzak, https://www.mmo-champion.com/threads/720835-Doom-Lord-Kazzak
-- https://wowwiki.fandom.com/wiki/World_boss
-- Let's change it to 2 days for now
UPDATE `creature` SET `spawntimesecs` = 172800 WHERE `id` IN (18728);
-- Brutallus, unkillable means default respawn time for us https://www.wowhead.com/npc=25158/brutallus#comments:id=943294
-- https://www.wowhead.com/npc=25158/brutallus#comments:id=330465
-- Since he does not use spells and can't kill Madrigosa, she too shares default respawn time
UPDATE `creature` SET `spawntimesecs` = 300 WHERE `id` IN (25158,25160);
-- Bosses
UPDATE `creature` SET `spawntimesecs` = 86400 WHERE `spawntimesecs` = 1000000;
-- Let's update Mulgore start area from 155 to 120 like in some other start areas
UPDATE `creature` SET `spawntimesecs` = 120 WHERE `id` IN (2955,2961,2966);

UPDATE `creature` SET `spawntimesecs` = 300 WHERE `id` IN (14724,16013,3505,3507,3508,3510,3511,3512,3513,23481,23482,23486,23510,23511,23521,23522,23525,23533,23558,23603,23604,23605,23606,23627,23628,23683,23684,23685,23696,23698,23710,24108,24462,24463,24468,24492,24493,24497,24498,24499,24501,24510,24657,24710,24711,5403,11278,11286,11815,11816,11817,11819,11857,12788,12789,12790,12791,12793,12794,12795,12796,12797,12798,13321,14833,16033,18528,19850,9699) AND `map` != 450;
UPDATE `creature` SET `spawntimesecs` = 300 WHERE `id` IN (15218,16123,17613,18253,18255,24729,24766,25058,25109,25946,27215,28650,29016,29019,29088,29728,34645,34682,34683,34708,34710,34712,35337,35340,35341,37674,39263,39275,39349,39368,39386,39396,39675,39678,39711,39715,39716,39717,7562,7565,7567,7772,8518,10988,25899,25929,24766,27216,27489,28601,28602,34681,34684,34685,34711,34713,34714,35338,35342,35343,15218,18687,21027,23142,23565,23705,23716,23718,23746,23748,23762,23764,24813,24965,24967,24975,25032,25043,25057,25061,25069,25112,25114,25163,25950,28343,28344,34783,34785,34786,34787,35099,35340,35342,37674);
UPDATE `creature` SET `spawntimesecs` = 300 WHERE `id` IN (4772,7410,28048,30578,30579,30583,31146,35021,35024,35025,36224,36225,36226,36273,36517,37888);
UPDATE `creature` SET `spawntimesecs` = 300 WHERE `id` IN (27928,28489,28491,28500,29194,29195,29196,29202,29246,29480,29587,32547,38065);
UPDATE `creature` SET `spawntimesecs` = 300 WHERE `id` IN (7427,29867,30580,30582,30590,30610,34955,35008,35017,35020,35023,40391,28092,24932,25167,25174,25992,25145,27946,30581,30584,30586,30587,35019,35022,35026,35027,37527,37552,11560,37509,37510);

-- Thrall is summoned after turning in quest
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 19556);
DELETE FROM `spawn_group` WHERE `spawnId` IN (SELECT `guid` FROM `creature` WHERE `id` = 19556);
DELETE FROM `creature` WHERE `id` IN (19556);
DELETE FROM `waypoint_data` WHERE `id` = 867510;
