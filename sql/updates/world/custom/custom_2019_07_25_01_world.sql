DELETE FROM `creature_text` WHERE `CreatureID`= 48964 AND `GroupID`= 4;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(48964, 4, 0, 'Mortals that fancy themselves HEROES have entered the Broken Hall. Oh, I do hope this \"raid\" will amuse me more than the last.', 14, 0, 100, 0, 0, 23379, 49053, 'Lord Victor Nefarius to Player');

DELETE FROM `areatrigger_scripts` WHERE `entry`= 6583;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(6583, 'at_bwd_intro');
