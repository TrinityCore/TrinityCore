DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (15290, 59725);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 59725, 0, 0, 33, 0, 1, 0, 0, 1, 0, 0, '', 'Spell Improved Spell Reflection (effect 0) will hit the potential target of the spell if target is not the same as condition target.'),
(13, 1, 15290, 0, 0, 33, 0, 1, 0, 0, 1, 0, 0, '', 'Spell Vampiric Embrace (effect 0) will hit the potential target of the spell if target is not the same as condition target.');

DELETE FROM `command` WHERE `name`='reload spell_proc_event';
-- Charges drop (previously hardcoded in SpellMgr::LoadSpellInfoCorrections)
DELETE FROM `spell_proc` WHERE `SpellId` IN (17941, 18820, 22008, 28200, 31834, 32216, 34477, 34936, 44401, 48108, 51124, 54741, 57761, 64823);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(17941,  0, 5, 0x00000001, 0x00000000, 0x00000000,  65536, 0x1, 0x1,    0, 0, 0, 0,      0, 1), -- Shadow Trance
(18820,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x7, 0x1,    0, 0, 0, 0,      0, 1), -- Insight
(22008,  0, 3, 0x61400035, 0x00000000, 0x00000000,  69632, 0x5, 0x1,    0, 0, 0, 0,      0, 1), -- Netherwind Focus
(28200,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x3, 0x1,    0, 0, 0, 0,      0, 6), -- Ascendance
(31834,  0,10, 0x80000000, 0x00000000, 0x00000000,  16384, 0x2, 0x1,    0, 0, 0, 0,      0, 1), -- Light's Grace
(32216,  0, 4, 0x00000000, 0x00000100, 0x00000000,     16, 0x1, 0x4,    0, 0, 0, 0,      0, 1), -- Victorious (drop charge on Victory rush cast)
(34477,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x5, 0x2,    0, 0, 0, 0,      0, 1), -- Misdirection
(34936,  0, 5, 0x00000001, 0x00000040, 0x00000000,  65536, 0x1, 0x1,    0, 0, 0, 0,      0, 1), -- Backlash
(44401,  0, 3, 0x00000800, 0x00000000, 0x00000000,   4096, 0x5, 0x1,    0, 0, 0, 0,      0, 1), -- Missile Barrage
(48108,  0, 3, 0x00400000, 0x00000000, 0x00000000,  65536, 0x1, 0x1,    0, 0, 0, 0,      0, 1), -- Hot Streak
(51124,  0,15, 0x00000002, 0x00000006, 0x00000000,  65552, 0x1, 0x2,    0, 0, 0, 0,      0, 1), -- Killing Machine
(54741,  0, 3, 0x00000004, 0x00000000, 0x00000000,  65536, 0x5, 0x1,    0, 0, 0, 0,      0, 1), -- Firestarter
(57761,  0, 3, 0x00000001, 0x00001000, 0x00000000,  65536, 0x1, 0x1,    0, 0, 0, 0,      0, 1), -- Fireball!
(64823,  0, 7, 0x00000004, 0x00000000, 0x00000000,  65536, 0x1, 0x1,    0, 0, 0, 0,      0, 1); -- Elune's Wrath

