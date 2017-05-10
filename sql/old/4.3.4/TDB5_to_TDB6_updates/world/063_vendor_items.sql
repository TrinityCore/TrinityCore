-- Tex Vortacoil's Vendor Template
SET @TEX := 36375; -- Tex Vortacoil
DELETE from `npc_vendor` WHERE `entry`=@TEX;
INSERT INTO `npc_vendor` (`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`) VALUES
(@TEX,0,17020,0,0,0), -- Arcane Powder
(@TEX,0,17030,0,0,0), -- Ankh
(@TEX,0,17031,0,0,0), -- Rune of Teleportation
(@TEX,0,17032,0,0,0), -- Rune of Portals
(@TEX,0,17034,0,0,0), -- Maple Seed
(@TEX,0,68806,0,0,0); -- Kalytha's Haunted Locket
