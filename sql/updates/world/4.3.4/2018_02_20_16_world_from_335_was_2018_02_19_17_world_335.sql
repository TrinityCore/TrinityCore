/*
-- Mordent Evenshade & Sentinel Stillbough
DELETE FROM `creature_text` WHERE `CreatureID` IN (36479,36481);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(36479,0,0,"Sentinel, I would speak with your High Priestess.",12,7,100,1,0,0,36428,0,"Archmage Mordent Evenshade"),
(36479,1,0,"Must I? I doubt Tyrande has more pressing business.",12,7,100,6,0,0,36429,0,"Archmage Mordent Evenshade"),
(36479,2,0,"The lure of power is great. Mistakes were made.",12,7,100,1,0,0,36430,0,"Archmage Mordent Evenshade"),
(36479,3,0,"I will not return until I am heard. There is too much at stake.",12,7,100,5,0,0,36431,0,"Archmage Mordent Evenshade"),
(36479,4,0,"There is change on the wind, and we cannot ignore it. I have traveled from the dust and ruin of the past to come to an accord.",12,7,100,1,0,0,36432,0,"Archmage Mordent Evenshade"),
(36479,5,0,"The time may soon come when the kaldorei require the knowledge and skill we have to offer.",12,7,100,1,0,0,36433,0,"Archmage Mordent Evenshade"),
(36479,6,0,"I will wait, Sentinel... but I will have my audience.",12,7,100,1,0,0,36434,0,"Archmage Mordent Evenshade"),
(36479,7,0,"%s looks over at the moonwell with a sigh.",16,0,100,0,0,0,36440,0,"Archmage Mordent Evenshade"),
(36479,8,0,"Calm yourself, Sentinel. I do not seek to use it. I am merely... remembering.",12,7,100,1,0,0,36435,0,"Archmage Mordent Evenshade"),
(36479,9,0,"Enough. I have been apart from this for centuries. The well within this temple may be a pale spectre of the Well of Eternity, but it still holds the same... beauty. Purity.",12,7,100,1,0,0,36436,0,"Archmage Mordent Evenshade"),
(36479,10,0,"I had forgotten.",12,7,100,0,0,0,36437,0,"Archmage Mordent Evenshade"),
(36479,11,0,"I do not believe admiration and wistful thoughts are against the societal norm.",12,7,100,6,0,0,36438,0,"Archmage Mordent Evenshade"),
(36479,12,0,"You were the one who challenged me for merely looking. I still await my audience with Tyrande.",12,7,100,1,0,0,36439,0,"Archmage Mordent Evenshade"),
(36481,0,0,"You must wait for an audience.",12,7,100,25,0,0,36446,0,"Sentinel Stillbough"),
(36481,1,0,"You show some nerve coming to Teldrassil, Highborne. Your kind are unwelcome here. We have not forgotten the War of the Ancients or the minds behind it.",12,7,100,1,0,0,36447,0,"Sentinel Stillbough"),
(36481,2,0,"And we would not see those mistakes repeated. Return to your exile.",12,7,100,5,0,0,36448,0,"Sentinel Stillbough"),
(36481,3,0,"Take your gaze off the moonwell, exile. The power within is not yours to wield.",12,7,100,5,0,0,36449,0,"Sentinel Stillbough"),
(36481,4,0,"Recalling your treachery?",12,7,100,6,0,0,36450,0,"Sentinel Stillbough"),
(36481,5,0,"Watch yourself, Highborne.",12,7,100,25,0,0,36451,0,"Sentinel Stillbough"),
(36481,6,0,"In good time.",12,7,100,1,0,0,36452,0,"Sentinel Stillbough");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=36479;
DELETE FROM `smart_scripts` WHERE `entryorguid`=36479 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3647900,3647901) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(36479,0,0,0,1,0,100,0,5000,15000,150000,180000,87,3647900,3647901,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Mordent Evenshade - Out of Combat - Run Random Script"),
(3647900,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Mordent Evenshade - On Script - Say Line 0"),
(3647900,9,1,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,19,36481,0,0,0,0,0,0,"Archmage Mordent Evenshade - On Script - Say Line 0 (Sentinel Stillbough)"),
(3647900,9,2,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Mordent Evenshade - On Script - Say Line 1"),
(3647900,9,3,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,19,36481,0,0,0,0,0,0,"Archmage Mordent Evenshade - On Script - Say Line 1 (Sentinel Stillbough)"),
(3647900,9,4,0,0,0,100,0,8000,8000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Mordent Evenshade - On Script - Say Line 2"),
(3647900,9,5,0,0,0,100,0,4000,4000,0,0,1,2,0,0,0,0,0,19,36481,0,0,0,0,0,0,"Archmage Mordent Evenshade - On Script - Say Line 2 (Sentinel Stillbough)"),
(3647900,9,6,0,0,0,100,0,5000,5000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Mordent Evenshade - On Script - Say Line 3"),
(3647900,9,7,0,0,0,100,0,5000,5000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Mordent Evenshade - On Script - Say Line 4"),
(3647900,9,8,0,0,0,100,0,7000,7000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Mordent Evenshade - On Script - Say Line 5"),
(3647900,9,9,0,0,0,100,0,6000,6000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Mordent Evenshade - On Script - Say Line 6"),
(3647901,9,0,0,0,0,100,0,0,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Mordent Evenshade - On Script - Say Line 7"),
(3647901,9,1,0,0,0,100,0,4000,4000,0,0,1,3,0,0,0,0,0,19,36481,0,0,0,0,0,0,"Archmage Mordent Evenshade - On Script - Say Line 3 (Sentinel Stillbough)"),
(3647901,9,2,0,0,0,100,0,5000,5000,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Mordent Evenshade - On Script - Say Line 8"),
(3647901,9,3,0,0,0,100,0,5000,5000,0,0,1,4,0,0,0,0,0,19,36481,0,0,0,0,0,0,"Archmage Mordent Evenshade - On Script - Say Line 4 (Sentinel Stillbough)"),
(3647901,9,4,0,0,0,100,0,3000,3000,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Mordent Evenshade - On Script - Say Line 9"),
(3647901,9,5,0,0,0,100,0,10000,10000,0,0,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Mordent Evenshade - On Script - Say Line 10"),
(3647901,9,6,0,0,0,100,0,3000,3000,0,0,1,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Mordent Evenshade - On Script - Say Line 11"),
(3647901,9,7,0,0,0,100,0,5000,5000,0,0,1,5,0,0,0,0,0,19,36481,0,0,0,0,0,0,"Archmage Mordent Evenshade - On Script - Say Line 5 (Sentinel Stillbough)"),
(3647901,9,8,0,0,0,100,0,3000,3000,0,0,1,12,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Mordent Evenshade - On Script - Say Line 12"),
(3647901,9,9,0,0,0,100,0,6000,6000,0,0,1,6,0,0,0,0,0,19,36481,0,0,0,0,0,0,"Archmage Mordent Evenshade - On Script - Say Line 6 (Sentinel Stillbough)");
*/