-- Port procs from spell_proc_event table
DELETE FROM `spell_proc` WHERE `SpellId` IN (-1463, -11185, -18094, -27243, -29441, -29834, -30293, -31244, -31571, -31871, -34497, -34914, -44445, -47569, -48539, -51625, -51664, -53228, -53290, -59088, -64127, 15286, 22007, 24658, 24932, 26169, 28716, 28719, 28744, 28809, 28847, 32863, 36123, 38252, 39367, 44141, 70388, 32409, 37288, 37295, 37381, 37377, 39437, 39372, 40438, 40442, 42770, 44835, 54754, 54815, 54821, 54832, 54845, 55677, 56218, 56372, 56374, 56375, 56800, 57870, 58375, 58642, 37447, 61062, 63320, 65032, 69755, 69739, 70723, 70664, 70770, 71519, 71562, 71761);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(-1463,  0, 3, 0x00000000, 0x00000000, 0x00000000,      0, 0x1, 0x0, 1024, 0, 0, 0,      0, 0), -- Mana Shield
(-11185, 0, 3, 0x00000080, 0x00000000, 0x00000000,  65536, 0x1, 0x2,    0, 2, 0, 0,      0 ,0), -- Improved Blizzard
(-18094, 0, 5, 0x0000000A, 0x00000000, 0x00000000,      0, 0x1, 0x2,    0, 0, 0, 0,      0, 0), -- Nightfall
(-27243, 0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x1, 0x0,    0, 0, 0, 0,      0, 0), -- Seed of corruption (Warlock)
(-29441, 0, 3, 0x00000000, 0x00000000, 0x00000000,      0, 0x7, 0x0,    8, 0, 0, 0,   1000, 0), -- Magic Absorption
(-29834, 0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x5, 0x0,    0, 0, 0, 0,      0, 0), -- Second Wind (Warrior talent)
(-30293, 0, 5, 0x00000181, 0x008200C0, 0x00000000,      0, 0x1, 0x2,    0, 0, 0, 0,      0, 0), -- Soul Leech
(-31244, 0, 8, 0x003A0000, 0x00000009, 0x00000000,      0, 0x5, 0x2,11196, 0, 0, 0,      0, 0), -- Quick Recovery
(-31571, 0, 3, 0x00000000, 0x00000022, 0x00000008,  16384, 0x7, 0x4,    0, 0, 0, 0,      0, 0), -- Arcane Potency
(-31871, 0,10, 0x00000010, 0x00000000, 0x00000000,  16384, 0x4, 0x2,    0, 0, 0, 0,      0, 0), -- Divine Purpose
(-34497, 0, 9, 0x00060800, 0x00800001, 0x00000201,      0, 0x1, 0x2,    2, 0, 0, 0,      0, 0), -- Thrill of the Hunt
(-34914, 0, 6, 0x00002000, 0x00000000, 0x00000000,      0, 0x1, 0x0,    0, 0, 0, 0,      0, 0), -- Vampiric Touch
(-44445, 0, 3, 0x00000013, 0x00011000, 0x00000000,      0, 0x1, 0x2,    0, 0, 0, 0,      0, 0), -- Hot Streak
(-47569, 0, 6, 0x00004000, 0x00000000, 0x00000000,  16384, 0x4, 0x2,    0, 0, 0, 0,      0, 0), -- Improved Shadowform
(-48539, 0, 7, 0x00000010, 0x04000000, 0x00000000, 262144, 0x2, 0x0,    0, 0, 0, 0,      0, 0), -- Revitalize
(-51625, 0, 8, 0x1000A000, 0x00000000, 0x00000000,      0, 0x5, 0x2,    0, 0, 0, 0,      0, 0), -- Deadly Brew
(-51664, 0, 8, 0x00020000, 0x00000008, 0x00000000,      0, 0x1, 0x2,    0, 0, 0, 0,      0, 0), -- Cut to the Chase
(-53228, 0, 9, 0x00000020, 0x01000000, 0x00000000,      0, 0x4, 0x2,    0, 0, 0, 0,      0, 0), -- Rapid Recuperation
(-53290, 0, 9, 0x00000800, 0x00000001, 0x00000200,      0, 0x1, 0x2,    2, 0, 0, 0,      0, 0), -- Hunting Party
(-59088, 0, 4, 0x00000000, 0x00000002, 0x00000000,   1024, 0x4, 0x4,    0, 0, 0, 0,      0, 0), -- Improved Spell Reflection
(-64127, 0, 6, 0x00000001, 0x00000001, 0x00000000,      0, 0x6, 0x2,    0, 0, 0, 0,      0, 0), -- Body and Soul
(15286, 32, 6, 0x00000000, 0x00000000, 0x00000000,      0, 0x1, 0x2,    0, 0, 0, 0,      0, 0), -- Vampiric Embrace
(22007,  0, 3, 0x00200021, 0x00000000, 0x00000000,      0, 0x1, 0x2,    0, 0, 0, 0,      0, 0), -- Netherwind Focus
(24658,  0, 0, 0x00000000, 0x00000000, 0x00000000,  87376, 0x7, 0x2,    0, 0, 0, 0,      0, 0), -- Unstable Power
(24932,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x1, 0x2,    2, 0, 0, 0,      0, 0), -- Leader of the Pack
(26169,  0, 6, 0x00000000, 0x00000000, 0x00000000,      0, 0x2, 0x2,    0, 0, 0, 0,      0, 0), -- Oracle Healing Bonus
(28716,  0, 7, 0x00000010, 0x00000000, 0x00000000, 262144, 0x2, 0x0,    0, 0, 0, 0,      0, 0), -- Rejuvenation - Dreamwalker Raiment 2pc
(28719,  0, 7, 0x00000020, 0x00000000, 0x00000000,      0, 0x2, 0x2,    2, 0, 0, 0,      0, 0), -- Healing Touch - Dreamwalker Raiment 8 pc
(28744,  0, 7, 0x00000040, 0x00000000, 0x00000000, 278528, 0x2, 0x2,    0, 0, 0, 0,      0, 0), -- Regrowth - Dreamwalker Raiment 6pc
(28809,  0, 6, 0x00001000, 0x00000000, 0x00000000,      0, 0x2, 0x2,    2, 0, 0, 0,      0, 0), -- Greater Heal - Vestments of Faith 4pc
(28847,  0, 7, 0x00000020, 0x00000000, 0x00000000,      0, 0x2, 0x2,    0, 0, 0, 0,      0, 0), -- Healing Touch Refund

