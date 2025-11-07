-- Update Spitelash Serpent Guard
SET @NPC=6194;
UPDATE `creature_equip_template` SET `ItemID2`=0, `VerifiedBuild`=58797 WHERE `CreatureID`=@NPC;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry`=@NPC;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `id` IN (4,5) AND `entryorguid`=@NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 4, 0, 0, 0, 100, 0, 2000, 4000, 20000, 25000, 0, 11, 12548, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Spitelash Serpent Guard - In Combat - Cast 'Frost Shock'"),
(@NPC, 0, 5, 0, 0, 0, 100, 0, 4000, 9000, 30000, 35000, 0, 11, 12545, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Spitelash Serpent Guard - In Combat - Cast 'Spitelash'");
