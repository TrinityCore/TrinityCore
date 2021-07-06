-- Duplicate spawns cleanup
-- Energized Geode
DELETE FROM `creature` WHERE `guid` IN (356424, 350126, 350813, 350812, 350814, 351958, 350122, 351959, 350606, 350373, 350372, 350366);
-- Lodestone Elemental
DELETE FROM `creature` WHERE `guid` IN (350815, 350125, 356817, 350156, 350165, 350171, 356411, 354256, 356806);
-- Living Blood
DELETE FROM `creature` WHERE `guid` IN (354031, 350177, 356412, 350149, 356426, 354028, 356810, 350179, 354030, 354369, 350178, 350180, 356812, 350182, 350148, 356425);
-- Rockslice Flayer
DELETE FROM `creature` WHERE `guid` IN (350327, 356823, 350211, 350344, 351952, 350212, 350214, 351950, 351941, 350221, 350222, 351947, 350205, 357267);

-- Creature Living Blood 43123 SAI
SET @ENTRY := 43123;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 4000, 5000, 14000, 15000, 11, 31281, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 4000 min and 5000 max ms (repeat 14000 min 15000 max ms) - Self: Cast spell Bloodbolt (31281) on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 14000, 17000, 24000, 27000, 11, 86808, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 14000 min and 17000 max ms (repeat 24000 min 27000 max ms) - Self: Cast spell Boiling Effusion (86808) on Self // ");

DELETE FROM `quest_template_addon` WHERE `ID` IN (26771, 27136);
INSERT INTO `quest_template_addon` (`ID`, `ProvidedItemCount`) VALUES
(26771, 1),
(27136, 1);
