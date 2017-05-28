DELETE FROM `quest_request_items` WHERE `ID` IN (28757,28762,28763,28764,28765,28766,28767,29078,28759,28769,28770,28771,28772,28773,28774,29079,28791,28792,28793,28794,28795,28796,28797,29081,28806,28808,28809,28810,28811,28812,28813,29082);
INSERT INTO `quest_request_items` (`ID`,`EmoteOnComplete`,`EmoteOnIncomplete`,`CompletionText`,`VerifiedBuild`) VALUES
(28757,6,0, 'Have you beaten back the Blackrock worgs?',0),
(28762,6,0, 'Have you beaten back the Blackrock worgs?',0),
(28763,6,0, 'Have you beaten back the Blackrock worgs?',0),
(28764,6,0, 'Have you beaten back the Blackrock worgs?',0),
(28765,6,0, 'Have you beaten back the Blackrock worgs?',0),
(28766,6,0, 'Have you beaten back the Blackrock worgs?',0),
(28767,6,0, 'Have you beaten back the Blackrock worgs?',0),
(29078,6,0, 'Have you beaten back the Blackrock worgs?',0),
(28759,5,0, 'Kill the spies!',0),
(28769,5,0, 'Kill the spies!',0),
(28770,5,0, 'Kill the spies!',0),
(28771,5,0, 'Kill the spies!',0),
(28772,5,0, 'Kill the spies!',0),
(28773,5,0, 'Kill the spies!',0),
(28774,5,0, 'Kill the spies!',0),
(29079,5,0, 'Kill the spies!',0),
(28791,0,0, 'Kill the goblin assassins',0),
(28792,0,0, 'Kill the goblin assassins',0),
(28793,0,0, 'Kill the goblin assassins',0),
(28794,0,0, 'Kill the goblin assassins',0),
(28795,0,0, 'Kill the goblin assassins',0),
(28796,0,0, 'Kill the goblin assassins',0),
(28797,0,0, 'Kill the goblin assassins',0),
(29081,0,0, 'Kill the goblin assassins',0),
(28806,5,0, 'Rescue our Soldiers!',0),
(28808,5,0, 'Rescue our Soldiers!',0),
(28809,5,0, 'Rescue our Soldiers!',0),
(28810,5,0, 'Rescue our Soldiers!',0),
(28811,5,0, 'Rescue our Soldiers!',0),
(28812,5,0, 'Rescue our Soldiers!',0),
(28813,5,0, 'Rescue our Soldiers!',0),
(29082,5,0, 'Rescue our Soldiers!',0);

