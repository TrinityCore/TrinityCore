/* Instance The Vortex Pinnacle */
UPDATE `instance_template` SET `script` = 'instance_the_vortex_pinnacle' WHERE `map` = 657;

/*---- Grand Vizier Ertan ----*/
UPDATE `creature_template` SET `ScriptName` = 'boss_grand_vizier_ertan' WHERE `entry` = 43878;
UPDATE `creature_template` SET `ScriptName` = 'npc_ertans_vortex' WHERE `entry` = 46007;

UPDATE `creature_template` SET `mechanic_immune_mask` = (1|2|8|16|32|64|256|512|1024|2048|4096|8192|65536|8388608|33554432|67108864|536870912) WHERE `entry` = 43878;

UPDATE `creature_template` SET `unit_flags` = (2|512|131072|33554432) WHERE `entry` = 46007;

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(43878, 0, 0, 'Filthy beasts! Your presence in Skywall will not be tolerated!', 14, 0, 100, 0, 0, 20876, 'Grand Vizier Ertan - Aggro'),
(43878, 1, 0, 'Ravaged!', 14, 0, 100, 0, 0, 20877, 'Grand Vizier Ertan - Slay'),
(43878, 2, 0, 'AHHHHHHHHH!', 14, 0, 100, 0, 0, 20878, 'Grand Vizier Ertan - Death'),
(43878, 3, 0, '%s pulls her cyclone shield back!', 41, 0, 100, 0, 0, 20878, 'Grand Vizier Ertan - Cyclone Shield');

/*---- Altairus ----*/
UPDATE `creature_template` SET `ScriptName` = 'boss_altairus' WHERE `entry` = 43873;

UPDATE `creature_template` SET `mechanic_immune_mask` = (1|2|8|16|32|64|256|512|1024|2048|4096|8192|65536|8388608|33554432|67108864|536870912) WHERE `entry` = 43873;

/*---- Asaad ----*/
UPDATE `creature_template` SET `ScriptName` = 'boss_grand_vizier_ertan' WHERE `entry` = 43875;

UPDATE `creature_template` SET `mechanic_immune_mask` = (1|2|8|16|32|64|256|512|1024|2048|4096|8192|65536|8388608|33554432|67108864|536870912) WHERE `entry` = 43875;

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(43875, 0, 0, 'YOU tread upon the sacrosanct! Mortals have no please amidst the clouds.', 14, 0, 0, 0, 0, 20867, 'Asaad - Aggro'),
(43875, 1, 0, 'BACK to the earth with you!', 14, 0, 0, 0, 0, 20868, 'Asaad - Slay'),
(43875, 2, 0, 'The winds take me!', 14, 0, 0, 0, 0, 20870, 'Asaad - Death'),
(43875, 3, 0, 'AlAkir, your servant calls for aid!', 14, 0, 0, 0, 0, 20869, 'Assad - Unstable Grounding Field');

