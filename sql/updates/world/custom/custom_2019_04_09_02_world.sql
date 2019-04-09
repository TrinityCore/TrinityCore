-- Creature Jessica Rogers 54485 SAI
SET @ENTRY := 54485;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 13012, 1, 0, 0, 57, 71083, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On gossip action 1 from menu 13012 selected - Action invoker: Remove item 1x71083 // "),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 101808, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell Ring Toss Gossip (101808) on Action invoker // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, " Linked - Action invoker: Close gossip // ");

-- Creature Mola 54601 SAI
SET @ENTRY := 54601;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 13018, 1, 0, 0, 28, 101612, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On gossip action 1 from menu 13018 selected - Action invoker: Remove aura due to spell Whack-a-Gnoll! (101612) // "),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 134, 110230, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, " Linked - Invoker: Cast spell Whack-a-Gnoll! (110230) to Action invoker // "),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 11, 102188, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell Mallet Gossip (102188) on Action invoker // "),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 57, 71083, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, " Linked - Action invoker: Remove item 1x71083 // "),
(@ENTRY, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 134, 101995, 2, 0, 0, 0, 0, 10, 290754, 0, 0, 0, 0, 0, 0, " Linked - Invoker: Cast spell Whack! Summon Gnoll Holder (101995) to Creature Whack-a-Gnoll Barrel 54546 (290754) // "),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 134, 101995, 2, 0, 0, 0, 0, 10, 290755, 0, 0, 0, 0, 0, 0, " Linked - Invoker: Cast spell Whack! Summon Gnoll Holder (101995) to Creature Whack-a-Gnoll Barrel 54546 (290755) // "),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 134, 101995, 2, 0, 0, 0, 0, 10, 290756, 0, 0, 0, 0, 0, 0, " Linked - Invoker: Cast spell Whack! Summon Gnoll Holder (101995) to Creature Whack-a-Gnoll Barrel 54546 (290756) // "),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 134, 101995, 2, 0, 0, 0, 0, 10, 290757, 0, 0, 0, 0, 0, 0, " Linked - Invoker: Cast spell Whack! Summon Gnoll Holder (101995) to Creature Whack-a-Gnoll Barrel 54546 (290757) // "),
(@ENTRY, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 134, 101995, 2, 0, 0, 0, 0, 10, 290759, 0, 0, 0, 0, 0, 0, " Linked - Invoker: Cast spell Whack! Summon Gnoll Holder (101995) to Creature Whack-a-Gnoll Barrel 54546 (290759) // "),
(@ENTRY, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 134, 101995, 2, 0, 0, 0, 0, 10, 290760, 0, 0, 0, 0, 0, 0, " Linked - Invoker: Cast spell Whack! Summon Gnoll Holder (101995) to Creature Whack-a-Gnoll Barrel 54546 (290760) // "),
(@ENTRY, 0, 10, 11, 61, 0, 100, 0, 0, 0, 0, 0, 134, 101995, 2, 0, 0, 0, 0, 10, 290761, 0, 0, 0, 0, 0, 0, " Linked - Invoker: Cast spell Whack! Summon Gnoll Holder (101995) to Creature Whack-a-Gnoll Barrel 54546 (290761) // "),
(@ENTRY, 0, 11, 12, 61, 0, 100, 0, 0, 0, 0, 0, 134, 101995, 2, 0, 0, 0, 0, 10, 290763, 0, 0, 0, 0, 0, 0, " Linked - Invoker: Cast spell Whack! Summon Gnoll Holder (101995) to Creature Whack-a-Gnoll Barrel 54546 (290763) // "),
(@ENTRY, 0, 12, 13, 61, 0, 100, 0, 0, 0, 0, 0, 134, 101995, 2, 0, 0, 0, 0, 10, 290762, 0, 0, 0, 0, 0, 0, " Linked - Invoker: Cast spell Whack! Summon Gnoll Holder (101995) to Creature Whack-a-Gnoll Barrel 54546 (290762) // "),
(@ENTRY, 0, 13, 14, 61, 0, 100, 0, 0, 0, 0, 0, 134, 101996, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, " Linked - Invoker: Cast spell Gnoll Aura - Okay to Hit (101996) to Action invoker // "),
(@ENTRY, 0, 14, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, " Linked - Action invoker: Close gossip // ");

DELETE FROM `gameobject_template` WHERE `entry`= 209296;
INSERT INTO `gameobject_template` (`entry`,`type`, `displayId`, `name`, `size`, `Data0`, `Data1`, `Data3`, `Data6`, `VerifiedBuild`) VALUES
(209296, 8, 2770, '[DND] Spell Focus', 1, 1731, 13, 1, -1, -18019);

DELETE FROM `gameobject` WHERE `guid`= 200889;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
(200889, 209296, 974, 5861, 5870, 169, -3997.79, 6280.09, 13.08, 0.63);

DELETE FROM `conditions` WHERE `SourceEntry` IN (101996, 102137, 102022) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 101996, 0, 0, 31, 0, 3, 54547, 0, 0, 0, '', 'Gnoll Aura - Okay to Hit - Target Darkmoon Faire Gnoll Holder'),
(13, 1, 102022, 0, 0, 31, 0, 3, 54444, 0, 0, 0, '', 'Whack! - Target Darkmoon Faire Gnoll'),
(13, 1, 102022, 0, 1, 31, 0, 3, 54466, 0, 0, 0, '', 'Whack! - Target Darkmoon Faire Gnoll - Baby'),
(13, 1, 102022, 0, 2, 31, 0, 3, 54549, 0, 0, 0, '', 'Whack! - Target Darkmoon Faire Gnoll - Bonus'),
(13, 1, 102137, 0, 0, 31, 0, 3, 54547, 0, 0, 0, '', 'DMF - Whack-a-Gnoll - Player - action bar removed - Target Darkmoon Faire Gnoll Holder'),
(13, 2, 102137, 0, 0, 31, 0, 3, 54444, 0, 0, 0, '', 'DMF - Whack-a-Gnoll - Player - action bar removed - Target Darkmoon Faire Gnoll'),
(13, 2, 102137, 0, 1, 31, 0, 3, 54466, 0, 0, 0, '', 'DMF - Whack-a-Gnoll - Player - action bar removed - Target Darkmoon Faire Gnoll - Baby'),
(13, 2, 102137, 0, 2, 31, 0, 3, 54549, 0, 0, 0, '', 'DMF - Whack-a-Gnoll - Player - action bar removed - Target Darkmoon Faire Gnoll - Bonus'),
(13, 4, 102137, 0, 2, 31, 0, 3, 54601, 0, 0, 0, '', 'DMF - Whack-a-Gnoll - Player - action bar removed - Target Mola');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_darkmoon_island_whack_summon_aura',
'spell_darkmoon_island_gnoll_aura_okay_to_hit',
'spell_darkmoon_island_whack_dummy',
'spell_darkmoon_island_whack',
'spell_darkmoon_island_whack_a_gnoll',
'spell_darkmoon_island_whack_a_gnoll_player_action_bar_removed');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(101994, 'spell_darkmoon_island_whack_summon_aura'),
(101996, 'spell_darkmoon_island_gnoll_aura_okay_to_hit'),
(101604, 'spell_darkmoon_island_whack_dummy'),
(102022, 'spell_darkmoon_island_whack'),
(101612, 'spell_darkmoon_island_whack_a_gnoll'),
(102137, 'spell_darkmoon_island_whack_a_gnoll_player_action_bar_removed');

UPDATE `creature_template` SET `ScriptName`= 'npc_darkmoon_island_gnoll' WHERE `entry` IN (54444, 54466, 54549);