(32863,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x1, 0x0,    0, 0, 0, 0,      0, 0), -- Seed of Corruption (Monster)
(36123,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x1, 0x0,    0, 0, 0, 0,      0, 0), -- Seed of Corruption (Monster)
(38252,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x1, 0x0,    0, 0, 0, 0,      0, 0), -- Seed of Corruption (Monster)
(39367,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x1, 0x0,    0, 0, 0, 0,      0, 0), -- Seed of Corruption (Monster)
(44141,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x1, 0x0,    0, 0, 0, 0,      0, 0), -- Seed of Corruption (Monster)
(70388,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x1, 0x0,    0, 0, 0, 0,      0, 0), -- Seed of Corruption (Monster)

(32409,  0, 0, 0x00000000, 0x00002000, 0x00000000,      0, 0x0, 0x0,    0, 0, 0, 0,      0, 0), -- Shadow Word: Death - do not require honor target
(37288,  0, 7, 0x00000000, 0x00000000, 0x00000000,      0, 0x2, 0x2,    0, 0, 0, 0,      0, 0), -- Mana Restore - Malorne Raiment 2pc
(37295,  0, 7, 0x00000000, 0x00000000, 0x00000000,      0, 0x1, 0x2,    0, 0, 0, 0,      0, 0), -- Mana Restore - Malorne Regalia 2pc
(37381,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x1, 0x2,    0, 0, 0, 0,      0, 0), -- Pet Healing

(37377, 32, 5, 0x00000000, 0x00000000, 0x00000000,      0, 0x1, 0x2,    0, 0, 0, 0,      0, 0), -- Shadowflame
(39437,  4, 5, 0x00000000, 0x00000000, 0x00000000,      0, 0x1, 0x2,    0, 0, 0, 0,      0, 0), -- Shadowflame Hellfire and RoF

