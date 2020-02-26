-- amphitheater of anguish (12932) should be startable without completing "The Champion's Call!" (12974)
UPDATE `quest_template` SET `RewardNextQuest`=12932 WHERE `ID`=12974;
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=12932;
