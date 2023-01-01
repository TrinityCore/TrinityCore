UPDATE creature_template SET `AIName`='',`ScriptName`='npc_pet_lich' WHERE entry=36979;
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_gen_lich_pet_aura', 'spell_gen_lich_pet_onsummon', 'spell_gen_lich_pet_aura_remove');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES 
(69732,'spell_gen_lich_pet_aura'),
(69735,'spell_gen_lich_pet_onsummon'),
(69736,'spell_gen_lich_pet_aura_remove');
