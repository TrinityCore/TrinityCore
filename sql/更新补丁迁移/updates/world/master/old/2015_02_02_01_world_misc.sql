update creature set spawnmask = 43200 where id = 51157;
update creature_template set npcflag = 1, ScriptName = 'npc_golden_orb' where entry = 51157;