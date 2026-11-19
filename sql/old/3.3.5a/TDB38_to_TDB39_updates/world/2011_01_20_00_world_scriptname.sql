UPDATE `creature_template` SET `ScriptName`='boss_varos' WHERE `entry`=27447;
UPDATE `creature_template` SET `ScriptName`='npc_azure_ring_captain' WHERE `entry`=27638;

DELETE FROM `spell_script_names` WHERE `spell_id`=50053;
INSERT INTO `spell_script_names` (spell_id,ScriptName) VALUES (50053,'spell_varos_centrifuge_shield');
