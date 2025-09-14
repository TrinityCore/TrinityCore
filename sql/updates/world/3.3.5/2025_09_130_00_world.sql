--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 70653;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_dragonblight_lich_king_zap_player';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(70653, 'spell_dragonblight_lich_king_zap_player');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (69377,69378,69381);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_item_runescroll_of_fortitude',
'spell_item_drums_of_forgotten_kings',
'spell_item_drums_of_the_wild');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(69377, 'spell_item_runescroll_of_fortitude'),
(69378, 'spell_item_drums_of_forgotten_kings'),
(69381, 'spell_item_drums_of_the_wild');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 61613;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_grizzly_hills_ganjo_ressurection';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(61613, 'spell_grizzly_hills_ganjo_ressurection');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 45661;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_felmyst_encapsulate';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(45661, 'spell_felmyst_encapsulate');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (32096,32098);
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_item_thrallmar_and_honor_hold_favor';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(32096, 'spell_item_thrallmar_and_honor_hold_favor'),
(32098, 'spell_item_thrallmar_and_honor_hold_favor');

-- Creature 11350
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 24071;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_zulgurub_axe_flurry';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(24019, 'spell_zulgurub_axe_flurry');

-- Creature 15547
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 29320;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_karazhan_charge';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(29320, 'spell_karazhan_charge');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 39835;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_najentus_needle_spine_explosion';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(39835, 'spell_najentus_needle_spine_explosion');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 45980;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_borean_tundra_re_cursive_transmatter_injection';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(45980, 'spell_borean_tundra_re_cursive_transmatter_injection');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 47585;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_pri_dispersion';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(47585, 'spell_pri_dispersion');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 49039;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_dk_lichborne';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(49039, 'spell_dk_lichborne');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (15237,15430,15431,25331,27799,27800,27801,48077,48078);
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_pri_holy_nova';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-15237, 'spell_pri_holy_nova');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (45719,46651);
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_midsummer_remove_torches';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(46074, 'spell_midsummer_remove_torches');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (45716,46630,-45716,-46630);
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_midsummer_torch_tossing_training_practice';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(45716, 'spell_midsummer_torch_tossing_training_practice'),
(46630, 'spell_midsummer_torch_tossing_training_practice');
