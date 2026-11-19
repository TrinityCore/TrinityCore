UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (16977,16978);
DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (16977,16978); -- clean old EAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (16977, 16978) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(16977,0,0,0,25,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arch Mage Xintor - prevent combat movement on spawn'),
(16977,0,1,0,4,0,100,0,0,0,0,0,11,20823,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Arch Mage Xintor - cast fireball on aggro'),
(16977,0,2,0,4,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arch Mage Xintor - set phase 1 on aggro'),
(16977,0,3,0,9,1,100,0,0,40,2400,3800,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Arch Mage Xintor - cast fireball'),
(16977,0,4,0,3,1,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arch Mage Xintor - start normal attack on 15% mana'),
(16977,0,5,0,3,1,100,0,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arch Mage Xintor - set phase 2 on 15% mana'),
(16977,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arch Mage Xintor - combatmovement'),
(16977,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arch Mage Xintor - combatmovement'),
(16977,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arch Mage Xintor - combatmovement'),
(16977,0,9,0,3,1,100,0,30,100,100,100,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arch Mage Xintor - set phase 1 on 30% mana'),
(16977,0,10,0,0,1,50,0,6000,8000,9000,12000,11,15735,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Arch Mage Xintor - cast arcane missles'),
(16977,0,11,0,2,0,100,0,0,50,0,0,11,33245,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arch Mage Xintor - 50% hp - cast ice barrier'),
(16977,0,12,0,2,0,100,0,0,50,0,0,11,29458,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Arch Mage Xintor - 50% hp - cast blizzard'),
(16977,0,13,0,2,0,100,0,0,15,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Arch Mage Xintor - flee on 15% hp'),
(16977,0,14,0,7,0,100,0,0,0,0,0,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Arch Mage Xintor - set phase 0 on evade'),
(16978,0,0,0,0,0,50,0,4000,4000,8000,8000,11,8242,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Lieutenant Commander Thalvos - Cast Shield Slam'),
(16978,0,1,0,0,0,50,0,5000,5000,10000,10000,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Lieutenant Commander Thalvos - Cast Strike'),
(16978,0,2,0,25,0,100,0,0,0,0,0,11,27978,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Lieutenant Commander Thalvos - Shroud of Death');
