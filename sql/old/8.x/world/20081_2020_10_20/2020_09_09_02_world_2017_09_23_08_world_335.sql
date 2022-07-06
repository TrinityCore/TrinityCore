-- Control
DELETE FROM `creature` WHERE `id`=17612;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (17190, 17475);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17190, 17191, 17192, 17475, 17612) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17190, 0, 0, 0, 6, 0, 20, 0, 0, 0, 0, 0, 11, 31593, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Siltfin Murloc - On Death - Cast 'Summon Greater Manawraith'"),
(17191, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2000, 2000, 11, 12550, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Siltfin Oracle - In Combat - Cast 'Lightning Shield'"),
(17191, 0, 1, 0, 0, 0, 100, 0, 0, 0, 2100, 2200, 11, 9739, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Siltfin Oracle - In Combat CMC - Cast 'Wrath'"),
(17191, 0, 2, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Siltfin Oracle - Between 0-15% Health - Flee For Assist (No Repeat)"),
(17191, 0, 3, 0, 6, 0, 20, 0, 0, 0, 0, 0, 11, 31593, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Siltfin Oracle - On Death - Cast 'Summon Greater Manawraith'"),
(17192, 0, 0, 0, 0, 0, 100, 0, 0, 0, 3000, 3000, 11, 10277, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Siltfin Hunter - In Combat CMC - Cast 'Throw'"),
(17192, 0, 1, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Siltfin Hunter - Between 0-15% Health - Flee For Assist (No Repeat)"),
(17192, 0, 2, 0, 6, 0, 20, 0, 0, 0, 0, 0, 11, 31593, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Siltfin Hunter - On Death - Cast 'Summon Greater Manawraith'"),
(17475, 0, 0, 0, 6, 0, 20, 0, 0, 0, 0, 0, 11, 31593, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Murgurgula - On Death - Cast 'Summon Greater Manawraith'"),
(17612, 0, 0, 0, 0, 0, 100, 0, 0, 0, 3100, 3200, 11, 11921, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Quel'dorei Magewraith - In Combat CMC - Cast 'Fireball'"),
(17612, 0, 1, 0, 0, 0, 100, 0, 7000, 11000, 9000, 13000, 11, 31595, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Quel'dorei Magewraith - In Combat CMC - Cast 'Arcane Bolt'"),
(17612, 0, 2, 0, 0, 0, 100, 0, 9000, 13000, 7000, 11000, 11, 31604, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Quel'dorei Magewraith - In Combat CMC - Cast 'Arcane Weakness'"),
(17612, 0, 3, 0, 0, 0, 100, 0, 11000, 15000, 16000, 20000, 11, 11436, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Quel'dorei Magewraith -In Combat CMC - Cast 'Slow'"),
(17612, 0, 4, 0, 13, 0, 100, 0, 10000, 15000, 0, 0, 11, 31596, 65, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Quel'dorei Magewraith - Target Casting - Cast 'Counterspell'"),
(17612, 0, 5, 0, 6, 0, 100, 1, 0, 0, 0, 0, 15, 9595, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, "Quel'dorei Magewraith - On Just Died - Quest Credit 'Control'"),
(17612, 0, 6, 0, 54, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Quel'dorei Magewraith - Just Summoned - Say Line 0"),
(17612, 0, 7, 0, 1, 0, 100, 1, 120000, 120000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Quel'dorei Magewraith - Out of Combat - Despawn In 2 Minutes");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (17190, 17191, 17192, 17475);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 17190, 0, 0, 9, 0, 9595, 0, 0, 0, 0, 0, "", "Smart Event 0 for creature Siltfin Murloc only executes if player has quest 'Control' taken AND"),
(22, 1, 17190, 0, 0, 29, 0, 17612, 100, 0, 1, 0, 0, "", "Smart Event 0 for creature Siltfin Murloc only executes if creature 'Quel'dorei Magewraith' is NOT nearby"),
(22, 4, 17191, 0, 0, 9, 0, 9595, 0, 0, 0, 0, 0, "", "Smart Event 3 for creature Siltfin Oracle only executes if player has quest 'Control' taken AND"),
(22, 4, 17191, 0, 0, 29, 0, 17612, 100, 0, 1, 0, 0, "", "Smart Event 3 for creature Siltfin Oracle only executes if creature 'Quel'dorei Magewraith' is NOT nearby"),
(22, 3, 17192, 0, 0, 9, 0, 9595, 0, 0, 0, 0, 0, "", "Smart Event 2 for creature Siltfin Hunter only executes if player has quest 'Control' taken AND"),
(22, 3, 17192, 0, 0, 29, 0, 17612, 100, 0, 1, 0, 0, "", "Smart Event 2 for creature Siltfin Hunter only executes if creature 'Quel'dorei Magewraith' is NOT nearby"),
(22, 1, 17475, 0, 0, 9, 0, 9595, 0, 0, 0, 0, 0, "", "Smart Event 0 for creature Murgurgula only executes if player has quest 'Control' taken AND"),
(22, 1, 17475, 0, 0, 29, 0, 17612, 100, 0, 1, 0, 0, "", "Smart Event 0 for creature Murgurgula only executes if creature 'Quel'dorei Magewraith' is NOT nearby");

DELETE FROM `creature_text` WHERE `CreatureID`=17612;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17612, 0, 0, "Who dares wield magic in my presence?", 14, 0, 100, 0, 0, 0, 14229, 0, "Quel'dorei Magewraith");
