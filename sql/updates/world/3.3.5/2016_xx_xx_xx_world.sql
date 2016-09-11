DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=59725;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 59725, 0, 0, 33, 0, 1, 0, 0, 1, 0, 0, '', 'Spell Improved Spell Reflection (effect 0) will hit the potential target of the spell if target is not the same as condition target.');

DELETE FROM `command` WHERE `name`='reload spell_proc_event';
DELETE FROM `spell_proc` WHERE `SpellId` IN (-1463, -11185, -29441, -29834, -31571, -31871, -44445, -48539, -59088, 24658, 28716, 28744, 32216, 32409, 42770, 56372, 56374, 56375, 58375, 58642, 37447, 61062, 63320, 65032, 69755, 69739, 71519, 71562);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(-1463,  0, 3, 0x00000000, 0x00000000, 0x00000000,      0, 0x1, 0x4, 1024, 0, 0, 0,   0, 0), -- Mana Shield
(-11185, 0, 3, 0x00000080, 0x00000000, 0x00000000,  65536, 0x1, 0x2,    0, 2, 0, 0,   0 ,0), -- Improved Blizzard
(-29441, 0, 3, 0x00000000, 0x00000000, 0x00000000,      0, 0x7, 0x4,    8, 0, 0, 0,   1, 0), -- Magic Absorption
(-29834, 0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x5, 0x2,    0, 0, 0, 0,   0, 0), -- Second Wind (Warrior talent)
(-31571, 0, 3, 0x00000000, 0x00000022, 0x00000008,  16384, 0x7, 0x4,    0, 0, 0, 0,   0, 0), -- Arcane Potency
(-31871, 0,10, 0x00000010, 0x00000000, 0x00000000,  16384, 0x4, 0x2,    0, 0, 0, 0,   0, 0), -- Divine Purpose
(-44445, 0, 3, 0x00000013, 0x00011000, 0x00000000,      0, 0x1, 0x2,    0, 0, 0, 0,   0, 0), -- Hot Streak
(-48539, 0, 7, 0x00000010, 0x04000000, 0x00000000, 262144, 0x2, 0x2,    0, 0, 0, 0,   0, 0), -- Revitalize
(-59088, 0, 4, 0x00000000, 0x00000002, 0x00000000,   1024, 0x4, 0x4,    0, 0, 0, 0,   0, 0), -- Improved Spell Reflection
(24658,  0, 0, 0x00000000, 0x00000000, 0x00000000,  87376, 0x7, 0x2,    0, 0, 0, 0,   0, 0), -- Unstable Power
(28716,  0, 7, 0x00000010, 0x00000000, 0x00000000, 262144, 0x2, 0x2,    0, 0, 0, 0,   0, 0), -- Rejuvenation - Dreamwalker Raiment 2pc
(28744,  0, 7, 0x00000040, 0x00000000, 0x00000000, 278528, 0x2, 0x2,    0, 0, 0, 0,   0, 0), -- Regrowth - Dreamwalker Raiment 6pc
(32216,  0, 4, 0x00000000, 0x00000100, 0x00000000,     16, 0x1, 0x4,    0, 0, 0, 0,   0, 1), -- Victorious (drop charge on Victory rush cast)
(32409,  0, 0, 0x00000000, 0x00002000, 0x00000000,      0, 0x1, 0x4,    0, 0, 0, 0,   0, 0), -- Shadow Word: Death - do not require honor target
(42770,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x5, 0x2,    0, 0, 0, 0,   0, 0), -- Second Wind (NPC aura)
(56372,  0, 3, 0x00000000, 0x00000080, 0x00000000,  16384, 0x4, 0x4,    0, 0, 0, 0,   0, 0), -- Glyph of Ice Block
(56374,  0, 3, 0x00000000, 0x00004000, 0x00000008,  16384, 0x4, 0x4,    0, 0, 0, 0,   0, 0), -- Glyph of Icy Veins
(56375,  0, 3, 0x01000000, 0x00000000, 0x00000000,  65536, 0x4, 0x4,    0, 0, 0, 0,   0, 0), -- Glyph of Polymorph
(58375,  0, 4, 0x00000000, 0x00000200, 0x00000000,     16, 0x1, 0x2,    0, 0, 0, 0,   0, 0), -- Glyph of Blocking
(58642,  0,15, 0x00000000, 0x08000000, 0x00000000,     16, 0x1, 0x4,    0, 0, 0, 0,   0, 0), -- Glyph of Scourge Strike
(37447,  0, 3, 0x00000000, 0x00000100, 0x00000000,  16384, 0x4, 0x2,    0, 0, 0, 0,   0, 0), -- Improved Mana Gems
(61062,  0, 3, 0x00000000, 0x00000100, 0x00000000,  16384, 0x4, 0x2,    0, 0, 0, 0,   0, 0), -- Improved Mana Gems
(63320,  0, 5, 0x80040000, 0x00000000, 0x00008000,   1024, 0x7, 0x4,    0, 0, 0, 0,   0, 0), -- Glyph of Life Tap
(65032,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x7, 0x4,    0, 0, 0, 0,   0, 0), -- 321-Boombot Aura - do not require experience target
(69755,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x7, 0x4,    0, 0, 0, 0,  45, 0), -- Purified Shard of the Scale
(69739,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x7, 0x4,    0, 0, 0, 0,  45, 0), -- Shiny Shard of the Scale
(71519,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x1, 0x4,    0, 0, 0, 0, 105, 0), -- Deathbringer's Will
(71562,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x1, 0x4,    0, 0, 0, 0, 105, 0); -- Deathbringer's Will (Heroic)
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_mage_imp_blizzard','spell_mage_magic_absorption','spell_warr_second_wind','spell_mage_arcane_potency','spell_pal_divine_purpose','spell_mage_hot_streak','spell_item_unstable_power','spell_item_restless_strength','spell_dru_revitalize','spell_warr_improved_spell_reflection','spell_twisted_reflection','spell_dru_t3_2p_bonus','spell_dru_t3_6p_bonus','spell_mark_of_malice','spell_anetheron_vampiric_aura','spell_item_aura_of_madness','spell_item_dementia','spell_uk_second_wind','spell_item_sunwell_exalted_caster_neck','spell_item_sunwell_exalted_melee_neck','spell_item_sunwell_exalted_tank_neck','spell_item_sunwell_exalted_healer_neck','spell_mage_glyph_of_ice_block','spell_mage_glyph_of_icy_veins','spell_mage_glyph_of_polymorph','spell_warr_glyph_of_blocking','spell_pri_shadowfiend_death','spell_dk_glyph_of_scourge_strike','spell_hun_kill_command_pet','spell_mage_imp_mana_gems','spell_gen_vampiric_touch','spell_warl_glyph_of_life_tap','spell_xt002_321_boombot_aura','spell_item_purified_shard_of_the_scale','spell_item_shiny_shard_of_the_scale','spell_item_deathbringers_will_normal','spell_item_deathbringers_will_heroic');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-11185, 'spell_mage_imp_blizzard'),
(-29441, 'spell_mage_magic_absorption'),
(-29834, 'spell_warr_second_wind'),
(-31571, 'spell_mage_arcane_potency'),
(-31871, 'spell_pal_divine_purpose'),
(-44445, 'spell_mage_hot_streak'),
(-48539, 'spell_dru_revitalize'),
(-59088, 'spell_warr_improved_spell_reflection'),
(21063,  'spell_twisted_reflection'),
(24658,  'spell_item_unstable_power'),
(24661,  'spell_item_restless_strength'),
(28716,  'spell_dru_t3_2p_bonus'),
(28744,  'spell_dru_t3_6p_bonus'),
(33493,  'spell_mark_of_malice'),
(38196,  'spell_anetheron_vampiric_aura'),
(39446,  'spell_item_aura_of_madness'),
(41404,  'spell_item_dementia'),
(42770,  'spell_uk_second_wind'),
(45481,  'spell_item_sunwell_exalted_caster_neck'),
(45482,  'spell_item_sunwell_exalted_melee_neck'),
(45483,  'spell_item_sunwell_exalted_tank_neck'),
(45484,  'spell_item_sunwell_exalted_healer_neck'),
(56372,  'spell_mage_glyph_of_ice_block'),
(56374,  'spell_mage_glyph_of_icy_veins'),
(56375,  'spell_mage_glyph_of_polymorph'),
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
(71519,  'spell_item_deathbringers_will_normal'),
(71562,  'spell_item_deathbringers_will_heroic');
