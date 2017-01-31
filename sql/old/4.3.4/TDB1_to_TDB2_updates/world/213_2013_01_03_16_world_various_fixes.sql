-- NPC talk text convert from creature_ai_text. Moving boss to cpp.
UPDATE `creature_template` SET `minlevel`=63,`maxlevel`=63,`InhabitType`=5,`AIName`= '', `ScriptName`= 'boss_kirtonos_the_herald' WHERE `entry`=10506;
UPDATE `gameobject_template` SET `AIName`= '', `ScriptName`= 'go_brazier_of_the_herald' WHERE `entry`=175564;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=10506; 4.x
-- DELETE FROM `creature_ai_texts` WHERE `entry`=-448; 4.x
DELETE FROM `creature_text` WHERE `entry` IN (10506);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(10506,0,0, '%s lets out a shrill cry.',16,0,100,0,0,0, 'Kirtonos The Herald - Emote');
