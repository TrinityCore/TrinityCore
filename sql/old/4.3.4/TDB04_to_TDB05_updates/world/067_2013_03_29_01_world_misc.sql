SET @NPC_ELM_BUNNY := 23837;
SET @NPC_HARKOA := 28401;
SET @NPC_KHUFU := 28479;
SET @NPC_AKILZON := 29021;
SET @NPC_HALAZZI := 29022;
SET @NPC_JANALAI := 29023;
SET @NPC_NALORAKK := 29024;

DELETE FROM `creature_text` WHERE `entry`=@NPC_HARKOA AND `groupid`=1;
DELETE FROM `creature_text` WHERE `entry` IN (@NPC_AKILZON,@NPC_HALAZZI,@NPC_JANALAI,@NPC_NALORAKK);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_HARKOA,1,0,'No, not Akali too!',15,0,100,0,0,0,'Har''koa'),
(@NPC_AKILZON,0,0,'And yet we see only doom in your future. It is your destiny that you do this, $N, but we fear that the prophet is too powerful for you and your friends. Still, you must try.',12,0,100,0,0,12196,'Akil''zon'),
(@NPC_HALAZZI,0,0,'Once more we hear your call, Khufu. We have wisdom for you and $N. You face great peril and must act swiftly or you all and Har''koa will die.',12,0,100,0,0,643,'Halazzi'),
(@NPC_JANALAI,0,0,'The gusty essence of deceased Quetz''lun''s wardens must be gathered to draw him near. To Har''koa must both of these rarities be delivered.',12,0,100,0,0,9919,'Jana''lai'),
(@NPC_NALORAKK,0,0,'The unblemished heart of the guardian must be secured to show defiance and strength. Jealous Zim''Rhuk keeps those who harbor it.',12,0,100,0,0,473,'Nalorakk');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (52934,52935,52936,52937);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,52934,0,0,31,0,3,@NPC_ELM_BUNNY,0,0,0,'','Spell Rampage: Summon Akil''zon targets ELM General Purpose Bunny'),
(13,1,52934,0,0,29,0,28527,10,0,1,0,'','Spell Rampage: Summon Akil''zon target needs to be 35y from Chronicler To''kini'),
(13,1,52934,0,0,29,0,28527,15,0,1,0,'','Spell Rampage: Summon Akil''zon target needs to be 35y from Chronicler To''kini'),
(13,1,52934,0,0,29,0,28527,30,0,1,0,'','Spell Rampage: Summon Akil''zon target needs to be 35y from Chronicler To''kini'),
(13,1,52934,0,0,29,0,28527,35,0,0,0,'','Spell Rampage: Summon Akil''zon target needs to be 35y from Chronicler To''kini'),
(13,1,52935,0,0,31,0,3,@NPC_ELM_BUNNY,0,0,0,'','Spell Rampage: Summon Akil''zon targets ELM General Purpose Bunny'),
(13,1,52935,0,0,29,0,28527,10,0,0,0,'','Spell Rampage: Summon Akil''zon target needs to be 10y from Chronicler To''kini'),
(13,1,52936,0,0,31,0,3,@NPC_ELM_BUNNY,0,0,0,'','Spell Rampage: Summon Akil''zon targets ELM General Purpose Bunny'),
(13,1,52936,0,0,29,0,28527,10,0,1,0,'','Spell Rampage: Summon Akil''zon target needs to be 15y from Chronicler To''kini'),
(13,1,52936,0,0,29,0,28527,15,0,0,0,'','Spell Rampage: Summon Akil''zon target needs to be 15y from Chronicler To''kini'),
(13,1,52937,0,0,31,0,3,@NPC_ELM_BUNNY,0,0,0,'','Spell Rampage: Summon Akil''zon targets ELM General Purpose Bunny'),
(13,1,52937,0,0,29,0,28527,10,0,1,0,'','Spell Rampage: Summon Akil''zon target needs to be 30y from Chronicler To''kini'),
(13,1,52937,0,0,29,0,28527,15,0,1,0,'','Spell Rampage: Summon Akil''zon target needs to be 30y from Chronicler To''kini'),
(13,1,52937,0,0,29,0,28527,30,0,0,0,'','Spell Rampage: Summon Akil''zon target needs to be 30y from Chronicler To''kini');

DELETE FROM `spell_scripts` WHERE `id`=52933;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(52933,0,0,15,52934,0,0,0,0,0,0),
(52933,0,0,15,52935,0,0,0,0,0,0),
(52933,0,0,15,52936,0,0,0,0,0,0),
(52933,0,0,15,52937,0,0,0,0,0,0);

UPDATE `creature_model_info` SET `bounding_radius`=0.93 WHERE `modelid`=21793;
UPDATE `creature_model_info` SET `bounding_radius`=1.833, `combat_reach`=4.5 WHERE `modelid`=21830;
UPDATE `creature_model_info` SET `bounding_radius`=0.525, `combat_reach`=2.625 WHERE `modelid`=21831;
UPDATE `creature_model_info` SET `bounding_radius`=0.775, `combat_reach`=5 WHERE `modelid`=22256;

