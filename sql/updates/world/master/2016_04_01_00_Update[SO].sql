UPDATE `creature_loot_template` SET `ChanceOrQuestChance`='100' WHERE `entry`='72433' AND `item`='102144'; 
UPDATE `creature_template` SET `flags_extra`='512' WHERE `entry`='72433';
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '145690','spell_kds_unlock');  
UPDATE `creature_template` SET `ScriptName`='npc_wildhammer_shaman' WHERE `entry`='72640';  