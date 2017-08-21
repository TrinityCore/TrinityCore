UPDATE `spell_proc` SET `AttributesMask`=(`AttributesMask` & ~0x40) WHERE `SpellId`=-1120;
UPDATE `spell_proc` SET `AttributesMask`=(`AttributesMask` | 0x20 | 0x40) WHERE `SpellId`=51209;
UPDATE `spell_proc` SET `AttributesMask`=(`AttributesMask` | 0x10) WHERE `SpellId`=56817;
UPDATE `spell_proc` SET `AttributesMask`=(`AttributesMask` | 0x20) WHERE `SpellId`=-44445;
UPDATE `spell_proc` SET `AttributesMask`=(`AttributesMask` | 0x10) WHERE `SpellId`=32216;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_item_argent_dawn_commission', 'spell_dk_rune_strike_proc', 'spell_warr_victorious');
