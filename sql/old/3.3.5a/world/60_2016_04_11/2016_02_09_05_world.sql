-- 
-- DB/Quest: Absholutely... Thish Will Work (11330)
SET @Prisoner   :=24284; -- Dragonflayer Vrykul Prisoner
SET @PeppysMix  :=43386; -- Spell Peppy's Special Mix
SET @WGDefender :=23842; -- Westguard Defender
SET @WGDguid1   :=99009; -- Westguard Defender Guid 1
SET @WGDguid2   :=99010; -- Westguard Defender Guid 2
SET @WGDguid3   :=99008; -- Westguard Defender Guid 3
SET @WGDguid4   :=99013; -- Westguard Defender Guid 4
SET @WGOfficer  :=23844; -- Westguard Officer
SET @WGOguid    :=99195; -- Westguard Officer Guid
SET @HumoVerde  :=18951; -- Spirit Particles (green) / humo verde
SET @CuerpoVerde:=39168; -- Vertex Color Green / efecto verde
SET @MocoVerde  :=28989; -- Plague Slime (Green) / Morph de Moco-Ooze    
SET @Crazed     :=48147; -- Crazed (enrage) - Only Defender
SET @Defensive  :=7164; -- Defensive stance
SET @ImpBlocking:=3639; --  improved blocking
SET @ShieldBash :=11972; -- Shield Bash
SET @Shoot      :=6660; -- Shoot
SET @DemorlShout:=16244; -- Demoralizing Shout - Only Officer
     
UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry` IN (@Prisoner,@WGDefender,@WGOfficer);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Prisoner,@WGDefender,@WGOfficer) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Prisoner*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Prisoner,0,0,0,8,0,100,0,@PeppysMix,0,0,0,80,@Prisoner*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - On Spell Hit (Olakin''s Torch) - Run Script'),
(@Prisoner*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script - Say'),
(@Prisoner*100,9,1,0,0,0,100,0,3000,3000,0,0,11,@HumoVerde,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script - Cast Spirit Particles (green)'),
(@Prisoner*100,9,2,0,0,0,100,0,1000,1000,0,0,45,1,1,0,0,0,0,10,@WGDguid1,@WGDefender,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script - Set Data to Westguard Defender'),
(@Prisoner*100,9,3,0,0,0,100,0,3000,3000,0,0,45,1,1,0,0,0,0,10,@WGDguid3,@WGDefender,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script - Set Data to Westguard Defender'),
(@Prisoner*100,9,4,0,0,0,100,0,2000,2000,0,0,11,@CuerpoVerde,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script - Vertex Color Green'),
(@Prisoner*100,9,5,0,0,0,100,0,2000,2000,0,0,45,1,1,0,0,0,0,10,@WGDguid2,@WGDefender,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script - Set Data to Westguard Defender'),
(@Prisoner*100,9,6,0,0,0,100,0,3000,3000,0,0,45,1,1,0,0,0,0,10,@WGDguid4,@WGDefender,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script - Set Data to Westguard Defender'),
(@Prisoner*100,9,7,0,0,0,100,0,2000,2000,0,0,11,@MocoVerde,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script - Plague Slime (Green)'),
(@Prisoner*100,9,8,0,0,0,100,0,3000,3000,0,0,45,1,1,0,0,0,0,10,@WGOguid,@WGOfficer,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script - Set Data to Westguard Defender'),
(@Prisoner*100,9,9,0,0,0,100,0,2000,2000,0,0,33,@Prisoner,0,0,0,0,0,7,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script - Call Killedmonster'),
(@Prisoner*100,9,10,0,0,0,100,0,20000,20000,0,0,28,@HumoVerde,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script - Remove Spirit Particles'),
(@Prisoner*100,9,11,0,0,0,100,0,0,0,0,0,28,@CuerpoVerde,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script - Remove Vertex Color Green'),
(@Prisoner*100,9,12,0,0,0,100,0,0,0,0,0,28,@MocoVerde,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script - Remove Plage Slime'),
(@WGDefender,0,0,0,38,0,100,0,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Westguard Defender - On Data set - Say'),
(@WGDefender,0,1,0,0,0,100,0,5000,15000,20000,40000,11,@Crazed,0,0,0,0,0,1,0,0,0,0,0,0,0,'Westguard Defender - IC - Cast Crazed'),
(@WGDefender,0,2,0,0,0,100,1,500,500,0,0,11,@Defensive,0,0,0,0,0,1,0,0,0,0,0,0,0,'Westguard Defender - IC - Cast Defensive'),
(@WGDefender,0,3,0,0,0,100,0,1000,3000,10400,10400,11,@ImpBlocking,0,0,0,0,0,1,0,0,0,0,0,0,0,'Westguard Defender - IC - Cast Improved Blocking'),
(@WGDefender,0,4,0,0,0,100,0,2000,5000,10000,21000,11,@ShieldBash,0,0,0,0,0,2,0,0,0,0,0,0,0,'Westguard Defender - IC - Cast ShieldBash'),
(@WGDefender,0,5,0,0,0,100,0,0,5000,1000,6000,11,@Shoot,0,0,0,0,0,2,0,0,0,0,0,0,0,'Westguard Defender - IC - Cast Shoot'),
(@WGOfficer,0,0,0,38,0,100,0,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Westguard Officer - On Data set - Say'),
(@WGOfficer,0,1,0,0,0,100,0,10000,15000,20000,30000,11,@DemorlShout,0,0,0,0,0,1,0,0,0,0,0,0,0,'Westguard Officer - IC - Cast Demoralizing Shout'),
(@WGOfficer,0,2,0,0,0,100,1,500,500,0,0,11,@Defensive,0,0,0,0,0,1,0,0,0,0,0,0,0,'Westguard Officer - IC - Cast Defensive'),
(@WGOfficer,0,3,0,0,0,100,0,1000,3000,10400,10400,11,@ImpBlocking,0,0,0,0,0,1,0,0,0,0,0,0,0,'Westguard Officer - IC - Cast Improved Blocking'),
(@WGOfficer,0,4,0,0,0,100,0,2000,5000,8000,21000,11,@ShieldBash,0,0,0,0,0,2,0,0,0,0,0,0,0,'Westguard Officer - IC - Cast ShieldBash'),
(@WGOfficer,0,5,0,0,0,100,0,0,5000,1000,6000,11,@Shoot,0,0,0,0,0,2,0,0,0,0,0,0,0,'Westguard Officer - IC - Cast Shoot');
 
DELETE FROM `creature_text` WHERE `entry` IN (@Prisoner,@WGDefender,@WGOfficer);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@Prisoner,0,0,'The vrykul clutches at his throat as he begins to gag and thrash about.',16,0,100,1,0,0,'Dragonflayer Vrykul Prisoner', 23087),
(@WGOfficer,0,0,'Is he okay?',12,0,100,1,0,0,'Westguard Officer - Say', 23105),
(@WGDefender,0,0,'Yikes.',12,0,100,1,0,0,'Westguard Defender - Say', 23104),
(@WGDefender,0,1,'Captain''s not gonna like this.',12,0,100,1,0,0,'Westguard Defender - Say', 23106),
(@WGDefender,0,2,'What kind of sicko are you?',12,0,100,1,0,0,'Westguard Defender - Say', 23095),
(@WGDefender,0,3,'Heh, cool!',12,0,100,1,0,0,'Westguard Defender - Say', 23094),
(@WGDefender,0,4,'That''s the new Forsaken plague?',12,0,100,1,0,0,'Westguard Defender - Say', 23098),
(@WGDefender,0,5,'Oh, sick!',12,0,100,1,0,0,'Westguard Defender - Say', 23091);
