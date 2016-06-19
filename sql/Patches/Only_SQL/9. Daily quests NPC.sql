SET
@ENTRY3 := 300123,
@ENTRY4 := 300124,
@ENTRY5 := 300125,
@ENTRY6 := 300126,
@ENTRY7 := 300127,
@ENTRY8 := 300128,
@ENTRY9 := 300129,
@ID1    := 700001,
@ID2    := 700002,
@ID3    := 700003,
@ID4    := 700004,
@ID5    := 700005,
@ID6    := 700006,
@ID7    := 700007,
@ID8    := 700008,
@ID9    := 700009;
REPLACE INTO `creature_template` (entry,modelid1,name,subname,minlevel,maxlevel,faction,npcflag,scale,AIName,InhabitType) VALUES
(@ENTRY3,23428,"Special quests","Special server quest giver",80,80,35,2,0.2,"SmartAI",3),
(@ENTRY4,23428,"Event Ends","Quester",80,80,35,2,0.2,"SmartAI",3),
(@ENTRY5,23428,"Event Ends","Quester",80,80,35,2,0.2,"SmartAI",3),
(@ENTRY6,23428,"Event Ends","Quester",80,80,35,2,0.2,"SmartAI",3),
(@ENTRY7,23428,"Event Ends","Quester",80,80,35,2,0.2,"SmartAI",3),
(@ENTRY8,23428,"Event Ends","Quester",80,80,35,2,0.2,"SmartAI",3),
(@ENTRY9,23428,"Event Ends","Quester",80,80,35,2,0.2,"SmartAI",3);

REPLACE INTO creature (guid, id, map, spawnMask, phaseMask, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, dynamicflags) VALUE
 (15010314, @ENTRY8, 1, 1, 1, 0, 0, -9575.09, -1905.99, 68.8638, 6.12509, 300, 0, 0, 5342, 0, 0, 0, 0, 0),
 (15009898, @ENTRY3, 1, 1, 1, 0, 0, 1578.8, -4417.07, 8.06324, 3.41204, 300, 0, 0, 5342, 0, 0, 0, 0, 0),
 (15115519, @ENTRY7, 0, 1, 1, 0, 0, -7722.33, 1080.61, 131.408, 0.764895, 300, 0, 0, 5342, 0, 0, 0, 0, 0),
 (15115521, @ENTRY6, 1, 1, 1, 0, 0, 2437.91, 2412.16, 169.796, 5.72175, 300, 0, 0, 5342, 0, 0, 0, 0, 0),
 (15115522, @ENTRY5, 1, 1, 1, 0, 0, 2904.03, 2967.07, 684.818, 5.12081, 300, 0, 0, 5342, 0, 0, 0, 0, 0),
 (15116778, @ENTRY9, 1, 1, 1, 0, 0, -11777.3, -4832.23, 66.8447, 2.46589, 300, 0, 0, 5342, 0, 0, 0, 0, 0),
 (15118049, @ENTRY3, 0, 1, 1, 0, 0, -8825.41, 634.354, 95.0751, 3.79538, 300, 0, 0, 5342, 0, 0, 0, 0, 0),
 (6523189, @ENTRY4, 1, 1, 1, 0, 0, -10383.8, 1047.25, 12.3799, 1.57934, 300, 0, 0, 5342, 0, 0, 0, 0, 0),
 (15122152, @ENTRY4, 1, 1, 1, 0, 0, -10390, 1426.07, 14.802, 4.96322, 300, 0, 0, 5342, 0, 0, 0, 0, 0);
