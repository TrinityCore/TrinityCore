UPDATE `instance_template` SET `script`='instance_grim_batol' WHERE `map`=670;
UPDATE `creature_template` SET `ScriptName`='boss_drahga_shadowburner' WHERE `entry`=40319;
UPDATE `creature_template` SET `ScriptName` = 'mob_valiona_gb' WHERE `entry` =40320;
UPDATE `creature_template` SET `VehicleId`=737 WHERE `entry`=40320;
UPDATE `creature_template` SET `mechanic_immune_mask`='613097436' WHERE `entry`=40320;
UPDATE `creature_template` SET `ScriptName`='mob_invoked_flame_spirit' WHERE `entry`=40357;
UPDATE `creature_template` SET `ScriptName`='boss_erudax' WHERE `entry`=40484;
UPDATE `creature_template` SET `ScriptName` = 'mob_faceless' WHERE `entry` =48844;
UPDATE `creature_template` SET `ScriptName` = 'mob_alexstraszas_eggs' WHERE `entry` =40486;
DELETE FROM `spell_script_names` WHERE `spell_id` IN(75664,91086);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
('75664', 'spell_shadow_gale_visual');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
('91086', 'spell_shadow_gale_visual');
UPDATE `creature_template` SET `ScriptName` = 'boss_umbriss' WHERE `entry` =39625;
UPDATE `creature_template` SET `ScriptName` = 'npc_dweller' WHERE `entry` =45467;
UPDATE `creature_template` SET `ScriptName` = 'npc_malveillant' WHERE `entry` =39984;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
('74984', 'spell_mighty_stomp_summon'),
('74914', 'spell_personal_phalanx_summon');
UPDATE `creature_template` SET `ScriptName` = 'boss_forgemaster_throngus' WHERE `entry` =40177;






