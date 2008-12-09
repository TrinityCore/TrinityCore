UPDATE `creature_template` SET `ScriptName` = 'boss_nalorakk' WHERE `entry` = 23576;
UPDATE `creature_template` set `ScriptName` = 'boss_akilzon' where entry = 23574;
UPDATE `creature_template` set `ScriptName` = 'mob_akilzon_eagle' where `entry`=24858; /*default is event ai*/
UPDATE `creature_template` SET `ScriptName` = 'boss_halazzi' WHERE `entry` = '23577';
UPDATE `creature_template` SET `ScriptName` = 'mob_halazzi_lynx' WHERE `entry` = '24143';
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = '24224'; /*totem default `spell1` = '43301' should be in DB*/
UPDATE `creature_template` SET `ScriptName` = 'boss_janalai' WHERE `entry` = '23578';
UPDATE `creature_template` SET `ScriptName` = 'mob_janalai_hatcher' WHERE `entry` = '23818';
UPDATE `creature_template` SET `ScriptName` = 'mob_janalai_hatchling' WHERE `entry` = '23598';
UPDATE `creature_template` SET `ScriptName` = 'mob_janalai_egg' WHERE `entry` = '23817';
UPDATE `creature_template` SET `ScriptName` = 'mob_janalai_firebomb' WHERE `entry` = '23920';
UPDATE `creature_template` SET `ScriptName` = 'boss_hexlord_malacrass' WHERE `entry` =24239;
UPDATE `creature_template` SET `ScriptName` = 'boss_alyson_antille' WHERE `entry` =24240;
UPDATE `creature_template` SET `ScriptName` = 'boss_thurg' WHERE `entry` =24241;
UPDATE `creature_template` SET `ScriptName` = 'boss_slither' WHERE `entry` =24242;
UPDATE `creature_template` SET `ScriptName` = 'boss_lord_raadan' WHERE `entry` =24243;
UPDATE `creature_template` SET `ScriptName` = 'boss_gazakroth' WHERE `entry` =24244;
UPDATE `creature_template` SET `ScriptName` = 'boss_fenstalker' WHERE `entry` =24245;
UPDATE `creature_template` SET `ScriptName` = 'boss_darkheart' WHERE `entry` =24246;
UPDATE `creature_template` SET `ScriptName` = 'boss_koragg' WHERE `entry` =24247;
UPDATE `creature_template` SET `ScriptName` = 'boss_zuljin' WHERE `entry` =23863;
UPDATE `creature_template` SET `ScriptName` = 'do_nothing' WHERE `entry` = '24187';
UPDATE `creature_template` SET `ScriptName` = 'mob_zuljin_vortex' WHERE `entry` = '24136';
UPDATE `creature_template` SET `ScriptName` = 'npc_zulaman_hostage' WHERE `entry` IN (23790, 23999, 24024, 24001);

-- sunwell
update instance_template set script = 'instance_sunwell_plateau' where map = 580;
UPDATE creature_template SET scriptname = 'boss_kalecgos' WHERE entry = 24850;
UPDATE creature_template SET scriptname = 'boss_sathrovarr' WHERE entry = 24892;
UPDATE creature_template SET scriptname = 'boss_kalec' WHERE entry = 24891;
UPDATE gameobject_template SET scriptname = 'kalocegos_teleporter' WHERE entry = 187055;
UPDATE creature_template SET ScriptName = 'boss_brutallus' WHERE entry = 24882;
UPDATE `creature_template` SET `ScriptName` = 'boss_felmyst' WHERE `entry` = 25038;
UPDATE `creature_template` SET `ScriptName` = 'mob_felmyst_vapor' WHERE `entry` = 25265;
UPDATE `creature_template` SET `ScriptName` = 'mob_felmyst_trail' WHERE `entry` = 25267;
update creature_template set scriptname = 'boss_sacrolash' where entry = 25165;
update creature_template set scriptname = 'boss_alythess' where entry = 25166;
update creature_template set scriptname = 'mob_shadow_image' where entry = 25214;

UPDATE instance_template SET script="instance_uldaman" where map = 70;
UPDATE creature_template SET ScriptName="boss_archaedas" where entry = 2748;
UPDATE creature_template SET ScriptName="mob_archaedas_minions" where entry in ('7309', '7077', '7076', '10120');
UPDATE creature_template SET ScriptName="mob_stonekeepers" where entry = 4857;
UPDATE gameobject_template set scriptName="go_altar_of_the_keepers" where entry = 130511;
UPDATE gameobject_template set scriptName="go_altar_of_archaedas" where entry = 133234;

