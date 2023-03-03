UPDATE `instance_template` SET `script`='instance_throne_of_the_tides' WHERE (`map`='643');
DELETE FROM `instance_template` WHERE (`map`='169');
UPDATE `instance_template` SET `parent`='571' WHERE (`map`='631');
UPDATE `instance_template` SET `parent`='571' WHERE (`map`='632');
UPDATE `instance_template` SET `parent`='1' WHERE (`map`='644');
UPDATE `instance_template` SET `parent`='571' WHERE (`map`='658');
UPDATE `instance_template` SET `parent`='571' WHERE (`map`='668');
UPDATE `instance_template` SET `parent`='1', `script`='instance_the_vortex_pinnacle', `allowMount`='1' WHERE (`map`='657');
UPDATE `instance_template` SET `script`='instance_blackwing_descent' WHERE (`map`='669');
UPDATE `instance_template` SET `script`='instance_grim_batol' WHERE (`map`='670');
UPDATE `instance_template` SET `script`='instance_twilight_bastion' WHERE (`map`='671');
UPDATE `instance_template` SET `parent`='1' WHERE (`map`='720');
UPDATE `instance_template` SET `parent`='571' WHERE (`map`='724');
UPDATE `instance_template` SET `parent`='646' WHERE (`map`='725');
UPDATE `instance_template` SET `parent`='1', `script`='instance_throne_of_four_winds', `allowMount`='1' WHERE (`map`='754');
UPDATE `instance_template` SET `parent`='1', `script`='instance_lost_city_of_tolvir' WHERE (`map`='755');
UPDATE `instance_template` SET `parent`='732' WHERE (`map`='757');
UPDATE `instance_template` SET `parent`='1', `script`='instance_end_time' WHERE (`map`='938');
UPDATE `instance_template` SET `parent`='1', `script`='instance_well_of_eternity' WHERE (`map`='939');
UPDATE `instance_template` SET `parent`='1', `script`='instance_hour_of_twilight' WHERE (`map`='940');
UPDATE `instance_template` SET `script`='instance_shadopan_monastery' WHERE (`map`='959');
UPDATE `instance_template` SET `script`='instance_temple_of_jade_serpent' WHERE (`map`='960');
UPDATE `instance_template` SET `script`='instance_stormstout_brewery' WHERE (`map`='961');
UPDATE `instance_template` SET `script`='instance_gate_setting_sun' WHERE (`map`='962');
UPDATE `instance_template` SET `parent`='1', `script`='instance_dragon_soul' WHERE (`map`='967');
UPDATE `instance_template` SET `script`='instance_mogu_shan_palace' WHERE (`map`='994');
UPDATE `instance_template` SET `script`='instance_siege_of_the_niuzao_temple' WHERE (`map`='1011');
UPDATE `instance_template` SET `script`='instance_throne_of_thunder' WHERE (`map`='1098');
UPDATE `instance_template` SET `parent`='1116', `script`='instance_bloodmaul_slag_mines' WHERE (`map`='1175');
UPDATE `instance_template` SET `parent`='1116', `script`='instance_shadowmoon_burial_grounds' WHERE (`map`='1176');
UPDATE `instance_template` SET `parent`='1116', `script`='instance_auchindoun' WHERE (`map`='1182');
UPDATE `instance_template` SET `parent`='1116', `script`='instance_iron_docks' WHERE (`map`='1195');
UPDATE `instance_template` SET `parent`='1116', `script`='instance_blackrock_foundry' WHERE (`map`='1205');
UPDATE `instance_template` SET `parent`='1116', `script`='instance_grim_depot' WHERE (`map`='1208');
UPDATE `instance_template` SET `parent`='1116', `script`='instance_skyreach' WHERE (`map`='1209');
UPDATE `instance_template` SET `parent`='1116', `script`='instance_highmaul' WHERE (`map`='1228');
UPDATE `instance_template` SET `parent`='1116', `script`='instance_everbloom' WHERE (`map`='1279');
UPDATE `instance_template` SET `script`='instance_upper_blackrock_spire_wod' WHERE (`map`='1358');
UPDATE `instance_template` SET `script`='instance_hellfire_citadel' WHERE (`map`='1448');
UPDATE `instance_template` SET `parent`='1220', `script`='instance_eye_of_azshara', `allowMount`='1' WHERE (`map`='1456');
UPDATE `instance_template` SET `parent`='1220', `script`='instance_neltharions_lair', `allowMount`='1' WHERE (`map`='1458');
UPDATE `instance_template` SET `parent`='1220', `script`='scenario_twisting_nether_masters_promontory' WHERE (`map`='1462');
UPDATE `instance_template` SET `parent`='1220', `script`='instance_darkheart_thicket', `allowMount`='1' WHERE (`map`='1466');
UPDATE `instance_template` SET `parent`='0', `script`='scenario_stormheim_prequest', `allowMount`='0' WHERE (`map`='1475');
UPDATE `instance_template` SET `parent`='1220', `script`='instance_halls_of_valor', `allowMount`='1' WHERE (`map`='1477');
UPDATE `instance_template` SET `parent`='1220', `script`='instance_maw_of_souls', `allowMount`='1' WHERE (`map`='1492');
UPDATE `instance_template` SET `parent`='1220', `script`='instance_vault_of_the_wardens' WHERE (`map`='1493');
UPDATE `instance_template` SET `script`='scenario_7.0_artifact_legion_ship', `allowMount`='1' WHERE (`map`='1498');
UPDATE `instance_template` SET `parent`='1220', `script`='scenario_7.0_artifact_blackrook_hold', `allowMount`='1' WHERE (`map`='1501');
UPDATE `instance_template` SET `parent`='1220', `script`='instance_arcway' WHERE (`map`='1516');
UPDATE `instance_template` SET `script`='scenario_7.0_artifact_karazhan_catacombs' WHERE (`map`='1533');
UPDATE `instance_template` SET `parent`='1220', `script`='instance_violet_hold_legion' WHERE (`map`='1544');
UPDATE `instance_template` SET `script`='scenario_legion_boost_alliance' WHERE (`map`='1554');

