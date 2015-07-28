-- Fix the quest chain for quests 25723, 25725 & 25735 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 25723 WHERE `Id` = 25725;
UPDATE `quest_template` SET `PrevQuestId` = 25725 WHERE `Id` = 25735;

-- Fix the quest chain for quests 25997, 25998, 26078, 26085, 26094, 26102 & 26112 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 25997 WHERE `Id` = 25998;
UPDATE `quest_template` SET `PrevQuestId` = 25998 WHERE `Id` = 26078;
UPDATE `quest_template` SET `PrevQuestId` = 26078 WHERE `Id` = 26085;
UPDATE `quest_template` SET `PrevQuestId` = 26085 WHERE `Id` = 26094;
UPDATE `quest_template` SET `PrevQuestId` = 26094 WHERE `Id` = 26102;
UPDATE `quest_template` SET `PrevQuestId` = 26102 WHERE `Id` = 26112;

-- Fix the quest chain for quests 13636, 26843 & 26844 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 13636 WHERE `Id` = 26843;
UPDATE `quest_template` SET `PrevQuestId` = 26843 WHERE `Id` = 26844;

-- Fix the quest chain for quests 26393, 26394, 26395 & 26396 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 26393 WHERE `Id` = 26394;
UPDATE `quest_template` SET `PrevQuestId` = 26394 WHERE `Id` = 26395;
UPDATE `quest_template` SET `PrevQuestId` = 26395 WHERE `Id` = 26396;

-- Fix the quest chain for quests 26688, 26689, 26690 & 26691 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 26688 WHERE `Id` = 26689;
UPDATE `quest_template` SET `PrevQuestId` = 26689 WHERE `Id` = 26690;
UPDATE `quest_template` SET `PrevQuestId` = 26690 WHERE `Id` = 26691;

-- Fix the quest chain for quests 26653, 26652, 26654, 26655, 26660, 26661, 26676, 26680, 26677, 26681 & 26727 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 26653 WHERE `Id` = 26652;
UPDATE `quest_template` SET `PrevQuestId` = 26652 WHERE `Id` = 26654;
UPDATE `quest_template` SET `PrevQuestId` = 26654 WHERE `Id` = 26655;
UPDATE `quest_template` SET `PrevQuestId` = 26655 WHERE `Id` = 26660;
UPDATE `quest_template` SET `PrevQuestId` = 26660 WHERE `Id` = 26661;
UPDATE `quest_template` SET `PrevQuestId` = 26661 WHERE `Id` = 26676;
UPDATE `quest_template` SET `PrevQuestId` = 26676 WHERE `Id` = 26680;
UPDATE `quest_template` SET `PrevQuestId` = 26680 WHERE `Id` = 26677;
UPDATE `quest_template` SET `PrevQuestId` = 26677 WHERE `Id` = 26681;
UPDATE `quest_template` SET `PrevQuestId` = 26681 WHERE `Id` = 26727;

-- Fix the quest chain for quests 26683, 26684 & 26685 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 26683 WHERE `Id` = 26684;
UPDATE `quest_template` SET `PrevQuestId` = 26684 WHERE `Id` = 26685;

-- Fix the quest chain for quests 26666, 26667, 26669. 26670, 26671, 26672 & 26674 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 26666 WHERE `Id` = 26667;
UPDATE `quest_template` SET `PrevQuestId` = 26667 WHERE `Id` = 26669;
UPDATE `quest_template` SET `PrevQuestId` = 26669 WHERE `Id` = 26670;
UPDATE `quest_template` SET `PrevQuestId` = 26670 WHERE `Id` = 26671;
UPDATE `quest_template` SET `PrevQuestId` = 26671 WHERE `Id` = 26672;
UPDATE `quest_template` SET `PrevQuestId` = 26672 WHERE `Id` = 26674;