DELETE FROM `quest_offer_reward` WHERE `ID` IN (28757,28762,28763,28764,28765,28766,28767,29078,28759,28769,28770,28771,28772,28773,28774,29079,28780,28784,28785,28786,28787,28788,28789,29080,28806,28808,28809,28810,28811,28812,28813,29082,28791,28792,28793,28794,28795,28796,28797,29081,28817,28818,28819,28820,28821,28822,28823,29083);
INSERT INTO `quest_offer_reward` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`RewardText`,`VerifiedBuild`) VALUES
(28757,1,1,0,0,0,0,0,0, 'You''ve bought us a little time, $n, but we''ve got even bigger problems to deal with now.',0),
(28762,1,1,0,0,0,0,0,0, 'You''ve bought us a little time, $n, but we''ve got even bigger problems to deal with now.',0),
(28763,1,1,0,0,0,0,0,0, 'You''ve bought us a little time, $n, but we''ve got even bigger problems to deal with now.',0),
(28764,1,1,0,0,0,0,0,0, 'You''ve bought us a little time, $n, but we''ve got even bigger problems to deal with now.',0),
(28765,1,1,0,0,0,0,0,0, 'You''ve bought us a little time, $n, but we''ve got even bigger problems to deal with now.',0),
(28766,1,1,0,0,0,0,0,0, 'You''ve bought us a little time, $n, but we''ve got even bigger problems to deal with now.',0),
(28767,1,1,0,0,0,0,0,0, 'You''ve bought us a little time, $n, but we''ve got even bigger problems to deal with now.',0),
(29078,1,1,0,0,0,0,0,0, 'You''ve bought us a little time, $n, but we''ve got even bigger problems to deal with now.',0),
(28759,21,1,5,0,0,0,0,0, 'Excellent work, $n. You''ve turned out to be quite an asset to this garrison. It''s time for you to train!',0),
(28769,21,1,5,0,0,0,0,0, 'Excellent work, $n. You''ve turned out to be quite an asset to this garrison. It''s time for you to train!',0),
(28770,21,1,5,0,0,0,0,0, 'Excellent work, $n. You''ve turned out to be quite an asset to this garrison. It''s time for you to train!',0),
(28771,21,1,5,0,0,0,0,0, 'Excellent work, $n. You''ve turned out to be quite an asset to this garrison. It''s time for you to train!',0),
(28772,21,1,5,0,0,0,0,0, 'Excellent work, $n. You''ve turned out to be quite an asset to this garrison. It''s time for you to train!',0),
(28773,21,1,5,0,0,0,0,0, 'Excellent work, $n. You''ve turned out to be quite an asset to this garrison. It''s time for you to train!',0),
(28774,21,1,5,0,0,0,0,0, 'Excellent work, $n. You''ve turned out to be quite an asset to this garrison. It''s time for you to train!',0),
(29079,21,1,5,0,0,0,0,0, 'Excellent work, $n. You''ve turned out to be quite an asset to this garrison. It''s time for you to train!',0),
(28780,0,0,0,0,0,0,0,0, 'It''s true, we were ambushed. I don''t dare send any more soldiers out there and risk losing them too. I need a volunteer. Someone willing to risk their life!',0),
(28784,0,0,0,0,0,0,0,0, 'It''s true, we were ambushed. I don''t dare send any more soldiers out there and risk losing them too. I need a volunteer. Someone willing to risk their life!',0),
(28785,0,0,0,0,0,0,0,0, 'It''s true, we were ambushed. I don''t dare send any more soldiers out there and risk losing them too. I need a volunteer. Someone willing to risk their life!',0),
(28786,0,0,0,0,0,0,0,0, 'It''s true, we were ambushed. I don''t dare send any more soldiers out there and risk losing them too. I need a volunteer. Someone willing to risk their life!',0),
(28787,0,0,0,0,0,0,0,0, 'It''s true, we were ambushed. I don''t dare send any more soldiers out there and risk losing them too. I need a volunteer. Someone willing to risk their life!',0),
(28788,0,0,0,0,0,0,0,0, 'It''s true, we were ambushed. I don''t dare send any more soldiers out there and risk losing them too. I need a volunteer. Someone willing to risk their life!',0),
(28789,0,0,0,0,0,0,0,0, 'It''s true, we were ambushed. I don''t dare send any more soldiers out there and risk losing them too. I need a volunteer. Someone willing to risk their life!',0),
(29080,0,0,0,0,0,0,0,0, 'It''s true, we were ambushed. I don''t dare send any more soldiers out there and risk losing them too. I need a volunteer. Someone willing to risk their life!',0),
(28806,273,4,0,0,0,0,0,0, 'I think you now understand the power of the Light. The Light giveth hope, $g brother:sister; and the Light taketh from the darkness! BLESSED BE THE LIGHT!',0),
(28808,273,4,0,0,0,0,0,0, 'I think you now understand the power of the Light. The Light giveth hope, $g brother:sister; and the Light taketh from the darkness! BLESSED BE THE LIGHT!',0),
(28809,273,4,0,0,0,0,0,0, 'I think you now understand the power of the Light. The Light giveth hope, $g brother:sister; and the Light taketh from the darkness! BLESSED BE THE LIGHT!',0),
(28810,273,4,0,0,0,0,0,0, 'I think you now understand the power of the Light. The Light giveth hope, $g brother:sister; and the Light taketh from the darkness! BLESSED BE THE LIGHT!',0),
(28811,273,4,0,0,0,0,0,0, 'I think you now understand the power of the Light. The Light giveth hope, $g brother:sister; and the Light taketh from the darkness! BLESSED BE THE LIGHT!',0),
(28812,273,4,0,0,0,0,0,0, 'I think you now understand the power of the Light. The Light giveth hope, $g brother:sister; and the Light taketh from the darkness! BLESSED BE THE LIGHT!',0),
(28813,273,4,0,0,0,0,0,0, 'I think you now understand the power of the Light. The Light giveth hope, $g brother:sister; and the Light taketh from the darkness! BLESSED BE THE LIGHT!',0),
(29082,273,4,0,0,0,0,0,0, 'I think you now understand the power of the Light. The Light giveth hope, $g brother:sister; and the Light taketh from the darkness! BLESSED BE THE LIGHT!',0),
(28791,0,0,0,0,0,0,0,0, 'That will teach those monsters! They''ll think twice before taking another mercenary job for orcs.',0),
(28792,0,0,0,0,0,0,0,0, 'That will teach those monsters! They''ll think twice before taking another mercenary job for orcs.',0),
(28793,0,0,0,0,0,0,0,0, 'That will teach those monsters! They''ll think twice before taking another mercenary job for orcs.',0),
(28794,0,0,0,0,0,0,0,0, 'That will teach those monsters! They''ll think twice before taking another mercenary job for orcs.',0),
(28795,0,0,0,0,0,0,0,0, 'That will teach those monsters! They''ll think twice before taking another mercenary job for orcs.',0),
(28796,0,0,0,0,0,0,0,0, 'That will teach those monsters! They''ll think twice before taking another mercenary job for orcs.',0),
(28797,0,0,0,0,0,0,0,0, 'That will teach those monsters! They''ll think twice before taking another mercenary job for orcs.',0),
(29081,0,0,0,0,0,0,0,0, 'That will teach those monsters! They''ll think twice before taking another mercenary job for orcs.',0),
(28817,1,1,1,5,0,0,0,0, 'With your help we have managed to secure the northern and western sectors of Northshire. We still have a rather large contingency of Blackrock orcs to the east and they''ve begun burning down the forest!',0),
(28818,1,1,1,5,0,0,0,0, 'With your help we have managed to secure the northern and western sectors of Northshire. We still have a rather large contingency of Blackrock orcs to the east and they''ve begun burning down the forest!',0),
(28819,1,1,1,5,0,0,0,0, 'With your help we have managed to secure the northern and western sectors of Northshire. We still have a rather large contingency of Blackrock orcs to the east and they''ve begun burning down the forest!',0),
(28820,1,1,1,5,0,0,0,0, 'With your help we have managed to secure the northern and western sectors of Northshire. We still have a rather large contingency of Blackrock orcs to the east and they''ve begun burning down the forest!',0),
(28821,1,1,1,5,0,0,0,0, 'With your help we have managed to secure the northern and western sectors of Northshire. We still have a rather large contingency of Blackrock orcs to the east and they''ve begun burning down the forest!',0),
(28822,1,1,1,5,0,0,0,0, 'With your help we have managed to secure the northern and western sectors of Northshire. We still have a rather large contingency of Blackrock orcs to the east and they''ve begun burning down the forest!',0),
(28823,1,1,1,5,0,0,0,0, 'With your help we have managed to secure the northern and western sectors of Northshire. We still have a rather large contingency of Blackrock orcs to the east and they''ve begun burning down the forest!',0),
(29083,1,1,1,5,0,0,0,0, 'With your help we have managed to secure the northern and western sectors of Northshire. We still have a rather large contingency of Blackrock orcs to the east and they''ve begun burning down the forest!',0);

