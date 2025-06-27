-- Grimclaw
DELETE FROM `creature_text` WHERE `CreatureID`=3695 AND `GroupID`<4;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3695,0,0,"%s roars at Terenthis to get his attention.",16,0,100,0,0,478,1226,0,"Grimclaw"),
(3695,1,0,"%s begins to moan and roar at Terenthis while stomping his paws on the ground.",16,0,100,53,0,474,1228,0,"Grimclaw"),
(3695,2,0,"%s roars at Terenthis more, but this time the druid seems to understand the bear.",16,0,100,0,0,473,1231,0,"Grimclaw"),
(3695,3,0,"%s roars in acknowledgement at Terenthis.",16,0,100,0,0,473,1233,0,"Grimclaw");
