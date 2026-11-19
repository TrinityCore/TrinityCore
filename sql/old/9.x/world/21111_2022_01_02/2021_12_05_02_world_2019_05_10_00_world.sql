-- 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26405, 26406) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2640600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26405, 0, 0, 0, 25, 0, 100, 512, 0, 0, 0, 0, 0, 75, 47922, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Iron Thane Furyhammer - On Reset - Add Aura 'Furyhammer's Immunity'"),
(26405, 0, 1, 0, 38, 0, 100, 512, 1, 1, 0, 0, 0, 75, 47922, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Iron Thane Furyhammer - On Data 1 1 Set - Add Aura 'Furyhammer's Immunity'"),
(26405, 0, 2, 0, 0, 0, 100, 0, 5000, 9000, 10000, 14000, 0, 11, 61575, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Iron Thane Furyhammer - In Combat - Cast 'Furyhammer'"),
(26406, 0, 0, 0, 8, 0, 100, 512, 47911, 0, 0, 0, 0, 80, 2640600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "The Anvil - On Spellhit 'EMP' - Run Script"),
(26406, 0, 1, 0, 0, 0, 100, 0, 5000, 7500, 1200, 14500, 0, 11, 61577, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "The Anvil - In Combat - Cast 'Molten Blast'"),
(2640600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "The Anvil - On Spellhit 'EMP' - Say Line 0"),
(2640600, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 75, 47923, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "The Anvil - On Script - Add Aura 'Stunned'"),
(2640600, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 28, 47922, 0, 0, 0, 0, 0, 19, 26405, 30, 0, 0, 0, 0, 0, 0, "The Anvil - On Script - Remove Aura 'Furyhammer's Immunity' (Iron Thane Furyhammer)"),
(2640600, 9, 3, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 0, 28, 47923, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "The Anvil - On Script - Remove Aura 'Stunned'"),
(2640600, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "The Anvil - On Script - Say Line 1"),
(2640600, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 26405, 30, 0, 0, 0, 0, 0, 0, "The Anvil - On Script - Set Data 1 1 (Iron Thane Furyhammer)");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=26406 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 26406, 0, 0, 1, 1, 47923, 0, 0, 1, 0, 0, "", "Execute SAI for NPC The Anvil only if it doesn't have aura 'Stunned'");

DELETE FROM `creature_text` WHERE `CreatureId`=26406;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(26406, 0, 0, "The EMP disrupts Iron Thane Furyhammer's shield!", 16, 0, 100, 0, 0, 0, 26169, 0, "The Anvil"),
(26406, 1, 0, "%s recovers from the EMP and restores Iron Thane Furyhammer's shield.", 16, 0, 100, 0, 0, 0, 26170, 0, "The Anvil");

DELETE FROM `conditions` WHERE `SourceEntry`=47911 AND `SourceTypeOrReferenceId`=17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(17,0,47911,0,0,29,0,26406,15,0,0,0,'', 'EMP can cast, if in 15 yards of Anvil');