DELETE FROM `creature_template_addon` WHERE `entry`=29021;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`) VALUES
(29021,33554432);

UPDATE `creature_template` SET `minlevel`=83, `maxlevel`=83, `faction_A`=1610, `faction_H`=1610, `unit_flags`=512|256, `AIName`='SmartAI' WHERE `entry` IN (@NPC_AKILZON,@NPC_HALAZZI,@NPC_JANALAI,@NPC_NALORAKK);

DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC_HARKOA AND `source_type`=0 AND `id`=16;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC_KHUFU AND `source_type`=0 AND `id` IN (3,4,5);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_AKILZON,@NPC_HALAZZI,@NPC_JANALAI,@NPC_NALORAKK) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC_HALAZZI*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_HARKOA,0,16,15,38,0,100,0,0,2,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Har''koa - On data 0 2 set - Say line'),

(@NPC_KHUFU,0,3,4,20,0,100,0,12721,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Khufu - On quest rewarded - Store targetlist'),
(@NPC_KHUFU,0,4,5,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,@NPC_HARKOA,100,0,0,0,0,0, 'Khufu - On quest rewarded - Send targetlist to Har''koa'),
(@NPC_KHUFU,0,5,0,61,0,100,0,0,0,0,0,45,0,2,0,0,0,0,19,@NPC_HARKOA,100,0,0,0,0,0, 'Khufu - On quest rewarded - Set data 0 2 Har''koa'),

(@NPC_AKILZON,0,0,0,54,0,100,0,0,0,0,0,11,35426,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akil''zon - Just summoned - Spellcast Arcane Explosion Visual'),
(@NPC_AKILZON,0,1,0,38,0,100,0,0,1,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0, 'Akil''zon - On data 0 1 set - Say line'),
(@NPC_AKILZON,0,2,0,38,0,100,0,0,2,0,0,41,800,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Akil''zon - On data 0 2 set - Despawn'),

(@NPC_HALAZZI,0,0,1,54,0,100,0,0,0,0,0,11,35426,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Halazzi - Just summoned - Spellcast Arcane Explosion Visual'),
(@NPC_HALAZZI,0,1,0,61,0,100,0,0,0,0,0,80,@NPC_HALAZZI*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Halazzi - Just summoned - Run script'),

(@NPC_JANALAI,0,0,0,54,0,100,0,0,0,0,0,11,35426,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Jana''lai - Just summoned - Spellcast Arcane Explosion Visual'),
(@NPC_JANALAI,0,1,0,38,0,100,0,0,1,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0, 'Jana''lai - On data 0 1 set - Say line'),
(@NPC_JANALAI,0,2,0,38,0,100,0,0,2,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Jana''lai - On data 0 2 set - Despawn'),

(@NPC_NALORAKK,0,0,0,54,0,100,0,0,0,0,0,11,35426,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Nalorakk - Just summoned - Spellcast Arcane Explosion Visual'),
(@NPC_NALORAKK,0,1,0,38,0,100,0,0,1,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0, 'Nalorakk - On data 0 1 set - Say line'),
(@NPC_NALORAKK,0,2,0,38,0,100,0,0,2,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Nalorakk - On data 0 2 set - Despawn'),

(@NPC_HALAZZI*100,9,0,0,0,0,100,0,3300,3300,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0, 'Halazzi script - Say line'),
(@NPC_HALAZZI*100,9,1,0,0,0,100,0,5200,5200,0,0,45,0,1,0,0,0,0,19,@NPC_NALORAKK,20,0,0,0,0,0, 'Halazzi script - Set data 0 1 Nalorakk'),
(@NPC_HALAZZI*100,9,2,0,0,0,100,0,5600,5600,0,0,45,0,1,0,0,0,0,19,@NPC_JANALAI,20,0,0,0,0,0, 'Halazzi script - Set data 0 1 Jana''lai'),
(@NPC_HALAZZI*100,9,3,0,0,0,100,0,7700,7700,0,0,45,0,1,0,0,0,0,19,@NPC_AKILZON,20,0,0,0,0,0, 'Halazzi script - Set data 0 1 Akil''zon'),
(@NPC_HALAZZI*100,9,4,0,0,0,100,0,8300,8300,0,0,45,0,2,0,0,0,0,19,@NPC_JANALAI,20,0,0,0,0,0, 'Halazzi script - Set data 0 2 Jana''lai'),
(@NPC_HALAZZI*100,9,5,0,0,0,100,0,800,800,0,0,11,42466,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Halazzi script - Spellcast Spirit Visual'),
(@NPC_HALAZZI*100,9,6,0,0,0,100,0,0,0,0,0,45,0,2,0,0,0,0,19,@NPC_AKILZON,20,0,0,0,0,0, 'Halazzi script - Set data 0 2 Akil''zon'),
(@NPC_HALAZZI*100,9,7,0,0,0,100,0,0,0,0,0,45,0,2,0,0,0,0,19,@NPC_NALORAKK,20,0,0,0,0,0, 'Halazzi script - Set data 0 2 Nalorakk'),
(@NPC_HALAZZI*100,9,8,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Halazzi script - Despawn');
