DELETE FROM `smart_scripts` WHERE `entryorguid`=28481 AND `source_type`=0;
UPDATE `creature_template` SET `AIName`='' WHERE `entry`=28481;

DELETE FROM `spell_script_names` WHERE `spell_id` IN (51769,51770,58941);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(51769,'spell_q12619_emblazon_runeblade'),
(51770,'spell_q12619_emblazon_runeblade_effect'),
(58941,'spell_archavon_rock_shards');

DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (58695,58696);
INSERT INTO `spelldifficulty_dbc`(`id`,`spellid0`,`spellid1`) VALUES 
(58695,58695,60883),
(58696,58696,60884);
