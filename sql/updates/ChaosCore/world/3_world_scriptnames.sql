DELETE FROM `spell_script_names` WHERE `spell_id` = 68645;
INSERT INTO `spell_script_names` VALUES (68645,"spell_icc_rocket_pack");
UPDATE `creature_template` SET `ScriptName` = "npc_sindragosas_ward" WHERE `entry` = 37503;
DELETE FROM `areatrigger_scripts` WHERE `entry` = 5623;
INSERT INTO `areatrigger_scripts` VALUES (5623,"at_icc_start_sindragosa_gauntlet");


