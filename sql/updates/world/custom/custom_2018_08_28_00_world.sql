DELETE FROM `spawn_group` WHERE `spawnId` IN (328052, 328324, 334607, 334694, 334855, 10873, 11348, 14387, 15031, 17874, 19107, 21584, 21594, 21692, 23229, 24268, 26987, 29241, 32333, 33115, 37085, 40210, 41759, 50381, 93194, 93301);

DELETE FROM `reference_loot_template` WHERE `Entry` IN (495410, 495411, 497120, 297110, 10100, 10101, 43401, 43403, 43405, 43407);

INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(497120, 63465, 0, 1, 1, 1, 1),
(497120, 63463, 0, 1, 1, 1, 1),
(497120, 63459, 0, 1, 1, 1, 1),
(497120, 63462, 0, 1, 1, 1, 1),
(497120, 63458, 0, 1, 1, 1, 1),
(497120, 63457, 0, 1, 1, 1, 1),
(497120, 63464, 0, 1, 1, 1, 1),
(497120, 63460, 0, 1, 1, 1, 1),
(497120, 63456, 0, 1, 1, 1, 1),
(497120, 63461, 0, 1, 1, 1, 1);

DELETE FROM `creature_loot_template` WHERE `entry` IN (49541, 49712);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `Reference`, `MaxCount`) VALUES
(49541, 495410, 100, 1, 495410, 2),
(49541, 52078, 100, 1, 0, 1), -- Chaos Orb
(49712, 497120, 100, 1, 497120, 2),
(49712, 52078, 100, 1, 0, 1); -- Chaos Orb

UPDATE `gameobject_template` SET `ScriptName`= 'go_cheer_speaker' WHERE `entry`= 180749;

DELETE FROM `item_script_names` WHERE `ScriptName`= 'item_generic_limit_chance_above_60';

INSERT INTO `item_script_names` (`Id`, `ScriptName`) VALUES
(19169, 'item_generic_limit_chance_above_60');

DELETE FROM `creature_loot_template` WHERE `Entry` IN (46964, 49712);
DELETE FROM `reference_loot_template` WHERE `Entry` IN (469640, 497120, 497121);

INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(495410, 63487, 0, 1, 1, 1, 1), -- Book of the Well Sung Song
(495410, 63480, 0, 1, 1, 1, 1), -- Record of the Broderhood's End
(495410, 63479, 0, 1, 1, 1, 1), -- Bracers of Some Consequence
(495410, 63478, 0, 1, 1, 1, 1), -- Stonemanons's Helm
(495410, 65178, 0, 1, 1, 1, 1), -- VanCleef's Boots
(495410, 63485, 0, 1, 1, 1, 1), -- Cowl of Rebellion
(495410, 63482, 0, 1, 1, 1, 1), -- Daughter's Hand
(495410, 63483, 0, 1, 1, 1, 1), -- Guildmaster's Greaves
(495410, 63486, 0, 1, 1, 1, 1), -- Shackles of the Betrayed
(495410, 63484, 0, 1, 1, 1, 1); -- Armbands of Exiled Architects

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (5470, 5315);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_item_toc25_normal_caster_trinket',
'spell_item_toc25_heroic_caster_trinket',
'spell_item_darkmoon_card_greatness',
'spell_item_charm_witch_doctor',
'spell_item_mana_drain',
'spell_item_thunder_capacitor',
'spell_item_lightning_capacitor',
'spell_item_death_choice',
'spell_item_soul_preserver',
'spell_item_harm_prevention_belt',
'spell_gen_clear_fear_poly',
'spell_gen_blood_reserve',
'spell_igb_battle_experience_check',
'spell_combined_toxins',
'spell_collecting_fallout');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(67712, 'spell_item_toc25_normal_caster_trinket'),
(67758, 'spell_item_toc25_heroic_caster_trinket'),
(57345, 'spell_item_darkmoon_card_greatness'),
(43820, 'spell_item_charm_witch_doctor'),
(27522, 'spell_item_mana_drain'),
(54841, 'spell_item_thunder_capacitor'),
(37657, 'spell_item_lightning_capacitor'),
(67702, 'spell_item_death_choice'),
(60510, 'spell_item_soul_preserver'),
(13234, 'spell_item_harm_prevention_belt'),
(8129,  'spell_gen_clear_fear_poly'),
(64568, 'spell_gen_blood_reserve'),
(71201, 'spell_igb_battle_experience_check'),
(56584, 'spell_combined_toxins'),
(12709, 'spell_collecting_fallout');

DELETE FROM `areatrigger_scripts` WHERE `ScriptName` IN
('at_nearby_scarshield_infiltrator');

INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(1946, 'at_nearby_scarshield_infiltrator');
