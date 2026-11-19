--
DELETE FROM `creature_text` WHERE `CreatureID` = 19220;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(19220,0,0,"I have been waiting for you!",14,0,100,0,0,0,19059,0,"Pathaleon SAY_SPAWN"),
(19220,1,0,"We are on a strict timetable. You will not interfere!",14,0,100,0,0,11193,20041,0,"Pathaleon SAY_AGGRO"),
(19220,2,0,"A minor inconvenience.",14,0,100,0,0,11194,20042,0,"Pathaleon SAY_SLAY_1"),
(19220,2,1,"Looks like you lose.",14,0,100,0,0,11195,20043,0,"Pathaleon SAY_SLAY_2"),
(19220,3,0,"Time to supplement my work force.",14,0,100,0,0,11196,18717,0,"Pathaleon SAY_SUMMON"),
(19220,4,0,"I'm looking for a team player...",14,0,100,0,0,11197,18716,0,"Pathaleon SAY_DOMINATION_1"),
(19220,4,1,"You work for me now!",14,0,100,0,0,11198,20040,0,"Pathaleon SAY_DOMINATION_2"),
(19220,5,0,"I prefer to be hands-on...",14,0,100,0,0,11199,18725,0,"Pathaleon SAY_ENRAGE"),
(19220,6,0,"The project will... continue.",14,0,100,0,0,11200,20044,0,"Pathaleon SAY_DEATH");
