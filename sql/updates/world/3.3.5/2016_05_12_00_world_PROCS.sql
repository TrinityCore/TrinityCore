DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_mage_blazing_speed','spell_pri_blessed_recovery','spell_dru_forms_trinket','spell_dru_t9_feral_relic',
'spell_sha_nature_guardian','spell_warl_nether_protection','spell_hun_piercing_shots','spell_hun_t9_4p_bonus',
'spell_sha_lightning_shield','spell_dk_acclimation','spell_dk_advantage_t10_4p','spell_dk_improved_blood_presence_triggered',
'spell_rog_t10_2p_bonus','spell_pal_illumination','spell_item_soul_preserver','spell_item_death_choice','spell_item_trinket_stack',
'spell_igb_battle_experience_check','spell_gen_blood_reserve');
 
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(-31641, 'spell_mage_blazing_speed'), -- Mage Blazing Speed
(-27811, 'spell_pri_blessed_recovery'), -- Priest Blessed Recovery
(37336, 'spell_dru_forms_trinket'), -- Druid Forms Trinket
(67353, 'spell_dru_t9_feral_relic'), -- Druid T9 Feral Relic (Idol of Mutilation)
(-30881, 'spell_sha_nature_guardian'), -- Shaman Nature's Guardian
(-30299, 'spell_warl_nether_protection'), -- Warlock Nether protection
(-53234, 'spell_hun_piercing_shots'), -- Hunter Piercing Shots
(-67151, 'spell_hun_t9_4p_bonus'), -- Hunter T9 Bonus
(-324, 'spell_sha_lightning_shield'), -- Shaman Lightning Shield
(-49200, 'spell_dk_acclimation'), -- DK Acclimation
(70656, 'spell_dk_advantage_t10_4p'), -- DK Advantage t10 4p melee
(63611, 'spell_dk_improved_blood_presence_triggered'), -- DK Improved blood Presence Triggered
(70805, 'spell_rog_t10_2p_bonus'), -- Rogue T10 2P bonus
(-20210, 'spell_pal_illumination'), -- Paladin Illumination (for Holy Shock)
(60510, 'spell_item_soul_preserver'), -- Soul Preserver
(67702, 'spell_item_death_choice'), -- Death Choice Trinket
(67771, 'spell_item_death_choice'), -- Death Choice Trinket
(37657, 'spell_item_trinket_stack'), -- ToC 25 Caster Trinket
(54841, 'spell_item_trinket_stack'), -- ToC 25 Caster Trinket
(67712, 'spell_item_trinket_stack'), -- ToC 25 Caster Trinket
(67758, 'spell_item_trinket_stack'), -- ToC 25 Caster Trinket
(71201, 'spell_igb_battle_experience_check'), -- Battle Experience (Gunship - ICC)
(64568, 'spell_gen_blood_reserve'); -- Blood Reserve (no idea what this is)
