delete from npc_spellclick_spells where npc_entry in (59464, 56718);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(59464, 46598, 1, 0),
(56718, 46598, 1, 0);

delete from vehicle_template_accessory where accessory_entry = 59429;
INSERT INTO `vehicle_template_accessory` (`EntryOrAura`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES 
(59464, 59429, 0, 1, 'Explosive Brew Barrel', 6, 30000),
(56718, 59429, 0, 1, 'Explosive Brew Barrel', 6, 30000);

update creature_template set AIName = 'SmartAI' where entry in (59426,59551,60276);
delete from smart_scripts where entryorguid in (59426,59551,60276);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(59426, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 114531, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Death - Cast Drop Hammer Cosmetic'),
(59551, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 114531, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Death - Cast Drop Hammer Cosmetic'),
(60276, 0, 0, 1, 8, 0, 100, 0, 116027, 0, 0, 0, 11, 116271, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spellhit - AchievCredit'),
(60276, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - Death');

delete from creature_template_addon where entry in (59426,59551);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(59426, 0, 0, 0, 1, 0, '114530'),
(59551, 0, 0, 0, 1, 0, '114530');
