-- Correct (Return) Default Language

DELETE FROM `quest_offer_reward` WHERE ID IN (14313,14320,14321,14336,14375,14367);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
('14313','0','0','0','0','0','0','0','0','It worked!  By the Light, it worked!','26365'),
('14320','0','0','0','0','0','0','0','0','The crate has been smashed and the vials inside of it appear to have been broken.','26365'),
('14321','0','0','0','0','0','0','0','0','Forsaken!  Quick, $N!  We must mount a defense.','26365'),
('14336','0','0','0','0','0','0','0','0','$N!!!  You ARE alive!$B$BI thought I was having dreams about the old days when I heard your voice...','26365'),
('14375','0','0','0','0','0','0','0','0','I need you to pull through, $N.  This dosage is strong enough to kill a horse.$B$BBut I know you.  I know what you\'re made of.  You will be fine.$B$BTrust me.  I know what you\'re going through.$B$BNow drink up and close your eyes.','26365'),
('14367','0','0','0','0','0','0','0','0','The Forsaken are here in full strength, $N.  We barely have enough men to hold them back.','26365');

DELETE FROM `gossip_menu_option` WHERE (`MenuId` = 10841 AND `OptionIndex` = 0) OR (`MenuId` = 12188 AND `OptionIndex` = 15) OR (`MenuId` = 12188 AND `OptionIndex` = 14) OR (`MenuId` = 12188 AND `OptionIndex` = 13) OR (`MenuId` = 12188 AND `OptionIndex` = 12) OR (`MenuId` = 12188 AND `OptionIndex` = 11) OR (`MenuId` = 12185 AND `OptionIndex` = 14) OR (`MenuId` = 12185 AND `OptionIndex` = 13) OR (`MenuId` = 12185 AND `OptionIndex` = 3) OR (`MenuId` = 12185 AND `OptionIndex` = 8) OR (`MenuId` = 12185 AND `OptionIndex` = 12) OR (`MenuId` = 12185 AND `OptionIndex` = 11) OR (`MenuId`=12180 AND `OptionIndex`=12) OR (`MenuId` = 12180 AND `OptionIndex` = 0) OR (`MenuId` = 12180 AND `OptionIndex` = 1) OR (`MenuId` = 12180 AND `OptionIndex` = 11) OR (`MenuId` = 12180 AND `OptionIndex` = 3) OR (`MenuId` = 12180 AND `OptionIndex` = 4)  OR (`MenuId` = 12180 AND `OptionIndex` = 6) OR (`MenuId` = 12180 AND `OptionIndex` = 8) OR (`MenuId` = 5855 AND `OptionIndex` = 0) OR (`MenuId` = 5853 AND `OptionIndex` = 0); 
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES
('5853','0','3','Train me.','3266','5','16','26365'),
('5855','0','3','Train me.','3266','5','16','26365'),
('10841','0','1','Let me browse your goods.','2823','3','128','26365'),
('12180','0','3','Train me in Alchemy.','0','3','16','26365'),
('12180','1','3','Train me in Blacksmithing.','0','3','1','26365'),
('12180','3','3','Train me in Engineering.','0','3','16','26365'),
('12180','4','3','Train me in Herbalism.','0','3','16','26365'),
('12180','6','3','Train me in Jewelcrafting.','0','3','16','26365'),
('12180','8','3','Train me in Mining.','0','3','16','26365'),
('12180','11','0','Tell me about gathering professions.','47106','1','1','26365'),
('12180','12','0','Tell me about production professions.','47107','1','1','26365'),
('12185','3','3','Train me in Engineering.','0','3','16','26365'),
('12185','8','3','Train me in Mining.','0','3','16','26365'),
('12185','11','0','Tell me about Herbalism.','47142','1','1','26365'),
('12185','12','0','Tell me about Mining.','47143','1','1','26365'),
('12185','13','0','Tell me about Skinning.','47144','1','1','26365'),
('12185','14','0','Tell me about production professions.','47107','1','1','26365'),
('12188','11','3','Train me in Herbalism.','47112','5','1','26365'),
('12188','12','0','Tell me about Alchemy.','47145','1','1','26365'),
('12188','13','0','Tell me about Inscription.','47149','1','1','26365'),
('12188','14','0','Tell me about gathering professions.','47106','1','1','26365'),
('12188','15','0','Tell me about production professions.','47107','1','1','26365');

