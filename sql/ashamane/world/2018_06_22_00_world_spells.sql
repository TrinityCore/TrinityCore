-- NPC Demonic Gateway
UPDATE `creature_template` SET  `npcflag`='16777216', `ScriptName`='spell_npc_warl_demonic_gateway_green' WHERE (`entry`='59262');
UPDATE `creature_template` SET  `npcflag`='16777216', `ScriptName`='spell_npc_warl_demonic_gateway_purple' WHERE (`entry`='59271');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` in (59262,59271);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
('59262', '113902', '0', '0'),
('59271', '113902', '0', '0');
