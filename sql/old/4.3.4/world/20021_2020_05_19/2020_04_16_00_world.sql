DELETE FROM `spell_proc` WHERE `SpellId` IN (96924, 96879, 97117);
INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Charges`, `Cooldown`) VALUES
(96924, 0, 1, 2, 0x2, 0, 0, 0, 0),
(96879, 0, 2, 0, 0x0, 0, 0, 0, 0),
(97117, 0, 2, 0, 0x0, 0, 0, 0, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_item_blessing_of_khazgoroth',
'spell_item_weight_of_a_feather',
'spell_item_tipping_of_the_scales',
'spell_item_blind_spot');

INSERT INTO `spell_script_names` (`spell_Id`, `ScriptName`) VALUES
(96934, 'spell_item_blessing_of_khazgoroth'),
(97127, 'spell_item_blessing_of_khazgoroth'),
(96879, 'spell_item_weight_of_a_feather'),
(97117, 'spell_item_weight_of_a_feather'),
(96880, 'spell_item_tipping_of_the_scales'),
(91322, 'spell_item_blind_spot'),
(92331, 'spell_item_blind_spot');
