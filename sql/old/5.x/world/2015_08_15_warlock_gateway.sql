UPDATE `creature_template` SET `ScriptName`='npc_demonic_gateway' WHERE `entry`='59262';
UPDATE `creature_template` SET `ScriptName`='npc_demonic_gateway' WHERE `entry`='59271';
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES ('59262', '120729', '1', '2');
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES ('59271', '113896', '1', '2');
UPDATE `npc_spellclick_spells` SET `spell_id`='120729' WHERE `npc_entry`='59271' and`spell_id`='113896';
UPDATE `npc_spellclick_spells` SET `spell_id`='113896' WHERE `npc_entry`='59262' and`spell_id`='120729';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('120729', 'spell_warl_gateway_teleport');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('113896', 'spell_warl_gateway_teleport');