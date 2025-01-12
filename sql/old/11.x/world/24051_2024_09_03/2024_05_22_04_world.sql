INSERT INTO `quest_template_addon` (`ID`, `ProvidedItemCount`)
(SELECT qt.`ID`, 1 FROM `quest_template` qt
LEFT JOIN `quest_template_addon` qta ON qta.`ID` = qt.`ID`
WHERE qt.`StartItem`!=0 AND qta.`ProvidedItemCount` IS NULL);
