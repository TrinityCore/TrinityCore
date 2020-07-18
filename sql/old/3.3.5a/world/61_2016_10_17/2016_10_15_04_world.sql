--
UPDATE `quest_template_addon` SET `PrevQuestID`=13239 WHERE `ID`=13261;

UPDATE `conditions` SET `Comment`="Show gossip text if quest A Letter for Home is rewarded" WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=4519 AND `SourceEntry`=12696;
