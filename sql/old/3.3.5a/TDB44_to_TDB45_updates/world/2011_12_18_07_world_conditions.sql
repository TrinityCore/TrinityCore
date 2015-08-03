-- Fix condition for Bom'bay's npc_text, gossip_menu and gossip_menu_option
-- Player must to complete quest 826 'Zalazane' to see gossip_menu_option
DELETE FROM `gossip_menu` WHERE `entry`=3062 AND `text_id` IN (3794,3795);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(3062,3794), -- text before to complete quest 826
(3062,3795); -- text after to complete quest 826
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=3062;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,3062,3794,0,14,826,0,0,0,'', "Bom'bay - show text 3794 if player does not have quest Zalazane"),
(14,3062,3795,0,8,826,0,0,0,'', "Bom'bay - show text 3795 if player has quest Zalazane rewarded"),
(15,3062,0,0,8,826,0,0,0,'', "Bom'bay - show gossip option 0 if player has quest Zalazane rewarded"),
(15,3062,1,0,8,826,0,0,0,'', "Bom'bay - show gossip option 1 if player has quest Zalazane rewarded"),
(15,3062,2,0,8,826,0,0,0,'', "Bom'bay - show gossip option 2 if player has quest Zalazane rewarded"),
(15,3062,3,0,8,826,0,0,0,'', "Bom'bay - show gossip option 3 if player has quest Zalazane rewarded"),
(15,3062,4,0,8,826,0,0,0,'', "Bom'bay - show gossip option 4 if player has quest Zalazane rewarded"),
(15,3062,5,0,8,826,0,0,0,'', "Bom'bay - show gossip option 5 if player has quest Zalazane rewarded"),
(15,3062,6,0,8,826,0,0,0,'', "Bom'bay - show gossip option 6 if player has quest Zalazane rewarded");