(39372, 48, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x1, 0x2,    0, 0, 0, 0,      0, 0), -- Frozen Shadoweave
(40438,  0, 6, 0x00008040, 0x00000000, 0x00000000,      0, 0x3, 0x0,    0, 0, 0, 0,      0, 0), -- Priest Tier 6 Trinket
(40442,  0, 7, 0x00000014, 0x00000440, 0x00000000,      0, 0x7, 0x1,    0, 0, 0, 0,      0, 0), -- Druid Tier 6 Trinket
(42770,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x5, 0x0,    0, 0, 0, 0,      0, 0), -- Second Wind (NPC aura)
(44835,  0, 7, 0x00000000, 0x00000080, 0x00000000,     16, 0x1, 0x2,    0, 0, 0, 0,      0, 0), -- Maim Interrupt
(54754,  0, 7, 0x00000010, 0x00000000, 0x00000000,      0, 0x2, 0x0,    0, 0, 0, 0,      0, 0), -- Glyph of Rejuvenation
(54815,  0, 7, 0x00008000, 0x00000000, 0x00000000,     16, 0x1, 0x2,    0, 0, 0, 0,      0, 0), -- Glyph of Shred
(54821,  0, 7, 0x00001000, 0x00000000, 0x00000000,     16, 0x1, 0x2,    0, 0, 0, 0,      0, 0), -- Glyph of Rake
(54832,  0, 7, 0x00000000, 0x00001000, 0x00000000,  16384, 0x4, 0x2,    0, 0, 0, 0,      0, 0), -- Glyph of Innervate
(54845,  0, 7, 0x00000004, 0x00000000, 0x00000000,  65536, 0x1, 0x2,    0, 0, 0, 0,      0, 0), -- Glyph of Starfire
(55677,  0, 6, 0x00000000, 0x00000001, 0x00000000,      0, 0x4, 0x2,    0, 0, 0, 0,      0, 0), -- Glyph of Dispel Magic
(56218,  0, 5, 0x00000002, 0x00000000, 0x00000000,      0, 0x1, 0x0,    0, 0, 0, 0,      0, 0), -- Glyph of Corruption
(56372,  0, 3, 0x00000000, 0x00000080, 0x00000000,  16384, 0x4, 0x4,    0, 0, 0, 0,      0, 0), -- Glyph of Ice Block
(56374,  0, 3, 0x00000000, 0x00004000, 0x00000008,  16384, 0x4, 0x4,    0, 0, 0, 0,      0, 0), -- Glyph of Icy Veins
(56375,  0, 3, 0x01000000, 0x00000000, 0x00000000,  65536, 0x4, 0x4,    0, 0, 0, 0,      0, 0), -- Glyph of Polymorph
(56800,  0, 8, 0x00000004, 0x00000000, 0x00000000,     16, 0x1, 0x2,    0, 0, 0, 0,      0, 0), -- Glyph of Backstab
(57870,  0, 9, 0x00800000, 0x00000000, 0x00000000, 262144, 0x2, 0x0,    0, 0, 0, 0,      0, 0), -- Glyph of Mend Pet
(58375,  0, 4, 0x00000000, 0x00000200, 0x00000000,     16, 0x1, 0x2,    0, 0, 0, 0,      0, 0), -- Glyph of Blocking
(58642,  0,15, 0x00000000, 0x08000000, 0x00000000,     16, 0x1, 0x4,    0, 0, 0, 0,      0, 0), -- Glyph of Scourge Strike

(37447,  0, 3, 0x00000000, 0x00000100, 0x00000000,  16384, 0x4, 0x2,    0, 0, 0, 0,      0, 0), -- Improved Mana Gems
(61062,  0, 3, 0x00000000, 0x00000100, 0x00000000,  16384, 0x4, 0x2,    0, 0, 0, 0,      0, 0), -- Improved Mana Gems

