--
UPDATE `quest_template_addon` SET `PrevQuestID`=13225 WHERE `ID`=13300; -- Slaves to Saronite requires The Skybreaker
UPDATE `quest_template_addon` SET `PrevQuestID`=13225 WHERE `ID`=13336; -- Blood of the Chosen requires The Skybreaker
UPDATE `quest_template_addon` SET `PrevQuestID`=13287 WHERE `ID`=13288; -- That's Abominable (non-daily) requires Poke and Prod
UPDATE `quest_template_addon` SET `PrevQuestID`=13288 WHERE `ID`=13289; -- That's Abominable (daily) requires That's Abominable (non-daily)
UPDATE `quest_template_addon` SET `PrevQuestID`=13231 WHERE `ID`=13233; -- No Mercy! requires The Broken Front
UPDATE `quest_template_addon` SET `PrevQuestID`=13332 WHERE `ID`=13314; -- Get the Message requires Raise the Barricades
UPDATE `quest_template_addon` SET `PrevQuestID`=13314 WHERE `ID`=13333; -- Capture More Dispatches requires Get the Message
UPDATE `quest_template_addon` SET `PrevQuestID`=13295 WHERE `ID`=13297; -- Neutralizing the Plague requires Basic Chemistry
UPDATE `quest_template_addon` SET `PrevQuestID`=13315 WHERE `ID`=13320; -- Cannot Reproduce requires Sneak Preview
UPDATE `quest_template_addon` SET `PrevQuestID`=13318 WHERE `ID`=13323; -- Drag and Drop (daily) requires Drag and Drop (non-daily)
UPDATE `quest_template_addon` SET `PrevQuestID`=13318 WHERE `ID`=13342; -- Not a Bug (non-daily) requires Drag and Drop (non-daily)
UPDATE `quest_template_addon` SET `PrevQuestID`=13342 WHERE `ID`=13344; -- Not a Bug (daily) requires Not a Bug (non-daily)
UPDATE `quest_template_addon` SET `PrevQuestID`=13345 WHERE `ID`=13332; -- Raise the Barricades requires Need More Info
UPDATE `quest_template_addon` SET `PrevQuestID`=13346 WHERE `ID`=13350; -- No Rest For The Wicked (daily) requires No Rest For The Wicked (non-daily)
UPDATE `quest_template_addon` SET `PrevQuestID`=13334 WHERE `ID`=13335; -- Before the Gate of Horror requires Bloodspattered Banners
UPDATE `quest_template_addon` SET `PrevQuestID`=13332 WHERE `ID`=13337; -- The Ironwall Rampart requires Raise the Barricades
UPDATE `quest_template_addon` SET `PrevQuestID`=13321 WHERE `ID`=13322; -- Retest Now (daily) requires Retest Now (non-daily)
UPDATE `quest_template_addon` SET `PrevQuestID`=13341 WHERE `ID` IN (13284, 13309); -- Assault by Air and Assault by Ground require Joining the Assault

DELETE FROM `quest_template_addon` WHERE `ID` IN (13294, 13231, 13296, 13286, 13290, 13298, 13315, 13319, 13318, 13334, 13339, 13338, 13345, 13341);
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`) VALUES
(13294, 13287), -- Against the Giants requires Poke and Prod
(13231, 13225), -- The Broken Front requires The Skybreaker
(13296, 13225), -- Get to Ymirheim! requires The Skybreaker
(13286, 13231), -- ...All the Help We Can Get. requires The Broken Front
(13290, 13231), -- Your Attention, Please requires The Broken Front
(13298, 13294), -- Coprous the Defiled requires Against the Giants
(13315, 13288), -- Sneak Preview requires That's Abominable! (non-daily)
(13319, 13315), -- Chain of Command requires Sneak Preview
(13318, 13315), -- Drag and Drop (non-daily) requires Sneak Preview
(13334, 13332), -- Bloodspattered Banners requires Raise the Barricades
(13339, 13335), -- Shatter the Shards requires Before the Gate of Horror
(13338, 13335), -- The Guardians of Corp'rethar requires Before the Gate of Horror
(13345, 13318), -- Need More Info requires Drag and Drop (non-daily)
(13341, 13225); -- Joining the Assault requires The Skybreaker
