-- Fix Karuk quests - Remove Karuk's Oath as NextQuestId in A Diplomatic Mission, as this blocks Horde from doing Karuk's Oath after turning in Seek Out Karuk!
UPDATE quest_template SET NextQuestId=0 WHERE Id=12141;
