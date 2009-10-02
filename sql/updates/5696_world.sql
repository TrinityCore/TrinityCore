
-- *Zum'Rah Area Trigger Script, Zum'Rah should become hostile when approached. By totoro.
DELETE FROM `areatrigger_scripts` WHERE `entry`=962;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES('962','at_zumrah');

-- *Judgement of Light PPM based, not 100%. By Drevi.
DELETE FROM `spell_proc_event` WHERE `entry`=20185;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
( 20185, 0x01,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,  15,   0,   0); -- Judgement of Light

-- *A Spirit Guide Escort Quest, code from SD2, patch by manuel.
UPDATE `creature_template` SET `ScriptName`='npc_ancestral_wolf' WHERE `entry`=17077;

-- This should be sent to TDB
-- INSERT INTO `gameobject` VALUES (NULL, 300070, 530, 1,1,-20.236, 3803.41, 93.1402, 5.24994, 0, 0, 0.493946, -0.869492, 25, 0, 1);

DELETE FROM `script_texts` WHERE `npc_entry`=17077;
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
   (17077,-1000496,'%s lifts its head into the air, as if listening for something.',0,2,0,0,'ancestral wolf EMOTE_WOLF_LIFT_HEAD'),
   (17077,-1000497,'%s lets out a howl that rings across the mountains to the north and motions for you to follow.',0,2,0,0,'ancestral wolf EMOTE_WOLF_HOWL'),
   (17077,-1000498,'Welcome, kind spirit. What has brought you to us?',0,0,0,0,'ancestral wolf SAY_WOLF_WELCOME');

DELETE FROM `script_waypoint` WHERE `entry`=17077;
INSERT INTO `script_waypoint` VALUES
   (17077, 0, -16.950142, 3801.409424, 95.064, 5000, 'EMOTE_WOLF_LIFT_HEAD'),
   (17077, 1, -15.577404, 3805.170898, 94.833, 2500, ''),
   (17077, 2, -20.011766, 3806.609863, 92.476, 5000, 'EMOTE_WOLF_HOWL'),
   (17077, 3, -18.594666, 3816.207764, 91.482, 0, ''),
   (17077, 4, -19.293468, 3838.218750, 85.012, 0, ''),
   (17077, 5, -16.504408, 3871.034668, 82.327, 0, ''),
   (17077, 6, 2.064510, 3898.678711, 85.623, 0, ''),
   (17077, 7, 16.403864, 3921.174072, 86.024, 0, ''),
   (17077, 8, 47.307926, 3932.001465, 83.302, 0, ''),
   (17077, 9, 90.067230, 3942.906250, 77.000, 0, ''),
   (17077, 10, 106.886024, 3944.388428, 76.502, 0, ''),
   (17077, 11, 139.085480, 3941.897217, 80.617, 0, ''),
   (17077, 12, 150.092346, 3942.782959, 80.399, 0, ''),
   (17077, 13, 193.511475, 3950.396484, 74.366, 0, ''),
   (17077, 14, 226.274948, 3958.003418, 73.257, 0, ''),
   (17077, 15, 246.686981, 3963.309326, 76.376, 0, ''),
   (17077, 16, 264.206177, 3977.726563, 83.704, 0, ''),
   (17077, 17, 279.857422, 3986.417236, 88.245, 0, ''),
   (17077, 18, 304.039642, 3998.354004, 95.649, 0, ''),
   (17077, 19, 328.071503, 3995.832764, 104.434, 0, ''),
   (17077, 20, 347.485229, 3990.817627, 113.608, 0, ''),
   (17077, 21, 351.257202, 3954.260254, 125.747, 0, ''),
   (17077, 22, 345.625977, 3932.016113, 132.358, 0, ''),
   (17077, 23, 347.971893, 3908.549561, 135.520, 0, ''),
   (17077, 24, 351.887878, 3891.062744, 139.957, 0, ''),
   (17077, 25, 346.116852, 3864.634277, 146.647, 0, ''),
   (17077, 26, 330.012360, 3839.859375, 154.148, 0, ''),
   (17077, 27, 297.250610, 3811.855225, 166.893, 0, ''),
   (17077, 28, 290.783112, 3800.188477, 172.130, 0, ''),
   (17077, 29, 288.125427, 3782.474365, 180.825, 0, ''),
   (17077, 30, 296.817841, 3771.629639, 184.961, 0, ''),
   (17077, 31, 305.256256, 3765.380615, 185.360, 0, ''),
   (17077, 32, 311.447906, 3757.902100, 184.312, 0, ''),
   (17077, 33, 325.258026, 3730.282227, 184.076, 0, ''),
   (17077, 34, 341.158630, 3717.757080, 183.904, 0, ''),
   (17077, 35, 365.589020, 3717.200684, 183.902, 0, ''),
   (17077, 36, 387.395081, 3731.750732, 183.645, 0, ''),
   (17077, 37, 396.574127, 3732.604248, 179.831, 0, ''),
   (17077, 38, 404.303192, 3737.313232, 180.151, 0, ''),
   (17077, 39, 410.995972, 3742.286865, 183.364, 0, ''),
   (17077, 40, 434.904541, 3761.058838, 186.219, 0, ''),
   (17077, 41, 460.128815, 3774.436768, 186.348, 0, ''),
   (17077, 42, 467.643951, 3788.506104, 186.446, 0, ''),
   (17077, 43, 491.551666, 3815.446777, 189.848, 0, ''),
   (17077, 44, 496.957855, 3836.875244, 193.078, 0, ''),
   (17077, 45, 502.889191, 3855.458740, 194.834, 0, ''),
   (17077, 46, 508.208466, 3863.689453, 194.024, 0, ''),
   (17077, 47, 528.907593, 3887.348633, 189.762, 0, ''),
   (17077, 48, 527.722229, 3890.686523, 189.240, 0, ''),
   (17077, 49, 524.637329, 3891.768066, 189.149, 0, ''),
   (17077, 50, 519.146057, 3886.701660, 190.128, 60000, 'SAY_WOLF_WELCOME');

-- *TrullyOne/MeanMachine Waypoint System Restored. Patch by XTElite1.
-- This should be applied to world_script_waypoints.sql ASAP
ALTER TABLE `creature_addon`
    ADD `path_id` int(11) unsigned NOT NULL default '0' AFTER `guid`;
ALTER TABLE `creature_template_addon`
    ADD `path_id` int(11) unsigned NOT NULL default '0' AFTER `entry`;

ALTER TABLE `waypoint_data` ADD COLUMN `id_old` int(10) unsigned NOT NULL default '0' COMMENT 'Creature GUID' AFTER `wpguid`;
UPDATE `waypoint_data` SET `id_old`=`id`*0.1;

REPLACE INTO `creature_addon` ( `guid` ) SELECT `id_old` FROM `waypoint_data`;

UPDATE `creature_addon`,`waypoint_data` SET `creature_addon`.`path_id` = `waypoint_data`.`id` WHERE `creature_addon`.`guid`=`waypoint_data`.`id_old`;

ALTER TABLE `waypoint_data` DROP COLUMN `id_old`;
