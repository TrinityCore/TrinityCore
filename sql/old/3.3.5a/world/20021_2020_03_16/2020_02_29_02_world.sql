-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=32573 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3257300 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(32573, 0, 0, 0, 8, 0, 100, 0, 43971, 0, 0, 0, 0, 80, 3257300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Valgarde Captive - On Spellhit 'Incinerate' - Action list"),
(3257300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Valgarde Captive - Action list - Say Line 0"),
(3257300, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Valgarde Captive - Action list - Remove bytes1"),
(3257300, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 90, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Valgarde Captive - Action list - Set bytes1"),
(3257300, 9, 3, 0, 0, 0, 100, 0, 20000, 20000, 0, 0, 0, 91, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Valgarde Captive - Action list - Remove bytes1"),
(3257300, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Valgarde Captive - Action list - Set bytes1");

DELETE FROM `creature_text` WHERE `CreatureID`=23656 AND `ID` IN (3,4);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23656,0,3,'I enjoy the screams most of all.',12,0,100,1,0,0,23535,0,'Dragonflayer Rune-Seer'),
(23656,0,4,'We shall see how much punishment these invaders can stand.',12,0,100,1,0,0,23537,0,'Dragonflayer Rune-Seer');
