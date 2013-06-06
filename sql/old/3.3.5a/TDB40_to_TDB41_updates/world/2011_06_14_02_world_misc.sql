UPDATE `creature_template` set `VehicleId` = 273 WHERE `entry` = 31406;
UPDATE `creature_template` set `VehicleId` = 274 WHERE `entry` = 31408;
UPDATE `creature_template` set `VehicleId` = 277 WHERE `entry` = 31407;
UPDATE `creature_template` set `VehicleId` = 278 WHERE `entry` = 31409;
UPDATE `creature_template` set `VehicleId` = 301 WHERE `entry` = 32344;
UPDATE `creature_template` set `npcflag`=`npcflag`|0x1000000 WHERE `entry` IN
(25762,27131,31110,31137,31157,31262,31406,31407,31408,31409,32490,31583,31830,31881,31884,32225,32227,32292,32344,37968);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN
(25762,27131,31110,31137,31157,31262,31406,31407,31408,31409,32490,31583,31830,31881,31884,32225,32227,32292,32344,37968);
INSERT INTO `npc_spellclick_spells` VALUES
(25762,43671,0,0,0,1,0,0,0),
(27131,48754,0,0,0,1,0,0,0),
(31110,46598,0,0,0,1,0,0,0), -- maybe missed quest data
(31137,46598,0,0,0,1,0,0,0),
(31157,46598,0,0,0,1,0,0,0),
(31262,46598,0,0,0,1,0,0,0),
(31406,46598,0,0,0,1,0,0,0),
(31407,46598,0,0,0,1,0,0,0),
(31408,46598,0,0,0,1,0,0,0),
(31409,46598,0,0,0,1,0,0,0),
(32490,46598,0,0,0,1,0,0,0),
(31583,59319,0,0,0,1,0,0,0),
-- (31583,46598,0,0,0,1,0,0,0), -- should be casted if creature interacts, not implemented yet
(31830,46598,0,0,0,1,0,0,0),
(31881,46598,0,0,0,1,0,0,0),
(31884,46598,0,0,0,1,0,0,0),
(32225,46598,0,0,0,1,0,0,0),
(32227,46598,0,0,0,1,0,0,0),
(32292,46598,0,0,0,1,0,0,0),
(32344,46598,0,0,0,1,0,0,0),
(37968,46598,0,0,0,1,0,0,0);

DELETE FROM `vehicle_template_accessory` WHERE `entry` IN
(29931,31262,31406,31583,31881,31884,32225,32227,32490,32344);
INSERT INTO `vehicle_template_accessory` VALUES
(29931,29982,0,0,'Drakkari Rider on Drakkari Rhino',6,300),
(29931,29982,1,0,'Drakkari Rider on Drakkari Rhino',6,300),
(29931,29982,2,0,'Drakkari Rider on Drakkari Rhino',6,300),
(31262,31263,0,0,'Carrion Hunter rides Blight Falconer',6,300),
(31406,31408,0,1,'Alliance Bomber Seat on Alliance Infra-green Bomber',8,0),
(31406,31407,1,1,'Alliance Turret Seat on Alliance Infra-green Bomber',8,0),
(31406,31409,2,1,'Alliance Engineering Seat on rides Alliance Infra-green Bomber',8,0),
(31406,32217,3,1,'Banner Bunny, Hanging, Alliance on Alliance Infra-green Bomber',8,0),
(31406,32221,4,1,'Banner Bunny, Side, Alliance on Alliance Infra-green Bomber',8,0),
(31406,32221,5,1,'Banner Bunny, Side, Alliance on Alliance Infra-green Bomber',8,0),
(31406,32256,6,1,'Shield Visual Loc Bunny on Alliance Infra-green Bomber',8,0),
(31406,32274,7,0,'Alliance Bomber Pilot rides Alliance Infra-green Bomber',6,300),
(31583,31630,1,1,'Skytalon Explosion Bunny on Frostbrood Skytalon',8,0),
(31881,31891,0,0,'Kor''kron Transport Pilot rides Kor''kron Troop Transport',6,300),
(31881,31884,1,1,'Kor''kron Suppression Turret on Kor''kron Troop Transport',8,0),
(31881,31882,2,0,'Kor''kron Infiltrator on Kor''kron Troop Transport',6,300),
(31881,31882,3,0,'Kor''kron Infiltrator on Kor''kron Troop Transport',6,300),
(31881,31882,4,0,'Kor''kron Infiltrator on Kor''kron Troop Transport',6,300),
(31881,31882,5,0,'Kor''kron Infiltrator on Kor''kron Troop Transport',6,300),
(31884,31882,0,1,'Kor''kron Infiltrator rides Kor''kron Suppression Turret',8,0),
(32225,32223,0,0,'Skybreaker Transport Pilot rides Skybreaker Troop Transport',6,300),
(32225,32227,1,1,'Skybreaker Suppression Turret on Skybreaker Troop Transport',8,0),
(32225,32222,2,0,'Skybreaker Infiltrator on Skybreaker Troop Transport',6,300),
(32225,32222,3,0,'Skybreaker Infiltrator on Skybreaker Troop Transport',6,300),
(32225,32222,4,0,'Skybreaker Infiltrator on Skybreaker Troop Transport',6,300),
(32225,32222,5,0,'Skybreaker Infiltrator on Skybreaker Troop Transport',6,300),
(32227,32222,0,1,'Skybreaker Infiltrator rides Skybreaker Suppression Turret',6,300),
(32490,32486,0,0,'Scourge Death Knight rides Scourge Deathcharger',6,300),
(32344,32274,0,0,'Alliance Bomber Pilot rides Alliance Rescue Craft',6,300),
(32344,32531,2,1,'Banner Bunny, Side, Alliance, Small rides Alliance Rescue Craft',8,0);

DELETE FROM `creature` where `id` IN (31408,31407,31409,32217,32221,32256,32274,31630,31891,31884,31882,32223,32227,32222,32486,32531);
DELETE FROM `creature` where `guid` IN (121310,121302,121301,121277,121304,121312,121303,121305,121311,121306,121308) and `id` = 31263;
