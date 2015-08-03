--
UPDATE `quest_template` SET `NextQuestId`=13722 WHERE `Id` =13696;
UPDATE `quest_template` SET `NextQuestId`=13593 WHERE `Id` =13593;
-- The below is to fix the alliance chain, horde chain works fine with above 2 changes, but http://www.wowhead.com/quest=13593
-- Valiant Of Stormwind had `NextQuestIdChain` set to http://www.wowhead.com/quest=13722 The Valiant's Charge which is
-- Horde (Bloodelf) quest, wowhead says quest is horde but wrongly says it grants stormwind rep too so maybe someone got this wrong
-- whole chain worked fine for humans but for non-humans chain would break after turning in http://www.wowhead.com/quest=13593 as 
-- http://www.wowhead.com/quest=13718 would never be offered to non humans once they picked to champion stormwind after doing own faction

-- Basically the non human quest for starting stormwind chain had nextquestchainid pointing to horde quest and thats what
-- was breaking it for alliance.
UPDATE `quest_template` SET `NextQuestIdChain`=13718 WHERE  `Id`=13593;
