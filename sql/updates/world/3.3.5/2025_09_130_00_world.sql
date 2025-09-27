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

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (65684,67176,67177,67178,65686,67222,67223,67224);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_twin_valkyr_dark_essence',
'spell_twin_valkyr_light_essence');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(65684, 'spell_twin_valkyr_dark_essence'),
(67176, 'spell_twin_valkyr_dark_essence'),
(67177, 'spell_twin_valkyr_dark_essence'),
(67178, 'spell_twin_valkyr_dark_essence'),
(65686, 'spell_twin_valkyr_light_essence'),
(67222, 'spell_twin_valkyr_light_essence'),
(67223, 'spell_twin_valkyr_light_essence'),
(67224, 'spell_twin_valkyr_light_essence');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 55814;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_eck_spit';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(55814, 'spell_eck_spit');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (53288,53311);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_grizzly_hills_flight_onequah_to_lights_breach',
'spell_grizzly_hills_flight_westfall_to_lights_breach');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(53288, 'spell_grizzly_hills_flight_onequah_to_lights_breach'),
(53311, 'spell_grizzly_hills_flight_westfall_to_lights_breach');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (55428,55480,55500,55501,55502,55503);

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 57387;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_icecrown_argent_cannon_assault';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(57387, 'spell_icecrown_argent_cannon_assault');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 57787;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_icecrown_forcecast_bridenbrad_ascension';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(57787, 'spell_icecrown_forcecast_bridenbrad_ascension');

UPDATE `creature_template` SET `AIName` = '' WHERE `entry` = 30562;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30562 AND `source_type` = 0;

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = -57350;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_item_darkmoon_card_illusion';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(57350, 'spell_item_darkmoon_card_illusion');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = -38708;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_hellfire_peninsula_demonaic_visitation';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(38708, 'spell_hellfire_peninsula_demonaic_visitation');
