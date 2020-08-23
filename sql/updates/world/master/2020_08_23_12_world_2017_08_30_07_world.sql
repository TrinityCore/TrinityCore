-- Madame Eva
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=265;
DELETE FROM `smart_scripts` WHERE `entryorguid`=265;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(265,0,0,0,1,0,100,0,1000,15000,150000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madame Eva - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=265;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(265,0,0,"I sense evil brewing. . . .",12,7,100,0,0,0,73,0,"Madame Eva"),
(265,0,1,"The stars speak to me.  They whisper of the horrors waiting in the night.",12,7,100,0,0,0,74,0,"Madame Eva"),
(265,0,2,"The future holds much death and uncertainty, not unlike the past.",12,7,100,0,0,0,75,0,"Madame Eva"),
(265,0,3,"The spirits whisper in my ear.  They are restless and full of angst.",12,7,100,0,0,0,76,0,"Madame Eva");
