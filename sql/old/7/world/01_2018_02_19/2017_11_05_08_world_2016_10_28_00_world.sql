--
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=26564;

DELETE FROM `smart_scripts` WHERE `entryorguid`=26564;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26564, 0, 0, 0, 1, 0, 100, 0, 300000, 300000, 600000, 600000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Borus Ironbender - Out of Combat - Talk 0");

DELETE FROM `creature_text` WHERE `CreatureID`=26564;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(26564, 0, 0, "Faster! Faster! These armaments must be delivered to the Kor'kron Vanguard TODAY!", 12, 1, 100, 0, 0, 0, 25775, 0, "Borus Ironbender"),
(26564, 0, 1, "I will happily replace you all with goblins! Do not fail me!", 12, 1, 100, 0, 0, 0, 25776, 0, "Borus Ironbender"),
(26564, 0, 2, "Overlord Agmar demands more of us! We must not disappoint!", 12, 1, 100, 0, 0, 0, 25777, 0, "Borus Ironbender"),
(26564, 0, 3, "Don't make me jump off of this crate! I will beat your head in, orc.", 12, 1, 100, 0, 0, 0, 25778, 0, "Borus Ironbender");
