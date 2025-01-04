-- Unneeded Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry` IN (26316,26318,26339);
-- Unneeded SpecialFlags
UPDATE `quest_template_addon` SET `SpecialFlags`=0 WHERE `ID` IN (26197,26199,26202,26203,26206,26264,26333,26373,26421,26422,26423,26424,26425,27635,27671,27674,28167,28169,31135,31137,41217,41218);
-- A Job for the Multibot, What's Left Behind, Dealing With the Fallout ExclusiveGroup
UPDATE `quest_template_addon` SET `ExclusiveGroup`=-26205 WHERE `ID` IN (26205,26264,26265);
UPDATE `quest_template_addon` SET `NextQuestID`=26316 WHERE `ID` IN (26205,26264,26265);
-- Missing In Action and Get Me Explosives Back ExclusiveGroup
UPDATE `quest_template_addon` SET `ExclusiveGroup`=-26284 WHERE `ID` IN (26284,26285);
UPDATE `quest_template_addon` SET `NextQuestID`=26318 WHERE `ID` IN (26284,26285);
-- Crushcog's Minions and No Tanks ExclusiveGroup
UPDATE `quest_template_addon` SET `ExclusiveGroup`=-26331 WHERE `ID` IN (26331,26333);
UPDATE `quest_template_addon` SET `NextQuestID`=26339 WHERE `ID` IN (26331,26333);
