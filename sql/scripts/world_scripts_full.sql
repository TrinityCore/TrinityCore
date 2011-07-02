-- Up to TC 11181

-- Cleanup first
UPDATE `battleground_template` SET `ScriptName`='';
UPDATE `instance_template` SET `Script`='';
UPDATE `item_template` SET `ScriptName`='';
UPDATE `creature_template` SET `ScriptName`='';
UPDATE `gameobject_template` SET `ScriptName`='';
UPDATE `outdoorpvp_template` SET `ScriptName`='';

/* AREA TRIGGERS */
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (822,5284,5285,5286,5287,4871,4872,4873,5108,5332,5338,5334,5340,5369,5423,5633,5604,5698,5649,5729,5616,5617,5618,5718);
DELETE FROM `areatrigger_scripts` WHERE `entry` BETWEEN 1726 AND 1740;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES 
(822, 'at_map_chamber'),
(5284, 'at_aldurthar_gate'),
(5285, 'at_aldurthar_gate'),
(5286, 'at_aldurthar_gate'),
(5287, 'at_aldurthar_gate'),
(4871, 'at_warsong_farms'),
(4872, 'at_warsong_farms'),
(4873, 'at_warsong_farms'),
(5108, 'at_stormwright_shelf'),
(5332, 'at_last_rites'),
(5338, 'at_last_rites'),
(5334, 'at_last_rites'),
(5340, 'at_last_rites'),
(1726, 'at_scent_larkorwi'),
(1727, 'at_scent_larkorwi'),
(1728, 'at_scent_larkorwi'),
(1729, 'at_scent_larkorwi'),
(1730, 'at_scent_larkorwi'),
(1731, 'at_scent_larkorwi'),
(1732, 'at_scent_larkorwi'),
(1733, 'at_scent_larkorwi'),
(1734, 'at_scent_larkorwi'),
(1735, 'at_scent_larkorwi'),
(1736, 'at_scent_larkorwi'),
(1737, 'at_scent_larkorwi'),
(1738, 'at_scent_larkorwi'),
(1739, 'at_scent_larkorwi'),
(1740, 'at_scent_larkorwi'),
(5369, 'at_RX_214_repair_o_matic_station'),
(5423, 'at_RX_214_repair_o_matic_station'),
(5633, 'at_tyrannus_event_starter'),
(5604, 'at_sindragosa_lair'),
(5698, 'at_icc_saurfang_portal'),
(5649, 'at_icc_shutdown_traps'),
(5729, 'at_icc_start_blood_quickening'),
(5616, 'at_icc_start_frostwing_gauntlet'),
(5617, 'at_icc_start_frostwing_gauntlet'),
(5618, 'at_icc_start_frostwing_gauntlet'),
(5718, 'at_frozen_throne_teleport');

/* WORLD BOSS */
UPDATE `creature_template` SET `ScriptName`='boss_ysondre' WHERE `entry`=14887;
UPDATE `creature_template` SET `ScriptName`='boss_emeriss' WHERE `entry`=14889;
UPDATE `creature_template` SET `ScriptName`='boss_taerar' WHERE `entry`=14890;
UPDATE `creature_template` SET `ScriptName`='boss_shade_of_taerar' WHERE `entry`=15302;
UPDATE `creature_template` SET `ScriptName`='boss_kruul' WHERE `entry`=18338;
UPDATE `creature_template` SET `ScriptName`='boss_azuregos' WHERE `entry`=6109;
UPDATE `creature_template` SET `ScriptName`='mob_dementeddruids' WHERE `entry`=15260;
UPDATE `creature_template` SET `ScriptName`='boss_mr_smite' WHERE `entry`=646;

/* GO */
UPDATE `gameobject_template` SET `ScriptName`='go_cat_figurine' WHERE `entry`=13873;
UPDATE `gameobject_template` SET `ScriptName`='go_northern_crystal_pylon' WHERE `entry`=164955;
UPDATE `gameobject_template` SET `ScriptName`='go_western_crystal_pylon' WHERE `entry`=164956;
UPDATE `gameobject_template` SET `ScriptName`='go_eastern_crystal_pylon' WHERE `entry`=164957;
UPDATE `gameobject_template` SET `ScriptName`='go_barov_journal' WHERE `entry`=180794;
UPDATE `gameobject_template` SET `ScriptName`='go_field_repair_bot_74A' WHERE `entry`=179552;
UPDATE `gameobject_template` SET `ScriptName`='go_orb_of_command' WHERE `entry`=179879;
UPDATE `gameobject_template` SET `ScriptName`='go_resonite_cask' WHERE entry=178145;
UPDATE `gameobject_template` SET `ScriptName`='go_tablet_of_madness' WHERE `entry`=180368;
UPDATE `gameobject_template` SET `ScriptName`='go_tablet_of_the_seven' WHERE `entry`=169294;
UPDATE `gameobject_template` SET `ScriptName`='go_manticron_cube' WHERE `entry`=181713;
UPDATE `gameobject_template` SET `ScriptName`='go_mausoleum_trigger' WHERE `entry`=104593;
UPDATE `gameobject_template` SET `ScriptName`='go_mausoleum_door' WHERE `entry`=176594;
UPDATE `gameobject_template` SET `ScriptName`='go_crystal_prison' WHERE `entry`=185126;
UPDATE `gameobject_template` SET `ScriptName`='go_legion_obelisk' WHERE `entry` IN (185193,185195,185196,185197,185198);
UPDATE `gameobject_template` SET `ScriptName`='go_jump_a_tron' WHERE `entry`=183146;
UPDATE `gameobject_template` SET `ScriptName`='go_ethereum_prison' WHERE `entry` BETWEEN 184418 AND 184431;
UPDATE `gameobject_template` SET `ScriptName`='go_ethereum_stasis' WHERE `entry` BETWEEN 185465 AND 185467;
UPDATE `gameobject_template` SET `ScriptName`='go_ethereum_stasis' WHERE `entry`=184595;
UPDATE `gameobject_template` SET `ScriptName`='go_ethereum_stasis' WHERE `entry` BETWEEN 185461 AND 185464;
UPDATE `gameobject_template` SET `ScriptName`='go_sacred_fire_of_life' WHERE `entry`=175944;
UPDATE `gameobject_template` SET `ScriptName`='go_skull_pile' WHERE `entry`=185913;
UPDATE `gameobject_template` SET `ScriptName`='go_tele_to_dalaran_crystal' WHERE `entry`=191230;
UPDATE `gameobject_template` SET `ScriptName`='go_tele_to_violet_stand' WHERE `entry`=191229;
UPDATE `gameobject_template` SET `ScriptName`='go_orb_of_the_blue_flight' WHERE `entry`=188415;
UPDATE `gameobject_template` SET `ScriptName`='go_acherus_soul_prison' WHERE `entry` IN (191577,191580,191581,191582,191583,191584,191585,191586,191587,191588,191589,191590);
UPDATE `gameobject_template` SET `ScriptName`='go_shrine_of_the_birds' WHERE `entry` IN (185547,185553,185551);
UPDATE `gameobject_template` SET `ScriptName`='go_matrix_punchograph' WHERE `entry` IN (142345,142475,142476,142696);
UPDATE `gameobject_template` SET `ScriptName`='go_jotunheim_cage' WHERE `entry`=192135;
UPDATE `gameobject_template` SET `scriptname`='go_inconspicuous_landmark' WHERE `entry`=142189;
UPDATE `gameobject_template` SET `ScriptName`='go_soulwell' WHERE `entry` IN (181621,193169);
UPDATE `gameobject_template` SET `scriptname`='go_tadpole_cage' WHERE `entry`=187373;
UPDATE `gameobject_template` SET `ScriptName`='go_dragonflayer_cage' WHERE entry IN (186566,186567,186568,186569,186570,186571,186572,186573,186574,186575);
UPDATE `gameobject_template` SET `ScriptName`='go_black_cage' WHERE `entry`=195310;
UPDATE `gameobject_template` SET `ScriptName`='go_massive_seaforium_charge' WHERE `entry`=190752;
UPDATE `gameobject_template` SET `ScriptName`='go_harpoon_launcher' WHERE `entry` IN (192175,192176,192177);

/* GUARD */
UPDATE `creature_template` SET `ScriptName`='guard_generic' WHERE `entry` IN (68,1976,3218,3296,3502,4624,9460,11190,15184);
UPDATE `creature_template` SET `ScriptName`='guard_shattrath_aldor' WHERE `entry`=18549;
UPDATE `creature_template` SET `ScriptName`='guard_shattrath_scryer' WHERE `entry`=18568;

/* INNKEEPER */
UPDATE `creature_template` SET `ScriptName`='npc_innkeeper' WHERE `entry` IN
(32418,32411,29926,30308,31433,32413,30005,29963,31115,31557,29971,18649,15397,6806,6778,16542,17553,19046,16739,16553,11116,9501,
6740,2352,6739,1247,3934,6727,7714,15433,16458,295,5111,7733,7737,6928,6929,6734,8931,1464,6272,7731,17630,6930,6747,12196,6736,
6738,11103,6741,6746,5688,6735,6737,2388,9356,7736,11106,5814,7744,6790,16618,11118,6791,23995,24208,6807,14731,16256,15174,16826,
19531,16602,19470,19232,21088,18245,18906,18905,18251,18907,18908,27148,18914,27187,21746,19352,19319,18957,19571,19495,18913,21744,
23731,21110,23143,23937,25278,25245,26596,24149,24033,25036,24057,27950,27042,22922,27066,27027,27052,26709,24342,26985,27125,26680,
29532,28687,28686,27174,28791,29583,26375,28038,29904);

/* ITEM */
UPDATE `item_template` SET `ScriptName`='item_draenei_fishing_net' WHERE `entry`=23654;
UPDATE `item_template` SET `ScriptName`='item_gor_dreks_ointment' WHERE `entry`=30175;
UPDATE `item_template` SET `ScriptName`='item_nether_wraith_beacon' WHERE `entry`=31742;
UPDATE `item_template` SET `ScriptName`='item_tainted_core' WHERE `entry`=31088;
UPDATE `item_template` SET `ScriptName`='item_only_for_flight' WHERE `entry` IN (34475,34489,24538);
UPDATE `item_template` SET `ScriptName`='item_incendiary_explosives' WHERE (`entry`=35704);
UPDATE `item_template` SET `ScriptName`='item_mysterious_egg' WHERE `entry` IN(39878);
UPDATE `item_template` SET `ScriptName`='item_disgusting_jar' WHERE `entry` IN(44717);
UPDATE `item_template` SET `ScriptName`='item_petrov_cluster_bombs' WHERE `entry`=33098;
UPDATE `item_template` SET `ScriptName`='item_Trident_of_Nazjan' WHERE `entry`=35850;
UPDATE `item_template` SET `ScriptName`='item_captured_frog' WHERE `entry`=53510;

/* NPC (usually creatures to be found in more than one specific zone) */
UPDATE `creature_template` SET `ScriptName`='npc_air_force_bots' WHERE `entry` IN (2614,2615,21974,21993,21996,21997,21999,22001,22002,22003,22063,22065,22066,22068,22069,22070,22071,22078,22079,22080,22086,22087,22088,22090,22124,22125,22126);
UPDATE `creature_template` SET `ScriptName`='npc_lunaclaw_spirit' WHERE `entry`=12144;
UPDATE `creature_template` SET `ScriptName`='npc_chicken_cluck' WHERE `entry`=620;
UPDATE `creature_template` SET `ScriptName`='npc_dancing_flames' WHERE `entry`=25305;
UPDATE `creature_template` SET `ScriptName`='npc_garments_of_quests' WHERE `entry` IN (12429,12423,12427,12430,12428);
UPDATE `creature_template` SET `ScriptName`='npc_guardian' WHERE `entry`=5764;
UPDATE `creature_template` SET `ScriptName`='npc_mount_vendor' WHERE `entry` IN (384,1261,1460,2357,3362,3685,4730,4731,4885,7952,7955,16264,17584);
UPDATE `creature_template` SET `ScriptName`='npc_doctor' WHERE `entry` IN (12939,12920);
UPDATE `creature_template` SET `ScriptName`='npc_injured_patient' WHERE `entry` IN (12936,12937,12938,12923,12924,12925);
UPDATE `creature_template` SET `ScriptName`='npc_prof_alchemy' WHERE `entry` IN (17909,19052,22427);
UPDATE `creature_template` SET `ScriptName`='npc_prof_blacksmith' WHERE `entry` IN (5164,11145,11146,11176,11177,11178,11191,11192,11193);
UPDATE `creature_template` SET `ScriptName`='npc_engineering_tele_trinket' WHERE `entry` IN (14742,14743,21493,21494);
UPDATE `creature_template` SET `ScriptName`='npc_prof_leather' WHERE `entry` IN (7866,7867,7868,7869,7870,7871);
UPDATE `creature_template` SET `ScriptName`='npc_prof_tailor' WHERE `entry` IN (22208,22212,22213);
UPDATE `creature_template` SET `ScriptName`='npc_rogue_trainer' WHERE `entry` IN (918,4163,3328,4583,5165,5167,13283,16684);
UPDATE `creature_template` SET `ScriptName`='npc_sayge' WHERE `entry`=14822;
UPDATE `creature_template` SET `ScriptName`='npc_steam_tonk' WHERE `entry`=19405;
UPDATE `creature_template` SET `ScriptName`='npc_tonk_mine' WHERE `entry`=15368;
UPDATE `creature_template` SET `ScriptName`='npc_winter_reveler' WHERE `entry`=15760;
UPDATE `creature_template` SET `ScriptName`='npc_brewfest_reveler' WHERE `entry`=24484;
UPDATE `creature_template` SET `ScriptName`='npc_snake_trap_serpents' WHERE `entry` IN (19921,19833);
UPDATE `creature_template` SET `ScriptName`='npc_unworthy_initiate' WHERE `entry` IN (29519,29520,29565,29566,29567);
UPDATE `creature_template` SET `ScriptName`='npc_unworthy_initiate_anchor' WHERE `entry`=29521;
UPDATE `creature_template` SET `ScriptName`='npc_kingdom_of_dalaran_quests' WHERE `entry` IN (29169,23729,26673,27158,29158,29161,26471,29155,29159,29160,29162);
UPDATE `creature_template` SET `ScriptName`='npc_taxi' WHERE `entry` IN (17435,23413,18725,19401,19409,20235,25059,25236,20903,20162,29154,23415,27575,26443,26949,23816,23704,26602,17209);
UPDATE `creature_template` SET `ScriptName`='npc_death_knight_initiate' WHERE `entry`=28406;
UPDATE `creature_template` SET `ScriptName`='npc_salanar_the_horseman' WHERE `entry` IN (28653,28788);
UPDATE `creature_template` SET `ScriptName`='npc_dark_rider_of_acherus' WHERE `entry`=28654;
UPDATE `creature_template` SET `ScriptName`='npc_ros_dark_rider' WHERE `entry`=28768;
UPDATE `creature_template` SET `ScriptName`='npc_dkc1_gothik' WHERE `entry`=28658;
UPDATE `creature_template` SET `ScriptName`='npc_scarlet_ghoul' WHERE `entry`=28845;
UPDATE `creature_template` SET `ScriptName`='npc_a_special_surprise' WHERE `entry` IN (29032,29061,29065,29067,29068,29070,29074,29072,29073,29071);
UPDATE `creature_template` SET `ScriptName`='npc_koltira_deathweaver' WHERE `entry`=28912;
UPDATE `creature_template` SET `ScriptName`='mob_high_inquisitor_valroth' WHERE `entry`=29001;
UPDATE `creature_template` SET `ScriptName`='npc_demolisher_engineerer' WHERE `entry` IN (30400,30499);
UPDATE `creature_template` SET `ScriptName`='npc_valkyr_battle_maiden' WHERE `entry`=28534;
UPDATE `creature_template` SET `ScriptName`='npc_mirror_image' WHERE `entry`=31216;
UPDATE `creature_template` SET `ScriptName`='npc_training_dummy' WHERE `entry` IN (17578,24792,32543,32546,32542,32545,30527,31143,31144,31146,32541,32666,32667,16111,2674,2673,33229,33243,33272);
UPDATE `creature_template` SET `ScriptName`='npc_lightwell' WHERE `entry` IN (31883,31893,31894,31895,31896,31897);
UPDATE `creature_template` SET `ScriptName`='npc_ebon_gargoyle' WHERE `entry`=27829;
UPDATE `gameobject_template` SET `ScriptName`='go_inconspicuous_mine_car' WHERE `entry`=190767;
UPDATE `creature_template` SET `ScriptName`='npc_scarlet_miner_cart' WHERE `entry`=28817;
UPDATE `creature_template` SET `ScriptName`='npc_scarlet_miner' WHERE `entry`=28841;
UPDATE `creature_template` SET `ScriptName`='npc_crusade_persuaded' WHERE `entry` IN (28939,28940,28610);
UPDATE `creature_template` SET `ScriptName`='mob_scarlet_courier' WHERE `entry`=29076;
UPDATE `creature_template` SET `AIName`='ArcherAI', `ScriptName`='' WHERE `entry` IN (29102,29103);
UPDATE `creature_template` SET `AIName`='TurretAI', `ScriptName`='' WHERE `entry`=29104;
UPDATE `creature_template` SET `ScriptName`='npc_highlord_darion_mograine' WHERE `entry`=29173;
UPDATE `creature_template` SET `ScriptName`='npc_the_lich_king_tirion_dawn' WHERE `entry` IN (29183,29175);
UPDATE `creature_template` SET `ScriptName`='npc_shadowfiend' WHERE `entry`=19668;
UPDATE `creature_template` SET `ScriptName`='npc_wormhole' WHERE `entry`=35646;
UPDATE `creature_template` SET `ScriptName`='npc_pet_trainer' WHERE `entry` IN (10090,3698,17484,4320,3545,16712,3622,16675,3620,10086,2879,3306,543,2878,3688,10089,16271,10088,3624);
UPDATE `creature_template` SET `ScriptName`='npc_locksmith' WHERE `entry` IN (29665,29725,29728);
UPDATE `creature_template` SET `ScriptName`='npc_tabard_vendor' WHERE `entry`=28776;
UPDATE `creature_template` SET `ScriptName`='npc_experience'WHERE `entry` IN (35364,35365);

/*  */
/* ZONE */
/* */

/* ALTERAC MOUNTAINS */

/* ALTERAC VALLEY */

UPDATE `creature_template` SET `ScriptName`='boss_drekthar' WHERE `entry`=11946;
UPDATE `creature_template` SET `ScriptName`='boss_vanndar' WHERE `entry`=11948;
UPDATE `creature_template` SET `ScriptName`='boss_balinda' WHERE `entry`=11949;
UPDATE `creature_template` SET `ScriptName`='mob_water_elemental' WHERE `entry`=25040;
UPDATE `creature_template` SET `ScriptName`='boss_galvangar' WHERE `entry`=11947;
UPDATE `creature_template` SET `ScriptName`='mob_av_marshal_or_warmaster' WHERE `entry` IN (14762,14763,14764,14765,14772,14773,14776,14777);

/* ARATHI HIGHLANDS */
UPDATE `creature_template` SET `ScriptName`='npc_professor_phizzlethorpe' WHERE `entry`=2768;

/* ASHENVALE */
UPDATE `creature_template` SET `ScriptName`='npc_torek' WHERE `entry`=12858;
UPDATE `creature_template` SET `ScriptName`='npc_ruul_snowhoof' WHERE `entry`=12818;
UPDATE `gameobject_template` SET `ScriptName`='go_naga_brazier' WHERE `entry`=178247;
UPDATE `creature_template` SET `ScriptName`='npc_muglash' WHERE `entry`=12717;

/* AUCHINDOUN */

/* MANA TOMBS */
UPDATE `creature_template` SET `ScriptName`='boss_pandemonius' WHERE `entry`=18341;
UPDATE `creature_template` SET `ScriptName`='boss_nexusprince_shaffar' WHERE `entry`=18344;
UPDATE `creature_template` SET `ScriptName`='mob_ethereal_beacon' WHERE `entry`=18431;
UPDATE `creature_template` SET `ScriptName`='mob_ethereal_apprentice' WHERE `entry`=18430;

/* AUCHENAI CRYPTS */
UPDATE `creature_template` SET `ScriptName`='boss_exarch_maladaar' WHERE `entry`=18373;
UPDATE `creature_template` SET `ScriptName`='mob_avatar_of_martyred' WHERE `entry`=18478;
UPDATE `creature_template` SET `ScriptName`='mob_stolen_soul' WHERE `entry`=18441;
UPDATE `creature_template` SET `ScriptName`='boss_shirrak_the_dead_watcher' WHERE `entry`=18371;
UPDATE `creature_template` SET `ScriptName`='mob_focus_fire' WHERE `entry`=18374;

/* SETHEKK HALLS */
UPDATE `instance_template` SET `script`='instance_sethekk_halls' WHERE `map`=556;
UPDATE `creature_template` SET `ScriptName`='mob_syth_fire' WHERE `entry`=19203;
UPDATE `creature_template` SET `ScriptName`='mob_syth_arcane' WHERE `entry`=19205;
UPDATE `creature_template` SET `ScriptName`='mob_syth_frost' WHERE `entry`=19204;
UPDATE `creature_template` SET `ScriptName`='mob_syth_shadow' WHERE `entry`=19206;
UPDATE `creature_template` SET `ScriptName`='boss_talon_king_ikiss' WHERE `entry`=18473;
UPDATE `creature_template` SET `ScriptName`='boss_darkweaver_syth' WHERE `entry`=18472;

/* SHADOW LABYRINTH */
UPDATE `instance_template` SET `script`='instance_shadow_labyrinth' WHERE `map`=555;
UPDATE `creature_template` SET `ScriptName`='boss_murmur' WHERE `entry`=18708;
UPDATE `creature_template` SET `ScriptName`='boss_grandmaster_vorpil' WHERE `entry`=18732;
UPDATE `creature_template` SET `ScriptName`='boss_blackheart_the_inciter' WHERE `entry`=18667;
UPDATE `creature_template` SET `ScriptName`='boss_ambassador_hellmaw' WHERE `entry`=18731;
UPDATE `creature_template` SET `ScriptName`='mob_voidtraveler' WHERE `entry`=19226;

/* AZJOL-NERUB */
UPDATE `instance_template` SET `script`='instance_azjol_nerub' WHERE `map`=601;
UPDATE `creature_template` SET `ScriptName`='npc_watcher_narjil' WHERE `entry`=28729;
UPDATE `creature_template` SET `ScriptName`='npc_watcher_silthik' WHERE `entry`=28731;
UPDATE `creature_template` SET `ScriptName`='npc_anub_ar_warrior' WHERE `entry`=28732;
UPDATE `creature_template` SET `ScriptName`='npc_watcher_gashra' WHERE `entry`=28730;
UPDATE `creature_template` SET `ScriptName`='boss_krik_thir' WHERE `entry`=28684;
UPDATE `creature_template` SET `ScriptName`='npc_skittering_infector' WHERE `entry`=28736;
UPDATE `creature_template` SET `ScriptName`='npc_anub_ar_skirmisher' WHERE `entry`=28734;
UPDATE `creature_template` SET `ScriptName`='npc_anub_ar_shadowcaster' WHERE `entry`=28733;
UPDATE `creature_template` SET `ScriptName`='boss_hadronox' WHERE `entry`=28921;
UPDATE `creature_template` SET `ScriptName`='boss_anub_arak' WHERE `entry`=29120;

/* AHN'KAHET: THE OLD KINGDOM */
UPDATE `instance_template` SET `script`='instance_ahnkahet' WHERE `map`=619;
UPDATE `creature_template` SET `ScriptName`='boss_elder_nadox' WHERE `entry`=29309;
UPDATE `creature_template` SET `ScriptName`='mob_ahnkahar_nerubian' WHERE `entry` IN (30176,30178);
UPDATE `creature_template` SET `ScriptName`='boss_taldaram' WHERE `entry`=29308;
UPDATE `creature_template` SET `ScriptName`='mob_taldaram_flamesphere' WHERE `entry` IN (30106,31686,31687);
UPDATE `gameobject_template` SET `ScriptName`='prince_taldaram_sphere' WHERE `entry` IN (193093,193094);
UPDATE `creature_template` SET `ScriptName`='boss_volazj' WHERE `entry`=29311;
UPDATE `creature_template` SET `ScriptName`='boss_amanitar' WHERE `entry`=30258;
UPDATE `creature_template` SET `ScriptName`='mob_amanitar_mushrooms' WHERE `entry` IN (30435,30391);
UPDATE `creature_template` SET `ScriptName`='mob_nadox_eggs' WHERE `entry` IN (30172,30173);
UPDATE `creature_template` SET `ScriptName`='boss_jedoga_shadowseeker' WHERE `entry`=29310;
UPDATE `creature_template` SET `ScriptName`='mob_jedoga_initiand' WHERE `entry`=30114;
UPDATE `creature_template` SET `ScriptName`='npc_jedogas_aufseher_trigger' WHERE `entry`=30181;

