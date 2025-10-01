--
DELETE FROM `creature_text` WHERE `CreatureID` = 16118;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16118,0,0,"You think you can summon us? We are the ones that summon, not you! We bash you good for this and suck the marrow from your bones!",14,0,100,0,0,0,11968,0,"Kormok SAY_SPAWN"),
(16118,1,0,"First Kormok crush your bones!  Then Kormok burn your soul!",12,0,100,0,0,0,11958,0,"Kormok SAY_AGGRO"),
(16118,1,1,"You so little and puny... you no make good servants for Kormok!",12,0,100,0,0,0,11959,0,"Kormok SAY_AGGRO"),
(16118,2,0,"We am free! Thank you little, puny ones.",14,0,100,0,0,0,11873,0,"Kormok SAY_DEATH"),
(16118,3,0,"%s goes into a frenzy!",16,0,100,0,0,0,10645,0,"Kormok EMOTE_FRENZY");

DELETE FROM `creature_text` WHERE `CreatureID` = 10432;
