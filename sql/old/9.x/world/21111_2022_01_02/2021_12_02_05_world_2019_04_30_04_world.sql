-- Prince Thunderaan
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14435;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14435 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1443500 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14435,0,0,0,54,0,100,0,0,0,0,0,80,1443500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Thunderaan - Just Summoned - Run Script"),
(14435,0,1,0,4,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Thunderaan - On Aggro - Say Line 2"),
(14435,0,2,0,0,0,100,0,11000,15000,12000,20000,11,23009,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Thunderaan - In Combat - Cast 'Tendrils of Air'"),
(14435,0,3,0,0,0,100,0,5000,7000,8000,11000,11,23011,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Thunderaan - In Combat - Cast 'Tears of the Wind Seeker'"),
(1443500,9,0,0,0,0,100,0,0,0,0,0,11,20568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Thunderaan - On Script - Cast 'Ragnaros Emerge'"),
(1443500,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Thunderaan - On Script - Say Line 0"),
(1443500,9,2,0,0,0,100,0,13000,13000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Thunderaan - On Script - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=14435;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(14435,0,0,"Well done, servant. For so long I have been held captive within the prison of the Firelord. I am once more free to feast upon the out world! The land shall once more be ravaged by the force of the Wind Seeker!",14,0,100,0,0,0,9570,0,"Prince Thunderaan"),
(14435,1,0,"Ah, and the fool who freed me shall be among the first to quell my immense hunger.",14,0,100,0,0,0,9571,0,"Prince Thunderaan"),
(14435,2,0,"My power is discombobulatingly devastating! It is ludicrous that these mortals even attempt to enter my realm!",14,0,100,0,0,0,9572,0,"Prince Thunderaan");
