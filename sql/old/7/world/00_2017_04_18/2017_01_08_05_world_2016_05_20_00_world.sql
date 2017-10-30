DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_dk_advantage_t10_4p',
'spell_dru_forms_trinket',
'spell_gen_blood_reserve',
'spell_hun_t9_4p_bonus',
'spell_igb_battle_experience_check',
'spell_item_soul_preserver',
'spell_item_death_choice',
'spell_item_lightning_capacitor',
'spell_item_thunder_capacitor',
'spell_item_toc25_normal_caster_trinket',
'spell_item_toc25_heroic_caster_trinket',
'spell_item_darkmoon_card_greatness',
'spell_item_mana_drain',
'spell_mage_blazing_speed',
'spell_rog_t10_2p_bonus',
'spell_sha_lightning_shield');

INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(70656, 'spell_dk_advantage_t10_4p'),                   -- DK Advantage t10 4p melee
(37336, 'spell_dru_forms_trinket'),                     -- Druid Forms Trinket
(64568, 'spell_gen_blood_reserve'),                     -- Blood Reserve (weapon enchant proc)
(67151, 'spell_hun_t9_4p_bonus'),                       -- Hunter T9 Bonus
(71201, 'spell_igb_battle_experience_check'),           -- Battle Experience (Gunship - ICC)
(60510, 'spell_item_soul_preserver'),                   -- Soul Preserver
(67702, 'spell_item_death_choice'),                     -- Death Choice Trinket
(67771, 'spell_item_death_choice'),                     -- Death Choice Trinket
(37657, 'spell_item_lightning_capacitor'),              -- Lightning Capcitor
(54841, 'spell_item_thunder_capacitor'),                -- Thunder Capacitor
(67712, 'spell_item_toc25_normal_caster_trinket'),      -- Item - Coliseum 25 Normal Caster Trinket
(67758, 'spell_item_toc25_heroic_caster_trinket'),      -- Item - Coliseum 25 Heroic Caster Trinket
(57345, 'spell_item_darkmoon_card_greatness'),          -- Darkmoon Card: Greatness
(27522, 'spell_item_mana_drain'),                       -- Mana Drain
(40336, 'spell_item_mana_drain'),                       -- Mana Drain
(70805, 'spell_rog_t10_2p_bonus');                      -- Rogue T10 2P bonus