/* AZSHARA */
UPDATE `creature_template` SET `ScriptName`='mobs_spitelashes' WHERE `entry` IN (6190,6193,6194,6195,6196,7885,7886,12204,12205);
UPDATE `creature_template` SET `ScriptName`='npc_loramus_thalipedes' WHERE `entry`=7783;
UPDATE `creature_template` SET `ScriptName`='mob_rizzle_sprysprocket' WHERE `entry`=23002;
UPDATE `creature_template` SET `ScriptName`='mob_depth_charge' WHERE `entry`=23025;

/* AZUREMYST ISLE */
UPDATE `creature_template` SET `ScriptName`='npc_engineer_spark_overgrind' WHERE `entry`=17243;
UPDATE `creature_template` SET `ScriptName`='npc_injured_draenei' WHERE `entry`=16971;
UPDATE `creature_template` SET `ScriptName`='npc_magwin' WHERE `entry`=17312;
UPDATE `creature_template` SET `ScriptName`='npc_geezle' WHERE `entry`=17318;
UPDATE `creature_template` SET `ScriptName`='npc_draenei_survivor' WHERE `entry`=16483;
UPDATE `creature_template` SET `ScriptName`='npc_death_ravager' WHERE `entry`=17556;
UPDATE `creature_template` SET `ScriptName`='npc_stillpine_capitive' where `entry`=17375;
UPDATE `gameobject_template` SET `ScriptName`='go_ravager_cage' WHERE `entry`=181849;
UPDATE `gameobject_template` SET `ScriptName`='go_bristlelimb_cage' WHERE `entry`=181714;

/* BADLANDS */

/* BARRENS */
UPDATE `creature_template` SET `ScriptName`='npc_beaten_corpse' WHERE `entry`=10668;
UPDATE `creature_template` SET `ScriptName`='npc_gilthares' WHERE `entry`=3465;
UPDATE `creature_template` SET `ScriptName`='npc_sputtervalve' WHERE `entry`=3442;
UPDATE `creature_template` SET `ScriptName`='npc_taskmaster_fizzule' WHERE `entry`=7233;
UPDATE `creature_template` SET `ScriptName`='npc_twiggy_flathead' WHERE `entry`=6248;
UPDATE `creature_template` SET `ScriptName`='npc_wizzlecrank_shredder' WHERE `entry`=3439;

/* BLACK TEMPLE */
UPDATE `gameobject_template` SET `ScriptName`='go_najentus_spine' WHERE `entry`=185584;
UPDATE `gameobject_template` SET `ScriptName`='gameobject_cage_trap' WHERE `entry`=185916; -- Cage Trap GO in Illidan Encounter
UPDATE `instance_template` SET `script`='instance_black_temple' WHERE `map`=564;
UPDATE `creature_template` SET `ScriptName`='npc_akama_shade' WHERE `entry`=22990; -- Akama at Shade of Akama
UPDATE `creature_template` SET `ScriptName`='npc_akama_illidan' WHERE `entry`=23089; -- Akama at Illidan
UPDATE `creature_template` SET `ScriptName`='mob_illidari_council' WHERE `entry`=23426; -- Illidari Council controller mob
UPDATE `creature_template` SET `ScriptName`='mob_blood_elf_council_voice_trigger' WHERE `entry`=23499; -- Voice Trigger Mob (Controls Aggro + Enrage yells)
UPDATE `creature_template` SET `ScriptName`='boss_veras_darkshadow' WHERE `entry`=22952; -- Rogue of Illidari Council
UPDATE `creature_template` SET `ScriptName`='boss_teron_gorefiend' WHERE `entry`=22871; -- Teron Gorefiend
UPDATE `creature_template` SET `ScriptName`='boss_supremus' WHERE `entry`=22898; -- Supremus
UPDATE `creature_template` SET `ScriptName`='boss_shade_of_akama' WHERE `entry`=22841; -- Shade of Akama
UPDATE `creature_template` SET `ScriptName`='boss_reliquary_of_souls' WHERE `entry`=22856; -- Reliquary Controller Mob
UPDATE `creature_template` SET `ScriptName`='boss_essence_of_suffering' WHERE `entry`=23418; -- Essence Of Suffering
UPDATE `creature_template` SET `ScriptName`='boss_essence_of_desire' WHERE `entry`=23419; -- Essence of Desire
UPDATE `creature_template` SET `ScriptName`='boss_essence_of_anger' WHERE `entry`=23420; -- Essence of Anger
UPDATE `creature_template` SET `ScriptName`='boss_najentus' WHERE `entry`=22887; -- High Warlord Naj'entus
UPDATE `creature_template` SET `ScriptName`='boss_gurtogg_bloodboil' WHERE `entry`=22948; -- Gurtogg Bloodboil
UPDATE `creature_template` SET `ScriptName`='boss_mother_shahraz' WHERE `entry`=22947; -- Mother Shahraz
UPDATE `creature_template` SET `ScriptName`='boss_lady_malande' WHERE `entry`=22951; -- Priest <3 at Illidari Council
UPDATE `creature_template` SET `ScriptName`='boss_illidan_stormrage' WHERE `entry`=22917; -- Illidan The Betrayer!
UPDATE `creature_template` SET `ScriptName`='boss_high_nethermancer_zerevor' WHERE `entry`=22950; -- Mage at Illidari Council
UPDATE `creature_template` SET `ScriptName`='boss_gathios_the_shatterer' WHERE `entry`=22949; -- Paladin at Illidari Council
UPDATE `creature_template` SET `ScriptName`='boss_maiev_shadowsong' WHERE `entry`=23197; -- Maiev Shadowsong
UPDATE `creature_template` SET `ScriptName`='mob_blaze' WHERE `entry`=23259; -- Blaze mob in Illidan Phase 2
UPDATE `creature_template` SET `ScriptName`='mob_flame_of_azzinoth' WHERE `entry`=22997; -- Flame of Azzinoth (Illidan Phase 2)
UPDATE `creature_template` SET `ScriptName`='mob_blade_of_azzinoth' WHERE `entry`=22996; -- Blade of Azzinoth (Illidan Phase 2)
UPDATE `creature_template` SET `ScriptName`='mob_demon_fire' WHERE `entry`=23069; -- Demon Fire in Illidan Phase 2
UPDATE `creature_template` SET `ScriptName`='mob_flame_crash' WHERE `entry`=23336; -- Flame Crash in Illidan Normal Form
UPDATE `creature_template` SET `ScriptName`='mob_cage_trap_trigger' WHERE `entry`=23304; -- Cage Trap mob in Illidan Phase 3/4 Normal
UPDATE `creature_template` SET `ScriptName`='mob_shadow_demon' WHERE `entry`=23375; -- Shadow Demon in Illidan Demon Form
UPDATE `creature_template` SET `ScriptName`='npc_volcano' WHERE `entry`=23085; -- Supremus Volcano
UPDATE `creature_template` SET `ScriptName`='molten_flame' WHERE `entry`=23095; -- Molten Flame in SUpremus
UPDATE `creature_template` SET `ScriptName`='mob_ashtongue_channeler' WHERE `entry`=23421; -- Ashtongue CHanneler in Shade of AKama
UPDATE `creature_template` SET `ScriptName`='mob_ashtongue_sorcerer' WHERE `entry`=23215; -- Ashtongue Sorcerer in Shade of Akama
UPDATE `creature_template` SET `ScriptName`='npc_enslaved_soul' WHERE `entry`=23469; -- Enslaved Soul in Reliquary Event
UPDATE `creature_template` SET `ScriptName`='mob_doom_blossom' WHERE `entry`=23123; -- Doom Blossoms in Teron Gorefiend's encounter
UPDATE `creature_template` SET `ScriptName`='npc_spirit_of_olum' WHERE `entry`=23411;
UPDATE `creature_template` SET `ScriptName`='mob_shadowy_construct' WHERE `entry`=23111;
UPDATE `creature_template` SET `ScriptName`='mob_parasitic_shadowfiend' WHERE `entry`=23498;

/* BLACKFATHOM DEPTHS */
UPDATE `instance_template` SET `script`='instance_blackfathom_deeps' WHERE `map`=48;
UPDATE `gameobject_template` SET `ScriptName`='go_blackfathom_fire' WHERE `entry` IN (21118,21119,21120,21121);
UPDATE `gameobject_template` SET `ScriptName`='go_blackfathom_altar' WHERE `entry` IN (103015,103016);
UPDATE `creature_template` SET `ScriptName`='boss_gelihast' WHERE `entry`=6243;
UPDATE `creature_template` SET `ScriptName`='boss_kelris' WHERE `entry`=4832;
UPDATE `creature_template` SET `ScriptName`='boss_aku_mai' WHERE `entry`=4829;
UPDATE `creature_template` SET `ScriptName`='npc_blackfathom_deeps_event' WHERE `entry` IN (4823,4825,4977,4978);
UPDATE `creature_template` SET `ScriptName`='npc_morridune' WHERE `entry`=6729;

/* BLACKROCK DEPTHS */
UPDATE `instance_template` SET `script`='instance_blackrock_depths' WHERE `map`=230;
UPDATE `creature_template` SET `ScriptName`='boss_emperor_dagran_thaurissan' WHERE `entry`=9019;
UPDATE `creature_template` SET `ScriptName`='boss_moira_bronzebeard' WHERE `entry`=8929;
UPDATE `creature_template` SET `ScriptName`='boss_ambassador_flamelash' WHERE `entry`=9156;
UPDATE `creature_template` SET `ScriptName`='boss_anubshiah' WHERE `entry`=9031;
UPDATE `creature_template` SET `ScriptName`='boss_doomrel' WHERE `entry`=9039;
UPDATE `creature_template` SET `ScriptName`='boss_gloomrel' WHERE `entry`=9037;
UPDATE `creature_template` SET `ScriptName`='boss_general_angerforge' WHERE `entry`=9033;
UPDATE `creature_template` SET `ScriptName`='boss_gorosh_the_dervish' WHERE `entry`=9027;
UPDATE `creature_template` SET `ScriptName`='boss_grizzle' WHERE `entry`=9028;
UPDATE `creature_template` SET `ScriptName`='boss_high_interrogator_gerstahn' WHERE `entry`=9018;
UPDATE `creature_template` SET `ScriptName`='boss_magmus' WHERE `entry`=9938;
UPDATE `creature_template` SET `ScriptName`='npc_lokhtos_darkbargainer' WHERE `entry`=12944;
UPDATE `creature_template` SET `ScriptName`='npc_kharan_mighthammer' WHERE `entry`=9021;
UPDATE `creature_template` SET `ScriptName`='npc_grimstone' WHERE `entry`=10096;
UPDATE `creature_template` SET `ScriptName`='npc_rocknot' WHERE `entry`=9503;
UPDATE `creature_template` SET `ScriptName`='mob_phalanx' WHERE `entry`=9502;
UPDATE `gameobject_template` SET `ScriptName`='go_shadowforge_brazier' WHERE `entry` IN (174744,174745);

/* BLACKROCK SPIRE */
UPDATE `instance_template` SET `script`='instance_blackrock_spire' WHERE `map`=229;
/* BLACKROCK SPIRE Lower bosses */
UPDATE `creature_template` SET `ScriptName`='boss_highlord_omokk' WHERE `entry`=9196;
UPDATE `creature_template` SET `ScriptName`='boss_shadow_hunter_voshgajin' WHERE `entry`=9236;
UPDATE `creature_template` SET `ScriptName`='boss_warmaster_voone' WHERE `entry`=9237;
UPDATE `creature_template` SET `ScriptName`='boss_mother_smolderweb' WHERE `entry`=10596;
UPDATE `creature_template` SET `ScriptName`='quartermaster_zigris' WHERE `entry`=9736;
UPDATE `creature_template` SET `ScriptName`='boss_halycon' WHERE `entry`=10220;
UPDATE `creature_template` SET `ScriptName`='boss_overlord_wyrmthalak' WHERE `entry`=9568;
/* BLACKROCK SPIRE Upper bosses */
UPDATE `creature_template` SET `ScriptName`='boss_the_beast' WHERE `entry`=10430;
UPDATE `creature_template` SET `ScriptName`='boss_drakkisath' WHERE `entry`=10363;
UPDATE `creature_template` SET `ScriptName`='boss_gyth' WHERE `entry`=10339;
UPDATE `creature_template` SET `ScriptName`='boss_rend_blackhand' WHERE `entry`=10429;
UPDATE `creature_template` SET `ScriptName`='boss_pyroguard_emberseer' WHERE `entry`=9816;

/* BLACKWING LAIR */
UPDATE `instance_template` SET `script`='instance_blackwing_lair' WHERE `map`=469;
UPDATE `creature_template` SET `ScriptName`='boss_razorgore' WHERE `entry`=12435;
UPDATE `creature_template` SET `ScriptName`='boss_vaelastrasz' WHERE `entry`=13020;
UPDATE `creature_template` SET `ScriptName`='boss_broodlord' WHERE `entry`=12017;
UPDATE `creature_template` SET `ScriptName`='boss_firemaw' WHERE `entry`=11983;
UPDATE `creature_template` SET `ScriptName`='boss_ebonroc' WHERE `entry`=14601;
UPDATE `creature_template` SET `ScriptName`='boss_flamegor' WHERE `entry`=11981;
UPDATE `creature_template` SET `ScriptName`='boss_chromaggus' WHERE `entry`=14020;
UPDATE `creature_template` SET `ScriptName`='boss_victor_nefarius' WHERE `entry`=10162;
UPDATE `creature_template` SET `ScriptName`='boss_nefarian' WHERE `entry`=11583;

/* BLADE'S EDGE MOUNTAINS */
UPDATE `creature_template` SET `ScriptName`='mobs_bladespire_ogre' WHERE `entry` IN (19998,20334,21296,21975);
UPDATE `creature_template` SET `ScriptName`='mobs_nether_drake' WHERE `entry` IN (20021,21817,21820,21821,21823);
UPDATE `creature_template` SET `ScriptName`='npc_daranelle' WHERE `entry`=21469;
UPDATE `creature_template` SET `ScriptName`='npc_overseer_nuaar' WHERE `entry`=21981;
UPDATE `creature_template` SET `ScriptName`='npc_saikkal_the_elder' WHERE `entry`=22932;
UPDATE `gameobject_template` SET `ScriptName`='go_fel_crystalforge' WHERE `entry`=185919;
UPDATE `gameobject_template` SET `ScriptName`='go_bashir_crystalforge' WHERE `entry`=185921;
UPDATE `creature_template` SET `ScriptName`='npc_ogre_brute' WHERE `entry`=19995;
UPDATE `creature_template` SET `ScriptName`='npc_bloodmaul_brutebane' WHERE `entry`=21241;

/* BLASTED LANDS */
UPDATE `creature_template` SET `ScriptName`='npc_deathly_usher' WHERE `entry`=8816;
UPDATE `creature_template` SET `ScriptName`='npc_fallen_hero_of_horde' WHERE `entry`=7572;

/* BLOODMYST ISLE */
UPDATE `creature_template` SET `ScriptName`='mob_webbed_creature' WHERE `entry`=17680;
UPDATE `creature_template` SET `ScriptName`='npc_captured_sunhawk_agent' WHERE `entry`=17824;
UPDATE `creature_template` SET `ScriptName`='npc_princess_stillpine' WHERE `entry`=17682;
UPDATE `gameobject_template` SET `ScriptName`='go_princess_stillpines_cage' WHERE `entry`=181928;

/* BOREAN TUNDRA */
UPDATE `creature_template` SET `ScriptName`='npc_fizzcrank_fullthrottle' WHERE `entry`=25590;
UPDATE `creature_template` SET `ScriptName`='npc_surristrasz' WHERE `entry`=24795;
UPDATE `creature_template` SET `ScriptName`='npc_tiare' WHERE `entry`=30051;
UPDATE `creature_template` SET `ScriptName`='npc_sinkhole_kill_credit' WHERE `entry` IN (26248,26249);
UPDATE `creature_template` SET `ScriptName`='npc_khunok_the_behemoth' WHERE `entry`=25862;
UPDATE `creature_template` SET `ScriptName`='npc_keristrasza' WHERE `entry`=26206;
UPDATE `creature_template` SET `ScriptName`='npc_iruk' WHERE `entry`=26219;
UPDATE `creature_template` SET `ScriptName`='npc_corastrasza' WHERE `entry`=32548;
UPDATE `creature_template` SET `ScriptName`='mob_nerubar_victim' WHERE `entry`=25284;
UPDATE `creature_template` SET `ScriptName`='npc_scourge_prisoner' WHERE `entry`=25610;
UPDATE `gameobject_template` SET `ScriptName`='go_scourge_cage' WHERE `entry` IN (187854,187855,187856,187857,187858,187859,187860,187862,187863,187864,187865,187866,187867,187868,187870,187871,187872,187873,187874,187861,190803);
UPDATE `gameobject_template` SET `ScriptName`='go_arcane_prison' WHERE `entry`=187561;
UPDATE `creature_template` SET `ScriptName`='npc_loklira_crone' WHERE `entry`=29975;
UPDATE `creature_template` SET `ScriptName`='npc_victorious_challenger' WHERE `entry`=30012;
UPDATE `creature_template` SET `ScriptName`='npc_mcgoyver' WHERE `entry`=24040;
UPDATE `creature_template` SET `ScriptName`='npc_jenny' WHERE `entry`=25969;
UPDATE `creature_template` SET `ScriptName`='npc_lurgglbr' WHERE `entry`=25208;
UPDATE `creature_template` SET `ScriptName`='npc_nexus_drake_hatchling' WHERE `entry`=26127;
UPDATE `creature_template` SET `ScriptName`='npc_nesingwary_trapper' WHERE `entry`=25835;
UPDATE `item_template` SET `ScriptName`='item_pile_fake_furs' WHERE `entry`=35127;
UPDATE `creature_template` SET `ScriptName`='npc_general_arlos' WHERE `entry`=25250;
UPDATE `creature_template` SET `ScriptName`='npc_leryssa' WHERE `entry`=25251;
UPDATE `creature_template` SET `ScriptName`='npc_thassarian' WHERE `entry`=26170;
UPDATE `creature_template` SET `ScriptName`='npc_image_lich_king' WHERE `entry`=26203;
UPDATE `creature_template` SET `ScriptName`='npc_counselor_talbot' WHERE `entry`=25301;
UPDATE `creature_template` SET `ScriptName`='npc_beryl_sorcerer' WHERE `entry`=25316;
UPDATE `creature_template` SET `ScriptName`='npc_imprisoned_beryl_sorcerer' WHERE `entry`=25478;
UPDATE `creature_template` SET `ScriptName`='npc_mootoo_the_younger' WHERE `entry`=25504;
UPDATE `creature_template` SET `ScriptName`='npc_bonker_togglevolt' WHERE `entry`=25589;
UPDATE `creature_template` SET `ScriptName`='npc_fezzix_geartwist' WHERE `entry`=25849;
UPDATE `creature_template` SET `scriptname`='npc_trapped_mammoth_calf' WHERE `entry`=25850;
UPDATE `item_template` SET `scriptname`='item_dehta_trap_smasher' WHERE `entry`=35228;
UPDATE `creature_template` SET `ScriptName`='npc_magmoth_crusher' WHERE `entry`=25434;
UPDATE `creature_template` SET `ScriptName`='npc_valiance_keep_cannoneer' WHERE `entry`=25306;
UPDATE `creature_template` SET `ScriptName`='npc_warmage_coldarra' WHERE `entry` IN (27173,27904,27906);
UPDATE `creature_template` SET `ScriptName`='npc_valiance_keep_cannoneer' WHERE `entry`=25306;
UPDATE `creature_template` SET `ScriptName`= 'npc_seaforium_depth_charge' WHERE `entry`=25401;
UPDATE `creature_template` SET `ScriptName`='npc_hidden_cultist' WHERE `entry` IN (25828,25248,25827);

/* BURNING STEPPES */
UPDATE `creature_template` SET `ScriptName`='npc_ragged_john' WHERE `entry`=9563;

/* CAVERNS OF TIME - CULLING OF STRATHOLME */
UPDATE `instance_template` SET `script`='instance_culling_of_stratholme' WHERE `map`=595;
UPDATE `creature_template` SET `Scriptname`='npc_arthas' WHERE `entry`=26499;
UPDATE `creature_template` SET `Scriptname`='boss_salramm' WHERE `entry`=26530;
UPDATE `creature_template` SET `Scriptname`='boss_meathook' WHERE `entry`=26529;
UPDATE `creature_template` SET `Scriptname`='boss_epoch' WHERE `entry`=26532;
UPDATE `creature_template` SET `Scriptname`='boss_mal_ganis' WHERE `entry`=26533;
UPDATE `creature_template` SET `Scriptname`='boss_infinite_corruptor' WHERE `entry`=32273;
UPDATE `creature_template` SET `ScriptName`='npc_create_helper_cot' WHERE `entry`=27827;

/* CRYSTALSONG FOREST */
UPDATE `creature_template` SET `ScriptName`='npc_warmage_violetstand' WHERE `entry` IN (32369,32371,32372);

/* MT. HYJAL */
UPDATE `instance_template` SET `script`='instance_hyjal' WHERE `map`=534;
UPDATE `creature_template` SET `ScriptName`='npc_tyrande_whisperwind' WHERE `entry`=17948;
UPDATE `creature_template` SET `ScriptName`='npc_thrall' WHERE `entry`=17852;
UPDATE `creature_template` SET `ScriptName`='npc_jaina_proudmoore' WHERE `entry`=17772;
UPDATE `creature_template` SET `ScriptName`='boss_archimonde' WHERE `entry`=17968;
UPDATE `creature_template` SET `ScriptName`='mob_doomfire' WHERE `entry`=18095;
UPDATE `creature_template` SET `ScriptName`='mob_doomfire_targetting' WHERE `entry`=18104;
UPDATE `creature_template` SET `ScriptName`='mob_ancient_wisp' WHERE `entry`=17946;
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

/* OLD HILLSBRAD */
UPDATE `instance_template` SET `script`='instance_old_hillsbrad' WHERE `map`=560;
UPDATE `creature_template` SET `ScriptName`='boss_lieutenant_drake' WHERE `entry`=17848;
UPDATE `creature_template` SET `ScriptName`='boss_epoch_hunter' WHERE `entry`=18096;
UPDATE `creature_template` SET `ScriptName`='boss_captain_skarloc' WHERE `entry`=17862;
UPDATE `creature_template` SET `ScriptName`='npc_erozion' WHERE `entry`=18723;
UPDATE `creature_template` SET `ScriptName`='npc_taretha' WHERE `entry`=18887;
UPDATE `creature_template` SET `ScriptName`='npc_thrall_old_hillsbrad' WHERE `entry`=17876;
UPDATE `gameobject_template` SET `ScriptName`='go_barrel_old_hillsbrad' WHERE `entry`=182589;

/* THE DARK PORTAL */
UPDATE `instance_template` SET `script`='instance_dark_portal' WHERE `map`=269;
UPDATE `creature_template` SET `ScriptName`='boss_chrono_lord_deja' WHERE `entry`=17879;
UPDATE `creature_template` SET `ScriptName`='boss_aeonus' WHERE `entry`=17881;
UPDATE `creature_template` SET `ScriptName`='boss_temporus' WHERE `entry`=17880;
UPDATE `creature_template` SET `ScriptName`='npc_medivh_bm' WHERE `entry`=15608;
UPDATE `creature_template` SET `ScriptName`='npc_time_rift' WHERE `entry`=17838;
UPDATE `creature_template` SET `ScriptName`='npc_saat' WHERE `entry`=20201;

/* COILFANG RESERVOIR */

/* THE SLAVE PENS */

/* THE UNDERBOG */
UPDATE `creature_template` SET `ScriptName`='mob_underbog_mushroom' WHERE `entry`=17990;
UPDATE `creature_template` SET `ScriptName`='boss_hungarfen' WHERE `entry`=17770;
UPDATE `creature_template` SET `ScriptName`='boss_the_black_stalker' WHERE `entry`=17882;

/* THE STEAMVAULT */
UPDATE `instance_template` SET `script`='instance_steam_vault' WHERE `map`=545;
UPDATE `creature_template` SET `ScriptName`='boss_hydromancer_thespia' WHERE `entry`=17797;
UPDATE `creature_template` SET `ScriptName`='boss_mekgineer_steamrigger' WHERE `entry`=17796;
UPDATE `creature_template` SET `ScriptName`='boss_warlord_kalithresh' WHERE `entry`=17798;
UPDATE `creature_template` SET `ScriptName`='mob_coilfang_waterelemental' WHERE `entry`=17917;
UPDATE `creature_template` SET `ScriptName`='mob_naga_distiller' WHERE `entry`=17954;
UPDATE `creature_template` SET `ScriptName`='mob_steamrigger_mechanic' WHERE `entry`=17951;

/* SERPENTSHRINE CAVERN */
UPDATE `instance_template` SET `script`='instance_serpent_shrine' WHERE `map`=548;
UPDATE `creature_template` SET `ScriptName`='boss_hydross_the_unstable' WHERE `entry`=21216;
UPDATE `gameobject_template` SET `ScriptName`='go_bridge_console' WHERE `entry`=184568;
INSERT IGNORE INTO `areatrigger_scripts` VALUES (4591,'at_coilfang_waterfall');

