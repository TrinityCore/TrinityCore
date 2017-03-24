--
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|64 WHERE `entry` IN (22506, 22507);

UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=10935;
UPDATE `quest_template_addon` SET `ExclusiveGroup`=-10909, `NextQuestID`=10935 WHERE `ID` IN (10909, 10916);
