update creature_template set npcflag = 16777216, ScriptName = 'npc_siege_explosive', unit_flags2 = 67127296 where entry = 61452;
delete from npc_spellclick_spells where npc_entry = 61452;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(61452, 119388, 1, 0);