/* Leotheras the Blind event */
UPDATE `creature_template` SET `ScriptName`='boss_leotheras_the_blind' WHERE `entry`=21215;
UPDATE `creature_template` SET `ScriptName`='boss_leotheras_the_blind_demonform' WHERE `entry`=21875;
UPDATE `creature_template` SET `ScriptName`='mob_greyheart_spellbinder' WHERE `entry`=21806;
UPDATE `creature_template` SET `ScriptName`='mob_inner_demon' WHERE `entry`=21857;
/* Fathom-lord Karathress event */
UPDATE `creature_template` SET `ScriptName`='boss_fathomlord_karathress' WHERE `entry`=21214;
UPDATE `creature_template` SET `ScriptName`='boss_fathomguard_sharkkis' WHERE `entry`=21966;
UPDATE `creature_template` SET `ScriptName`='boss_fathomguard_tidalvess' WHERE `entry`=21965;
UPDATE `creature_template` SET `ScriptName`='boss_fathomguard_caribdis' WHERE `entry`=21964;
/* Morogrim Tidewalker event */
UPDATE `creature_template` SET `ScriptName`='boss_morogrim_tidewalker' WHERE `entry`=21213;
UPDATE `creature_template` SET `ScriptName`='mob_water_globule' WHERE `entry`=21913;
/* The Lurker Below */
UPDATE `creature_template` SET `ScriptName`='boss_the_lurker_below' WHERE `entry`=21217;
UPDATE `creature_template` SET `ScriptName`='mob_coilfang_ambusher' WHERE `entry`=21865;
UPDATE `creature_template` SET `ScriptName`='mob_coilfang_guardian' WHERE `entry`=21873;
UPDATE `gameobject_template` SET `ScriptName`='go_strange_pool' WHERE `entry`=184956;
/* Lady Vashj event */
UPDATE `creature_template` SET `ScriptName`='boss_lady_vashj' WHERE `entry`=21212;
UPDATE `creature_template` SET `ScriptName`='mob_enchanted_elemental' WHERE `entry`=21958;
UPDATE `creature_template` SET `ScriptName`='mob_tainted_elemental' WHERE `entry`=22009;
UPDATE `creature_template` SET `ScriptName`='mob_coilfang_elite' WHERE `entry`=22055;
UPDATE `creature_template` SET `ScriptName`='mob_coilfang_strider' WHERE `entry`=22056;
UPDATE `creature_template` SET `ScriptName`='mob_toxic_sporebat' WHERE `entry`=22140;
UPDATE `creature_template` SET `ScriptName`='mob_shield_generator_channel' WHERE `entry`=19870;

/* CRYSTALSONG FOREST */

/* DALARAN */
UPDATE `creature_template` SET `ScriptName`='npc_mageguard_dalaran' WHERE `entry` IN (29254,29255);
UPDATE `creature_template` SET `ScriptName`='npc_hira_snowdawn' WHERE `entry`=31238;

/* DARKSHORE */
UPDATE `creature_template` SET `ScriptName`='npc_kerlonian' WHERE `entry`=11218;
UPDATE `creature_template` SET `ScriptName`='npc_threshwackonator' WHERE `entry`=6669;
UPDATE `creature_template` SET `ScriptName`='npc_prospector_remtravel' WHERE `entry`=2917;

/* DEADMINES */
UPDATE `instance_template` SET `script`='instance_deadmines' WHERE `map`=36;
UPDATE `item_template` SET `ScriptName`='item_defias_gunpowder' WHERE `entry`=5397;
UPDATE `gameobject_template` SET `ScriptName`='go_defias_cannon' WHERE `entry`=16398;
UPDATE `gameobject_template` SET `ScriptName`='go_door_lever_dm' WHERE `entry`=101833;
UPDATE `gameobject_template` SET `ScriptName`='go_main_chambers_access_panel' WHERE `entry` IN (184125,184126);

/* DRAGONBLIGHT */
UPDATE `creature_template` SET `ScriptName`='npc_alexstrasza_wr_gate' WHERE `entry`=31333;
UPDATE `creature_template` SET `ScriptName`='npc_inquisitor_hallard' WHERE `entry`=27316;

/* DEADWIND PASS */

/* DESOLACE */
UPDATE `creature_template` SET `ScriptName`='npc_aged_dying_ancient_kodo' WHERE `entry` IN (4700,4701,4702,11627);
UPDATE `gameobject_template` SET `ScriptName`='go_iruxos' WHERE `entry`=176581;
UPDATE `creature_template` SET `ScriptName`='npc_dalinda' WHERE `entry`=5644;

/* DIRE MAUL */

/* DUN MOROGH */

/* DUROTAR */
UPDATE `creature_template` SET `ScriptName`='npc_lazy_peon' WHERE `entry`=10556;
UPDATE `creature_template` SET `ScriptName`= 'npc_tiger_matriarch_credit' WHERE `entry`=40301;
UPDATE `creature_template` SET `ScriptName`= 'npc_tiger_matriarch' WHERE `entry`=40312;
UPDATE `creature_template` SET `ScriptName`= 'npc_troll_volunteer' WHERE `entry` IN (40260,40264);

/* DUSKWOOD */
DELETE FROM `areatrigger_scripts` WHERE `entry`=4017;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES (4017,'at_twilight_grove');
UPDATE `creature_template` SET `ScriptName`='boss_twilight_corrupter' WHERE `entry`=15625;

/* DUSTWALLOW MARSH */
UPDATE `creature_template` SET `ScriptName`='mobs_risen_husk_spirit' WHERE `entry` IN (23554,23555);
UPDATE `creature_template` SET `ScriptName`='npc_deserter_agitator' WHERE `entry`=23602;
UPDATE `creature_template` SET `ScriptName`='npc_lady_jaina_proudmoore' WHERE `entry`=4968;
UPDATE `creature_template` SET `ScriptName`='npc_nat_pagle' WHERE `entry`=12919;
UPDATE `creature_template` SET `ScriptName`='npc_private_hendel' WHERE `entry`=4966;
UPDATE `creature_template` SET `ScriptName`='npc_zelfrax' WHERE `entry`=23864;
UPDATE `creature_template` SET `ScriptName`='npc_stinky' WHERE `entry`=4880;
UPDATE `creature_template` SET `ScriptName`='npc_theramore_guard' WHERE `entry`=4979;

/* EASTERN PLAGUELANDS */
UPDATE `creature_template` SET `ScriptName`='mobs_ghoul_flayer' WHERE `entry` IN (8530,8531,8532);
UPDATE `creature_template` SET `ScriptName`='npc_augustus_the_touched' WHERE `entry`=12384;
UPDATE `creature_template` SET `ScriptName`='npc_darrowshire_spirit' WHERE `entry`=11064;
UPDATE `creature_template` SET `ScriptName`='npc_tirion_fordring' WHERE `entry`=1855;

/* ELWYNN FOREST */

/* EVERSONG WOODS */
UPDATE `creature_template` SET `ScriptName`='npc_prospector_anvilward' WHERE `entry`=15420;
UPDATE `creature_template` SET `ScriptName`='npc_second_trial_paladin' WHERE `entry` IN (17809,17810,17811,17812);
UPDATE `creature_template` SET `ScriptName`='npc_second_trial_controller' WHERE `entry` IN (17807);
UPDATE `creature_template` SET `ScriptName`='npc_apprentice_mirveda' WHERE `entry`=15402;
UPDATE `creature_template` SET `ScriptName`='npc_infused_crystal' WHERE `entry`=16364;
UPDATE `gameobject_template` SET `ScriptName`='go_second_trial' WHERE `entry` IN (182052);

/* EYE OF ETERNITY */
UPDATE `instance_template` SET `script`='instance_eye_of_eternity' WHERE `map`=616;
UPDATE `creature_template` SET `ScriptName`='boss_malygos' WHERE `entry`=28859;
UPDATE `creature_template` SET `ScriptName`='npc_power_spark' WHERE `entry`=30084;
UPDATE `creature_template` SET `ScriptName`='npc_portal_eoe' WHERE `entry`=30118;
UPDATE `creature_template` SET `ScriptName`='npc_hover_disk' WHERE `entry` IN (30234,30248);
UPDATE `creature_template` SET `ScriptName`='npc_arcane_overload' WHERE `entry`=30282;
UPDATE `creature_template` SET `ScriptName`='npc_wyrmrest_skytalon' WHERE `entry`=30161;
UPDATE `creature_template` SET `ScriptName`='npc_alexstrasza_eoe' WHERE `entry`=32295;

/* FELWOOD */
UPDATE `creature_template` SET `ScriptName`='npcs_riverbreeze_and_silversky' WHERE `entry` IN (9528,9529);

/* FERALAS */
UPDATE `creature_template` SET `ScriptName`='npc_gregan_brewspewer' WHERE `entry`=7775;
UPDATE `creature_template` SET `ScriptName`='npc_screecher_spirit' WHERE `entry`=8612;
UPDATE `creature_template` SET `ScriptName`='npc_oox22fe' WHERE `entry`=7807;

/* FORGE OF SOULS */
UPDATE `instance_template` SET `script`='instance_forge_of_souls' WHERE `map`=632;
UPDATE `creature_template` SET `Scriptname`='boss_devourer_of_souls' WHERE `entry`=36502;
UPDATE `creature_template` SET `Scriptname`='boss_bronjahm' WHERE `entry`=36497;
UPDATE `creature_template` SET `Scriptname`='npc_jaina_fos' WHERE `entry`=37597;
UPDATE `creature_template` SET `Scriptname`='npc_sylvanas_fos' WHERE `entry`=37596;
UPDATE `creature_template` SET `Scriptname`='mob_soul_horror' WHERE `entry`=36522;
UPDATE `creature_template` SET `Scriptname`='mob_soulguard_adept' WHERE `entry`=36620;
UPDATE `creature_template` SET `Scriptname`='mob_soulguard_animator' WHERE `entry`=36516;
UPDATE `creature_template` SET `Scriptname`='mob_soulguard_bonecaster' WHERE `entry`=36564;
UPDATE `creature_template` SET `Scriptname`='mob_soulguard_reaper' WHERE `entry`=36499;
UPDATE `creature_template` SET `Scriptname`='mob_soulguard_watchman' WHERE `entry`=36478;
UPDATE `creature_template` SET `Scriptname`='mob_spectral_warden' WHERE `entry`=36666;
UPDATE `creature_template` SET `Scriptname`='mob_spiteful_apparition' WHERE `entry`=36551;
UPDATE `creature_template` SET `Scriptname`='mob_corrupted_soul_fragment' WHERE `entry`=36535;

/* GHOSTLANDS */
UPDATE `creature_template` SET `ScriptName`='npc_blood_knight_dawnstar' WHERE `entry`=17832;
UPDATE `creature_template` SET `ScriptName`='npc_budd_nedreck' WHERE `entry`=23559;
UPDATE `creature_template` SET `ScriptName`='npc_rathis_tomber' WHERE `entry`=16224;
UPDATE `creature_template` SET `Scriptname`='npc_ranger_lilatha' WHERE `entry`=16295;
UPDATE `gameobject_template` SET `ScriptName`='go_gilded_brazier' WHERE `entry`=181956;

/* GNOMEREGAN */
UPDATE `creature_template` SET `ScriptName`='npc_blastmaster_emi_shortfuse' WHERE `entry`=7998;
UPDATE `creature_template` SET `ScriptName`='boss_grubbis' WHERE `entry`=7361;
UPDATE `instance_template` SET `script`='instance_gnomeregan' WHERE `map`=90;

/* GRIZZLY HILLS */
UPDATE `creature_template` SET `ScriptName`='npc_orsonn_and_kodian' WHERE `entry` IN (27274,27275);
UPDATE `creature_template` SET `ScriptName`='npc_emily' WHERE `entry`=26588;
UPDATE `creature_template` SET `ScriptName`='npc_mrfloppy' WHERE `entry`=26589;
UPDATE `gameobject_template` SET `ScriptName`='go_amberpine_outhouse' WHERE `entry`=188666;
UPDATE `creature_template` SET `ScriptName`='npc_outhouse_bunny' WHERE `entry`=27326;
UPDATE `creature_template` SET `ScriptName`='npc_tallhorn_stag' WHERE `entry`=26363;
UPDATE `creature_template` SET `ScriptName`='npc_amberpine_woodsman' WHERE `entry`=27293;
UPDATE `creature_template` SET `ScriptName`='npc_wounded_skirmisher' WHERE `entry`=27463;
UPDATE `creature_template` SET `ScriptName`='npc_lightning_sentry' WHERE `entry`=26407;
UPDATE `creature_template` SET `ScriptName`='npc_venture_co_straggler',`AIName`='' WHERE `entry`=27570;

/* DRAK'THARON KEEP */
UPDATE `instance_template` SET `script`='instance_drak_tharon' WHERE `map`=600;
UPDATE `creature_template` SET `ScriptName`='boss_trollgore' WHERE `entry`=26630;
UPDATE `creature_template` SET `ScriptName`='boss_novos' WHERE `entry`=26631;
UPDATE `creature_template` SET `ScriptName`='mob_crystal_handler' WHERE `entry`=26627;
UPDATE `creature_template` SET `ScriptName`='mob_novos_minion' WHERE `entry` IN (27600,27597,27598);
UPDATE `creature_template` SET `ScriptName`='npc_drakkari_gutripper' WHERE `entry`=26641;
UPDATE `creature_template` SET `ScriptName`='npc_drakkari_scytheclaw' WHERE `entry`=26628;
UPDATE `creature_template` SET `ScriptName`='boss_dred' WHERE `entry`=27483;
UPDATE `creature_template` SET `ScriptName`='boss_tharon_ja' WHERE `entry`=26632;

/* GRUUL'S LAIR */
UPDATE `instance_template` SET `script`='instance_gruuls_lair' WHERE `map`=565;
UPDATE `creature_template` SET `ScriptName`='boss_gruul' WHERE `entry`=19044;
/* Maulgar and Event */
UPDATE `creature_template` SET `ScriptName`='boss_high_king_maulgar' WHERE `entry`=18831;
UPDATE `creature_template` SET `ScriptName`='boss_kiggler_the_crazed' WHERE `entry`=18835;
UPDATE `creature_template` SET `ScriptName`='boss_blindeye_the_seer' WHERE `entry`=18836;
UPDATE `creature_template` SET `ScriptName`='boss_olm_the_summoner' WHERE `entry`=18834;
UPDATE `creature_template` SET `ScriptName`='boss_krosh_firehand' WHERE `entry`=18832;

/* GUNDRAK */
UPDATE `instance_template` SET `script`='instance_gundrak' WHERE `map`=604;
/* Moorabi */
UPDATE `creature_template` SET `ScriptName`='boss_moorabi' WHERE `entry`=29305;
/* Slad'ran */
UPDATE `creature_template` SET `ScriptName`='boss_slad_ran' WHERE `entry`=29304;
UPDATE `creature_template` SET `ScriptName`='mob_slad_ran_viper' WHERE `entry`=29680;
UPDATE `creature_template` SET `ScriptName`='mob_slad_ran_constrictor' WHERE `entry`=29713;
/* Gal'darah */
UPDATE `creature_template` SET `ScriptName`='boss_gal_darah' WHERE `entry`=29306;
/* Drakkari Colossus */
UPDATE `creature_template` SET `ScriptName`='boss_drakkari_colossus' WHERE `entry`=29307;
UPDATE `creature_template` SET `ScriptName`='boss_drakkari_elemental' WHERE `entry`=29573;
UPDATE `creature_template` SET `ScriptName`='npc_living_mojo' WHERE `entry`=29830;
/* Eck the Ferocious */
UPDATE `creature_template` SET `ScriptName`='boss_eck' WHERE `entry`=29932;
UPDATE `creature_template` SET `ScriptName`='npc_ruins_dweller' WHERE `entry`=29920;

UPDATE `gameobject_template` SET `ScriptName`='go_gundrak_altar' WHERE `entry`=192518;
UPDATE `gameobject_template` SET `ScriptName`='go_gundrak_altar' WHERE `entry`=192519;
UPDATE `gameobject_template` SET `ScriptName`='go_gundrak_altar' WHERE `entry`=192520;

/* HALLS OF LIGHTNING */
UPDATE `instance_template` SET `script`='instance_halls_of_lightning' WHERE `map`=602;
/* Bjarngrim */
UPDATE `creature_template` SET `ScriptName`='boss_bjarngrim' WHERE `entry`=28586;
UPDATE `creature_template` SET `ScriptName`='mob_stormforged_lieutenant' WHERE `entry`=29240;
/* Loken */
UPDATE `creature_template` SET `ScriptName`='boss_loken' WHERE `entry`=28923;
/* Volkhan */
UPDATE `creature_template` SET `ScriptName`='boss_volkhan' WHERE `entry`=28587;
UPDATE `creature_template` SET `ScriptName`='mob_molten_golem' WHERE `entry`=28695;
/* Ionar */
UPDATE `creature_template` SET `ScriptName`='boss_ionar' WHERE `entry`=28546;
UPDATE `creature_template` SET `ScriptName`='mob_spark_of_ionar' WHERE `entry`=28926;

/* HALLS OF STONE */
UPDATE `instance_template` SET `script`='instance_halls_of_stone' WHERE `map`=599;
/* Krystallus */
UPDATE `creature_template` SET `ScriptName`='boss_krystallus' WHERE `entry`=27977;
/* Sjonnir */
UPDATE `creature_template` SET `ScriptName`='boss_sjonnir' WHERE `entry`=27978;
UPDATE `creature_template` SET `ScriptName`='mob_tribuna_controller' WHERE `entry`=28234;
UPDATE `creature_template` SET `ScriptName`='npc_brann_hos' WHERE `entry`=28070;
UPDATE `creature_template` SET `ScriptName`='mob_malformed_ooze' WHERE `entry`=27981;
UPDATE `creature_template` SET `ScriptName`='mob_iron_sludge' WHERE `entry`=28165;
/* Maiden of Grief */
UPDATE `creature_template` SET `ScriptName`='boss_maiden_of_grief' WHERE `entry`=27975;

/* HELLFIRE CITADEL */

/* BLOOD FURNACE */
UPDATE `instance_template` SET `script`='instance_blood_furnace' WHERE `map`=542;
UPDATE `creature_template` SET `ScriptName`='boss_the_maker' WHERE `entry`=17381;
UPDATE `creature_template` SET `ScriptName`='boss_broggok' WHERE `entry`=17380;
UPDATE `creature_template` SET `ScriptName`='boss_kelidan_the_breaker' WHERE `entry`=17377;
UPDATE `creature_template` SET `ScriptName`='mob_broggok_poisoncloud' WHERE `entry`=17662;
UPDATE `creature_template` SET `ScriptName`='mob_shadowmoon_channeler' WHERE `entry`=17653;

/* HELLFIRE RAMPARTS */
UPDATE `instance_template` SET `script`='instance_ramparts' WHERE `map`=543;

/* Vazruden, Omor the Unscarred, Watchkeeper Gargolmar */
UPDATE `creature_template` SET `ScriptName`='boss_omor_the_unscarred' WHERE `entry`=17308;
UPDATE `creature_template` SET `ScriptName`='boss_watchkeeper_gargolmar' WHERE `entry`=17306;
UPDATE `creature_template` SET `ScriptName`='boss_vazruden_the_herald' WHERE `entry`=17307;
UPDATE `creature_template` SET `ScriptName`='boss_vazruden' WHERE `entry`=17537;
UPDATE `creature_template` SET `ScriptName`='boss_nazan' WHERE `entry`=17536;
UPDATE `creature_template` SET `ScriptName`='mob_hellfire_sentry' WHERE `entry`=17517;

/* SHATTERED HALLS */
/* Nethekurse and his spawned shadow fissure */
UPDATE `creature_template` SET `ScriptName`='boss_grand_warlock_nethekurse' WHERE `entry`=16807;
UPDATE `creature_template` SET `ScriptName`='boss_warchief_kargath_bladefist' WHERE `entry`=16808;
UPDATE `creature_template` SET `ScriptName`='boss_warbringer_omrogg' WHERE `entry`=16809;
UPDATE `creature_template` SET `ScriptName`='mob_fel_orc_convert' WHERE `entry`=17083;
UPDATE `creature_template` SET `ScriptName`='mob_lesser_shadow_fissure' WHERE `entry`=17471;
UPDATE `creature_template` SET `ScriptName`='mob_omrogg_heads' WHERE `entry` IN (19523,19524);
UPDATE `instance_template` SET `script`='instance_shattered_halls' WHERE `map`=540;

/* MAGTHERIDON'S LAIR */
UPDATE `instance_template` SET `script`='instance_magtheridons_lair' WHERE `map`=544;
UPDATE `gameobject_template` SET `ScriptName`='go_manticron_cube' WHERE `entry`=181713;
UPDATE `creature_template` SET `ScriptName`='boss_magtheridon' WHERE `entry`=17257;
UPDATE `creature_template` SET `ScriptName`='mob_hellfire_channeler' WHERE `entry`=17256;
UPDATE `creature_template` SET `ScriptName`='mob_abyssal' WHERE `entry`=17454;

/* HALLS OF REFLECTION */
UPDATE `instance_template` SET `script`='instance_halls_of_reflection' WHERE `map`=668;
UPDATE `creature_template` SET `Scriptname`='boss_falric' WHERE `entry`=38112;
UPDATE `creature_template` SET `Scriptname`='boss_marwyn' WHERE `entry`=38113;
UPDATE `creature_template` SET `Scriptname`='npc_jaina_hor_part1' WHERE `entry`=37221;
UPDATE `creature_template` SET `Scriptname`='npc_sylvanas_hor_part1' WHERE `entry`=37223;
UPDATE `creature_template` SET `Scriptname`='npc_ghostly_priest' WHERE `entry`=38175;
UPDATE `creature_template` SET `Scriptname`='npc_phantom_mage' WHERE `entry`=38172;
UPDATE `creature_template` SET `Scriptname`='npc_phantom_hallucination' WHERE `entry`=38567;
UPDATE `creature_template` SET `Scriptname`='npc_shadowy_mercenary' WHERE `entry`=38177;
UPDATE `creature_template` SET `Scriptname`='npc_spectral_footman' WHERE `entry`=38173;
UPDATE `creature_template` SET `Scriptname`='npc_tortured_rifleman' WHERE `entry`=38176;

/* HELLFIRE PENINSULA */
UPDATE `creature_template` SET `ScriptName`='boss_doomlord_kazzak' WHERE `entry`=18728;
UPDATE `creature_template` SET `ScriptName`='npc_wounded_blood_elf' WHERE `entry`=16993;
UPDATE `creature_template` SET `ScriptName`='npc_aeranas' WHERE `entry`=17085;
UPDATE `gameobject_template` SET `ScriptName`='go_haaleshi_altar' WHERE `entry`=181606;
UPDATE `creature_template` SET `ScriptName`='npc_naladu' WHERE `entry`=19361;
UPDATE `creature_template` SET `ScriptName`='npc_tracy_proudwell' WHERE `entry`=18266;
UPDATE `creature_template` SET `ScriptName`='npc_trollbane' WHERE `entry`=16819;
UPDATE `creature_template` SET `ScriptName`='npc_ancestral_wolf' WHERE `entry`=17077;
UPDATE `creature_template` SET `ScriptName`='npc_fel_guard_hound' WHERE `entry`=21847;

/* HILLSBRAD FOOTHILLS */

/* HINTERLANDS */
UPDATE `creature_template` SET `ScriptName`='npc_00x09hl' WHERE `entry`=7806;
UPDATE `creature_template` SET `ScriptName`='npc_rinji' WHERE `entry`=7780;

/* HOWLING FJORD */
UPDATE `creature_template` SET `ScriptName`='npc_plaguehound_tracker' WHERE `entry`=24156;
UPDATE `creature_template` SET `ScriptName`='npc_razael_and_lyana' WHERE `entry` IN (23778,23998);
UPDATE `creature_template` SET `ScriptName`='npc_apothecary_hanes' WHERE `entry`=23784;
UPDATE `creature_template` SET `ScriptName`='npc_daegarn' WHERE `entry`=24151;

/* ICECROWN */
UPDATE `creature_template` SET `ScriptName`='npc_arete' WHERE `entry`=29344;
UPDATE `creature_template` SET `ScriptName`='npc_dame_evniki_kapsalis' WHERE `entry`=34885;
UPDATE `creature_template` SET `ScriptName`='npc_squire_david' WHERE `entry`=33447;
UPDATE `creature_template` SET `ScriptName`='npc_argent_valiant' WHERE `entry`=33448;
UPDATE `creature_template` SET `ScriptName`='npc_alorah_and_grimmin' WHERE `entry` IN (36101,36102);
UPDATE `creature_template` SET `ScriptName`='npc_guardian_pavilion' WHERE `entry` IN (33543,33643);

