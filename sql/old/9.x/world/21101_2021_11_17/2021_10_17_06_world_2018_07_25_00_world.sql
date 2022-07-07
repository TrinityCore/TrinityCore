UPDATE `creature_template` SET `ScriptName`='npc_pet_gen_soul_trader' WHERE `entry`=27914;
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_ethereal_pet_aura','spell_ethereal_pet_onsummon','spell_ethereal_pet_aura_remove','spell_steal_essence_visual');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES 
(50051,'spell_ethereal_pet_aura'),
(50052,'spell_ethereal_pet_onsummon'),
(50055,'spell_ethereal_pet_aura_remove'),
(50101,'spell_steal_essence_visual');
