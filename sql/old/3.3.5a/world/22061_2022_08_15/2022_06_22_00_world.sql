--
DELETE FROM `spell_scripts` WHERE `id` IN (23645,23725,24194,24195,38358,45185,47097,47958,57082,47703,47724,50252);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_item_hourglass_sand',
'spell_item_lifegiving_gem',
'spell_quest_uther_grom_tribute',
'spell_fathomlord_karathress_tidal_surge',
'spell_brutallus_stomp',
'spell_dragonblight_surge_needle_teleporter',
'spell_ormorok_summon_crystal_spikes',
'spell_dragonblight_fill_blood_unholy_frost_gem');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(23645,'spell_item_hourglass_sand'),
(23725,'spell_item_lifegiving_gem'),
(24194,'spell_quest_uther_grom_tribute'),
(24195,'spell_quest_uther_grom_tribute'),
(38358,'spell_fathomlord_karathress_tidal_surge'),
(45185,'spell_brutallus_stomp'),
(47097,'spell_dragonblight_surge_needle_teleporter'),
(47958,'spell_ormorok_summon_crystal_spikes'),
(57082,'spell_ormorok_summon_crystal_spikes'),
(47703,'spell_dragonblight_fill_blood_unholy_frost_gem'),
(47724,'spell_dragonblight_fill_blood_unholy_frost_gem'),
(50252,'spell_dragonblight_fill_blood_unholy_frost_gem');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` IN
(24101,24102,24103,24104,69530,24105,24106,24107,24108,69533,47324,47325);

DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (47954,47955,47956,47957);
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`, `spellid2`, `spellid3`) VALUES
(47954,47954,57077,0,0),
(47955,47955,57078,0,0),
(47956,47956,57080,0,0),
(47957,47957,57081,0,0);

UPDATE `spell_script_names` SET `ScriptName` = 'spell_ormorok_crystal_spike' WHERE `ScriptName` = 'spell_crystal_spike';
