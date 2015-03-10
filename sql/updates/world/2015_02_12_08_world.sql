--
SET @Ameer  :=20482; -- Image of Commander Ameer
SET @SpellSummon:=35679; -- Summons Protectorate. 
SET @Protectorate:=20802; -- Protectorate Demolitionist
SET @Cleave :=30619; -- Protectorate Demolitionist's Cleave
SET @Hamstring  :=31553; -- Protectorate Demolitionist's Hamstring 
SET @Strike :=16856; -- Protectorate Demolitionist's Mortal Striket
SET @Stalker    :=20474; -- Ethereum Nexus-Stalker
SET @Sshadowtouched:=36515; -- Ethereum Nexus-Stalker's Shadowtouched
SET @Sshadowsurge:=36517; -- Ethereum Nexus-Stalker's Shadowsurge

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@Ameer,@Protectorate,@Stalker);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`= @Ameer AND id IN (5,6);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@Protectorate,@Stalker);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@Protectorate*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Ameer,0,5,0,19,0,100,0,10406,0,0,0,85,@SpellSummon,2,0,0,0,0,7,0,0,0,0,0,0,0,'Image of Commander Ameer - On Quest 10406 accepted - Cast Summon Protectorate Demolitionist'),
(@Ameer,0,6,0,20,0,100,0,10406,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Image of Commander Ameer - On Quest 10406 accepted - Cast Summon Protectorate Demolitionist'),
(@Protectorate,0,0,0,54,0,100,0,0,0,0,0,1,0,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Just Summoned - Say 0'),
(@Protectorate,0,1,0,52,0,100,0,0,@Protectorate,0,0,53,0,@Protectorate,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Text Over - Start Wp'),
(@Protectorate,0,2,3,40,0,100,0,3,@Protectorate,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Reached WP 3 - Pause Wp'),
(@Protectorate,0,3,0,61,0,100,0,0,0,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Link Event - Say 1'),
(@Protectorate,0,4,5,40,0,100,0,5,@Protectorate,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Reached WP 5 - Pause Wp'),
(@Protectorate,0,5,0,61,0,100,0,0,0,0,0,1,2,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Link Event - Say 2'),
(@Protectorate,0,6,7,40,0,100,0,7,@Protectorate,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Reached WP 7 - Pause Wp'),
(@Protectorate*100,9,0,0,0,0,100,0,0,0,0,0,1,3,14000,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Script - Say 3'),
(@Protectorate*100,9,1,0,0,0,100,0,500,500,0,0,5,28,0,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Script - Emote Work'),
(@Protectorate*100,9,2,0,0,0,100,0,3500,3500,0,0,12,@Stalker,2,30000,1,0,0,8,0,0,0,3866.837402,2321.753418,113.736206,0.120686,'Protectorate Demolitionist - Script - Summon Nexus-Stalker'),
(@Protectorate*100,9,3,0,0,0,100,0,0,0,0,0,12,@Stalker,2,30000,1,0,0,8,0,0,0,3879.268799,2321.939209,115.065338,3.137270,'Protectorate Demolitionist - Script - Summon Nexus-Stalker'),
(@Protectorate*100,9,4,0,0,0,100,0,6000,6000,0,0,1,4,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Script - Say 4'),
(@Protectorate*100,9,5,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Script - Run'),
(@Protectorate*100,9,6,0,0,0,100,0,0,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Script - Resume WP'),
(@Protectorate*100,9,7,0,0,0,100,0,0,0,0,0,5,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Script - Emote Work'),
(@Protectorate,0,7,0,61,0,100,0,0,0,0,0,80,@Protectorate*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Link - Start Script'),
(@Protectorate,0,8,9,40,0,100,0,8,@Protectorate,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Reached WP 8 - Pause Wp'),
(@Protectorate,0,9,10,61,0,100,0,0,0,0,0,1,5,6000,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Link - Say 5'),
(@Protectorate,0,10,0,61,0,100,0,0,0,0,0,15,10406,0,0,0,0,0,21,15,0,0,0,0,0,0,'Protectorate Demolitionist - Link - Complete Quest'),
(@Protectorate,0,11,12,52,0,100,0,5,@Protectorate,0,0,11,35517,0,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Text Over - cast teleportaion visual'),
(@Protectorate,0,12,0,61,0,100,0,0,0,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - Text Over - despawn'),
(@Protectorate,0,13,0,4,0,100,0,0,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Protectorate Demolitionist - On aggro - talk'),
(@Stalker,0,0,0,54,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ethereum Nexus-Stalker - On respawn - Say 0'),
(@Stalker,0,1,0,0,0,100,0,200,200,5000,5000,11,@Sshadowtouched,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ethereum Nexus-Stalker - IC - Cast Shadowtouched'),
(@Stalker,0,2,0,0,0,100,0,500,2000,10000,12000,11,@Sshadowsurge,0,0,0,0,0,2,0,0,0,0,0,0,0,'Ethereum Nexus-Stalker -IC - Cast Shadowsurge');

DELETE FROM `creature_text` WHERE `entry` IN (@Protectorate,@Stalker, @Ameer);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextID`) VALUES
(@Protectorate,0,0,'Let''s do this... Just keep me covered and I''ll deliver the package.',12,0,100,0,0,0,'Protectorate Demolitionist - Comienza escort', 18432),
(@Protectorate,1,0,'By the second sun of K''aresh, look at this place! I can only imagine what Salhadaar is planning. Come on, let''s keep going.',12,0,100,0,0,0,'Protectorate Demolitionist - Waypoint 1', 18433),
(@Protectorate,2,0,'Look there, fleshling! Salhadaar''s conduits! He''s keeping well fed...',12,0,100,0,0,0,'Protectorate Demolitionist - Waypoint 4', 18435),
(@Protectorate,3,0,'Alright, keep me protected while I plant this disruptor. This shouldn''t take very long..',12,0,100,0,0,0,'Protectorate Demolitionist - Waypoint 6', 18436),
(@Protectorate,4,0,'Done! Back up! Back up!',12,0,100,0,0,0,'Protectorate Demolitionist - Disruptor', 18437),
(@Protectorate,5,0,'Looks like my work here is done. Report to the holo-image of Ameer over at the transporter.',12,0,100,0,0,0,'Protectorate Demolitionist - Waypoint 7', 18442),
(@Protectorate,6,0,'I''m under attack! I repeat, I am under attack!',12,0,100,0,0,0,'Protectorate Demolitionist - Being attacked', 18439),
(@Protectorate,6,1,'Keep these things off me!',12,0,100,0,0,0,'Protectorate Demolitionist - Being attacked', 18438),
(@Stalker,0,0,'Protect the conduit! Stop the intruders!',12,0,100,0,0,0,'Ethereum Nexus-Stalker - Protect Conduct',18441),
(@Ameer,0,0,'Hostiles detected. Ending transmission.',12,0,100,15,0,0,'Image of Commander Ameer - On aggro', 18190),
(@Ameer,1,0,'Protectorate transmission complete.',12,0,100,0,0,0,'Ameer - Quest rewarded',18191);

DELETE FROM `waypoints` WHERE `entry`=@Protectorate;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@Protectorate,1,4006.368652,2323.582520,111.407501,'Protectorate Demolitionist'),
(@Protectorate,2,3946.502441,2329.601074,113.647179,'Protectorate Demolitionist'),
(@Protectorate,3,3934.442383,2333.215088,110.971733,'Protectorate Demolitionist'),
(@Protectorate,4,3912.811035,2339.968018,113.876434,'Protectorate Demolitionist'),
(@Protectorate,5,3887.416748,2408.539063,113.081406,'Protectorate Demolitionist'),
(@Protectorate,6,3863.596191,2348.160645,115.446754,'Protectorate Demolitionist'),
(@Protectorate,7,3872.944580,2321.384766,114.501541,'Protectorate Demolitionist'),
(@Protectorate,8,3859.826416,2360.402588,114.603340,'Protectorate Demolitionist');
