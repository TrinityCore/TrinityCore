-- Fix Karuk not offering Karuk's Oath after completing Seek Out Karuk (Horde)

UPDATE `quest_template` SET `NextQuestId`=0 WHERE `Id`=12141;
