 /* Quest/Barrens Horde - Counterattack! */
SET @Counterattack = 4021;

-- Vars
SET @Gossip = 21253;
-- NPCs
SET @Deathgate = 3389; -- Regthar Deathgate (quest giver)
SET @Kromzar = 9456; -- Warlord Krom'zar (abilities: 11976 Strike)
SET @Stormseer = 9523; -- Kolkar Stormseer (abilities: 9532 Lighting Bolt; 6535 Lightning Cloud)
SET @Invader = 9524; -- Kolkar Invader (abilities: 8014 Tetatuns, 11976 Strike, 6268 Rushing Charge)
SET @Thrower = 9458; -- Horde Axe Thrower
SET @Defender = 9457; -- Horde Defender (abilities: 10277 Throw)
-- Spells
SET @CreateBanner = 13965; -- Create Krom'zar's Banner

DELETE FROM `gossip_menu` WHERE `entry` IN (@Gossip,@Gossip+1);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(@Gossip+0,2533),
(@Gossip+1,2534);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=@Gossip AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@Gossip,0,0, 'Where is Warlord Krom''zar?',1,1,@Gossip+1,0,0,0,0,NULL);

DELETE FROM `creature_text` WHERE `entry` IN (@Deathgate,@Invader,@Thrower,@Kromzar);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Deathgate,0,0,'Beware, $N! Look to the west!',0,0,100,1,0,0,'Regthar Deathgate: quest start'),
(@Deathgate,1,0,'A defender has fallen!',0,0,100,1,0,0,'Regthar Deathgate: Horde Defender death'),
(@Invader,0,0,'Kolkar Invader charges!',2,0,100,0,0,0,'Kolkar Invader: aggro'),
(@Thrower,0,0,'Defend the bunkers!',0,0,100,0,0,0,'Kolkar Axe Thrower'),
(@Thrower,0,1,'Our foes will fail!',0,0,100,0,0,0,'Kolkar Axe Thrower'),
(@Thrower,0,2,'For the Horde',0,0,100,0,0,0,'Kolkar Axe Thrower'),
(@Kromzar,0,0,'The Kolkar are the strongest!',1,0,100,0,0,0,'Warlord Krom''zar: spawn');

UPDATE `creature_template` SET `AIName`='SmartAI', `MovementType`=1 WHERE `entry` IN (@Kromzar,@Invader,@Stormseer,@Thrower,@Defender);
UPDATE `creature_template` SET `AIName`='SmartAI', `gossip_menu_id`=@Gossip WHERE `entry`=@Deathgate;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@Gossip;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`Comment`) VALUES
(15,@Gossip,0,0,9,@Counterattack,0,0,0, 'Regthar Deathgate: Counterattack!: gossip: has quest'),
(15,@Gossip,0,0,26,11227,0,0,0, 'Regthar Deathgate: Counterattack!: gossip: does not have item Piece Banner');