DELETE FROM `quest_template` WHERE ID IN (14313,14320,14321,14336,14347,14348,14375);
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestLevel`, `MaxScalingLevel`, `QuestPackageID`, `MinLevel`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoney`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardDisplaySpell1`, `RewardDisplaySpell2`, `RewardDisplaySpell3`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `RewardItem1`, `RewardAmount1`, `RewardItem2`, `RewardAmount2`, `RewardItem3`, `RewardAmount3`, `RewardItem4`, `RewardAmount4`, `ItemDrop1`, `ItemDropQuantity1`, `ItemDrop2`, `ItemDropQuantity2`, `ItemDrop3`, `ItemDropQuantity3`, `ItemDrop4`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemQuantity1`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemID2`, `RewardChoiceItemQuantity2`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemID3`, `RewardChoiceItemQuantity3`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemID4`, `RewardChoiceItemQuantity4`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemID5`, `RewardChoiceItemQuantity5`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitTurnIn`, `RewardFactionID1`, `RewardFactionValue1`, `RewardFactionOverride1`, `RewardFactionCapIn1`, `RewardFactionID2`, `RewardFactionValue2`, `RewardFactionOverride2`, `RewardFactionCapIn2`, `RewardFactionID3`, `RewardFactionValue3`, `RewardFactionOverride3`, `RewardFactionCapIn3`, `RewardFactionID4`, `RewardFactionValue4`, `RewardFactionOverride4`, `RewardFactionCapIn4`, `RewardFactionID5`, `RewardFactionValue5`, `RewardFactionOverride5`, `RewardFactionCapIn5`, `RewardFactionFlags`, `RewardCurrencyID1`, `RewardCurrencyQty1`, `RewardCurrencyID2`, `RewardCurrencyQty2`, `RewardCurrencyID3`, `RewardCurrencyQty3`, `RewardCurrencyID4`, `RewardCurrencyQty4`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `QuestRewardID`, `Expansion`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `QuestCompletionLog`, `VerifiedBuild`) VALUES
('14313','2','-1','20','0','5','4714','0','0','14320','3','1','600','3','1','30','0','0','0','68996','0','0','0','0','1','0','8','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1134','2','2500','7','0','0','0','7','0','0','0','7','0','0','0','7','0','0','0','7','0','0','0','0','0','0','0','0','0','890','878','0','0','-1067450368','0','0','Among Humans Again','Speak to Krennan Aranas in Duskhaven.','So Krennan\'s potion did not kill you?  Well, I suppose that means the human inside of you is in control then.$B$BI guess I won\'t be shooting you after all.  At least not yet.$B$BGo speak to Krennan Aranas and give him the good news.  He\'s in charge of the house where we keep... your kind.$B$BJust remember, $n.  I\'ve got my eye on you.  You so much as try anything funny and you\'ll get a bullet between the eyes.','','','','','','','25996'),
('14320','2','-1','20','0','5','4714','0','0','0','5','1','1200','5','1','90','0','0','0','69296','0','0','0','0','1','0','2097160','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1134','5','25000','7','0','0','0','7','0','0','0','7','0','0','0','7','0','0','0','7','0','0','0','0','0','0','0','0','0','890','878','0','0','-1067450368','0','0','In Need of Ingredients','Find the Crate of Mandrake Essence.','Ah, yes.  The effects of the Curse cannot ever be fully cured as far as we know.$B$BWith treatment, however, your mind will remain yours... and not that of a wild animal.$B$BWe are fortunate that the treatment worked on you.  Normally, I can only treat recent infections.$B$BWe\'ll need to continue your medication if we\'re to have you reverse the Curse.$B$BI will need mandrake essence to brew another batch of my serum for you.  You will find a crate stashed beneath a shed southwest of town.','','','','','','','26365'),
('14321','2','-1','20','0','5','4714','0','0','14336','5','1','1200','5','1','90','0','0','0','0','0','0','0','0','1','0','8','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1134','5','25000','7','0','0','0','7','0','0','0','7','0','0','0','7','0','0','0','7','0','0','0','0','0','0','0','0','0','890','878','0','0','-1067450368','0','0','Invasion','Speak to Gwen Armstead in Duskhaven.','<A long knife with a skull ornament on its hilt sticks out of the militiaman\'s ribs.  As you look around for clues, you spot a pair of savage-looking warships at the shore.>$B$B<Gilneas is being invaded.  Bring word back to Duskhaven\'s Mayor, Gwen Armstead.>','','','','','','','26365'),
('14336','2','-1','20','0','5','4714','0','0','0','3','1','600','3','1','30','0','0','0','0','0','0','0','0','1','0','16777224','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1134','3','7500','7','0','0','0','7','0','0','0','7','0','0','0','7','0','0','0','7','0','0','0','0','0','0','0','0','0','890','878','0','0','-1067450368','0','0','Kill or Be Killed','Speak to Prince Liam Greymane outside of Duskhaven.','The reefs have always protected us from a coastal attack.  The earthquakes must\'ve opened a passage for the Forsaken ships.$B$BQuick, $n.  Slow down the attackers while I get the rest of the militia ready.$B$BI think I can hear the Prince and some of our men engaging the Forsaken even as we speak.  Speak to Liam and see how you can be of use.$B$BOh... and make sure he doesn\'t get himself killed.  I\'m afraid he might be a little reckless in his current state.','','','','','','','26365'),
('14347','2','-1','20','1874','5','4714','0','0','14366','5','1','1200','5','1','90','0','0','0','0','0','0','0','0','1','0','8','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1134','5','25000','7','0','0','0','7','0','0','0','7','0','0','0','7','0','0','0','7','0','0','0','0','0','0','0','0','0','890','878','0','0','-1067450368','0','0','Hold the Line','Kill 10 Forsaken Invaders.','$n!  I\'m still not sure if you\'re alive or dead... human or worgen...$B$BI\'m not even sure if I\'m really awake.  But THIS I am sure of...$B$BWe\'re going to kill a great many of these motherless Forsaken.','','','','','','','26365'),
('14348','2','-1','20','1875','5','4714','0','0','14366','5','1','1200','5','1','90','0','0','0','0','0','0','0','0','1','0','131080','0','2723','5','0','0','0','0','0','0','49202','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1134','5','25000','7','0','0','0','7','0','0','0','7','0','0','0','7','0','0','0','7','0','0','0','0','0','0','0','0','0','890','878','0','0','-1067450368','0','0','You Can\'t Take \'Em Alone','Use the Black Gunpowder Kegs to blow up 4 Horrid Abominations.','Look here, $n.  The big fat ones -- abominations, they\'re called -- they don\'t go down easy, so don\'t tackle them on your own.$B$BBut I have an idea so crazy it might just work.  Or it might get you killed, if we\'re not careful, I suppose.$B$BThere\'s barrels of gunpowder beneath the sheds and by the windmills.  Grab them and toss \'em right on the abominations\' heads.  I\'ll take care of the rest with this trusty old blunderbuss.','','','','','','','26365'),
('14375','0','-1','20','0','5','4714','0','0','0','5','1','0','0','1','90','0','0','0','68639','0','0','0','0','1','0','8','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1134','5','25000','7','0','0','0','7','0','0','0','7','0','0','0','7','0','0','0','7','0','0','0','0','0','0','0','0','0','890','878','0','0','-1067450368','0','0','Last Chance at Humanity','','','','','','','','','26365');

UPDATE gameobject_template SET NAME = "Crate of Mandrake Essence" WHERE entry = 196394;
UPDATE gameobject_template SET NAME = "Black Gunpowder Keg" WHERE entry = 196403;
UPDATE gameobject_template SET NAME = "Mailbox" WHERE entry = 196846;
UPDATE gameobject_template SET NAME = "Brazier" WHERE entry = 196849;
UPDATE gameobject_template SET NAME = "Cookpot" WHERE entry = 196854;
UPDATE gameobject_template SET NAME = "Forge" WHERE entry = 196879;
UPDATE gameobject_template SET NAME = "Anvil" WHERE entry = 196880;
UPDATE gameobject_template SET NAME = "Gilneas Invasion Camera" WHERE entry = 197337;

-- Add Russian Language on locale tables where it belong

DELETE FROM `quest_offer_reward_locale` WHERE ID IN (14336,14321,14320,14313,14375,14367) AND (locale = "ruRU");
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
('14336','ruRU','$n! Ты и правда $gвыжил:выжила;!!!$B$BЯ уж подумал, что твой голос мне померещился.','26365'),
('14321','ruRU','Отрекшиеся! У нас мало времени, $n! Мы должны организовать оборону.','26365'),
('14320','ruRU','Похоже, что ящик сильно пострадал, и все находящиеся в нем склянки разбились.','26365'),
('14313','ruRU','Сработало! Хвала Свету, сработало!','26365'),
('14375','ruRU','Я тебя вытащу, $n. Я тебе приготовил такую дозу, что хватит свалить лошадь, но я знаю, что делаю. Я знаю, из какого теста ты $gсделан:сделана;. Ты выдержишь, и все будет хорошо.$B$BВерь мне, $n. Я понимаю, через что тебе придется пройти...$B$BА теперь выпей это и закрой глаза.','26365'),
('14367','ruRU','Отрекшиеся обрушились на нас всей своей военной мощью, $n. У нас едва хватает людей, чтобы сдерживать их натиск.','26365');

DELETE FROM `gossip_menu_option_locale` WHERE (`MenuId` = 10841 AND `OptionIndex` = 0 AND Locale = "ruRU") OR (`MenuId` = 12188 AND `OptionIndex` = 15 AND Locale = "ruRU") OR (`MenuId` = 12188 AND `OptionIndex` = 14 AND Locale = "ruRU") OR (`MenuId` = 12188 AND `OptionIndex` = 13 AND Locale = "ruRU") OR (`MenuId` = 12188 AND `OptionIndex` = 12 AND Locale = "ruRU") OR (`MenuId`=12188 AND `OptionIndex`=11) OR (`MenuId` = 12185 AND `OptionIndex` = 14 AND Locale = "ruRU") OR (`MenuId` = 12185 AND `OptionIndex` = 13 AND Locale = "ruRU") OR (`MenuId` = 12185 AND `OptionIndex` = 12 AND Locale = "ruRU") OR (`MenuId` = 12185 AND `OptionIndex` = 11 AND Locale = "ruRU") OR (`MenuId` = 12180 AND `OptionIndex` = 12 AND Locale = "ruRU") OR (`MenuId` = 12180 AND `OptionIndex` = 11 AND Locale = "ruRU") OR (`MenuId` = 5855 AND `OptionIndex` = 0 AND Locale = "ruRU") OR (`MenuId` = 5853 AND `OptionIndex` = 0 AND Locale = "ruRU"); 
INSERT INTO `gossip_menu_option_locale` (`MenuId`, `OptionIndex`, `Locale`, `OptionText`, `BoxText`) VALUES
('10841','0','ruRU','Можно мне взглянуть на товар?',''),
('12188','15','ruRU','Расскажи мне подробнее о ремесленных профессиях.',''),
('12188','14','ruRU','Расскажи мне подробнее о профессиях, связанных с собирательством и добычей ресурсов.',''),
('12188','13','ruRU','Расскажи мне о начертании.',''),
('12188','12','ruRU','Расскажи мне об алхимии.',''),
('12188','11','ruRU','Обучи меня травничеству.',''),
('12185','14','ruRU','Расскажи мне подробнее о ремесленных профессиях.',''),
('12185','13','ruRU','Расскажи мне о снятии шкур.',''),
('12185','12','ruRU','Расскажи мне о горном деле.',''),
('12185','11','ruRU','Расскажи мне о травничестве.',''),
('12180','12','ruRU','Расскажи мне подробнее о ремесленных профессиях.',''),
('12180','11','ruRU','Расскажи мне подробнее о профессиях, связанных с собирательством и добычей ресурсов.',''),
('5855','0','ruRU','Обучи меня.',''),
('5853','0','ruRU','Обучи меня.','');
