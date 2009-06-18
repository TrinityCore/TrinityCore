UPDATE `creature_template` SET `ScriptName`='mob_giant_infernal' WHERE `entry`=17908;
UPDATE `creature_template` SET `ScriptName`='mob_abomination' WHERE `entry`=17898;
UPDATE `creature_template` SET `ScriptName`='mob_ghoul' WHERE `entry`=17895;
UPDATE `creature_template` SET `ScriptName`='mob_necromancer' WHERE `entry`=17899;
UPDATE `creature_template` SET `ScriptName`='mob_banshee' WHERE `entry`=17905;
UPDATE `creature_template` SET `ScriptName`='mob_crypt_fiend' WHERE `entry`=17897;
UPDATE `creature_template` SET `ScriptName`='mob_fel_stalker' WHERE `entry`=17916;
UPDATE `creature_template` SET `ScriptName`='mob_frost_wyrm' WHERE `entry`=17907;
UPDATE `creature_template` SET `ScriptName`='mob_gargoyle' WHERE `entry`=17906;
UPDATE `creature_template` SET `ScriptName`='alliance_rifleman' WHERE `entry`=17921;

UPDATE `creature_template` SET `ScriptName`='mob_towering_infernal' WHERE `entry`=17818;
UPDATE `creature_template` SET `ScriptName`='boss_anetheron' WHERE `entry`=17808;

UPDATE `creature_template` SET `ScriptName`='boss_azgalor' WHERE `entry`=17842;
UPDATE `creature_template` SET `ScriptName`='mob_lesser_doomguard' WHERE `entry`=17864;

UPDATE `creature_template` SET `ScriptName`='boss_kazrogal' WHERE `entry`=17888;

UPDATE `creature_template` SET `ScriptName`='boss_rage_winterchill' WHERE `entry`=17767;

UPDATE `creature_template` SET `scale`='0.5' WHERE `entry`=17968;

UPDATE `creature_template` SET `equipment_id`='17888' WHERE `entry`=17888;
UPDATE `creature_template` SET `equipment_id`='17921' WHERE `entry`=17921;

DELETE FROM creature_equip_template WHERE `entry` IN (17888, 17921);
INSERT INTO creature_equip_template () VALUES (17888, 45776, 0, 0, 33490946, 0, 0, 0, 0, 0);
INSERT INTO creature_equip_template () VALUES (17921, 20732, 0, 20732, 33489666, 0, 33489666, 26, 0, 26);



