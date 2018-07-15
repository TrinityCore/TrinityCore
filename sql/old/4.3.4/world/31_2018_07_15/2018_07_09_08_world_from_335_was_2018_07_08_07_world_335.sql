/*
-- Malyfous's Catalogue
DELETE FROM `gossip_menu` WHERE `MenuID` IN (2986,2987,2988,2989,2990);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(2986,3695,0),
(2987,3696,0),
(2988,3697,0),
(2989,3699,0),
(2990,3698,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=2985;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(2985,0,0,"Chapter on Frayed Abomination Stitchings.",6145,1,1,2986,0,0,0,"",0,0),
(2985,1,0,"Chapter on Enchanted Scarlet Thread.",6146,1,1,2987,0,0,0,"",0,0),
(2985,2,0,"Chapter on Frostwhisper's Embalming Fluid.",6147,1,1,2988,0,0,0,"",0,0),
(2985,3,0,"Chapter on Arcane Crystals and Arcanite.",6151,1,1,2989,0,0,0,"",0,0),
(2985,4,0,"Chapter on Skin of Shadow.",6161,1,1,2990,0,0,0,"",0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=2985;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,2985,0,0,0,8,0,5047,0,0,0,0,0,"","Show gossip option if quest 'Finkle Einhorn, At Your Service!' is rewarded"),
(15,2985,1,0,0,8,0,5047,0,0,0,0,0,"","Show gossip option if quest 'Finkle Einhorn, At Your Service!' is rewarded"),
(15,2985,2,0,0,8,0,5047,0,0,0,0,0,"","Show gossip option if quest 'Finkle Einhorn, At Your Service!' is rewarded"),
(15,2985,3,0,0,8,0,5047,0,0,0,0,0,"","Show gossip option if quest 'Finkle Einhorn, At Your Service!' is rewarded"),
(15,2985,4,0,0,8,0,5047,0,0,0,0,0,"","Show gossip option if quest 'Finkle Einhorn, At Your Service!' is rewarded");

DELETE FROM `npc_text` WHERE `ID` IN (3695,3696,3697,3698,3699);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `em0_1`) VALUES
(3695,"If it's frayed abomination stitchings you be wanting, to Stratholme you'll be jaunting.$B$BFormerly the hometown of the Lightbringer hisself, now overrun by the minions of Kel'Thuzad.$B$BBrave the perils of the burning city and strike down the meaty abominations! Take from them your prize: Frayed abomination stitchings!","",6163,0,1,0),
(3696,"The final sanctum of crazed zealots. 'Tis where they create their scarlet uniforms, magically imbued by the enchanted scarlet thread!$B$BTo Stratholme, adventurer!","",6164,0,1,0),
(3697,"The finest preservative of flesh known to man and Scourge alike - Frostwhisper's embalming fluid.  Only one place an adventurer could find this and one would think that the lich the fluid is named after would not take too kindly to anyone going to said place.$B$BBut... if it's the fluid you want, the Scholomance you'll haunt...","",6165,0,1,0),
(3698,"The ground upon which the Scholomance was built was given to Kel'Thuzad by the Barov family. In exchange for this land - a place where the Cult of the Damned could learn the foul magics of the Scourge - Kel'Thuzad granted the Barov's immortality through undeath.$B$BIt is in Shadow Vault that you will find both the skin of shadow and its owner, Lady Illucia Barov.$B$BA finer mirror for the vain and dead never existed.","",6166,0,1,0),
(3699,"A staple of the Thorium Brotherhood.$B$BArcanite crystals are harvested from rich thorium lodes. Through the alchemical prowess of powerful alchemists, arcanite bars are born.$B$BSeek out a miner, if you aren't one... and find a good alchemist! You'll need both.","",6167,0,1,0);
*/
