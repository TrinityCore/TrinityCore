--
DELETE FROM `creature_text` WHERE `CreatureID` IN (17377,17653);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17377,0,0,"Who dares interrupt--What is this; what have you done? You'll ruin everything!",14,0,100,0,0,10164,15130,0,"kelidan SAY_WAKE"),
(17377,1,0,"Closer! Come closer... and burn!",14,0,100,0,0,10165,15132,0,"kelidan SAY_NOVA"),
(17377,2,0,"Just as you deserve!",14,0,100,0,0,10169,17670,0,"kelidan SAY_SLAY_1"),
(17377,2,1,"Your friends will soon be joining you!",14,0,100,0,0,10170,17671,0,"kelidan SAY_SLAY_2"),
(17377,3,0,"Good...luck. You'll need it.",14,0,100,0,0,10171,17672,0,"kelidan SAY_DEATH"),

(17653,0,0,"You mustn't let him loose!",14,0,100,0,0,10166,17673,0,"Shadowmoon Channeler SAY_AGGRO_1"),
(17653,0,1,"Ignorant whelps!",14,0,100,0,0,10167,17674,0,"Shadowmoon Channeler SAY_AGGRO_2"),
(17653,0,2,"You fools! He'll kill us all!",14,0,100,0,0,10168,17675,0,"Shadowmoon Channeler SAY_AGGRO_3");