UPDATE `quest_template_addon` SET `AllowableClasses`=4,`NextQuestID`=28759 WHERE `ID`=28767; -- Hunter
UPDATE `quest_template_addon` SET `AllowableClasses`=128,`NextQuestID`=28769 WHERE `ID`=28757; -- Mage
UPDATE `quest_template_addon` SET `AllowableClasses`=2,`NextQuestID`=28770 WHERE `ID`=28762; -- Paladin
UPDATE `quest_template_addon` SET `AllowableClasses`=16,`NextQuestID`=28771 WHERE `ID`=28763; -- Priest
UPDATE `quest_template_addon` SET `AllowableClasses`=8,`NextQuestID`=28772 WHERE `ID`=28764; -- Rogue
UPDATE `quest_template_addon` SET `AllowableClasses`=256,`NextQuestID`=28773 WHERE `ID`=28765; -- Warlock
UPDATE `quest_template_addon` SET `AllowableClasses`=1,`NextQuestID`=28774 WHERE `ID`=28766; -- Warrior
UPDATE `quest_template_addon` SET `AllowableClasses`=32,`NextQuestID`=29079 WHERE `ID`=29078; -- Deathknight

UPDATE `quest_template_addon` SET `AllowableClasses`=4,`NextQuestID`=28780 WHERE `ID`=28759; -- Hunter
UPDATE `quest_template_addon` SET `AllowableClasses`=128,`NextQuestID`=28784 WHERE `ID`=28769; -- Mage
UPDATE `quest_template_addon` SET `AllowableClasses`=2,`NextQuestID`=28785 WHERE `ID`=28770; -- Paladin
UPDATE `quest_template_addon` SET `AllowableClasses`=16,`NextQuestID`=28786 WHERE `ID`=28771; -- Priest
UPDATE `quest_template_addon` SET `AllowableClasses`=8,`NextQuestID`=28787 WHERE `ID`=28772; -- Rogue
UPDATE `quest_template_addon` SET `AllowableClasses`=256,`NextQuestID`=28788 WHERE `ID`=28773; -- Warlock
UPDATE `quest_template_addon` SET `AllowableClasses`=1,`NextQuestID`=28789 WHERE `ID`=28774; -- Warrior
UPDATE `quest_template_addon` SET `AllowableClasses`=32,`NextQuestID`=29080 WHERE `ID`=29079; -- Deathknight

