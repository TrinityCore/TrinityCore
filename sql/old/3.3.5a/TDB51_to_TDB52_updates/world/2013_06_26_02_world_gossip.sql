-- Add Any Missing Gossip Option for Injured Goblin Miner
DELETE FROM `gossip_menu_option` WHERE menu_id IN (9859);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(9859,0,0,"I am ready, lets get you out of here.",1,1,0,0,0,0,'');

-- Add Gossip option condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (15) AND `SourceGroup` IN (9859);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9859,0,0,28,12832,0,0,1,0,'','Injured Goblin Miner - Show gossip option only if quest "Bitter Departure" is not complete');
