-- Quest 25039: Have You Seen Anything Weird Out There?
UPDATE `quest_template` SET `RewardNextQuest`=24993 WHERE `ID`=25039;

-- add ExclusiveGroup 24992 - only one of the quests must be available
DELETE FROM `quest_template_addon` WHERE `ID` IN (24992,25039);
INSERT INTO `quest_template_addon` (`ID`,`MaxLevel`,`AllowableClasses`,`SourceSpellID`,`PrevQuestID`,`NextQuestID`,`ExclusiveGroup`,`RewardMailTemplateID`,`RewardMailDelay`,`RequiredSkillID`,`RequiredSkillPoints`,`RequiredMinRepFaction`,`RequiredMaxRepFaction`,`RequiredMinRepValue`,`RequiredMaxRepValue`,`ProvidedItemCount`,`SpecialFlags`,`ScriptName`) VALUES
(24992, 0, 0, 0, 0, 24993, 24992, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(25039, 0, 0, 0, 0, 24993, 24992, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- add missing quest_offer_reward entries for 24992/24993/25039
DELETE FROM `quest_offer_reward` WHERE `ID` IN (24992,25039,24993);
INSERT INTO `quest_offer_reward` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`RewardText`,`VerifiedBuild`) VALUES
(24992, 0, 0, 0, 0, 0, 0, 0, 0, 'Hmm... yes, that makes sense.  Since the worgen have come streaming out of Gilneas, I knew it would only be a matter of time before they arrived here in Tirisfal.', 0),
(25039, 0, 0, 0, 0, 0, 0, 0, 0, 'Hmm... yes, that makes sense.  Since the worgen have come streaming out of Gilneas, I knew it would only be a matter of time before they arrived here in Tirisfal.', 0),
(24993, 0, 0, 0, 0, 0, 0, 0, 0, "To think, they've been right under our noses!  I'll put my deathguards on alert... this will NOT happen again.", 0);
