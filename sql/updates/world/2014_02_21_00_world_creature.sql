-- db errors
UPDATE `creature_template` SET `exp`=0 WHERE `entry` IN (13096,12047,13116,37236,13116,37323,13546,13777,14284,37409,14285,14848);
UPDATE `creature_template` SET `exp`=1 WHERE `entry` IN (20536,20539);
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry` IN (14185,14186,14187,14188,22712,22569,22528,22699,32049,32053,31924,31963);
UPDATE `creature_template` SET `npcflag`=128 WHERE `entry`=37486; -- vendor
UPDATE `creature_template` SET `npcflag`=4225 WHERE `entry` IN (3343,22650,31999,37318,13218,22681,32001,37320); -- vendor+repair+gossip
UPDATE `creature_template` SET `npcflag`=3 WHERE `entry` IN (13437,22597,32766,37480,13439,22722,31823,37484,13176,22571,32080,37401,13179,22721,31828,37479,13180,22697,31826,37481); -- quest giver+gossip