INSERT INTO `instance_template` (`map`, `parent`, `script`, `allowMount`) VALUES
(734, 0, 'instance_anquiraj_event', 1),
(930, 0, 'scenario_alcaz_island_unused', 1),
(951, 0, 'instance_nexus_tarecgosas_rest', 1),
(971, 0, 'jade_forest_skyfire_gy', 1),
(980, 0, 'arena_tolvir', 1),
(996, 870, 'instance_terrace_of_the_endless_spring', 1),
(998, 0, 'battleground_deepwind_gorge', 1),
(999, 0, 'scenario_theramore_horde', 1),
(1000, 0, 'scenario_theramore_alliance', 1),
(1001, 0, 'instance_scarlet_halls', 0),
(1004, 0, 'instance_scarlet_monastery_mop', 1),
(1005, 0, 'scenario_brewing_storm', 0),
(1007, 0, 'instance_scholomance_mop', 0),
(1008, 870, 'instance_mogushan_vaults', 0),
(1009, 870, 'instance_heart_of_fear', 0),
(1010, 0, 'battleground_ctf3_whatever', 1),
(1014, 0, 'scenario_7.0_artifact_monk_peak_of_serenity', 1),
(1024, 0, 'scenario_greenstone_village', 1),
(1029, 0, 'scenario_mogu_catacombs', 0),
(1030, 0, 'scenario_crypt_of_forgotten_king', 0),
(1031, 0, 'scenario_ring_of_blood', 1),
(1035, 0, 'scenario_kotmogu', 1),
(1048, 0, 'scenario_oonga_ingoo', 1),
(1049, 0, 'scenario_black_ox_temple', 1),
(1050, 0, 'scenario_zanvess', 1),
(1051, 0, 'scenario_brewmoon_festival', 1),
(1060, 0, 'scenario_mining_prototype_for_6.0', 1),
(1061, 0, 'scenario_domination_point', 1),
(1062, 0, 'scenario_lions_landing', 1),
(1095, 0, 'scenario_knife_in_the_dark', 1),
(1099, 0, 'scenario_battle_on_the_high_seas', 0),
(1102, 0, 'scenario_fort_horde', 1),
(1103, 0, 'scenario_fort_alliance', 1),
(1104, 0, 'scenario_patience', 1),
(1105, 0, 'battleground_gold_rush', 1),
(1106, 0, 'scenario_dalaran_for_garrosh_questline', 1),
(1107, 0, 'scenario_7.0_artifact_warlock_OH_and_7.2_mount', 1),
(1112, 0, 'scenario_warlock_black_temple_green_fire', 1),
(1120, 0, 'instance_isle_of_the_thunder_king_horde_boat', 1),
(1121, 0, 'instance_isle_of_the_thunder_king_alliance_boat', 1),
(1126, 1064, 'scenario_isle_of_the_thunder_progression', 1),
(1130, 0, 'scenario_shimmer', 1),
(1131, 0, 'scenario_emberdeep', 1),
(1134, 0, 'arena_shadopan', 1),
(1135, 1064, 'scenario_treasury_of_the_thunder_king', 1),
(1136, 870, 'instance_siege_of_orgrimmar', 1),
(1144, 0, 'scenario_dark_heart_of_pandaria', 1),
(1148, 870, 'scenario_proving_grounds', 0),
(1152, 1116, 'instance_horde_garrison_tier_1', 1),
(1153, 1116, 'instance_horde_garrison_tier_3', 1),
(1155, 0, 'scenario_5.5_defense', 1),
(1157, 0, 'scenario_noodle_cart_in_halfhill', 1),
(1158, 1116, 'instance_alliance_garrison_tier_1', 1),
(1159, 1116, 'instance_alliance_garrison_tier_3', 1),
(1161, 870, 'scenario_celestial_tournament', 0),
(1168, 1116, 'scenario_the_purge_of_grommar', 1),
(1170, 0, 'scenario_boss_fight_arena', 1),
(1171, 0, 'instance_small_battleground', 1),
(1191, 1116, 'battleground_ashran', 1),
(1200, 1116, 'scenario_frostfire_1_bonetown', 1),
(1203, 1116, 'scenario_frostfire_2_finale', 1),
(1207, 1116, 'scenario_shattrath_city', 1),
(1268, 0, 'scenario_remains_of_xandros', 1),
(1277, 1116, 'scenario_defense_of_karabor', 1),
(1280, 0, 'battleground_hillsbrad_foothills', 1),
(1329, 1116, 'scenario_grommashar', 1),
(1330, 1116, 'instance_horde_garrison_tier_2', 1),
(1331, 1116, 'instance_alliance_garrison_tier_2', 1),
(1374, 1116, 'scenario_auchindoun_trial_of_fate', 1),
(1402, 1116, 'scenario_gorgrond_finale', 1),
(1431, 0, 'battleground_the_coliseum', 1),
(1451, 0, 'scenario_6.2_tanaan', 1),
(1453, 0, 'scenario_scourge_of_northshire', 1),
(1455, 0, 'scenario_edge_of_reality_darkfeather_mount', 1),
(1460, 0, 'scenario_broken_shore_7.0', 1),
(1461, 0, 'scenario_aszuna', 1),
(1464, 1116, 'instance_tanaan_jungle_6.2', 1),
(1468, 1220, 'scenario_vault_of_the_wardens', 0),
(1469, 0, 'scenario_7.0_artifact_shaman_OH', 1),
(1476, 0, 'scenario_stormheim_prequest_skyfire_ship', 0),
(1478, 1220, 'scenario_valsharah_temple_of_elune', 1),
(1479, 1220, 'scenario_7.0_warrior_artifact_OH', 1),
(1480, 0, 'scenario_7.0_deathknight_artifact_icecrown', 1),
(1481, 0, 'scenario_7.0_dh_artifact_mardum', 1),
(1489, 0, 'scenario_7.0_artifact', 1),
(1494, 1220, 'scenario_7.0_artifact_violet_hold', 1),
(1495, 1220, 'scenario_7.0_artifact_shields_rest', 1),
(1500, 1220, 'scenario_7.0_artifact_brokenshore', 1),
(1502, 1220, 'scenario_7.0_artifact_shadowgore', 1),
(1503, 1220, 'scenario_7.0_artifact_ench_shaman', 1),
(1504, 0, 'arena_blackrook_hold', 1),
(1505, 0, 'arena_nagrand_legion', 1),
(1511, 1220, 'scenario_7.0_artifact_fury_surv', 1),
(1512, 1220, 'scenario_7.0_artifact_priest_OH', 1),
(1513, 571, 'scenario_7.0_artifact_oculus', 1),
(1514, 0, 'scenario_7.0_artifact_monk_OH', 1),
(1515, 1220, 'instance_azshara_highmountains_flashback', 1),
(1519, 0, 'scenario_7.0_artifact_dh_OH', 1),
(1520, 1220, 'instance_the_emerald_nightmare', 1),
(1522, 1220, 'scenario_dreadscar_rift_warlock', 1),
(1523, 0, 'scenario_mardum_start', 1),
(1526, 1220, 'scenario_7.0_artifact_elemental_shaman', 1),
(1528, 0, 'scenario_7.0_artifact_skywall', 1),
(1529, 0, 'scenario_karazhan_dungeon', 0),
(1530, 1220, 'instance_nighthold', 1),
(1536, 571, 'scenario_7.0_artifact_ursoks_lair', 0),
(1537, 0, 'scenario_boost_expirience_old', 0),
(1539, 0, 'scenario_7.0_artifact_tirisfal_glades', 1),
(1540, 0, 'scenario_7.0_artifact_dreamway', 1),
(1541, 0, 'scenario_7.0_artifact_mistweaver', 1),
(1545, 1220, 'scenario_7.0_artifact_combat_rogue', 1),
(1552, 0, 'arena_ashamane', 1),
(1553, 0, 'scenario_artifact_gloaming_reef', 1),
(1557, 0, 'scenario_legion_boost_horde', 0),
(1571, 1220, 'instance_court_of_the_stars', 1),
(1572, 0, 'scenario_7.0_artifact_shaman_intro', 0),
(1579, 0, 'scenario_7.0_artifact_ulduar', 0),
(1580, 0, 'scenario_artifact_maelstrom', 0),
(1583, 0, 'scenario_7.0_artifact_nexus_vault', 0),
(1599, 0, 'scenario_7.0_artifact_resto_druid', 0),
(1600, 0, 'scenario_7.0_artifact_resto_shaman', 0),
(1602, 0, 'scenario_7.0_artifact_vortex_pinnacle', 0),
(1604, 0, 'scenario_7.0_artifact_niskara', 0),
(1605, 0, 'scenario_7.0_artifact_firelands', 1),
(1607, 0, 'scenario_7.0_artifact_subtlety', 0),
(1608, 0, 'scenario_7.0_artifact_malornes_nightmare', 1),
(1609, 0, 'scenario_7.0_artifact_beastmaster', 0),
(1611, 0, 'scenario_7.0_artifact_lights_hope', 0),
(1612, 0, 'scenario_7.0_artifact_ruins_of_falanaar', 0),
(1616, 0, 'scenario_aoe_challenge_and_frost_artifact', 0),
(1617, 0, 'scenario_7.0_artifact_rescue_coltira', 1),
(1618, 0, 'scenario_7.0_artifact_dk_scarlet_monastery', 0),
(1620, 0, 'scenario_7.0_artifact_assassination_rogue', 0),
(1621, 0, 'scenario_black_temple', 0),
(1623, 0, 'scenario_mage_campaign_oculus', 1),
(1624, 0, 'scenario_illidans_origins', 0),
(1625, 0, 'scenario_7.0_artifact_brewmaster', 0),
(1626, 0, 'scenario_the_collapse', 0),
(1629, 0, 'scenario_defense_of_netherlight_temple', 0),
(1630, 0, 'scenario_7.0_artifact_tolbarad', 0),
(1632, 0, 'scenario_7.0_artifact_arcway', 0),
(1646, 0, 'scenario_illidans_origins_2', 0),
(1648, 1220, 'instance_trial_of_valor', 1),
(1651, 0, 'instance_karazhan_legion', 0),
(1653, 0, 'scenario_illidans_origins_3', 0),
(1662, 1220, 'scenario_suramar_campaign_finale', 1),
(1666, 1220, 'scenario_7.2_broken_shore_intro', 1),
(1672, 0, 'arena_blades_edge_new', 1),
(1673, 0, 'scenario_single_challenge', 0),
(1676, 1220, 'instance_tomb_of_sargeras', 1),
(1677, 1220, 'instance_cathedral_of_eternal_night', 0),
(1681, 0, 'battleground_arathi_basin_winter_brawl', 1),
(1683, 0, 'scenario_challenge_stealth', 0),
(1684, 0, 'scenario_challenge_twins', 0),
(1687, 1, 'scenario_wailing_caverns_pet_dungeon', 0),
(1692, 0, 'scenario_7.2_dk_campaign_pit_of_saron', 1),
(1693, 0, 'scenario_7.2_monk_brewmaster', 1),
(1695, 0, 'scenario_7.2_brokenshore_legion_commandship', 0),
(1698, 0, 'scenario_challenge_tank', 0),
(1702, 0, 'scenario_challenge_dualboss', 0),
(1703, 0, 'scenario_challenge_godqueen', 0),
(1704, 1220, 'scenario_invasion_valsharah', 1),
(1705, 1220, 'scenario_invasion_azsuna', 1),
(1706, 1220, 'scenario_invasion_highmountain', 1),
(1707, 1220, 'scenario_invasion_stormheim', 1),
(1708, 0, 'scenario_7.2_paladin_class_mount', 1),
(1710, 0, 'scenario_challenge_healer', 0),
(1714, 0, 'scenario_7.2_warrior_class_mount', 1),
(1715, 0, 'battleground_blackrock_mountain_brawl', 1),
(1719, 0, 'scenario_7.2_warlock_class_mount', 1),
(1728, 0, 'scenario_7.2_hunter_class_mount', 1),
(1729, 0, 'scenario_7.2_mage_class_mount', 1),
(1730, 0, 'scenario_7.2_druid_class_mount1', 1),
(1731, 0, 'scenario_7.2_druid_class_mount2', 1),
(1732, 0, 'scenario_7.2_dh_class_mount', 1),
(1734, 0, 'scenario_7.2_shaman_class_mount', 1),
(1736, 0, 'scenario_7.2_dk_class_mount', 1),
(1737, 0, 'scenario_7.2_akazamaks_hat', 0),
(1738, 0, 'scenario_7.2_dk_class_mount2', 1);
