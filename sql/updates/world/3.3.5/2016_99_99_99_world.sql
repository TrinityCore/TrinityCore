DELETE FROM `spell_proc` WHERE `SpellId` IN (-18213, -12834, 26467, 38164, 52420, 28845, 37594, 40971, -63156, 72176, -15337, 71770, 45057, 71634, 71640, 75475, 75481, -49182, -49188, -51627, -13983, -20234, 37168, -14156, 16864, 30823, 29601, 53646, 54909, -29723,
-46913, 46916, 52437, -46951, -54747, -51474, 54748);
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
(-49188,   0, 15, 0x00000000, 0x00020000, 0x00000000,     0, 0x0, 0x2,    0, 0, 0, 0,      0, 0), -- Rime
(-51627,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x0, 0x70, 0, 0, 0,      0, 0), -- Turn the Tables
(-13983,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x0, 0x18, 0, 0, 0,   1000, 0), -- Setup
(-20234,   0, 10, 0x00008000, 0x00000000, 0x00000000,     0, 0x2, 0x2,    0, 0, 0, 0,      0, 0), -- Improved Lay on Hands
(37168 ,   0,  8, 0x003E0000, 0x00000009, 0x00000000,     0, 0x0, 0x4,    0, 0, 0, 0,      0, 0), -- Finisher Combo
(-14156,   0,  8, 0x003E0000, 0x00000009, 0x00000000,     0, 0x0, 0x4,    0, 0, 0, 0,      0, 0), -- Ruthlessness
(16864 ,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x2,    0, 0, 0, 6,  10000, 0), -- Omen of Clarity
(30823 ,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x2,    0, 0,10, 0,      0, 0), -- Shamanistic Rage
(29601 ,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x2,    0, 0, 0, 0,      0, 0), -- Enlightenment
(53646 ,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x2,    2, 0, 0, 0,      0, 0), -- Demonic Pact
(54909 ,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x2,    2, 0, 0, 0,      0, 0), -- Demonic Pact
(-29723,   0,  4, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x2,    0, 0, 0, 0,      0, 0), -- Sudden Death
(-46913,   0,  4, 0x00000040, 0x00000404, 0x00000000,     0, 0x0, 0x2,    0, 0, 0, 0,      0, 0), -- Bloodsurge
(46916 ,   0,  4, 0x00200000, 0x00000000, 0x00000000,     0, 0x0, 0x4,    0, 0, 0, 0,      0, 0), -- Slam! (Bloodsurge proc)
(52437 ,   1,  4, 0x20000000, 0x00000000, 0x00000000,    16, 0x0, 0x4,    0, 0, 0, 0,      0, 0), -- Sudden Death proc
(-46951,   0,  4, 0x00000400, 0x00000040, 0x00000000,     0, 0x0, 0x2,    0, 0, 0, 0,      0, 0), -- Sword and Board
(-54747,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x0,    3, 0, 0, 0,      0, 0), -- Burning Determination
(-51474,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x0,    3, 0, 0, 0,      0, 0), -- Astral Shift
(54748 ,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x0,  256, 0, 0, 0,      0, 0); -- Burning Determination proc

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warl_improved_drain_soul','spell_warr_deep_wounds_aura','spell_gen_dummy_trigger','spell_item_persistent_shield','spell_item_soul_harvesters_charm','spell_warr_t3_prot_8p_bonus','spell_pri_item_greater_heal_refund',
'spell_pri_t5_heal_2p_bonus','spell_item_crystal_spire_of_karabor','spell_warl_decimation','spell_deathbringer_blood_beast_blood_link','spell_pri_improved_spirit_tap','spell_putricide_ooze_tank_protection','spell_item_commendation_of_kaelthas','spell_item_corpse_tongue_coin',
'spell_item_corpse_tongue_coin_heroic','spell_item_petrified_twilight_scale','spell_item_petrified_twilight_scale_heroic','spell_dk_blade_barrier','spell_dk_rime','spell_rog_turn_the_tables','spell_rog_turn_the_tables_proc','spell_rog_setup','spell_pal_improved_lay_of_hands',
'spell_dru_omen_of_clarity','spell_sha_shamanistic_rage','spell_item_pendant_of_the_violet_eye','spell_warl_demonic_pact','spell_warr_extra_proc','spell_warr_sword_and_board','spell_mage_burning_determination','spell_sha_astral_shift_aura');
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
(-49188, 'spell_dk_rime'),
(-51627, 'spell_rog_turn_the_tables'),
(52910 , 'spell_rog_turn_the_tables_proc'),
(52914 , 'spell_rog_turn_the_tables_proc'),
(52915 , 'spell_rog_turn_the_tables_proc'),
(-13983, 'spell_rog_setup'),
(-20234, 'spell_pal_improved_lay_of_hands'),
(16864 , 'spell_dru_omen_of_clarity'),
(30823 , 'spell_sha_shamanistic_rage'),
(29601 , 'spell_item_pendant_of_the_violet_eye'),
(53646 , 'spell_warl_demonic_pact'),
(54909 , 'spell_warl_demonic_pact'),
(-29723, 'spell_warr_extra_proc'),
(-46913, 'spell_warr_extra_proc'),
(-46951, 'spell_warr_sword_and_board'),
(-54747, 'spell_mage_burning_determination'),
(-51474, 'spell_sha_astral_shift_aura'),
(54748 , 'spell_mage_burning_determination');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=24 AND `SourceGroup`=0 AND `SourceEntry`=38164;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(24,0,38164,0,0,31,1,3,19457,0,0,0,0,"","Aura Unyielding Knights can only proc on condition target");
