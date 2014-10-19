-- Cleanup of Quest_template Spam in Console
UPDATE `quest_template` SET `SourceItemCount`=0 WHERE `SourceItemId`=0;
UPDATE `quest_template` SET `RequiredItemCount1`=0 WHERE `RequiredItemId1`=0;
UPDATE `quest_template` SET `RequiredItemCount2`=0 WHERE `RequiredItemId2`=0;
UPDATE `quest_template` SET `RequiredSourceItemCount1`=0 WHERE `RequiredSourceItemId1`=0;
UPDATE `quest_template` SET `RequiredSourceItemCount2`=0 WHERE `RequiredSourceItemId2`=0;
UPDATE `quest_template` SET `RequiredSourceItemCount3`=0 WHERE `RequiredSourceItemId3`=0;
UPDATE `quest_template` SET `RequiredSourceItemCount4`=0 WHERE `RequiredSourceItemId4`=0;
UPDATE `quest_template` SET `RequiredNpcOrGoCount1`=0 WHERE `RequiredNpcOrGo1`=0;
UPDATE `quest_template` SET `RequiredNpcOrGoCount2`=0 WHERE `RequiredNpcOrGo2`=0;
UPDATE `quest_template` SET `RequiredNpcOrGoCount3`=0 WHERE `RequiredNpcOrGo3`=0;
UPDATE `quest_template` SET `RequiredNpcOrGoCount4`=0 WHERE `RequiredNpcOrGo4`=0;
UPDATE `quest_template` SET `RewardCurrencyId1`=0 WHERE `RewardCurrencyCount1`=0;

UPDATE `quest_template` SET `RequiredSkillId`=171 WHERE `ZoneOrSort`=-181;
UPDATE `quest_template` SET `RequiredSkillId`=185 WHERE `ZoneOrSort`=-304;
UPDATE `quest_template` SET `RequiredSkillId`=356 WHERE `ZoneOrSort`=-101;
UPDATE `quest_template` SET `RequiredSkillId`=794 WHERE `ZoneOrSort`=-377;
UPDATE `quest_template` SET `RequiredSkillId`=755 WHERE `ZoneOrSort`=-373;
UPDATE `quest_template` SET `RequiredSkillId`=773 WHERE `ZoneOrSort`=-371;
UPDATE `quest_template` SET `RequiredSkillId`=202 WHERE `ZoneOrSort`=-201;
