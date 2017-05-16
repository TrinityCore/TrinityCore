--
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=184980;
DELETE FROM `smart_scripts` WHERE `entryorguid`=184980;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(184980, 1, 0, 0, 70, 0, 100, 0, 2, 0, 0, 0, 11, 37695, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Felhound Poo - On Gameobject State 2 - Cast 'Stanky'");
UPDATE `gameobject_loot_template` SET `Chance`=0, `GroupId`=1 WHERE `Entry`=21311;
