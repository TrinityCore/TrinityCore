SET @Illidan:=23467;
SET @Morghor:=23139;
SET @Sinestra1:=23283;  
SET @Sinestra2:=23284;
SET @Yarzill:= 23141;
SET @Dragonmaw:=23146;

DELETE FROM `creature_template_addon` WHERE `entry` IN (@Illidan);
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`, `emote`, `auras`) VALUES
(@Illidan,0,4097,0,"37816");

UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry` IN (@Illidan, @Morghor, @Yarzill, @Dragonmaw, 23468);
UPDATE `creature_template` SET `VehicleId`=321 WHERE `entry`=23468;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Illidan, @Morghor, @Yarzill, @Dragonmaw, 23468, @Illidan*100);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Morghor*100, @Morghor*100+1, @Yarzill*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Morghor,0,0,0,19,0,100,0,11108,0,0,0,80,@Morghor*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Mor''ghor - On quest accept (Lord Illidan Stormrage) - ActionList'),
(@Morghor*100,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Mor''ghor - Action List - Remove npcfla'),
(@Morghor*100,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Overlord Mor''ghor - Action List - Talk'),
(@Morghor*100,9,2,0,0,0,100,0,2000,2000,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Mor''ghor - Action List - Set Run OFF'),
(@Morghor*100,9,3,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-5104.410156, 595.296997, 85.680908, 2.368710,'Overlord Mor''ghor - Action List - Go to pos'),
(@Morghor*100,9,4,0,0,0,100,0,9000,9000,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Overlord Mor''ghor - Action List - Talk'),
(@Morghor*100,9,5,0,0,0,100,0,9000,9000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Mor''ghor - Action List - Talk'),
(@Morghor*100,9,6,0,0,0,100,0,5000,5000,0,0,12,@Illidan,8,0,0,0,0,8,0,0,0,-5107.830078, 602.583984, 85.239304, 4.925980,'Overlord Mor''ghor - Action List - Summon'),
(@Morghor*100,9,7,0,0,0,100,0,3000,3000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Mor''ghor - Action List - Talk'),
(@Morghor*100,9,8,0,0,0,100,0,1000,1000,0,0,11,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Mor''ghor - Action List - Cast emote kneel'),
(@Morghor*100,9,9,0,0,0,100,0,2000,2000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Mor''ghor - Action List - Talk'),
(@Morghor*100,9,10,0,0,0,100,0,6000,6000,0,0,1,0,0,0,0,0,0,19,@Illidan,15,0,0,0,0,0,'Overlord Mor''ghor - Action List - Illidan Talk'),
(@Morghor*100,9,11,0,0,0,100,0,0,0,0,0,5,1,0,0,0,0,0,19,@Illidan,15,0,0,0,0,0,'Overlord Mor''ghor - Action List - Illidan Play emote talk'),
(@Morghor*100,9,12,0,0,0,100,0,5000,5000,0,0,1,5,0,0,0,0,0,7,0,0,0,0,0,0,0,'Overlord Mor''ghor - Action List - Talk'),
(@Morghor*100,9,13,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,19,@Illidan,15,0,0,0,0,0,'Overlord Mor''ghor - Action List - Illidan Talk'),
(@Morghor*100,9,14,0,0,0,100,0,0,0,0,0,5,1,0,0,0,0,0,19,@Illidan,15,0,0,0,0,0,'Overlord Mor''ghor - Action List - Illidan Play emote talk'),
(@Morghor*100,9,15,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,19,@Illidan,15,0,0,0,0,0,'Overlord Mor''ghor - Action List - Illidan Talk'),
(@Morghor*100,9,16,0,0,0,100,0,0,0,0,0,5,1,0,0,0,0,0,19,@Illidan,15,0,0,0,0,0,'Overlord Mor''ghor - Action List - Illidan Play emote talk'),
(@Morghor*100,9,17,0,0,0,100,0,5000,5000,0,0,1,3,0,0,0,0,0,19,@Illidan,15,0,0,0,0,0,'Overlord Mor''ghor - Action List - Illidan Talk'),
(@Morghor*100,9,18,0,0,0,100,0,0,0,0,0,5,1,0,0,0,0,0,19,@Illidan,15,0,0,0,0,0,'Overlord Mor''ghor - Action List - Illidan Play emote talk'),
(@Morghor*100,9,19,0,0,0,100,0,5000,5000,0,0,1,4,0,0,0,0,0,19,@Illidan,15,0,0,0,0,0,'Overlord Mor''ghor - Action List - Illidan Talk'),
(@Morghor*100,9,20,0,0,0,100,0,0,0,0,0,5,1,0,0,0,0,0,19,@Illidan,15,0,0,0,0,0,'Overlord Mor''ghor - Action List - Illidan Play emote talk'),
(@Morghor*100,9,21,0,0,0,100,0,5000,5000,0,0,1,5,0,0,0,0,0,19,@Illidan,15,0,0,0,0,0,'Overlord Mor''ghor - Action List - Illidan Talk'),
(@Morghor*100,9,22,0,0,0,100,0,0,0,0,0,5,1,0,0,0,0,0,19,@Illidan,15,0,0,0,0,0,'Overlord Mor''ghor - Action List - Illidan Play emote talk'),
(@Morghor*100,9,23,0,0,0,100,0,2000,2000,0,0,85,41528,0,0,0,0,0,7,0,0,0,0,0,0,0,'Overlord Mor''ghor - Action List - InvokerCast'),
(@Morghor*100,9,24,0,0,0,100,0,0,0,0,0,28,42016,0,0,0,0,0,7,0,0,0,0,0,0,0,'Overlord Mor''ghor - Action List - Remove aura'),
(@Morghor*100,9,25,0,0,0,100,0,5000,5000,0,0,1,6,0,0,0,0,0,19,@Illidan,15,0,0,0,0,0,'Overlord Mor''ghor - Action List - Illidan Talk'),
(@Morghor*100,9,26,0,0,0,100,0,0,0,0,0,5,53,0,0,0,0,0,19,@Illidan,15,0,0,0,0,0,'Overlord Mor''ghor - Action List - Illidan Play emote rowar'),
(@Morghor*100,9,27,0,0,0,100,0,5000,5000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Mor''ghor - Action List - Talk'),
(@Morghor*100,9,28,0,0,0,100,0,0,0,0,0,5,254,0,0,0,0,0,19,@Illidan,15,0,0,0,0,0,'Overlord Mor''ghor - Action List - Emote land'), 
(@Morghor*100,9,29,0,0,0,100,0,1000,1000,0,0,41,0,0,0,0,0,0,19,@Illidan,15,0,0,0,0,0,'Overlord Mor''ghor - Action List - Despawn'), 
(@Morghor*100,9,30,0,0,0,100,0,1000,1000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Mor''ghor - Action List - remove emote aura'),
(@Morghor*100,9,31,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Overlord Mor''ghor - Action List - Set orientation'),
(@Morghor*100,9,32,0,0,0,100,0,1000,1000,0,0,1,7,0,0,0,0,0,7,0,0,0,0,0,0,0,'Overlord Mor''ghor - Action List - Talk'),
(@Morghor*100,9,33,0,0,0,100,0,0,0,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Mor''ghor - Action List - Play emote'),
(@Morghor*100,9,34,0,0,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Overlord Mor''ghor - Action List - Store target'),
(@Morghor*100,9,35,0,0,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,@Yarzill,30,0,0,0,0,0,'Overlord Mor''ghor - Action List - Send target'),
(@Morghor*100,9,36,0,0,0,100,0,5000,5000,0,0,45,0,1,0,0,0,0,19,@Yarzill,30,0,0,0,0,0,'Overlord Mor''ghor - Action List - set Data'),
(@Morghor*100,9,37,0,0,0,100,0,2000,2000,0,0,12,23468,8,0,0,0,0,8,0,0,0,-5126.729004, 604.291626, 84.271423, 2.468847,'Overlord Mor''ghor - Action List - Summon'),
(@Morghor*100,9,38,0,0,0,100,0,1000,1000,0,0,85,46598,0,0,0,0,0,19,23468,40,0,0,0,0,0,'Overlord Mor''ghor - Action List - Cast to ride'),
(@Morghor*100,9,39,0,0,0,100,0,3000,3000,0,0,85,41540,0,0,0,0,0,7,0,0,0,0,0,0,0,'Overlord Mor''ghor - Action List - Cast taxi'),
(@Morghor*100,9,40,0,0,0,100,0,10000,10000,0,0,69,0,0,0,0,0,0,8,0,0,0,-5085.000000, 578.656982, 86.648300, 2.368710,'Overlord Mor''ghor - Action List - Go to pos'),
(@Morghor*100,9,41,0,0,0,100,0,9000,9000,0,0,66,0,0,0,0,0,0,8,0,0,0,-5085.000000, 578.656982, 86.648300, 2.368710,'Overlord Mor''ghor - Action List - Set orientation'),
(@Morghor*100,9,42,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Mor''ghor - Action List - Add npcfla'),
(@Yarzill,0,0,0,38,0,100,0,0,1,0,0,80,@Yarzill*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Yarzill - On Data set (Lord Illidan Stormrage) - ActionList'),
(@Yarzill*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,'Yarzill - Action List - Talk'), 
(@Yarzill*100,9,1,0,0,0,100,0,0,0,0,0,28,41528,0,0,0,0,0,12,1,0,0,0,0,0,0,'Yarzill - Action List - remove aura'),
(@Yarzill*100,9,2,0,0,0,100,0,0,0,0,0,28,41519,0,0,0,0,0,12,1,0,0,0,0,0,0,'Yarzill - Action List - remove aura'),
(@Yarzill*100,9,4,0,0,0,100,0,0,0,0,0,15,11108,0,0,0,0,0,12,1,0,0,0,0,0,0,'Yarzill - Action List - AREAEXPLOREDOREVENTHAPPENS'),
(@Illidan,0,0,0,54,0,100,0,0,0,0,0,80,@Illidan*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Illidan - Just summoned - Action List'),
(@Illidan*100,9,0,0,0,0,100,0,300,300,0,0,11,39990,0,0,0,0,0,1,0,0,0,0,0,0,0,'Illidan - Action List - cast'),
(@Illidan*100,9,1,0,0,0,100,0,0,0,0,0,50,185520,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Illidan - Action List - Summon Fel Fire (GO)'),
(23468,0,0,0,27,0,100,0,0,0,0,0,11,50630,0,0,0,0,0,1,0,0,0,0,0,0,0,'Yarzill Dragon - passenger boarded - Eject all passengers'),
(23468,0,1,0,28,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Yarzill Dragon- passenger removed - despawn');

DELETE FROM `creature_text` WHERE `entry`IN (@Illidan, @Morghor, @Sinestra2, @Yarzill, @Dragonmaw);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextID`) VALUES
(@Yarzill,0,0,'You will not harm the $g boy:girl;, Mor''ghor! Quickly, $n, climb on my back!',12,0,100,0,0,0, 'Yarzill', 21825),
(@Dragonmaw,0,0,'Who... Who is you?? What you want?',12,0,100,0,0,0, 'Dragonmaw Enforcer', 21300),
(@Dragonmaw,1,0,'Yes... Yes we move now... Please no hurt us...',12,0,100,0,0,0, 'Dragonmaw Enforcer', 21302),
(@Morghor,0,0,'Come, $n. Lord Stormrage awaits.',12,0,100,0,0,0, 'Overlord Mor''ghor', 21798),
(@Morghor,1,0,'Warriors of Dragonmaw, gather ''round! One among you has attained the rank of highlord! Bow your heads in reverence! Show your respect and allegiance to Highlord $n!',14,0,100,0,0,0, 'Overlord Mor''ghor', 21799),
(@Morghor,2,0,'Lord Illidan will be here shortly.',12,0,100,0,0,0, 'Overlord Mor''ghor', 21800),
(@Morghor,3,0,'All hail Lord Illidan!',14,0,100,0,0,0, 'Overlord Mor''ghor', 21802),
(@Morghor,4,0,'Lord Illidan, this is the Dragonmaw that I, and others, have told you about. He will lead us to victory!',12,0,100,0,0,0, 'Overlord Mor''ghor', 21803),
(@Morghor,5,0,'But... My lord, I do not understand. $n... He is the orc that has...',12,0,100,0,0,0, 'Overlord Mor''ghor', 21805),
(@Morghor,6,0,'It will be done, my lord.',12,0,100,0,0,0, 'Overlord Mor''ghor', 21823),
(@Morghor,7,0,'So you thought to make a fool of Mor''ghor, eh? Before you are delivered to Lord Illidan, you will feel pain that you could not know to exist. I will take pleasure in exacting my own vengeance.',12,0,100,0,0,0, 'Overlord Mor''ghor', 21824),

(@Morghor,8,0,'I will not drag this out any further than it needs, Lady Sinestra. You have bent my ear, now tell me what it is that you want from Dragonmaw.',12,0,100,0,0,0, 'Overlord Mor''ghor', 21307),
(@Morghor,9,0,'The... The master? He lives?',12,0,100,0,0,0, 'Overlord Mor''ghor', 21310),
(@Morghor,10,0,'%s stammers.',16,0,100,0,0,0, 'Overlord Mor''ghor', 21313),
(@Morghor,11,0,'Ye... Yes, yes... Of course. We need only the crystals and ore from this place. There is... We will need mounts.',12,0,100,0,0,0, 'Overlord Mor''ghor', 21314),

(@Illidan,0,0,'What is the meaning of this, Mor''ghor?',12,0,100,0,0,0, 'Illidan', 21804),
(@Illidan,1,0,'SILENCE!',12,0,100,0,0,0, 'Illidan', 21807),
(@Illidan,2,0,'Blathering idiot. You incomprehensibly incompetent buffoon...',12,0,100,0,0,0, 'Illidan', 21808),
(@Illidan,3,0,'THIS is your hero?',12,0,100,0,0,0, 'Illidan', 21809),
(@Illidan,4,0,'You have been deceived, imbecile.',12,0,100,0,0,0, 'Illidan', 21810),
(@Illidan,5,0,'This... whole... operation... HAS BEEN COMPROMISED!',12,0,100,0,0,0, 'Illidan', 21811),
(@Illidan,6,0,'I expect to see this insect''s carcass in pieces in my lair within the hour. Fail and you will suffer a fate so much worse than death.',12,0,100,0,0,0, 'Illidan', 21812),

(@Sinestra2,0,0,'Step aside lest I add you as another adornment to my armor. Your leader and I have matters to attend...',12,0,100,0,0,0, 'Sinestra', 21301),
(@Sinestra2,1,0,'$s smiles.',16,0,100,0,0,0, 'Sinestra', 21303),
(@Sinestra2,2,0,'I thought you would see it my way...',12,0,100,0,0,0, 'Sinestra', 21304),
(@Sinestra2,3,0,'Overlord Mor''ghor, I presume... A pleasure to finally make your acquaintance.',12,0,100,0,0,0, 'Sinestra', 21305),
(@Sinestra2,4,0,'I am Lady Sinestra.',12,0,100,0,0,0, 'Sinestra', 21306),
(@Sinestra2,5,0,'You have no doubt heard about Nefarian''s failures on Azeroth... While he has fallen, the experiment continues. My master... He continues the work that his progeny began.',12,0,100,0,0,0, 'Sinestra', 21308),
(@Sinestra2,6,0,'$s nods.',16,0,100,0,0,0, 'Sinestra', 21309),
(@Sinestra2,7,0,'You were once a chief lieutenant, Mor''ghor. Your work in Grim Batol is not easily forgotten.',12,0,100,0,0,0, 'Sinestra', 21311),
(@Sinestra2,8,0,'Now... We need the eggs that you recovered. The Netherwing eggs. They are, after all, a product of the master. We will pay whatever price that you ask.',12,0,100,0,0,0, 'Sinestra', 21312),
(@Sinestra2,9,0,'The master will be most pleased with this news. The Black Dragonflight will provide you all that you ask. You will be allowed to ride upon the backs of our drakes as needed. ',12,0,100,0,0,0, 'Sinestra', 21315),
(@Sinestra2,10,0,'I thank you for your graciousness, Mor''ghor. I must now take my leave.',12,0,100,0,0,0, 'Sinestra', 21316);
