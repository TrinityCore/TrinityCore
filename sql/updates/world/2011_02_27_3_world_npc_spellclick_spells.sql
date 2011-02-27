DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=28366 AND `spell_id`=60962;  -- Wintergrasp Tower Cannon, duplicate from previous rev
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES
(28366,60962,0,0,0,1,0,0,0);  -- Wintergrasp Tower Cannon'
