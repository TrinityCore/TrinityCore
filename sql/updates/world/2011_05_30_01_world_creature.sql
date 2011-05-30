-- Saviana Ragefire
UPDATE `creature_template` SET `InhabitType`=3,`mechanic_immune_mask`=`mechanic_immune_mask`|8388624,`ScriptName`= 'boss_saviana_ragefire' WHERE `entry`=39747;
DELETE FROM `creature_text` WHERE `entry`=39747; 
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES 
(39747,0,0, 'You will sssuffer for this intrusion!',14,0,100,0,0,17528, 'Saviana Ragefire'),
(39747,1,0, 'Burn in the master''s flame!',14,0,100,0,0,17532, 'Saviana Ragefire'),
(39747,2,0, '%s becomes enraged!',16,0,100,0,0,0, 'Saviana Ragefire'),
(39747,3,0, 'Halion will be pleased.',14,0,100,0,0,17530, 'Saviana Ragefire'),
(39747,3,1, 'As it should be....',14,0,100,0,0,17529, 'Saviana Ragefire');

-- Baltharus the Warborn Clone
UPDATE `creature_template` SET `AIName`= '',`ScriptName`= 'npc_baltarhus_the_warborn_clone' WHERE `entry`=39899;
DELETE FROM `smart_scripts` WHERE `entryorguid`=39899;