--
DELETE FROM `spell_script_names` WHERE `scriptname` IN (
'spell_gordunni_trap',
'spell_mage_frost_warding_trigger',
'spell_mandokir_devastating_slam_damage',
'spell_pal_ardent_defender',
'spell_sha_mana_tide',
'spell_threatening_gaze');

UPDATE `gameobject_template` SET `scriptname`='' WHERE `scriptname` IN (
'go_eastern_crystal_pylon',
'go_iruxos',
'go_mausoleum_door',
'go_mausoleum_trigger',
'go_northern_crystal_pylon',
'go_panther_cage',
'go_western_crystal_pylon');

UPDATE `creature_template` SET `scriptname`='' WHERE `scriptname` IN (
'npc_archmage_malin',
'npc_bartleby',
'npc_batrider',
'npc_brann_bronzebeard',
'npc_calvin_montague',
'npc_corporal_keeshan',
'npc_daphne_stilwell',
'npc_deathly_usher',
'npc_defias_traitor',
'npc_forest_frog',
'npc_galen_goodward',
'npc_healing_ward',
'npc_lady_katrana_prestor',
'npc_lord_gregor_lescovar',
'npc_marzon_silent_blade',
'npc_mount_vendor',
'npc_mountaineer_pebblebitty',
'npc_ragged_john',
'npc_rinji',
'npc_rogue_trainer',
'npc_shade_of_jindo',
'npc_spawn_of_marli',
'npc_tyrion',
'npc_tyrion_spybot',
'npc_vilebranch_speaker',
'npc_zealot_lorkhan',
'npc_zealot_zath',
'npc_zulaman_hostage',
'npc_zuljin_vortex',
'pyrewood_ambush',
'boss_arlokk',
'boss_gahzranka',
'boss_hakkar',
'boss_jeklik',
'boss_jindo',
'boss_marli',
'boss_thekal');

-- scriptwaypoints
DELETE FROM `script_waypoint` WHERE `entry` IN (467, 6182, 7780, 1754, 8856, 349, 5391);
