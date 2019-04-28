-- Creature Unbound Flame Spirit 40080 SAI
SET @ENTRY := 40080;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 60, 0, 100, 1, 2000, 2000, 0, 0, 3, 0, 8409, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 2000 and 2000 ms) - Self: Morph to model 8409 // "),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 19, 33554688, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Remove UNIT_FLAGS to UNIT_FLAG_IMMUNE_TO_PC, UNIT_FLAG_NOT_SELECTABLE // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Attack Owner/Summoner // "),
(@ENTRY, 0, 3, 0, 6, 0, 100, 0, 0, 0, 0, 0, 33, 40065, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On death - Action invoker: Give kill credit Unbound Flame Spirit (40065) // ");
