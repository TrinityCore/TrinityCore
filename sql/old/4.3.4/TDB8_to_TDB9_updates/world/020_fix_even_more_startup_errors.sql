--
UPDATE `quest_template` SET `RequiredNpcOrGoCount1`=0 WHERE `RequiredNpcOrGo1` = 0 AND `RequiredNpcOrGoCount1` > 0;
UPDATE `quest_template` SET `RequiredNpcOrGoCount2`=0 WHERE `RequiredNpcOrGo2` = 0 AND `RequiredNpcOrGoCount2` > 0;
UPDATE `quest_template` SET `RequiredNpcOrGoCount3`=0 WHERE `RequiredNpcOrGo3` = 0 AND `RequiredNpcOrGoCount3` > 0;
UPDATE `quest_template` SET `RequiredItemCount1`=0 WHERE `RequiredItemId1` = 0 AND `RequiredItemCount1` > 0;
UPDATE `quest_template` SET `RequiredSourceItemCount1`=0 WHERE `RequiredSourceItemId1` = 0 AND `RequiredSourceItemCount1` > 0;
UPDATE `quest_template` SET `RequiredSourceItemCount2`=0 WHERE `RequiredSourceItemId2` = 0 AND `RequiredSourceItemCount2` > 0;
UPDATE `quest_template` SET `RequiredSourceItemCount3`=0 WHERE `RequiredSourceItemId3` = 0 AND `RequiredSourceItemCount3` > 0;
UPDATE `quest_template` SET `RequiredSourceItemCount4`=0 WHERE `RequiredSourceItemId4` = 0 AND `RequiredSourceItemCount4` > 0;
