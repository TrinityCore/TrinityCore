-- NPC talk text insert for Sara
DELETE FROM `creature_text` WHERE `entry`=33134;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(33134,0,0, 'Help me! Please get them off me!',14,0,100,0,0,15771, 'Sara YELL_PREFIGHT'),
(33134,0,1, 'What do you want from me? Leave me alone!',14,0,100,0,0,15772, 'Sara YELL_PREFIGHT'),
(33134,1,0, 'Yes! YES! Show them no mercy! Give no pause to your attacks!',14,0,100,0,0,15773, 'Sara YELL_COMBAT_PHASE_1'),
(33134,1,1, 'Let hatred and rage guide your blows!',14,0,100,0,0,15774, 'Sara YELL_COMBAT_PHASE_1'),
(33134,1,2, 'The time to strike at the head of the beast will soon be upon us! Focus your anger and hatred on his minions!',14,0,100,457,0,15775, 'Sara YELL_COMBAT_PHASE_1'),
(33134,2,0, 'Suffocate upon your own hate!',14,0,100,0,0,15776, 'Sara YELL_COMBAT_PHASE_2'),
(33134,2,1, 'Tremble, mortals, before the coming of the end!',14,0,100,0,0,15777, 'Sara YELL_COMBAT_PHASE_2'),
(33134,3,0, 'Powerless to act...',14,0,100,0,0,15778, 'Sara YELL_SLAY'),
(33134,3,1, 'Could they have been saved?',14,0,100,0,0,15779, 'YELL SAY_SLAY');
-- remove script text
DELETE FROM script_texts WHERE entry BETWEEN -1603319 AND -1603310;
