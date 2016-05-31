-- Elwynn Forest Quest Chain - Fix the quest flags so they follow the correct chain
update quest_template set PrevQuestId = 0, ExclusiveGroup = 0 where id = 28757;
update quest_template set PrevQuestId = 0, ExclusiveGroup = 0 where id = 28767;
update quest_template set PrevQuestId = 0, ExclusiveGroup = 0 where id = 28762;
update quest_template set PrevQuestId = 0, ExclusiveGroup = 0 where id = 28763;
update quest_template set PrevQuestId = 0, ExclusiveGroup = 0 where id = 28764;
update quest_template set PrevQuestId = 0, ExclusiveGroup = 0 where id = 28765;
update quest_template set PrevQuestId = 0, ExclusiveGroup = 0 where id = 28766;
update quest_template set PrevQuestId = 0, ExclusiveGroup = 0 where id = 29078;
-- Second quest
update quest_template set PrevQuestId = 28757, ExclusiveGroup = 0 where id = 28769;
update quest_template set PrevQuestId = 28767, ExclusiveGroup = 0 where id = 28759;
update quest_template set PrevQuestId = 28762, ExclusiveGroup = 0 where id = 28770;
update quest_template set PrevQuestId = 28763, ExclusiveGroup = 0 where id = 28771;
update quest_template set PrevQuestId = 28764, ExclusiveGroup = 0 where id = 28772;
update quest_template set PrevQuestId = 28765, ExclusiveGroup = 0 where id = 28773;
update quest_template set PrevQuestId = 28766, ExclusiveGroup = 0 where id = 28774;
update quest_template set PrevQuestId = 29078, ExclusiveGroup = 0 where id = 29079;
-- Third quest
update quest_template set PrevQuestId = 28759, ExclusiveGroup = 0 where id = 26910;
update quest_template set PrevQuestId = 28769, ExclusiveGroup = 0 where id = 3104;
update quest_template set PrevQuestId = 28770, ExclusiveGroup = 0 where id = 3101;
update quest_template set PrevQuestId = 28771, ExclusiveGroup = 0 where id = 3103;
update quest_template set PrevQuestId = 28772, ExclusiveGroup = 0 where id = 3102;
update quest_template set PrevQuestId = 28773, ExclusiveGroup = 0 where id = 3105;
update quest_template set PrevQuestId = 28774, ExclusiveGroup = 0 where id = 3100;
update quest_template set PrevQuestId = 29079, ExclusiveGroup = 0 where id = 29080;
-- Fourth quest
update quest_template set PrevQuestId = 3100, ExclusiveGroup = 0 where id = 26913;
update quest_template set PrevQuestId = 3101, ExclusiveGroup = 0 where id = 26918;
update quest_template set PrevQuestId = 3102, ExclusiveGroup = 0 where id = 26915;
update quest_template set PrevQuestId = 3103, ExclusiveGroup = 0 where id = 26919;
update quest_template set PrevQuestId = 3104, ExclusiveGroup = 0 where id = 26916;
update quest_template set PrevQuestId = 3105, ExclusiveGroup = 0 where id = 26914;
update quest_template set PrevQuestId = 26910, ExclusiveGroup = 0 where id = 26917;
update quest_template set PrevQuestId = 29080, ExclusiveGroup = 0 where id = 29081;
-- Fifth quest
update quest_template set PrevQuestId = 26913, ExclusiveGroup = 0 where id = 28789;
update quest_template set PrevQuestId = 26914, ExclusiveGroup = 0 where id = 28788;
update quest_template set PrevQuestId = 26915, ExclusiveGroup = 0 where id = 28787;
update quest_template set PrevQuestId = 26916, ExclusiveGroup = 0 where id = 28784;
update quest_template set PrevQuestId = 26917, ExclusiveGroup = 0 where id = 28780;
update quest_template set PrevQuestId = 26918, ExclusiveGroup = 0 where id = 28785;
update quest_template set PrevQuestId = 26919, ExclusiveGroup = 0 where id = 28786;
update quest_template set PrevQuestId = 29081, ExclusiveGroup = 0 where id = 29083;
-- Sixth quest
update quest_template set PrevQuestId = 28780, ExclusiveGroup = 0 where id = 28791;
update quest_template set PrevQuestId = 28784, ExclusiveGroup = 0 where id = 28792;
update quest_template set PrevQuestId = 28785, ExclusiveGroup = 0 where id = 28793;
update quest_template set PrevQuestId = 28786, ExclusiveGroup = 0 where id = 28794;
update quest_template set PrevQuestId = 28787, ExclusiveGroup = 0 where id = 28795;
update quest_template set PrevQuestId = 28788, ExclusiveGroup = 0 where id = 28796;
update quest_template set PrevQuestId = 28789, ExclusiveGroup = 0 where id = 28797;
update quest_template set PrevQuestId = 29083, ExclusiveGroup = 0 where id = 26389;
