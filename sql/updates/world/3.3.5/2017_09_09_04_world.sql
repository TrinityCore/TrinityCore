-- Gath'Ilzogg
DELETE FROM `creature_text` WHERE `CreatureID`=334;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(334,0,0,'Stupid $R!  The Blackrock Clan shall dance on your grave!',12,1,100,0,0,0,465,0,'Gath\'Ilzogg'),
(334,0,1,'Foolish $C!  You are no match for my might!',12,1,100,0,0,0,466,0,'Gath\'Ilzogg'),
(334,0,2,'I am Gath\'Ilzogg!  And you are a $R on the brink of death!',12,1,100,0,0,0,467,0,'Gath\'Ilzogg'),
(334,0,3,'Death to $n!  Long live the Blackrock Clan!',12,1,100,0,0,0,468,0,'Gath\'Ilzogg'),
(334,0,4,'Who dares intrude upon the Blackrock Clan?  Death to this $R!',12,1,100,0,0,0,469,0,'Gath\'Ilzogg'),
(334,0,5,'Tiny $C!  You are no match for the Blackrock Clan!',12,1,100,0,0,0,470,0,'Gath\'Ilzogg'),
(334,0,6,'Foolish $C!  I will snap the bones of this weak $R!',12,1,100,0,0,0,471,0,'Gath\'Ilzogg'),
(334,0,7,'Long live the mighty Blackrock Clan!',12,1,100,0,0,0,472,0,'Gath\'Ilzogg');
DELETE FROM `smart_scripts` WHERE `entryorguid`=334 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(334,0,3,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Gath\'Ilzogg - On Aggro - Say Line 0');
