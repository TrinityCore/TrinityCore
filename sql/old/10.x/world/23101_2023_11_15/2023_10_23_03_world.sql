UPDATE `quest_template_addon` SET `ProvidedItemCount`=1 WHERE `ID` IN (11332,26248,26766,26861,26876,31514,31516,34422,40195,40541,41148,48016,54951,59930,72424,72644,75265);

INSERT INTO `quest_template_addon` (`ID`, `ProvidedItemCount`)
(SELECT qt.`ID`, 1 FROM `quest_template` qt
LEFT JOIN `quest_template_addon` qta ON qta.`ID` = qt.`ID`
WHERE qt.`StartItem`!=0 AND qta.`ProvidedItemCount` IS NULL);