/* ICECROWN CITADEL */
UPDATE `instance_template` SET `script`='instance_icecrown_citadel' WHERE `map`=631;
UPDATE `gameobject_template` SET `ScriptName`='icecrown_citadel_teleport' WHERE `entry` IN (202223,202235,202242,202243,202244,202245,202246);
UPDATE `creature_template` SET `ScriptName`='npc_highlord_tirion_fordring_lh' WHERE `entry`=37119;
UPDATE `creature_template` SET `ScriptName`='boss_lord_marrowgar' WHERE `entry`=36612;
UPDATE `creature_template` SET `ScriptName`='npc_coldflame' WHERE `entry`=36672;
UPDATE `creature_template` SET `ScriptName`='npc_bone_spike' WHERE `entry` IN (36619,38711,38712);
UPDATE `creature_template` SET `ScriptName`='boss_lady_deathwhisper' WHERE `entry`=36855;
UPDATE `creature_template` SET `ScriptName`='npc_cult_fanatic' WHERE `entry` IN (37890,38009,38135);
UPDATE `creature_template` SET `ScriptName`='npc_cult_adherent' WHERE `entry` IN(37949,38010,38136);
UPDATE `creature_template` SET `ScriptName`='npc_vengeful_shade' WHERE `entry`=38222;
UPDATE `creature_template` SET `ScriptName`='npc_darnavan' WHERE `entry` IN (38472,38485);
UPDATE `creature_template` SET `ScriptName`='npc_rotting_frost_giant' WHERE `entry` IN (38490,38494);
UPDATE `creature_template` SET `ScriptName`='boss_deathbringer_saurfang' WHERE `entry`=37813;
UPDATE `creature_template` SET `ScriptName`='npc_high_overlord_saurfang_icc' WHERE `entry`=37187;
UPDATE `creature_template` SET `ScriptName`='npc_muradin_bronzebeard_icc' WHERE `entry`=37200;
UPDATE `creature_template` SET `ScriptName`='npc_saurfang_event' WHERE `entry` IN (37920,37830);
UPDATE `creature_template` SET `ScriptName`='npc_frost_freeze_trap' WHERE `entry`=37744;
UPDATE `creature_template` SET `ScriptName`='npc_alchemist_adrianna' WHERE `entry`=38501;
UPDATE `creature_template` SET `ScriptName`='boss_festergut' WHERE `entry`=36626;
UPDATE `creature_template` SET `ScriptName`='npc_stinky_icc' WHERE `entry`=37025;
UPDATE `creature_template` SET `ScriptName`='boss_rotface' WHERE `entry`=36627;
UPDATE `creature_template` SET `ScriptName`='npc_little_ooze' WHERE `entry`=36897;
UPDATE `creature_template` SET `ScriptName`='npc_big_ooze' WHERE `entry`=36899;
UPDATE `creature_template` SET `ScriptName`='npc_precious_icc' WHERE `entry`=37217;
UPDATE `creature_template` SET `ScriptName`='boss_professor_putricide' WHERE `entry`=36678;
UPDATE `creature_template` SET `ScriptName`='npc_volatile_ooze' WHERE `entry`=37697;
UPDATE `creature_template` SET `ScriptName`='boss_blood_council_controller' WHERE `entry`=38008;
UPDATE `creature_template` SET `ScriptName`='boss_prince_keleseth_icc' WHERE `entry`=37972;
UPDATE `creature_template` SET `ScriptName`='boss_prince_taldaram_icc' WHERE `entry`=37973;
UPDATE `creature_template` SET `ScriptName`='boss_prince_valanar_icc' WHERE `entry`=37970;
UPDATE `creature_template` SET `ScriptName`='npc_blood_queen_lana_thel' WHERE `entry`=38004;
UPDATE `creature_template` SET `ScriptName`='npc_kinetic_bomb' WHERE `entry`=38454;
UPDATE `creature_template` SET `ScriptName`='npc_dark_nucleus' WHERE `entry`=38369;
UPDATE `creature_template` SET `ScriptName`='npc_ball_of_flame' WHERE `entry` IN (38332,38451);
UPDATE `creature_template` SET `ScriptName`='boss_blood_queen_lana_thel' WHERE `entry`=37955;
UPDATE `creature_template` SET `ScriptName`='boss_sister_svalna' WHERE `entry`=37126;
UPDATE `creature_template` SET `ScriptName`='npc_crok_scourgebane' WHERE `entry`=37129;
UPDATE `creature_template` SET `ScriptName`='npc_captain_arnath' WHERE `entry`=37122;
UPDATE `creature_template` SET `ScriptName`='npc_captain_brandon' WHERE `entry`=37123;
UPDATE `creature_template` SET `ScriptName`='npc_captain_grondel' WHERE `entry`=37124;
UPDATE `creature_template` SET `ScriptName`='npc_captain_rupert' WHERE `entry`=37125;
UPDATE `creature_template` SET `ScriptName`='npc_frostwing_vrykul' WHERE `entry` IN (37132,38125,37127,37134,37133);
UPDATE `creature_template` SET `ScriptName`='npc_impaling_spear' WHERE `entry`=38248;
UPDATE `creature_template` SET `ScriptName`='boss_valithria_dreamwalker' WHERE `entry`=36789;
UPDATE `creature_template` SET `ScriptName`='npc_green_dragon_combat_trigger' WHERE `entry`=38752;
UPDATE `creature_template` SET `ScriptName`='npc_the_lich_king_controller' WHERE `entry`=16980;
UPDATE `creature_template` SET `ScriptName`='npc_risen_archmage' WHERE `entry`=37868;
UPDATE `creature_template` SET `ScriptName`='npc_blazing_skeleton' WHERE `entry`=36791;
UPDATE `creature_template` SET `ScriptName`='npc_suppresser' WHERE `entry`=37863;
UPDATE `creature_template` SET `ScriptName`='npc_blistering_zombie' WHERE `entry`=37934;
UPDATE `creature_template` SET `ScriptName`='npc_gluttonous_abomination' WHERE `entry`=37886;
UPDATE `creature_template` SET `ScriptName`='npc_dream_portal' WHERE `entry` IN (37945,38430);
UPDATE `creature_template` SET `ScriptName`='npc_dream_cloud' WHERE `entry` IN (37985,38421);
UPDATE `creature_template` SET `ScriptName`='boss_sindragosa' WHERE `entry`=36853;
UPDATE `creature_template` SET `ScriptName`='npc_ice_tomb' WHERE `entry`=36980;
UPDATE `creature_template` SET `ScriptName`='npc_spinestalker' WHERE `entry`=37534;
UPDATE `creature_template` SET `ScriptName`='npc_rimefang_icc' WHERE `entry`=37533;
UPDATE `creature_template` SET `ScriptName`='npc_sindragosa_trash' WHERE `entry` IN (37531,37532);

/* IRONFORGE */
UPDATE `creature_template` SET `ScriptName`='npc_royal_historian_archesonus' WHERE `entry`=8879;

/* ISLE OF CONQUEST */
UPDATE `creature_template` SET `ScriptName`='npc_four_car_garage' WHERE `entry` IN (35273,34802,34793,34775,35069,34776);

/* ISLE OF QUEL'DANAS */
UPDATE `creature_template` SET `ScriptName`='npc_converted_sentry' WHERE `entry`=24981;
UPDATE `creature_template` SET `ScriptName`='npc_greengill_slave' WHERE `entry`=25084;

/* KARAZHAN */
UPDATE `instance_template` SET `script`='instance_karazhan' WHERE `map`=532;
UPDATE `creature_template` SET `ScriptName`='boss_midnight' WHERE `entry`=16151;
UPDATE `creature_template` SET `ScriptName`='boss_attumen' WHERE `entry`=15550;
UPDATE `creature_template` SET `ScriptName`='boss_moroes' WHERE `entry`=15687;
UPDATE `creature_template` SET `ScriptName`='boss_maiden_of_virtue' WHERE `entry`=16457;
UPDATE `creature_template` SET `ScriptName`='boss_curator' WHERE `entry`=15691;
UPDATE `creature_template` SET `ScriptName`='boss_julianne' WHERE `entry`=17534;
UPDATE `creature_template` SET `ScriptName`='boss_romulo' WHERE `entry`=17533;
UPDATE `creature_template` SET `ScriptName`='boss_dorothee' WHERE `entry`=17535;
UPDATE `creature_template` SET `ScriptName`='boss_strawman' WHERE `entry`=17543;
UPDATE `creature_template` SET `ScriptName`='boss_tinhead' WHERE `entry`=17547;
UPDATE `creature_template` SET `ScriptName`='mob_tito' WHERE `entry`=17548;
UPDATE `creature_template` SET `ScriptName`='boss_roar' WHERE `entry`=17546;
UPDATE `creature_template` SET `ScriptName`='boss_crone' WHERE `entry`=18168;
UPDATE `creature_template` SET `ScriptName`='boss_terestian_illhoof' WHERE `entry`=15688;
UPDATE `creature_template` SET `ScriptName`='mob_fiendish_portal' WHERE `entry`=17265;
UPDATE `creature_template` SET `ScriptName`='boss_shade_of_aran' WHERE `entry`=16524;
UPDATE `creature_template` SET `ScriptName`='boss_netherspite' WHERE `entry`=15689;
UPDATE `creature_template` SET `ScriptName`='boss_malchezaar' WHERE `entry`=15690;
UPDATE `creature_template` SET `ScriptName`='boss_nightbane' WHERE `entry`=17225;
UPDATE `creature_template` SET `ScriptName`='boss_baroness_dorothea_millstipe' WHERE `entry`=19875;
UPDATE `creature_template` SET `ScriptName`='boss_baron_rafe_dreuger' WHERE `entry`=19874;
UPDATE `creature_template` SET `ScriptName`='boss_lady_catriona_von_indi' WHERE `entry`=19872;
UPDATE `creature_template` SET `ScriptName`='boss_lady_keira_berrybuck' WHERE `entry`=17007;
UPDATE `creature_template` SET `ScriptName`='boss_lord_robin_daris' WHERE `entry`=19876;
UPDATE `creature_template` SET `ScriptName`='boss_lord_crispin_ference' WHERE `entry`=19873;
UPDATE `creature_template` SET `ScriptName`='boss_bigbadwolf' WHERE `entry`=17521;
UPDATE `creature_template` SET `ScriptName`='mob_shadow_of_aran' WHERE `entry`=18254;
UPDATE `creature_template` SET `ScriptName`='mob_aran_elemental' WHERE `entry`=17167;
UPDATE `creature_template` SET `ScriptName`='mob_aran_blizzard' WHERE `entry`=17161;
UPDATE `creature_template` SET `ScriptName`='mob_homunculus' WHERE `entry`=16539;
UPDATE `creature_template` SET `ScriptName`='mob_fiendish_imp' WHERE `entry`=17267;
UPDATE `creature_template` SET `ScriptName`='mob_kilrek' WHERE `entry`=17229;
UPDATE `creature_template` SET `ScriptName`='mob_demon_chain' WHERE `entry`=17248;
UPDATE `creature_template` SET `ScriptName`='mob_cyclone' WHERE `entry`=18412;
UPDATE `creature_template` SET `ScriptName`='netherspite_infernal' WHERE `entry`=17646;
UPDATE `creature_template` SET `ScriptName`='npc_berthold' WHERE `entry`=16153;
UPDATE `creature_template` SET `ScriptName`='npc_barnes' WHERE `entry`=16812;
UPDATE `creature_template` SET `ScriptName`='npc_grandmother' WHERE `entry`=17603;
UPDATE `creature_template` SET `ScriptName`='npc_image_of_medivh' WHERE `entry`=17651;

/* LOCH MODAN */
UPDATE `creature_template` SET `ScriptName`='npc_mountaineer_pebblebitty' WHERE `entry`=3836;

/* Magister's Terrace */
UPDATE `instance_template` SET `script`='instance_magisters_terrace' WHERE `map`=585;
UPDATE `creature_template` SET `ScriptName`='boss_selin_fireheart' WHERE `entry`=24723;
UPDATE `creature_template` SET `ScriptName`='mob_fel_crystal' WHERE `entry`=24722;
UPDATE `creature_template` SET `ScriptName`='boss_vexallus' WHERE `entry`=24744;
UPDATE `creature_template` SET `ScriptName`='mob_pure_energy' WHERE `entry`=24745;
UPDATE `creature_template` SET `ScriptName`='boss_priestess_delrissa' WHERE `entry`=24560;
UPDATE `creature_template` SET `ScriptName`='boss_kagani_nightstrike' WHERE `entry`=24557;
UPDATE `creature_template` SET `ScriptName`='boss_ellris_duskhallow' WHERE `entry`=24558;
UPDATE `creature_template` SET `ScriptName`='boss_eramas_brightblaze' WHERE `entry`=24554;
UPDATE `creature_template` SET `ScriptName`='boss_yazzai' WHERE `entry`=24561;
UPDATE `creature_template` SET `ScriptName`='boss_warlord_salaris' WHERE `entry`=24559;
UPDATE `creature_template` SET `ScriptName`='boss_garaxxas' WHERE `entry`=24555;
UPDATE `creature_template` SET `ScriptName`='mob_sliver' WHERE `entry`=24552;
UPDATE `creature_template` SET `ScriptName`='boss_apoko' WHERE `entry`=24553;
UPDATE `creature_template` SET `ScriptName`='boss_zelfan' WHERE `entry`=24556;
UPDATE `creature_template` SET `ScriptName`='boss_felblood_kaelthas' WHERE `entry`=24664;
UPDATE `creature_template` SET `ScriptName`='mob_arcane_sphere' WHERE `entry`=24708;
UPDATE `creature_template` SET `ScriptName`='mob_felkael_phoenix' WHERE `entry`=24674;
UPDATE `creature_template` SET `ScriptName`='mob_felkael_phoenix_egg' WHERE `entry`=24675;
UPDATE `creature_template` SET `ScriptName`='mob_felkael_flamestrike' WHERE `entry`=24666;
UPDATE `creature_template` SET `ScriptName`='npc_kalecgos' WHERE `entry` IN (24844,24848);

/* MARAUDON */
UPDATE `creature_template` SET `ScriptName`='boss_princess_theradras' WHERE `entry`=12201;
UPDATE `creature_template` SET `ScriptName`='boss_noxxion' WHERE `entry`=13282;
UPDATE `creature_template` SET `ScriptName`='boss_landslide' WHERE `entry`=12203;
UPDATE `creature_template` SET `ScriptName`='celebras_the_cursed' WHERE `entry`=12225;

/* MOLTEN CORE */
UPDATE `instance_template` SET `script`='instance_molten_core' WHERE `map`=409;
UPDATE `creature_template` SET `ScriptName`='boss_lucifron' WHERE `entry`=12118;
UPDATE `creature_template` SET `ScriptName`='boss_magmadar' WHERE `entry`=11982;
UPDATE `creature_template` SET `ScriptName`='boss_gehennas' WHERE `entry`=12259;
UPDATE `creature_template` SET `ScriptName`='boss_garr' WHERE `entry`=12057;
UPDATE `creature_template` SET `ScriptName`='boss_baron_geddon' WHERE `entry`=12056;
UPDATE `creature_template` SET `ScriptName`='boss_shazzrah' WHERE `entry`=12264;
UPDATE `creature_template` SET `ScriptName`='boss_golemagg' WHERE `entry`=11988;
UPDATE `creature_template` SET `ScriptName`='boss_sulfuron' WHERE `entry`=12098;
UPDATE `creature_template` SET `ScriptName`='boss_majordomo' WHERE `entry`=12018;
UPDATE `creature_template` SET `ScriptName`='boss_ragnaros' WHERE `entry`=11502;
UPDATE `creature_template` SET `ScriptName`='mob_ancient_core_hound' WHERE `entry`=11673;
UPDATE `creature_template` SET `ScriptName`='mob_firesworn' WHERE `entry`=12099;
UPDATE `creature_template` SET `ScriptName`='mob_core_rager' WHERE `entry`=11672;
UPDATE `creature_template` SET `ScriptName`='mob_flamewaker_priest' WHERE `entry`=11662;
UPDATE `creature_template` SET `ScriptName`='mob_SonOfFlame' WHERE `entry`=12143;

/* MOONGLADE */
UPDATE `creature_template` SET `ScriptName`='npc_bunthen_plainswind' WHERE `entry`=11798;
UPDATE `creature_template` SET `ScriptName`='npc_great_bear_spirit' WHERE `entry`=11956;
UPDATE `creature_template` SET `ScriptName`='npc_silva_filnaveth' WHERE `entry`=11800;
UPDATE `creature_template` SET `ScriptName`='npc_clintar_dreamwalker' WHERE `entry`=22834;
UPDATE `creature_template` SET `ScriptName`='npc_clintar_spirit' WHERE `entry`=22916;

/* MULGORE */
UPDATE `creature_template` SET `ScriptName`='npc_skorn_whitecloud' WHERE `entry`=3052;
UPDATE `creature_template` SET `ScriptName`='npc_kyle_frenzied' WHERE `entry`=23616;
UPDATE `creature_template` SET `ScriptName`='npc_plains_vision' WHERE `entry`=2983;

/* NAGRAND */
UPDATE `creature_template` SET `ScriptName`='mob_lump' WHERE `entry`=18351;
UPDATE `creature_template` SET `ScriptName`='mob_shattered_rumbler' WHERE `entry`=17157;
UPDATE `creature_template` SET `ScriptName`='mob_sunspring_villager' WHERE `entry`=18240;
UPDATE `creature_template` SET `ScriptName`='npc_altruis_the_sufferer' WHERE `entry`=18417;
UPDATE `creature_template` SET `ScriptName`='npc_greatmother_geyah' WHERE `entry`=18141;
UPDATE `creature_template` SET `ScriptName`='npc_lantresor_of_the_blade' WHERE `entry`=18261;
UPDATE `creature_template` SET `ScriptName`='npc_creditmarker_visit_with_ancestors' WHERE `entry` IN (18840,18841,18842,18843);
UPDATE `creature_template` SET `ScriptName`='mob_sparrowhawk' WHERE `entry`=22979;
UPDATE `creature_template` SET `ScriptName`='npc_maghar_captive' WHERE `entry`=18210;
UPDATE `creature_template` SET `ScriptName`='npc_corki' WHERE `entry` IN (18445,20812,18369);
UPDATE `gameobject_template` SET `ScriptName`='go_corkis_prison' WHERE `entry` IN (182349,182350,182521);