(63320,  0, 5, 0x80040000, 0x00000000, 0x00008000,   1024, 0x7, 0x4,    0, 0, 0, 0,      0, 0), -- Glyph of Life Tap
(65032,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x0, 0x0,    0, 0, 0, 0,      0, 0), -- 321-Boombot Aura - do not require experience target
(69755,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x7, 0x4,    0, 0, 0, 0,  45000, 0), -- Purified Shard of the Scale
(69739,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x7, 0x4,    0, 0, 0, 0,  45000, 0), -- Shiny Shard of the Scale
(70723,  0, 7, 0x00000005, 0x00000000, 0x00000000,      0, 0x1, 0x2,    2, 0, 0, 0,      0, 0), -- Item - Druid T10 Balance 4P Bonus
(70664,  0, 7, 0x00000010, 0x00000000, 0x00000000,      0, 0x2, 0x2,    0, 0, 0, 0,      0, 0), -- Druid T10 Restoration 4P Bonus (Rejuvenation)
(70770,  0, 6, 0x00000800, 0x00000000, 0x00000000,      0, 0x2, 0x2,    0, 0, 0, 0,      0, 0), -- Item - Priest T10 Healer 2P Bonus
(71519,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x1, 0x4,    0, 0, 0, 0, 105000, 0), -- Deathbringer's Will
(71562,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x1, 0x4,    0, 0, 0, 0, 105000, 0), -- Deathbringer's Will (Heroic)
(71761,  3, 0, 0x00000000, 0x00100000, 0x00000000,      0, 0x5, 0x2,  256, 0, 0, 0,      0, 0); -- Deep Freeze Immunity State

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_mage_imp_blizzard','spell_warl_seed_of_corruption_dummy','spell_mage_magic_absorption','spell_warr_second_wind','spell_warl_soul_leech','spell_rog_quick_recovery','spell_mage_arcane_potency','spell_pal_divine_purpose','spell_hun_thrill_of_the_hunt','spell_mage_hot_streak','spell_pri_imp_shadowform','spell_item_unstable_power','spell_item_restless_strength','spell_dru_leader_of_the_pack','spell_pri_aq_3p_bonus','spell_dru_revitalize','spell_rog_deadly_brew','spell_rog_cut_to_the_chase','spell_hun_rapid_recuperation_trigger','spell_hun_hunting_party','spell_warr_improved_spell_reflection','spell_pri_body_and_soul','spell_warl_seduction','spell_pri_vampiric_embrace','spell_twisted_reflection','spell_dru_t3_2p_bonus','spell_dru_t3_8p_bonus','spell_dru_t3_6p_bonus','spell_pri_t3_4p_bonus','spell_item_healing_touch_refund','spell_warl_seed_of_corruption_generic','spell_mark_of_malice','spell_dru_t4_2p_bonus','spell_anetheron_vampiric_aura','spell_item_frozen_shadoweave','spell_item_aura_of_madness','spell_pri_item_t6_trinket','spell_dru_item_t6_trinket','spell_item_dementia','spell_item_pet_healing','spell_warl_t4_2p_bonus_shadow','spell_warl_t4_2p_bonus_fire','spell_uk_second_wind','spell_item_sunwell_exalted_caster_neck','spell_item_sunwell_exalted_melee_neck','spell_item_sunwell_exalted_tank_neck','spell_item_sunwell_exalted_healer_neck','spell_warl_glyph_of_corruption_nightfall','spell_dru_glyph_of_rejuvenation','spell_dru_glyph_of_shred','spell_dru_glyph_of_rake','spell_dru_glyph_of_innervate','spell_dru_glyph_of_starfire_dummy','spell_pri_glyph_of_dispel_magic','spell_mage_glyph_of_ice_block','spell_mage_glyph_of_icy_veins','spell_mage_glyph_of_polymorph','spell_rog_glyph_of_backstab','spell_hun_glyph_of_mend_pet','spell_warr_glyph_of_blocking','spell_pri_shadowfiend_death','spell_dk_glyph_of_scourge_strike','spell_hun_kill_command_pet','spell_mage_imp_mana_gems','spell_gen_vampiric_touch','spell_warl_glyph_of_life_tap','spell_xt002_321_boombot_aura','spell_item_purified_shard_of_the_scale','spell_item_shiny_shard_of_the_scale','spell_dru_t10_balance_4p_bonus','spell_dru_t10_restoration_4p_bonus_dummy','spell_pri_t10_heal_2p_bonus','spell_item_deathbringers_will_normal','spell_item_deathbringers_will_heroic');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-11185, 'spell_mage_imp_blizzard'),
(-27243, 'spell_warl_seed_of_corruption_dummy'),
(-29441, 'spell_mage_magic_absorption'),
(-29834, 'spell_warr_second_wind'),
(-30293, 'spell_warl_soul_leech'),
(-31244, 'spell_rog_quick_recovery'),
(-31571, 'spell_mage_arcane_potency'),
(-31871, 'spell_pal_divine_purpose'),
(-34497, 'spell_hun_thrill_of_the_hunt'),
(-44445, 'spell_mage_hot_streak'),
(-47569, 'spell_pri_imp_shadowform'),
(-48539, 'spell_dru_revitalize'),
(-51625, 'spell_rog_deadly_brew'),
(-51664, 'spell_rog_cut_to_the_chase'),
(-53228, 'spell_hun_rapid_recuperation_trigger'),
(-53290, 'spell_hun_hunting_party'),
(-59088, 'spell_warr_improved_spell_reflection'),
(-64127, 'spell_pri_body_and_soul'),
(6358,   'spell_warl_seduction'),
(15286,  'spell_pri_vampiric_embrace'),
(21063,  'spell_twisted_reflection'),
(24658,  'spell_item_unstable_power'),
(24661,  'spell_item_restless_strength'),
(24932,  'spell_dru_leader_of_the_pack'),
(26169,  'spell_pri_aq_3p_bonus'),
(28716,  'spell_dru_t3_2p_bonus'),
(28719,  'spell_dru_t3_8p_bonus'),
(28744,  'spell_dru_t3_6p_bonus'),
(28809,  'spell_pri_t3_4p_bonus'),
(28847,  'spell_item_healing_touch_refund'),

