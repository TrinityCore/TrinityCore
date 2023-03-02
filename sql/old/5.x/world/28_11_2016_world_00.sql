REPLACE INTO `achievement_criteria_data` (`criteria_id`, `type`, `ScriptName`) VALUES 
(18363, 11, 'achievement_thats_not_cannon');
REPLACE INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES 
(18607, 11, 0, 0, 'achievement_dont_stay_so_close_to_me');
UPDATE `creature_template` SET `ScriptName` = 'boss_murmur' WHERE `entry` = 18708;
UPDATE `creature_template` SET `ScriptName` = 'boss_grandmaster_vorpil' WHERE `entry` = 18732;
UPDATE `creature_template` SET `ScriptName` = 'boss_blackheart_the_inciter' WHERE `entry` = 18667;
UPDATE `creature_template` SET `ScriptName`='boss_ambassador_hellmaw' WHERE `entry`=18731;
REPLACE INTO `achievement_criteria_data` (`criteria_id`, `type`, `ScriptName`) VALUES 
(18495, 11, 'achievement_taste_the_rainbow_BY'),
(18496, 11, 'achievement_taste_the_rainbow_RG'),
(18497, 11, 'achievement_taste_the_rainbow_BB'),
(18498, 11, 'achievement_taste_the_rainbow_PY');
replace into `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) values('6084','11','0','0','achievement_minutes_to_midnight');
REPLACE INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES 
(18444, 11, 0, 0, 'achievement_deck_defender');
REPLACE INTO `achievement_criteria_data` (`criteria_id`, `type`, `ScriptName`) VALUES 
(18494, 11, 'achievement_ping_pong_champion');
UPDATE `creature_template` SET `ScriptName` = 'boss_hydromancer_thespia' WHERE `entry` = 17797;
UPDATE `creature_template` SET `ScriptName` = 'mob_coilfang_waterelemental' WHERE `entry` = 17917;
UPDATE `creature_template` SET `ScriptName`='boss_mekgineer_steamrigger' WHERE `entry`=17796;
UPDATE `creature_template` SET `ScriptName` = 'boss_hungarfen' WHERE `entry` = 17770;
UPDATE creature_template SET ScriptName='boss_warlord_kalithresh' WHERE entry=17798;
UPDATE `creature_template` SET `ScriptName`='mob_naga_distiller' WHERE `entry`=17954;
UPDATE `creature_template` SET `ScriptName`='mob_steamrigger_mechanic' WHERE `entry`=17951;
UPDATE `creature_template` SET `ScriptName`='boss_the_black_stalker' WHERE `entry`='17882';
UPDATE `creature_template` SET `ScriptName`='mob_fel_orc_convert' WHERE `entry`=17083;
UPDATE `creature_template` SET `ScriptName`='npc_Prince' WHERE (`entry`='38614');
update creature_template set AIName = '', scriptName = 'npc_watcher_gashra' where entry = 28730;
UPDATE `creature_template` SET `ScriptName`='mob_frost_sphere' WHERE `entry`='34606';
UPDATE creature_template SET ScriptName = 'npc_anub_ar_warrior' WHERE entry = 28732;
UPDATE creature_template SET ScriptName = 'npc_anub_ar_skirmisher' WHERE entry = 28734;
UPDATE creature_template SET ScriptName = 'npc_anub_ar_shadowcaster' WHERE entry = 28733;
update creature_template set AIName = '', scriptName = 'npc_watcher_silthik' where entry = 28731;
update creature_template set AIName = '', scriptName = 'npc_watcher_narjil' where entry = 28729;
UPDATE `creature_template` SET `ScriptName` = 'npc_dragon_soul_kalecgos_dragon' WHERE `entry` = 58210;
REPLACE INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(4244,11,0,0,'achievement_hadronox_denied');
UPDATE `creature_template` SET `ScriptName` = 'npc_dragon_soul_ysera_dragon' WHERE `entry` = 58209;
UPDATE `creature_template` SET `ScriptName` = 'npc_dragon_soul_nozdormu_dragon' WHERE `entry` = 58208;
UPDATE `creature_template` SET `ScriptName` = 'npc_madness_of_deathwing_elementium_terror' WHERE `entry` = 56710;
UPDATE `creature_template` SET `ScriptName` = 'npc_madness_of_deathwing_impaling_tentacle' WHERE `entry` = 56724;
UPDATE `creature_template` SET `ScriptName` = 'npc_madness_of_deathwing_deathwing' WHERE `entry` = 56173;
UPDATE `creature_template` SET `ScriptName` = 'npc_madness_of_deathwing_corrupting_parasite' WHERE `entry` = 57479;
UPDATE `creature_template` SET `ScriptName` = 'npc_madness_of_deathwing_elementium_bolt' WHERE `entry` = 56262;
UPDATE `creature_template` SET `ScriptName` = 'npc_madness_of_deathwing_regenerative_blood' WHERE `entry` = 56263;
UPDATE `gameobject_template` SET `ScriptName` = 'containment_sphere' WHERE `entry` IN (188527, 188528, 188526);
UPDATE `creature_template` SET `ScriptName` = 'mogu_engine_keeper' WHERE `entry` = 64068; 
UPDATE `creature_template` SET `scriptname`='npc_throneofthunder_teleporter' WHERE `entry`=74000;
UPDATE `creature_template` SET `ScriptName` = 'boss_norushen' WHERE `entry` = 71965;
UPDATE `creature_template` SET `ScriptName` = 'boss_jaomin_ro' WHERE `entry` = 54611;
UPDATE `creature_template` SET `ScriptName` = 'mob_jaomin_ro' WHERE `entry` = 57750;  



UPDATE `creature_template` SET `ScriptName` = 'mob_mogu_warden' WHERE `entry` = 64947; 
UPDATE `creature_template` SET `ScriptName` = 'mob_mogu_warden' WHERE `entry` = 64061; 
UPDATE `creature_template` SET `ScriptName` = 'boss_general_pavalak' WHERE `entry` = 61485; 









UPDATE `creature_template` SET `ScriptName` = 'mob_general_purpose_bunnyJMF' WHERE `entry` = 55091;   
REPLACE INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(10082,11,0,0,'achievement_i_choose_you'),
(10083,11,0,0,'achievement_i_choose_you'),
(10084,11,0,0,'achievement_i_choose_you'),
(10085,11,0,0,'achievement_i_choose_you'),
(10086,11,0,0,'achievement_i_choose_you'),
(10087,11,0,0,'achievement_i_choose_you'),
(10082,12,0,0,''),
(10083,12,0,0,''),
(10084,12,0,0,''),
(10085,12,1,0,''),
(10086,12,1,0,''),
(10087,12,1,0,'');

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10082,10083,10084,10085,10086,10087,10088,10418,10419,10089,10420,10421,10090,10422,10423,10091,10424,10425);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(10082, 11, 0, 0, 'achievement_i_choose_you'),
(10082, 12, 0, 0, ''),
(10083, 11, 0, 0, 'achievement_i_choose_you'),
(10083, 12, 0, 0, ''),
(10084, 11, 0, 0, 'achievement_i_choose_you'), 
(10084, 12, 0, 0, ''),
(10085, 11, 0, 0, 'achievement_i_choose_you_25'),
(10085, 12, 1, 0, ''),
(10086, 11, 0, 0, 'achievement_i_choose_you_25'),
(10086, 12, 1, 0, ''),
(10087, 11, 0, 0, 'achievement_i_choose_you_25'), 
(10087, 12, 1, 0, ''),
(10088, 11, 0, 0, 'achievement_but_i_am_on_your_side'), 
(10088, 12, 0, 0, ''),
(10418, 11, 0, 0, 'achievement_but_i_am_on_your_side'), 
(10418, 12, 0, 0, ''),
(10419, 11, 0, 0, 'achievement_but_i_am_on_your_side'), 
(10419, 12, 0, 0, ''),
(10089, 11, 0, 0, 'achievement_but_i_am_on_your_side_25'), 
(10089, 12, 1, 0, ''),
(10420, 11, 0, 0, 'achievement_but_i_am_on_your_side_25'),
(10420, 12, 1, 0, ''),
(10421, 11, 0, 0, 'achievement_but_i_am_on_your_side_25'),
(10421, 12, 1, 0, ''),
(10090, 11, 0, 0, 'achievement_cant_do_that_while_stunned'),
(10090, 12, 0, 0, ''),
(10422, 11, 0, 0, 'achievement_cant_do_that_while_stunned'), 
(10422, 12, 0, 0, ''),
(10423, 11, 0, 0, 'achievement_cant_do_that_while_stunned'), 
(10423, 12, 0, 0, ''),
(10091, 11, 0, 0, 'achievement_cant_do_that_while_stunned_25'), 
(10091, 12, 1, 0, ''),
(10424, 11, 0, 0, 'achievement_cant_do_that_while_stunned_25'),
(10424, 12, 1, 0, ''),
(10425, 11, 0, 0, 'achievement_cant_do_that_while_stunned_25'), 
(10425, 12, 1, 0, '');

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10284, 10722, 10285, 10095, 10290, 10133);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES 
(10285, 11, 0, 0, 'achievement_with_open_arms'),
(10285, 12, 0, 0, ''),
(10095, 11, 0, 0, 'achievement_with_open_arms_25'),
(10095, 12, 1, 0, ''),
(10290, 11, 0, 0, 'achievement_rubble_and_roll'),
(10290, 12, 0, 0, ''),
(10133, 11, 0, 0, 'achievement_rubble_and_roll_25'),
(10133, 12, 1, 0, '');






