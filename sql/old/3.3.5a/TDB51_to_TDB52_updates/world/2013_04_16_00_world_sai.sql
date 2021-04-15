SET @NPC_BUNNY1 := 23921;
SET @NPC_BUNNY2 := 23922;
SET @NPC_BUNNY3 := 23923;
SET @NPC_BUNNY4 := 23924;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=42564;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,42564,0,31,3,@NPC_BUNNY1,0,0,'','Spell Ever-burning Torch targets Halgrind Torch Bunny 01'),
(13,1,42564,1,31,3,@NPC_BUNNY2,0,0,'','Spell Ever-burning Torch targets Halgrind Torch Bunny 02'),
(13,1,42564,2,31,3,@NPC_BUNNY3,0,0,'','Spell Ever-burning Torch targets Halgrind Torch Bunny 03'),
(13,1,42564,3,31,3,@NPC_BUNNY4,0,0,'','Spell Ever-burning Torch targets Halgrind Torch Bunny 04');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@NPC_BUNNY1,@NPC_BUNNY2,@NPC_BUNNY3,@NPC_BUNNY4);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_BUNNY1,@NPC_BUNNY2,@NPC_BUNNY3,@NPC_BUNNY4) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_BUNNY1,0,0,1,8,0,100,0,42564,0,0,0,11,42632,0,0,0,0,0,7,0,0,0,0,0,0,0,'Halgrind Torch Bunny 01 - On spellhit Ever-burning Torch - Spellcast Mission: Eternal Flame: Bunny 01 Kill Credit'),
(@NPC_BUNNY1,0,1,2,61,0,100,0,0,0,0,0,50,186457,20,0,0,0,0,8,0,0,0,868.8023,-4339.792,182.2122,1.937312,'Halgrind Torch Bunny 01 - On spellhit Ever-burning Torch - Summon Blacksmith Smoke (x2.0)'),
(@NPC_BUNNY1,0,2,3,61,0,100,0,0,0,0,0,50,186457,20,0,0,0,0,8,0,0,0,870.0853,-4333.663,175.9133,2.059488,'Halgrind Torch Bunny 01 - On spellhit Ever-burning Torch - Summon Blacksmith Smoke (x2.0)'),
(@NPC_BUNNY1,0,3,4,61,0,100,0,0,0,0,0,50,186457,20,0,0,0,0,8,0,0,0,863.741,-4335.814,175.8825,2.809975,'Halgrind Torch Bunny 01 - On spellhit Ever-burning Torch - Summon Blacksmith Smoke (x2.0)'),
(@NPC_BUNNY1,0,4,5,61,0,100,0,0,0,0,0,50,186457,20,0,0,0,0,8,0,0,0,865.0932,-4329.501,184.862,-1.239183,'Halgrind Torch Bunny 01 - On spellhit Ever-burning Torch - Summon Blacksmith Smoke (x2.0)'),
(@NPC_BUNNY1,0,5,6,61,0,100,0,0,0,0,0,50,186459,20,0,0,0,0,8,0,0,0,868.7471,-4339.819,182.2086,-2.216565,'Halgrind Torch Bunny 01 - On spellhit Ever-burning Torch - Summon Stratholme Fire Medium'),
(@NPC_BUNNY1,0,6,7,61,0,100,0,0,0,0,0,50,186459,20,0,0,0,0,8,0,0,0,870.0593,-4333.669,175.9119,-3.019413,'Halgrind Torch Bunny 01 - On spellhit Ever-burning Torch - Summon Stratholme Fire Medium'),
(@NPC_BUNNY1,0,7,8,61,0,100,0,0,0,0,0,50,186459,20,0,0,0,0,8,0,0,0,863.8395,-4335.782,175.8698,2.251473,'Halgrind Torch Bunny 01 - On spellhit Ever-burning Torch - Summon Stratholme Fire Medium'),
(@NPC_BUNNY1,0,8,0,61,0,100,0,0,0,0,0,50,186459,20,0,0,0,0,8,0,0,0,865.0274,-4329.538,184.8592,-2.513274,'Halgrind Torch Bunny 01 - On spellhit Ever-burning Torch - Summon Stratholme Fire Medium'),