/* NAXXRAMAS */
UPDATE `instance_template` SET `script`='instance_naxxramas' WHERE `map`=533;
UPDATE `creature_template` SET `ScriptName`='boss_anubrekhan' WHERE `entry`=15956;
UPDATE `creature_template` SET `ScriptName`='boss_faerlina' WHERE `entry`=15953;
UPDATE `creature_template` SET `ScriptName`='mob_faerlina_add' WHERE `entry`=16506;
UPDATE `creature_template` SET `ScriptName`='boss_maexxna' WHERE `entry`=15952;
UPDATE `creature_template` SET `ScriptName`='mob_webwrap' WHERE `entry`=16486;
UPDATE `creature_template` SET `ScriptName`='boss_noth' WHERE `entry`=15954;
UPDATE `creature_template` SET `ScriptName`='boss_heigan' WHERE `entry`=15936;
UPDATE `creature_template` SET `ScriptName`='boss_loatheb' WHERE `entry`=16011;
UPDATE `creature_template` SET `ScriptName`='boss_razuvious' WHERE `entry`=16061;
UPDATE `creature_template` SET `ScriptName`='boss_gothik' WHERE `entry`=16060;
UPDATE `creature_template` SET `ScriptName`='mob_gothik_minion' where `entry` IN (16124,16125,16126,16127,16148,16149,16150);
UPDATE `creature_template` SET `ScriptName`='boss_four_horsemen' WHERE `entry` IN (16063,16064,16065,30549);
UPDATE `creature_template` SET `ScriptName`='boss_patchwerk' WHERE `entry`=16028;
UPDATE `creature_template` SET `ScriptName`='boss_grobbulus' WHERE `entry`=15931;
UPDATE `creature_template` SET `ScriptName`='npc_grobbulus_poison_cloud' WHERE `entry`=16363;
UPDATE `creature_template` SET `ScriptName`='boss_gluth' WHERE `entry`=15932;
UPDATE `creature_template` SET `ScriptName`='boss_thaddius' WHERE `entry`=15928;
UPDATE `creature_template` SET `ScriptName`='mob_stalagg' WHERE `entry`=15929;
UPDATE `creature_template` SET `ScriptName`='mob_feugen' WHERE `entry`=15930;
UPDATE `creature_template` SET `ScriptName`='boss_sapphiron' WHERE `entry`=15989;
UPDATE `creature_template` SET `ScriptName`='boss_kelthuzad' WHERE `entry`=15990;
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry` IN (16062,30000);
UPDATE `creature_template` SET `ScriptName`='trigger_periodic' WHERE `entry` IN (16474,16697,16129);

DELETE FROM `areatrigger_scripts` WHERE `entry`=4112;
INSERT INTO `areatrigger_scripts`(`entry`,`ScriptName`) VALUES(4112,'at_kelthuzad_center');

/* NETHERSTORM */
UPDATE `gameobject_template` SET `ScriptName`='go_manaforge_control_console' WHERE `entry` IN (183770,183956,184311,184312);
UPDATE `creature_template` SET `ScriptName`='npc_manaforge_control_console' WHERE `entry` IN (20209,20417,20418,20440);
UPDATE `creature_template` SET `ScriptName`='mob_phase_hunter' WHERE `entry`=18879;
UPDATE `creature_template` SET `ScriptName`='npc_professor_dabiri' WHERE `entry`=20907;
UPDATE `creature_template` SET `ScriptName`='npc_bessy' WHERE `entry`=20415;
UPDATE `creature_template` SET `ScriptName`='npc_commander_dawnforge' WHERE `entry`=19831;
UPDATE `creature_template` SET `ScriptName`='npc_maxx_a_million_escort', `MovementType`=2 WHERE `entry`=19589;


/* THE NEXUS */
UPDATE `instance_template` SET `script`='instance_nexus' WHERE `map`=576;
UPDATE `creature_template` SET `ScriptName`='boss_magus_telestra' WHERE `entry`=26731;
UPDATE `creature_template` SET `ScriptName`='boss_anomalus' WHERE `entry`=26763;
UPDATE `creature_template` SET `ScriptName`='mob_chaotic_rift' WHERE `entry`=26918;
UPDATE `creature_template` SET `ScriptName`='boss_ormorok' WHERE `entry`=26794;
UPDATE `creature_template` SET `ScriptName`='mob_crystal_spike' WHERE `entry`=27099;
UPDATE `creature_template` SET `ScriptName`='mob_crystalline_tangler' WHERE `entry`=32665;
UPDATE `creature_template` SET `ScriptName`='boss_keristrasza' WHERE `entry`=26723;
UPDATE `gameobject_template` SET `ScriptName`='containment_sphere' WHERE `entry` IN (188527,188528,188526);

/* THE NEXUS, THE OCULUS */
UPDATE `instance_template` SET `script`='instance_oculus' WHERE `map`=578;
UPDATE `creature_template` SET `ScriptName`='boss_drakos' WHERE `entry`=27654;
UPDATE `creature_template` SET `ScriptName`='npc_unstable_sphere' WHERE `entry`=28166;
UPDATE `creature_template` SET `ScriptName`='npc_oculus_drake' WHERE `entry` IN (27657,27658,27659);
UPDATE `creature_template` SET `ScriptName`='boss_urom' WHERE `entry`=27655;
UPDATE `creature_template` SET `ScriptName`='boss_varos' WHERE `entry`=27447;
UPDATE `creature_template` SET `ScriptName`='npc_azure_ring_captain' WHERE `entry`=28236;
UPDATE `creature_template` SET `ScriptName`='boss_eregos' WHERE `entry`=27656;

/* OBSIDIAN SANCTUM */
UPDATE `instance_template` SET `script`='instance_obsidian_sanctum' WHERE `map`=615;
UPDATE `creature_template` SET `ScriptName`='boss_sartharion' WHERE `entry`=28860;
UPDATE `creature_template` SET `ScriptName`='mob_vesperon' WHERE `entry`=30449;
UPDATE `creature_template` SET `ScriptName`='mob_shadron' WHERE `entry`=30451;
UPDATE `creature_template` SET `ScriptName`='mob_tenebron' WHERE `entry`=30452;
UPDATE `creature_template` SET `ScriptName`='mob_twilight_eggs' WHERE `entry`=30882;
UPDATE `creature_template` SET `ScriptName`='mob_twilight_whelp' WHERE `entry` IN (30890,31214);
UPDATE `creature_template` SET `ScriptName`='npc_twilight_fissure' WHERE `entry`=30641;
UPDATE `creature_template` SET `ScriptName`='mob_acolyte_of_shadron' WHERE `entry`=31218;
UPDATE `creature_template` SET `ScriptName`='mob_acolyte_of_vesperon' WHERE `entry`=31219;
UPDATE `creature_template` SET `ScriptName`='npc_flame_tsunami' WHERE `entry`=30616;

/* ONYXIA'S LAIR */
UPDATE `instance_template` SET `script`='instance_onyxias_lair' WHERE `map`=249;
UPDATE `creature_template` SET `ScriptName`='boss_onyxia' WHERE `entry`=10184;

/* ORGRIMMAR */
UPDATE `creature_template` SET `ScriptName`='npc_shenthul' WHERE `entry`=3401;
UPDATE `creature_template` SET `ScriptName`='npc_thrall_warchief' WHERE `entry`=4949;

/* PIT OF SARON */
UPDATE `instance_template` SET `script`='instance_pit_of_saron' WHERE `map`=658;
UPDATE `creature_template` SET `Scriptname`='boss_garfrost' WHERE `entry`=36494;
UPDATE `creature_template` SET `Scriptname`='boss_ick' WHERE `entry`=36476;
UPDATE `creature_template` SET `Scriptname`='boss_krick' WHERE `entry`=36477;
UPDATE `creature_template` SET `Scriptname`='boss_tyrannus' WHERE `entry`=36658;
UPDATE `creature_template` SET `Scriptname`='boss_rimefang' WHERE `entry`=36661;
UPDATE `creature_template` SET `Scriptname`='mob_ymirjar_flamebearer' WHERE `entry`=36893;
UPDATE `creature_template` SET `Scriptname`='mob_wrathbone_laborer' WHERE `entry`=36830;
UPDATE `creature_template` SET `Scriptname`='mob_iceborn_protodrake' WHERE `entry`=36891;
UPDATE `creature_template` SET `Scriptname`='mob_geist_ambusher' WHERE `entry`=36886;

/* RAGEFIRE CHASM */
UPDATE `gameobject_template` SET `ScriptName`='go_blood_filled_orb' WHERE `entry`=182024;

/* RAZORFEN DOWNS */
UPDATE `creature_template` SET `ScriptName`='boss_amnennar_the_coldbringer' WHERE `entry`=7358;
UPDATE `creature_template` SET `ScriptName`='npc_henry_stern' WHERE `entry`=8696;
UPDATE `creature_template` SET `ScriptName`='npc_tomb_creature' WHERE `entry` IN (7351,7349);
UPDATE `instance_template` SET `script`='instance_razorfen_downs' WHERE `map`=129;
UPDATE `gameobject_template` SET `ScriptName`='go_gong' WHERE `entry`=148917;

/* RAZORFEN KRAUL */
UPDATE `creature_template` SET `Scriptname`='npc_willix' WHERE `entry`=4508;
UPDATE `instance_template` SET `script`='instance_razorfen_kraul' WHERE `map`=47;
UPDATE `creature_template` SET `ScriptName`='npc_deaths_head_ward_keeper' WHERE `entry`=4625;

/* REDRIDGE MOUNTAINS */
UPDATE `creature_template` SET `ScriptName`='npc_corporal_keeshan' WHERE `entry`=349;

/* RUINS OF AHN'QIRAJ */
UPDATE `creature_template` SET `ScriptName`='boss_kurinnaxx' WHERE `entry`=15348;
UPDATE `creature_template` SET `ScriptName`='boss_rajaxx' WHERE `entry`=15341;
UPDATE `creature_template` SET `ScriptName`='boss_moam' WHERE `entry`=15340;
UPDATE `creature_template` SET `ScriptName`='boss_buru' WHERE `entry`=15370;
UPDATE `creature_template` SET `ScriptName`='boss_ayamiss' WHERE `entry`=15369;
UPDATE `creature_template` SET `ScriptName`='boss_ossirian' WHERE `entry`=15339;
UPDATE `instance_template` SET `script`='instance_ruins_of_ahnqiraj' WHERE `map`=509;

/* SCARLET MONASTERY */
UPDATE `instance_template` SET `script`='instance_scarlet_monastery' WHERE `map`=189;
UPDATE `creature_template` SET `ScriptName`='boss_arcanist_doan' WHERE `entry`=6487;
UPDATE `creature_template` SET `ScriptName`='boss_azshir_the_sleepless' WHERE `entry`=6490;
UPDATE `creature_template` SET `ScriptName`='boss_bloodmage_thalnos' WHERE `entry`=4543;
UPDATE `creature_template` SET `ScriptName`='boss_herod' WHERE `entry`=3975;
UPDATE `creature_template` SET `ScriptName`='boss_high_inquisitor_fairbanks' WHERE `entry`=4542;
UPDATE `creature_template` SET `ScriptName`='boss_high_inquisitor_whitemane' WHERE `entry`=3977;
UPDATE `creature_template` SET `ScriptName`='boss_houndmaster_loksey' WHERE `entry`=3974;
UPDATE `creature_template` SET `ScriptName`='boss_interrogator_vishas' WHERE `entry`=3983;
UPDATE `creature_template` SET `ScriptName`='boss_scarlet_commander_mograine' WHERE `entry`=3976;
UPDATE `creature_template` SET `ScriptName`='boss_scorn' WHERE `entry`=14693;
UPDATE `creature_template` SET `ScriptName`='boss_headless_horseman' WHERE `entry`=23682;
UPDATE `creature_template` SET `ScriptName`='mob_head' WHERE `entry`=23775;
UPDATE `creature_template` SET `ScriptName`='mob_pulsing_pumpkin' WHERE `entry`=23694;
UPDATE `creature_template` SET `ScriptName`='mob_wisp_invis' WHERE `entry`=23686;
UPDATE `creature_template` SET `ScriptName`='mob_wisp_invis' WHERE `entry`=24034;
UPDATE `creature_template` SET `ScriptName`='mob_scarlet_trainee' WHERE `entry`=6575;
UPDATE `gameobject_template` SET `ScriptName`='go_loosely_turned_soil' WHERE `entry`=186314;

/* SCHOLOMANCE */
UPDATE `instance_template` SET `script`='instance_scholomance' WHERE `map`=289;
UPDATE `creature_template` SET `ScriptName`='boss_darkmaster_gandling' WHERE `entry`=1853;
UPDATE `creature_template` SET `ScriptName`='boss_death_knight_darkreaver' WHERE `entry`=14516;
UPDATE `creature_template` SET `ScriptName`='boss_lord_alexei_barov' WHERE `entry`=10504;
UPDATE `creature_template` SET `ScriptName`='boss_instructor_malicia' WHERE `entry`=10505;
UPDATE `creature_template` SET `ScriptName`='boss_boss_ras_frostwhisper' WHERE `entry`=10508;
UPDATE `creature_template` SET `ScriptName`='boss_the_ravenian' WHERE `entry`=10507;
UPDATE `creature_template` SET `ScriptName`='boss_vectus' WHERE `entry`=10432;
UPDATE `creature_template` SET `ScriptName`='boss_illucia_barov' WHERE `entry`=10502;
UPDATE `creature_template` SET `ScriptName`='boss_doctor_theolen_krastinov' WHERE `entry`=11261;
UPDATE `creature_template` SET `ScriptName`='boss_jandice_barov' WHERE `entry`=10503;
UPDATE `creature_template` SET `ScriptName`='boss_lorekeeper_polkelt' WHERE `entry`=10901;
UPDATE `creature_template` SET `ScriptName`='boss_kormok' WHERE `entry`=16118;
UPDATE `creature_template` SET `ScriptName`='mob_illusionofjandicebarov' WHERE `entry`=11439;

/* SEARING GORGE */
UPDATE `creature_template` SET `ScriptName`='npc_kalaran_windblade' WHERE `entry`=8479;
UPDATE `creature_template` SET `ScriptName`='npc_lothos_riftwaker' WHERE `entry`=14387;
UPDATE `creature_template` SET `ScriptName`='npc_zamael_lunthistle' WHERE `entry`=8436;

/* SHADOWFANG KEEP */
UPDATE `instance_template` SET `script`='instance_shadowfang_keep' WHERE `map`=33;
UPDATE `creature_template` SET `ScriptName`='npc_shadowfang_prisoner' WHERE `entry` IN (3849,3850);
UPDATE `creature_template` SET `ScriptName`='npc_arugal_voidwalker' WHERE `entry`=4627;

/* SHADOWMOON VALLEY */
UPDATE `creature_template` SET `ScriptName`='boss_doomwalker' WHERE `entry`=17711;
UPDATE `creature_template` SET `ScriptName`='npc_drake_dealer_hurlunk' WHERE `entry`=23489;
UPDATE `creature_template` SET `ScriptName`='npc_invis_legion_teleporter' WHERE `entry`=21807;
UPDATE `creature_template` SET `ScriptName`='npcs_flanis_swiftwing_and_kagrosh' WHERE `entry` IN (21725,21727);
UPDATE `creature_template` SET `ScriptName`='npc_murkblood_overseer' WHERE `entry`=23309;
UPDATE `creature_template` SET `ScriptName`='npc_oronok_tornheart' WHERE `entry`=21183;
UPDATE `creature_template` SET `ScriptName`='mob_mature_netherwing_drake' WHERE `entry`=21648;
UPDATE `creature_template` SET `ScriptName`='mob_enslaved_netherwing_drake' WHERE `entry`=21722;
UPDATE `creature_template` SET `ScriptName`='npc_overlord_morghor' WHERE `entry`=23139;
UPDATE `creature_template` SET `ScriptName`='mob_illidari_spawn' WHERE `entry` IN (22075,22074,19797);
UPDATE `creature_template` SET `ScriptName`='mob_torloth_the_magnificent' WHERE `entry`=22076;
UPDATE `creature_template` SET `ScriptName`='npc_lord_illidan_stormrage' WHERE `entry`=22083;
UPDATE `creature_template` SET `ScriptName`='npc_earthmender_wilda' WHERE `entry`=21027;
UPDATE `creature_template` SET `ScriptName`='npc_enraged_spirit' WHERE `entry` IN (21050,21061,21060,21059);
UPDATE `creature_template` SET `ScriptName`='mob_dragonmaw_peon' WHERE `entry`=22252;
UPDATE `creature_template` SET `ScriptName`='npc_karynaku' WHERE `entry`=22112;

/* SHATTRATH */
UPDATE `creature_template` SET `ScriptName`='npc_raliq_the_drunk' WHERE `entry`=18585;
UPDATE `creature_template` SET `ScriptName`='npc_salsalabim' WHERE `entry`=18584;
UPDATE `creature_template` SET `ScriptName`='npc_shattrathflaskvendors' WHERE `entry` IN (23483,23484);
UPDATE `creature_template` SET `ScriptName`='npc_zephyr' WHERE `entry`=25967;
UPDATE `creature_template` SET `ScriptName`='npc_kservant' WHERE `entry`=19685;
UPDATE `creature_template` SET `ScriptName`='npc_dirty_larry' WHERE `entry`=19720;
UPDATE `creature_template` SET `ScriptName`='npc_ishanah' WHERE `entry`=18538;
UPDATE `creature_template` SET `ScriptName`='npc_khadgar' WHERE `entry`=18166;

/* Sholazar Basin */
UPDATE `creature_template` SET `ScriptName`='npc_injured_rainspeaker_oracle' WHERE `entry`=28217;
UPDATE `creature_template` SET `ScriptName`='npc_vekjik' WHERE `entry`=28315;
UPDATE `creature_template` SET `ScriptName`='npc_avatar_of_freya' WHERE `entry`=27801;
UPDATE `creature_template` SET `ScriptName`='npc_bushwhacker' WHERE `entry`=28317;
UPDATE `creature_template` SET `ScriptName`='npc_engineer_helice' WHERE `entry`=28787;
UPDATE `creature_template` SET `ScriptName`='npc_adventurous_dwarf' WHERE `entry`=28604;
UPDATE `creature_template` SET `ScriptName`='npc_jungle_punch_target' WHERE `entry` IN(27986,28047,28568);

/* SILITHUS */
UPDATE `creature_template` SET `ScriptName`='npcs_rutgar_and_frankal' WHERE `entry` IN (15170,15171);
UPDATE `creature_template` SET `ScriptName`='npc_highlord_demitrian' WHERE `entry`=14347;
UPDATE `gameobject_template` SET `ScriptName`='go_gauntlet_gate' WHERE `entry`=175357;
UPDATE `gameobject_template` SET `ScriptName`='go_crystalline_tear' WHERE `entry`=180633;
UPDATE `creature_template` SET `ScriptName`='mob_qiraj_war_spawn' WHERE `entry` IN (15414,15422,15424,15423);
UPDATE `creature_template` SET `ScriptName`='npc_anachronos_the_ancient' WHERE `entry`=15381;
UPDATE `creature_template` SET `ScriptName`='npc_anachronos_quest_trigger' WHERE `entry`=15454;
UPDATE `gameobject_template` SET `ScriptName`='go_hive_pod' WHERE `entry`=178553;

/* SILVERMOON */
UPDATE `creature_template` SET `ScriptName`='npc_blood_knight_stillblade' WHERE `entry`=17768;

/* SILVERPINE FOREST */
UPDATE `creature_template` SET `ScriptName`='npc_astor_hadren' WHERE `entry`=6497;
UPDATE `creature_template` SET `ScriptName`='npc_deathstalker_erland' WHERE `entry`=1978;
UPDATE `creature_template` SET `ScriptName`='pyrewood_ambush' WHERE `entry`=2058;

/* STOCKADES */

/* STONETALON MOUNTAINS */
UPDATE `creature_template` SET `ScriptName`='npc_braug_dimspirit' WHERE `entry`=4489;
UPDATE `creature_template` SET `ScriptName`='npc_kaya_flathoof' WHERE `entry`=11856;

/* STORM PEAKS */
UPDATE `creature_template` SET `ScriptName`='npc_agnetta_tyrsdottar' WHERE `entry`=30154;
UPDATE `creature_template` SET `ScriptName`='npc_frostborn_scout' WHERE `entry`=29811;
UPDATE `creature_template` SET `ScriptName`='npc_thorim' WHERE `entry`=29445;
UPDATE `creature_template` SET `ScriptName`='npc_goblin_prisoner' WHERE `entry`=29466;
UPDATE `gameobject_template` SET ScriptName='go_rusty_cage' WHERE `entry`=191544;
UPDATE `creature_template` SET `ScriptName`='npc_injured_goblin' WHERE `entry`=29434;
UPDATE `creature_template` SET `ScriptName`='npc_roxi_ramrocket' WHERE `entry`=31247;
UPDATE `creature_template` SET `ScriptName`='npc_brunnhildar_prisoner' WHERE `entry`=29639;
UPDATE `creature_template` SET `ScriptName`='npc_icefang' WHERE `entry`=29602;

/* STORMWIND CITY */
UPDATE `creature_template` SET `ScriptName`='npc_archmage_malin' WHERE `entry`=2708;
UPDATE `creature_template` SET `ScriptName`='npc_bartleby' WHERE `entry`=6090;
UPDATE `creature_template` SET `ScriptName`='npc_dashel_stonefist' WHERE `entry`=4961;
UPDATE `creature_template` SET `ScriptName`='npc_lady_katrana_prestor' WHERE `entry`=1749;
UPDATE `creature_template` SET `ScriptName`='npc_tyrion' WHERE `entry`=7766;
UPDATE `creature_template` SET `ScriptName`='npc_tyrion_spybot' WHERE `entry`=8856;
UPDATE `creature_template` SET `ScriptName`='npc_lord_gregor_lescovar' WHERE `entry`=1754;
UPDATE `creature_template` SET `ScriptName`='npc_marzon_silent_blade' WHERE `entry`=1755;


/* STRANGLETHORN VALE */
UPDATE `creature_template` SET `ScriptName`='mob_yenniku' WHERE `entry`=2530;

/* STRATHOLME */
UPDATE `instance_template` SET `script`='instance_stratholme' WHERE `map`=329;
UPDATE `creature_template` SET `ScriptName`='boss_dathrohan_balnazzar' WHERE `entry`=10812;
UPDATE `creature_template` SET `ScriptName`='boss_magistrate_barthilas' WHERE `entry`=10435;
UPDATE `creature_template` SET `ScriptName`='boss_maleki_the_pallid' WHERE `entry`=10438;
UPDATE `creature_template` SET `ScriptName`='boss_nerubenkan' WHERE `entry`=10437;
UPDATE `creature_template` SET `ScriptName`='boss_cannon_master_willey' WHERE `entry`=10997;
UPDATE `creature_template` SET `ScriptName`='boss_baroness_anastari' WHERE `entry`=10436;
UPDATE `creature_template` SET `ScriptName`='boss_ramstein_the_gorger' WHERE `entry`=10439;
UPDATE `creature_template` SET `ScriptName`='boss_timmy_the_cruel' WHERE `entry`=10808;
UPDATE `creature_template` SET `ScriptName`='boss_silver_hand_bosses' WHERE `entry` IN (17910,17911,17912,17913,17914);
UPDATE `creature_template` SET `ScriptName`='boss_postmaster_malown' WHERE `entry`=11143;
UPDATE `creature_template` SET `ScriptName`='boss_baron_rivendare' WHERE `entry`=10440;
UPDATE `creature_template` SET `ScriptName`='mob_mindless_skeleton' WHERE `entry`=11197;
UPDATE `creature_template` SET `ScriptName`='mob_thuzadin_acolyte' WHERE `entry`=10399;
UPDATE `creature_template` SET `ScriptName`='mobs_spectral_ghostly_citizen' WHERE `entry` IN (10384,10385);
UPDATE `creature_template` SET `ScriptName`='mob_restless_soul' WHERE `entry`=11122;
UPDATE `creature_template` SET `ScriptName`='mob_freed_soul' WHERE `entry`=11136;

/* SUNKEN TEMPLE */
UPDATE `instance_template` SET `script`='instance_sunken_temple' WHERE `map`=109;
UPDATE `gameobject_template` SET `ScriptName`='go_atalai_statue' WHERE `entry` IN (148830,148831,148832,148833,148834,148835);
UPDATE `creature_template` SET `ScriptName`='boss_twilight_corrupter' WHERE `entry`=15625;
DELETE FROM `areatrigger_scripts` WHERE `entry`=4016;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES (4016,'at_malfurion_stormrage');

/* SUNWELL PLATEAU */
UPDATE `instance_template` SET `script`='instance_sunwell_plateau' WHERE `map`=580;
UPDATE `creature_template` SET `ScriptName`='boss_brutallus' WHERE `entry`=24882;
UPDATE `creature_template` SET `ScriptName`='boss_felmyst' WHERE `entry`=25038;
UPDATE `creature_template` SET `ScriptName`='mob_felmyst_vapor' WHERE `entry`=25265;
UPDATE `creature_template` SET `ScriptName`='mob_felmyst_trail' WHERE `entry`=25267;
UPDATE `creature_template` SET `ScriptName`='boss_sacrolash' WHERE `entry`=25165;
UPDATE `creature_template` SET `ScriptName`='boss_alythess' WHERE `entry`=25166;
UPDATE `creature_template` SET `ScriptName`='mob_shadow_image' WHERE `entry`=25214;
UPDATE `creature_template` SET `ScriptName`='boss_kiljaeden' WHERE `entry`=25315;
UPDATE `creature_template` SET `ScriptName`='boss_kalecgos_kj' WHERE `entry`=25319;
UPDATE `creature_template` SET `ScriptName`='mob_kiljaeden_controller' WHERE `entry`=25608;
UPDATE `creature_template` SET `ScriptName`='mob_hand_of_the_deceiver' WHERE `entry`=25588;
UPDATE `creature_template` SET `ScriptName`='mob_felfire_portal' WHERE `entry`=25603;
UPDATE `creature_template` SET `ScriptName`='mob_volatile_felfire_fiend' WHERE `entry`=25598;
UPDATE `creature_template` SET `ScriptName`='mob_armageddon' WHERE `entry`=25735;
UPDATE `creature_template` SET `ScriptName`='mob_shield_orb' WHERE `entry`=25502;
UPDATE `creature_template` SET `ScriptName`='mob_sinster_reflection' WHERE `entry`=25708;
UPDATE `gameobject_template` SET `ScriptName`='go_orb_of_the_blue_flight' WHERE `entry`=188415;
UPDATE `creature_template` SET `ScriptName`='npc_void_sentinel' WHERE `entry`=25772;
UPDATE `creature_template` SET `ScriptName`='npc_dark_fiend' WHERE `entry`=25744;
UPDATE `creature_template` SET `ScriptName`='boss_muru' WHERE `entry`=25741;
UPDATE `creature_template` SET `ScriptName`='boss_entropius' WHERE `entry`=25840;
UPDATE `creature_template` SET `ScriptName`='npc_muru_portal' WHERE `entry`=25770;
UPDATE `creature_template` SET `ScriptName`='boss_kalecgos' WHERE `entry`=24850;
UPDATE `creature_template` SET `ScriptName`='boss_sathrovarr' WHERE `entry`=24892;
UPDATE `creature_template` SET `ScriptName`='boss_kalec' WHERE `entry`=24891;
UPDATE `gameobject_template` SET `ScriptName`='kalecgos_teleporter' WHERE `entry`=187055;
UPDATE `creature_template` SET `ScriptName`='npc_blackhole' WHERE `entry`=25855;

/* SWAMP OF SORROWS */
UPDATE `creature_template` SET `ScriptName`='npc_galen_goodward' WHERE `entry`=5391;

/* TANARIS */
UPDATE `creature_template` SET `ScriptName`='mob_aquementas' WHERE `entry`=9453;
UPDATE `creature_template` SET `ScriptName`='npc_custodian_of_time' WHERE `entry`=20129;
UPDATE `creature_template` SET `ScriptName`='npc_marin_noggenfogger' WHERE `entry`=7564;
UPDATE `creature_template` SET `ScriptName`='npc_steward_of_time' WHERE `entry`=20142;
UPDATE `creature_template` SET `ScriptName`='npc_stone_watcher_of_norgannon' WHERE `entry`=7918;
UPDATE `creature_template` SET `ScriptName`='npc_OOX17' WHERE `entry`=7784;
UPDATE `creature_template` SET `ScriptName`='npc_tooga' WHERE `entry`=5955;

/* TELDRASSIL */
UPDATE `creature_template` SET `ScriptName`='npc_mist' WHERE `entry`=3568;

/* TEMPEST KEEP */

/* THE MECHANAR */
UPDATE `creature_template` SET `ScriptName`='boss_gatewatcher_iron_hand' WHERE `entry`=19710;
UPDATE `creature_template` SET `ScriptName`='boss_nethermancer_sepethrea' WHERE `entry`=19221;
UPDATE `creature_template` SET `ScriptName`='mob_ragin_flames' WHERE `entry`=20481;
UPDATE `creature_template` SET `ScriptName`='boss_pathaleon_the_calculator' WHERE `entry`=19220;
UPDATE `creature_template` SET `ScriptName`='mob_nether_wraith' WHERE `entry`=21062;
UPDATE `instance_template` SET `script`='instance_mechanar' WHERE `map`=554;

/* THE BOTANICA */
UPDATE `creature_template` SET `ScriptName`='boss_high_botanist_freywinn' WHERE `entry`=17975;
UPDATE `creature_template` SET `ScriptName`='boss_laj' WHERE `entry`=17980;
UPDATE `creature_template` SET `ScriptName`='boss_warp_splinter' WHERE `entry`=17977;
UPDATE `creature_template` SET `ScriptName`='mob_warp_splinter_treant' WHERE `entry`=19949;

/* THE ARCATRAZ */
UPDATE `instance_template` SET `script`='instance_arcatraz' WHERE `map`=552;
UPDATE `creature_template` SET `ScriptName`='mob_zerekethvoidzone' WHERE `entry`=21101;
UPDATE `creature_template` SET `ScriptName`='boss_harbinger_skyriss' WHERE `entry`=20912;
UPDATE `creature_template` SET `ScriptName`='boss_harbinger_skyriss_illusion' WHERE `entry` IN (21466,21467);
UPDATE `creature_template` SET `ScriptName`='npc_warden_mellichar' WHERE `entry`=20904;
UPDATE `creature_template` SET `ScriptName`='npc_millhouse_manastorm' WHERE `entry`=20977;

/* THE EYE */
UPDATE `instance_template` SET `script`='instance_the_eye' WHERE `map`=550;
UPDATE `gameobject_template` SET `ScriptName`='go_kael_orb' WHERE `entry`=188173;
UPDATE `gameobject_template` SET `ScriptName`='go_movie_orb' WHERE `entry`=187578;
/* The Eye Trash Mobs */
UPDATE `creature_template` SET `ScriptName`='mob_crystalcore_devastator' WHERE `entry`=20040;
/* Void Reaver event */
UPDATE `creature_template` SET `ScriptName`='boss_void_reaver' WHERE `entry`=19516;
/* Astromancer event */
UPDATE `creature_template` SET `ScriptName`='boss_high_astromancer_solarian' WHERE `entry`=18805;
UPDATE `creature_template` SET `ScriptName`='mob_solarium_priest' WHERE `entry`=18806;
/* Kael'thas event */
UPDATE `creature_template` SET `ScriptName`='boss_kaelthas' WHERE `entry`=19622;
UPDATE `creature_template` SET `ScriptName`='boss_thaladred_the_darkener' WHERE `entry`=20064;
UPDATE `creature_template` SET `ScriptName`='boss_lord_sanguinar' WHERE `entry`=20060;
UPDATE `creature_template` SET `ScriptName`='boss_grand_astromancer_capernian' WHERE `entry`=20062;
UPDATE `creature_template` SET `ScriptName`='boss_master_engineer_telonicus' WHERE `entry`=20063;
UPDATE `creature_template` SET `ScriptName`='mob_phoenix_tk' WHERE `entry`=21362;
UPDATE `creature_template` SET `ScriptName`='mob_phoenix_egg_tk' WHERE `entry`=21364;
UPDATE `creature_template` SET `ScriptName`='mob_nether_vapor' WHERE `entry`=21002;
UPDATE `creature_template` SET `ScriptName`='mob_kael_flamestrike' WHERE `entry`=21369;
UPDATE `creature_template` SET `ScriptName`='boss_alar' WHERE `entry`=19514;
UPDATE `creature_template` SET `ScriptName`='mob_ember_of_alar' WHERE `entry`=19551;
UPDATE `creature_template` SET `ScriptName`='mob_flame_patch_alar' WHERE `entry`=20602;

/* TEMPLE OF AHN'QIRAJ */
UPDATE `instance_template` SET `script`='instance_temple_of_ahnqiraj' WHERE `map`=531;
UPDATE `creature_template` SET `ScriptName`='boss_cthun' WHERE `entry`=15727;
UPDATE `creature_template` SET `ScriptName`='boss_skeram' WHERE `entry`=15263;
UPDATE `creature_template` SET `ScriptName`='boss_vem' WHERE `entry`=15544;
UPDATE `creature_template` SET `ScriptName`='boss_yauj' WHERE `entry`=15543;
UPDATE `creature_template` SET `ScriptName`='boss_kri' WHERE `entry`=15511;
UPDATE `creature_template` SET `ScriptName`='boss_sartura' WHERE `entry`=15516;
UPDATE `creature_template` SET `ScriptName`='boss_fankriss' WHERE `entry`=15510;
UPDATE `creature_template` SET `ScriptName`='boss_viscidus' WHERE `entry`=15299;
UPDATE `creature_template` SET `ScriptName`='boss_glob_of_viscidus' WHERE `entry`=15667;
UPDATE `creature_template` SET `ScriptName`='boss_huhuran' WHERE `entry`=15509;
UPDATE `creature_template` SET `ScriptName`='boss_veklor' WHERE `entry`=15276;
UPDATE `creature_template` SET `ScriptName`='boss_veknilash' WHERE `entry`=15275;
UPDATE `creature_template` SET `ScriptName`='boss_ouro' WHERE `entry`=15517;
UPDATE `creature_template` SET `ScriptName`='boss_eye_of_cthun' WHERE `entry`=15589;
UPDATE `creature_template` SET `ScriptName`='mob_sartura_royal_guard' WHERE `entry`=15984;
UPDATE `creature_template` SET `ScriptName`='mob_yauj_brood' WHERE `entry`=15621;
UPDATE `creature_template` SET `ScriptName`='mob_claw_tentacle' WHERE `entry`=15725;
UPDATE `creature_template` SET `ScriptName`='mob_eye_tentacle' WHERE `entry`=15726;
UPDATE `creature_template` SET `ScriptName`='mob_giant_claw_tentacle' WHERE `entry`=15728;
UPDATE `creature_template` SET `ScriptName`='mob_giant_eye_tentacle' WHERE `entry`=15334;
UPDATE `creature_template` SET `ScriptName`='mob_giant_flesh_tentacle' WHERE `entry`=15802;
UPDATE `creature_template` SET `ScriptName`='mob_anubisath_sentinel' WHERE `entry`=15264;

/* TEROKKAR FOREST */
UPDATE `creature_template` SET `ScriptName`='mob_infested_root_walker' WHERE `entry`=22095;
UPDATE `creature_template` SET `ScriptName`='mob_netherweb_victim' WHERE `entry`=22355;
UPDATE `creature_template` SET `ScriptName`='mob_rotting_forest_rager' WHERE `entry`=22307;
UPDATE `creature_template` SET `ScriptName`='npc_floon' WHERE `entry`=18588;
UPDATE `creature_template` SET `ScriptName`='npc_isla_starmane' WHERE `entry`=18760;
UPDATE `creature_template` SET `ScriptName`='mob_unkor_the_ruthless' WHERE `entry`=18262;
UPDATE `creature_template` SET `ScriptName`='npc_slim' WHERE `entry`=19679;
UPDATE `creature_template` SET `ScriptName`='npc_akuno' WHERE `entry`=22377;
UPDATE `creature_template` SET `ScriptName`='npc_skywing' WHERE `entry`=22424;

/* THOUSAND NEEDLES */
UPDATE `creature_template` SET `ScriptName`='npc_kanati' WHERE `entry`=10638;
UPDATE `creature_template` SET `ScriptName`='npc_paoka_swiftmountain' WHERE `entry`=10427;
UPDATE `creature_template` SET `ScriptName`='npc_plucky' WHERE `entry`=6626;
UPDATE `creature_template` SET `ScriptName`='npc_lakota_windsong' WHERE `entry`=10646;
UPDATE `creature_template` SET `ScriptName`='npc_enraged_panther' WHERE `entry`=10992;
UPDATE `gameobject_template` SET `ScriptName`='go_panther_cage' WHERE `entry`=176195;

/* THUNDER BLUFF */
UPDATE `creature_template` SET `ScriptName`='npc_cairne_bloodhoof' WHERE `entry`=3057;

/* TRIAL OF THE CHAMPION */
UPDATE `instance_template` SET `script`='instance_trial_of_the_champion' WHERE `map`=650;
UPDATE `creature_template` SET `ScriptName` = 'generic_vehicleAI_toc5' WHERE `entry` IN (33217,33323,33320,33316,33317,33324,33318,33319,33321,33322);
UPDATE `creature_template` SET `ScriptName`='boss_warrior_toc5' WHERE `entry` IN (34705,35572);
UPDATE `creature_template` SET `ScriptName`='boss_mage_toc5' WHERE `entry` IN (34702,35569);
UPDATE `creature_template` SET `ScriptName`='boss_shaman_toc5' WHERE `entry` IN (35571,34701);
UPDATE `creature_template` SET `ScriptName`='boss_hunter_toc5' WHERE `entry` IN (35570,34657);
UPDATE `creature_template` SET `ScriptName`='boss_rouge_toc5' WHERE `entry` IN (35617,34703);
UPDATE `creature_template` SET `ScriptName`='npc_announcer_toc5' WHERE `entry`IN (35004,35005);
UPDATE `creature_template` SET `ScriptName`='npc_risen_ghoul' WHERE `entry` IN (35545,35564);
UPDATE `creature_template` SET `ScriptName`='boss_black_knight' WHERE `entry`=35451;
UPDATE `creature_template` SET `ScriptName`='boss_eadric' WHERE `entry`=35119;
UPDATE `creature_template` SET `ScriptName`='boss_paletress' WHERE `entry`=34928;
UPDATE `creature_template` SET `ScriptName`='npc_memory' WHERE `entry` IN (35052,35041,35033,35046,35043,35047,35044,35039,35034,35049,35030,34942,35050,35042,35045,35037,35031,35038,35029,35048,35032,35028,35040,35036,35051);
UPDATE `creature_template` SET `ScriptName`='npc_argent_soldier'  WHERE `entry` IN (35309,35305,35307);
UPDATE `creature_template` SET `ScriptName`='npc_black_knight_skeletal_gryphon' WHERE `entry`=35491;
UPDATE `creature_template` SET `AIName`='PassiveAI' WHERE `entry` IN (35332,35330,35328,35327,35331,35329,35325,35314,35326,35323);

/* TRIAL OF THE CRUSADER */
UPDATE `instance_template` SET `script`='instance_trial_of_the_crusader' WHERE `map`=649;
UPDATE `creature_template` SET `scriptname`='npc_announcer_toc10' WHERE `entry`=34816;
UPDATE `creature_template` SET `scriptname`='boss_lich_king_toc' WHERE `entry`=35877;
UPDATE `creature_template` SET `scriptname`='npc_fizzlebang_toc' WHERE `entry`=35458;
UPDATE `creature_template` SET `scriptname`='npc_tirion_toc' WHERE `entry`=34996;
UPDATE `creature_template` SET `scriptname`='npc_garrosh_toc' WHERE `entry`=34995;
UPDATE `creature_template` SET `scriptname`='npc_varian_toc' WHERE `entry`=34990;
UPDATE `creature_template` SET `scriptname`='boss_gormok' WHERE `entry`=34796;
UPDATE `creature_template` SET `scriptname`='mob_snobold_vassal' WHERE `entry`=34800;
UPDATE `creature_template` SET `scriptname`='boss_dreadscale' WHERE `entry`=34799;
UPDATE `creature_template` SET `scriptname`='boss_acidmaw' WHERE `entry`=35144;
UPDATE `creature_template` SET `scriptname`='mob_slime_pool' WHERE `entry`=35176;
UPDATE `creature_template` SET `scriptname`='boss_icehowl' WHERE `entry`=34797;
UPDATE `creature_template` SET `scriptname`='boss_jaraxxus' WHERE `entry`= 34780;
UPDATE `creature_template` SET `scriptname`='mob_legion_flame' WHERE `entry`=34784;
UPDATE `creature_template` SET `scriptname`='mob_infernal_volcano' WHERE `entry`=34813;
UPDATE `creature_template` SET `scriptname`='mob_nether_portal' WHERE `entry`=34825;
UPDATE `creature_template` SET `scriptname`='mob_fel_infernal' WHERE `entry`=34815;
UPDATE `creature_template` SET `scriptname`='mob_mistress_of_pain' WHERE `entry`=34826;
UPDATE `creature_template` SET `scriptname`='boss_toc_champion_controller' WHERE `entry`=34781;
UPDATE `creature_template` SET `scriptname`='mob_toc_warrior' WHERE `entry` IN (34475,34453);
UPDATE `creature_template` SET `scriptname`='mob_toc_mage' WHERE `entry` IN (34468,34449);
UPDATE `creature_template` SET `scriptname`='mob_toc_shaman' WHERE `entry` IN (34470,34444);
UPDATE `creature_template` SET `scriptname`='mob_toc_enh_shaman' WHERE `entry` IN (34463,34455);
UPDATE `creature_template` SET `scriptname`='mob_toc_hunter' WHERE `entry` IN (34467,34448);
UPDATE `creature_template` SET `scriptname`='mob_toc_rogue' WHERE `entry` IN (34472,34454);
UPDATE `creature_template` SET `scriptname`='mob_toc_priest' WHERE `entry` IN (34466,34447);
UPDATE `creature_template` SET `scriptname`='mob_toc_shadow_priest' WHERE `entry` IN (34473,34441);
UPDATE `creature_template` SET `scriptname`='mob_toc_dk' WHERE `entry` IN (34461,34458);
UPDATE `creature_template` SET `scriptname`='mob_toc_paladin' WHERE `entry` IN (34465,34445);
UPDATE `creature_template` SET `scriptname`='mob_toc_retro_paladin' WHERE `entry` IN (34471,34456);
UPDATE `creature_template` SET `scriptname`='mob_toc_druid' WHERE `entry` IN (34469,34459);
UPDATE `creature_template` SET `scriptname`='mob_toc_boomkin' WHERE `entry` IN (34460,34451);
UPDATE `creature_template` SET `scriptname`='mob_toc_warlock' WHERE `entry` IN (34474,34450);
UPDATE `creature_template` SET `scriptname`='mob_toc_pet_warlock' WHERE `entry`=35465;
UPDATE `creature_template` SET `scriptname`='mob_toc_pet_hunter' WHERE `entry`=35610;
UPDATE `creature_template` SET `scriptname`='boss_fjola' WHERE `entry`=34497;
UPDATE `creature_template` SET `scriptname`='boss_eydis' WHERE `entry`=34496;
UPDATE `creature_template` SET `scriptname`='mob_essence_of_twin' WHERE `entry` IN (34567,34568);
UPDATE `creature_template` SET `scriptname`='mob_unleashed_dark' WHERE entry=34628;
UPDATE `creature_template` SET `scriptname`='mob_unleashed_light' WHERE entry=34630;
UPDATE `creature_template` SET `scriptname`='boss_anubarak_trial' WHERE `entry`=34564;
UPDATE `creature_template` SET `ScriptName`='mob_frost_sphere' WHERE `entry`=34606;
UPDATE `creature_template` SET `scriptname`='mob_swarm_scarab' WHERE `entry`=34605;
UPDATE `creature_template` SET `scriptname`='mob_nerubian_burrower' WHERE `entry`=34607;
UPDATE `creature_template` SET `scriptname`='mob_anubarak_spike' WHERE `entry`=34660;

/* TIRISFAL GLADES */
UPDATE `creature_template` SET `ScriptName`='npc_calvin_montague' WHERE `entry`=6784;

/* ULDAMAN */
UPDATE `instance_template` SET `script`='instance_uldaman' WHERE `map`=70;
UPDATE `creature_template` SET `ScriptName`='boss_ironaya' WHERE `entry`=7228;
UPDATE `creature_template` SET `ScriptName`='mob_jadespine_basilisk' WHERE `entry`=4863;
UPDATE `creature_template` SET `ScriptName`='npc_lore_keeper_of_norgannon' WHERE `entry`=7172;
UPDATE `creature_template` SET `ScriptName`='boss_archaedas' WHERE `entry`=2748;
UPDATE `creature_template` SET `ScriptName`='mob_archaedas_minions' WHERE `entry` IN (7309,7077,7076,10120);
UPDATE `creature_template` SET `ScriptName`='mob_stonekeepers' WHERE `entry`=4857;
UPDATE `gameobject_template` SET `ScriptName`='go_altar_of_the_keepers' WHERE `entry`=130511;
UPDATE `gameobject_template` SET `ScriptName`='go_altar_of_archaedas' WHERE `entry`=133234;
UPDATE `gameobject_template` SET `ScriptName`='go_keystone_chamber' WHERE `entry`=124371;

/* ULDUAR */
UPDATE `instance_template` SET `script`='instance_ulduar' WHERE `map`=603;
UPDATE `creature_template` SET `ScriptName`='boss_auriaya' WHERE `entry`=33515;
UPDATE `creature_template` SET `ScriptName`='boss_flame_leviathan' WHERE `entry`=33113;
UPDATE `creature_template` SET `AIName`='TurretAI',`ScriptName`='' WHERE `entry`=33139;
UPDATE `creature_template` SET `ScriptName`='boss_flame_leviathan_seat' WHERE `entry`=33114;
UPDATE `creature_template` SET `ScriptName`='boss_flame_leviathan_defense_turret' WHERE `entry`=33142;
UPDATE `creature_template` SET `ScriptName`='boss_flame_leviathan_overload_device' WHERE `entry`=33143;
UPDATE `creature_template` SET `ScriptName`='boss_flame_leviathan_defense_cannon' WHERE `entry`=33139;
UPDATE `creature_template` SET `ScriptName`='npc_colossus' WHERE `entry`=33237;
UPDATE `creature_template` SET `ScriptName`='npc_pool_of_tar' WHERE `entry`=33090;
UPDATE `creature_template` SET `ScriptName`='boss_ignis' WHERE `entry`=33118;
UPDATE `creature_template` SET `ScriptName`='npc_iron_construct' WHERE `entry`=33121;
UPDATE `creature_template` SET `ScriptName`='npc_scorch_ground' WHERE `entry`=33221;
UPDATE `creature_template` SET `ScriptName`='boss_razorscale' WHERE `entry`=33186;
UPDATE `creature_template` SET `ScriptName`='boss_razorscale_controller' WHERE `entry`=33233;
UPDATE `gameobject_template` SET `ScriptName`='go_razorscale_harpoon' WHERE `entry` IN(194519,194541,194542,194543);
UPDATE `creature_template` SET `ScriptName`='npc_devouring_flame' WHERE `entry`=34188;
UPDATE `creature_template` SET `ScriptName`='npc_mole_machine_trigger' WHERE `entry`=33245;
UPDATE `creature_template` SET `ScriptName`='npc_expedition_commander' WHERE `entry`=33210;
UPDATE `creature_template` SET `ScriptName`='npc_darkrune_guardian' WHERE `entry`=33388;
UPDATE `creature_template` SET `ScriptName`='npc_darkrune_sentinel' WHERE `entry`=33846;
UPDATE `creature_template` SET `ScriptName`='npc_darkrune_watcher' WHERE `entry`=33453;
UPDATE `creature_template` SET `ScriptName`='boss_xt002' WHERE `entry`=33293;
UPDATE `creature_template` SET `ScriptName`='mob_xt002_heart' WHERE `entry`=33329;
UPDATE `creature_template` SET `ScriptName`='mob_scrapbot' WHERE `entry`=33343;
UPDATE `creature_template` SET `ScriptName`='mob_pummeller' WHERE `entry`=33344;
UPDATE `creature_template` SET `ScriptName`='mob_boombot' WHERE `entry`=33346;
UPDATE `creature_template` SET `ScriptName`='mob_void_zone' WHERE `entry`=34001;
UPDATE `creature_template` SET `ScriptName`='mob_life_spark' WHERE `entry`=34004;
UPDATE `creature_template` SET `ScriptName`='boss_steelbreaker' WHERE `entry`=32867;
UPDATE `creature_template` SET `ScriptName`='boss_runemaster_molgeim' WHERE `entry`=32927;
UPDATE `creature_template` SET `ScriptName`='boss_stormcaller_brundir' WHERE `entry`=32857;
UPDATE `creature_template` SET `ScriptName`='mob_lightning_elemental' WHERE `entry`=32958;
UPDATE `creature_template` SET `ScriptName`='mob_rune_of_summoning' WHERE `entry`=33051;
UPDATE `creature_template` SET `ScriptName`= 'mob_rune_of_power' WHERE entry = 33705;
UPDATE `creature_template` SET `ScriptName`='boss_kologarn' WHERE `entry`=32930;
UPDATE `creature_template` SET `ScriptName`='boss_general_vezax' WHERE `entry`=33271;
UPDATE `creature_template` SET `ScriptName`='npc_saronite_vapors' WHERE `entry`=33488;
UPDATE `creature_template` SET `ScriptName`='npc_saronite_animus' WHERE `entry`=33524;
UPDATE `creature_template` SET `ScriptName`='boss_algalon' WHERE `entry`=32871;
UPDATE `creature_template` SET `ScriptName`='mob_collapsing_star' WHERE `entry`=32955;
UPDATE `gameobject_template` SET `ScriptName`='ulduar_teleporter' WHERE `entry`=194569;
UPDATE `creature_template` SET `ScriptName`= 'npc_thorims_hammer' WHERE `entry`=33365;
UPDATE `creature_template` SET `ScriptName`= 'npc_mimirons_inferno' WHERE `entry`=33370;
UPDATE `creature_template` SET `ScriptName`= 'npc_hodirs_fury' WHERE `entry`=33212;
UPDATE `creature_template` SET `ScriptName`= 'npc_freyas_ward' WHERE `entry`=33367;
UPDATE `creature_template` SET `ScriptName`= 'npc_lorekeeper' WHERE `entry`=33686;
UPDATE `creature_template` SET `ScriptName`= 'npc_brann_bronzebeard' WHERE `entry`=33579;
UPDATE `creature_template` SET `ScriptName`= 'npc_freya_ward_summon' WHERE `entry`=34275;
UPDATE `creature_template` SET `ScriptName`= 'npc_mechanolift' WHERE `entry`=33214;
UPDATE `gameobject_template` SET `ScriptName`= 'go_ulduar_tower' WHERE `entry`=194375;
UPDATE `gameobject_template` SET `ScriptName`= 'go_ulduar_tower' WHERE `entry`=194371;
UPDATE `gameobject_template` SET `ScriptName`= 'go_ulduar_tower' WHERE `entry`=194370;
UPDATE `gameobject_template` SET `ScriptName`= 'go_ulduar_tower' WHERE `entry`=194377;
UPDATE `creature_template` SET `ScriptName`='npc_hodir_priest' WHERE `entry` IN (32897,33326,32948,33330);
UPDATE `creature_template` SET `ScriptName`='npc_hodir_shaman' WHERE `entry` IN (33328,32901,33332,32950);
UPDATE `creature_template` SET `ScriptName`='npc_hodir_druid' WHERE `entry` IN (33325,32900,32941,33333);
UPDATE `creature_template` SET `ScriptName`='npc_hodir_mage' WHERE `entry` IN (32893,33327,33331,32946);
UPDATE `creature_template` SET `ScriptName`='npc_toasty_fire' WHERE `entry`=33342;
UPDATE `creature_template` SET `ScriptName`='npc_flash_freeze' WHERE `entry`=32926;
UPDATE `creature_template` SET `ScriptName`='npc_icicle' WHERE `entry` IN (33169,33173);
UPDATE `creature_template` SET `ScriptName`='npc_snowpacked_icicle' WHERE `entry`=33174;
UPDATE `creature_template` SET `ScriptName`='npc_ice_block' WHERE `entry`=32938;
UPDATE `creature_template` SET `ScriptName`='boss_hodir' WHERE `entry`=32845;
UPDATE `creature_template` SET `ScriptName`='boss_freya' WHERE `entry`=32906;
UPDATE `creature_template` SET `ScriptName`='boss_elder_brightleaf' WHERE `entry`=32915;
UPDATE `creature_template` SET `ScriptName`='boss_elder_ironbranch' WHERE `entry`=32913;
UPDATE `creature_template` SET `ScriptName`='boss_elder_stonebark' WHERE `entry`=32914;
UPDATE `creature_template` SET `ScriptName`='npc_ancient_conservator' WHERE `entry`=33203;
UPDATE `creature_template` SET `ScriptName`='npc_snaplasher' WHERE `entry`=32916;
UPDATE `creature_template` SET `ScriptName`='npc_storm_lasher' WHERE `entry`=32919;
UPDATE `creature_template` SET `ScriptName`='npc_ancient_water_spirit' WHERE `entry`=33202;
UPDATE `creature_template` SET `ScriptName`='npc_detonating_lasher' WHERE `entry`=32918;
UPDATE `creature_template` SET `ScriptName`='npc_sun_beam' WHERE `entry`=33170;
UPDATE `creature_template` SET `ScriptName`='npc_nature_bomb' WHERE `entry`=34129;
UPDATE `creature_template` SET `ScriptName`='npc_eonars_gift' WHERE `entry`=33228;
UPDATE `creature_template` SET `ScriptName`='npc_healthy_spore' WHERE `entry`=33215;
UPDATE `creature_template` SET `ScriptName`='npc_unstable_sun_beam' WHERE `entry`=33050;
UPDATE `creature_template` SET `ScriptName`='npc_iron_roots' WHERE `entry` IN (33088,33168);
UPDATE `creature_template` SET `ScriptName`='npc_feral_defender' WHERE `entry`=34035;
UPDATE `creature_template` SET `ScriptName`='npc_sanctum_sentry' WHERE `entry`=34014;
UPDATE `creature_template` SET `ScriptName`='npc_auriaya_seeping_trigger' WHERE `entry` =34098;


/* UN'GORO CRATER */
UPDATE `creature_template` SET `ScriptName`='npc_ame' WHERE `entry`=9623;
UPDATE `creature_template` SET `ScriptName`='npc_ringo' WHERE `entry`=9999;

/* UNDERCITY */
UPDATE `creature_template` SET `ScriptName`='npc_lady_sylvanas_windrunner' WHERE `entry`=10181;
UPDATE `creature_template` SET `ScriptName`='npc_highborne_lamenter' WHERE `entry`=21628;
UPDATE `creature_template` SET `ScriptName`='npc_parqual_fintallas' WHERE `entry`=4488;

/* UTGARDE KEEP */
UPDATE `creature_template` SET `scriptname`='boss_keleseth' WHERE `entry`=23953;
UPDATE `creature_template` SET `scriptname`='mob_frost_tomb' WHERE `entry`=23965;
UPDATE `instance_template` SET `script`='instance_utgarde_keep' WHERE `map`=574;
UPDATE `creature_template` SET `ScriptName`='mob_vrykul_skeleton' WHERE `entry`=23970;
UPDATE `creature_template` SET `ScriptName`='boss_skarvald_the_constructor' WHERE `entry` IN (24200,27390);
UPDATE `creature_template` SET `ScriptName`='boss_dalronn_the_controller' WHERE `entry` IN (24201,27389);
UPDATE `creature_template` SET `ScriptName`='boss_ingvar_the_plunderer' WHERE `entry`=23954;
UPDATE `creature_template` SET `ScriptName`='mob_annhylde_the_caller' WHERE `entry`=24068;
UPDATE `creature_template` SET `ScriptName`='mob_ingvar_throw_dummy' WHERE `entry`=23997;
UPDATE `creature_template` SET `ScriptName`='npc_dragonflayer_forge_master' WHERE `entry`=24079;

/* UTGARDE PINNACLE */
UPDATE `creature_template` SET `ScriptName`='boss_svala_sorrowgrave' WHERE `entry`=26668;
UPDATE `creature_template` SET `ScriptName`='mob_ritual_channeler' WHERE `entry`=27281;
UPDATE `creature_template` SET `ScriptName`='boss_svala' WHERE `entry`=29281;
UPDATE `creature_template` SET `ScriptName`='boss_palehoof' WHERE `entry`=26687;
UPDATE `creature_template` SET `ScriptName`='mob_palehoof_orb' WHERE `entry`=26688;
UPDATE `creature_template` SET `ScriptName`='boss_skadi' WHERE `entry`=26693;
UPDATE `creature_template` SET `ScriptName`='boss_ymiron' WHERE `entry`=26861;
UPDATE `creature_template` SET `ScriptName`='mob_frenzied_worgen' WHERE `entry`=26683;
UPDATE `creature_template` SET `ScriptName`='mob_ravenous_furbolg' WHERE `entry`=26684;
UPDATE `creature_template` SET `ScriptName`='mob_massive_jormungar' WHERE `entry`=26685;
UPDATE `creature_template` SET `ScriptName`='mob_ferocious_rhino' WHERE `entry`=26686;
UPDATE `creature_template` SET `ScriptName`='mob_palehoof_orb' WHERE `entry`=26688;
UPDATE `instance_template` SET `script`='instance_utgarde_pinnacle' WHERE `map`=575;
UPDATE `gameobject_template` SET `ScriptName`='go_palehoof_sphere'WHERE `entry`=188593;

/* VAULT OF ARCHAVON */
UPDATE `creature_template` SET `ScriptName`='boss_archavon' WHERE `entry`=31125;
UPDATE `creature_template` SET `ScriptName`='mob_archavon_warder' WHERE `entry`=32353;
UPDATE `creature_template` SET `ScriptName`='boss_emalon' WHERE `entry`=33993;
UPDATE `creature_template` SET `ScriptName`='mob_tempest_minion' WHERE `entry`=33998;
UPDATE `creature_template` SET `ScriptName`='boss_koralon' WHERE `entry`=35013;
UPDATE `creature_template` SET `ScriptName`='mob_flame_warder' WHERE `entry`=35143;
UPDATE `creature_template` SET `ScriptName`='boss_toravon' WHERE `entry`=38433;
UPDATE `creature_template` SET `ScriptName`='mob_frost_warder' WHERE `entry`=38482;
UPDATE `creature_template` SET `ScriptName`='mob_frozen_orb_stalker' WHERE `entry`=38461;
UPDATE `creature_template` SET `ScriptName`='mob_frozen_orb' WHERE `entry`=38456;
UPDATE `instance_template` SET `script`='instance_archavon' WHERE `map`=624;

/* VIOLET HOLD */
UPDATE `creature_template` SET `ScriptName`='npc_sinclari_vh' WHERE `entry`=30658;
UPDATE `creature_template` SET `ScriptName`='npc_teleportation_portal_vh' WHERE `entry`=31011;
UPDATE `creature_template` SET `ScriptName`='boss_lavanthor' WHERE `entry`=29312;
UPDATE `creature_template` SET `ScriptName`='boss_ichoron' WHERE `entry`=29313;
UPDATE `creature_template` SET `ScriptName`='mob_ichor_globule' WHERE `entry`=29321;
UPDATE `creature_template` SET `ScriptName`='boss_zuramat' WHERE `entry`=29314;
UPDATE `creature_template` SET `ScriptName`='boss_erekem' WHERE `entry`=29315;
UPDATE `creature_template` SET `ScriptName`='mob_erekem_guard' WHERE `entry`=29395;
UPDATE `creature_template` SET `ScriptName`='boss_moragg' WHERE `entry`=29316;
UPDATE `creature_template` SET `ScriptName`='boss_xevozz' WHERE `entry`=29266;
UPDATE `creature_template` SET `ScriptName`='mob_ethereal_sphere' WHERE `entry`=29271;
UPDATE `creature_template` SET `ScriptName`='boss_cyanigosa' WHERE `entry`=31134;
update `creature_template` SET `scriptname`='mob_azure_invader' WHERE `entry`=30661; 
update `creature_template` SET `scriptname`='mob_azure_spellbreaker' WHERE `entry`=30662;
update `creature_template` SET `scriptname`='mob_azure_binder' WHERE `entry`=30663;
update `creature_template` SET `scriptname`='mob_azure_mage_slayer' WHERE `entry`=30664;
update `creature_template` SET `scriptname`='mob_azure_captain' WHERE `entry`=30666;
update `creature_template` SET `scriptname`='mob_azure_sorceror' WHERE `entry`=30667;
update `creature_template` SET `scriptname`='mob_azure_raider' WHERE `entry`=30668;
update `creature_template` SET `scriptname`='mob_azure_stalker' WHERE `entry`=32191;
update `creature_template` SET `scriptname`='mob_azure_invader' WHERE `entry`=30961;
update `creature_template` SET `scriptname`='mob_azure_spellbreaker' WHERE `entry`=30962;
update `creature_template` SET `scriptname`='mob_azure_binder' WHERE `entry`=30918;
update `creature_template` SET `scriptname`='mob_azure_mage_slayer' WHERE `entry`=30963;
UPDATE `creature_template` SET `scriptname`='mob_azure_saboteur' WHERE `entry`=31079;
UPDATE `instance_template` SET `script`='instance_violet_hold' WHERE `map`=608;

/* WAILING CAVERNS */
UPDATE `creature_template` SET `ScriptName`='npc_disciple_of_naralex' WHERE entry=3678;
UPDATE `instance_template` SET `script`='instance_wailing_caverns' WHERE map=43;

/* WESTERN PLAGUELANDS */
UPDATE `creature_template` SET `ScriptName`='npcs_dithers_and_arbington' WHERE `entry` IN (11056,11057);
UPDATE `creature_template` SET `ScriptName`='npc_the_scourge_cauldron' WHERE `entry`=11152;
UPDATE `creature_template` SET `ScriptName`='npc_myranda_the_hag' WHERE `entry`=11872;
UPDATE `creature_template` SET `ScriptName`='npc_andorhal_tower' WHERE `entry` IN (10902,10903,10904,10905);
UPDATE `creature_template` SET `ScriptName`='npc_anchorite_truuen' WHERE `entry`=17238;

/* WESTFALL */
UPDATE `creature_template` SET `ScriptName`='npc_defias_traitor' WHERE `entry`=467;
UPDATE `creature_template` SET `ScriptName`='npc_daphne_stilwell' WHERE `entry`=6182;

/* WETLANDS */
UPDATE `creature_template` SET `ScriptName`='npc_tapoke_slim_jahn' WHERE `entry`=4962;
UPDATE `creature_template` SET `ScriptName`='npc_mikhail' WHERE `entry`=4963;

/* WINTERSPRING */
UPDATE `creature_template` SET `ScriptName`='npc_lorax' WHERE `entry`=10918;
UPDATE `creature_template` SET `ScriptName`='npc_rivern_frostwind' WHERE `entry`=10618;
UPDATE `creature_template` SET `ScriptName`='npc_witch_doctor_mauari' WHERE `entry`=10307;

/* ZANGARMARSH */
UPDATE `creature_template` SET `ScriptName`='npcs_ashyen_and_keleth' WHERE `entry` IN (17900,17901);
UPDATE `creature_template` SET `ScriptName`='npc_cooshcoosh' WHERE `entry`=18586;
UPDATE `creature_template` SET `ScriptName`='npc_elder_kuruti' WHERE `entry`=18197;
UPDATE `creature_template` SET `ScriptName`='npc_mortog_steamhead' WHERE `entry`=23373;
UPDATE `creature_template` SET `ScriptName`='npc_kayra_longmane' WHERE `entry`=17969;
UPDATE `creature_template` SET `ScriptName`='npc_timothy_daniels' WHERE `entry`=18019;
UPDATE `gameobject_template` SET `ScriptName`='go_southfury_moonstone' WHERE `entry`=185566;

/* ZUL'AMAN */
UPDATE `instance_template` SET `script`='instance_zulaman' WHERE `map`=568;
UPDATE `creature_template` SET `ScriptName`='boss_janalai' WHERE `entry`=23578;
UPDATE `creature_template` SET `ScriptName`='boss_nalorakk' WHERE `entry`=23576;
UPDATE `creature_template` SET `ScriptName`='mob_janalai_firebomb' WHERE `entry`=23920;
UPDATE `creature_template` SET `ScriptName`='mob_janalai_hatcher' WHERE `entry`=23818;
UPDATE `creature_template` SET `ScriptName`='mob_janalai_hatchling' WHERE `entry`=23598;
UPDATE `creature_template` SET `ScriptName`='mob_janalai_egg' WHERE `entry`=23817;
UPDATE `creature_template` SET `ScriptName`='npc_forest_frog' WHERE `entry`=24396;
UPDATE `creature_template` SET `ScriptName`='boss_akilzon' WHERE `entry`=23574;
UPDATE `creature_template` SET `ScriptName`='mob_akilzon_eagle' WHERE `entry`=24858;
UPDATE `creature_template` SET `ScriptName`='boss_halazzi' WHERE `entry`=23577;
UPDATE `creature_template` SET `ScriptName`='mob_halazzi_lynx' WHERE `entry`=24143;
UPDATE `creature_template` SET `ScriptName`='boss_hexlord_malacrass' WHERE `entry`=24239;
UPDATE `creature_template` SET `ScriptName`='boss_alyson_antille' WHERE `entry`=24240;
UPDATE `creature_template` SET `ScriptName`='boss_thurg' WHERE `entry`=24241;
UPDATE `creature_template` SET `ScriptName`='boss_slither' WHERE `entry`=24242;
UPDATE `creature_template` SET `ScriptName`='boss_lord_raadan' WHERE `entry`=24243;
UPDATE `creature_template` SET `ScriptName`='boss_gazakroth' WHERE `entry`=24244;
UPDATE `creature_template` SET `ScriptName`='boss_fenstalker' WHERE `entry`=24245;
UPDATE `creature_template` SET `ScriptName`='boss_darkheart' WHERE `entry`=24246;
UPDATE `creature_template` SET `ScriptName`='boss_koragg' WHERE `entry`=24247;
UPDATE `creature_template` SET `ScriptName`='boss_zuljin' WHERE `entry`=23863;
UPDATE `creature_template` SET `ScriptName`='do_nothing' WHERE `entry`=24187;
UPDATE `creature_template` SET `ScriptName`='mob_zuljin_vortex' WHERE `entry`=24136;
UPDATE `creature_template` SET `ScriptName`='npc_zulaman_hostage' WHERE `entry` IN (23790,23999,24024,24001);
UPDATE `creature_template` SET `ScriptName`='mob_mojo' WHERE `entry`=24480;

/* ZUL'DRAK */
UPDATE `creature_template` SET `ScriptName`='npc_captured_rageclaw' WHERE `entry`=29686;
UPDATE `creature_template` SET `ScriptName`='npc_drakuru_shackles' WHERE `entry`=29700;
UPDATE `creature_template` SET `ScriptName`='npc_gymer' WHERE `entry`=29647;
UPDATE `creature_template` SET `ScriptName`='npc_gurgthock' WHERE `entry`=30007;
UPDATE `creature_template` SET `ScriptName`='npc_orinoko_tuskbreaker' WHERE `entry`=30020;
UPDATE `creature_template` SET `ScriptName`='npc_korrak_bloodrager' WHERE `entry`=30023;
UPDATE `creature_template` SET `ScriptName`='npc_yggdras' WHERE `entry`=30014;
UPDATE `creature_template` SET `ScriptName`='npc_released_offspring_harkoa' WHERE `entry`=28526;
UPDATE `creature_template` SET `ScriptName`='npc_stinkbeard' WHERE `entry`=30017;
UPDATE `creature_template` SET `ScriptName`='npc_crusade_recruit' WHERE `entry`=28090;
UPDATE `gameobject_template` SET `ScriptName`='go_scourge_enclosure' WHERE `entry`=191548;
UPDATE `creature_template` SET `ScriptName`='npc_elemental_lord' WHERE `entry` IN (30024,30025,30019,30026);
UPDATE `creature_template` SET `ScriptName`='npc_fiend_elemental' WHERE `entry` IN (30044,30042,30043,30045);

/* ZUL'FARRAK */
UPDATE `creature_template` SET `ScriptName`='npc_sergeant_bly' WHERE `entry`=7604;
UPDATE `creature_template` SET `ScriptName`='npc_weegli_blastfuse' WHERE `entry`=7607;
UPDATE `gameobject_template` SET `ScriptName`='go_shallow_grave' WHERE `entry` IN (128308,128403);
INSERT IGNORE INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES(962, 'at_zumrah');
UPDATE `gameobject_template` SET `ScriptName`='go_table_theka' WHERE `entry`=142715;
UPDATE `gameobject_template` SET `ScriptName`='go_troll_cage' WHERE `entry`>= 141070 AND `entry`< 141075;
UPDATE `instance_template` SET `script`='instance_zulfarrak' WHERE `map`=209;

/* ZUL'GURUB */
UPDATE `instance_template` SET `script`='instance_zulgurub' WHERE `map`=309;
UPDATE `creature_template` SET `ScriptName`='boss_jeklik' WHERE `entry`=14517;
UPDATE `creature_template` SET `ScriptName`='boss_venoxis' WHERE `entry`=14507;
UPDATE `creature_template` SET `ScriptName`='boss_marli' WHERE `entry`=14510;
UPDATE `creature_template` SET `ScriptName`='boss_mandokir' WHERE `entry`=11382;
UPDATE `creature_template` SET `ScriptName`='boss_gahzranka' WHERE `entry`=15114;
UPDATE `creature_template` SET `ScriptName`='boss_jindo' WHERE `entry`=11380;
UPDATE `creature_template` SET `ScriptName`='boss_hakkar' WHERE `entry`=14834;
UPDATE `creature_template` SET `ScriptName`='boss_thekal' WHERE `entry`=14509;
UPDATE `creature_template` SET `ScriptName`='boss_arlokk' WHERE `entry`=14515;
UPDATE `gameobject_template` SET `ScriptName`='go_gong_of_bethekk' WHERE `entry`=180526;
UPDATE `creature_template` SET `ScriptName`='boss_grilek' WHERE `entry`=15082;
UPDATE `creature_template` SET `ScriptName`='boss_hazzarah' WHERE `entry`=15083;
UPDATE `creature_template` SET `ScriptName`='boss_renataki' WHERE `entry`=15084;
UPDATE `creature_template` SET `ScriptName`='boss_wushoolay' WHERE `entry`=15085;
UPDATE `creature_template` SET `ScriptName`='mob_zealot_lorkhan' WHERE `entry`=11347;
UPDATE `creature_template` SET `ScriptName`='mob_zealot_zath' WHERE `entry`=11348;
UPDATE `creature_template` SET `ScriptName`='mob_healing_ward' WHERE `entry`=14987;
UPDATE `creature_template` SET `ScriptName`='mob_spawn_of_marli' WHERE `entry`=15041;
UPDATE `creature_template` SET `ScriptName`='mob_batrider' WHERE `entry`=14965;
UPDATE `creature_template` SET `ScriptName`='mob_shade_of_jindo' WHERE `entry`=14986;
UPDATE `creature_template` SET `ScriptName`='mob_ohgan' WHERE `entry`=14988;

DELETE FROM `areatrigger_scripts` WHERE `entry`=3066;
INSERT INTO `areatrigger_scripts` VALUES
   (3066,'at_ravenholdt');

/* Moved from world_spell_full.sql to here. */
UPDATE `creature_template` SET `AIName`='TurretAI',`ScriptName`='' WHERE `entry`=33139;
UPDATE `creature_template` SET `ScriptName`= 'boss_kologarn' WHERE `entry`=32930;
UPDATE `creature_template` SET `ScriptName`= 'boss_flame_leviathan_safety_container' WHERE `entry`=33218;

/* BATTLEGROUNDS */
/* TODO */

/* OUTDOOR PVP */
UPDATE `outdoorpvp_template` SET `ScriptName`='outdoorpvp_hp' WHERE `TypeId`=1;
UPDATE `outdoorpvp_template` SET `ScriptName`='outdoorpvp_na' WHERE `TypeId`=2;
UPDATE `outdoorpvp_template` SET `ScriptName`='outdoorpvp_tf' WHERE `TypeId`=3;
UPDATE `outdoorpvp_template` SET `ScriptName`='outdoorpvp_zm' WHERE `TypeId`=4;
UPDATE `outdoorpvp_template` SET `ScriptName`='outdoorpvp_si' WHERE `TypeId`=5;
UPDATE `outdoorpvp_template` SET `ScriptName`='outdoorpvp_ep' WHERE `TypeId`=6;

/* ACHIEVEMENTS */
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (3693,3804,3805,3806,3807,3808,3809,3810,3811,3812,3813,1234,1239,5605,5606,12778,13036,13035,13037,12977,12967,12986,12982,12993,12780,13012,13011,13013,12062,12063,12064,12065,12183,12068,12060,12061,12822,12996,12972,12989,10062,10063,10054,10055,10046,10047,10048,10049,10050,10051,10044,10045,6446,7625,7628,5541,5542,5543,7573,7574,7265,7549,12971,12978,12979,12980,7598,7587,7264,7548,10068,10069,10173,10306,10451,10462,10447,10448,10449,10459,10460,10461,7316,7317,7318,7583,4240,6803,7319,7577,7320,7590,7361) AND `type` IN (0,11);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(3693,11,0,0, 'achievement_storm_glory'),
(3804,11,0,0, 'achievement_resilient_victory'),
(3805,11,0,0, 'achievement_resilient_victory'),
(3806,11,0,0, 'achievement_resilient_victory'),
(3807,11,0,0, 'achievement_resilient_victory'),
(3808,11,0,0, 'achievement_resilient_victory'),
(3809,11,0,0, 'achievement_resilient_victory'),
(3810,11,0,0, 'achievement_resilient_victory'),
(3811,11,0,0, 'achievement_resilient_victory'),
(3812,11,0,0, 'achievement_resilient_victory'),
(3813,11,0,0, 'achievement_resilient_victory'),
(1234,11,0,0, 'achievement_bg_control_all_nodes'),
(1239,11,0,0, 'achievement_bg_control_all_nodes'),
(5605,11,0,0, 'achievement_save_the_day'),
(5606,11,0,0, 'achievement_save_the_day'),
(6800,11,0,0, 'achievement_sickly_gazelle'),
(12993,11,0,0, 'achievement_doesnt_go_to_eleven'),
(12778,11,0,0, 'achievement_ive_gone_and_made_a_mess'),
(13036,11,0,0, 'achievement_ive_gone_and_made_a_mess'),
(13035,11,0,0, 'achievement_ive_gone_and_made_a_mess'),
(13037,11,0,0, 'achievement_ive_gone_and_made_a_mess'),
(12977,11,0,0, 'achievement_flu_shot_shortage'),
(12967,11,0,0, 'achievement_flu_shot_shortage'),
(12986,11,0,0, 'achievement_flu_shot_shortage'),
(12982,11,0,0, 'achievement_flu_shot_shortage'),
(12780,11,0,0, 'achievement_once_bitten_twice_shy_n'),
(13012,11,0,0, 'achievement_once_bitten_twice_shy_n'),
(13011,11,0,0, 'achievement_once_bitten_twice_shy_v'),
(13013,11,0,0, 'achievement_once_bitten_twice_shy_v'),
(12062,11,0,0, 'achievement_bg_control_all_nodes'),
(12063,11,0,0, 'achievement_bg_control_all_nodes'),
(12064,11,0,0, 'achievement_bg_control_all_nodes'),
(12065,11,0,0, 'achievement_bg_control_all_nodes'),
(12183,11,0,0, 'achievement_bg_ic_glaive_grave'),
(12068,11,0,0, 'achievement_bg_ic_mowed_down'),
(12060,11,0,0, 'achievement_bg_ic_resource_glut'),
(12061,11,0,0, 'achievement_bg_ic_resource_glut'),
(12822,11,0,0, 'achievement_all_you_can_eat'),
(12996,11,0,0, 'achievement_all_you_can_eat'),
(12972,11,0,0, 'achievement_all_you_can_eat'),
(12989,11,0,0, 'achievement_all_you_can_eat'),
(10044,11,0,0, 'achievement_unbroken'),
(10045,11,0,0, 'achievement_unbroken'),
(10054,11,0,0, 'achievement_shutout'),
(10055,11,0,0, 'achievement_shutout'),
(10046,11,0,0, 'achievement_three_car_garage_chopper'),
(10047,11,0,0, 'achievement_three_car_garage_siege'),
(10048,11,0,0, 'achievement_three_car_garage_demolisher'),
(10049,11,0,0, 'achievement_three_car_garage_chopper'),
(10050,11,0,0, 'achievement_three_car_garage_siege'),
(10051,11,0,0, 'achievement_three_car_garage_demolisher'),
(10062,11,0,0, 'achievement_quick_shave'),
(10063,11,0,0, 'achievement_quick_shave'),
(7625,11,0,0, 'achievement_bg_sa_artillery'),
(7628,11,0,0, 'achievement_bg_sa_artillery'),
(5541,11,0,0,'achievement_arena_2v2_kills'),
(5542,11,0,0,'achievement_arena_3v3_kills'),
(5543,11,0,0,'achievement_arena_5v5_kills'),
(7573,11,0,0,'achievement_denyin_the_scion'),
(7574,11,0,0,'achievement_denyin_the_scion'),
(7265,11,0,0,'achievement_momma_said_knock_you_out'),
(7549,11,0,0,'achievement_momma_said_knock_you_out'),
(12978,11,0,0,'achievement_portal_jockey'),
(12979,11,0,0,'achievement_portal_jockey'),
(12971,11,0,0,'achievement_portal_jockey'),
(12980,11,0,0,'achievement_portal_jockey'),
(7598,11,0,0,'achievement_kings_bane'),
(7587,11,0,0,'achievement_void_dance'),
(7264,11,0,0,'achievement_safety_dance'),
(7548,11,0,0,'achievement_safety_dance'),
(10068,11,0,0,'achievement_ignis_shattered'),
(10069,11,0,0,'achievement_ignis_shattered'),
(10173,11,0,0,'achievement_shadowdodger'),
(10306,11,0,0,'achievement_shadowdodger'),
(10451,11,0,0,'achievement_smell_saronite'),
(10462,11,0,0,'achievement_smell_saronite'),
(10447,11,0,0,'achievement_knock_on_wood'),
(10448,11,0,0,'achievement_knock_knock_on_wood'),
(10449,11,0,0,'achievement_knock_knock_knock_on_wood'),
(10459,11,0,0,'achievement_knock_on_wood'),
(10460,11,0,0,'achievement_knock_knock_on_wood'),
(10461,11,0,0,'achievement_knock_knock_knock_on_wood'),
(10445,11,0,0,'achievement_getting_back_to_nature'),
(10758,11,0,0,'achievement_getting_back_to_nature'),
(7317,11,0,0,'achievement_respect_your_elders'),
(7318,11,0,0,'achievement_king_dred'),
(7316,11,0,0,'achievement_chaos_theory'),
(7583,11,0,0,'achievement_share_the_love'),
(4240,11,0,0,'achievement_watch_him_die'),
(6803,11,0,0,'achievement_defenseless'),
(7319,11,0,0,'achievement_less_rabi'),
(7577,11,0,0,'achievement_split_personality'),
(7320,11,0,0,'achievement_dehydration'),
(7590,11,0,0,'achievement_brann_sparklin_news'),
(7361,11,0,0,'achievement_oh_novos');

/* SPELLS */
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
-- generic
( 66218, 'spell_gen_launch'),
( 39228, 'spell_gen_absorb0_hitlimit1'),
( 60218, 'spell_gen_absorb0_hitlimit1'),
(  6962, 'spell_gen_pet_summoned'),
( 24750, 'spell_gen_trick'),
( 24751, 'spell_gen_trick_or_treat'),
( 29266, 'spell_creature_permanent_feign_death'),
( 31261, 'spell_creature_permanent_feign_death'),
( 41337, 'spell_gen_aura_of_anger'),
( 45472, 'spell_gen_parachute'),
( 46394, 'spell_gen_burn_brutallus'),
( 57685, 'spell_creature_permanent_feign_death'),
( 58601, 'spell_gen_remove_flight_auras'),
( 58951, 'spell_creature_permanent_feign_death'),
( 70592, 'spell_creature_permanent_feign_death'),
( 70628, 'spell_creature_permanent_feign_death'),
( 74490, 'spell_creature_permanent_feign_death'),
( 72752, 'spell_pvp_trinket_wotf_shared_cd'),
( 72757, 'spell_pvp_trinket_wotf_shared_cd'),
( 46221, 'spell_gen_animal_blood'),
( 70769, 'spell_gen_divine_storm_cd_reset'),
( 58630, 'spell_gen_dungeon_credit'),
( 59046, 'spell_gen_dungeon_credit'),
( 59450, 'spell_gen_dungeon_credit'),
( 61863, 'spell_gen_dungeon_credit'),
( 64899, 'spell_gen_dungeon_credit'),
( 64985, 'spell_gen_dungeon_credit'),
( 65074, 'spell_gen_dungeon_credit'),
( 65195, 'spell_gen_dungeon_credit'),
( 68184, 'spell_gen_dungeon_credit'),
( 68572, 'spell_gen_dungeon_credit'),
( 68574, 'spell_gen_dungeon_credit'),
( 68663, 'spell_gen_dungeon_credit'),
( 72706, 'spell_gen_dungeon_credit'),
( 72830, 'spell_gen_dungeon_credit'),
( 72959, 'spell_gen_dungeon_credit'),
( 60893, 'spell_gen_profession_research'),
( 61177, 'spell_gen_profession_research'),
( 61288, 'spell_gen_profession_research'),
( 61756, 'spell_gen_profession_research'),
( 45785, 'spell_generic_clone'),
( 49889, 'spell_generic_clone'),
( 50218, 'spell_generic_clone'),
( 51719, 'spell_generic_clone'),
( 57528, 'spell_generic_clone'),
( 69828, 'spell_generic_clone'),
( 41055, 'spell_generic_clone_weapon'),
( 63416, 'spell_generic_clone_weapon'),
( 69891, 'spell_generic_clone_weapon'),
( 45206, 'spell_generic_clone_weapon'),
( 69892, 'spell_generic_clone_weapon'),
( 57593, 'spell_generic_clone_weapon'),
( 52408, 'spell_gen_seaforium_blast'),
( 25281, 'spell_gen_turkey_marker'),
(-55428, 'spell_gen_lifeblood'),
( 65917, 'spell_gen_magic_rooster'),
( 4073,  'spell_gen_allow_cast_from_item_only'),
( 19804, 'spell_gen_allow_cast_from_item_only'),
( 12749, 'spell_gen_allow_cast_from_item_only'),
( 13258, 'spell_gen_allow_cast_from_item_only'),
( 13166, 'spell_gen_allow_cast_from_item_only'),
 (65266, 'spell_gen_vehicle_scaling'),
 (65635, 'spell_gen_vehicle_scaling'),
 (65636, 'spell_gen_vehicle_scaling'),
 (66666, 'spell_gen_vehicle_scaling'),
 (66667, 'spell_gen_vehicle_scaling'),
 (66668, 'spell_gen_vehicle_scaling'),
-- instances
-- Black Temple
( 41475, 'spell_boss_lady_malande_shield'),
-- Forge of Souls
( 68793, 'spell_bronjahm_magic_bane'),
( 69050, 'spell_bronjahm_magic_bane'),
( 68861, 'spell_bronjahm_consume_soul'),
( 69008, 'spell_bronjahm_soulstorm_channel'),
( 68870, 'spell_bronjahm_soulstorm_visual'),
( 68921, 'spell_bronjahm_soulstorm_targeting'),
( 69049, 'spell_bronjahm_soulstorm_targeting'),
-- Pit of Saron
( 68786, 'spell_garfrost_permafrost'),
( 70336, 'spell_garfrost_permafrost'),
( 69012, 'spell_krick_explosive_barrage'),
( 69263, 'spell_ick_explosive_barrage'),
( 44851, 'spell_exploding_orb_hasty_grow'),
( 68987, 'spell_krick_pursuit'),
( 69029, 'spell_krick_pursuit_confusion'),
( 70850, 'spell_krick_pursuit_confusion'),
( 69275, 'spell_tyrannus_mark_of_rimefang'),
( 69172, 'spell_tyrannus_overlord_brand'),
( 70292, 'spell_trash_mob_glacial_strike'),
-- Icecrown Citadel
( 69057, 'spell_marrowgar_bone_spike_graveyard'),
( 70826, 'spell_marrowgar_bone_spike_graveyard'),
( 72088, 'spell_marrowgar_bone_spike_graveyard'),
( 72089, 'spell_marrowgar_bone_spike_graveyard'),
( 69140, 'spell_marrowgar_coldflame'),
( 72705, 'spell_marrowgar_coldflame'),
( 69146, 'spell_marrowgar_coldflame_damage'),
( 70823, 'spell_marrowgar_coldflame_damage'),
( 70824, 'spell_marrowgar_coldflame_damage'),
( 70825, 'spell_marrowgar_coldflame_damage'),
( 69075, 'spell_marrowgar_bone_storm'),
( 70834, 'spell_marrowgar_bone_storm'),
( 70835, 'spell_marrowgar_bone_storm'),
( 70836, 'spell_marrowgar_bone_storm'),
( 70842, 'spell_deathwhisper_mana_barrier'),
( 70903, 'spell_cultist_dark_martyrdom'),
( 72498, 'spell_cultist_dark_martyrdom'),
( 72499, 'spell_cultist_dark_martyrdom'),
( 72500, 'spell_cultist_dark_martyrdom'),
( 71236, 'spell_cultist_dark_martyrdom'),
( 72495, 'spell_cultist_dark_martyrdom'),
( 72496, 'spell_cultist_dark_martyrdom'),
( 72497, 'spell_cultist_dark_martyrdom'),
( 72864, 'spell_frost_giant_death_plague'),
( 72202, 'spell_deathbringer_blood_link'),
( 72178, 'spell_deathbringer_blood_link_aura'),
( 72371, 'spell_deathbringer_blood_power'),
( 72409, 'spell_deathbringer_rune_of_blood'),
( 72447, 'spell_deathbringer_rune_of_blood'),
( 72448, 'spell_deathbringer_rune_of_blood'),
( 72449, 'spell_deathbringer_rune_of_blood'),
( 72380, 'spell_deathbringer_blood_nova'),
( 72438, 'spell_deathbringer_blood_nova'),
( 72439, 'spell_deathbringer_blood_nova'),
( 72440, 'spell_deathbringer_blood_nova'),
( 72378, 'spell_deathbringer_blood_nova_targeting'),
( 73058, 'spell_deathbringer_blood_nova_targeting'),
( 72385, 'spell_deathbringer_boiling_blood'),
( 72441, 'spell_deathbringer_boiling_blood'),
( 72442, 'spell_deathbringer_boiling_blood'),
( 72443, 'spell_deathbringer_boiling_blood'),
( 72155, 'spell_icc_harvest_blight_specimen'),
( 72162, 'spell_icc_harvest_blight_specimen'),
( 71123, 'spell_stinky_precious_decimate'),
( 73032, 'spell_festergut_pungent_blight'),
( 73031, 'spell_festergut_pungent_blight'),
( 71219, 'spell_festergut_pungent_blight'),
( 69195, 'spell_festergut_pungent_blight'),
( 72219, 'spell_festergut_gastric_bloat'),
( 72551, 'spell_festergut_gastric_bloat'),
( 72552, 'spell_festergut_gastric_bloat'),
( 72553, 'spell_festergut_gastric_bloat'),
( 69290, 'spell_festergut_blighted_spores'),
( 71222, 'spell_festergut_blighted_spores'),
( 73033, 'spell_festergut_blighted_spores'),
( 73034, 'spell_festergut_blighted_spores'),
( 69159, 'spell_festergut_gaseous_blight'),
( 70135, 'spell_festergut_gaseous_blight'),
( 70136, 'spell_festergut_gaseous_blight'),
( 70137, 'spell_festergut_gaseous_blight'),
( 69161, 'spell_festergut_gaseous_blight'),
( 70138, 'spell_festergut_gaseous_blight'),
( 70139, 'spell_festergut_gaseous_blight'),
( 70140, 'spell_festergut_gaseous_blight'),
( 69163, 'spell_festergut_gaseous_blight'),
( 70468, 'spell_festergut_gaseous_blight'),
( 70469, 'spell_festergut_gaseous_blight'),
( 70470, 'spell_festergut_gaseous_blight'),
( 69782, 'spell_rotface_ooze_flood'),
( 69796, 'spell_rotface_ooze_flood'),
( 69798, 'spell_rotface_ooze_flood'),
( 69801, 'spell_rotface_ooze_flood'),
( 69538, 'spell_rotface_little_ooze_combine'),
( 69553, 'spell_rotface_large_ooze_combine'),
( 69610, 'spell_rotface_large_ooze_buff_combine'),
( 69839, 'spell_rotface_unstable_ooze_explosion_init'),
( 69832, 'spell_rotface_unstable_ooze_explosion'),
( 71441, 'spell_rotface_unstable_ooze_explosion_suicide'),
( 69507, 'spell_rotface_slime_spray'),
( 71213, 'spell_rotface_slime_spray'),
( 73189, 'spell_rotface_slime_spray'),
( 73190, 'spell_rotface_slime_spray'),
( 70701, 'spell_putricide_expunged_gas'),
( 70343, 'spell_putricide_slime_puddle'),
( 70351, 'spell_putricide_unstable_experiment'),
( 71966, 'spell_putricide_unstable_experiment'),
( 71967, 'spell_putricide_unstable_experiment'),
( 71968, 'spell_putricide_unstable_experiment'),
( 71412, 'spell_putricide_ooze_summon'),
( 71415, 'spell_putricide_ooze_summon'),
( 70672, 'spell_putricide_gaseous_bloat'),
( 72455, 'spell_putricide_gaseous_bloat'),
( 72832, 'spell_putricide_gaseous_bloat'),
( 72833, 'spell_putricide_gaseous_bloat'),
( 70447, 'spell_putricide_ooze_channel'),
( 72836, 'spell_putricide_ooze_channel'),
( 72837, 'spell_putricide_ooze_channel'),
( 72838, 'spell_putricide_ooze_channel'),
( 70672, 'spell_putricide_ooze_channel'),
( 72455, 'spell_putricide_ooze_channel'),
( 72832, 'spell_putricide_ooze_channel'),
( 72833, 'spell_putricide_ooze_channel'),
( 70459, 'spell_putricide_ooze_eruption_searcher'),
( 71255, 'spell_putricide_choking_gas_bomb'),
( 70920, 'spell_putricide_unbound_plague'),
( 70360, 'spell_putricide_eat_ooze'),
( 72527, 'spell_putricide_eat_ooze'),
( 72451, 'spell_putricide_mutated_plague'),
( 72463, 'spell_putricide_mutated_plague'),
( 72671, 'spell_putricide_mutated_plague'),
( 72672, 'spell_putricide_mutated_plague'),
( 70308, 'spell_putricide_mutation_init'),
( 70311, 'spell_putricide_mutated_transformation'),
( 71503, 'spell_putricide_mutated_transformation'),
( 70405, 'spell_putricide_mutated_transformation_dismiss'),
( 72508, 'spell_putricide_mutated_transformation_dismiss'),
( 72509, 'spell_putricide_mutated_transformation_dismiss'),
( 72510, 'spell_putricide_mutated_transformation_dismiss'),
( 70402, 'spell_putricide_mutated_transformation_dmg'),
( 72511, 'spell_putricide_mutated_transformation_dmg'),
( 72512, 'spell_putricide_mutated_transformation_dmg'),
( 72513, 'spell_putricide_mutated_transformation_dmg'),
( 70539, 'spell_putricide_regurgitated_ooze'),
( 72457, 'spell_putricide_regurgitated_ooze'),
( 72875, 'spell_putricide_regurgitated_ooze'),
( 72876, 'spell_putricide_regurgitated_ooze'),
( 71598, 'spell_creature_permanent_feign_death'),
( 71806, 'spell_taldaram_glittering_sparks'),
( 71718, 'spell_taldaram_summon_flame_ball'),
( 72040, 'spell_taldaram_summon_flame_ball'),
( 55891, 'spell_taldaram_flame_ball_visual'),
( 55947, 'spell_taldaram_flame_ball_visual'),
( 71756, 'spell_taldaram_ball_of_inferno_flame'),
( 72782, 'spell_taldaram_ball_of_inferno_flame'),
( 72783, 'spell_taldaram_ball_of_inferno_flame'),
( 72784, 'spell_taldaram_ball_of_inferno_flame'),
( 72080, 'spell_valanar_kinetic_bomb'),
( 72087, 'spell_valanar_kinetic_bomb_knockback'),
( 72054, 'spell_valanar_kinetic_bomb_absorb'),
( 73001, 'spell_blood_council_shadow_prison'),
( 72999, 'spell_blood_council_shadow_prison_damage'),
( 70877, 'spell_blood_queen_frenzied_bloodthirst'),
( 71474, 'spell_blood_queen_frenzied_bloodthirst'),
( 70946, 'spell_blood_queen_vampiric_bite'),
( 71475, 'spell_blood_queen_vampiric_bite'),
( 71476, 'spell_blood_queen_vampiric_bite'),
( 71477, 'spell_blood_queen_vampiric_bite'),
( 71899, 'spell_blood_queen_bloodbolt'),
( 71900, 'spell_blood_queen_bloodbolt'),
( 71901, 'spell_blood_queen_bloodbolt'),
( 71902, 'spell_blood_queen_bloodbolt'),
( 71390, 'spell_blood_queen_pact_of_the_darkfallen'),
( 71340, 'spell_blood_queen_pact_of_the_darkfallen_dmg'),
( 71341, 'spell_blood_queen_pact_of_the_darkfallen_dmg_target'),
( 70078, 'spell_svalna_caress_of_death'),
( 70053, 'spell_svalna_revive_champion'),
( 71462, 'spell_svalna_remove_spear'),
( 71085, 'spell_dreamwalker_mana_void'),
( 70915, 'spell_dreamwalker_decay_periodic_timer'),
( 70912, 'spell_dreamwalker_decay_periodic_timer'),
( 70916, 'spell_dreamwalker_decay_periodic_timer'),
( 70913, 'spell_dreamwalker_decay_periodic_timer'),
( 70921, 'spell_dreamwalker_summoner'),
( 70912, 'spell_dreamwalker_summon_suppresser'),
( 71032, 'spell_dreamwalker_summoner'),
( 71078, 'spell_dreamwalker_summoner'),
( 70933, 'spell_dreamwalker_summoner'),
( 72224, 'spell_dreamwalker_summon_dream_portal'),
( 72480, 'spell_dreamwalker_summon_nightmare_portal'),
( 71970, 'spell_dreamwalker_nightmare_cloud'),
( 72868, 'spell_putricide_slime_puddle_aura'),
( 72869, 'spell_putricide_slime_puddle_aura'),
( 71357, 'spell_frostwarden_handler_order_whelp'),
( 71350, 'spell_frostwarden_handler_focus_fire'),
( 71376, 'spell_rimefang_icy_blast'),
( 70598, 'spell_sindragosa_s_fury'),
( 69762, 'spell_sindragosa_unchained_magic'),
( 69766, 'spell_sindragosa_instability'),
( 70126, 'spell_sindragosa_frost_beacon'),
( 69712, 'spell_sindragosa_ice_tomb'),
( 69675, 'spell_sindragosa_ice_tomb_dummy'),
( 70157, 'spell_sindragosa_ice_tomb_trap'),
( 69845, 'spell_sindragosa_collision_filter'),
( 71053, 'spell_sindragosa_collision_filter'),
( 71054, 'spell_sindragosa_collision_filter'),
( 71055, 'spell_sindragosa_collision_filter'),
( 70127, 'spell_sindragosa_collision_filter'),
( 72528, 'spell_sindragosa_collision_filter'),
( 72529, 'spell_sindragosa_collision_filter'),
( 72530, 'spell_sindragosa_collision_filter'),
( 70117, 'spell_sindragosa_collision_filter'),
( 70117, 'spell_sindragosa_icy_grip'),
-- Isle of Conquest
( 66630, 'spell_gen_gunship_portal'),
( 66637, 'spell_gen_gunship_portal'),
( 66656, 'spell_gen_parachute_ic'),
-- Oculus
( 50053, 'spell_varos_centrifuge_shield'),
( 61407, 'spell_varos_energize_core_area_entry'),
( 62136, 'spell_varos_energize_core_area_entry'),
( 54069, 'spell_varos_energize_core_area_entry'),
( 56251, 'spell_varos_energize_core_area_entry'),
( 50785, 'spell_varos_energize_core_area_enemy'),
( 59372, 'spell_varos_energize_core_area_enemy'),
( 51162, 'spell_eregos_planar_shift'),
-- Trial of Crusader
( 66118, 'spell_gen_leeching_swarm'),
( 67630, 'spell_gen_leeching_swarm'),
( 68646, 'spell_gen_leeching_swarm'),
( 68647, 'spell_gen_leeching_swarm'),
-- Trial of the Champion
( 66862, 'spell_eadric_radiance'),
( 67681, 'spell_eadric_radiance'),
-- Ulduar
( 63308, 'spell_razorscale_devouring_flame'),
( 62717, 'spell_ignis_slag_pot'),
( 63477, 'spell_ignis_slag_pot'),
( 62521, 'spell_attuned_to_nature_dose_reduction'),
( 62524, 'spell_attuned_to_nature_dose_reduction'),
( 62525, 'spell_attuned_to_nature_dose_reduction'),
( 63633, 'spell_ulduar_rubble_summon'),
( 65594, 'spell_ulduar_cancel_stone_grip'),
( 62056, 'spell_ulduar_stone_grip'),
( 63985, 'spell_ulduar_stone_grip'),
( 64224, 'spell_ulduar_stone_grip_absorb'),
( 64225, 'spell_ulduar_stone_grip_absorb'),
( 62166, 'spell_ulduar_stone_grip_cast_target'),
( 63981, 'spell_ulduar_stone_grip_cast_target'),
( 64702, 'spell_ulduar_squeezed_lifeless'),
 (63720, 'spell_kologarn_stone_shout'),
 (64004, 'spell_kologarn_stone_shout'),
( 63027, 'spell_ulduar_proximity_mines'),
( 63276, 'spell_mark_of_the_faceless'),
( 63489, 'spell_shield_of_runes'),
( 62274, 'spell_shield_of_runes'),
( 63018, 'spell_xt002_searing_light_spawn_life_spark'),
( 65121, 'spell_xt002_searing_light_spawn_life_spark'),
( 64234, 'spell_xt002_gravity_bomb_aura'),
( 63024, 'spell_xt002_gravity_bomb_aura'),
( 64233, 'spell_xt002_gravity_bomb_damage'),
( 63025, 'spell_xt002_gravity_bomb_damage'),
( 62791, 'spell_xt002_heart_overload_periodic'),
( 62775, 'spell_xt002_tympanic_tantrum'),
( 37751, 'spell_xt002_submerged'),
( 37752, 'spell_xt002_stand'),
( 64381, 'spell_auriaya_strenght_of_the_pack'),
( 64679, 'spell_auriaya_sentinel_blast'),
( 64392, 'spell_auriaya_sentinel_blast'),
-- Eye Of Eternity
( 56105, 'spell_malygos_vortex_dummy'),
( 55873, 'spell_malygos_vortex_visual'),
-- Zalazane's Fall
( 75420, 'spell_mount_check'),
( 75102, 'spell_voljin_war_drums'),
-- Dustwallow Marsh
( 42489, 'spell_ooze_zap'),
( 42485, 'spell_ooze_zap_channel_end'),
( 42492, 'spell_energize_aoe'),
-- quest
(  8913, 'spell_q55_sacred_cleansing'),
( 17271, 'spell_q5206_test_fetid_skull'),
( 19512, 'spell_q6124_6129_apply_salve'),
( 34665, 'spell_q10255_administer_antidote'),
( 43874, 'spell_q11396_11399_force_shield_arcane_purple_x3'),
( 43882, 'spell_q11396_11399_scourging_crystal_controller_dummy'),
( 50133, 'spell_q11396_11399_scourging_crystal_controller'),
( 44936, 'spell_q11515_fel_siphon_dummy'),
( 45449, 'spell_q11587_arcane_prisoner_rescue'),
( 46023, 'spell_q11730_ultrasonic_screwdriver'),
( 49587, 'spell_q12459_seeds_of_natures_wrath'),
( 51840, 'spell_q12634_despawn_fruit_tosser'),
( 52308, 'spell_q12683_take_sputum_sample'),
( 55804, 'spell_q12937_relief_for_the_fallen'),
( 54798, 'spell_q12851_going_bearback'),
(  8593, 'spell_symbol_of_life_dummy'),
( 52090, 'spell_q12659_ahunaes_knife'),
-- item
( 23074, 'spell_item_arcanite_dragonling'),
(  8063, 'spell_item_deviate_fish'),
( 67019, 'spell_item_flask_of_the_north'),
( 23133, 'spell_item_gnomish_battle_chicken'),
( 13280, 'spell_item_gnomish_death_ray'),
( 33060, 'spell_item_make_a_wish'),
( 23076, 'spell_item_mechanical_dragonling'),
( 40802, 'spell_item_mingos_fortune_generator'),
( 23075, 'spell_item_mithril_mechanical_dragonling'),
( 13120, 'spell_item_net_o_matic'),
( 16589, 'spell_item_noggenfogger_elixir'),
(  8213, 'spell_item_savory_deviate_delight'),
( 14537, 'spell_item_six_demon_bag'),
( 59640, 'spell_item_underbelly_elixir'),
( 71905, 'spell_item_shadowmourne'),
( 67533, 'spell_item_red_rider_air_rifle'),
( 26678, 'spell_item_create_heart_candy'),
( 64323, 'spell_item_book_of_glyph_mastery'),
( 52481, 'spell_item_gift_of_the_harvester'),
( 45853, 'spell_item_map_of_the_geyser_fields'),
( 64981, 'spell_item_vanquished_clutches'),
( 28441, 'spell_item_ashbringer'),
-- warrior
( 12975, 'spell_warr_last_stand'),
( 59725, 'spell_warr_improved_spell_reflection'),
-- paladin
(-31850, 'spell_pal_ardent_defender'),
( 20425, 'spell_pal_judgement_of_command'),
( 63521, 'spell_pal_guarded_by_the_light'),
(-20473, 'spell_pal_holy_shock'),
( 20911, 'spell_pal_blessing_of_sanctuary'),
( 25899, 'spell_pal_blessing_of_sanctuary'),
( 37877, 'spell_pal_blessing_of_faith'),
-- hunter
( 53209, 'spell_hun_chimera_shot'),
( 53412, 'spell_hun_invigoration'),
( 53271, 'spell_hun_masters_call'),
( 53478, 'spell_hun_last_stand_pet'),
( 23989, 'spell_hun_readiness'),
( 37506, 'spell_hun_scatter_shot'),
(-53302, 'spell_hun_sniper_training'),
( 55709, 'spell_hun_pet_heart_of_the_phoenix'),
( 54044, 'spell_hun_pet_carrion_feeder'),
-- rogue
(-31228, 'spell_rog_cheat_death'),
(-31130, 'spell_rog_nerves_of_steel'),
(  5938, 'spell_rog_shiv'),
( 14185, 'spell_rog_preparation'),
(-51685, 'spell_rog_prey_on_the_weak'),
( -2818, 'spell_rog_deadly_poison'),
-- priest
(-47788, 'spell_pri_guardian_spirit'),
( -8129, 'spell_pri_mana_burn'),
( 47948, 'spell_pri_pain_and_suffering_proc'),
(-47540, 'spell_pri_penance'),
(   -17, 'spell_pri_reflective_shield_trigger'),
(-49821, 'spell_pri_mind_sear'),
-- death knight
( 50462, 'spell_dk_anti_magic_shell_raid'),
( 48707, 'spell_dk_anti_magic_shell_self'),
( 50461, 'spell_dk_anti_magic_zone'),
(-49158, 'spell_dk_corpse_explosion'),
( 50524, 'spell_dk_runic_power_feed'),
(-55090, 'spell_dk_scourge_strike'),
(-49145, 'spell_dk_spell_deflection'),
(-52284, 'spell_dk_will_of_the_necropolis'),
( 48743, 'spell_dk_death_pact'),
( 52751, 'spell_dk_death_gate'),
-- shaman
(-51474, 'spell_sha_astral_shift'),
( 39610, 'spell_sha_mana_tide_totem'),
( -1535, 'spell_sha_fire_nova'),
(  6474, 'spell_sha_earthbind_totem'),
-- mage
(-11113, 'spell_mage_blast_wave'),
( 11958, 'spell_mage_cold_snap'),
(  -543, 'spell_mage_frost_warding_trigger'),
( -6143, 'spell_mage_frost_warding_trigger'),
(  -543, 'spell_mage_incanters_absorbtion_absorb'),
( -6143, 'spell_mage_incanters_absorbtion_absorb'),
(-11426, 'spell_mage_incanters_absorbtion_absorb'),
( -1463, 'spell_mage_incanters_absorbtion_manashield'),
( 31687, 'spell_mage_summon_water_elemental'),
( 32826, 'spell_mage_polymorph_visual'),
-- warlock
( -6201, 'spell_warl_create_healthstone'),
( 47193, 'spell_warl_demonic_empowerment'),
( 47422, 'spell_warl_everlasting_affliction'),
(-27285, 'spell_warl_seed_of_corruption'),
-- druid
( 54846, 'spell_dru_glyph_of_starfire'),
( 69366, 'spell_dru_moonkin_form_passive'),
(-33851, 'spell_dru_primal_tenacity'),
( 62606, 'spell_dru_savage_defense'),
( 70691, 'spell_dru_t10_restoration_4p_bonus'),
(-50294, 'spell_dru_starfall_aoe'),
-- example
( 66244, 'spell_ex_66244'), 
( 5581,  'spell_ex_5581'),
( 47299, 'spell_ex_absorb_aura');

/* EOF */
