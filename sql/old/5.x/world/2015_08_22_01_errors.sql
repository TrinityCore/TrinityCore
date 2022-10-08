UPDATE `creature_template` SET `ScriptName`='boss_novos' WHERE `entry`=26631;
UPDATE `creature_template` SET `ScriptName`='mob_hisek_the_swarmkeeper' WHERE `entry`=71153;
UPDATE `creature_template` SET `ScriptName`='mob_restless_leng' WHERE `entry`=65698;
UPDATE `creature_template` SET `Scriptname`='mob_iceborn_protodrake' WHERE `entry`=36891;
UPDATE `creature_template` SET `ScriptName`='mob_talking_fish' WHERE `entry`=59546;
UPDATE creature_template SET ScriptName = 'mob_resin_flake' WHERE entry = 61910;
UPDATE creature_template SET ScriptName = 'mob_sikthik_amber_weaver' WHERE entry = 61929;
UPDATE creature_template SET ScriptName = 'mob_sikthik_guardian' WHERE entry = 61928;
UPDATE creature_template SET modelid1 = 38497, modelid2 = 0 WHERE entry = 62208;
UPDATE `creature_template` SET `ScriptName`='boss_jinbak' WHERE `entry`=61567;
UPDATE creature_template SET ScriptName='npc_thorim' WHERE entry=29445;
DELETE FROM `instance_template` WHERE `map`=1011;
INSERT INTO `instance_template` VALUES (1011, 870, 'instance_siege_of_the_niuzoa_temple', 0);
update creature_template set ScriptName = 'mob_whirling_dervish' where entry = 61626;
UPDATE `creature_template` SET `ScriptName`='boss_the_black_stalker' WHERE `entry`='17882';
UPDATE `creature_template` SET `ScriptName`='boss_warbringer_omrogg' WHERE `entry`=16809;
UPDATE `creature_template` SET `ScriptName` = 'boss_hungarfen' WHERE `entry` = 17770;
UPDATE `creature_template` SET `ScriptName`='boss_laj' WHERE `entry`=17980;
UPDATE `creature_template` SET `ScriptName` = 'boss_gatewatcher_iron_hand' WHERE `entry` = 19710;
UPDATE `creature_template` SET `ScriptName` = 'boss_nethermancer_sepethrea' WHERE `entry` = 19221;
UPDATE `creature_template` SET `ScriptName` = 'boss_murmur' WHERE `entry` = 18708;
UPDATE `creature_template` SET `ScriptName`='boss_ambassador_hellmaw' WHERE `entry`=18731;
UPDATE `creature_template` SET `ScriptName` = 'boss_exarch_maladaar' WHERE `entry` = 18373;
UPDATE `creature_template` SET `ScriptName` = 'boss_nexusprince_shaffar' WHERE `entry` = 18344;
UPDATE `creature_template` SET `ScriptName` = 'boss_grandmaster_vorpil' WHERE `entry` = 18732;
UPDATE `creature_template` SET `ScriptName` = 'boss_hydromancer_thespia' WHERE `entry` = 17797;
UPDATE `creature_template` SET `ScriptName`='boss_mekgineer_steamrigger' WHERE `entry`=17796;
UPDATE `creature_template` SET `ScriptName` = 'boss_darkweaver_syth' WHERE `entry` = 18472;


INSERT INTO spell_script_names VALUES (121114, 'spell_resin_weaving');
INSERT INTO spell_script_names VALUES (106548, 'spell_madness_of_deathwing_agonizing_pain');
INSERT INTO spell_script_names VALUES (108649, 'spell_madness_of_deathwing_corrupting_parasite_aura');

