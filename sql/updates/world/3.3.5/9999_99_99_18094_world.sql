-- core script (and delete the incomplete SAI)
DELETE FROM `smart_scripts` WHERE `entryorguid`=24210;
UPDATE `creature_template` SET `AIName`='' WHERE `entry`= 24210;
UPDATE `creature_template` SET `ScriptName`='npc_riven_widow_cocoon' WHERE `entry`= 24210;

-- set creatures that spawn to SmartAI (the ones that aren't already)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`= 24219;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`= 24073;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`= 24026;

-- Add an attack summoner on just summoned to each creature. Some of these creatures already have SmartAI, did all this to avoid errors.

DELETE FROM `smart_scripts` WHERE `entryorguid`=24219;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(24219, 0, 0, 0, 54, 0, 100, 512, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Baby Riven Widow  - On Just Summoned - Attack Summoner');

DELETE FROM `smart_scripts` WHERE `entryorguid`=24073;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(24073, 0, 0, 0, 54, 0, 100, 512, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Fearsome Horror  - On Just Summoned - Attack Summoner');

DELETE FROM `smart_scripts` WHERE `entryorguid`=23661;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(23661, 0, 0, 1, 8, 0, 100, 0, 43036, 0, 0, 0, 11, 43059, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Tribesman - On Spellhit \'Dismembering Corpse\' - Cast \'Gruesome, But Necessary: Vrykul On Dismember\''),
(23661, 0, 3, 0, 54, 0, 100, 512, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Tribesman  - On Just Summoned - Attack Summoner'),
(23661, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 43037, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Tribesman - On Aggro - Cast \'Gruesome, But Necessary: Kill Credit\''),
(23661, 0, 2, 0, 0, 0, 100, 0, 1000, 15000, 7200, 35000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Tribesman - In Combat - Say Line 0');

DELETE FROM `smart_scripts` WHERE `entryorguid`=23666;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(23666, 0, 4, 0, 54, 0, 100, 512, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Berserker  - On Just Summoned - Attack Summoner'),
(23666, 0, 0, 1, 8, 0, 100, 0, 43036, 0, 0, 0, 11, 43059, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Berserker - On Spellhit \'Dismembering Corpse\' - Cast \'Gruesome, But Necessary: Vrykul On Dismember\''),
(23666, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 43037, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Berserker - On Spellhit \'Dismembering Corpse\' - Cast \'Gruesome, But Necessary: Kill Credit\''),
(23666, 0, 2, 0, 0, 0, 100, 0, 1000, 15000, 7200, 35000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Berserker - In Combat - Say Line 0'),
(23666, 0, 3, 0, 1, 0, 100, 0, 0, 60000, 15000, 70000, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Berserker - Out of Combat - Say Line 1');

DELETE FROM `smart_scripts` WHERE `entryorguid`=23991;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(23991, 0, 0, 0, 4, 0, 50, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gjalerbron Warrior - On Agro - Say'),
(23991, 0, 1, 0, 54, 0, 100, 512, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Gjalerbron Warrior  - On Just Summoned - Attack Summoner');

DELETE FROM `smart_scripts` WHERE `entryorguid`=23990;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(23990, 0, 0, 0, 4, 0, 50, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gjalerbron Rune-Caster - On Agro - Say'),
(23990, 0, 1, 0, 54, 0, 100, 512, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Gjalerbron Runecaster  - On Just Summoned - Attack Summoner');

DELETE FROM `smart_scripts` WHERE `entryorguid`=23989;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(23989, 0, 0, 0, 4, 0, 50, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gjalerbron Sleep-Watcher - On Agro - Say'),
(23989, 0, 1, 0, 54, 0, 100, 512, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Gjalerbron SleepWatcher  - On Just Summoned - Attack Summoner');

DELETE FROM `smart_scripts` WHERE `entryorguid`=23669;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(23669, 0, 0, 0, 0, 0, 100, 0, 1000, 3500, 3000, 9000, 11, 43083, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Oracle - In Combat - Cast \'Frostbolt\''),
(23669, 0, 1, 2, 8, 0, 100, 0, 43036, 0, 0, 0, 11, 43059, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Oracle - On Spellhit \'Dismembering Corpse\' - Cast \'Gruesome, But Necessary: Vrykul On Dismember\''),
(23669, 0, 1, 0, 54, 0, 100, 512, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Oracle  - On Just Summoned - Attack Summoner'),
(23669, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 43037, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Oracle - On Spellhit \'Dismembering Corpse\' - Cast \'Gruesome, But Necessary: Kill Credit\''),
(23669, 0, 3, 0, 0, 0, 100, 0, 1000, 15000, 7200, 35000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Oracle - In Combat - Say Line 0');

DELETE FROM `smart_scripts` WHERE `entryorguid`=23959;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(23959, 0, 0, 0, 38, 0, 100, 0, 0, 1, 0, 0, 69, 1, 0, 0, 0, 0, 0, 19, 24230, 50, 0, 0, 0, 0, 0, 'Darkclaw Bat - On Data Set 0 1 - Move To Closest Creature \'Feknut\'s Firecrackers Bunny\' (No Repeat) (Dungeon)'),
(23959, 0, 1, 0, 34, 0, 100, 512, 0, 1, 0, 0, 45, 0, 1, 0, 0, 0, 0, 19, 24230, 5, 0, 0, 0, 0, 0, 'Darkclaw Bat - On Reached Point 1 - Set Data 0 1 (No Repeat) (Dungeon)'),
(23959, 0, 2, 0, 54, 0, 100, 512, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Darkclaw Bat  - On Just Summoned - Attack Summoner');

DELETE FROM `smart_scripts` WHERE `entryorguid`=23662;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(23662, 0, 0, 0, 0, 0, 100, 0, 100, 1000, 5000, 14500, 11, 38557, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Woodsman - In Combat - Cast \'Throw\''),
(23662, 0, 1, 0, 0, 0, 100, 0, 1000, 4500, 4900, 8100, 11, 43410, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Woodsman - In Combat - Cast \'Chop\''),
(23662, 0, 2, 3, 8, 0, 100, 0, 43036, 0, 0, 0, 11, 43059, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Woodsman - On Spellhit \'Dismembering Corpse\' - Cast \'Gruesome, But Necessary: Vrykul On Dismember\''),
(23662, 0, 2, 0, 54, 0, 100, 512, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Woodsman  - On Just Summoned - Attack Summoner'),
(23662, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 43037, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Woodsman - On Spellhit \'Dismembering Corpse\' - Cast \'Gruesome, But Necessary: Kill Credit\''),
(23662, 0, 4, 0, 0, 0, 100, 0, 1000, 15000, 7200, 35000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Woodsman - In Combat - Say Line 0');

DELETE FROM `smart_scripts` WHERE `entryorguid`=24026;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(24026, 0, 0, 0, 54, 0, 100, 512, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Fanggore Worg  - On Just Summoned - Attack Summoner');

-- fixes the cocoon being able to attack
UPDATE `creature_template` SET `unit_flags`=131076 WHERE `entry`=24210;
