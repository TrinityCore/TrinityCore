-- db errors
UPDATE `creature_template` SET `exp`=0 WHERE `entry` IN (13096,12047,13116,37236,13116,37323,13546,13777,14284,37409,14285,14848);
UPDATE `creature_template` SET `exp`=1 WHERE `entry` IN (20536,20539);
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry` IN (14185,14186,14187,14188);
