--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (13, 17) AND `SourceEntry` IN (42767, 42788);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 2, 42788, 0, 0, 31, 0, 3, 23943, 0, 0, 0, 0, "", "Spell 'Feed Plaguehound' targets NPC 'Hungry Plaguehound'"),
(17, 0, 42788, 0, 0, 29, 0, 23943, 10, 0, 0, 0, 0, "", "Spell 'Feed Plaguehound' requires NPC 'Hungry Plaguehound' within 10 yards"),
(13, 1, 42767, 0, 0, 31, 0, 3, 23945, 0, 0, 0, 0, "", "Spell 'Sic'em' targets NPC 'Fjord Crow'");

UPDATE `creature_template` SET `spell1`=42767 WHERE `entry`=23943;

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23945;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23945;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23945, 0, 0, 0, 8, 0, 100, 0, 42767, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Fjord Crow - On Spellhit 'Sic'em' - Attack Invoker");
