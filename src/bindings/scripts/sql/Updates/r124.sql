-- BT Trash Mobs
UPDATE `creature_template` SET `scriptname`='mob_blacktemple' WHERE `entry` IN (22844,22845,22846,22849,22853,22855,22869,22873,22875,22876,22877,22878,22880,22881,22882,22883,22884,22945,22953,22954,23337,23339);

-- The Eye Trash Mobs
UPDATE `creature_template` SET `scriptname`='mob_the_eye' WHERE `entry` IN (20031,20032,20033,20034,20035,20039,20041,20043,20046,20052);
UPDATE `creature_template` SET `scriptname`='mob_crystalcore_devastator' WHERE `entry`='20040';

-- Uldaman Trash Mobs
UPDATE `creature_template` SET `scriptname`='mob_uldaman' WHERE `entry` IN (4847,4852,4853,4854,4860,4861,6910,7011,7012,7022,7030,7078,7291);
UPDATE `creature_template` SET `scriptname`='mob_jadespine_basilisk' WHERE `entry`='4863';

-- Uldaman Boss Ironaya
UPDATE `creature_template` SET `scriptname`='boss_ironaya' WHERE `entry`='7228';