UPDATE `creature_template` SET `unit_flags` = 646, `ScriptName` = 'npc_demonic_gateway', `npcflag` = 16777216   WHERE `entry` IN (59262, 59271);

DELETE FROM `creature_template_aura` WHERE `entry` IN (59262, 59271);
INSERT INTO `creature_template_aura` (`entry`, `aura`) VALUES
(59262, '71994'),
(59271, '71994');

DELETE FROM `spell_script_names` WHERE (`spell_id`='113901') AND (`ScriptName`='spell_warl_demonic_gateway_charges');
