-- Hover Disk
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (30248,30234);
INSERT INTO `npc_spellclick_spells` (npc_entry,spell_id,quest_start,quest_end,cast_flags) VALUES
(30234,61421,0,0,0),
(30248,61421,0,0,0);
