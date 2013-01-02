-- NPC talk text convert from creature_ai_text. Moving boss to cpp.
UPDATE `creature_template` SET `AIName`= '', `ScriptName`= 'boss_commander_sarannis' WHERE `entry`=17976;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=17976;
DELETE FROM `creature_ai_texts` WHERE `entry` BETWEEN -39 AND -34;
DELETE FROM `creature_text` WHERE `entry` IN (17976);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(17976,0,0, 'Step forward! I will see that you are properly welcomed.',14,0,100,0,0,11071, 'Commander Sarannis - On Aggro Say'),
(17976,1,0, 'Oh stop your whimpering.',14,0,100,0,0,11072, 'Commander Sarannis - On Player Death Say'),
(17976,1,1, 'Mission accomplished.',14,0,100,0,0,11073, 'Commander Sarannis - On Player Death Say'),
(17976,2,0, 'You are no longer dealing with some underling.',14,0,100,0,0,11076, 'Commander Sarannis - On Cast Arcane Resonance Say'),
(17976,3,0, 'Band''or shorel''aran!',14,0,100,0,0,11077, 'Commander Sarannis - On Cast Arcane Devastation Say'),
(17976,4,0, '%s calls for reinforcements.',16,0,100,0,0,0, 'Commander Sarannis - On HP@50% Summon emote'),
(17976,5,0, 'Guards! Come and kill these intruders!',14,0,100,0,0,11078, 'Commander Sarannis - On HP@50% Summon Say'),
(17976,6,0, 'I have not yet... begun to...',14,0,100,0,0,11079, 'Commander Sarannis - On Death Say');

-- NPC talk text convert from creature_ai_text. Moving boss to cpp.
UPDATE `creature_template` SET `AIName`= '', `ScriptName`= 'thorngrin_the_tender' WHERE `entry`=17978;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=17978;
DELETE FROM `creature_ai_texts` WHERE entry BETWEEN -16 AND -9;
DELETE FROM `creature_text` WHERE `entry` IN (17978);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(17978,0,0, 'What aggravation is this? You will die!',14,0,100,0,0,11205, 'Thorngrin the Tender - Aggro Say'),
(17978,1,0, 'You seek a prize, eh? How about death?',14,0,100,0,0,11206, 'Thorngrin the Tender - 20% Health Say'),
(17978,2,0, 'I hate to say I told you so...',14,0,100,0,0,11207, 'Thorngrin the Tender - Player Death Say'),
(17978,3,0, 'Your life will be mine!',14,0,100,0,0,11208, 'Thorngrin the Tender - Cast Sacrifice Say'),
(17978,4,0, 'I revel in your pain!',14,0,100,0,0,11209, 'Thorngrin the Tender - 50% Health Say'),
(17978,5,0, 'I''ll incinerate you!',14,0,100,0,0,11210, 'Thorngrin the Tender - Cast Hellfire Say'),
(17978,5,1, 'Scream while you burn!',14,0,100,0,0,11211, 'Thorngrin the Tender - Cast Hellfire Say'),
(17978,6,0, 'You won''t... get far.',14,0,100,0,0,11212, 'Thorngrin the Tender - On Death Say'),
(17978,7,0, '%s becomes enraged!',16,0,100,0,0,0, 'Thorngrin the Tender - On Enrage Say');
