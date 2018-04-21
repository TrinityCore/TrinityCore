-- DB/Quest: Fix: A Dark Influence (12220) | by wintergreen77
SET @SPELL     := 48218; -- Sampling Energy
SET @NPC_HEART := 27263; -- Vordrassil's Heart Credit
SET @NPC_LIMB  := 27264; -- Vordrassil's Limb Credit
SET @NPC_TEARS := 27265; -- Vordrassil's Tears Credit

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@NPC_HEART, @NPC_LIMB, @NPC_TEARS);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_HEART, @NPC_LIMB, @NPC_TEARS) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@NPC_HEART, 0, 0, 0, 8, 0, 100, 0, @SPELL, 0, 0, 0, 33, @NPC_HEART, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On Spellhit - Give Vordrasill''s Heart Kill credit - Action Invoker'),
(@NPC_LIMB, 0, 0, 0, 8, 0, 100, 0, @SPELL, 0, 0, 0, 33, @NPC_LIMB, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On Spellhit - Give Vordrasill''s Limb Kill credit - Action Invoker'),
(@NPC_TEARS, 0, 0, 0, 8, 0, 100, 0, @SPELL, 0, 0, 0, 33, @NPC_TEARS, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On Spellhit - Give Vordrasill''s Tears Kill credit - Action Invoker');
