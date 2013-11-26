-- Pilgrim's Bounty event


-- Achievement: Pilgrim's Paunch
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (11078,11079,11080,11081,11082,11083,11084,11085);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`) VALUES
-- Alliance
(11078, 6, 1657, 0),  -- Darnassus
(11078, 16, 404, 0),  -- Darnassus
(11079, 6, 809, 0),   -- Ironforge
(11079, 16, 404, 0),  -- Ironforge
(11080, 6, 3557, 0),  -- Exodar
(11080, 16, 404, 0),  -- Exodar
(11081, 6, 12, 0),    -- Stormwind
(11081, 16, 404, 0),  -- Stormwind
-- Horde
(11082, 6, 14, 0),    -- Orgrimmar
(11082, 16, 404, 0),  -- Orgrimmar
(11083, 6, 3470, 0),  -- Silvermoon City
(11083, 16, 404, 0),  -- Silvermoon City
(11084, 6, 1638, 0),  -- Thunder Bluff
(11084, 16, 404, 0),  -- Thunder Bluff
(11085, 6, 1497, 0),  -- Undercity
(11085, 16, 404, 0);  -- Undercity

-- Achievement: "FOOD FIGHT!"
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (11168,11178,11179,11180,11181);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(11168, 11, 0, 0, 'TW_achievement_food_fight'),
(11168, 16, 404, 0, ''),
(11178, 11, 0, 0, 'TW_achievement_food_fight'),
(11178, 16, 404, 0, ''),
(11179, 11, 0, 0, 'TW_achievement_food_fight'),
(11179, 16, 404, 0, ''),
(11180, 11, 0, 0, 'TW_achievement_food_fight'),
(11180, 16, 404, 0, ''),
(11181, 11, 0, 0, 'TW_achievement_food_fight'),
(11181, 16, 404, 0, '');


-- Achievement: The Turkinator
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=32820;
DELETE FROM `smart_scripts` WHERE `entryorguid`=32820 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(32820,0,0,0,6,0,100,0,0,0,0,0,85,62014,2,0,0,0,0,7,0,0,0,0,0,0,0,'On death - Cast Turkey Marker');

-- Item: Turkey Caller
UPDATE `creature_template` SET `faction_A`=35, `faction_H`=35, `ScriptName` = 'TW_npc_lonely_turkey' WHERE `entry` =32956; -- Lonely Turkey

-- Achievement: The Turkinator
DELETE FROM `spell_script_names` WHERE `ScriptName`='TW_spell_gen_turkey_tracker';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(62014, 'TW_spell_gen_turkey_tracker'); -- Turkey Tracker

-- Feast On Spells
DELETE FROM `spell_script_names` WHERE `ScriptName`='TW_spell_gen_feast_on';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(61784, 'TW_spell_gen_feast_on'), -- Feast On Turkey
(61785, 'TW_spell_gen_feast_on'), -- Feast On Cranberries
(61786, 'TW_spell_gen_feast_on'), -- Feast On Sweet Potatoes
(61787, 'TW_spell_gen_feast_on'), -- Feast On Pie
(61788, 'TW_spell_gen_feast_on'); -- Feast On Stuffing

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'TW_spell_gen_well_fed_pilgrims_bounty_ap',
'TW_spell_gen_well_fed_pilgrims_bounty_zm',
'TW_spell_gen_well_fed_pilgrims_bounty_hit',
'TW_spell_gen_well_fed_pilgrims_bounty_haste',
'TW_spell_gen_well_fed_pilgrims_bounty_spirit');
INSERT INTO `spell_script_names` (`spell_id` ,`ScriptName`) VALUES
(61807, 'TW_spell_gen_well_fed_pilgrims_bounty_ap'),     -- A Serving of Turkey
(61804, 'TW_spell_gen_well_fed_pilgrims_bounty_zm'),     -- A Serving of Cranberries
(61806, 'TW_spell_gen_well_fed_pilgrims_bounty_hit'),    -- A Serving of Stuffing
(61808, 'TW_spell_gen_well_fed_pilgrims_bounty_haste'),  -- A Serving of Sweet Potatoes
(61805, 'TW_spell_gen_well_fed_pilgrims_bounty_spirit'); -- A Serving of Pie

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'TW_spell_gen_on_plate_pilgrims_bounty_turkey',
'TW_spell_gen_on_plate_pilgrims_bounty_cranberries',
'TW_spell_gen_on_plate_pilgrims_bounty_stuffing',
'TW_spell_gen_on_plate_pilgrims_bounty_sweet_potatoes',
'TW_spell_gen_on_plate_pilgrims_bounty_pie');
INSERT INTO `spell_script_names` (`spell_id` ,`ScriptName`) VALUES
(66250, 'TW_spell_gen_on_plate_pilgrims_bounty_turkey'),            -- Pass The Turkey
(66261, 'TW_spell_gen_on_plate_pilgrims_bounty_cranberries'),       -- Pass The Cranberries
(66259, 'TW_spell_gen_on_plate_pilgrims_bounty_stuffing'),          -- Pass The Stuffing
(66262, 'TW_spell_gen_on_plate_pilgrims_bounty_sweet_potatoes'),    -- Pass The Sweet Potatoes
(66260, 'TW_spell_gen_on_plate_pilgrims_bounty_pie');               -- Pass The Pie

DELETE FROM `spell_script_names` WHERE `ScriptName`='TW_spell_gen_bountiful_feast';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(66477, 'TW_spell_gen_bountiful_feast'); -- Bountiful Feast

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'TW_spell_gen_slow_roasted_turkey',
'TW_spell_gen_cranberry_chutney',
'TW_spell_gen_spice_bread_stuffing',
'TW_spell_gen_pumpkin_pie',
'TW_spell_gen_candied_sweet_potato');
INSERT INTO `spell_script_names` (`spell_id` ,`ScriptName`) VALUES
(65422, 'TW_spell_gen_slow_roasted_turkey'),   -- Slow-Roasted Turkey
(65420, 'TW_spell_gen_cranberry_chutney'),     -- Cranberry Chutney
(65419, 'TW_spell_gen_spice_bread_stuffing'),  -- Spice Bread Stuffing
(65421, 'TW_spell_gen_pumpkin_pie'),           -- Pumpkin Pie
(65418, 'TW_spell_gen_candied_sweet_potato');  -- Candied Sweet Potato

-- Temp Hack Fixes
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (32823,32830,32840);
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (32823,32830,32840);
-- Pilgrims Bounty: Chair hack root
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=65403;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(65403, 18373, 2, 'hack root pilgrim chairs');
