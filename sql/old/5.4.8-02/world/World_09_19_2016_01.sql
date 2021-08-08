UPDATE `creature_template` SET `ScriptName` = 'boss_horridon' WHERE `entry` = 68476;
UPDATE `creature_template` SET `ScriptName` = 'npc_direhorn_spirit_horridon' WHERE `entry` = 70688;
UPDATE `creature_template` SET `ScriptName` = 'npc_farraki_skirmisher_amani_protector' WHERE `entry` = 69173;
UPDATE `creature_template` SET `ScriptName` = 'npc_farraki_skirmisher_amani_protector' WHERE `entry` = 69169;
UPDATE `creature_template` SET `ScriptName` = 'npc_sul_lithuz_stonegazer' WHERE `entry` = 69172;
UPDATE `creature_template` SET `ScriptName` = 'npc_farraki_wastewalker' WHERE `entry` = 69175;
UPDATE `creature_template` SET `ScriptName` = 'npc_sand_trap' WHERE `entry` = 69346;
UPDATE `creature_template` SET `ScriptName` = 'npc_gurubashi_bloodlord' WHERE `entry` = 69167;
UPDATE `creature_template` SET `ScriptName` = 'npc_gurubashi_venom_priest' WHERE `entry` = 69164;
UPDATE `creature_template` SET `ScriptName` = 'npc_venomous_effusion_horridon' WHERE `entry` = 69314;
UPDATE `creature_template` SET `ScriptName` = 'npc_living_poison_horridon' WHERE `entry` = 69313;
UPDATE `creature_template` SET `ScriptName` = 'npc_risen_drakkari_warrior_champion' WHERE `entry` = 69184;
UPDATE `creature_template` SET `ScriptName` = 'npc_risen_drakkari_warrior_champion' WHERE `entry` = 69185;
UPDATE `creature_template` SET `ScriptName` = 'npc_drakkari_frozen_warlord' WHERE `entry` = 69178;
UPDATE `creature_template` SET `ScriptName` = 'npc_frozen_orb_horridon' WHERE `entry` = 69268;
UPDATE `creature_template` SET `ScriptName` = 'npc_amani_shi_flame_caster_horridon' WHERE `entry` = 69168;
UPDATE `creature_template` SET `ScriptName` = 'npc_amani_warbear_horridon' WHERE `entry` = 69177;
UPDATE `creature_template` SET `ScriptName` = 'npc_amani_shi_beast_shaman_horridon' WHERE `entry` = 69176;
UPDATE `creature_template` SET `ScriptName` = 'npc_lightning_nova_totem' WHERE `entry` = 69215;
UPDATE `creature_template` SET `ScriptName` = 'npc_zandalari_dinomancer_horridon' WHERE `entry` = 69221;
UPDATE `creature_template` SET `ScriptName` = 'npc_war_god_jalak' WHERE `entry` = 69374;

DELETE FROM `spell_script_names` WHERE `spell_id` = 136653;
DELETE FROM `spell_script_names` WHERE `spell_id` = 136587;
DELETE FROM `spell_script_names` WHERE `spell_id` = 136797;

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (136653, 'spell_rending_charge_horridon');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (136587, 'spell_venom_bolt_volley_horridon');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (136797, 'spell_dino_mending_horridon');