(32863,  'spell_warl_seed_of_corruption_generic'),
(36123,  'spell_warl_seed_of_corruption_generic'),
(38252,  'spell_warl_seed_of_corruption_generic'),
(39367,  'spell_warl_seed_of_corruption_generic'),
(44141,  'spell_warl_seed_of_corruption_generic'),
(70388,  'spell_warl_seed_of_corruption_generic'),

(33493,  'spell_mark_of_malice'),
(37288,  'spell_dru_t4_2p_bonus'),
(37295,  'spell_dru_t4_2p_bonus'),
(38196,  'spell_anetheron_vampiric_aura'),
(39372,  'spell_item_frozen_shadoweave'),
(39446,  'spell_item_aura_of_madness'),
(40438,  'spell_pri_item_t6_trinket'),
(40442,  'spell_dru_item_t6_trinket'),
(41404,  'spell_item_dementia'),

(37381,  'spell_item_pet_healing'),

(37377,  'spell_warl_t4_2p_bonus_shadow'),
(39437,  'spell_warl_t4_2p_bonus_fire'),

(42770,  'spell_uk_second_wind'),
(45481,  'spell_item_sunwell_exalted_caster_neck'),
(45482,  'spell_item_sunwell_exalted_melee_neck'),
(45483,  'spell_item_sunwell_exalted_tank_neck'),
(45484,  'spell_item_sunwell_exalted_healer_neck'),

(-18094, 'spell_warl_glyph_of_corruption_nightfall'),
(56218,  'spell_warl_glyph_of_corruption_nightfall'),

(54754,  'spell_dru_glyph_of_rejuvenation'),
(54815,  'spell_dru_glyph_of_shred'),
(54821,  'spell_dru_glyph_of_rake'),
(54832,  'spell_dru_glyph_of_innervate'),
(54845,  'spell_dru_glyph_of_starfire_dummy'),
(55677,  'spell_pri_glyph_of_dispel_magic'),
(56372,  'spell_mage_glyph_of_ice_block'),
(56374,  'spell_mage_glyph_of_icy_veins'),
(56375,  'spell_mage_glyph_of_polymorph'),
(56800,  'spell_rog_glyph_of_backstab'),
(57870,  'spell_hun_glyph_of_mend_pet'),
(58375,  'spell_warr_glyph_of_blocking'),
(57989,  'spell_pri_shadowfiend_death'),
(58642,  'spell_dk_glyph_of_scourge_strike'),
(58914,  'spell_hun_kill_command_pet'),

(37447,  'spell_mage_imp_mana_gems'),
(61062,  'spell_mage_imp_mana_gems'),

(52723,  'spell_gen_vampiric_touch'),
(60501,  'spell_gen_vampiric_touch'),
(63320,  'spell_warl_glyph_of_life_tap'),
(65032,  'spell_xt002_321_boombot_aura'),
(69755,  'spell_item_purified_shard_of_the_scale'),
(69739,  'spell_item_shiny_shard_of_the_scale'),
(70723,  'spell_dru_t10_balance_4p_bonus'),
(70664,  'spell_dru_t10_restoration_4p_bonus_dummy'),
(70770,  'spell_pri_t10_heal_2p_bonus'),
(71519,  'spell_item_deathbringers_will_normal'),
(71562,  'spell_item_deathbringers_will_heroic');
