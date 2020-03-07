-- Scarlet Ghoul
DELETE FROM `creature_text` WHERE `CreatureID`=28845;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(28845,0,0,'So hungry...',12,0,100,0,0,0,28955,0,'Scarlet Ghoul'),
(28845,0,1,'Must feed...',12,0,100,0,0,0,28956,0,'Scarlet Ghoul'),
(28845,0,2,'GIVE ME BRAINS!',12,0,100,0,0,0,28957,0,'Scarlet Ghoul'),
(28845,0,3,'Smell flesh... close...',12,0,100,0,0,0,28958,0,'Scarlet Ghoul'),
(28845,0,4,'Mommy?',12,0,100,0,0,0,28959,0,'Scarlet Ghoul'),
(28845,0,5,'$g Poppy:Mama;!',12,0,100,0,0,0,28960,0,'Scarlet Ghoul');

-- Scarlet Ghost
DELETE FROM `creature_text` WHERE `CreatureID`=28846;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(28846,0,0,'Vengeance is mine!',12,0,100,0,0,0,28969,0,'Scarlet Ghost'),
(28846,0,1,'I\'ll take you with me!',12,0,100,0,0,0,28964,0,'Scarlet Ghost'),
(28846,0,2,'The grave calls to us all!',12,0,100,0,0,0,28966,0,'Scarlet Ghost'),
(28846,0,3,'Die, Scourge filth!',12,0,100,0,0,0,28968,0,'Scarlet Ghost'),
(28846,0,4,'YOU KILLED ME!',12,0,100,0,0,0,28967,0,'Scarlet Ghost');

UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=28846;
DELETE FROM `smart_scripts` WHERE `entryorguid`=28846 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(28846,0,0,0,54,0,50,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Scarlet Ghost - On Just Appeared -Say Line 0");
