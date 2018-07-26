SET @NPC_GRYAN_STOUTMANTLE                      := 234;
SET @NPC_RISE_BROTHERHOOD_DUMMY                 := 42771;
	
UPDATE `creature_template`
SET `ScriptName` = ''
WHERE entry = @NPC_RISE_BROTHERHOOD_DUMMY;

UPDATE `creature_template`
SET `ScriptName` = 'npc_rise_br'
WHERE entry = @NPC_GRYAN_STOUTMANTLE;