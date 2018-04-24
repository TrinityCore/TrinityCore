-- Apply Disables

DELETE FROM `disables` WHERE `entry` IN (8328,8329,8563,8564,9392,9393,9676,10068,10069,10070,10071,10072,10073,27091,31170,31171,37441);
Insert INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(1,8328,0,"","","Deprecated Quest: Mage Training"),
(1,8329,0,"","","Deprecated Quest: Warrior Training"),
(1,8563,0,"","","Deprecated Quest: Warlock Training"),
(1,8564,0,"","","Deprecated Quest: Priest Training"),
(1,9392,0,"","","Deprecated Quest: Rogue Training"),
(1,9393,0,"","","Deprecated Quest: Hunter Training"),
(1,9676,0,"","","Deprecated Quest: Paladin Training"),
(1,31170,0,"","","Deprecated Quest: Monk Training"),
(1,10068,0,"","","Deprecated Quest: Frost Nova"),
(1,27091,0,"","","Deprecated Quest: Charge!"),
(1,10070,0,"","","Deprecated Quest: Steady Shot"),
(1,10073,0,"","","Deprecated Quest: Corruption"),
(1,10069,0,"","","Deprecated Quest: Ways of the Light"),
(1,10072,0,"","","Deprecated Quest: Learning the Word"),
(1,10071,0,"","","Deprecated Quest: Evisceration"),
(1,31171,0,"","","Deprecated Quest: Tiger Palm"),
(1,37441,0,"","","Deprecated Quest: Solanian Belonging's (Unused Version)");

-- Delete QuestGiver Flag. Trainers no longer have quests.

UPDATE `creature_template` SET `npcflag` = 49 WHERE `entry` IN (15283,15285,15513,43010,15284,15280);

-- Stops randoms Questgiver Marks on Sunstrider Isles. Have an incorrect queststarter info (already deleted below)

UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 15468;

-- Delete Info of deprecated quests on Queststarter and Questender

DELETE FROM `creature_queststarter` WHERE `quest` in (8328,8329,8330,8336,8345,8346,8563,8564,9392,9393,9676,10068,10069,10070,10071,10072,10073,27091,31170,31171,37441);
DELETE FROM `creature_questender` WHERE `quest` in (8328,8329,8330,8336,8345,8346,8563,8564,9392,9393,9676,10068,10069,10070,10071,10072,10073,27091,31170,31171,37441);
