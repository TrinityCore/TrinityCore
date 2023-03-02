UPDATE `creature_template` SET `modelid1`='0' WHERE (`entry`='72588');

UPDATE `creature_template_addon` SET `auras`='145590' WHERE (`entry`='72588');
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`) VALUES ('72588', '145591', '1');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('145591', 'spell_sha_cloud');