DELETE FROM `spell_proc` WHERE `SpellId` IN (-18213, -12834, 26467, 38164, 52420, 28845, 37594);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(-18213,  32,  5, 0x00004000, 0x00000000, 0x00000000,     2, 0x0, 0x0,    0, 0, 0, 0,      0, 0), -- Improved Drain Soul
(-12834,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x1, 0x2,    2, 0, 0, 0,      0, 0), -- Deep Wounds Aura
(26467,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x2, 0x2,    0, 0, 0, 0,      0, 0), -- Persistent Shield
(38164,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x2,    0, 0, 0, 0,      0, 0), -- Unyielding Knights
(52420,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x0,    0, 0, 0, 0,  30000, 0), -- Deflection
(28845,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x0,    0, 0, 0, 0,      0, 0), -- Cheat Death
(37594,   0,  6, 0x00001000, 0x00000000, 0x00000000,     0, 0x2, 0x2,    0, 0, 0, 0,      0, 0); -- Greater Heal Refund

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warl_improved_drain_soul','spell_warr_deep_wounds_aura','spell_gen_dummy_trigger','spell_item_persistent_shield','spell_item_soul_harvesters_charm','spell_warr_T3_prot_8P_bonus','spell_pri_item_greater_heal_refund','spell_pri_t5_heal_2p_bonus');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-18213, 'spell_warl_improved_drain_soul'),
(-12834, 'spell_warr_deep_wounds_aura'),
(26467, 'spell_item_persistent_shield'),
(52420, 'spell_item_soul_harvesters_charm'),
(28845, 'spell_warr_T3_prot_8P_bonus'),
(37594, 'spell_pri_t5_heal_2p_bonus');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=24 AND `SourceGroup`=0 AND `SourceEntry`=38164;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(24,0,38164,0,0,31,1,3,19457,0,0,0,0,"","Aura Unyielding Knights can only proc on condition target");
