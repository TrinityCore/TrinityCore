--
UPDATE `creature_template_addon` SET `auras`="5680" WHERE `entry`=17278;
UPDATE `creature_template` SET `AIName`="" WHERE `entry`=17278;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17278;