UPDATE `quest_template_addon` SET `AllowableClasses`=4,`NextQuestID`=28791 WHERE `ID`=28780; -- Hunter
UPDATE `quest_template_addon` SET `AllowableClasses`=128,`NextQuestID`=28792 WHERE `ID`=28784; -- Mage
UPDATE `quest_template_addon` SET `AllowableClasses`=2,`NextQuestID`=28793 WHERE `ID`=28785; -- Paladin
UPDATE `quest_template_addon` SET `AllowableClasses`=16,`NextQuestID`=28794 WHERE `ID`=28786; -- Priest
UPDATE `quest_template_addon` SET `AllowableClasses`=8,`NextQuestID`=28795 WHERE `ID`=28787; -- Rogue
UPDATE `quest_template_addon` SET `AllowableClasses`=256,`NextQuestID`=28796 WHERE `ID`=28788; -- Warlock
UPDATE `quest_template_addon` SET `AllowableClasses`=1,`NextQuestID`=28797 WHERE `ID`=28789; -- Warrior
UPDATE `quest_template_addon` SET `AllowableClasses`=32,`NextQuestID`=29081 WHERE `ID`=29080; -- Deathknight

UPDATE `quest_template_addon` SET `AllowableClasses`=4,`NextQuestID`=28817 WHERE `ID`=28791; -- Hunter
UPDATE `quest_template_addon` SET `AllowableClasses`=128,`NextQuestID`=28818 WHERE `ID`=28792; -- Mage
UPDATE `quest_template_addon` SET `AllowableClasses`=2,`NextQuestID`=28819 WHERE `ID`=28793; -- Paladin
UPDATE `quest_template_addon` SET `AllowableClasses`=16,`NextQuestID`=28820 WHERE `ID`=28794; -- Priest
UPDATE `quest_template_addon` SET `AllowableClasses`=8,`NextQuestID`=28821 WHERE `ID`=28795; -- Rogue
UPDATE `quest_template_addon` SET `AllowableClasses`=256,`NextQuestID`=28822 WHERE `ID`=28796; -- Warlock
UPDATE `quest_template_addon` SET `AllowableClasses`=4,`NextQuestID`=28823 WHERE `ID`=28797; -- Warrior
UPDATE `quest_template_addon` SET `AllowableClasses`=32,`NextQuestID`=29083 WHERE `ID`=29081; -- Deathknight

UPDATE `quest_template_addon` SET `AllowableClasses`=4,`PrevQuestID`=28780 WHERE `ID`=28806; -- Hunter
UPDATE `quest_template_addon` SET `AllowableClasses`=128,`PrevQuestID`=28784 WHERE `ID`=28808; -- Mage
UPDATE `quest_template_addon` SET `AllowableClasses`=2,`PrevQuestID`=28785 WHERE `ID`=28809; -- Paladin
UPDATE `quest_template_addon` SET `AllowableClasses`=16,`PrevQuestID`=28786 WHERE `ID`=28810; -- Priest
UPDATE `quest_template_addon` SET `AllowableClasses`=8,`PrevQuestID`=28787 WHERE `ID`=28811; -- Rogue
UPDATE `quest_template_addon` SET `AllowableClasses`=256,`PrevQuestID`=28788 WHERE `ID`=28812; -- Warlock
UPDATE `quest_template_addon` SET `AllowableClasses`=4,`PrevQuestID`=28789 WHERE `ID`=28813; -- Warrior
UPDATE `quest_template_addon` SET `AllowableClasses`=32,`PrevQuestID`=29080 WHERE `ID`=29082; -- Deathknight

UPDATE `quest_template_addon` SET `AllowableClasses`=4,`NextQuestID`=26389 WHERE `ID`=28817; -- Hunter
UPDATE `quest_template_addon` SET `AllowableClasses`=128,`NextQuestID`=26389 WHERE `ID`=28818; -- Mage
UPDATE `quest_template_addon` SET `AllowableClasses`=2,`NextQuestID`=26389 WHERE `ID`=28819; -- Paladin
UPDATE `quest_template_addon` SET `AllowableClasses`=16,`NextQuestID`=26389 WHERE `ID`=28820; -- Priest
UPDATE `quest_template_addon` SET `AllowableClasses`=8,`NextQuestID`=26389 WHERE `ID`=28821; -- Rogue
UPDATE `quest_template_addon` SET `AllowableClasses`=256,`NextQuestID`=26389 WHERE `ID`=28822; -- Warlock
UPDATE `quest_template_addon` SET `AllowableClasses`=4,`NextQuestID`=26389 WHERE `ID`=28823; -- Warrior
UPDATE `quest_template_addon` SET `AllowableClasses`=32,`NextQuestID`=26389 WHERE `ID`=29083; -- Deathknight

UPDATE `creature_queststarter` SET `id`=197 WHERE `quest` IN (28780,28784,28785,28786,28787,28788,28789,29080);
