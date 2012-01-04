-- Ogre Heaven fix PrevQuestID by shlomi1515
-- Closes #2732

UPDATE quest_template SET PrevQuestID='11000' WHERE ID='11009';
