/* NPC entries:
14902 - Jin'rokh the Breaker 	- 6321			- Warriors and paladins
14903 - Al'tabim the All-Seeing - 6322			- Mages, warlocks and priests
14904 - Maywiki of Zuldazar 	- 6341			- Shamans and druids
14905 - Falthir the Sightless 	- @GOSSIP		- Rogues and hunters
 */
 
/* TO DO:
 * There is one missing condition. When you get an upgrade of one of the necklaces, you lose the necklace of the previous quest. (the quest always takes it) But that also makes the conditions meet and it will show the gossip that you lost a necklace.
 * There is currently no way to do this through conditions, so whenever you read this and think it's possible, feel free to!
 */
 
-- Vars
SET @GOSSIP = 21262; -- gossip_menu.entry - need 10
SET @SUB_PALADIN := @GOSSIP+1; -- Menu id for Paladins
SET @SUB_WARRIOR := @GOSSIP+2; -- Menu id for Warriors
SET @SUB_PRIEST := @GOSSIP+3; -- Menu id for Priests
SET @SUB_WARLOCK := @GOSSIP+4; -- Menu id for Warlocks
SET @SUB_MAGE := @GOSSIP+5; -- Menu id for Mages
SET @SUB_SHAMAN := @GOSSIP+6; -- Menu id for Shamans
SET @SUB_DRUID := @GOSSIP+7; -- Menu id for Druids
SET @SUB_ROGUE := @GOSSIP+8; -- Menu id for Rogues
SET @SUB_HUNTER := @GOSSIP+9; -- Menu id for Hunters
 
-- Insert gossip options itself
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+0 AND `text_id`=7556;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(@GOSSIP+0,7556);

-- Set the gossip_menu for Falthir the Sightless
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP+0 WHERE `entry`=14905; -- Falthir the Sightless

-- Actual menu
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (6321,6322,6341,@GOSSIP,@SUB_PALADIN,@SUB_WARRIOR,@SUB_PRIEST,@SUB_WARLOCK,@SUB_MAGE,@SUB_SHAMAN,@SUB_DRUID,@SUB_ROGUE,@SUB_HUNTER);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
-- Main menu for Jin'rokh
(6321,0,0,"Jin\'rokh, I need assistance in recovering a piece of my Freethinker's outfit.",1,3,@SUB_PALADIN,0,0,0,''), -- Main menu option for Paladins
(6321,1,0,"Jin\'rokh, I need assistance in recovering a piece of my Vindicator's outfit.",1,3,@SUB_WARRIOR,0,0,0,''), -- Main menu option for Warriors
-- PALADIN
(@SUB_PALADIN,0,0,"I seem to have misplaced my Zandalar Freethinker's Armguards. Can you help?",1,3,0,0,0,0,''),
(@SUB_PALADIN,1,0,"I seem to have misplaced my Zandalar Freethinker's Belt. Can you help?",1,3,0,0,0,0,''),
(@SUB_PALADIN,2,0,"I seem to have misplaced my Zandalar Freethinker's Breastplate. Can you help?",1,3,0,0,0,0,''),
(@SUB_PALADIN,3,0,"I seem to have misplaced my Hero's Brand. Can you help?",1,3,0,0,0,0,''),
(@SUB_PALADIN,4,0,"I seem to have misplaced my Heathen's Brand. Can you help?",1,3,0,0,0,0,''), -- Green necklace
(@SUB_PALADIN,5,0,"I seem to have misplaced my Heathen's Brand. Can you help?",1,3,0,0,0,0,''), -- Blue (1) necklace
(@SUB_PALADIN,6,0,"I seem to have misplaced my Heathen's Brand. Can you help?",1,3,0,0,0,0,''), -- Blue (2) necklace
-- WARRIOR
(@SUB_WARRIOR,0,0,"I seem to have misplaced my Zandalar Vindicator's Armguards. Can you help?",1,3,0,0,0,0,''),
(@SUB_WARRIOR,1,0,"I seem to have misplaced my Zandalar Vindicator's Belt. Can you help?",1,3,0,0,0,0,''),
(@SUB_WARRIOR,2,0,"I seem to have misplaced my Zandalar Vindicator's Breastplate. Can you help?",1,3,0,0,0,0,''),
(@SUB_WARRIOR,3,0,"I seem to have misplaced my Rage of Mugamba. Can you help?",1,3,0,0,0,0,''),
(@SUB_WARRIOR,4,0,"I seem to have misplaced my Strength of Mugamba. Can you help?",1,3,0,0,0,0,''), -- Green necklace
(@SUB_WARRIOR,5,0,"I seem to have misplaced my Strength of Mugamba. Can you help?",1,3,0,0,0,0,''), -- Blue (1) necklace
(@SUB_WARRIOR,6,0,"I seem to have misplaced my Strength of Mugamba. Can you help?",1,3,0,0,0,0,''), -- Blue (2) necklace
-- Main menu for Al'tabim
(6322,0,0,"Al\'tabim, I need assistance in recovering a piece of my Confessor's outfit.",1,3,@SUB_PRIEST,0,0,0,''), -- Main menu option for Priests
(6322,1,0,"Al\'tabim, I need assistance in recovering a piece of my Demoniac's outfit.",1,3,@SUB_WARLOCK,0,0,0,''), -- Main menu option for Warlocks
(6322,2,0,"Al\'tabim, I need assistance in recovering a piece of my Illusionist's outfit.",1,3,@SUB_MAGE,0,0,0,''), -- Main menu option for Mages
-- PRIEST
(@SUB_PRIEST,0,0,"I seem to have misplaced my Zandalar Confessor's Bindings. Can you help?",1,3,0,0,0,0,''),
(@SUB_PRIEST,1,0,"I seem to have misplaced my Zandalar Confessor's Mantle. Can you help?",1,3,0,0,0,0,''),
(@SUB_PRIEST,2,0,"I seem to have misplaced my Zandalar Confessor's Wraps. Can you help?",1,3,0,0,0,0,''),
(@SUB_PRIEST,3,0,"I seem to have misplaced my All-Seeing Eye of Zuldazar. Can you help?",1,3,0,0,0,0,''),
(@SUB_PRIEST,4,0,"I seem to have misplaced my Eye of Zuldazar. Can you help?",1,3,0,0,0,0,''), -- Green necklace
(@SUB_PRIEST,5,0,"I seem to have misplaced my Eye of Zuldazar. Can you help?",1,3,0,0,0,0,''), -- Blue (1) necklace
(@SUB_PRIEST,6,0,"I seem to have misplaced my Eye of Zuldazar. Can you help?",1,3,0,0,0,0,''), -- Blue (2) necklace
-- WARLOCK
(@SUB_WARLOCK,0,0,"I seem to have misplaced my Zandalar Demoniac's Robe. Can you help?",1,3,0,0,0,0,''),
(@SUB_WARLOCK,1,0,"I seem to have misplaced my Zandalar Demoniac's Mantle. Can you help?",1,3,0,0,0,0,''),
(@SUB_WARLOCK,2,0,"I seem to have misplaced my Zandalar Demoniac's Wraps. Can you help?",1,3,0,0,0,0,''),
(@SUB_WARLOCK,3,0,"I seem to have misplaced my Kezan's Unstoppable Taint. Can you help?",1,3,0,0,0,0,''),
(@SUB_WARLOCK,4,0,"I seem to have misplaced my Kezan's Taint. Can you help?",1,3,0,0,0,0,''), -- Green necklace
(@SUB_WARLOCK,5,0,"I seem to have misplaced my Kezan's Taint. Can you help?",1,3,0,0,0,0,''), -- Blue (1) necklace
(@SUB_WARLOCK,6,0,"I seem to have misplaced my Kezan's Taint. Can you help?",1,3,0,0,0,0,''), -- Blue (2) necklace
-- MAGE
(@SUB_MAGE,0,0,"I seem to have misplaced my Zandalar Illusionist's Robe. Can you help?",1,3,0,0,0,0,''),
(@SUB_MAGE,1,0,"I seem to have misplaced my Zandalar Illusionist's Mantle. Can you help?",1,3,0,0,0,0,''),
(@SUB_MAGE,2,0,"I seem to have misplaced my Zandalar Illusionist's Wraps. Can you help?",1,3,0,0,0,0,''),
(@SUB_MAGE,3,0,"I seem to have misplaced my Jewel of Kajaro. Can you help?",1,3,0,0,0,0,''),
(@SUB_MAGE,4,0,"I seem to have misplaced my Pebble of Kajaro. Can you help?",1,3,0,0,0,0,''), -- Green necklace
(@SUB_MAGE,5,0,"I seem to have misplaced my Pebble of Kajaro. Can you help?",1,3,0,0,0,0,''), -- Blue (1) necklace
(@SUB_MAGE,6,0,"I seem to have misplaced my Pebble of Kajaro. Can you help?",1,3,0,0,0,0,''), -- Blue (2) necklace
-- Main menu for Maywiki
(6341,0,0,"Maywiki, I need assistance in recovering a piece of my Augur's outfit.",1,3,@SUB_SHAMAN,0,0,0,''), -- Main menu option for Shamans
(6341,1,0,"Maywiki, I need assistance in recovering a piece of my Haruspex's outfit.",1,3,@SUB_DRUID,0,0,0,''), -- Main menu option for Druids
-- SHAMAN
(@SUB_SHAMAN,0,0,"I seem to have misplaced my Zandalar Augur's Belt. Can you help?",1,3,0,0,0,0,''),
(@SUB_SHAMAN,1,0,"I seem to have misplaced my Zandalar Augur's Bracers. Can you help?",1,3,0,0,0,0,''),
(@SUB_SHAMAN,2,0,"I seem to have misplaced my Zandalar Augur's Hauberk. Can you help?",1,3,0,0,0,0,''),
(@SUB_SHAMAN,3,0,"I seem to have misplaced my Unmarred Vision of Voodress. Can you help?",1,3,0,0,0,0,''),
(@SUB_SHAMAN,4,0,"I seem to have misplaced my Vision of Voodress. Can you help?",1,3,0,0,0,0,''), -- Green necklace
(@SUB_SHAMAN,5,0,"I seem to have misplaced my Vision of Voodress. Can you help?",1,3,0,0,0,0,''), -- Blue (1) necklace
(@SUB_SHAMAN,6,0,"I seem to have misplaced my Vision of Voodress. Can you help?",1,3,0,0,0,0,''), -- Blue (2) necklace
-- DRUID
(@SUB_DRUID,0,0,"I seem to have misplaced my Zandalar Haruspex's Belt. Can you help?",1,3,0,0,0,0,''),
(@SUB_DRUID,1,0,"I seem to have misplaced my Zandalar Haruspex's Bracers. Can you help?",1,3,0,0,0,0,''),
(@SUB_DRUID,2,0,"I seem to have misplaced my Zandalar Haruspex's Tunic. Can you help?",1,3,0,0,0,0,''),
(@SUB_DRUID,3,0,"I seem to have misplaced my Pristine Enchanted South Seas Kelp. Can you help?",1,3,0,0,0,0,''),
(@SUB_DRUID,4,0,"I seem to have misplaced my Enchanted South Seas Kelp. Can you help?",1,3,0,0,0,0,''), -- Green necklace
(@SUB_DRUID,5,0,"I seem to have misplaced my Enchanted South Seas Kelp. Can you help?",1,3,0,0,0,0,''), -- Blue (1) necklace
(@SUB_DRUID,6,0,"I seem to have misplaced my Enchanted South Seas Kelp. Can you help?",1,3,0,0,0,0,''), -- Blue (2) necklace
-- Main menu for Falthir
(@GOSSIP,0,0,"Falthir, I need assistance in recovering a piece of my Madcap's outfit.",1,3,@SUB_ROGUE,0,0,0,''), -- Main menu option for Rogues
(@GOSSIP,1,0,"Falthir, I need assistance in recovering a piece of my Predator's outfit.",1,3,@SUB_HUNTER,0,0,0,''), -- Main menu option for Hunters
-- ROGUE
(@SUB_ROGUE,0,0,"I seem to have misplaced my Zandalar Madcap's Belt. Can you help?",1,3,0,0,0,0,''),
(@SUB_ROGUE,1,0,"I seem to have misplaced my Zandalar Madcap's Bracers. Can you help?",1,3,0,0,0,0,''),
(@SUB_ROGUE,2,0,"I seem to have misplaced my Zandalar Madcap's Tunic. Can you help?",1,3,0,0,0,0,''),
(@SUB_ROGUE,3,0,"I seem to have misplaced my Zandalarian Shadow Mastery Talisman. Can you help?",1,3,0,0,0,0,''),
(@SUB_ROGUE,4,0,"I seem to have misplaced my Zandalarian Shadow Talisman. Can you help?",1,3,0,0,0,0,''), -- Green necklace
(@SUB_ROGUE,5,0,"I seem to have misplaced my Zandalarian Shadow Talisman. Can you help?",1,3,0,0,0,0,''), -- Blue (1) necklace
(@SUB_ROGUE,6,0,"I seem to have misplaced my Zandalarian Shadow Talisman. Can you help?",1,3,0,0,0,0,''), -- Blue (2) necklace
-- HUNTER
(@SUB_HUNTER,0,0,"I seem to have misplaced my Zandalar Predator's Belt. Can you help?",1,3,0,0,0,0,''),
(@SUB_HUNTER,1,0,"I seem to have misplaced my Zandalar Predator's Bracers. Can you help?",1,3,0,0,0,0,''),
(@SUB_HUNTER,2,0,"I seem to have misplaced my Zandalar Predator's Tunic. Can you help?",1,3,0,0,0,0,''),
(@SUB_HUNTER,3,0,"I seem to have misplaced my Maelstrom's Wrath. Can you help?",1,3,0,0,0,0,''),
(@SUB_HUNTER,4,0,"I seem to have misplaced my Malestrom's Tendril. Can you help?",1,3,0,0,0,0,''), -- Green necklace
(@SUB_HUNTER,5,0,"I seem to have misplaced my Malestrom's Tendril. Can you help?",1,3,0,0,0,0,''), -- Blue (1) necklace
(@SUB_HUNTER,6,0,"I seem to have misplaced my Malestrom's Tendril. Can you help?",1,3,0,0,0,0,''); -- Blue (2) necklace

