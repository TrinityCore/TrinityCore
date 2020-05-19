DELETE FROM `creature_text` WHERE `CreatureID`= 54601;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(54601, 0, 0, 'Hammer time!', 12, 0, 100, 70, 0, 0, 53469, 'Mola to Player'),
(54601, 0, 1, 'Whack some gnolls! Step right up and whack some gnolls!', 12, 0, 100, 70, 0, 0, 53470, 'Mola to Player'),
(54601, 0, 2, 'Hammer swingin\' fun! Who wants to swing a hammer?', 12, 0, 100, 70, 0, 0, 53471, 'Mola to Player'),
(54601, 0, 3, 'Swing a hammer, win a prize!', 12, 0, 100, 70, 0, 0, 53472, 'Mola to Player'),
(54601, 1, 0, 'Please stay out of the gaming area.', 42, 0, 100, 0, 0, 0, 56891, 'Mola to Player');

-- Creature Mola 54601 SAI
SET @ENTRY := 54601;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 13018, 1, 0, 0, 28, 101612, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On gossip action 1 from menu 13018 selected - Action invoker: Remove aura due to spell Whack-a-Gnoll! (101612) // "),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 134, 110230, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, " Linked - if avaliable, last used invoker will cast spellId: Whack-a-Gnoll! (110230) with castFlags on Action invoker // "),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 11, 102188, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell Mallet Gossip (102188) on Action invoker // "),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 57, 71083, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, " Linked - Action invoker: Remove item 1x71083 // "),
(@ENTRY, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 134, 101995, 2, 0, 0, 0, 0, 10, 290754, 0, 0, 0, 0, 0, 0, " Linked - if avaliable, last used invoker will cast spellId: Whack! Summon Gnoll Holder (101995) with castFlags on Creature Whack-a-Gnoll Barrel 54546 (290754) // "),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 134, 101995, 2, 0, 0, 0, 0, 10, 290755, 0, 0, 0, 0, 0, 0, " Linked - if avaliable, last used invoker will cast spellId: Whack! Summon Gnoll Holder (101995) with castFlags on Creature Whack-a-Gnoll Barrel 54546 (290755) // "),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 134, 101995, 2, 0, 0, 0, 0, 10, 290756, 0, 0, 0, 0, 0, 0, " Linked - if avaliable, last used invoker will cast spellId: Whack! Summon Gnoll Holder (101995) with castFlags on Creature Whack-a-Gnoll Barrel 54546 (290756) // "),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 134, 101995, 2, 0, 0, 0, 0, 10, 290757, 0, 0, 0, 0, 0, 0, " Linked - if avaliable, last used invoker will cast spellId: Whack! Summon Gnoll Holder (101995) with castFlags on Creature Whack-a-Gnoll Barrel 54546 (290757) // "),
(@ENTRY, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 134, 101995, 2, 0, 0, 0, 0, 10, 290759, 0, 0, 0, 0, 0, 0, " Linked - if avaliable, last used invoker will cast spellId: Whack! Summon Gnoll Holder (101995) with castFlags on Creature Whack-a-Gnoll Barrel 54546 (290759) // "),
(@ENTRY, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 134, 101995, 2, 0, 0, 0, 0, 10, 290760, 0, 0, 0, 0, 0, 0, " Linked - if avaliable, last used invoker will cast spellId: Whack! Summon Gnoll Holder (101995) with castFlags on Creature Whack-a-Gnoll Barrel 54546 (290760) // "),
(@ENTRY, 0, 10, 11, 61, 0, 100, 0, 0, 0, 0, 0, 134, 101995, 2, 0, 0, 0, 0, 10, 290761, 0, 0, 0, 0, 0, 0, " Linked - if avaliable, last used invoker will cast spellId: Whack! Summon Gnoll Holder (101995) with castFlags on Creature Whack-a-Gnoll Barrel 54546 (290761) // "),
(@ENTRY, 0, 11, 12, 61, 0, 100, 0, 0, 0, 0, 0, 134, 101995, 2, 0, 0, 0, 0, 10, 290763, 0, 0, 0, 0, 0, 0, " Linked - if avaliable, last used invoker will cast spellId: Whack! Summon Gnoll Holder (101995) with castFlags on Creature Whack-a-Gnoll Barrel 54546 (290763) // "),
(@ENTRY, 0, 12, 13, 61, 0, 100, 0, 0, 0, 0, 0, 134, 101995, 2, 0, 0, 0, 0, 10, 290762, 0, 0, 0, 0, 0, 0, " Linked - if avaliable, last used invoker will cast spellId: Whack! Summon Gnoll Holder (101995) with castFlags on Creature Whack-a-Gnoll Barrel 54546 (290762) // "),
(@ENTRY, 0, 13, 14, 61, 0, 100, 0, 0, 0, 0, 0, 134, 101996, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, " Linked - if avaliable, last used invoker will cast spellId: Gnoll Aura - Okay to Hit (101996) with castFlags on Action invoker // "),
(@ENTRY, 0, 14, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, " Linked - Action invoker: Close gossip // "),
(@ENTRY, 0, 15, 0, 60, 0, 100, 0, 1000, 10000, 50000, 50000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 50000 and 50000 ms (for the first time, timer between 1000 and 10000 ms) - Self: Talk 0 // "),
(@ENTRY, 0, 16, 0, 31, 0, 100, 0, 109977, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "When spell Stay Out! (109977)  hits a target - Action invoker: Talk 1 // ");

DELETE FROM `areatrigger_scripts` WHERE `ScriptName`= 'AreaTrigger_at_darkmoon_island_gaming_area';
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(7344, 'AreaTrigger_at_darkmoon_island_gaming_area');