DELETE FROM `smart_scripts` WHERE (`entryorguid`=@Kromzar AND `source_type`=0);
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@Deathgate AND `source_type`=0);
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@Invader AND `source_type`=0);
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@Stormseer AND `source_type`=0);
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@Thrower AND `source_type`=0);
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@Deathgate*100 AND `source_type`=9);
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@Defender AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Kromzar,0,0,0,0,0,100,0,0,1000,4000,6000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,'Warlord Krom''Zar: In combat cast Strike every 4 to 6 seconds'),
(@Kromzar,0,1,0,6,0,100,1,0,1000,5000,8000,11,@CreateBanner,2,0,0,0,0,0,0,0,0,0,0,0,0,'Warlord Krom''Zar: On death cast Create Krom''zar''s Banner'),
(@Kromzar,0,4,0,11,0,100,0,0,0,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Warlord Krom''Zar: On spawn set random movement'),
(@Kromzar,0,5,0,11,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Warlord Krom''Zar: On spawn say text 0'),
(@Invader,0,0,0,4,0,100,0,0,0,0,0,11,6268,0,0,0,0,0,2,0,0,0,0,0,0,0,'Kolkar Invader: On aggro cast Rushing Charge'),
(@Invader,0,1,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kolkar Invader: On aggro say text 0'),
(@Invader,0,2,0,0,0,100,0,0,1000,4000,6000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,'Kolkar Invader: In combat cast Strike every 4 to 6 seconds'),
(@Invader,0,3,0,0,0,100,0,1000,2000,20000,20000,11,8014,0,0,0,0,0,2,0,0,0,0,0,0,0,'Kolkar Invader: In combat cast Tetanus every 20 seconds'),
(@Invader,0,4,0,11,0,100,0,0,0,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kolkar Invader: On spawn set random movement'),
(@Stormseer,0,0,0,11,0,100,0,0,0,0,0,58,1,9532,3500,6000,30,15,1,0,0,0,0,0,0,0,'Kolkar Stormseer: On respawn install AI template caster for Lighting Bolt'),
(@Stormseer,0,1,0,0,0,100,0,3000,4000,10000,10000,11,6535,1,0,0,0,0,2,0,0,0,0,0,0,0,'Kolkar Stormseer: In combat cast Lightning Cloud every 10 seconds'),
(@Stormseer,0,2,0,11,0,100,0,0,0,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kolkar Stormseer: On spawn set random movement'),
(@Thrower,0,0,0,11,0,100,0,0,0,0,0,58,2,10277,35,0,0,0,1,0,0,0,0,0,0,0,'Horde Axe Thrower: On respawn install AI template turret for Throw'),
(@Thrower,0,1,0,6,0,100,0,0,0,0,0,12,@Thrower,1,450000,0,0,0,8,0,0,0,-293.212,-1912.51,91.6673,1.42794,'Horde Axe Thrower: On death summon Horde Axe Thrower'),
(@Thrower,0,2,0,11,0,100,0,0,0,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Horde Axe Thower: On spawn set random movement'),
(@Thrower,0,3,0,60,0,100,0,20000,25000,30000,40000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Horde Axe Thower: Say text 0 every 30 to 40 seconds'),
(@Defender,0,0,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,9,@Deathgate,0,300,0,0,0,0,'Horde Axe Thrower: On death Regthar Deathgate say text 1'),
(@Defender,0,1,0,6,0,100,0,0,0,0,0,12,@Defender,1,450000,0,0,0,8,0,0,0,-280.703,-1908.01,91.6668,1.77351,'Horde Defender: On death summon Horde Defender'),
(@Defender,0,2,0,11,0,100,0,0,0,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Horde Defender: On spawn set random movement'),
(@Deathgate,0,0,0,11,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Regthar Deathgate: On respawn set phase 1 (p0)'),
(@Deathgate,0,1,0,19,1,100,0,@Counterattack,0,0,0,1,0,0,0,0,0,0,18,15,0,0,0,0,0,0,'Regthar Deathgate: On quest accept say text 0 (p1)'),
(@Deathgate,0,2,0,19,1,100,0,@Counterattack,0,0,0,22,2,0,0,0,0,0,0,0,0,0,0,0,0,0,'Regthar Deathgate: On quest accept set event phase 2 (p1)'),
(@Deathgate,0,3,0,19,2,100,0,@Counterattack,0,0,0,80,@Deathgate*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Regthar Deathgate: On quest accept call main script (p2)'),
(@Deathgate,0,4,0,62,1,100,0,@Gossip,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Regthar Deathgate: On gossip select say text 0 (p1)'),
(@Deathgate,0,5,0,62,4,100,0,@Gossip,0,0,0,80,@Deathgate*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Regthar Deathgate: On gossip select call main script (p4)'),
(@Deathgate*100,9,0,0,0,0,100,0,0,0,0,0,12,@Defender,1,450000,0,0,0,8,0,0,0,-280.703,-1908.01,91.6668,1.77351,'Counterattack!: Summon Horde Axe Thrower 1'),
(@Deathgate*100,9,1,0,0,0,100,0,0,0,0,0,12,@Defender,1,450000,0,0,0,8,0,0,0,-286.384,-1910.99,91.6668,1.59444,'Counterattack!: Summon Horde Defender 2'),
(@Deathgate*100,9,2,0,0,0,100,0,0,0,0,0,12,@Defender,1,450000,0,0,0,8,0,0,0,-297.373,-1917.11,91.6746,1.81435,'Counterattack!: Summon Horde Defender 3'),
(@Deathgate*100,9,3,0,0,0,100,0,0,0,0,0,12,@Thrower,1,450000,0,0,0,8,0,0,0,-293.212,-1912.51,91.6673,1.42794,'Counterattack!: Summon Horde Axe Thrower 1'),
(@Deathgate*100,9,4,0,0,0,100,0,0,0,0,0,12,@Invader,1,450000,0,0,0,8,0,0,0,-280.037,-1888.35,92.2549,2.28087,'Counterattack!: Summon Kolkar Invader'),
(@Deathgate*100,9,5,0,0,0,100,0,0,0,0,0,12,@Invader,1,450000,0,0,0,8,0,0,0,-292.107,-1899.54,91.667,4.78158,'Counterattack!: Summon Kolkar Invader'),
(@Deathgate*100,9,6,0,0,0,100,0,0,0,0,0,12,@Invader,1,450000,0,0,0,8,0,0,0,-305.57,-1869.88,92.7754,2.45131,'Counterattack!: Summon Kolkar Invader'),
(@Deathgate*100,9,7,0,0,0,100,0,0,0,0,0,12,@Invader,1,450000,0,0,0,8,0,0,0,-289.972,-1882.76,92.5714,3.43148,'Counterattack!: Summon Kolkar Invader'),
(@Deathgate*100,9,8,0,0,0,100,0,0,0,0,0,12,@Invader,1,450000,0,0,0,8,0,0,0,-277.454,-1873.39,92.7773,4.75724,'Counterattack!: Summon Kolkar Invader'),
(@Deathgate*100,9,9,0,0,0,100,0,0,0,0,0,12,@Invader,1,450000,0,0,0,8,0,0,0,-271.581,-1847.51,93.4329,4.39124,'Counterattack!: Summon Kolkar Invader'),
(@Deathgate*100,9,10,0,0,0,100,0,0,0,0,0,12,@Invader,1,450000,0,0,0,8,0,0,0,-269.982,-1828.6,92.4754,4.68655,'Counterattack!: Summon Kolkar Invader'),
(@Deathgate*100,9,11,0,0,0,100,0,0,0,0,0,12,@Stormseer,1,450000,0,0,0,8,0,0,0,-279.267,-1827.92,92.3128,1.35332,'Counterattack!: Summon Kolkar Stormseer'),
(@Deathgate*100,9,12,0,0,0,100,0,0,0,0,0,12,@Stormseer,1,450000,0,0,0,8,0,0,0,-297.42,-1847.41,93.2295,5.80967,'Counterattack!: Summon Kolkar Stormseer'),
(@Deathgate*100,9,13,0,0,0,100,0,0,0,0,0,12,@Stormseer,1,450000,0,0,0,8,0,0,0,-310.607,-1831.89,95.9363,0.371571,'Counterattack!: Summon Kolkar Stormseer'),
(@Deathgate*100,9,14,0,0,0,100,0,0,0,0,0,12,@Stormseer,1,450000,0,0,0,8,0,0,0,-329.177,-1842.43,95.3891,0.516085,'Counterattack!: Summon Kolkar Stormseer'),
(@Deathgate*100,9,15,0,0,0,100,0,0,0,0,0,12,@Stormseer,1,450000,0,0,0,8,0,0,0,-324.448,-1860.63,94.3221,4.97793,'Counterattack!: Summon Kolkar Stormseer'),
(@Deathgate*100,9,16,0,0,0,100,0,20000,30000,0,0,12,@Invader,1,250000,0,0,0,8,0,0,0,-290.588,-1858,92.5026,4.14698,'Counterattack!: Summon Kolkar Invader'),
(@Deathgate*100,9,17,0,0,0,100,0,20000,30000,0,0,12,@Stormseer,1,250000,0,0,0,8,0,0,0,-286.103,-1846.18,92.544,6.11047,'Counterattack!: Summon Kolkar Stormseer'),
(@Deathgate*100,9,18,0,0,0,100,0,20000,30000,0,0,12,@Invader,1,250000,0,0,0,8,0,0,0,-304.978,-1844.7,94.4432,1.61721,'Counterattack!: Summon Kolkar Invader'),
(@Deathgate*100,9,19,0,0,0,100,0,20000,30000,0,0,12,@Stormseer,1,250000,0,0,0,8,0,0,0,-308.105,-1859.08,93.8039,2.80709,'Counterattack!: Summon Kolkar Stormseer'),
(@Deathgate*100,9,20,0,0,0,100,0,20000,30000,0,0,12,@Invader,1,250000,0,0,0,8,0,0,0,-297.089,-1867.68,92.5601,2.21804,'Counterattack!: Summon Kolkar Invader'),
(@Deathgate*100,9,21,0,0,0,100,0,20000,30000,0,0,12,@Stormseer,1,250000,0,0,0,8,0,0,0,-286.988,-1876.47,92.7447,1.39494,'Counterattack!: Summon Kolkar Stormseer'),
(@Deathgate*100,9,22,0,0,0,100,0,20000,30000,0,0,12,@Invader,1,250000,0,0,0,8,0,0,0,-291.86,-1893.04,92.0213,1.96121,'Counterattack!: Summon Kolkar Invader'),
(@Deathgate*100,9,23,0,0,0,100,0,20000,30000,0,0,12,@Invader,1,250000,0,0,0,8,0,0,0,-298.297,-1846.85,93.3672,4.97792,'Counterattack!: Summon Kolkar Invader'),
(@Deathgate*100,9,24,0,0,0,100,0,0,0,0,0,12,@Invader,1,250000,0,0,0,8,0,0,0,-294.942,-1845.88,93.0999,4.86797,'Counterattack!: Summon Kolkar Invader'),
(@Deathgate*100,9,25,0,0,0,100,0,0,0,0,0,12,@Kromzar,1,250000,0,0,0,8,0,0,0,-296.718,-1846.38,93.2334,5.02897,'Counterattack!: Summon Warlord Kromzar'),
(@Deathgate*100,9,26,0,0,0,100,0,20000,20000,0,0,22,4,1,450000,0,0,0,1,0,0,0,0,0,0,0,'Regthar Deathgate: set phase 4'), -- if player does not finish this quest this time s/he can come back later'
(@Deathgate*100,9,27,0,0,0,100,0,2*3600*1000,2*3600*1000,0,0,22,1,1,450000,0,0,0,1,0,0,0,0,0,0,0,'Regthar Deathgate: set phase 1'), -- after 2 hours reset everything (event start on quest accept)'
(@Deathgate,0,7,0,20,10,100,0,@Counterattack,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Regthar Deathgate: On quest reward set phase 1');

DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (@Deathgate,@Kromzar,@Stormseer,@Invader,@Thrower,@Defender ); -- 16 EAI scripts
