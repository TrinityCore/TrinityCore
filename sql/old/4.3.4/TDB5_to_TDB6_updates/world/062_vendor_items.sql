SET @ESTULAN := 44381;
DELETE FROM `npc_vendor` WHERE `entry`=@ESTULAN;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`) VALUES
(@ESTULAN,0,10938,2,600,0), -- Lesser Magic Essence
(@ESTULAN,1,10940,4,600,0), -- Strange Dust
(@ESTULAN,2,6217,0,0,0), -- Copper Rod
(@ESTULAN,3,38682,0,0,0), -- Enchanting Vellum
(@ESTULAN,4,20753,0,0,0), -- Formula: Lesser Wizard Oil
(@ESTULAN,5,20752,0,0,0), -- Formula: Minor Mana Oil
(@ESTULAN,6,20758,0,0,0), -- Formula: Minor Wizard Oil
(@ESTULAN,7,22307,0,0,0), -- Pattern: Enchanted Mageweave Pouch
(@ESTULAN,8,4470,0,0,0), -- Simple Wood
(@ESTULAN,9,11291,0,0,0); -- Star Wood