(@NPC_BUNNY2,0,0,1,8,0,100,0,42564,0,0,0,11,42633,0,0,0,0,0,7,0,0,0,0,0,0,0,'Halgrind Torch Bunny 02 - On spellhit Ever-burning Torch - Spellcast Mission: Eternal Flame: Bunny 02 Kill Credit'),
(@NPC_BUNNY2,0,1,2,61,0,100,0,0,0,0,0,50,186457,20,0,0,0,0,8,0,0,0,990.3699,-4312.481,169.8106,-0.1396245,'Halgrind Torch Bunny 02 - On spellhit Ever-burning Torch - Summon Blacksmith Smoke (x2.0)'),
(@NPC_BUNNY2,0,2,3,61,0,100,0,0,0,0,0,50,186457,20,0,0,0,0,8,0,0,0,986.9997,-4317.327,175.7941,-0.9948372,'Halgrind Torch Bunny 02 - On spellhit Ever-burning Torch - Summon Blacksmith Smoke (x2.0)'),
(@NPC_BUNNY2,0,3,4,61,0,100,0,0,0,0,0,50,186457,20,0,0,0,0,8,0,0,0,984.7455,-4311.373,170.311,0.9250239,'Halgrind Torch Bunny 02 - On spellhit Ever-burning Torch - Summon Blacksmith Smoke (x2.0)'),
(@NPC_BUNNY2,0,4,5,61,0,100,0,0,0,0,0,50,186457,20,0,0,0,0,8,0,0,0,989.3688,-4306.89,178.847,-0.6806787,'Halgrind Torch Bunny 02 - On spellhit Ever-burning Torch - Summon Blacksmith Smoke (x2.0)'),
(@NPC_BUNNY2,0,5,6,61,0,100,0,0,0,0,0,50,186459,20,0,0,0,0,8,0,0,0,986.9559,-4317.405,175.7507,-0.7853968,'Halgrind Torch Bunny 02 - On spellhit Ever-burning Torch - Summon Stratholme Fire Medium'),
(@NPC_BUNNY2,0,6,7,61,0,100,0,0,0,0,0,50,186459,20,0,0,0,0,8,0,0,0,990.3775,-4312.451,169.8137,-1.605702,'Halgrind Torch Bunny 02 - On spellhit Ever-burning Torch - Summon Stratholme Fire Medium'),
(@NPC_BUNNY2,0,7,8,61,0,100,0,0,0,0,0,50,186459,20,0,0,0,0,8,0,0,0,984.8902,-4311.392,170.2798,-1.169369,'Halgrind Torch Bunny 02 - On spellhit Ever-burning Torch - Summon Stratholme Fire Medium'),
(@NPC_BUNNY2,0,8,0,61,0,100,0,0,0,0,0,50,186459,20,0,0,0,0,8,0,0,0,989.3943,-4306.688,178.8235,1.448622,'Halgrind Torch Bunny 02 - On spellhit Ever-burning Torch - Summon Stratholme Fire Medium'),

(@NPC_BUNNY3,0,0,1,8,0,100,0,42564,0,0,0,11,42634,0,0,0,0,0,7,0,0,0,0,0,0,0,'Halgrind Torch Bunny 03 - On spellhit Ever-burning Torch - Spellcast Mission: Eternal Flame: Bunny 03 Kill Credit'),
(@NPC_BUNNY3,0,1,2,61,0,100,0,0,0,0,0,50,186457,20,0,0,0,0,8,0,0,0,1082.445,-4486.045,197.2445,2.268925,'Halgrind Torch Bunny 03 - On spellhit Ever-burning Torch - Summon Blacksmith Smoke (x2.0)'),
(@NPC_BUNNY3,0,2,3,61,0,100,0,0,0,0,0,50,186457,20,0,0,0,0,8,0,0,0,1084.6,-4491.493,190.9798,1.239183,'Halgrind Torch Bunny 03 - On spellhit Ever-burning Torch - Summon Blacksmith Smoke (x2.0)'),
(@NPC_BUNNY3,0,3,4,61,0,100,0,0,0,0,0,50,186457,20,0,0,0,0,8,0,0,0,1088.523,-4486.683,191.1761,2.652894,'Halgrind Torch Bunny 03 - On spellhit Ever-burning Torch - Summon Blacksmith Smoke (x2.0)'),
(@NPC_BUNNY3,0,4,5,61,0,100,0,0,0,0,0,50,186457,20,0,0,0,0,8,0,0,0,1091.084,-4492.35,199.8263,1.53589,'Halgrind Torch Bunny 03 - On spellhit Ever-burning Torch - Summon Blacksmith Smoke (x2.0)'),
(@NPC_BUNNY3,0,5,6,61,0,100,0,0,0,0,0,50,186459,20,0,0,0,0,8,0,0,0,1082.465,-4486.012,197.2427,-2.530723,'Halgrind Torch Bunny 03 - On spellhit Ever-burning Torch - Summon Stratholme Fire Medium'),
(@NPC_BUNNY3,0,6,7,61,0,100,0,0,0,0,0,50,186459,20,0,0,0,0,8,0,0,0,1084.627,-4491.507,190.978,2.583081,'Halgrind Torch Bunny 03 - On spellhit Ever-burning Torch - Summon Stratholme Fire Medium'),
(@NPC_BUNNY3,0,7,8,61,0,100,0,0,0,0,0,50,186459,20,0,0,0,0,8,0,0,0,1088.549,-4486.602,191.1885,-0.4886912,'Halgrind Torch Bunny 03 - On spellhit Ever-burning Torch - Summon Stratholme Fire Medium'),
(@NPC_BUNNY3,0,8,0,61,0,100,0,0,0,0,0,50,186459,20,0,0,0,0,8,0,0,0,1090.992,-4492.313,199.8432,-1.937316,'Halgrind Torch Bunny 03 - On spellhit Ever-burning Torch - Summon Stratholme Fire Medium'),

