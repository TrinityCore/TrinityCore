DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (29625,29433,29555,25460,33778,28614,33687,30330,32189,30895,30337);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES
(29625,46598,0,0,0,1,0,0,0), -- Hyldsmeet Proto-Drake
(29433,47020,0,0,0,1,0,0,0), -- Goblin Sapper
(29555,47020,0,0,0,1,0,0,0), -- Goblin Sapper
(25460,46598,0,0,0,1,0,0,0), -- Amazing Flying Carpet
(33778,43671,0,0,0,1,0,0,0), -- Tournament Hippogryph
(28614,46598,0,0,0,1,0,0,0), -- Scarlet Gryphon
(33687,46598,0,0,0,1,0,0,0), -- Chillmaw
(30330,46598,0,0,0,1,0,0,0), -- Jotunheim Proto-Drake
(32189,46598,0,0,0,1,0,0,0), -- Skybreaker Recon Fighter
(30895,46598,0,0,0,1,0,0,0), -- Lithe Stalker
(30337,43671,13069,1,13069,1,0,0,0); -- Jotunheim Rapid-Fire Harpoon
