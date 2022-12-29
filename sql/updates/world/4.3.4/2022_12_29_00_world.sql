DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_item_obsidian_armor';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(27539, 'spell_item_obsidian_armor');

DELETE FROM `spell_proc` WHERE `SpellId`= 27539;
INSERT INTO `spell_proc` (`SpellId`, `SpellTypeMask`, `Cooldown`) VALUES
(27539, 0x1, 10000); -- 10s cooldown