(@NPC_BUNNY4,0,0,1,8,0,100,0,42564,0,0,0,11,42635,0,0,0,0,0,7,0,0,0,0,0,0,0,'Halgrind Torch Bunny 04 - On spellhit Ever-burning Torch - Spellcast Mission: Eternal Flame: Bunny 04 Kill Credit'),
(@NPC_BUNNY4,0,1,2,61,0,100,0,0,0,0,0,50,186457,20,0,0,0,0,8,0,0,0,800.0019,-4499.426,192.1779,0.5934101,'Halgrind Torch Bunny 04 - On spellhit Ever-burning Torch - Summon Blacksmith Smoke (x2.0)'),
(@NPC_BUNNY4,0,2,3,61,0,100,0,0,0,0,0,50,186457,20,0,0,0,0,8,0,0,0,793.686,-4502.086,187.2915,1.53589,'Halgrind Torch Bunny 04 - On spellhit Ever-burning Torch - Summon Blacksmith Smoke (x2.0)'),
(@NPC_BUNNY4,0,3,4,61,0,100,0,0,0,0,0,50,186457,20,0,0,0,0,8,0,0,0,798.1101,-4505.706,186.7136,-0.4886912,'Halgrind Torch Bunny 04 - On spellhit Ever-burning Torch - Summon Blacksmith Smoke (x2.0)'),
(@NPC_BUNNY4,0,4,5,61,0,100,0,0,0,0,0,50,186457,20,0,0,0,0,8,0,0,0,794.305,-4506.923,196.7457,0.7330382,'Halgrind Torch Bunny 04 - On spellhit Ever-burning Torch - Summon Blacksmith Smoke (x2.0)'),
(@NPC_BUNNY4,0,5,6,61,0,100,0,0,0,0,0,50,186459,20,0,0,0,0,8,0,0,0,800.0145,-4499.367,192.1402,-1.047198,'Halgrind Torch Bunny 04 - On spellhit Ever-burning Torch - Summon Stratholme Fire Medium'),
(@NPC_BUNNY4,0,6,7,61,0,100,0,0,0,0,0,50,186459,20,0,0,0,0,8,0,0,0,793.655,-4502.067,187.294,2.268925,'Halgrind Torch Bunny 04 - On spellhit Ever-burning Torch - Summon Stratholme Fire Medium'),
(@NPC_BUNNY4,0,7,8,61,0,100,0,0,0,0,0,50,186459,20,0,0,0,0,8,0,0,0,798.0519,-4505.68,186.7271,0.2094394,'Halgrind Torch Bunny 04 - On spellhit Ever-burning Torch - Summon Stratholme Fire Medium'),
(@NPC_BUNNY4,0,8,0,61,0,100,0,0,0,0,0,50,186459,20,0,0,0,0,8,0,0,0,794.0874,-4507.057,196.7687,-0.2268925,'Halgrind Torch Bunny 04 - On spellhit Ever-burning Torch - Summon Stratholme Fire Medium');
