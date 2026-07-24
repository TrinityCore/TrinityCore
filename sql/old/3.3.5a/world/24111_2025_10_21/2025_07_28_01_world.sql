-- Sen'jin Fetish
SET @NPC=33810;
UPDATE `creature_template` SET `unit_flags`=768, `AIName`='SmartAI' WHERE `entry`=@NPC;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 0, 3, 0, 28880, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sen'Jin Fetish - Just Summoned - Morph"),
(@NPC, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 87, @NPC * 100, @NPC * 100 + 1, @NPC * 100 + 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sen'Jin Fetish - On Link - Call Random Script");

DELETE FROM `creature_template_addon` WHERE `entry`=@NPC;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(@NPC, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '52619'); -- Enchanted Tiki Warrior: Enchanted Tiki Warrior Glow Visual

DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@NPC * 100, @NPC * 100 +1, @NPC * 100 + 2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC * 100, 9, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 11, 52614, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sen'Jin Fetish - Just Summoned - Cast Spell 'Enchanted Tiki Warrior: Enchanted Tiki Warrior Visual 01' on self"),
(@NPC * 100 + 1, 9, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 11, 52617, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sen'Jin Fetish - Just Summoned - Cast Spell 'Enchanted Tiki Warrior: Enchanted Tiki Warrior Visual 02' on self"),
(@NPC * 100 + 2, 9, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 11, 52618, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sen'Jin Fetish - Just Summoned - Cast Spell 'Enchanted Tiki Warrior: Enchanted Tiki Warrior Visual 03' on self");
