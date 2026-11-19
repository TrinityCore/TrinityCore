-- Chain the Black Knight Quest Series
UPDATE `quest_template` SET `PrevQuestId`=0,`NextQuestId`=13641 WHERE `entry`=13633; -- The Black Knight of Westfall? (Ally)
UPDATE `quest_template` SET `PrevQuestId`=0,`NextQuestId`=13641 WHERE `entry`=13634; -- The Black Knight of Silverpine (Horde)
UPDATE `quest_template` SET `PrevQuestId`=0,`NextQuestId`=13643 WHERE `entry`=13641; -- The Seer's Crystal
UPDATE `quest_template` SET `PrevQuestId`=13641,`NextQuestId`=0 WHERE `entry`=13643; -- The Stories Dead Men Tell
UPDATE `quest_template` SET `PrevQuestId`=13643,`NextQuestId`=0 WHERE `entry`=13654; -- There's Something About the Squire
UPDATE `quest_template` SET `PrevQuestId`=13654,`NextQuestId`=0 WHERE `entry`=13663; -- The Black Knight's Orders
UPDATE `quest_template` SET `PrevQuestId`=13663,`NextQuestId`=0 WHERE `entry`=13664; -- The Black Knight's Fall
UPDATE `quest_template` SET `PrevQuestId`=13664,`NextQuestId`=0 WHERE `entry`=14016; -- The Black Knight's Curse
UPDATE `quest_template` SET `PrevQuestId`=14016,`NextQuestId`=0 WHERE `entry`=14017; -- The Black Knight's Fate
-- Thread from Above only after The Black Knight's Fall
UPDATE `quest_template` SET `PrevQuestId`=13664 WHERE `entry`=13682; -- Thread from Above only after The Black Knights Fall
UPDATE `quest_template` SET `PrevQuestId`=13664 WHERE `entry`=13788; -- Thread from Above only after The Black Knights Fall
UPDATE `quest_template` SET `PrevQuestId`=13664 WHERE `entry`=13809; -- Thread from Above only after The Black Knights Fall
UPDATE `quest_template` SET `PrevQuestId`=13664 WHERE `entry`=13812; -- Thread from Above only after The Black Knights Fall
-- Fix some startuperrors:
UPDATE `creature_template` SET `npcflag`=`npcflag`|128 WHERE `entry` IN (32405,32407);
