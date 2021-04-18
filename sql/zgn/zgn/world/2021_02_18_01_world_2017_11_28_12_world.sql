-- 
DELETE FROM `creature_text` WHERE `CreatureID`=35476 AND `GroupID`=0 AND `ID` IN (2,3);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(35476,0,2,'It won''t be long before Fizzlebang is a household word, used to scare children into bed! "Beware, or Fizzlebang will summon a mighty demon to eat you!"',12,0,100,1,0,0,35817,0,"Wilfred Fizzlebang"),
(35476,0,3,'I, Wilfred Fizzlebang, have been invited to this quaint tournament to make use of my extensive knowledge of the summoning arts. What better choice?',12,0,100,1,0,0,35815,0,"Wilfred Fizzlebang");
