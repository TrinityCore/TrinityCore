UPDATE creature_template SET `ScriptName`="boss_vizier_jinbak" WHERE entry=61567;
UPDATE creature_template SET `ScriptName`="boss_commander_vojak" WHERE entry=61634;
UPDATE creature_template SET `ScriptName`="boss_general_pavalak" WHERE entry=61485;
UPDATE `creature_template` SET `ScriptName`="boss_wing_leader_neronok" where entry=62205;
UPDATE `creature_template` SET `ScriptName`="npc_vizier_jinbak_sap_puddle" WHERE `entry`=61613;
UPDATE `creature_template` SET `ScriptName`="npc_vizier_jinbak_sap_globule" WHERE `entry`=61623;
UPDATE `creature_template` SET `ScriptName`="npc_commander_vojak_mantid_tar_keg" WHERE `entry`=61817;
UPDATE `creature_template` SET `ScriptName`="npc_commander_vojak_yang_ironclaw" WHERE `entry`=61620;
UPDATE `creature_template` SET `ScriptName`="npc_commander_vojak_lo_and_lo_chu" WHERE `entry` IN (61812,62794);
UPDATE `creature_template` SET `ScriptName`="npc_commander_vojak_sap_puddle" WHERE `entry`=61579;
UPDATE `creature_template` SET `ScriptName`="npc_commander_vojak_sikthik_swarmer" WHERE `entry`=63106;
UPDATE `creature_template` SET `ScriptName`="npc_commander_vojak_sikthik_demolisher" WHERE `entry`=61670;
UPDATE `creature_template` SET `ScriptName`="npc_commander_vojak_sikthik_amberwing" WHERE `entry`=61699;
UPDATE `creature_template` SET `ScriptName`="npc_commander_vojak_sikthik_warrior" WHERE `entry`=61701;
UPDATE `creature_template` SET `ScriptName`="npc_general_pavalak_blade_rush" WHERE `entry`=63720;
UPDATE `creature_template` SET `ScriptName`="npc_general_pavalak_reinforcement_summoner" WHERE `entry`=61483;
UPDATE `creature_template` SET `ScriptName`="npc_general_pavalak_siege_explosive" WHERE `entry`=61452;
UPDATE `creature_template` SET `ScriptName`="npc_general_pavalak_sikthik_soldier" WHERE `entry`=61448;
UPDATE `creature_template` SET `ScriptName`="npc_wing_leader_neronok_sticky_resin" WHERE `entry`=63730;


DELETE FROM `spell_script_names` WHERE `spell_id` IN (120001,119990,119941,119939,123039,120405,120202,124277,124278,124312,119376,119393,121440,121447,121282,121284,119476);
INSERT INTO `spell_script_names` VALUES
(120001,"spell_vinzier_jinbak_detonate"),
(119990,"spell_vinzier_jinbak_summon_sappling_periodic"),
(119941,"spell_vinzier_jinbak_sap_residue_target_selector"),
(123039,"spell_commander_vojak_player_throw_barrel"),
(120405,"spell_commander_vojak_grab_barrel"),
(120202,"spell_commander_vojak_bombard_trigger"),
(124277,"spell_general_pavalak_blade_rush_target_selector"),
(124278,"spell_general_pavalak_blade_rush_summon_effect"),
(124312,"spell_general_pavalak_blade_rush_charge_effect"),
(119376,"spell_general_pavalak_siege_explosive_summon_effect"),
(119393,"spell_general_pavalak_siege_explosive_trigger_effect"),
(119476,"spell_general_pavalak_bulwark"),
(121440,"spell_wing_leader_neronok_caustic_pitch_target_selector"),
(121447,"spell_wing_leader_neronok_quick_dry_resin_aura"),
(121282,"spell_wing_leader_neronok_gusting_winds"),
(121284,"spell_wing_leader_neronok_gusting_winds");

DELETE FROM `creature_template_addon` WHERE `entry` IN (61579,61452,61484,61613);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(61579,0,0,0,1,0,'120591'),
(61452,0,0,0,1,0,'119380'),
(61484,0,0,0,1,0,'119698'),
(61613,0,0,0,1,0,'119939');

DELETE FROM `creature_template_addon` WHERE `entry`=61699;

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=121447;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=121448;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(121448,122063,2,'Encased in Resin - Quick-Dry Resin');

DELETE FROM `conditions` WHERE `SourceEntry` IN (120095,120001,124291);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, SourceGroup, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
(13,1,120095,31,3,61613,''),
(13,1,120001,31,3,61613,''),
(13,1,124291,31,3,63720,'');