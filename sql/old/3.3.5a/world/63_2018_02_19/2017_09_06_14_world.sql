-- Devlin Agamand
DELETE FROM `smart_scripts` WHERE `entryorguid`=1657 AND `source_type`=0 AND `id` IN (1, 2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1657,0,1,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Devlin Agamand - On Aggro - Say Line 0"),
(1657,0,2,0,1,0,100,0,1000,10000,15000,25000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Devlin Agamand - Out Of Combat - Say Line 1");
DELETE FROM `creature_text` WHERE `CreatureID`=1657;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1657,0,0,"The Agamand Mills is held by the Scourge, $C.  Join us!",12,0,100,0,0,0,575,0,"Devlin Agamand"),
(1657,0,1,"Here to visit the family?  Die, fool!",12,0,100,0,0,0,574,0,"Devlin Agamand"),
(1657,1,0,"Mother, oh mother.  You should have listened to me...",12,0,100,0,0,0,572,0,"Devlin Agamand"),
(1657,1,1,"They thought I was weak.  Haha!!",12,0,100,0,0,0,567,0,"Devlin Agamand"),
(1657,1,2,"I am the head of the family.  Me.  ME!!!"	,12,0,100,0,0,0,568,0,"Devlin Agamand"),
(1657,1,3,"I'm cold, lord.  When will you keep your promise?",12,0,100,0,0,0,569,0,"Devlin Agamand"),
(1657,1,4,"My family hates me.  Frightened idiots, all of them!",12,0,100,0,0,0,570,0,"Devlin Agamand"),
(1657,1,5,"Father?  Are you proud of me now? HAHAH!",12,0,100,0,0,0,571,0,"Devlin Agamand"),
(1657,1,6,"Thurman my brother, who's laughing now?  Hah!",12,0,100,0,0,0,573,0,"Devlin Agamand");