-- Jin'rokh the Breaker SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=14902;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14902;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Paladin
(14902,0,0,0,62,0,100,0,@SUB_PALADIN,0,0,0,56,19827,1,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker - On gossip select 0 give item Zandalar Freethinker''s Armguards'),
(14902,0,1,0,62,0,100,0,@SUB_PALADIN,1,0,0,56,19826,1,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker - On gossip select 1 give item Zandalar Freethinker''s Belt'),
(14902,0,2,0,62,0,100,0,@SUB_PALADIN,2,0,0,56,19825,1,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker - On gossip select 2 give item Zandalar Freethinker''s Breastplate'),
(14902,0,3,0,62,0,100,0,@SUB_PALADIN,3,0,0,56,19588,1,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker - On gossip select 3 give item Hero''s Brand'),
(14902,0,4,0,62,0,100,0,@SUB_PALADIN,4,0,0,56,19579,1,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker - On gossip select 4 give item Heathen''s Brand (green)'),
(14902,0,5,0,62,0,100,0,@SUB_PALADIN,5,0,0,56,19585,1,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker - On gossip select 5 give item Heathen''s Brand (blue (1))'),
(14902,0,6,0,62,0,100,0,@SUB_PALADIN,6,0,0,56,19586,1,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker - On gossip select 6 give item Heathen''s Brand (blue (2))'),
-- Closing gossips
(14902,0,7,0,62,0,100,0,@SUB_PALADIN,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker- On gossip option select - Close gossip'),
(14902,0,8,0,62,0,100,0,@SUB_PALADIN,1,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker- On gossip option select - Close gossip'),
(14902,0,9,0,62,0,100,0,@SUB_PALADIN,2,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker- On gossip option select - Close gossip'),
(14902,0,10,0,62,0,100,0,@SUB_PALADIN,3,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker- On gossip option select - Close gossip'),
(14902,0,11,0,62,0,100,0,@SUB_PALADIN,4,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker- On gossip option select - Close gossip'),
(14902,0,12,0,62,0,100,0,@SUB_PALADIN,5,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker- On gossip option select - Close gossip'),
(14902,0,13,0,62,0,100,0,@SUB_PALADIN,6,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker- On gossip option select - Close gossip'),
-- Warrior
(14902,0,14,0,62,0,100,0,@SUB_WARRIOR,0,0,0,56,19824,1,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker - On gossip select 0 give item Zandalar Vindicator''s Armguards'),
(14902,0,15,0,62,0,100,0,@SUB_WARRIOR,1,0,0,56,19823,1,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker - On gossip select 1 give item Zandalar Vindicator''s Belt'),
(14902,0,16,0,62,0,100,0,@SUB_WARRIOR,2,0,0,56,19822,1,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker - On gossip select 2 give item Zandalar Vindicator''s Breastplate'),
(14902,0,17,0,62,0,100,0,@SUB_WARRIOR,3,0,0,56,19577,1,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker - On gossip select 3 give item Rage of Mugamba'),
(14902,0,18,0,62,0,100,0,@SUB_WARRIOR,4,0,0,56,19574,1,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker - On gossip select 4 give item Strength of Mugamba (green)'),
(14902,0,19,0,62,0,100,0,@SUB_WARRIOR,5,0,0,56,19575,1,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker - On gossip select 5 give item Strength of Mugamba (blue (1))'),
(14902,0,20,0,62,0,100,0,@SUB_WARRIOR,6,0,0,56,19576,1,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker - On gossip select 6 give item Strength of Mugamba (blue (2))'),
-- Closing gossips
(14902,0,21,0,62,0,100,0,@SUB_WARRIOR,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker - On gossip option select - Close gossip'),
(14902,0,22,0,62,0,100,0,@SUB_WARRIOR,1,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker - On gossip option select - Close gossip'),
(14902,0,23,0,62,0,100,0,@SUB_WARRIOR,2,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker - On gossip option select - Close gossip'),
(14902,0,24,0,62,0,100,0,@SUB_WARRIOR,3,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker - On gossip option select - Close gossip'),
(14902,0,25,0,62,0,100,0,@SUB_WARRIOR,4,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker - On gossip option select - Close gossip'),
(14902,0,26,0,62,0,100,0,@SUB_WARRIOR,5,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker - On gossip option select - Close gossip'),
(14902,0,27,0,62,0,100,0,@SUB_WARRIOR,6,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Jin''rokh the Breaker - On gossip option select - Close gossip');

-- Al''tabim the All-Seeing SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=14903;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14903;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Priest
(14903,0,0,0,62,0,100,0,@SUB_PRIEST,0,0,0,56,19842,1,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip select 0 give item Zandalar Confessor''s Bindings'),
(14903,0,1,0,62,0,100,0,@SUB_PRIEST,1,0,0,56,19841,1,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip select 1 give item Zandalar Confessor''s Mantle'),
(14903,0,2,0,62,0,100,0,@SUB_PRIEST,2,0,0,56,19843,1,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip select 2 give item Zandalar Confessor''s Wraps'),
(14903,0,3,0,62,0,100,0,@SUB_PRIEST,3,0,0,56,19594,1,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip select 3 give item The All-Seeing Eye of Zuldazar'),
(14903,0,4,0,62,0,100,0,@SUB_PRIEST,4,0,0,56,19591,1,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip select 4 give item The Eye of Zuldazar (green)'),
(14903,0,5,0,62,0,100,0,@SUB_PRIEST,5,0,0,56,19592,1,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip select 5 give item The Eye of Zuldazar (blue (1))'),
(14903,0,6,0,62,0,100,0,@SUB_PRIEST,6,0,0,56,19593,1,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip select 6 give item The Eye of Zuldazar (blue (2))'),
-- Closing gossips
(14903,0,7,0,62,0,100,0,@SUB_PRIEST,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip option select - Close gossip'),
(14903,0,8,0,62,0,100,0,@SUB_PRIEST,1,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip option select - Close gossip'),
(14903,0,9,0,62,0,100,0,@SUB_PRIEST,2,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip option select - Close gossip'),
(14903,0,10,0,62,0,100,0,@SUB_PRIEST,3,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip option select - Close gossip'),
(14903,0,11,0,62,0,100,0,@SUB_PRIEST,4,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip option select - Close gossip'),
(14903,0,12,0,62,0,100,0,@SUB_PRIEST,5,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip option select - Close gossip'),
(14903,0,13,0,62,0,100,0,@SUB_PRIEST,6,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip option select - Close gossip'),
-- Warlock
(14903,0,14,0,62,0,100,0,@SUB_WARLOCK,0,0,0,56,19849,1,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip select 0 give item Zandalar Demoniac''s Bindings'),
(14903,0,15,0,62,0,100,0,@SUB_WARLOCK,1,0,0,56,20033,1,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip select 1 give item Zandalar Demoniac''s Mantle'),
(14903,0,16,0,62,0,100,0,@SUB_WARLOCK,2,0,0,56,19848,1,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip select 2 give item Zandalar Demoniac''s Wraps'),
(14903,0,17,0,62,0,100,0,@SUB_WARLOCK,3,0,0,56,19605,1,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip select 3 give item The All-Seeing Eye of Zuldazar'),
(14903,0,18,0,62,0,100,0,@SUB_WARLOCK,4,0,0,56,19602,1,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip select 4 give item Kezan''s Taint (green)'),
(14903,0,19,0,62,0,100,0,@SUB_WARLOCK,5,0,0,56,19603,1,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip select 5 give item Kezan''s Taint (blue (1))'),
(14903,0,20,0,62,0,100,0,@SUB_WARLOCK,6,0,0,56,19604,1,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip select 6 give item Kezan''s Taint (blue (2))'),
-- Closing gossips
(14903,0,21,0,62,0,100,0,@SUB_WARLOCK,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip option select - Close gossip'),
(14903,0,22,0,62,0,100,0,@SUB_WARLOCK,1,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip option select - Close gossip'),
(14903,0,23,0,62,0,100,0,@SUB_WARLOCK,2,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip option select - Close gossip'),
(14903,0,24,0,62,0,100,0,@SUB_WARLOCK,3,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip option select - Close gossip'),
(14903,0,25,0,62,0,100,0,@SUB_WARLOCK,4,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip option select - Close gossip'),
(14903,0,26,0,62,0,100,0,@SUB_WARLOCK,5,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip option select - Close gossip'),
(14903,0,27,0,62,0,100,0,@SUB_WARLOCK,6,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip option select - Close gossip'),
-- Mage
(14903,0,28,0,62,0,100,0,@SUB_MAGE,0,0,0,56,19845,1,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip select 0 give item Zandalar Illusionist''s Mantle'),
(14903,0,29,0,62,0,100,0,@SUB_MAGE,1,0,0,56,20034,1,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip select 1 give item Zandalar Illusionist''s Robes'),
(14903,0,30,0,62,0,100,0,@SUB_MAGE,2,0,0,56,19846,1,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip select 2 give item Zandalar Illusionist''s Wraps'),
(14903,0,31,0,62,0,100,0,@SUB_MAGE,3,0,0,56,19601,1,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip select 3 give item Jewel of Kajaro'),
(14903,0,32,0,62,0,100,0,@SUB_MAGE,4,0,0,56,19598,1,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip select 4 give item Pebble of Kajaro (green)'),
(14903,0,33,0,62,0,100,0,@SUB_MAGE,5,0,0,56,19599,1,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip select 5 give item Pebble of Kajaro (blue (1))'),
(14903,0,34,0,62,0,100,0,@SUB_MAGE,6,0,0,56,19600,1,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip select 6 give item Pebble of Kajaro (blue (2))'),
-- Closing gossips
(14903,0,35,0,62,0,100,0,@SUB_MAGE,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip option select - Close gossip'),
(14903,0,36,0,62,0,100,0,@SUB_MAGE,1,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip option select - Close gossip'),
(14903,0,37,0,62,0,100,0,@SUB_MAGE,2,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip option select - Close gossip'),
(14903,0,38,0,62,0,100,0,@SUB_MAGE,3,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip option select - Close gossip'),
(14903,0,39,0,62,0,100,0,@SUB_MAGE,4,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip option select - Close gossip'),
(14903,0,40,0,62,0,100,0,@SUB_MAGE,5,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip option select - Close gossip'),
(14903,0,41,0,62,0,100,0,@SUB_MAGE,6,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Al''tabim the All-Seeing - On gossip option select - Close gossip');

-- Maywiki of Zuldazar SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=14904;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14904;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Shaman
(14904,0,0,0,62,0,100,0,@SUB_SHAMAN,0,0,0,56,19829,1,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip select 0 give item Zandalar Augur''s Belt'),
(14904,0,1,0,62,0,100,0,@SUB_SHAMAN,1,0,0,56,19830,1,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip select 1 give item Zandalar Augur''s Bracers'),
(14904,0,2,0,62,0,100,0,@SUB_SHAMAN,2,0,0,56,19828,1,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip select 2 give item Zandalar Augur''s Hauberk'),
(14904,0,3,0,62,0,100,0,@SUB_SHAMAN,3,0,0,56,19609,1,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip select 3 give item Unmarred Vision of Voodress'),
(14904,0,4,0,62,0,100,0,@SUB_SHAMAN,4,0,0,56,19606,1,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip select 4 give item Vision of Voodress (green)'),
(14904,0,5,0,62,0,100,0,@SUB_SHAMAN,5,0,0,56,19607,1,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip select 5 give item Vision of Voodress (blue (1))'),
(14904,0,6,0,62,0,100,0,@SUB_SHAMAN,6,0,0,56,19608,1,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip select 6 give item Vision of Voodress (blue (2))'),
-- Closing gossips
(14904,0,7,0,62,0,100,0,@SUB_SHAMAN,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip option select - Close gossip'),
(14904,0,8,0,62,0,100,0,@SUB_SHAMAN,1,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip option select - Close gossip'),
(14904,0,9,0,62,0,100,0,@SUB_SHAMAN,2,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip option select - Close gossip'),
(14904,0,10,0,62,0,100,0,@SUB_SHAMAN,3,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip option select - Close gossip'),
(14904,0,11,0,62,0,100,0,@SUB_SHAMAN,4,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip option select - Close gossip'),
(14904,0,12,0,62,0,100,0,@SUB_SHAMAN,5,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip option select - Close gossip'),
(14904,0,13,0,62,0,100,0,@SUB_SHAMAN,6,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip option select - Close gossip'),
-- Druid
(14904,0,14,0,62,0,100,0,@SUB_DRUID,0,0,0,56,19839,1,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip select 0 give item Zandalar Haruspex''s Belt'),
(14904,0,15,0,62,0,100,0,@SUB_DRUID,1,0,0,56,19840,1,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip select 1 give item Zandalar Haruspex''s Bracers'),
(14904,0,16,0,62,0,100,0,@SUB_DRUID,2,0,0,56,19838,1,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip select 2 give item Zandalar Haruspex''s Tunic'),
(14904,0,17,0,62,0,100,0,@SUB_DRUID,3,0,0,56,19613,1,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip select 3 give item Pristine Enchanted South Seas Kelp'),
(14904,0,18,0,62,0,100,0,@SUB_DRUID,4,0,0,56,19610,1,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip select 4 give item Enchanted South Seas Kelp (green)'),
(14904,0,19,0,62,0,100,0,@SUB_DRUID,5,0,0,56,19611,1,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip select 5 give item Enchanted South Seas Kelp (blue (1))'),
(14904,0,20,0,62,0,100,0,@SUB_DRUID,6,0,0,56,19612,1,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip select 6 give item Enchanted South Seas Kelp (blue (2))'),
-- Closing gossips
(14904,0,21,0,62,0,100,0,@SUB_DRUID,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip option select - Close gossip'),
(14904,0,22,0,62,0,100,0,@SUB_DRUID,1,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip option select - Close gossip'),
(14904,0,23,0,62,0,100,0,@SUB_DRUID,2,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip option select - Close gossip'),
(14904,0,24,0,62,0,100,0,@SUB_DRUID,3,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip option select - Close gossip'),
(14904,0,25,0,62,0,100,0,@SUB_DRUID,4,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip option select - Close gossip'),
(14904,0,26,0,62,0,100,0,@SUB_DRUID,5,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip option select - Close gossip'),
(14904,0,27,0,62,0,100,0,@SUB_DRUID,6,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Maywiki of Zuldazar - On gossip option select - Close gossip');

-- Falthir the Sightless SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=14905;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14905;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Rogue
(14905,0,0,0,62,0,100,0,@SUB_ROGUE,0,0,0,56,19836,1,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip select 0 give item Zandalar Madcap''s Bracers'),
(14905,0,1,0,62,0,100,0,@SUB_ROGUE,1,0,0,56,19835,1,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip select 1 give item Zandalar Madcap''s Tunic'),
(14905,0,2,0,62,0,100,0,@SUB_ROGUE,2,0,0,56,19834,1,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip select 2 give item Zandalar Augur''s Belt'),
(14905,0,3,0,62,0,100,0,@SUB_ROGUE,3,0,0,56,19617,1,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip select 3 give item Zandalarian Shadow Mastery Talisman'),
(14905,0,4,0,62,0,100,0,@SUB_ROGUE,4,0,0,56,19614,1,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip select 4 give item Zandalarian Shadow Talisman (green)'),
(14905,0,5,0,62,0,100,0,@SUB_ROGUE,5,0,0,56,19615,1,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip select 5 give item Zandalarian Shadow Talisman (blue (1))'),
(14905,0,6,0,62,0,100,0,@SUB_ROGUE,6,0,0,56,19616,1,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip select 6 give item Zandalarian Shadow Talisman (blue (2))'),
-- Closing gossips
(14905,0,7,0,62,0,100,0,@SUB_ROGUE,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip option select - Close gossip'),
(14905,0,8,0,62,0,100,0,@SUB_ROGUE,1,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip option select - Close gossip'),
(14905,0,9,0,62,0,100,0,@SUB_ROGUE,2,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip option select - Close gossip'),
(14905,0,10,0,62,0,100,0,@SUB_ROGUE,3,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip option select - Close gossip'),
(14905,0,11,0,62,0,100,0,@SUB_ROGUE,4,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip option select - Close gossip'),
(14905,0,12,0,62,0,100,0,@SUB_ROGUE,5,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip option select - Close gossip'),
(14905,0,13,0,62,0,100,0,@SUB_ROGUE,6,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip option select - Close gossip'),
-- Hunter
(14905,0,14,0,62,0,100,0,@SUB_HUNTER,0,0,0,56,19832,1,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip select 0 give item Zandalar Predator''s Belt'),
(14905,0,15,0,62,0,100,0,@SUB_HUNTER,1,0,0,56,19833,1,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip select 1 give item Zandalar Predator''s Bracers'),
(14905,0,16,0,62,0,100,0,@SUB_HUNTER,2,0,0,56,19831,1,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip select 2 give item Zandalar Predator''s Mantle'),
(14905,0,17,0,62,0,100,0,@SUB_HUNTER,3,0,0,56,19621,1,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip select 3 give item Maelstrom''s Wrath'),
(14905,0,18,0,62,0,100,0,@SUB_HUNTER,4,0,0,56,19618,1,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip select 4 give item Maelstrom''s Tendril (green)'),
(14905,0,19,0,62,0,100,0,@SUB_HUNTER,5,0,0,56,19619,1,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip select 5 give item Maelstrom''s Tendril (blue (1))'),
(14905,0,20,0,62,0,100,0,@SUB_HUNTER,6,0,0,56,19620,1,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip select 6 give item Maelstrom''s Tendril (blue (2))'),
-- Closing gossips
(14905,0,21,0,62,0,100,0,@SUB_HUNTER,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip option select - Close gossip'),
(14905,0,22,0,62,0,100,0,@SUB_HUNTER,1,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip option select - Close gossip'),
(14905,0,23,0,62,0,100,0,@SUB_HUNTER,2,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip option select - Close gossip'),
(14905,0,24,0,62,0,100,0,@SUB_HUNTER,3,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip option select - Close gossip'),
(14905,0,25,0,62,0,100,0,@SUB_HUNTER,4,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip option select - Close gossip'),
(14905,0,26,0,62,0,100,0,@SUB_HUNTER,5,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip option select - Close gossip'),
(14905,0,27,0,62,0,100,0,@SUB_HUNTER,6,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Falthir the Sightless - On gossip option select - Close gossip');

-- Conditions for gossip menu options
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (6321,6322,6341,@GOSSIP,@SUB_PALADIN,@SUB_WARRIOR,@SUB_PRIEST,@SUB_WARLOCK,@SUB_MAGE,@SUB_SHAMAN,@SUB_DRUID,@SUB_ROGUE,@SUB_HUNTER);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`Comment`) VALUES
-- PALADIN CONDITIONS
-- Zandalar Freethinker's Armguards
(15,@SUB_PALADIN,0,0,8,8053,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Freethinker's Armguards is rewarded"),
(15,@SUB_PALADIN,0,0,26,19827,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Freethinker's Armguards"),
-- Zandalar Freethinker's Belt
(15,@SUB_PALADIN,1,0,8,8054,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Freethinker's Belt is rewarded"),
(15,@SUB_PALADIN,1,0,26,19826,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Freethinker's Belt"),
-- Zandalar Freethinker's Breastplate
(15,@SUB_PALADIN,2,0,8,8055,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Freethinker's Breastplate is rewarded"),
(15,@SUB_PALADIN,2,0,26,19825,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Freethinker's Breastplate"),
-- Hero's Brand
(15,@SUB_PALADIN,3,0,8,8048,0,0,0,"Only allow gossip option to be visible if quest The Hero's Brand is rewarded"),
(15,@SUB_PALADIN,3,0,26,19588,1,0,0,"Only allow gossip option to be visible if player does not have item Hero's Brand"),
-- Heathen's Band (green)
(15,@SUB_PALADIN,4,0,8,8045,0,0,0,"Only allow gossip option to be visible if quest The Heathen's Brand is rewarded"),
(15,@SUB_PALADIN,4,0,26,19579,1,0,0,"Only allow gossip option to be visible if player does not have item Heathen's Brand"),
-- Heathen's Band (blue - one)
(15,@SUB_PALADIN,5,0,8,8046,0,0,0,"Only allow gossip option to be visible if quest The Heathen's Brand is rewarded"),
(15,@SUB_PALADIN,5,0,26,19585,1,0,0,"Only allow gossip option to be visible if player does not have item Heathen's Brand"),
-- Heathen's Band (blue - two)
(15,@SUB_PALADIN,6,0,8,8047,0,0,0,"Only allow gossip option to be visible if quest The Heathen's Brand is rewarded"),
(15,@SUB_PALADIN,6,0,26,19586,1,0,0,"Only allow gossip option to be visible if player does not have item Heathen's Brand"),
-- WARRIOR CONDITIONS
-- Zandalar Vindicator's Armguards
(15,@SUB_WARRIOR,0,0,8,8058,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Vindicator's Armguards is rewarded"),
(15,@SUB_WARRIOR,0,0,26,19824,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Vindicator's Armguards"),
-- Zandalar Vindicator's Belt
(15,@SUB_WARRIOR,1,0,8,8078,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Vindicator's Belt is rewarded"),
(15,@SUB_WARRIOR,1,0,26,19823,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Vindicator's Belt"),
-- Zandalar Vindicator's Breastplate
(15,@SUB_WARRIOR,2,0,8,8079,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Vindicator's Breastplate is rewarded"),
(15,@SUB_WARRIOR,2,0,26,19822,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Vindicator's Breastplate"),
-- Rage of Mugamba
(15,@SUB_WARRIOR,3,0,8,8044,0,0,0,"Only allow gossip option to be visible if quest The Rage of Mugamba is rewarded"),
(15,@SUB_WARRIOR,3,0,26,19577,1,0,0,"Only allow gossip option to be visible if player does not have item Rage of Mugamba"),
-- Strength of Mugamba (green)
(15,@SUB_WARRIOR,4,0,8,8041,0,0,0,"Only allow gossip option to be visible if quest Strength of Mount Mugamba is rewarded"),
(15,@SUB_WARRIOR,4,0,26,19574,1,0,0,"Only allow gossip option to be visible if player does not have item Strength of Mugamba"),
-- Strength of Mugamba (blue - one)
(15,@SUB_WARRIOR,5,0,8,8042,0,0,0,"Only allow gossip option to be visible if quest Strength of Mount Mugamba is rewarded"),
(15,@SUB_WARRIOR,5,0,26,19575,1,0,0,"Only allow gossip option to be visible if player does not have item Strength of Mugamba"),
-- Strength of Mugamba (blue - two)
(15,@SUB_WARRIOR,6,0,8,8043,0,0,0,"Only allow gossip option to be visible if quest Strength of Mount Mugamba is rewarded"),
(15,@SUB_WARRIOR,6,0,26,19576,1,0,0,"Only allow gossip option to be visible if player does not have item Strength of Mugamba"),
-- PRIEST CONDITIONS
-- Zandalar Confessor's Bindings
(15,@SUB_PRIEST,0,0,8,8070,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Confessor's Bindings is rewarded"),
(15,@SUB_PRIEST,0,0,26,19842,1,0,0,"Only allow gossip option to be visible if player does not have item  Zandalar Confessor's Bindings"),
-- Zandalar Confessor's Mantle
(15,@SUB_PRIEST,1,0,8,8071,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Confessor's Mantle is rewarded"),
(15,@SUB_PRIEST,1,0,26,19841,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Confessor's Mantle"),
-- Zandalar Confessor's Wraps
(15,@SUB_PRIEST,2,0,8,8061,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Confessor's Wraps is rewarded"),
(15,@SUB_PRIEST,2,0,26,19843,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Confessor's Wraps"),
-- The All-Seeing Eye of Zuldazar
(15,@SUB_PRIEST,3,0,8,8052,0,0,0,"Only allow gossip option to be visible if quest The All-Seeing Eye of Zuldazar is rewarded"),
(15,@SUB_PRIEST,3,0,26,19594,1,0,0,"Only allow gossip option to be visible if player does not have item The All-Seeing Eye of Zuldazar"),
-- The Eye of Zuldazar (green)
(15,@SUB_PRIEST,4,0,8,8049,0,0,0,"Only allow gossip option to be visible if quest The Eye of Zuldazar is rewarded"),
(15,@SUB_PRIEST,4,0,26,19591,1,0,0,"Only allow gossip option to be visible if player does not have item The Eye of Zuldazar"),
-- The Eye of Zuldazar (blue - one)
(15,@SUB_PRIEST,5,0,8,8050,0,0,0,"Only allow gossip option to be visible if quest The Eye of Zuldazar is rewarded"),
(15,@SUB_PRIEST,5,0,26,19592,1,0,0,"Only allow gossip option to be visible if player does not have item The Eye of Zuldazar"),
-- The Eye of Zuldazar (blue - two)
(15,@SUB_PRIEST,6,0,8,8051,0,0,0,"Only allow gossip option to be visible if quest The Eye of Zuldazar is rewarded"),
(15,@SUB_PRIEST,6,0,26,19593,1,0,0,"Only allow gossip option to be visible if player does not have item The Eye of Zuldazar"),
-- WARLOCK CONDITIONS
-- Zandalar Demoniac's Mantle
(15,@SUB_WARLOCK,0,0,8,8076,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Demoniac's Mantle is rewarded"),
(15,@SUB_WARLOCK,0,0,26,19849,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Demoniac's Mantle"),
-- Zandalar Demoniac's Robe
(15,@SUB_WARLOCK,1,0,8,8077,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Demoniac's Robes is rewarded"),
(15,@SUB_WARLOCK,1,0,26,20033,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Demoniac's Robe"),
-- Zandalar Demoniac's Wraps
(15,@SUB_WARLOCK,2,0,8,8059,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Demoniac's Wraps is rewarded"),
(15,@SUB_WARLOCK,2,0,26,19848,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Demoniac's Wraps"),
-- Kezan's Unstoppable Taint
(15,@SUB_WARLOCK,3,0,8,8109,0,0,0,"Only allow gossip option to be visible if quest Kezan's Unstoppable Taint is rewarded"),
(15,@SUB_WARLOCK,3,0,26,19605,1,0,0,"Only allow gossip option to be visible if player does not have item Kezan's Unstoppable Taint"),
-- Kezan's Taint (green)
(15,@SUB_WARLOCK,4,0,8,8106,0,0,0,"Only allow gossip option to be visible if quest Kezan's Taint is rewarded"),
(15,@SUB_WARLOCK,4,0,26,19602,1,0,0,"Only allow gossip option to be visible if player does not have item Kezan's Taint"),
-- Kezan's Taint (blue - one)
(15,@SUB_WARLOCK,5,0,8,8107,0,0,0,"Only allow gossip option to be visible if quest Kezan's Taint is rewarded"),
(15,@SUB_WARLOCK,5,0,26,19603,1,0,0,"Only allow gossip option to be visible if player does not have item Kezan's Taint"),
-- Kezan's Taint (blue - two)
(15,@SUB_WARLOCK,6,0,8,8108,0,0,0,"Only allow gossip option to be visible if quest Kezan's Taint is rewarded"),
(15,@SUB_WARLOCK,6,0,26,19604,1,0,0,"Only allow gossip option to be visible if player does not have item Kezan's Taint"),
-- MAGE CONDITIONS
-- Zandalar Illusionist's Mantle
(15,@SUB_MAGE,0,0,8,8068,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Illusionist's Mantle is rewarded"),
(15,@SUB_MAGE,0,0,26,19845,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Illusionist's Mantle"),
-- Zandalar Illusionist's Robe
(15,@SUB_MAGE,1,0,8,8069,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Illusionist's Robes is rewarded"),
(15,@SUB_MAGE,1,0,26,20034,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Illusionist's Robe"),
-- Zandalar Illusionist's Wraps
(15,@SUB_MAGE,2,0,8,8060,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Illusionist's Wraps is rewarded"),
(15,@SUB_MAGE,2,0,26,19846,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Illusionist's Wraps"),
-- Jewel of Kajaro
(15,@SUB_MAGE,3,0,8,8104,0,0,0,"Only allow gossip option to be visible if quest The Jewel of Kajaro is rewarded"),
(15,@SUB_MAGE,3,0,26,19601,1,0,0,"Only allow gossip option to be visible if player does not have item Jewel of Kajaro"),
-- Pebble of Kajaro (green)
(15,@SUB_MAGE,4,0,8,8101,0,0,0,"Only allow gossip option to be visible if quest The Pebble of Kajaro is rewarded"),
(15,@SUB_MAGE,4,0,26,19598,1,0,0,"Only allow gossip option to be visible if player does not have item Pebble of Kajaro"),
-- Pebble of Kajaro (blue - one)
(15,@SUB_MAGE,5,0,8,8102,0,0,0,"Only allow gossip option to be visible if quest The Pebble of Kajaro is rewarded"),
(15,@SUB_MAGE,5,0,26,19599,1,0,0,"Only allow gossip option to be visible if player does not have item Pebble of Kajaro"),
-- Pebble of Kajaro (blue - two)
(15,@SUB_MAGE,6,0,8,8103,0,0,0,"Only allow gossip option to be visible if quest The Pebble of Kajaro is rewarded"),
(15,@SUB_MAGE,6,0,26,19600,1,0,0,"Only allow gossip option to be visible if player does not have item Pebble of Kajaro"),
-- SHAMAN CONDITIONS
-- Zandalar Augur's Belt
(15,@SUB_SHAMAN,0,0,8,8074,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Augur's Belt is rewarded"),
(15,@SUB_SHAMAN,0,0,26,19829,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Augur's Belt"),
-- Zandalar Augur's Bracers
(15,@SUB_SHAMAN,1,0,8,8056,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Augur's Bracers is rewarded"),
(15,@SUB_SHAMAN,1,0,26,19830,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Augur's Bracers"),
-- Zandalar Augur's Hauberk
(15,@SUB_SHAMAN,2,0,8,8075,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Augur's Hauberk is rewarded"),
(15,@SUB_SHAMAN,2,0,26,19828,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Augur's Hauberk"),
-- Unmarred Vision of Voodress
(15,@SUB_SHAMAN,3,0,8,8119,0,0,0,"Only allow gossip option to be visible if quest The Unmarred Vision of Voodress is rewarded"),
(15,@SUB_SHAMAN,3,0,26,19609,1,0,0,"Only allow gossip option to be visible if player does not have item Unmarred Vision of Voodress"),
-- Vision of Voodress (green)
(15,@SUB_SHAMAN,4,0,8,8116,0,0,0,"Only allow gossip option to be visible if quest Vision of Voodress is rewarded"),
(15,@SUB_SHAMAN,4,0,26,19606,1,0,0,"Only allow gossip option to be visible if player does not have item Vision of Voodress"),
-- Vision of Voodress (blue - one)
(15,@SUB_SHAMAN,5,0,8,8117,0,0,0,"Only allow gossip option to be visible if quest Vision of Voodress is rewarded"),
(15,@SUB_SHAMAN,5,0,26,19607,1,0,0,"Only allow gossip option to be visible if player does not have item Vision of Voodress"),
-- Vision of Voodress (blue - two)
(15,@SUB_SHAMAN,6,0,8,8118,0,0,0,"Only allow gossip option to be visible if quest Vision of Voodress is rewarded"),
(15,@SUB_SHAMAN,6,0,26,19608,1,0,0,"Only allow gossip option to be visible if player does not have item Vision of Voodress"),
-- DRUID CONDITIONS
-- Zandalar Haruspex's Belt
(15,@SUB_DRUID,0,0,8,8064,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Haruspex's Belt is rewarded"),
(15,@SUB_DRUID,0,0,26,19839,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Haruspex's Belt"),
-- Zandalar Haruspex's Bracers
(15,@SUB_DRUID,1,0,8,8057,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Haruspex's Bracers is rewarded"),
(15,@SUB_DRUID,1,0,26,19840,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Haruspex's Bracers"),
-- Zandalar Haruspex's Tunic
(15,@SUB_DRUID,2,0,8,8065,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Haruspex's Tunic is rewarded"),
(15,@SUB_DRUID,2,0,26,19838,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Haruspex's Tunic"),
-- Pristine Enchanted South Seas Kelp
(15,@SUB_DRUID,3,0,8,8113,0,0,0,"Only allow gossip option to be visible if quest Pristine Enchanted South Seas Kelp is rewarded"),
(15,@SUB_DRUID,3,0,26,19613,1,0,0,"Only allow gossip option to be visible if player does not have item Pristine Enchanted South Seas Kelp"),
-- Enchanted South Seas Kelp (green)
(15,@SUB_DRUID,4,0,8,8110,0,0,0,"Only allow gossip option to be visible if quest Enchanted South Seas Kelp is rewarded"),
(15,@SUB_DRUID,4,0,26,19610,1,0,0,"Only allow gossip option to be visible if player does not have item Enchanted South Seas Kelp"),
-- Enchanted South Seas Kelp (blue - one)
(15,@SUB_DRUID,5,0,8,8111,0,0,0,"Only allow gossip option to be visible if quest Enchanted South Seas Kelp is rewarded"),
(15,@SUB_DRUID,5,0,26,19611,1,0,0,"Only allow gossip option to be visible if player does not have item Enchanted South Seas Kelp"),
-- Enchanted South Seas Kelp (blue - two)
(15,@SUB_DRUID,6,0,8,8112,0,0,0,"Only allow gossip option to be visible if quest Enchanted South Seas Kelp is rewarded"),
(15,@SUB_DRUID,6,0,26,19612,1,0,0,"Only allow gossip option to be visible if player does not have item Enchanted South Seas Kelp"),
-- ROGUE CONDITIONS
-- Zandalar Madcap's Bracers
(15,@SUB_ROGUE,0,0,8,8063,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Madcap's Bracers is rewarded"),
(15,@SUB_ROGUE,0,0,26,19836,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Madcap's Bracers"),
-- Zandalar Madcap's Mantle
(15,@SUB_ROGUE,1,0,8,8072,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Madcap's Mantle is rewarded"),
(15,@SUB_ROGUE,1,0,26,19835,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Madcap's Mantle"),
-- Zandalar Madcap's Tunic
(15,@SUB_ROGUE,2,0,8,8073,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Madcap's Tunic is rewarded"),
(15,@SUB_ROGUE,2,0,26,19834,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Madcap's Tunic"),
-- Zandalarian Shadow Mastery Talisman
(15,@SUB_ROGUE,3,0,8,8144,0,0,0,"Only allow gossip option to be visible if quest Zandalarian Shadow Mastery Talisman is rewarded"),
(15,@SUB_ROGUE,3,0,26,19617,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalarian Shadow Mastery Talisman"),
-- Zandalarian Shadow Talisman (green)
(15,@SUB_ROGUE,4,0,8,8141,0,0,0,"Only allow gossip option to be visible if quest Zandalarian Shadow Talisman is rewarded"),
(15,@SUB_ROGUE,4,0,26,19614,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalarian Shadow Talisman"),
-- Zandalarian Shadow Talisman (blue - one)
(15,@SUB_ROGUE,5,0,8,8142,0,0,0,"Only allow gossip option to be visible if quest Zandalarian Shadow Talisman is rewarded"),
(15,@SUB_ROGUE,5,0,26,19615,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalarian Shadow Talisman"),
-- Zandalarian Shadow Talisman (blue - two)
(15,@SUB_ROGUE,6,0,8,8143,0,0,0,"Only allow gossip option to be visible if quest Zandalarian Shadow Talisman is rewarded"),
(15,@SUB_ROGUE,6,0,26,19616,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalarian Shadow Talisman"),
-- HUNTER CONDITIONS
-- Zandalar Predator's Belt
(15,@SUB_HUNTER,0,0,8,8066,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Predator's Belt is rewarded"),
(15,@SUB_HUNTER,0,0,26,19832,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Predator's Belt"),
-- Zandalar Predator's Bracers
(15,@SUB_HUNTER,1,0,8,8062,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Predator's Bracers is rewarded"),
(15,@SUB_HUNTER,1,0,26,19833,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Predator's Bracers"),
-- Zandalar Predator's Mantle
(15,@SUB_HUNTER,2,0,8,8067,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Predator's Mantle is rewarded"),
(15,@SUB_HUNTER,2,0,26,19831,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Predator's Mantle"),
-- Maelstrom's Wrath
(15,@SUB_HUNTER,3,0,8,8148,0,0,0,"Only allow gossip option to be visible if quest Maelstrom's Wrath is rewarded"),
(15,@SUB_HUNTER,3,0,26,19621,1,0,0,"Only allow gossip option to be visible if player does not have item Maelstrom's Wrath"),
-- Maelstrom's Tendril (green)
(15,@SUB_HUNTER,4,0,8,8145,0,0,0,"Only allow gossip option to be visible if quest The Maelstrom's Tendril is rewarded"),
(15,@SUB_HUNTER,4,0,26,19618,1,0,0,"Only allow gossip option to be visible if player does not have item Maelstrom's Tendril"),
-- Maelstrom's Tendril (blue - one)
(15,@SUB_HUNTER,5,0,8,8146,0,0,0,"Only allow gossip option to be visible if quest The Maelstrom's Tendril is rewarded"),
(15,@SUB_HUNTER,5,0,26,19619,1,0,0,"Only allow gossip option to be visible if player does not have item Maelstrom's Tendril"),
-- Maelstrom's Tendril (blue - two)
(15,@SUB_HUNTER,6,0,8,8147,0,0,0,"Only allow gossip option to be visible if quest The Maelstrom's Tendril is rewarded"),
(15,@SUB_HUNTER,6,0,26,19620,1,0,0,"Only allow gossip option to be visible if player does not have item Maelstrom's Tendril"),
-- NOTE: THESE ARE GROUPED CONDITIONS!
-- EITHER ONE OF THE REQUIREMENTS MUST BE MET FOR THE GOSSIP TO BE VISIBLE!
-- Conditions for gossip main menu of Jin''rokh the Breaker
-- Paladin main menu conditions
(15,6321,0,0,8,8053,0,0,0,"Only allow main gossip to be visible if quest Paragons of Power: The Freethinker's Armguards is rewarded"),
(15,6321,0,0,26,19827,1,0,0,"Only allow main gossip to be visible if player does not have item Zandalar Freethinker's Armguards"),
(15,6321,0,1,8,8054,0,0,0,"Only allow main gossip to be visible if quest Paragons of Power: The Freethinker's Belt is rewarded"),
(15,6321,0,1,26,19826,1,0,0,"Only allow main gossip to be visible if player does not have item Zandalar Freethinker's Belt"),
(15,6321,0,2,8,8055,0,0,0,"Only allow main gossip to be visible if quest Paragons of Power: The Freethinker's Breastplate is rewarded"),
(15,6321,0,2,26,19825,1,0,0,"Only allow main gossip to be visible if player does not have item Zandalar Freethinker's Breastplate"),
(15,6321,0,3,8,8048,0,0,0,"Only allow main gossip to be visible if quest The Hero's Brand is rewarded"),
(15,6321,0,3,26,19588,1,0,0,"Only allow main gossip to be visible if player does not have item Hero's Brand"),
(15,6321,0,4,8,8045,0,0,0,"Only allow main gossip to be visible if quest The Heathen's Brand is rewarded"),
(15,6321,0,4,26,19579,1,0,0,"Only allow main gossip to be visible if player does not have item Heathen's Brand"),
(15,6321,0,5,8,8046,0,0,0,"Only allow main gossip to be visible if quest The Heathen's Brand is rewarded"),
(15,6321,0,5,26,19585,1,0,0,"Only allow main gossip to be visible if player does not have item Heathen's Brand"),
(15,6321,0,6,8,8047,0,0,0,"Only allow main gossip to be visible if quest The Heathen's Brand is rewarded"),
(15,6321,0,6,26,19586,1,0,0,"Only allow main gossip to be visible if player does not have item Heathen's Brand"),
-- Warrior main menu conditions
(15,6321,1,0,8,8058,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Vindicator's Armguards is rewarded"),
(15,6321,1,0,26,19824,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Vindicator's Armguards"),
(15,6321,1,1,8,8078,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Vindicator's Belt is rewarded"),
(15,6321,1,1,26,19823,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Vindicator's Belt"),
(15,6321,1,2,8,8079,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Vindicator's Breastplate is rewarded"),
(15,6321,1,2,26,19822,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Vindicator's Breastplate"),
(15,6321,1,3,8,8044,0,0,0,"Only allow gossip option to be visible if quest The Rage of Mugamba is rewarded"),
(15,6321,1,3,26,19577,1,0,0,"Only allow gossip option to be visible if player does not have item Rage of Mugamba"),
(15,6321,1,4,8,8041,0,0,0,"Only allow gossip option to be visible if quest Strength of Mount Mugamba is rewarded"),
(15,6321,1,4,26,19574,1,0,0,"Only allow gossip option to be visible if player does not have item Strength of Mugamba"),
(15,6321,1,5,8,8042,0,0,0,"Only allow gossip option to be visible if quest Strength of Mount Mugamba is rewarded"),
(15,6321,1,5,26,19575,1,0,0,"Only allow gossip option to be visible if player does not have item Strength of Mugamba"),
(15,6321,1,6,8,8043,0,0,0,"Only allow gossip option to be visible if quest Strength of Mount Mugamba is rewarded"),
(15,6321,1,6,26,19576,1,0,0,"Only allow gossip option to be visible if player does not have item Strength of Mugamba"),
-- Conditions for gossip main menu of Al''tabim the All-Seeing
-- Priest main menu conditions
(15,6322,0,0,8,8070,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Confessor's Bindings is rewarded"),
(15,6322,0,0,26,19842,1,0,0,"Only allow gossip option to be visible if player does not have item  Zandalar Confessor's Bindings"),
(15,6322,0,1,8,8071,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Confessor's Mantle is rewarded"),
(15,6322,0,1,26,19841,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Confessor's Mantle"),
(15,6322,0,2,8,8061,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Confessor's Wraps is rewarded"),
(15,6322,0,2,26,19843,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Confessor's Wraps"),
(15,6322,0,3,8,8052,0,0,0,"Only allow gossip option to be visible if quest The All-Seeing Eye of Zuldazar is rewarded"),
(15,6322,0,3,26,19594,1,0,0,"Only allow gossip option to be visible if player does not have item The All-Seeing Eye of Zuldazar"),
(15,6322,0,4,8,8049,0,0,0,"Only allow gossip option to be visible if quest The Eye of Zuldazar is rewarded"),
(15,6322,0,4,26,19591,1,0,0,"Only allow gossip option to be visible if player does not have item The Eye of Zuldazar"),
(15,6322,0,5,8,8050,0,0,0,"Only allow gossip option to be visible if quest The Eye of Zuldazar is rewarded"),
(15,6322,0,5,26,19592,1,0,0,"Only allow gossip option to be visible if player does not have item The Eye of Zuldazar"),
(15,6322,0,6,8,8051,0,0,0,"Only allow gossip option to be visible if quest The Eye of Zuldazar is rewarded"),
(15,6322,0,6,26,19593,1,0,0,"Only allow gossip option to be visible if player does not have item The Eye of Zuldazar"),
-- Warlock main menu conditions
(15,6322,1,0,8,8076,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Demoniac's Mantle is rewarded"),
(15,6322,1,0,26,19849,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Demoniac's Mantle"),
(15,6322,1,1,8,8077,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Demoniac's Robes is rewarded"),
(15,6322,1,1,26,20033,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Demoniac's Robe"),
(15,6322,1,2,8,8059,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Demoniac's Wraps is rewarded"),
(15,6322,1,2,26,19848,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Demoniac's Wraps"),
(15,6322,1,3,8,8109,0,0,0,"Only allow gossip option to be visible if quest Kezan's Unstoppable Taint is rewarded"),
(15,6322,1,3,26,19605,1,0,0,"Only allow gossip option to be visible if player does not have item Kezan's Unstoppable Taint"),
(15,6322,1,4,8,8106,0,0,0,"Only allow gossip option to be visible if quest Kezan's Taint is rewarded"),
(15,6322,1,4,26,19602,1,0,0,"Only allow gossip option to be visible if player does not have item Kezan's Taint"),
(15,6322,1,5,8,8107,0,0,0,"Only allow gossip option to be visible if quest Kezan's Taint is rewarded"),
(15,6322,1,5,26,19603,1,0,0,"Only allow gossip option to be visible if player does not have item Kezan's Taint"),
(15,6322,1,6,8,8108,0,0,0,"Only allow gossip option to be visible if quest Kezan's Taint is rewarded"),
(15,6322,1,6,26,19604,1,0,0,"Only allow gossip option to be visible if player does not have item Kezan's Taint"),
-- Mage main menu conditions
(15,6322,2,0,8,8068,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Illusionist's Mantle is rewarded"),
(15,6322,2,0,26,19845,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Illusionist's Mantle"),
(15,6322,2,1,8,8069,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Illusionist's Robes is rewarded"),
(15,6322,2,1,26,20034,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Illusionist's Robe"),
(15,6322,2,2,8,8060,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Illusionist's Wraps is rewarded"),
(15,6322,2,2,26,19846,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Illusionist's Wraps"),
(15,6322,2,3,8,8104,0,0,0,"Only allow gossip option to be visible if quest The Jewel of Kajaro is rewarded"),
(15,6322,2,3,26,19601,1,0,0,"Only allow gossip option to be visible if player does not have item Jewel of Kajaro"),
(15,6322,2,4,8,8101,0,0,0,"Only allow gossip option to be visible if quest The Pebble of Kajaro is rewarded"),
(15,6322,2,4,26,19598,1,0,0,"Only allow gossip option to be visible if player does not have item Pebble of Kajaro"),
(15,6322,2,5,8,8102,0,0,0,"Only allow gossip option to be visible if quest The Pebble of Kajaro is rewarded"),
(15,6322,2,5,26,19599,1,0,0,"Only allow gossip option to be visible if player does not have item Pebble of Kajaro"),
(15,6322,2,6,8,8103,0,0,0,"Only allow gossip option to be visible if quest The Pebble of Kajaro is rewarded"),
(15,6322,2,6,26,19600,1,0,0,"Only allow gossip option to be visible if player does not have item Pebble of Kajaro"),
-- Conditions for gossip main menu of Maywiki of Zuldazar
-- Shaman main menu conditions
(15,6341,0,0,8,8074,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Augur's Belt is rewarded"),
(15,6341,0,0,26,19829,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Augur's Belt"),
(15,6341,0,1,8,8056,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Augur's Bracers is rewarded"),
(15,6341,0,1,26,19830,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Augur's Bracers"),
(15,6341,0,2,8,8075,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Augur's Hauberk is rewarded"),
(15,6341,0,2,26,19828,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Augur's Hauberk"),
(15,6341,0,3,8,8119,0,0,0,"Only allow gossip option to be visible if quest The Unmarred Vision of Voodress is rewarded"),
(15,6341,0,3,26,19609,1,0,0,"Only allow gossip option to be visible if player does not have item Unmarred Vision of Voodress"),
(15,6341,0,4,8,8116,0,0,0,"Only allow gossip option to be visible if quest Vision of Voodress is rewarded"),
(15,6341,0,4,26,19606,1,0,0,"Only allow gossip option to be visible if player does not have item Vision of Voodress"),
(15,6341,0,5,8,8117,0,0,0,"Only allow gossip option to be visible if quest Vision of Voodress is rewarded"),
(15,6341,0,5,26,19607,1,0,0,"Only allow gossip option to be visible if player does not have item Vision of Voodress"),
(15,6341,0,6,8,8118,0,0,0,"Only allow gossip option to be visible if quest Vision of Voodress is rewarded"),
(15,6341,0,6,26,19608,1,0,0,"Only allow gossip option to be visible if player does not have item Vision of Voodress"),
-- Druid main menu conditions
(15,6341,1,0,8,8064,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Haruspex's Belt is rewarded"),
(15,6341,1,0,26,19839,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Haruspex's Belt"),
(15,6341,1,1,8,8057,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Haruspex's Bracers is rewarded"),
(15,6341,1,1,26,19840,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Haruspex's Bracers"),
(15,6341,1,2,8,8065,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Haruspex's Tunic is rewarded"),
(15,6341,1,2,26,19838,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Haruspex's Tunic"),
(15,6341,1,3,8,8113,0,0,0,"Only allow gossip option to be visible if quest Pristine Enchanted South Seas Kelp is rewarded"),
(15,6341,1,3,26,19613,1,0,0,"Only allow gossip option to be visible if player does not have item Pristine Enchanted South Seas Kelp"),
(15,6341,1,4,8,8110,0,0,0,"Only allow gossip option to be visible if quest Enchanted South Seas Kelp is rewarded"),
(15,6341,1,4,26,19610,1,0,0,"Only allow gossip option to be visible if player does not have item Enchanted South Seas Kelp"),
(15,6341,1,5,8,8111,0,0,0,"Only allow gossip option to be visible if quest Enchanted South Seas Kelp is rewarded"),
(15,6341,1,5,26,19611,1,0,0,"Only allow gossip option to be visible if player does not have item Enchanted South Seas Kelp"),
(15,6341,1,6,8,8112,0,0,0,"Only allow gossip option to be visible if quest Enchanted South Seas Kelp is rewarded"),
-- Conditions for gossip main menu of Falthir the Sightless
-- Rogue main menu conditions
(15,@GOSSIP,0,0,8,8063,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Madcap's Bracers is rewarded"),
(15,@GOSSIP,0,0,26,19836,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Madcap's Bracers"),
(15,@GOSSIP,0,1,8,8072,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Madcap's Mantle is rewarded"),
(15,@GOSSIP,0,1,26,19835,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Madcap's Mantle"),
(15,@GOSSIP,0,2,8,8073,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Madcap's Tunic is rewarded"),
(15,@GOSSIP,0,2,26,19834,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Madcap's Tunic"),
(15,@GOSSIP,0,3,8,8144,0,0,0,"Only allow gossip option to be visible if quest Zandalarian Shadow Mastery Talisman is rewarded"),
(15,@GOSSIP,0,3,26,19617,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalarian Shadow Mastery Talisman"),
(15,@GOSSIP,0,4,8,8141,0,0,0,"Only allow gossip option to be visible if quest Zandalarian Shadow Talisman is rewarded"),
(15,@GOSSIP,0,4,26,19614,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalarian Shadow Talisman"),
(15,@GOSSIP,0,5,8,8142,0,0,0,"Only allow gossip option to be visible if quest Zandalarian Shadow Talisman is rewarded"),
(15,@GOSSIP,0,5,26,19615,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalarian Shadow Talisman"),
(15,@GOSSIP,0,6,8,8143,0,0,0,"Only allow gossip option to be visible if quest Zandalarian Shadow Talisman is rewarded"),
(15,@GOSSIP,0,6,26,19616,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalarian Shadow Talisman"),
-- Hunter main menu conditions
(15,@GOSSIP,1,0,8,8066,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Predator's Belt is rewarded"),
(15,@GOSSIP,1,0,26,19832,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Predator's Belt"),
(15,@GOSSIP,1,1,8,8062,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Predator's Bracers is rewarded"),
(15,@GOSSIP,1,1,26,19833,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Predator's Bracers"),
(15,@GOSSIP,1,2,8,8067,0,0,0,"Only allow gossip option to be visible if quest Paragons of Power: The Predator's Mantle is rewarded"),
(15,@GOSSIP,1,2,26,19831,1,0,0,"Only allow gossip option to be visible if player does not have item Zandalar Predator's Mantle"),
(15,@GOSSIP,1,3,8,8148,0,0,0,"Only allow gossip option to be visible if quest Maelstrom's Wrath is rewarded"),
(15,@GOSSIP,1,3,26,19621,1,0,0,"Only allow gossip option to be visible if player does not have item Maelstrom's Wrath"),
(15,@GOSSIP,1,4,8,8145,0,0,0,"Only allow gossip option to be visible if quest The Maelstrom's Tendril is rewarded"),
(15,@GOSSIP,1,4,26,19618,1,0,0,"Only allow gossip option to be visible if player does not have item Maelstrom's Tendril"),
(15,@GOSSIP,1,5,8,8146,0,0,0,"Only allow gossip option to be visible if quest The Maelstrom's Tendril is rewarded"),
(15,@GOSSIP,1,5,26,19619,1,0,0,"Only allow gossip option to be visible if player does not have item Maelstrom's Tendril"),
(15,@GOSSIP,1,6,8,8147,0,0,0,"Only allow gossip option to be visible if quest The Maelstrom's Tendril is rewarded"),
(15,@GOSSIP,1,6,26,19620,1,0,0,"Only allow gossip option to be visible if player does not have item Maelstrom's Tendril");

-- Gahz'ranka Dead (npc) should be dead and unselectable
-- This creature spawns when original Gahz'ranka body dissapears
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=15122;
DELETE FROM `creature_template_addon` WHERE `entry`=15122;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(15122,0,0,1,0,'29266');

-- Set spawnpoint of Gahz'ranka into water instead of at land
UPDATE `event_scripts` SET `x`=-11688.5136,`y`=-1737.743,`z`=2.6789,`o`=3.9 WHERE `id`=9104;

-- Set all Hooktooth Frenzies homeposition higher in water
UPDATE `creature` SET `position_z`=8.638660 WHERE `guid` IN (49731,49727,46069,49730,49071,51444,49074,51443,49072,49724,49068,51447,51446,51450,49723,49728,49076,49722,51964,51963,51448,51442,49073,49070,51445,51449,49726,49075,49725,49729);

-- Correct homeposition of Gurubashi Berserkers
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`position_x`=-11777.142578,`position_y`=-1581.515991,`position_z`=20.997643,`orientation`=1.621398 WHERE `guid`=51395;
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`position_x`=-11802.939453,`position_y`=-1582.822388,`position_z`=21.003288,`orientation`=1.621398 WHERE `guid`=48555;

-- Double spawned Soulflayer & Son of Hakkar group
DELETE FROM `creature` WHERE `guid` IN (49673,49674,51393) AND `id` IN (11357);
DELETE FROM `creature` WHERE `guid`=49672 AND `id`=11359;
DELETE FROM `creature_addon` WHERE `guid` IN (49672,49674,51393);

-- Hakkari Oracle pathing: 11346
SET @GUID := 736;
SET @PATH := @GUID * 10;
UPDATE `creature` SET `MovementType`=2,`position_x`=-11880.799805,`position_y`=-1114.160034,`position_z`=83.378799 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0,'');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11880.609375,-1096.299805,89.065399,0,0,0,100,0),
(@PATH,2,-11880.470703,-1075.671265,95.479660,0,0,0,100,0),
(@PATH,3,-11880.609375,-1096.299805,89.065399,0,0,0,100,0),
(@PATH,4,-11880.521484,-1136.912598,77.347404,0,0,0,100,0),
(@PATH,5,-11881.089844,-1142.275757,77.281197,0,0,0,100,0),
(@PATH,6,-11885.173828,-1146.204590,77.279572,0,0,0,100,0),
(@PATH,7,-11893.494141,-1147.923462,77.285706,0,0,0,100,0),
(@PATH,8,-11941.483398,-1149.618530,77.287071,0,0,0,100,0),
(@PATH,9,-11945.541992,-1148.230957,77.279755,0,0,0,100,0),
(@PATH,10,-11951.206055,-1141.635376,77.282402,0,0,0,100,0),
(@PATH,11,-11952.918945,-1133.938110,78.511307,0,0,0,100,0),
(@PATH,12,-11952.707031,-1113.114014,84.954788,0,0,0,100,0),
(@PATH,13,-11952.385742,-1092.186523,91.525848,0,0,0,100,0),
(@PATH,14,-11952.707031,-1113.114014,84.954788,0,0,0,100,0),
(@PATH,15,-11952.918945,-1133.938110,78.511307,0,0,0,100,0),
(@PATH,16,-11951.206055,-1141.635376,77.282402,0,0,0,100,0),
(@PATH,17,-11945.541992,-1148.230957,77.279755,0,0,0,100,0),
(@PATH,18,-11941.483398,-1149.618530,77.287071,0,0,0,100,0),
(@PATH,19,-11893.494141,-1147.923462,77.285706,0,0,0,100,0),
(@PATH,20,-11885.173828,-1146.204590,77.279572,0,0,0,100,0),
(@PATH,21,-11881.089844,-1142.275757,77.281197,0,0,0,100,0),
(@PATH,22,-11880.521484,-1136.912598,77.347404,0,0,0,100,0),
(@PATH,23,-11880.609375,-1096.299805,89.065399,0,0,0,100,0),
(@PATH,24,-11880.470703,-1075.671265,95.479660,0,0,0,100,0);

-- Make the six Hakkari Oracle and Gurubashi Warrior emote to talk
DELETE FROM `creature_addon` WHERE `guid` IN (739,740,741,742,743,744);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(739,0,0,0,0,1,''),(740,0,0,0,0,1,''),(741,0,0,0,0,1,''),(742,0,0,0,0,1,''),(743,0,0,0,0,1,''),(744,0,0,0,0,1,'');

-- Son of Hakkar pathing: 11357
SET @GUID := 49034;
SET @PATH := @GUID * 10;
UPDATE `creature` SET `MovementType`=2,`position_x`=-11836.500000,`position_y`=-1599.979980,`position_z`=40.750099 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0,'');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11836.160156,-1613.540039,40.456375,0,0,0,100,0),
(@PATH,2,-11836.692383,-1618.308838,36.998791,0,0,0,100,0),
(@PATH,3,-11836.348633,-1635.910522,36.999691,0,0,0,100,0),
(@PATH,4,-11836.131836,-1647.003418,33.733452,0,0,0,100,0),
(@PATH,5,-11835.504883,-1659.293457,36.999123,0,0,0,100,0),
(@PATH,6,-11833.794922,-1676.584351,36.986992,0,0,0,100,0),
(@PATH,7,-11833.675781,-1682.667236,40.679619,0,0,0,100,0),
(@PATH,8,-11833.439453,-1694.743042,40.748413,0,0,0,100,0),
(@PATH,9,-11833.675781,-1682.667236,40.679619,0,0,0,100,0),
(@PATH,10,-11833.794922,-1676.584351,36.986992,0,0,0,100,0),
(@PATH,11,-11835.504883,-1659.293457,36.999123,0,0,0,100,0),
(@PATH,12,-11836.131836,-1647.003418,33.733452,0,0,0,100,0),
(@PATH,13,-11836.348633,-1635.910522,36.999691,0,0,0,100,0),
(@PATH,14,-11836.692383,-1618.308838,36.998791,0,0,0,100,0),
(@PATH,15,-11836.160156,-1613.540039,40.456375,0,0,0,100,0),
(@PATH,16,-11836.500000,-1599.979980,40.750099,0,0,0,100,0);

-- Son of Hakkar pathing: 11357
SET @GUID := 49033;
SET @PATH := @GUID * 10;
UPDATE `creature` SET `MovementType`=2,`position_x`=-11745.992188,`position_y`=-1620.595581,`position_z`=36.996082 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0,'');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11743.156250,-1609.533691,40.685410,0,0,0,100,0),
(@PATH,2,-11743.031250,-1615.080078,36.998463,0,0,0,100,0),
(@PATH,3,-11739.655273,-1631.531128,36.998829,0,0,0,100,0),
(@PATH,4,-11739.375000,-1643.833984,33.733307,0,0,0,100,0),
(@PATH,5,-11739.109375,-1655.463013,36.796623,0,0,0,100,0),
(@PATH,6,-11740.051758,-1673.494141,37.093468,0,0,0,100,0),
(@PATH,7,-11740.300781,-1678.714233,40.658524,0,0,0,100,0),
(@PATH,8,-11740.165039,-1691.161987,40.748100,0,0,0,100,0),
(@PATH,9,-11740.300781,-1678.714233,40.658524,0,0,0,100,0),
(@PATH,10,-11740.051758,-1673.494141,37.093468,0,0,0,100,0),
(@PATH,11,-11739.109375,-1655.463013,36.796623,0,0,0,100,0),
(@PATH,12,-11739.375000,-1643.833984,33.733307,0,0,0,100,0),
(@PATH,13,-11739.655273,-1631.531128,36.998829,0,0,0,100,0),
(@PATH,14,-11743.031250,-1615.080078,36.998463,0,0,0,100,0),
(@PATH,15,-11742.692383,-1597.847656,40.750408,0,0,0,100,0);

-- Zulian Panther pathing: 11365
SET @GUID := 49320;
SET @PATH := @GUID * 10;
UPDATE `creature` SET `MovementType`=2,`position_x`=-11626.807617,`position_y`=-1701.435425,`position_z`=38.823635 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0,'');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11626.807617,-1701.435425,38.823635,0,0,0,100,0),
(@PATH,2,-11627.707031,-1727.870483,40.333164,0,0,0,100,0),
(@PATH,3,-11629.434570,-1760.955322,38.754513,0,0,0,100,0),
(@PATH,4,-11653.967773,-1807.740723,43.086334,0,0,0,100,0),
(@PATH,5,-11629.434570,-1760.955322,38.754513,0,0,0,100,0),
(@PATH,6,-11627.707031,-1727.870483,40.333164,0,0,0,100,0),
(@PATH,7,-11630.115234,-1687.330566,39.997681,0,0,0,100,0),
(@PATH,8,-11634.075195,-1596.245239,39.645630,0,0,0,100,0);

-- Make the two other panthers follow the leader
UPDATE `creature` SET `MovementType`=2 WHERE `guid` IN (49319,49318);
DELETE FROM `creature_formations` WHERE `leaderGUID`=49320;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(49320,49320,0,0,2),
(49320,49319,3,225,2),
(49320,49318,3,90,2);

-- Soulflayer pathing: 11359
SET @GUID := 51397;
SET @PATH := @GUID * 10;
UPDATE `creature` SET `MovementType`=2,`position_x`=-11857.572266,`position_y`=-1597.060181,`position_z`=21.108191 WHERE `guid`=@GUID;
UPDATE `creature` SET `MovementType`=2,`position_x`=-11853.084961,`position_y`=-1689.830444,`position_z`=21.169413 WHERE `guid`=51398; -- Son of Hakkar on the left
UPDATE `creature` SET `MovementType`=2,`position_x`=-11859.287109,`position_y`=-1602.102905,`position_z`=21.126654 WHERE `guid`=51402; -- Son of Hakkar on the right
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0,'');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11854.121094,-1704.387817,21.126833,0,0,0,100,0),
(@PATH,2,-11857.572266,-1597.060181,21.108191,0,0,0,100,0);

-- Make the two Son of Hakkars follow the Soulflayer
DELETE FROM `creature_formations` WHERE `leaderGUID`=51397;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(51397,51397,0,0,2),
(51397,51398,3,225,2),
(51397,51402,3,90,2);

-- Soulflayer pathing: 11359
SET @GUID := 49663;
SET @PATH := @GUID * 10;
UPDATE `creature` SET `MovementType`=2,`position_x`=-11714.797852,`position_y`=-1701.325806,`position_z`=21.127512 WHERE `guid`=@GUID;
UPDATE `creature` SET `MovementType`=2,`position_x`=-11722.087891,`position_y`=-1695.433838,`position_z`=21.128262 WHERE `guid`=49665; -- Son of Hakkar on the left
UPDATE `creature` SET `MovementType`=2,`position_x`=-11716.234375,`position_y`=-1695.188965,`position_z`=21.128262 WHERE `guid`=49664; -- Son of Hakkar on the right
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0,'');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11718.995117,-1690.362915,21.128012,0,0,0,100,0),
(@PATH,2,-11723.005859,-1587.319458,21.028204,0,0,0,100,0),
(@PATH,3,-11719.233398,-1696.215698,21.127626,0,0,0,100,0);

-- Make the two Son of Hakkars follow the Soulflayer
DELETE FROM `creature_formations` WHERE `leaderGUID`=49663;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(49663,49663,0,0,2),
(49663,49665,3,225,2),
(49663,49664,3,90,2);

-- Soulflayer pathing: 11359
SET @GUID := 51421;
SET @PATH := @GUID * 10;
UPDATE `creature` SET `MovementType`=2,`position_x`=-11762.890625,`position_y`=-1722.024536,`position_z`=19.575914 WHERE `guid`=@GUID;
UPDATE `creature` SET `MovementType`=2,`position_x`=-11764.499023,`position_y`=-1719.525024,`position_z`=19.575289 WHERE `guid`=51422; -- Son of Hakkar on the left
UPDATE `creature` SET `MovementType`=2,`position_x`=-11764.550781,`position_y`=-1724.298218,`position_z`=19.625282 WHERE `guid`=51423; -- Son of Hakkar on the right
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0,'');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11763.343750,-1722.480713,19.575899,0,0,0,100,0),
(@PATH,2,-11708.300781,-1720.306274,19.575914,0,0,0,100,0),
(@PATH,3,-11713.461914,-1566.296997,19.575914,0,0,0,100,0),
(@PATH,4,-11708.300781,-1720.306274,19.575914,0,0,0,100,0),
(@PATH,5,-11862.150391,-1725.399780,19.576309,0,0,0,100,0),
(@PATH,6,-11867.898438,-1571.811768,19.576309,0,0,0,100,0),
(@PATH,7,-11862.150391,-1725.399780,19.576309,0,0,0,100,0);

-- Make the two Son of Hakkars follow the Soulflayer
DELETE FROM `creature_formations` WHERE `leaderGUID`=51421;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(51421,51421,0,0,2),
(51421,51422,3,225,2),
(51421,51423,3,90,2);

-- Set one group to another platform and make the Sons of Hakkar group up with the Soulflayer
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`position_x`=-11735.766602,`position_y`=-1585.883423,`position_z`=40.750748 WHERE `guid`=51427; -- Soulflayer
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`position_x`=-11738.824219,`position_y`=-1586.245483,`position_z`=40.750748 WHERE `guid`=51428; -- Son of Hakkar
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`position_x`=-11732.513672,`position_y`=-1591.200195,`position_z`=40.750748 WHERE `guid`=51429; -- Son of Hakkar
DELETE FROM `creature_formations` WHERE `leaderGUID`=51427;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(51427,51427,0,0,2),
(51427,51428,3,225,2),
(51427,51429,3,90,2);

-- Set one group to another platform and make the Sons of Hakkar group up with the Soulflayer
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`position_x`=-11843.626953,`position_y`=-1593.210083,`position_z`=40.750298 WHERE `guid`=51390; -- Soulflayer
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`position_x`=-11844.555664,`position_y`=-1589.202515,`position_z`=40.750298 WHERE `guid`=51425; -- Son of Hakkar
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`position_x`=-11846.154297,`position_y`=-1594.911377,`position_z`=40.750298 WHERE `guid`=51426; -- Son of Hakkar
DELETE FROM `creature_formations` WHERE `leaderGUID`=51390;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(51390,51390,0,0,2),
(51390,51425,3,225,2),
(51390,51426,3,90,2);

-- Insert missing Hooktooth Frenzy
DELETE FROM `creature` WHERE `guid`=49673;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES 
(49673,11374,309,1,1,15101,0,-11673.693359,-1623.402710,8.929444,4.587632,7200,0,0,9156,0,0,0,0,0);

-- Hooktooth Frenzy pathing: 11359
SET @GUID := 49673;
SET @PATH := @GUID * 10;
UPDATE `creature` SET `MovementType`=2,`position_x`=-11673.693359,`position_y`=-1623.402710,`position_z`=8.638660 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0,'');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11673.025391,-1622.384766,8.638660,0,1,0,100,0),
(@PATH,2,-11673.558594,-1686.983032,8.638660,0,1,0,100,0),
(@PATH,3,-11685.807617,-1714.556519,8.638660,0,1,0,100,0),
(@PATH,4,-11713.664063,-1759.057007,8.638660,0,1,0,100,0),
(@PATH,5,-11745.197266,-1778.084229,8.638660,0,1,0,100,0),
(@PATH,6,-11769.161133,-1780.376587,8.638660,0,1,0,100,0),
(@PATH,7,-11792.379883,-1767.869629,8.638660,0,1,0,100,0),
(@PATH,8,-11816.695313,-1739.452515,8.638660,0,1,0,100,0),
(@PATH,9,-11868.729492,-1734.182373,8.638660,0,1,0,100,0),
(@PATH,10,-11899.966797,-1680.415405,8.638660,0,1,0,100,0),
(@PATH,11,-11893.339844,-1632.780518,8.638660,0,1,0,100,0),
(@PATH,12,-11882.101563,-1558.908203,8.638660,0,1,0,100,0),
(@PATH,13,-11862.220703,-1522.576660,8.638660,0,1,0,100,0),
(@PATH,14,-11821.798828,-1434.877319,8.638660,0,1,0,100,0),
(@PATH,15,-11833.968750,-1368.541626,8.638660,0,1,0,100,0),
(@PATH,16,-11802.698242,-1365.827637,8.638660,0,1,0,100,0),
(@PATH,17,-11813.227539,-1424.008911,8.638660,0,1,0,100,0),
(@PATH,18,-11721.414063,-1441.936646,8.638660,0,1,0,100,0),
(@PATH,19,-11697.149414,-1525.417969,8.638660,0,1,0,100,0),
(@PATH,20,-11698.563477,-1591.051880,8.638660,0,1,0,100,0),
(@PATH,21,-11673.025391,-1622.384766,8.638660,0,1,0,100,0);

-- Hooktooth Frenzy pathing: 11359
SET @GUID := 49726;
SET @PATH := @GUID * 10;
UPDATE `creature` SET `MovementType`=2,`position_x`=-11679.599609,`position_y`=-1607.959961,`position_z`=8.638660 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0,'');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11673.025391,-1622.384766,8.638660,0,1,0,100,0),
(@PATH,2,-11698.563477,-1591.051880,8.638660,0,1,0,100,0),
(@PATH,3,-11697.149414,-1525.417969,8.638660,0,1,0,100,0),
(@PATH,4,-11721.414063,-1441.936646,8.638660,0,1,0,100,0),
(@PATH,5,-11813.227539,-1424.008911,8.638660,0,1,0,100,0),
(@PATH,6,-11802.698242,-1365.827637,8.638660,0,1,0,100,0),
(@PATH,7,-11833.968750,-1368.541626,8.638660,0,1,0,100,0),
(@PATH,8,-11821.798828,-1434.877319,8.638660,0,1,0,100,0),
(@PATH,9,-11862.220703,-1522.576660,8.638660,0,1,0,100,0),
(@PATH,10,-11882.101563,-1558.908203,8.638660,0,1,0,100,0),
(@PATH,11,-11893.339844,-1632.780518,8.638660,0,1,0,100,0),
(@PATH,12,-11899.966797,-1680.415405,8.638660,0,1,0,100,0),
(@PATH,13,-11868.729492,-1734.182373,8.638660,0,1,0,100,0),
(@PATH,14,-11816.695313,-1739.452515,8.638660,0,1,0,100,0),
(@PATH,15,-11792.379883,-1767.869629,8.638660,0,1,0,100,0),
(@PATH,16,-11769.161133,-1780.376587,8.638660,0,1,0,100,0),
(@PATH,17,-11745.197266,-1778.084229,8.638660,0,1,0,100,0),
(@PATH,18,-11713.664063,-1759.057007,8.638660,0,1,0,100,0),
(@PATH,19,-11685.807617,-1714.556519,8.638660,0,1,0,100,0),
(@PATH,20,-11673.558594,-1686.983032,8.638660,0,1,0,100,0);
