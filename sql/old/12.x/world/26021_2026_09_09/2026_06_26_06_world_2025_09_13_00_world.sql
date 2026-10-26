--
DELETE FROM `creature_text` WHERE `CreatureID` = 15341 AND `GroupID` > 5;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15341,6,0,"Breathe your last!",14,0,100,0,0,8604,11433,0,"rajaxx SAY_SLAY"),
(15341,7,0,"Warriors, Captains, continue the fight!",14,0,100,0,0,8613,11434,0,"rajaxx SAY_DEATH"),
(15341,8,0,"%s goes into a frenzy!",16,0,100,0,0,0,2384,0,"rajaxx EMOTE_FRENZY");
