--
SET @TEXTID := 11074;
DELETE FROM `npc_text` WHERE `ID`=@TEXTID;
INSERT INTO `npc_text` (`ID`, `text0_1`, `BroadcastTextID0`) VALUES
(@TEXTID, "Forgetting your skill in Potion Mastery is not something to do lightly.$B$BAre you absolutely sure?", 21870);

SET @MENUID := 21402; -- Need 3
DELETE FROM `gossip_menu` WHERE `MenuID` BETWEEN @MENUID AND @MENUID+2;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(@MENUID, 11076, 0), -- Transmutation
(@MENUID+1, 11075, 0), -- Elixir
(@MENUID+2, @TEXTID, 0); -- Potion

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (8542, @MENUID, 8540, @MENUID+1, 7571, @MENUID+2);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(8542, 0, 0, "I wish to unlearn Transmutation Mastery.", 21876, 1, 1, @MENUID, 0, 0, 0, "", 0, 0),
(8542, 1, 0, "I've trained as an alchemist once again.  I wish to specialize in transmutations.", 20292, 1, 1, 0, 0, 0, 0, "", 0, 0),
(@MENUID, 0, 0, "I've made up my mind.  Make me forget my alchemy mastery!", 21873, 1, 1, 0, 0, 0, 1500000, "Forgetting your knowledge is an expensive endeavor.  Are you willing to pay the cost?", 21569, 0),
(8540, 0, 0, "I wish to unlearn Elixir Mastery.", 21875, 1, 1, @MENUID+1, 0, 0, 0, "", 0, 0),
(8540, 1, 0, "I've trained as an alchemist once again.  I wish to specialize in elixirs.", 20289, 1, 1, 0, 0, 0, 0, "", 0, 0),
(@MENUID+1, 0, 0, "I've made up my mind.  Make me forget my alchemy mastery!", 21873, 1, 1, 0, 0, 0, 1500000, "Forgetting your knowledge is an expensive endeavor.  Are you willing to pay the cost?", 21569, 0),
(7571, 0, 0, "I wish to unlearn Potion Mastery.", 21874, 1, 1, @MENUID+2, 0, 0, 0, "", 0, 0),
(7571, 1, 0, "I've trained as an alchemist once again.  I wish to specialize in potions.", 20287, 1, 1, 0, 0, 0, 0, "", 0, 0),
(@MENUID+2, 0, 0, "I've made up my mind.  Make me forget my alchemy mastery!", 21873, 1, 1, 0, 0, 0, 1500000, "Forgetting your knowledge is an expensive endeavor.  Are you willing to pay the cost?", 21569, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (8542, 8540, 7571);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
-- Unlearn Transmutation
(15, 8542, 0, 0, 0, 27, 0, 68, 3, 0, 0, 0, 0, "", "Gossip option requires level 68 or higher"),
(15, 8542, 0, 0, 0, 7, 0, 171, 350, 0, 0, 0, 0, "", "Gossip option requires an Alchemy skill of 350 or higher"),
(15, 8542, 0, 0, 0, 25, 0, 28672, 0, 0, 0, 0, 0, "", "Gossip option requires player to have the spell 'Transmutation Master' learned"),
-- Learn Transmutation
(15, 8542, 1, 0, 0, 27, 0, 68, 3, 0, 0, 0, 0, "", "Gossip option requires level 68 or higher"),
(15, 8542, 1, 0, 0, 7, 0, 171, 350, 0, 0, 0, 0, "", "Gossip option requires an Alchemy skill of 350 or higher"),
(15, 8542, 1, 0, 0, 25, 0, 28672, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Transmutation Master' NOT learned"),
(15, 8542, 1, 0, 0, 25, 0, 28677, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Elixir Master' NOT learned"),
(15, 8542, 1, 0, 0, 25, 0, 28675, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Potion Master' NOT learned"),
(15, 8542, 1, 0, 0, 8, 0, 10899, 0, 0, 0, 0, 0, "", "Gossip option requires player to have the quest 'Master of Transmutation' rewarded OR"),
(15, 8542, 1, 0, 1, 27, 0, 68, 3, 0, 0, 0, 0, "", "Gossip option requires level 68 or higher"),
(15, 8542, 1, 0, 1, 7, 0, 171, 350, 0, 0, 0, 0, "", "Gossip option requires an Alchemy skill of 350 or higher"),
(15, 8542, 1, 0, 1, 25, 0, 28672, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Transmutation Master' NOT learned"),
(15, 8542, 1, 0, 1, 25, 0, 28677, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Elixir Master' NOT learned"),
(15, 8542, 1, 0, 1, 25, 0, 28675, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Potion Master' NOT learned"),
(15, 8542, 1, 0, 1, 8, 0, 10902, 0, 0, 0, 0, 0, "", "Gossip option requires player to have the quest 'Master of Elixirs' rewarded OR"),
(15, 8542, 1, 0, 2, 27, 0, 68, 3, 0, 0, 0, 0, "", "Gossip option requires level 68 or higher"),
(15, 8542, 1, 0, 2, 7, 0, 171, 350, 0, 0, 0, 0, "", "Gossip option requires an Alchemy skill of 350 or higher"),
(15, 8542, 1, 0, 2, 25, 0, 28672, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Transmutation Master' NOT learned"),
(15, 8542, 1, 0, 2, 25, 0, 28677, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Elixir Master' NOT learned"),
(15, 8542, 1, 0, 2, 25, 0, 28675, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Potion Master' NOT learned"),
(15, 8542, 1, 0, 2, 8, 0, 10897, 0, 0, 0, 0, 0, "", "Gossip option requires player to have the quest 'Master of Potions' rewarded"),
-- Unlearn Elixir
(15, 8540, 0, 0, 0, 27, 0, 68, 3, 0, 0, 0, 0, "", "Gossip option requires level 68 or higher"),
(15, 8540, 0, 0, 0, 7, 0, 171, 350, 0, 0, 0, 0, "", "Gossip option requires an Alchemy skill of 350 or higher"),
(15, 8540, 0, 0, 0, 25, 0, 28677, 0, 0, 0, 0, 0, "", "Gossip option requires player to have the spell 'Elixir Master' learned"),
-- Learn Elixir
(15, 8540, 1, 0, 0, 27, 0, 68, 3, 0, 0, 0, 0, "", "Gossip option requires level 68 or higher"),
(15, 8540, 1, 0, 0, 7, 0, 171, 350, 0, 0, 0, 0, "", "Gossip option requires an Alchemy skill of 350 or higher"),
(15, 8540, 1, 0, 0, 25, 0, 28672, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Transmutation Master' NOT learned"),
(15, 8540, 1, 0, 0, 25, 0, 28677, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Elixir Master' NOT learned"),
(15, 8540, 1, 0, 0, 25, 0, 28675, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Potion Master' NOT learned"),
(15, 8540, 1, 0, 0, 8, 0, 10899, 0, 0, 0, 0, 0, "", "Gossip option requires player to have the quest 'Master of Transmutation' rewarded OR"),
(15, 8540, 1, 0, 1, 27, 0, 68, 3, 0, 0, 0, 0, "", "Gossip option requires level 68 or higher"),
(15, 8540, 1, 0, 1, 7, 0, 171, 350, 0, 0, 0, 0, "", "Gossip option requires an Alchemy skill of 350 or higher"),
(15, 8540, 1, 0, 1, 25, 0, 28672, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Transmutation Master' NOT learned"),
(15, 8540, 1, 0, 1, 25, 0, 28677, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Elixir Master' NOT learned"),
(15, 8540, 1, 0, 1, 25, 0, 28675, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Potion Master' NOT learned"),
(15, 8540, 1, 0, 1, 8, 0, 10902, 0, 0, 0, 0, 0, "", "Gossip option requires player to have the quest 'Master of Elixirs' rewarded OR"),
(15, 8540, 1, 0, 2, 27, 0, 68, 3, 0, 0, 0, 0, "", "Gossip option requires level 68 or higher"),
(15, 8540, 1, 0, 2, 7, 0, 171, 350, 0, 0, 0, 0, "", "Gossip option requires an Alchemy skill of 350 or higher"),
(15, 8540, 1, 0, 2, 25, 0, 28672, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Transmutation Master' NOT learned"),
(15, 8540, 1, 0, 2, 25, 0, 28677, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Elixir Master' NOT learned"),
(15, 8540, 1, 0, 2, 25, 0, 28675, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Potion Master' NOT learned"),
(15, 8540, 1, 0, 2, 8, 0, 10897, 0, 0, 0, 0, 0, "", "Gossip option requires player to have the quest 'Master of Potions' rewarded"),
-- Unlearn Potion
(15, 7571, 0, 0, 0, 27, 0, 68, 3, 0, 0, 0, 0, "", "Gossip option requires level 68 or higher"),
(15, 7571, 0, 0, 0, 7, 0, 171, 350, 0, 0, 0, 0, "", "Gossip option requires an Alchemy skill of 350 or higher"),
(15, 7571, 0, 0, 0, 25, 0, 28675, 0, 0, 0, 0, 0, "", "Gossip option requires player to have the spell 'Potion Master' learned"),
-- Learn Potion
(15, 7571, 1, 0, 0, 27, 0, 68, 3, 0, 0, 0, 0, "", "Gossip option requires level 68 or higher"),
(15, 7571, 1, 0, 0, 7, 0, 171, 350, 0, 0, 0, 0, "", "Gossip option requires an Alchemy skill of 350 or higher"),
(15, 7571, 1, 0, 0, 25, 0, 28672, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Transmutation Master' NOT learned"),
(15, 7571, 1, 0, 0, 25, 0, 28677, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Elixir Master' NOT learned"),
(15, 7571, 1, 0, 0, 25, 0, 28675, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Potion Master' NOT learned"),
(15, 7571, 1, 0, 0, 8, 0, 10899, 0, 0, 0, 0, 0, "", "Gossip option requires player to have the quest 'Master of Transmutation' rewarded OR"),
(15, 7571, 1, 0, 1, 27, 0, 68, 3, 0, 0, 0, 0, "", "Gossip option requires level 68 or higher"),
(15, 7571, 1, 0, 1, 7, 0, 171, 350, 0, 0, 0, 0, "", "Gossip option requires an Alchemy skill of 350 or higher"),
(15, 7571, 1, 0, 1, 25, 0, 28672, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Transmutation Master' NOT learned"),
(15, 7571, 1, 0, 1, 25, 0, 28677, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Elixir Master' NOT learned"),
(15, 7571, 1, 0, 1, 25, 0, 28675, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Potion Master' NOT learned"),
(15, 7571, 1, 0, 1, 8, 0, 10902, 0, 0, 0, 0, 0, "", "Gossip option requires player to have the quest 'Master of Elixirs' rewarded OR"),
(15, 7571, 1, 0, 2, 27, 0, 68, 3, 0, 0, 0, 0, "", "Gossip option requires level 68 or higher"),
(15, 7571, 1, 0, 2, 7, 0, 171, 350, 0, 0, 0, 0, "", "Gossip option requires an Alchemy skill of 350 or higher"),
(15, 7571, 1, 0, 2, 25, 0, 28672, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Transmutation Master' NOT learned"),
(15, 7571, 1, 0, 2, 25, 0, 28677, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Elixir Master' NOT learned"),
(15, 7571, 1, 0, 2, 25, 0, 28675, 0, 0, 1, 0, 0, "", "Gossip option requires player to have the spell 'Potion Master' NOT learned"),
(15, 7571, 1, 0, 2, 8, 0, 10897, 0, 0, 0, 0, 0, "", "Gossip option requires player to have the quest 'Master of Potions' rewarded");

UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`="" WHERE `entry` IN (22427, 19052, 17909);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (22427, 19052, 17909) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22427, 0, 0, 1, 62, 0, 100, 0, @MENUID, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Zarevhi - On Gossip Option 0 Selected - Close Gossip"),
(22427, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 41565, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Zarevhi - On Gossip Option 0 Selected - Cast 'Unlearn Transmutation Mastery'"),
(22427, 0, 2, 3, 62, 0, 100, 0, 8542, 1, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Zarevhi - On Gossip Option 1 Selected - Close Gossip"),
(22427, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 28674, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Zarevhi - On Gossip Option 1 Selected - Invoker Cast 'Transmutation Master'"),
(19052, 0, 0, 1, 62, 0, 100, 0, @MENUID+1, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Lorokeem - On Gossip Option 0 Selected - Close Gossip"),
(19052, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 41564, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Lorokeem - On Gossip Option 0 Selected - Cast 'Unlearn Elixir Mastery'"),
(19052, 0, 2, 3, 62, 0, 100, 0, 8540, 1, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Lorokeem - On Gossip Option 1 Selected - Close Gossip"),
(19052, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 28678, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Lorokeem - On Gossip Option 1 Selected - Invoker Cast 'Elixir Master'"),
(17909, 0, 0, 1, 62, 0, 100, 0, @MENUID+2, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Lauranna Thar'well - On Gossip Option 0 Selected - Close Gossip"),
(17909, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 41563, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Lauranna Thar'well - On Gossip Option 0 Selected - Cast 'Unlearn Potion Mastery'"),
(17909, 0, 2, 3, 62, 0, 100, 0, 7571, 1, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Lauranna Thar'well - On Gossip Option 1 Selected - Close Gossip"),
(17909, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 28676, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Lauranna Thar'well - On Gossip Option 1 Selected - Invoker Cast 'Potion Master'");
