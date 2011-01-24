UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`=27638;
UPDATE `creature_template` SET `ScriptName`='npc_azure_ring_captain' WHERE `entry`=28236;
            
DELETE FROM `spell_script_names` WHERE `spell_id` IN (61407,62136,54069,56251,50785,59372);
INSERT INTO `spell_script_names` (spell_id,ScriptName) VALUES 
(61407,'spell_varos_energize_core_area_entry'),
(62136,'spell_varos_energize_core_area_entry'),
(54069,'spell_varos_energize_core_area_entry'),
(56251,'spell_varos_energize_core_area_entry'),
(50785,'spell_varos_energize_core_area_enemy'),
(59372,'spell_varos_energize_core_area_enemy');