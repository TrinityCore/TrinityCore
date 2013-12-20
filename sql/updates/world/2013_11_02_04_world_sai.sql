--
SET @Mechagnome=29384; -- Captive Mechagnome

-- Update creature template to use SAI
UPDATE `creature_template` SET `ainame`='SmartAI',`scriptname`='' WHERE `entry`=@Mechagnome;
-- Add gossip option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9871;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(9871,0,0,'I\'m not a laborer. I\'m here to free you from servitude in the mines.',1,1,0,0,0,0,NULL);
-- Add conditions for gossip option visibility
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9871;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,9871,0,0,0,9,0,12957,0,0,0,0,0,'','Show gossip only if quest is active');
-- Add Captive Mechagnome text
DELETE FROM `creature_text` WHERE `entry`=@Mechagnome;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@Mechagnome,0,0,'Does not compute. Unit malfunctioning. Directive: shut down.',12,0,0,0,0,0,''),
(@Mechagnome,0,1,'New directive: leave mine and return to Inventor\'s Library.',12,0,0,0,0,0,''),
(@Mechagnome,0,2,'New directive: assist in the defeat of the iron dwarves.',12,0,0,0,0,0,''),
(@Mechagnome,0,3,'Free again? Keeper Mimir\'s work awaits.',12,0,0,0,0,0,''),
(@Mechagnome,0,4,'Thank you, $r. I will join your struggle against the stormforged.',12,0,0,0,0,0,'');
-- Add Captive Mechagnome SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Mechagnome AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Mechagnome,0,0,1,62,0,100,0,9871,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Captive Mechagnome - On Gossip Option Select - Close Gossip'),
(@Mechagnome,0,1,2,61,0,100,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Captive Mechagnome - Link With Previous Event - Remove npcflag 1'),
(@Mechagnome,0,2,3,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Captive Mechagnome - Link With Previous Event - Talk'),
(@Mechagnome,0,3,4,61,0,100,0,0,0,0,0,33,29962,0,0,0,0,0,7,0,0,0,0,0,0,0,'Captive Mechagnome - Link With Previous Event - Give Quest Credit'),
(@Mechagnome,0,4,5,61,0,100,0,0,0,0,0,69,0,0,0,0,0,0,1,0,0,0,7818.4,-86.48,880.63,0,'Captive Mechagnome - Link With Previous Event - Move To Position'),
(@Mechagnome,0,5,0,61,0,100,0,0,0,0,0,41,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Captive Mechagnome - Link With Previous Event - Despawn');
