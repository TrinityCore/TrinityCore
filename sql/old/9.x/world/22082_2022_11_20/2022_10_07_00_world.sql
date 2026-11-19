--
--
-- Silverpine Forest

--
-- Note: This is part [2/5]
 
-- Honor the Dead
DELETE FROM `quest_template_addon` WHERE `ID`=27180;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(27180, 0, 0, 0, 27098, 27181, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- Excising the Taint
UPDATE `quest_template_addon` SET `PrevQuestID` = 27180, `NextQuestID` = 27193 WHERE `ID` = 27181;

-- Seek and Destroy
UPDATE `quest_template_addon` SET `PrevQuestID` = 27181, `NextQuestID` = 27194 WHERE `ID` = 27193;

-- Cornered and Crushed!
UPDATE `quest_template_addon` SET `PrevQuestID` = 27193, `NextQuestID` = 27195 WHERE `ID` = 27194;

-- Nowhere to Run
DELETE FROM `quest_template_addon` WHERE `ID`=27195;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(27195, 0, 0, 0, 0, 27290, -27195, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, '');

-- Hair of the Dog
UPDATE `quest_template_addon` SET `PrevQuestID` = 27098, `NextQuestID` = 27290, `ExclusiveGroup` = -27195 WHERE `ID` = 27226;

-- Reinforcements from Fenris
DELETE FROM `quest_template_addon` WHERE `ID`=27231;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(27231, 0, 0, 0, 27098, 27232, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, '');

-- The Waters Run Red...
UPDATE `quest_template_addon` SET `PrevQuestID` = 27231, `NextQuestID` = 27290, `ExclusiveGroup` = -27195 WHERE `ID` = 27232;
 
-- To Forsaken Forward Command
UPDATE `quest_template_addon` SET `PrevQuestID` = 27342 WHERE `ID` = 27290;

--
-- Note: This is part [3/5]

-- Losing Ground
UPDATE `quest_template_addon` SET `PrevQuestID` = 27290, `NextQuestID` = 27349, `ExclusiveGroup` = -27333 WHERE `ID` = 27333;
-- The F.C.D.
UPDATE `quest_template_addon` SET `PrevQuestID` = 27290, `NextQuestID` = 27349, `ExclusiveGroup` = -27333 WHERE `ID` = 27345;
-- In Time, All Will Be Revealed
UPDATE `quest_template_addon` SET `PrevQuestID` = 27290, `NextQuestID` = 27349, `ExclusiveGroup` = -27333 WHERE `ID` = 27342;

-- Break in Communications: Dreadwatch Outpost (last three must be rewarded to obtain this one)
DELETE FROM `quest_template_addon` WHERE `ID`=27349;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(27349, 0, 0, 0, 0, 27350, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, '');

-- Break in Communications: Rutsak's Guard
UPDATE `quest_template_addon` SET `PrevQuestID` = 27349, `NextQuestID` = 27360 WHERE `ID` = 27350;

-- Vengeance for Our Soldiers
UPDATE `quest_template_addon` SET `PrevQuestID` = 27350 WHERE `ID` = 27360;

-- On Whose Orders?
UPDATE `quest_template_addon` SET `PrevQuestID` = 27350, `NextQuestID` = 27401 WHERE `ID` = 27364;

-- What Tomorrow Brings
DELETE FROM `quest_template_addon` WHERE `ID`=27423;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(27423, 0, 0, 0, 27364, 27405, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- Fall Back!
UPDATE `quest_template_addon` SET `PrevQuestID` = 27401, `NextQuestID` = 27406 WHERE `ID` = 27405;

-- A Man Named Godfrey
UPDATE `quest_template_addon` SET `PrevQuestID` = 27405, `NextQuestID` = 27438, `ExclusiveGroup` = -27406 WHERE `ID` = 27406;
-- Resistance is Futile
UPDATE `quest_template_addon` SET `PrevQuestID` = 27405, `NextQuestID` = 27438, `ExclusiveGroup` = -27406 WHERE `ID` = 27423;

-- The Great Escape (last two must be rewarded to obtain this one)
UPDATE `quest_template_addon` SET `PrevQuestID` = 0, `NextQuestID` = 27472 WHERE `ID` = 27438;

DELETE FROM `quest_details` WHERE `ID` IN (27342, 27322, 27345, 27333, 27349, 27350, 27364, 27401, 27360, 27405, 27406, 27438);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(27342, 1, 1, 1, 273, 0, 0, 0, 0, 15595),
(27322, 0, 0, 0, 0, 0, 0, 0, 0, 15595),
(27345, 1, 1, 1, 0, 0, 0, 0, 0, 15595),
(27333, 1, 1, 5, 0, 0, 0, 0, 0, 15595),
(27349, 1, 1, 1, 0, 0, 0, 0, 0, 15595),
(27350, 0, 0, 0, 0, 0, 0, 0, 0, 15595),
(27364, 0, 0, 0, 0, 0, 0, 0, 0, 15595),
(27401, 0, 0, 0, 0, 0, 0, 0, 0, 15595),
(27360, 0, 0, 0, 0, 0, 0, 0, 0, 15595),
(27405, 0, 0, 0, 0, 0, 0, 0, 0, 15595),
(27406, 1, 1, 1, 273, 0, 0, 0, 0, 15595),
(27438, 1, 1, 0, 0, 0, 0, 0, 0, 15595);

DELETE FROM `quest_request_items` WHERE `ID` IN (27342, 27364, 27345, 27322);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `CompletionText`, `VerifiedBuild`) VALUES
(27342, 6, 0, 'Did you gather the wolfsbane?', 15595),
(27364, 0, 0, 'Status?', 15595),
(27345, 0, 0, 'Recover the F.C.D.', 15595),
(27322, 6, 0, 'Korok is dead?', 15595);

DELETE FROM `quest_offer_reward` WHERE `ID` IN (27342, 27322, 27345, 27333, 27349, 27350, 27364, 27401, 27360, 27405, 27423, 27406, 27438);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(27342, 1, 1, 1, 0, 0, 0, 0, 0, '<Belmont takes the wolfsbane from you.>$B$BGood. Now just do as Forward Commander Onslaught commands. Try your best to fit in with the rest of the soldiers. We don\'t want the Gilneas Liberation Front to get suspicious.$B$BOh, you didn\'t know they were watching us? Right now there are five different worgen spies looking down on our position. Just be calm and follow orders. I\'ll let you know when we are ready to proceed.', 15595),
(27322, 1, 273, 0, 0, 0, 0, 0, 0, 'That towering behemoth has killed hundreds of Forsaken soldiers. You\'ve done a great thing, $n.', 15595),
(27345, 1, 1, 0, 0, 0, 0, 0, 0, 'With this device I will be able to communicate with you in the field. Now to check the rest of our frontline outposts.', 15595),
(27333, 0, 0, 0, 0, 0, 0, 0, 0, 'If I could still breathe I\'d let out a sigh of relief.$B$BDon\'t get too comfortable, though, $n, your mission here has just begun.', 15595),
(27349, 0, 0, 0, 0, 0, 0, 0, 0, '<The F.C.D. crackles with static.>$B$BDreadwatch is lost? This is bad, $n. Real bad.$B$BIf Dreadwatch is compromised it means we\'ve lost Gilneas City.', 15595),
(27350, 0, 0, 0, 0, 0, 0, 0, 0, 'Th... Af... After we lost Gilneas City, the port fell.$B$BHU... HUM... HUMANS ARE HERE! Reinforcements from Stormwind! They slaughtered my men. Left me alive to witness their strength. To tell high command... To tell them that the 7th Legion are here...', 15595),
(27364, 0, 0, 0, 0, 0, 0, 0, 0, '<The F.C.D. crackles with electricity.>$B$BAn Alliance armada is en route? How could this have happened?$B$B<Forward Commander Onslaught cuts out for a moment. You hear worgen howling in the background.>$B$BYou\'ve got to hurry, $n. We\'re being overrun up here at Forward Command.', 15595),
(27401, 0, 0, 0, 0, 0, 0, 0, 0, '<The F.C.D. crackles with electricity.>$B$BTORPEDOED! We had everything at the water line covered, but nothing below the line. They must have snuck in beneath our defenses and then blown our warships to smithereens.$B$BAnd now the rest of the Alliance fleet is nearly here...', 15595),
(27360, 0, 0, 0, 0, 0, 0, 0, 0, 'Though we were shamed in battle, the enemy was not victorious. I will not soon forget this, $n.$B$BIf I make it back to Silverpine I will likely retire from the service. War is not in my blood.', 15595),
(27405, 1, 1, 0, 0, 0, 0, 0, 0, 'Forward Commander Onslaught fought until the bitter end, $n. It took a pack of bloodthirsty worgen to finally bring him down. We must not let his death, or the death of all of our soldiers in Gilneas, go in vain. Our mission MUST succeed.$B$BNow I will reveal to you why we are here.', 15595),
(27423, 274, 1, 0, 0, 0, 0, 0, 0, 'No time to bask in the battle glory, $n. We have a job to do. I have no doubt more of those beasts are on the way.', 15595),
(27406, 1, 1, 0, 0, 0, 0, 0, 0, 'Here we are, $n. He is a little rotted, but no worse for the wear. We must hurry before the Alliance finds us!', 15595),
(27438, 1, 1, 1, 0, 0, 0, 0, 0, 'I had no doubt that you would succeed, $n. I hope you can understand why I kept the true purpose of your mission a secret. Should Crowley and Bloodfang have found out about our plan, they would have surely gotten to Godfrey first and disposed of the body.$B$BStand by, $n. The time of their rebirth is at hand.', 15595);

--
-- Note: This is part [4/5]

-- Rise, Godfrey
DELETE FROM `quest_template_addon` WHERE `ID`=27472;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(27472, 0, 0, 0, 27438, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- Breaking the Barrier
DELETE FROM `quest_template_addon` WHERE `ID`=27474;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(27474, 0, 0, 0, 27472, 27476, -27474, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
-- Unyielding Servitors
DELETE FROM `quest_template_addon` WHERE `ID`=27475;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(27475, 0, 0, 0, 27472, 27476, -27474, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- Dalar Dawnweaver (last two must be rewarded to obtain this one)
UPDATE `quest_template_addon` SET `PrevQuestID` = 27474, `NextQuestID` = 27478 WHERE `ID` = 27476;

-- Relios the Relic Keeper
UPDATE `quest_template_addon` SET `PrevQuestID` = 27476, `NextQuestID` = 27484, `ExclusiveGroup` = -27478 WHERE `ID` = 27478;
-- Practical Vengeance
DELETE FROM `quest_template_addon` WHERE `ID`=27483;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(27483, 0, 0, 0, 27476, 27484, -27478, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- Only One May Enter (last two must be rewarded to obtain this one)
UPDATE `quest_template_addon` SET `PrevQuestID` = 0, `NextQuestID` = 27512 WHERE `ID` = 27484;

-- Transdimensional Warfare: Chapter I
UPDATE `quest_template_addon` SET `PrevQuestID` = 27484, `NextQuestID` = 27513 WHERE `ID` = 27512;

-- Transdimensional Warfare: Chapter II
UPDATE `quest_template_addon` SET `PrevQuestID` = 27512, `NextQuestID` = 27518 WHERE `ID` = 27513;

-- Transdimensional Warfare: Chapter III
UPDATE `quest_template_addon` SET `PrevQuestID` = 27513, `NextQuestID` = 27542 WHERE `ID` = 27518;

DELETE FROM `quest_details` WHERE `ID` IN (27472, 27474, 27475, 27476, 27483, 27478, 27480, 27484, 27547, 28089, 27518, 27513, 27510, 27512);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(27472, 1, 1, 1, 0, 0, 0, 0, 0, 0),
(27474, 1, 1, 1, 0, 0, 0, 0, 0, 0),
(27475, 457, 457, 457, 0, 0, 0, 0, 0, 0),
(27476, 1, 1, 0, 0, 0, 0, 0, 0, 0),
(27483, 1, 1, 1, 0, 0, 0, 0, 0, 0),
(27478, 273, 1, 1, 0, 0, 0, 0, 0, 0),
(27480, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(27484, 11, 1, 273, 1, 0, 0, 0, 0, 0),
(27547, 1, 1, 0, 0, 0, 0, 0, 0, 0),
(28089, 1, 1, 1, 0, 0, 0, 0, 0, 0),
(27518, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(27513, 1, 1, 0, 0, 0, 0, 0, 0, 0),
(27510, 1, 1, 1, 0, 0, 0, 0, 0, 0),
(27512, 1, 1, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `quest_request_items` WHERE `ID` IN (27472, 27474, 27475, 27476, 27478, 27480, 27484, 27512);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `CompletionText`, `VerifiedBuild`) VALUES
(27472, 5, 0, 'Today marks a new beginning for the Forsaken and the end of the Alliance in Lordaeron!', 15595),
(27474, 6, 0, 'Have you found anything yet?', 15595),
(27475, 457, 0, 'Have you recovered the servitor cores?', 15595),
(27476, 6, 0, 'Yes? What is it?', 15595),
(27478, 6, 0, 'Did you recover a Dalaran Archmage\'s Signet Ring?', 15595),
(27480, 6, 0, 'What\'s that you\'ve got there, $n?', 15595),
(27484, 6, 0, 'What have you learned?', 15595),
(27512, 0, 0, '<The portal hums.>', 15595);

DELETE FROM `quest_offer_reward` WHERE `ID` IN (27474, 27475, 27476, 27483, 27478, 27480, 27518, 27510, 27513, 27512, 27484);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(27474, 1, 1, 0, 0, 0, 0, 0, 0, 'Clever mages. The codex is sealed by a magical ward.$B$BPity that they weren\'t clever enough to realize that former archmages of Dalaran are now Forsaken.', 15595),
(27475, 457, 457, 0, 0, 0, 0, 0, 0, 'Well done, $n. The praise the Banshee Queen lavishes upon you is apparently not unfounded.', 15595),
(27476, 0, 0, 0, 0, 0, 0, 0, 0, 'The Dark Lady requires my expertise? Well of course! Give it here, $g boy:girl;.', 15595),
(27483, 1, 6, 1, 0, 0, 0, 0, 0, 'I thought for sure that with the death of a dozen of my most hated enemies I would feel a great burden lifted from my shoulders. Sadly, I do not feel a thing. Perhaps I am a psychopath.', 15595),
(27478, 21, 1, 1, 0, 0, 0, 0, 0, 'Perfect. I hope this wasn\'t too much trouble to come by, $n. Relios was a pupil of mine back when I was a mortal man thereby making him a competent and formidable adversary. I suppose I could have warned you ahead of time.$B$BNow, let us see the ring.$B$B<Dalar trails the ring across the spine of the codex.>$B$BThere we are...', 15595),
(27480, 1, 1, 0, 0, 0, 0, 0, 0, 'Smart $g boy:girl;! I can most definitely use these arcane remnants in my studies. Indeed, Dalaran was built upon a massive ley line. It\'s no wonder, then, that such things exist at the crater.', 15595),
(27518, 5, 1, 1, 0, 0, 0, 0, 0, 'Had I not witnessed what you did with my own eyes I would not have believed it, $n. Now, with the Ambermill magi on our side, there is but one thing left to do before we retake Gilneas and send those Alliance dogs running for Stormwind.', 40725),
(27510, 1, 1, 0, 0, 0, 0, 0, 0, 'I only hope that we don\'t end up getting beat down by inconspicuous birds, cats and trees next... or seals. Could you imagine it?', 40725),
(27513, 0, 0, 0, 0, 0, 0, 0, 0, '<The Banshee Queen\'s voice invades your thoughts.>$B$BExcellent work, $n. Now to eject them into our waiting hands!', 40725),
(27512, 0, 0, 0, 0, 0, 0, 0, 0, '<The Banshee Queen\'s voice invades your thoughts.>$B$BYes, this is it. Now run the ring along the runes of the portal and you should become attuned for transdimensional travel.', 40725),
(27484, 6, 25, 0, 0, 0, 0, 0, 0, 'Only one may enter? I know just the person for this mission.$B$B<Sylvanas nods at you.>$B$BI will prepare our forces and have them at the ready.', 40725);

--
-- Note: This is part [5/5]

-- Taking the Battlefront
DELETE FROM `quest_template_addon` WHERE `ID`=27542;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(27542, 0, 0, 0, 27518, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- Pyrewood's Fall
UPDATE `quest_template_addon` SET `PrevQuestID` = 27542, `NextQuestID` = 27580, `ExclusiveGroup` = -27550 WHERE `ID` = 27550;
-- Of No Consecuence
DELETE FROM `quest_template_addon` WHERE `ID`=27547;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(27547, 0, 0, 0, 27542, 27580, -27550, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
-- Lessons in Fear
DELETE FROM `quest_template_addon` WHERE `ID`=27548;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(27548, 0, 0, 0, 27542, 27580, -27550, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- Sowing Discord (last three must be rewarded to obtain these two)
UPDATE `quest_template_addon` SET `PrevQuestID` = 27550, `NextQuestID` = 27594, `ExclusiveGroup` = -27580 WHERE `ID` = 27580;
-- 7th Legion Battle Plans
UPDATE `quest_template_addon` SET `PrevQuestID` = 27550, `NextQuestID` = 27594, `ExclusiveGroup` = -27580 WHERE `ID` = 27577;

-- On Her Majesty's Secret Service (last two must be rewarded to obtain these two)
UPDATE `quest_template_addon` SET `PrevQuestID` = 27580, `NextQuestID` = 27601 WHERE `ID` = 27594;

-- Cities in Dust
DELETE FROM `quest_template_addon` WHERE `ID`=27601;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(27601, 0, 0, 0, 27594, 27746, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- Empire of Dirt
UPDATE `quest_template_addon` SET `PrevQuestID` = 27601 WHERE `ID` = 27746;

DELETE FROM `quest_details` WHERE `ID` IN (27594, 27575, 27574, 27580, 27577, 27548, 27547, 27550, 27601, 27746, 28089);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(27550, 1, 1, 1, 0, 0, 0, 0, 0, 40944),
(27547, 1, 1, 0, 0, 0, 0, 0, 0, 40944),
(27548, 1, 11, 1, 0, 0, 0, 0, 0, 40944),
(27580, 1, 1, 0, 0, 0, 0, 0, 0, 40944),
(27577, 1, 1, 1, 0, 0, 0, 0, 0, 40944),
(27574, 0, 0, 0, 0, 0, 0, 0, 0, 40944),
(27575, 1, 1, 5, 0, 0, 0, 0, 0, 40944),
(27594, 1, 1, 0, 0, 0, 0, 0, 0, 40944),
(27601, 0, 1, 0, 0, 0, 0, 0, 0, 40944),
(27746, 1, 0, 66, 0, 0, 0, 0, 0, 40944),
(28089, 1, 0, 1, 0, 0, 0, 0, 0, 40944);

DELETE FROM `quest_request_items` WHERE `ID` IN (27577, 27575, 27574);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `CompletionText`, `VerifiedBuild`) VALUES
(27577, 5, 5, 'Search every filthy dwarven corpse.', 40944),
(27575, 273, 273, 'At the very least we\'ll have some crocolisk hides to make fancy shoes out of.', 40944),
(27574, 5, 5, 'I never forget a face!', 40944);

DELETE FROM `quest_offer_reward` WHERE `ID` IN (27542, 27601, 27746, 28089, 27594, 27577, 27580, 27575, 27574, 27548, 27547, 27550);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(27542, 1, 0, 0, 0, 0, 0, 0, 0, 'The hour of victory approaches, $n. Godfrey has devised a plan to decimate our enemies. I am sending you into the field with him and his men to bring the rebel insurgents to their knees and seal the fate of the Alliance filth encroaching upon our lands.$B$BOur final march begins when you are ready.', 40944),
(27550, 1, 1, 0, 0, 0, 0, 0, 0, 'The part of me that was Gilnean died at Tempest\'s Reach. Only vengeance remains, $n. To that end, we have work to do. Spare me your pointless queries.', 40944),
(27548, 1, 1, 0, 0, 0, 0, 0, 0, 'I suspect we\'ll see fewer humans at the Battlefront. The risk for these cowards is too great.', 40944),
(27547, 1, 25, 0, 0, 0, 0, 0, 0, 'What happened here today is between us. Say a word to anyone and you will find yourself in a corpse pit next to these poor fools.', 40944),
(27577, 1, 1, 1, 0, 0, 0, 0, 0, '<Walden flips through the battle plan.>$B$BIt looks like the reinforcements from the ships in Gilneas are marching soon. Crowley and Bloodfang have set up an encampment to the southeast for the Gilneas Liberation front.', 40944),
(27580, 1, 1, 0, 0, 0, 0, 0, 0, 'The rest of the Alliance fleet will arrive shortly, only to find their base camp decimated. Now for the second and most important part of our battle plan.', 40944),
(27574, 1, 1, 1, 0, 0, 0, 0, 0, 'I know that face, $n. This head belongs to a former Gilnean known as Sean Dempsey. He was imprisoned with Crowley before the great outbreak.$B$BI wonder if it would be possible to put him back together. The rest of him must be in the belly of these crocolisks.', 40944), -- 27574
(27575, 1, 5, 0, 0, 0, 4000, 0, 0, 'Now let\'s see if I can do this.$B$B<Godfrey starts mumbling under his breath.>$B$B...leg bone connects to the thigh bone...$B$B...arm bone to torso...$B$B...sprinkle on a little Forsaken necromancy...$B$BTA-DA!', 40944),
(27594, 5, 1, 1, 0, 0, 0, 0, 0, 'You have done it! Finally, everything is in place. Should Crowley not accept our terms, his daughter will be turned.', 40944),
(27601, 0, 0, 0, 0, 0, 0, 0, 0, '<Lady Sylvanas Windrunner grimaces in pain.>$B$BThis... is not over. Godfrey and his traitorous allies will pay for what they have done as will the remaining Alliance forces occupying Lordaeron.$B$BOur work has only just begun.', 40944),
(27746, 66, 1, 0, 0, 0, 0, 0, 0, 'News of your conquest in Silverpine emboldens us, $n. We are prepared to fight at your command and beat back the last remaining vestiges of humanity in Hillsbrad.', 40944),
(28089, 66, 1, 5, 0, 0, 0, 0, 0, 'I was wondering when reinforcements would show up. Suit up, <name>. It\'s time to dispense some justice!', 40944);
