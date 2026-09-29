--
DELETE FROM `creature_text` WHERE `CreatureID` = 16118;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16118,0,0,"You think you can summon us? We are the ones that summon, not you! We bash you good for this and suck the marrow from your bones!",14,0,100,0,0,0,11968,0,"Kormok SAY_SPAWN"),
(16118,1,0,"First Kormok crush your bones!  Then Kormok burn your soul!",12,0,100,0,0,0,11958,0,"Kormok SAY_AGGRO"),
(16118,1,1,"You so little and puny... you no make good servants for Kormok!",12,0,100,0,0,0,11959,0,"Kormok SAY_AGGRO"),
(16118,2,0,"We am free! Thank you little, puny ones.",14,0,100,0,0,0,11873,0,"Kormok SAY_DEATH"),
(16118,3,0,"%s goes into a frenzy!",16,0,100,0,0,0,10645,0,"Kormok EMOTE_FRENZY");

DELETE FROM `creature_text` WHERE `CreatureID` = 10432;

DELETE FROM `creature_text` WHERE `CreatureID` = 14516;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(14516,0,0,"ENOUGH - this ends now!  You fools will be added to my bone collection!",14,0,100,0,0,0,9784,0,"Death Knight Darkreaver");

DELETE FROM `creature_text` WHERE `CreatureID` = 11261;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(11261,0,0,"The doctor is in!",12,0,100,0,0,0,6715,0,"Doctor Theolen Krastinov SAY_AGGRO"),
(11261,1,0,"%s goes into a frenzy!",16,0,100,0,0,0,10645,0,"Doctor Theolen Krastinov EMOTE_FRENZY");

DELETE FROM `creature_text` WHERE `CreatureID` = 10503;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(10503,0,0,"%s loosens her grasp on the journal she had been clutching.",16,0,100,0,0,0,11408,0,"Jandice Barov");

UPDATE `waypoint_data` SET `move_type` = 1 WHERE `id` = 105061;

UPDATE `creature_template` SET `unit_flags` = 832, `flags_extra` = `flags_extra`|512 WHERE `entry` = 10506;
