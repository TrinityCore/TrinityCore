-- Remove hack for glyph of Eternal Water
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=31687 AND `spell_effect`=70907;
