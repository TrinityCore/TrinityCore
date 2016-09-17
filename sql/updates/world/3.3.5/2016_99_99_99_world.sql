DELETE FROM `spell_proc` WHERE `SpellId` IN (-18213, -12834, 26467, 38164, 52420, 28845, 37594, 40971, -63156, 72176, -15337, 71770, 45057, 71634, 71640, 75475, 75481, -49182, -49188);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(-18213,  32,  5, 0x00004000, 0x00000000, 0x00000000,     2, 0x0, 0x0,    0, 0, 0, 0,      0, 0), -- Improved Drain Soul
(-12834,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x1, 0x2,    2, 0, 0, 0,      0, 0), -- Deep Wounds Aura
(26467 ,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x2, 0x2,    0, 0, 0, 0,      0, 0), -- Persistent Shield
(38164 ,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x2,    0, 0, 0, 0,      0, 0), -- Unyielding Knights
(52420 ,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x0,    0, 0, 0, 0,  30000, 0), -- Deflection
(28845 ,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x0,    0, 0, 0, 0,      0, 0), -- Cheat Death
(37594 ,   0,  6, 0x00001000, 0x00000000, 0x00000000,     0, 0x2, 0x2,    0, 0, 0, 0,      0, 0), -- Greater Heal Refund
(40971 ,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x2, 0x2,    0, 0, 0, 0,      0, 0), -- Bonus Healing (Crystal Spire of Karabor)
(-63156,   0,  5, 0x00000001, 0x000000C0, 0x00000000,     0, 0x1, 0x2,    0, 0, 0, 0,      0, 0), -- Decimation
(72176 ,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x1, 0x2,    0, 0, 0, 0,      0, 0), -- Blood Beast's Blood Link
(-15337,   0,  6, 0x00802000, 0x00000002, 0x00000000,     0, 0x1, 0x2,    2, 0, 0, 0,      0, 0), -- Improved Spirit Tap
(71770 ,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x0,    0, 0, 0, 0,      0, 0), -- Ooze Spell Tank Protection
(45057 ,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x0,    0, 0, 0, 0,  30000, 0), -- Evasive Maneuvers
(71634 ,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x0,    0, 0, 0, 0,  30000, 0), -- Item - Icecrown 25 Normal Tank Trinket 1
(71640 ,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x0,    0, 0, 0, 0,  30000, 0), -- Item - Icecrown 25 Heroic Tank Trinket 1
(75475 ,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x0,    0, 0, 0, 0,  45000, 0), -- Item - Chamber of Aspects 25 Tank Trinket
(75481 ,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x0,    0, 0, 0, 0,  45000, 0), -- Item - Chamber of Aspects 25 Heroic Tank Trinket
(-49182,   0, 15, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x2,    0, 0, 0, 0,      0, 0), -- Blade Barrier
(-49188,   0, 15, 0x00000000, 0x00020000, 0x00000000,     0, 0x0, 0x2,    0, 0, 0, 0,      0, 0); -- Rime

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warl_improved_drain_soul','spell_warr_deep_wounds_aura','spell_gen_dummy_trigger','spell_item_persistent_shield','spell_item_soul_harvesters_charm','spell_warr_t3_prot_8p_bonus','spell_pri_item_greater_heal_refund',
'spell_pri_t5_heal_2p_bonus','spell_item_crystal_spire_of_karabor','spell_warl_decimation','spell_deathbringer_blood_beast_blood_link','spell_pri_improved_spirit_tap','spell_putricide_ooze_tank_protection','spell_item_commendation_of_kaelthas','spell_item_corpse_tongue_coin',
'spell_item_corpse_tongue_coin_heroic','spell_item_petrified_twilight_scale','spell_item_petrified_twilight_scale_heroic','spell_dk_blade_barrier','spell_dk_rime');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-18213, 'spell_warl_improved_drain_soul'),
(-12834, 'spell_warr_deep_wounds_aura'),
(26467 , 'spell_item_persistent_shield'),
(52420 , 'spell_item_soul_harvesters_charm'),
(28845 , 'spell_warr_t3_prot_8p_bonus'),
(37594 , 'spell_pri_t5_heal_2p_bonus'),
(40971 , 'spell_item_crystal_spire_of_karabor'),
(-63156, 'spell_warl_decimation'),
(72176 , 'spell_deathbringer_blood_beast_blood_link'),
(-15337, 'spell_pri_improved_spirit_tap'),
(71770 , 'spell_putricide_ooze_tank_protection'),
(45057 , 'spell_item_commendation_of_kaelthas'),
(71634 , 'spell_item_corpse_tongue_coin'),
(71640 , 'spell_item_corpse_tongue_coin_heroic'),
(75475 , 'spell_item_petrified_twilight_scale'),
(75481 , 'spell_item_petrified_twilight_scale_heroic'),
(-49182, 'spell_dk_blade_barrier'),
(-49188, 'spell_dk_rime');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=24 AND `SourceGroup`=0 AND `SourceEntry`=38164;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(24,0,38164,0,0,31,1,3,19457,0,0,0,0,"","Aura Unyielding Knights can only proc on condition target");
