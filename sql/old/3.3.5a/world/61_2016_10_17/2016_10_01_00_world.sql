-- 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27206) AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-98539, 27213) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN (27213*100, 98539*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27213,0,0,0,31,0,100,513,48297,0,0,0,80,27213*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Warhorse - spell_hit_target - Action list"),
(27213*100,9,0,0,0,0,100,512,0,0,0,0,11,50630,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Warhorse - Action list - Eject All Passengers"),
(27213*100,9,1,0,0,0,100,512,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Warhorse - Action list - Set run off"),
(27213*100,9,2,0,0,0,100,512,0,0,0,0,29,0,0,0,0,0,0,10,98539,23837,0,0,0,0,0,"Onslaught Warhorse - Action list - Follow"),
(27213*100,9,3,0,0,0,100,512,3000,3000,0,0,45,0,1,0,0,0,0,10,98539,23837,0,0,0,0,0,"Onslaught Warhorse - Action list - set data"),
(27213*100,9,4,0,0,0,100,512,3000,3000,0,0,11,48304,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Warhorse - Action list - cast"),
(27213*100,9,5,0,0,0,100,512,4000,4000,0,0,69,0,0,0,0,0,0,8,0,0,0,3231.088135, -659.988831, 166.621277,1.059199,"Onslaught Warhorse - Action list - move to pos"),
(27213*100,9,6,0,0,0,100,512,13000,13000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Warhorse - Action list - Despawn"),
(27213,0,1,2,28,0,100,512,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Warhorse - Passenger removed - Set faction"),
(27213,0,2,0,61,0,100,512,0,0,0,0,18,131072,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Warhorse - Passenger removed - set pacified"),
(-98539,0,0,0,38,0,100,0,0,1,0,0,11,48298,0,0,0,0,0,19,27213,20,0,0,0,0,0,"ELM General Purpose Bunny - On data set - Cast"),
(27213,0,3,0,1,0,100,0,30000,30000,30000,30000,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Warhorse - ooc - Despawn");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup` IN (4) AND `SourceEntry`=27213;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`, `ConditionTarget`) VALUES
(22,4,27213,0,1,43671,1,0,0,'','event will not trigger if the aura 43671 is missing', 1, 1),
(22,4,27213,0,1,48290,0,0,0,'','event will not trigger if the aura 48290 is missing', 1, 1);

DELETE FROM `vehicle_template_accessory` WHERE `entry`=27213;
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`) VALUES
(27213,27206,0,0, 'Onslaught Warhorse - Onslaught Knight', 8);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=48290;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,48290,0,0,31,1,3,27213,0,0,0,0,'','Only Onslaught Warhorse is a target for Onslaught Riding Crop'),
(17,0,48290,0,0,1,1,43671,0,0,1,0,0,'','Only NOT RIDDEN Onslaught Warhorse is a target for Onslaught Riding Crop'),
(17,0,48290,0,0,23,1,4186,0,0,1,0,0,'','Onslaught Riding Crop cannot be used in area 4186');


DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (27213);
INSERT INTO `npc_spellclick_spells` (npc_entry,spell_id,cast_flags,user_type) VALUES
(27213,43671,0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=27213 AND `SourceEntry` IN (43671);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(18,27213,43671,0,0,31,0,3,0,0,0,0,'','Only npcs can use Onslaught Warhorse spellclick');
