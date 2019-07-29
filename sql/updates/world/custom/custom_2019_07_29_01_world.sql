DELETE FROM `game_event_gameobject` WHERE `guid` IN (227017, 227033, 227036, 227037, 227038, 227047, 227048, 227049, 227050, 227051, 227052, 227053, 227054, 227055, 227056, 227057, 227058, 227059, 227060, 227061, 227062, 227063, 227064, 227065, 227066, 227067, 227068, 227069, 227070, 227071, 227072, 227073, 227074, 227075, 227076, 227077, 227078, 227079, 227081, 227082, 227083, 227084, 227085, 227086, 227103, 227104, 227105, 227106, 227107, 227108, 227109, 227110, 227111, 227112, 227113, 227117, 227118, 227119, 227120, 227124, 227127, 227130, 227141, 227180);

DELETE FROM `spawn_group` WHERE `spawnId` IN (218818, 218824, 218833, 218844, 218865);

-- Creature Anchorite Fateema 17214 SAI
SET @ENTRY := 17214;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 5, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On just summoned - Self: Play emote STATE_DANCE (10) // Anchorite Fateema - On Just Summoned - Play Emote 10"),
(@ENTRY, 0, 1, 0, 20, 0, 100, 512, 9463, 0, 0, 0, 80, 1721400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When player rewards quest 9463 - Start timed action list id #1721400 // Anchorite Fateema - On Quest 'Medicinal Purposes' Rewarded - Run Script");

-- Creature Daedal 17215 SAI
SET @ENTRY := 17215;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On just summoned - Self: Set event phase to 1 // Acteon - On Just Summoned - Set Event Phase 1"),
(@ENTRY, 0, 1, 0, 1, 1, 100, 0, 3000, 3000, 5000, 8000, 5, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 3000 and 3000 ms (and later repeats every 5000 and 8000 ms) - Self: Play emote ONESHOT_CHEER(DNR) (4) // Acteon - Out of Combat - Play Emote 4"),
(@ENTRY, 0, 2, 0, 38, 0, 100, 512, 1, 1, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On data 1 set to 1 - Self: Set npc flags UNIT_NPC_FLAG_NONE // Daedal - On Data Set 1 1- Set NPC Flags"),
(@ENTRY, 0, 3, 0, 38, 0, 100, 512, 2, 2, 0, 0, 81, 83, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On data 2 set to 2 - Self: Set npc flags UNIT_NPC_FLAG_GOSSIP, UNIT_NPC_FLAG_QUESTGIVER, UNIT_NPC_FLAG_TRAINER, UNIT_NPC_FLAG_TRAINER_PROFESSION // Daedal - On Data Set 2 2- Set NPC Flags"),
(@ENTRY, 0, 4, 0, 20, 0, 100, 512, 9473, 0, 0, 0, 80, 1721500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When player rewards quest 9473 - Start timed action list id #1721500 // Daedal - On Quest 'An Alternative Alternative' Rewarded - Run Script");

-- Creature Matthias Lehner 32423 SAI
SET @ENTRY := 32423;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 20, 0, 100, 0, 13398, 0, 0, 0, 12, 32443, 1, 27000, 0, 0, 0, 8, 0, 0, 0, 7863.78, 943.377, 451.502, 1.556, "When player rewards quest 13398 - Self: Summon creature The Lich King (32443) at (7863.78, 943.377, 451.502, 1.556) // Matthias Lehner - On Quest 'Where Dragons Fell' Finished - Summon Creature 'The Lich King'"),
(@ENTRY, 0, 1, 0, 20, 0, 100, 0, 13359, 0, 0, 0, 12, 32443, 1, 27000, 0, 0, 0, 8, 0, 0, 0, 7863.78, 943.377, 451.502, 1.556, "When player rewards quest 13359 - Self: Summon creature The Lich King (32443) at (7863.78, 943.377, 451.502, 1.556) // Matthias Lehner - On Quest 'Where Dragons Fell' Finished - Summon Creature 'The Lich King'");
