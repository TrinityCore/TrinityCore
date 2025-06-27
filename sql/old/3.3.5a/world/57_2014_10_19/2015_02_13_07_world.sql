--
SET @Zuluhed                   := 11980;
SET @Portal                    := 22336;
SET @Arcubus                   := 22338;
SET @Infusion                  := 38853;
SET @SummonPortal              := 38876;
SET @Rain                      := 19717;
SET @SummonArcubus             := 38877;

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (@Zuluhed, @Portal, @Arcubus);

DELETE FROM `creature_text` WHERE `entry`=@Zuluhed;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES 
(@Zuluhed,0,0,'Indeed, the time has come to end this charade.',14,0,100,0,0,0,'Zuluhed the Whacked', 20128),
(@Zuluhed,1,0,'Destroy them! Destroy them all!', 14,0,100,0,0,0,'Zuluhed the Whacked', 20129),
(@Zuluhed,2,0,'Foolish mortals. Did you think that I would not strike you down for your transgressions?', 14,0,100,0,0,0,'Zuluhed the Whacked', 20127),
(@Zuluhed,3,0,'Lord Illidan, bless me with the power of the flight!', 14,0,100,0,0,0,'Zuluhed the Whacked', 20126);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Zuluhed, @Portal, @Arcubus) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Zuluhed*100, @Zuluhed*100+1, @Portal*100)  AND `source_type`=9; 
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@Zuluhed,0,0,0,54,0,100,0,0,0,0,0,80,@Zuluhed*100,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Zuluhed the Whacked - Just Summoned - action list"),
(@Zuluhed*100,9,0,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Zuluhed the Whacked - action list - text"),
(@Zuluhed*100,9,1,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Zuluhed the Whacked - action list - text"),
(@Zuluhed*100,9,2,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Zuluhed the Whacked - action list - text"),
(@Zuluhed,0,1,0,0,0,100,0,12000,12000,12000,12000,11,@Rain,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Zuluhed the Whacked - IC - Cast rain"),
(@Zuluhed,0,2,0,0,0,100,0,30000,30000,60000,60000,11,@SummonPortal,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Zuluhed the Whacked - IC - Summon portal"),
(@Zuluhed,0,3,0,2,0,100,1,0,25,0,0,80,@Zuluhed*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,'Zuluhed the Whacked - On 25% health - ActionList'),
(@Zuluhed*100+1,9,0,0,0,0,100,0,0,0,0,0,11,@Infusion,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zuluhed the Whacked - ActionList - Cast Infusion'),
(@Zuluhed*100+1,9,1,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zuluhed the Whacked - ActionList - Text'),
(@Arcubus,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,10,0,0,0.0,0.0,0.0,0.0,"Zuluhed the Whacked - Just Summoned - Attack player on 10 yards"),
(@Portal,0,0,0,54,0,100,1,0,0,0,0,80,@Portal*100,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Portal - Just Summoned - action list"), 
(@Portal*100,9,0,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Portal - ActionList - SET_ROOT'),
(@Portal*100,9,1,0,0,0,100,0,15000,15000,0,0,11,@SummonArcubus,0,0,0,0,0,1,0,0,0,0,0,0,0,'Portal - ActionList - Cast SummonArcubus');
