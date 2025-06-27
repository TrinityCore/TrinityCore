-- 
UPDATE `quest_template_addon` SET `SpecialFlags`=1 WHERE `id`=1463;
DELETE FROM `conditions` WHERE `SourceEntry`=1463 AND `SourceTypeOrReferenceId` IN (20, 19) AND `ConditionTypeOrReference` IN (2);
INSERT INTO `conditions` VALUES
(19, 0, 1463, 0, 0, 2, 0, 6635, 1, 1, 1, 0, 0, "", "Show quest 'Earth Sapta' only if the item 'earth-sapta' is not in player's bags or bank"),
(20, 0, 1463, 0, 0, 2, 0, 6635, 1, 1, 1, 0, 0, "", "Show question mark for quest 'Earth Sapta' only if the item 'earth-sapta' is not in player's bags or bank");
UPDATE `quest_request_items` SET `CompletionText`="I give you one in good faith. You already proved yourself once, but me tinkin' you should be more careful in the future." WHERE `ID`= 1463;
