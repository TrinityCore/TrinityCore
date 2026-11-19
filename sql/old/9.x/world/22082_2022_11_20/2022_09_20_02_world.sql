--
-- Quests
--

 -- The Warchief Cometh
DELETE FROM `quest_template_addon` WHERE `ID`=26965;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(26965, 0, 0, 0, 0, 26989, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

 -- The Gilneas Liberation Front
DELETE FROM `quest_template_addon` WHERE `ID`=26989;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(26989, 0, 0, 0, 0, 27039, -26989, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

 -- Agony Abounds
DELETE FROM `quest_template_addon` WHERE `ID`=26992;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(26992, 0, 0, 0, 0, 27039, -26989, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

 -- Guts and Gore
DELETE FROM `quest_template_addon` WHERE `ID`=26995;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(26995, 0, 0, 0, 0, 26998, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

 -- Iterating Upon Success
UPDATE `quest_template_addon` SET `PrevQuestID` = 26995, `NextQuestID` = 27039, `ExclusiveGroup` = -26989 WHERE `ID` = 26998;

 -- Dangerous Intentions
DELETE FROM `quest_template_addon` WHERE `ID`=27039;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(27039, 0, 0, 0, 0, 27045, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

 -- Waiting to Exsanguinate
UPDATE `quest_template_addon` SET `PrevQuestID` = 27039, `NextQuestID` = 27056 WHERE `ID` = 27045;

 -- Belmont's Report
UPDATE `quest_template_addon` SET `PrevQuestID` = 27045, `NextQuestID` = 27065 WHERE `ID` = 27056;

 -- The Warchief's Fleet
UPDATE `quest_template_addon` SET `PrevQuestID` = 27056, `NextQuestID` = 27069 WHERE `ID` = 27065;

 -- Steel Thunder
UPDATE `quest_template_addon` SET `PrevQuestID` = 27065, `NextQuestID` = 27093, `ExclusiveGroup` = -27069 WHERE `ID` = 27069;

 -- Give 'em Hell!
DELETE FROM `quest_template_addon` WHERE `ID`=27073;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(27073, 0, 0, 0, 27065, 27095, -27069, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

 -- Skitterweb Menace
DELETE FROM `quest_template_addon` WHERE `ID`=27095;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(27095, 0, 0, 0, 0, 27094, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

 -- Deeper into Darkness
UPDATE `quest_template_addon` SET `PrevQuestID` = 27095, `NextQuestID` = 27096, `ExclusiveGroup` = -27094 WHERE `ID` = 27094;

 -- Lost in the Darkness
UPDATE `quest_template_addon` SET `PrevQuestID` = 0, `NextQuestID` = 27096, `ExclusiveGroup` = -27094 WHERE `ID` = 27093;

 -- Playing Dirty
DELETE FROM `quest_template_addon` WHERE `ID`=27082;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(27082, 0, 0, 0, 27065, 27088, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

 -- It's Only Poisonous if You Ingest It
UPDATE `quest_template_addon` SET `PrevQuestID` = 27082, `NextQuestID` = 27096, `ExclusiveGroup` = -27094 WHERE `ID` = 27088;

 -- Orcs are in Order
UPDATE `quest_template_addon` SET `PrevQuestID` = 0, `NextQuestID` = 27097 WHERE `ID` = 27096;

 -- Rise, Forsaken
DELETE FROM `quest_template_addon` WHERE `ID`=27097;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(27097, 0, 0, 0, 27096, 27099, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

 -- No Escape
UPDATE `quest_template_addon` SET `PrevQuestID` = 27097, `NextQuestID` = 27098 WHERE `ID` = 27099;

 -- Lordaeron
UPDATE `quest_template_addon` SET `PrevQuestID` = 27099, `NextQuestID` = 27180 WHERE `ID` = 27098;
 
 -- To Forsaken Forward Command
 -- Note: this one belongs in a later stage, but since Sylvanas' Entry is used in two different places, 
 --    some quests are available to be taken when the player shouldn't yet, so I'm handling it now.
DELETE FROM `quest_template_addon` WHERE `ID`=27290;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(27290, 0, 0, 0, 27342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

DELETE FROM `quest_details` WHERE `ID` IN (27098 /*27098*/, 27099 /*27099*/, 27097 /*27097*/, 27096 /*27096*/, 27094 /*27094*/, 27088 /*27088*/, 27093 /*27093*/, 27095 /*27095*/, 27082 /*27082*/, 27073 /*27073*/, 27069 /*27069*/, 27065 /*27065*/, 27056 /*27056*/, 27045 /*27045*/, 27039 /*27039*/, 26998 /*26998*/, 26995 /*26995*/, 26992 /*26992*/, 26989 /*26989*/, 26965 /*26965*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(27098, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- 27098
(27099, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- 27099
(27097, 1, 1, 1, 0, 0, 0, 0, 0, 45338), -- 27097
(27096, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- 27096
(27094, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- 27094
(27088, 1, 1, 1, 0, 0, 0, 0, 0, 45338), -- 27088
(27093, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- 27093
(27095, 15, 1, 5, 0, 0, 0, 0, 0, 45338), -- 27095
(27082, 1, 1, 1, 0, 0, 0, 0, 0, 45338), -- 27082
(27073, 5, 1, 1, 0, 0, 0, 0, 0, 45338), -- 27073
(27069, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- 27069
(27065, 1, 1, 1, 0, 0, 0, 0, 0, 45338), -- 27065
(27056, 1, 1, 0, 0, 0, 0, 0, 0, 45338), -- 27056
(27045, 0, 0, 0, 0, 0, 0, 0, 0, 45338), -- 27045
(27039, 6, 1, 0, 0, 0, 0, 0, 0, 45338), -- 27039
(26998, 1, 1, 1, 0, 0, 0, 0, 0, 45338), -- 26998
(26995, 5, 1, 1, 0, 0, 0, 0, 0, 45338), -- 26995
(26992, 6, 1, 1, 0, 0, 0, 0, 0, 45338), -- 26992
(26989, 1, 5, 1, 397, 0, 0, 0, 0, 45338), -- 26989
(26965, 1, 1, 66, 0, 0, 0, 0, 0, 45338); -- 26965

DELETE FROM `quest_request_items` WHERE `ID` IN (27093 /*27093*/, 26998 /*26998*/, 26965 /*26965*/, 26995 /*26995*/, 27088 /*27088*/, 27056 /*27056*/, 26992 /*26992*/, 26989 /*26989*/, 27082 /*27082*/, 27045 /*27045*/, 27073 /*27073*/, 27069 /*27069*/, 27099 /*27099*/, 27097 /*27097*/, 27096 /*27096*/, 27095 /*27095*/, 27094 /*27094*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `CompletionText`, `VerifiedBuild`) VALUES
(27093, 0, 0, 'Thankfully we\'re almost out of ale.', 45338), -- 27093
(26998, 0, 6, 'Have you exterminated the Vile Fin murlocs of the Dawning Isles?', 45338), -- 26998
(26965, 0, 5, 'Stand at attention, $nnub!', 45338), -- 26965
(26995, 1, 1, 'Remember, I can only use clean beast guts for the new strain of blight we\'re developing.', 45338), -- 26995
(27088, 0, 6, 'Have you dealt with the ettin?', 45338), -- 27088
(27056, 25, 0, 'Kneel before your queen, $n.', 45338), -- 27056
(26992, 6, 6, 'Have you collected the ferocious doomweed I requested?', 45338), -- 26992
(26989, 0, 6, 'What have you to report, $nnub?', 45338), -- 26989
(27082, 5, 5, 'We are Forsaken! This is how we do it, $c.', 45338), -- 27082
(27045, 0, 6, 'News from Yorick?', 45338), -- 27045
(27073, 0, 15, 'Give \'em hell, $r!', 45338), -- 27073
(27069, 0, 0, 'The pups might be the only orcs not drunk at this base.', 45338), -- 27069
(27099, 0, 6, 'What have you to report?', 45338), -- 27099
(27097, 0, 0, 'Victory!', 45338), -- 27097
(27096, 6, 0, 'And the orcs?', 45338), -- 27096
(27095, 0, 0, 'The matriarch must be found!', 45338), -- 27095
(27094, 0, 6, 'You killed the Skitterweb matriarch?', 45338); -- 27094

DELETE FROM `quest_offer_reward` WHERE `ID` IN (28568 /*28568*/, 27099 /*27099*/, 27097 /*27097*/, 27096 /*27096*/, 27088 /*27088*/, 27094 /*27094*/, 27093 /*27093*/, 27095 /*27095*/, 27082 /*27082*/, 27073 /*27073*/, 27069 /*27069*/, 28966 /*28966*/, 27065 /*27065*/, 27056 /*27056*/, 27045 /*27045*/, 27039 /*27039*/, 26998 /*26998*/, 26995 /*26995*/, 26992 /*26992*/, 26989 /*26989*/, 26965 /*26965*/, 27098 /*27098*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(28568, 5, 21, 0, 0, 0, 0, 0, 0, 'Most excellent! A new recruit has arrived. There is much to do... much to do I say.', 45338), -- 28568
(27099, 1, 1, 25, 6, 0, 0, 0, 0, 'It would seem that Crowley is more formidable than I anticipated. Still, he is a man - flesh and bone - full of secrets. Secrets that I know all about...$B$BYou have served me well, $n. I could use someone of your ability at the Sepulcher. I have a plan to deal with Crowley and his insurgents once and for all. Will you help?', 45338), -- 27099
(27097, 1, 0, 0, 0, 0, 0, 0, 0, 'I see everything, $n. Through Agatha all is known to me.', 45338), -- 27097
(27096, 0, 0, 0, 0, 0, 0, 0, 0, '<Sylvanas raises an eyebrow.>$B$BSo the orcs are in order?$B$B<Sylvanas reads the commendation letter.>$B$BRecovered their supplies? Killed a dozen worgen? Toppled an ettin? Freed their soldiers and destroyed the Skitterweb matriarch?$B$BI say this rarely, $n, but I am impressed. Perhaps your ability matches your aspirations. We shall see, for now you will be tested!', 45338), -- 27096
(27088, 11, 25, 0, 0, 0, 0, 0, 0, '<Apothecary Wormcrud laughs maniacally.>$B$BWas there ever any doubt? An ettin is no match for science!', 45338), -- 27088
(27094, 5, 1, 66, 0, 0, 0, 0, 0, 'You rescued our orcs and killed the Skitterweb matriarch? We owe you a great debt of gratitude. You\'ve saved us all from certain execution, $n. I\'m sure we can rouse these drunken idiots now.', 45338), -- 27094
(27093, 0, 0, 0, 0, 0, 0, 0, 0, 'Lok\'tar, $n! Once the ale wears off my orcs will be ready!', 45338), -- 27093
(27095, 0, 0, 0, 0, 0, 0, 0, 0, 'The root of this evil must be found and destroyed! The Skitterweb matriarch must be nearby. No doubt hiding in the nearby cave!', 45338), -- 27095
(27082, 5, 1, 0, 0, 0, 0, 0, 0, 'Excellent! Now to prepare the \"meal.\"', 45338), -- 27082
(27073, 25, 1, 11, 0, 0, 0, 0, 0, 'Looks as if you really gave those worgen a beating and, in the process, lifted the \"shame haze\" they cast over us. Perhaps the sea dogs will quit drinkin\' now.$B$BWho am I kidding?$B$BHah!', 45338), -- 27073
(27069, 0, 0, 0, 0, 0, 0, 0, 0, 'Within these crates are held STEEL THUNDER! With our weaponry returned we might have a chance to redeem ourselves.', 45338), -- 27069
(28966, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 45338), -- 28966
(27065, 0, 0, 0, 0, 0, 0, 0, 0, 'This fiasco may go down as one of the biggest embarrassments in the history of naval warfare. How did this happen? Drunk happened. That\'s how.', 45338), -- 27065
(27056, 1, 1, 274, 5, 0, 0, 0, 0, 'Crowley... A gnat. An insect, waiting to be crushed beneath my boot heel.$B$BSo he thinks to rouse the feral worgen of Silverpine? We shall show him and his allies the might of the Forsaken!$B$BBut first we must clean up the mess made by the Warchief\'s fleet. Without their aid we may lose this war.', 45338), -- 27056
(27045, 5, 1, 0, 0, 0, 0, 0, 0, 'Alas, poor Yorick! I knew her, $n. An assassin of infinite courage...$B$BNow, tell me what\'s going on? What did you and Yorick discover?', 45338), -- 27045
(27039, 0, 0, 0, 0, 0, 0, 0, 0, 'Belmont gets a little nervous and sends some newbie to look for me? Listen, I\'ve been staking out the old Ivar cottage from inside this outhouse for three days. Your presence threatens the whole damn operation!$B$BThere\'s no time to explain. We have to act now or this mission will be compromised.', 45338), -- 27039
(26998, 5, 1, 273, 0, 0, 0, 0, 0, 'Potent enough to exterminate a thousand murlocs! I think I\'ll put that on the label. You\'ve done well, $n, and great work around here gets rewarded.', 45338), -- 26998
(26995, 4, 1, 0, 0, 0, 0, 0, 0, 'Excellent! With these guts and the ferocious doomweed we\'ll be able to test out our new strain of blight. Now to select a suitable target...', 45338), -- 26995
(26992, 5, 1, 273, 0, 0, 0, 0, 0, 'Agony abounds, friend! The land itself threatens to devour us, and yet we persist. I wonder why that is? With this doomweed and the guts and gore that T\'Veen needs, we might have something suitable to send to the Forsaken front.', 45338), -- 26992
(26989, 1, 5, 21, 21, 0, 0, 0, 0, '$nnub has returned! And in one piece!$B$BDefender of Silverpine! Redeemer of the Horde! $nnub, your bravery must be rewarded!', 45338), -- 26989
(26965, 274, 1, 273, 0, 0, 0, 0, 0, 'Well that was unexpected. I am not one to doubt our Warchief, but...$B$BNevermind! We have work to do. I\'m sure the Dark Lady and the Warchief will get this all worked out.', 45338), -- 26965
(27098, 25, 6, 5, 0, 0, 0, 0, 0, 'Do you now understand the importance of our mission here? Crowley and his Alliance dogs must be stopped!', 45338); -- 27098