update creature_template SET scriptname='npc_overlord_morghor' WHERE entry=23139;
update creature_template SET scriptname='npc_lord_illidan_stormrage' WHERE entry=22083;
update creature_template SET scriptname='npc_yarzill_the_merc' WHERE entry=23141;

UPDATE creature_template SET ScriptName = 'mob_toxic_sporebat' WHERE entry = '22140';
UPDATE creature_template SET ScriptName = 'boss_leotheras_the_blind' WHERE entry = '21215';
UPDATE creature_template SET ScriptName = 'boss_leotheras_the_blind_demonform' WHERE entry = '21875';
UPDATE creature_template SET ScriptName = 'mob_greyheart_spellbinder' WHERE entry = '21806';
UPDATE creature_template SET ScriptName = 'mob_inner_demon' WHERE entry = '21857';
UPDATE creature_template SET ScriptName = 'boss_the_lurker_below' WHERE entry = '21217';
UPDATE creature_template SET ScriptName = 'mob_coilfang_ambusher' WHERE entry = '21865';
UPDATE creature_template SET ScriptName = 'mob_coilfang_guardian' WHERE entry = '21873';

update gameobject_template set scriptname = 'go_najentus_spine' where entry = 185584;
update creature_template set scriptname = 'mob_blade_of_azzinoth' where entry = 22996;
update creature_template set scriptname = 'mob_parasitic_shadowfiend' where entry = 23498;

update `creature_template` set `ScriptName`='boss_alar' where `entry`='19514';
update `creature_template` set `ScriptName`='mob_ember_of_alar' where `entry`='19551';
update `creature_template` set `ScriptName`='mob_flame_patch_alar' where `entry`='20602';
update gameobject_template set scriptname = "go_manticron_cube" where entry = 181713;
update creature_template set scriptname = "mob_abyssal" where entry = 17454;

update creature_template set scriptname = 'boss_warchief_kargath_bladefist' where entry = 16808;
UPDATE `instance_template` SET `script`='instance_deadmines' WHERE map = 36;
UPDATE `item_template` SET `ScriptName`='item_defias_gunpowder' WHERE entry = 5397;

UPDATE `creature_template` SET `ScriptName` = 'npc_twiggy_flathead' WHERE `entry` =6248;
UPDATE `item_template` SET `ScriptName`='item_arcane_charges' WHERE `entry`='34475';
UPDATE `gameobject_template` SET `ScriptName` = 'go_kael_orb' WHERE `entry` = 188173;
UPDATE `gameobject_template` SET `ScriptName` = 'go_movie_orb' WHERE `entry` = 187578;
UPDATE `creature_template` SET `ScriptName`='npc_defias_traitor' WHERE `entry`='467';
UPDATE `creature_template` SET `ScriptName`='npc_clintar_dreamwalker' WHERE `entry`=22834;
UPDATE `creature_template` SET `ScriptName`='npc_clintar_spirit' WHERE `entry` = 22916;
UPDATE `creature_template` SET `ScriptName`='mob_sparrowhawk' WHERE `entry`=22979;
UPDATE `creature_template` SET `ScriptName`='mob_rizzle_sprysprocket' WHERE `entry`=23002;
UPDATE `creature_template` SET `ScriptName`='mob_depth_charge' WHERE `entry`=23025;
UPDATE `creature_template` SET `ScriptName`='boss_pathaleon_the_calculator' WHERE `entry`=19220;
UPDATE `creature_template` SET `ScriptName`='mob_nether_wraith' WHERE `entry`=21062;
UPDATE `instance_template` SET `script`='instance_mechanar' WHERE `map`=554;
UPDATE `creature_template` SET `ScriptName`='npc_wounded_blood_elf' WHERE `entry`='16993';
UPDATE `creature_template` SET `ScriptName` = 'mob_phase_hunter' WHERE `entry` = '18879';

-- quest
update gameobject_template set scriptname = 'go_gilded_brazier' where entry = 181956;
update creature_template set scriptname = 'npc_second_trial_paladin' where entry in (17809,17810,17811,17812);
update creature_template set scriptname = 'npc_second_trial_controller' where entry in (17807);
update gameobject_template set scriptname = 'go_second_trial' where entry in (182052);